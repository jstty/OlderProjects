////////////////////////////////////////////////////////////////////////
//	Program Name:	ChildWindow.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Child Window File
//	Date: 
////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <windowsx.h> 
#include <stdio.h>
#include "AlienMansion.h"
#include "resource.h"
#include "ChildWindow.h"

//////////////////////////////////////////////////
// 							Procedure Functions							//
//////////////////////////////////////////////////
			//////////////////////////////////////
			// The Child Window Procedure
			//////////////////////////////////////
long CALLBACK ChildWindowProc(HWNDdll childHwnd, UINT Message, 
																			 WPARAM wParam, LPARAM lParam)
{
  switch(Message)
  {
	  HANDLE_MSG(childHwnd, WM_CREATE 			, Child_OnCreate);
		HANDLE_MSG(childHwnd, WM_TIMER				, Child_Timer);
		HANDLE_MSG(childHwnd, WM_COMMAND			, Child_OnCommand);
		HANDLE_MSG(childHwnd, WM_DRAWITEM			, Child_DrawItem);
    HANDLE_MSG(childHwnd, WM_PAINT  			, Child_OnPaint);
		HANDLE_MSG(childHwnd, WM_LBUTTONDOWN	, Child_Mouse);
    default:
      return DefWindowProc(childHwnd, Message, wParam, lParam);
  }

}
//////////////////////////////////////////////////
// 							Message Functions								//
//////////////////////////////////////////////////
			//////////////////////////////////////
			// Handles Child WM_CREATE messages
			//////////////////////////////////////
BOOL Child_OnCreate(HWND childhwnd, CREATESTRUCT FAR* lpCreateStruct)
{
	RECT Rect;
	UINT i;
	GetWindowRect(GetDesktopWindow(), &Rect);

	global->MainVar.hAccControls	= NULL;
	global->MainVar.hAccOptions		= NULL;
	global->MainVar.hAccFileUtil	= NULL;

	game = (LPGAME)malloc(sizeof(GAME));
	strcpy(game->name, "");
	game->levelNum		= TITLE;
	for(i = 0; i < MAXICON; i++)
		game->item[i] = 0;
	for(i = 0; i < MAXVAR; i++)
		game->var[i] = 0;
	game->MainChar.x = 20;
	game->MainChar.y = 72;
	game->MainChar.m1 = 0;
	game->MainChar.m2 = 0;

	global->MainVar.ChildHwnd = (HWNDdll)childhwnd;
	strcpy(global->LevelVar.ScreenItem, "");
	global->levelState	= START;
	global->MidX				= (UINT)((Rect.right)	*(0.50) - XMAX*(0.50));
	global->MidY				= (UINT)((Rect.bottom)*(0.50) - YMAX*(0.50) + 100);
	global->LevelVar.LoadLevel	= FALSE;
	global->LevelVar.Redraw			= TRUE;
	global->LevelVar.iconloop		= 0;
	global->mouse.x		= 0;
	global->mouse.y		= 0;
	global->mouse.m1	= FALSE;
	global->mouse.m2	= FALSE;
	global->MainVar.LoadFile = FALSE;

	global->Default = LoadSetupFile(SETUPFILE);

	strcpy(global->sound.midi.mf.file, "");
	global->sound.midi.MidiId		= -1;
	global->sound.midi.error		= "";
	global->sound.midi.MidiStat = global->Default.MidiStat;
	global->sound.wav.WavStat		= global->Default.WavStat;
	global->sound.cd.CDGStat		= global->Default.CDGStat;
	global->sound.cd.error			= "";
	global->sound.cd.CDRStat		= IDM_NULL;
	global->sound.cd.CTrack			= 1;
	global->sound.cd.TMin				= 0;
	global->sound.cd.TSec				= 0;
	global->sound.cd.TFrm				= 0;
	global->sound.cd.TArray			= 0;
	global->sound.cd.MciError		= 0;
	RandomNum(0);
	CDProc(START);
	// Get Number of CD Tracks
	if(global->Default.CDGStat == IDM_STOP)
		{
		for(i = 0; i < global->sound.cd.nTrack; i++)
			global->sound.cd.TrackNumber[i] = i+1;
		CDProc(IDM_STOP);
		}
	// STOP CD
	
	LoadButton	= FALSE;
	NewButton		= FALSE;
	ExitButton	= FALSE;

	BitmapLoad1	= LoadBitmap(global->MainVar.MainhInst, MAKEINTRESOURCE(IDB_LOAD1));
	BitmapLoad2	= LoadBitmap(global->MainVar.MainhInst, MAKEINTRESOURCE(IDB_LOAD2));
	BitmapNew1	= LoadBitmap(global->MainVar.MainhInst, MAKEINTRESOURCE(IDB_NEW1));
	BitmapNew2	= LoadBitmap(global->MainVar.MainhInst, MAKEINTRESOURCE(IDB_NEW2));
	BitmapExit1	= LoadBitmap(global->MainVar.MainhInst, MAKEINTRESOURCE(IDB_EXIT1));
	BitmapExit2	= LoadBitmap(global->MainVar.MainhInst, MAKEINTRESOURCE(IDB_EXIT2));

//	ButtonUpdate();
	SetTimer(childhwnd, IDT_CHILD, CHILDTIME, NULL);
	return TRUE;
}
			//////////////////////////////////////
			// Handles Child WM_COMMAND messages
			//////////////////////////////////////
