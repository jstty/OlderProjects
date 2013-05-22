//////////////////////////////////////////////////////////////////////////////
// Program Name:  level_main.cpp
// Programmer:    Joseph E. Sutton
// Description:	Level Main
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "level_main.h"

#include "sds.h"
extern SuperShooter *sds;


LevelMain::LevelMain()
{
   loaded = false;
   level_num = 0;
   bkg = new Bkg();

   char *file[3];

   //
   ship = new Ship();
   ship_anim = 0;
   char sfile[2][32] = {"data\\ship1.dat", "data\\ship2.dat"};
   file[0] = sfile[0];
   file[1] = sfile[1];
   ship->Load((char **)file, 2);

   //
   base_ufo1 = new UFO();
   char ufile[3][32] = {"data\\ufo.dat", "data\\exp1.dat", "data\\exp2.dat"};
   file[0] = ufile[0];
   file[1] = ufile[1];
   file[2] = ufile[2];
   base_ufo1->Load((char **)file, 3);
   base_ufo1->SetWorth(15);

   size = 0;
   //

   //
   explosion.LoadWav(IDW_EXPLOS);
}

LevelMain::~LevelMain()
{
   if(ship != NULL)      delete ship;
   if(bkg != NULL)       delete bkg;
   if(base_ufo1 != NULL) delete base_ufo1;

   DeleteAllEnemy();
}

void LevelMain::DeleteAllEnemy()
{
   for(x = 0; x < size; x++)
   {
      temp_enemy = enemy[x];
      if(temp_enemy != NULL)
         delete temp_enemy;
   }
   enemy.clear();
   size = 0;
}

void LevelMain::Init(uInt32 data)
{
   if(!loaded)
   {
      level_over = false;
      game_over = false;
      key_pressed[0] = false;
      key_pressed[1] = false;
      key_pressed[2] = false;
      key_pressed[3] = false;
      show_level_num = true;
      lScore = 0;
      level_num = data;

      // clear all previous
      DeleteAllEnemy();

      // create new set
      size = rand()%5 + 6; // 5 -> 10
      for(x = 0; x < size; x++)
      {
         temp_enemy = new UFO(*base_ufo1);
         enemy.push_back(temp_enemy);
      }

      ship->Reset();
      bkg->Reset();
   
      //
      sprintf(temp_str, "sound\\l%d.mid", level_num+1);
      music.LoadMidi(temp_str, 2);
  
      //
      current_time = start_time = GetTickCount();

           if(level_num == 0) total_time = start_time + LEVEL1_TIME;
      else if(level_num == 1) total_time = start_time + LEVEL2_TIME;
      else if(level_num == 2) total_time = start_time + LEVEL3_TIME;

      status.SetColor(0.0, 1.0, 0.0);
      //
      loaded = true;
   }
}

void LevelMain::Exit(uInt32 data)
{
   loaded = false;
   music.Close();
}

void LevelMain::Draw()
{
   DrawBkg();
   DrawStatus();

   if( !GameOver() )
   {
      CheckCollision();
      DrawShip();
   }

   //
   DrawShipBullets();
   DrawEnemy();

   // display for 3 sec
   if( show_level_num )
      DrawLevelNumber(level_num+1);

   if( GameOver() )
      DrawGameOver();
}


void LevelMain::Idle()
{
   if( !GameOver() )
   {
      current_time = GetTickCount();

      if(key_pressed[0])      // up
         MoveShip(0, +SHIP_SPEED);
      else if(key_pressed[1]) // down
         MoveShip(0, -SHIP_SPEED);
      else if(key_pressed[2]) // right
         MoveShip(+SHIP_SPEED, 0);
      else if(key_pressed[3]) // left
         MoveShip(-SHIP_SPEED, 0);

      AnimateShip();
   }

   ShipMoveBullets();
   ScrollBkg();

   // Level Over, Time ran out
   if( current_time >= total_time )
   {
      current_time = total_time;
      level_over = true;
   }

   //
   if( (current_time - start_time) > 6000 )
   {
      if( show_level_num) show_level_num = false;
      MoveEnemy();
   }
   

   AnimateEnemy();
}

void LevelMain::PlayMusic()
{
   music.Play();
}

void LevelMain::StopMusic()
{
   music.Stop();
}

