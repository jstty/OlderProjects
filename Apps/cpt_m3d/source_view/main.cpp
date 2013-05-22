//////////////////////////////////////////////////////////////////////////////
// File Name:		main.cpp
// Programmer:		Joseph E. Sutton
// Description:	start main
// Course:			cs490
// Start Date:		1/23/2007
// Last Updated:	
// Version:			1.00
// Details:       
//////////////////////////////////////////////////////////////////////////////

void reset(void);

void display();
void keyboard(unsigned char key, int x, int y);
void mouse_move(int x, int y);
void mouse_press(int button, int state, int x, int y);
void reshape(int width, int height);
void idle();

#include "../include/cpts.h"
CPTS *cpts = NULL;
CptsSettings *settings = NULL;

int main(int argc, char *argv[])
{
   glutInit(&argc, argv);

   cpts = new CPTS();
   cpts->Init();

   //
   glutDisplayFunc( display );
   glutKeyboardFunc( keyboard );
   glutMotionFunc( mouse_move );
   glutPassiveMotionFunc( mouse_move );
   glutMouseFunc( mouse_press );
   glutReshapeFunc( reshape );
   glutIdleFunc( idle );

   //
   glutMainLoop();

   // clean up
   delete cpts;

   return 0;
}


void display()
{
   cpts->Display();
}

void idle()
{
   cpts->Loop();
}

void keyboard(unsigned char key, int x, int y)
{
   cpts->Keyboard(key, x, y);
}

void mouse_move(int x, int y)
{
   cpts->MouseMoved(x, y);
}

void mouse_press(int button, int state, int x, int y)
{
   cpts->MousePressed(button, state, x, y);
}

void reshape(int width, int height)
{
   cpts->WindowResized(width, height);
}


