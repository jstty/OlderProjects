/******************************************************************************
 Map Building Class for Behavior Planning.!

 Author Dr. Wei Li

 Computer Science Department
 California State University, Bakersfield
 Bakersfield, CA 93311

 May 12th, 2002.
*******************************************************************************/

#include "../../include/org/MapBehavior.h"

//#define threshold 0.04		// Million molecules per cubic cm
									// This should be consitent with the
                           // threshold in menu.ini


/****************************************************************************
**		Map Building Behaviors
*****************************************************************************/

void MapBuildingBehavior::CalWind(double *strat_in, double *strat_mem)
{
	map_iSimTime = static_cast<int>(100 * local_time);
	map_iBaseTime = static_cast<int>(stg_iDeltTimeA);
	map_iTimeN = (int)fmod( map_iSimTime, map_iBaseTime );  // record a wind per second

	if ( map_iTimeN == 0 ) {
		map_iWindNr = (int)plm_dblWindRcodNr;
		if ( map_iWindNr < iWindLimitRcrd ) 
		{
			RecordWind( strat_in, strat_mem );
     		map_iWindNr++; plm_dblWindRcodNr = map_iWindNr;
		}
		else 
		{
      		plm_dblWindRcodNr = iWindLimitRcrd - 1;
      		CopyWind( strat_mem );
			RecordWind( strat_in, strat_mem );
		}
	}
};

void MapBuildingBehavior::RecordWind(double *strat_in, double *strat_mem)
{
	//map_iWindNr = (int)plm_dblWindRcodNr;
	map_dblWindPointX = &strat_mem[iWindArrayX0 + map_iWindNr];
	map_dblWindPointY = &strat_mem[iWindArrayY0 + map_iWindNr];
	*map_dblWindPointX = wind_speed * cos(wind_dir * pi / 180);
	*map_dblWindPointY = wind_speed * sin(wind_dir * pi / 180);
};

void MapBuildingBehavior::CopyWind(double *strat_mem)
{
	map_iWindNr = (int)plm_dblWindRcodNr;
	for ( int map_ii = 0; map_ii < map_iWindNr; map_ii++ ) 
	{
   		strat_mem[iWindArrayX0 + map_ii] = strat_mem[iWindArrayX0 + map_ii + 1];
   		strat_mem[iWindArrayY0 + map_ii] = strat_mem[iWindArrayY0 + map_ii + 1];
	}
};

void MapBuildingBehavior::CalTraject(double *strat_mem)
{
	plm_dblWindSN++;
	plm_dblOldX = x_current;
	plm_dblOldY = y_current;
	map_dblPx[0] = x_current;
	map_dblPy[0] = y_current;

	//if ( map_iWindNr > 30 )  map_iWindNr = 30;

	map_iTempWindNr = 0;
	for (int map_ii = map_iWindNr; map_ii >= 0; map_ii--) 
	{
   		map_dblWindPointX = &strat_mem[iWindArrayX0 + map_ii];
		map_dblWindPointY = &strat_mem[iWindArrayY0 + map_ii];
		map_dblPx0 = map_dblPx[map_iWindNr - map_ii] - 
					*map_dblWindPointX * dt * stg_iDeltTimeA;
		map_dblPy0 = map_dblPy[map_iWindNr - map_ii] - 
					*map_dblWindPointY * dt * stg_iDeltTimeA;
		if (( map_dblPx0 > x_min ) && ( map_dblPx0 < x_max ) &&
      		( map_dblPy0 > y_min ) && ( map_dblPy0 < y_max )) 
		{
      		map_iTempWindNr++;
			map_dblPx[map_iWindNr + 1 - map_ii] = map_dblPx0;
			map_dblPy[map_iWindNr + 1 - map_ii] = map_dblPy0;
		}
	}
};

