////////////////////////////////////////////////////////////////////////
//	Program Name:	MainLevels.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Main Levels File
//	Date: 
////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <stdio.h>
#include <commctrl.h>
#include <richedit.h>
#include "E:\My Code\Alien Mansion\resource.h"
#include "E:\My Code\Alien Mansion\AlienMansion.h"
#include "resource.h"
#include "MainLevels.h"

//////////////////////////////////////////////////
// 								DLL Functions									//
//////////////////////////////////////////////////
			//////////////////////////////////////
			// DllEntryPoint Function
			//////////////////////////////////////
BOOL APIENTRY DllEntryPoint(HINSTANCE hInstDLL, WORD wDataSeg, LPVOID lpReserved)
{
  return TRUE;
}
			//////////////////////////////////////
			// GameProc Function
			//////////////////////////////////////
void GameProc(HWNDdll hwndDll)
{
	if(global->LevelVar.LoadLevel)
		{
///////////////////////////////////////
		switch(game->levelNum)
			{
			case 0:
				LevelJump(1, hwndDll);
				break;
			case 1:
				LevelJump(2, hwndDll);
				break;
			case 2:
				LevelJump(3, hwndDll);
				break;
			case 3:
				LevelJump(4, hwndDll);
				break;
			}
///////////////////////////////////////
		}
	else
		{
		SetCursor(LoadCursor(NULL, IDC_WAIT));
		for(int i = 0; i < MAXARRAY; i++)
			strcpy(SelectStr[i], "");
		LevelhInst = LoadLibrary(DLLFILE);
//	load levels from data array
		if(fopen(LEVELSFILE, "r") == NULL)
			{
			HWND hwnd = GetDesktopWindow();
			global->LevelVar.LoadLevel = 2;
			char S[MAXARRAY];
			LoadString(LevelhInst, IDST_FILEERROR, (LPTSTR)S, sizeof(S));
			MessageBox(hwnd, strcat(S, LEVELSFILE), "File Error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
			PostQuitMessage(0);
			}
		else 
			{
			strcpy(global->LevelVar.ScreenItem , "");

			level = (LPLEVEL)malloc(sizeof(LEVEL));
			LPLEVELARRAY leveltemp[MAXLEVEL];
	
			for(int i = 0; i < MAXLEVEL; i++)
				leveltemp[i] = (LPLEVELARRAY)malloc(sizeof(LEVELARRAY));

			FILE *fp;
			fp = fopen(LEVELSFILE, "r");
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

			level = leveltemp[game->levelNum];
			for(i = 0; i < MAXARRAY; i++)
				global->sound.wav.file[i] = level->lWaveA[i];
			global->sound.wav.nfile = level->waveNum;
			LoadGraphics(game->levelNum);
			global->sound = LoadWaveFile(LevelhInst, global->sound);
			global->LevelVar.LoadLevel = TRUE;
			SetCursor(LoadCursor(NULL, IDC_ARROW));
			}
		}
}
			//////////////////////////////////////
			// LoadGraphics Function
			//////////////////////////////////////
void LoadGraphics(UINT levelnum)
{
switch(levelnum)
	{
	case 0:
		{
// Bitmaps
		level->lBitmapA[0].bitmap	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDB_TITLEBKG));
// Sprites
		level->lSpriteA[0].sprite	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDS_TITLEB));
		level->lSpriteA[0].spriteM	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDS_TITLEM));
		} break;
	case 1:
		{
// Path bgk
		level->bkgPath	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDB_PATH_2));
// Bitmaps
		level->lBitmapA[0].bitmap	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDB_LEVEL02));
// Sprites
		level->lSpriteA[0].sprite	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDS_GEORGEB));
		level->lSpriteA[0].spriteM	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDS_GEORGEM));
		game->MainChar.m1 = 0;
		} break;
	case 2:
		{
// Path bgk
		level->bkgPath	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDB_PATH_3));
// Bitmaps
		level->lBitmapA[0].bitmap	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDB_LEVEL03));
// Sprites
		level->lSpriteA[0].sprite	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDS_GEORGEB));
		level->lSpriteA[0].spriteM	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDS_GEORGEM));
		game->MainChar.m1 = 0;
		} break;
	case 3:
		{
// Path bgk
		level->bkgPath	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDB_PATH_4));
