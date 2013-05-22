//////////////////////////////////////////////////////////////////////////////
// Program Name:  battle_level.h
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/6/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _CBATTLELEVEL_
#define _CBATTLELEVEL_

#include "level.h"
#include "terrain.h"
#include "tank.h"

#include "../pop/resource.h"
#include "cStatusBar.h"

class cBattleLevel : public cLevel
{
public:
   cBattleLevel();
   ~cBattleLevel();
   void Exit();

   //////////////////////////////////////////////
   // Init
   //////////////////////////////////////////////
   void Init();

	//
	void SwitchPlayer();
	void SetPlayer(int num);
   void CheckTankHit(unsigned char num, cVector exp_pos, float rad, float damage);

   //////////////////////////////////////////////
   // Loop
   //////////////////////////////////////////////
   void Loop();
   void KeyPressed(int key, int flag);
   void KeyUp(int key, int flag);
   void MouseClick(int button, int state, float x, float y);
   void MouseMoved(float x, float y);
 
protected:
	cTerrain *terrain;
	cTank *tank[2];
   unsigned int current_tank_num;

   cCritterBullet * bullet;
   cCritter *boom; // bullet explosion

   //
   bool start_game;

   //
   PlanetData *pd;
   float temp_wind_spd;
   cVector temp_wind_dir;

   bool mflag[2];
   bool sflag;
};


#endif