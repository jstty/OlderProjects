// Critter.cpp: implementation of the cCritter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "critter.h"
#include "force.h"
#include "listener.h"
#include "game.h"
#include "spritepolygon.h" //For Player critter
#include "pop.h" //for playSound
#include "graphics.h"
#include "popview.h" //for the DF_ flags
#include "spritebubble.h"
#include "collider.h"

//#define DRAWMOVINGTRIHEDRON
	/* This draws red, blue, yellow lines for each critter's _tangent, _normal, _binormal.
		It's useful in debugging motion problems. */
//#define SHOWDAMAGE
		/*This flag makes you draw critters as wireframe when they're recently damaged.
		Some users of the framework have found this feature annoying or confusing.  We
		now no longer use it for bitmaps, though, so it's less obtrusive. Now
		I've taken it out because when I use cGraphicsOpenGL, every time the
		SHOWDAMAGE code is exercised, it makes an ugly flash in all the colors.*/
#define CLIP2D 
	/* CLIP2D is used to turn on a clipbox the shape of the _border in 2D games if wrapflag is on, 
		it keeps a critter's extra parts that are in mid-wrap from showing. I only have
		this working for cGraphicsMFC.*/
#define WRAPICON
		/* WRAPICON turns on our 2D trick of showing a sprite on both sides of the world when it
		wraps, we can turn it off if we don't like seeing the critters outside the world
		in multiples.  It looks better with CLIP2D turned on. It doesn't look good in 3D,
		as the clip isn't implemented for 3D, so we actually have a check on pgraphics->is3D()
		to not wrap the icon with cGrahicsOpenGL even if WRAPICON is on. */
#define NOFLIPBINORMAL
		/* I have had a problem of a 2D critter sometimes flipping over to the
		other side of the 2D world, this becomes visible in 3D view.   NOFLIPBINORMAL
		puts a fix into the cCritter::fixNormalAndBinormal method. */
//#define CRITTERDECIDES3D
		/* CRITTERDECIDES3D tells critter to look at the z axis of its own
		movebox	to decide in isIn3D() if it's in 2D or 3D.  If I comment out
		CRITTERDECIDES3D, then critter looks to pgame()->isIn3D.  I'm not sure
		which is best.  On the one hand, I might bouncing 3D critters in a 3D
		world with some critters confined to a 2D plane, and then
		CRITTERDECIDES3D is good.  On the other hand, I might have put some
		3D walls into the world and have to make the walls' movebox be 3D, so
		they don't get clamped, but leave the world and the critters 2D. In
		this case I might want the walls really to act like they're in 2D when
		they bounce things? */
#define PREVENT2DDROOP
		/* Change cCritter::update so critters in 2D worlds can't tilt away
		from being parallel to the xy plane. */
	
		/* The following TRACE??? defines turn on TRACE dumps to the output window from various
		parts of the code. */
//#define TRACEATTITUDE
//#define TRACEROTATEATTITUDE
//#define TRACEOPENGL
//#define TRACEFIXNORMAL
//#define TRACEPLAYERFIXNORMAL

#ifdef TRACEOPENGL
// Include the OpenGL headers so as to be able to carry out the trace.
#include "gl\gl.h"
#include "gl\glu.h"
#endif

//******** CONST STATICS **********************************************
//Whether to lock critter attitude to the trihedron of the critter motion
const int cCritter::BOUNCE = 0;
const int cCritter::WRAP = 1;
const int cCritter::CLAMP = 2;
	/* Instead of these uniform wrap styles we could maybe someday implement a
	notion of having the wrap be selective according to which edge, and use soemthing
	like the BOX_ flags from realbox.h to specify the edges for the various behaviors. */
const Real cCritter::INFINITEDENSITY = 1000.0;
//================== cCritter Statics ===============
Real cCritter::DENSITY = 1.0;
Real cCritter::MUTATIONSTRENGTH = 0.6;
int cCritter::STARTHEALTH = 1;
BOOL cCritter::STARTWRAPFLAG = cCritter::WRAP; //or cCritter::BOUNCE;
Real cCritter::SAFEWAIT = 0.3;
Real cCritter::FIXEDLIFETIME = 3.0;
//********* SIZE RELATED STATICS *******************
 /* In looking at the size and speed , keep in mind that our typical world size is 14.0
  by 9.0, defined by the WORLD??? statics.  The speed is in units per second, so a
 speed of 3 means it takes about 3 seconds to cross the window.  A speed of 1 takes 10 
 seconds, a speed of 5 takes 2 seconds and so on. */
 // Size Statics=========================================
 /* cCritter MINRADIUS, MAXRADIUS, BULLETRADIUS, and MAXSPEED are default values that actually don't
matter as we set them equal to the corresponding cGame:: statics in the cGame constructor. It's also
common to override these in the constructors of child critters. We group them here simply so we can compare them.  */
Real cCritter::MINRADIUS = 0.3;  
Real cCritter::MAXRADIUS = 0.8;  
Real cCritter::BULLETRADIUS = 0.125; 
Real cCritter::PLAYERRADIUS = 0.4;
 //==================Speed Related Statics ==============================
Real cCritter::MAXSPEED =3.0; /* This is sometimes changed by child game
	constructors.  This value is used	in cCritter::randomize(MF_VELOCITY) and
	is used in cCritter::move(dt). */
Real cCritter::MINSPEED = 0.5; //Used in cCritter::randomize(MF_VELOCITY).
Real cCritter::MINTWITCHTHRESHOLDSPEED = 0.0; /* If we have _attitudetomotionlock, and we have some
		critters barely bouncing on a "floor" it looks bad if they keep twitching their orientation up
		and down.  So in cCritter::updateAttitude, we don't actually change the _attitudeMatrix to
		match the motionMatrix() if the speed is less than _mintwitchtriggerspeed. Don't bother
		with accessors or mutator for this as we change it, if at all, in the constructor.  Default
		value is cCritter::MINTWITCHTHRESHOLDSPEED */ 
Real cCritter::NEAREDGEPERCENT = 0.15; /* Used in moveToNearEdge.  0.1 for instance means
 	put critters in outer 10% of movebox. */
Real cCritter::LISTENERACCELERATION = 10.0; /* Used by the cListenerSpaceship and cListenerCar */

//============================= cCritter ==========================
IMPLEMENT_SERIAL( cCritter, CObject, 0 );

//----------------------- Constructors and Destructors -------------

cCritter::cCritter(cGame *pownergame):
	_pownerbiota(NULL),
	_age(0.0),
	_lasthit_age(- cCritter::SAFEWAIT), /* We do this so that critters don't start out
		thinking they were just hit.  cCritter::SAFEWAIT is currently 0.3 seconds. */
	_oldrecentlydamaged(FALSE), //Can use to notice when you need to change sprite.
	_health(cCritter::STARTHEALTH), //Default 1.
	_usefixedlifetime(FALSE),
	_fixedlifetime(cCritter::FIXEDLIFETIME),
	_shieldflag(FALSE),
	_outcode(0),
	_score(0),
	_newlevelscorestep(0),
	_newlevelreward(0),
	_value(1),
	_personality(cRandomizer::pinstance()->random()), //Use our static randomizing method.
	_movebox(cRealBox(4.0,3.0, 0.0)), //Dummy defaults to be reset with setMoveBox
	_dragbox(cRealBox(_movebox)),  //Dummy defaults to be reset with setDrag
	_wrapflag(cCritter::STARTWRAPFLAG), //cCritter::BOUNCE
	_defaultprismdz(cSprite::CRITTERPRISMDZ),
	_density(cCritter::DENSITY), //This standard value is currently 1.0.
	_mass(1.0), //Dummy default is reset by fixMass.
	_collidepriority(cCollider::CP_CRITTER),
	_lastcollidepartnerpriority(cCollider::CP_MAXIMUM),
	_absorberflag(FALSE),
	_fixedflag(FALSE),
	_position(cVector::ZEROVECTOR),
	_oldposition(cVector::ZEROVECTOR),
	_wrapposition1(cVector::ZEROVECTOR),
	_wrapposition2(cVector::ZEROVECTOR),
	_wrapposition3(cVector::ZEROVECTOR),
	_velocity(cVector::ZEROVECTOR),
	_curvature(0.0),
	_speed(0.0), //Must match _velocity.magnitude().
	_tangent(cVector(1.0, 0.0)), //We always want some unit vector _tangent.
	_oldtangent(cVector(1.0, 0.0)),
	_normal(cVector(0.0, 1.0)),
	_binormal(cVector(0.0, 0.0, 1.0)),
	_attitudetomotionlock(TRUE),
	_acceleration(cVector::ZEROVECTOR),
	_listeneracceleration(cCritter::LISTENERACCELERATION),
	_spin(), //_spin is initialized to 0 spinangle around ZAXIS by default constructor
	_maxspeed(cCritter::MAXSPEED), //Default 3.0
	_maxspeedstandard(cCritter::MAXSPEED),
	_mintwitchthresholdspeed(cCritter::MINTWITCHTHRESHOLDSPEED),
	_bounciness(1.0),
	_mutationstrength(cCritter::MUTATIONSTRENGTH), //Default 0.6 (out of 1.0 max)
	_ptarget(NULL),
	_metrickey(-1) //Put in a bad index by default
{
	_psprite = new cSprite(); /* Let's always have a valid sprite.  The default cSprite looks
		like a circle, by the way. */
	_plistener = new cListener();  /* For uniformity, always have a valid listener as well.  The
		default listener does nothing.  Don't call setListener(new cListener()) here as this 
		call may have side-effects I don't want yet. */ 
	_attitude.setLastColumn(_position);
		/* The default _attitude constructor has set the matrix to the identity matrix, and it's
			more accurate to the make the fourth column match the position. */
	fixMass();
	if (pownergame)
		pownergame->add(this, FALSE); /* This call will set _movebox and _dragbox to
			match pownergame->_border, and will set _wrapflag to match pownergame->wrapflag).
			The second argument controls whehter to insert the critter into the game cBiota array
			right away. It's better not to insert right away adn to let the critter finish
			being constructed so that the cCollider::smartAdd will use the properly
			overlaoded form of collidesWith. */
}

