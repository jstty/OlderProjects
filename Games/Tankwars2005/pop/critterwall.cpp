// Critterwall.cpp
//
/////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include "collider.h"
#include "spritepolygon.h"
#include "critterwall.h"
#include "assert.h"
#include "critterviewer.h"
#include "critterarmed.h"

//============================= cCritter ==========================
IMPLEMENT_SERIAL( cCritterWall, cCritter, 0 );

//Statics
#ifdef THREEDVECTORS
Real cCritterWall::WALLPRISMDZ = 0.75; 
#else //not THREEDVECTOR means 2D case
Real cCritterWall::WALLPRISMDZ = 0.0;
#endif //THREEDVECTORS

Real cCritterWall::THICKNESS = 0.2;
Real cCritterWall::CORNERJIGGLETURN = PI/4; //Random rotation cone halfangle
Real cCritterWall::CORNERJIGGLEKICK = 1.15; //Increase speed by this factor
COLORREF cCritterWall::WALLFILLCOLOR = cColorStyle::CN_LIGHTGRAY;

#define BACKUPSTEPS 10
	/* I use BACKUPSTEPS as a coarse method of backing a collided sphere out of a wall
	by moving from the overlapping new position to the non-overlapping old position in
	BACKUPSTEPS steps until I find a non-overlapping old position close to the wall. */
#define USECORNERJIGGLE
	/* If I define USECORNERJIGGLE, I make the bounce off a corner
	jiggle for nonplayer critters. This helps keep critters from
	getting stuck on corners. */
//==================cCritterWall==================

cCritterWall::cCritterWall(const cVector &enda, const cVector &endb,
	Real thickness, Real height, cGame* pownergame):
cCritter(pownergame),
_pskeleton(NULL),
_defaultfillcolor(cCritterWall::WALLFILLCOLOR)
{
	initialize(enda, endb, thickness, height, pownergame);
}

cCritterWall::cCritterWall(const cVector &enda, const cVector &endb,
	Real thickness, cGame* pownergame):
cCritter(pownergame),
_pskeleton(NULL),
_defaultfillcolor(cCritterWall::WALLFILLCOLOR)
{
	initialize(enda, endb, thickness, cCritterWall::WALLPRISMDZ,
		 pownergame);
}

void cCritterWall::initialize(const cVector &enda, const cVector &endb,
	Real thickness, Real height, cGame* pownergame)
{
	_defaultprismdz = height; //Used if cSprite is a cPolygon
	setFixedflag(TRUE); /* By default a wall is fixed;
		remember this if you want to use one for a paddle. */
	_collidepriority = cCollider::CP_WALL; /* Don't use
		the setCollidePriority mutator, as that
		forces a call to pgame()->buildCollider(); */
	_wrapflag = cCritter::WRAP; /* In case a wall extends
		across the _border, don't bounce it. Note that
		we have overloaded setWrap so you can't turn
		off the WRAP */
	setEndsThicknessHeight(enda, endb,
		thickness, _defaultprismdz);
}

void cCritterWall::setEndsThicknessHeight(const cVector &enda,
	const cVector &endb, Real thickness, Real height)
{
	_position = 0.5 * (enda + endb);
	_wrapposition3 = _wrapposition2 = _wrapposition1 = _position;
		/* This line is important, as otherwise the 
		cCritter::draw will thing this thing was wrapped,
		and it'll get drawn in two places. */
	_tangent = endb - enda;
	Real length = _tangent.magnitude();
	_tangent.normalize();
	_oldtangent = _tangent;
	_normal = _tangent.defaultNormal(); /* We orient so that
		the normal is oriented to the tangent as the "y-axis"
		is to the the "x-axis".*/
	_binormal = _tangent*_normal;
	_attitude = cMatrix(_tangent, _normal, _binormal, _position);
	setSkeleton(new cRealBox(length, thickness, height));
	setSpeed(0.0); /* Also sets _velocity to ZEROVECTOR,
		but doesn't wipe out _direction. */
#ifdef TRACEATTIDUDE
		Real *aelements = _attitude.transpose().elements();
	TRACE("3D version of cCritter attitude() matrix in cCritterWall::setEndsThicknessHeight call.\n");
	TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
	TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
	TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
	TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
#endif //TRACEATTITUDE
/*In looking at these settings, think of the wall as aligned horizontally with endb - enda pointing to the right and the normal pointing into the screen*/
	cPolygon *ppolygon = new cPolygon(4);
	ppolygon->setEdged(TRUE);
	ppolygon->setFillColor(cColorStyle::CN_GRAY);
	ppolygon->setLineWidthWeight(cColorStyle::LW_IGNORELINEWIDTHWEIGHT);
	ppolygon->setLineWidth(1);
		//Means draw a one-pixel edge line.
	ppolygon->setVertex(0, cVector(0.5*length, 0.5*thickness));
	ppolygon->setVertex(1, cVector(-0.5*length, 0.5*thickness));
	ppolygon->setVertex(2, cVector(-0.5*length, -0.5*thickness));
	ppolygon->setVertex(3, cVector( 0.5*length, -0.5*thickness));
	ppolygon->fixCenterAndRadius(); /* Use this call after a bunch
		of setVertex if points are just where you want. */
	ppolygon->setSpriteAttitude(cMatrix::translation(cVector(0.0, 0.0, -height/2.0)));
		/* This corrects for the fact that we always draw the ppolygon with its
		bottom face in the xy plane and its top in the plane z = height.  We
		shift it down so it's drawn to match the skeleton positon. */

	setSprite(ppolygon); 
	/* Also sets cSprite::_prismdz to
		cCritter::_defaultprismdz, which we set to 
		CritterWall::WALLPRISMDZ in our cCritterWall 
		constructor. */
}	

