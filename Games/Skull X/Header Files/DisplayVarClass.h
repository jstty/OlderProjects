////////////////////////////////////////////////////////////////////////
//	Program Name:	DisplayVarClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Display Var Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _DISPLAY_VAR
#define _DISPLAY_VAR

class DisplayVar
{
	public:
		// Delay time for loop in milli sec.
		unsigned __int16	Delay;
			// Will the delay be on time. if MainDelayRes = 0, yes. if greater than 0 maybe.
		unsigned __int16	DelayRes;
				// x Res
		unsigned __int16 xMax;
			// y Res
		unsigned __int16 yMax;
			// 0->63(max) Bit per pixel. 8bit = 256 colors, 16bit = 65536, 24bit = 16777216, . . . 
		unsigned __int8 bpp;
};

#endif