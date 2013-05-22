/* //////////////////////////////////////////////////////////////////////
 Program Name:  cSuperStars.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-14
 Updated:       
 Version:       1.00
 Description:
   SuperStars Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __SUPER_STARS__
#define __SUPER_STARS__

// KEY_ESC, __allegro_KEY_ESC
enum {GAME_KEY_ESC = 0,
      GAME_KEY_PAUSE, 
      GAME_KEY_STEP,
      GAME_KEY_PLAYER_PLAY,
      GAME_KEY_PLAYER_LOAD,
      GAME_KEY_PLAYER_SAVE,
      GAME_KEY_RESET_LEVEL,
      GAME_KEY_SLOW_MOTION
     };

enum {PL_1 = 0, PL_2};
enum {PL_UP = 0, PL_LEFT, PL_DOWN, PL_RIGHT,
      PL_A1, PL_A2, PL_A3};



class cSuperStars
{
   public:
      cSuperStars();
      ~cSuperStars();

      int Init();
      int MainLoop();
      int Exit();

      float GetFPS();

      // wrapper for cLevelMngr
      int NextLevel();
      int PrevLevel();
      int JumpLevel(uInt16 num);

      // Font Manager
      cFontMngr *font;

      // debugging data
      ImgData   *hotspot;
      ImgData   *scopespot;


   private:
      cToggleAction *m_pause;
      cToggleAction *m_step;
      bool           m_play;

      cDisplay    *m_display;
      cSound      *m_sound;
      cControls   *m_controls;

      cLevelMngr  *m_lvlmngr;

      cLvl_Intro  *m_intro;
      cLvl_Ring01 *m_ring01;

      uInt32      m_fps_want;
      float       m_fps_got;
      uInt32      m_clock_start;
      uInt32      m_clock_diff_want;
      uInt32      m_clock_diff_got;
      uInt32      m_loop_ticks;

      cToggleAction *m_reset; // reset level

      cToggleAction *m_slowmo;
      uInt32         m_clock_diff_want_slowmo;

      cGfxText      *m_pause_text;
      void           DrawPause();
      
      //
      cActionPlayer *m_player;
      uInt8          m_player_state;

      cToggleAction *m_player_play;
      cToggleAction *m_player_load;
      cToggleAction *m_player_save;
      cGfxText      *m_player_text;

      uInt8          m_player_drawtext;
      void DrawPlayerText();
};

#endif // __SUPER_STARS__