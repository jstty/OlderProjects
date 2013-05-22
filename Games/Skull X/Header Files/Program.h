////////////////////////////////////////////////////////////////////////
//	Program Name:	Program.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Program File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef PROGRAM
#define PROGRAM

#include <windows.h>

// Defined cases
#define WM_START			(WM_USER + 0)
#define WM_END				(WM_USER + 1)
#define DllExport			__declspec( dllexport )
#define DllImport			__declspec( dllimport )
#define HWNDdll				struct HWND__ *
#define HINST					struct HINSTANCE__ *


#define NEWFILE						"untitled"
// Main Setup Info
#define FILE_EXT_SETUP		"ini"

// Level Dll Code
#define FILE_EXT_LEVEL		"dll"

// Level Info
#define FILE_EXT_LINFO		"inf"

#define FILE_EXT_SOUND		"snd"

#define FILE_EXT_GRAPHIC	"gfx"

#define FILE_EXT_SAVE			"sav"
//

#define TRANS_COLOR1 (RGB(168, 204, 240))
#define TRANS_COLOR2 (RGB(255, 0, 255))

//NORMAL_PRIORITY_CLASS
//THREAD_PRIORITY_NORMAL
//REALTIME_PRIORITY_CLASS
//THREAD_PRIORITY_HIGHEST

#define D_DELAY	0
#define D_DRES	THREAD_PRIORITY_HIGHEST

// MAX
#define MAXSTR				65535
#define MAXARRAY			256
//
//#define TIMER_LOOP		TIME_PERIODIC
//#define TIMER_ONCE		TIME_ONESHOT
// use inline funct.
/*
inline bool GetBit(DWORD Var, DWORD type)
{
	if(~(type ^ (Var | ~type)))
		return 1;
	else
		return 0;
};
*/
// or macro
#define GETBIT(A, B) (~(B ^ (A | ~B)))
//
//#define GETBIT(A, B) ((A | (A & ~B)) & ~(A & (A & ~B)))
//
/*
inline bool CheckOnScreen(RECT r, int xMax, int yMax)
{
	if(	(r.right > 0) && (r.bottom > 0) && (r.left < xMax) && (r.top < yMax))
		return 1;

return 0;
}
*/
// or macro
#define ONSCREEN(A, B, C, D, SCREEN_W, SCREEN_H) ((A > 0) && (B > 0) && (C < SCREEN_W) && (D < SCREEN_H))

#define ONSCREEN_RECT(R, SCREEN_W, SCREEN_H) ((R.right > 0) && (R.bottom > 0) && (R.left < SCREEN_W) && (R.top < SCREEN_H))

#define IN_RECT(R1, R2) ((R1.right > R2.left) && (R1.bottom > R2.top) && (R1.left < R2.right) && (R1.top < R2.bottom))

#define POINT_IN_RECT(R, x, y) ((R.right > x) && (R.bottom > y) && (R.left < x) && (R.top < y))

//

#endif



