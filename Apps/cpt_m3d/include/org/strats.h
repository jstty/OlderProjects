/******************************************************************************
 Planner Class for Behavior Planning.!

 Author Dr. Wei Li

 Computer Science Department
 California State University, Bakersfield
 Bakersfield, CA 93311

 May 12th, 2002.
*******************************************************************************/

#ifndef STRATS_H
#define STRATS_H

#include "actfunction.h"
#include "mapbehavior.h"
#include "biobehavior.h"
#include "desbehavior.h"

enum SearchMethod { Planning, BehaviorTrace };

class Planner : public ActiveFunc {

public:	
	Planner( double *strat_in, double *strat_mem, double DT, double RADIUS, double THRESHOLD ) 
      : ActiveFunc(strat_in, strat_mem, DT, THRESHOLD ), 
        map(strat_in, strat_mem, DT),
	     biology( strat_in, strat_mem ), 
        design( strat_in, strat_mem, DT, RADIUS, THRESHOLD )
   { };
	
	char *pln_chBehaviorptr;
	char pln_chBehavior;
	
	void GenerateStartPoint( double *strat_mem, Point pln_dblP );
    
	void CheckBehavior( double *strat_mem );
	
	void setMapWind( double *strat_in, double *strat_mem  ) { map.CalWind( strat_in, strat_mem );};
	void setMapBackTrace( double *strat_in, double *strat_mem, double s = 1.0) { map.BackTrace(strat_in, strat_mem, 1.0 );}
    void setBiologyFindingSearch( double *strat_in, double *strat_out, double *strat_mem ) 
	{biology.FindingSearch( strat_in, strat_out, strat_mem );};
    void setBiologyMaintainInPlume( double *strat_in, double *strat_out, double *strat_mem ) 
	{biology.MaintainInPlume( strat_in, strat_out, strat_mem );};
    void setBiologyMaintainOutPlume( double *strat_in, double *strat_out, double *strat_mem ) 
	{biology.MaintainOutPlume( strat_in, strat_out, strat_mem );};

    void setDesignMovingPos( double *strat_in, double *strat_out, const double x0, const double y0 )
	{ design.MovingPos( strat_in, strat_out, x0, y0);};
	
	void setDesignBoxSource( double *strat_in, double *strat_mem )
	{ design.BoxSource( strat_in, strat_mem );}
	
	void setDesignCloverLeaf( int num1, int num2, double *strat_in, double *strat_out, double *strat_mem )
	{ design.CloverLeaf( num1, num2, strat_in, strat_out, strat_mem ); }
	
	void setDesignMakeTurn( double *strat_in, double *strat_out, double *strat_mem ) 
	{ design.MakeTurn(strat_in, strat_out, strat_mem); }

    double getDistance( double *strat_in, double *strat_mem, 
						double fun_dblGoolX, double fun_dblGoolY ) 
	{
	   return CalDistance( fun_dblGoolY, y_current, fun_dblGoolX, x_current );
	}
	   
private:
    MapBuildingBehavior map;
    BiologicalBehavior biology;
    DesignBehavior design;
};


//added by fc----------------
struct behStruct {
	int m_iNumber;			//number of children
	char m_cBehavior;		//behavior char
	char *m_content;		//behavior string
	char m_cChildBehavior[MAXCHILDREN];	// children behaviors
	char *m_cString[MAXCHILDREN];		//children strings
}; 

#endif