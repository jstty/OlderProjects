//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_cpts_env_data.h
// Programmer:		Joseph E. Sutton
// Description:	CPTS Environment Data Class
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __CPTS_ENV_DATA__
#define __CPTS_ENV_DATA__

#include "i_env.h"
#include "i_env_data.h"
#include "c_wind.h"
#include "i_chem_sensor.h"

class CptsEnvData : public iEnvData {
   public:
      CptsEnvData();
      ~CptsEnvData();
      
      void SetWind(Wind *wind);
      void SetSensor(iChemSensor *sensor);
      void SetEnv(iEnv *env);
      
            
      // get the wind direction vector at a point
      void GetWindDir(Point3D &outDir, Point3D inPoint);
      
      // applies the wind to a point
      void ApplyWind(Point3D inPoint, double object[3]);
      
      
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
      
      double GetSimTime();
      
   protected:
      iEnv *e;        // DON'T DELETE!
      iChemSensor *s; // DON'T DELETE!
      Wind *w;        // DON'T DELETE!
};

#endif // __CPTS_ENV_DATA__
