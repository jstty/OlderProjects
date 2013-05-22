//////////////////////////////////////////////////////////////////////////////
// Program Name:  ship.cpp
// Programmer:    Joseph E. Sutton
// Description:	Ship - sprite
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "ship.h"

Ship::Ship()
{
   Reset();

   missle_tail[0] = new float[missle_tail_max];
   missle_tail[1] = new float[missle_tail_max];

   s[0].LoadWav(IDW_LASER);
   s[1].LoadWav(IDW_MISSLE);
}

Ship::~Ship()
{
   if( missle_tail[0] != NULL) delete [] missle_tail[0];
   if( missle_tail[1] != NULL) delete [] missle_tail[1];
}

void Ship::Reset()
{
   shield = 550;

   isLaser = false;
   laser_x = 0;
   laser_length = 0;
   laser_y = 0;

   isMissle = false;
   last_mouse_y = 0;
   missle_x = 0;
   missle_y = 0;
   missle_y_mag = 0;

   x = 50;
   y = 250;


}

void Ship::Collision()
{
   shield -= 110;
   if(shield < 0) shield = 0;
}

void Ship::Move(float mx, float my)
{
   x += mx;
   y += my;

   if(x > (MAX_WIDTH-70))
      x -= mx;
   else if(x < 0)
      x -= mx;

   if(y > (MAX_HEIGHT-30))
      y -= my;
   else if(y < 90)
      y -= my;
}

void Ship::FireMissle(int my)
{
   if(!isMissle)
   {
      isMissle = true;
      last_mouse_y = my;
      missle_y_mag = 0;

      missle_x = x + 30;
      missle_y = y + 2;

      for(j = missle_tail_max; j >= 0; j--)
      {
         missle_tail[0][j] = missle_x;
         missle_tail[1][j] = missle_y;
      }

      s[1].Play();
   }
}

void Ship::MoveMissle()
{
   if(isMissle)
   {
      missle_x += MISSLE_SPEED;
      missle_y += missle_y_mag;

      if( missle_x - missle_tail[0][1] > 25)
      {
         for(j = missle_tail_max; j > 0; j--)
         {
            missle_tail[0][j] = missle_tail[0][j-1];
            missle_tail[1][j] = missle_tail[1][j-1];
         }
      }

      missle_tail[0][0] = missle_x;
      missle_tail[1][0] = missle_y;

      if(missle_x >= (MAX_WIDTH + 10) )
         isMissle = false;

      if(missle_y >= (MAX_HEIGHT + 10) )
         isMissle = false;
      else if(missle_y <= 90 )
         isMissle = false;
   }
}

void Ship::DrawMissle()
{
   if(isMissle)
   {
      // tail
      glLineWidth(4);
      glBegin(GL_LINE_STRIP);
         i = 0;
         missle_color[0] = 1.0;
         missle_color[1] = 0.0;
         missle_color[2] = 0.0;
         missle_color[3] = 0.0;

         for(j = 0; j < missle_tail_max; j++)
         {
            glColor4fv(missle_color);
            glVertex2f(missle_tail[0][j] + 3, missle_tail[1][j] + 3);

            if( j < missle_tail_max/2 )
               missle_color[1] += 2/((float)missle_tail_max);
            else
            {
               missle_color[0] -= 2/((float)missle_tail_max);
               missle_color[1] -= 2/((float)missle_tail_max);

               if(missle_color[0] < 0) missle_color[0] = 0;
               if(missle_color[1] < 0) missle_color[1] = 0;
            }
         }

      glEnd();

      // missle body
      glColor4f(1.0, 0.0, 1.0, 0.0);
      glBegin(GL_POLYGON);
         glVertex2i(missle_x + 2, missle_y);
         glVertex2i(missle_x + 4, missle_y);
      
         glVertex2i(missle_x + 6, missle_y + 2);
         glVertex2i(missle_x + 6, missle_y + 4);

         glVertex2i(missle_x + 4, missle_y + 6);
         glVertex2i(missle_x + 2, missle_y + 6);

         glVertex2i(missle_x, missle_y + 4);
         glVertex2i(missle_x, missle_y + 2);        
      glEnd();

      glFlush();
   }
}

void Ship::UpdateMissle(int my)
{
   if(isMissle)
   {
      missle_y_mag += (last_mouse_y - my)*(UPDATE_MISSLE_SPEED);
      last_mouse_y = my;
   }
}


void Ship::FireLaser()
{
   if(!isLaser)
   {
      isLaser = true;
      laser_x = x + 56;
      laser_y = y + 12;
      laser_length = 0;

      s[0].Play();
   }
}

void Ship::DrawLaser()
{
   if(isLaser)
   {
      glLineWidth(1);
      glBegin(GL_LINE_STRIP);
         glColor4f(0.0, 1.0, 0.0, 0.0);
         glVertex2f(laser_x, laser_y);

         glColor4f(0.0, 1.0, 0.0, 0.0);
         glVertex2f(laser_x - laser_length/2, laser_y);

         glColor4f(0.0, 0.0, 0.0, 1.0);
         glVertex2f(laser_x - laser_length, laser_y);
      glEnd();

      glFlush();
   }
}


void Ship::MoveLaser()
{
   if(isLaser)
   {
      laser_x += LASER_SPEED;

      if( laser_length < 75)
         laser_length += LASER_LENGTH_SPEED;

      if(laser_x >= (MAX_WIDTH + 20) )
         isLaser = false;
   }
}

sInt32 * Ship::LaserRect()
{
   if(isLaser)
   {
      laser_rect[0] = laser_x - laser_length;
      laser_rect[1] = laser_y;
      laser_rect[2] = laser_x;
      laser_rect[3] = laser_y + 1;
   }
   return laser_rect;
}


sInt32 * Ship::MissleRect()
{
   if(isMissle)
   {
      missle_rect[0] = missle_x - 3;
      missle_rect[1] = missle_y - 3;
      missle_rect[2] = missle_x + 6;
      missle_rect[3] = missle_y + 6;
   }
   return missle_rect;
}

