//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_cpts_env.h
// Programmer:		Joseph E. Sutton
// Description:	CPTS Environment Class
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __CPTS_ENV__
#define __CPTS_ENV__

#include "i_env.h"
#include "c_wind.h"
#include "c_cpts_env_data.h"
#include "c_chemical_trail_manager.h"

class CptsEnv : public iEnv {
   public:
      CptsEnv();
      ~CptsEnv();
   
      void Init();
      void Loop();
      
      iEnvData *GetData();
      
      double GetSimTime();
      
   private:
      Wind    *w;
      ChemicalTrailManager *s;
      
      CptsEnvData *ed;
      
      double Sim_Time;
};

#endif // __CPTS_ENV__
