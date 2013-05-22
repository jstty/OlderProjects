//////////////////////////////////////////////////////////////////////////////
// Program Name:  level.h
// Programmer:    Joseph E. Sutton
// Description:	Super Shooter - Game
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _LEVEL_
#define _LEVEL_

#include "main.h"

class Level
{
public:
   Level() { }
   ~Level() { }
   
   virtual void Init(uInt32 data = 0) { lScore = 0; level_over = false; }
   virtual void Exit(uInt32 data = 0) { }
   virtual void Draw() { }
   virtual void Idle() { }
   virtual void KeyPressed(bool down, bool skey, int key, int x, int y) { }
   virtual void MouseClick(bool down, int button, int x, int y) { }
   virtual void MouseMoved(int x, int y) { }

   virtual void PlayMusic() { }
   virtual void StopMusic() { }

   virtual bool isLevelOver() { return level_over; }
   virtual uInt32 GetScore() { return lScore; }

protected:
   bool level_over;
   uInt32 lScore;

};


#endif