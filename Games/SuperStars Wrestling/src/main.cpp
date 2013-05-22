/* //////////////////////////////////////////////////////////////////////
 Program Name:  cSuperStars.h
 Programmer:    Joseph E. Sutton, Scott J. Brobst
 Design & Gfx:  Scott J. Brobst
 Start Date:    2006-06-14
 Updated:       
 Version:       1.00
 Description:
   Super Stars Main Source File
   
////////////////////////////////////////////////////////////////////// */

#define _MAIN_
#include "main.h"

void main(void)
{
   game = new cSuperStars();
   info = new cLevelInfo();

   game->Init();
   game->MainLoop();
   game->Exit();

   DELETE(info);
   DELETE(game);
}

//	Close Allegro
END_OF_MAIN();
