//////////////////////////////////////////////////////////////////////////////
// Program Name:  title_level.cpp
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/6/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "title_level.h"
#include "actionbutton.h"
#include "tankwars2005.h"

#include "cOptions.h"

extern cTankWars2005 *tws2005;

IMPLEMENT_SERIAL(cActionButton, cCritter, 0);

cTitleLevel::cTitleLevel()
{
	play = NULL;
	custom = NULL;
   options_active = false;
}

cTitleLevel::~cTitleLevel()
{}

void cTitleLevel::Exit()
{
   //play = NULL;
   //custom = NULL;
   DeleteCritterType( RUNTIME_CLASS(cActionButton) );
}

//////////////////////////////////////////////
// Init
//////////////////////////////////////////////
void cTitleLevel::Init()
{
   // Create opject
   // background test
   SetBkgImg("pics\\title.bmp");

   // music test
   SetMusic("music\\title.mid");

   // create default player and hide it
   tws2005->setPlayer(new cCritterArmed(), false);

   //
   play = new cActionButton(tws2005, "play");
   play->moveTo(cVector(-5, -2.0), false);

   custom = new cActionButton(tws2005, "custom");
   custom->moveTo(cVector(5, -2.0), false);
   //

   // Start up
   PlayMusic();
}

//////////////////////////////////////////////
// Timer Loop
//////////////////////////////////////////////
void cTitleLevel::Loop()
{
	if(play != NULL)
   {
		if( play->IsClicked() )
			 NextLevel();
   }

	if(custom != NULL)
   {
		if( custom->IsClicked() )
      {
         if(options_active == false)
         {
            options_active = true;
            cOptions o;
			   o.DoModal();
            options_active = false;
         }
      }
   }
}

void cTitleLevel::KeyPressed(int key, int flag)
{
   // flag == 0 -> no shift
   // flag == 4 -> shift
   if( (flag == 0) || (flag == 4) ) 
   {
      if( (key == 80) || // p - play
          (key == 32) || // spacebar
          (key == 13)    // enter
         )
      {
         NextLevel();
      }
      else if( (key == 67) || // c -> custom/options
               (key == 79) )  // o -> options/custom
      {
			if(options_active == false)
         {
            options_active = true;
            cOptions o;
			   o.DoModal();
            options_active = false;
         }
      }
   }
}

void cTitleLevel::MouseClick(int button, int state, float x, float y)
{
   if(play != NULL)
      play->CheckUpdate(x, y, true);

   if(custom != NULL)
      custom->CheckUpdate(x, y, true);
}

void cTitleLevel::MouseMoved(float x, float y)
{
   if(play != NULL)
      play->CheckUpdate(x, y);

   if(custom != NULL)
      custom->CheckUpdate(x, y);
}

