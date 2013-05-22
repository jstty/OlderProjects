////////////////////////////////////////////////////////////////////////
//	Program Name:	time.h
//	Programmer:		Joseph E. Sutton
//	Description:	Time Header
//	Date:				1/2/02
//	v2.00 Date:		8/20/2002
//	Version:			2.00
////////////////////////////////////////////////////////////////////////

#ifndef _TIME_DEF
#define _TIME_DEF

#define MS_HOUR 3600000
#define MS_MIN  60000
#define MS_SEC  1000
#define TIME_FORMAT_DEF    "%0.2d:%0.2d:%0.2d.%0.2d"
#define TIME_FORMAT_SIMPLE "%0.2d:%0.2d:%0.2d"
#define TIME_FORMAT_MIN_SEC "%0.2d:%0.2d"

#include "main.h"

class Time
{
public:
	uInt8 hour;
	uInt8 min;
	uInt8 sec;
	uInt16 msec;
   char time_str[256];

	Time();

	operator =(Time t);
	operator =(uInt32 t);
	void Set(Time t);
	void Set(uInt8 h, uInt8 m, uInt8 s = 0, uInt16 ms = 0);
	void Set(uInt32 t);
	void Current();

	void Copy(Time *tt);	// copy from this to dest
	int Compare(Time tt);
	int operator ==(Time tt){	return Compare(tt);	};

	const char *GetText(char *format = TIME_FORMAT_DEF);
   const char *GetTextMS(char *format = TIME_FORMAT_MIN_SEC);
	const char *GetText24H(char *format = TIME_FORMAT_DEF);
	operator const char *();				// return char * (aka string)

	uInt32 GetTime();
	operator uInt32();				// return uInt32 (aka int)
};


#endif