void MapBuildingBehavior::CalProbability( double *strat_mem )
{
	int map_ii, map_ij;
	for ( map_ii = 0; map_ii < iArrayL; map_ii++ )
   		for ( map_ij = 0; map_ij < iArrayL; map_ij++ )
      		map_iIndexXY[map_ii][map_ij] = 0;

	for ( map_ii = 0; map_ii <= map_iTempWindNr; map_ii++ ) 
	{	
		map_iNx = (int)floor( map_dblPx[map_ii] / stg_iBinX );                         			//round down
		map_iNy = (int)floor( map_dblPy[map_ii] / stg_iBinY ) + iMitteY / stg_iBinY;         //round down
		map_iNxy = map_iNx * iArrayL + map_iNy;
		map_dblPointMap = &strat_mem[iMapArray0 + map_iNxy];

		if ( map_iIndexXY[map_iNx][map_iNy] == 0 ) 
		{
      		*map_dblPointMap = *map_dblPointMap * stg_dblBeta + 
				                map_dblGama * ( 1 - stg_dblBeta );
			map_iIndexXY[map_iNx][map_iNy] = 1;
		}
	}

	map_dblSumT = 0.0;
	for ( map_ii = 0; map_ii < stg_iGridM; map_ii++ )
   		for (map_ij = 0; map_ij < stg_iGridN; map_ij++ )
      		map_dblSumT	+= strat_mem[iMapArray0 + map_ii * iArrayL + map_ij];

	for ( map_ii = 0; map_ii < stg_iGridM; map_ii++ ) 
	{
   		for ( map_ij = 0; map_ij < stg_iGridN; map_ij++ ) 
		{
			if ( map_dblSumT > 0.0 )
         		map_dblCxy[map_ii][map_ij] =
            		strat_mem[iMapArray0 + map_ii * iArrayL + map_ij] / map_dblSumT;
			else map_dblCxy[map_ii][map_ij] = 0.0;
			
			map_dblTempProb[map_ii][map_ij] = map_dblCxy[map_ii][map_ij];
		}
	}

};

void MapBuildingBehavior::CalMaxProbXY( double *strat_mem )
{
	map_dblSource = 0.0;
	plm_dblGoToX = 0.0;
	plm_dblGoToY = 0.0;
	for ( int map_ii = 0; map_ii < stg_iGridM; map_ii++ ) 
	{
   		for ( int map_ij = 0; map_ij < stg_iGridN; map_ij++ ) 
		{
      		if ( map_dblSource < map_dblTempProb[map_ii][map_ij] ) 
			{
         		map_dblSource = map_dblTempProb[map_ii][map_ij];
				plm_dblGoToX = map_ii * stg_iBinX;
				plm_dblGoToY = map_ij * stg_iBinY - iMitteY;
			}
		}
	}
};

void MapBuildingBehavior::EstimatePlume( double *strat_mem )
{
	for ( int map_ii = 0; map_ii < stg_iGridM; map_ii++ ) 
   		for ( int map_ij = 0; map_ij < stg_iGridN; map_ij++ ) 				                			
			map_dblTempProb[map_ii][map_ij] = map_dblCxy[map_ii][map_ij];
	
	map_iRadiusR = 4;
	CalMaxProbXY( strat_mem );
	plm_dblSrcPosX1 = plm_dblGoToX;
	plm_dblSrcPosY1 = plm_dblGoToY;
	ReCalProbability( strat_mem );

	CalMaxProbXY( strat_mem );
	plm_dblSrcPosX2 = plm_dblGoToX;
	plm_dblSrcPosY2 = plm_dblGoToY;
	ReCalProbability( strat_mem );

	CalMaxProbXY( strat_mem );
	plm_dblSrcPosX3 = plm_dblGoToX;
	plm_dblSrcPosY3 = plm_dblGoToY;
	ReCalProbability( strat_mem );

	CalMaxProbXY( strat_mem );
	plm_dblSrcPosX4 = plm_dblGoToX;
	plm_dblSrcPosY4 = plm_dblGoToY;
	ReCalProbability( strat_mem );
}

