#include "stdafx.h"
#include "Timer.h"
#include <math.h> //for fabs

/* If we try and update with a BitBlt over 200 times per second, the animation
has an odd jump in it every few hundred updates.  To prevent this, we don't 
allow the counter to run so overly fast, and make it spin in a while loop in
tick() if it would give a timestep of, say, less than a hundredth, which is
more than fast enough for a video animation.  0.005 or even 0.0025 are OK too,
but the jerkiness is present at 0.001.
We also set a _maxDT field because when you get less than ten or so updates per
second the program gets too jerky if we let the dt returned by updage() reflect 
the "true" dt per update.  For a really slow simulation, in other words, we
give up on real time and pretend we have 20 updates per second. */
#define START_MINDT 0.01
#define START_MAXDT 0.05

/* As we like to have the updatesPerSecond as information to show the user,
it shouldn't flicker between different values all the time, as it tends to do,
what with Windows doing things in the background during some cycles but not
during others.  To prevent the flicker, we use a rolling average of the 
values.  Empirically, I find that 60 is about the lowest average span which
stabilizes. Note that the use of a rolling average means that it takes the
values to home in on something stable, but that's ok and kind of cool to 
watch.  The static fixed array gets initizliazed to all 0s, so the startup
is a smooth creep upward. */

#define ROLLING_AVERAGE_SPAN 60

/* Comment FORCE_NOT_HIGHRESOLUTION_PERFORMANCE_COUNTER in, for testing, to prevent the 
High-resolution Performance Counter being used, so you can test the crappy 
lo-res clock() or timeGetTime() functions. */
//#define FORCE_NOT_HIGHRESOLUTION_PERFORMANCE_COUNTER 

 /* If USE_CLOCK is defined, use clock() function, otherwise use timeGetTime().
They seem to have about the same temporal resolution (minimum time interval
measured), and clock() is perhaps more portable.  Note that timeGetTime uses
the multimedia library. timeGetTime returns the time in milliseconds, it does
not have a resolution of one millisecond, that is, if you keep calling it, it
might return a different value only after 6 or 43 milliseconds.  The clock()
function is similar, but its units aren't guaranteed to be any special time
length.  You use the CLOCKS_PER_SECOND defined in time.h to convert clock values
into milliseconds.  As it happens, CLOCKS_PER_SECOND actually is 1000 in the
current Visual C++ implmenetation, so clock really is about the same as 
timeGetTime.  I'm not positive if the two have the same minimum jump size to 
their tick, I haven't checked it closely. Debugging timer code is a bit 
troublesome as when you're stopping for the debbugger, the clocks keep running,
so you see atypically long values of _dt in here. */
#define USE_CLOCK
#ifndef USE_CLOCK
#include <mmsystem.h> //for timeGetTime.  Must also link to winmm.lib
#endif //USE_CLOCK

/* I have largeIntegerToDouble function because a LARGE_INTEGER is a 64-bit "union"
type that can be viewed either as holding a single 64 bit integer field called
QuadPart, or as holding two 32 bit fields called LowPart and HighPart.  The QuadPart field
only works if my chip supports 64 bit integers, but perhaps some pre-Pentium chips 
may not. So I write a _largeIntegerToDouble function to munge a LARGE_INTEGER into
a double, and have a ASSUME_64BIT switch so it works on a pure 32-bit machine. 
Probably this isn't necessary, though, as we only use the LARGE_INTEGER on a machine
which supports High Performance counter, which means it's modern, so it would
be safe to comment ASSUME_64BIT in.  But we are only likely to need the
_largeIntegerToDouble  function once per update anyway, so the speed isn't a real
issue, so why not be safe. */
//#define ASSUME_64BIT


