#include "stdafx.h"
#include "critterviewer.h"
#include "critterwall.h"
#include "game.h"
#include "listener.h"
#include "Pop.h"
#include "PopView.h"
#include "PopDoc.h"
#include "graphicsopengl.h"
#include "graphicsmfc.h"

IMPLEMENT_SERIAL(cCritterViewer, cCritter, 0)

//#define TURNMYHEADTOTRACKPLAYER
	/* When _trackplayer is on, if I'm looking ortho at a 2D world, I just stay over the
player.  If I'm in a 3D world, I can either turn my head to look towards the player or I can 
try and stay "over" the player, though here it becomes a bit problematic to decide what
"over" means. Define TURNMYHEADTOTRACKPLAYER to turn your head, comment TURNMYHEADTOTRACKPLAYER
out to stay over the player.  We use the _lastgoodplayeroffset field to track what we
mean by "over."  Actually I like TURNMYHEADTOTRACKPLAYER better for Space War, but it works
less well for Ball World.*/

#define COLLIDEVIEWER
/*We've had a problem that when you ride the player you can move through the
world wall or an individual obstacle wall. I fix this with the collideviewer
code*/

//#define TRACEVIEWER
#define ORTHO2DONLY
/* Only use the Ortho viewer for 2D, otherwise we have an issue with the 
3D ortho controls being active in 2D cases.  */

Real cCritterViewer::STARTFIELDOFVIEWANGLE = PI/6.0;
Real cCritterViewer::MAXFIELDOFVIEWANGLE = PI/2.0;
Real cCritterViewer::MINFIELDOFVIEWANGLE = PI/36.0;
Real cCritterViewer::MOVEBOXTOGAMEBORDERRATIO = 20.0;
Real cCritterViewer::MINZNEAR = 0.1;
Real cCritterViewer::DEFAULTZOOMFACTOR = 1.1;
Real cCritterViewer::ORTHOZOFFSET = 10.0; //Just to have some standard ortho offset.
Real cCritterViewer::FOVEAPROPORTION = 0.85;
Real cCritterViewer::TURNPROPORTION = 0.005;
Real cCritterViewer::MOVEPROPORTION = 0.1;
Real cCritterViewer::STARTYOFFSETPROPORTION = 0.25;
Real cCritterViewer::PROPORTIONOFWORLDTOSHOW = 0.75;
	 /* How much of the world you typically
	want to show, where "how much" is multiplied times the distance from the lookatpoint to
	to the furthest corner. */
Real cCritterViewer::MINPROPORTIONOFWORLDTOSHOW = 0.3; //Limits Zoom in
Real cCritterViewer::MAXPROPORTIONOFWORLDTOSHOW = 3.0; //Limits Zoom out


cCritterViewer::cCritterViewer(CPopView *pview):
_pownerview(pview), 
_proportionofworldtoshow(cCritterViewer::PROPORTIONOFWORLDTOSHOW),
_aspect(4.0/3.0), //Start with standard screen aspect.
_fieldofviewangle(cCritterViewer::STARTFIELDOFVIEWANGLE),
_trackplayer(FALSE), /* Depending on the game, you might want to start with either FALSE 
	or TRUE for _trackplayer. In general the place where your game can make adjustments 
	to the critterviewer is in the cGame::initializeView method. */
_perspective(FALSE), //Will be reset by setViewer,
_foveaproportion(cCritterViewer::FOVEAPROPORTION)
{
	resetAndMatchMoveBox(pgame());
}

