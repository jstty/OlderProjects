//////////////////////////////////////////////////////////////////////////////
// Program Name:	cpts_env_dll.h
// Programmer:		Joseph E. Sutton
// Description:	CPTS Environment DLL header
// Start Date:		01/12/2009
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "cpts.h"
#include "i_env.h"

DLL_TYPE iEnv * cptsEnvInit(CptsSettings *s);
DLL_TYPE void   cptsEnvFree();
