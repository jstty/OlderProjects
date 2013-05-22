/******************************************************************************
 Initial Search Class for Behavior Planning.!

 Author Dr. Wei Li

 Computer Science Department
 California State University, Bakersfield
 Bakersfield, CA 93311

 May 12th, 2002.
*******************************************************************************/

#ifndef INISEARCH_H
#define INISEARCH_H

#ifdef WINDOWS
   #include <windows.h>
#endif

#include <string.h>

#include <math.h>
#include "constants.h"

#include "GlobalDef.h"
#define N_STRAT_MEM 70000         // number of memory elements for strategy

extern double	sgn(double x);
extern double	hdist(double *x, double *y);
extern double	boundary(double t);
extern double	limit_heading(double hd);

/*
extern double	Sim_Time;

extern char		currentBehavior;
extern double	currentXmin;
extern double	currentXmax;
extern double	currentYmin;
extern double	currentYmax;
extern int		pier_width;
extern int		pier_height;

extern void wind(double x,double y, double *u, double *ux_grid, double *uy_grid);
*/

//static double dblSubGoalX;			// subGoal from a Queue (06-20-02)
//static double dblSubGoalY;
//static double dblSubGoalZ;
	

//static int plm_dblBhvSwitch;  		// Behavior Switch
#define plm_dblBhvSwitch  		strat_mem[7]   // Behavior Switch

enum BehaviorStatus { FindPlume = 0, MainInPlume, MainOutPlume, RecoverPlume, 
					  ReturnHome, DeclareSource, GoToSearhArea };

#define plm_dblSign	    		strat_mem[0]
#define plm_dblOldHdng   		strat_mem[1]  	// Defined in the old versions

#define plm_dblLastX 			strat_mem[2]   // Last postion at which the plume
#define plm_dblLastY 			strat_mem[3]   // was detected.
#define plm_dblMeanX    		strat_mem[4]   // Mean values of the last position
#define plm_dblMeanY   			strat_mem[5]   // at which the plume was detected.

#define plm_dblRcvFlag  		strat_mem[6]   // Flag for Recovery Behavior

#define plm_dblFindTime  		strat_mem[8]   // Record plume finding time
#define plm_dblMatnTime  		strat_mem[9]   // Record plume mainting time
#define plm_dblOdorDetc			strat_mem[10]  // Record odor detection
#define plm_dblEndTime     		strat_mem[11]  // Record searching ending time

#define plm_dblRcvNum 			strat_mem[12]  // Recovey behavior numbers
#define plm_dblRcvTime  		strat_mem[13]  // Recovery behavior time
#define plm_dblRcvHead  		strat_mem[14]  // Heading angle in recovery behavior

#define plm_dblFindFlag  		strat_mem[15]  // Finding time behavior flag
#define plm_dblFindDir    		strat_mem[16]
#define plm_dblFindReflcTime    strat_mem[75]  

#define plm_dblLostX0 	 		strat_mem[17]  // Three lost postions
#define plm_dblLostY0 	 		strat_mem[18]
#define plm_dblLostX1 	 		strat_mem[19]
#define plm_dblLostY1 	 		strat_mem[20]
#define plm_dblLostX2 	 		strat_mem[21]
#define plm_dblLostY2 	 		strat_mem[22]

#define plm_dblRange 	 		strat_mem[23]  // Range around the odor
#define plm_dblLostNum 	 		strat_mem[24]  // Lost times

#define plm_dblSourcX 	 		strat_mem[25]  // Location of the source
#define plm_dblSourcY 	 		strat_mem[26]

#define plm_dblOldX				strat_mem[27]  // Previous vehicle location
#define plm_dblOldY				strat_mem[28]

#define plm_dblUpX				strat_mem[29]  // Estimated positions
#define plm_dblUpY 				strat_mem[30]
#define plm_dblDownX			strat_mem[31]
#define plm_dblDownY 			strat_mem[32]
#define plm_dblMitteX			strat_mem[33]
#define plm_dblMitteY 			strat_mem[34]

#define plm_dblWindSpMax 		strat_mem[35]
#define plm_dblWindRcodNr		strat_mem[36]
#define plm_dblWindSN      		strat_mem[37]
#define plm_dblPuffNr			strat_mem[38]

#define plm_dblGridOldX    		strat_mem[39]
#define plm_dblGridOldY    		strat_mem[40]
#define plm_dblGoToX       		strat_mem[41]
#define plm_dblGoToY      		strat_mem[42]

#define plm_dblTau				strat_mem[43]
#define plm_dblLocMinX     		strat_mem[44]
#define plm_dblLocMaxX     		strat_mem[45]
#define plm_dblLocMinY			strat_mem[46]
#define plm_dblLocMaxY			strat_mem[47]
#define plm_dblReachPos    		strat_mem[48]
#define plm_dblWindLastDir 		strat_mem[49]
#define plm_dblVehLastDir    	strat_mem[50]
#define plm_dblMeanNrX			strat_mem[51]
#define plm_dblTempFound		strat_mem[52]

#define plm_dblBoxMinX     		strat_mem[53]
#define plm_dblBoxMaxX     		strat_mem[54]
#define plm_dblBoxMinY			strat_mem[55]
#define plm_dblBoxMaxY			strat_mem[56]

