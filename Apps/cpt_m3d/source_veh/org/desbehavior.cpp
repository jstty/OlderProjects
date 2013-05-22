/******************************************************************************
 Designed Behavior Class for Behavior Planning.!

 Author Dr. Wei Li

 Computer Science Department
 California State University, Bakersfield
 Bakersfield, CA 93311

 May 12th, 2002.
*******************************************************************************/

#include "../../include/org/desbehavior.h"

/****************************************************************************
**		Designed Behaviors
*****************************************************************************/

void DesignBehavior::MovingPos( double *strat_in, double *strat_out, const double mov_dblX, const double mov_dblY )
{
	double tmp_head, tmp_speed, tmp_distance; 
   	
	tmp_head= atan2( ( mov_dblY - y_current ), ( mov_dblX - x_current ) ) * 180 / pi;
   	tmp_distance = CalDistance( x_current, mov_dblX, y_current, mov_dblY );

	if ( tmp_distance < 10 )
		tmp_speed = 1.0;										// low speed when targer is close; 
	else if ( tmp_distance > 20)
		tmp_speed = 2.0;										// high speed when distance far;
	else
		tmp_speed = 1.0+0.1*(tmp_distance-10.0);   

	hdng_c = tmp_head;
	vel_ch = tmp_speed;
}

void DesignBehavior::CloverLeaf(int iLeafNr, double dblDmeter, 
								double *strat_in, double *strat_out, double *strat_mem)
{
	double	subGoalX, subGoalY, dblGamma, tmp_x0, tmp_y0;
    int i, j;
    Point leafPoint[6];
	static bool tmp_found = false;
	
	dblGamma = plm_dblLeafOrder;
	tmp_x0 = plm_dblLastX;
	tmp_y0 = plm_dblLastY;
	iLeafNr = 2;
	
	for ( i = 0; i < 2*iLeafNr; i++ )
	{
   	leafPoint[i].x = tmp_x0;
		leafPoint[i].y = tmp_y0 ;
		leafPoint[i].z = 0.0;
	}
	
   leafPoint[0].x = dblDmeter * cos( dblGamma*pi/2.0) + tmp_x0;
	leafPoint[0].y = dblDmeter * sin( dblGamma*pi/2.0) + tmp_y0;

   leafPoint[2].x = dblDmeter * cos( -dblGamma*pi/2.0) + tmp_x0;
	leafPoint[2].y = dblDmeter * sin( -dblGamma*pi/2.0) + tmp_y0;


	for ( i = 0; i < 2*iLeafNr; i++ ) 
	{
		if ( tmp_found == true )
		{
			tmp_found = false;
      		plm_dblRcvNum++;
			if ( j == 2*iLeafNr - 1 ) plm_dblRcvNum = iRecoverNum;
		}
		
		j = (int)plm_dblRcvNum - 1;
		
		if ( j <= (2*iLeafNr - 1) ) 
		{
			subGoalX = leafPoint[j].x;
			subGoalY = leafPoint[j].y;
			if ( GoolReach( strat_in, strat_mem, subGoalX, subGoalY ) ) 
				tmp_found = true;
			else
				MovingPos(	strat_in, strat_out, subGoalX, subGoalY );
		}
	}

	plm_dblOdorDetc = 0;
	plm_dblFindTime = 0;
	plm_dblMatnTime = 0;
	
//	test_mn = (int)plm_dblRcvNum;
};

