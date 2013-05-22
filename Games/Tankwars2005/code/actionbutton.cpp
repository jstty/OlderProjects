//////////////////////////////////////////////////////////////////////////////
// Program Name:  actionbutton.cpp
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/8/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "tankwars2005.h"
extern cTankWars2005 *tws2005;


cActionButton::~cActionButton()
{
   if(img_file[0] != NULL) delete [] img_file[0];
   if(img_file[1] != NULL) delete [] img_file[1];
   if(img_file[2] != NULL) delete [] img_file[2];
}

//////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////
cActionButton::cActionButton(cGame *pownergame, const char name[]) : cCritter(pownergame)
{
   char file[255];
   strcpy(file, name);

   img_file[0] = new char[255];
   img_file[1] = new char[255];
   img_file[2] = new char[255];

   sprintf(img_file[0], "pics\\%s_d.bmp", file);   // default
   sprintf(img_file[1], "pics\\%s_o.bmp", file);   // over
   sprintf(img_file[2], "pics\\%s_c.bmp", file);   // clicked

   current_state = 1;
   OnDefault();
}


void cActionButton::CheckUpdate(float x, float y, bool clicked)
{
   cRealBox rb = realBox();
   if( rb.inside( cVector(x, y) ) )
   {
      if(clicked)
			OnClicked();
      else
			OnOver();
   }
   else
		OnDefault();
}

bool cActionButton::IsClicked()
{
	if( current_state == 2)	return true;
	else				      	return false;
}

void cActionButton::OnDefault()
{
   if(current_state != 0)
   {
      tws2005->SetCursor(CURSOR_CROSS);

      current_state = 0;
      img = new cSpriteIcon((int)(img_file[0]), false, true);   // default
      img->setSize(1, 1);
      setSprite(img);
   }
}

void cActionButton::OnOver()
{
   if(current_state != 1)
   {
      tws2005->SetCursor(CURSOR_ZAP);

      current_state = 1;
      img = new cSpriteIcon((int)(img_file[1]), false, true);   // over
      img->setSize(1, 1);
      setSprite(img);
   }
}

void cActionButton::OnClicked()
{
   if(current_state != 2)
   {
      tws2005->SetCursor(CURSOR_CROSS);

      current_state = 2;
      img = new cSpriteIcon((int)(img_file[2]), false, true);   // clicked
      img->setSize(1, 1);
      setSprite(img);
   }
}