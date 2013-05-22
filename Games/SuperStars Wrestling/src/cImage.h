/* //////////////////////////////////////////////////////////////////////
 Program Name:  cImage.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Basic Image Class Header File
   Does not have multi-animations, see cSprite
   
////////////////////////////////////////////////////////////////////// */
#ifndef __IMAGE__
#define __IMAGE__

class cImage : public cGfxObj
{
   public:
      cImage();
      cImage(const cImage &src); // copy constructor
      cImage(const char *name);
      ~cImage();

      virtual int Load(const char *filename);      // load animation file
      virtual int LoadImage(const char *filename); // load single image(bitmap) file

      virtual cAnim *Anim();
      virtual void   Step(); // step animation

      virtual void AnimSelect(const char *name, uInt16 frame_num = 0);
      virtual void AnimSelect(uInt16   seq_num, uInt16 frame_num = 0);
      virtual void AnimSetFrame(uInt16 frame_num);

   protected:
      cAnim *m_anim;
};

#endif // __IMAGE__