void cCritterWall::setThickness(Real newthickness)
{
	setSkeleton(new cRealBox(length(), newthickness, height()));
	cPolygon *ppolygon = (cPolygon*)(psprite());
	ASSERT (ppolygon->vertCount() == 4);
	ppolygon->setVertex(0, cVector(0.5*length(), 0.5*thickness()));
	ppolygon->setVertex(1, cVector(-0.5*length(), 0.5*thickness()));
	ppolygon->setVertex(2, cVector(-0.5*length(), -0.5*thickness()));
	ppolygon->setVertex(3, cVector( 0.5*length(), -0.5*thickness()));
	ppolygon->fixCenterAndRadius(); /* Use this call after a bunch
		of setVertex if points are just where you want. */
}	

void cCritterWall::setHeight(Real newheight)
{
	setSkeleton(new cRealBox(length(), thickness(), newheight));
	psprite()->setPrismDz(newheight);
	psprite()->setSpriteAttitude(cMatrix::translation(cVector(0.0, 0.0, -height()/2.0)));
		/* This corrects for the fact that we always draw the ppolygon with its
		bottom face in the xy plane and its top in the plane z = height.  We
		shift it down so it's drawn to match the skeleton positon. */
}	

void cCritterWall::setFillColor(COLORREF fillcolor)
{
	_defaultfillcolor = fillcolor;
	if(_psprite)_psprite->setFillColor(fillcolor);
}

void cCritterWall::Serialize(CArchive &ar)
{

	cCritter::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		ar << _pskeleton << _defaultfillcolor;
	}
	else //reading data
	{
		delete _pskeleton;
		ar >> _pskeleton >> _defaultfillcolor;
	}
}

int cCritterWall::dragTo(cVector newposition, Real dt)
{
	if (!draggable())
		return BOX_INSIDE; //Don't change the velocity.
	/* I'm going to allow for the possibility that I have a 3D creature in
	a 2D game world, as when I put a cSpriteQuake into a board game like 
	DamBuilder.  When I drag the walls, I still want them to be positioned
	so their butts are sitting on the xy plane. I'll run the in3DWorld test
	on the pgame->border().zsize as opposed to on the _movebox.zsize(). */
	if (!in3DWorld())
		newposition.setZ(_position.z());
	_position = newposition;
	_wrapposition3 = _wrapposition2 = _wrapposition1 = _position; 
	return clamp(_dragbox);
}

int cCritterWall::collidesWith(cCritter *pcritterother)
{
	/* Make sure I don't ever waste time colliding walls with
walls. I only call this the one time that I enroll the cCritterWall
 into the cGame's _pcollider. */
	if(pcritterother->IsKindOf(RUNTIME_CLASS(cCritterWall)))
		return cCollider::DONTCOLLIDE;
	return cCritter::collidesWith(pcritterother);
}

