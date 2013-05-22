//////////////////////////////////////////////////////////////////////////////
// Program Name:	i_env_data.h
// Programmer:		Joseph E. Sutton
// Description:	Environment Data Interface
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __IENV_DATA__
#define __IENV_DATA__

#include "types_structs.h"

class iEnvData {
   public:
      // get the wind direction vector at a point
      virtual void GetWindDir(Point3D &outDir, Point3D inPoint) = 0;
      
      // applies the wind to a point
      virtual void ApplyWind(Point3D inPoint, double object[3]) = 0;

      
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
   
      virtual double GetSimTime() = 0;
};

#endif // __IENV_DATA__
