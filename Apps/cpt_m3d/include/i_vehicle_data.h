//////////////////////////////////////////////////////////////////////////////
// Program Name:	i_vehicle_data.h
// Programmer:		Joseph E. Sutton
// Description:	Vehicle Data Interface
// Start Date:		5/8/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __IVEHICLE_DATA__
#define __IVEHICLE_DATA__

#include "types_structs.h"

class iVehicleData {
   public:
      
      virtual uInt32 GetNumVehicle() = 0;
   
      // call first, resets the vehicle iteration
      // returns 0 if ok, otherwise error
      virtual int StartVehicleRead() = 0;
      
      // moves to the next vehicle
      // returns 0 if ok, otherwise error
      virtual int NextVehicle() = 0;
      
      // this is from the currently selected vehicle
      // call StartVehicleRead before calling these functions
         // a vector specifing the x, y, z point and direction
         virtual void GetPosDir(Point3D &outPoint) = 0;
         virtual const char *GetCurrentBehaviorName() = 0;
         
         //
         virtual void Update() = 0;
         
         virtual void GetColor(Color &c) = 0;
};

#endif // __IVEHICLE_DATA__
