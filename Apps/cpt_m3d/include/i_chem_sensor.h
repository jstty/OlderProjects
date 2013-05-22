//////////////////////////////////////////////////////////////////////////////
// Program Name:	i_chem_sensor.h
// Programmer:		Joseph E. Sutton
// Description:	Chemical Sensor Interface
// Start Date:		5/7/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __ICHEM_SENSOR__
#define __ICHEM_SENSOR__

#include "types_structs.h"

class iChemSensor {
   public:	   
      virtual void Update() = 0;
   
      // returns the chemical density at a point
      virtual double GetChemDensity(Point3D inPoint) = 0;
      
      virtual uInt32 GetNumChemSensor() = 0;
      
      // returns 0 if ok, otherwise error
      virtual int StartChemSensorRead() = 0;
      // returns 0 if ok, otherwise at end
      // resets ChemPoint position
      virtual int GetNextChemSensor() = 0;
      
      // returns 0 if ok, otherwise error
      virtual int StartChemPointRead() = 0;
      // returns 0 if ok, otherwise at end
      virtual int GetNextChemPoint(Point3D &outPoint) = 0;
};

#endif // __ICHEM_SENSOR__
