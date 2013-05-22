/* //////////////////////////////////////////////////////////////////////
 Program Name:  cWrestlerMngr.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-21
 Updated:       
 Version:       1.00
 Description:
   Generic Wrestler Manager Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __WRESTLER_MNGF__
#define __WRESTLER_MNGF__


class cWrestlerNode
{
   public:
      cWrestlerNode();
      cWrestlerNode(cWrestler *d, const char *n);
      ~cWrestlerNode();

      cWrestler *GetWrestler();
      bool CmpName(const char *n);

   private:
      char       m_name[16];
      cWrestler *m_data;
};


class cWrestlerMngr
{
   public:
      cWrestlerMngr();
      ~cWrestlerMngr();

      int  Load(const char *filename);
      void Clear(); // deletes all wreslter pointers

      cWrestler *Find(const char *name);

      // step through list, to do what ever needs to be done
            

   private:
      cLList<cWrestlerNode> *m_list; // NEED TO DELETE ALL wreslers passed in

};


#endif // __WRESTLER_MNGF__

