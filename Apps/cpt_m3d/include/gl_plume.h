//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_plume.h
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Plume Class
// Start Date:		2/13/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __GL_PLUME__
#define __GL_PLUME__

#include "types_structs.h"
#include "gl_color.h"

#include "i_env_data.h"

// start class
class GlPlume
{
	protected:
      GlColor mColor;
      Point3D *mTrans;
      Point3D *mRot;
      
      float x_max, y_max, z_max;
      
      // DON'T DELETE!
      iEnvData *ed;

   public:
      GlPlume();
      ~GlPlume();
      
      void SetMax(Point3D m);

      void SetColor(double c[3]);
      void SetTranslate(int i, float x, float y, float z);
      void SetRotate(int i, float angle, float x, float y, float z);

      void Init();
      void Loop();
      void Display();
      
      void SetEnvData(iEnvData *edata);
};
// end class

#endif // END __GL_PLUME__