/* When I do my update method, it may happen that not very much time has elapsed since the
last call.  It's not a good idea to return very small dt from update as if you try and
update a monitor more often than its refresh rate (typically 60, 75, or 80 updates a second)
then the display will look screwed up.  Another issue is that if you're using the clock
or the timeGetTime function, it is a coarse measure of time and won't actually measure less
than something like 6 millisecond time clicks and can return a spurious 0.  So what we need
to do is to not allow update to return a dt less than our _mindt size, which should be at
the smallest something like 0.01 seconds (100 updates per second).  This means we have to
kill some time inside update.  The safest way to do this by simply running
 around and around a while loop till enough time had elapsed.  This has the bad effect of
sucking up a lot of processor time, so that the app won't share as well as it could in
multitasking situations.  To some extent this doesn't matter, becuase a Pop framework
app will in fact pause when it loses the focus.
	I experimented with using the ::Sleep function and put the execution thread to sleep for a 
a few milliseconds.  This would seem to support multitasking better than hoggin the processor
with a while loop.  But on Feb 27, 00, I found that if I use the Sleep method, then often
a Pop framework app will cause the machine not to be able to run any other apps.  The Pop
app keeps running fine, but if you try and open another app, it won't open.  And if you 
close the Pop app, all other apps are still frozen; the only way out is to to a hard on/off
switch reboot.  This bug was particularly hard to pinpoint as it doesn't happen all the time,
or right away.  Typically it would happen only after the Pop app had run for some time.  But
if I let it run long enough (15 minutes to half an hour), then it would always arise, that is,
I would be unable to open up another other apps besides the Pop app, and this bad beavior 
would continue even after the Pop app was closed.  I don't know why this behavior occurs.
This note from the Sleep documentation may be relevant.  "If you have a thread that uses Sleep
with infinite delay, the system will deadlock."  For now, don't use Sleep. */
//#define USESLEEP //DON'T comment this in!

/* I use the SHOWSPIN to invoke a TRACE to dump the spincount to the output window in both
the highperformaance counter and regular clock modes.  See more comments down in the update function.*/
//#define SHOWSPIN

#ifdef _DEBUG
#define MAXSLEEPWAIT 100
#endif //_DEBUG

double cPerformanceTimer::_largeIntegerToDouble(LARGE_INTEGER lg)
{
#ifndef ASSUME_64BIT
	double lowpart, highpart, quadpart;
	lowpart = double(lg.LowPart);
	highpart = double(lg.HighPart);
	highpart *= (double(0xFFFFFFFFUL)+1.0); //This is a way to say 2^32.
	quadpart = highpart + lowpart;
	return quadpart;
#else //ASSUME_64BIT
	double quadpart = double(lg.QuadPart);
	return quadpart;
#endif //ASSUME_64BIT
}

cPerformanceTimer::cPerformanceTimer():
	_dt(START_MINDT), //Just to put a non-zero number in here.
	_mindt(START_MINDT), 
	_maxdt(START_MAXDT), 
	_highperformanceflag(FALSE), 
	_nStartUpdate(0),
	_nFinish(0),
	_nStartTimer(0)
{
	_fCyclesPerSecond = double(90000000UL); //90 MegaHerz, just for a default
	_lgintStartUpdate.LowPart = _lgintStartUpdate.HighPart = 0;
	_lgintStartTimer.LowPart = _lgintStartTimer.HighPart = 0;
	_lgintFinish.LowPart = _lgintFinish.HighPart = 0;
	LARGE_INTEGER nCyclesPerSecond;
#ifndef FORCE_NOT_HIGHRESOLUTION_PERFORMANCE_COUNTER
	if (_highperformanceflag = ::QueryPerformanceFrequency(&nCyclesPerSecond))
	{
		_fCyclesPerSecond = _largeIntegerToDouble(nCyclesPerSecond);
/* I used to not bother with the performance counter if its not accurate to 100 million, that is, 
accurate to a tick per cycle, but it's worth trying to use it anyway.
		if (_fCyclesPerSecond < 100000000UL)
			_highperformanceflag = FALSE; */
	}
#endif //FORCE_NOT_HIGHRESOLUTION_PERFORMANCE_COUNTER
	reset();
} 