void cCritter::copy(cCritter *pcritter)
{

	delete _psprite; //Immediately replace this with a good pointer.
	_psprite = NULL;
	_psprite =(pcritter->psprite())->clone(); //See comments on clone below and in sprite.cpp

	_age = pcritter->_age;
	_lasthit_age = pcritter->_lasthit_age;
	_oldrecentlydamaged = pcritter->_oldrecentlydamaged;
	_health = pcritter->_health;
	_usefixedlifetime = pcritter->_usefixedlifetime;
	_fixedlifetime = pcritter->_fixedlifetime;
	_shieldflag = pcritter->_shieldflag;
	_score = pcritter->_score;
	_newlevelscorestep = pcritter->_newlevelscorestep;
	_newlevelreward = pcritter->_newlevelreward;
	_personality = pcritter->_personality;
	_value = pcritter->_value;
	_defaultprismdz = pcritter->_defaultprismdz;
	_density = pcritter->_density;
	_mass = pcritter->_mass;
	_collidepriority = pcritter->_collidepriority;
	_lastcollidepartnerpriority = pcritter->_lastcollidepartnerpriority;
	_absorberflag = pcritter->_absorberflag;
	_mutationstrength = pcritter->_mutationstrength;

	_wrapflag = pcritter->_wrapflag;
	_outcode = pcritter->_outcode;
	_movebox = pcritter->_movebox;
	_dragbox = pcritter->_dragbox;
	_fixedflag = pcritter->_fixedflag;
	_position =	pcritter->_position;
	_oldposition = pcritter->_oldposition;
	_oldtangent = pcritter->_oldtangent;
	_wrapposition1 = pcritter->_wrapposition1;
	_wrapposition2 = pcritter->_wrapposition2;
	_wrapposition3 = pcritter->_wrapposition3;
	_velocity = pcritter->_velocity;
	_curvature = pcritter->_curvature;
	_speed = pcritter->_speed;
	_tangent = pcritter->_tangent;
	_normal = pcritter->_normal;
	_binormal = pcritter->_binormal;
	_attitude = pcritter->_attitude;
	_maxspeed = pcritter->_maxspeed;
	_maxspeedstandard = pcritter->_maxspeedstandard;
	_mintwitchthresholdspeed = pcritter->_mintwitchthresholdspeed;
	_bounciness = pcritter->_bounciness;
	_acceleration = pcritter->_acceleration;
	_listeneracceleration = pcritter->_listeneracceleration;
	_spin = pcritter->_spin;
	_attitudetomotionlock = pcritter->_attitudetomotionlock;

	_pownerbiota = pcritter->_pownerbiota; //Will cause a problem if pasting to a different document.
	_ptarget = pcritter->_ptarget; //Will cause a problem if pasting to a different document.
	copyForcearray(pcritter);
	//We don't copy the _plistener or the _pbiota
}

//----------------- cCritter Serialize ------------------------

/*		Whenever you use load into a pointer variable ptr, we have to call delete on the pointer 
	first, otherwise we'll have a memory leak caused by the "orphaned" object that the pointer
	pointed to before you overwrote it with the load.  For reasons we'll now explain, we must use
	an overloaded ar >> ptr operator to load into a pointer, rather than a ptr->Serialize(ar) call.
		To save and load the _psprite and _plistener fields of cCritter, we use the autogenerated
	overloaded operator<<(CArchive &ar, cSprite *p) and operator>>(CArchive &ar, cSprite *&p).
	MFC has "written the code" for these operators automatically becasue the cSprite	
			(a) inherits from CObject,
			(b) has DECLARE and IMPLEMENT_SERIAL, and
			(c) has it's own Serialize defined. 
		In the load case we want to make a new cSprite* and place it into the _psprite field, and
	this is exactly what ar >> _psprite does.
		Now, as mentioned just above, in the load case, we delete _psprite before loading it.  At
	first you might think you could load either with _psprite->Serialize(ar) or ar >> _psprite. 
		But since you delete _psprite just before the load, it becomes an invalid pointer just before
	the load, and you would get a crash if you tried to call _psprite->Serialize(ar) for the load.
		We could actually use _psprite->Serialize(ar) in the save case, but for symmetry in the
	appearance of the read and write cases, we use	ar << _psprite there. 
*/

 void cCritter::Serialize(CArchive &ar)
 {
 	CObject::Serialize(ar);
 
 	if (ar.IsStoring()) //Writing data.
 	{
 		_forcearray.Serialize(ar); /* Save the array and its contents using 
 			CTypedPointerArray. */
 //Sprite
 		ar << _psprite <<
 //Listener 
 		_plistener <<
 //Personal variables
 		_age << _lasthit_age<< _oldrecentlydamaged << _health << _usefixedlifetime << _fixedlifetime <<
		_shieldflag  << _score  <<_newlevelscorestep <<
 		_newlevelreward << _personality << _value << _defaultprismdz << _density << _mass <<
 		_collidepriority << _lastcollidepartnerpriority << _absorberflag << _mutationstrength  << 
 //Motion variables
 		_wrapflag << _outcode << _movebox << _dragbox << _fixedflag << 
 			_position << _oldposition << _wrapposition1 <<_wrapposition2 <<_wrapposition3 <<
 			_velocity << _curvature << _speed << _tangent << _oldtangent <<_normal <<_binormal <<	_attitude <<
			_maxspeed << _maxspeedstandard << _mintwitchthresholdspeed << _bounciness <<
 			_acceleration << _listeneracceleration << _spin << _attitudetomotionlock;
 //Pointer index variables.
 		if (_pownerbiota)
 			_targetindex = _pownerbiota->_index(_ptarget); //Prepare for a nonserializiable pointer reference.
 		else
 			_targetindex = cBiota::NOINDEX;
 		ar << _targetindex;
 	}
 	else //Reading data.
 	{
 		clearForcearray(); /* We have to empty out the array before reading into it
 				or we'll have a memory leak in case something's in it. */
 		delete _psprite;
		_psprite = NULL;
 			//always delete a pointer before reading into it or you have a leak.
 		delete _plistener;
		_plistener = NULL;
 			//always delete a pointer before reading into it or you have a leak.
 		_forcearray.Serialize(ar); //Read in.
 //Sprite
 		ar >> _psprite >> /* Uses CreateObject to creates a new cSprite* object of the
 				correct child class, copies the new objects fields out of the file,
 				and places the pointer to the new object in _psprite */
 //Listener and force
 		_plistener >> // See the comment just above.
 
 //Personal variables
 		_age >> _lasthit_age >> _oldrecentlydamaged >> _health >>  _usefixedlifetime >> _fixedlifetime >>
		_shieldflag  >> _score >> _newlevelscorestep >>
 		_newlevelreward >> _personality >> _value >> _defaultprismdz >> _density >> _mass >>
 		_collidepriority >> _lastcollidepartnerpriority >> _absorberflag >> _mutationstrength >> 
 //Motion variables
 		_wrapflag >> _outcode >> _movebox >> _dragbox >> _fixedflag >> 
 			_position >> _oldposition >> _wrapposition1 >>_wrapposition2 >>_wrapposition3 >>
 			_velocity >> _curvature >> _speed >> _tangent >> _oldtangent >> _normal >>_binormal >> _attitude >> 
			_maxspeed >> _maxspeedstandard >> _mintwitchthresholdspeed >> _bounciness >>
 			_acceleration >>  _listeneracceleration >>  _spin >> _attitudetomotionlock;
 //Dummy index for nonserializable pointer reference variables.
 		ar >> _targetindex; //It's up to cBiota to replace this index by a pointer.
 
 	_pownerbiota = NULL; /* The cBiota::Serialize will set all the cCritter _pownerbiota fields 
 		after all the critters are loaded. */
 	_ptarget = NULL; /* And then the cBiota::Serialize will call
 			all pcritter->fixPointerRefs for each critter to fix the _ptarget, and also 
 			fix any pointer refs in the forces. */
 	}
 }

