/* //////////////////////////////////////////////////////////////////////
 Program Name:  cDisplay.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-18
 Updated:       
 Version:       1.00
 Description:
   cDisplay Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __DISPLAY__
#define __DISPLAY__

class cDisplay
{
   public:
      cDisplay();
      ~cDisplay();

      int Init();
      int Exit();

      uInt32 GetWidth();
      uInt32 GetHeight();

      int Draw(cLayerMngr *lm, bool clear_buffer = false);
      int Draw(cGfxObj    *gfxobj);
      int Draw(ImgData *src, uInt32 x = 0, uInt32 y = 0, bool clear_buffer = false);

      // should only called from the game
      int DrawUpdate(); // force draw buffer to screen

      uInt8 GetScale();
     
   private:
      bool m_exited;

      uInt8       m_scale;
      uInt32      m_width, m_height;
      ImgData    *m_buffer;
};

#endif // __DISPLAY__
