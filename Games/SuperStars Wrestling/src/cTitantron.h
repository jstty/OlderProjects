/* //////////////////////////////////////////////////////////////////////
 Program Name:  cTitantron.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-25
 Updated:       
 Version:       1.00
 Description:
   
////////////////////////////////////////////////////////////////////// */
#ifndef __TITANTRON__
#define __TITANTRON__

class cTitantron : public cGfxObj
{
   public:
      cTitantron();
      ~cTitantron();

      virtual int Draw(ImgData *out, Int32 offset_x = 0, Int32 offset_y = 0);
      void CaptureBuffer(ImgData *out);

      void GetFocusObject(cGfxObj *obj);

   protected:
      ImgData *m_buffer;

      cGfxObj *m_focus;

};

#endif // __TITANTRON__
