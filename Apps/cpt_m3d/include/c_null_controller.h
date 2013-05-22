//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_null_controller.h
// Programmer:		Joseph E. Sutton
// Description:	Vehicle Null Controller Class
// Start Date:		5/14/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __NULL_CONTROLLER__
#define __NULL_CONTROLLER__

#include "i_vehicle_controller.h"

class nullController : public iVehicleController {
   public:
      void Init(){ }

      void MoveTo(Point3D p){ }
      void GetRealPos(Point3D &p){ }
};

#endif // __NULL_CONTROLLER__
