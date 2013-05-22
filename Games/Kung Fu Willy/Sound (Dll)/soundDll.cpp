////////////////////////////////////////////////////////////////////////
//  Program Name: SoundDll.cpp
//  Programmer: Joseph Sutton
//  Description: DLL Sound File
//  Date:
////////////////////////////////////////////////////////////////////////
#define STRICT
#include <windows.h>
#include <stdio.h>
#include <string.h>            
#include <mmsystem.h>
#include <Game.h>
#include "SoundDll.h"

			//////////////////////////////////////
			// DLLMain
			//////////////////////////////////////
BOOL APIENTRY DllEntryPoint(HINSTANCE hInstDLL, WORD wDataSeg, LPVOID lpReserved)
{
  return TRUE;
}
			//////////////////////////////////////
			// Midi Function
			//////////////////////////////////////
DllExport LPTSTR MIDI(UINT msg, HWNDdll hwnd)
{
	mciSendCommand(MidiId, MCI_CLOSE, 0, 0);

	MCIERROR MciError;
	MCI_OPEN_PARMS Open;
	memset(&Open, 0, sizeof(MCI_OPEN_PARMS));
	Open.lpstrElementName = File;
	DWORD style = MCI_OPEN_ELEMENT;
	MciError = mciSendCommand(0, MCI_OPEN, style, DWORD(&Open));    
	MidiId = Open.wDeviceID;
	if(!MciError)
		{
			MCI_SET_PARMS InfoSet;
			memset(&InfoSet, 0, sizeof(MCI_SET_PARMS));
			InfoSet.dwTimeFormat	= MCI_FORMAT_MILLISECONDS;
			MciError = mciSendCommand(MidiId, MCI_SET, MCI_SET_TIME_FORMAT, DWORD(&InfoSet));
		}

switch(msg)
	{
	case PLAY:
		if(!MciError)
			{
				MCI_STATUS_PARMS InfoStat;
				memset(&InfoStat, 0, sizeof(MCI_STATUS_PARMS));
				InfoStat.dwCallback = 0;
				InfoStat.dwItem			= MCI_STATUS_LENGTH;
				InfoStat.dwTrack		= 0;
				MciError = mciSendCommand(MidiId, MCI_STATUS, MCI_STATUS_ITEM, DWORD(&InfoStat));

				MCI_PLAY_PARMS InfoPlay;
				memset(&InfoPlay, 0, sizeof(MCI_PLAY_PARMS));
				InfoPlay.dwCallback = (DWORD)hwnd;
				InfoPlay.dwFrom	= (DWORD)(sec * 1000);
				MciError = mciSendCommand(MidiId, MCI_PLAY, MCI_FROM | MCI_NOTIFY, DWORD(&InfoPlay));

				MTimeRate = (InfoStat.dwReturn) - (sec * 1000);
				SetTimer(hwnd, ID_MTIMER, MTimeRate, NULL);
			}
		break;
	case STOP:
		mciSendCommand(MidiId, MCI_STOP, 0, 0);
		break;
	}

	mciGetErrorString(MciError, error, sizeof(error));
	return error;
}
			//////////////////////////////////////
			// Wave Function
			//////////////////////////////////////
DllExport void WAVE(WORD rcFile)
{
HRSRC hResInfo;
HANDLE hWave; 
LPCSTR lWave;
HINSTANCE hInst = LoadLibrary("levels.dll");
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
			// Wave Function
			//////////////////////////////////////
DllExport LPTSTR CDAudio(UINT msg, DWORD TrackNumber)
{
	mciSendCommand(PlayCDId, MCI_CLOSE, 0, 0);

	MCIERROR MciError;
	MCI_OPEN_PARMS Open;
	memset(&Open, 0, sizeof(MCI_OPEN_PARMS));
	Open.lpstrDeviceType = MAKEINTRESOURCE(MCI_DEVTYPE_CD_AUDIO); 
	DWORD style = MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID;
	MciError = mciSendCommand(0, MCI_OPEN, style, DWORD(&Open));   
	PlayCDId = Open.wDeviceID;
//	Setting format to play Track
	if(!MciError)
			{
			MCI_SET_PARMS InfoSet;
			memset(&InfoSet, 0, sizeof(MCI_SET_PARMS));
			InfoSet.dwTimeFormat	= MCI_FORMAT_TMSF;
			MciError = mciSendCommand(PlayCDId, MCI_SET, MCI_SET_TIME_FORMAT, DWORD(&InfoSet));
			}
	switch(msg)
		{
			case PLAY:
				{
// Playing CD
				if(!MciError)
					{
						MCI_PLAY_PARMS InfoPlay;
						memset(&InfoPlay, 0, sizeof(MCI_PLAY_PARMS));
						InfoPlay.dwFrom	= MCI_MAKE_TMSF(TrackNumber,0,0,0);
						MciError = mciSendCommand(PlayCDId, MCI_PLAY, MCI_FROM | MCI_NOTIFY, DWORD(&InfoPlay));
					}
				}	break;
			case STOP:
				{
					MCI_GENERIC_PARMS GenInfo;
					memset(&GenInfo, 0, sizeof(MCI_GENERIC_PARMS));
					GenInfo.dwCallback = 0;
					mciSendCommand(PlayCDId, MCI_STOP, MCI_NOTIFY, DWORD(&GenInfo));
				}	break;
			case SEEK:
				{
					MCI_SEEK_PARMS InfoSeek;
					memset(&InfoSeek, 0, sizeof(MCI_SEEK_PARMS));
					InfoSeek.dwTo	= MCI_MAKE_TMSF(TrackNumber,0,0,0);
					MciError = mciSendCommand(PlayCDId, MCI_SEEK, MCI_TO, DWORD(&InfoSeek));
				}
			case PAUSE:
				{
					MCI_GENERIC_PARMS GenInfo;
					memset(&GenInfo, 0, sizeof(MCI_GENERIC_PARMS));
					mciSendCommand(PlayCDId, MCI_PAUSE, 0, DWORD(&GenInfo));
				}
		}
mciGetErrorString(MciError, error, sizeof(error));
return error;
}

DllExport void Main_MciNotify(HWNDdll hwnd, UINT wFlags, LONG lDevID)
{
/*
if(wFlags)
	{
switch(wFlags)
	{
	case MCI_NOTIFY_ABORTED:
		test = 1;
		break;
	case MCI_NOTIFY_FAILURE:
		test = 2;
		break;
	case MCI_NOTIFY_SUCCESSFUL:
		test = 3;
		break;
	case MCI_NOTIFY_SUPERSEDED:
		test = 4;
		break;
	}
	}
else test = 5;
*/
}