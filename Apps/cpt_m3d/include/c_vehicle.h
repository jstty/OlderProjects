//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_vehicle.h
// Programmer:		Joseph E. Sutton
// Description:	Class to handle Vehicle
// Start Date:		2/8/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __VEHICAL__
#define __VEHICAL__

#define NUM_VEH 1
//#define  NUM_VEH     (N_x*N_y)

#include "env_def.h"
#include "types_structs.h"
#include "i_env_data.h"
#include "c_vehicle_const.h"
#include "s_data.h"

typedef struct _veh_str
{
  double x;             // m
  double y;
  double z;
  double phi;           // radians
  double theta;         // radians
  double omega; 			// heading  , degree
  double u;             // speed, m/s
  double v;
  double w;
  double p;             // rad/s
  double q;
  double r;
  double z_c;				//commanded depth
  double z_i;
  double vel_c;			// commanded speed
  double omega_c;			// commanded heading, degree
  double theta_c;			// commanded pitch
  double omega_i;       // intial heading

  double xth;
  double xu1;
  double xu2;
  
  double snsd[NUM_SENS];// sensed concentration
  double dsd;				// distance trvld to declare the source is found
  double dsf;				// distance trvld to find source
  double dpf;				// distance trvld to find plume
  double det_tm;			// last time of odor det
  double plm_find_tm;   // first time plume is detected
  double src_find_tm;   // time to get within R of source
  double src_dclr_tm;   // time to declare that source is found
  double src_dclr_d;    // distance from source when find flag is set
  double x_real;			// Position that the vehicle reaches
  double y_real;			// Position that the vehicle
  int    src_fnd_flg;	// flag indicating strategy has previously declared success
} veh_str;


// start class
class Vehicle
{
	protected:
      StratagyData *strat;
      char currentBehaviorName[256];

      veh_str veh[NUM_VEH];

      double x_left,
             y_top,
             d_x,
             d_y;

      double  ux_grid[MAX_NODE_X][MAX_NODE_Y], 
              uy_grid[MAX_NODE_X][MAX_NODE_Y];

      float   bck_grnd[GRID_X][GRID_Y];
      double  vh_x[VH_M],
              vh_y[VH_M],
              veh_omega_flag[VH_M];

      int     det_flag[VH_M];

      int batch_not;
      int done_cnt, 
          fnd_cnt,
          veh_plot_cnt;

      int vh_count;

      double Ah[9];   //(3,3)
      double Bh[3];   //(3,1)
      double Ad[16];    //(4,4)
      double Bd[4];    //(4,1)
      double A[36];     //(6,6)
      double B[18];     //(6,3)
      double C[18];     //(6,3)

      double Cd1[16];   //(4,4)
      double Ch1[9];   //(3,3)
      double rw2a[9];    //(3,3)

      double d2r;
      double Mhinv[9];     //(3,3)
      double Mdinv[16];     //(4,4)

      double 	vehicle_pos_x;
      double 	vehicle_pos_y;
      double 	vehicle_pos_z;

      //ChemicalTrail *chem; // don't delete

      int init_flag;

      Point3D last_p;
      
      // settings
      Point3D vehloc;
      Color   color;
      double  dt;
      Point3D srcloc;
      double  threshold;
      double  radius;
      double  max_t;
      
      iEnvData *ed; // DON'T DELETE

   public:
      Vehicle();
      ~Vehicle();

      void Init();
      void Update();

      void GetLastPos(Point3D &p);
      void GetPos(Point3D &p);
      
      double GetHeading();
      
      void GetColor(Color &c);
      
      //
      void SetSettings(Point3D vl, Color c, Point3D sl, double ddt, double dth, double r, double m);
      
      void SetEnvData(iEnvData *edata);
      
      const char *GetCurrentBehaviorName();

   protected:
      void vehicle_update();
      void vehicle_init();

      void vehicle_model(veh_str *vehicl, double Sim_Time);

      double hdist(double *x, double *y);

      void   m_cpy(double* o, const double* m, int r, int c);
      void   m_add(double* o, const double* m1, const double* m2, int r, int c);
      void   m_sub(double* o, const double* m1, const double* m2, int r, int c);
      void   m_mul(double* o, const double* m1, const double* m2, int r, int m, int c);
      void   m_muls(double* o, const double* m, double s, int r, int c);
      void   m_transpose(double* o, const double* m, int r, int c);
      int    m_lud(double* m, int n, int* index);
      void   m_lub(double* m, int n, int* index, double* b);
      void   m_invert(double* o, const double* m, int n);
      double m_trace(const double* m, int n);
};
// end class

#endif // END __VEHICAL__