// Bitmaps
		level->lBitmapA[0].bitmap	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDB_LEVEL04));
// Sprites
		level->lSpriteA[0].sprite		= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDS_MBOXB));
		level->lSpriteA[0].spriteM	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDS_MBOXM));
//////////////////////////////
		level->lSpriteA[1].sprite		= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDS_GEORGEB));
		level->lSpriteA[1].spriteM	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDS_GEORGEM));
//////////////////////////////
		level->lSpriteA[2].sprite		= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDS_POSTB));
		level->lSpriteA[2].spriteM	= LoadBitmap(LevelhInst, MAKEINTRESOURCE(IDS_POSTM));
		game->MainChar.m1 = 1;
		} break;
	}
}
			//////////////////////////////////////
			// DisplayIcon Function
			//////////////////////////////////////
void DisplayIcon(void)
{
global->LevelVar.iconloop = 0;
SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_DELETEALLITEMS, (WPARAM)(0), (LPARAM)(0));
while(global->LevelVar.iconloop <= (MAXICON - 3))
{
LV_ITEM item;
if(global->LevelVar.iconloop < (MAXICON - 3))
	{
	if(game->item[global->LevelVar.iconloop] == 1)
		{
// Add item loop
	switch(global->LevelVar.iconloop)
		{
		case 0:
			item.pszText = STAKE;
			break;
		case 1:
			item.pszText = ROBOARM;
			break;
		case 2:
			item.pszText = KEY;
			break;
		case 3:
			item.pszText = VEGGY;
			break;
		case 4:
			item.pszText = CANDYBAR;
			break;
		case 5:
			item.pszText = SODA;
			break;
		case 6:
			item.pszText = SANTA;
			break;
		case 7:
			item.pszText = APP;
			break;
		case 8:
			item.pszText = STAMP;
			break;
		case 9:
			item.pszText = REMOTE;
			break;
		}

	item.mask = LVIF_IMAGE | LVIF_TEXT;
	item.iImage = global->LevelVar.iconloop;
	item.iItem = (int)SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_GETITEMCOUNT, (WPARAM)(0), (LPARAM)(0));
	item.iSubItem = 0;
	SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_INSERTITEM, (WPARAM)(0), (LPARAM)(LV_ITEM FAR *)(&item));
		// Add item loop
	}
}
else if((game->item[10] > 0) && (global->LevelVar.iconloop == (MAXICON - 3)))
	{
	if(game->item[7] != 2)
		item.pszText = ENVELOP;
	else
		item.pszText = ENVELOP_APP;
	if(game->item[10] == 1)
		{
		item.mask = LVIF_IMAGE | LVIF_TEXT;
		item.iImage = 10;
		item.iItem = (int)SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_GETITEMCOUNT, (WPARAM)(0), (LPARAM)(0));
		item.iSubItem = 0;
		SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_INSERTITEM, (WPARAM)(0), (LPARAM)(LV_ITEM FAR *)(&item));
		}
	else if(game->item[10] == 2)
		{
		item.mask = LVIF_IMAGE | LVIF_TEXT;
		item.iImage = 11;
		item.iItem = (int)SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_GETITEMCOUNT, (WPARAM)(0), (LPARAM)(0));
		item.iSubItem = 0;
		SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_INSERTITEM, (WPARAM)(0), (LPARAM)(LV_ITEM FAR *)(&item));
		}
	else if(game->item[10] == 3)
		{
		item.mask = LVIF_IMAGE | LVIF_TEXT;
		item.iImage = 12;
		item.iItem = (int)SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_GETITEMCOUNT, (WPARAM)(0), (LPARAM)(0));
		item.iSubItem = 0;
		SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_INSERTITEM, (WPARAM)(0), (LPARAM)(LV_ITEM FAR *)(&item));
		}
	else if(game->item[10] == 4)
		{
		item.mask = LVIF_IMAGE | LVIF_TEXT;
		item.iImage = 13;
		item.iItem = (int)SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_GETITEMCOUNT, (WPARAM)(0), (LPARAM)(0));
		item.iSubItem = 0;
		SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_INSERTITEM, (WPARAM)(0), (LPARAM)(LV_ITEM FAR *)(&item));
		}
		SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_ARRANGE, (WPARAM)(LVA_DEFAULT), (LPARAM)(0));
		RECT r;
		r.top	= 0, r.left	= 0, r.bottom	= 128, r.right	= 640;
		RedrawWindow(global->MainVar.ControlsHwnd, &r, NULL, RDW_ERASE |  RDW_INVALIDATE);
	}

