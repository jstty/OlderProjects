/******************************************************************************
  Initialization of sim.!

 Author Prof. Jay Farrell & Yunchun Yang

 Electrical Engineering Department
 University of California, Riverside
 Riverside, CA 92521

 Dec. 18th, 1998.
*******************************************************************************/
#ifndef _ODOR_
#define _ODOR_

typedef  struct{
  double xx;
  double yy;
  double zz;
  double R3; 			// Squared radius
  }puff_str;

extern float bck_grnd[grid_m][grid_n];   // declared in integral.cpp
extern puff_str  puff[N_PUFF];
extern int odor_count;
extern double QQ;

extern void Init_odor_release(int i);

#endif