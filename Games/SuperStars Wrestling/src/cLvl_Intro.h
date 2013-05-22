/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLvl_Intro.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-17
 Updated:       
 Version:       1.00
 Description:
   Level Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __LVL_INTRO__
#define __LVL_INTRO__

#define NUM_STARS      3
#define STAR_DELAY     150

#define NUM_SELECTIONS 6
#define SELECT_DELAY   15

class  cLvl_Intro: public cLevel
{
   public:
      cLvl_Intro();
      ~cLvl_Intro();

      virtual int Init();

      virtual int Loop();
      virtual int Draw(); // update display, only

      virtual int Exit(); // called when leaving level
   private:

      uInt8    m_stage;

      cLayer      m_main_layer;
      cLayer      m_select_layer;
      cLayerMngr *m_layer_mngr;

      cImage  *m_intro;

      cImage  *m_bkg;
      cImage  *m_logo;

      cImage **m_star;
      uInt32  *m_star_delay;
      
      void PickRandomStarPos(int num);


      // selection
      bool     m_action1_key_was_up;
      uInt32   m_selection_delay;
      uInt8    m_current_selection;
      uInt8    m_prev_selection;

      cGfxText **m_selection;

      void InitSelection();
      void NextSelection();
      void PrevSelection();
      void UpdateSelection();
};

#endif // __LVL_INTRO__