void cCritter::fixPointerRefs()
{
	if (!_pownerbiota)
		return;
	else
	{
		_ptarget = _pownerbiota->GetAt(_targetindex);
			//Note that GetAt returns NULL if _targetindex is cBiota:: NOINDEX
		for (int i=0; i<_forcearray.GetSize(); i++)
			_forcearray.GetAt(i)->fixPointerRefs(_pownerbiota);
	}
}

cCritter::cCritter(cCritter *pcritter)
{ 
	_psprite = new cSprite;	 //Let's always have a sprite.
	copy(pcritter);
}

cCritter::~cCritter()
{
	delete _psprite;
	_psprite = NULL; //Just to be safe we always get rid of any deleted pointer right away.
	delete _plistener;
	_plistener = NULL;
	clearForcearray(); //Delete all of the pForce objects we own.
	if (_pownerbiota && pgame())
		pgame()->removeReferencesTo(this); /* Calls (a)  
			_pbiota->removeReferencesTo(this) to check all critters in the cBiota and
			destroy any cCritter _ptarget or cForceObject _pnode variables that refer to this,
			and	(b) calls pgame()->pcollider()->_pbiota->removeReferencesTo(this) to remove the
			cCollisionPair involving this. */
} 

void cCritter::removeReferencesTo(cCritter *pdeadcritter)
{
	if(ptarget() == pdeadcritter)
		setTarget(NULL);
	for (int j=0; j<pforcearray()->GetSize(); j++)
	{
		if (pforcearray()->GetAt(j)->IsKindOf(RUNTIME_CLASS(cForceObject)))
		{
			cForceObject *pforcenodal = (cForceObject *)(pforcearray()->GetAt(j));
			if (pforcenodal->pnode() == pdeadcritter)
			{
				delete pforcenodal;
				pforcearray()->ElementAt(j) = NULL;
				pforcearray()->RemoveAt(j);
			}
		}
	}
}


cCritter* cCritter::clone()
{
/* The purpose of this method is that we may later have various child classes
cCritterChild of the cCritter class, and to truly copy a cCritterChild, you need
a cCritterChild* pointer and not a cCritter* pointer.  The following will
create a cCritteryChild* pointer.  Even though we cast pcritter into a cCritter*
pointer for the return, it "really" remains a cCritterChild, and will use the
child classes overloads of any virtual methods. For a critter child class's clone to work properly,
that critter child class must overload the copy method.*/  
	CRuntimeClass *pRuntimeClass = GetRuntimeClass();
	cCritter *pcritter = (cCritter*)(pRuntimeClass->CreateObject());
	pcritter->copy(this);
	return pcritter;
}

void cCritter::add_me(cBiota *pownerbiota, BOOL immediateadd)
{
	setOwner(pownerbiota);
	makeServiceRequest("add_me");
	if (immediateadd)
		pownerbiota->processServiceRequests();
}
//--------------------- cCritter sprite mutator -------------

void cCritter::setPrismDz(Real prismdz)
{
	_defaultprismdz = prismdz;
	 if(_psprite)
		_psprite->setPrismDz(_defaultprismdz);
}

void cCritter::setSprite(cSprite *psprite)
{
	if (!(_psprite == psprite)) //Do nothing if it happens to be the same pointer.
	{
		delete _psprite;  //Immediately replace the deleted pointer.
		_psprite = NULL;
		_psprite = psprite;
	}
	_psprite->setPrismDz(_defaultprismdz); //Do I need this?
	fixMass(); //Use the sprite's radius() to recompute your mass.
}

int cCritter::setRadius(Real radius)
{
	_psprite->setRadius(radius);
	fixMass();
	return clamp();
}

//---------------cCritter cListener methods-------------------------

void cCritter::setListener(cListener *plistener)
{
	ASSERT(_plistener);
	ASSERT(plistener);
	delete _plistener;
	_plistener = NULL;
	_plistener = plistener;
	_plistener->install(this); /* Note that this may change _attitudetomotionlock and will by default set
		_mintwitchthresholdspeed to 0.0 */
}

void cCritter::feellistener(Real dt)
{
	/* The cGame::step calls feellistener(), move(), update(), feellistener(), move(), update(), feellistener(),
			move(), and so on.  In other words, after start up the process is to 
			(1) call update() and, within update, call feelforce().
			(2) call feellistener() and possibly add in some more acceleration
			(3) use the _acceleration in move().  */

	_plistener->listen(dt, this); /* We pass the pointer "this" to the listener so that it can 
		change the fields of this calling cCritter as required.  The caller critter's pgame()
		hold the cController object thatstores all of the keys and mouse actions you need
		to process. */
}

//-----------------cForce----------------

void cCritter::addForce(cForce *pforce)
{
	_forcearray.Add(pforce);
}

void cCritter::clearForcearray()
{
	for (int i=0; i<_forcearray.GetSize(); i++)
	{
		delete _forcearray.GetAt(i);
		_forcearray.ElementAt(i) = NULL;
	}
	_forcearray.RemoveAll();
}

void cCritter::copyForcearray(cCritter *pcritter)
{
	clearForcearray();
	for (int i=0; i<pcritter->pforcearray()->GetSize(); i++)
		addForce(pcritter->pforcearray()->GetAt(i)->clone());
}

void cCritter::copyPhysicsForces(cCritter *pcritter)
{
	for (int i=0; i<pcritter->pforcearray()->GetSize(); i++)
	{
		cForce *pforce = pcritter->pforcearray()->GetAt(i);
		if (pforce->isGlobalPhysicsForce())
			addForce(pforce->clone()); 
	}
}

void cCritter::update(CPopView *pactiveview, Real dt)
{
	feelforce();
	if (recentlyDamaged() != _oldrecentlydamaged)
	{
		psprite()->setNewgeometryflag(TRUE); /* I do this as some critters are drawn differently
			when recently damaged. */
		_oldrecentlydamaged = recentlyDamaged();
	}
	if(_usefixedlifetime && _age > _fixedlifetime)
		dieOfOldAge(); /* I don't call die() because I like to use die for when a critter dies
			of unnatural causes, like getting shot.  It's more likely that I overload die() to
			do something dramatic than that I overlaod dieOfOldAge(). */
	if (!in3DWorld()) 
	{ /* First prevent a bad phenomenon where an odd bounce makes the binormal
		flip, and puts a 2D critter upside down. */
		if (binormal().z() < 0.0)
			setAttitude(cMatrix(_tangent, cVector::ZAXIS*_tangent,
				cVector::ZAXIS, _position));
#ifdef PREVENT2DDROOP
	/* And now  rule out any possibility that the critter got tilted,
	say by a collision. This has been a lingering issue, like where a critter would
	get jostled and then be tilted enough so that its bullets go into the ground. */
		_tangent.setZ(0.0);
		_normal.setZ(0.0);
		_binormal = cVector::ZAXIS;
#endif //PREVENT2DDROOP
	}
}

void cCritter::feelforce()
{
	cVector forcesum; //Default constructor (0,0)
	for (int i=0; i<_forcearray.GetSize(); i++)
		forcesum += _forcearray.GetAt(i)->force(this);
	_acceleration = forcesum/mass();  //From Newton's Law: Force = Mass * Acceleration.
}
	
//----------------cCritter accessors--------------

void cCritter::fixMass()
{
	if (radius()< SMALL_REAL)
		_mass = 1.0; //Don't allow a zero mass() as we divide by it in force().
	else _mass =  _density * pow(radius(), 3); /* We will think of our critters as
		three-dimensional objects, as this seems to give more natural looking motion.
		You could use 2 here instead to make them more like disks. */
}

cBiota* cCritter::pownerbiota()const
{
//	ASSERT(_pownerbiota); Turn off this assert because it triggers when the 
	return _pownerbiota;
}

cGame* cCritter::pgame()const
{
	if (!_pownerbiota)
		return NULL;
	return _pownerbiota->pgame();
}

BOOL cCritter::in3DWorld() //Tells you if the owner game has a true z-Thickness.
{
/* I'm going to allow for the possibility that I have a 2D creature in a 3D game
world, as when I put a bouncing critter into a game where the player slides
in 2D. */
#ifdef CRITTERDECIDES3D
		return _movebox.zsize()  > cRealBox3::MINSIZE;
#else //not CRITTERDECIDES3D means game decides 3D
	if (pgame())	
		return pgame()->border().zsize()  > cRealBox3::MINSIZE;
	else 
		return _movebox.zsize()  > cRealBox3::MINSIZE;
#endif //CRITTERDECIDES3D.
}

