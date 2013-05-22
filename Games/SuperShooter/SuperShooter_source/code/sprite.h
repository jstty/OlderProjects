//////////////////////////////////////////////////////////////////////////////
// Program Name:  sprite.h
// Programmer:    Joseph E. Sutton
// Description:	Sprint
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _SPRITE_
#define _SPRITE_

#include "main.h"

class SpriteData
{
public:
   SpriteData();
   SpriteData(const SpriteData & src);   // copy data
   ~SpriteData();

   int LoadFile(char *file);
   void Draw(sInt16 x, sInt16 y);

   sInt16 GetWidth(){ return w; }
   sInt16 GetHeight(){ return h; }


protected:
   // Size
   sInt8 w;
   sInt8 h;

   uInt16 size;
   void ***data;
   uInt16 *pts_num;
   uInt16 *pts_off[2];

   // temp
   uInt16 tx, ty, i, k, tsize, tpts_num;
};

class Sprite
{
public:
   Sprite();
   Sprite(const Sprite & src);

   ~Sprite();

   void Draw(uInt16 an);
   int Load(char **file, uInt16 num);
   sInt32 *Rect();

   float GetX(){ return x; }
   float GetY(){ return y; }

protected:
   // Position
   float x;
   float y;
   sInt32 rect[4];

   uInt16 current_anim;
   uInt16 num_anim;
   SpriteData **anim;

   // temp
   uInt16 i;

   //
   void copy(const Sprite & src);
};

#endif