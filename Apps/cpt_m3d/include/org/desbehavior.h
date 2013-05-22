/******************************************************************************
 Designed Behavior Class for Behavior Planning.!

 Author Dr. Wei Li

 Computer Science Department
 California State University, Bakersfield
 Bakersfield, CA 93311

 May 12th, 2002.
*******************************************************************************/

#ifndef DESBEHAVIOR_H
#define DESBEHAVIOR_H

#include "actfunction.h"
//#include "menu.h"
#include "../maxmin.h"
#include "point.h"

class DesignBehavior : public ActiveFunc {

public:
      //double des_dblTempFound;
	DesignBehavior( double *strat_in, double *strat_mem, double DT, double RADIUS, double THRESHOLD )
      : ActiveFunc( strat_in, strat_mem, DT, THRESHOLD )
   {
      Radius = RADIUS;
   }

	void MovingPos(double *strat_in, double *strat_out, //double *strat_mem, 
				   const double, const double); // 06-20-02
	
	
	void CloverLeaf(int leaf_num, double diameter, double *strat_in, double *strat_out, double *strat_mem);
   	void BoxSource(	double *strat_in, double *strat_mem);
   	void MakeTurn(double *strat_in, double *strat_out, double *strat_mem);
protected :
   double Radius;

   double 	des_dblUpFai, des_dblMitteFai, des_dblDownFai, des_dblFuzzFai;
	double 	des_dblMaxXc, des_dblMinXc, des_dblMaxYc, des_dblMinYc;
	double	des_dblGama1, des_dblGama2, des_dblHeadErr;
	int 	des_iMeanNr; //, des_ii, des_ij; //, des_iPFlag[];
};

#endif