cCritter* cCritter::pplayer()
{
	cCritter* pplayergame = pgame()->pplayer();
	ASSERT(pplayergame && "cCritter's owner game has valid player.");
	return pplayergame;
}

//-------------- cCritter initializers -------------------

void cCritter::reset()
{
	_lasthit_age = -SAFEWAIT;
	_age = 0.0;
	_health = cCritter::STARTHEALTH;
	_score = 0;
	_position.setZero();
	_velocity.setZero();
	_acceleration.setZero();
	_spin.setZero();
	_speed = 0;
}

void cCritter::randomizePosition(const cRealBox &startbox)
{
	cVector newposition = startbox.randomVector();
	moveTo(newposition); //this clamps to fit in the startbox if no wrap.
//	if (_psprite)
//		_psprite->moveTo(_position);
		 /* Need this becasue we abruptly move this way and sprite isn't caught up.
		If you don't have this line, then a reseed shows the sprites at middle of screen 
		for one update. */
}

void cCritter::randomizeVelocity(Real minspeed, Real maxspeed, BOOL force2D)
{
	cVector randomunitvector = cVector::randomUnitVector();
	if (!in3DWorld() || force2D)
	{
		randomunitvector.setZ(0.0);
		randomunitvector.normalize();
	}
	setVelocity(cRandomizer::pinstance()->randomReal(minspeed, maxspeed) * randomunitvector);
}

void cCritter::randomizeSpin(Real minspeed, Real maxspeed)
{
	_spin = cSpin(cRandomizer::pinstance()->randomReal(minspeed, maxspeed),
		cVector::randomUnitVector()); //cSpin constuctor takes spinangle, spinaxis args.
}

//-------------- cCritter Breeders ----------------------------

void cCritter::mutate(int mutationflags, Real mutationstrength)
{ //Note that cCritterWall has its own version of this method.
	if (mutationflags & MF_NUDGE)  //Special kind of weak mutation
	{
		Real turnangle = cRandomizer::pinstance()->randomSign() * cRandomizer::pinstance()->randomReal(-PI/2, PI/2);
		_velocity.turn(turnangle);
		_velocity *= cRandomizer::pinstance()->randomReal(0.5, 1.5);
		randomizePosition(realBox()); /* cCritter::realBox() is the
			smallest box holding the current sprite. Note that if the
			game is 2D, this box will be 2D.  */
	}
	if (mutationflags & MF_POSITION)
		randomizePosition(_movebox);
	if (mutationflags & MF_VELOCITY)
		randomizeVelocity(cCritter::MINSPEED, _maxspeedstandard);
	_psprite->mutate(mutationflags, mutationstrength);
	fixMass(); // In case the radius got changed.
}

//------------- cCritter service request method ---------
void cCritter::makeServiceRequest(CString request)
{ /* This is one place we use _pownerbiota, other than the destructor  */
	_pownerbiota->addServiceRequest(cServiceRequest(this, request));
}

//----------------- cCritter location methods ----------------------------

Real cCritter::radius() const
{
	return _psprite->radius();
}

cVector cCritter::directionTo(cCritter *pcritter)
{
	return _pownerbiota->direction(this, pcritter); //Uses the cMetricCritter in cBiota	
}

Real cCritter::distanceTo(cCritter *pcritter)
{
	return _pownerbiota->distance(this, pcritter); /* Depending on USEMETRIC uses cCritter::distanceTo(cVector)
		or uses a lookup into a _cmetric (also computed with cCritter::distanceTo(cVector). */	
}

cDistanceAndDirection cCritter::distanceAndDirectionTo(cCritter *pcritter)
{
	return _pownerbiota->distanceAndDirection(this, pcritter);
}

BOOL cCritter::touch(cCritter *pcritter)
{
	return  (pcritter != this) && (distanceTo(pcritter) < radius()+pcritter->radius());
}

BOOL cCritter::touch(const cVector &vpoint)
{
	return distanceTo(vpoint) < radius(); //distance is a cVector friend.
}

BOOL cCritter::touch(const cLine &sightline)
{
	return sightline.distanceTo(position()) < radius();
}

BOOL cCritter::contains(cCritter *pcritter)
{
	return distanceTo(pcritter) + pcritter->radius() < radius();
}

Real cCritter::distanceTo(const cVector &vpoint)
{
	return _position.distanceTo(vpoint);  /*Use the cVector function for now,
		but later we should adjust this to be different if _wrapflag is on. */
}

int cCritter::clamp()
{
	return clamp(_movebox);
}

int cCritter::clamp(const cRealBox &border)
{ //Clamp against border
	cRealBox effectivebox = border.innerBox(radius());
	int outcode = effectivebox.clamp(_position);
	_wrapposition3 = _wrapposition2 = _wrapposition1 = _position;
	return outcode;
}

int cCritter::moveTo(const cVector &newposition, BOOL treatascontinuousmotion)
{
	_position = newposition; //Allow this even if _fixedflag is TRUE.
	_outcode = BOX_INSIDE;
	if (_wrapflag != cCritter::WRAP)
		_outcode = clamp();
	else
		_outcode = _movebox.wrap(_position, _wrapposition1, _wrapposition2,
			_wrapposition3, radius());
	if (!treatascontinuousmotion) /* This is the usual, default case.  We only
		turn treatascontinuousmotion to TRUE when we are using moveTo in bouncing
		off a wall or colliding with another critter, as in these cases we want
		the moveTo to be like a physical motion, and thus affect the _tangent,
		_normal, and _binormal.  In the default case as in randomizePosition or
		in some of the cListener code, we just want to move the cCritter but not
		affect its motion trihedron. */
		_oldtangent = _tangent; //So fixNormalAndBinormal doesn't react.
	_attitude.setLastColumn(_position); /* So this gets rendered in the right
		position immediately. */
	return _outcode;
}

int cCritter::moveToProportional(const cVector &newposition, Real amount, BOOL
	treatascontinuousmotion)
{
	CLAMP(amount, 0.0, 1.0);
	return moveTo((1.0-amount)*_position + amount * newposition, treatascontinuousmotion);
}

int cCritter::dragTo(cVector newposition, Real dt)
{
	if (!draggable())
		return BOX_INSIDE;
	/* We aren't going to use this velocity in move, because a dragged critter is a focus critter,
		and will opt out of the move call.  Even so, we store this velocity so that when we 
		release a dragged critter and it is no longer the focus, it will then move with the velocity
		we dragged it at. */
	_oldtangent = _tangent; //So fixNormalAndBinormal doesn't react.
	/* I'm going to allow for the possibility that I have a 3D creature in
	a 2D game world, as when I put a cSpriteQuake into a board game like 
	DamBuilder.  When I drag the walls, I still want them to be positioned
	so their butts are sitting where I put them initially, like in the xy
	plane or a little bit below.  I don't want to change the z, in other words.
	So I'll run the in3DWorld test on the pgame->border().zsize as opposed to
	on the _movebox.zsize(). */
	if (!in3DWorld())
		newposition.setZ(_position.z()); //Don't allow change in z
	if (dt > SMALL_REAL) //Don't divide by 0.
		setVelocity((1.0/dt)*(newposition - _position));
	_position = newposition;
	int outcode = clamp(_dragbox);
	_attitude.setLastColumn(_position); /* So this gets rendered in the right
		position immediately. */
	return outcode;
}

void cCritter::moveToMoveboxEdge(Real nearedgepercent) 
{
		/* Make critter be near edge of _movebox by rerandomizing the position until it's not
			in the central area. This is so they're not right on top of the player if the
			player starts out in the middle.  I use this in cGameSpacewar in particular. 
			The default cGame::NEAREDGEPERCENT is 0.15.  */
	int safetycount = 100; /* Use a counter like this when you have a possibly endless
		loop to ensure that you get out of the loop even if the task fails. */
	if (!in3DWorld())
	{
		cRealBox2 flatborder(_movebox);
		cRealBox2 centralbox = flatborder.innerBox(
			nearedgepercent * flatborder.minsize());
		while (centralbox.inside(position()) && safetycount > 0)
		{
			safetycount--;
			randomizePosition();
		}
	}
	else
	{
		cRealBox3 centralbox = _movebox.innerBox(
			nearedgepercent * _movebox.minsize());
		while (centralbox.inside(position()) && safetycount > 0)
		{
			safetycount--;
			randomizePosition();
		}
	}
}

int cCritter::setMoveBox(const cRealBox &box)
{
	_movebox = box;
	return clamp();
}

void cCritter::setWrapflag(int wrapflag)
{
	_wrapflag = wrapflag;
	if (_wrapflag == cCritter::BOUNCE || _wrapflag == cCritter::CLAMP)
		clamp();
	else
		_wrapposition3 = _wrapposition2 = _wrapposition1 = _position;
}
//----------------------------cCritter game methods--------------
int cCritter::damage(int hitstrength)
{
		// If we have our shield on, or were just hit, then don't allow a hit
	if ( _shieldflag || recentlyDamaged() )
		return 0;
	_lasthit_age = _age; //Save age for use by the recentlyDamaged() accessor.
	_health -= hitstrength;
	if (_health <= 0)
	{
		_health = 0;
		die(); //Make a delete_me service request, possibly make noise or more.
		return _value; //The reward for killing this critter.
	}
	return 0; //Not killed yet.
}

