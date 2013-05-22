#ifndef RANDOMIZER_H
#define RANDOMIZER_H

/* This is a set of 32-bit-based randomizing functions written by Rudy Rucker,
rucker@mathcs.sjsu.edu.  The functions use a standard C library technique. The code
is written to be fully portable, although there is one line you need to comment in
or out at the head of Randomizer.cpp according to whether or not you use Microsoft
MFC.
	 These randomizing functions are based on a modular scheme derived
from the Microsoft implmentation of the C library randomizer. In the Microsoft
implementation, the C Library int rand() function works by rand works by
maintaining a _holdrand variable and iterating _holdrand * 214013 + 2531011.
rand() returns (_holdrand >> 16) & 07FFF, which is a 15 bit positive short
integer.  We use the same scheme, but tailor it to return a 32 bit unsigned 
long integer. Returning _holdrand gives too much correlation, so we actually
execute the _holdrand update twice, and use the high words of the two
successive _holdrands as the upper and lower words of the value we return.
	The Randomizer.cpp file includes a historical note at the end about an 
unsuccessful attempt to base the randomizer on Wolfram's CA Rule 30.
	We  make cRandomizer a singleton class, menaing that an application can only make
and use one instance of it.  To accomplish this, we (a) make the constructors private,
(b) add a public pinstance() method that returns a pointer to a unique static cRandomizer*
object _pinstancesingleton which is initially NULL(c) make the pinstance() implementation 
resposible for calling "new" to allocate _pinstancesingleton if it is NULL and (d) add
a static deleteSingleton() method to be called by the App to delete _pinstancesingleton
at exit.
 */

#include "realnumber.h" //For the Real typedef, which is double or float

class cRandomizer
{
private:
	static cRandomizer *_pinstancesingleton;
public:
	static cRandomizer *pinstance(); /* pinstance() allocates _pinstancesingleton if this is
		NULL, then returns _pinstancesingleton. */
	static void deleteSingleton(){delete _pinstancesingleton; _pinstancesingleton = NULL;}	
		/* We need to delete the _pinstancesingleton somewhere, the CPopApp destructor is a
		reasonable spot. */
private:
	unsigned long _seed; //Start value of _shiftregister
	unsigned long _shiftregister; //Used internally for the running compute process.
	unsigned long _thirtytwobits(); // The internal pseudorandom function used.
	cRandomizer(); //Uses the C Library randomizer and seeds it with the time.
	cRandomizer(unsigned long seednumber); //C Library randomizer seeded by seednumber.
public:
	unsigned long getSeed(){return _seed;}
	void setSeed(unsigned long seednumber); //Start the off in a specific state
	unsigned long randomizeSeed(void); //Seed with the time in seconds
	unsigned long random(); //Return an unsigned long int
	unsigned long random(unsigned long n); //Return an int betweeon 0 and n - 1
	long random(long lon, long hin); //int between lon and hin inclusive
	BOOL randomBOOL(Real truthweight = 0.5); // Return TRUE truthweight often.
	unsigned char randomByte(void); //Return a byte between 0 and 255
	unsigned short randomShort(unsigned short n); // Short between 0 and n-1
	Real randomReal(void); //A real between 0.0 and 1.0
	Real randomSignedReal(void); //A real between -1.0 and 1.0
	Real randomReal(Real lo, Real hi); //A real between lo and hi
	Real mutate(Real base, Real lo, Real hi, Real percent); //Mutate base by percent of size.
	int mutate(int base, int lo, int hi, Real percent); //Mutate base by percent of size.
	unsigned long mutateColor(unsigned long base, Real percent); //Mutate a color.
	Real randomSign(void); //1.0 or -1.0
	void randomUnitDiskPair(Real *x, Real *y);
	// Makes (x,y) a random point with distance <= 1 from (0,0)
	void randomUnitPair(Real *x, Real *y);
	// Makes (x,y) a random point with distance 1 from (0,0)
	void randomUnitSphereTriple(Real *x, Real *y, Real *z);
	// Makes (x,y,z) a random point with distance <= 1 from (0,0)
	void randomUnitTriple(Real *x, Real *y, Real *z);
	// Makes (x,y, z) a random point with distance 1 from (0,0)
	unsigned long randomColor(); //A Windows COLORREF number.
};

#endif RANDOMIZER_H