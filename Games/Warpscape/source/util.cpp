/****************************************
 filename:    util.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/14
 description: 
 ****************************************/
#include "global.h"

void MoveToNextLine(char **str, uInt32 &size)
{
   char *pch;

   pch    = strchr(*str, '\n');
   if(pch != NULL)
   {
      pch++; // skip past \n
      
      // fix windows diff end char problem
      while((pch[0] == '\r') || pch[0] == '\n')
      {
         pch++;
      }
      
      size  -= uInt32(pch - *str);
      (*str) = pch;
   } else {
      size = 0;
      (*str) = NULL;
   }
}

void RemoveStrComments(char **str, uInt32 &size)
{
   while( (size > 0) && ((*str) != NULL) )
   {
      if((*str)[0] == '#')
      {
         MoveToNextLine(str, size);
      } else {
         break;
      }
   }
}
