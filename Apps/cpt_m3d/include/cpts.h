//////////////////////////////////////////////////////////////////////////////
// Program Name:	cpts.h
// Programmer:		Joseph E. Sutton
// Description:	Chemical Plume Controller Main Class
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __CPTS__
#define __CPTS__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#include <time.h>

//
#include "types_structs.h"

//
#include "c_settings.h"
#include "c_cpts_settings.h"

// View
#include "gl.h"
#include "i_view.h"
#include "c_cpts_gl_view.h"

// Environment
#include "i_env.h"
#include "c_cpts_env.h"

#include "i_env_data.h"
#include "c_cpts_env_data.h"


// Vehicle
#include "i_vehicle.h"
#include "c_cpts_vehicle.h"

#include "i_vehicle_data.h"
//#include "c_cpts_vehicle_data.h"


// start class
class CPTS
{
	protected:
      //
      double loop_time_start, loop_time_end, loop_fps;
      uInt32 loop_frame_count;
      double display_time_start, display_time_end, display_fps;
      uInt32 display_frame_count;
      
      float loop_rate, loop_step;
      float display_rate;
      bool paused;
      //

      //
      iView        *view;
      
      iEnv         *env;
      iEnvData     *env_data; // DON'T DELETE
      
      iVehicle     *veh;
      iVehicleData *veh_data; // DON'T DELETE
      //

      //
      Point3D cam;


      bool  Lmouse_pressed, Mmouse_pressed, Rmouse_pressed;
      float last_mouse_x, last_mouse_y;
      
      
      float cam_step;
      //

   public:
      CPTS();
      ~CPTS();

      void Init(const char *settings_filename = "settings.ini");
      void Loop();
      void Display();
      
      //void GetInfo(char *info);
      void UpdateCamVector(Point3D &c);

      void Keyboard(unsigned char key, int x, int y);
      void MouseMoved(int x, int y);
      void MousePressed(int button, int state, int x, int y);
      void WindowResized(int w, int h);

   protected:
      
      
};
// end class

#endif // END __CPTS__
