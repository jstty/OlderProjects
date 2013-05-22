//////////////////////////////////////////////////////////////////////////////
// Program Name:  levelselector.cpp
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/6/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "levelselector.h"
#include "tankwars2005.h"
extern cTankWars2005 *tws2005;

enum { LEVEL_INIT, LEVEL_LOADING, LEVEL_LOOP, LEVEL_EXIT };

cLevelSelector::cLevelSelector()
{
   current_state = LEVEL_LOOP;
   current_num = 0;
   current_level = NULL;
}

cLevelSelector::~cLevelSelector()
{
   for(int i = 0; i < level_list.size(); i++)
   {
      delete level_list.retrieve(i);
   }
}


//////////////////////////////////////////////
// Level
//////////////////////////////////////////////
unsigned char cLevelSelector::AddLevel(cLevel *nl)
{
   if(nl != NULL)
   {
      level_list.insert(level_list.size(), nl);
      nl->SetParent(this);
   }

   return level_list.size() - 1;

}

void cLevelSelector::SelectLevel(unsigned char num)
{
   if(current_state == LEVEL_LOOP)
   {
      current_state = LEVEL_EXIT;
      // end current level
      if(current_level != NULL)
      {
         current_level->Exit();
         current_level->FreeGfx();
      }

      current_state = LEVEL_INIT;
      current_num = num;
      current_level = level_list.retrieve(num);

      Init();
   }
}

void cLevelSelector::NextLevel()
{
   SelectLevel(++current_num);
}

void cLevelSelector::PrevLevel()
{
   if(current_num > 0)
   {
      SelectLevel(--current_num);
   }
}

void cLevelSelector::FirstLevel()
{
   SelectLevel(0);
}

void cLevelSelector::LastLevel()
{
   SelectLevel(level_list.size() - 1);
}

//////////////////////////////////////////////
// Init
//////////////////////////////////////////////
void cLevelSelector::Init()
{
   if( (current_level != NULL) && (current_state == LEVEL_INIT))
   {
      current_state = LEVEL_LOADING;
      current_level->Init();
      current_state = LEVEL_LOOP;
   }
}

//////////////////////////////////////////////
// Loop
//////////////////////////////////////////////
void cLevelSelector::Loop()
{
   if( (current_level != NULL) && (current_state == LEVEL_LOOP))
   {
      current_level->UpdateTimer();
      current_level->Loop();
   }
}


void cLevelSelector::KeyPressed(int key, int flag)
{
   if(current_level != NULL) current_level->KeyPressed(key, flag);
}

void cLevelSelector::KeyUp(int key, int flag)
{
   if(current_level != NULL) current_level->KeyUp(key, flag);
}

void cLevelSelector::MouseClick(int button, int state, float x, float y)
{
   if(current_level != NULL) current_level->MouseClick(button, state, x, y);
}

void cLevelSelector::MouseMoved(float x, float y)
{
   if(current_level != NULL) current_level->MouseMoved(x, y);
}

