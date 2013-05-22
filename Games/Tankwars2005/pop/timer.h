#ifndef TIMER_HPP
#define TIMER_HPP

/* Rudy Rucker, August 10, 1999.  Usage.

Declare as cPerformanceTimer _timer;  The default constructor initializes it.

Inside an AppUpdate you're timing, put _timer.tick() and use the return value as your
real time measusrement of the AppUpdate.  You can also use _timer.dt() to access the
same number.

When going back into an AppUpdate process, call _timer.reset(), otherwise the 
_timer.dt() will be large, as it's been running while you were out of the AppUpdate.

To time something like a game, have an extra cPerformaneTimer _gametimer.  Call
_gametimer.reset() when the game starts.  In the AppUpdate process keep comparing
_gametimer.elapsedSeconds() to whatever GAME_LENGTH is in seconds, and when the
time is past do something like call cGameDoc::endGame().

On newer machines this timer uses a high-resolution performance counter.  On the
lastest machines this counter runs at the same clock cycle as the machine, e.g.
400 MHz. On slightly older machines, like a 200 MHz machine, the high-resolution
performance coutner runs at about 1 MHz.  So the counter frequency is not 
necessarily the same as the chip MHz.  On really old machines, this code defaults
to use the crappy old clock() function, which runs at about 50 ticks per second.
 */


class cPerformanceTimer
{
private:
	double _dt; //True time interval per update in seconds, can exceed _maxdt.
	double _mindt; //Shortest _dt to return in tick(), default 0.01
	double _maxdt; //longest time to return in tick(), default 0.1
	BOOL _highperformanceflag;
// High-resolution performance counter variables
	double _fCyclesPerSecond;
	LARGE_INTEGER _lgintStartUpdate;
	LARGE_INTEGER _lgintStartTimer;
	LARGE_INTEGER _lgintFinish;
	double _largeIntegerToDouble(LARGE_INTEGER lg);
// Non high-resolution performance counter variables
	unsigned long _nStartUpdate;
	unsigned long _nStartTimer;
	unsigned long _nFinish;
public:
	cPerformanceTimer();
	void reset();
	double tick(); //Returns _dt in seconds, clamped to be betwen _mindt, _maxdt
	double elapsedSeconds();
	double dt(){return _dt;} //Time since last update in seconds.
	double updatesPerSecond()const; //Rolling average of last sixty or so 1/_dt.
	BOOL highperformanceflag()const {return _highperformanceflag;}
	double minDt()const{return _mindt;}
	void setMinDt(double mindt); //Won't let you set it to 0.0.
	double maxDt()const{return _maxdt;}
	void setMaxDt(double maxdt);
	BOOL runningNearMaxSpeed()const{return updatesPerSecond() > 0.92 * (1.0/_mindt);}
		/* Because of the rolling average, we don't require you be exactly at
		the _mindt, being near it is enough.  How near?  Well, let's say 90%
		is close enough.  */
	BOOL runningNearMinSpeed()const{return updatesPerSecond() < 1.1 * (1.0/_maxdt);}
};

#endif //TIMER_HPP
