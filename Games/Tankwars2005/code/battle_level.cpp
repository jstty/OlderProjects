//////////////////////////////////////////////////////////////////////////////
// Program Name:  battle_level.cpp
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/6/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "battle_level.h"
#include "tankwars2005.h"
#include "cOptions.h"
#include "cMainState.h"

extern cTankWars2005 *tws2005;
extern cOptionsData *options_data;
cStatusBar *status = NULL;

cBattleLevel::cBattleLevel()
{
	terrain = NULL;
	tank[0] = NULL;
	tank[1] = NULL;

	mflag[0] = true;
   mflag[1] = true;
	sflag = true;
}

cBattleLevel::~cBattleLevel()
{}

void cBattleLevel::Exit()
{
   DeleteCritterType( RUNTIME_CLASS(cCritterBullet) );
   DeleteCritterType( RUNTIME_CLASS(cCritter) );

   if(terrain != NULL) delete terrain;
   if(tank[0] != NULL) delete tank[0];
	if(tank[1] != NULL) delete tank[1];

   tws2005->StopStatusBar();
}

//////////////////////////////////////////////
// Init
//////////////////////////////////////////////
void cBattleLevel::Init()
{
   StartTimer();

   // Create opject
   // background test
   SetBkgImg(options_data->GetPlanet_Img());

   // music test
   SetMusic("music\\battle.mid");

   // sound test
   AddSound("wav\\pop.wav");

   pd = options_data->GetPlanet();
   temp_wind_spd = pd->UpdateWindSpd();
	temp_wind_dir = pd->UpdateWindDir();

	options_data->SetCurrentPlayer(0);
	tank[0] = new cTank(tws2005, 0);
   tank[0]->UpdateWind(temp_wind_spd, temp_wind_dir);
	tank[0]->Init( options_data->GetPlanet() );
	tank[0]->SetTankColor( options_data->GetPlayer_Color() );

	options_data->SetCurrentPlayer(1);
	tank[1] = new cTank(tws2005, 1);
	tank[1]->UpdateWind(temp_wind_spd, temp_wind_dir);
	tank[1]->Init( options_data->GetPlanet() );
	tank[1]->SetTankColor( options_data->GetPlayer_Color() );

	terrain = new cTerrain(tws2005,  options_data->GetPlanet_Color() );

   // Start up
   PlayMusic();

   // Start by select current player 0
	SetPlayer(0);
   options_data->ResetStates();
	//

   start_game = false;
   StartTimer();

   bullet = NULL;
   boom = NULL;

   // show status bar
   tws2005->StartStatusBar();
}

void cBattleLevel::SetPlayer(int num)
{
	current_tank_num = num;
	options_data->SetCurrentPlayer( current_tank_num );
	tank[ current_tank_num ]->SetAsPlayer();
}

void cBattleLevel::SwitchPlayer()
{
   if(bullet != NULL)   bullet->delete_me();
   if(boom != NULL)     boom->delete_me();
   bullet = NULL;
   boom = NULL;

	if(current_tank_num == 0)	current_tank_num = 1;
	else								current_tank_num = 0;

	options_data->SetCurrentPlayer( current_tank_num );
   options_data->ResetStates();

   tws2005->StatusBar_ResetTimer();
	tws2005->StatusBar_UpdatePlayer();
}

