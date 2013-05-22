////////////////////////////////////////////////////////////////////////
//	Program Name:	Main.cpp
//	Programmer:		Joseph E. Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Main Window File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////

/*
 if you get an "error LNK2001: unresolved external symbol _main" error

copy the next line to the edit box in Project->Settings->C/C++
	/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR"Debug/" /Fo"Debug/" /Fd"Debug/" /FD /c 

copy the next line to the edit box in Project->Settings->Links
	kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"Debug/Skull.pdb" /debug /machine:I386 /out:"Debug/Skull.exe" /pdbtype:sept 
*/

//#define STRICT

//#include <windows.h>
#include <afx.h>

#include <windowsx.h>
#include <stdio.h>
#include <time.h>
#include <commctrl.h>
//
	#include "..\Resource Files\resource.h"
//
#include "..\Header Files\Main.h"
//#include "..\Header Files\SetupUtilClass.h"

#ifdef _DEBUG
	#include "..\Header Files\DebugClass.h"
	DEBUGCLASS Debug;

	extern BOOL CALLBACK DebugProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	#include "..\Header Files\TestSpeed.h"
	TestSpeed tsMain;
	TestSpeed tsDisplay;
	TestSpeed tsControls;
	TestSpeed tsAction;
	TestSpeed tsSound;
#endif

BOOL CALLBACK LoadProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

//////////////////////////////////////////////////
// 								Initialization								//
//////////////////////////////////////////////////
			//////////////////////////////////////		
			// Program entry point
			//////////////////////////////////////
int PASCAL WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
                   LPSTR  lpszCmdParam, int nCmdShow)
{
	SetLastError(0);
	srand( (unsigned int)time(NULL) );

	hVal = GlobalAlloc(GHND, sizeof(VALUES) );
	if(GetLastError() != NO_ERROR)
		return FALSE;

	Val = (VALUES*)GlobalLock(hVal);
	if(GetLastError() != 0)
		return FALSE;

	Val->LoadAll();

//
  if(hPrevInst)
    return FALSE;
  else
    if(!Val->Main->Register(hInst))
      return FALSE;

  if(!Val->Main->Create(hInst, nCmdShow))
    return FALSE;

	MSG  Msg;
  while(GetMessage(&Msg, NULL, 0, 0))
  {
     TranslateMessage(&Msg);
     DispatchMessage(&Msg);
  }

  return Msg.wParam;
}
//////////////////////////////////////////////////
// 					WndProc and Implementation					//
//////////////////////////////////////////////////
BOOL MAIN::Register(HINSTANCE hInst)
{
	Val->InitObjects();
	Closing = 0;

  WNDCLASS WndClass;

  WndClass.style          = CS_HREDRAW | CS_VREDRAW;
  WndClass.lpfnWndProc    = Main_WindowProc;
  WndClass.cbClsExtra     = 0;
  WndClass.cbWndExtra     = 0;
  WndClass.hInstance      = hInst;
  WndClass.hIcon          = LoadIcon(hInst, MAKEINTRESOURCE(IDI_MAIN));
  WndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);
  WndClass.hbrBackground  = CreateSolidBrush(RGB(32, 32, 32));
  WndClass.lpszMenuName   = NULL;
  WndClass.lpszClassName  = MAINWINDOW;
	RegisterClass (&WndClass);

	WndClass.lpfnWndProc    = Child_WindowProc;
	WndClass.cbWndExtra     = sizeof(WORD);
	WndClass.hIcon          = LoadIcon(hInst, MAKEINTRESOURCE(IDI_MAIN));
	WndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);
  WndClass.hbrBackground  = CreateSolidBrush(RGB(32, 32, 32));
  WndClass.lpszMenuName   = NULL;
  WndClass.lpszClassName  = CHILDWINDOW;
  return RegisterClass (&WndClass);
}
			//////////////////////////////////////
			// Create
			//////////////////////////////////////
