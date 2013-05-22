/****************************************
 filename:    timer.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: Timer, keeps track of start to end time and if timer expired
 ****************************************/
#ifndef _TIMER_
#define _TIMER_

class cTimer
{
protected:
   uInt32 mExpire;
   static const uInt32 mOneSecond = 1000000;
   static float mExpireMag;
   
   #ifdef WIN32
      uInt32 mStartTime;
      uInt32 mCurrentTime;
   #else
      struct timeval mStartTime;
      struct timeval mCurrentTime;
   #endif
   
public:
	void SetExpire(uInt32 e);
   void SetExpirePerSec(float e);
   static void SetExpireMag(float mag);

	void Start();
	void Update();
	bool HasExpired();
	
   static uInt32 GetTime();
   uInt32 TimeDiff();
};

#endif // _TIMER_
