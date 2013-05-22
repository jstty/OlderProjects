////////////////////////////////////////////////////////////////////////
//	Program Name:	Main.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Main Window header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////

// Defined cases
#define MAINWINDOW		"Main Window"
#define CHILDWINDOW		"Child Window"
#define Main_DefProc	DefWindowProc

#include "..\Header Files\ValuesClass.h"
VALUES	*Val;
HGLOBAL	hVal;

	// Misc. Functions
long CALLBACK Main_WindowProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
long CALLBACK Child_WindowProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);

void End(HWND hwnd);

// Handle WM_## message
/* void On##(HWND hwnd) */
//
#define	HANDLE_WM_START(hwnd, wParam, lParam, fn) \
												((fn)(hwnd), 0L)
#define FORWARD_WM_START(hwnd, fn) \
												(void)(fn)((hwnd), WM_LOOP, 0L, 0L)

#define	HANDLE_WM_END(hwnd, wParam, lParam, fn) \
												((fn)(hwnd), 0L)
#define FORWARD_WM_END(hwnd, fn) \
												(void)(fn)((hwnd), WM_LOOP, 0L, 0L)
