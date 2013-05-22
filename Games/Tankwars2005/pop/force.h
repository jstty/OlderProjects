 #ifndef FORCE_H
 #define FORCE_H
 
#include "vectortransformation.h"
 
 class cCritter; //For the cCritter* argument to force and the cCritter* member of cForceObject.
 class cBiota; //For the cBiota* argument to fixPointerRefs.
 
 	/* I would really prefer to make cForce, cForceObject and cForceClass be abstract base 
 classes in which I declare virtual cVector force(cCritter *pcritter)=0;  But in order for the 
 SERIAL macros to compile for its child classes, it must itself have the SERIAL macros, and these 
 require that it be possible to use the CRuntimeClass::CreateObject() call to construct an 
 instance of the class, and if a class has an abstract method you can't instantiate it. MFC is not 
 really "pure" C++. As a partial measure, I make the cForce, cForceObject and cForceClass
 classes almost like abstract classes by making their constructors protected to prevent
 people from trying to independently instantiate them. */
 
 class cForce : public CObject 
 {
 	DECLARE_SERIAL(cForce);
 public:
 	static Real INTENSITY; //5.0 Default value.  How strong the _intensity is.
 protected:
  	Real _intensity;
	cForce():_intensity(cForce::INTENSITY){} 
 		//protected constructor to make it like an abstract class you don't use instances of.
 public:
 	virtual	~cForce(){}
 	cForce* clone();
 	virtual void fixPointerRefs(cBiota *pownerbiota){}
 	virtual void copy(cForce *pforce);
 	virtual void Serialize(CArchive &ar);
 	virtual BOOL isGlobalPhysicsForce(){return FALSE;} /* This is useful for the cCritterBullet to
 		know which forces to copy from the shooter.  We return TRUE only for cForceDrag and 	
 		cForceGravity, the others will give the default return value of FALSE. */
 	virtual cVector force(cCritter *pcritter){return cVector::ZEROVECTOR;}
 };
 
 class cForceGravity : public cForce
 {
 	DECLARE_SERIAL(cForceGravity);
 protected:
	cVector _pulldirection;
 public:
 	cForceGravity(Real gravity = 25.0, cVector pulldirection = -cVector::YAXIS):
		_pulldirection(pulldirection){_intensity = gravity;}
		/* This acts as a default constructor as well.  25.0 seems to work well as a default value.
		Since I often use this in 2D games, we'll make the default gravity be negative Y reather than
		the negative Z we'd normally want for 3D games. */
 	virtual void Serialize(CArchive &ar);
 	virtual void copy(cForce *pforce);
 	virtual BOOL isGlobalPhysicsForce(){return TRUE;}
 	virtual cVector force(cCritter *pcritter);
 };
 
 class cForceDrag : public cForce
 {
 	DECLARE_SERIAL(cForceDrag);
 protected:
 	cVector _windvector; /* The effective rest direction for this force.  Default is
 		the zero vector.  */
 public:
 	cForceDrag():_windvector(cVector::ZEROVECTOR){_intensity = 0.5;} //A good default _friction.
 	cForceDrag(Real friction, cVector windvector = cVector::ZEROVECTOR)
		{_windvector = windvector; _intensity = friction;}
 	virtual void Serialize(CArchive &ar);
 	virtual void copy(cForce *pforce);
 	virtual BOOL isGlobalPhysicsForce(){return TRUE;}
 	virtual cVector force(cCritter *pcritter);
 };
 
 class cForceVortex : public cForceDrag
 {
 	DECLARE_SERIAL(cForceVortex);
 protected: /* Note that the _intensity inherited from cForceDrag affects how strongly 
 		this force acts. */
 	cVector _eyeposition; //Center of the vortex.
 	Real _spiralangle; /* Angle that the vortex force makes with the vector from _eyeposition
 			to a critter position.  Positive means counterclockwise, negative is clockwise,
 			-0.5 to 0.5 PI is outward, 0.5 to 1.5 PI is inward. +- 0.5 PI is neither. */  
 public:
 	cForceVortex():_spiralangle(0.6 * PI),_eyeposition(cVector::ZEROVECTOR){} 
 	cForceVortex(Real friction, Real spiralangle = 0.6 * PI, cVector eyeposition = cVector::ZEROVECTOR):
 		cForceDrag(friction), /* Note in this line that since _friction is a member of cForceDrag,
 			we can't call _friction(friction).  Members of a parent class can only be set
 			in an initializer list by calling a parent-class constructor. */
 		_spiralangle(spiralangle),_eyeposition(eyeposition){}
 	virtual void Serialize(CArchive &ar);
 	virtual void copy(cForce *pforce);
 	virtual cVector force(cCritter *pcritter);
 };
 
 class cForceObject : public cForce
 {
 	DECLARE_SERIAL(cForceObject);
 protected:
 	cCritter * _pnode; /* Reference to an existing critter you are attracted to or
 		repelled by. Note that the destructor does NOT delete this.  If _pnode gets
 		deleted elsewhere, the owner cBiota will find this reference and set it to NULL. */
 	int _nodeindex;  /* A serialization helper.  Gets set and saved when we do a serialize save,
 		and gets read and used by fixPointerRefs when we do a serialize load.  We can't 
 		serialize the actual _pnode value, as when we reload it wouldn't be the pointer to the same 
 		critter as before.  The value of this ONLY matters during Serilization. */
 	cForceObject():_pnode(NULL){} /* protected constructors to make this base like an abstract
 		class you don't use instances of. */
 	cForceObject(cCritter *pnode):_pnode(pnode){}
 public:
 	cCritter* pnode(){return _pnode;}
 	virtual void Serialize(CArchive &ar);
 	virtual void copy(cForce *pforce);
 	virtual void fixPointerRefs(cBiota *pownerbiota); /* Used at the end of a cGame serialization load.
 		We pass the pownerbiota arg so we can find the pointer of the critter located at
 		the _nodeindex. */
 };
 
 class cForceObjectSeek : public cForceObject
 {
 	DECLARE_SERIAL(cForceObjectSeek);
 public:
 	cForceObjectSeek(){}
 	cForceObjectSeek(cCritter *pnode, Real maxacceleration):
 		cForceObject(pnode){_intensity = maxacceleration;}
 	cVector force(cCritter *pcritter);
 };
 
 class cForceClass : public cForce
 {
 	DECLARE_SERIAL(cForceClass);
 protected:
 	CRuntimeClass *_pnodeclass; /* Default is RUNTIME_CLASS(cBullet).  Note that the destructor
 		does NOT delete this; MFC handles clean-up of CRuntimeClass* pointers itself. */
 	BOOL _includechildclasses; //Whether to also be affected by the child classes of _pnodeclass.
 	cForceClass():_pnodeclass(NULL),	_includechildclasses(FALSE){} 
 	cForceClass::cForceClass(CRuntimeClass *pnodeclass,	BOOL includechildclasses):
 		_pnodeclass(pnodeclass), _includechildclasses(includechildclasses){}
 			/* protected constructors to make this like an abstract class you don't use
 				instances of. */
 public:
 	virtual void Serialize(CArchive &ar);
 	virtual void copy(cForce *pforce);
 };
 
 class cForceClassEvade : public cForceClass
 {
 	DECLARE_SERIAL(cForceClassEvade);
 public:
 	static Real COSINESMALLANGLE;  /* Default cos(PI/40.0).  Move off to the side if the 
		velocity of	the thing chasing you is with a cone of twice this angle size around your the 
		direction towards you.  cos changes very slowly near 0.  	cos(PI/40) is 0.997 and
		cos(PI/7) about 0.9. So PI/40 would mean 2*180/40 degrees or 9 degrees.  Normally
	 	is something like 0.99 or so, but can be any number between -1.0 and 1.0*/ 
 	static Real COSINEIGNOREANGLE; /* Default -0.8. Ignore a nearest enemy whose direction
 		of motion makes an angle less than this with the direction to you.  If I put -1.0
		here that means not to ignore any enemy at all and to be skittish.   If I put 0.0
		here that means ignore any enemy that is not at all moving towards me and be fairly
		bold.  Normally I use something like -0.2, but I can use any number between -1.0 and 1.0.*/ 
 	static UINT TURNPERSONALITYBIT; //A bit of the personality field to use in evading bullets.
 protected:
			// Remember that you inherit a _pnodeclass and _includechildclasses from cForceClass.
 	Real _dartspeedup; /* A multiplier used for a temporary speed up when fleeing _pnodeclass.
			Gets multiplied times the force-calling pcritter's _maxspeed. */
 public:
 	cForceClassEvade():_dartspeedup(0.0){} 
 	cForceClassEvade::cForceClassEvade(Real dartacceleration, Real dartspeedup,
 		CRuntimeClass *pnodeclass,	BOOL includechildclasses = FALSE):
 		cForceClass(pnodeclass, includechildclasses),/* Note in this line that since these
 			fields are members of cForceClass, we can't set them in an intializer list with
 			a call like pnodeclass(_pnodeclass).  Members of a parent class can only be set
 			in an initializer list by calling a parent-class constructor. */
 		_dartspeedup(dartspeedup){_intensity = dartacceleration;}
 	virtual void Serialize(CArchive &ar);
 	virtual void copy(cForce *pforce);
 	cVector force(cCritter *pcritter);
 };
 
 class cForceEvadeBullet : public cForceClassEvade
 {
 	DECLARE_SERIAL(cForceEvadeBullet);
 public:
 	static Real INTENSITY; //Default 8.0. Rate you accelerate away from an enemy bullet.
 	static Real DARTSPEEDUP; //Default 2.0. When fleeing a bullet your maxspeed is multiplied by this.
 public:
 	cForceEvadeBullet();
 	cForceEvadeBullet(Real dartacceleration, Real dartspeedup, BOOL includechildclasses = FALSE);
 		/* This  force  evades cBullet class objects.  The default FALSE in the fourth 
 		cForceClassEvade constructor arg means only evade objects whose class is exactly
 		cBullet such as the player fires, (and not a child class of cBullet, such as the
 		cCritterBulletSilver that the UFOs fire). If you want something to evade all bullets,
 		you need feed in a TRUE as the third constructor argument. */
 };
 
 class cForceObjectSpringRod : public cForceObject
 {
 	DECLARE_SERIAL(cForceObjectSpringRod);
 protected:
 	Real _rodlength;
 public:
 	cForceObjectSpringRod():_rodlength(1.0){_intensity = 1.0;}
 	cForceObjectSpringRod(cCritter *pnode, Real rodlength = 1.0,
		 Real springforce = 1.0): cForceObject(pnode),
		_rodlength(rodlength){_intensity = springforce;}
 	virtual void Serialize(CArchive &ar);
 	virtual void copy(cForce *pforce);
 	virtual cVector force(cCritter *pcritter);
 };


//============
 class cForceObjectGravity : public cForceObject
 {
 	DECLARE_SERIAL(cForceObjectGravity);
 public:
 	cForceObjectGravity(){}
 	cForceObjectGravity(cCritter *pnode, Real gforce):
 		cForceObject(pnode){_intensity = gforce;}
 	cVector force(cCritter *pcritter);
	virtual BOOL isGlobalPhysicsForce(){return TRUE;} 
		/* "Global physics forces" get copied from the
		shooter to its bullets.  So if we return TRUE,
		the gravity pull to the sun is copied to the
		bullets shot by the player and the smart UFOs,
		if we return FALSE the bullets don't have the
		sun gravity. */
 };
 
 
 #endif //FORCE_H
