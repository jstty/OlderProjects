/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLevelMngr.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-16
 Updated:       
 Version:       1.00
 Description:
   Level Manager Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __LEVEL_MNGR__
#define __LEVEL_MNGR__

class cLevelMngr
{
   public:
      cLevelMngr();
      ~cLevelMngr();

      int Init(int num); // should only done once
      int AddLevel(cLevel *lvl);

      int ResetLevel();

      // 
      int FirstLevel();
      int LastLevel();

      int NextLevel();
      int PrevLevel();
      int JumpLevel(uInt16 num);

      // really updates current level
      // should be done in thread
      int UpdateLevel();

      // wrapper of current level functions
      int LevelLoop();
      int LevelDraw();
      int LevelSound();

   private:
      uInt16 m_max_levels;
      uInt16 m_num_levels;
      cLevel **m_levels; // array of level pointers, 
                         // ONLY DELETE array, DON'T DELETE level pointer

      bool    m_change_level;
      uInt16  m_prev_clevel;
      uInt16  m_pos_clevel;
      cLevel *m_clevel;  // current level, DON'T DELETE

      void FreeAll();

      int LevelInit();
      int LevelExit();
};

#endif // __LEVEL_MNGR__
