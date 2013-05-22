/* //////////////////////////////////////////////////////////////////////
 Program Name:  cGfxObj.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Basic Gfx Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cGfxObj::cGfxObj()
{
   m_type = OBJTYPE_GFX;
   xpos = 0;
   ypos = 0;
   zpos = 0;

   xhot = 0;
   yhot = 0;

   scope = 0;

   alpha_on = false;
   opacity = 255;

   show = true;

   m_cframe = NULL;
}

cGfxObj::cGfxObj(const cGfxObj &src)
{
   show = src.show;

   xpos = src.xpos;
   ypos = src.ypos;
   zpos = src.zpos;

   xhot = src.xhot;
   yhot = src.yhot;

   alpha_on = src.alpha_on;
   opacity = src.opacity;

   m_type = src.m_type;
   strcpy(m_name, src.m_name);
   m_cframe = src.m_cframe;
}

cGfxObj::~cGfxObj()
{
}

void cGfxObj::Show()
{
   show = true;
}

void cGfxObj::Hide()
{
   show = false;
}


const char *cGfxObj::GetName()
{
   return m_name;
}


void cGfxObj::SetName(const char *name)
{
   strcpy(m_name, name);
}

Int32 cGfxObj::GetX()
{
   return xpos;
}

Int32 cGfxObj::GetY()
{
   return ypos;
}

Int32 cGfxObj::GetZ()
{
   return zpos;
}

void cGfxObj::SetX(Int32 x)
{
   xpos = x;
}

void cGfxObj::SetY(Int32 y)
{
   ypos = y;
}

void cGfxObj::SetZ(Int32 z)
{
   zpos = z;
}

void cGfxObj::SetXZ(Int32 x, Int32 z)
{
   xpos = x;
   zpos = z;
}

void cGfxObj::SetXY(Int32 x, Int32 y)
{
   xpos = x;
   ypos = y;
}

Int32 cGfxObj::GetW()
{
   if(m_cframe != NULL) return m_cframe->w;
   else                 return 0;
}

Int32 cGfxObj::GetH()
{
   if(m_cframe != NULL) return m_cframe->h;
   else                 return 0;
}


int cGfxObj::Draw(ImgData *out, Int32 offset_x, Int32 offset_y)
{
   if( (!show) ||
       (out == NULL) ||
       (m_cframe == NULL) ||
       (m_cframe->img == NULL) )
   {
      return 1;
   }

   if(alpha_on)
   {
      // draw with transparency
      drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
         set_trans_blender(0, 0, 0, opacity);
         draw_trans_sprite(out, m_cframe->img, xpos + offset_x, ypos + offset_y);
      drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);
   } else {     
      masked_blit(m_cframe->img, out, 
         0, 0, 
         xpos + offset_x - xhot,
         ypos + zpos + offset_y - yhot,
         m_cframe->img->w, m_cframe->img->h 
         );
   }

   return 0;
}

void cGfxObj::Step()
{
   // do nothing, should be overloaded
}

//

