//////////////////////////////////////////////////////////////////////////////
// Program Name:  tank_bullet.h
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    3/2/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _CTANKBULLET_
#define _CTANKBULLET_

#include "../pop/critter.h"
#include "tank.h"

class cTankBullet : public cCritter
{
DECLARE_SERIAL(cTankBullet);
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
	class cCritterArmedPlayerTank *_pshooter;
public:
	cTankBullet(); 
	virtual ~cTankBullet(); //Removes self from _pshooter->_bulletarray.
	virtual void initialize(cCritterArmedPlayerTank *pshooter);
		/* The shooter creates new bullets by a call to its _pbulletclass->CreateObject(). 
			This call doesn't take any arguments and uses the standard default constructor 
			for that kind of bullet.  The initialize call is so the shooter can feed some
			more initialization information into the bullet.  */
//Serialize methods
	virtual void Serialize(CArchive &ar);
	virtual void fixPointerRefs(); // This is for fixing things like _ptarget after serialization
//Accessor
	cCritterArmedPlayerTank* pshooter(){return _pshooter;}
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


#endif