SendDlgItemMessage(global->MainVar.ControlsHwnd, IDC_ITEMLIST, LVM_ARRANGE, (WPARAM)(LVA_DEFAULT), (LPARAM)(0));
RECT r;
r.top	= 0, r.left	= 0, r.bottom	= 128, r.right	= 640;
RedrawWindow(global->MainVar.ControlsHwnd, &r, NULL, RDW_ERASE |  RDW_INVALIDATE);
(global->LevelVar.iconloop)++;
}
}
			//////////////////////////////////////
			// Walk Function
			//////////////////////////////////////
void Walk(void)
{
	if(level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 >= 620)
		{
		game->levelNum++;
		game->var[1] = 0;
		global->levelState = 0;
		global->LevelVar.LoadLevel = FALSE;
		if(global->sound.midi.MidiStat == IDM_PLAY)
			global->sound.midi.MidiStat = IDM_PAUSE;
		if(global->sound.wav.WavStat == IDM_PLAY)
			global->sound.wav.WavStat = IDM_PAUSE;
		}
	else if((level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 <= 0) &&
					(game->levelNum >= 2))
		{
		game->levelNum--;
		game->var[1] = 1;
		global->levelState = 0;
		global->LevelVar.LoadLevel = FALSE;
		if(global->sound.midi.MidiStat == IDM_PLAY)
			global->sound.midi.MidiStat = IDM_PAUSE;
		if(global->sound.wav.WavStat == IDM_PLAY)
			global->sound.wav.WavStat = IDM_PAUSE;
		}

	if(global->mouse.m1)
		{
////////////////////////////////////////////
		if(level->lSpriteA[game->MainChar.m1].xDelta < 0)
				level->lSpriteA[game->MainChar.m1].xDelta *= (-1);
		////////////////////////////////////////////
		if( 
				(CheckPath(global->MainVar.ChildHwnd, level, game->MainChar.m1, HORZ, -1) == TRUE) &&
				((level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 + level->lSpriteA[game->MainChar.m1].xHotspot) > global->mouse.x) && 
				((level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 + level->lSpriteA[game->MainChar.m1].xHotspot - level->lSpriteA[game->MainChar.m1].xDelta) > global->mouse.x)
			)
			{
				if(level->lSpriteA[game->MainChar.m1].xDelta >= 0)
					level->lSpriteA[game->MainChar.m1].xDelta *= (-1);
				level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 += level->lSpriteA[game->MainChar.m1].xDelta;
				level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x2 = level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 + level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].w;
				level->lSpriteA[game->MainChar.m1].cel = 1;
				CompileSprite(global->MainVar.ChildHwnd, origBkgHdc, level);
			}
		else if	(
							(CheckPath(global->MainVar.ChildHwnd, level, game->MainChar.m1, HORZ, 1) == TRUE) &&
							((level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 + level->lSpriteA[game->MainChar.m1].xHotspot) < global->mouse.x) && 
							((level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 + level->lSpriteA[game->MainChar.m1].xHotspot + level->lSpriteA[game->MainChar.m1].xDelta) < global->mouse.x) 
						)
			{
			level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 += level->lSpriteA[game->MainChar.m1].xDelta;
			level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x2 = level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 + level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].w;
			level->lSpriteA[game->MainChar.m1].cel = 0;
			CompileSprite(global->MainVar.ChildHwnd, origBkgHdc, level);
			}
		else if((global->mouse.m2 == 0) || (global->mouse.m2 == 10))
			global->mouse.m2++;
