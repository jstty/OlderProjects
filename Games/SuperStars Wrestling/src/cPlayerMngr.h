/* //////////////////////////////////////////////////////////////////////
 Program Name:  cPlayerMngr.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-26
 Updated:       
 Version:       1.00
 Description:
   Player Manager Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __PLAYER_MNGR__
#define __PLAYER_MNGR__

//
class cPlayerMngr
{
   public:
      cPlayerMngr();
      ~cPlayerMngr();

      void ClearList();

      void AddPlayer(cPlayer *p);

      cPlayer* StartWalk();
      cPlayer* NextWalk();

      cPlayer* Find(JSObject *js_obj);

   protected:
      cLList<cPlayerNode> *m_plist;
      cPlayerNode *m_tn; // temp player node
      
};

#endif // __PLAYER_MNGR__
