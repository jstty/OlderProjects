/****************************************
 filename:    map.cpp
 description: 
 project:     astar
 created by:  Joseph E. Sutton
 version:   
 
 ****************************************/

#include "global.h"

unsigned long Map::GetDistance(unsigned short ax, unsigned short ay, unsigned short bx, unsigned short by)
{
   return abs(bx - ax) + abs(by - ay);
}

bool Map::isBlocked(unsigned short x, unsigned short y)
{
   return grid[x + (width - y - 1)*width];
}

int Map::Load(const char *filename)
{
   int i, j, d1, d2;
   FILE * fp = NULL;
   char *tmp = NULL;
      
   fp = fopen(filename, "r");
   if(fp == NULL)  return 1; // error could not load file
   
   fscanf(fp, "WIDTH = %d\n",     &d1);
   fscanf(fp, "HEIGHT = %d\n",    &d2);
   width  = (unsigned short)d1;
   height = (unsigned short)d2;
   
   fscanf(fp, "agent = %d,%d\n",  &d1, &d2);
   fscanf(fp, "target = %d,%d\n", &d1, &d2);
   fscanf(fp, "configuration");
   
   tmp = new char[width+1];
   
   if(grid != NULL) delete [] grid;
   grid = new bool[width*height];
   
   for(i = 0; i < height; ++i)
   {
      fscanf(fp, "%s\n", tmp);
      for(j = 0; j < width; ++j)
      {
         if(tmp[j] == '1')
            grid[j + i*width] = true;
         else
            grid[j + i*width] = false;
      }
   }
   
   if(tmp != NULL) delete tmp;
   if(fp  != NULL) fclose(fp);
   
   return 0;
}