#define plm_dblFindBehaviorTime strat_mem[57]

//#define plm_dblHomeX			strat_mem[60]
//#define plm_dblHomeY			strat_mem[61]
//#define plm_dblStartX			strat_mem[62]
//#define plm_dblStartY			strat_mem[63]
//#define plm_dblStartZ			strat_mem[76]


#define plm_dblSrcPosX1			strat_mem[64]
#define plm_dblSrcPosY1			strat_mem[65]
#define plm_dblSrcPosX2			strat_mem[66]
#define plm_dblSrcPosY2			strat_mem[67]
#define plm_dblSrcPosX3			strat_mem[68]
#define plm_dblSrcPosY3			strat_mem[69]
#define plm_dblSrcPosX4			strat_mem[70]
#define plm_dblSrcPosY4			strat_mem[71]

#define plm_dblSrcOn			strat_mem[72]
#define plm_dblEstimaX			strat_mem[73]
#define plm_dblEstimaY			strat_mem[74]
#define plm_dblNrLeaf           strat_mem[75]	// 04-23-02 by Wei Li
#define plm_dblLeafOrder		strat_mem[76]
  
const int 		stg_iLargNr = 1000;
const int 		stg_iBackNum = 5;
const int 		stg_iBinX = 1;
const int 		stg_iBinY = 1;
const int 		stg_iGridM = 100 / (stg_iBinX);
const int 		stg_iGridN = 100 / (stg_iBinY);
const int 		stg_iDeltTimeA = 100;
const int 		stg_iTau = 400;
const int 		stg_iSrchLimitT = 1000;
const double 	stg_dblBeta = 0.7;
const double	stg_dblEngLimit = 800.0;


// strat_mem[100:199] wind of x direction
// strat_mem[300:399] wind of y direction
//#define 		stg_iWindArrayX0 		100

const int		iWindArrayX0 = 100;
const int		iWindArrayY0 = 300;
const int		iMapArray0 = 1000;
const int		iArrayL = 100;
const int		iMitteY =	50;
const int		iWindLimitRcrd = 30;

const double	dblWindUpAng = 110.0;
const double	dblWindDownAng = 70.0;
const int		iRecoverNum = 6;
const double	dblWindCrossAng = 85.0;
const double	dblOffsetAng =	5.0;
		
//#define plm_dblOdorUp		strat_mem[39]
//#define plm_dblOdorDown    strat_mem[40]
//#define plm_dblOdorMitte	strat_mem[41]
 
 
#define vel_ch	(strat_out[0])
#define hdng_c (strat_out[1])
#define found  (strat_out[2])

#define		CalDistance( x0, x1, y0, y1 ) \
						     sqrt( ((x0)-(x1))*((x0)-(x1))+((y0)-(y1))*((y0)-(y1)))

class InitialSearch {
	public:   	   
		InitialSearch( double *strat_in, double *strat_mem ) 
		{ 
			setInputData(strat_in); 
			SearchArea (strat_mem);
		}
		
		void setInputData ( double *strat_in )
		{
			setXcurrent( strat_in[0] );   // meters, positive to the right
         setYcurrent( strat_in[1] );   // meters, positive downward on the screen
			setWindSpeed( strat_in[2] );	// meters/s
  			setWindDir( strat_in[3] );	// degrees (0 is positive x, 90 is positive y)
			setLocalTime( strat_in[4] );	// seconds
			setVelocity( strat_in[5] );	// m/s
  			setHeading( strat_in[6] );	// degrees
			setSense( &(strat_in[7]) );	// million molecules per cm^3
		}
	   	
		void setXcurrent( double x0 ) { x_current = x0; }
		void setYcurrent( double y0 ) { y_current = y0; }
		void setWindSpeed( double wsp ) { wind_speed = wsp; }
		void setWindDir( double wdr ) { wind_dir = wdr; }
		void setLocalTime( double tm ) { local_time = tm; }
		void setVelocity( double v0 ) { vel = v0; }
		void setHeading( double h0 ) { heading = h0; }
		void setSense( double *conc ) { sens = conc;} 

		double getXcurrent( void ) const { return x_current; }
		double getYcurrent( void ) const { return y_current; }
		double getWindSpeed( void ) const { return wind_speed; }
		double getWindDir( void ) const { return wind_dir; }
		double getLocalTime( void ) const { return local_time; }
		double getVelocity( void ) const { return vel; }
		double getHeading( void ) const { return heading; }
		double getSense( void ) const { return *sens;} 

//		void setOutVel_ch( double v1 ) { vel_ch = v1;}
//		void setFound( double fnd ) { found = fnd; }
//		void setOutHead( double h1 ) { hndg_c = h1; }

//		double getOutVel_ch( void ) { return vel_ch; }
//		double getFound( void ) { return found; }
//		double getOutHead( void ) { return hndg_c; }
		
		
		void SearchArea (double *strat_mem)
		{
         plm_dblLocMinX = x_min;
         plm_dblLocMaxX = x_max;
         plm_dblLocMinY = y_min;
         plm_dblLocMaxY = y_max;
		}

		void Parameters( double *strat_in, double *strat_out, double *strat_mem );

	protected:
		double x_current, y_current, wind_speed, wind_dir;
		double *sens, local_time, vel, heading;
//		double vel_ch, found, hndg_c;
};

#endif