HWND MAIN::Create(HINSTANCE	hInst, int Show)
{
	MainhInst =  hInst;

	Val->SetGlobal();

	xMax = Val->Display->xMax;
	yMax = Val->Display->yMax;
	
	__int16  x, y;
	unsigned __int16  w, h;
	if(data.FullScreen)
	{
		x = 0;
		y = 0;
		w = GetSystemMetrics(SM_CXSCREEN);
		h = GetSystemMetrics(SM_CYSCREEN);
	}
	else
	{
	 // Xmax/2 - (w + 2)/2
		x = ( ( GetSystemMetrics(SM_CXSCREEN) - xMax) >> 1) - (GetSystemMetrics(SM_CXFIXEDFRAME) << 2);
		y = ( ( GetSystemMetrics(SM_CYSCREEN) - yMax) >> 1) - (GetSystemMetrics(SM_CYFIXEDFRAME) << 2) - GetSystemMetrics(SM_CYCAPTION);
		w = xMax + 10;
		h = yMax + 10 + GetSystemMetrics(SM_CYCAPTION);

		if(w > GetSystemMetrics(SM_CXSCREEN))
		{
			x = 0;
			w = GetSystemMetrics(SM_CXSCREEN);
		}
		if(h > GetSystemMetrics(SM_CYSCREEN))
		{
			y = 0;
			h = GetSystemMetrics(SM_CYSCREEN);
		}

		if(x < 0)
			x = 0;
		if(y < 0)
			y = 0;

	}

	DWORD Style;
	if(!data.InWindow)
		Style = WS_POPUPWINDOW;
	else
		Style = WS_SYSMENU | WS_CAPTION |WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_VISIBLE;
		
	HWND MainHwnd = CreateWindow(MAINWINDOW, MAINWINDOW,
													Style,	x,	y,	w,	h,
													NULL, NULL, hInst, NULL);

	if(!data.InWindow)
		DeleteMenu(GetSystemMenu(MainHwnd, FALSE),  SC_MOVE, MF_BYCOMMAND);

	DeleteMenu(GetSystemMenu(MainHwnd, FALSE),  SC_SIZE, MF_BYCOMMAND);

	if (MainHwnd == NULL)
     return MainHwnd;
  

	if(!data.InWindow)
		Style = Show | SW_SHOWMAXIMIZED;
	else
		Style = Show;

  ShowWindow(MainHwnd, Style);
  UpdateWindow(MainHwnd);

  return MainHwnd;
}
			//////////////////////////////////////
			// The Window Procedure
			//////////////////////////////////////
long CALLBACK Main_WindowProc(HWND hwnd, UINT Message, 
															 WPARAM wParam, LPARAM lParam)
{
	switch(Message)
  {
		HANDLE_MSG(hwnd, WM_DESTROY		, Val->Main->Main_Destroy);
		HANDLE_MSG(hwnd, WM_PAINT  		, Val->Main->Main_Paint);
		HANDLE_MSG(hwnd, WM_CREATE 		, Val->Main->Main_Create);
		HANDLE_MSG(hwnd, WM_MOVE 			, Val->Main->Main_Move);
		HANDLE_MSG(hwnd, WM_ACTIVATE 	, Val->Main->Main_Activate);
		HANDLE_MSG(hwnd, WM_START			, Val->Main->Start);
		HANDLE_MSG(hwnd, WM_END				, ::End);

		HANDLE_MSG(hwnd, WM_KEYDOWN 	, Val->Controls->OnKey);
		HANDLE_MSG(hwnd, WM_MOUSEMOVE	, Val->Controls->OnMouse);
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
  }
}
			//////////////////////////////////////
			// WM_CREATE
			//////////////////////////////////////
BOOL MAIN::Main_Create(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct)
{
	CreateChildWindow(hwnd);
	return TRUE;
}