void cCritterWall::copy(cCritter *pcritter)
{
/*We need to overload the cCritter copy because if I have 
cCritterWallRobot which is a cCritterWall, and it gets split in two 
by a replicate call, then I want the new copy to have all the same 
shooting behavior as the old one.  In general, I should
overload copy for each of my critter child classes, but for now this 
one is the most important.  The overload does the regular copy, then 
looks if the thing being copied is a cCritterWall, and if it is then 
it copies the additional fields. */
	cCritter::copy(pcritter);	
	if (!pcritter->IsKindOf(RUNTIME_CLASS(cCritterWall)))
		return; //You're done if pcritter isn't a cCritterWall*.
	cCritterWall *pcritterwall = (cCritterWall *)(pcritter);
		/* I know it is a cCritterWall at this point, but I need
		to do a cast, so the compiler will let me
		access cCritterWall methods and fields. */
	setSkeleton(new cRealBox(pcritterwall->pskeleton()));
	_defaultfillcolor = pcritterwall->_defaultfillcolor;
}

void cCritterWall::mutate(int mutationflags, Real mutationstrength)
{ /* This is exactly the same as the base class cCritter::mutate except that we comment out the last line, which would mutate the sprite.  We don't want to mutate a wall's sprite. */
	if (mutationflags & MF_NUDGE)  //Special kind of weak mutation
	{
		Real turnangle = cRandomizer::pinstance()->randomSign()
		* cRandomizer::pinstance()->randomReal(-PI/2, PI/2);
		_velocity.turn(turnangle);
		_velocity *=
			cRandomizer::pinstance()->randomReal(0.5, 1.5);
		randomizePosition(realBox()); 
	}
	if (mutationflags & MF_POSITION)
		randomizePosition(_movebox);
	if (mutationflags & MF_VELOCITY)
		randomizeVelocity(cCritter::MINSPEED,
			_maxspeedstandard);
 		/* The following line is the cCritter::mutate line
		that we MUST comment out. */
	//_psprite->mutate(mutationflags, mutationstrength);
}

//Outcode and distance methods
int cCritterWall::outcode(const cVector &globalpos) 
{
	return outcodeLocal(globalToLocalPosition(globalpos));
}
int cCritterWall::outcodeLocal(const cVector &localpos) 
{ 		/* This tells you which of the 27 possible positions a 
		localpos has relative to the pskeleton box */
	return _pskeleton->outcode(localpos);
}

Real cCritterWall::distanceTo(const cVector &vpoint)
{
	return _pskeleton->distanceTo(globalToLocalPosition(vpoint));
}

//-----------------------Other Overloads-----------------
int cCritterWall::clamp(const cRealBox &border)
{  /* We don't change _pskeleton as it has the geometric info.  We 
	just change _position. */
	cRealBox effectivebox = border;
	//or border.innerBox(__min(_radiustangent, _radiusnormal));
	cVector oldcorner;
	cVector newcorner;
	int outcode = 0;
	int totaloutcode;
	for (int i=0; i<8; i++) //Step through the wall's corners
	{
		oldcorner = newcorner =
			_pskeleton->corner(i) + _position;
		outcode = effectivebox.clamp(newcorner);
		if (outcode != BOX_INSIDE) //corner was moved
		{
			_position += newcorner - oldcorner;
				/* As long at the wall is small enough to 
				fit inside the border, the successive 
				corrections won't cancel each other out. */
			totaloutcode |= outcode;
		}
	}
	_wrapposition3 = _wrapposition2 = _wrapposition1 = _position;
		 /* So it won't think it wrapped. */
	return outcode;
}

//-------------Colliding and Blocking--------------------

BOOL cCritterWall::blocks(const cVector& start, const cVector& end)
{
	return crossed (outcode(start), outcode(end));
}

BOOL cCritterWall::crossed(int startoutcode , int endoutcode )
{
	/* If crossed is TRUE then moving from start to end may
	mean you moved across the wall, even though neither start 
	nor end has to be close to the wall.  The only way to get a false
	positive is if you move very rapidly from, like LOY to HIX, skipping
	over the corner zone.  If you have a largish radius and smallish
	speed this shouldn't happen.  Our checks work by noticing when you
	leave a side zone.  To check against moving into the block exactly from
	a corner we include the BOX_INSIDE checks as well. */
	
	return
		(startoutcode == BOX_LOX && !(endoutcode & BOX_LOX)) ||
		(startoutcode == BOX_HIX && !(endoutcode & BOX_HIX)) ||
		(startoutcode == BOX_LOY && !(endoutcode & BOX_LOY)) ||
		(startoutcode == BOX_HIY && !(endoutcode & BOX_HIY)) ||
		(startoutcode == BOX_LOZ && !(endoutcode & BOX_LOZ)) ||
		(startoutcode == BOX_HIZ && !(endoutcode & BOX_HIZ)) ||
		startoutcode == BOX_INSIDE || endoutcode == BOX_INSIDE; //For corners
}

