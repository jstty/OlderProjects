//////////////////////////////////////////////////////////////////////////////
// Program Name:	s_data.h
// Programmer:		Joseph E. Sutton
// Description:	Data Structs
// Start Date:		3/7/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __S_DATA__
#define __S_DATA__

#include "c_vehicle.h"

#define N_STRAT_MEM 70000 // number of memory elements for strategy

typedef struct _StratagyData
{
	double in[7+NUM_SENS];
	double out[3];
	double mem[N_STRAT_MEM*NUM_VEH];
} StratagyData;


#endif // __S_DATA__