void cPerformanceTimer::setMinDt(double mindt)
{ //Won't let you set it to 0.0 or above _maxdt.
	if (!mindt)
		return;
	if (mindt > _maxdt)
		mindt = _maxdt;
	_mindt = mindt;
}

void cPerformanceTimer::setMaxDt(double maxdt)
{ //Won't let you set it below _mindt.
	if (maxdt < _mindt)
		maxdt = _mindt;
	_maxdt = maxdt;
}

double cPerformanceTimer::updatesPerSecond()const
{
	static double ups[ROLLING_AVERAGE_SPAN];
	double ups_sum = 0.0;

	for (int i=ROLLING_AVERAGE_SPAN - 1; i>0 ; i--)
	{
		ups[i] = ups[i-1];
		ups_sum += ups[i];
	}
	
	if (fabs(_dt)<_mindt) //Redundant check to prevent division by 0
		ups[0] = 1/_mindt;
	else
		ups[0] =  1.0/_dt; 
	return (ups_sum + ups[0])/ROLLING_AVERAGE_SPAN;
}

void cPerformanceTimer::reset()
{ 
 	if (_highperformanceflag)
	{
		::QueryPerformanceCounter(&_lgintStartUpdate);
		_lgintFinish = _lgintStartTimer = _lgintStartUpdate;
	}
	else
	{
#ifdef USE_CLOCK
		_nStartUpdate = clock();
#else //not USE_CLOCK
		_nStartUpdate = timeGetTime();
#endif //USE_CLOCK
		_nFinish = _nStartTimer = _nStartUpdate;
	}
}

#ifdef USESLEEP
double cPerformanceTimer::tick()
{
	double dt = 0;
#ifdef _DEBUG
	unsigned long sleepmillis = 0;
#endif //_DEBUG
	if (_highperformanceflag)
	{

		::QueryPerformanceCounter(&_lgintFinish);
		dt = (_largeIntegerToDouble(_lgintFinish) -
			 _largeIntegerToDouble(_lgintStartUpdate)) / _fCyclesPerSecond;
#ifdef _DEBUG
		if (dt < _mindt)
		{
			sleepmillis = (unsigned long)(1000.0 * (_mindt - dt));
			ASSERT(sleepmillis < MAXSLEEPWAIT); 
		}
#endif //_DEBUG
		if (dt < _mindt)
			::Sleep((unsigned long)(1000.0 * (_mindt - dt)));
		::QueryPerformanceCounter(&_lgintFinish);
		dt = (_largeIntegerToDouble(_lgintFinish) -
			 _largeIntegerToDouble(_lgintStartUpdate)) / _fCyclesPerSecond;
		_lgintStartUpdate = _lgintFinish;
	}
	else
	{ /* The  lo-res time functions often haven't clicked yet and you get a
	false read of a _dt of 0.0, which means no update is actually done and
	a misleading value gets into the updatesPerSecond, so we just 
	wait for the  clock to tick. Instead of ticking in increments of one,
	these clocks tick in increments of 6 or 21 or something. */
	#ifdef USE_CLOCK
		_nFinish = clock();
		dt =  double(_nFinish - _nStartUpdate)/CLOCKS_PER_SEC;
#ifdef _DEBUG
		if (dt < _mindt)
		{
			sleepmillis = (unsigned long)(1000.0 * (_mindt - dt));
			ASSERT(sleepmillis < MAXSLEEPWAIT); 
		}
#endif //_DEBUG
		if (dt < _mindt)
			::Sleep((unsigned long)(1000.0 * (_mindt - dt)));
		_nFinish = clock();
		dt =  double(_nFinish - _nStartUpdate)/CLOCKS_PER_SEC;
	#else //not USE_CLOCK
		_nFinish = timeGetTime();
		dt =  double(_nFinish - _nStartUpdate)/ 1000.0;
		dt =  double(_nFinish - _nStartUpdate)/CLOCKS_PER_SEC;
#ifdef _DEBUG
		if (dt < _mindt)
		{
			sleepmillis = (unsigned long)(1000.0 * (_mindt - dt));
			ASSERT(sleepmillis < MAXSLEEPWAIT); 
		}
#endif //_DEBUG
		if (dt < _mindt)
			::Sleep((unsigned long)(1000.0 * (_mindt - dt)));
		_nFinish = timeGetTime();
		dt =  double(_nFinish - _nStartUpdate)/ 1000.0;
	#endif //USE_CLOCK
		_nStartUpdate = _nFinish;
		_dt = dt;
	}
	_dt = dt;
	return __min(_dt, _maxdt);
}

