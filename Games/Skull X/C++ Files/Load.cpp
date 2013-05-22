////////////////////////////////////////////////////////////////////////
//	Program Name:	Load.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Debug Window File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////

#include <windows.h>
//#include <windowsx.h>
#include <commctrl.h>
	#include "..\Resource Files\resource.h"
#include "..\Header Files\ValuesClass.h"
extern VALUES	*Val;

HWND MainHwnd;
HWND Prog;

HANDLE				Load_hThread;
DWORD WINAPI	Load_ThreadProc(LPVOID msg);

//////////////////////////////////////
// The Load Procedure
//////////////////////////////////////
BOOL CALLBACK LoadProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if(msg == WM_INITDIALOG)
	{
		RECT Rect1, Rect2;
		int xMax, yMax;

		GetWindowRect(hwnd, &Rect1);
		GetClientRect(Val->Main->Get_MainHwnd(), &Rect2);
		xMax = ( ( Rect2.right + Rect2.left - Rect1.right + Rect1.left ) >> 1) ;
		//
		yMax = ( ( Rect2.bottom + Rect2.top - Rect1.bottom + Rect1.top ) >> 1);

		if(xMax < 0)
			xMax = 0;
		if(yMax < 0)
			yMax = 0;

		SetWindowPos(hwnd, HWND_TOPMOST, xMax, yMax, 0, 0, SWP_NOSIZE);

		Prog = GetDlgItem(hwnd, IDC_PROG);
		MainHwnd = hwnd;

		if( Val->cLoop(Load_hThread, Load_ThreadProc, "LOAD", THREAD_PRIORITY_NORMAL) )
				return 1;

		if( Val->sLoop(Load_hThread, "LOAD") )
				return 1;

		return 1;
	}
	else if((msg == WM_COMMAND) || (msg == WM_DESTROY))
	{
		if((UINT)LOWORD(wParam) == IDCANCEL )
			DestroyWindow(hwnd);

		return 1;
	}

	return 0;
}

HANDLE hThread;
//
DWORD WINAPI Load_ThreadProc(LPVOID msg)
{	
	hThread = GetCurrentThread();

	{
		SendMessage(Prog, PBM_SETRANGE, 0, MAKELPARAM(0, 500)); 
		SendMessage(Prog, PBM_SETSTEP, (WPARAM) 100, 0); 

		Val->Display->FreeLayers();
		SendMessage(Prog, PBM_STEPIT, 0, 0);

		Val->Display->Load();
		SendMessage(Prog, PBM_STEPIT, 0, 0);

		Val->Action->Load();
		SendMessage(Prog, PBM_STEPIT, 0, 0);

		Val->Sound->Load();
		SendMessage(Prog, PBM_STEPIT, 0, 0);

		Val->Main->Load();
		SendMessage(Prog, PBM_STEPIT, 0, 0);
	}

	WaitForSingleObject(hThread, 500);

	PostMessage(MainHwnd, WM_COMMAND, IDCANCEL, 0);
	return 0;
}