void cCritter::addScore(int scorechange)
{ /* This adds the score and checks if you reached a new multiple of the _newlevelscorestep
		value, and if so it adds to your health.  We do this without bothering to remember
		the last time you got a health reward, instead we just figure out what int "scorelevel"
		you're at by doing int division to get a level value. */
	int oldscore = _score;
	_score += scorechange;
	if (!_newlevelscorestep)
		return;
	if (oldscore/_newlevelscorestep < _score/_newlevelscorestep) //int division. Check old level < new level. 
		_health += _newlevelreward;
} 
//================Coordinate methods=====================

cVector cCritter::globalToLocalDirection(const cVector &globalvec)
{
	return _inverseattitude * (globalvec + _position);
		/* The _inverseattitude transformation translates _position to origin and then
		rotates to match critter's attitude. So to just change a direction, we add on
		the _position before subracting it.*/
}

cVector cCritter::localToGlobalDirection(const cVector &localvec)
{
	return _attitude * localvec - _position;
		/* The _attitude transformation rotates to match critter, then translates
		to _position.  So to just change a direction, we subtract off the _position
		after we're done.*/
}

cVector cCritter::globalToLocalPosition(const cVector &globalpos)
{
	return _inverseattitude * globalpos;
}

cVector cCritter::localToGlobalPosition(const cVector &localpos)
{
	return _attitude * localpos;
}
		
//------------------------- cCritter motion methods -----------------

void cCritter::rotateAttitude(Real angle)
{
	rotateAttitude(cSpin(angle));
}

void cCritter::rotateAttitude(cSpin &spin)
{
/* When we rotate the attitude, we right multiply the rotation times the _attitude, so the fact
that the _position is in the _attitude doesn't matter. */

	_attitude *= cMatrix::rotation(spin);

#ifdef TRACEROTATEATTITUDE
	Real *aelements = _attitude.transpose().elements();
	TRACE("3D version of cCritter attitude() matrix in cCritter::rotateAttitude call.\n");
	TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
	TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
	TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
	TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
#endif //TRACEROTATEATTITUDE
}

void cCritter::animate(Real dt)
{
	updateAttitude(dt);
	_inverseattitude = _attitude.inverse();
	_psprite->animate(dt, this);
} 

void cCritter::updateAttitude(Real dt, BOOL forceattitudeadjustment)
{ 
	_attitude.setLastColumn(_position); //always update position.
//And then deal with the rotational aspect of _attitude in one of three ways.
	if (!_attitudetomotionlock)
		rotateAttitude(dt*_spin);
	else //_attitudetomotionlock is TRUE
		if (_speed >= _mintwitchthresholdspeed || forceattitudeadjustment) 
				//don't update attitude for tiny jostling unless caller insists.
			copyMotionMatrixToAttitudeMatrix(); 
#ifdef TRACEOPENGL
	Real *aelements = _attitude.transpose().elements();
	TRACE("3D version of cCritter attitude() matrix out cCritter::updateAttitude call.\n");
	TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
	TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
	TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
	TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
#endif //TRACEOPENGL
}

void cCritter::copyAttitudeMatrixToMotionMatrix() 
{
	_attitude.orthonormalize(); //To be safe.
	_tangent = attitudeTangent();
	_velocity = _speed * _tangent;
	_normal = attitudeNormal();
	_binormal = attitudeBinormal();
}

void cCritter::copyMotionMatrixToAttitudeMatrix()
{
	_attitude = cMatrix(_tangent, _normal, _binormal, _position); 
	_attitude.orthonormalize(); //To be safe.
}

void cCritter::setAttitudeTangent(const cVector &tangent)
{
	cVector oldtangent = attitudeTangent();
	cVector newtangent = tangent;
	newtangent.normalize();
#ifdef TRACEATTITUDE
	Real *aelements = _attitude.transpose().elements();
	TRACE("\n newtangent %f  %f  %f\n", newtangent.x(), newtangent.y(), newtangent.z());
	TRACE("oldtangent %f  %f  %f\n", oldtangent.x(), oldtangent.y(), oldtangent.z());
	TRACE("3D version of cCritter attitude() matrix in cCritter::setAttitudeTangent call.\n");
	TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
	TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
	TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
	TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
#endif //TRACEOPENGL
	if ((newtangent - oldtangent).isPracticallyZero())
		return;
	if (_attitudetomotionlock) // LOCK_ON
	{
		setTangent(tangent); 
		//updateAttitude(0.0, TRUE); 
			/* I could call this to set _attitude to match _tangent, _normal and _binormal.
			But seems safe to just wait for the updateAttitude to get called by cCritter::animate. */
	}	
	else //case of not _attitudetomotionlock
	{
		cMatrix turnmatrix = cMatrix::rotationFromUnitToUnit(oldtangent, newtangent); 
		/* When you multiply _atttude by a matrix to rotate it, you have to temporarily
			set the last column to 0.*/
		_attitude.setLastColumn(cVector::ZEROVECTOR);
		_attitude = turnmatrix * _attitude;
		_attitude.setLastColumn(_position);
		//_attitude.orthonormalize(); //Could do this to be safe, but is probably superflous.
	}	
}

BOOL cCritter::lookAt(const cVector &targetpos)
{
	cVector newtangent = targetpos - position();
	if (newtangent.isPracticallyZero()) //You can't look at this as it's on top of you.
		return FALSE;
	newtangent.normalize();
	cVector temporaryup = newtangent * attitudeNormal();
	if (temporaryup.isPracticallyZero())
		setAttitudeTangent(newtangent);
	else
	{
		cVector newnormal = temporaryup * newtangent;
		newnormal.normalize();
		setAttitude(cMatrix(newtangent, newnormal, newtangent*newnormal, _position));
	}
	return TRUE;
}

BOOL cCritter::lookAtProportional(const cVector &targetpos, Real amount)
{
	CLAMP(amount, 0.0, 1.0);
	cVector targettangent = (targetpos - _position).normalize();
	cVector weightedlookpos = _position +
		(1.0-amount)*attitudeTangent() + amount*targettangent;
	return lookAt(weightedlookpos);
}
		
void cCritter::setAttitude(const cMatrix &attitude) //Change tan, norm, binorm, but NOT position.
{
	_attitude = attitude;
	_attitude.setLastColumn(_position); /* Don't use the last column of the attitude argument. */
	if 	(_attitudetomotionlock) 
	{
		_tangent = attitudeTangent();
		_velocity = _speed*_tangent;
		_normal = attitudeNormal();
#ifdef THREEDVECTORS
		_binormal = attitudeBinormal();
#endif //THREEDVECTORS
		_oldtangent = _tangent; //So fixNormalAndBinormal doesn't undo this.
	}
}

void cCritter::resetAttitude()
{
	setAttitude(cMatrix::identityMatrix()); /* Note that setAttitude leaves _position in the last column, 
		so this doesn't	change position. */
}

void cCritter::orthonormalize()
{
	_tangent.normalize();
	_normal -= (_normal%_tangent)*_tangent; //Make it perpendicular to _tangent.
	_normal.normalize(); //Make it a unit vector.
	_binormal = _tangent * _normal;
	_oldtangent = _tangent;
}

void cCritter::rotate(const cSpin &spin)
{
	_tangent.rotate(spin);
	_velocity = _speed * _tangent;
	_normal.rotate(spin);
	_binormal.rotate(spin);
	_oldtangent = _tangent; //This signals fixNormalAndBinormal not to react to this.
}

void cCritter::yaw(Real turnangle) //Means rotate aroudn binormal axis.
{
	cSpin diryaw(turnangle, _binormal);
	_tangent.rotate(diryaw);
	_velocity = _speed * _tangent;
	_normal.rotate(diryaw);
	_oldtangent = _tangent; //This signals fixNormalAndBinormal not to react to this.
	updateAttitude(0.0, TRUE); //Force the attitude to reflect this change if _attitudetomotionlock.
}

void cCritter::roll(Real turnangle)
{
	cSpin rollturn(turnangle, _tangent);
	_binormal.rotate(rollturn);
	_normal.rotate(rollturn);
	_oldtangent = _tangent; //This signals fixNormalAndBinormal not to react to this.
	updateAttitude(0.0, TRUE); //Force the attitude to reflect this change if _attitudetomotionlock.
//	TRACE("rolled turnangle %f binormal %f %f %f\n", turnangle, _binormal.x(), _binormal.y(), _binormal.z());
}

