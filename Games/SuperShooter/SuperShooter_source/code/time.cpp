////////////////////////////////////////////////////////////////////////
//	Program Name:	time.cpp
//	Programmer:		Joseph E. Sutton
//	Description:	Time Functions
//	Date:				6/17/02
//	v2.00 Date:		8/20/2002
//	Version:			2.00
////////////////////////////////////////////////////////////////////////

#include "time.h"

Time::Time()
{
	hour = 0;
	min = 0;
	sec = 0;
	msec = 0;
}

void Time::Set(Time t)
{
	hour = t.hour;
	min = t.min;
	sec = t.sec;
	msec = t.msec;
}

void Time::Set(uInt8 h, uInt8 m, uInt8 s, uInt16 ms)
{
	hour = h;
	min = m;
	sec = s;
	msec = ms;
}

void Time::Set(uInt32 t)
{
	float temp;

	temp = ((float)t)/MS_HOUR;
	hour = (uInt8)(temp);
	// subtract whole hour
	t -= hour*MS_HOUR;

	temp = ((float)t)/MS_MIN;
	min = (uInt8)(temp);
	// subtract whole minute
	t -= min*MS_MIN;

	temp = ((float)t)/MS_SEC;
	sec = (uInt8)(temp);
	// subtract whole minute
	t -= sec*MS_SEC;

	// 
	msec = (uInt16)(t);
}

Time::operator =(Time t)
{
	Set(t);
}

Time::operator =(uInt32 t)
{
	Set(t);
}

void Time::Current()
{
	time_t long_time;
	struct tm *tt;
	time( &long_time );
	tt = localtime(&long_time);
	if(tt != NULL)
	{
		Set(tt->tm_hour, tt->tm_min, tt->tm_sec);
	}
}

void Time::Copy(Time *tt)
{
	if(tt != NULL)
		Set(tt->GetTime());
}

int Time::Compare(Time tt)
{
	if(
		(hour == tt.hour) &&
		(min == tt.min) &&
		(sec == tt.sec) &&
		(msec == tt.msec)	)	return 1;
	else					    return 0;
}

const char *Time::GetText24H(char *format)
{
	if(format == NULL) return time_str;

	sprintf(time_str, format, hour, min, sec, msec);
	return time_str;
}

const char *Time::GetTextMS(char *format)
{
	if(format == NULL) return time_str;

	sprintf(time_str, format, min, sec, msec);
	return time_str;
}

const char *Time::GetText(char *format)
{
	if(format == NULL) return NULL;

	char ampm[4] = " am";
	uInt8 th = hour;
	if(th > 12)
	{
		th -= 12;
		strcpy(ampm, " pm");
	}

	sprintf(time_str, format, th, min, sec, msec);
	strcat(time_str, ampm);

	return time_str;
}

// return char * (aka string)
Time::operator const char *()
{
	return GetText24H();
}


uInt32 Time::GetTime()
{
	uInt32 t = 0;
	t += hour*MS_HOUR;	// Hours
	t += min*MS_MIN;	// Minutes
	t += sec*MS_SEC;	// seconds
	t += msec;			// milli-seconds
	return t;
}

Time::operator uInt32()
{
	return GetTime();
}

