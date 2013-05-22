// Biota.cpp: implementation of the cBiota class.
//
//////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include "metric.h"

cMetricCritter::cMetricCritter():
_arraysize(0),
_crittercount(0),
_array(NULL)
{}

cMetricCritter::~cMetricCritter()
{
	for (int i=0; i<_arraysize; i++)
		delete [] _array[i];
	delete [] _array;
	_arraysize = 0;
}	

void cMetricCritter::setSizeForCritterCount(int crittercount)
{
	if (_arraysize == crittercount)
		return;
	for (int i=0; i<_arraysize; i++)
		delete [] _array[i];
	delete [] _array;
	_arraysize = crittercount;
	_array = new cDistanceAndDirection*[_arraysize];
	for (i=0; i<_arraysize; i++)
	{
		_array[i] = new cDistanceAndDirection[_arraysize];
		_array[i][i] = cDistanceAndDirection(0.0, cVector(0.0, 0.0));
	}
}

