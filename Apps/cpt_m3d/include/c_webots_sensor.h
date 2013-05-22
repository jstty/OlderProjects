//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_webots_sensor.h
// Programmer:		Joseph E. Sutton
// Description:	Webots Sensor Class
// Start Date:		5/14/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __WEBOTS_SENSOR__
#define __WEBOTS_SENSOR__

#include "i_chem_sensor.h"

class webotsSensor : public iChemSensor {
   public:
      void Update();
   
      // returns the chemical density at a point
      double GetChemDensity(Point3D inPoint);
      
      uInt32 GetNumChemSensor();
      
      // returns 0 if ok, otherwise error
      int StartChemSensorRead();
      // returns 0 if ok, otherwise at end
      // resets ChemPoint position
      int GetNextChemSensor();
      
      // returns 0 if ok, otherwise error
      int StartChemPointRead();
      // returns 0 if ok, otherwise at end
      int GetNextChemPoint(Point3D &outPoint);
};

#endif // __WEBOTS_SENSOR__
