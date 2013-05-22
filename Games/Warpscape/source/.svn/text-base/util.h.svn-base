/****************************************
 filename:    util.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/14
 description: 
 ****************************************/
#ifndef _UTIL_
#define _UTIL_

void MoveToNextLine(char **str, uInt32 &size);
void RemoveStrComments(char **str, uInt32 &size);

template<class T>
T Random(T min, T max)
{
   return min + (T)((float)(max - min))*((float)rand())/((float)RAND_MAX);
}

template<class T>
T Abs(T a)
{
   if(a < 0) return (-1)*a;
   else      return a;
}

#endif // _UTIL_
