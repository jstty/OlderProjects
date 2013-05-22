//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_cpst_settings.h
// Programmer:		Joseph E. Sutton
// Description:	Class to read/write settings
// Start Date:		2/27/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __CPTS_SETTINGS__
#define __CPTS_SETTINGS__

#include "types_structs.h"
#include "c_settings.h"

typedef struct _CptsSettingsColor
{
   double top_bkg[3];
   double main_bkg[3];
   double right_bkg[3];

   double grid_front[3];
   double grid_mid[3];
   double grid_back[3];

   double chem[3];
   double wind[3];

   double text[3];
} CptsSettingsColor;


// start class
class CptsSettings
{
	public:
      Point3D speed;
      Point3D sigma;

      uInt32 strategy;
      uInt32 n_itt;
      double max_t;

      uInt32 WN, WM;

      uInt32  num_plume;
      Point3D *plume_loc;
      //Point3D src_loc;

      double dt;

      //
      uInt32 odor_num_per_second;
      double puffs_growth_rate;
      double plume_length, threshold;


      // wind
      double wind_bandwidth, wind_damping, wind_gain;
      double wind_spectral_density;

      // view
      CptsSettingsColor color;

      double radius; // declaration of found source radius

      Point3D max;
      
      
      // loop rate
      double loop_rate, loop_step;
      double display_rate;
      
      // 
      uInt32  num_veh;
      Point3D *veh_loc;
      Color   *veh_color;

   public:
       CptsSettings();
      ~CptsSettings();

      void SetDefault();

      // if(return > 0) error
      // else           ok
      int Load(const char *filename);
      
      int IsLoaded();

   protected:
      Settings *s;
      
      int loaded;
   
};
// end class

#endif // END __CPTS_SETTINGS__

