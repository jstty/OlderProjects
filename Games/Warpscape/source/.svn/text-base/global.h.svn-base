/****************************************
 filename:    global.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: 
 ****************************************/
#ifndef _GLOBAL_
#define _GLOBAL_

#define MODEL_DIR "data"


// disable fopen, fscanf... unsafe warnings
#define _CRT_SECURE_NO_WARNINGS
// newer windows
#ifdef _WIN32
   #define WIN32
#elif _WIN64
   #define WIN32
#endif

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

#ifdef WIN32
   #include <windows.h>
   #include "GL/glew.h"
   #include <GL/gl.h>
   #include <GL/glu.h>
   #include "GL/glut.h"
#else
   #include "GL/glew.h"
   #include <OpenGL/gl.h>
   #include <OpenGL/glu.h>
   #include <GLUT/glut.h>
   #include <sys/time.h>
#endif

#include "global_types.h"
#include "util.h"

// classes
#include "timer.h"
#include "sound_bank.h"
#include "polygon.h"
#include "model.h"
#include "text_render.h"
#include "anim_model_gfx.h"
#include "anim_model_bank.h"
#include "anim_model.h"
#include "graphics.h"
#include "warp_path.h"
#include "background.h"
#include "starfield_bkg.h"
#include "enemy.h"
#include "flipper.h"
#include "player_ship.h"
#include "player_ship_bullet.h"
#include "level.h"
#include "level_title.h"
#include "level_warp.h"
#include "game_engine.h"

#ifdef _MAIN_
   GameEngine *game;
#else
   extern GameEngine *game;
#endif

#endif // _GLOBAL_
