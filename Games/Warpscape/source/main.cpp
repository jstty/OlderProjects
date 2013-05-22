//////////////////////////////////////////////////////////////////////////////
// Program Name:  main.cpp
// Programmer:    Joseph E. Sutton
// Description:	Super Shooter - Game
// Course:        cs371
// Start Date:    10/15/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#define _MAIN_
#include "global.h"

int main(int argc, char* argv[])
{
   game = new GameEngine();
   
   game->Init(argc, argv);
   game->Run();

   if( game != NULL) delete game;
	return 0;
}

// interface to global game engine varible
void display()
{
   if(game != NULL) game->Display();
}

void reshape(int w, int h)
{
   if(game != NULL) game->Resize(w, h);
}

void idle()
{
   if(game != NULL) game->Idle();
}

void key_down(unsigned char key, int x, int y)
{
   if(game != NULL) game->KeyDown(key, x, y);
}

void key_special_down(int key, int x, int y)
{
   if(game != NULL) game->KeySpecialDown(key, x, y);
}

void mouse_click(int button, int state, int x, int y)
{
   if(game != NULL) game->MouseClick(button, state, x, y);
}

void mouse_motion(int x, int y) 
{
   if(game != NULL) game->MouseMotion(x, y);
}

void mouse_passive(int x, int y)
{
   if(game != NULL) game->MousePassive(x, y);
}
