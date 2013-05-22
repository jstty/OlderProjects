/* //////////////////////////////////////////////////////////////////////
 Program Name:  cRingClock.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-03
 Updated:       
 Version:       1.00
 Description:
   Ring Clock Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cRingClock::cRingClock()
{
   m_text = new cGfxText();
   m_text->SetXY(0,0);
   m_text->SetSize(130, 16);
   m_text->SetCharPadding(1, 0);
   m_text->SetFontIndex(6);

   m_fps = 30;
}


cRingClock::~cRingClock()
{
   DELETE(m_text);
}


void cRingClock::SetTime(uInt32 time)
{
   m_stime = time;
   ResetTime();
}


void cRingClock::ResetTime()
{
   m_ctime = m_stime;
   m_ticks = m_fps;

   // update time
   m_cmin = m_ctime / 60;
   m_csec = m_ctime % 60;
}


int cRingClock::Draw(ImgData *out, Int32 offset_x, Int32 offset_y)
{
   m_text->Draw(out, offset_x, offset_y);

   return 0;
}


void cRingClock::Update()
{
   if(m_ctime != 0)
   {
      if(m_ticks == 0)
      {
         m_ticks = m_fps;
         --m_ctime;

         // update time
         m_cmin = m_ctime / 60;
         m_csec = m_ctime % 60;
      }
      --m_ticks;
   } else {
      m_ticks = 0;
   }

   sprintf(m_str, "TIME %0.2d:%0.2d.%d", m_cmin, m_csec, (uInt8)((10*m_ticks)/m_fps));
   m_text->SetString(m_str);
   m_text->Update();
}

//


