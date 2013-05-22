/******************************************************************************
 Planner Class for Behavior Planning.!

 Author Dr. Wei Li

 Computer Science Department
 California State University, Bakersfield
 Bakersfield, CA 93311

 May 12th, 2002.
*******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <fstream>
#include "../../include/org/list.h"
#include "../../include/org/strats.h"

static double dblHomeX;			// Position of Vehicle Home (06-20-02)
static double dblHomeY;


FILE *Traj, *W_xy;

// added by fc-----------------------------------------------
// current behavior char
char currentBehavior = 0;
double currentXmin = 0;
double currentXmax = 0;
double currentYmin = 0;
double currentYmax = 0;
int pier_height = 15;	//meters
int pier_width  = 7;	//meters

// currently there are 7 possibilities: CURRENTPOSS == 7
struct behStruct  bMapping[CURRENTPOSS] = {
	//the first behavior is currently defined as 'G', if you change it, also change 
	// the FIRST_BEHAVIOR definition in GlobalDef.h, because other code depends on this
	// Also, if you define more children number than what it really has, use '0' to fill any vacancy
	// for detail, see the two lines below
	//{2, FIRST_BEHAVIOR, "Go Search Area",	'F',	'I',	0,		"Find Plume",		"Main In Plume",	0},

    {3, FIRST_BEHAVIOR, "Go Point",	'H', 'I', 'F',  0, "Return Home",  "Main In Plume", "Find Plume", 0},
	//{2 children, current behavior, explanation, First child, Second Child, no other child, explanation of the first, expl. of the second, no more expl} 	
	
	{2, 'F', "Find Plume", 'I', 'H', 0,	0, "Main In Plume", "Return Home", 0, 0},
	{3, 'I', "Main In Plume", 'D', 'O', 'H', 0, "Declare Source", "Main Out Plume",	"Return Home", 0},
	//{2, 'I', "Main In Plume", 'O', 'H', 0, 0,  "Main Out Plume",	"Return Home", 0, 0},
	//{4, 'O', "Main Out Plume", 'H',	'R', 'I', 'D', "Return Home", "Recover Plume", "Main In Plume", "Declare Source"},
	{3, 'O', "Main Out Plume", 'I',	'R', 'D', 0, "Main In Plume", "Recover Plume",  "Declare Source", 0},
	//{2, 'R', "Recover Plume",	'F',	'I',	0,		"Find Plume",		"Main In Plume", 0},
	{4, 'R', "Recover Plume", 'F', 'I',	'G', 'H', "Find Plume", "Main In Plume", "Go Point", "Return Home"},
	//{2, 'R', "Recover Plume", 'F', 'I',	0, 0, "Find Plume", "Main In Plume", 0, 0},	
	{0, 'H', "Return Home",	0,  0,	0,  0,   0, 0, 0, 0 },
	{1, 'D', "Declare Source", 'H',	0, 0, 0,  "Return Home", 0, 0, 0}
};
//-----------------------------------------------------------

void Planner::CheckBehavior( double *strat_mem )
{
	if ( plm_dblBhvSwitch == 6 ) 
	{
		pln_chBehaviorptr = "GoToSearhArea";
		pln_chBehavior = 'G';
	}
		
	if ( plm_dblBhvSwitch == 0 ) 
	{
		pln_chBehaviorptr = "FindPlume";
		pln_chBehavior = 'F';
	}
	
	if ( plm_dblBhvSwitch == 1 ) 
	{
		pln_chBehaviorptr = "MainInPlume";
		pln_chBehavior = 'I';
	}
	
	if ( plm_dblBhvSwitch == 2 ) 
	{
		pln_chBehaviorptr = "MainOutPlume";
		pln_chBehavior = 'O';
	}
		
	if ( plm_dblBhvSwitch == 3 ) 
	{
		pln_chBehaviorptr = "RecoverPlume";
		pln_chBehavior = 'R';
	}
	
	if ( plm_dblBhvSwitch == 4 ) 
	{
		pln_chBehaviorptr = "ReturnHome";
		pln_chBehavior = 'H';
	}

	if ( plm_dblBhvSwitch == 5 ) 
	{
		pln_chBehaviorptr = "DeclareSource";
		pln_chBehavior = 'D';
	}
} 

void Planner::GenerateStartPoint( double *strat_mem, Point pln_dblP )
{
//	dblSubGoalX = pln_dblP.x;
//	dblSubGoalY = pln_dblP.y;
//	dblSubGoalZ = pln_dblP.z;
}

void setPlan_Q1( List<Point> & Tmp_Q )
{
/*
	Point Tmp_P1;
	if ( Tmp_Q.isEmpty( ) ) {
		Tmp_P1.x = 90.0; 
		Tmp_P1.y = -30.0;
		Tmp_P1.z = 0.0; 

		ofstream outRandomFile( "test_num.txt", ios::out );  
   
		if ( !outRandomFile )
		{
			cerr << "File could not be opened\n";
			exit(1);
		}  

		for ( int i = 0; i < 7; ++i ) 
		{
			Tmp_P1.x -= 10.0;
			Tmp_P1.y *= -1.0;
			Tmp_P1.z = 0.0;
			outRandomFile << Tmp_P1.x <<' ' << Tmp_P1.y << ' ' << Tmp_P1.z <<'\n';
			Tmp_Q.insertAtFront( Tmp_P1 );
		}
		outRandomFile.close();
	}
*/
}

