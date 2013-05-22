/******************************************************************************
 Active Function Class for Behavior Planning.!

 Author Dr. Wei Li

 Computer Science Department
 California State University, Bakersfield
 Bakersfield, CA 93311

 May 12th, 2002.
*******************************************************************************/

#ifndef ACTFUNCTION_H
#define ACTFUNCTION_H

#include "IniSearch.h"

class ActiveFunc : public InitialSearch {
public:
	
	ActiveFunc(double *strat_in, double *strat_mem, double DT, double THRESHOLD)
      : InitialSearch(strat_in, strat_mem)
   {
      dt = DT;
      threshold = THRESHOLD;
   }
	
	bool InitialOn(double Sim_Time) { return ( Sim_Time <= dt ); }
	
	bool ConcBelowThreshold( double *strat_in, double *strat_mem ) 
	{		
		//setInputData( strat_in );
		return ( sens[0] < threshold );
	}

	bool ConcAboveThreshold( double *strat_in, double *strat_mem ) {		
		//setInputData( strat_in );
		return ( sens[0] >= threshold );
	}
	
	bool InWaitingTime(double Sim_Time, double *strat_mem ) {
		return ( (Sim_Time - plm_dblMatnTime - plm_dblFindTime ) < stg_iTau*dt );
	}

	bool OutWaitingTime(double Sim_Time, double *strat_mem ) {
		return ( (Sim_Time - plm_dblMatnTime - plm_dblFindTime ) >= stg_iTau*dt );
	}

	bool EnergyCriterion( double *strat_in, double *strat_mem ) {
		double Act_dblCurrentEnergy;
		// Current Energy should be calculated and 
		// stg_dblEngLimit should be specified
		Act_dblCurrentEnergy = strat_in[4]; // Sim_Time
		return ( Act_dblCurrentEnergy < stg_dblEngLimit );
	} 
	
	//bool RecoverPlume(double *strat_in, double *strat_mem ) {		
	//	InputData( strat_in );
	//	return ( ( sens[0] < threshold ) && ( plm_dblBhvSwitch == 3 ) );
	//}

	bool InSearchArea( double *strat_in, double *strat_mem ) {		
		//setInputData( strat_in );
		return ( ( y_current <= plm_dblLocMaxY ) &&
			     ( y_current >= plm_dblLocMinY ) &&
                 ( x_current <= plm_dblLocMaxX ) &&
                 ( x_current >= plm_dblLocMinX ) );
	}

	bool RecoverLimit( double *strat_mem ) {
		return ( plm_dblRcvNum < iRecoverNum );
	}

	bool GoolReach( double *strat_in, double *strat_mem, 
		            double fun_dblGoolX, double fun_dblGoolY ) {
		//setInputData( strat_in );
		return ( CalDistance( fun_dblGoolY, y_current, fun_dblGoolX, x_current ) < 2.5 );
	}

	bool EstimateGoolOn( double *strat_mem ) {
		return ( plm_dblSrcOn == 1 );
	}
private:

   double dt;
   double threshold;
};

#endif