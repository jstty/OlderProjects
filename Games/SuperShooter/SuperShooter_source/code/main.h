//////////////////////////////////////////////////////////////////////////////
// Program Name:  main.h
// Programmer:    Joseph E. Sutton
// Description:	Constat variables
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef _MAIN_
#define _MAIN_

#include <GL/glut.h>
#include <stdlib.h>  // for random
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

#include "../resource.h"

const int MAX_WIDTH = 640;
const int MAX_HEIGHT = 480;
const float SYSTEM_MAG = 45;

const int LEVEL1_TIME = 180000;
const int LEVEL2_TIME = 150000;
const int LEVEL3_TIME = 120000;

// speeds
const float MISSLE_SPEED				   = 0.2*SYSTEM_MAG;
const float UPDATE_MISSLE_SPEED			= 0.0005*SYSTEM_MAG;
const float LASER_SPEED					   = 0.4*SYSTEM_MAG;
const float LASER_LENGTH_SPEED			= 0.3*SYSTEM_MAG;
const float BACKGROUND_OFFSET1_SPEED	= 0.02*SYSTEM_MAG;
const float BACKGROUND_OFFSET2_SPEED	= 0.03*SYSTEM_MAG;
const float BACKGROUND_OFFSET3_SPEED	= 0.04*SYSTEM_MAG;
const float SHIP_SPEED					   = 0.1*SYSTEM_MAG;
const float SHIP_ANIM_SPEED				= 0.005*SYSTEM_MAG;
const float ENEMY_ANIM_SPEED				= 0.01*SYSTEM_MAG;
const float ENEMY_ANIM_LENGTH		      = 1*SYSTEM_MAG;
const float ENEMY_OSILATION_SPEED		= 0.01*SYSTEM_MAG;

#define STAR_MAX_PTS 25
#define STAR_MAX_LEVEL 3


// data types
typedef signed   char   sInt8;   // -128 to 127
typedef signed   short  sInt16;  // -32,768 to 32,767
typedef signed   long   sInt32;  // -2,147,483,648 to 2,147,483,647
typedef unsigned char   uInt8;   // 0 to 255
typedef unsigned short  uInt16;  // 0 to 65,535
typedef unsigned long   uInt32;  // 0 to 4,294,967,295


#endif
