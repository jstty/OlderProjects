#ifndef METRIC_H
#define METRIC_H

#include "critter.h"
//#define USEMETRIC
/* Comment in USEMETRIC to have methods like Real cBiota::distance(cCritter *pa, 
	cCritter *pb) do a lookup of the distance in the precomputed cMetricCritter 
	array.  You can look up the direction as well.  In USEMETRIC mode, the
	the cBiota::updateMetric() refreshes the cMetricCritter array with every
	cGame::step.  
 At present, the USEMETRIC code is unsophisticated and
	tracks them metric for every possible pair of critters. If you improved the
	cBiota::updateMetric code to be smarter and to only compute the metric info for
	pairs you will check at least once, then you'd have something worth using.
If you comment out USEMETRIC you avoid the updateMetric overhead,
	but you have to compute each critter-to-critter distance and direction each
	time its requested.  For our current games, the code runs slower
	with USEMETRIC because, as mentioned above, we are in fact computing some distances
	we don't care about.  But should we start forces or methods in which
	the code is likely to  check the distance between a given critter-critter pair more 
	than once per game step, then it may be that USEMETRIC improves the speed.  This
	situation will arise if you do flocking code, as here a critter A will check its
	distance to a critter B two or three times per update as it carries out avoidance,
	flying parallel, and heading towards flock center, each of which requires a
	distance check.
On the other hand, USEMETRIC will very strongly
	reduce speed if you have a world with a lot of, say, walls that don't need to know
	each others' distance.  As mentioned above this could be fixed by making the
	updateMetric smarter.
The current implementaiotn is kludgy, it woudl be better to do something closer to the
	cCollider code. */

/* The cDistanceAndDirection utility class is needed for the values to be looked up
in the cMetricCritter.  This calss saves information about the distance and unit
vector direction between pairs of critters. */ 
class cDistanceAndDirection
{
public:
	Real _distance;
	cVector _direction;
	cDistanceAndDirection():_distance(0.0){} //Default cVector is (0,0).
	~cDistanceAndDirection(){}
	cDistanceAndDirection(Real dist, const cVector &dir){_distance = dist; _direction = dir;}
};

class cMetricCritter 
{
private:
	int _crittercount;
	int _arraysize; //Will always be _crittercount*_crittercount
	cDistanceAndDirection **_array;
public:
	void setSizeForCritterCount(int crittercount);
	cMetricCritter();
	~cMetricCritter();
	Real distance(cCritter *first, cCritter *second)
		{return	_array[first->metrickey()][second->metrickey()]._distance;}
	cVector direction(cCritter *first, cCritter *second)
		{return _array[first->metrickey()][second->metrickey()]._direction;}
	cDistanceAndDirection distanceanddirection(cCritter *first, cCritter *second)
		{return _array[first->metrickey()][second->metrickey()];}
	void setAt(int i, int j, Real distance, const cVector &direction)
		{_array[i][j]._distance = distance;	_array[i][j]._direction = direction;}
};

#endif //METRIC_H