void cCritterViewer::resetAndMatchMoveBox(cGame *pgame)
{
	_proportionofworldtoshow = cCritterViewer::PROPORTIONOFWORLDTOSHOW;
	_aspect = 4.0/3.0;
	_fieldofviewangle = cCritterViewer::STARTFIELDOFVIEWANGLE;
	_trackplayer = FALSE;
	_perspective = FALSE; //Will be reset by setViewpoint,
	_foveaproportion = cCritterViewer::FOVEAPROPORTION;
	_wrapflag = cCritter::CLAMP; /* I had WRAP, which was a big mistake,
		as sometimes I'd back way up above the world and then suddenly be
		under it. */
	_dragbox = _movebox = cRealBox(pgame->border().center(),
		MOVEBOXTOGAMEBORDERRATIO * pgame->border().maxsize()); /* Put the
		viewer in a cube (or square in the 2D case) whose edge is a multiple 
		of the world's largest dimension. */
	//We will set _znear and _zfar in the cCritterViewer::setZClipPlanes call.
	setViewpoint(); /* Default viewpoint is up the z axis looking down at the origin.
		This call also initializes some of the remaining vairables. */
	zoom(1.0); //Matches _fieldofviewangle to _proportionofworldtoshow
	/* Don't bother to set a listener, as the various cGame::initializeView will do
	that indirectly via a setGraphicsClass call, and then possibly with a 
	direct call to change the listener again. */
	setDensity(0.0); //so you don't move things you bump into.
	setAbsorberflag(TRUE); //So you don't bounce when you bump things.
	psprite()->setRadius(0.1); /* Although this guy is invisible, it seems to be
		good to have a radius of 1.0 for use in the COLLIDEVIEWER code. */
}

void cCritterViewer::copy(cCritter *pcritter)
{
	cCritter::copy(pcritter);
}

CPopView* cCritterViewer::pownerview()const
{
	ASSERT(_pownerview && "cCritterViewer has valid owner CPopView pointer. ");
	return _pownerview;
}

cGame* cCritterViewer::pgame()const
{
	return pownerview()->pgame();
}

cGraphics * cCritterViewer::pgraphics()const
{
	return pownerview()->pgraphics();
}

BOOL cCritterViewer::is3D()
{
	return pgraphics()->is3D();
}

void cCritterViewer::resetZoom()
{
	_proportionofworldtoshow = cCritterViewer::PROPORTIONOFWORLDTOSHOW;
	zoom(1.0);
}

BOOL cCritterViewer::zoom(Real zoomfactor)
{ /* Sets the _proportionofworldtoshow parameter, and, if _perspective,
		adjusts the _fieldofviewangle and possibly the position if the
		proportionofworldtoshow would make _fieldofviewangle exceed WIDESTANGLE. */
	_proportionofworldtoshow /= zoomfactor; /* We think of a positive zoom
		factor as making the image bigger.  To do this, we show a smaller
		part of the world. */
	CLAMP(_proportionofworldtoshow, cCritterViewer::MINPROPORTIONOFWORLDTOSHOW,
		cCritterViewer::MAXPROPORTIONOFWORLDTOSHOW); 
		//REcent defaults for these zoom limiters were  0.2 and 5.0
	//Need to do some more work here.
	if (_perspective)
	{
		_fieldofviewangle /= zoomfactor; /* A 1.1 zoomfactor, say, is intended to make the
			image bigger. To make the image look bigger in a perspective view, you make
			the viewangle narrower. */
		_fieldofviewangle = CLAMP(_fieldofviewangle, cCritterViewer::MINFIELDOFVIEWANGLE,
			cCritterViewer::MAXFIELDOFVIEWANGLE);
	}
	return FALSE;
}

