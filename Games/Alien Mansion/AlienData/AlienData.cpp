////////////////////////////////////////////////////////////////////////
//	Program Name:	AlienData.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Alien Data File
//	Date: 
////////////////////////////////////////////////////////////////////////

	// Included Header Files
#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <string.h>
#include "E:\My Code\Alien Mansion\AlienMansion.h"
#include "E:\My Code\Alien Mansion\AlienLevels\resource.h"
#include "AlienData.h"

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
  WndClass.hIcon          = LoadIcon(hInst, IDI_WINLOGO);
  WndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);
  WndClass.hbrBackground  = (HBRUSH)GetStockObject(BLACK_BRUSH);
  WndClass.lpszMenuName   = NULL;
  WndClass.lpszClassName  = MAINWINDOW;

  return RegisterClass (&WndClass);

}
			//////////////////////////////////////
			// Create the window
			//////////////////////////////////////
HWND Create(HINSTANCE hInst, int nCmdShow)
{
  
  HWND hwnd = CreateWindow(MAINWINDOW, MAINWINDOW,
                           WS_BORDER | 
                           WS_SYSMENU | 
                           WS_CAPTION |
                           WS_MINIMIZEBOX | 
                           WS_MAXIMIZEBOX ,
                           CW_USEDEFAULT, CW_USEDEFAULT, 
                           CW_USEDEFAULT, CW_USEDEFAULT,
                           NULL, NULL, hInst, NULL);

  if (hwnd == NULL)
     return hwnd;
  
  ShowWindow(hwnd, SW_MAXIMIZE);
  UpdateWindow(hwnd);
  return hwnd;
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
		HANDLE_MSG(hwnd, WM_LBUTTONDOWN	, Main_LMouse);
		HANDLE_MSG(hwnd, WM_RBUTTONDOWN	, Main_RMouse);
		HANDLE_MSG(hwnd, WM_KEYDOWN			, Main_Key);
    default:
      return DefWindowProc(hwnd, Message, wParam, lParam);
  }
}
			//////////////////////////////////////
			// Handles WM_CREATE messages
			//////////////////////////////////////
BOOL Main_OnCreate(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct)
{
	RECT Rect;
	GetWindowRect(GetDesktopWindow(), &Rect);
	mouseswitch = TRUE;
	Mstart = TRUE;
	n = 0;
	k = 0;
	l = 0;
	w = 0;
	b = 0;
	SetCursor(LoadCursor(NULL, IDC_WAIT));
	for(int i = 0; i < MAXLEVEL; i++)
		{
		level[i] = (LPLEVELARRAY)malloc(sizeof(LEVELARRAY));
		memset(level[i], 0L, sizeof(level[i]));
		}
	SetCursor(LoadCursor(NULL, IDC_ARROW));
	SetTimer(hwnd, IDT_MAIN, 100, NULL);
	SetWindowPos(hwnd, NULL, 0, 0, Rect.right, Rect.bottom, NULL);
	return TRUE;
}
			//////////////////////////////////////
			// Handles WM_DESTROY messages
			//////////////////////////////////////
void Main_OnDestroy(HWND hwnd)
{
  PostQuitMessage(0);
}
			//////////////////////////////////////
			// Handles WM_PAINT messages
			//////////////////////////////////////
void Main_OnPaint(HWND hwnd)
{
PAINTSTRUCT PaintStruct;
HDC PaintDC = BeginPaint(hwnd, &PaintStruct);
// Insert paint stuff hear
/*
	POINT p;
	p.x = xPos;
	p.y = yPos;
	HWND Hwnd = WindowFromPoint(p);]
	SetFocus(Hwnd);
*/
EndPaint(hwnd, &PaintStruct);
}
			//////////////////////////////////////
			// Handles WM_LBUTTONDOWN messages
			//////////////////////////////////////
void Main_LMouse(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
if(n < (CL-1))
	{
	mouseswitch = TRUE;
	n++;
	k = 0;
	l = 0;
	}
}
			//////////////////////////////////////
			// Handles WM_RBUTTONDOWN messages
			//////////////////////////////////////
void Main_RMouse(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
if(n > 0)
	{
	mouseswitch = TRUE;
	n--;
	k = 0;
	l = 0;
	}
}
			//////////////////////////////////////
			// Handles WM_KEYDOWN messages
			//////////////////////////////////////
