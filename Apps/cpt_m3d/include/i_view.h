//////////////////////////////////////////////////////////////////////////////
// Program Name:	i_view.h
// Programmer:		Joseph E. Sutton
// Description:	View Interface
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __IVIEW__
#define __IVIEW__

#include "i_env_data.h"
#include "i_vehicle_data.h"

class iView {
   public:	   
      virtual void Init()    = 0;
      virtual void Loop()    = 0;
      virtual void Display() = 0;
      virtual void Refresh() = 0;
      virtual void WindowResized(int w, int h) = 0;
      
      virtual void SetEnvData(iEnvData *edata) = 0;
      virtual void SetVehicleData(iVehicleData *vdata) = 0;
};

#endif // __IVIEW__