//////////////////////////////////////////////
// Timer Loop
//////////////////////////////////////////////
void cBattleLevel::Loop()
{
   // quick exit
   if(options_data->CheckMainState( Surrender ) )
   { 
      options_data->SetPlayer_Lose( options_data->GetPlayer_Num() ); 
      NextLevel(); return;
   }
   //

   if(start_game)   // delay two seconds before start game
   {
      //prevent tanks from sliding all over the place
      if(mflag[0]) tank[0]->Stop();
      if(mflag[1]) tank[1]->Stop();
      
      // Start bu poping up dlg box
      if( options_data->CheckMainState( DlgBox ) )
      {
         if( options_data->GetPlayer_HP() < 1.0)
         {
            options_data->SetMainState( Surrender );
         }
         else if( options_data->NoAmmo() )
         {
            options_data->SetMainState( Surrender );
         }
         else
         {
            options_data->SetMainState( Waiting );

            // popup options menu
            cMainState ms;
            ms.DoModal();
         }
      }
      else if( options_data->CheckMainState(Fire) )
      {
         // player selected to fire
         if( options_data->CheckTankState(Fired) )
         {
            // player pressed 'f' or fire button
            if( options_data->CheckBulletState(Empty) )
            {
               boom = NULL;

               options_data->UseWeapon_Ammo();
               options_data->SetBulletState(Moving);
               bullet = tank[ current_tank_num ]->Fire();
            }
            else if( options_data->CheckBulletState(Collided) )
            {
               // bullet collided with an object
               options_data->SetBulletState( Exploding );
               boom = new cCritter(tws2005);
			      cPolyPolygon *pp = tws2005->LoadPoly("objects\\explode.dat");

               cVector exp_pos = tank[ current_tank_num ]->GetBulletPos();

               float damage = options_data->GetWeapon_Damage();
               float size = 0.50;
               float exp_rad = 1.5; // explosion radious - used to calc the damage
               if(damage == options_data->GetWeapon_Damage(0))
               {
                  // small
                  exp_rad = 1.5;
                  size = 0.07;
                  pp->setCenter( cVector(-1.0, -1.0) );
                  tws2005->playSound("wav\\small.wav");
               }
               else if(damage == options_data->GetWeapon_Damage(1))
               {
                  // mid
                  exp_rad = 2.0;
                  size = 0.12;
                  pp->setCenter( cVector(-1.0, -1.0) );
                  tws2005->playSound("wav\\mid.wav");
               }
               else if(damage == options_data->GetWeapon_Damage(2))
               {
                  // large
                  exp_rad = 3.0;
                  size = 0.22;
                  pp->setCenter( cVector(-1.0, -1.0) );
                  tws2005->playSound("wav\\large.wav");
               }
               else if(damage == options_data->GetWeapon_Damage(3))
               {
                  // NUKE!!!
                  exp_rad = 4.0;
                  size = 0.50;
                  pp->setCenter( cVector(-1.0, -1.0) );
                  tws2005->playSound("wav\\nuke.wav");
               }

               CheckTankHit(0, exp_pos, exp_rad, damage);
               CheckTankHit(1, exp_pos, exp_rad, damage);

               // create explosion
			      pp->setRadius(size);
               pp->setPrismDz(0.0);
			      boom->setSprite( pp );
               boom->moveTo( exp_pos , false);
               //
         
               tank[ current_tank_num ]->KillBullet();
               bullet = NULL;
               StartTimer();
            }
            else if( options_data->CheckBulletState(Exploding) &&
                     (time_diff > 1000)
                   )
            {
               // after explosion, with two second delay
               // calc damage and kill explosion critter
               options_data->SetBulletState( Done );
               options_data->SetTankState( Done );
               options_data->SetMainState( Done );

               if(boom != NULL)
               {
                  boom->delete_me();
                  boom = NULL;
               }
            }
            // if bullet destroyed and not collided
            else if( (bullet == NULL) &&
                !options_data->CheckBulletState(Collided) )
            {
               options_data->SetBulletState( Done );
               options_data->SetTankState( Done );
               options_data->SetMainState( Done );
            }
         }
      }
      else if( options_data->CheckMainState( Pass ) )
      {
         options_data->SetMainState( Done );
      }
      else if( options_data->CheckMainState( TimesUp ) )
      {
         options_data->SetMainState( Done );
      }
      else if( options_data->CheckMainState( Done ) )
      {
         SwitchPlayer();
      }

      if(time_diff > 2000)
      {
         SetBkgImg(options_data->GetPlanet_Img());

         StartTimer();

		   temp_wind_spd = pd->UpdateWindSpd();
		   temp_wind_dir = pd->UpdateWindDir();
		   tank[0]->UpdateWind(temp_wind_spd, temp_wind_dir);
		   tank[1]->UpdateWind(temp_wind_spd, temp_wind_dir);
      }
   }
   else if( (!start_game) && time_diff < 2000)
   {
      // increase gravity to drop quicker
      tank[0]->init_gravity();
      tank[1]->init_gravity();
   }
   // delay two seconds before start game
   else if( (!start_game) && (time_diff > 2000) )
   {
      StartTimer();
      start_game = true;
      tank[0]->Stop();
      tank[1]->Stop();
   }
   else
   {
      tank[0]->Stop();
      tank[1]->Stop();
   }
}

