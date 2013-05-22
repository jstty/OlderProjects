//////////////////////////////////////////////////////////////////////////////
// Program Name:  planet_data.h
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/8/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _CPLANETDATA_
#define _CPLANETDATA_

#include "../pop/force.h"

#define WIND_LEFT		(-cVector::XAXIS)
#define WIND_RIGHT	(cVector::XAXIS)

class PlanetData
{
public:

	PlanetData();

	char *GetName();
	void SetName(const char *str, int len);

	char *GetDesc();
	void SetDesc(const char *str, int len);

	char *GetIcon();
	void SetIcon(const char *str, int len);

	char *GetImg();
	void SetImg(const char *str, int len);

	void SetColor(int r, int g, int b);
	COLORREF GetColor();

	void SetWind(float min, float max, float prob);
	void SetGravity(float g);

   float UpdateWindSpd();	  // random on with ranges
	cVector UpdateWindDir();	  // using the probability, it select a wind direction

	float GetWindSpd();
	cVector GetWindDir();
	float GetGravity();


protected:
	char  name[128];
   char  desc[512];
   char  icon[128];
   char  img[128];

   int   color[3];
   float wind[3];

   float temp_wind_spd;
	cVector temp_wind_dir;

   float gravity;
};

#endif