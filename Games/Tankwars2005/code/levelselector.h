//////////////////////////////////////////////////////////////////////////////
// Program Name:  levelselector.h
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/6/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _CLEVELSELECTOR_
#define _CLEVELSELECTOR_

#include "level.h"

class cLevelSelector
{
public:
   cLevelSelector();
   ~cLevelSelector();
   
   unsigned char AddLevel(cLevel *nl);
   void SelectLevel(unsigned char num);
   void NextLevel();
   void PrevLevel();
   void FirstLevel();
   void LastLevel();

   //////////////////////////////////////////////
   // Init
   //////////////////////////////////////////////
   virtual void Init();

   //////////////////////////////////////////////
   // Loop
   //////////////////////////////////////////////
   virtual void Loop();
   virtual void KeyPressed(int key, int flag);
   virtual void KeyUp(int key, int flag);
   virtual void MouseClick(int button, int state, float x, float y);
   virtual void MouseMoved(float x, float y);

 
protected:
   unsigned char current_num;
   unsigned char current_state;

   cLevel *current_level;
   List<cLevel *> level_list;
};


#endif