void cCritterViewer::setViewpoint(cVector toviewer, cVector lookatpoint, 
	BOOL trytoseewholeworld)
{
//First do some default setup stuff
	_fieldofviewangle = cCritterViewer::STARTFIELDOFVIEWANGLE;
	setSpeed(0.0);
#ifndef THREEDVECTORS //not THREEDVECTORS means the 2D case.
	_attitude = cMatrix(cVector2(1.0, 0.0), cVector2(0.0, 1.0), _position);
#else //THREEDVECTORS
	_attitude = cMatrix(-cVector::ZAXIS, -cVector::XAXIS, cVector::YAXIS, cVector::ZEROVECTOR);
		/* To get a reasonable default orientation, we arrange the viewer axes so that:  
		viewer x axis = world -z axis, viewer y axis = world -x axis, viewer z axis = world y axis.
		We pick this orientation so that if the viewer moves "forward" (along its tangent vector)
		it moves towards the world.  (We correct the mismatch between the coordinate systems in the 
		cCritterViewer::loadViewMatrix method, which has a long comment about this.)
		 Note that we will adjust _position (fourth column) later in this  call
		 with a moveTo, also we may rotate the _attitude a bit. */
	if (!_perspective) //Ortho view, simply move up.
	{
		_proportionofworldtoshow = 1.0; //Show all of a flat world.
		moveTo(lookatpoint + cCritterViewer::ORTHOZOFFSET * cVector::ZAXIS); // Get above the world
		_maxspeed = _maxspeedstandard = 0.5 * cCritterViewer::ORTHOZOFFSET; //Mimic perspective case.
	}
	else //_perspective
	{
		if (toviewer.isPracticallyZero()) //Not usable, so pick a real direction.
			toviewer = cVector::ZAXIS; //Default is straight up.
		if (trytoseewholeworld) /* Treat toviewer as a direction, and back off in that direction
			enough to see the whole world */
		{
			toviewer.normalize(); //Make it a unit vector.
			_proportionofworldtoshow = cCritterViewer::PROPORTIONOFWORLDTOSHOW;
			//Trying to show all of a world when flying around it, often leaves too big a space around it.
			Real furthestcornerdistance = pgame()->border().maxDistanceToCorner(lookatpoint); 
			Real tanangle = tan(_fieldofviewangle/2.0); /* We work with half the fov in this calculation, 
				the tanangle will be the ratio of visible distance to distance above the world,
				that is, tanangle = dr/dz, where
				Our dr is _proportionofworldtoshow * furthestcornerdistance, and
				our dz is the unknown seeallz height we need to back off to. 
				Swap tangangle and dz to get the next formula. */
			ASSERT(tanangle);
			Real seeallz = _proportionofworldtoshow * furthestcornerdistance / tanangle; 
			moveTo(lookatpoint + seeallz * toviewer);
		}
		else /*Not trytoseewholeworld.  In this case we don't normalize toviewer, instead	
			we treat it as a displacment from the lookatpoint. */
			moveTo(lookatpoint + toviewer);
		lookAt(lookatpoint);
		_maxspeed = _maxspeedstandard = 0.5 * (position()-lookatpoint).magnitude(); 
			/* Define the speed like this so it typically takes two seconds (1/0.5)
			to fly in to lookatpoint. */
		_lastgoodplayeroffset = position() - pgame()->pplayer()->position();
	}
#endif //THREEDVECTORS case
}

void cCritterViewer::setDefaultView()
{
	pgame()->initializeViewpoint(this);
}

void cCritterViewer::setPerspective(BOOL onoff)
{
	_perspective = onoff;
} 

void cCritterViewer::loadViewMatrix()const
{
/* What we do here is a bit tricky.  It involves matching two "trihedrons" (where a trihedron is a set
of three mutually perpendicular vectors used as the basis of a coordinate system). 
(a) On the one hand, the standard OpenGL-style graphics pipeline
sets up its projection matrix with the expectation that the viewer is situated so that the points
of interest are on the negative z-axis of the viewer's coordinates.  The viewers x and y axes are
thought of as situated with x pointing right and y pointing up. 
(b) We plan to sometimes let our
viewer either "fly around" or "ride the back of the player."  In this case, we expect to have the
viewer's attitudeTangent pointing towards the thing it is looking at, with its attitudeNormal in the plane 
it's turning in, and its attitudeBinormal pointing up.  Note that the attitudeNormal will seem to 
point to the left, so that the attiudeTangent * attitudeNormal = attitudeBinormal points up.
In the constructor, we set up a standard view by these three replacements:  x = -z, y = -x, z = y. 
(c) In order to match the trihedron of (b) to the expectation of (a), we want to essentially relabel
the axes of (b), so that the attitudeTangent is now the -z axis we look towards, the attitudeBinormal
is the y axis of "up", and the attitudeNormal is the positinve x-axis. So that's how we get the
formula in the line below.  Essentially we undo what the constructor does, by setting
z = -x, x = -y, y = z.
(note to b) By the way, if setAttitudeToMotoinLock(TRUE) has been called,
as we will do when riding a critter, then the attitude vectors will match, respetively, 
the critterviwer's _tangent, _normal and _binormal. */
#ifdef THREEDVECTORS //cMatrix means cMatrix3
	cMatrix viewmatrix(-attitudeNormal(), attitudeBinormal(), -attitudeTangent(),
		position());
#else //not THREEDVECTORS, the Two dimensional case, cMatrix means cMatrix2.
//	cMatrix2 viewmatrix(attitudeTangent(), attitudeNormal(), position());
	cMatrix viewmatrix(cVector2::XAXIS, cVector2::YAXIS, position());
#endif //THREEDVECTORS
/* The next thing to realize is that transforming a world position into the coordinates of a viewer
means pre-multiplying the world by the inverse of the viewer's position in world coordinates.  Here's
why.  If the viewer attitude is matrix V in world coordinates, and an object attitude is matrix W in 
world coordinates, then our task is to find the matrix W' of the object in viewer coordiantes.  Well,
if the matrix T transforms attitude V into the standard origin trihedron of the world --- which is the
identity matrix --- then T should transform W into W'.  But if T * V = I, then T is V.inverse().  So
W' = V.inverse() * W. */
#ifdef TRACEVIEWER
	Real *aelements = viewmatrix.transpose().elements();
	TRACE("3D version of cCritterViewer attitude() matrix in loadViewMatrix call.\n");
	TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
	TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
	TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
	TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
#endif // TRACEVIEWER
	pgraphics()->loadMatrix(viewmatrix.inverse());
#ifdef TRACEVIEWER
	aelements = viewmatrix.inverse().transpose().elements();
	TRACE("3D version of cCritterViewer attitude().inverse() matrix in loadViewMatrix call.\n");
	TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
	TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
	TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
	TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
#endif // TRACEVIEWER
}