void cCritter::pitch(Real turnangle)
{
	cSpin pitchturn(turnangle, _normal);
	_tangent.rotate(pitchturn);
	_velocity = _speed * _tangent;
	_binormal.rotate(pitchturn);
	_oldtangent = _tangent; //This signals fixNormalAndBinormal not to react to this.
	updateAttitude(0.0, TRUE); //Force the attitude to reflect this change if _attitudetomotionlock.
}

void cCritter::setTangent(const cVector &direction)
{
	if (direction.isPracticallyZero()) //ignore zero vector
		return;
	_tangent = direction;
	if (!in3DWorld()) //Don't tilt if you are in 2D world.
		_tangent.setZ(0.0); //Make sure z is zero.
	_tangent.normalize();
/* We are committed to always having _velocity = _speed * _tangent, so if we chane one
we need to change the other two. We do a more thorough checking, e.g. against _maxspeed,
in the cCritter::move method. */
	_velocity = _speed * _tangent;
	fixNormalAndBinormal();
}

void cCritter::setSpeed(Real speed)
{
	_speed = fabs(speed); //We don't allow negative speed.  To go backwards, reverse _tangent.
/* We are committed to always having _velocity = _speed * _tangent, so if we change one
we need to change the other two. We do a more thorough checking, e.g. against _maxspeed,
in the cCritter::move method. */
	_velocity = _speed * _tangent;
}

void cCritter::setVelocity(const cVector &velocity)
{
	_velocity = velocity;
	/*
	if (!in3DWorld()) //Don't tilt if you are in 2D world.
		_velocity.setZ(0.0); //Make sure z is zero.
	*/
/* We are committed to always having _velocity = _speed * _tangent, so if we change one
we need to change the other two. */
	synchSpeedAndDirectionToVelocity(); //This sets _speed and _tangent to match _velocity.
	fixNormalAndBinormal();
}

void cCritter::	synchSpeedAndDirectionToVelocity()
{ //This sets _speed and _tangent to match _velocity
		_speed = _velocity.magnitude();
		if (_speed > SMALL_REAL)  /*  Don't allow small positive speeds as they cause wobble,
			as when a mass is sitting on a border slightly bouncing. */
			_tangent = (1.0/_speed)*_velocity;
		else
			_speed = 0.0;
}

int cCritter::move(Real dt)
{
	_age += dt;
	_oldposition = _position; /* We save the _oldposition here so we can compare it with
		_position in cCritterWall::collide(cCritter *) to see if this move call jumps us
		over a wall. */
	if (_fixedflag)
		return BOX_INSIDE;
	_velocity += dt * _acceleration;
//Now clamp the _speed to be either 0.0 or between SMALL_REAL and _maxspeed.
	synchSpeedAndDirectionToVelocity(); //This sets _speed and _tangent to match _velocity.
	if (_speed > _maxspeed)
		_speed = _maxspeed;
	_velocity = _speed * _tangent; //Reset the _velocity in case you changed _speed.
//Now bounce or clamp, and when that's done do a final fix of _tangent, _tangent, and _binormal.
	addvelocityandcheckedges(dt); /* Do a bounce or wrap or clamp, depending on _wrapflag.
		The addvelocityandcheckedges call sets the _outcode field as well. */
	fixNormalAndBinormal(); /* Now that we're through changing the _velocity and the accompanying
		_tangent, make the _normal and _binormal (in 3D case) match.*/
	if (dt > SMALL_REAL) 
		_curvature /= dt;
	/* _curvature measures the rate at which the tangent is turning,
		specifically, if we write dTangent to stnad for the size change of the tangent
		vecotr, we want the size of dTangent/dt = _curvature.  
		Now, the code in fixNormalAndBinomral has set _curvature = dTangent,
		so now we have to divide by dt. */
	else
		_curvature = 0.0; //If you're not moving, you have no curvature.
//A totally different issue is to spin the aspect, but we do that in cCritter::animate.
	return _outcode;
} 

void cCritter::addvelocityandcheckedges(Real dt)
{ // This helper method is only called by cCritter::move.
	cRealBox effectiveborder = _movebox.innerBox(radius());
	if (_wrapflag == cCritter::BOUNCE)
	{
		_outcode = effectiveborder.addBounce(_position, _velocity, _bounciness, dt); /* The _position and
			_velocity arguments are passed as non-constant references, and may both be changed.
			Due to a possibly damped bounce (if _bounciness is less than 1.0), the newvelocity's
			speed can also change. */
		synchSpeedAndDirectionToVelocity();
	}
	else if (_wrapflag == cCritter::WRAP)
	{
		_position += dt * _velocity;
		_outcode = _movebox.wrap(_position, _wrapposition1, _wrapposition2,
			_wrapposition3, radius());
		if (_outcode)
			//	_oldposition = _position;
				 /* I used to do this because otherwise a wrap can make it look like a 
				critter moved through a wall because the outcodes of the two positions
				change. But when I upgdraded my cCritterWall::collide in May, 2003, 
				BUGFIX this broke the wall collide code!!!! */
			_oldposition = _position - dt * _velocity; /* This way the old position is
				in a correct orietnation relative to the wrapped position, even though
				the old position will probably be outside the _movebox */
	}
	else //_wrapflag == cCritter::CLAMP
	{
		_position += dt * _velocity;
		_outcode = effectiveborder.clamp(_position, _velocity);
		synchSpeedAndDirectionToVelocity();
	}
}


void cCritter::fixNormalAndBinormal()
{ // This helper method is called by cCritter::move, by cCritter::setVelocity and cCritter::setTangent.
#ifndef THREEDVECTORS
	_normal = _tangent;
	_normal.turn(PI/2.0); //No brainer!
	_oldtangent = _tangent; /* Have this line to match what we do at the end 
		of the 3D case, thoughwe don't actually use _oldtangent
		in the 2D case. */
	return;
#else //The THREEDVECTORS case
// Assume _tangent and _oldtangent are unit vectors.  Guess newnormal as the difference.
	cVector tangentchange = _tangent - _oldtangent;
//If _tangent has changed very little or none, just orthonormalize.
	if (tangentchange.isPracticallyZero()) //Nothing major has changed.
	{
		_curvature = 0.0;
		orthonormalize();
		return; 
	}
/* Otherwise we've made a substantial change in _tangent.  We could try and preserve the direction
of the normal as an "up", but instead we'll try and keep the normal pointing in the direction of the
latest turn, that is, guess that newnormral is (_tangent-olddirection).normalize(). */
	tangentchange -= (tangentchange%_tangent)*_tangent; //Make it perpendicular to _tangent.
	_curvature = tangentchange.normalizeAndReturnMagnitude(); 
		/*Make it a unit vector.  Also save the size of it as your curvature. */
	Real howparallel = tangentchange%_normal;
//Case where tangentchange is close to _normal
	if (howparallel > cVector::PRACTICALLY_PARALLEL_COSINE)
		/* If howparallel is near 1, then the vectors are
			nearly the same, so we comfortably will set _normal
			to tangentchange. */
		_normal = tangentchange;
//Case where tangentchange is close to -_normal
	else if (howparallel < -cVector::PRACTICALLY_PARALLEL_COSINE) 
		/* If howparallel is near -1, means _normal and
			tangentchange are pointing almost in opposite directions,
			which can happen if the critter has changed the direction
			its path is turning in.  We don't want to do an abrupt 180 degree
			flip in the normal as this will make a discontinuous flip in the
			binormal, so in this case we abandon our desire to have normal 
			pointing in the direction of the path's bending, and are satisfied
			to have it point in the opposite direciton of the bend, and nearly
			in the same direction as before. */
		_normal = -tangentchange;
//Hard case, where tangentchange is quite diffrent from _normal.
	else 
		/* The case where _normal and tangentchange have a medium dot product.
		This means not parallel, not antiparallel,  might
		happen if you have a zero tangentchange, or it's flipped by
		a bounce or a discontinous direction change like a
		mouse drag or a velocity impulse, and then we use a different
		method to find a new value for _normal. */
	{
		_curvature = 0.0;
		/* In this case its better not to try and guess at the cuvature */
//Make sure everything's kosher coming into the rotation.
		_tangent.normalize();
		_oldtangent.normalize();
		_normal.normalize();
		_normal -= (_normal%_oldtangent)*_oldtangent; //Make it perpendicular to _oldtangent.
		if (!in3DWorld()) //If you're in a 2D world
			_normal.setZ(0.0); //Dont' let anything sneak into normal._z.
		_normal.normalize(); //Make it a unit vector.
#ifdef TRACEFIXNORMAL
	TRACE("Using _oldtangent (%f, %f, %f) and _normal  (%f, %f, %f)\n", 
		_oldtangent.x(), _oldtangent.y(), _oldtangent.z(), 
		_normal.x(), _normal.y(), _normal.z());
#endif //TRACEFIXNORMAL
		cMatrix turnmatrix = cMatrix::rotationFromUnitToUnit(
			_oldtangent, _tangent); 
			/* This is a computation-intensive method in 3D,
			 so we don't call it unless we have to. */
		_normal = turnmatrix * _normal;
//Make sure everything's kosher coming out of the rotation.
		_normal -= (_normal%_tangent)*_tangent; //Make it perpendicular to _tangent.
		_normal.normalize(); //To be safe.
#ifdef TRACEFIXNORMAL
	TRACE("New _tangent (%f, %f, %f) and _normal  (%f, %f, %f)\n", 
		_tangent.x(), _tangent.y(), _tangent.z(), 
		_normal.x(), _normal.y(), _normal.z());
#endif //TRACEFIXNORMAL
	}
	cVector oldbinormal = _binormal; //Save this for use in the NOFLIPBINORMAL code.
	_binormal = _tangent *_normal; //Fix the binormal.
	_binormal.normalize();

#ifdef NOFLIPBINORMAL
// Don't allow this method to unexpectedly flip the binormal.  Always call this to be safe.
//	if ((_binormal + oldbinormal).isPracticallyZero()) //You flipped over. Undo it.
	if ((_binormal % oldbinormal)<0.0) //You flipped over. Undo it.
	{ //By the way, you don't want to use this test in the 2D case, as both vects will be 0.
		_binormal  = oldbinormal;
		_normal = _binormal * _tangent;
	}
#endif //NOFLIPBINORMAL
	_oldtangent = _tangent;	/* We're done with _tangent and _oldtangent for now.  So we 
		save the current _tangent. The fixNormalAndBinormal method won't 
		get called again till the end of the next move method call, so whatever happens to _tangent
		will be accumulated and taken into account, whether the changes come from forces, from 
		listeners, from collisions or from the next move. */

#ifdef TRACEPLAYERFIXNORMAL
	if (_pownerbiota && this == pplayer())
	{
		TRACE("\nPlayer trihedron vectors after fixNormalAndBinormal call.\n");
		TRACE("Direction %f  %f  %f \n", _tangent.x(), _tangent.y(), _tangent.z());
		TRACE("Normal %f  %f  %f \n", _normal.x(), _normal.y(), _normal.z());
		TRACE("Binormal %f  %f  %f \n", _binormal.x(), _binormal.y(), _binormal.z());
	}
#endif

#endif //THREEDVECTORS case
}

