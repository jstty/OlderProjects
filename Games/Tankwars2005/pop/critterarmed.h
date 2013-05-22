// Critterarmed.h: interface for the cCritterArmed and cCritterBullet classes.
//
//////////////////////////////////////////////////////////////////////

#ifndef CRITTERARMED_H
#define CRITTERARMED_H

#include "critter.h"

class cCritterBullet : public cCritter
{
DECLARE_SERIAL(cCritterBullet);
friend class cCritterArmed;
public:
	static Real FIXEDLIFETIME; //Life in seconds before spontaneous decay, currently 3.0.
	static Real MAXSPEED; //Greater than cCritter::MAXSPEED. Currently 22.0.
	static BOOL DIEATEDGES; //Default _dieatedges is TRUE for disappear at edges.
	static Real BULLETSPEED;
	static int HITSTRENGTH;
protected:
//Serialized fields
	int _hitstrength; //How much damage it does.
	int _shooterindex; //Helper used only in Serialize
	BOOL _dieatedges; /*  If TRUE this keeps bullets from bouncing or wrapping,	note that it
also makes the critters unable to fire when they are really near an edge. */
//Nonserialized pointer ref.
	class cCritterArmed *_pshooter;
public:
	cCritterBullet(); 
	virtual ~cCritterBullet(); //Removes self from _pshooter->_bulletarray.
	virtual void initialize(cCritterArmed *pshooter);
		/* The shooter creates new bullets by a call to its _pbulletclass->CreateObject(). 
			This call doesn't take any arguments and uses the standard default constructor 
			for that kind of bullet.  The initialize call is so the shooter can feed some
			more initialization information into the bullet.  */
//Serialize methods
	virtual void Serialize(CArchive &ar);
	virtual void fixPointerRefs(); // This is for fixing things like _ptarget after serialization
//Accessor
	cCritterArmed* pshooter(){return _pshooter;}
//Overloaded methods
	virtual void replicate(){} //Don't replicate bullets because then there's confusion about pshooter.
	virtual void update(CPopView *pactiveview, Real dt);
	int collidesWith(cCritter *pcritter);
	virtual BOOL collide(cCritter *pcritter);
//Special methods
	virtual BOOL isTarget(cCritter *pcritter); /* Tells me if this is something I want to
		blow up.  Default is to blow up everything except (a) the shooter, (b) bullets of the
		same class as the shooter's bullets, or (c) walls. */
};

class cCritterBulletRubber : public cCritterBullet
{
DECLARE_SERIAL(cCritterBulletRubber);
public:
	static BOOL DIEATEDGES; //If TRUE they disappear at edges, no bounce or wrap.
	static Real DENSITY;
	cCritterBulletRubber();
	virtual BOOL isTarget(cCritter *pcritter){return FALSE;} // Don't blow up anyone.
	virtual void update(CPopView *pactiveview, Real dt); /* Overload to use the cCritter update instead of 
		the cCritterBullet update that you inherit. */
	virtual BOOL collide(cCritter *pcritter);
};

class cCritterBulletSilver : public cCritterBullet
{
DECLARE_SERIAL(cCritterBulletSilver);
public:
	static int SCOREVALUE;
	cCritterBulletSilver();
	virtual BOOL isTarget(cCritter *pcritter); // Only blows up _ptarget.
	virtual int damage(int hitstrength); //Make a noise and call cCritter::damage.
};

class cCritterBulletSilverMissile : public cCritterBulletSilver
{
DECLARE_SERIAL(cCritterBulletSilverMissile);
public:
	static int SCOREVALUE;
	static Real MAXSPEED;
	static Real CHASEACCELERATION; //Rate you accelerate towards player.
public:
	cCritterBulletSilverMissile();
	virtual void initialize(cCritterArmed *pshooter); //Overload to make a cForceObjectSeek
};

