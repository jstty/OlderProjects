////////////////////////////////////////////////////////////////////////
//	Program Name:	MainVarClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Main Var Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _MAIN_VAR
#define _MAIN_VAR

#define G_XRES	320
#define G_YRES	240
#define G_BPP		16

#define D_XRES	320
#define D_YRES	240

#define D_USEDX				false
#define D_INWINDOW		false
#define D_FULLSCREEN	false
#define D_STRETCH			true

class MainVar
{
	public:
			// Delay time for loop in milli sec.
		unsigned __int16	Delay;
			// Will the delay be on time. if MainDelayRes = 0, yes. if greater than 0 maybe.
		unsigned __int16	DelayRes;

			// use DirectX
		bool UseDX;

			//In a window
		bool InWindow;

			// Maximized or not
		bool FullScreen;

			// fit to screen
		bool Stretch;
};

class GSMainVar
{
	public:
			// Delay time for loop in milli sec.
		unsigned __int16	Delay;
			// Will the delay be on time. if MainDelayRes = 0, yes. if greater than 0 maybe.
		unsigned __int16	DelayRes;
			// Music
		bool Midi;
			// Sound
		bool SndFx;
			// Display full screen.  Only in non-debug mode
		bool FullScreen;
				// Stretch to fit window
		bool Stretch;
	//
			// x Res
		unsigned __int16 Xmax;
			// y Res
		unsigned __int16 Ymax;
			// 0->63(max) Bit per pixel. 8bit = 256 colors, 16bit = 65536, 24bit = 16777216, . . . 
		unsigned int Bpp:6;
};

#endif