cRealBox2 cCritterViewer::orthoViewRect() const
{
	Real dx = _proportionofworldtoshow * pgame()->border().xsize();
	Real dy = _proportionofworldtoshow * pgame()->border().ysize();
	ASSERT(dy);
	Real tempaspect = dx/dy;
	if (tempaspect > _aspect) //dy is too small, make it bigger.
		dy = dx / _aspect;
	if (tempaspect < _aspect) //dx is too small, make it bigger.
		dx = _aspect * dy;
	return cRealBox2(dx, dy); 
/* This constructor makes a box centred at the origin.
		We don't center at positon, because once we do
		the loadViewMatrix translation, the origin is effectively at the critter
		location. Earlier I mistakenly had return cRealBox2(_position, dx, dy), 
		and my ortho images were always off by a factor of two. */
}

void cCritterViewer::loadProjectionMatrix()
{ /* Set the perspective matrix of the pgraphics
		of the _pownerview so that something like _proportionofworldtoshow much of
		world shows (0.1 would be a tenth of the world, 1.0 would be all of it,
		2.0 would mean show space around the world so it takes up half the
		view).  Also use _znear and _zfar so that all of the visible world can
		fit	in between these bounds.  We regularly compute _znear and _zfar in 
		the setZClipPlanes method, called by our cCritterViewer::update call. */
	pgraphics()->matrixMode(cGraphics::PROJECTION);
	pgraphics()->loadIdentity();
	if (!_perspective || pownerview()->pgraphicsclass()==(RUNTIME_CLASS(cGraphicsMFC))) 
		//We don't have perspective implemented for cGraphicsMFC yet.
	{//use Ortho view. ortho call takes (left, right, bottom, top, nearzclip, farzclip).
		cRealBox2 orthoviewrect = orthoViewRect(); 
		/* The call to ortho() becomes a _realpixelconverter.setRealWindow call 
			in cGraphicsMFC, replacing our old call to
			_pgraphics->setRealBox(border()); */
		pgraphics()->ortho(orthoviewrect.lox(), orthoviewrect.hix(), 
			orthoviewrect.loy(), orthoviewrect.hiy(), _znear, _zfar);
	}
	else // _perspective is TRUE. perspective call takes (fieldofview, xtoyratio, nearzclip, farzclip).
	{
		pgraphics()->perspective(fieldOfViewDegrees(), _aspect, _znear, _zfar);
	}
	pgraphics()->matrixMode(cGraphics::MODELVIEW);
}

