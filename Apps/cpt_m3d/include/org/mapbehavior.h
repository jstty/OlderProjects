/******************************************************************************
 Map Building Class for Behavior Planning.!

 Author Dr. Wei Li

 Computer Science Department
 California State University, Bakersfield
 Bakersfield, CA 93311

 May 12th, 2002.
*******************************************************************************/

#ifndef MAPBEHAVIOR_H
#define MAPBEHAVIOR_H

#include "IniSearch.h"
#include "../maxmin.h"

class MapBuildingBehavior : public InitialSearch {
	public:
      MapBuildingBehavior( double *strat_in, double *strat_mem, double DT ) 
         : InitialSearch( strat_in, strat_mem )
         {
            dt = DT;
         }

		void CalWind( double *strat_in, double *strat_mem );
		void BackTrace( double *strat_in, double *strat_mem, double sign_det );
   	void RecordWind( double *strat_in, double *strat_mem );
		void CopyWind( double *strat_mem );
		void CalTraject( double *strat_mem );
		void CalProbability( double *strat_mem );
		void CalMaxProbXY( double *strat_mem );
		void ReCalProbability( double *strat_mem );
		void EstimateSource( double *strat_in, double *strat_mem );
		void EstimatePlume( double *strat_mem );

   protected:
      double dt;

   	double 	*map_dblWindPointX, *map_dblWindPointY, *map_dblPointMap, map_dblSumT;
		int		map_iTimeN; //map_ii, map_ij, map_ik;
		int  	map_iSimTime, map_iBaseTime, map_iWindNr, map_iRadiusR;
		double  map_dblEpslon, map_dblSource, map_dblCrit, map_dblSourceRadius;
		double	map_dblGama, map_dblPx0, map_dblPy0;
		double  map_dblLastXToGridX, map_dblLastYToGridY;
		double  map_dblLastXYToGridXY, map_dblRadiusMu; 
		double  map_dblPx[iArrayL], map_dblPy[iArrayL];
		double  map_dblCxy[iArrayL][iArrayL];
		double  map_dblTempProb[iArrayL][iArrayL];
		double  map_dblRectXmin, map_dblRectXmax, map_dblRectYmin, map_dblRectYmax; 
		int 	map_iIndexXY[iArrayL][iArrayL];
		int		map_iTempWindNr, map_iI0, map_iJ0, map_iN0, map_iN1;
		int		map_iNx, map_iNy, map_iNxy, map_iGridX, map_iGridY;
};

#endif