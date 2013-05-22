/****************************************
 filename:    sound_bank.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: 
 ****************************************/
#ifndef _SOUND_BANK_
#define _SOUND_BANK_

enum SoundType { SoundType_Wave, SoundType_Midi };

class cSoundData {
   char      mName[256];
   SoundType mType;
   int *     mData;
};

class cSoundBank
{
public:
   cSoundBank();
   ~cSoundBank();
   
   void Play(const char *name);
   void Pause(const char *name);
   void Stop(const char *name);

   void AddWave(const char *name, const char *filename);
   void AddMidi(const char *name, const char *filename);
   
protected:
   vector< cSoundData * > mSounds;
   
   int Load(const char *filename);
};

#endif // _SOUND_BANK_
