////////////////////////////////////////////////////////////////////////
//	Program Name:	Game Setup.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Game Setup Window File
//	Date: 
////////////////////////////////////////////////////////////////////////

	// Included Header Files
#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <string.h>
#include <commctrl.h>
#include "resource.h"
#include "E:\My Code\Alien Mansion\AlienMansion.h"
#include "Game Setup.h"

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
  WndClass.hbrBackground  = (HBRUSH)GetStockObject(RGB(255,255,255));
  WndClass.lpszMenuName   = NULL;
  WndClass.lpszClassName  = MAINWINDOW;

  return RegisterClass (&WndClass);

}
			//////////////////////////////////////
			// Create the window
			//////////////////////////////////////
HWND Create(HINSTANCE hInst, int nCmdShow)
{
	MainhInst = hInst;
 	RECT Rect;
	GetWindowRect(GetDesktopWindow(), &Rect);
	long ScreenW = Rect.right, ScreenH = Rect.bottom;
 
  MainHwnd = CreateWindow(MAINWINDOW, MAINWINDOW,
                           WS_POPUP | 
                           WS_SYSMENU | 
                           WS_CAPTION |
                           WS_MINIMIZEBOX | 
                           WS_MAXIMIZEBOX ,
                           0, 0, 
                           ScreenW, ScreenW,
                           NULL, NULL, hInst, NULL);

  if (MainHwnd == NULL)
     return MainHwnd;
  
  ShowWindow(MainHwnd, nCmdShow);
  UpdateWindow(MainHwnd);
  return MainHwnd;
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
  switch(Message)
  {
    HANDLE_MSG(hwnd, WM_DESTROY			, Main_OnDestroy);
    HANDLE_MSG(hwnd, WM_PAINT  			, Main_OnPaint);
		HANDLE_MSG(hwnd, WM_CREATE 			, Main_OnCreate);
		HANDLE_MSG(hwnd, WM_TIMER				, Main_Timer);
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

	SoundSetup.MidiStat = IDM_PAUSE;
	SoundSetup.WavStat	= IDM_PAUSE;
	SoundSetup.CDGStat	= IDM_NULL;
	hAccel = NULL;

	SetTimer(hwnd, IDT_MAIN, 100, NULL);
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
}
			//////////////////////////////////////
			// Handle WM_TIMER
			//////////////////////////////////////
void Main_Timer(HWND hwnd, UINT id)
{
KillTimer(hwnd, IDT_MAIN);
DialogBox(MainhInst, MAKEINTRESOURCE(IDD_GAMESETUP), hwnd, DialogProc);
}
			//////////////////////////////////////
			// The Dialog Procedure
			//////////////////////////////////////
BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
LPMSG lpMsg = (LPMSG)malloc(sizeof(MSG));
lpMsg->hwnd			= hwndDlg;
lpMsg->message	= uMsg;
lpMsg->wParam		= wParam;
lpMsg->lParam		= lParam;
TranslateAccelerator(hwndDlg, hAccel, lpMsg);
UINT  CommandMsg = (UINT)(LOWORD(wParam));
UINT	CommandNC	 = (UINT)(HIWORD(wParam));
	if(uMsg == WM_COMMAND)
		{
			switch(CommandMsg)
			{
				case IDCANCEL:
					EndDialog(hwndDlg, NULL);
					PostQuitMessage(0);
					break;
				case IDC_DEFAULTSETUP:
					DefaultSetup();
					break;
				case IDC_LOADSETUP:
					LoadSetup();
					break;
				case IDC_SAVESETUP:
					if(SendDlgItemMessage(hwndDlg, IDC_LOADSETUP, BM_GETCHECK, (WPARAM)(0), (LPARAM)(0)) == BST_CHECKED)
						SaveStat();
					else if(SendDlgItemMessage(hwndDlg, IDC_DEFAULTSETUP, BM_GETCHECK, (WPARAM)(0), (LPARAM)(0)) == BST_CHECKED)
						SaveSetupFile(SETUPFILE);
					break;
				case IDMIDISND:
					if(SendDlgItemMessage(hwndDlg, IDMIDISND, BM_GETCHECK, (WPARAM)(0), (LPARAM)(0)) == BST_CHECKED)
						SoundSetup.MidiStat = IDM_PAUSE;
					else 
						SoundSetup.MidiStat = IDM_STOP;
					break;
				case IDWAVSND:
					if(SendDlgItemMessage(hwndDlg, IDWAVSND, BM_GETCHECK, (WPARAM)(0), (LPARAM)(0)) == BST_CHECKED)
						SoundSetup.WavStat = IDM_PAUSE;
					else 
						SoundSetup.WavStat = IDM_STOP;
					break;
				case IDCDSND:
					if(SendDlgItemMessage(hwndDlg, IDCDSND, BM_GETCHECK, (WPARAM)(0), (LPARAM)(0)) == BST_CHECKED)
						SoundSetup.CDGStat = IDM_STOP;
					else 
						SoundSetup.CDGStat = IDM_NULL;
					break;
			}
		if(CommandNC == LBN_SELCHANGE)
			LoadStat();
		return TRUE;
		}
	else if(uMsg == WM_INITDIALOG)
		{
		DlgHwnd = hwndDlg;
		hAccel = LoadAccelerators(MainhInst, MAKEINTRESOURCE(IDR_GAMESETUP));
	// Load Game List
		LoadList();
		DefaultSetup();
		return TRUE;
		}
  else
		return FALSE;
}
			//////////////////////////////////////
			// Default Setup
			//////////////////////////////////////
