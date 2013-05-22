////////////////////////////////////////////////////////////////////////
//	Program Name:	MainWindow.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Main Window File
//	Date: 
////////////////////////////////////////////////////////////////////////

	// Included Header Files
#define STRICT
#include <windows.h>
#include <windowsx.h> 
#include <mmsystem.h>
#include <stdio.h>  
#include <string.h>
#include <commctrl.h>
#include "AlienMansion.h"
#include "resource.h"
#include "MainWindow.h"

//////////////////////////////////////////////////
// 								Initialization								//
//////////////////////////////////////////////////
			//////////////////////////////////////		
			// Program entry point
			//////////////////////////////////////
int PASCAL WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
                   LPSTR  lpszCmdParam, int nCmdShow)
{
  MSG  Msg;

  if(hPrevInst)
   { 
    return FALSE;
   }
    
  if (!hPrevInst)
    if (!Register(hInst))
      return FALSE;

  if (!Create(hInst, nCmdShow))
    return FALSE;

  while (GetMessage(&Msg, NULL, 0, 0))
  {
     TranslateMessage(&Msg);
     DispatchMessage(&Msg);
  }

  return Msg.wParam;
}
			//////////////////////////////////////
			// Register the window
			//////////////////////////////////////
BOOL Register(HINSTANCE hInst)
{
  WNDCLASS WndClass;

  WndClass.style          = CS_HREDRAW | CS_VREDRAW;
  WndClass.lpfnWndProc    = WindowProc;
  WndClass.cbClsExtra     = 0;
  WndClass.cbWndExtra     = 0;
  WndClass.hInstance      = hInst;
  WndClass.hIcon          = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON));
  WndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);
  WndClass.hbrBackground  = (HBRUSH)GetStockObject(BLACK_BRUSH);
  WndClass.lpszMenuName   = NULL;
  WndClass.lpszClassName  = MAINWINDOW;

	RegisterClass (&WndClass);

	WndClass.lpfnWndProc    = ChildWindowProc;
	WndClass.cbWndExtra     = sizeof(WORD);
	WndClass.hIcon          = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON));
	WndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);
  WndClass.hbrBackground  = (HBRUSH)CreateSolidBrush(RGB(0,0,0));
  WndClass.lpszMenuName   = NULL;
  WndClass.lpszClassName  = CHILDWINDOW;

  return RegisterClass (&WndClass);

}
			//////////////////////////////////////
			// Create the window
			//////////////////////////////////////
HWND Create(HINSTANCE hInst, int nCmdShow)
{
 	RECT Rect;
	GetWindowRect(GetDesktopWindow(), &Rect);
	long ScreenW = Rect.right, ScreenH = Rect.bottom;

	global = (LPGLOBAL)malloc(sizeof(GLOBAL));

  global->MainVar.MainhInst = hInst;
  
  global->MainVar.MainHwnd = CreateWindow(MAINWINDOW, MAINWINDOW,
                           WS_BORDER | 
                           WS_SYSMENU | 
                           WS_CAPTION |
                           WS_MINIMIZEBOX | 
                           WS_MAXIMIZEBOX ,
                           0, 0, 
                           ScreenW, ScreenH,
                           NULL, NULL, hInst, NULL);

	DeleteMenu(GetSystemMenu(global->MainVar.MainHwnd, FALSE),  SC_MOVE, MF_BYCOMMAND);
	DeleteMenu(GetSystemMenu(global->MainVar.MainHwnd, FALSE),  SC_SIZE, MF_BYCOMMAND);

  if (global->MainVar.MainHwnd == NULL)
     return global->MainVar.MainHwnd;
  
  ShowWindow(global->MainVar.MainHwnd, nCmdShow);
  UpdateWindow(global->MainVar.MainHwnd);
  return global->MainVar.MainHwnd;
}
//////////////////////////////////////////////////
// 					WndProc and Implementation					//
//////////////////////////////////////////////////
			//////////////////////////////////////
			// The Window Procedure
			//////////////////////////////////////
