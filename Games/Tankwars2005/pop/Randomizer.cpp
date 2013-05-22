// We always need to include stdafx.h include first in files to compile under MFC. 
#include "stdafx.h"  //Comment this line out if not using Microsoft MFC.

#include <stdlib.h> //For _lrotr and _lrotl, rand(), and srand() used by RR_CA30
#include <time.h> //For C library Unix time function
#include <math.h> // For cos and sin in randomunitpair
#include "randomizer.h"

//Static member 
cRandomizer* cRandomizer::_pinstancesingleton = NULL; /* Initialize with the first call to pinstance().
	and release with a garbageCollect() call in your WinApp's destructor. */

cRandomizer* cRandomizer::pinstance()/* pinstance() allocates
	_pinstancesingleton if it's NULL, then returns it. */
{
	if (cRandomizer::_pinstancesingleton == NULL) 
		//First time pinstance() is called
#define REGRESSIONTEST //Force identical startup even in Release
#ifndef _DEBUG 
	#ifndef REGRESSIONTEST
		 cRandomizer::_pinstancesingleton = new cRandomizer(1);
	#else //REGRESSIONTEST
		 cRandomizer::_pinstancesingleton = new cRandomizer();
	#endif //REGRESSIONTEST
	//In Release build, default constructor seeds with time for variety.
#else 
		 cRandomizer::_pinstancesingleton = new cRandomizer(1);
	// In the Debug build, use a fixed seed to help replicate bugs.
#endif //_DEBUG
	return cRandomizer::_pinstancesingleton;
}

#ifndef PI
#define PI 3.14159265358979
#endif //PI

//-------Constructors and Mutators---------

cRandomizer::cRandomizer()
{
	randomizeSeed();
}

cRandomizer::cRandomizer(unsigned long seednumber)
{
	setSeed(seednumber);
}

unsigned long cRandomizer::randomizeSeed()
{
// This uses the Unix time function to install a random seed.
	unsigned long seednumber = time(NULL); // Seconds since midnight, Jan 1, 1970
	_shiftregister = _seed = seednumber; //Seed the CA30 randomizer
	srand(seednumber);		//C Library function to seed the C Library randomizer
	return (unsigned long)seednumber;
}

void cRandomizer::setSeed(unsigned long seednumber)
{
	_shiftregister = _seed = seednumber;
	srand(seednumber);		//C Library function to seed the C Library randomizer
}

//-------Methods---------
unsigned long cRandomizer::_thirtytwobits()
{
#define DOITYOURSELF //Use the idea of the C Library randomizer, but do it yourself
#ifdef DOITYOURSELF 
 /* Do the Microsoft C Library calculation yourself but keep 16 bits of
	each call instead of just 15, and that way we only need two calls, not three,
	to get the 32 bits for our answer. You do need the two calls because if
	you try and just do it once and return _shiftregister you get enough
	correlations to fail the randomColor test (there's patterns in the snow). */
	unsigned long hiword, loword;
	_shiftregister *= 214013L;
	hiword = _shiftregister += 2531011L;
	_shiftregister *= 214013L;
	loword = _shiftregister += 2531011L;
	return (hiword & 0xFFFF0000L) | (loword >> 16);
#else //Use the CLibrary call that only gives you 15 bits.
	/* The C library rand() supplies 15 bits, a positive int between 0 and +32K.
		We assemble this into a 32 bit number. */
	register unsigned long c,r;
	c = rand(); //This gives me 15 good bits
	c <<= 15;	//Shift the bits up to the left
	r = rand();
	c |= r;		//OR in 15 more good bits.
	c <<= 2;	//Shift up by 2 to make room for the last two bits
	r = rand();
	c |= (r & 3); //Just use the low two bits.
	return c;
#endif //DOITYOURSELF
}

unsigned long cRandomizer::random()
{
	return ( (unsigned long)((this->*_thirtytwobits)()) );
}