void MAIN::CreateChildWindow(HWND hwnd)
{
	MainHwnd = 	hwnd;
	RECT Rect;

	x = 0; y = 0;
//	unsigned int w = abs( (Rect2.right - Rect2.left) - (Rect1.right - Rect1.left) );
//	unsigned int h = abs( (Rect2.bottom - Rect2.top) - (Rect1.bottom - Rect1.top) - w);
//	MainPos + ( 1/2(MainWidth) - 1/2(ChildWidth) )
//	x = (unsigned __int16)( Rect.left + (GetSystemMetrics(SM_CXFIXEDFRAME) << 1) );
//	y =	(unsigned __int16)( Rect.top  + (GetSystemMetrics(SM_CXFIXEDFRAME) << 1) + GetSystemMetrics(SM_CYCAPTION) );

	if(data.Stretch)
	{
		if(!data.FullScreen)
		{
			w = xMax;
			h = yMax;

			GetWindowRect(MainHwnd, &Rect);
			x = (Rect.right - Rect.left - w) >> 1;
			y =	(Rect.bottom - Rect.top - h) >> 1;
		}
		else
		{
			Rect.left = 0;
			Rect.top = 0;
			Rect.right = GetSystemMetrics(SM_CXSCREEN);
			Rect.bottom = GetSystemMetrics(SM_CYSCREEN);

			w = (short)abs(Rect.right - Rect.left - 10 );
			h = (short)abs(Rect.bottom - Rect.top - 10  - GetSystemMetrics(SM_CYCAPTION));

			if( (w - xMax) > (h - yMax) )
				w = (h*xMax)/(yMax);
			else
				h = (w*yMax)/(xMax);
			
			x = (Rect.right - Rect.left - w) >> 1;
			y =	(Rect.bottom - Rect.top - h) >> 1;
		}

		if(data.InWindow)
		{
			x += (short)Rect.left;
			y += Rect.top + (GetSystemMetrics(SM_CYCAPTION) >> 1);
		}
	}
	else
	{
		w = xMax;
		h = yMax;

		Rect.left = 0;
		Rect.top = 0;
		Rect.right = GetSystemMetrics(SM_CXSCREEN);
		Rect.bottom = GetSystemMetrics(SM_CYSCREEN);

		x = (Rect.right - Rect.left - w) >> 1;
		y =	(Rect.bottom - Rect.top - h) >> 1;

		if(data.InWindow)
			y += GetSystemMetrics(SM_CYCAPTION) >> 1;
	}

	ChildRect.left = x;
	ChildRect.right = w + x;
	ChildRect.top = y;
	ChildRect.bottom = h + y;

	//WS_POPUPWINDOW
	CreateWindow(CHILDWINDOW, NULL, WS_POPUPWINDOW | WS_VISIBLE,	x, y, w, h,	MainHwnd,	NULL, MainhInst, NULL);
}
			//////////////////////////////////////
			// WM_PAINT
			//////////////////////////////////////
void MAIN::Main_Paint(HWND hwnd)
{
	PAINTSTRUCT PaintStruct;
	HDC PaintDC = BeginPaint(hwnd, &PaintStruct);
	// Insert paint stuff hear
	EndPaint(hwnd, &PaintStruct);
	//
	Val->Display->Re_Draw = RE_ALL;
}
			//////////////////////////////////////
			// WM_MOVE
			//////////////////////////////////////
