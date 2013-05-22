//////////////////////////////////////////////////////////////////////////////
// Program Name:  end_level.cpp
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/6/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "title_level.h"
#include "cGameOver.h"

#include "tankwars2005.h"
#include "cOptions.h"

extern cTankWars2005 *tws2005;
extern cOptionsData *options_data;

cEndLevel::cEndLevel()
{
   play = NULL;
}

cEndLevel::~cEndLevel()
{}

void cEndLevel::Exit()
{
   DeleteCritterType( RUNTIME_CLASS(cActionButton) );
}

//////////////////////////////////////////////
// Init
//////////////////////////////////////////////
void cEndLevel::Init()
{
   // Create opject
   // background test
   SetBkgImg("pics\\end.bmp");

   // music test
   SetMusic("music\\end.mid");

   // create default player and hide it
   tws2005->setPlayer(new cCritterArmed(), false);

   play = new cActionButton(tws2005, "play_again");
   play->moveTo(cVector(0, -2.0), false);

   // Start up
   PlayMusic();

   show_game_over = true;
}

//////////////////////////////////////////////
// Timer Loop
//////////////////////////////////////////////
void cEndLevel::Loop()
{
   if(play != NULL)
   {
      // Game over Dlg Box
      if(show_game_over)
      {
         show_game_over = false;
         cGameOver go;
         go.DoModal();

         // reset both players weapon ammo
         options_data->SetPlayerDefault(0);
         options_data->SetPlayerDefault(1);
      }

		if( play->IsClicked() )
			 FirstLevel();
   }
}

void cEndLevel::KeyPressed(int key, int flag)
{
   // flag == 0 -> no shift
   // flag == 4 -> shift
   if( (flag == 0) || (flag == 4) ) 
   {
      if( (key == 32) || // spacebar
          (key == 13) || // enter
          (key == 82)    // r
         )
      {
         FirstLevel();
      }
   }
}

void cEndLevel::MouseClick(int button, int state, float x, float y)
{
   if(play != NULL)
      play->CheckUpdate(x, y, true);
}

void cEndLevel::MouseMoved(float x, float y)
{
   if(play != NULL)
      play->CheckUpdate(x, y);
}

