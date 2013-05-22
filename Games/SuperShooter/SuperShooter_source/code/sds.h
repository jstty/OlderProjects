//////   ////////////////////////////////////////////////////////////////////////
// Program Name:  sds.h
// Programmer:    Joseph E. Sutton
// Description:	Super Shooter - Game
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _SDS_
#define _SDS_

#include "main.h"
#include "sound.h"
#include "ship.h"
#include "ufo.h"
#include "background.h"
#include "gfx_util.h"
#include "gltext.h"
#include "level.h"
#include "level_title.h"
#include "level_main.h"
#include "level_end.h"

class SuperShooter
{
public:
   SuperShooter();
   ~SuperShooter();

   void Init();

   void Draw();
   void Idle();
   void KeyPressed(bool down, bool skey, int key, int x, int y);
   void MouseClick(bool down, int button, int x, int y);
   void MouseMoved(int x, int y);
   void PlayMusic();

   void SetLevelNum(uInt8 ln);
   void NextLevel() { level_num++;  }

   uInt32 lScore[3]; // level score

protected:
   bool isLoaded;
   
   //
   Level *CurrentLevel;
   LevelMain  *main;
   LevelTitle *title;
   LevelEnd   *end;

   uInt8 level_num;
   uInt8 last_level_num;
   void UpdateLevelNum();

   void SelectTitleLevel();
   void SelectMainLevel();
   void SelectEndLevel();
};

#endif
