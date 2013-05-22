//////////////////////////////////////////////////////////////////////////////
// Program Name:	cpts_veh_dll.h
// Programmer:		Joseph E. Sutton
// Description:	CPTS Vehicle DLL
// Start Date:		01/12/2009
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "windows.h"

#define DLL_TYPE __declspec(dllexport)
#include "../../../include/cpts_veh_dll.h"

CptsVehicle  *cpts_veh = NULL;
CptsSettings *settings = NULL;

iVehicle *cptsVehInit(CptsSettings *s)
{
   settings = s;

   cpts_veh = new CptsVehicle();
   cpts_veh->Init();

   return cpts_veh;
}

void cptsVehFree()
{
   if(cpts_veh != NULL)
      delete cpts_veh;
}