void Child_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
switch(id)
	{
	case ID_LOADBUTTON:
		{
			if(LoadButton == TRUE)
			{
				global->MainVar.SaveFile = FALSE;
				DialogBox(global->MainVar.MainhInst, MAKEINTRESOURCE(IDD_LOADFILE), hwnd, (DLGPROC)Loadfile_DialogProc);
				SetFocus(hwnd);
				LoadButton = FALSE;
				if(global->MainVar.LoadFile)
					{
					global->LevelVar.LoadLevel = FALSE;
					global->LevelVar.iconloop = -1;
					global->LevelVar.Redraw = TRUE;
					PostMessage(global->MainVar.MainHwnd, WM_START, 0, 0);
					}
			}
		}	break;
	case ID_NEWBUTTON:
		{
		if(NewButton == TRUE)
			{
			strcpy(game->name, NEWFILE);
			game->levelNum = 1;
			global->levelState = 0;
			game->var[0] = 1;
			global->LevelVar.Redraw = TRUE;
			global->LevelVar.LoadLevel = FALSE;
			if(global->sound.midi.MidiStat == IDM_PLAY)
				global->sound.midi.MidiStat = IDM_PAUSE;
			if(global->sound.wav.WavStat == IDM_PLAY)
				global->sound.wav.WavStat = IDM_PAUSE;
			PostMessage(global->MainVar.MainHwnd, WM_START, 0, 0);
			}
		}	break;
	case ID_EXITBUTTON:
		{
		if(ExitButton == TRUE)
			{
			PostQuitMessage(0);
			}
		}	break;
	}
}
			//////////////////////////////////////
			// Handles Child WM_DRAWITEM messages
			//////////////////////////////////////