unsigned long cRandomizer::random(unsigned long n)
{
/* This returns a random integer from 0 to n - 1. */
/* Bail 0 if n <= 1 to avoid weirdness with modulo operator.*/
	if (n <= 0)
		return 0;
	return ( (unsigned long)((this->*_thirtytwobits)() % n) );
/* Remember that N%k is the remainder when N is divided by k.  If N and k are positive,
	this means that N%k is a number ranging between 0 and k. Behavior of % is 
	weird for negative numbers. */ 
}

long cRandomizer::random(long lon, long hin)
{
/* This returns a random integer from lon to hin inclusive. */
/* Bail 0 if n <= 1 to avoid weirdness with modulo operator.*/
	if (lon == hin)
		return lon;
	if (lon > hin) //swap
	{ 
		long temp = lon;
		lon = hin;
		hin = temp;
	}
	return ( lon + (long)((this->*_thirtytwobits)() % (hin - lon + 1)) );
}

BOOL cRandomizer::randomBOOL(Real truthweight)
{
	if (truthweight == 0.5) //Do something faster
		return ((this->*_thirtytwobits)() & 1);
	else
		return (randomReal() < truthweight);	
}

unsigned char cRandomizer::randomByte(void)
{
	return (unsigned char)( (this->*_thirtytwobits)() & 0x00FF );
}

unsigned short cRandomizer::randomShort(unsigned short n)
{
/* This returns a random integer from 0 to n - 1. */
/* Bail 0 if n <= 1 to avoid weirdness with modulo operator.*/
	if (n <= 0)
		return 0;
	return ( (unsigned short)((unsigned short)((this->*_thirtytwobits)()) % n) );
}

Real cRandomizer::randomReal()
{
/* This returns a random real between 0 and 1. */
	return (((Real)((this->*_thirtytwobits)())) / 0xFFFFFFFFUL);
}

Real cRandomizer::randomSign(void)
{
	if ((this->*_thirtytwobits)() & 1)
		return 1.0;
	else
		return -1.0;
}

Real cRandomizer::randomSignedReal(void)
{
/* This returns a random real between -1 and 1. */
	return ( -1.0 + 2.0 * randomReal() );
}

Real cRandomizer::randomReal(Real lo, Real hi) //A real between lo and hi
{
	return ( lo + (hi-lo) * randomReal() );
}

void cRandomizer::randomUnitDiskPair(Real *x, Real *y)
{/* randomizes the pair (x,y) within unit pythagorean distance of (0,0).  We
	have to do this in a tricky way because you want to distribute over
	a disk not a square. */
	*x = randomSignedReal();
	*y = randomSignedReal();
	while ((*x)*(*x) + (*y)*(*y) > 1.0)
	{
		*x = randomSignedReal();
		*y = randomSignedReal();
	}
}

void cRandomizer::randomUnitPair(Real *x, Real *y)
{
	Real angle = randomReal(0, 2.0 * PI);
	*x = cos(angle);
	*y = sin(angle);
}

void cRandomizer::randomUnitSphereTriple(Real *x, Real *y, Real *z)
{/* randomizes the pair (x,y) within unit pythagorean distance of (0,0).  We
	have to do this in a tricky way because you want to distribute over
	a disk not a square. */
	*x = randomSignedReal();
	*y = randomSignedReal();
	*z = randomSignedReal();
	while ((*x)*(*x) + (*y)*(*y) + (*z)*(*z) > 1.0)
	{
		*x = randomSignedReal();
		*y = randomSignedReal();
		*z = randomSignedReal();
	}
}

void cRandomizer::randomUnitTriple(Real *x, Real *y, Real *z)
{
	Real norm = 0.0; 
	while (norm <= 0.001) //Avoid dividing by something small.
	{
		randomUnitSphereTriple(x, y, z);
		norm = sqrt((*x)*(*x) + (*y)*(*y) + (*z)*(*z));
	}
	*x /= norm;
	*y /= norm;
	*z /= norm;
}