void MapBuildingBehavior::EstimateSource( double *strat_in, double *strat_mem )
{
	for ( int map_ii = 0; map_ii < stg_iGridM; map_ii++ ) 
	{
   		for ( int map_ij = 0; map_ij < stg_iGridN; map_ij++ ) 
		{				                			
			map_dblLastYToGridY = y_current - float(map_ij);    
         	map_dblLastXToGridX = x_current - float(map_ii);
			
			if ( map_dblLastXToGridX < 0 ) 
				map_dblTempProb[map_ii][map_ij] = 0.0;
			else 
				map_dblTempProb[map_ii][map_ij] = map_dblCxy[map_ii][map_ij];
			
			map_dblLastXYToGridXY = sqrt( map_dblLastXToGridX * map_dblLastXToGridX + 
										  map_dblLastYToGridY * map_dblLastYToGridY );
			
			if ( map_dblLastXYToGridXY > 150.0 ) map_dblLastXYToGridXY = 150.0;
			map_dblRadiusMu = 1.0 - map_dblLastXYToGridXY / 150.0;
			map_dblTempProb[map_ii][map_ij] *= map_dblRadiusMu; 
			
			map_dblLastXYToGridXY = stg_iLargNr;
            		
			for ( int map_ik = 0; map_ik < (int)map_iTempWindNr; map_ik++ ) 
			{
            	map_iGridY = (int)floor( map_dblPx[map_ik] / stg_iBinX );                         //round down
         		map_iGridX = (int)floor( map_dblPy[map_ik] / stg_iBinY ) + 50 / stg_iBinY;
                map_dblLastYToGridY = map_iGridY - map_ij;
         		map_dblLastXToGridX = map_iGridX - map_ii;
                map_dblRadiusMu = min(map_dblLastXYToGridXY, sqrt( map_dblLastXToGridX * map_dblLastXToGridX + 
									  map_dblLastYToGridY * map_dblLastYToGridY ));
            }
			if ( map_dblLastXYToGridXY > 150.0 ) map_dblLastXYToGridXY = 150.0;
			map_dblRadiusMu = 1.0 - map_dblLastXYToGridXY / 150.0;
			//map_dblTempProb[map_ii][map_ij] *= map_dblRadiusMu; 
		}
	}
	
	if ( map_iTempWindNr != 0 )
		map_iRadiusR = map_iTempWindNr;
	else
		map_iTempWindNr = 4;

	CalMaxProbXY( strat_mem );
	plm_dblSrcPosX1 = plm_dblGoToX;
	plm_dblSrcPosY1 = plm_dblGoToY;
	ReCalProbability( strat_mem );

	CalMaxProbXY( strat_mem );
	plm_dblSrcPosX2 = plm_dblGoToX;
	plm_dblSrcPosY2 = plm_dblGoToY;
	ReCalProbability( strat_mem );

	map_dblRectXmin = min( plm_dblSrcPosX1, plm_dblSrcPosX2 );
	map_dblRectXmax = max( plm_dblSrcPosX1, plm_dblSrcPosX2 );
	map_dblRectYmin = min( plm_dblSrcPosY1, plm_dblSrcPosY2 );
	map_dblRectYmax = max( plm_dblSrcPosY1, plm_dblSrcPosY2 );

	CalMaxProbXY( strat_mem );
	plm_dblSrcPosX3 = plm_dblGoToX;
	plm_dblSrcPosY3 = plm_dblGoToY;
	ReCalProbability( strat_mem );

	map_dblRectXmin = min( map_dblRectXmin, plm_dblSrcPosX3 );
	map_dblRectXmax = max( map_dblRectXmax, plm_dblSrcPosX3 );
	map_dblRectYmin = min( map_dblRectYmin, plm_dblSrcPosY3 );
	map_dblRectYmax = max( map_dblRectYmax, plm_dblSrcPosY3 );

	//CalMaxProbXY( strat_mem );
	//plm_dblSrcPosX4 = plm_dblGoToX;
	//plm_dblSrcPosY4 = plm_dblGoToY;
	//ReCalProbability( strat_mem );

	//map_dblRectXmin = min( map_dblRectXmin, plm_dblSrcPosX4 );
	//map_dblRectXmax = max( map_dblRectXmax, plm_dblSrcPosX4 );
	//map_dblRectYmin = min( map_dblRectYmin, plm_dblSrcPosY4 );
	//map_dblRectYmax = max( map_dblRectYmax, plm_dblSrcPosY4 );

	plm_dblEstimaX = 0.5 * ( map_dblRectXmin + map_dblRectXmax );
	plm_dblEstimaY = 0.5 * ( map_dblRectYmin + map_dblRectYmax );
	
	map_dblSourceRadius = CalDistance( plm_dblEstimaX, plm_dblLastX, 
									   plm_dblEstimaY, plm_dblLastY );
	if ( ( map_dblSourceRadius < 4 ) && ( plm_dblLostNum ) > 5 ) {
		plm_dblSrcOn = 1;
//		plm_dblEstimaX = 0.5 * ( map_dblRectXmin + map_dblRectXmax );
//		plm_dblEstimaY = 0.5 * ( map_dblRectXmin + map_dblRectXmax );
	}

}

