////////////////////////////////////////////////////////////////////////
//	Program Name:	TestSpeed.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Main Window header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG

#ifndef _TESTSPEED
#define _TESTSPEED

	#include "math.h"
	#include "..\Header Files\ErrorClass.h"

	class TestSpeed : public ERRORCLASS
	{
		private:
			DWORD	Tick1;
			DWORD	Tick2;
		public:
			DWORD	LoopCount;
			int		Start;
			DWORD TickCount;
			float ForLoop;
			float Rate;
//
			TestSpeed()
			{
				Rate = 0;
				LoopCount = 0;
				Start = 1;
				TickCount = 0;
				ForLoop = 0;
				SetError_Format("%s || Time = %f, Count = %d, MainRate = %f, ForRate = %f");
			};
//
			void ShowResults(char *Name, DWORD Tick)
			{
				float f1;
				float f2;
				Tick -= TickCount;
				if(Tick > 0)
					f1 = (float)( LoopCount )/( Tick );
				else
					f1 = 0;
				f1 = f1*1000;
				f2 = (float)(Tick)/(1000);
				Error(NULL, Name, f2, LoopCount, f1, ForLoop);
			};
//
			void Loop(void)
			{
				Tick1 = GetTickCount();
				
				if(Start == 1)
				{
					Start = 0;
					TickCount = Tick1;
				}

				if( (Tick1 - TickCount) > 100)
				{
					Tick2 = Tick1 - TickCount;
					Rate = (float)( LoopCount*1000)/( Tick2 );

					LoopCount = 0;
					TickCount = Tick1;
				}


/*
				Tick1 = GetTickCount();
				for(i = 0; i < 32; i++)
				{
					temp = 10;
					temp = (int)( (temp*37 + temp*23)*(0.3) );
					temp = (int)( (temp/3) + (temp/4) + (temp/5) );
					temp = (int)sin( (temp*37 + temp*23)*(0.3) );
					temp = (int)cos( (temp*37 + temp*23)*(0.3) );
					temp = (int)tan( (temp*37 + temp*23)*(0.3) );
				}
				Tick2 = GetTickCount();
				float TempRate = (float(Tick2 - Tick1))/1000;
				ForLoop = (float(ForLoop + TempRate) )/2;
*/

/*
				div_t result;
				result = div(LoopCount, 10);
				switch(result.rem)
				{
					case 0: LoopTest++;	break;
					case 1: LoopTest++;	break;
					case 2: LoopTest++;	break;
					case 3: LoopTest++;	break;
					case 4: LoopTest++;	break;
					case 5: LoopTest++;	break;
					case 6: LoopTest++;	break;
					case 7: LoopTest++;	break;
					case 8: LoopTest++;	break;
					case 9: LoopTest++;	break;
					default: LoopTest++;
				}
							if(result.rem == 0)	LoopCount++;
				else	if(result.rem == 1) LoopCount++;
				else	if(result.rem == 2) LoopCount++;
				else	if(result.rem == 3) LoopCount++;
				else	if(result.rem == 4) LoopCount++;
				else	if(result.rem == 5) LoopCount++;
				else	if(result.rem == 6) LoopCount++;
				else	if(result.rem == 7) LoopCount++;
				else	if(result.rem == 8) LoopCount++;
				else	if(result.rem == 9) LoopCount++;
				else	LoopCount++;
*/
				LoopCount++;
			};
	};
#endif

#endif