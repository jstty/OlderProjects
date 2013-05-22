/* //////////////////////////////////////////////////////////////////////
 Program Name:  cRingStatusMenu.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-19
 Updated:       
 Version:       1.00
 Description:
   Ring Status Menu Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __RING_STATUS_MENU__
#define __RING_STATUS_MENU__

typedef struct _sPlayerStatus
{
   uInt8     style; // used to load color and hp gfx
   uInt8     type;

   int       color; // 
   cGfxText *name;  // NEED TO DELETE
   ImgData  *hp;    // NEED TO DELETE
   ImgData  *star;  // NEED TO DELETE
   cGfxText *star_text;   // NEED TO DELETE
   ImgData  *color_box;   // NEED TO DELETE
   ImgData  *player_type; // NEED TO DELETE

   ImgData    *face;    // DON'T DELETE
   const char *fname;   // HULK HOGAN
   Int8       *nhp;     // 0-100
   Int8       *nhp_max; // 100

   uInt8      *nflags;  // 0-3
   uInt8      *nstars;  // 0-9

   // so the text object will not have to re-render 
   // text every loop, only when the number changes
   uInt8       prev_nstars; 
   
} sPlayerStatus;

class cRingStatusMenu
{
   public:
      cRingStatusMenu();
      ~cRingStatusMenu();

      void SetPlayer(uInt8 pn, cPlayer *p, uInt8 style, uInt8 type);

      void Init();
      void Exit();

      void Update();
      void Draw();

      int  Load();

   private:
      cRingClock *m_clock;

      ImgData  *m_status_buff;

      uInt32    m_status_w;
      uInt32    m_status_h;

      uInt8     m_hpsize;   // width of each hitpoints
      uInt8     m_flagsize; // 


      sPlayerStatus pstat[2];
      ImgData  *m_frame;


      void FreeAll();
};


#endif // __RING_STATUS_MENU__


