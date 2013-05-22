////////////////////////////////////////////////////////////////////////
//	Program Name:	Sound.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Sound File
//	Date: 
////////////////////////////////////////////////////////////////////////

	// Included Header Files

#define STRICT
#include <windows.h>
#include <stdio.h>
#include <string.h>            
#include <mmsystem.h>
#include "AlienMansion.h"
#include "Sound.h"

			//////////////////////////////////////
			// Midi Function
			//////////////////////////////////////
LPTSTR MidiProc(HWNDdll hwnd, SOUND sound, UINT msg)
{
	mciSendCommand(sound.midi.MidiId, MCI_CLOSE, 0, 0);

	MCIERROR MciError;
	MCI_OPEN_PARMS Open;
	memset(&Open, 0, sizeof(MCI_OPEN_PARMS));
	Open.lpstrElementName = sound.midi.file;
	DWORD style = MCI_OPEN_ELEMENT;
	MciError = mciSendCommand(0, MCI_OPEN, style, DWORD(&Open));    
	sound.midi.MidiId = Open.wDeviceID;
	if(!MciError)
		{
			MCI_SET_PARMS InfoSet;
			memset(&InfoSet, 0, sizeof(MCI_SET_PARMS));
			InfoSet.dwTimeFormat	= MCI_FORMAT_MILLISECONDS;
			MciError = mciSendCommand(sound.midi.MidiId, MCI_SET, MCI_SET_TIME_FORMAT, DWORD(&InfoSet));
		}

switch(msg)
	{
	case IDM_PLAY:
		if(!MciError)
			{
				MCI_STATUS_PARMS InfoStat;
				memset(&InfoStat, 0, sizeof(MCI_STATUS_PARMS));
				InfoStat.dwCallback = 0;
				InfoStat.dwItem			= MCI_STATUS_LENGTH;
				InfoStat.dwTrack		= 0;
				MciError = mciSendCommand(sound.midi.MidiId, MCI_STATUS, MCI_STATUS_ITEM, DWORD(&InfoStat));

				MCI_PLAY_PARMS InfoPlay;
				memset(&InfoPlay, 0, sizeof(MCI_PLAY_PARMS));
				InfoPlay.dwCallback = (DWORD)hwnd;
				InfoPlay.dwFrom	= (DWORD)(sound.midi.sec * 1000);
				MciError = mciSendCommand(sound.midi.MidiId, MCI_PLAY, MCI_FROM | MCI_NOTIFY, DWORD(&InfoPlay));

				sound.midi.MidiTimeRate = (InfoStat.dwReturn) - (sound.midi.sec * 1000);
				SetTimer(hwnd, IDT_MIDI, sound.midi.MidiTimeRate, TimerProc);
			}
		break;
	case IDM_STOP:
		mciSendCommand(sound.midi.MidiId, MCI_STOP, 0, 0);
		break;
	}

	mciGetErrorString(MciError, sound.midi.error, sizeof(sound.midi.error));
	return sound.midi.error;
}
			//////////////////////////////////////
			// Wave Function
			//////////////////////////////////////
void WaveProc(HINST hInst, WORD rcFile)
{
HRSRC hResInfo;
HANDLE hWave; 
LPCSTR lWave;
	if( hResInfo = FindResource(hInst, MAKEINTRESOURCE(rcFile), "WAVE") )
		{  	
			if( hWave = LoadResource(hInst, hResInfo) )
			lWave = (LPCSTR)LockResource(hWave);
		} 
// Playing sound files.
	PlaySound(lWave, hInst, SND_ASYNC | SND_MEMORY);
// Releasing sound files from mem.
	if( lWave )	  UnlockResource(hWave);
	if( hWave )		FreeResource(hWave);
}
			//////////////////////////////////////
			// CDAudio Function
			//////////////////////////////////////
LPTSTR CDAudio(SOUND sound, UINT msg, DWORD TrackNumber)
{
	sound.cd.TrackNumber[0] = 0;
	mciSendCommand(sound.cd.PlayCDId, MCI_CLOSE, 0, 0);

	MCIERROR MciError;
	MCI_OPEN_PARMS Open;
	memset(&Open, 0, sizeof(MCI_OPEN_PARMS));
	Open.lpstrDeviceType = MAKEINTRESOURCE(MCI_DEVTYPE_CD_AUDIO); 
	DWORD style = MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID;
	MciError = mciSendCommand(0, MCI_OPEN, style, DWORD(&Open));   
	sound.cd.PlayCDId = Open.wDeviceID;
//	Setting format to play Track
	if(!MciError)
			{
			MCI_SET_PARMS InfoSet;
			memset(&InfoSet, 0, sizeof(MCI_SET_PARMS));
			InfoSet.dwTimeFormat	= MCI_FORMAT_TMSF;
			MciError = mciSendCommand(sound.cd.PlayCDId, MCI_SET, MCI_SET_TIME_FORMAT, DWORD(&InfoSet));
			}
	switch(msg)
		{
			case IDM_PLAY:
				{
// Playing CD
				if(!MciError)
					{
						MCI_PLAY_PARMS InfoPlay;
						memset(&InfoPlay, 0, sizeof(MCI_PLAY_PARMS));
						InfoPlay.dwFrom	= MCI_MAKE_TMSF(sound.cd.TrackNumber[0],0,0,0);
						MciError = mciSendCommand(sound.cd.PlayCDId, MCI_PLAY, MCI_FROM | MCI_NOTIFY, DWORD(&InfoPlay));
					}
				}	break;
			case IDM_STOP:
				{
					MCI_GENERIC_PARMS GenInfo;
					memset(&GenInfo, 0, sizeof(MCI_GENERIC_PARMS));
					GenInfo.dwCallback = 0;
					mciSendCommand(sound.cd.PlayCDId, MCI_STOP, MCI_NOTIFY, DWORD(&GenInfo));
				}	break;
			case IDM_SEEK:
				{
					MCI_SEEK_PARMS InfoSeek;
					memset(&InfoSeek, 0, sizeof(MCI_SEEK_PARMS));
					InfoSeek.dwTo	= MCI_MAKE_TMSF(sound.cd.TrackNumber[0],0,0,0);
					MciError = mciSendCommand(sound.cd.PlayCDId, MCI_SEEK, MCI_TO, DWORD(&InfoSeek));
				}
			case IDM_PAUSE:
				{
					MCI_GENERIC_PARMS GenInfo;
					memset(&GenInfo, 0, sizeof(MCI_GENERIC_PARMS));
					mciSendCommand(sound.cd.PlayCDId, MCI_PAUSE, 0, DWORD(&GenInfo));
				}
		}
mciGetErrorString(MciError, sound.cd.error, sizeof(sound.cd.error));
return sound.cd.error;
}

void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
MidiProc((HWNDdll)hwnd, global->sound, IDM_PLAY);
}
