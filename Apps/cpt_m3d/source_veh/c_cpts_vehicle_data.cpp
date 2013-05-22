//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_cpts_vehicle_data.cpp
// Programmer:		Joseph E. Sutton
// Description:	CPTS Vehicle Data Class
// Start Date:		5/8/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/c_cpts_vehicle_data.h"

CptsVehicleData::CptsVehicleData()
{
   v = NULL;
   mList.clear();
}

CptsVehicleData::~CptsVehicleData()
{
   for(mIt = mList.begin(); mIt != mList.end(); mIt++)
   {
      v = (*mIt);
      delete v;
   }
}

uInt32 CptsVehicleData::GetNumVehicle()
{
   return mList.size();
}

void CptsVehicleData::SetEnvData(iEnvData *edata)
{
   ed = edata;
   for(mIt = mList.begin(); mIt != mList.end(); mIt++)
   {
      (*mIt)->SetEnvData(ed);
   }
}

void CptsVehicleData::SetSettings(Point3D sl, double ddt, double dth, double r, double m)
{
   srcloc = sl;
   dt = ddt;
   threshold = dth;
   radius = r;
   max_t = m;
}

void CptsVehicleData::AddVehicle(Point3D vl, Color color)
{
   Vehicle *tv = new Vehicle();
   tv->SetSettings(vl, color, srcloc, dt, threshold, radius, max_t);
   tv->Init();
   
   mList.push_back(tv);
}


int CptsVehicleData::StartVehicleRead()
{
   v = NULL;
   
   if(mList.size() > 0)
   {
      mIt = mList.begin();
      v = (*mIt);
      return 0;
   }

   return 1;
}

int CptsVehicleData::NextVehicle()
{
   v = NULL;
   mIt++;
   if(mIt != mList.end())
   {
      v = (*mIt);
      return 0;
   }
   
   return 1;
}


void CptsVehicleData::Update()
{
   if(v != NULL)
   {
      v->Update();
   }
}

void CptsVehicleData::GetColor(Color &c)
{
   if(v != NULL)
   {
      v->GetColor(c);
   }
}

void CptsVehicleData::GetPosDir(Point3D &outPoint)
{
   if(v != NULL)
   {
      v->GetPos(outPoint);
      outPoint.heading = v->GetHeading();
   }
}


const char *CptsVehicleData::GetCurrentBehaviorName()
{
   if(v != NULL)
   {
      return v->GetCurrentBehaviorName();
   }
   
   return "";
}

