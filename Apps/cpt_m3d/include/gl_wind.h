//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_wind.h
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Wind Class
// Start Date:		2/13/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __GL_WIND__
#define __GL_WIND__

#include "types_structs.h"
#include "i_env_data.h"

// start class
class GlWind
{
	protected:
		iEnvData *ed; // DON'T DELETE
		uInt32 x, y, x_max, y_max, z_max;
		Point3D dir, p;
		float color[3];

   public:
      void Init();
      void Loop();
      void Display();
      
      void SetEnvData(iEnvData *edata);
      
      void SetMax(Point3D m);
      void SetColor(double c[3]);

};
// end class

#endif // END __GL_WIND__