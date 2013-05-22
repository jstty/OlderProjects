//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_cpts_env.cpp
// Programmer:		Joseph E. Sutton
// Description:	CPTS Environment Class
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/cpts.h"
extern CPTS *cpts;
extern CptsSettings *settings;

CptsEnv::CptsEnv()
{
   ed = NULL;
   w = NULL;   
   s = NULL;
   
   Sim_Time = 0.0;
}

CptsEnv::~CptsEnv()
{
   if(ed != NULL)  delete ed;
   if(w != NULL)  delete w;
   if(s != NULL)  delete s;
}

void CptsEnv::Init()
{   
   // wind
   w = new Wind();
   w->SetSettings(settings->speed.x, 
                  settings->speed.y,
                  settings->dt,
                  settings->wind_damping,
                  settings->wind_bandwidth,
                  settings->wind_gain);
   
   // sensor
   s = new ChemicalTrailManager(w, settings->num_plume);
   s->SetSettings(settings->dt, 
                  settings->speed,
                  settings->sigma,
                  settings->odor_num_per_second,
                  settings->plume_length,
                  settings->puffs_growth_rate,
                  settings->threshold);
   uInt32 i;
   for(i = 0; i < settings->num_plume; ++i)
   {
      s->AddPlume(i, settings->plume_loc[i]);
   }
   //
   
   // env data
   ed = new CptsEnvData();
   ed->SetWind(w);
   ed->SetSensor(s);
   ed->SetEnv(this);
}

void CptsEnv::Loop()
{
   Sim_Time += settings->loop_rate;

   // wind
   w->Update();
   
   // sensor
   s->Update();
}

iEnvData *CptsEnv::GetData()
{
   return ed;
}

double CptsEnv::GetSimTime()
{
   return Sim_Time;
}


