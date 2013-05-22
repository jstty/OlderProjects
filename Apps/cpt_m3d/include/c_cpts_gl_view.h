//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_cpts_gl_view.h
// Programmer:		Joseph E. Sutton
// Description:	CPTS OpenGL View Class
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __CPTS_GL_VIEW__
#define __CPTS_GL_VIEW__

#include "i_view.h"
#include "gl_color.h"
#include "gl_text.h"

#include "gl_grid.h"
#include "gl_info.h"

// enviroment
#include "gl_wind.h"
#include "gl_plume.h"

// vehicle
#include "gl_vehicle.h"
#include "gl_sensor.h"

class CptsGlView : public iView {
   public:
      CptsGlView();
      ~CptsGlView();
   
      void Init();
      void Loop();
      void Display();
      void Refresh();
      void WindowResized(int w, int h);
      
      void SetEnvData(iEnvData *edata);
      void SetVehicleData(iVehicleData *vdata);
       
   private:
      iEnvData     *ed; // DON'T DELETE
      iVehicleData *vd; // DON'T DELETE
      
      uInt32 width, height;
      double mTopViewHeight, mRightViewWidth;
   
      //char info[256];
      //GlText *text;
      Point3D cam;
      
      //
      GlGrid    *g;
      GlInfo    *i;
      
      // enviroment
      GlWind    *w;
      GlPlume   *p;
      
      // vehicle
      GlVehicle *v;
      GlSensor  *s;
      
      void SetMainView();
      void SetTopView();
      void SetRightView();
};

#endif // __CPTS_GL_VIEW__