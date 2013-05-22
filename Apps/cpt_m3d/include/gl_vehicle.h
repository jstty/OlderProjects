//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_vehicle.h
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Vehicle Class
// Start Date:		2/13/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __GL_VEHICLE__
#define __GL_VEHICLE__

#include <list>
using namespace std;

#include "types_structs.h"
#include "gl_color.h"
#include "i_vehicle_data.h"

// start class
class GlVehicle
{
	protected:
      uInt32 i, j;
      Point3D p;
      uInt32 mMaxPoints;
      GlColor mColor;
      float x_max, y_max, z_max;
      double mLoopCount, mLoopSkip;
      
      list< list<Point3D> * > mList;
      list< list<Point3D> * >::iterator mListIt;
      list<Point3D>::iterator mPoint3DIt;
      
      // DON'T DELETE!
      iVehicleData *vd;

   public:
      GlVehicle();
      ~GlVehicle();
      
      void Init();
      void Loop();
      void Display();

      void SetMax(Point3D m);
      
      void SetVehicleData(iVehicleData *vdata);
};
// end class

#endif // END __GL_VEHICLE__
