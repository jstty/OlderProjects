/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLvl_Ring01.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-03
 Updated:       
 Version:       1.00
 Description:
   Level Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __LVL_RING01__
#define __LVL_RING01__

#define NUM_RING_LAYERS 7

class  cLvl_Ring01: public cLevel
{
   public:
      cLvl_Ring01();
      ~cLvl_Ring01();

      virtual int Init();

      virtual int Loop();
      virtual int Draw(); // update display, only

      virtual int Exit(); // called when leaving level
   private:
      cRingStatusMenu  *m_ring_status_menu;
      cRingCamera      *m_ring_camera;

      uInt32      m_screen_w;
      uInt32      m_screen_h;
      ImgData    *m_screen_buff;
      Int32       m_screen_x;
      Int32       m_screen_y;

      ImgData    *m_titantron_buff;

      cWrestlerMngr *m_wmngr;
      cPlayerMngr   *m_pmngr;

      cScriptEngine *m_se;
      cScriptPlayer *m_sp1;
      cScriptPlayer *m_sp2;
      cPlayer       *m_p1; // DON'T DELETE
      cPlayer       *m_p2; // DON'T DELETE

      
      cZones  *m_zones;

      cLayerMngr *m_layers;
         cLayer   *m_bkg;
            cImage *m_arena;
            cTitantron *m_titan;

         // ring
         cLayer   *m_ring_layers[NUM_RING_LAYERS];
            cImage *m_ring;              // 0
            cImage *m_backropes;         // 1
            cImage *m_sideropebottom_l;  // 2
            cImage *m_sideropetop_l;     // 2
            cImage *m_sideropebottom_r;  // 3
            cImage *m_sideropetop_r;     // 3
            cImage *m_frontropes;        // 4

         //cLayer   *m_main;

         cLayer   *m_fr_comm;
         // bottom
            uInt8   m_comm_delay;
            cImage *m_commintator;
            cImage *m_frontrow_l;
            cImage *m_frontrow_r;
};

#endif // __LVL_RING01__
