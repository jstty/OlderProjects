/****************************************
 filename:    global_defines.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: 
 ****************************************/
#ifndef _GLOBAL_DEFINES_
#define _GLOBAL_DEFINES_

#define PI      3.14159265f
#define PI2     1.57079633f
#define _180_PI 57.2957795f

// data types
typedef signed   char   sInt8;   // -128 to 127
typedef signed   short  sInt16;  // -32,768 to 32,767
typedef signed   long   sInt32;  // -2,147,483,648 to 2,147,483,647
typedef unsigned char   uInt8;   // 0 to 255
typedef unsigned short  uInt16;  // 0 to 65,535
typedef unsigned long   uInt32;  // 0 to 4,294,967,295

struct Point3D
{
   float x, y, z;
};

struct Color4D
{
   float r, g, b, a;
};

struct Line3D
{
   Point3D p1;
   Color4D c1;
   
   Point3D p2;
   Color4D c2;
   
   Point3D normal;
   float maxLength;
};

struct PointBox3D
{
   Point3D s[4];
};

#endif // _GLOBAL_DEFINES_