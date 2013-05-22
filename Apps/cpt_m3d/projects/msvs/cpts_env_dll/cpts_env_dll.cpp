//////////////////////////////////////////////////////////////////////////////
// Program Name:	cpts_env_dll.h
// Programmer:		Joseph E. Sutton
// Description:	CPTS Environment DLL
// Start Date:		01/12/2009
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "windows.h"

#define DLL_TYPE __declspec(dllexport)
#include "../../../include/cpts_env_dll.h"

CptsEnv      *cpts_env = NULL;
CptsSettings *settings = NULL;

iEnv *cptsEnvInit(CptsSettings *s)
{
   settings = s;

   cpts_env = new CptsEnv();
   cpts_env->Init();

   return cpts_env;
}

void cptsEnvFree()
{
   if(cpts_env != NULL)
      delete cpts_env;
}