void Main_Key(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
switch(vk)
	{
	case 'A':
		{
		if(k < (level[n]->zoneNum - 1))
			{
			mouseswitch = TRUE;
			k++;
			}
		} break;
	case 'S':
		{
		if(k > 0)
			{
			mouseswitch = TRUE;
			k--;
			}
		} break;
	case 'Z':
		{
		if(l < (level[n]->spriteNum - 1))
			{
			mouseswitch = TRUE;
			l++;
			}
		} break;
	case 'X':
		{
		if(l > 0)
			{
			mouseswitch = TRUE;
			l--;
			}
		} break;
	}
}
			//////////////////////////////////////
			// Handles WM_TIMER messages
			//////////////////////////////////////
void Main_Timer(HWND hwnd, UINT id)
{
if(Mstart == TRUE)
	{
	SaveLevels();

	SetCursor(LoadCursor(NULL, IDC_WAIT));
	for(int i = 0; i < MAXLEVEL; i++)
		{
		leveltemp[i] = (LPLEVELARRAY)malloc(sizeof(LEVELARRAY));
		}
	SetCursor(LoadCursor(NULL, IDC_ARROW));

	FILE *fp;
	char S2[MAXARRAY] = GAMEDIR;
	strcat(S2, LEVELSFILE);
	fp = fopen(S2, "r");
for(i = 0; i < CL; i++)
	{
	fread(&(leveltemp[i]->midi),			sizeof(MIDIFILE),			1, fp);
	fread(&(leveltemp[i]->waveNum),		sizeof(UINT),					1, fp);
	fread(&(leveltemp[i]->bitmapNum),	sizeof(UINT),					1, fp);
	fread(&(leveltemp[i]->spriteNum),	sizeof(UINT),					1, fp);
	fread(&(leveltemp[i]->zoneNum),		sizeof(UINT),					1, fp);
	fread(&(leveltemp[i]->lWaveA),		sizeof(UINT),					leveltemp[i]->waveNum, fp);
	fread(&(leveltemp[i]->lBitmapA),	sizeof(BITMAPARRAY),	leveltemp[i]->bitmapNum, fp);
	fread(&(leveltemp[i]->lSpriteA),	sizeof(SPRITEARRAY),	leveltemp[i]->spriteNum, fp);
	fread(&(leveltemp[i]->lZoneA),		sizeof(ZONEARRAY),		leveltemp[i]->zoneNum, fp);
	}
	fclose(fp);

	Mstart = FALSE;
	}

else if(mouseswitch)
	{
	int m = 10;
	int x = 10;
	RECT r;
	char S[MAXARRAY];
	HDC PaintDC = GetDC(hwnd);
	GetWindowRect(hwnd, &r);
	FillRect(PaintDC, &r, (HBRUSH)GetStockObject(BLACK_BRUSH));

	sprintf(S, "LevelNum = %u", n);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 30;

	sprintf(S, "level.midi.file = %s", leveltemp[n]->midi.file);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.midi.sec = %u", leveltemp[n]->midi.sec);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 30;

	sprintf(S, "level.waveNum = %u", leveltemp[n]->waveNum);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.bitmapNum = %u", leveltemp[n]->bitmapNum);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.spriteNum = %u", leveltemp[n]->spriteNum);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.zoneNum = %u", leveltemp[n]->zoneNum);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 30;
//////////////////////////////////////////////////////////////////
	sprintf(S, "WaveNum = %u", w);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lWaveA = %d", leveltemp[n]->lWaveA[w]);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 30;
//////////////////////////////////////////////////////////////////
	x = 400;
	m = 10;
	sprintf(S, "BitmapNum = %u", b);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lBitmapA.zNum = %u", leveltemp[n]->lBitmapA[b].zNum);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
if(leveltemp[n]->lZoneA[leveltemp[n]->lBitmapA[b].zNum].x1 < 65500)
	{
	sprintf(S, "level.lBitmapA.zoneName = %s", leveltemp[n]->lZoneA[leveltemp[n]->lBitmapA[b].zNum].zoneName);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	}
	sprintf(S, "level.lBitmapA.x1 = %u", leveltemp[n]->lZoneA[leveltemp[n]->lBitmapA[b].zNum].x1);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lBitmapA.y1 = %u", leveltemp[n]->lZoneA[leveltemp[n]->lBitmapA[b].zNum].y1);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lBitmapA.x2 = %u", leveltemp[n]->lZoneA[leveltemp[n]->lBitmapA[b].zNum].x2);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lBitmapA.y2 = %u", leveltemp[n]->lZoneA[leveltemp[n]->lBitmapA[b].zNum].y2);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lBitmapA.w = %u", leveltemp[n]->lZoneA[leveltemp[n]->lBitmapA[b].zNum].w);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lBitmapA.h = %u", leveltemp[n]->lZoneA[leveltemp[n]->lBitmapA[b].zNum].h);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 30;
