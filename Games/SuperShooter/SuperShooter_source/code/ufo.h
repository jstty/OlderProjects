//////////////////////////////////////////////////////////////////////////////
// Program Name:  ufo.h
// Programmer:    Joseph E. Sutton
// Description:	UFO - sprint
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _UFO_
#define _UFO_

#include "sprite.h"

static uInt16 GID = 0;
class UFO : public Sprite
{
public:

   UFO() { Init(); }
   UFO(const UFO &src);
   ~UFO(){ }

   void Move();
   void Animate();
   void Draw();

   void Dead() { dead = true; }
   bool isDead() { return dead; }
   bool isDestroy() { return destroy; }

   uInt8 GetWorth(){ return worth; }
   void SetWorth(uInt8 w){ worth = w; }

protected:
   uInt16 ID;
   bool destroy;
   bool dead;
   uInt8 worth;

   uInt16 amp; // amplitude
   bool   up;
   float  cp;
   uInt16 speed_mag_x, speed_mag_y;
   uInt16 anim_loop;
   float  anim_increment;

   // temp
   float mx, my;

   void Init();
};

#endif