void LevelMain::KeyPressed(bool down, bool skey, int key, int x, int y)
{
   if( !GameOver() )
   {
      if(skey)
      {  
         if(down)
         {
            key_pressed[0] = false;
            key_pressed[1] = false;
            key_pressed[2] = false;
            key_pressed[3] = false;

                 if(key == GLUT_KEY_UP)    key_pressed[0] = true;
            else if(key == GLUT_KEY_DOWN)  key_pressed[1] = true;
            else if(key == GLUT_KEY_RIGHT) key_pressed[2] = true;
            else if(key == GLUT_KEY_LEFT)  key_pressed[3] = true;
         }
         else
         {
                 if(key == GLUT_KEY_UP)    key_pressed[0] = false;
            else if(key == GLUT_KEY_DOWN)  key_pressed[1] = false;
            else if(key == GLUT_KEY_RIGHT) key_pressed[2] = false;
            else if(key == GLUT_KEY_LEFT)  key_pressed[3] = false;
         }
      }
      else
      {
         if(key == ' ')
            ShipFireLaser();
         else if(key == 'm')
            ShipFireMissle(y);
      }
   }
}


void LevelMain::MouseClick(bool down, int button, int x, int y)
{
   if( !GameOver() )
   {
      if(down)
      {
         if( button == GLUT_LEFT_BUTTON )
            ShipFireLaser();
         else if( button == GLUT_RIGHT_BUTTON )
            ShipFireMissle(y);
      }
   }
}


void LevelMain::MouseMoved(int x, int y)
{
   if( !GameOver() )
   {
      ShipUpdateMissle(y);
   }
}


void LevelMain::GameIsOver()
{
   game_over = true;
}


bool LevelMain::GameOver()
{
   return game_over;
}

////////////////////////////////////////////////////////
void LevelMain::ShipFireLaser()
{
   if(ship != NULL)
      ship->FireLaser();
}

void LevelMain::ShipFireMissle(int y)
{
   if(ship != NULL)
      ship->FireMissle(y);
}


void LevelMain::ShipUpdateMissle(int y)
{
   if(ship != NULL)
      ship->UpdateMissle(y);
}

void LevelMain::ShipMoveBullets()
{
   if(ship != NULL)
   {
      ship->MoveLaser();
      ship->MoveMissle();
   }
}
////////////////////////////////////////////////////////


////////////////////////////////////////////////////////
void LevelMain::MoveShip(float x, float y)
{
   if(ship != NULL)
      ship->Move(x, y);
}

void LevelMain::AnimateShip()
{
   ship_anim += SHIP_ANIM_SPEED;
   if(ship_anim > 2) ship_anim = 0;
}

void LevelMain::ScrollBkg()
{
   if(bkg != NULL)
      bkg->Scroll();
}

void LevelMain::MoveEnemy()
{
   for(x = 0; x < size; x++)
   {
      if( enemy[x] != NULL)
      {
         if(enemy[x]->isDestroy())
         {
            // remove destroyed
            temp_enemy = enemy[x];
            if(temp_enemy != NULL)
               delete temp_enemy;

            enemy.erase(&enemy[x]);
            // 

            // add new
            temp_enemy = new UFO(*base_ufo1);
            enemy.push_back(temp_enemy);
         }
         else
            enemy[x]->Move();
      }
   }
}
//

//
void LevelMain::AnimateEnemy()
{
   for(x = 0; x < size; x++)
   {
      if( enemy[x] != NULL)
      {
         if( !enemy[x]->isDestroy() && enemy[x]->isDead() )
         {
            enemy[x]->Animate();
         }
      }
   }
}
////////////////////////////////////////////////////////


void LevelMain::DrawShip()
{
   if(ship != NULL)
      ship->Draw((uInt16)ship_anim);
}



void LevelMain::DrawShipBullets()
{
   if(ship != NULL)
   {
      ship->DrawLaser();
      ship->DrawMissle();
   }
}


void LevelMain::DrawEnemy()
{
   for(x = 0; x < size; x++)
   {
      if( enemy[x] != NULL)
         enemy[x]->Draw();
   }
}


void LevelMain::DrawBkg()
{
   if(bkg != NULL)
      bkg->Draw();
}

