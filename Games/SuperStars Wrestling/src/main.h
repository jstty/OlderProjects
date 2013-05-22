/* //////////////////////////////////////////////////////////////////////
 Program Name:  main.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-14
 Updated:       
 Version:       1.00
 Description:
   Main Header File
   Intended to be included by all source files.
   
////////////////////////////////////////////////////////////////////// */

/*
 dep/allegro/include, dep/js/include

 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib 

 dep/allegro/lib, dep/js/lib/

 alld.lib js32.lib
 alld_s.lib js32.lib

*/

#define DEBUG 1

#define GAME_WIDTH  320
#define GAME_HEIGHT 240
#define GAME_DEBUG_SCALE  2


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//
#define USE_CONSOLE
#include "allegro.h"

//
#define XP_PC
#include "jsapi.h"


// misc.
#include "types.h"
#include "stl/cSTree.h"
#include "stl/cSList.h"
#include "stl/cLList.h"

#include "cTextFileReader.h"

// classes
#include "cFx.h"
#include "cPolygon.h"

#include "cToggleAction.h"
#include "cActionPlayer.h"

#include "cSeq.h"
#include "cFrame.h"
#include "cAnim.h"

#include "cFontMngr.h"

#include "cGfxObj.h"
   #include "cImage.h"
   #include "cSprite.h"
   #include "cGfxText.h"

#include "cGfxNode.h"

#include "cLayer.h"
#include "cLayerMngr.h"

#include "cLevelInfo.h"
#include "cLevel.h"
#include "cLevelMngr.h"

#include "cLvl_Intro.h"

//
#include "cTitantron.h"
#include "cBaseWrestler.h"
#include "cWrestler.h"

#include "cZoneInfo.h"

#include "cPlayer.h"
#include "cPlayerNode.h"
#include "cPlayerMngr.h"
#include "cWrestlerMngr.h"

#include "cZones.h"

#include "cRingClock.h"
#include "cRingCamera.h"
#include "cRingStatusMenu.h"

//
#include "cScriptEngine.h"
#include "cScriptEnvCollision.h"
#include "cScriptPlayer.h"

//
#include "cLvl_Ring01.h"


//
#include "cSound.h"
#include "cDisplay.h"
#include "cControls.h"
#include "cSuperStars.h"

#ifndef _MAIN_
   extern cSuperStars *game;
   extern cLevelInfo  *info;
#else
   cSuperStars *game = NULL;
   cLevelInfo  *info = NULL;
#endif
