/* //////////////////////////////////////////////////////////////////////
 Program Name:  cFx.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-28
 Updated:       
 Version:       1.00
 Description:
   Animation Class Header File
   frame number starts at ZERO
////////////////////////////////////////////////////////////////////// */
#ifndef __SPECIAL_FX__
#define __SPECIAL_FX__

class cFx
{
   public:
      cFx();
      ~cFx();

      void  FadeNone();
      void  FadeIn(uInt8 step, uInt8 min, uInt8 max);
      void  FadeOut(uInt8 step, uInt8 min, uInt8 max);

      void  FadeUpdate();

      bool  FadeDone();
      bool  IsFade();
      Int16 GetFade();

   private:
      uInt8   m_fade;    // 0 - not fadeing
                         // 1 - fade in
                         // 2 - fade out
      uInt8   m_fade_step;
      bool    m_fade_done;

      uInt8   m_opacity_min;
      uInt8   m_opacity_max;

      Int16   m_opacity; // temp opacity, for fade in/out

};

#endif // __SPECIAL_FX__
