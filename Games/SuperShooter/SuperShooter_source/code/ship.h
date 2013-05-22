//////////////////////////////////////////////////////////////////////////////
// Program Name:  ship.h
// Programmer:    Joseph E. Sutton
// Description:	Ship - sprite
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _SHIP_
#define _SHIP_

#include "sound.h"
#include "sprite.h"

const int missle_tail_max = 3;
class Ship : public Sprite
{
public:
   Ship();
   ~Ship();

   void Reset();

   void Move(float mx, float my);
   
   void FireLaser();
   void MoveLaser();
   void DrawLaser();
   sInt32 *LaserRect();
   bool FiredLaser() { return isLaser; }

   void FireMissle(int my);
   void MoveMissle();
   void UpdateMissle(int my);
   void DrawMissle();
   sInt32 *MissleRect();
   bool FiredMissle() { return isMissle; }
   void MissleDead() { isMissle = false; }

   sInt16 GetShield() { return shield; }
   void Collision();

protected:
   sInt16 shield;

   Sound s[2];

   // Laser
   bool   isLaser;
   float  laser_x, laser_length;
   uInt16 laser_y;
   sInt32 laser_rect[4];

   // Missle
   bool  isMissle;
   int   last_mouse_y;
   float missle_x;
   float missle_y;
   float missle_y_mag;
   float *missle_tail[2];
   float missle_color[4];
   sInt32 missle_rect[4];

   //
   sInt32 j;
   float temp;
};

#endif