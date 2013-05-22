//////////////////////////////////////////////////////////////////////////////
// Program Name:  actionbutton.h
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/8/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _CACTIONBUTTON_
#define _CACTIONBUTTON_

#include "../pop/critter.h"
#include "../pop/spriteicon.h"

class cActionButton : public cCritter
{
DECLARE_SERIAL(cActionButton);
public:
	cActionButton(cGame *pownergame = NULL, const char name[] = "");
   ~cActionButton();

   void CheckUpdate(float x, float y, bool clicked = false);
   void OnDefault();
   void OnOver();
   void OnClicked();
   bool IsClicked();

   virtual BOOL draggable(){ return FALSE; }

protected:
   unsigned char current_state;
   char        *img_file[3];
   cSpriteIcon *img;
};

#endif