long FAR PASCAL WindowProc(HWND hwnd, UINT Message, 
													 WPARAM wParam, LPARAM lParam)
{
LPMSG lpMsg = (LPMSG)malloc(sizeof(MSG));
lpMsg->hwnd = hwnd;
lpMsg->message = Message;
lpMsg->wParam = wParam;
lpMsg->lParam = lParam;
  switch(Message)
  {
    HANDLE_MSG(hwnd, WM_DESTROY			, Main_OnDestroy);
    HANDLE_MSG(hwnd, WM_PAINT  			, Main_OnPaint);
		HANDLE_MSG(hwnd, WM_CREATE 			, Main_OnCreate);
		HANDLE_MSG(hwnd, WM_TIMER				, Main_Timer);
		HANDLE_MSG(hwnd, WM_START				, Main_Start);
    default:
      return DefWindowProc(hwnd, Message, wParam, lParam);
  }
}
//////////////////////////////////////////////////
// 							Message Functions								//
//////////////////////////////////////////////////
			//////////////////////////////////////
			// Handle WM_CREATE
			//////////////////////////////////////
BOOL Main_OnCreate(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct)
{
	HINSTANCE hInst = global->MainVar.MainhInst;

	TEXTMETRIC t;
	HDC hdc = GetDC(hwnd);
	GetTextMetrics(hdc, LPTEXTMETRIC(&t));
	ReleaseDC(hwnd, hdc);
	if(t.tmHeight < 20)
		ScreenSize = TRUE;
	else 
		ScreenSize = FALSE;

//	640x200 display area
	RECT Rect;
	GetWindowRect(GetDesktopWindow(), &Rect);
	int ScreenW	= (int)(Rect.right*(0.50) - XMAX*(0.50)), 
			ScreenH	= (int)(Rect.bottom*(0.50) - YMAX*(0.50));

	CreateWindow(CHILDWINDOW, NULL, 
								WS_POPUP | WS_VISIBLE, 
								ScreenW, ScreenH, 
								XMAX, YMAX, hwnd,	NULL, hInst, NULL);

	global->MainVar.SaveFile = FALSE;

	SetTimer(hwnd, IDT_MAIN, 100, NULL);

	sprintf(string, NEWFILE);

	return TRUE;
}
			//////////////////////////////////////
			// Handle WM_DESTROY
			//////////////////////////////////////
void Main_OnDestroy(HWND hwnd)
{
  PostQuitMessage(0);
}
			//////////////////////////////////////
			// Handle WM_PAINT
			//////////////////////////////////////
void Main_OnPaint(HWND hwnd)
{
PAINTSTRUCT PaintStruct;
HDC PaintDC = BeginPaint(hwnd, &PaintStruct);
// Insert paint stuff hear
EndPaint(hwnd, &PaintStruct);
if(global->LevelVar.LoadLevel)
	global->LevelVar.Redraw = TRUE;
}
			//////////////////////////////////////
			// Handles WM_TIMER messages
			//////////////////////////////////////
