//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_cpts_vehicle_data.h
// Programmer:		Joseph E. Sutton
// Description:	CPTS Vehicle Data Class
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __CPTS_VEHICLE_DATA__
#define __CPTS_VEHICLE_DATA__

#include <list>
using namespace std;

#include "i_vehicle_data.h"
#include "c_vehicle.h"

class CptsVehicleData : public iVehicleData {
   public:
      CptsVehicleData();
      ~CptsVehicleData();
      
      void SetEnvData(iEnvData *edata);
            
      void SetSettings(Point3D sl, double ddt, double dth, double r, double m);
      
      void AddVehicle(Point3D vl, Color color);
      
      
      uInt32 GetNumVehicle();
      
      // call first, resets the vehicle iteration
      // returns 0 if ok, otherwise error
      int StartVehicleRead();
      
      // moves to the next vehicle
      // returns 0 if ok, otherwise error
      int NextVehicle();
      
      // this is from the currently selected vehicle
      // call StartVehicleRead before calling these functions
         // a vector specifing the x, y, z point and direction
         void GetPosDir(Point3D &outPoint);
         const char *GetCurrentBehaviorName();
         
         //
         void Update();
         
         void GetColor(Color &c);
      
   private:
      list<Vehicle *> mList;
      list<Vehicle *>::iterator mIt;
      
      double  dt;
      Point3D vehloc;
      Point3D srcloc;
      double  threshold;
      double  radius;
      double  max_t;
      
      iEnvData *ed; // DON'T DELETE!
      Vehicle *v; // DON'T DELETE
      
};

#endif // __CPTS_VEHICLE_DATA__
