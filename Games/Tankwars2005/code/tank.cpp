//////////////////////////////////////////////////////////////////////////////
// Program Name:  tank.cpp
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/12/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "tws_listener.h"
#include "tank.h"
#include "tankwars2005.h"
#include "cOptions.h"
#include "math.h"

extern cTankWars2005 *tws2005;
extern cOptionsData *options_data;

IMPLEMENT_SERIAL(cCritterArmedPlayerTank, cCritterArmedPlayer, 0);
IMPLEMENT_SERIAL(cForceWind, cForce, 0);

//////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////
cTank::cTank(cGame *pownergame, int pn)
{	
	player_num = pn;
	tankcritter = new cCritterArmedPlayerTank(pownergame);

   // add left right function
	
	if(player_num == 0)
	{
      FaceRight();
      tankcritter->moveTo(cVector(-8.0, 3.0, 0.0), false);
	}
	else
	{
      FaceLeft();
      tankcritter->moveTo(cVector(+8.0, 3.0, 0.0), false);
	}
   tankcritter->setAimToAttitudeLock(FALSE);
	tankcritter->setArmed(FALSE);      //Although I made it "Unarmed I can shoot by pressing the g key (JPH)
}

void cTank::SetAsPlayer()
{
	tws2005->setPlayer( tankcritter );
}

void cTank::FaceLeft()
{
   face = 1;
   tank_pp = tws2005->LoadPoly("objects\\tank2.dat");
	tank_pp->setCenter( cVector(1.1, -0.2) );
	tank_pp->setRadius(0.8);
   tank_pp->setPrismDz(0.0);
   tank_pp->rotate(PI);	// rotates player
   tankcritter->setSprite( tank_pp );
}

void cTank::FaceRight()
{
   face = 0;
   tank_pp = tws2005->LoadPoly("objects\\tank1.dat");
	tank_pp->setCenter( cVector(1.1, -0.2) );
	tank_pp->setRadius(0.8);
   tank_pp->setPrismDz(0.0);
	tank_pp->rotate(PI);	// rotates player
   tankcritter->setSprite( tank_pp );
}

void cTank::FaceFlip()
{
   if(face == 1)  FaceRight();
   else           FaceLeft();
}

cCritterBullet* cTank::Fire()
{
	double angle = (double)options_data->GetPlayer()->GetAngle();
	int pnum = options_data->GetPlayer_Num();
	if(pnum == 1)
	{
		if(angle < 90)
			angle = 180 - angle;
		else
			angle -= 180;
		angle = abs(angle);
	}
	double x = cos((PI*angle)/180);
	double y = sin((PI*angle)/180);
	tankcritter->setAimVector(cVector(x, y, 0.0));
   cb = tankcritter->shoot();

	Real power = (Real)options_data->GetPlayer_Power();
	Real bulletspeedup = 0.0;
	bulletspeedup = power/3.0;
	cb->setVelocity(bulletspeedup * cb->tangent()); //So bullets don't stack up.

	cb->addForce(new cForceWind(temp_wind_spd, temp_wind_dir) );
	cb->addForce(new cForceGravity(gravity));

	return cb;
}

cVector cTank::GetBulletPos()
{
   return cb->position();
}

cVector cTank::GetTankPos()
{
   return tankcritter->position();
}

void cTank::KillBullet()
{
   cb->delete_me();
}

void cTank::moving()
{
   tankcritter->clearForcearray();
   tankcritter->addForce(new cForceGravity(5*gravity));
}

void cTank::init_gravity()
{
   tankcritter->clearForcearray();
   tankcritter->addForce(new cForceGravity(6));
}

cTank::~cTank()
{
	// can't use DeleteCritterType, because it's not defined in critter, only in clevel
	tws2005->GetBiota()->purgeCritters( RUNTIME_CLASS(cCritterArmedPlayerTank) );
}

void cTank::Init(PlanetData *tpd)
{
  	tankcritter->setSensitive(TRUE);
  	tankcritter->setHealth(cTankWars2005::PLAYERHEALTH);

   tankcritter->setListener(new cListenerLR());

	tankcritter->setVelocity(cVector(0,0));
	tankcritter->setMaxspeed(2.0*cTankWars2005::CRITTERMAXSPEED);
	tankcritter->setShield(TRUE); //invulnerable

	pd = tpd;
	gravity = pd->GetGravity();
	tankcritter->addForce(new cForceGravity(1*gravity));
}

void cTank::SetTankColor(COLORREF color)
{
	tank_pp->setFillColor( color );
}

void cTank::Explode()
{
	cPolyPolygon *pp = tws2005->LoadPoly("objects\\explode.dat");
	pp->setCenter( cVector(-0.5, -0.5) );
	pp->setRadius(0.15);
	tankcritter->setSprite( pp );
}

void cTank::UpdateWind(float spd, cVector dir)
{
	temp_wind_spd = spd;
	temp_wind_dir = dir;
}

void cTank::MoveLeft()
{
	tankcritter->setVelocity(-tankcritter->maxspeed() * cVector::XAXIS);
}

void cTank::MoveRight()
{
	tankcritter->setVelocity(+tankcritter->maxspeed() * cVector::XAXIS);
}

void cTank::Stop()
{
	tankcritter->setVelocity(cVector::ZEROVECTOR);
   tankcritter->clearForcearray();
   tankcritter->addForce(new cForceGravity(1*gravity));
}


//====================cCritterArmedPlayerSpacewar
cCritterArmedPlayerTank::cCritterArmedPlayerTank(cGame *pownergame):
cCritterArmedPlayer(pownergame)
{ }

void cCritterArmedPlayerTank::reset()
{
	cCritterArmedPlayer::reset();
  	setHealth(cTankWars2005::PLAYERHEALTH);
}

//============ cForceGravity ======================
cVector cForceWind::force(cCritter *pcritter)
{
	return _intensity * pcritter->mass() * _pulldirection;
}

void cForceWind::copy(cForce *pforce)
{
	cForce::copy(pforce);
	if (!pforce->IsKindOf(RUNTIME_CLASS(cForceWind)))
		return;
	cForceWind *pforcechild = (cForceWind *)(pforce); 
	_pulldirection = pforcechild->_pulldirection;
}

void cForceWind::Serialize(CArchive &ar)
{
	cForce::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		ar <<  _pulldirection;
	}
	else //reading data
	{
		ar >> _pulldirection;
	}
}