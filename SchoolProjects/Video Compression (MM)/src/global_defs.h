/****************************************
filename:    global_defs.h
description: Global Definitions
project:     
created by:  Joseph E. Sutton
version:     
****************************************/

#ifndef _GLOBAL_DEFS_
#define _GLOBAL_DEFS_

#define NUM_COLORS     3
#define Y_INDEX		  3
#define VIDEO_EXT      ".576v"
#define COMPRESSED_EXT ".cmp"
#define NUM_LAYERS     2

#define LAYER_FOREGROUND  0
#define LAYER_BACKGROUND  1

#define SEG_BLOCKWIDTH 16
#define SEG_BLOCKSIZE  (SEG_BLOCKWIDTH*SEG_BLOCKWIDTH)
#define SEG_SEARCHSIZE 16
#define SEG_THRESHOLD  2.0f

#define DCT_BLOCKWIDTH 8
#define DCT_BLOCKSIZE  (DCT_BLOCKWIDTH*DCT_BLOCKWIDTH)
#define DCT_16BITBLOCKS 12


//
#define PI      (3.14159265359f)
#define PI_D2   (1.57079632679f)
#define PI_180  (PI/(double)180.0)
#define _180_PI ((double)180.0/PI)

// Keyboard keys
#define ASCII_ESC 27


typedef unsigned char       uInt8;
typedef unsigned short      uInt16;
typedef unsigned long       uInt32;
typedef unsigned long long  uInt64;

typedef signed char         sInt8;
typedef signed short        sInt16;
typedef signed long         sInt32;
typedef signed long long    sInt64;


//#define round(A)(int(A + 0.5))


#ifndef NULL
   #define NULL  (0)
#endif


typedef struct _point
{
	sInt32 x;
   sInt32 y;
} point;

typedef struct _vector
{
	point from;
   point to;

   // diff of from and to
   sInt32 x;
   sInt32 y;
   
   uInt32 SegBlockIndex;
} vector;



#endif
/* _GLOBAL_DEFS_ */
