//////////////////////////////////////////////////////////////////////////////
// Program Name:  ufo.cpp
// Programmer:    Joseph E. Sutton
// Description:	UFO - sprint
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "ufo.h"

UFO::UFO(const UFO &src)
{
   Init();

   worth = src.worth;
   copy(src);
}

void UFO::Move()
{
   if(!dead)
   {
      mx = speed_mag_x*ENEMY_OSILATION_SPEED;
      my = speed_mag_y*ENEMY_OSILATION_SPEED;
      x -= mx;
   
      if(up)
      {
         cp += my;
         y  += my;
      }
      else
      {
         cp -= my;
         y  -= my;
      }

      if(cp > amp)        up = false;
      else if(cp < -amp)  up = true;

      if(x < -20) // past ship
         destroy = true;
   }
}

void UFO::Draw()
{
   if(!dead)   Sprite::Draw(0);
   else
   {
      Sprite::Draw( floor(anim_increment) );
      anim_loop++;
      
      if(anim_loop > ENEMY_ANIM_LENGTH)
         destroy = true;
   }
}

void UFO::Animate()
{
   anim_increment += ENEMY_ANIM_SPEED;
   if(anim_increment >= 3) anim_increment = 1;
}

void UFO::Init()
{
   ID = GID++;

   worth = 10;
   anim_increment = 1;
   anim_loop = 0;

   amp = rand()%50 + 10;                              // 10 -> 50
   x = rand()%(2*MAX_WIDTH) + MAX_WIDTH + 1;          // MAX_WIDTH -> 3*MAX_WIDTH
   y = rand()%(MAX_HEIGHT - 100 - amp) + 101 + amp;   // 100 + ( 1 -> 50 ) -> MAX_HEIGHT

   cp = rand()%(2*amp) - amp;   // -amp -> amp
   y += cp;

   up = ((rand()%8 + 1)%2 == 0); // 0 -> 1  up or down direction
   speed_mag_x = rand()%8 + 1;   // 1 -> 8
   speed_mag_y = rand()%8 + 1;   // 1 -> 8

   dead = false;
   destroy = false;
}