////////////////////////////////////////////
		if(level->lSpriteA[game->MainChar.m1].yDelta < 0)
				level->lSpriteA[game->MainChar.m1].yDelta *= (-1);
		////////////////////////////////////////////
		if( 
				(CheckPath(global->MainVar.ChildHwnd, level, game->MainChar.m1, VERT, -1) == TRUE) &&
				((level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y1 + level->lSpriteA[game->MainChar.m1].yHotspot) > global->mouse.y) && 
				((level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y1 + level->lSpriteA[game->MainChar.m1].yHotspot - level->lSpriteA[game->MainChar.m1].yDelta) > global->mouse.y)
			)
			{
				if(level->lSpriteA[game->MainChar.m1].yDelta >= 0)
					level->lSpriteA[game->MainChar.m1].yDelta *= (-1);
				level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y1 += level->lSpriteA[game->MainChar.m1].yDelta;
				level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y2 = level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y1 + level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].h;
//				level->lSpriteA[George].cel = 1;
				CompileSprite(global->MainVar.ChildHwnd, origBkgHdc, level);
			}
		else if	(
							(CheckPath(global->MainVar.ChildHwnd, level, game->MainChar.m1, VERT, 1) == TRUE) &&
							((level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y1 + level->lSpriteA[game->MainChar.m1].yHotspot) < global->mouse.y) && 
							((level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y1 + level->lSpriteA[game->MainChar.m1].yHotspot + level->lSpriteA[game->MainChar.m1].yDelta) < global->mouse.y) 
						)
			{
			level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y1 += level->lSpriteA[game->MainChar.m1].yDelta;
			level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y2 = level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y1 + level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].h;
//			level->lSpriteA[George].cel = 0;
			CompileSprite(global->MainVar.ChildHwnd, origBkgHdc, level);
			}
		else if((global->mouse.m2 == 0) || (global->mouse.m2 == 1))
			global->mouse.m2 += 10;
////////////////////////////////////////////
	if(global->mouse.m2 == 11)
		{
		game->MainChar.x = level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1;
		game->MainChar.y = level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y1;
		game->MainChar.m2 = level->lSpriteA[game->MainChar.m1].cel;
		RectCheck();
		global->mouse.m1 = FALSE;
		global->mouse.m2 = FALSE;
		}
	}
}
			//////////////////////////////////////
			// RectCheck Function
			//////////////////////////////////////
void RectCheck(void)
{
UINT i;
POINT p;
RECT r;
p.x = global->mouse.x;
p.y =	global->mouse.y;
for(i = 1; i < level->zoneNum; i++)
	{
	r.left		= level->lZoneA[i].x1;
	r.top			= level->lZoneA[i].y1;
	r.right		= level->lZoneA[i].x2;
	r.bottom	= level->lZoneA[i].y2;
	if(PtInRect(&r, p))
		{
		strcpy(global->LevelVar.ScreenItem, level->lZoneA[i].zoneName);
		LPNMHDR pnmh;
		pnmh = (LPNMHDR)malloc(sizeof(NMHDR));
		pnmh->code = LVN_ITEMCHANGING;
		ControlBar_OnNotify(global->MainVar.ControlsHwnd, 0, pnmh);
		}
	}
}
			//////////////////////////////////////
			// MsgProc Function
			//////////////////////////////////////
