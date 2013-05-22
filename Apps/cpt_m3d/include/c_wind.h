//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_wind.h
// Programmer:		Joseph E. Sutton
// Description:	Class to generate Dynamic Wind
// Start Date:		2/27/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __WIND__
#define __WIND__

#include "types_structs.h"
#include "env_def.h"

// start class
class Wind
{
	protected:
      int first;

      double mUxGrid[MAX_NODE_X][MAX_NODE_Y],
             mUyGrid[MAX_NODE_X][MAX_NODE_Y],
             mUzGrid[MAX_NODE_X][MAX_NODE_Y];

      double mDeltaX, mDeltaY, mDeltaZ;
      int samplesZ;

      double wind_dir;
      
      // settings
      double speed_x, speed_y;
      double dt;
      double damping, bandwidth, gain;

   public:
      Wind();
      
      // speed.x, speed.y, dt, wind_damping, wind_bandwidth, wind_gain
      void SetSettings(double ssx, double ssy, double sdt, double sd, double sb, double sg);

      void UpdateZ();
      void Update();
      void Apply(double x, double y, 
                 double *u, 
                 double *ux_grid = NULL, double *uy_grid = NULL);

      void GetDir(Point3D &dir, Point3D p);

   protected:
      double colored_noise(double *x,double dt);

};
// end class

#endif // END __WIND__

