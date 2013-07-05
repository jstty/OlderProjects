/****************************************
 filename:    map.h
 description: 
 project:     astar
 created by:  Joseph E. Sutton
 version:   
 
 ****************************************/

#ifndef _MAP_
#define _MAP_

class Map
{
protected: 
   unsigned short width, height;
   bool           *grid;
   
public:
   
   int Load(const char *filename);
   
   // gets Manhattan distance from A to B
   static unsigned long GetDistance(unsigned short ax, unsigned short ay, unsigned short bx, unsigned short by);
   
   // returns if the area at this pos is blocked
   bool isBlocked(unsigned short x, unsigned short y);
   
};

#endif // _MAP_
