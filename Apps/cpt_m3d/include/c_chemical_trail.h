//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_chemical_trail.h
// Programmer:		Joseph E. Sutton
// Description:	Class to generate Dynamic Chemical Trail
// Start Date:		2/8/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __CHEMICAL_TRAIL__
#define __CHEMICAL_TRAIL__

#define MAX_CHEM_POINTS 1500 // size of puff structure

// start class
class ChemicalTrail
{
	protected:
	   Point3D *mChem;
	   uInt32   mCount;
	   int Count;
	   Point3D start;

      double   mChemMaxY, mChemMinY;

      double    mQQ;
      double    mMaxDensity;

      Wind *wind; // DON'T DELETE!
       
      // Settings
      double  dt;
      Point3D speed;
      Point3D sigma;
      uInt32  odor_num_per_second;
      double  plume_length;
      double  puffs_growth_rate;
      double  threshold;

   public:
      ChemicalTrail();
      ~ChemicalTrail();
      
      void SetSettings(
         double  ddt,    // dt
         Point3D dsp,    // speed
         Point3D dsi,    // sigma
         uInt32  donps,  // odor_num_per_second
         double  dpl,    // plume_length
         double  dpgr,   // puffs_growth_rate
         double  dth     // threshold
      );

      void Init(Wind *w, Point3D start);
      void Update();

      void GetPoint(int i, Point3D &p);
      uInt32  GetMax();

      double CalcDensity(double x,  double y,  double z);
      
      // fix
      //double ReadConc(double *pos, double *vel, double *ux_grid = NULL, double *uy_grid = NULL);

   protected:
      void DeletePoint(int i);
      void InitOdorRelease(int i);

      double Boundary(double t);
};
// end class

#endif // END __CHEMICAL_TRAIL__