void DesignBehavior::BoxSource(double *strat_in, double *strat_mem)
{
	des_dblGama1 = 0.3;
	des_dblGama2 = 0.3;

	double box_dblPointMetrics;

	setInputData( strat_in );
	SearchArea( strat_mem );

	if ( plm_dblLostNum < 3 ) 
	{
   		if ( plm_dblLostNum == 0 ) { plm_dblLostX0 = plm_dblLastX;
       								 plm_dblLostY0 = plm_dblLastY; }
		if ( plm_dblLostNum == 1 ) { plm_dblLostX1 = plm_dblLastX;
        							 plm_dblLostY1 = plm_dblLastY; }
		if ( plm_dblLostNum == 2 ) { plm_dblLostX2 = plm_dblLastX;
      								 plm_dblLostY2 = plm_dblLastY; }
        plm_dblLostNum++;
	}
	else 
	{
		box_dblPointMetrics = max( CalDistance( plm_dblLastX, plm_dblLostX0,
      									 	 	plm_dblLastY, plm_dblLostY0 ),
								   CalDistance( plm_dblLastX, plm_dblLostX1,
      									 	 	plm_dblLastY, plm_dblLostY1 ) );
		box_dblPointMetrics = max ( box_dblPointMetrics,
                                    CalDistance( plm_dblLastX, plm_dblLostX2,
      									 	     plm_dblLastY, plm_dblLostY2 ) );

   		if ( ( box_dblPointMetrics < 6 * Radius ) ||
			 ( plm_dblLastX < plm_dblBoxMaxX ) )
		{
   			plm_dblLostX0 = plm_dblLostX1;
      		plm_dblLostY0 = plm_dblLostY1;
      		plm_dblLostX1 = plm_dblLostX2;
      		plm_dblLostY1 = plm_dblLostY2;
      		plm_dblLostX2 = plm_dblLastX;
      		plm_dblLostY2 = plm_dblLastY;

      		des_dblMaxXc = max( plm_dblLostX0, plm_dblLostX1 );
      		des_dblMaxXc = max( plm_dblLostX2, des_dblMaxXc );
      		des_dblMinXc = min( plm_dblLostX0, plm_dblLostX1 );
      		des_dblMinXc = min( plm_dblLostX2, des_dblMinXc );
      		des_dblMaxYc = max( plm_dblLostY0, plm_dblLostY1 );
      		des_dblMaxYc = max( plm_dblLostY2, des_dblMaxYc );
      		des_dblMinYc = min( plm_dblLostY0, plm_dblLostY1 );
      		des_dblMinYc = min( plm_dblLostY2, des_dblMinYc );

      		plm_dblBoxMinX = des_dblMinXc;
      		plm_dblBoxMaxX = des_dblMaxXc;
      		plm_dblBoxMinY = des_dblMinYc;
      		plm_dblBoxMaxY = des_dblMaxYc;

			plm_dblRange = CalDistance( des_dblMaxXc, des_dblMinXc,
      									des_dblMaxYc, des_dblMinYc );

      		if ( plm_dblRange <= 6 * Radius ) 
			{ // if Box is not very big, calculate mean value
      			plm_dblMeanX = ( plm_dblMeanX * plm_dblMeanNrX + plm_dblLostX2 ) /
      						   ( plm_dblMeanNrX + 1 );
      			plm_dblMeanY = ( plm_dblMeanY * plm_dblMeanNrX + plm_dblLostY2 ) /
      					       ( plm_dblMeanNrX + 1 );
      			des_iMeanNr = (int)plm_dblMeanNrX;
      			des_iMeanNr++;
      			plm_dblMeanNrX = des_iMeanNr;
      		}
      		else 
			{
         		plm_dblMeanNrX = 0;
         		plm_dblMeanX = 0;
         		plm_dblMeanY = 0;
      		}

     	
			if ( ( plm_dblRange < 4 * Radius ) && 
				 ( plm_dblMeanNrX >= 3 ) && ( plm_dblBhvSwitch != 5 ) ) 
			{
				plm_dblBhvSwitch = 5;
         		plm_dblSourcX = plm_dblMeanX;
         		plm_dblSourcY = plm_dblMeanY;
      		}

      		if ( ( local_time >= stg_iSrchLimitT ) && ( plm_dblBhvSwitch  != 5 ) ) 
			{
      			plm_dblBhvSwitch = 5;
         		plm_dblSourcX = plm_dblMeanX;
         		plm_dblSourcY = plm_dblMeanY;
      		}

      		plm_dblTau = des_dblGama1 * fabs( des_dblMaxXc - des_dblMinXc ) +
      				 	 des_dblGama2 * fabs( des_dblMaxYc - des_dblMinYc );
      		if ( plm_dblTau > 1.0 ) plm_dblTau=1.0;
      		if ( plm_dblTau < 0.3 ) plm_dblTau=0.3;

// Calculate Recovery heading based on probobility

      		des_dblUpFai = atan2( ( plm_dblUpY - y_current ),
      							  ( plm_dblUpX - x_current ) ) * 180 / pi;
      		des_dblDownFai = atan2( ( plm_dblDownY - y_current ),
      							    ( plm_dblDownX - x_current ) ) * 180 / pi;
      		des_dblMitteFai = atan2( ( plm_dblMitteY - y_current ),
      								 ( plm_dblMitteX - x_current ) ) * 180 / pi;

      		des_dblFuzzFai = ( des_dblUpFai + des_dblDownFai + des_dblMitteFai ) / 3.0;

      		plm_dblRcvTime = plm_dblTau * stg_iTau;
      		plm_dblRcvNum = 1;
   		}
	}
};

void DesignBehavior::MakeTurn(double *strat_in, double *strat_out, double *strat_mem)
{
	setInputData( strat_in );
	des_dblHeadErr = hdng_c - heading;
	while ( des_dblHeadErr >= 180 ) des_dblHeadErr = des_dblHeadErr - 360;
	while ( des_dblHeadErr < -180 ) des_dblHeadErr = des_dblHeadErr + 360;

	hdng_c = heading + des_dblHeadErr;
	plm_dblOldHdng = hdng_c;

	if ( fabs(des_dblHeadErr) > 10 ) 
	{
   		if ( fabs(des_dblHeadErr) > 30 ) des_dblHeadErr = 30; 
   		vel_ch = 2 - fabs( des_dblHeadErr / 30 ); // when the vehiche makes turn slowdown 
	}
};