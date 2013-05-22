//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_vehicle.h
// Programmer:		Joseph E. Sutton
// Description:	Class to handle Vehicle
// Start Date:		2/8/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __VEHICAL_CONST__
#define __VEHICAL_CONST__

#define  N_x         1
#define  N_y         1
#define  NUM_SENS    1 // (2*ns + 1)  total number of sensors

#define  VH_M 100
#define  NS   0      // 20 # sensors per side

#define mm   41.08
#define Xud  -0.686
#define xg    0.00127
#define Zqd  -2.25
#define Mwd  -2.25
#define Iyy   3.45
#define Mqd -10.3
#define Zw  -80.9
#define Zq  -13.8
#define Mw   38
#define Mq  -15
#define Mth  -7.17
#define Zds -50.6
#define Mds -43.8
#define Uss   1.54
#define Xdp   5
#define Xdr  -0.1
#define Xds  -0.1
#define Yvd -46.3
#define Yrd  -2.25
#define Nvd  -2.25
#define Izz   3.45
#define Nrd -10.3
#define Yv  -80.9
#define Yr  -13.8
#define Nv   38
#define Nr  -15
#define Ydr -50.6
#define Ndr -43.8
#define Ixx   0.177
#define Kdp   0
#define Kpd  -1
#define pv   (Ixx - Kpd)
#define ut   (mm - Xud)
#define Xu  -13.5
#define Ku    0
#define zg    0.0178
#define yg    0
#define Kp   -3
#define Kphi -2
#define xdp   5
#define xdr  -0.1
#define xds  -0.1

const double Md[16] = {mm - Xud,-(mm*xg + Zqd),0,0, 
                       -(mm*xg + Mwd),Iyy - Mqd,0,0,
                       0,0,1,0,
                       0,0,0,1};

const double Cd[16] = {Zw, mm*Uss + Zq, 0, 0, 
                       Mw, -mm*xg*Uss + Mq, 0, Mth,
                       1,0,0,-Uss,
                       0,1,0,0};

const double Dd[4] = {Zds,Mds,0,0};


const double Mh[9] = {mm - Yvd,0,mm*xg - Yrd, 
                      mm*xg - Nvd,0,Izz - Nrd,
                      0,1,0};

const double Ch[9] = {Yv,0,Yr - mm*Uss, 
                      Nv,0,Nr - mm*xg*Uss,
                      0,0,1};

const double Dh[3] = {Ydr,Ndr,0};

const double Ath = -30;
const double Bth = 1;
const double Cth = 1.6449e+003;
const double Dth = -65.1735; 

const double Au[4] = {-6,0,
                       1,0};  // (2,2)
const double Bu[2] = {1,0};   // (2,1)
const double Cu[2] = {25,10}; // (1,2)
const double Du = 0;

/*
extern double Md[16];
extern double Cd[16];
extern double Dd[4];

extern double Mh[9];
extern double Ch[9];
extern double Dh[3];

extern double Ath;
extern double Bth;
extern double Cth;
extern double Dth;

extern double Au[4];
extern double Bu[2];
extern double Cu[2];
extern double Du;
*/

// change this constant to affect the rate at
// which the trail of vehicle arrows is drawn.
#define VEH_MAX_PLT_CNT 100


#endif // __VEHICAL_CONST__
