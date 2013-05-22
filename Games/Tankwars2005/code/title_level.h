//////////////////////////////////////////////////////////////////////////////
// Program Name:  title_level.h
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/6/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _CTITLELEVEL_
#define _CTITLELEVEL_

#include "level.h"
#include "actionbutton.h"
#include "../pop/critterarmed.h"

class cTitleLevel : public cLevel
{
public:
   cTitleLevel();
   ~cTitleLevel();
   void Exit();

   //////////////////////////////////////////////
   // Init
   //////////////////////////////////////////////
   void Init();

   //////////////////////////////////////////////
   // Loop
   //////////////////////////////////////////////
   void Loop();
   void KeyPressed(int key, int flag);
   void MouseClick(int button, int state, float x, float y);
   void MouseMoved(float x, float y);
 
protected:
   cActionButton *play;
   cActionButton *custom;

   bool options_active;
};


#endif