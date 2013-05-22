//////////////////////////////////////////////////////////////////////////////
// Program Name:	i_vehicle_controller.h
// Programmer:		Joseph E. Sutton
// Description:	Vehicle Controller Interface
// Start Date:		5/14/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __IVEHICLE_CONTROLLER__
#define __IVEHICLE_CONTROLLER__

#include "types_structs.h"

class iVehicleController {
   public: 
      virtual void Init() = 0;

      virtual void MoveTo(Point3D p) = 0;
      virtual void GetRealPos(Point3D &p) = 0;
};

#endif // __IVEHICLE_CONTROLLER__
