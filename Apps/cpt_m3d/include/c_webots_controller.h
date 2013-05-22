//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_webots_controller.h
// Programmer:		Joseph E. Sutton
// Description:	Vehicle Webots Controller Class
// Start Date:		5/14/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __WEBOTS_CONTROLLER__
#define __WEBOTS_CONTROLLER__

#include "i_vehicle_controller.h"

class webotsController : public iVehicleController {
   public:
      void Init();

      void MoveTo(Point3D p);
      void GetRealPos(Point3D &p);
};

#endif // __WEBOTS_CONTROLLER__