COLORREF cCritter::sniff(const cVector &snifflocation, CPopView *pactiveview)
{
	return pactiveview->sniff(snifflocation);
}

void cCritter::setCollidePriority(Real collidepriority)
{ //Rebuild the pgame()->_pcollider just in case.
	_collidepriority = collidepriority;
	pgame()->buildCollider();
}

int cCritter::collidesWith(cCritter *pcritterother)
{
	/* I only call this within cCollider::smartAdd, which is called in such a way to
	ensure the ASSERT condition.  But I check it for testing. */
	ASSERT(pcritterother != this);
	int othercollidepriority =  pcritterother->collidePriority();
	if (_fixedflag && pcritterother->fixedflag())
		return cCollider::DONTCOLLIDE;
	if (_collidepriority == othercollidepriority)
		return cCollider::COLLIDEEITHERWAY;
	if (_collidepriority > othercollidepriority)
		return cCollider::COLLIDEASCALLER;
	//else (_collidepriority < othercollidepriority)
	return cCollider::COLLIDEASARG;
}

/* The way collide works is that (a) the momentum is conserved and (b) the energy is
conserved.  We get (a) Ma*newVa  +  Mb*newVb ==  Ma*Va  +  Mb*Vb, and
 (b) (1/2)*((Ma*newVa^2 +  Mb*newVb^2)) == (1/2)*(Ma*Va^2 +  Mb*Vb^2).
This is the intersection of a line and an ellipse, which is two points.
I ran this through Mathematica and came up with the trivial solution
newVa = Va and newVb = Vb and the one we'll use:
newVa = (Ma*Va - Mb*Va + 2*Mb*Vb) / (Ma + Mb)
newVb = (2*Ma*Va - Ma*Vb + Mb*Vb)/ (Ma + Mb).
If I divide both numerators and denominators by Ma, and call Mb/Ma "massratio" I get
newVa = (Va - massratio*Va + 2*massratio*Vb) / (1 + massratio)
newVb = (2*Va - Vb + massratio*Vb)/ (1 + massratio).
Simplifying a little more, we get
newVa = ((1-massratio)*Va + 2*massratio*Vb) / (1 + massratio)
newVb = (2*Va + (massratio - 1)*Vb)/ (1 + massratio).
Note that if massratio is 1, then this is simply newVa = Vb and newVb = Va.
If a has a huge (infinite) mass compared to b, then massratio is about 0 and
we get newVa = Va, newVb = 2Va - Vb, so if a is motionless, this is a simple bounce.
	Now suppose we want to take into account the _bounciness of the critters, which
we might label as Ba and Bb.  I'm not sure yet how best to incorporate these into
the equations.  For now let's make a (probably incorrect) thess that the right thing is to
attentuate the new velocity by the bounciness of the critter, so that any collision attenuates
an inelastic critter's velocity.
newVa = Ba*((1-massratio)*Va + 2*massratio*Vb) / (1 + massratio)
newVb = Bb*(2*Va + (massratio - 1)*Vb)/ (1 + massratio).
 */

BOOL cCritter::collide(cCritter *pother)
{
	cVector toOther;
	Real distanceToOther;
	Real givecomponent;
	cVector give;
	Real receivecomponent;
	cVector receive;
	Real massratio;
	cVector contactpoint;

	if (pother == this)
		return FALSE;
	cDistanceAndDirection distanceanddirection = distanceAndDirectionTo(pother);
	distanceToOther = distanceanddirection._distance;
	if (distanceToOther > radius() + pother->radius())
		return FALSE;
	toOther = distanceanddirection._direction;
	givecomponent = (_velocity % toOther);
	give = givecomponent * toOther; 
	receivecomponent = pother->_velocity % toOther;
	receive = receivecomponent * toOther; //else leave it at 0.
/* We think of the calling critter as having a mass of 1, so we
give the other critter a proportional to the cube or the square of the radius 
ratios.  Either one works pretty well, though the cube seems to look more realistic,
that is, looks more like what we're used to seeing. */
	if (!radius()) //Check because we'll divide by this.
		return FALSE;  
	massratio = pother->mass()/mass(); /* The mass() function is by default
		pow(radius(), 3.0), but we overload it for player to be very large. */
	Real massdivisor = (1.0/(1.0 + massratio)); //Use this twice, so calculate once.
/* Now we subtract off the components of velocity that lie along the line
of collision and add in the new components. */
#ifndef USEBOUNCINESS //Old way
	if (!_absorberflag  && !_fixedflag)
		setVelocity(_velocity - give + //This would be ZEROVECTOR in the 1D case.
			massdivisor * ((1.0 - massratio)*give + 2.0*massratio*receive)); //Our formula
	if (!pother->absorberflag() && !pother->fixedflag())
		pother->setVelocity(pother->_velocity -receive + 
			massdivisor * (2.0*give + (massratio - 1.0)*receive));
#else //USEBOUNCINESS defined means use _bounciness
	if (!_absorberflag  && !_fixedflag)
		setVelocity(_velocity - give + 
			_bounciness * massdivisor * ((1.0 - massratio)*give + 2.0*massratio*receive));
	if (!pother->absorberflag() && !pother->fixedflag())
		pother->setVelocity(pother->_velocity - receive + 
			pother->bounciness()*massdivisor * (2.0*give + (massratio - 1.0)*receive));
#endif //end USEBOUNCINESS switch
/* In general we want to move the critters apart so that they are just touching
at a point we call contactpoint, on the line between the two centers.
Rather than making contactpoint the midpoint, we weight it so that it divides
this line in the same ratio as radius and pother->radius().  That
is, we need to pick a sublength "contactdistance" of the "distance"
length between the two centers so that 
radius/radius+otheradius = contactdistance/distance.
Multiply both sides of this equation to solve for contactdistance,
which is the multiplier of toOther in the line just below. */
	if (!_fixedflag && !pother->fixedflag())
	{
		contactpoint = _position +
			((radius()*distanceToOther)/(radius()+pother->radius()))*toOther;
		moveTo(contactpoint - radius()*toOther, TRUE); /* The TRUE arg here means that
			we should treat motion as a physical thing that can change the
			_tangent, _normal, and _binormal. */
		pother->moveTo(contactpoint + pother->radius()*toOther, TRUE);
	}
/* We special case the situations where one of the critters must remain fixed, such
as a bumper in a pinball game. */
	else if (_fixedflag && !pother->fixedflag())
		pother->moveTo(_position + (radius() + pother->radius())*toOther, TRUE);
	else if (!_fixedflag && pother->fixedflag())
		moveTo(pother->position() - (radius() + pother->radius())*toOther, TRUE);
//else the (_fixedflag && pother->fixedflag()) case, where we move neither.
	return TRUE;
}

