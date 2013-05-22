/****************************************
 filename:    timer.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/23
 description: Timer, keeps track of start to end time and if timer expired
 ****************************************/
#include "global.h"

float cTimer::mExpireMag = 1.0;

void cTimer::SetExpire(uInt32 e)
{
   mExpire = e;
}

void cTimer::SetExpirePerSec(float e)
{
   mExpire = (uInt32)(e*mOneSecond);
}

void cTimer::SetExpireMag(float mag)
{
   mExpireMag = mag;
}

void cTimer::Start()
{
   #ifdef WIN32
      mStartTime = 1000*GetTickCount();
   #else
      gettimeofday(&mStartTime, NULL);
   #endif
}

void cTimer::Update()
{
  #ifdef WIN32
     mCurrentTime = 1000*GetTickCount();
  #else
     gettimeofday(&mCurrentTime, NULL);
  #endif
}

uInt32 cTimer::GetTime()
{
   uInt32 time = 0;
   
   #ifdef WIN32
      time = 100*GetTickCount();
   #else
      struct timeval tv;
      gettimeofday(&tv, NULL);
      time = tv.tv_sec*mOneSecond + tv.tv_usec;
   #endif
   
   return time;
}

uInt32 cTimer::TimeDiff()
{
   #ifdef WIN32
      return (mCurrentTime - mStartTime);
   #else
      return ((mCurrentTime.tv_sec*mOneSecond + mCurrentTime.tv_usec) - 
              (mStartTime.tv_sec*mOneSecond + mStartTime.tv_usec) );
   #endif
}

bool cTimer::HasExpired()
{
   #ifdef WIN32
      if( (mCurrentTime - mStartTime) > (uInt32)(mExpire*mExpireMag) ) return true;
   #else
      if( ((mCurrentTime.tv_sec*mOneSecond + mCurrentTime.tv_usec) - 
           (mStartTime.tv_sec*mOneSecond + mStartTime.tv_usec) ) > (uInt32)(mExpire*mExpireMag) ) return true;
   #endif
   
   return false;  
}