void LevelMain::DrawLevelNumber(uInt8 num)
{
   sprintf(temp_str, "Level %d", num);

   status.SetText(temp_str);
   status.SetPos(320, 300);
   status.SetFont(GLUT_BITMAP_9_BY_15, 15);
   status.SetJustify(GLUT_TEXT_CENTER | GLUT_TEXT_MID);
   status.SetColor(1.0, 1.0, 0.0);
   status.Draw();

   // reset to default
   status.SetFont(GLUT_BITMAP_HELVETICA_12, 18);
   status.SetJustify(GLUT_TEXT_RIGHT | GLUT_TEXT_TOP);
   status.SetColor(0.0, 1.0, 0.0);
   //
}


void LevelMain::DrawStatus()
{
   // gray bottom
   glBegin(GL_QUADS);
      glColor3f((float)128/255, (float)128/255, (float)255/255);
      glVertex2i(0, 0);
      glVertex2i(MAX_WIDTH, 0);

      glColor3f(0.0, 0.0, 0.0);
      glVertex2i(MAX_WIDTH, 100);
      glVertex2i(0, 100);
   glEnd();
   //

   //
   x = 15;
   y = 55;
   status.SetText("Shield");
   status.SetPos(x, y);
   status.Draw();

      // shield bar
      x += 40;
      y -= 5;
      glBegin(GL_QUADS);
         glColor3f(1.0, 0.0, 0.0);
         glVertex2i(x, y);
         glVertex2i(x, y + 15);

         glColor3f(0.0, 1.0, 0.0);
         glVertex2i(x + 550, y + 15);
         glVertex2i(x + 550, y);
      glEnd();

      // black out
      x += 550;
      glColor3f(0.0, 0.0, 0.0);
      glBegin(GL_QUADS);
         glVertex2i(x, y);
         glVertex2i(x, y + 15);

         glVertex2i(x - 550 + ship->GetShield(), y + 15);
         glVertex2i(x - 550 + ship->GetShield(), y);
      glEnd();
   //

   //
   x = 15;
   y = 30;
   status.SetText("Points");
   status.SetPos(x, y);
   status.Draw();

      x += 40;
      y -= 5;
      glColor3f(0.0, 0.0, 0.0);
      glBegin(GL_QUADS);
         glVertex2i(x, y);
         glVertex2i(x, y + 15);
         glVertex2i(x + 100, y + 15);
         glVertex2i(x + 100, y);
      glEnd();

      x += 10;
      y += 4;
      sprintf(temp_str, "%d", lScore);
      status.SetText(temp_str);
      status.SetPos(x, y);
      status.SetJustify(GLUT_TEXT_RIGHT | GLUT_TEXT_TOP);
      status.Draw();
   //


   //
   x = 165;
   y = 30;
   status.SetText("Time");
   status.SetPos(x, y);
   status.SetJustify(GLUT_TEXT_RIGHT | GLUT_TEXT_TOP);
   status.Draw();

      x += 30;
      y -= 5;
      glColor3f(0.0, 0.0, 0.0);
      glBegin(GL_QUADS);
         glVertex2i(x, y);
         glVertex2i(x, y + 15);
         glVertex2i(x + 145, y + 15);
         glVertex2i(x + 145, y);
      glEnd();

      x += 5;
      y += 4;
      diff_time.Set(current_time - start_time);
      status.SetText( diff_time.GetTextMS(TIME_FORMAT_MIN_SEC "  of") );
      status.SetPos(x, y);
      status.Draw();

      x += 60;
      diff_time.Set(total_time - start_time);
      status.SetText( diff_time.GetTextMS(TIME_FORMAT_MIN_SEC) );
      status.SetPos(x, y);
      status.Draw();

      x += 30;
      diff_time.Set(total_time - current_time);
      status.SetText( diff_time.GetTextMS(" - " TIME_FORMAT_MIN_SEC) );
      status.SetPos(x, y);
      status.Draw();
   //
}