void Main_Timer(HWND hwnd, UINT id)
{
if(id == IDT_START1)
	{
	KillTimer(hwnd, IDT_START1);
	CreateDialog(global->MainVar.MainhInst, MAKEINTRESOURCE(IDD_CONTROLBARS + ScreenSize), global->MainVar.MainHwnd, ControlBar_DialogProc);
	}
else if(id == IDT_START2)
	{
	KillTimer(hwnd, IDT_START2);
	char S[100];
	GetSystemDirectory(S, sizeof(S));
	strcat(S, "\\RICHED32.DLL");
	LoadLibrary(S);
	CreateDialog(global->MainVar.MainhInst, MAKEINTRESOURCE(IDD_TEXTS + ScreenSize), global->MainVar.MainHwnd, Text_DialogProc);
	}

	int space = 0, i;
	char S[256];
	HDC PaintDC = GetDC(global->MainVar.MainHwnd);

//	RECT r;
//	GetWindowRect(global->MainVar.MainHwnd, &r);
//	FillRect(PaintDC, &r, (HBRUSH)GetStockObject(BLACK_BRUSH));
	//sprintf(S, "name = %s", game->name);
	sprintf(S, "name = %s", global->sound.cd.error);
		TextOut(PaintDC, 10, space, S, strlen(S));
		space += 20;
	sprintf(S, "ScreenItem = %s", global->LevelVar.ScreenItem);
		TextOut(PaintDC, 10, space, S, strlen(S));
		space += 20;
	sprintf(S, "levelNum, levelState  = %d, %d", game->levelNum, global->levelState);
		TextOut(PaintDC, 10, space, S, strlen(S));
		space += 20;
	for(i = 0; i < MAXICON; i++)
		{
			sprintf(S, "game.item[%d] = %d", i, game->item[i]);
			TextOut(PaintDC, 10, space, S, strlen(S));
			space += 20;
		}
	for(i = 0; i < MAXVAR; i++)
		{
//		sprintf(S, "TrackNumber[%d] = %d", i, global->sound.cd.TrackNumber[i]);
		sprintf(S, "game.var[%d] = %d", i, game->var[i]);
			TextOut(PaintDC, 10, space, S, strlen(S));
			space += 20;
		}
	sprintf(S, "MainChar.x, y = %d, %d", game->MainChar.x, game->MainChar.y);
		TextOut(PaintDC, 10, space, S, strlen(S));
		space += 20;
	sprintf(S, "MainChar.m1, m2 = %d, %d", game->MainChar.m1, game->MainChar.m2);
		TextOut(PaintDC, 10, space, S, strlen(S));
		space += 20;
	sprintf(S, "Mouse.x, y = %d, %d", global->mouse.x, global->mouse.y);
		TextOut(PaintDC, 10, space, S, strlen(S));
		space += 20;
	sprintf(S, "Mouse.m1, m2 = %d, %d", global->mouse.m1, global->mouse.m2);
		TextOut(PaintDC, 10, space, S, strlen(S));
		space += 20;
	sprintf(S, "LoadLevel = %d", global->LevelVar.LoadLevel);
		TextOut(PaintDC, 10, space, S, strlen(S));
		space += 20;
	sprintf(S, "Redraw = %d", global->LevelVar.Redraw);
		TextOut(PaintDC, 10, space, S, strlen(S));
		space += 20;
	sprintf(S, "iconloop = %d", global->LevelVar.iconloop);
		TextOut(PaintDC, 10, space, S, strlen(S));
		space += 20;
	sprintf(S, "LoadFile = %d", global->MainVar.LoadFile);
		TextOut(PaintDC, 10, space, S, strlen(S));
		space += 20;

		ReleaseDC(hwnd, PaintDC);

SetTimer(hwnd, IDT_MAIN, MAINTIME, NULL);
}
			//////////////////////////////////////
			// Handles WM_START messages
			//////////////////////////////////////
void Main_Start(HWND hwnd)
{
	RECT Rect;
	GetWindowRect(GetDesktopWindow(), &Rect);
	int ScreenW	= (int)(Rect.right*(0.50) - XMAX*(0.50)), 
			ScreenH	= (int)(Rect.bottom*(0.50) - YMAX*(0.50));
	int DlgH1 = 100, DlgH2 = 180;

	SetWindowPos(global->MainVar.ChildHwnd, NULL, ScreenW, ScreenH + DlgH1, XMAX, YMAX - (DlgH2 + DlgH1), NULL);
	SetTimer(global->MainVar.MainHwnd, IDT_START1, 0, NULL);
	SetTimer(global->MainVar.MainHwnd, IDT_START2, 10, NULL);
}
/*
	POINT p;
	p.x = xPos;
	p.y = yPos;
	HWND Hwnd = WindowFromPoint(p);
	SetFocus(Hwnd);
*/
