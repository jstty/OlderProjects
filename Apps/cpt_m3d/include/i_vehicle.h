//////////////////////////////////////////////////////////////////////////////
// Program Name:	i_vehicle.h
// Programmer:		Joseph E. Sutton
// Description:	Vehicle Interface
// Start Date:		5/8/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __IVEHICLE__
#define __IVEHICLE__

#include "i_vehicle_data.h"
#include "i_env_data.h"

class iVehicle {
   public:
      virtual void Init() = 0;
      virtual void Loop() = 0;

      // DON'T DELETE retrun variable
      virtual iVehicleData *GetData() = 0;
      
      virtual void SetEnvData(iEnvData *edata) = 0;
};

#endif // __IVEHICLE__
