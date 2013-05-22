/* //////////////////////////////////////////////////////////////////////
 Program Name:  cTitantron.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Basic Gfx Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cTitantron::cTitantron()
{
   m_buffer = load_bitmap("data/stadium/0/titantron.bmp", NULL);

   zpos = 100;
}

cTitantron::~cTitantron()
{
   if(m_buffer != NULL) {
      destroy_bitmap(m_buffer);
      m_buffer = NULL;
   }
}


int cTitantron::Draw(ImgData *out, Int32 offset_x, Int32 offset_y)
{
   // draw old titantron to screen buffer
   masked_blit(m_buffer, out, 
      0, 0, 
      offset_x + 308, offset_y + 16, 
      m_buffer->w, m_buffer->h);

   return 0;
}

void cTitantron::GetFocusObject(cGfxObj *obj)
{
   m_focus = obj;
}

void cTitantron::CaptureBuffer(ImgData *out)
{
   Int32 x = m_focus->GetX() - m_focus->GetW();
   Int32 y = m_focus->GetZ() - m_focus->GetH();

   // prevent crashing
   if(x < 0) x = 0;
   if(y < 0) y = 0;
   if(x > out->w) x = out->w;
   if(y > (out->h - m_buffer->h/2)) y = out->h - m_buffer->h/2;

   // capture new titantron from screen buffer
   masked_stretch_blit(out, m_buffer, 
      x, y, 
      m_buffer->w/2, m_buffer->h/2, 
      0, 0,
      m_buffer->w, m_buffer->h
   );
   //

   /*
   rectfill(out, 
             x, y,
             x + m_buffer->w/2, y + m_buffer->h/2,
             COLOR_GRAY);
   */
}


//