void cCritterViewer::setZClipPlanes(const cRealBox3 &worldbox)
{ /*This tries to set _znear and _zfar so that each of the eight corners of the worldbox is between
	the planes cutting the attitudeTangent() direction at distances of _znear and _zfar from the
	position().  We don't take into account the corners that are behind the viewer.  If
	any point is behind or almost behind the viewer pos relative to the
	viewedirection we set _znear to cCritterViewer::MINZNEAR, which is typically 0.1. */
#ifndef THREEDVECTORS //2D case.  Everything is in the xy plane.
	_znear = 0.1;
	_zfar = -0.1;
#else //THREEDVECTORS defined is 3D case
	cVector viewdirection = attitudeTangent();
	ASSERT(viewdirection.magnitude() - 1.0 < cVector:: PRACTICALLY_ZERO); 
		//Just to be safe, check this while in Debug mode. It will usually be off by some tiny amount.
	Real neardistance = BIG_REAL;
	Real fardistance = 0.0;
	Real testdistance;
	for (int i=0; i<8; i++) // We are assuming we have cast the worldbox to cRealBox3 if necessary.
	{
		testdistance = viewdirection % (worldbox.corner(i) - cVector(position()));
		 /* Recall that cRealBox3::corner
			steps through the eight corners of the box.  This gives the distance
			along the viewdirection.  If testdistance is negative, then	the point is behind the
			critterviewer relative to the direction its looking in.  In the not THREEDVECTORS case,
			position() would actually be a cVector2, but the #ifdef ensures that we are in
			3D here.  Note that testdistance may be negative. */
		if (testdistance < neardistance)
			neardistance = testdistance;
		if (testdistance > fardistance)
			fardistance = testdistance;
	}
	_znear = 0.1; //__max(neardistance, cCritterViewer::MINZNEAR); 
			//Has to be positive and bigger than 0.0.
	_zfar = __max(fardistance, _znear + 2*cCritterViewer::MINZNEAR); 
			//Has to be bigger than _znear.

#endif //THREEDVECTORS
}

//overloads

void cCritterViewer::Serialize(CArchive &ar)
{
 	cCritter::Serialize(ar);
 	if (ar.IsStoring()) // Save 
	{
		ar << _perspective << _trackplayer << _proportionofworldtoshow << _foveaproportion <<
			_aspect << _fieldofviewangle << _znear << _zfar << _lastgoodplayeroffset;
	}
 	else //Load 
	{
		ar >> _perspective >> _trackplayer >> _proportionofworldtoshow >> _foveaproportion >>
			_aspect >> _fieldofviewangle >> _znear >> _zfar >> _lastgoodplayeroffset;
	}
}

BOOL cCritterViewer::isVisible(const cVector &testpos) const
{
	/* _foveaproportion lies between 0.0 and 1.0. We say something is visible if it 
		appears on the inner foveaproportion central box of the viewer's image screen,
		which is what you see in the view window. */ 
	if (!_perspective)
	{
		cRealBox2 fovea;
		fovea = orthoViewRect();
		fovea = fovea.innerBox((1.0-_foveaproportion)*fovea.minsize());
		return (fovea.inside(cVector2(testpos)-cVector2(_position)));
	}
	else
	{
		cVector totestpos = (testpos - position()).normalize();
		return fabs(angleBetween(totestpos, attitudeTangent())) < 
			_foveaproportion * 0.5 * _fieldofviewangle;
	} 
}

