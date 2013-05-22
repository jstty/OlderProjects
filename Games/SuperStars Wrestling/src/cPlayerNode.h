/* //////////////////////////////////////////////////////////////////////
 Program Name:  cPlayerNode.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-18
 Updated:       
 Version:       1.00
 Description:
   Player Node Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __PLAYER_NODE__
#define __PLAYER_NODE__

class cPlayerNode
{
   public:
      cPlayerNode(cPlayer *player = NULL);
      ~cPlayerNode();

      bool operator ==(cPlayerNode &src);
      bool operator !=(cPlayerNode &src);
      bool operator  >(const cPlayerNode &src);
      bool operator  <(const cPlayerNode &src);

      cPlayer *GetPlayer();

   private:
      cPlayer *m_obj;
};


#endif  // __PLAYER_NODE__
