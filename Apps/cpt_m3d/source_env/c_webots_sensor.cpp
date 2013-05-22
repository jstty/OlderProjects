//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_webots_sensor.cpp
// Programmer:		Joseph E. Sutton
// Description:	Webots Sensor Class
// Start Date:		5/14/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/c_webots_sensor.h"

void webotsSensor::Update()
{

}

double webotsSensor::GetChemDensity(Point3D inPoint)
{
   return 0;
}

uInt32 webotsSensor::GetNumChemSensor()
{
   return 0;
}

int webotsSensor::StartChemSensorRead()
{
   return 0;
}

int webotsSensor::GetNextChemSensor()
{
   return 1;
}

int webotsSensor::StartChemPointRead()
{
   return 0;
}

int webotsSensor::GetNextChemPoint(Point3D &outPoint)
{
   return 1;
}
