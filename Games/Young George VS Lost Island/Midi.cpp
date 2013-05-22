////////////////////////////////////////////////////////////////////////
//	Program Name:	Midi.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Midi File
//	Date: 10/26/97
////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <stdio.h>
#include <string.h>            
#include <mmsystem.h>
#include "E:\My Code\Young George VS Lost Island\YoungGeroge.h"
#include "Midi.h"

			//////////////////////////////////////
			// Midi Function
			//////////////////////////////////////
void MidiProc(UINT msg)
{
	MCIERROR MciError = 0;
	switch(msg)
		{
		case IDM_PLAY:
			{
			if(global->sound.midi.MidiId != -1)
				mciSendCommand(global->sound.midi.MidiId, MCI_CLOSE, 0, 0);
			MCI_OPEN_PARMS Open;
			memset(&Open, 0, sizeof(MCI_OPEN_PARMS));
			Open.lpstrElementName = global->sound.midi.mf.file;
			DWORD style = MCI_OPEN_ELEMENT;
			MciError = mciSendCommand(global->sound.cd.PlayCDId + 1, MCI_OPEN, style, DWORD(&Open));
			global->sound.midi.MidiId = Open.wDeviceID;
			if(!MciError)
				{
					MCI_SET_PARMS InfoSet;
					memset(&InfoSet, 0, sizeof(MCI_SET_PARMS));
					InfoSet.dwTimeFormat	= MCI_FORMAT_MILLISECONDS;
					MciError = mciSendCommand(global->sound.midi.MidiId, MCI_SET, MCI_SET_TIME_FORMAT, DWORD(&InfoSet));
				}
			if(!MciError)
				{
					KillTimer(global->MainVar.ChildHwnd, IDT_MIDI);
					MCI_STATUS_PARMS InfoStat;
					memset(&InfoStat, 0, sizeof(MCI_STATUS_PARMS));
					InfoStat.dwCallback = 0;
					InfoStat.dwItem			= MCI_STATUS_LENGTH;
					InfoStat.dwTrack		= 0;
					MciError = mciSendCommand(global->sound.midi.MidiId, MCI_STATUS, MCI_STATUS_ITEM, DWORD(&InfoStat));

					MCI_PLAY_PARMS InfoPlay;
					memset(&InfoPlay, 0, sizeof(MCI_PLAY_PARMS));
					InfoPlay.dwCallback = (DWORD)global->MainVar.ChildHwnd;
					InfoPlay.dwFrom	= (DWORD)(global->sound.midi.mf.sec * 1000);
					MciError = mciSendCommand(global->sound.midi.MidiId, MCI_PLAY, MCI_FROM | MCI_NOTIFY, DWORD(&InfoPlay));

					global->sound.midi.MidiTimeRate = (InfoStat.dwReturn) - (global->sound.midi.mf.sec * 1000);
					SetTimer(global->MainVar.ChildHwnd, IDT_MIDI, global->sound.midi.MidiTimeRate, (TIMERPROC)TimerProc);
				} 
			}	break;
		case IDM_STOP:
			if(!MciError)
				{
				MciError = mciSendCommand(global->sound.midi.MidiId, MCI_STOP, 0, 0);
				} break;
		}
	mciGetErrorString(MciError, global->sound.midi.error, MAXARRAY*sizeof(global->sound.midi.error));
}
			//////////////////////////////////////
			// TimerProc Function
			//////////////////////////////////////
void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
MidiProc(IDM_PLAY);
}
