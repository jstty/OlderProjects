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
#include "resource.h"
#include "E:\My Code\Alien Mansion\AlienMansion.h"
#include "Level01.h"

//////////////////////////////////////////////////
// 						Level_Proc Functions							//
//////////////////////////////////////////////////
			//////////////////////////////////////
			// Level_Proc##n Function
			//////////////////////////////////////
void Level_Proc1(HWNDdll hwndDll)
{
switch(global->levelState)
	{
	case 0:
		Start_L1();
		break;
	case 1:
		Mid_L1();
		break;
	}
}
			//////////////////////////////////////
			// Start_Level##n Function
			//////////////////////////////////////
void Start_L1(void)
{
	origBkgHdc = CompileBitmap(global->MainVar.ChildHwnd, level);
	DisplayBG(global->MainVar.ChildHwnd, origBkgHdc);
	CompileSprite(global->MainVar.ChildHwnd, origBkgHdc, level);
	ButtonUpdate();
	global->LevelVar.Redraw = FALSE;
	global->levelState = 1;
}
			//////////////////////////////////////
			// Mid_Level##n Function
			//////////////////////////////////////
void Mid_L1(void)
{
	if(global->LevelVar.Redraw)
		{
		DisplayBG(global->MainVar.ChildHwnd, origBkgHdc);
		CompileSprite(global->MainVar.ChildHwnd, origBkgHdc, level);
		ButtonUpdate();
		global->LevelVar.Redraw = FALSE;
		}
	if(global->sound.midi.MidiStat == IDM_NULL)
		{
		MidiProc(IDM_STOP);
		global->sound.midi.MidiStat = IDM_STOP;
		}
	else if(global->sound.midi.MidiStat == IDM_PAUSE)
		{
		global->sound.midi.mf.sec = 14;
		strcpy(global->sound.midi.mf.file, IDM_LEVEL01);
		MidiProc(IDM_PLAY);
		global->sound.midi.MidiStat = IDM_PLAY;
		}
	if(global->sound.wav.WavStat == IDM_NULL)
		{
//		WaveProc(0, IDM_STOP, NULL);
		global->sound.wav.WavStat = IDM_STOP;
		}
	else if(global->sound.wav.WavStat == IDM_PAUSE)
		{
//		WaveProc(0, IDM_PLAY, NULL);
		global->sound.wav.WavStat = IDM_PLAY;
		}
}
