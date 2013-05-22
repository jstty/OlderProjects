//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_cpts_vehicle.h
// Programmer:		Joseph E. Sutton
// Description:	CPTS Vehicle Class
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __CPTS_VEHICLE__
#define __CPTS_VEHICLE__

#include "i_vehicle.h"
#include "i_vehicle_data.h"
#include "i_vehicle_controller.h"

#include "c_vehicle.h"
#include "c_cpts_vehicle_data.h"
#include "c_null_controller.h"

class CptsVehicle : public iVehicle {
   public:
      CptsVehicle();
      ~CptsVehicle();
   
      void Init();
      void Loop();
      
      iVehicleData *GetData();
      
      void SetEnvData(iEnvData *edata);
      
   private:
      Vehicle *v;
      CptsVehicleData *vd;
      
      iVehicleController *vc;
};

#endif // __CPTS_VEHICLE__
