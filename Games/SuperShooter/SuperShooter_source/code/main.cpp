//////////////////////////////////////////////////////////////////////////////
// Program Name:  main.cpp
// Programmer:    Joseph E. Sutton
// Description:	Super Shooter - Game
// Course:        cs371
// Start Date:    10/15/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "sds.h"

SuperShooter *sds = NULL;
HWND main_hwnd;
DWORD ct, st;

void display(void);
void idle(void);
void keyboard_down(unsigned char key, int x, int y);
void special_down(int key, int x, int y);
void special_up(int key, int x, int y);
void mouse_click(int button, int state, int x, int y);
void mouse_motion(int x, int y);
void mouse_passive(int x, int y);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(MAX_WIDTH, MAX_HEIGHT);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Joseph E. Sutton - Super Dooper Shooter OpenGL Game");
   main_hwnd = FindWindow(NULL, "Joseph E. Sutton - Super Dooper Shooter OpenGL Game");
	//glutFullScreen();

	glutDisplayFunc(display);

   float l, r, b, t;
   l = 0.5;
   r = ((float)MAX_WIDTH) - 0.5;
   b = 0.5;
   t = ((float)MAX_HEIGHT) - 0.5;
   
	gluOrtho2D(l, r, b, t);

   glutDisplayFunc(display);
	glutIdleFunc(idle);

	glutKeyboardFunc(keyboard_down);
   glutSpecialFunc(special_down);
   //glutSpecialUpFunc(special_up);

   glutMouseFunc(mouse_click);
   glutMotionFunc(mouse_motion);
   glutPassiveMotionFunc(mouse_passive);
   
   st = ct = GetTickCount();
   sds = new SuperShooter();
   sds->Init();
   
	glutMainLoop();

   if( sds != NULL) delete sds;
	return 0;
}


void display(void)
{
   if(sds != NULL)
   {
	   glClearColor(0.0,0.0,0.0, 0.0); // black
	   glClear(GL_COLOR_BUFFER_BIT);

      sds->Draw();
      
      glFlush();
      glutSwapBuffers();
   }
}


void idle(void)
{
   if(sds != NULL)
   {
      ct = GetTickCount();
      if(ct - st > 33)
      {
         st = ct;
         sds->Idle();
         display();
      }
   }
}


void keyboard_down(unsigned char key, int x, int y)
{
   if( key == 27 )
   {
      //if( sds != NULL) delete sds;
      exit(1); // ESC
   }

   if(sds != NULL)
   {
      if( key == '0' )
      {
         sds->SetLevelNum(0);
      }
      else if( key == '1' )
      {
         sds->SetLevelNum(1);
      }
      else if( key == '2' )
      {
         sds->SetLevelNum(2);
      }
      else if( key == '3' )
      {
         sds->SetLevelNum(3);
      }
      else if( key == '4' )
      {
         sds->SetLevelNum(4);
      }
      else
         sds->KeyPressed(true, false, key, x, y);      
   }
}

void special_down(int key, int x, int y)
{
   if(sds != NULL)
   {
      sds->KeyPressed(true, true, key, x, y);
   }
}

void special_up(int key, int x, int y)
{
   if(sds != NULL)
   {
      sds->KeyPressed(false, true, key, x, y); 
   }
}

void mouse_click(int button, int state, int x, int y)
{
   if(sds != NULL)
   {
      bool down = false;
      if(state == GLUT_DOWN) down = true;

      sds->MouseClick(down, button, x, y); 
   }
}

void mouse_motion(int x, int y)
{
   if(sds != NULL)
   {
      sds->MouseMoved(x, y); 
   }
}

void mouse_passive(int x, int y)
{
   if(sds != NULL)
   {
      sds->MouseMoved(x, y); 
   }
}

void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
   if(idEvent == IDT_MIDI)
   {
      sds->PlayMusic();
   }
}