void Child_DrawItem(HWND hwnd, const DRAWITEMSTRUCT *lpdis)
{
	switch(lpdis->CtlID)
	{
		case ID_LOADBUTTON:
		{
			HDC hdcMem = CreateCompatibleDC(lpdis->hDC); 
			if(lpdis->itemState == 17)
				{
				SelectObject(hdcMem, BitmapLoad2);
				LoadButton = TRUE;
				}
			else if(lpdis->itemState == 16)
				SelectObject(hdcMem, BitmapLoad1);
			else
				SelectObject(hdcMem, BitmapLoad1);

			StretchBlt( lpdis->hDC, lpdis->rcItem.left,	lpdis->rcItem.top,
									lpdis->rcItem.right - lpdis->rcItem.left, 
									lpdis->rcItem.bottom - lpdis->rcItem.top,
									hdcMem, 0, 0, 135, 63, SRCCOPY);
			
			DeleteDC(hdcMem);
		}	break;
	case ID_NEWBUTTON:
		{
			HDC hdcMem = CreateCompatibleDC(lpdis->hDC); 
			if(lpdis->itemState == 17)
				{
				SelectObject(hdcMem, BitmapNew2);
				NewButton = TRUE;
				}
			else if(lpdis->itemState == 16)
				SelectObject(hdcMem, BitmapNew1);
			else
				SelectObject(hdcMem, BitmapNew1);

			StretchBlt( lpdis->hDC, lpdis->rcItem.left,	lpdis->rcItem.top,
									lpdis->rcItem.right - lpdis->rcItem.left, 
									lpdis->rcItem.bottom - lpdis->rcItem.top,
									hdcMem, 0, 0, 135, 63, SRCCOPY);
			
			DeleteDC(hdcMem);
		}	break;
	case ID_EXITBUTTON:
		{
			HDC hdcMem = CreateCompatibleDC(lpdis->hDC); 
			if(lpdis->itemState == 17)
				{
				SelectObject(hdcMem, BitmapExit2);
				ExitButton = TRUE;
				}
			else if(lpdis->itemState == 16)
				SelectObject(hdcMem, BitmapExit1);
			else
				SelectObject(hdcMem, BitmapExit1);

			StretchBlt( lpdis->hDC, lpdis->rcItem.left,	lpdis->rcItem.top,
									lpdis->rcItem.right - lpdis->rcItem.left, 
									lpdis->rcItem.bottom - lpdis->rcItem.top,
									hdcMem, 0, 0, 135, 63, SRCCOPY);
			
			DeleteDC(hdcMem);
		}	break;
	}
}
			//////////////////////////////////////
			// Handles Child WM_PAINT messages
			//////////////////////////////////////
void Child_OnPaint(HWND hwnd)
{
PAINTSTRUCT PaintStruct;
HDC PaintDC = BeginPaint(hwnd, &PaintStruct);
// Insert paint stuff hear
EndPaint(hwnd, &PaintStruct);
}
			//////////////////////////////////////
			// Handles Child WM_LBUTTONDOWN messages
			//////////////////////////////////////
void Child_Mouse(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
global->mouse.x = x;
global->mouse.y = y;
global->mouse.m1 = TRUE;
}
			//////////////////////////////////////
			// Handles Child WM_TIMER messages
			//////////////////////////////////////
void Child_Timer(HWND hwnd, UINT id)
{
GameProc((HWNDdll)hwnd);
SetTimer(hwnd, IDT_CHILD, CHILDTIME, NULL);
}
			//////////////////////////////////////
			//  Button Update Function
			//////////////////////////////////////
void ButtonUpdate(void)
{
int ScreenW = (int)(XMAX*(0.50)) - 250,
		ScreenH = (int)(XMAX*(0.50)) + 85;

CreateWindow("button", "LOAD",
             WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
             ScreenW, ScreenH, 135, 63, global->MainVar.ChildHwnd, (HMENU)ID_LOADBUTTON,
             global->MainVar.MainhInst, NULL);
CreateWindow("button", "NEW",
		         WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
		         ScreenW + 183, ScreenH, 135, 63, global->MainVar.ChildHwnd, (HMENU)ID_NEWBUTTON,
             global->MainVar.MainhInst, NULL);
CreateWindow("button", "EXIT",
             WS_CHILD | WS_VISIBLE | BS_OWNERDRAW,
             ScreenW + 366, ScreenH, 135, 63, global->MainVar.ChildHwnd, (HMENU)ID_EXITBUTTON,
             global->MainVar.MainhInst, NULL);
}
