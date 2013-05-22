/* //////////////////////////////////////////////////////////////////////
 Program Name:  cRingCamera.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-27
 Updated:       
 Version:       1.00
 Description:
   Ring Camera Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __RING_CAMERA__
#define __RING_CAMERA__

class cRingCamera
{
   public:
       cRingCamera();
      ~cRingCamera();

      void SetRingSize(uInt32 w, uInt32 h);

      void SetFirst(cGfxObj *gfx);
      void SetSecond(cGfxObj *gfx);

      void Update(uInt16 type = 0);

      Int32 GetShiftX();
      Int32 GetShiftY();
      
   protected:
      uInt32 m_display_w;
      uInt32 m_display_h;
      uInt32 m_ring_w;
      uInt32 m_ring_h;

      Int32 m_current_x;
      Int32 m_current_y;

      Int32 m_want_x;
      Int32 m_want_y;

      cGfxObj *m_first;
      cGfxObj *m_second;

};

#endif // __RING_CAMERA__
