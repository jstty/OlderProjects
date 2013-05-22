////////////////////////////////////////////////////////////////////////
//  Program Name: Kung Fu Willy.cpp
//  Programmer: Joseph Sutton
//  Description: Kung Fu Willy File
//  Date: 6/20/97
////////////////////////////////////////////////////////////////////////

	// Included Header Files
#include <windows.h>
#include <windowsx.h> 
#include <mmsystem.h>
#include <string.h>
#include <stdio.h>  
#include <math.h>
#include <Game.h>
#include "Kung Fu Willy.h" 
#include "Resource.h"
#include "levels~1\\Sound.h"
#include "levels~1\\Graphics.h"
#include "Controls.h"
#include "Levels.h"
 
			//////////////////////////////////////
			// Program entry point
			//////////////////////////////////////
int PASCAL WinMain(HINSTANCE hInst, HINSTANCE hPrevInst,
                   LPSTR  lpszCmdParam, int nCmdShow)
{
  MSG  Msg;
	LPSECURITY_ATTRIBUTES LPS_A = NULL;

	CreateMutex(LPS_A, TRUE, WinName);
	if(GetLastError())
   { 
    Error_Message(MAINWIN, NULL);
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

  WndClass.style          = CS_HREDRAW | CS_VREDRAW | CS_BYTEALIGNCLIENT;
  WndClass.lpfnWndProc    = WindowProc;
  WndClass.cbClsExtra     = 0;
  WndClass.cbWndExtra     = 0;
  WndClass.hInstance      = hInst;
  WndClass.hIcon          = LoadIcon(hInst, MAKEINTRESOURCE(IDI_KFW));
  WndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);
  WndClass.hbrBackground  = GetStockBrush(BLACK_BRUSH);
  WndClass.lpszMenuName   = NULL;
  WndClass.lpszClassName  = WinName;
  
  return RegisterClass (&WndClass);
}
			//////////////////////////////////////
			// Create the window
			//////////////////////////////////////
HWND Create(HINSTANCE hInst, int nCmdShow)
{
  MainHInst = hInst;

	MidScreen();
  HWND hwnd = CreateWindow(WinName, WinName,
								WS_POPUP | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX 
								, 0, 0, ScreenW, ScreenH, NULL, NULL, hInst, NULL);

  if (hwnd == NULL)
     return hwnd;

	ShowWindow(hwnd, SW_MAXIMIZE);
  UpdateWindow(hwnd);
  
  return hwnd;
}
			//////////////////////////////////////
			// The Window Procedure
			//////////////////////////////////////
long FAR PASCAL WindowProc(HWND hwnd, UINT Message,
                                 WPARAM wParam, LPARAM lParam)
{
  switch(Message)
  {
    HANDLE_MSG(hwnd, WM_CREATE 			, Main_Create);
    HANDLE_MSG(hwnd, WM_DESTROY			, Main_Destroy);
		HANDLE_MSG(hwnd, WM_COMMAND			, Main_Command);
    HANDLE_MSG(hwnd, WM_PAINT  			, Main_Paint);
    HANDLE_MSG(hwnd, WM_MOVE  			, Main_Move);
		HANDLE_MSG(hwnd, MM_MCINOTIFY		, Main_MciNotify);
		HANDLE_MSG(hwnd, MM_JOY1MOVE		, Main_Joy1);
		HANDLE_MSG(hwnd, MM_JOY1BUTTONDOWN		, Main_Joy1);
		HANDLE_MSG(hwnd, MM_JOY2MOVE		, Main_Joy2);
		HANDLE_MSG(hwnd, MM_JOY2BUTTONDOWN		, Main_Joy2);
		HANDLE_MSG(hwnd, WM_KEYDOWN			, Main_Key);
//		HANDLE_MSG(hwnd, WM_TIMER  			, Main_Timer);
		default:
      return Main_DefProc(hwnd, Message, wParam, lParam);
  }
} 
			//////////////////////////////////////
			// Handle WM_CREATE
			//////////////////////////////////////
BOOL Main_Create(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct)
{
	fight = TRUE;
	joySetCapture(hwnd, JOYSTICKID1, TimeRate, FALSE);
	Reset((HWNDdll)hwnd);
	ButtonUpdate((HWNDdll)hwnd, (HINST)hInst);
	return TRUE;
}
			//////////////////////////////////////
			// Handle WM_DESTROY
			//////////////////////////////////////
void Main_Destroy(HWND hwnd)
{ 
	Quit((HWNDdll)hwnd);
}
			//////////////////////////////////////
			// Handles WM_MOVE messages
			//////////////////////////////////////
void Main_Move(HWND hwnd, int x, int y)
{
	BOOL Min;
	Min = IsIconic(hwnd);
	
	if(!Min)
		{                                                  
			SetWindowPos(hwnd, NULL, 0, 0, ScreenW, ScreenH, NULL);    
		}     
}
			//////////////////////////////////////
			// Handle WM_PAINT
			//////////////////////////////////////

