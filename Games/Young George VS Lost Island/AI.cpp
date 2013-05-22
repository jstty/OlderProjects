////////////////////////////////////////////////////////////////////////
//	Program Name:	Artificial Intelligence.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Artificial Intelligence Window File
//	Date: 
////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <time.h>
#include "E:\My Code\Young George VS Lost Island\YoungGeroge.h"
#include "AI.h"

			//////////////////////////////////////
			// Random Number Func.
			//////////////////////////////////////
int RandomNum(int iRanMax)
{
	if(iRanMax == 0)
		srand((unsigned)time(NULL));

return (int)((iRanMax+1)*((float)rand()/(float)RAND_MAX));
}
			//////////////////////////////////////
			// Random List Func.
			//////////////////////////////////////
void RandomList(int *iRanArray, int iListMax, int iRanMax)
{
int iTempArray[MAXARRAY];
for(int i = 0; i < iListMax; i++)
	iTempArray[i] = iRanArray[i];
i = 0;
if(iListMax > 1)
	{
	while(i < iListMax)
		{
		if(iRanMax == 0)
			{
			int iTempNum = RandomNum(iListMax-1);
			if(iTempArray[iTempNum] != 0)
				{
				iRanArray[i] = iTempArray[iTempNum];
				iTempArray[iTempNum] = 0;
				i++;
				}
			}
		else
			{
			iRanArray[i] = RandomNum(iRanMax) + 1;
			i++;
			}
		}
	}
}

void ArrayCopy(float *Des, float *Src, unsigned int num)
{
for(unsigned int i = 0; i < num; i++)
	{
	Des[i] = Src[i];
	}
}
