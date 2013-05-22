//////////////////////////////////////////////////////////////////////////////
// Program Name:  sound.cpp
// Programmer:    Joseph E. Sutton
// Description:	Sound
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "sound.h"

Sound::Sound()
{
   type = SND_NONE;
   PlayCDId = MidiId = 0;
   MTimeRate = start_sec = 0;
   midi_loaded =  false;
}

Sound::~Sound()
{
   if(wav_hres != NULL)   FreeResource(wav_hres);
}

void Sound::Play(DWORD TrackNumber)
{
   if(type == SND_MIDI)       Midi(SND_PLAY);
   else if(type == SND_WAV)   Wave(SND_PLAY);
}

void Sound::Pause()
{
   if(type == SND_MIDI)       Midi(SND_PAUSE);
}

void Sound::Stop()
{
   if(type == SND_MIDI)       Midi(SND_STOP);
}

void Sound::Close()
{
   if(type == SND_MIDI)       Midi(SND_CLOSE);
}


// Wave file
void Sound::LoadWav(UINT res_id)
{
   type = SND_WAV;
   
   if(main_hwnd != NULL)
   {
      HINSTANCE hInst = (HINSTANCE)GetWindowLong(main_hwnd, GWL_HINSTANCE);

      HRSRC hResInfo = FindResource(hInst, MAKEINTRESOURCE(res_id), "WAVE"); 
      if(hResInfo != NULL)
      {
         // Load Wave
         wav_hres = LoadResource(hInst, hResInfo);
      }
   }
}


void Sound::Wave(SndType msg)
{
   wav_data = LockResource(wav_hres);
   if(wav_data != NULL)
   {
      PlaySound((LPCSTR)wav_data, NULL, SND_ASYNC | SND_MEMORY);
      UnlockResource(wav_hres);
   }
}


void Sound::LoadMidi(char *file, int start_time)
{
   if( !midi_loaded )
   {
      type = SND_MIDI;
      strcpy(MidiFile, file);
      start_sec = start_time;

	   MCI_OPEN_PARMS Open;
	   memset(&Open, 0, sizeof(MCI_OPEN_PARMS));
	   Open.lpstrElementName = MidiFile;
	   DWORD style = MCI_OPEN_ELEMENT;
	   MciError = mciSendCommand(0, MCI_OPEN, style, DWORD(&Open));    
	   MidiId = Open.wDeviceID;
	   if(!MciError)
	   {
		   MCI_SET_PARMS InfoSet;
		   memset(&InfoSet, 0, sizeof(MCI_SET_PARMS));
		   InfoSet.dwTimeFormat	= MCI_FORMAT_MILLISECONDS;
		   MciError = mciSendCommand(MidiId, MCI_SET, MCI_SET_TIME_FORMAT, DWORD(&InfoSet));

         midi_loaded = true;
	   }
   }
}

void Sound::Midi(SndType msg)
{
   if(midi_loaded)
	{
      switch(msg)
	   {
	   case SND_PLAY:
			MCI_STATUS_PARMS InfoStat;
			memset(&InfoStat, 0, sizeof(MCI_STATUS_PARMS));
			InfoStat.dwCallback = 0;
			InfoStat.dwItem	  = MCI_STATUS_LENGTH;
			InfoStat.dwTrack	  = 0;
			MciError = mciSendCommand(MidiId, MCI_STATUS, MCI_STATUS_ITEM, DWORD(&InfoStat));

			MCI_PLAY_PARMS InfoPlay;
			memset(&InfoPlay, 0, sizeof(MCI_PLAY_PARMS));
			InfoPlay.dwCallback = (DWORD)main_hwnd;
			InfoPlay.dwFrom	  = (DWORD)(start_sec * 1000);
			MciError = mciSendCommand(MidiId, MCI_PLAY, MCI_FROM | MCI_NOTIFY, DWORD(&InfoPlay));

         // loop timer
			MTimeRate = (InfoStat.dwReturn) - (start_sec * 1000);
			SetTimer(main_hwnd, IDT_MIDI, MTimeRate, TimerProc);
		 
		   break;
	   case SND_STOP:
		   MciError = mciSendCommand(MidiId, MCI_STOP, 0, 0);
		   break;
      case SND_CLOSE:
         midi_loaded = false;
         MciError = mciSendCommand(MidiId, MCI_CLOSE, 0, 0);
         break;
	   }

	   mciGetErrorString(MciError, error, 255);
   }
}


void Sound::AudioCD(SndType msg, DWORD TrackNumber)
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
		case SND_PLAY:
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
		case SND_STOP:
		{
			MCI_GENERIC_PARMS GenInfo;
			memset(&GenInfo, 0, sizeof(MCI_GENERIC_PARMS));
			GenInfo.dwCallback = 0;
			mciSendCommand(PlayCDId, MCI_STOP, MCI_NOTIFY, DWORD(&GenInfo));
		}	break;
		case SND_SEEK:
		{
			MCI_SEEK_PARMS InfoSeek;
			memset(&InfoSeek, 0, sizeof(MCI_SEEK_PARMS));
			InfoSeek.dwTo	= MCI_MAKE_TMSF(TrackNumber,0,0,0);
			MciError = mciSendCommand(PlayCDId, MCI_SEEK, MCI_TO, DWORD(&InfoSeek));
		}
		case SND_PAUSE:
		{
			MCI_GENERIC_PARMS GenInfo;
			memset(&GenInfo, 0, sizeof(MCI_GENERIC_PARMS));
			mciSendCommand(PlayCDId, MCI_PAUSE, 0, DWORD(&GenInfo));
		}
	}
   mciGetErrorString(MciError, error, 255);
}

