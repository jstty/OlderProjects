//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_chemical_trail_manager.h
// Programmer:		Joseph E. Sutton
// Description:	Class to generate Manage a List of Dynamic Chemical Trail
// Start Date:		5/1/2008
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __CHEMICAL_TRAIL_MANAGER__
#define __CHEMICAL_TRAIL_MANAGER__

#include "i_chem_sensor.h"
#include "c_chemical_trail.h"

// start class
class ChemicalTrailManager : public iChemSensor
{
	protected:
      uInt32 i;
      Wind *mWind; // DON'T DELETE!
      
      ChemicalTrail *mList;
      uInt32 mSize;
      
      uInt32 cp_num;  // current Chemical Trail
      uInt32 cp_max;  // max number of points in trail
      uInt32 cp_cpos; // current point in trail

   public:
      ChemicalTrailManager(Wind *w, uInt32 numPlume);
      ~ChemicalTrailManager();
   
      // part or interface
      void Update();
      
      double GetChemDensity(Point3D inPoint);
      
      uInt32 GetNumChemSensor();
      
      int StartChemSensorRead();
      int GetNextChemSensor();
      
      int StartChemPointRead();
      int GetNextChemPoint(Point3D &outPoint);
      //

      void SetSettings(
         double  ddt,    // dt
         Point3D dsp,    // speed
         Point3D dsi,    // sigma
         uInt32  donps,  // odor_num_per_second
         double  dpl,    // plume_length
         double  dpgr,   // puffs_growth_rate
         double  dth     // threshold
      );

      void   AddPlume(uInt32 pnum, Point3D start);
};
// end class

#endif // END __CHEMICAL_TRAIL_MANAGER__
