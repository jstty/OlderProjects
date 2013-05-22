//////////////////////////////////////////////////////////////////////
// Critter.h: interface for the cCritter class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CRITTER_H
#define CRITTER_H
#include "randomizer.h"
#include "realbox.h"
#include "realpixelconverter.h"
#include "vectortransformation.h"
#include <mmsystem.h> //For PlaySound flags
class cGraphics;

#define USEBOUNCINESS //Compile switch used in critter.cpp, critterwall.cpp, realbox.cpp.

	/* We don't need to include the headers for the following classes as
	we only mention them as pointers.  In general, we only include a header in a header if
	we absolutely have to.  Here we can get by with forward class declarations that simply
	say such and such a class exists.  Of course we will need to include the headers in the
	critter.cpp which is where we actually use the properties of these classes. */
class cBiota; //For the *_pownerbiota member.
class cSprite; //For the *_psprite member.
class cListener; //For *_plistener member.
class cForce; //For _forcearray member.
class cDistanceAndDirection; // Return type of the distanceAndDirection function. 
class CPopView; //Used as an argument to sniff.
class cGame; //For the return type of the pgame() method.
class cGraphics; //For the draw method.

class cCritter : public CObject
{
DECLARE_SERIAL(cCritter);  /* An MFC macro used to enable CRuntimeClass reflection
	of class type, dynamic creation, and serialization. */
public:
// Statics =========================================
//Constant Statics =================================
	//The MF_ statics are mutation flags used in the mutate methods.
	//They are defined in static.cpp.
	static const int MF_NUDGE;
	static const int MF_POSITION;
	static const int MF_VELOCITY;
	static const int MF_ALL; //MF_POSITION | MF_VELOCITY
	//Wrapflag values specify possible behaviors when critter hits edge of world.
	static const int BOUNCE;
	static const int WRAP;
	static const int CLAMP;
	//special high density used for player or other immovable critter.
	static const Real INFINITEDENSITY;
//Variable Statics =================================
	//These might (rarely) be reset by a cGame constructor.
//Motion Statics =================================
	static Real MINSPEED; //Used in randomizing critter _speed.
	static Real MAXSPEED; // Used in randomizing, and to clamp _speed in move(dt).
	static Real MINTWITCHTHRESHOLDSPEED; //Default for _mintwitchthresholdspeed
	static Real NEAREDGEPERCENT; // Default arg for moveToMoveboxEdge.
	static BOOL STARTWRAPFLAG;
	static Real DENSITY; //Default density.
//State Statics =================================
	static Real MUTATIONSTRENGTH; //Default argument to mutate method.
	static Real MINRADIUS; //Used in randomizing
	static Real MAXRADIUS;
	static Real BULLETRADIUS; //Gets set to cGame::BULLETRADIUS in cGame constructor.
	static Real PLAYERRADIUS; 
	static Real LISTENERACCELERATION; //Default for _listeneracceleration
	static int STARTHEALTH; //Default is 1.
	static Real SAFEWAIT; /* Time in seconds of invulnerability, use at start up and after
		damage, gives critters breathing room so they don't get damaged twice in a row,
		like by the same bullet volley. */
	static Real FIXEDLIFETIME; // Default lifetime for critters with _usefixedlifetime TRUE.
protected:
//================================================
//State Fields. =================================
//================================================
	Real _age; //Measure in seconds of time simulated, start at 0.0 when constructed.
	BOOL _usefixedlifetime; //If TRUE, then die when _age > _fixedlifetime.
	Real _fixedlifetime;  //Max lifetime in seconds, applies only if _usefixedlifetime.
	int _health;  //Lose by being hit and taking damage().  Usually die when _health is 0.
	BOOL _shieldflag; //Immunity to being damage() calls.
	UINT _personality; /* Random bits to sometimes use for making critters have different
		behaviors, as when using evasion forces. */
	Real _mutationstrength; /* Number between 0.0 and 1.0 controlling how different
		a spawned copy will be. */
	cCritter *_ptarget;/* In case you are following or dragging or watching or aimed at
		someone else, use this field to track them. _ptarget is one of the only fields
		that is NOT serialized. We use the _targetindex with the _pownerbiota to copy
		or serialize _ptarget. */
//================================================
//Game Fields =================================
//================================================
	cBiota *_pownerbiota; /* Used in makeServiceRequest and in other places.  It allows
	the	critter to be aware of all the other critters. Gets set by
	the cCritter(cGame *pownergame) constructor. _pownerbiota is NOT serialized. */
	int _score; //Usually gain by eating or shooting others.
	int _value; //Value to another critter shooting or eating this one.
	int _newlevelscorestep; //Step size between score levels that are rewarded.
	int _newlevelreward; //Health reward for new score level.
//================================================
//Motion Fields. =================================
//================================================
//Position Fields =================================
	cVector _position;
	cRealBox _movebox; //Keep critter inside _movebox.
	cRealBox _dragbox; /* Usually same as _movebox, but in cGamePickNPop, it's bigger, so
		can drag a critter outside of its _movebox. */ 
	int _wrapflag; //BOUNCE, WRAP, or CLAMP when you bump a wall.
	int _outcode; // Flag info about which wall, if any, the last move bumped.
//Velocity Fields =================================
	BOOL _fixedflag; //Refuse to move.
	cVector _velocity;
	Real _speed; 
	cVector _tangent; /* We always keep _velocity = _speed * _tangent.  It's
		useful to have _tangent around even when _speed goes to 0 and _velocity
		is zero, this way we know what direction to start back up in. */
	cVector _normal; /* We maintain a _normal and _binormal vector to fully
		express the	motion of the critter through 3D space. */
	cVector _binormal; //Always cVector::ZAXIS in 2D worlds.
	Real _curvature; /* This measures the rate at which the tangent is turning,
		specifically, we adjust it so that the change of the tangent vector has
		size _curvature * dt.  See Frenet formula dT/dt = _curvature * N. */
	Real _maxspeed; //Clamp _speed below this in move().
	Real _maxspeedstandard;/* In case  _maxspeed might be temporarily increased, for
		instance if the critter is allowed to move extra fast while
		fleeing or chasing another. */
//Acceleration Mass, and Force Fields =================================
	cVector _acceleration; /* _acceleration gets reset during every cycle, using the
		_forcearray and possibly the _plistener to change it. */
	Real _mass; //Use fixMass() helper to maintain _mass = _density * radius()^3.
	Real _density; /* Default is 1.  We often assign the cCritterPlayer a very 
		large _density so that it can whack others around. */
	CTypedPtrArray<CObArray, cForce*> _forcearray; //We serialize this array
//Listener Fields. =================================
	cListener *_plistener; //Never NULL.  We serialize the plistener.
	Real _listeneracceleration; /* This is the acceleration used by listeners such as
		cListenerCar and cListenerSpaceship that "drive" the critter around. Like the
		critter's engine strength. */
//Collision Fields =================================
	Real _collidepriority;
	/* These are default cCritter _collidepriority values, in increasing size for
		increasingly high priority, where in a pair of critters, the higher priority
		critter is the caller of the collide method, and the lower priority critter
		is the argument to the collide call. */
	Real _lastcollidepartnerpriority; /* At each fresh call of cGame::collide, I reset all
		the critters' _lastcollidepartnerpriority to cCollider::CP_MINIMUM, and then set to match the 
		_collidepriority of the latest collision allowed.  If I find multiple collisions
		cause problems, I may want to disallow later, lower priority collisions. */
	Real _absorberflag; /* Don't change your own velocity after a collision.  This
		siphons energy out of the system, cooling down the motions by absorbing it. */
	Real _bounciness; /* ranges from 0.0 to 1.0.  Determines how elastically
		you bounce off of walls	or off of other critters.  1.0 is perfect bounce,
		0.9 is pretty reasonable, 0.0  don't bounce at all. */
	Real _mintwitchthresholdspeed; /* If we have _attitudetomotionlock, 
		and we have some critters barely bouncing on a "floor" it looks bad if they
		keep twitching their orientation up and down.  Don't change the _attitude to
		match the motion if the speed is less than _mintwitchtriggerspeed. */
//================================================
//Attitude and Display Fields =================================
//================================================
	cSprite *_psprite; //Never NULL.  We serialize the _psprite.
	BOOL _attitudetomotionlock; /* Shall I lock together the display sprite and
		the motion? By default the player has _attitudetomotionlock
		FALSE and all other critters have it TRUE. */
	cMatrix _attitude; /* The attitude expresses the way that the critter
		is situated for rendering.  When _attitudetomotionlock is
		TRUE, _attitude has the columns	_tangent, _normal, _binormal, _position.
		 If _attitudetomotionlock is FALSE, _attitude can be instead controlled by
		_spin or by the _plistener actions. The _attitude transformation rotates
		to match the standard ijk trihedron to the critter's _tangent-_normal-
		_binormal trihedron, then translates the origin to _position. */
	cMatrix _inverseattitude; /* If we eventually want to do box-style collisions instead of 
		sphere-style collisions, it will be useful to have the _inverseattitude 
		available to convert global coordinates into the local coordinates of the
		critter. Certainly we'll need this for cCritteWall, and maybe later for
		character critters. We will update this in the cCritter::update method. 
		The _inverseattitude transformation does a translation that moves _position to
		origin and then	rotates to match the standard ijk trihedron to the critter's
		_tangent-_normal-_binormal trihedron. */
	cSpin _spin; /* A cSpin holds the spinangle in radians per second and
		the spinaxis which is the axis to spin around (z by default).  Presently
		used only when _attitudetomotionlock is OFF. */
	Real _defaultprismdz; /* We copy this into the psprite's _prismdz field in setSprite.  
		If we are in 3D and if the sprite is, for instance, a polygon that makes use of 
		the _prismdz field, then _prismdz will determine the z-thickness of the sprite. */
//================================================
//Bookkeeping Fields =================================
//================================================
//Serialized Bookkeeping Fields =================================
	Real _lasthit_age; //Age at last hit (or age at birth), use to time invulnerability.
	BOOL _oldrecentlydamaged; // Used in update() in connection with sprite display lists.
	cVector _oldposition; //This is used by the cCritterWall::collide method.
	cVector _oldtangent; //This is used by the cCritter::fixNormalAndBinormal method.
	cVector _wrapposition1, _wrapposition2, _wrapposition3; //Use for showing wrap in 2D
	int _targetindex; /* _targetindex is a dummy used to copy and serialize the _ptarget
		pointer	reference. */
//Nonserialized Bookkeeping Fields =================================
	int _metrickey; /* Index into the _pownerbiota cBiota's _metric, can be used to
		look up metric values. _metrickey is NOT serialized.*/
public:
//================================================
//Constructor and destructor and helpers =================================
//================================================
	cCritter(cGame *pownergame = NULL); /* Initializes fields, adds to pownergame
		if not null. With the NULL default for the pownergame argument, this  constructor
		doubles	as a no-argument constructor.  */
	virtual void copy(cCritter *pcritter);  /* Helper function for copy 
		constructor, and for clone method. */
	cCritter(cCritter *pcritter); //copy constructor
	cCritter* clone(); /* Returns a pointer to a cCritter of the same child class
		type, with the same info in it. */
	virtual ~cCritter(); /* deletes pointer members and calls
		cBiota::removeReferencesTo(this). The destructor is virtual so that child
		critter destructors can do extra cleanup before the baseclass destructor. */
	void removeReferencesTo(cCritter *pdeadcritter); /* Don't let pdeadcritter be
		the _ptarget or the pnode() of any cForceObject in the _forcearray. */
//================================================
//Mutators =================================
//================================================
//State Field Mutators  =================================
	void setValue(int value){_value = value;}
		//The velocity, direction, and speed mutators always keep _velocity = _speed * _tangent.
	void setShield(BOOL shield){_shieldflag = shield;}
	void setUseFixedLifetime(BOOL yesno){_usefixedlifetime = yesno;}
	void setFixedLifetime(Real lifetime){_fixedlifetime = lifetime;}
	void setMutationStrength(Real mutationstrength){_mutationstrength = mutationstrength;}
	virtual void setTarget(cCritter *pcritter){_ptarget = pcritter;} /* Comes in handy
		sometimes, though more often I'll use a cForceObject. */
	void setMetricKey(int i){_metrickey = i;}
	virtual void reset(); //can overload to do special things.
	virtual void setAge(Real age){_age = age; _lasthit_age = _age - cCritter::SAFEWAIT;}
		//overloaded by cCritterArmedRobot.
//Game Field Mutators =================================
	void setOwner(cBiota* pownerbiota){_pownerbiota = pownerbiota;} 
		//Used in Add and CBiota::Serialize
	virtual void addScore(int scorechange); 
	void setHealth(int health){_health = health; if(_health<0)_health=0;} /* We can add
		health points at certain score levels. Or by eating health packs. */ 
	void addHealth(int healthchange){setHealth(_health + healthchange);}
	void setNewlevelreward(int healthgain){_newlevelreward = healthgain;}
	void setNewlevelscorestep(int pointspread){_newlevelscorestep = pointspread;}
//================================================
//Motion Field Mutators =================================
//================================================
//Position Field Mutators =================================
	int setMoveBox(const cRealBox &box);
	void setDragBox(const cRealBox &box){_dragbox = box;}
	virtual void setWrapflag(int wrapflag); //We have a kludge overload for cCritterWall
	virtual int moveTo(const cVector &newposition, BOOL treatascontinuousmotion = FALSE);
		 /* Do the move, and then clamp against _movebox, return outcode of clamp. */
	virtual int moveToZ(Real z){return moveTo(cVector(_position.x(), _position.y(), z));}
		/* I use moveToZ in cGamePickNPop::seedCritters. */
	virtual int moveToProportional(const cVector &newposition, Real proportion,
		BOOL treatascontinuousmotion = FALSE); /* Proportion
		between 0.0 and 1.0 is how much of the way you want to move towards newposition. */
	virtual int dragTo(cVector newposition, Real dt); /* Move and clamp against
		_dragbox, return outcode. In addition, use dt to set critter velocity to match
		the drag velocity. I make it virtual so cCritterWall can overload to NOT change
		the velocity.  newposition isn't passed as a reference, as the dragTo
		method may possibly change it. */
 	void moveToMoveboxEdge(Real percent = cCritter::NEAREDGEPERCENT); 
 		//Useful in some games, to start a critter near the _movebox edge.
//Velocity Field Mutators =================================
	void setFixedflag(BOOL flag){_fixedflag = flag;}
	void setVelocity(const cVector &velocity);
	void addVelocity(const cVector velocitychange){setVelocity(_velocity + velocitychange);}
	void setTangent(const cVector &direction);
	void rotate(const cSpin &spin); //cSpin is a way to express general 3D angles.
	void yaw(Real turnangle); //Rotate around _binormal. 
	void roll(Real turnangle); //Rotate around _tangent
	void pitch(Real turnangle); //Rotate around _normal
	void orthonormalize(); //Make sure _tangent, _normal, _binormal are orthogonal units.
	void setSpeed(Real speed);
	void setMaxspeed(Real maxspeed){_maxspeed = _maxspeedstandard = maxspeed;}
	void setTempMaxspeed(Real maxspeed){_maxspeed = maxspeed;} 
	void restoreMaxspeed(){_maxspeed = _maxspeedstandard;}
//Acceleration, Mass and Force Field Mutators =================================
	void setAcceleration(const cVector &acceleration){_acceleration = acceleration;}
	void addAcceleration(const cVector &acceleration){_acceleration += acceleration;}
	void setDensity(Real density){_density = density; fixMass();}
	void fixMass(); //Keep _mass = _density * _radius()^3.
	void addForce(cForce *pforce);
	void clearForcearray();
	void copyForcearray(cCritter *pcritter); /* This helper method will empty the existing
		force array and copy all of the forces in the pcritter force array.  */
	virtual void copyPhysicsForces(cCritter *pcritter); /* A more modest kind of force
		copying. Here we don't wipeout the existing forces in the caller, and we only
		copy the "physics" forces like cForceGravity and cForceDrag from pcritter.  Use
		the BOOL cForce::isGlobalPhysicsForce() to tell us which ones.  We need this
		method so that bullets can copy the physics of their shooters but not their
		behavioral forces.  */
//Listener Field Mutators =================================
	void setListener(cListener *plistener); 
	void setListenerAcceleration(Real la){_listeneracceleration = la;}
//Collision Field Mutators =================================
	void setMinTwitchThresholdSpeed(Real twitchspeed)
		{_mintwitchthresholdspeed = twitchspeed;}
	void setBounciness(Real bounciness)
		{CLAMP(bounciness, 0.0, 1.0); _bounciness = bounciness;}
	void setAbsorberflag(BOOL flag)
		{_absorberflag = flag; _absorberflag?_bounciness=0.0:_bounciness=1.0;}
	void setCollidePriority(Real collidepriority); //Rebuild the pgame()->_pcollider just in case.
	void setLastCollidePartnerPriority(Real priority){_lastcollidepartnerpriority = priority;}
//================================================
//Attitude and Display Field Mutators =================================
//================================================
	void setSprite(cSprite *psprite);
	void setSpin(cVector3 spinvector){_spin = cSpin(spinvector);}
	void setAttitudeToMotionLock(BOOL lockmode){_attitudetomotionlock = lockmode;}
	void setSpin(Real spinangle, cVector3 spinaxis = cVector::ZAXIS)
		{_spin = cSpin(spinangle, spinaxis);}
	void rotateAttitude(Real angle);//{_attitude *= cMatrix::rotation(angle);}
	void rotateAttitude(cSpin &spin);//{_attitude *= cMatrix::rotation(spin);}
	void setAttitude(const cMatrix &attitude); /* This changes the orientation aspect
		of _attitude, but NOT the _position aspect, that is, it leaves the last
		column alone. */
	void resetAttitude(); /* Assume the identity orientation. */
	void setAttitudeTangent(const cVector &tangent); /* points _attitude in tangent
		direction.  If _attitudetomotionlock is TRUE, we move _tangent to match. */
	void copyMotionMatrixToAttitudeMatrix(); 
	void copyAttitudeMatrixToMotionMatrix(); 
	BOOL lookAt(const cVector &targetpos); /* Aim attitudeTangent at targetpos, and try 
		and perverse attitudeNormal while you're at it. Return FALSE if the targetpos 
		is right on top of you,	preventing you from looking at it, else return TRUE. */
	BOOL lookAtProportional(const cVector &targetpos, Real proportion); /* Proportion is
		between 0.0 and	1.0 specifying how far towards targetpos you turn to look. */
	int setRadius(Real radius);
	void setPrismDz(Real prismdz); /* Sets _defaultprismdz and the 
		current _psprite->_prismdz. */
//================================================
//Randomizing mutators =================================
//================================================
	void randomizePosition( const cRealBox &startbox);
	void randomizePosition(){randomizePosition(_movebox);}
	void randomizeRadius(Real minradius, Real maxradius)
		{setRadius(cRandomizer::pinstance()->randomReal(minradius, maxradius));}
	void randomizeVelocity(Real minspeed, Real maxspeed, BOOL force2D = FALSE);
	void randomizeVelocity(Real speed){randomizeVelocity(speed, speed);}
	void randomizeVelocity(){randomizeVelocity(MINSPEED, _maxspeed);}
	void randomizeSpin(Real minspeed, Real maxspeed);
	virtual void mutate(int mutationflags, Real mutationstrength); /* Mutate flagged
		position, velocity  and sprite properties by an amount specified in
		mutationstrength. */
	void mutate(int mutationflags) {mutate(mutationflags, _mutationstrength);}
		//Uses the member _mutationstrength, which defaults to 0.6.
	void randomize(int mutationflags){mutate(mutationflags, 1.0);} //1.0 is maximum.
//================================================
//Accessors =================================
//================================================
//State Field Accessors =================================
	Real mutationStrength()const{return _mutationstrength;}
	int value()const{return _value;}
	unsigned long personality()const{return _personality;}
	BOOL shield()const{return _shieldflag;}
	BOOL usefixedlifetime(){return _usefixedlifetime;}
	Real fixedlifetime(){return _fixedlifetime;}
	Real age()const{return _age;}
	BOOL recentlyDamaged(){return (_age - _lasthit_age) < SAFEWAIT;}
//Game Field Accessors =================================
	cBiota* pownerbiota()const;
	virtual cGame* pgame()const; /*Normally this will just return _pownerbiota->pgame(),
		but in the case of a cCritterViewer associated with a CPopView we use a different
		path to the cGame.*/
	cCritter* ptarget()const{return _ptarget;}
	cCritter* pplayer(); /* return pgame()->pplayer(), in other words the player of 
		the game that this critter belongs to. */
	int score()const{return _score;}
	int health()const{return _health;}
//================================================
//Motion Field Accessors =================================
//================================================
//Position Field Accessors =================================
	cVector position() const {return _position;}
	cVector oldposition() const {return _oldposition;}
	cPlane plane()const{return cPlane(_position, _binormal);}
	int wrapflag()const {return _wrapflag;}
	cRealBox moveBox()const{return _movebox;}
	cRealBox dragBox()const{return _dragbox;}
	cRealBox realBox(); //Smallest box holding the sprite.
	virtual BOOL draggable(){return TRUE;} /* Used to see if a critter is willing to be
		dragged in cGame::onLButtonDown. If you ever want a non-draggable critter child class,
		overload draggable to return FALSE. */
	virtual BOOL in3DWorld(); //Tells you if the owner game has a z-Thickness.
		/* I make this virtual as I don't want my cCritterViewer to ever think they
		are stuck in 2D */
//Velocity Field Accessors =================================
	BOOL fixedflag()const{return _fixedflag;}
	cVector velocity() const {return _velocity;}
	cVector tangent() const {return _tangent;}
	cVector normal() const{return _normal;}
	cVector binormal() const{return _binormal;}
	Real curvature()const {return _curvature;}
	Real speed()const {return _speed;}
	Real maxspeed()const {return _maxspeed;}
	Real maxspeedstandard()const {return _maxspeedstandard;}
//Acceleration, Force and Mass Field Accessors =================================
	cVector acceleration() const {return _acceleration;}
	Real density()const{return _density;}
	CTypedPtrArray<CObArray, cForce*>* pforcearray(){return &_forcearray;}
//Listener Field Accessors =================================
	cListener* plistener()const{return _plistener;}
	Real listeneracceleration()const{return _listeneracceleration;}
//Collision Field Accessors =================================
	Real minTwitchThresholdSpeed(){return _mintwitchthresholdspeed;}
	Real bounciness(){return _bounciness;}
	BOOL absorberflag()const{return _absorberflag;}
	Real mass()const{return _mass;}
	Real collidePriority(){return _collidepriority;}
	Real lastCollidePartnerPriority(){return _lastcollidepartnerpriority;}
//================================================
//Attitude and Display Field Accessors =================================
//================================================
	cSprite* psprite() const{return _psprite;}
	Real radius() const;
	cSpin spin()const{return _spin;}
	cMatrix attitude(){return _attitude;} 
	cMatrix inverseattitude(){return _inverseattitude;} 
	cVector attitudeTangent()const {return _attitude.column(0);}
	cVector attitudeNormal()const {return _attitude.column(1);}
	cVector attitudeBinormal()const{return _attitude.column(2);}
	BOOL attitudetomotionlock() const{return _attitudetomotionlock;}
	Real defaultprismdz()const{return _defaultprismdz;}
//================================================
//Bookkeeping Field Accessors =================================
//================================================
	int metrickey()const{return _metrickey;}
//================================================
// Serialize methods =================================
//================================================
	virtual void Serialize(CArchive &ar);
//================================================
// Helper methods =================================
//================================================
//Service Request Methods ================================================
	/* The point of these is that if a critter is do something that affects the set
		of critters as a whole, we want it to let the cBiota* _pownerbiota do it, so that
		all critter changes are coordinated.  So critter just passes this request to
		its _pownerbiota, and later _pownerbiota calls cBiota::processServiceRequests. */
	void makeServiceRequest(CString request);
	void add_me(cBiota *pownerbiota, BOOL immediateadd = FALSE); /* Make a request
		to the pownerbiota to add yourself to its array, normally this doesn't happen
		until pownerbiota makes a periodic call to processServiceRequests, but you
		can force it to be immediate with immediateadd. */
	void delete_me(){_health = 0; makeServiceRequest("delete_me");}
	void spawn(){makeServiceRequest("spawn");}
	void zap(){makeServiceRequest("zap");}
	void replicate(){makeServiceRequest("replicate");} //copy yourself to all the others.
//Helper Methods for Move Methods =================================
	virtual int clamp(); //Clamp against _movebox.  cCritterWall treats differently.
	virtual int clamp(const cRealBox &border); //Clamp against border
	virtual void addvelocityandcheckedges(Real dt); /* do _position += dt*_velocity,
		and clamp, wrap, or bounce the  new position off the _movebox.  Set _outcode to
		tell which edges. Called by move(). Need the dt to figure out a velocity bounce. */
	void synchSpeedAndDirectionToVelocity(); /* Enforces _speed*_tangent = _velocity
		and avoids having _speed less than SMALL_REAL */
	void fixNormalAndBinormal(); /* This is easy in 2D, subtler in 3D.  Call this from
		inside move on every update.  It also orthonormolizes
		_tangent, _normal, and _binormal. */
//Helper method for pointer references. =================================
	virtual void fixPointerRefs(); /* This  helper is for fixing things like 
		_ptarget after serialization, is also needed when we delete a critter.*/
//================================================
//Distance, touch, sniff, collide methods =================================
//================================================
	//The first three methods' code depends whether USEMETRIC is #defined in metric.h
	virtual cVector directionTo(cCritter *pcritter);//Use  cMetricCritter or compute direct
	Real distanceTo(cCritter *pcritter); //Uses cBiota's cMetricCritter or computes direct
	Real distanceTo(const cLine &testline){return testline.distanceTo(_position);}//Direct
	cDistanceAndDirection distanceAndDirectionTo(cCritter *pcritter); //ditto
	Real distanceTo(const cVector &vpoint); //Brute force.
	virtual BOOL touch(const cVector &vpoint);//Brute force.
	virtual BOOL touch(const cLine &sightline); /* In 3D, clicking the screen really
		picks a line of sight rather than a particular point in space. */
	virtual BOOL touch(cCritter *pcritter); /* TRUE if pcritter is different from this
		and the distance between the centers is less than the sum of the radii. Uses
		cBiota's cMetricCritter or just does the brute force distance checks. */
	virtual BOOL contains(cCritter *pcritter); /* TRUE if the disk of pcritter is inside
		the disk of the caller. */
	virtual COLORREF sniff(const cVector &snifflocation, CPopView *pactiveview); /* Can
		be used in update to check the current screen's pixel color at locations you're
		interested in. */
	virtual int collidesWith(cCritter *pcritterother); /* Returns cCollider::DONTCOLLIDE,
		::COLLIDEASCALLER,	or ::COLLIDEASARG to specify which of the pair, if either, gets
		to call for a collision. Default just checks _fixedflag and _collidepriority. */
	virtual BOOL collide(cCritter *pcritter); /* Does a physically natural collision and
		possibly overloads to make the critters react in some other way such as damage. */
//================================================
//Coordinate methods =================================
//================================================
		/* The coordinate methods transform directions (thought of as vectors not attached to
		a location) and positions between the global world coordinates and the local
		trihedron coordinates of the critter, which has its origin at _position and
		its ijk axes as the trihedron _tangent-_normal-_binormal.  The methods are
		used in box-style collision calculations, as with cCritterWall. */
	cVector globalToLocalDirection(const cVector &globalvec);
	cVector localToGlobalDirection(const cVector &localvec);
	cVector globalToLocalPosition(const cVector &globalpos);
	cVector localToGlobalPosition(const cVector &localpos);
//================================================
//Game methods =================================
//================================================
	virtual void die(){delete_me();} /* Can be overloaded to add dying behavior.  But should
		eventually produce a call to delete_me. */
	virtual void cCritter::dieOfOldAge(){delete_me();} 	/* dieOfOldAge is called in the
		update method if(_usefixedlifetime && _age > _fixedlifetime).  We distinguish
		between die() and dieOfOldAge() so die() can make a different sound for instance. */
	virtual int damage(int hitstrength); /* Deducts hitstrength from _health, calls die
		if this is below zero, returns _value as a reward to the damager. */
//================================================
//Force and Listen methods =================================
//================================================
	virtual void feellistener(Real dt); /* Call _plistener->listen, maybe more. */ 
	virtual void feelforce(); /* Do _acceleration =
		(sum of _forcearray[i]->force(this))/mass(). feelforce is virtual because you
		might possibly want to select which forces you feel, depending on the situation,
		like whether you're currently pursuing or fleeing. */
//================================================
//Drawing methods =================================
//================================================
	void updateAttitude(Real dt, BOOL forceattitudeupdate = FALSE); /* This keeps 
		graphical attitude matrix of the critter in synch with its motionmatrix.  To prevent
		a too-busy look, we normally don't do the update if the _speed is less than
		_mintwitchthresholdspeed. But if we are controlling the critter with arrow key
		calls to, e.g. the yaw, pitch and roll methods, we do want to force the update of
		the appearance, and then you set the forceattitudeupdate argument to TRUE. */
	virtual void draw(cGraphics *pgraphics, int drawflags=0);
		/* Calls _psprite->draw.  Has to be virtual because some child critters draw stuff
			 (like guns) on top of sprite. */
	virtual void drawHighlight(cGraphics *pgraphics, Real highlightratio); /* Draw a
		highlighted XOR circle around the critter with a size = highlightratio * radius(). 
		Or draw a sphere in 3D if you like. */
//================================================
//Sound methods =================================
//================================================
	static void playSound(CString wavfileresourcename);
	static void playMusic(const char* wavMidiFilename);
		/* By default interrupts any current sounds to play this sound. wavfileresourcename
		has to be the resource name of  *.wav file that you've added as a resource to your build. */
	static void stopSound(); //Turns off any currently playing sounds.
	static void stopMusic();
//================================================
//Simulation methods =================================
//================================================
	virtual void animate(Real dt); //Calls _psprite->animate(dt). Can overload to setAimVector.
	virtual void update(CPopView *pactiveview, Real dt); /* Call force to set the
		_acceleration to zero or to the quantity determined by _pforce. The 
		pactiveview argument can be used to sniff pixel colors. */ 
	int move(Real dt); /* You really should NOT change the delicately constructed move
		method, which is why its not virtual. */
};
#endif //CRITTER_H
