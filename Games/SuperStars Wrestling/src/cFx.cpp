/* //////////////////////////////////////////////////////////////////////
 Program Name:  cFx.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-28
 Updated:       
 Version:       1.00
 Description:
   Special Graphics FX Class Source File
   - Fade in/out
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cFx::cFx()
{
   m_fade = 0;
   m_fade_done = false;
}


cFx::~cFx()
{
}


void cFx::FadeNone()
{
   m_fade = 0;
   m_fade_done = true;
}

void cFx::FadeIn(uInt8 step, uInt8 min, uInt8 max)
{
   m_opacity_min = min;
   m_opacity_max = max;
   m_opacity = m_opacity_min;
   m_opacity = 0;

   m_fade = 1;
   m_fade_step = step;
   m_fade_done = false;
}

void cFx::FadeOut(uInt8 step, uInt8 min, uInt8 max)
{
   m_opacity_min = min;
   m_opacity_max = max;
   m_opacity = m_opacity_max;

   m_fade = 2;
   m_fade_step = step;
   m_fade_done = false;
}

void cFx::FadeUpdate()
{
   if(!m_fade_done)
   {
      if(m_fade == 1)
      {
         m_opacity += m_fade_step;
         if(m_opacity > m_opacity_max)
         {
            m_opacity = m_opacity_max;
            m_fade_done = true;
         }
      }
      else if(m_fade == 2)
      {
         m_opacity -= m_fade_step;
         if(m_opacity < m_opacity_min)
         {
            m_opacity = m_opacity_min;
            m_fade_done = true;
         }
      }
   }
}

bool cFx::FadeDone()
{
   return m_fade_done;
}

bool cFx::IsFade()
{
   return (m_fade != 0);
}

Int16 cFx::GetFade()
{
   return m_opacity;
}