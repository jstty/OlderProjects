////////////////////////////////////////////////////////////////////////
//	Program Name:	Level##n.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Level ##n File
//	Date: 
////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <stdio.h>
#include <commctrl.h>
#include "E:\My Code\Young George VS Lost Island\YoungGeroge.h"
#include "E:\My Code\Young George VS Lost Island\resource.h"
#include "resource.h"
#include "Level02.h"

//////////////////////////////////////////////////
// 						Level_Proc Functions							//
//////////////////////////////////////////////////
			//////////////////////////////////////
			// Level_Proc##n Function
			//////////////////////////////////////
void Level_Proc2(HWNDdll hwndDll)
{
switch(global->levelState)
	{
	case 0:
		Start_L2();
		break;
	case 1:
		Mid_L2();
		break;
	}
}
			//////////////////////////////////////
			// Start_Level##n Function
			//////////////////////////////////////
void Start_L2(void)
{
	SetDlgItemText(global->MainVar.TextHwnd, IDC_TEXTBOX, "");
	if(game->var[0] == 1)
		{
		char S[MAXSTR];
		LoadString(LevelhInst, IDST_TITLE, (LPTSTR)S, sizeof(S));
		SetDlgItemText(global->MainVar.TextHwnd, IDC_TEXTBOX, (LPCTSTR)S);
		game->var[0] = 0;
		}
	global->mouse.x = 16;
	global->mouse.y = 72;
	global->mouse.m2 = 0;
	global->LevelVar.Redraw = FALSE;
	global->levelState = 1;
	if(global->MainVar.LoadFile)
		{
		level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 = game->MainChar.x;
		level->lSpriteA[game->MainChar.m1].cel = game->MainChar.m2;
		global->MainVar.LoadFile = FALSE;
		}
	else if(game->var[1] == 0){
		level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 = 20;
		game->MainChar.x = 20;
		level->lSpriteA[game->MainChar.m1].cel = 0;}
	else if(game->var[1] == 1){
		level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x1 = 600;
		game->MainChar.x = 600;
		level->lSpriteA[game->MainChar.m1].cel = 1;}
	level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].x2 = level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y1 + level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].w;
	level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y1 = 72;
	level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y2 = level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].y1 + level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].h;
	level->lSpriteA[game->MainChar.m1].yHotspot = level->lZoneA[level->lSpriteA[game->MainChar.m1].zNum].h;
	level->lSpriteA[game->MainChar.m1].xDelta = 10;
	level->lSpriteA[game->MainChar.m1].yDelta = 10;
//	origBkgHdc = CompileBitmap(global->MainVar.ChildHwnd, level);
//	DisplayBG(global->MainVar.ChildHwnd, origBkgHdc);
//	CompileSprite(global->MainVar.ChildHwnd, origBkgHdc, level);
	// Icon	
//	DisplayIcon();
}
			//////////////////////////////////////
			// Mid_Level##n Function
			//////////////////////////////////////
void Mid_L2(void)
{
	if(global->LevelVar.Redraw)
		{
//		DisplayBG(global->MainVar.ChildHwnd, origBkgHdc);
//		CompileSprite(global->MainVar.ChildHwnd, origBkgHdc, level);
//		DisplayIcon();
		global->LevelVar.Redraw = FALSE;
		}
	if(global->sound.midi.MidiStat == IDM_NULL)
		{
//		MidiProc(IDM_STOP);
		global->sound.midi.MidiStat = IDM_STOP;
		}
	else if(global->sound.midi.MidiStat == IDM_PAUSE)
		{
		if(strcmp(global->sound.midi.mf.file, IDM_LEVEL02) != 0)
			{
			global->sound.midi.mf.sec = 0;
			strcpy(global->sound.midi.mf.file, IDM_LEVEL02);
//			MidiProc(IDM_PLAY);
			global->sound.midi.MidiStat = IDM_PLAY;
			}
		}
/*if(global->sound.wav.WavStat == IDM_NULL)
		{
		WaveProc(global->sound, IDM_STOP);
		global->sound.wav.WavStat = IDM_STOP;
		}
	else if(global->sound.wav.WavStat == IDM_PAUSE)
		{
		WaveLoad(LevelhInst, global->sound);
		WaveProc(global->sound, IDM_PLAY);
		global->sound.wav.WavStat = IDM_PLAY;
		}*/
	Walk();
}
			//////////////////////////////////////
			// Level_Msg##n Function
			//////////////////////////////////////
LPSTR Level_Msg2(HWNDdll hwndDll, LPSTR tempstr, UINT id, LPSTR item1, LPSTR item2)
{
char str[MAXSTR];
strcpy(str, "");
if(id == IDTALK)
	{
	if(strcmp(item1, level->lZoneA[2].zoneName) == 0)
		{
			LoadString(LevelhInst, IDST_MOON_L2, (LPTSTR)str, sizeof(str));
			LoadString(LevelhInst, IDST_MOON_L2_1, (LPTSTR)SelectStr[0], sizeof(SelectStr[0]));
		}
	else if(strcmp(item1, level->lZoneA[1].zoneName) == 0)
			LoadString(LevelhInst, IDST_SELF_L2, (LPTSTR)str, sizeof(str));
	else
		LoadString(LevelhInst, IDST_ERROR_L2, (LPTSTR)str, sizeof(str));
	}
else
	LoadString(LevelhInst, IDST_ERROR_L2, (LPTSTR)str, sizeof(str));
strcpy(tempstr, str);
return tempstr;
}