void MyStratFunc(double *strat_in, double *strat_out, double *strat_mem, 
                 double dt, double radius, double threshold, 
                 double Sim_Time, char *currentBehaviorName)
{
	Planner plan(strat_in, strat_mem, dt, radius, threshold);
	static SearchMethod test_state = BehaviorTrace;
	//static SearchMethod test_state = Planning;
	Point Tmp_P1;
	static	List< Point > Plan_Q1;
	static double dblSubGoalX, dblSubGoalY, dblSubGoalZ;			// subGoal from a Queue (06-20-02)
   
	setPlan_Q1(Plan_Q1);
	
   //plan.setInputData( strat_in ); // need to check if in actfunction in working plume simulator
   
	if ( plan.InitialOn(Sim_Time) )  {
		// Initialize the parameters
		plan.Parameters( strat_in, strat_out, strat_mem );
	
		if ( (test_state==Planning)&&(Sim_Time<dt) ) 
		{														// Getting Starting Point for Planning
			Plan_Q1.removeFromBack(Tmp_P1);      
			//plan.GenerateStartPoint( strat_mem, Tmp_P1 );
			
			dblSubGoalX = Tmp_P1.x;
			dblSubGoalY = Tmp_P1.y;
			dblSubGoalZ = Tmp_P1.z;
		
		}
		if ( (test_state==BehaviorTrace)&&(plan.InitialOn(Sim_Time)) )
		{														// Getting Starting Point for Behavior Tracing								   	
			Tmp_P1.x =  70.0;
			Tmp_P1.y =  -10.0;
			Tmp_P1.z = 0.0;
			//plan.GenerateStartPoint( strat_mem, Tmp_P1 );
			dblSubGoalX = Tmp_P1.x;
			dblSubGoalY = Tmp_P1.y;
			dblSubGoalZ = Tmp_P1.z;
		}
	}
	
	plan.setMapWind( strat_in, strat_mem );
	plan.CheckBehavior( strat_mem );
   
   // copy Behavior to global so can be displayed
   strcpy(currentBehaviorName, plan.pln_chBehaviorptr);
   
	// added here by fc
	currentBehavior = plan.pln_chBehavior ;
	currentXmin		= plm_dblBoxMinX;
	currentXmax		= plm_dblBoxMaxX;
	currentYmin		= plm_dblBoxMinY;
	currentYmax		= plm_dblBoxMaxY;

	if ( test_state == Planning )
	{	
		if ( plan.GoolReach( strat_in, strat_mem, dblSubGoalX, dblSubGoalY))
		{
			Plan_Q1.removeFromBack(Tmp_P1);			
			dblSubGoalX =  Tmp_P1.x;
			dblSubGoalY =  Tmp_P1.y;	
		}
		plan.setDesignMovingPos( strat_in, strat_out, dblSubGoalX, dblSubGoalY);
	}
    else
	{
		switch ( plan.pln_chBehavior ) {
		case 'G' :	// planning at Going to start position
			if ( plan.GoolReach( strat_in, strat_mem, dblSubGoalX, dblSubGoalY ) )
			{   // is going to finding time behavior
				//plm_dblFindFlag = 1;
				plm_dblBhvSwitch = 0;
				plm_dblFindBehaviorTime = 0;
			}
			else
			{   // firing going to searh area behavior
				plan.setDesignMovingPos( strat_in, strat_out, dblSubGoalX, dblSubGoalY );
			} 
			if ( plan.ConcAboveThreshold( strat_in, strat_mem ) ) 
			{		// is going to maintaining behavior				
				plm_dblBhvSwitch = 1;
				plm_dblFindTime = Sim_Time;
			}
			if ( !plan.EnergyCriterion( strat_in, strat_mem ) ) {
				plm_dblBhvSwitch = 4;  	
			}
			break;
		case 'F' :	// planning at Finding Behavior
			if ( plan.ConcBelowThreshold( strat_in, strat_mem ) )
			{         // firing finding time behavior
				plan.setBiologyFindingSearch( strat_in, strat_out, strat_mem );
			} 
			if ( plan.ConcAboveThreshold( strat_in, strat_mem ) ) 
			{		// is going to maintaining behavior				
				plm_dblBhvSwitch = 1;
				plm_dblFindTime = Sim_Time;
			}
			if ( !plan.EnergyCriterion( strat_in, strat_mem ) ) {
				plm_dblBhvSwitch = 4;	
			}
			break;
		case 'I' : // planning at Maintaining within Plume
			if ( plan.ConcAboveThreshold( strat_in, strat_mem ) ) 
			{	// firing maintaining behavior within Plume
				plan.setMapBackTrace( strat_in, strat_mem, 1.0 );
				//map.EstimateSource( strat_mem );
				plan.setBiologyMaintainInPlume( strat_in, strat_out, strat_mem );
			}
			if ( plan.ConcBelowThreshold( strat_in, strat_mem ) ) 	
			{	// is going to maintaining behavior outside Plume
				plm_dblBhvSwitch = 2;
				plm_dblOdorDetc = 0;
      			plm_dblMatnTime = plan.getLocalTime()-plm_dblFindTime;
			}
			if ( !plan.EnergyCriterion( strat_in, strat_mem ) ) {
				plm_dblBhvSwitch = 4;	
			}
			break;
		case 'O' : // planning at Maintaing behavior outside Plume
			if ( plan.ConcBelowThreshold( strat_in, strat_mem ) && 
				 plan.InWaitingTime(Sim_Time, strat_mem ) ) 
			{   // firing maintaining behavior outside plume 
				plan.setBiologyMaintainOutPlume( strat_in, strat_out, strat_mem );      			
			}
			if ( plan.ConcBelowThreshold( strat_in, strat_mem ) && 
				 plan.OutWaitingTime(Sim_Time, strat_mem ) ) 
			{	// is going to recovering behavior
				plm_dblBhvSwitch = 3;
         		plan.setDesignBoxSource( strat_in, strat_mem ); // here plm_dblBhvSwitch = 5 may be true
			}			
			if ( plan.ConcAboveThreshold( strat_in, strat_mem ) )
			{	// is going to maintaining behavior within Plume
				plm_dblBhvSwitch = 1;
				plm_dblFindTime = Sim_Time;
			}
			//if ( !function.EnergyCriterion( strat_in, strat_mem ) ) {
			//	plm_dblBhvSwitch = 4;	
			//}
			break;
		case 'R' : // planning at recovering behavior
			if ( plan.ConcBelowThreshold( strat_in, strat_mem ) && 
				 plan.InSearchArea( strat_in, strat_mem ) &&
				 plan.RecoverLimit( strat_mem ) )
			{ // firing recovering behavior
				plan.setDesignCloverLeaf( 2, 8, strat_in, strat_out, strat_mem );
			}
			if ( plan.ConcBelowThreshold( strat_in, strat_mem ) && 
				 !plan.InSearchArea( strat_in, strat_mem ) ||
				 !plan.RecoverLimit( strat_mem ) )
			{ // is going to finding plume behavior
				//plm_dblFindFlag = 0;
				if ( !( ( plm_dblEstimaX == stg_iLargNr ) && 
					    ( plm_dblEstimaY == -stg_iLargNr ) ) ) {
					plm_dblBhvSwitch = 6;
					dblSubGoalX = plm_dblEstimaX;
					dblSubGoalY = plm_dblEstimaY;
				}
				else {				
					plm_dblBhvSwitch = 0;
					plm_dblFindBehaviorTime = 0;
				//biology.FindingSearch( strat_in, strat_out, strat_mem );
				}
			}
			if ( plan.ConcAboveThreshold( strat_in, strat_mem ) )
			{   // is going to maintaining behavior within Plume
				plm_dblBhvSwitch = 1;
				plm_dblFindTime = Sim_Time;	
			}
			if ( !plan.EnergyCriterion( strat_in, strat_mem ) ) {
				plm_dblBhvSwitch = 4;	
			}
			break;
		case 'D' :
			if ( plan.GoolReach( strat_in, strat_mem, plm_dblSourcX, plm_dblSourcY ) ||
				 !plan.EnergyCriterion( strat_in, strat_mem ) ) 
			{
				//plm_dblTempFound = 1;	
				plm_dblBhvSwitch = 4;
			}
			else 
			{
				plan.setDesignMovingPos( strat_in, strat_out, plm_dblSourcX, plm_dblSourcY );
      			//found = plm_dblTempFound;
			}
			//if ( ) {
			//	plm_dblBhvSwitch = 4;	
			//}
			break;
		case 'H' :
			//if ( plan.GoolReach( strat_in, strat_mem, plm_dblHomeX, plm_dblHomeY ) ) 
			if ( plan.GoolReach( strat_in, strat_mem, dblHomeX, dblHomeY ) ) 
			{
				plm_dblTempFound = 1;	
				//plm_dblBhvSwitch = 4;
			}
			else 
			{
				//plan.setDesignMovingPos( strat_in, strat_out, strat_mem, plm_dblHomeX, plm_dblHomeY );
      			plan.setDesignMovingPos( strat_in, strat_out, dblHomeX, dblHomeY );
				found = plm_dblTempFound;
			}
			break;
		}
	}	
	plan.setDesignMakeTurn(strat_in, strat_out, strat_mem);
};


