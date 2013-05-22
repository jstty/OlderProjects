//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_cpts_vehicle.cpp
// Programmer:		Joseph E. Sutton
// Description:	CPTS Vehicle Class
// Start Date:		5/8/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/c_cpts_vehicle.h"
#include "../include/c_cpts_settings.h"
extern CptsSettings *settings;

CptsVehicle::CptsVehicle()
{
   vd = NULL;
   vc = NULL;
}

CptsVehicle::~CptsVehicle()
{
   if(vd != NULL) delete vd;
   if(vc != NULL) delete vc;
}

void CptsVehicle::Init()
{
   int i;
   vd = new CptsVehicleData();
   
   vd->SetSettings(settings->plume_loc[0],
                   settings->dt,
                   settings->threshold,
                   settings->radius,
				       settings->max_t);
   
   for(i = 0; i < settings->num_veh; ++i)
   {   
      vd->AddVehicle(settings->veh_loc[i], settings->veh_color[i]);
   }
}

void CptsVehicle::SetEnvData(iEnvData *edata)
{
   if(vd != NULL)
   {
      vd->SetEnvData(edata);
   }
}

void CptsVehicle::Loop()
{
   if(vd != NULL)
   {
      vd->StartVehicleRead();
      do
      {
         vd->Update();
      } while(vd->NextVehicle() == 0);
   }
}

iVehicleData *CptsVehicle::GetData()
{
   return vd;
}