void DefaultSetup(void)
{
	SoundSetup = LoadSetupFile(SETUPFILE);
	if(SoundSetup.MidiStat == IDM_STOP)
		SendDlgItemMessage(DlgHwnd, IDMIDISND, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
	else
		SendDlgItemMessage(DlgHwnd, IDMIDISND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
	if(SoundSetup.WavStat == IDM_STOP)
		SendDlgItemMessage(DlgHwnd, IDWAVSND, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
	else
		SendDlgItemMessage(DlgHwnd, IDWAVSND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
	if(SoundSetup.CDGStat == IDM_NULL)
		SendDlgItemMessage(DlgHwnd, IDCDSND, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
	else
		SendDlgItemMessage(DlgHwnd, IDCDSND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));

	SendDlgItemMessage(DlgHwnd, IDC_DEFAULTSETUP, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
	SendDlgItemMessage(DlgHwnd, IDC_LOADSETUP, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));

	EnableWindow(GetDlgItem(DlgHwnd, IDC_GAMELIST), FALSE);
}
			//////////////////////////////////////
			// Load Setup
			//////////////////////////////////////
void LoadSetup(void)
{
	EnableWindow(GetDlgItem(DlgHwnd, IDC_GAMELIST), TRUE);
	SendDlgItemMessage(DlgHwnd, IDC_DEFAULTSETUP, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
	SendDlgItemMessage(DlgHwnd, IDC_LOADSETUP, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));

// Load Game List
	SendDlgItemMessage(DlgHwnd, IDC_GAMELIST, LB_SELECTSTRING, (WPARAM)(-1), (LPARAM)(LPCTSTR)(GameInfo[0].game.name)); 
	SoundSetup.MidiStat	=	GameInfo[0].game.GameSound.MidiStat;
	SoundSetup.WavStat	=	GameInfo[0].game.GameSound.WavStat;
	SoundSetup.CDGStat	=	GameInfo[0].game.GameSound.CDGStat;

	if(SoundSetup.MidiStat == IDM_STOP)
		SendDlgItemMessage(DlgHwnd, IDMIDISND, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
	else
		SendDlgItemMessage(DlgHwnd, IDMIDISND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
	if(SoundSetup.WavStat == IDM_STOP)
		SendDlgItemMessage(DlgHwnd, IDWAVSND, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
	else
		SendDlgItemMessage(DlgHwnd, IDWAVSND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
	if(SoundSetup.CDGStat == IDM_NULL)
		SendDlgItemMessage(DlgHwnd, IDCDSND, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
	else
		SendDlgItemMessage(DlgHwnd, IDCDSND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
}
			//////////////////////////////////////
			// Load ListBox
			//////////////////////////////////////
void LoadList(void)
{
	FILE *fp;
	char cPath[MAXARRAY];
	strcpy(cPath, GAMEDIR);
	if((fp = fopen(strcat(cPath, SAVEFILE), "r+")) == NULL)
		{
		NewGameFile(SAVEFILE);
		strcpy(cPath, GAMEDIR);
		fp = fopen(strcat(cPath, SAVEFILE), "r");
		}
	fread(&GameInfo, sizeof(GameInfo), 1, fp);
	fclose(fp);

	for (int j = 0; j < MAXSAVE; j++)
		{
		if(GameInfo[j].game.item[0] != (-1))
			SendDlgItemMessage(DlgHwnd, IDC_GAMELIST, LB_ADDSTRING, 0, (LPARAM)(LPCTSTR)(GameInfo[j].game.name));
		}
	SendDlgItemMessage(DlgHwnd, IDC_GAMELIST, LB_SELECTSTRING, (WPARAM)(-1), (LPARAM)(LPCTSTR)(GameInfo[0].game.name)); 
}
			//////////////////////////////////////
			// Load Stat
			//////////////////////////////////////
void LoadStat(void)
{
	FILE *fp;
	int item, i, listsize;
	char S[MAXARRAY];
	char cPath[MAXARRAY];
	strcpy(cPath, GAMEDIR);
	if((fp = fopen(strcat(cPath, SAVEFILE), "r")) == NULL)
		{
		fclose(fp);
		NewGameFile(SAVEFILE);
		}
	fread(&GameInfo, sizeof(GameInfo), 1, fp);
	fclose(fp);

	listsize = (int)SendDlgItemMessage(DlgHwnd, IDC_GAMELIST, LB_GETCOUNT, 0, 0);
	for (item = 0; item < listsize; item++)
	 	{
		if((SendDlgItemMessage(DlgHwnd, IDC_GAMELIST, LB_GETSEL, (WPARAM)(item), (LPARAM)(0))) > 0)
			{
			SendDlgItemMessage(DlgHwnd, IDC_GAMELIST, LB_GETTEXT, (WPARAM)(item), (LPARAM)(LPSTR)(S));
			for (i = 0; i < MAXSAVE; i++)
				{
				if(strcmp(S, GameInfo[i].game.name) == 0)
					{
					SoundSetup.MidiStat	=	GameInfo[i].game.GameSound.MidiStat;
					SoundSetup.WavStat	=	GameInfo[i].game.GameSound.WavStat;
					SoundSetup.CDGStat	=	GameInfo[i].game.GameSound.CDGStat;
					i = MAXSAVE;
					item = listsize;
					}
				}
			}
		}
	if(SoundSetup.MidiStat == IDM_STOP)
		SendDlgItemMessage(DlgHwnd, IDMIDISND, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
	else
		SendDlgItemMessage(DlgHwnd, IDMIDISND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
	if(SoundSetup.WavStat == IDM_STOP)
		SendDlgItemMessage(DlgHwnd, IDWAVSND, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
	else
		SendDlgItemMessage(DlgHwnd, IDWAVSND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
	if(SoundSetup.CDGStat == IDM_NULL)
		SendDlgItemMessage(DlgHwnd, IDCDSND, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
	else
		SendDlgItemMessage(DlgHwnd, IDCDSND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
}
			//////////////////////////////////////
			// Save Stat
			//////////////////////////////////////
void SaveStat(void)
{
	FILE *fp;
	int item, i, listsize;
	char S[MAXARRAY];
	char cPath[MAXARRAY];
	strcpy(cPath, GAMEDIR);
	if((fp = fopen(strcat(cPath, SAVEFILE), "r")) == NULL)
		{
		strcpy(cPath, GAMEDIR);
		fclose(fp);
		NewGameFile(SAVEFILE);
		}
	fread(&GameInfo, sizeof(GameInfo), 1, fp);
	fclose(fp);

	listsize = (int)SendDlgItemMessage(DlgHwnd, IDC_GAMELIST, LB_GETCOUNT, 0, 0);
	for (item = 0; item < listsize; item++)
	 	{
		if((SendDlgItemMessage(DlgHwnd, IDC_GAMELIST, LB_GETSEL, (WPARAM)(item), (LPARAM)(0))) > 0)
			{
			SendDlgItemMessage(DlgHwnd, IDC_GAMELIST, LB_GETTEXT, (WPARAM)(item), (LPARAM)(LPSTR)(S));
			for (i = 0; i < MAXSAVE; i++)
				{
				if(strcmp(S, GameInfo[i].game.name) == 0)
					{
					GameInfo[i].game.GameSound.MidiStat = SoundSetup.MidiStat;
					GameInfo[i].game.GameSound.WavStat = SoundSetup.WavStat;
					GameInfo[i].game.GameSound.CDGStat = SoundSetup.CDGStat;
					i = MAXSAVE;
					item = listsize;
					}
				}
			}
		}
SaveGameFile(SAVEFILE);
}
			//////////////////////////////////////
			// Save Setup File Function
			//////////////////////////////////////
void SaveSetupFile(LPSTR file)
{
	FILE *fp;
	char cPath[MAXARRAY];
	strcpy(cPath, GAMEDIR);
	if((fp = fopen(strcat(cPath, file), "w+")) == NULL)
		{
		strcpy(cPath, GAMEDIR);
		fclose(fp);
		NewSetupFile(file);
		}
	fwrite(&SoundSetup, sizeof(SoundSetup), 1, fp);
	fclose(fp);
}
			//////////////////////////////////////
			// New Setup File Function
			//////////////////////////////////////
void NewSetupFile(LPSTR file)
{
	FILE *fp;
	char cPath[MAXARRAY];
	strcpy(cPath, GAMEDIR);
	fp = fopen(strcat(cPath, file), "w+");
	strcpy(cPath, GAMEDIR);
	SoundSetup.MidiStat = IDM_PAUSE;
	SoundSetup.WavStat	= IDM_PAUSE;
	SoundSetup.CDGStat	= IDM_NULL;
	fwrite(&SoundSetup, sizeof(SoundSetup), 1, fp);
	fclose(fp);
}