BOOL cCritterWall::collide(cCritter *pcritter)
{
	cVector oldlocalpos, newlocalpos;
	Real newdistance;
	int oldoutcode, newoutcode;
	BOOL crossedwall;

	oldlocalpos = globalToLocalPosition(pcritter->oldposition());
	oldoutcode = _pskeleton->outcode(oldlocalpos); 
	newlocalpos = globalToLocalPosition( pcritter->position());
	newdistance = _pskeleton->distanceToOutcode(newlocalpos,
		newoutcode); //Sets the newoutcode as well.
	crossedwall = crossed(oldoutcode, newoutcode);

//#define DEBUGWALLCOLLIDE
#ifdef DEBUGWALLCOLLIDE
Real test = newlocalpos.y() ;
//if (test < 2*_pskeleton->hiy() && test > 2*_pskeleton->loy())
TRACE("OLD global position = (%f  %f  %f), \nNEW global position = (%f  %f  %f)\n",
pcritter->oldposition().x(), pcritter->oldposition().y(), pcritter->oldposition().z(),
pcritter->position().x(), pcritter->position().y(), pcritter->position().z());
TRACE("OLD local position = (%f  %f  %f), outcode = %d\nNEW local position = (%f  %f  %f), outcode = %d\n crossedwall %d \n",
oldlocalpos.x(), oldlocalpos.y(), oldlocalpos.z(), oldoutcode,
newlocalpos.x(), newlocalpos.y(), newlocalpos.z(), newoutcode,
crossedwall );
#endif //DEBUGWALLCOLLIDE

	if (newdistance >= pcritter->radius() && !crossedwall) //No collision
		return FALSE; /*See if there's a collision at all. We
	say there's a collision if crossedwall or if the
	cCritterWall::distance is less than radius.  Remember that
	cCritterWall::distance measures the distance to the OUTSIDE 
	PERIMETER of the box, not the distance to the box's center. */
	
#ifdef DEBUGWALLCOLLIDE
TRACE("collided local position = (%f  %f  %f)\n",
newlocalpos.x(), newlocalpos.y(),newlocalpos.z());
#endif //DEBUGWALLCOLLIDE
	
	/* I collided, so I need to move back further into the last good
		zone I was in outside the wall.  I want to set newlocalpos so 
		the rim of its critter is touching the wall. The idea is to back
		up in the direction of oldlocalpos.  To allow the possibility
		of skidding along the wall, we plan to back up from the
		the face (or edge or corner) facing oldlocalpos.  This works
		only if oldlocalpos was a good one, not inside the box.  In 
		principle this should always be true, but some rare weird circumstance
		(like a triple collsion) might mess this up, so we check for the
		bad case before starting. */

	if (oldoutcode == BOX_INSIDE) //Note that this almost never happens.
	{
TRACE("BAD WALL COLLISION CASE: Inside the box old pos = (%f  %f  %f), outcode %d\n", oldlocalpos.x(),
oldlocalpos.y(),oldlocalpos.z(), oldoutcode);
		cVector insidepos = oldlocalpos;
		oldlocalpos -= _pskeleton->maxsize() * pcritter->tangent();
			//Do a brutally large backup to get out of the box for sure.
		oldoutcode = _pskeleton->outcode(oldlocalpos);
			//Recalculate outcode at this new position.
		oldlocalpos = _pskeleton->closestSurfacePoint(oldlocalpos, oldoutcode,
			insidepos, BOX_INSIDE, FALSE);
			//Go to the closest surface point from there.
		oldoutcode = _pskeleton->outcode(oldlocalpos);
			//Recalculate outcode one more time to be safe.
		crossedwall = crossed(oldoutcode, newoutcode);
			//Recalculate crossedwall
	}
		/* I find that with this code, the mouse can drag things through walls,
		so I do a kludge to block it by setting crossedwall to TRUE, this
		affects the action of cRealBox::closestSurfacePoint, as modified
		in build 34_4. */
	if (pcritter->plistener()->IsKindOf(RUNTIME_CLASS(cListenerCursor)))
		crossedwall = TRUE; //Don't trust the mouse listener.
	newlocalpos = _pskeleton->closestSurfacePoint(oldlocalpos, oldoutcode, 
		newlocalpos, newoutcode, crossedwall);
		/* This call to closestSurfacePoint will move the newlocal pos
		from the far new side (or inside, or overlapping) of the box back to 
		the surface, usually on the old near side, edge, or corner given by
		oldoutcode. This prevents going through the	wall.
			If oldoutcode is a corner position and you are in fact heading
		towards a face near the corner, we used to bounce off the corner
		even though visually you can see you should bounce off the
		face.  This had the effect of making a scooter player get hung up on
		a corner sometimes. As of build 34_3, I'm moving the 
		newlocalpos to the newoutocode side in the case where oldlocalpos
		is an edge or a corner, and where crossedwall isn't TRUE.  I
		have to force in a TRUE for the cCursorLIstener case.  The USEJIGGLE
		code below also helps keep non-player critters from getting stuck
		on corners. */
	//Now back away from the box.
	newoutcode = _pskeleton->outcode(newlocalpos);
	cVector avoidbox = _pskeleton->escapeVector(newlocalpos, newoutcode);
	newlocalpos += pcritter->radius() * avoidbox; 
	newoutcode = _pskeleton->outcode(newlocalpos);

#ifdef DEBUGWALLCOLLIDE	
TRACE("non-overlapping local position = (%f  %f  %f) for \n critter radius %f, wall thickness %f, step per update %f.\n",
newlocalpos.x(), newlocalpos.y(), newlocalpos.z(), pcritter->radius(), _pskeleton->ysize(), 
pcritter->position().distanceTo(pcritter->oldposition()));
cVector correctedposition = localToGlobalPosition(newlocalpos);
TRACE("corrected global position = (%f  %f  %f)\n\n",
correctedposition.x(), correctedposition.y(), correctedposition.z());
#endif //DEBUGWALLCOLLIDE

	pcritter->moveTo(localToGlobalPosition(newlocalpos), TRUE); 
		//TRUE means continuous motion, means adjust tangent etc.
	//Done with position, now change the velocity
	cVector localvelocity = globalToLocalDirection(
		pcritter->velocity());
	cVector oldlocalvelocity = localvelocity;
	_pskeleton->reflect(localvelocity, newoutcode); 
		/* I rewrote the reflect code on Feb 22, 2004 for VErsion 34_3, changing
		it so that when you reflect off an edge or corner, you only bounce
		the smallest of your three velocity components. Balls stll seem to
		get hung up on the corner once is awhile. */
		/* Now decide, depending on the pcritter's absorberflag and bounciness,
		how much you want to use the new localvelocity vs. the 
		oldlocalvelocity. We decompose the new localvelocity into the
		tangentvelocity parallel to the wall and the normalvelocity
		away from the wall. Some pencil and paper drawings convince
		me that the tangent is half the sum of the oldlocalvelocity
		and the reflected new localvelocity. */
	cVector tangentvelocity = 0.5*(localvelocity + oldlocalvelocity);
	cVector normalvelocity = localvelocity - tangentvelocity;
	Real bouncefactor = 1.0;
	if (pcritter->absorberflag())
		bouncefactor = 0.0;
	else
		bouncefactor = pcritter->bounciness();
	localvelocity = tangentvelocity + bouncefactor * normalvelocity;
#ifdef USECORNERJIGGLE
		/* USECORNERJIGGLE livens up action at the edges and corners.  Maybe
			the rotation should depend on the kind of edge or corner.
			Right now let's just use critter's binormal. Don't to it 
			to the player or viewer as it's confusing.  */
	if ( !(cRealBox::isFaceOutcode(newoutcode)) &&  //edge or corner
		 !(pcritter->IsKindOf(RUNTIME_CLASS(cCritterViewer))) && //not viewer
		 !(pcritter->IsKindOf(RUNTIME_CLASS(cCritterArmedPlayer))) ) 
			//Not player.  Note that cPlayer inherits from cCritterArmedPlayer,
			//so don't use cCritterPlayer as the base class here.
	{
		localvelocity.rotate(cSpin(
			cRandomizer::pinstance()->randomReal(
				-cCritterWall::CORNERJIGGLETURN,
 				cCritterWall::CORNERJIGGLETURN), //A random turn
				pcritter->binormal())); //Around the critter's binormal
		localvelocity *=  cCritterWall::CORNERJIGGLEKICK;  //Goose it a little
	}
#endif //USECORNERJIGGLE
	pcritter->setVelocity(localToGlobalDirection(localvelocity));
	return TRUE;
}


