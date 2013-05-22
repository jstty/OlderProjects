/******************************************************************************
 Biology Behavior Class for Behavior Planning.!

 Author Dr. Wei Li

 Computer Science Department
 California State University, Bakersfield
 Bakersfield, CA 93311

 May 12th, 2002.
*******************************************************************************/

#include "../../include/org/biobehavior.h"

/****************************************************************************
**		BioLogical Behaviors
*****************************************************************************/

void BiologicalBehavior::FindingSearch(double *strat_in, double *strat_out, double *strat_mem)
{
	double tmp_heading, tmp_speed;
	
	if( getXcurrent() > plm_dblLocMaxX ) 
		plm_dblFindDir = 1;										// Go to upwind search

	if( getXcurrent() < plm_dblLocMinX ) 
		plm_dblFindDir = 0;										// Go to downwind search
	
	if( ( getYcurrent() > plm_dblLocMaxY ) || ( getYcurrent() < plm_dblLocMinY ) )   // Change Search angle sign on Bounds of Y-Axis 
		plm_dblSign = sgn( ( plm_dblLocMaxY + plm_dblLocMinY ) / 2 - getYcurrent() );

	if ( plm_dblFindDir == 1 ) 
		tmp_heading = getWindDir() + plm_dblSign * dblWindUpAng;
	
	if ( plm_dblFindDir == 0 ) 
		 tmp_heading = getWindDir() + plm_dblSign * dblWindDownAng;
	
	tmp_speed = 2.0;

	hdng_c = tmp_heading;
	vel_ch = tmp_speed;
}

void  BiologicalBehavior::MaintainInPlume(double *strat_in, double *strat_out, double *strat_mem)
{
	double tmp_heading, tmp_speed;
	
	if ( plm_dblOdorDetc == 0 ) 
	{ 
		plm_dblOdorDetc = 1; 
		plm_dblMatnTime = 0; 
	}

	plm_dblLastX = getXcurrent();
	plm_dblLastY = getYcurrent();

	plm_dblWindLastDir = getWindDir();
	plm_dblVehLastDir = getHeading();
		
	plm_dblFindFlag = 0;
	plm_dblRcvNum = 1;
	plm_dblOldHdng = hdng_c;

	tmp_speed = 1.0;
	tmp_heading = getWindDir() + 180;
   
	hdng_c = tmp_heading;
	vel_ch = tmp_speed;
}

void BiologicalBehavior::MaintainOutPlume(double *strat_in, double *strat_out, double *strat_mem)
{
	double tmp_heading, tmp_speed;
	double tmp_Px0, tmp_Py0;
	double tmp_angle, tmp_sgn;
	
   tmp_Px0 = plm_dblLastX;
	tmp_Py0 = plm_dblLastY;

	tmp_angle = atan2( ( tmp_Py0 - getYcurrent() ), 
					   ( tmp_Px0 - getXcurrent() ) )*180/pi;

	if ( tmp_angle < 0 ) 
	{
		tmp_sgn = -1;
		plm_dblLeafOrder = 1;
	}
	else 
	{		
		tmp_sgn = +1;
		plm_dblLeafOrder = -1;
	}
	
	tmp_heading = getWindDir() + 180 - tmp_sgn * 90;
	tmp_speed = 1.2;
	
	hdng_c = tmp_heading;
	vel_ch = tmp_speed;
}

