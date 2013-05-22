//////////////////////////////////////////////////////////////////////////////
// Program Name:  planet_data.cpp
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/25/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "planet_data.h"

PlanetData::PlanetData()
{
	temp_wind_dir = WIND_LEFT;
}

char *PlanetData::GetName()
{
	return name;
}

void PlanetData::SetName(const char *str, int len)
{
	memset(name, 0, 512);
   strncpy(name, str, len);
}

char *PlanetData::GetDesc()
{
	return desc;
}

void PlanetData::SetDesc(const char *str, int len)
{
	memset(desc, 0, 128);
   strncpy(desc, str, len);
}

char *PlanetData::GetIcon()
{
	return icon;
}

void PlanetData::SetIcon(const char *str, int len)
{
	memset(icon, 0, 128);
   strncpy(icon, str, len);
}

char *PlanetData::GetImg()
{
	return img;
}

void PlanetData::SetImg(const char *str, int len)
{
	memset(img, 0, 128);
   strncpy(img, str, len);
}

COLORREF PlanetData::GetColor()
{
	return RGB( color[0], color[1], color[2]);
}

void PlanetData::SetColor(int r, int g, int b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

float PlanetData::UpdateWindSpd()
{
	temp_wind_spd = ( ((float)rand()/RAND_MAX) * (wind[1] - wind[0])) + wind[0];
	return temp_wind_spd;
}

cVector PlanetData::UpdateWindDir()
{		
	if( ((float)rand()/RAND_MAX) <= wind[2] )
	{
		int wind_dir = (int)(((float)rand()/RAND_MAX) + 0.5);
		if(wind_dir)
			temp_wind_dir = WIND_LEFT;
		else
			temp_wind_dir = WIND_RIGHT;
	}

	return temp_wind_dir;
}

float PlanetData::GetWindSpd()
{
	return temp_wind_spd;
}

cVector PlanetData::GetWindDir()
{
	return temp_wind_dir;
}


float PlanetData::GetGravity()
{
	return gravity;
}

void PlanetData::SetWind(float min, float max, float prob)
{
	wind[0] = min;
	wind[1] = max;
	wind[2] = prob;
}

void PlanetData::SetGravity(float g)
{
	gravity = g;
}