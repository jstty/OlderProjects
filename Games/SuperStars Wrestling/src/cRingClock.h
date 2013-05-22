/* //////////////////////////////////////////////////////////////////////
 Program Name:  cRingClock.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-03
 Updated:       
 Version:       1.00
 Description:
   
////////////////////////////////////////////////////////////////////// */
#ifndef __RING_CLOCK__
#define __RING_CLOCK__

class cRingClock : public cGfxObj
{
   public:
      cRingClock();
      ~cRingClock();

      void SetTime(uInt32 time); // in seconds
      void ResetTime();

      virtual int Draw(ImgData *out, Int32 offset_x = 0, Int32 offset_y = 0);

      void Update(); // take next tick

   protected:
      char      m_str[256];
      cGfxText *m_text;

      uInt32 m_stime; // start time
      uInt32 m_ctime; // current time left, in seconds

      uInt8 m_cmin;   // calc of min
      uInt8 m_csec;   // calc of sec

      uInt8  m_fps;   // frames per second
      uInt8  m_ticks; // frames left per second, when reach zero decrease one second

};

#endif // __RING_CLOCK__
