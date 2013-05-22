//////////////////////////////////////////////////////////////////////////////
// Program Name:  level_main.h
// Programmer:    Joseph E. Sutton
// Description:	Level Main
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _LEVEL_MAIN_
#define _LEVEL_MAIN_

#include "level.h"
#include "main.h"
#include "background.h"
#include "ship.h"
#include "ufo.h"
#include "gltext.h"
#include "time.h"

class LevelMain : public Level
{
public:
   LevelMain();
   ~LevelMain();
   
   void Init(uInt32 data = 0);
   void Exit(uInt32 data = 0);

   void Draw();
   void Idle();
   void KeyPressed(bool down, bool skey, int key, int x, int y);
   void MouseClick(bool down, int button, int x, int y);
   void MouseMoved(int x, int y);

   void PlayMusic();
   void StopMusic();

   void GameIsOver();
   bool GameOver();

protected:
   bool loaded;
   bool game_over;
   bool key_pressed[4];

   uInt8 level_num;
   bool show_level_num;

   // Time
   Time diff_time;
   DWORD start_time;
   DWORD current_time;
   DWORD total_time;

   // Ship
   Ship  *ship;
   float ship_anim;

   // UFO's
   UFO *          base_ufo1;
   uInt32         size;
   vector<UFO *>  enemy;
   UFO * temp_enemy;

   // Background
   Bkg *bkg;

   // Status
   glText status;

   // Sound
   Sound music;
   Sound explosion;

   // temp
   uInt32 x, y;
   char temp_str[32];


   //
   void DrawShip();
   void ShipFireLaser();
   void ShipFireMissle(int y);
   void ShipUpdateMissle(int y);
   void ShipMoveBullets();

   //
   void MoveShip(float x, float y);
   void AnimateShip();
   void ScrollBkg();
   void MoveEnemy();
   void AnimateEnemy();

   //
   void DrawShipBullets();
   void DrawEnemy();
   void DrawBkg();
   void DrawStatus();
   void DrawGameOver();
   void DrawLevelNumber(uInt8 num);

   //
   void CheckCollision();

   //
   void DeleteAllEnemy();

};


#endif