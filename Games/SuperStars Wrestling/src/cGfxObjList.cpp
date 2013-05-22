/* //////////////////////////////////////////////////////////////////////
 Program Name:  cGfxObjList.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-15-06
 Updated:       
 Version:       1.00
 Description:
   Graphics Object List Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


cGfxNode::cGfxNode(const char name[128])
{
   m_type = 0;
   m_gfx = NULL;

   memcpy(m_name, name, 128);
}

cGfxNode::~cGfxNode()
{
   if(m_gfx != NULL)
   {
   }
}

bool cGfxNode::operator ==(const cGfxNode &src) const
{
   if(strcmp(src.m_name, m_name) == 0)
      return true;
   else 
      return false;
}

bool cGfxNode::operator  >(const cGfxNode &src) const
{
   if(strcmp(src.m_name, m_name) > 0)
      return true;
   else 
      return false;
}

bool cGfxNode::operator  <(const cGfxNode &src) const
{
   if(strcmp(src.m_name, m_name) < 0)
      return true;
   else 
      return false;
}

cGfxObj *cGfxNode::GetGfxObj()
{
   return m_gfx;
}


int cGfxNode::Load(const char *filename)
{

//   m_img = load_bitmap(filename, NULL);
//   if(m_img == NULL) return 1; // error

   return 0;
}



////////////////////////////////////////////////////
cGfxObjList::cGfxObjList()
{
}

cGfxObjList::~cGfxObjList()
{
   Clear();
}


void cGfxObjList::Clear()
{
   m_list.release();
}


cGfxObj *cGfxObjList::Find(const char *name)
{
   cGfxNode tmp(name);
   if(m_list.find(tmp) == 0) // if found
   {
      return tmp.GetGfxObj();
   }

   return NULL;
}


int cGfxObjList::AddImg(const char *tagname, const char *filename)
{
   cGfxNode tn(tagname);
   tn.Load(filename);

   return m_list.add(tn);
}