//////////////////////////////////////////////////////////////////
	sprintf(S, "SpriteNum = %u", l);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lSpriteA.zNum = %u", leveltemp[n]->lSpriteA[l].zNum);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
if(leveltemp[n]->lZoneA[leveltemp[n]->lSpriteA[l].zNum].x1 < 65500)
	{
	sprintf(S, "level.lSpriteA.zoneName = %s", leveltemp[n]->lZoneA[leveltemp[n]->lSpriteA[l].zNum].zoneName);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	}
sprintf(S, "level.lSpriteA.x1 = %u", leveltemp[n]->lZoneA[leveltemp[n]->lSpriteA[l].zNum].x1);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lSpriteA.y1 = %u", leveltemp[n]->lZoneA[leveltemp[n]->lSpriteA[l].zNum].y1);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lSpriteA.x2 = %u", leveltemp[n]->lZoneA[leveltemp[n]->lSpriteA[l].zNum].x2);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lSpriteA.y2 = %u", leveltemp[n]->lZoneA[leveltemp[n]->lSpriteA[l].zNum].y2);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lSpriteA.w = %u", leveltemp[n]->lZoneA[leveltemp[n]->lSpriteA[l].zNum].w);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lSpriteA.h = %u", leveltemp[n]->lZoneA[leveltemp[n]->lSpriteA[l].zNum].h);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lSpriteA.zOrder = %u", leveltemp[n]->lSpriteA[l].zOrder);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lSpriteA.cel = %u", leveltemp[n]->lSpriteA[l].cel);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lSpriteA.xDelta = %u", leveltemp[n]->lSpriteA[l].xDelta);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lSpriteA.yDelta = %u", leveltemp[n]->lSpriteA[l].yDelta);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lSpriteA.xHotspot = %u", leveltemp[n]->lSpriteA[l].xHotspot);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lSpriteA.yHotspot = %u", leveltemp[n]->lSpriteA[l].yHotspot);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 30;
//////////////////////////////////////////////////////////////////
	sprintf(S, "ZoneNum = %u", k);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
if(leveltemp[n]->lZoneA[k].x1 < 65500)
	{
	sprintf(S, "level.lZoneA.zoneName = %s", leveltemp[n]->lZoneA[k].zoneName);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	}
	sprintf(S, "level.lZoneA.x1 = %u", leveltemp[n]->lZoneA[k].x1);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lZoneA.y1 = %u", leveltemp[n]->lZoneA[k].y1);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lZoneA.x2 = %u", leveltemp[n]->lZoneA[k].x2);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lZoneA.y2 = %u", leveltemp[n]->lZoneA[k].y2);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lZoneA.w = %u", leveltemp[n]->lZoneA[k].w);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 20;
	sprintf(S, "level.lZoneA.h = %u", leveltemp[n]->lZoneA[k].h);
		TextOut(PaintDC, x, m, S, strlen(S));
		m += 30;

	ReleaseDC(hwnd, PaintDC);
	mouseswitch = FALSE;
	}
SetTimer(hwnd, IDT_MAIN, 10, NULL);
}
			//////////////////////////////////////
			// Save Levels Function
			//////////////////////////////////////