void MAIN::Main_Move(HWND hwnd, int x, int y)
{
	if( (ChildHwnd != NULL) && ( !IsIconic(MainHwnd) ) )
	{
		bool zoom = IsZoomed(MainHwnd) > 0 ? 1 : 0;
		//unsigned __int16 x = 0, y = 0, w = xMax, h = yMax;
		RECT Rect;

		//if(!zoom)
		{
			if(data.Stretch)
			{
				if(!data.FullScreen)
				{
					w = xMax;
					h = yMax;

					GetWindowRect(MainHwnd, &Rect);
					x = (Rect.right - Rect.left - w) >> 1;
					y =	(Rect.bottom - Rect.top - h) >> 1;
				}
				else
				{
					Rect.left = 0;
					Rect.top = 0;
					Rect.right = GetSystemMetrics(SM_CXSCREEN);
					Rect.bottom = GetSystemMetrics(SM_CYSCREEN);

					w = (short)abs(Rect.right - Rect.left - 10 );
					h = (short)abs(Rect.bottom - Rect.top - 10  - GetSystemMetrics(SM_CYCAPTION));

					if( (w - xMax) > (h - yMax) )
						w = (h*xMax)/(yMax);
					else
						h = (w*yMax)/(xMax);
					
					x = (Rect.right - Rect.left - w) >> 1;
					y =	(Rect.bottom - Rect.top - h) >> 1;
				}

				if(data.InWindow)
				{
					x += (short)Rect.left;
					y += Rect.top + (GetSystemMetrics(SM_CYCAPTION) >> 1);
				}

				if(x < 0)
					x = 0;
				if(y < 0)
					y = 0;

				ChildRect.left = x;
				ChildRect.right = w + x;
				ChildRect.top = y;
				ChildRect.bottom = h + y;

				SetWindowPos(ChildHwnd, HWND_TOP, x, y, w, h, 0 );
			}
		}
		/*
		else
		{
			if(data.Stretch)
			{
				GetWindowRect(MainHwnd, &Rect);

				w = (short)abs(Rect.right - Rect.left - 10 );
				h = (short)abs(Rect.bottom - Rect.top - 10  - GetSystemMetrics(SM_CYCAPTION));

				if( (w - xMax) > (h - yMax) )
					w = (h*xMax)/(yMax);
				else
					h = (w*yMax)/(xMax);
				
				xPos = (Rect.right - Rect.left - w) >> 1;
				yPos =	(Rect.bottom - Rect.top - h) >> 1;

				if(data.InWindow)
				{
					xPos += (short)Rect.left;
					yPos += Rect.top + (GetSystemMetrics(SM_CYCAPTION) >> 1);
				}
			}
			else
			{
				xPos = (GetSystemMetrics(SM_CXSCREEN) - xMax) >> 1;
				yPos = ( ( GetSystemMetrics(SM_CYSCREEN) - yMax) >> 1) - GetSystemMetrics(SM_CYCAPTION);
			}

			if(xPos < 0)
				xPos = 0;
			if(yPos < 0)
				yPos = 0;

			ChildRect.left = xPos;
			ChildRect.right = w + xPos;
			ChildRect.top = yPos;
			ChildRect.bottom = h + yPos;

			SetWindowPos(ChildHwnd, HWND_TOP, xPos, yPos, w, h, 0);
		}
*/
	}
}
			//////////////////////////////////////
			// WM_ACTIVATE
			//////////////////////////////////////
void MAIN::Main_Activate(HWND hwnd, UINT state, HWND hwndActDeact, BOOL fMinimized)
{
	
}
			//////////////////////////////////////
			// The Child Window Procedure
			//////////////////////////////////////
