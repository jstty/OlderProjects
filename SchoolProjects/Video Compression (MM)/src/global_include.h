/****************************************
filename:    global_include.h
description: Global Definitions
project:     
created by:  Joseph E. Sutton
version:     
****************************************/

#ifndef _GLOBAL_INCLUDE_
#define _GLOBAL_INCLUDE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/timeb.h>

#include <list>
using namespace std;

#include "global_defs.h"
#include "util.h"

#ifdef WIN32
	#include "glut.h"
#else
	#include <OpenGL/OpenGL.h>
	#include <GLUT/GLUT.h>
#endif

#ifdef FFTW
   #include <fftw3.h>
#endif
#include "ct2.h"


#include "c_frame.h"
#include "c_seg_block.h"
#include "c_seg_frame.h"

#include "c_dct_block.h"
#include "c_dct_frame.h"

#include "c_segmentation.h"
#include "c_dct_encoder.h"

#include "c_video.h"

#ifdef MAIN
	Video *vid = NULL;
#else
	extern Video *vid;
#endif


#endif
/* _GLOBAL_INCLUDE_ */
