/* //////////////////////////////////////////////////////////////////////
 Program Name:  cPlayerMngr.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-26
 Updated:       
 Version:       1.00
 Description:
   Player Manager Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

///////////////////////////////////////////////////////
cPlayerMngr::cPlayerMngr()
{
   m_plist = new cLList<cPlayerNode>;
}


cPlayerMngr::~cPlayerMngr()
{
   DELETE(m_plist);
}


void cPlayerMngr::ClearList()
{
   m_plist->clear();
}


void cPlayerMngr::AddPlayer(cPlayer *p)
{
   cPlayerNode tn(p);
   m_plist->append(tn);
}


cPlayer* cPlayerMngr::StartWalk()
{
   m_tn = m_plist->front();
   if(m_tn != NULL) return m_tn->GetPlayer();

   return NULL;
}


cPlayer* cPlayerMngr::NextWalk()
{
   m_tn = m_plist->next();
   if(m_tn != NULL) return m_tn->GetPlayer();

   return NULL;
}


cPlayer* cPlayerMngr::Find(JSObject *js_obj)
{
   cPlayer *obj;

   m_tn = m_plist->front();
   while(m_tn != NULL)
   {
      obj = m_tn->GetPlayer();
      if(obj != NULL)
      {
         if(obj->m_js_object == js_obj) {
            return obj;
         }
      }

      m_tn = m_plist->next();
   }

   return NULL;
}