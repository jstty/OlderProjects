//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_cpts_settings.cpp
// Programmer:		Joseph E. Sutton
// Description:	Class to read/write settings
// Start Date:		2/27/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/cpts.h"

// Constructor
CptsSettings::CptsSettings()
{
   loaded = 0;
   s = new Settings();
   
   SetDefault();
}


CptsSettings::~CptsSettings()
{
   delete s;
   
   delete [] plume_loc;
   
   delete [] veh_loc;
   delete [] veh_color;
}

int CptsSettings::IsLoaded()
{
   return loaded;
}

void CptsSettings::SetDefault()
{
   loaded = 0;
   
   loop_rate = 0.01;
   loop_step = 0.001;
   display_rate = 0.01;
   
   speed.x = 1.0;
   speed.y = 0.0;
   speed.z = 0.0;
   wind_spectral_density = 1.0;
   wind_bandwidth = 0.075000;
   wind_damping   = 0.10;
   wind_gain      = 8.00;
   sigma.x = 0.0;
   sigma.y = 2.0;
   sigma.z = 0.0;

   odor_num_per_second = 5;
   puffs_growth_rate   = 0.001;
   
   WN = 6;
   WM = 10;
   
   strategy = 3;

   num_plume = 0;
   plume_loc = NULL;
   /*
   src_loc.x = 20.0;
   src_loc.y = 0.0;
   src_loc.z = 5.0;
    */
   
   plume_length = 600.0;	 // meters
   threshold =  0.0007;    // units of million molecules per cm^3

   n_itt = 100;
   max_t = 100;

   radius = 1.0;
   
   dt = 0.01;
   max.x = 100.0;
   max.y = 100.0;
   max.z = 10.0;
   
   num_veh = 0;
   veh_loc = NULL;
   veh_color = NULL;
   
   color.top_bkg[0] = color.top_bkg[1] = color.top_bkg[2] = 1;
   color.main_bkg[0] = color.main_bkg[1] = color.main_bkg[2] = 1;
   color.right_bkg[0] = color.right_bkg[1] = color.right_bkg[2] = 1;
   
   color.grid_front[0] = color.grid_front[1] = color.grid_front[2] = 1;
   color.grid_back[0] = color.grid_back[1] = color.grid_back[2] = 0;
   
   color.chem[0] = color.chem[1] = color.chem[2] = 0;
   color.wind[2] = 1;
   
   color.text[0] = color.text[1] = color.text[2] = 0;
}


int CptsSettings::Load(const char *filename)
{
   int e = 0;

   e = s->load(filename);
   if( !e )
   {
      loaded = 1;
      
      s->getDouble("loop_rate", loop_rate);
      s->getDouble("loop_step", loop_step);
      s->getDouble("display_rate", display_rate);
   
      s->getDouble("speedx", speed.x);
      s->getDouble("speedy", speed.y);
      s->getDouble("speedz", speed.z);
   
      s->getDouble("wind_spectral_density", wind_spectral_density);
      s->getDouble("wind_bandwidth", wind_bandwidth);
      s->getDouble("wind_gain", wind_gain);
   
      s->getDouble("sigmax", sigma.x);
      s->getDouble("sigmay", sigma.y);
      s->getDouble("sigmaz", sigma.z);
   
      s->getUInt32("odor_num_per_second", odor_num_per_second);
      s->getDouble("puffs_growth_rate", puffs_growth_rate);
      s->getUInt32("wn", WN);
      s->getUInt32("wm", WM);
   
      s->getUInt32("strategy", strategy);
   
   
      //s->getDouble("source_pos_x", src_loc.x);
      //s->getDouble("source_pos_y", src_loc.y);
      //s->getDouble("source_pos_z", src_loc.z);
      s->getUInt32("num_plume",   num_plume);
      if(num_plume > 0)
      {
         uInt32 i;
         char tmp[32];
         
         plume_loc   = new Point3D[num_plume];
         for(i = 0; i < num_plume; ++i)
         {
            sprintf(tmp, "plume%d_pos_x", i);
            s->getDouble(tmp, plume_loc[i].x);
            
            sprintf(tmp, "plume%d_pos_y", i);
            s->getDouble(tmp, plume_loc[i].y);
            
            sprintf(tmp, "plume%d_pos_z", i);
            s->getDouble(tmp, plume_loc[i].z);
         }
      }
   
      // 
      s->getDouble("plume_length", plume_length);
      s->getDouble("threshold",    threshold);
   
      s->getDouble("radius", radius);
      s->getUInt32("n_itt",   n_itt);
      s->getDouble("max_t",   max_t);
      
      s->getUInt32("num_veh",   num_veh);
      if(num_veh > 0)
      {
         uInt32 i;
         char tmp[32];
         
         veh_loc   = new Point3D[num_veh];
         veh_color = new Color[num_veh];
         for(i = 0; i < num_veh; ++i)
         {
            sprintf(tmp, "veh%d_pos_x", i);
            s->getDouble(tmp, veh_loc[i].x);
            
            sprintf(tmp, "veh%d_pos_y", i);
            s->getDouble(tmp, veh_loc[i].y);
            
            sprintf(tmp, "veh%d_pos_z", i);
            s->getDouble(tmp, veh_loc[i].z);
      
            sprintf(tmp, "veh%d_color", i);
            s->getColor(tmp,  veh_color[i]);
         }
      }
   
      s->getColor("color_top_bkg",   color.top_bkg);
      s->getColor("color_main_bkg",  color.main_bkg);
      s->getColor("color_right_bkg", color.right_bkg);
      
      s->getColor("color_grid_front", color.grid_front);
      s->getColor("color_grid_back",  color.grid_back);
      s->getColor("color_chem", color.chem);
      s->getColor("color_wind", color.wind);
      s->getColor("color_text", color.text);
   }

   return e; // error loading
}


