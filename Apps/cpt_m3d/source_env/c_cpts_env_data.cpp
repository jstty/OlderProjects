//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_cpts_env_data.cpp
// Programmer:		Joseph E. Sutton
// Description:	CPTS Environment Data Class
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/c_cpts_env_data.h"

CptsEnvData::CptsEnvData()
{
   w = NULL;
   s = NULL;
   e = NULL;
}

CptsEnvData::~CptsEnvData()
{
}

void CptsEnvData::SetWind(Wind *wind)
{
   w = wind;
}

void CptsEnvData::SetSensor(iChemSensor *sensor)
{
   s = sensor;
}

void CptsEnvData::SetEnv(iEnv *env)
{
   e = env;
}

void CptsEnvData::GetWindDir(Point3D &outDir, Point3D inPoint)
{
   if(w != NULL) w->GetDir(outDir, inPoint);
}


void CptsEnvData::ApplyWind(Point3D inPoint, double object[3])
{
   if(w != NULL) w->Apply(inPoint.x, inPoint.y, object);
}


double CptsEnvData::GetChemDensity(Point3D inPoint)
{
   if(s != NULL) return s->GetChemDensity(inPoint);
   return 0;
}

uInt32 CptsEnvData::GetNumChemSensor()
{
   if(s != NULL) return s->GetNumChemSensor();
   return 0;
}

int CptsEnvData::StartChemSensorRead()
{
   if(s != NULL) return s->StartChemSensorRead();
   return 0;
}

int CptsEnvData::GetNextChemSensor()
{
   if(s != NULL) return s->GetNextChemSensor();
   return 1;
}
      

int CptsEnvData::StartChemPointRead()
{
   if(s != NULL) return s->StartChemPointRead();
   return 0;
}

int CptsEnvData::GetNextChemPoint(Point3D &outPoint)
{
   if(s != NULL) return s->GetNextChemPoint(outPoint);
   return 1;
}

double CptsEnvData::GetSimTime()
{
   if(e != NULL) return e->GetSimTime();
   return 0;
}