#define GAME_OVER_POINT(P1, P2) glVertex2i(x + P1*seg_length, y + P2*seg_length);
void LevelMain::DrawGameOver()
{
   glColor3f(1.0, 0.0, 0.0);
   glLineWidth(2);

   int seg_length = 10;
   int xc = 160;
   int yc = 380;

   x = xc;
   y = yc;
   ////////////////////////////////////////////////////////
   // Print GAME OVER
   ////////////////////////////////////////////////////////

   // G
   glBegin(GL_LINE_STRIP);
      GAME_OVER_POINT(2, 4);
      GAME_OVER_POINT(0, 4);
      GAME_OVER_POINT(0, 0);
      GAME_OVER_POINT(2, 0);
      GAME_OVER_POINT(2, 2);
      GAME_OVER_POINT(1, 2);
      GAME_OVER_POINT(1, 1);
      GAME_OVER_POINT(0, 0);
   glEnd();

   x += 3*seg_length;
   // A
   glBegin(GL_LINE_STRIP);
      GAME_OVER_POINT(0, 0);
      GAME_OVER_POINT(0, 4);
      GAME_OVER_POINT(2, 4);
      GAME_OVER_POINT(2, 0);
   glEnd();

   x += 3*seg_length;
   // M
   glBegin(GL_LINE_STRIP);
      GAME_OVER_POINT(0, 0);
      GAME_OVER_POINT(0, 4);
      GAME_OVER_POINT(1, 2);
      GAME_OVER_POINT(2, 4);
      GAME_OVER_POINT(2, 0);
   glEnd();

   x += 3*seg_length;
   // E
   glBegin(GL_LINE_STRIP);
      GAME_OVER_POINT(2, 4);
      GAME_OVER_POINT(0, 4);
      GAME_OVER_POINT(0, 0);
      GAME_OVER_POINT(2, 0);
   glEnd();


   x += 6*seg_length;
   // O
   glBegin(GL_LINE_STRIP);
      GAME_OVER_POINT(0, 0);
      GAME_OVER_POINT(0, 4);
      GAME_OVER_POINT(2, 4);
      GAME_OVER_POINT(2, 0);
      GAME_OVER_POINT(0, 0);
   glEnd();

   x += 3*seg_length;
   // V
   glBegin(GL_LINE_STRIP);;
      GAME_OVER_POINT(0, 4);
      GAME_OVER_POINT(1, 0);
      GAME_OVER_POINT(2, 4);
   glEnd();

   x += 3*seg_length;
   // E
   glBegin(GL_LINE_STRIP);
      GAME_OVER_POINT(2, 4);
      GAME_OVER_POINT(0, 4);
      GAME_OVER_POINT(0, 0);
      GAME_OVER_POINT(2, 0);
   glEnd();

   x += 3*seg_length;
   // R
   glBegin(GL_LINE_STRIP);
      GAME_OVER_POINT(0, 0);
      GAME_OVER_POINT(0, 4);
      GAME_OVER_POINT(2, 4);
      GAME_OVER_POINT(2, 2);
      GAME_OVER_POINT(0, 2);
      GAME_OVER_POINT(2, 0);
   glEnd();

   ////////////////////////////////////////////////////////
   ////////////////////////////////////////////////////////
}


void LevelMain::CheckCollision()
{
   if( loaded )
   {
      sInt32 enemy_rect[4];
      // test collisions
      for(x = 0; x < size; x++)
      {
         temp_enemy = enemy[x];
         if( temp_enemy != NULL)
         {
            if(!temp_enemy->isDead())
            {
               memcpy(enemy_rect, temp_enemy->Rect(), sizeof(uInt32)*4);
         
               if( RectOverRect(enemy_rect, ship->Rect()) )
               {
                  lScore += temp_enemy->GetWorth();
                  temp_enemy->Dead();
                  ship->Collision();
                  explosion.Play();

                  if(ship->GetShield() == 0)
                  {
                     GameIsOver();
                     music.LoadMidi("sound\\end.mid");
                     music.Play();
                  }
               }
               else if( ship->FiredLaser() )
               {
                  if( RectOverRect(enemy_rect, ship->LaserRect()) )
                  {
                     lScore += temp_enemy->GetWorth();
                     temp_enemy->Dead();
                     explosion.Play();
                  }
               }
               else if( ship->FiredMissle() )
               {
                  if( RectOverRect(enemy_rect, ship->MissleRect()) )
                  {
                     lScore += temp_enemy->GetWorth();
                     temp_enemy->Dead();
                     ship->MissleDead();
                     explosion.Play();
                  }
               }
            }
         }
      }
   }
}