void MsgProc(HWNDdll hwndDll, UINT id, LPSTR item1, LPSTR item2)
{
BOOL golevel = FALSE;
char S[MAXSTR];
strcpy(S, "");
////////////////////////////////////////////
if(id == IDEXAMINE)
	{
	if(strcmp(item1, KEY) == 0)
		LoadString(LevelhInst, IDST_E_KEY, (LPTSTR)S, sizeof(S));
	else if(strcmp(item1, SODA) == 0)
		LoadString(LevelhInst, IDST_E_SODA, (LPTSTR)S, sizeof(S));
	else if(strcmp(item1, ROBOARM) == 0)
		LoadString(LevelhInst, IDST_E_ROBOARM, (LPTSTR)S, sizeof(S));
	else if(strcmp(item1, APP) == 0)
		LoadString(LevelhInst, IDST_E_APP, (LPTSTR)S, sizeof(S));
	else if(strcmp(item1, CANDYBAR) == 0)
		LoadString(LevelhInst, IDST_E_CANDYBAR, (LPTSTR)S, sizeof(S));
	else if(strcmp(item1, REMOTE) == 0)
		LoadString(LevelhInst, IDST_E_REMOTE, (LPTSTR)S, sizeof(S));
	else if(strcmp(item1, ENVELOP) == 0)
		LoadString(LevelhInst, IDST_E_ENVELOP, (LPTSTR)S, sizeof(S));
	else if(strcmp(item1, SANTA) == 0)
		LoadString(LevelhInst, IDST_E_SANTA, (LPTSTR)S, sizeof(S));
	else if(strcmp(item1, STAKE) == 0)
		LoadString(LevelhInst, IDST_E_STAKE, (LPTSTR)S, sizeof(S));
	else if(strcmp(item1, STAMP) == 0)
		LoadString(LevelhInst, IDST_E_STAMP, (LPTSTR)S, sizeof(S));
	else if(strcmp(item1, VEGGY) == 0)
		LoadString(LevelhInst, IDST_E_VEGGY, (LPTSTR)S, sizeof(S));
	else 
		golevel = TRUE;
	}
////////////////////////////////////////////
else if(id == IDUSE)
	{
	if((strcmp(item1, ENVELOP) == 0) || (strcmp(item2, ENVELOP) == 0) ||
		 (strcmp(item1, ENVELOP_APP) == 0) || (strcmp(item2, ENVELOP_APP) == 0))
		{
		if(((strcmp(item1, APP) == 0) || (strcmp(item2, APP) == 0)) && (game->item[10] > 0))
			{
			game->item[7] = 2;
			DisplayIcon();
			}
		else if(((strcmp(item1, STAMP) == 0) || (strcmp(item2, STAMP) == 0)) && (game->item[10] > 0))
			{
			game->item[8] = 0;
			if(game->item[10] == 1)
				game->item[10] = 4;
			else if(game->item[10] == 2)
				game->item[10] = 3;
			DisplayIcon();
			}
		else
			golevel = TRUE;
		}
	else 
		golevel = TRUE;
	}
else
	golevel = TRUE;
////////////////////////////////////////////
if(golevel = TRUE)
	{
	if(game->levelNum == 1)
			strcpy(S, LevelMsg(2, hwndDll, S, id, item1, item2));
	else if(game->levelNum == 2)
			strcpy(S, LevelMsg(3, hwndDll, S, id, item1, item2));
	else if(game->levelNum == 3)
			strcpy(S, LevelMsg(4, hwndDll, S, id, item1, item2));
	}
////////////////////////////////////////////
SetDlgItemText(global->MainVar.TextHwnd, IDC_TEXTBOX, (LPCTSTR)S);
FINDTEXT ft;
CHARRANGE cr;
CHARFORMAT  lpFmt;
for(int i = 0; strcmp(SelectStr[i], "") != 0; i++)
	{
	ft.chrg.cpMin = 0;
	ft.chrg.cpMax = strlen(S);
	ft.lpstrText = SelectStr[i];
	cr.cpMin = SendDlgItemMessage(global->MainVar.TextHwnd, IDC_TEXTBOX, EM_FINDTEXT, (WPARAM)(0), (LPARAM)(FINDTEXT FAR *)(&ft));
	cr.cpMax = cr.cpMin + strlen(SelectStr[i]);
	SendDlgItemMessage(global->MainVar.TextHwnd, IDC_TEXTBOX, EM_EXSETSEL, (WPARAM)(0), (LPARAM)(CHARRANGE FAR *)(&cr));

	lpFmt.cbSize = sizeof(lpFmt);
	lpFmt.dwMask = CFM_COLOR | CFM_FACE;
	lpFmt.crTextColor = RGB(255, 0, 0);
	strcpy(lpFmt.szFaceName, "Symbol");
	SendDlgItemMessage(global->MainVar.TextHwnd, IDC_TEXTBOX, EM_SETCHARFORMAT, (WPARAM)(SCF_SELECTION ), (LPARAM)(CHARFORMAT FAR *)(&lpFmt));
//	cr.cpMin = strlen(S) - 1;
//	cr.cpMax = cr.cpMin + 1;
	cr.cpMin = 0;
	cr.cpMax = 0;
	SendDlgItemMessage(global->MainVar.TextHwnd, IDC_TEXTBOX, EM_EXSETSEL, (WPARAM)(0), (LPARAM)(CHARRANGE FAR *)(&cr));
	}
}