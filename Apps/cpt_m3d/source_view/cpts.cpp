//////////////////////////////////////////////////////////////////////////////
// Program Name:	cpts.cpp
// Programmer:		Joseph E. Sutton
// Description:	Chemical Plume Controller Main Class
// Start Date:		2/8/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/cpts.h"

#define DLL_TYPE __declspec(dllimport)
#include "../include/cpts_env_dll.h"
#include "../include/cpts_veh_dll.h"

extern CptsSettings *settings;

CPTS::CPTS()
{
   char file[256];

   // seed random!
   srand( time(NULL) );

   strcpy(file, "settings.ini");
   
   //
   cam.x = 0.0;
   cam.y = 0.0;
   cam_step = 2.0;
   cam.xrot = 360;
   cam.yrot = 360;
   
   last_mouse_x  = -1;
   last_mouse_y  = -1;
   Lmouse_pressed = false;
   Rmouse_pressed = false;
   
   paused = false;
   
   settings = new CptsSettings();
   if( settings->Load(file) )
   {
      printf("* ERROR - Loading Settings File: \"%s\"\n\n", file);
      exit(0);
   }
   
   loop_rate = settings->loop_rate;
   loop_step = settings->loop_step;
   
   display_rate = settings->display_rate;
}

CPTS::~CPTS()
{
   if(settings != NULL) delete settings;

   if(view != NULL) delete view;
   
   //if(env != NULL)  delete env;
   cptsEnvFree();

   //if(veh != NULL)  delete veh;
   cptsVehFree();
}

void CPTS::Init(const char *settings_filename)
{
   //env = new CptsEnv();
   //env->Init();
   env = cptsEnvInit(settings); // loaded from DLL

   //veh = new CptsVehicle();
   //veh->Init();
   veh = cptsVehInit(settings); // loaded from DLL
      
   // connect view to environment
   env_data = env->GetData();
   veh_data = veh->GetData();
 
   veh->SetEnvData( env_data );
 
   //
   view = new CptsGlView();
   view->Init();
     
   view->SetEnvData( env_data );
   view->SetVehicleData( veh_data );
   
   //
   loop_time_start = getHiResTime();
   loop_frame_count = 0;
   loop_fps = 0.0;
   
   display_time_start = getHiResTime();
   display_frame_count = 0;
   display_fps = 0.0;

   cam.z = 0;
}


void CPTS::Loop()
{
   loop_frame_count++;
   loop_time_end = getHiResTime();
   if( (loop_time_end - loop_time_start >= loop_rate) &&
       (!paused)
      )
   {
      loop_fps = 0.100*(float)loop_frame_count/(float)(loop_time_end - loop_time_start);
      loop_frame_count = 0;
      //

      env->Loop();
      veh->Loop();
      view->Loop();

      //
      loop_time_start = getHiResTime();
   }
}


void CPTS::Display(void)
{
   display_frame_count++;
   display_time_end = getHiResTime();
   if(display_time_end - display_time_start >= display_rate)
   {
      display_fps = 0.100*(float)display_frame_count/(float)(display_time_end - display_time_start);
      display_frame_count = 0;
      //
      
      view->Display();
      
      //
      display_time_start = getHiResTime();
   } else {
      view->Refresh();
   }
}

/*
void CPTS::GetInfo(char *info)
{
   Point3D p, d;
   p.x = 0; p.y = 0; p.z = 0;
   env_data->GetWindDir(d, p);
   veh_data->GetPosDir(p);
   
   if(paused)
   {
      sprintf(info, "veh(x %0.3f, y %0.3f, z %0.3f, h %0.3f) loop rate(%0.4f) behavior(%s) !!!PAUSED!!!", 
         p.x, p.y, p.z, p.heading,
         loop_rate,
         veh_data->GetCurrentBehaviorName());
   }
   else
   {
      sprintf(info, "veh(x %0.3f, y %0.3f, z %0.3f, h %0.3f) loop rate(%0.4f) behavior(%s)", 
         p.x, p.y, p.z, p.heading,
         loop_rate,
         veh_data->GetCurrentBehaviorName());
   }
}
*/

void CPTS::UpdateCamVector(Point3D &c)
{
   c = cam;
}


void CPTS::Keyboard(unsigned char key, int x, int y)
{
   switch (key) 
	{
      // move
      case 'a':
		   cam.x += cam_step;
		   break;
	   case 'd':
         cam.x -= cam_step;
		   break;
	   case 'w':
         cam.y -= cam_step;
		   break;
      case 's':
         cam.y += cam_step;
		   break;
         
      case '=':
         cam.z += 10;
         break;

      case '-':
         cam.z -= 10;
         break;
      
      case ' ':
         paused = paused ? false : true;
         break;
      
      // speed up
      case '.':
         if(loop_rate - loop_step >= 0)
         {
            loop_rate -= loop_step;
         }
		   break;
      // slow down
      case ',':
         loop_rate += loop_step;
		   break;

      case GLUT_KEY_ESC:
         exit(0);
	}

   view->Refresh();
}



void CPTS::MouseMoved(int x, int y)
{
   if(Lmouse_pressed)
   {
      // rotate
      if(last_mouse_x == -1) last_mouse_x = x;
      if(last_mouse_y == -1) last_mouse_y = y;

      cam.xrot += (-y + last_mouse_y)/5.0;
      cam.yrot += (-x + last_mouse_x)/5.0;

           if(cam.xrot < 0)   cam.xrot = 360;
      else if(cam.xrot > 360) cam.xrot = 0;

           if(cam.yrot < 0)   cam.yrot = 360;
      else if(cam.yrot > 360) cam.yrot = 0;
   }
   
   if(Rmouse_pressed)
   {
      // move
      if(last_mouse_x == -1) last_mouse_x = x;
      if(last_mouse_y == -1) last_mouse_y = y;

      cam.x -= (-x + last_mouse_x)/5.0;
      cam.y += (-y + last_mouse_y)/5.0;
   }
   
   if(Mmouse_pressed)
   {
      // zoom
      if(last_mouse_x == -1) last_mouse_x = x;
      if(last_mouse_y == -1) last_mouse_y = y;

      cam.z += (-y + last_mouse_y)/5.0;

           if(cam.z < 0)   cam.z = 0;
      else if(cam.z > 180) cam.z = 180;
   }


   last_mouse_x = x;
   last_mouse_y = y;
}

void CPTS::MousePressed(int button, int state, int x, int y)
{  
   Lmouse_pressed = false;
   Mmouse_pressed = false;
   Rmouse_pressed = false;

   switch(button)
   {
      case GLUT_LEFT_BUTTON: // left button
         if(state == 0)
         {
            Lmouse_pressed = true;
         }
         break;

      case GLUT_MIDDLE_BUTTON: // middle button
         if(state == 0)
         {
            Mmouse_pressed = true;
         }
         break;

      case GLUT_RIGHT_BUTTON: // right button
         if(state == 0)
         {
            Rmouse_pressed = true;
         }
         break;

      case GLUT_WHEEL_UP: // wheel up
         cam.z += 10;
         break;

      case GLUT_WHEEL_DOWN: // wheel down
         cam.z -= 10;
         break;
   }

   if(cam.z < 0)  cam.z = 0;
}

void CPTS::WindowResized(int w, int h)
{
   view->WindowResized(w, h);
}

