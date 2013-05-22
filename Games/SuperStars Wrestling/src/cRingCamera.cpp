/* //////////////////////////////////////////////////////////////////////
 Program Name:  cRingCamera.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-27
 Updated:       
 Version:       1.00
 Description:
   Ring Camera Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cRingCamera::cRingCamera()
{
   m_display_w = info->display->GetWidth();
   m_display_h = info->display->GetHeight();

   m_current_x = m_display_w/2;
   m_want_x = m_current_x;

   m_current_y = m_display_h/2 + 20;
   m_want_y = m_current_y;

   m_first = NULL;
   m_second = NULL;
}

cRingCamera::~cRingCamera()
{
}

Int32 cRingCamera::GetShiftX()
{
   uInt32 diff;
   uInt8  inc;

   diff = abs(m_current_x - m_want_x);
   inc = 1;
   if(diff < 3) {
      inc = 1;
   } else
   if(diff < 6) {
      inc = 2;
   } else
   if(diff < 9) {
      inc = 4;
   } else {
      inc = 20;
   }

   if(m_current_x > m_want_x) {
      m_current_x -= inc;
      return +inc;
   } else
   if (m_current_x < m_want_x) {
      m_current_x += inc;
      return -inc;
   }

   return 0;
}


Int32 cRingCamera::GetShiftY()
{
   uInt32 diff = abs(m_current_y - m_want_y);
   uInt8  inc = 1;

   if(diff < 3) {
      inc = 1;
   } else
   if(diff < 6) {
      inc = 2;
   } else
   if(diff < 9) {
      inc = 4;
   } else {
      inc = 20;
   }

   if(m_current_y > m_want_y) {
      m_current_y -= inc;
      return +inc;
   } else
   if (m_current_y < m_want_y) {
      m_current_y += inc;
      return -inc;
   }

   return 0;
}

void cRingCamera::SetRingSize(uInt32 w, uInt32 h)
{
   m_ring_w = w;
   m_ring_h = h;
}

void cRingCamera::SetFirst(cGfxObj *gfx)
{
   m_first = gfx;
}


void cRingCamera::SetSecond(cGfxObj *gfx)
{
   m_second = gfx;
}


// calc middle
void cRingCamera::Update(uInt16 type)
{
   if(m_first == NULL) return;
   if(m_second == NULL) return;

   Int32 tx, ty, padding;

   tx = m_first->GetX() + m_second->GetX();
   ty = m_first->GetZ() + m_second->GetZ();

   tx /= 2;
   ty /= 2;

   //
   padding = 20;
   if((Int32)(m_first->GetX() + padding) > (Int32)(tx + m_display_w/2)) {
      tx = m_first->GetX() + padding - m_display_w/2;
   } else
   if((Int32)(m_first->GetX() - padding) < (Int32)(tx - m_display_w/2)) {
      tx = m_first->GetX() - padding + m_display_w/2;
   }

   if((Int32)(m_first->GetZ() + 30) > (Int32)(ty + m_display_h/2)) {
      ty = m_first->GetZ() + 30 - m_display_h/2;
   } else
   if((Int32)(m_first->GetZ() - 90) < (Int32)(ty - m_display_h/2)) {
      ty = m_first->GetZ() - 90 + m_display_h/2;
   }
   //

   m_want_x = tx;
   m_want_y = ty;


   ///////////////////////////////////////////////////
   // fix want_x/wany_y of outside boundy
   tx = m_want_x - m_display_w/2;
   ty = m_want_y - m_display_h/2;
   if(tx < 0) m_want_x = m_display_w/2;
   if(ty < 0) m_want_y = m_display_h/2;

   tx = m_ring_w - m_display_w/2;
   ty = m_ring_h - m_display_h/2;
   if(m_want_x > tx) m_want_x = tx;
   if(m_want_y > ty) m_want_y = ty;
   ///////////////////////////////////////////////////
}