void InitialSearch::Parameters(double *strat_in, double *strat_out, double *strat_mem)
{
	setInputData( strat_in );
	
	dblHomeX = getXcurrent();
	dblHomeY = getYcurrent();
	
	plm_dblBhvSwitch = 6;   // First behavior is to GoToSearhArea
	
	plm_dblSign = sgn( ( plm_dblLocMaxY + plm_dblLocMinY ) / 2 - getYcurrent() );	// Initialize an searching angle for finding plume 
	plm_dblFindDir = 1;		// Initialize to upwind search				
	found = 0;
	plm_dblNrLeaf = 0;				// 04-23-02 
	
	plm_dblFindBehaviorTime = 0.0;

	
	plm_dblOdorDetc = 0;
	
	plm_dblFindTime = 0;
	plm_dblMatnTime = 0;
	plm_dblLostNum = 0;
	plm_dblRange = stg_iLargNr;
	plm_dblFindFlag = 0;

	plm_dblOldX = 0;
	plm_dblOldY = 0;
	plm_dblWindRcodNr = 0;
	plm_dblMeanNrX = 0;
	plm_dblWindSN = 0;
	plm_dblTau = 1;
	plm_dblGridOldX = -stg_iLargNr;
	plm_dblGridOldY = stg_iLargNr;
	plm_dblReachPos = 0.0;
	plm_dblGoToX = 0.0;
	plm_dblGoToY = 0.0;
	plm_dblRcvFlag = 0;
	plm_dblTempFound = 0;

	plm_dblLostX0 = stg_iLargNr;
	plm_dblLostY0 = stg_iLargNr;

	plm_dblLostX1 = -stg_iLargNr;
	plm_dblLostY1 = -stg_iLargNr;

	plm_dblLostX2 = -stg_iLargNr;
	plm_dblLostY2 = stg_iLargNr;

	plm_dblBoxMinX = stg_iLargNr;
	plm_dblBoxMaxX = stg_iLargNr + 100;
	plm_dblBoxMinY	= -stg_iLargNr;
	plm_dblBoxMaxY = stg_iLargNr;			

	for (int par_ii = 0; par_ii < stg_iGridM; par_ii++)
   		for (int par_ij = 0; par_ij < stg_iGridN; par_ij++)
      		strat_mem[iMapArray0 + par_ii * iArrayL + par_ij] = 0.0;
}

