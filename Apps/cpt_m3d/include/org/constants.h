#ifndef _CONSTANTS_
#define _CONSTANTS_

#define     N_x             1
#define     N_y             1
//#define     NUM_VEH         (N_x*N_y)
#define     Find_Plume  	'Sorc'      // Sorc --> Finding Source; Fdin --> Finding the first detection
#define     x_o         	67.0
#define     y_o         	15.0
#define     x_min       	0.0         // meters
#define     x_max       	100.0        // meters
#define     y_min       	-50.0           // meters
#define     y_max        	50.0        // meters
#define     search_dx_min	10.0			// meters
#define     search_dx_max	10.0       // meters
#define     search_dy_min	20.0       // meters
#define     search_dy_max	20.0        // meters
#define     search_x_min	(x_min + search_dx_min)			// meters
#define     search_x_max	(x_max - search_dx_max)      // meters
#define     search_y_min	(y_min + search_dy_min)      // meters
#define     search_y_max	(y_max - search_dy_max)
#define     N_PUFF      	1500        // size of puff structure
#define     node_n        	15         // number of nodes in the x direction
#define     node_m        	15             // number of nodes in the y direction
#define     mn          	1000
#define     alpha          2
#define    	N_SNS_LOC 4
#define    	pi          	3.14159265359

#define 		ns 	0					// 20 # sensors per side
#define 		lngth 1
#define 		num_sens 1 //(2*ns + 1)  total number of sensors

//sim_win.cpp, trans_mp.cpp
#define     scale_m2p   10
//pixel coordinates of the origin
#define     px0         24
#define     py0        205

//in calculate.cpp, sim_win.cpp
// pixel x range:     0-610
// pixel y range:     0-410
//#define        scale_m2p_x  ((610.0)/(x_max-x_min))
//#define        scale_m2p_y  ((410.0)/(y_max-y_min))

//vehicle.cpp
#define    vh_M 100

// new constants for variable color background
#define     grid_m 100   // number of bins in x direction
#define     grid_n 100   // number of bins in y direction

// bck_grnd[grid_m][grid_n] is defined in odor.h
//#define       T_AVE  180.00   // Concentration averaging time
                                    // Set to zero or negative to turn off
#define     L 1.0          // body frame sensor x coord
#define     d 0.5          // body frame sensor y coord

#endif