void cCritterViewer::update(CPopView *pactiveview, Real dt)
{		
	cCritter::update(pactiveview, dt);
	setZClipPlanes((cRealBox3(pgame()->border())).outerBox(cSprite::MAXPRISMDZ)); 
		/* This call updates _znear and _zfar.  It explicity requires a
		cRealBox3 input, and we do cast of pgame()->border() BEFORE we compute
		the outer box. */
	if (_trackplayer && pgame()->visibleplayer() &&
		 !(plistener() && plistener()->GetRuntimeClass() == RUNTIME_CLASS(cListenerViewerRide)))
		/* The meaning of the visibleplayer() condition is that it doesn't make sense
		to track the player if it's not an onscreen player. The reason for the
		listener condition is that you don't want to stare at the player when
		riding it. */
/*  I should  explain that the goal here is to not bother turning when the player 
is  moving around in the middle of the veiw area, and only to turn when he's near
the edge, but to have the turning when he's near the edge be smoooth.
	The use of the 0.85 foveaproportion parameter means that you react before the player
gets right up to the edge.  The reactproportion factor in lookAtProportional and
moveToProportional is delicate and should probably be adjusted according to the
current player speed relative to the visible window.  The issue is that (a) if I make
reactproportion too small, like 0.01, then the viewer doesn't turn (or move) fast
enough to catch up with the player and keep it in view, but (b) if I make reactpropotion
too big, like 0.5, then the turning or moving is such an abrupt jump that the visual
effect is jerky.  The goal is to do turns that are just big enough to not look jerky,
but to have the turns be big enough so you aren't turning more often than you really
have to.  Another downside of a toosmall reactproportion, by the way, is that it can be
computationally expensive to react. 
	The way we finally solved this is to do a while loop to turn just
far enough, moving just a little at a time so as to not overshoot. */
	{
		if (isVisible(pgame()->pplayer()->position()))// Uses _foveaproportion
			_lastgoodplayeroffset = position() - pgame()->pplayer()->position();
			/*I'm not sure about constantly changing _lastgoodplayeroffset.  On the
			one hand, the offset I set in setViewpoint was a standard good one, so why
			not keep it.  On the other, if I want to move my viewpoint around then I
			do want to be able to get a new value here. It seems ok for now.*/
		else //not visible, so do somehting about it. 
		{
			int loopcount = 0; /* Never have a while loop without a loopcount
				to make sure you don't spin inside the while forever under some
				unexpected situation like at startup. */
			cVector lookat = pgame()->pplayer()->position();
			cVector viewerpos = lookat + _lastgoodplayeroffset;
			if (pgame()->worldShape() == cGame::SHAPE_XSCROLLER)
			{
				lookat = cVector(pgame()->pplayer()->position().x(),
					pgame()->border().midy(), pgame()->pplayer()->position().z());
				viewerpos = cVector(lookat.x(), position().y(), position().z()); 
			}
			if (pgame()->worldShape() == cGame::SHAPE_YSCROLLER)
			{
				lookat = cVector(pgame()->border().midx(),
					pgame()->pplayer()->position().y(), pgame()->pplayer()->position().z());
				viewerpos = cVector(position().x(), lookat.y(), position().z()); 
			} 
			if (_perspective)
				while (!isVisible(lookat) && loopcount < 100)// Uses _foveaproportion
				{
#ifdef TURNMYHEADTOTRACKPLAYER
					lookAtProportional(lookat, cCritterViewer::TURNPROPORTION);
#else //Don't TURNMYHEADTOTRACKPLAYER, instead move with the player.
					moveToProportional(viewerpos, cCritterViewer::TURNPROPORTION);
#endif //TURNMYHEADTOTRACKPLAYER
					loopcount++;
				}
			else //ortho case
				while( !isVisible(lookat) && loopcount < 100)// Uses _foveaproportion
				{
					moveToProportional(lookat +	10.0*pgame()->pplayer()->binormal(),
						cCritterViewer::TURNPROPORTION);
					loopcount++;
				}
		}
	}
//Possibly ride the player. 
	if (plistener()->IsKindOf(RUNTIME_CLASS(cListenerViewerRide)))
	{
		cCritter *pplayer = pgame()->pplayer();
		cVector offset = ((cListenerViewerRide*)plistener())->offset();
		moveTo(pplayer->position() + 
			offset.x()*pplayer->attitudeTangent() +
			offset.y()*pplayer->attitudeNormal() +
			offset.z()*pplayer->attitudeBinormal());
#ifdef COLLIDEVIEWER
		cRealBox skeleton = pplayer->moveBox();
		if (skeleton.zsize()<0.5)
			skeleton.setZRange(0.0, offset.z());
		if (skeleton.ysize()<0.5)
			skeleton.setYRange(0.0, offset.z());
		skeleton.clamp(_position);
		for (int i=0; i<pgame()->pbiota()->count(); i++)
		{
			cCritter* pother = pgame()->pbiota()->GetAt(i);
			if (pother->IsKindOf(RUNTIME_CLASS(cCritterWall)))
				pother->collide(this);
		}
		/* colliding with the wall may have twisted the viwer's orientation,
		so align it once again. */
#endif //COLLIDEVIEWER
		setAttitude(pplayer->attitude()); /* Before we call lookAt, 
			make sure your attitude matches the player.  For one thing,
			you may have gotten twisted around in the COLLIDEVIEWER code. */
		lookAt(pplayer->position() +
			cListenerViewerRide::PLAYERLOOKAHEAD * pplayer->radius() * 
			pplayer->attitudeTangent());
			 /* This has the effect that as offset gets large you change your
			looking direction see right in front of the player. The multiplier
			cCritterViewer::PLAYERLOOKAHEAD is tweaked to work well
			with the default cCritterViewer::OFFSET. */
	}
}