void Main_Paint(HWND hwnd)
{	  	
PAINTSTRUCT PaintStruct;
HDC PaintDC = BeginPaint(hwnd, &PaintStruct);
// Insert paint stuff hear
EndPaint(hwnd, &PaintStruct);
DisplayBG((HWNDdll)hwnd);
} 
			//////////////////////////////////////
			// Handle WM_TIMER
			//////////////////////////////////////
void CALLBACK TimerProc( HWNDdll hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
switch(idEvent)	{
	case ID_TIMER:	{
		gtimer = FALSE;
		Level(hwnd, hInst);
// DeBugging Text
/*
char S[100];
		HDC PaintDC = GetDC(hwnd); 
			sprintf(S, "l.number = %u", l.number);
		TextOut(PaintDC, 10, 10, S, strlen(S));
			sprintf(S, "l.stat   = %u", l.stat);
		TextOut(PaintDC, 10, 30, S, strlen(S));
			sprintf(S, "c.player = %u", c.player);
		TextOut(PaintDC, 10, 50, S, strlen(S));
			sprintf(S, "c.JD     = %u", c.JD);
		TextOut(PaintDC, 10, 70, S, strlen(S));
			sprintf(S, "c.JB     = %u", c.JB);
		TextOut(PaintDC, 10, 90, S, strlen(S));
			sprintf(S, "MidX     = %u", MidX);
		TextOut(PaintDC, 10, 110, S, strlen(S));
			sprintf(S, "MidY     = %u", MidY);
		TextOut(PaintDC, 10, 130, S, strlen(S));
			sprintf(S, "fight    = %u", fight);
		TextOut(PaintDC, 10, 150, S, strlen(S));
			sprintf(S, "EnergyP1 = %d", EnergyP1);
		TextOut(PaintDC, 10, 170, S, strlen(S));
  		sprintf(S, "EnergyP2 = %d", EnergyP2);
		TextOut(PaintDC, 10, 190, S, strlen(S));
			sprintf(S, "MTimeRate = %d", MTimeRate);
		TextOut(PaintDC, 10, 210, S, strlen(S));
		ReleaseDC(hwnd, PaintDC);
*/
// DeBugging Text
		SetTimer(hwnd, ID_TIMER, TimeRate, (TIMERPROC)TimerProc);
		}	break;

	case ID_GTIMER:	
		{
		if((l.stat == MID || l.stat == END) && l.number != TITLE)
			{
			gtimer = TRUE;
			Level(hwnd, hInst);
			}
		}	break;

	case ID_MTIMER:
		{
		MIDI(PLAY, (HWNDdll)hwnd);
		}	break;
	}
}                                                                        
			//////////////////////////////////////
			// Error Message Function
			//////////////////////////////////////
void Error_Message(UINT Type, LPTSTR Message)
{
	switch(Type)
		{
			case MAINWIN:
		 		MessageBox(0, WinName" caused a general protection fault in module "WinName".EXE at 0001:000002ad."
				, WinName, MB_OK | MB_ICONEXCLAMATION);
				break;
			case GRAPH:
				MessageBox(0, Message, "Graphics Error", MB_OK | MB_ICONEXCLAMATION);
				break;

			case SOUND:
				MessageBox(0, Message, "Sound Error", MB_OK | MB_ICONEXCLAMATION);
				break;
		}
}
////////////////////////////////////////////////////////////////////////
//  Level Main Function
////////////////////////////////////////////////////////////////////////
void Level(HWND hwnd, HINSTANCE hInst)
{
	if(l.number == TITLE)
		{
			if(l.stat == START)
				TitleStart((HWNDdll)hwnd, (HINST)hInst);
			if(l.stat == MID)
				TitleMid((HWNDdll)hwnd, (HINST)hInst);
		}
	if(l.number == P1_VS_P2)
		{
			if(l.stat == START)
				PvsPStart((HWNDdll)hwnd, (HINST)hInst);
			if(l.stat == MID)
				PvsPMid((HWNDdll)hwnd, (HINST)hInst);
			if(l.stat == END)
				PvsPEnd((HWNDdll)hwnd, (HINST)hInst);
		}
	if(l.number == P1_VS_COM)
		{
			if(l.stat == START)
				PvsCStart((HWNDdll)hwnd, (HINST)hInst);
			if(l.stat == MID)
				PvsCMid((HWNDdll)hwnd, (HINST)hInst);
			if(l.stat == END)
				PvsCEnd((HWNDdll)hwnd, (HINST)hInst);
		}
}
			//////////////////////////////////////
			// Handles WM_COMMAND messages
			//////////////////////////////////////
void Main_Command(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch(id)
		{
			case ID_MINBUTTON:	{
				ShowWindow(hwnd, SW_MINIMIZE);
				}	break;
			case ID_P1BUTTON:	{
				l.number = P1_VS_COM;
				TitleEnd((HWNDdll)hwnd, (HINST)hInst);
				}	break;
			case ID_P2BUTTON:	{
				l.number = P1_VS_P2;
				TitleEnd((HWNDdll)hwnd, (HINST)hInst);
				}	break;
			case ID_CLOSEBUTTON:	{
				Main_Destroy(hwnd);
				}	break;
		}
}