long CALLBACK Child_WindowProc(HWND childHwnd, UINT Message, 
															 WPARAM wParam, LPARAM lParam)
{
  switch(Message)
  {
		HANDLE_MSG(childHwnd, WM_CREATE 			, Val->Main->Child_Create);
		HANDLE_MSG(childHwnd, WM_DESTROY			, Val->Main->Child_Destroy);
		HANDLE_MSG(childHwnd, WM_PAINT  			, Val->Main->Child_Paint);

		HANDLE_MSG(childHwnd, WM_KEYDOWN 			, Val->Controls->OnKey);

		HANDLE_MSG(childHwnd, WM_MOUSEMOVE		, Val->Controls->OnMouse);

		HANDLE_MSG(childHwnd, WM_LBUTTONDOWN	, Val->Controls->OnMouseLDown);
		HANDLE_MSG(childHwnd, WM_RBUTTONDOWN	, Val->Controls->OnMouseRDown);
		HANDLE_MSG(childHwnd, WM_MBUTTONDOWN	, Val->Controls->OnMouseMDown);

		HANDLE_MSG(childHwnd, WM_LBUTTONUP	, Val->Controls->OnMouseLUp);
		HANDLE_MSG(childHwnd, WM_RBUTTONUP	, Val->Controls->OnMouseRUp);
		HANDLE_MSG(childHwnd, WM_MBUTTONUP	, Val->Controls->OnMouseMUp);
		default:
			return DefWindowProc(childHwnd, Message, wParam, lParam);
  }
}
//////////////////////////////////////////////////
// 							Message Functions								//
//////////////////////////////////////////////////
BOOL MAIN::Child_Create(HWND childhwnd, CREATESTRUCT FAR* lpCreateStruct)
{
	ChildHwnd = childhwnd;
	Val->Controls->hWnd = ChildHwnd;

	DeleteMenu(GetSystemMenu(ChildHwnd, FALSE),  SC_MOVE, MF_BYCOMMAND);
	DeleteMenu(GetSystemMenu(ChildHwnd, FALSE),  SC_SIZE, MF_BYCOMMAND);

	PostMessage(MainHwnd, WM_START, 0, 0);
	return TRUE;
}
//
void MAIN::Child_Destroy(HWND hwnd)
{
	Main_Destroy(hwnd);
}
//
void MAIN::Child_Paint(HWND hwnd)
{
	PAINTSTRUCT PaintStruct;
	HDC PaintDC = BeginPaint(hwnd, &PaintStruct);
// Insert paint stuff hear
	EndPaint(hwnd, &PaintStruct);
//
	Val->Display->Re_Draw = RE_ALL;
}

///////////////////////////////////////////////////////
// Start
///////////////////////////////////////////////////////
void MAIN::Start(HWND hwnd)
{
	Val->Controls->ChildRect = ChildRect;

	if( Val->Display->Setup_Display(&ChildRect, data.UseDX) )
	{
		SetError_Format("%s:%s->Error = %s");
		Error(NULL, "MAIN", "Start", "Could not recover from error.");
		ReSetError_Format();
		PostMessage(Val->Main->Get_MainHwnd(), WM_END, 0, 0);
		return;
	}

	//NORMAL_PRIORITY_CLASS
	//THREAD_PRIORITY_NORMAL
	//REALTIME_PRIORITY_CLASS
	//THREAD_PRIORITY_HIGHEST
	SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_NORMAL);

	// Create
	if(	Val->CreateLoops() )
	{
		PostMessage(Val->Main->Get_MainHwnd(), WM_END, 0, 0);
		return;
	}

	// Start
	if(	Val->StartLoops() )
	{
		PostMessage(Val->Main->Get_MainHwnd(), WM_END, 0, 0);
		return;
	}

#ifdef _DEBUG
	InitCommonControls();
	DialogBox(MainhInst, MAKEINTRESOURCE(IDD_DEBUG), NULL, (DLGPROC)DebugProc);
