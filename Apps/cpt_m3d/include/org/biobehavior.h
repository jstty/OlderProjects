/******************************************************************************
 Biology Behavior Class for Behavior Planning.!

 Author Dr. Wei Li

 Computer Science Department
 California State University, Bakersfield
 Bakersfield, CA 93311

 May 12th, 2002.
*******************************************************************************/

#ifndef BIOBEHAVIOR_H
#define BIOBEHAVIOR_H

#include	"IniSearch.h"

class BiologicalBehavior : public InitialSearch {

public:
	BiologicalBehavior( double *strat_in, double *strat_mem ) : InitialSearch(strat_in, strat_mem ){ };
	void FindingSearch(double *strat_in, double *strat_out, double *strat_mem);
	void MaintainInPlume(double *strat_in, double *strat_out, double *strat_mem);
	void MaintainOutPlume(double *strat_in, double *strat_out, double *strat_mem);

	//void RecoveryPlume(double *strat_in, double *strat_out, double *strat_mem);
   //void EdgeDiamond(double *strat_out, double *strat_mem);

};


#endif