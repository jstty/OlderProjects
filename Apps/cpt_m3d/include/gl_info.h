//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_info.h
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Info Class
// Start Date:		5/29/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __GL_INFO__
#define __GL_INFO__

#include "types_structs.h"

#include "i_env_data.h"
#include "i_vehicle_data.h"

#include "gl_color.h"
#include "gl_text.h"

// start class
class GlInfo
{
	protected:
      uInt32 width, height;
      
      char info[256];
      GlText text;
      Point3D p;
      GlColor color;
      Color c;
                        
      iVehicleData *vd; // DO NOT DELETE
      iEnvData     *ed; // DO NOT DELETE
      
   public:
      GlInfo();
      ~GlInfo();

      void Init();
      void Loop();
      void Display();
      
      void SetSize(uInt32 w, uInt32 h);
            
      void SetEnvData(iEnvData *edata);
      void SetVehicleData(iVehicleData *vdata);
};
// end class

#endif // END __GL_SENSOR__