#endif

}
//
// Loop
//
bool MAIN::Loop(void)
{
	LoadLevel = 0;
	Val->Game->gData.LevelNum = 0;

	HANDLE hThread = GetCurrentThread();
//	CRITICAL_SECTION cs;
//	InitializeCriticalSection(&cs);

	Val->Display->StartLayer = NULL;

	while(ThreadLoop == 0)
	{
//		EnterCriticalSection(&cs);

		if(!LoadLevel)
		{
			HCURSOR OldC = SetCursor( LoadCursor(NULL, IDC_WAIT) );
			//

			DialogBox(MainhInst, MAKEINTRESOURCE(IDD_LOADLEVEL), NULL, (DLGPROC)LoadProc);

			//
			SetCursor(OldC);
			ReSetError_Format();
			LoadLevel = true;
		}
		else
		{
			tick = GetTickCount();
			Val->Controls->Sys_Loop();
			Val->Controls->Key_Loop();
			Val->Controls->Joy_Loop();
			tick = GetTickCount() - tick;
			if(tick > 0)
				controls_rate = (float)( 1000/tick );
			else
				controls_rate = (float)(1000);

			tick = GetTickCount();
			if(LevelProc != NULL)
			{
				if( e = (* LevelProc)(Val, Val->Size))
				{
					Error(NULL, "MAIN", "LevelProc", e);
					goto END;
				}
			}
			else
			{
				Error(NULL, "MAIN", "LevelProc", e);
				goto END;
			}
			tick = GetTickCount() - tick;
			if(tick > 0)
				level_rate = (float)( 1000/tick );
			else
				level_rate = (float)(1000);

			tick = GetTickCount();
			Val->Display->DrawScreen();
			tick = GetTickCount() - tick;
			if(tick > 0)
				display_rate = (float)( 1000/tick );
			else
				display_rate = (float)(1000);

			#ifdef _DEBUG
				tsMain.Loop();
				Debug.ReFresh();
			#endif

		}

//		LeaveCriticalSection(&cs);
		if(data.Delay)
			WaitForSingleObject(hThread, data.Delay);
	}

END:

//	ThreadLoop = 2;

	Val->Display->FreeGfx();

	// test speed
	#ifdef _DEBUG
		Debug.End();
	#endif
	//

	PostMessage(MainHwnd, WM_END, 0, 0);
	return 0;
}
			//////////////////////////////////////
			// WM_DESTROY
			//////////////////////////////////////
void MAIN::Main_Destroy(HWND hwnd)
{
	if(!Closing)
	{
		Closing = 1;
		ThreadLoop = 1;
		//Val->DestroyLoops();
	}
}

void End(HWND hwnd)
{
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_NORMAL);
	SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);

	Val->FreeAll();

	GlobalUnlock(hVal);
	GlobalDiscard(hVal);

	PostQuitMessage(0);
}

///////////////////////////////////////////////////////
// Main_ThreadProc
///////////////////////////////////////////////////////
DWORD WINAPI Main_ThreadProc(LPVOID msg)
{
	return Val->Main->Loop();
}

void MAIN::Load(void)
{
	char  S[256], dir[256];
	GetCurrentDirectory(255, dir);
	sprintf(S, "%s\\levels\\level%0.3d.%s", dir, Val->Game->gData.LevelNum, FILE_EXT_LEVEL);
	//SetError_Format("%s:\n %s(%s).\n Error = %d");

		if((hLevel = LoadLibrary(S)) == NULL)
		{
			Error(NULL, "MAIN:LoadLibrary", "Could not load file", S, GetLastError() );
			ReSetError_Format();
			goto END;
		}

		if((Val->Main->LevelProc = (LEVELPROC)GetProcAddress(hLevel, "LoadDefaultVar")) != NULL )
		{
			e = (* LevelProc)(Val, Val->Size);
			if(e)
			{
				Error("%s:\n %s.\n Error = %d, %d", "MAIN:LevelProc", "Level incorrect Version", e, Val->Size);
				ReSetError_Format();
				goto END;
			}
		}
		else
		{
			Error(NULL, "MAIN:GetProcAddress", "Could not find LoadDefaultVar", S, GetLastError() );
			ReSetError_Format();
			goto END;
		}

		if((LevelProc = (LEVELPROC)GetProcAddress(hLevel, "LevelCode")) == NULL )
		{
			Error(NULL, "MAIN:GetProcAddress", "Could not find LevelCode", S, GetLastError() );
			ReSetError_Format();
			goto END;
		}

return;

END:
	Val->Display->FreeGfx();

	// test speed
	#ifdef _DEBUG
		Debug.End();
	#endif
	//

	PostMessage(MainHwnd, WM_END, 0, 0);
}