void MapBuildingBehavior::ReCalProbability( double *strat_mem )
{
	if ( map_iRadiusR == 0 ) map_iRadiusR = 4;

	map_iN0 = map_iTempWindNr / map_iRadiusR;
	map_iI0 = (int)plm_dblGoToX;
	map_iJ0 = (int)(plm_dblGoToY + iMitteY);

	for ( int map_ii = 0; map_ii < stg_iGridM; map_ii++ )  {
   		for ( int map_ij = 0; map_ij < stg_iGridN; map_ij++ ) {
      		map_iN1 = (int)CalDistance( map_ii, map_iI0, map_ij, map_iJ0 );
			if ( map_iN1 < map_iN0 ) map_dblTempProb[map_ii][map_ij] = 0.0000;
		}
	}
};

void MapBuildingBehavior::BackTrace(double *strat_in, double *strat_mem, double sign_det)
{
	for ( int map_ii = 0; map_ii < iArrayL; map_ii++ )
   	{	
		map_dblPx[map_ii] = 0.0; 
		map_dblPy[map_ii] = 0.0; 
	}

	map_iWindNr = (int)plm_dblWindRcodNr;
	map_dblEpslon = CalDistance( plm_dblOldX, x_current, plm_dblOldY, y_current );
	if ( sign_det > 0.0 ) { map_dblCrit = 3; map_dblGama = 1.0; }
	else { map_dblCrit = 4.0; map_dblGama = -0.001; }

	if ( ( plm_dblWindSN == 0.0 ) || ( map_dblEpslon > map_dblCrit ) && ( map_iWindNr > stg_iBackNum ) ) {
		
		CalTraject( strat_mem );
		CalProbability( strat_mem );

  		EstimatePlume( strat_mem );      
		//CalMaxProbXY( strat_mem );
		//plm_dblUpX = plm_dblGoToX;
		//plm_dblUpY = plm_dblGoToY;
		//ReCalProbability( strat_mem );

//   Upwind Position

		//CalMaxProbXY( strat_mem );
		//plm_dblDownX = plm_dblGoToX;
		//plm_dblDownY = plm_dblGoToY;
		//ReCalProbability( strat_mem );

// Downwind Position

		//CalMaxProbXY( strat_mem );

		//if ( plm_dblGoToX < plm_dblUpX ) {
		//	plm_dblMitteX = plm_dblUpX;
      	//	plm_dblMitteY = plm_dblUpY;
		//	plm_dblUpX = plm_dblGoToX;
      	//	plm_dblUpY = plm_dblGoToY;
		//}
		//else 
		//{
		//	plm_dblMitteX = plm_dblGoToX;
      	//	plm_dblMitteY = plm_dblGoToY;
		//}

		EstimateSource( strat_in, strat_mem );	
	}
};