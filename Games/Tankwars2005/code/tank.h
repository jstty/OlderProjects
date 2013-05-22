//////////////////////////////////////////////////////////////////////////////
// Program Name:  tank.h
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/12/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _CTANK_
#define _CTANK_

#include "../pop/spritepolygon.h"
#include "../pop/critterarmed.h"
#include "../pop/listener.h"
#include "../pop/force.h"

//#include "tank_bullet.h"
#include "planet_data.h"

class cCritterArmedPlayerTank : public cCritterArmedPlayer //Our player.
{
   DECLARE_SERIAL(cCritterArmedPlayerTank);
public:
	cCritterArmedPlayerTank(cGame *pownergame = NULL);
	void reset();
};

class cTank
{
public:
	cTank(cGame *pownergame = NULL, int pn = 0);
   ~cTank();

	void Init( PlanetData *tpd );

   void SetTankColor(COLORREF color);
	void SetAsPlayer();

	void Explode();
	void UpdateWind(float spd, cVector dir);

	cCritterBullet* Fire();
   cVector GetBulletPos();
   cVector GetTankPos();
   void KillBullet();
   void moving();

   void init_gravity();

	void MoveLeft();
	void MoveRight();
   void Stop();

   void FaceLeft();
   void FaceRight();
   void FaceFlip();

protected:
	// tank player number
	int player_num;

   // used with flip
   bool face;

	// temp
	float temp_wind_spd;
	cVector temp_wind_dir;

	PlanetData *pd;
	cPolyPolygon *tank_pp;

   cCritterBullet *cb;

	//
	float wind_min;
	float wind_max;
	float gravity;
	float wind_prob;

	cCritterArmedPlayerTank *tankcritter;
};



#define WIND_LEFT		(-cVector::XAXIS)
#define WIND_RIGHT	(cVector::XAXIS)

class cForceWind : public cForce
{
DECLARE_SERIAL(cForceWind);
protected:
cVector _pulldirection;
public:
   cForceWind(Real windspeed = 25.0, cVector pulldirection = WIND_RIGHT)
	{
		_pulldirection = pulldirection;
		_intensity = windspeed;
	}

   virtual void Serialize(CArchive &ar);
   virtual void copy(cForce *pforce);
   virtual BOOL isGlobalPhysicsForce(){return TRUE;}
   virtual cVector force(cCritter *pcritter);
};

#endif