Real cRandomizer::mutate(Real base, Real lo, Real hi, Real percent) //Mutate base by percent of size.
{
	if (percent == 1.0)
		return randomReal(lo,hi);
	Real temp, range = hi-lo;
	temp = base + randomSignedReal()*percent*range;
	if (temp<lo) temp = lo; if (temp > hi) temp = hi;
	return temp;
}

int cRandomizer::mutate(int base, int lo, int hi, Real percent)
{
	if (percent == 1.0)
		return random(lo,hi);
	int temp, range = hi-lo;
	temp = int(base + randomSignedReal()*percent*range);
	if (temp<lo) temp = lo; if (temp > hi) temp = hi;
	return temp;
}

unsigned long cRandomizer::mutateColor(unsigned long basecolor, Real percent)
{ //Mutate a color.
	if (percent == 1.0)
		return randomColor();
	return  (unsigned long)((1.0 - percent)*basecolor + percent*randomColor());
}

unsigned long cRandomizer::randomColor()
{
/* We assemble a Windows style COLORREF, which is a 32 bit number with the 
form 0x00bbggrr  with the letter bytes standing for blue, green, and red.
 The color numbers are intensities between 0 and 255. COLORREF is a Windows
typedef for DWORD which is in turn a Windows typedef for unsigned long. We
don't want to mention the Windows types in here because we want this module
to be fully portable to other C++ platforms.  */
	unsigned long temp;
	return 	temp = (this->*_thirtytwobits)() & 0x00FFFFFF;
}
 
//========================== Begin Historical Note ===========================================
/* During the 1980s Rudker believed it was possible to implement a faster randomizer
based on a cellular automata rule discovered by Stephen Wolfram and called Rule 30.   
	Stephen Wolfram believed this rule makes a good randomizer, see his paper on
the subject in his anthology, Theory and Applications of Cellular
Automata, World Scientific, 1986.  See also Wolfram's Patent #4,691,291
on this rule, and be warned that use of Rule 30 as a randomizer may
be in violation of the patent.
	The rule does not work well as a randomizer becauase it tends to die out on
small arrays.  To "fix" it, Rucker altered the randomizer by adding
a "_count" register.  To prevent the rule from quickly dying out in a
small 32 bit register, we keep  XORing it with a count.  But in any case,
the rule works very poorly as a randomizer, at least with the 32 bit word size
we tried. 
	A quick test of the validity of the rules can be done with the Windows 
Random program supplied with this code.  We have two tests, one for randomColor and
one for randomReal.  The idea is to fill the screen with, respectively, calls to
	SetPixel(i, j, randomizer.randomColor());
or to get cx and cy as the screen size and do calls to 
	SetPixel(int(_randomizer.randomReal()*cx),	int(_randomizer.randomReal()*cy),
		RGB(0,0,0));
	CA Rule 30 fails the first test, but not too badly, and fails the second test
rather dramatically by drawing a fractal dust instead of the expected video snow!

	Just for the record, here is the CA based randmoizing rule.  It needs an extra
	unsigned long _count variable in the cRandomizer.  _count gets intialized to 
	0 whenever you set the seed.*/

//#define JUNKCODE
#ifdef JUNKCODE
unsigned long cRandomizer::_thirtytwobits_ca30()
{
	register unsigned long l, r, c = _shiftregister;
	/* The next five lines are Rule 30.  If we only do it once per call,
	there is too much correlation between successive members.  Twice is
	enough to fix colors but no number of repeats seems to be 
	enough to fix reals, sigh. */

	l = r = c;
	l = _lrotr(l, 1);/* bit i of l equals bit just left of bit i in c */
	r = _lrotl(r, 1);/* bit i of r euqals bit just right of bit i in c */
	c |= r;
	c ^= l;	/* c = l xor (c or r), aka rule 30, named by Wolfram */
	c ^= _count;	/* Rucker's trick to  make reaction self-sustaining */
	_count++;
	_shiftregister = c;
	return c;
}
#endif //JUNKCODE
//========================== End Historical Note ===========================================
