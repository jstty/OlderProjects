//////////////////////////////////////////////////////////////////////////////
// Program Name:	cpts_env_dll.h
// Programmer:		Joseph E. Sutton
// Description:	CPTS Vehicle DLL header
// Start Date:		01/12/2009
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "cpts.h"
#include "i_vehicle.h"

DLL_TYPE iVehicle * cptsVehInit(CptsSettings *s);
DLL_TYPE void       cptsVehFree();
