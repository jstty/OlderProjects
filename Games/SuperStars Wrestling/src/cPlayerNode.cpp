/* //////////////////////////////////////////////////////////////////////
 Program Name:  cPlayerNode.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-18
 Updated:       
 Version:       1.00
 Description:
   Player Node Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cPlayerNode::cPlayerNode(cPlayer *player)
{
   m_obj = player;
}


cPlayerNode::~cPlayerNode()
{
}


bool cPlayerNode::operator ==(cPlayerNode &src)
{
   return (src.m_obj == m_obj);
}

bool cPlayerNode::operator !=(cPlayerNode &src)
{
   return (src.m_obj != m_obj);
}


bool cPlayerNode::operator >(const cPlayerNode &src)
{
   if( (src.m_obj != NULL) &&
       (m_obj     != NULL)
     )
   {
       return (m_obj->ypos > src.m_obj->ypos);
   }

   return false;
}

bool cPlayerNode::operator <(const cPlayerNode &src)
{
   if( (src.m_obj != NULL) &&
       (m_obj     != NULL)
     )
   {
      return (m_obj->ypos < src.m_obj->ypos);
   }

   return false;
}

cPlayer *cPlayerNode::GetPlayer()
{
   return m_obj;
}

