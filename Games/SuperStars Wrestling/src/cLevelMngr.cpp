/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLevelMngr.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-16
 Updated:       
 Version:       1.00
 Description:
   Level Manager Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cLevelMngr::cLevelMngr()
{
   m_max_levels = 0;
   m_num_levels = 0;
   m_levels = NULL;

   m_change_level = false;
   m_prev_clevel = -1;
   m_pos_clevel = 0;
   m_clevel = NULL;
}

cLevelMngr::~cLevelMngr()
{
   FreeAll();
}

void cLevelMngr::FreeAll()
{
   m_num_levels = 0;
   m_pos_clevel = 0;
   m_prev_clevel = -1;
   m_clevel = NULL;

   if(m_levels != NULL)
   {
      int i;
      for(i = 0; i < m_max_levels; ++i) {
         m_levels[i] = NULL;
      }

      delete [] m_levels;
      m_levels = NULL;
   }

   m_max_levels = 0;
}

int cLevelMngr::Init(int num)
{
   FreeAll();
   m_max_levels = num;
   m_num_levels = 0;

   m_levels = new cLevel *[m_max_levels];

   return 0;
}

int cLevelMngr::AddLevel(cLevel *lvl)
{
   m_levels[m_num_levels] = lvl;
   ++m_num_levels;

   return 0;
}


int cLevelMngr::UpdateLevel()
{
   if( (m_change_level == true) 
       //&& (m_prev_clevel != m_pos_clevel)
      )
   {
      // todo, should be put in a thread...
      // update progress

      // exit old
      LevelExit(); // exit current level before change to next

      m_clevel = m_levels[m_pos_clevel]; // set level to current level

      // init new
      LevelInit(); // call init to load data

      // done
      m_prev_clevel = m_pos_clevel;
      m_change_level = false;
      return 0;
   }

   return 1;
}


int cLevelMngr::ResetLevel()
{
   if(m_levels != NULL)
   {
      m_change_level = true;
      return 0;
   }

   return 1;
}

int cLevelMngr::FirstLevel()
{
   if(m_levels != NULL)
   {
      m_pos_clevel = 0;
      m_change_level = true;
      return 0;
   }

   return 1;
}


int cLevelMngr::LastLevel()
{
   if((m_levels != NULL) &&
      (m_num_levels > 0))
   {
      m_pos_clevel = m_num_levels - 1;
      m_change_level = true;
      return 0;
   }

   return 1;
}


int cLevelMngr::NextLevel()
{
   if((m_levels != NULL) &&
      (m_pos_clevel < (m_num_levels - 1)) )
   {
      ++m_pos_clevel;
      m_change_level = true;
      return 0;
   }

   return 1;
}


int cLevelMngr::PrevLevel()
{
   if((m_levels != NULL) &&
      (m_pos_clevel > 0) )
   {
      --m_pos_clevel;
      m_change_level = true;
      return 0;
   }

   return 1;
}


int cLevelMngr::JumpLevel(uInt16 num)
{
   if((m_levels != NULL) && 
      (num < m_num_levels) )
   {
      m_pos_clevel = num;
      m_change_level = true;
      return 0;
   }

   return 1;
}


// wrapper of current level functions
int cLevelMngr::LevelInit()
{
   if(m_clevel != NULL)
      return m_clevel->Init();

   return 1000;
}

int cLevelMngr::LevelExit()
{
   if(m_clevel != NULL)
      return m_clevel->Exit();

   return 1000;
}


int cLevelMngr::LevelLoop()
{
   if( (m_clevel != NULL) && (!m_change_level) )
      return m_clevel->Loop();

   return 1000;
}

int cLevelMngr::LevelDraw()
{
   if( (m_clevel != NULL) && (!m_change_level) )
      return m_clevel->Draw();

   return 1000;
}

int cLevelMngr::LevelSound()
{
   if( (m_clevel != NULL) && (!m_change_level) )
      return m_clevel->Sound();

   return 1000;
}