//----------------------- cCritter sound methods ------------------

void cCritter::playSound(CString wavfileresourcename)
{
	((CPopApp*)::AfxGetApp())->playSound((LPCSTR)wavfileresourcename);
}

void cCritter::playMusic(const char* wavMidiFilename)
{
	((CPopApp*)::AfxGetApp())->playMusic(wavMidiFilename);
}

void cCritter::stopSound()
{
	((CPopApp*)::AfxGetApp())->stopSound(); //Terminate any currently playing sound so you're more likely to hear this.
}

void cCritter::stopMusic()
{
	((CPopApp*)::AfxGetApp())->stopMusic(); //Terminate current music
}

//------------------------ cCritter draw methods --------------------

cRealBox cCritter::realBox()
{
	if (!pgame()->in3DWorld()) //It's a two-dimensional game.
		return cRealBox(cRealBox2(_position, 2*radius()));
		//Smallest square holding the critter.
	else
		return cRealBox(_position, 2*radius());
		//Smallest cube holding the critter.
} 



/* The cCritter::draw method is hard to read, as we have so many #ifdef in it.  Here, for 
reference, is a simplified version of what the code does: 
void cCritter::draw(cGraphics *pgraphics, int drawflags)
{
	if (recentlyDamaged())
		drawflags |= CPopView::DF_WIREFRAME; 
	pgraphics->pushMatrix();  
	pgraphics->multMatrix(_attitude);
 	_psprite->draw(pgraphics, drawflags); 
	pgraphics->popMatrix();
}
*/

void cCritter::draw(cGraphics *pgraphics, int drawflags) //Look at simple listing just above.
{
#ifdef SHOWDAMAGE
//	if (_health == 0)
//		drawflags |= CPopView::DF_WIREFRAME; 
		/* Draw yourself as a"shadow of yourself" if you're dead.  We comment
		this out for good, as it only causes confusion.  There are better ways to show
		that you're health is gone. */
	if (recentlyDamaged())
		drawflags |= CPopView::DF_WIREFRAME; 
			/* I used to do this to draw yourself as a "shadow of yourself" 
			if you're  recently damaged.  Note that DF_WIREFRAME
			doesn't affect bitmaps as long as DONTWIREFRAMEBITAPS is
			#defined in	graphics.h.  But now I discover that this causes
			a flash in the colors in 3D graphics, so I'm not using it. */
#endif //SHOWDAMAGE
#ifdef CLIP2D
	if (_wrapflag == WRAP)
		pgraphics->setClipRegion(&_movebox);
	else
		pgraphics->setClipRegion(NULL);
#endif //CLIP2D
/* The clipping code, along with the  code at the
end of the draw function, is present so as to (a) make multiple sprites when we
are in wrap mode, but (b) to clip the pieces of the multiples that lie outside
_movebox.  The reason for (a) is so that a sprite won't seem to jump from, say,
the left side to the right side.  Instead you'll see part on the left and part
on the right while it's moving.  In the corner case this means you need four
sprites, and in the edge cases you need two sprites.  The idea behind (b)
is not to draw the pieces of the sprites that lie outside of the _movebox.  */
	/* We don't have to call _psprite->moveTo(_position) because we call this inside
		the render method that gets called in the draw method. */
#ifdef TRACEOPENGL
Real *aelements = attitude().transpose().elements();
#ifndef THREEDVECTORS
TRACE("2D version of cCritter attitude() matrix in cCritter::draw call.\n");
TRACE("%f  %f  %f  \n", aelements[0], aelements[3], aelements[6]);
TRACE("%f  %f  %f \n", aelements[1], aelements[4], aelements[7]);
TRACE("%f  %f  %f \n", aelements[2], aelements[5], aelements[8]);
#endif //THREEDVECTORS
aelements = cMatrix3(attitude()).transpose().elements();
TRACE("3D version of cCritter attitude() matrix in cCritter::draw call.\n");
TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
pgraphics->matrixMode(cGraphics::MODELVIEW);
GLfloat elements[16];
glGetFloatv(GL_MODELVIEW_MATRIX, elements);
TRACE("OpenGL Modelview matrix in cCritter::draw call before push.\n");
TRACE("%f  %f  %f  %f\n", elements[0], elements[4], elements[8], elements[12]);
TRACE("%f  %f  %f  %f\n", elements[1], elements[5], elements[9], elements[13]);
TRACE("%f  %f  %f  %f\n", elements[2], elements[6], elements[10], elements[14]);
TRACE("%f  %f  %f  %f\n", elements[3], elements[7], elements[11], elements[15]);
#endif //TRACEOPENGL
//CORE CODE IS HERE *****************************************************
	pgraphics->pushMatrix();  //Normal call just does these three lines followed by the popMatrix below.
	pgraphics->multMatrix(_attitude);
 	_psprite->draw(pgraphics, drawflags); 
//CORE CODE IS HERE *****************************************************
#ifdef TRACEOPENGL
glGetFloatv(GL_MODELVIEW_MATRIX, elements);
TRACE("OpenGL Modelview matrix in cCritter::draw call after multiply.\n");
TRACE("%f  %f  %f  %f\n", elements[0], elements[4], elements[8], elements[12]);
TRACE("%f  %f  %f  %f\n", elements[1], elements[5], elements[9], elements[13]);
TRACE("%f  %f  %f  %f\n", elements[2], elements[6], elements[10], elements[14]);
TRACE("%f  %f  %f  %f\n", elements[3], elements[7], elements[11], elements[15]);
#endif //TRACEOPENGL

// If you want to check the orientation of the critters, DRAWMOVINGTRIHEDRON is useful.
#ifdef DRAWMOVINGTRIHEDRON
	cColorStyle dummy;
	dummy.setLineColor(cColorStyle::CN_RED);
	pgraphics->drawline(cVector::ZEROVECTOR, 2.0 * cVector::XAXIS, &dummy);
	dummy.setLineColor(cColorStyle::CN_BLUE);
	pgraphics->drawline(cVector::ZEROVECTOR, cVector::YAXIS, &dummy);
	dummy.setLineColor(cColorStyle::CN_YELLOW);
	pgraphics->drawline(cVector::ZEROVECTOR, cVector::ZAXIS, &dummy);
#endif //DRAWMOVINGTRIHEDRON

	if (_wrapflag == WRAP && !pgraphics->is3D())
		/* Disable the wrapicon trick for 3D until
		maybe someday we get 3D clip working with 3D clip planes. */
	{
#ifdef WRAPICON
		cMatrix wrapattitude = attitude();
		if (!(_wrapposition1 == _position)) 
		{
			wrapattitude.setLastColumn(_wrapposition1);
			pgraphics->popMatrix();
			pgraphics->pushMatrix();
			pgraphics->multMatrix(wrapattitude);
			_psprite->draw(pgraphics, drawflags);
			if (!(_wrapposition2 == _position)) 
			{
				wrapattitude.setLastColumn(_wrapposition2);
				pgraphics->popMatrix();
				pgraphics->pushMatrix();
				pgraphics->multMatrix(wrapattitude);
				_psprite->draw(pgraphics, drawflags);
				wrapattitude.setLastColumn(_wrapposition3);
				pgraphics->popMatrix();
				pgraphics->pushMatrix();
				pgraphics->multMatrix(wrapattitude);
				_psprite->draw(pgraphics, drawflags);
			}
		}
#endif //WRAPICON
	}
//CORE CODE IS HERE *****************************************************
	pgraphics->popMatrix();
//CORE CODE IS HERE *****************************************************
#ifdef CLIP2D
	if (_wrapflag == WRAP) 
		pgraphics->setClipRegion(NULL);//If you changed the clip region, set back to whole client.
#endif //CLIP2D
}

// Modified by: Joseph E. Sutton - changed circle size, color and translation
void cCritter::drawHighlight(cGraphics *pgraphics, Real highlightsizeratio)
{
	Real focusradius = highlightsizeratio * radius() + 0.2;
	cSpriteCircle focuscircle;
	focuscircle.setFilled(FALSE);
   
   COLORREF color = RGB(0, 167, 202);

	focuscircle.setLineColor( color );
   focuscircle.setFillColor( color );
	focuscircle.setRadius(focusradius);
	focuscircle.setPrismDz(0.0);

	pgraphics->pushMatrix();
	pgraphics->multMatrix(attitude()); 

   cVector v = psprite()->center();
   v += cVector(-1.1, -0.4, 0.01);
   pgraphics->translate(v); 
	//pgraphics->translate(psprite()->center() + 0.01*cVector::ZAXIS); 

		//Scoot in case the sprite is off-center, also  scoot out of the plane.
	focuscircle.draw(pgraphics);
//	pgraphics->drawcircle(cVector::ZEROVECTOR, psprite()->radius(), &highlightcolorstyle);
	pgraphics->popMatrix();
}