class cCritterArmed : public cCritter
{
DECLARE_SERIAL(cCritterArmed);
//friend cCritterBullet;
public:
	static int MAXBULLETS;
	static Real GUNLENGTH; //Ratio of gun length to critter radius, maybe 1.3.
	static Real WAITSHOOT; // The default interval to wait between shots.
protected:
//Serialized fields
	BOOL _armed; //Use this to turn the gun on or off.
	Real _ageshoot; //Age at last shot, so you wait a bit between shots
	Real _waitshoot; //Time to wait between shots.
	Real _gunlength;
	cVector _aimvector;
	int _maxbullets;
	BOOL _bshooting;
	BOOL _aimtoattitudelock; //FALSE means aim any old way, TRUE means match aim to attitude tangent
	CRuntimeClass *_pbulletclass; /* Note that we do NOT delete this in the destructor, MFC
		takes care of CRuntimeClass memory. Use the CArchive::ReadClass and WriteClass methods
to serialize this. */
//Dummy variables needed for use in the fixPointerRefs method
	CArray<int, int> _bulletindexarray; //Used only in Serialize
//Nonserializable fields
	CTypedPtrArray<CObArray, cCritterBullet*> _bulletarray;
public:
	cCritterArmed(cGame *pownergame = NULL);
	virtual ~cCritterArmed();
	virtual void copy(cCritter *pcritter);
//Serialize methods
	virtual void Serialize(CArchive &ar);
virtual void fixPointerRefs(); /* This is for fixing things like _ptarget after serialization */
//Accessors
	cVector aimvector(){return _aimvector;}
	CRuntimeClass *pbulletclass(){return _pbulletclass;}
	CTypedPtrArray<CObArray, cCritterBullet*>* pbulletarray(){return &_bulletarray;}
	Real gunlength(){return _gunlength;}
	BOOL armed(){return _armed;}
//Mutators
	virtual void aimAt(cVector vclick); //aim on line from position towards vclick.
	virtual void aimAt(cCritter *pcritter); //Aim at position of pcritter.
	virtual void setAimVector(cVector dir); /* aim parallel to dir, note dir
			 doesn't have to be unit vector */
	void setArmed(BOOL onoff){_armed = onoff;}
	virtual void setWaitShoot(Real waitshoot){_waitshoot = waitshoot;}
	void setBulletClass(CRuntimeClass *pbulletclass){_pbulletclass = pbulletclass;}
	void removeBullet(cCritterBullet *pbullet);
	void setShooting(BOOL onoff){_bshooting = onoff;}
	void setAimToAttitudeLock(BOOL onoff){_aimtoattitudelock = onoff;}
	void setGunlength(Real gunlength){_gunlength = gunlength;}
//Overloads
	virtual void update(CPopView *pactiveview, Real dt);
	virtual void draw(cGraphics *pgraphics,	int drawflags = 0);
	virtual void animate(Real dt); //Overload for possibly locking gun to sprite direction.
//Special Methods
	virtual cCritterBullet* shoot(); /* Create a bullet and add it to your personal tracking
		array. We return the bullet in case we want to overload the shoot method do do
		something else to it. */
};

class cCritterArmedRobot : public cCritterArmed
{
DECLARE_SERIAL(cCritterArmedRobot);
public:
	cCritterArmedRobot(cGame *pownergame = NULL);
//overloads
	virtual void setWaitShoot(Real waitshoot); //randomize ageshoot so N robots not in synch
	virtual void setAge(Real age); //randmoize ageshoot so N robots not in synch.
	virtual void update(CPopView *pactiveview, Real dt);
};

class cCritterArmedPlayer : public cCritterArmed
{
DECLARE_SERIAL(cCritterArmedPlayer);
public:
	static int PLAYERHEALTH;
	static CString DAMAGESOUND;
	static Real DENSITY;
protected:
	BOOL _sensitive; /* If TRUE, then you are damaged by a collision with 
		a cEnemyCritter */
public:
	cCritterArmedPlayer(cGame *pownergame = NULL);
	void copy(cCritter *pcritter); 
//Serialize methods
	virtual void Serialize(CArchive &ar);
//Mutators
	void reset();
	void setSensitive(BOOL onoff){_sensitive = onoff;}
//Accessors
	BOOL sensitive(){return _sensitive;}
//Main methods
	virtual void feellistener(Real dt); /* Overload to listen for VK_SPACE to turn on _bshooting
if you have a _plistener. */
	virtual int damage(int hitstrength); /* ignores damage if _shieldflag on */
	virtual BOOL collide(cCritter *pcritter); //Can call damage or not.
	virtual void draw(cGraphics *pgraphics, int drawflags = 0); //Draw differently when _health == 0.
	virtual cCritterBullet* shoot(); /* Call the standard shoot method but add your player
		velocity to the bullet because otherwise if you're flying forward the bullets pile up.*/
};

class cCritterPlayer : public cCritterArmedPlayer
{
DECLARE_SERIAL(cCritterPlayer);
public:
	cCritterPlayer(cGame *pownergame = NULL);
};


#endif //CRITTERARMED_H