void SaveLevels(void)
{
	Level1();
	Level2();
	Level3();
	Level4();
	Level5();
	Level6();
	Level7();
	Level8();

//	LevelLast();

	FILE *fp;
	char S[MAXARRAY] = GAMEDIR;
	strcat(S, LEVELSFILE);
	fp = fopen(S, "w");
for(int i = 0; i < CL; i++)
	{
	error = fwrite(&(level[i]->midi),				sizeof(MIDIFILE),	1, fp);
	if(error == 1)
		error = fwrite(&(level[i]->waveNum),	sizeof(UINT),			1, fp);
	else return;
	if(error == 1)
		error = fwrite(&(level[i]->bitmapNum),sizeof(UINT),			1, fp);
	else return;
	if(error == 1)
		error = fwrite(&(level[i]->spriteNum),sizeof(UINT),			1, fp);
	else return;
	if(error == 1)
		error = fwrite(&(level[i]->zoneNum),	sizeof(UINT),			1, fp);
	else return;
	if(error == 1)
		error = fwrite(&(level[i]->lWaveA),		sizeof(UINT),			level[i]->waveNum, fp);
	else return;
	if(error == level[i]->waveNum)
		error = fwrite(&(level[i]->lBitmapA),	sizeof(BITMAPARRAY),	level[i]->bitmapNum, fp);
	else return;
	if(error == level[i]->bitmapNum)
		error = fwrite(&(level[i]->lSpriteA),	sizeof(SPRITEARRAY),	level[i]->spriteNum, fp);
	else return;
	if(error == level[i]->spriteNum)
		error = fwrite(&(level[i]->lZoneA),		sizeof(ZONEARRAY),		level[i]->zoneNum, fp);
	else return;
	}
	fclose(fp);
}
//////////////////////////////////////////////////////////////////
void Level1(void)
{
int i = 0, j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL01);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 1;
level[i]->zoneNum								= 1;

l = 0;
level[i]->lWaveA[l]							= -1;

j = 0;
level[i]->lBitmapA[j].zNum			=	0;

j = 0;
level[i]->lSpriteA[j].zNum			=	0;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL01);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	640;
level[i]->lZoneA[k].h			=	480;
level[i]->lZoneA[k].x2		=	(UINT)(level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w);
level[i]->lZoneA[k].y2		=	(UINT)(level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h);
}
//////////////////////////////////////////////////////////////////
void Level2(void)
{
int i = 1;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL02);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 1;
level[i]->zoneNum								= 3;