#else //not USESLEEP

double cPerformanceTimer::tick()
{
	double dt = 0;
#ifdef SHOWSPIN
	int spiniterations = 0;
#endif SHOWSPIN

	if (_highperformanceflag)
	{
		while (dt < _mindt) // Don't try to update overly fast.
		{
			::QueryPerformanceCounter(&_lgintFinish);
			dt = (_largeIntegerToDouble(_lgintFinish) -
				 _largeIntegerToDouble(_lgintStartUpdate)) / _fCyclesPerSecond;
	/* If I put these lines in I find that I'll get dt = 0.0 a bunch of times and then eventually, and
	if _minddt happens to be 0.01, I'll get a spiniterations of about 1,000 and a dt of something lke
	0.010001, when _highperformance flag is on.  Note, however that if I move the mouse, or press the
	kyes, the spiniterations are more likely to be 1 or 2 and the dt will be more like 0.015 or soemthing,
	 as the system used up time in processing the mouse message.*/
#ifdef SHOWSPIN
		spiniterations++;
		if (dt >= _mindt) 
		TRACE("highperformance spiniterations = %d, dt = %f\n", spiniterations, dt);
#endif //SHOWSPIN

		}
		_lgintStartUpdate = _lgintFinish;
	}
	else
	{ /* The  lo-res time functions often haven't clicked yet and you get a
	false read of a _dt of 0.0, which means no update is actually done and
	a misleading value gets into the updatesPerSecond, so we just 
	wait for the  clock to tick. Instead of ticking in increments of one,
	these clocks tick in increments of 6 or 21 or something. I can measure this
	by using the spiniterations counter, if I like. */
		while (dt < _mindt)
		{
	#ifdef USE_CLOCK
			_nFinish = clock();
			dt =  double(_nFinish - _nStartUpdate)/CLOCKS_PER_SEC;
	#else //not USE_CLOCK
			_nFinish = timeGetTime();
			dt =  double(_nFinish - _nStartUpdate)/ 1000.0;
	#endif //USE_CLOCK
	/* If I run on Win98, which doesn't support high performance flag, or force this mode by commenting
in the #define FORCE_NOT_HIGHRESOLUTION_PERFORMANCE_COUNTER line, then
I find that I'll get dt = 0.0 thousands  of times and then eventually, when I get to 
 a spiniterations of about 15,000 I'll suddenly get a dt of 0.16 when USE_CLOCK is on.  The same if USE_CLOCK
is off. */
#ifdef SHOWSPIN
		spiniterations++;
		if (dt >= _mindt) // if (dt != 0.0) will do the same thing here, as dt is steadily 0 before jumping to 0.16
		TRACE("clock spiniterations = %d, dt = %f\n", spiniterations, dt);
#endif //SHOWSPIN
		}
		_nStartUpdate = _nFinish;
		_dt = dt;
	}
	_dt = dt;
	return __min(_dt, _maxdt);
}
#endif //USESLEEP

double cPerformanceTimer::elapsedSeconds()
{
	tick();
	if (_highperformanceflag)
		return (_largeIntegerToDouble(_lgintFinish) -
			_largeIntegerToDouble(_lgintStartTimer)) / _fCyclesPerSecond;
	else
#ifdef USE_CLOCK
		return  double(_nFinish - _nStartTimer)/CLOCKS_PER_SEC;
#else //not USE_CLOCK
		return  double(_nFinish - _nStartTimer)/1000.0;
#endif //USE_CLOCK
}
