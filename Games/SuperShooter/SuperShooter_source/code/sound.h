//////////////////////////////////////////////////////////////////////////////
// Program Name:  sound.h
// Programmer:    Joseph E. Sutton
// Description:	Sound
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _SOUND_
#define _SOUND_

#include "main.h"

extern HWND main_hwnd;
#define IDT_MIDI 101

void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);

class Sound
{
   enum SndType{SND_NONE=0, SND_MIDI=1, SND_WAV, SND_CD, SND_PLAY, SND_PAUSE, SND_STOP, SND_SEEK, SND_CLOSE};

public:
   Sound();
   ~Sound();

   void LoadWav(UINT res_id);
   void LoadMidi(char *file, int start_time = 0);
   void Play(DWORD TrackNumber = 0);
   void Pause();
   void Stop();
   void Close();

protected:
   SndType type;
   char error[256];

   char MidiFile[256];
   UINT MidiId, PlayCDId;
   int start_sec, MTimeRate;
   bool midi_loaded;
   MCIERROR MciError;

   HANDLE wav_hres;
   HANDLE wav_data;   

   void Midi(SndType msg);
   void Wave(SndType msg);
   void AudioCD(SndType msg, DWORD TrackNumber);
};


#endif