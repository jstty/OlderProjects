//////////////////////////////////////////////////////////////////////////////
// Program Name:  level_title.h
// Programmer:    Joseph E. Sutton
// Description:	Level Title
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _LEVEL_TITLE_
#define _LEVEL_TITLE_

#include "level.h"
#include "gltext.h"
#include "sound.h"

class LevelTitle : public Level
{
public:
   LevelTitle();
   ~LevelTitle();
   
   void Init(uInt32 data = 0);
   void Exit(uInt32 data = 0);

   void Draw();
   void Idle();
   void KeyPressed(bool down, bool skey, int key, int x, int y);
   void MouseClick(bool down, int button, int x, int y);
   void MouseMoved(int x, int y);

   void PlayMusic();
   void StopMusic();

protected:
   bool DisplayLoading;
   bool DoneDisplayLoading;

   glText info;

   // sound
   Sound music;

   //
   float  *bkg_offset;
   uInt16 bkg[2][STAR_MAX_LEVEL][STAR_MAX_PTS][2];
   uInt8  *bkg_pt_size;
   uInt8  *bkg_ln_length;

   // temp
   uInt32 i, x, y, level;


   //
   void DrawTitle();
   void DrawShootingStars();
   void MoveStars();
   void UpdateStars(uInt8 bkgn, uInt8 ln);

};


#endif