/* //////////////////////////////////////////////////////////////////////
 Program Name:  cToggleAction.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-19
 Updated:       
 Version:       1.00
 Description:
   Toggle Action Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


cToggleAction::cToggleAction()
{
   m_toggle = 0;
   m_action = NULL;
}


cToggleAction::~cToggleAction()
{
}

void cToggleAction::SetAction(bool *action, bool single_step)
{
   m_action = action;
   m_single_step = single_step;
}


bool cToggleAction::Update()
{
   if( (m_toggle == 0) &&
       (*m_action)
     ) {
     m_toggle = 1;
   } else
   if( (m_toggle == 1) &&
       (!(*m_action))
     ) {
     m_toggle = 2;
   } else
   if( (m_toggle == 2) &&
       (*m_action)
     ) {
     m_toggle = 3;
   } else
   if( (m_toggle == 3) &&
       (!(*m_action))
     ) {
     m_toggle = 0;
   }

   return Get();
}


bool cToggleAction::Get()
{
   if(m_single_step)
   {
      if( (m_toggle == 0) &&
          (*m_action)
        ) {
         m_toggle = 1;
         return true;
      } else
      if( (m_toggle == 1) &&
          (!(*m_action))
        ) {
         m_toggle = 0;
         return false;
      } else {
         return false;
      }
   } else {
      return (m_toggle != 0);
   }
}