void cBattleLevel::KeyPressed(int key, int flag)
{
   if(start_game)
   {
      if( (flag == 0) || (flag == 4) ) 
      {
		   if( (key == 80) ) // p - switch player
         {
            options_data->SetMainState(Done);   // pass
		   }
         
         if( options_data->CheckMainState(Fire) &&
             options_data->CheckTankState(Weapon_Selection) )
         {
            if( (key == 32) ||   // spacebar - fire
                (key == 70)      // f - fire
              )
            {
               // check ammo before fire.
			      if( (options_data->GetWeapon_Ammo() > 0) )
               {
	               options_data->SetTankState(Fired);
               }
            }
            else if(key == VK_LEFT)
		      {
			      PlayerData *pd = options_data->GetPlayer();
               if(pd->GetPower() > 1)
                  pd->SetPower( pd->GetPower() - 1 );

               tws2005->StatusBar_UpdatePlayer();
		      }
		      else if(key == VK_RIGHT)
		      {
			      PlayerData *pd = options_data->GetPlayer();
               if(pd->GetPower() < 101)
                  pd->SetPower( pd->GetPower() + 1 );

               tws2005->StatusBar_UpdatePlayer();
            }
            else if(key == VK_UP)
		      {
			      PlayerData *pd = options_data->GetPlayer();
               if(pd->GetAngle() < 91)
                  pd->SetAngle( pd->GetAngle() + 1 );

               tws2005->StatusBar_UpdatePlayer();
		      }
		      else if(key == VK_DOWN)
		      {
			      PlayerData *pd = options_data->GetPlayer();
               if(pd->GetAngle() > 1)
                  pd->SetAngle( pd->GetAngle() - 1 );

               tws2005->StatusBar_UpdatePlayer();
            }

         }
         else if( options_data->CheckMainState(Move) &&
                  options_data->CheckTankState(Moving)
                  )
         {
		      if(key == VK_LEFT)
		      {
			      tank[current_tank_num]->MoveLeft();
               if(mflag[current_tank_num])
			      {
				      tank[current_tank_num]->moving();
			      }
               mflag[current_tank_num] = false;
		      }
		      else if(key == VK_RIGHT)
		      {
			      tank[current_tank_num]->MoveRight();
               if(mflag[current_tank_num])
			      {
				      tank[current_tank_num]->moving();
			      }
               mflag[current_tank_num] = false;
            }
            else if(key == VK_DOWN)
	         {
		         tank[current_tank_num]->Stop();
		         mflag[current_tank_num] = true;
	         }
         }
      }
   }
}

void cBattleLevel::KeyUp(int key, int flag)
{
   if(start_game)
   {
      //By John P Harris
	   if(key == VK_LEFT)
	   {
		   tank[current_tank_num]->Stop();
		   mflag[current_tank_num] = true;
	   }
	   else if(key == VK_RIGHT)
	   {
		   tank[current_tank_num]->Stop();
		   mflag[current_tank_num] = true;
	   }
   }
}

void cBattleLevel::CheckTankHit(unsigned char num, cVector exp_pos, float rad, float damage)
{
   cVector tank_pos = tank[num]->GetTankPos();

   cVector dif = exp_pos - tank_pos;
   Real length = dif.magnitude();
   if( length < rad ) // hit
   {
      damage *= (length/rad);
      options_data->GetPlayer(num)->Hit(damage);
   }
   //else no hit
}

void cBattleLevel::MouseClick(int button, int state, float x, float y)
{
}

void cBattleLevel::MouseMoved(float x, float y)
{
}


