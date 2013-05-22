//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_chemical_trail_manager.cpp
// Programmer:		Joseph E. Sutton
// Description:	Class to generate Manage a List of Dynamic Chemical Trail
// Start Date:		5/1/2008
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/cpts.h"
#include "../include/c_chemical_trail_manager.h"
extern Settings *settings;

// Constructor
ChemicalTrailManager::ChemicalTrailManager(Wind *w, uInt32 numPlume)
{
   mWind = w;
   mSize = numPlume;
   mList = new ChemicalTrail[mSize];
   
   cp_num = 0;
   cp_cpos = 0;
   cp_max = 0;
}

ChemicalTrailManager::~ChemicalTrailManager()
{
   delete [] mList;
}

void ChemicalTrailManager::SetSettings(double ddt, Point3D dsp, Point3D dsi, uInt32 donps, double dpl, double dpgr, double dth)
{
   for(i = 0; i < mSize; i++)
   {
      mList[i].SetSettings(ddt, dsp, dsi, donps, dpl, dpgr, dth);
   }
}


void ChemicalTrailManager::AddPlume(uInt32 pnum, Point3D start)
{
   if(pnum < mSize)
   {
      mList[pnum].Init(mWind, start);
   }
}


double ChemicalTrailManager::GetChemDensity(Point3D inPoint)
{
   double den = 0;
   double tmp;

   // take max value of all chemical densities
   for(i = 0; i < mSize; i++)
   {
      tmp = mList[i].CalcDensity(inPoint.x, inPoint.y, inPoint.z);
      if(tmp > den) den = tmp;
   }
   
   return den;
}


uInt32 ChemicalTrailManager::GetNumChemSensor()
{
   return mSize;
}

int ChemicalTrailManager::StartChemSensorRead()
{
   cp_num = 0;
   cp_cpos = 0;
   
   return 0;
}

int ChemicalTrailManager::GetNextChemSensor()
{
   if(cp_num < mSize) 
   {
      ++cp_num;
      return 0;
   }
   
   return 1;
}

int ChemicalTrailManager::StartChemPointRead()
{
   if(cp_num < mSize) 
   {
      cp_cpos = 0;
      cp_max = mList[cp_num].GetMax();
      
      return 0;
   }
   
   return 1;
}

int ChemicalTrailManager::GetNextChemPoint(Point3D &outPoint)
{
   if(cp_cpos < cp_max) 
   {
      mList[cp_num].GetPoint(cp_cpos, outPoint);
      ++cp_cpos;
      
      return 0;
   }
   
   return 1;
}

void ChemicalTrailManager::Update()
{
   for(i = 0; i < mSize; i++)
   {
      mList[i].Update();
   }
}



