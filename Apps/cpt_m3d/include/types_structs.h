//////////////////////////////////////////////////////////////////////////////
// Program Name:	types_structs.h
// Programmer:		Joseph E. Sutton
// Description:	types and structs
// Start Date:		2/15/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __TYPE_STRUCTS__
#define __TYPE_STRUCTS__

#ifndef WIN32
   typedef unsigned char  uInt8;
   typedef   signed char  sInt8;
   typedef unsigned short uInt16;
   typedef   signed short sInt16;
   typedef unsigned long  uInt32;
   typedef   signed long  sInt32;
   typedef unsigned long long int uInt64;
   typedef   signed long long int sInt64;
#else
   typedef unsigned __int8  uInt8;
   typedef   signed __int8  sInt8;
   typedef unsigned __int16 uInt16;
   typedef   signed __int16 sInt16;
   typedef unsigned __int32 uInt32;
   typedef   signed __int32 sInt32;
   typedef unsigned __int64 uInt64;
   typedef   signed __int64 sInt64;
#endif

#define PI      3.14159265359f
#define PI_180  (PI/(double)180.0)
#define _180_PI ((double)180.0/PI)


#ifdef WIN32
   #include <windows.h>
   #define getHiResTime() (((double)GetTickCount()/1000.0f))
#else
   #include <sys/time.h>
   
   inline double getHiResTime()
   {
      struct timeval tv;
      double t;
      
      gettimeofday(&tv, NULL);
      t = ((double)tv.tv_sec + ((double)tv.tv_usec/1000000.0f));
      return t;
   }
#endif


typedef struct _Color
{
   double r;
   double g;
   double b;
} Color;

typedef struct _Point3D
{
	double x;
	double y;
	double z;
      
   union
   {
      double heading;
      double rad;
      double xrot;
   };
   
   union
   {
      double den; // density
      double yrot;
   };
} Point3D;


/*
* produces a unit variance normal random variable
*
*
*/
#include <stdlib.h>
#include <math.h>
inline double nrand()
{
	double r=0;
	int i, n=10;

	for(i = 0; i < n; ++i)
	{
		r += ((double)rand()/RAND_MAX); // in [0,n]
	}
	
	r = (r - (double)n/2.0) * 2.0 * sqrt( 3.0/((double)n) );
	return(r);
}


#endif // __TYPE_STRUCTS__