l = 0;
level[i]->lWaveA[l]							= -1;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 1;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL02);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	640;
level[i]->lZoneA[k].h			=	200;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL02);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL02);
level[i]->lZoneA[k].x1		=	556;
level[i]->lZoneA[k].y1		=	17;
level[i]->lZoneA[k].w			=	32;
level[i]->lZoneA[k].h			=	33;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
//////////////////////////////////////////////////////////////////
void Level3(void)
{
int i = 2;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL03);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 1;
level[i]->zoneNum								= 4;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;
j = 0;
level[i]->lSpriteA[j].zNum			= 1;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[j].zoneName, ID_ZONE01_LEVEL03);
level[i]->lZoneA[j].x1		=	0;
level[i]->lZoneA[j].y1		=	0;
level[i]->lZoneA[j].w			=	640;
level[i]->lZoneA[j].h			=	200;
level[i]->lZoneA[j].x2		=	level[i]->lZoneA[j].x1 + level[i]->lZoneA[j].w;
level[i]->lZoneA[j].y2		=	level[i]->lZoneA[j].y1 + level[i]->lZoneA[j].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL03);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL03);
level[i]->lZoneA[k].x1		=	464;
level[i]->lZoneA[k].y1		=	17;
level[i]->lZoneA[k].w			=	32;
level[i]->lZoneA[k].h			=	33;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 3;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE04_LEVEL03);
level[i]->lZoneA[k].x1		=	204;
level[i]->lZoneA[k].y1		=	96;
level[i]->lZoneA[k].w			=	108;
level[i]->lZoneA[k].h			=	50;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
//////////////////////////////////////////////////////////////////
void Level4(void)
{
int i = 3;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL04);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 3;
level[i]->zoneNum								= 5;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 2;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 1;
level[i]->lSpriteA[j].zNum			= 1;
level[i]->lSpriteA[j].zOrder		= 1;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 2;
level[i]->lSpriteA[j].zNum			= 3;
level[i]->lSpriteA[j].zOrder		= 2;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL04);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	640;
level[i]->lZoneA[k].h			=	200;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL04);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL04);
level[i]->lZoneA[k].x1		=	336;
level[i]->lZoneA[k].y1		=	94;
level[i]->lZoneA[k].w			=	48;
level[i]->lZoneA[k].h			=	68;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 3;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE04_LEVEL04);
level[i]->lZoneA[k].x1		=	588;
level[i]->lZoneA[k].y1		=	69;
level[i]->lZoneA[k].w			=	16;
level[i]->lZoneA[k].h			=	123;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 4;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE05_LEVEL04);
level[i]->lZoneA[k].x1		=	308;
level[i]->lZoneA[k].y1		=	17;
level[i]->lZoneA[k].w			=	32;
level[i]->lZoneA[k].h			=	33;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
//////////////////////////////////////////////////////////////////
void Level5(void)
{
int i = 4;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL05);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 2;
level[i]->zoneNum								= 5;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 3;
level[i]->lSpriteA[j].zOrder		= 1;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 1;
level[i]->lSpriteA[j].zNum			= 4;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL05);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	640;
level[i]->lZoneA[k].h			=	200;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL05);
level[i]->lZoneA[k].x1		=	148;
level[i]->lZoneA[k].y1		=	17;
level[i]->lZoneA[k].w			=	32;
level[i]->lZoneA[k].h			=	33;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL05);
level[i]->lZoneA[k].x1		=	412;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	8;
level[i]->lZoneA[k].h			=	150;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 3;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE04_LEVEL05);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 4;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE05_LEVEL05);
level[i]->lZoneA[k].x1		=	156;
level[i]->lZoneA[k].y1		=	92;
level[i]->lZoneA[k].w			=	32;
level[i]->lZoneA[k].h			=	77;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
//////////////////////////////////////////////////////////////////
void Level6(void)
{
int i = 5;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL06);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 2;
level[i]->zoneNum								= 4;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 2;
level[i]->lSpriteA[j].zOrder		= 1;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 1;
level[i]->lSpriteA[j].zNum			= 3;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL06);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	640;
level[i]->lZoneA[k].h			=	200;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL06);
level[i]->lZoneA[k].x1		=	224;
level[i]->lZoneA[k].y1		=	33;
level[i]->lZoneA[k].w			=	64;
level[i]->lZoneA[k].h			=	67;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL06);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 3;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE04_LEVEL06);
level[i]->lZoneA[k].x1		=	112;
level[i]->lZoneA[k].y1		=	17;
level[i]->lZoneA[k].w			=	40;
level[i]->lZoneA[k].h			=	104;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
//////////////////////////////////////////////////////////////////
void Level7(void)
{
int i = 6;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL07);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 2;
level[i]->zoneNum								= 4;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 2;
level[i]->lSpriteA[j].zOrder		= 1;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 1;
level[i]->lSpriteA[j].zNum			= 3;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL07);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	200;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL07);
level[i]->lZoneA[k].x1		=	256;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	156;
level[i]->lZoneA[k].h			=	65;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL07);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 3;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE04_LEVEL07);
level[i]->lZoneA[k].x1		=	428;
level[i]->lZoneA[k].y1		=	17;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	28;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
//////////////////////////////////////////////////////////////////
void Level8(void)
{
int i = 7;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL08);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 3;
level[i]->zoneNum								= 6;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 3;
level[i]->lSpriteA[j].zOrder		= 2;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 1;
level[i]->lSpriteA[j].zNum			= 4;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 2;
level[i]->lSpriteA[j].zNum			= 5;
level[i]->lSpriteA[j].zOrder		= 1;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL08);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	640;
level[i]->lZoneA[k].h			=	200;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL08);
level[i]->lZoneA[k].x1		=	136;
level[i]->lZoneA[k].y1		=	56;
level[i]->lZoneA[k].w			=	40;
level[i]->lZoneA[k].h			=	40;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL08);
level[i]->lZoneA[k].x1		=	216;
level[i]->lZoneA[k].y1		=	96;
level[i]->lZoneA[k].w			=	96;
level[i]->lZoneA[k].h			=	68;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 3;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE04_LEVEL08);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 4;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE05_LEVEL08);
level[i]->lZoneA[k].x1		=	4;
level[i]->lZoneA[k].y1		=	48;
level[i]->lZoneA[k].w			=	24;
level[i]->lZoneA[k].h			=	148;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 5;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE06_LEVEL08);
level[i]->lZoneA[k].x1		=	596;
level[i]->lZoneA[k].y1		=	28;
level[i]->lZoneA[k].w			=	36;
level[i]->lZoneA[k].h			=	164;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
/*
//////////////////////////////////////////////////////////////////
void LevelLast(void)
{
int i = (CL-1);
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL00);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 1;
level[i]->zoneNum								= 2;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 1;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, "LAST BKG");
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	0;
level[i]->lZoneA[k].h			=	0;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, "LAST SPR");
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	0;
level[i]->lZoneA[k].h			=	0;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
*/
