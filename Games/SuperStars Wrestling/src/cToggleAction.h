/* //////////////////////////////////////////////////////////////////////
 Program Name:  cToggleAction.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-19
 Updated:       
 Version:       1.00
 Description:
   Toggle Action Class Header File
     
////////////////////////////////////////////////////////////////////// */
#ifndef __TOGGLE_ACTION__
#define __TOGGLE_ACTION__


class cToggleAction
{
   public:
      cToggleAction();
      ~cToggleAction();

      void SetAction(bool *action, bool single_step = 0);

      bool Update();
      bool Get();
      
   private:
      bool   m_single_step;
      bool  *m_action;
      uInt8  m_toggle;

};

#endif // __TOGGLE_ACTION__
