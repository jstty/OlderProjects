/* //////////////////////////////////////////////////////////////////////
 Program Name:  cActionPlayer.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-19
 Updated:       
 Version:       1.00
 Description:
   Control Action Recorder and Player
   
////////////////////////////////////////////////////////////////////// */
#ifndef __ACTION_PLAYER__
#define __ACTION_PLAYER__

enum {
   AP_NOTHING = 0,
   AP_PLAYING,
   AP_RECORDING,
     };

class cActionPlayer
{
   public:
      cActionPlayer();
      ~cActionPlayer();

      //void Init();
      int  Load(const char *filename);
      int  Save(const char *filename);
      void Close();

      void Update();

      void UnPause();
      void Pause();
      void Step();

      void SetPlaying();
      void SetRecording();
      
   private:
      FILE *m_fp;

      uInt32 m_pos;
      uInt32 m_num_actions;

      bool  m_paused;
      uInt8 m_state; // nothing, playing, or recording

      void CloseFile();

};

#endif // __ACTION_PLAYER__

