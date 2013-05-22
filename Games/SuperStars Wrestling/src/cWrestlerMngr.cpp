/* //////////////////////////////////////////////////////////////////////
 Program Name:  cWrestlerMngr.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-21
 Updated:       
 Version:       1.00
 Description:
   Generic Wrestler Manager Class Header File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

//////////////////////////////////////////////////////////////////////

cWrestlerNode::cWrestlerNode()
{
   m_data = NULL;
}

cWrestlerNode::cWrestlerNode(cWrestler *d, const char *n)
{
   m_data = d;
   strcpy(m_name, n);
}

cWrestlerNode::~cWrestlerNode()
{
}

bool cWrestlerNode::CmpName(const char *n)
{
   return (strcmp(m_name, n) == 0);
}

cWrestler *cWrestlerNode::GetWrestler()
{
   return m_data;
}



//////////////////////////////////////////////////////////////////////
cWrestlerMngr::cWrestlerMngr()
{
   m_list = new cLList<cWrestlerNode>();
}

cWrestlerMngr::~cWrestlerMngr()
{
   Clear();

   DELETE(m_list);
}


void cWrestlerMngr::Clear()
{
   Int32 i;
   cWrestler *tmp;
   cWrestlerNode *tnp;

   // walk linked list
   tnp = m_list->front();
   for(i = 0; (i < m_list->size()) && (tnp != NULL); ++i)
   {
      tmp = tnp->GetWrestler();
      DELETE(tmp);

      tnp = m_list->next();
   }

   m_list->clear();
}


// file struct
// <wrestler dir>
// ...
int cWrestlerMngr::Load(const char *filename)
{
   int e;
   char s[256], name[256], path[256];
   cTextFileReader fr;
   cBaseWrestler base;

   // get file path
   Int32 path_len = (Int32)(strrchr(filename, '/') - filename + 1);
   strncpy(path, filename, sizeof(char)*path_len);
   path[path_len] = '\0';
   //

   e = fr.Load(filename);
   if(e) return e;

   // read base data
   base.Load(path);

   // load each wrestler in list
   cWrestler *tmp;
   while( !fr.AtEnd() )
   {
      fr.ReadString(name);

      tmp = new cWrestler();
      sprintf(s, "%s%s/wrestler.info", path, name);
      tmp->Load(s, &base);

      cWrestlerNode tmpnode(tmp, name);
      m_list->append(tmpnode);
   }

   return 0;
}


cWrestler *cWrestlerMngr::Find(const char *name)
{
   Int32 i;
   cWrestlerNode *tnp;

   // walk linked list
   tnp = m_list->front();
   for(i = 0; (i < m_list->size()) && (tnp != NULL); ++i)
   {
      if(tnp->CmpName(name)) {
         return tnp->GetWrestler();
      }

      tnp = m_list->next();
   }

   return NULL;
}


