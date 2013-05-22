/* //////////////////////////////////////////////////////////////////////
 Program Name:  types.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   
   
////////////////////////////////////////////////////////////////////// */

typedef BITMAP ImgData;
typedef SAMPLE SndData;

#define COLOR_TRANS makecol(255,  0,255)
#define COLOR_WHITE makecol(255,255,255)
#define COLOR_BLACK makecol(  0,  0,  0)
#define COLOR_GRAY  makecol(128,128,128)
#define COLOR_RED   makecol(255,  0,  0)
#define COLOR_GREEN makecol(0,  255,  0)
#define COLOR_BLUE  makecol(0,  0,  255)

#define ATTACK_LINE_COLOR COLOR_GREEN

#ifdef WIN32

   typedef signed __int8  Int8;
   typedef signed __int16 Int16;
   typedef signed __int32 Int32;
   typedef signed __int64 Int64;

   typedef unsigned __int8  uInt8;
   typedef unsigned __int16 uInt16;
   typedef unsigned __int32 uInt32;
   typedef unsigned __int64 uInt64;

#else

   typedef signed char      Int8;
   typedef signed short     Int16;
   typedef signed int       Int32;
   typedef signed long long Int64;

   typedef unsigned char      uInt8;
   typedef unsigned short     uInt16;
   typedef unsigned int       uInt32;
   typedef unsigned long long uInt64;

#endif


#define DELETE(ptr) { \
   if(ptr != NULL) {  \
      delete ptr; \
      ptr = NULL; \
   } }

#define DELETE_A(ptr) { \
   if(ptr != NULL) {  \
      delete [] ptr; \
      ptr = NULL; \
   } }


typedef struct _sPoint
{
   Int32 x;   // X point
   Int32 y;   // Y point
} sPoint;

