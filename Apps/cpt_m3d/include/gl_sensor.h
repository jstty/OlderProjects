//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_sensor.h
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Sensor Class
// Start Date:		5/9/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __GL_SENSOR__
#define __GL_SENSOR__

#include <list>
using namespace std;

#include "gl_color.h"
#include "gl_text.h"
#include "types_structs.h"

#include "i_env_data.h"
#include "i_vehicle_data.h"

// start class
class GlSensor
{
	protected:
      uInt32 i, j;
      Point3D p;
      uInt32 offset_x, offset_y, padding_x, padding_y;
      uInt8 grid_nrows, grid_ncols;
      GlColor mColor;
      uInt32 width, height;
      double mChemDensity, mMaxChemDensity;
      
      GlText text;
      char xaxis_str[256];
      char yaxis_str[64];
      char time_str[64];
      
      list< list<double> * > mList;
      list< list<double> * >::iterator mListIt;
      list<double>::iterator mDoubleIt;

      uInt32 mMaxPoints;
      double mStep;
      
      double time_rate;
      
      iEnvData *ed;     // DON'T DELETE!
      iVehicleData *vd; // DON'T DELETE!
      
      double time_start, time_end;
      
      void UpdateMaxChemDensity();
      
   public:
      GlSensor();
      ~GlSensor();

      void Init();
      void Loop();
      void Display();
      
      void SetTimeRate(double rate);
      
      void SetColor(double c[3]);
      void SetSize(uInt32 w, uInt32 h);
      
      void SetEnvData(iEnvData *edata);
      void SetVehicleData(iVehicleData *vdata);
};
// end class

#endif // END __GL_SENSOR__
