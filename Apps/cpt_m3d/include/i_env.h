//////////////////////////////////////////////////////////////////////////////
// Program Name:	i_env.h
// Programmer:		Joseph E. Sutton
// Description:	Environment Interface
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __IENV__
#define __IENV__

#include "i_env_data.h"

class iEnv {
   public:
      virtual void Init() = 0;
      virtual void Loop() = 0;

      // DON'T DELETE
      virtual iEnvData *GetData()= 0;
      
      virtual double GetSimTime() = 0;
};

#endif // __IENV__