double limit_heading(double hd)
{
	while(hd>=180.0)
  		hd = hd - 360.0;
	while(hd<-180.0)
   		hd = hd + 360.0;
	return(hd);
}

/************************************************************
dist
***********************************************************/
double hdist(double *x, double *y)       // horizontal distance
{
	double dist,d1,d2,dist2;

	d1 = x[0] - y[0];
	d2 = x[1] - y[1];
	dist2 = d1 * d1 + d2 * d2;
	if( dist2 > 0 )
       dist=sqrt(dist2);
    else
       dist=0;

   return(dist);
}

/*************************************************************
Calculate the y boundary condition.
Also used toinitialize the plume for batch sims
**************************************************************/

double boundary(double t)
{
int i;
double rtn;
static double f[3]={ 0, 0, 0 }, amp[3], phs[3];

	if(f[0]==0) 
	{
	//randomize();
		i = 1 + rand() % 2024;
		srand(i);
		f[0] = 0.100 + 0.400 * ( (double)rand() / RAND_MAX );   // .10-.50
		f[1] = 0.020 + 0.030 * ( (double)rand() / RAND_MAX );   // .02-.05
		f[2] = 0.001 + 0.019 * ( (double)rand() / RAND_MAX );   // .001-.02
		amp[0] = 0.100+0.250*((double)rand()/RAND_MAX);   // 0.1-.35                   // -1
		amp[1] = 0.100+0.150*((double)rand()/RAND_MAX);   // 0.1-.25                   // -.1
		amp[2] = 0.010+0.090*((double)rand()/RAND_MAX);   // 0.01-.1
		phs[0] = 2*pi*((double)rand()/RAND_MAX);
		phs[1] = 2*pi*((double)rand()/RAND_MAX);
		phs[2] = 2*pi*((double)rand()/RAND_MAX);
	}

	rtn = amp[0] * sin( t * f[0] + phs[0] ) + 
		  amp[1] * sin( t * f[1] + phs[1] ) + 
		  amp[2] * sin( t * f[2] + phs[2] );
	return(rtn);
}


double sgn(double x)
{
	double y = 1.0;
	if( x < 0.0 )
 		y = -1.0;
	return(y);
}