/* //////////////////////////////////////////////////////////////////////
 Program Name:  cGfxNode.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Graphics Node Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cGfxNode::cGfxNode(const char name[128])
{
   m_type = 0;
   m_gfx = NULL;
   memcpy(m_name, name, 128);
}


cGfxNode::cGfxNode(const char name[128], cGfxObj *gfx)
{
   m_type = 0;
   m_gfx = gfx;
   memcpy(m_name, name, 128); 
}

cGfxNode::cGfxNode(const char name[128], cImage  *img)
{
   m_type = 1;
   m_img = img;
   memcpy(m_name, name, 128);
}

cGfxNode::cGfxNode(const char name[128], cSprite *sprite)
{
   m_type = 2;
   m_spr = sprite;
   memcpy(m_name, name, 128);
}


cGfxNode::~cGfxNode()
{
}

bool cGfxNode::operator ==(cGfxNode &src)
{
   return (src.GetGfxObj() == GetGfxObj());
}

bool cGfxNode::operator !=(cGfxNode &src)
{
   return (src.GetGfxObj() != GetGfxObj());
}

bool cGfxNode::operator >(const cGfxNode &src)
{
   if((m_gfx == NULL) || (src.m_gfx == NULL)) return false;

   return (m_gfx->zpos > src.m_gfx->zpos);
}

bool cGfxNode::operator <(const cGfxNode &src)
{
   if((m_gfx == NULL) || (src.m_gfx == NULL)) return false;

   return (m_gfx->zpos < src.m_gfx->zpos);
}


uInt8 cGfxNode::GetType()
{
   return m_type;
}

cGfxObj *cGfxNode::GetGfxObj()
{
   return m_gfx;
}

cImage *cGfxNode::GetImage()
{
   return m_img;
}

cSprite *cGfxNode::GetSprite()
{
   return m_spr;
}

