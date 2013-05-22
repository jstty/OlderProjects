//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_vehicle.cpp
// Programmer:		Joseph E. Sutton
// Description:	Class to handle Vehicle
// Start Date:		2/8/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/c_vehicle.h"

#include "../include/org/strats.h"
void MyStratFunc(double *strat_in, double *strat_out, double *strat_mem, 
                 double dt, double radius, double threshold,
                 double Sim_Time,
                 char *currentBehaviorName);

// Constructor
Vehicle::Vehicle()
{
   strat = new StratagyData;
   
   batch_not = 1;
   done_cnt = 0;
   fnd_cnt = 0;
   vh_count = 0;
   max_t = 200.0;

   init_flag = 1;
}

Vehicle::~Vehicle()
{
   if(strat != NULL) delete strat;
}

void Vehicle::SetSettings(Point3D vl, Color c, Point3D sl, double ddt, double dth, double r, double m)
{
   vehloc = vl;
   color  = c;
   
   srcloc = sl;
   dt = ddt;
   threshold = dth;
   radius = r;
   max_t = m;
}

void Vehicle::SetEnvData(iEnvData *edata)
{
   ed = edata;
}


void Vehicle::Init()
{
   memset(veh, 0, NUM_VEH*sizeof(veh_str));

   vehicle_pos_x = vehloc.x;
   vehicle_pos_y = vehloc.y;
   vehicle_pos_x = vehloc.z;

   veh[0].x	      = vehloc.x;
   veh[0].y       = vehloc.y;
   veh[0].z	      = vehloc.z;
   veh[0].phi	   = 0;      // roll
   veh[0].theta   = 0;      // pitch
   veh[0].omega   = 0;      //heading
   veh[0].u	      = 1.6;    // axial velocity
   veh[0].v	      = 0;      // lateral velocity
   veh[0].w	      = 0;      // vertical velocity
   veh[0].p       = 0;      // roll rate
   veh[0].q	      = 0;      // pitch rate
   veh[0].r	      = 0;      // heading rate
   veh[0].z_c	   = 10.0;   // depth command
   veh[0].vel_c   = 1.54;   // velocity command
   veh[0].omega_c	= -150.0; // heading command
   veh[0].theta_c	= 0.0;    // pitch command (control law generated)
   veh[0].omega_i	= 0.0;    // integrated heading error control law generated)
   veh[0].xth	   = 0.0;    // (control state - pitch)
   veh[0].xu1	   = 0.0;    // (control state - velocity)
   veh[0].xu2	   = 0.0;    // (control state - velocity)
   veh[0].dsd	   = 0.0;    // performance state
   veh[0].dsf	   = 0.0;
   veh[0].dpf	   = 0.0;
   veh[0].det_tm  = -100;
   veh[0].plm_find_tm =	10.0*max_t;
   veh[0].src_find_tm =	10.0*max_t;
   veh[0].src_dclr_tm =	10.0*max_t;
   veh[0].src_dclr_d	 =	0.0; // distance from source when find flag is set
   veh[0].src_fnd_flg =	0;   // flag indicating odor detection
}

void Vehicle::GetPos(Point3D &p)
{
	p.x = veh[0].x;
	p.y = veh[0].y;
	p.z = 0;
}

void Vehicle::GetLastPos(Point3D &p)
{
	p.x = last_p.x;
	p.y = last_p.y;
	p.z = 0;
}


void Vehicle::GetColor(Color &c)
{
   c = color;
}

double Vehicle::GetHeading()
{
   double heading;

   if((veh[0].x - last_p.x) != 0)
   {
      heading = atan2((veh[0].y - last_p.y), (veh[0].x - last_p.x));
   } else {
      heading = asin(veh[0].y - last_p.y);
   }

   return heading;
}


const char *Vehicle::GetCurrentBehaviorName()
{
   return currentBehaviorName;
}


// Veh_Integral
void Vehicle::Update()
{
   double wind_dir, hdng, rand_wind=0.0;
	double headrot[4];
	double senspostang[2], vehsenspos[2];
   double chemDensity;
   Point3D vpos;
	double u_wind[3];
	int    i_v,iii,jjj, j;
	static int detect_yet;
   double Sim_Time;
   
   if(ed == NULL) return; // if no enviromental data then return
   Sim_Time = ed->GetSimTime();

   // save last pos
   GetPos(last_p);

	// Simulate the batch of vehicles
    for(i_v = 0; i_v < NUM_VEH; i_v++)
    {
      if(!(veh[i_v].src_fnd_flg))  // if not done
      {
         // following are the lines where the vehicle simulation interfaces
         // with the wind and concentration sensor models.  The wind speed
         // and concentration can be evaluated at any position of interest

         hdng = veh[i_v].omega;
         headrot[0] = cos(hdng);
         headrot[1] = -sin(hdng);
         headrot[2] = sin(hdng);
         headrot[3] = cos(hdng);

         double sensposbody[2];
         for(j = 0; j < NUM_SENS; j++)
         {
            sensposbody[0] = 0;
            sensposbody[1] = 0; // (-ns+j)*lngth/ns;
            m_mul(senspostang, headrot, sensposbody, 2, 2, 1);
            m_add(vehsenspos, &(veh[i_v].x), senspostang, 2, 1);
            
            
            //veh[i_v].snsd[j] = chem->ReadConc(vehsenspos, u_wind);
            {
               vpos.x = vehsenspos[0];
               vpos.y = vehsenspos[1];
               vpos.z = 0.0; // vehsenspos[2]
               ed->ApplyWind(vpos, u_wind);
               chemDensity = ed->GetChemDensity(vpos);
               
               veh[i_v].snsd[j] = chemDensity; 
               vehsenspos[0] = vpos.x;
               vehsenspos[1] = vpos.y;
               //vehsenspos[2] = vpos.z;
            }
         }

         if (i_v==0) rand_wind = 5.0*nrand();
         wind_dir = atan2(u_wind[1],u_wind[0])*180/PI + rand_wind;

         // following is the call to the strategy
         strat->in[0] = veh[i_v].x;
         strat->in[1] = (-1)*veh[i_v].y; // invert because of axis flip
         strat->in[2] = sqrt(u_wind[0]*u_wind[0] + u_wind[1]*u_wind[1]);
         strat->in[3] = wind_dir;
         strat->in[4] = Sim_Time;
         strat->in[5] = veh[i_v].u;
         strat->in[6] = veh[i_v].omega;

         // added by JES. copy global to fit older code
         double src_loc[2];
         src_loc[0] = srcloc.x;
         src_loc[1] = srcloc.y;
         //

         for(j = 7; j < 7 + NUM_SENS; j++)
         {
            strat->in[j] = veh[i_v].snsd[j-7];
         }

         strat->out[0]= veh[i_v].vel_c;       // Initialize output values
         strat->out[1]= veh[i_v].omega_c;     // Initialize output values
         strat->out[2]= veh[i_v].src_fnd_flg; // Initialize output values

         //-------------------------Call Strategy----------------------------------------------
         MyStratFunc(strat->in, 
			            strat->out, 
					      &(strat->mem[N_STRAT_MEM*i_v]), 
                     dt, 
                     radius, 
                     threshold,
                     Sim_Time,
                     currentBehaviorName
                    );
         //-------------------------Return from strategy----------------------------------------------

         veh[i_v].vel_c   = strat->out[0];
         veh[i_v].omega_c = strat->out[1];

         // The source found flag once set is set for the run
         veh[i_v].src_fnd_flg   =  ((strat->out[2])||(veh[i_v].src_fnd_flg));

         x_left=0.0;
         y_top=-50;
         d_x=1;
         d_y=1;

         if( veh[i_v].snsd[0] > threshold)
         {
            veh[i_v].det_tm = Sim_Time;         // store most recent detection time

            if(veh[i_v].plm_find_tm > Sim_Time)
               veh[i_v].plm_find_tm = Sim_Time;   // record time of first detection
         }

         if( ( hdist(&(veh[i_v].x), src_loc) < radius) && // near the source
             ( veh[i_v].src_find_tm > Sim_Time) )         // for the first time
         {
            veh[i_v].src_find_tm = Sim_Time; // store the frst tm near src
            fnd_cnt++;
         }   // if near source

         if( (veh[i_v].src_fnd_flg) &&
             (veh[i_v].src_dclr_tm > Sim_Time) )
         {
            // Graphics --------------------------------------------
            if( (batch_not == 1) &&
                (i_v ==0 ) )
            {
               for(iii = 0; iii < GRID_X; iii++)
               {
                  for(jjj = 0; jjj < GRID_Y; jjj++) 
                  {
                     bck_grnd[iii][jjj] = (float)(strat->mem[1000+iii*100+jjj]);
                  }
               }

               // RESET!
               veh[i_v].x = vehicle_pos_x; // ((double)random(100))*(x_max-x_min)/100.0 + x_min;
               veh[i_v].y = vehicle_pos_y; // ((double)random(100))*(y_max-y_min)/100.0 + y_min;
               veh[i_v].z = vehicle_pos_z; // ((double)random(100))*(z_max-z_min)/100.0 + z_min;
               veh[i_v].omega_c = nrand()*180.0;
               veh[i_v].dsd = 0.0;
               veh[i_v].dsf = 0.0;
               veh[i_v].dpf = 0.0;
               veh[i_v].det_tm = -100;
               veh[i_v].plm_find_tm = 1e8;
               veh[i_v].src_find_tm = 1e8;
               veh[i_v].src_dclr_tm = 1e8;
               veh[i_v].src_dclr_d  = 0.0;
               veh[i_v].snsd[NS + 1] = 0;  
               veh[i_v].src_fnd_flg = 0;

               
            }
            // --------------------------------------------
            else
            {
               veh[i_v].src_dclr_tm = Sim_Time;  // store tm of first src found flag
               veh[i_v].src_dclr_d = hdist(&(veh[i_v].x), src_loc);
               veh[i_v].x_real=veh[i_v].x;
               veh[i_v].y_real=veh[i_v].y;
               veh[i_v].vel_c  = 0;            // stop this vehicle
               done_cnt++;                     // veh is done
            }

         }  //  if src fnd flag

         vehicle_model(&(veh[i_v]), Sim_Time);        // advance vehicle to next time

         //Graphics --------------------------------------------
         if((batch_not==1)&&(i_v==0))
         {  // Have we detected anything this interval

            detect_yet = ( (veh[i_v].snsd[0] > threshold) || (detect_yet) );
            veh_plot_cnt++;  // track interval

            if(veh_plot_cnt >= VEH_MAX_PLT_CNT)
            {
               veh_plot_cnt = 0;

               if(vh_count < VH_M)
               {
                  det_flag[vh_count] 		 = detect_yet;
                  detect_yet 			   	 = 0;
                  veh_omega_flag[vh_count] = veh[0].omega*PI/180.0;
                  vh_x[vh_count] 			 = veh[0].x;
                  vh_y[vh_count] 			 = veh[0].y;
                  vh_count++;
               }
               else
               {
                  vehicle_update();
                  det_flag[VH_M-1] 			= detect_yet;
                  detect_yet 					= 0;
                  veh_omega_flag[VH_M-1]	= veh[0].omega*PI/180.0;
                  vh_x[VH_M-1] 				= veh[0].x;
                  vh_y[VH_M-1] 				= veh[0].y;
               }

            } // veh_plot_cnt
         }   // not batch
         // --------------------------------------------

      }   // if not vehicle done
   }   // for each vehicle

   init_flag = 0;
}

void Vehicle::vehicle_update()
{
   int i;
   for(i = 1; i < VH_M; i++)
   {
      vh_x[i-1] = vh_x[i];
      vh_y[i-1] = vh_y[i];
      det_flag[i-1] = det_flag[i];
      veh_omega_flag[i-1]= veh_omega_flag[i];
   }
}


//Added by Fang Chen
void Vehicle::vehicle_init()
{
  	veh[0].x	      = vehicle_pos_x;
  	veh[0].y	      = vehicle_pos_y;
  	veh[0].z	      = vehicle_pos_z;
  	veh[0].phi	   = 0;      // roll
  	veh[0].theta   = 0;      // pitch
  	veh[0].omega   = 0;      //heading
	veh[0].u	      = 1.6;    // axial velocity
	veh[0].v	      = 0;      // lateral velocity
	veh[0].w	      = 0;      // vertical velocity
	veh[0].p	      = 0;      // roll rate
	veh[0].q	      = 0;      // pitch rate
	veh[0].r	      = 0;      // heading rate
  	veh[0].z_c	   = 10.0;   // depth command
  	veh[0].vel_c	= 1.54;   // velocity command
  	veh[0].omega_c	= -150.0; // heading command
  	veh[0].theta_c	= 0.0;    // pitch command (control law generated)
	veh[0].omega_i	= 0.0;    // integrated heading error control law generated)
	veh[0].xth	   = 0.0;    // (control state - pitch)
	veh[0].xu1	   = 0.0;    // (control state - velocity)
	veh[0].xu2	   = 0.0;    // (control state - velocity)
	veh[0].dsd	   = 0.0;    // performance state
	veh[0].dsf	   = 0.0;
	veh[0].dpf	   = 0.0;
  	veh[0].det_tm	= -100;
  	veh[0].plm_find_tm = 10.0*max_t;
  	veh[0].src_find_tm = 10.0*max_t;
  	veh[0].src_dclr_tm = 10.0*max_t;
	veh[0].src_dclr_d	 = 0.0;  // distance from source when find flag is set
	veh[0].src_fnd_flg = 0;    // flag indicating odor detection
}


void Vehicle::vehicle_model(veh_str *vehicl, double Sim_Time)
{
  	//char dummy[256];
  	double dp,dr,ds;
  	//double dp1;
  	double u[3];
  	static double u_old,old_phi,old_theta,old_omegac;
  	double heading_rads;
  	double head_err, depth_err, pitch_err, prop_err;
  	static double cosomega, sinomega;
  	static double costheta, sintheta, tantheta;
  	static double cosphi, sinphi;
  	static double rb2t[9];    //(3,3)
  	static double rt2b[9];    //(3,3)

  	double *pos;
  	double *ang;
  	double *vect;

  	double dpos[3];
  	double dang[3];
  	double dvect[6];

  	double dvec1[6];
  	double dvec2[6];
  	double dvec3[6];
  	double dvec4[6];
  	double dxth;
  	double dxuv[2];
  	double dxu1[2];
  	double dxu2[2];
   int i;

  	(*vehicl).phi = (*vehicl).phi*PI/180;       // Wei
	(*vehicl).theta = (*vehicl).theta*PI/180;

  	if (init_flag == 1) {
  		m_invert(Mhinv,Mh,3);
      m_mul(Ah,Mhinv,Ch,3,3,3);
      m_mul(Bh,Mhinv,Dh,3,3,1);

      m_invert(Mdinv,Md,4);
      m_mul(Ad,Mdinv,Cd,4,4,4);
      m_mul(Bd,Mdinv,Dd,4,4,1);

      memset(A, 0, 36*sizeof(double));
      A[0] = Xu/(mm - Xud);        //(0,0)
   	A[7] = Ah[0];                //(1,1)=(0,0)
      A[11] = Ah[2];               //(1,5)=(0,2)
      A[14] = Ad[0];               //(2,2)=(0,0)
      A[16] = Ad[1];               //(2,4)=(0,1)
      A[21] = Kp/(Ixx - Kpd);      //(3,3)
      A[23] = (*vehicl).u*mm*zg;   //(3,5)
      A[26] = Ad[4];               //(4,2)=(1,0)
      A[28] = Ad[5];               //(4,4)=(1,1)
      A[31] = Ah[6];               //(5,1)=(2,0)
      A[35] = Ah[8];               //(5,5)=(2,2)

      memset(B, 0, 18*sizeof(double));
      B[0] = Xdp/(mm-Xud);         //(0,0)
      B[1] = Xdr/(mm-Xud);         //(0,1)
      B[2] = Xds/(mm-Xud);         //(0,2)
      B[4] = Bh[0];                //(1,1)=(0,0)
      B[8] = Bd[0];                //(2,2)=(0,0)
      B[9] = Kdp/(Ixx-Kpd);        //(3,0)
      B[14] = Bd[1];               //(4,2)=(1,0)
      B[16] = Bh[2];               //(5,1)=(2,0)

      memset(C, 0, 18*sizeof(double));
      C[5] = Ah[1];                //(1,2)=(0,1)
      C[7] = Ad[3];                //(2,1)=(0,3)
      C[9] = Kphi/(Ixx-Kpd);       //(3,0)
      C[13] = Ad[7];               //(4,1)=(1,3)
      C[17] = Ah[7];               //(5,2)=(2,1)

      for(i = 0; i < 16; i++) {
	 		Cd1[i]=Cd[i];
  	   }

      for(i = 0; i < 9; i++) {
	 		Ch1[i]=Ch[i];
  	   }

     	d2r = PI/180.0;

     	rw2a[0] = 1;                    //(0,0)
     	rw2a[3] = 0;                    //(1,0)
     	rw2a[6] = 0;                    //(2,0)

     	u_old = 100;
     	old_phi = 100;
     	old_theta = 100;
     	old_omegac = 100;
	}

   if(abs((int)((*vehicl).u - u_old))>0.2){
   	u_old = (*vehicl).u;
	   Cd1[1] = (*vehicl).u*mm + Zq;       //(0,1)
 		Cd1[4] = (*vehicl).u*(-mm)*xg + Mq; //(1,1)
  		Cd1[11] = -(*vehicl).u;             //(2,3)

  		Ch1[2] = Yr - (*vehicl).u*mm;       //(0,2)
  		Ch1[5] = Nr - (*vehicl).u*mm*xg;    //(1,2)

 		m_mul(Ah,Mhinv,Ch1,3,3,3);
  		m_mul(Ad,Mdinv,Cd1,4,4,4);

  		A[23] = (*vehicl).u*mm*zg;        //(3,5)
  		A[35] = Ah[8];                    //(5,5)=(2,2)
  		A[16] = Ad[1];                    //(2,4)=(0,1)
  		A[28] = Ad[5];                    //(4,4)=(1,1)
   } 

  	heading_rads = (*vehicl).omega*d2r;

   	old_phi =  (int)((*vehicl).phi);
   	old_theta = (*vehicl).theta;
   	old_omegac = (*vehicl).omega;

  		cosomega = cos(heading_rads);
  		costheta = cos((*vehicl).theta); //wei
  		sinomega = sin(heading_rads);
  		sintheta = sin((*vehicl).theta);
  		cosphi   = cos((*vehicl).phi);
  		sinphi   = sin((*vehicl).phi);
  		tantheta = tan((*vehicl).theta);

  		rt2b[0] = cosomega*costheta;               //(0,0)
  		rt2b[1] = sinomega*costheta;               //(0,1)
  		rt2b[2] = -sintheta;                       //(0,2)
  		rt2b[3] = -sinomega*cosphi+cosomega*sintheta*sinphi;       //(1,0)
  		rt2b[4] = cosomega*cosphi+sinomega*sintheta*sinphi;        //(1,1)
  		rt2b[5] = costheta*sinphi;                                 //(1,2)
  		rt2b[6] = sinomega*sinphi+cosomega*sintheta*cosphi;        //(2,0)
  		rt2b[7] = -cosomega*sinphi+sinomega*sintheta*cosphi;       //(2,1)
  		rt2b[8] = costheta*cosphi;                                 //(2,2)

  		m_transpose(rb2t,rt2b,3,3);

  		rw2a[1] = sinphi*tantheta;                                //(0,1)
  		rw2a[2] = cosphi*tantheta;                                //(0,2)
  		rw2a[4] = cosphi;                                         //(1,1)
  		rw2a[5] = -sinphi;                                        //(1,2)
  		rw2a[7] = sinphi/costheta;                                //(2,1)
  		rw2a[8] = cosphi/costheta;                                //(2,2)

  	pos  = &((*vehicl).x);
  	ang  = &((*vehicl).phi);
  	vect = &((*vehicl).u);

  //---------------------------heading control---------------------------------

  	head_err = ((vehicl->omega_c) - (vehicl->omega));			// degrees
  	head_err = head_err*d2r;											// radians
  	while(head_err>PI)
  	   head_err = head_err - 2.0*PI;

	while(head_err<-PI)
   	head_err = head_err + 2.0*PI;

  	dr = head_err*-0.2;                                     // Calculate dr

  //--------------------------------depth control-----------------------------

  	depth_err = (*vehicl).z_c - (*vehicl).z;
  	(*vehicl).theta_c = (-0.772*depth_err);

  	if((*vehicl).theta_c>0.5)
  	  	(*vehicl).theta_c = 0.5;
  	if((*vehicl).theta_c<-0.5)
  		(*vehicl).theta_c = -0.5;

  	pitch_err = ((*vehicl).theta_c - (*vehicl).theta);
  	ds = ((*vehicl).xth)*Cth + Dth*pitch_err;         // Calculate ds

  	if(ds>0.8)                                    // saturation
  	  	ds = 0.8;
  	if(ds<-0.8)
     ds = -0.8;

  //-----------------------------propulsion control---------------------------

  	prop_err = (*vehicl).vel_c - (*vehicl).u;
  	dp = Cu[0]*(*vehicl).xu1 + Cu[1]*(*vehicl).xu2 + prop_err*Du; // Calculate dp

  	u[0] = dp;
  	u[1] = dr;
  	u[2] = ds;

  	m_mul(dpos,rb2t,vect,3,3,1);
  	m_mul(dang,rw2a,(vect+3),3,3,1);

  	m_mul(dvec1,A,vect,6,6,1);
  	m_mul(dvec2,B,u,6,3,1);
  	m_mul(dvec3,C,ang,6,3,1);
  	m_add(dvec4,dvec1,dvec2,6,1);

  	m_add(dvect,dvec3,dvec4,6,1);

  	m_mul(dxu1,Au,&((*vehicl).xu1),2,2,1);
  	m_muls(dxu2,Bu,prop_err,2,1);
  	m_add(dxuv,dxu1,dxu2,2,1);

  	dxth = (Ath*((*vehicl).xth) + Bth*pitch_err);       // jay
  	(*vehicl).xth += dxth*dt;

   /*
  	for (i=0;i<3;i++) {    // jay
	 	pos[i] += dpos[i]*dt;
  	}
   */
   pos[0] += dpos[0]*dt;      // x
   pos[1] += (-1)*dpos[1]*dt; // y, invert because of axis flip
   pos[2] += dpos[2]*dt;      // z
   //

  	for (i=0;i<2;i++){        //jay
  	 	ang[i] += dang[i]*dt;  //Wei
  	}
  	ang[2] += dang[2]*dt*180.0/PI;

   (*vehicl).phi = ang[0]*180/PI;       // Wei
	(*vehicl).theta = ang[1]*180/PI;
   (*vehicl).omega = ang[2];

  	for (int j=0;j<6;j++){
  		vect[j] += dvect[j]*dt;
  	}

  	(*vehicl).xu1 += dxuv[0]*dt;
  	(*vehicl).xu2 += dxuv[1]*dt;

	//--------------------------------------------------------------------------

  	if(((*vehicl).src_find_tm) > Sim_Time){      // if not source found
  		(*vehicl).dsf   += ((*vehicl).u)*(dt);}	// integrated path length to source
  	if(((*vehicl).plm_find_tm) > Sim_Time){      // if not plume found
  		(*vehicl).dpf   += ((*vehicl).u)*(dt);}	// integrated path length to plume
  	if(!((*vehicl).src_fnd_flg)){      			   // if src fnd has not been declared
  		(*vehicl).dsd   += ((*vehicl).u)*(dt);}	// integrated path length to plume

  	while((*vehicl).omega >= 180.0)
  		(*vehicl).omega = (*vehicl).omega - 360.0;
  	while((*vehicl).omega < -180.0)
   	(*vehicl).omega = (*vehicl).omega + 360.0;
}


/************************************************************
dist
***********************************************************/
double Vehicle::hdist(double *x, double *y) // horizontal distance
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

/*
 * Matrix assignment.
 * ==================
 *
 * Input
 *  m : Source matrix.
 *  r : Number of row elements.
 *  c : Number of col elements.
 *
 * Output
 *  o : Destination matrix.
 */
void Vehicle::m_cpy(double* o, const double* m, int r, int c)
{
   memcpy(o, m, r*c*sizeof(double));
}

/*
 * Matrix addition.
 * ================
 *
 * Input
 *  m1 : Matrix #1.
 *  m2 : Matrix #2.
 *  r : Number of row elements.
 *  c : Number of col elements.
 *
 * Output
 *  o : Gets m1 + m2.
 *
 * Note
 *  Arg o can be the same as m1 or m2.
 */
void Vehicle::m_add(double* o, const double* m1, const double* m2, int r, int c)
{
  int i, n;

  for(n = r*c, i=0; i < n; i++)
    o[i] = m1[i] + m2[i];
}


/*
 * Matrix subtraction.
 * ===================
 *
 * Input
 *  m1 : Matrix #1.
 *  m2 : Matrix #2.
 *  r : Number of row elements.
 *  c : Number of col elements.
 *
 * Output
 *  o : Gets m1 - m2.
 *
 * Note
 *  Arg o can be the same as m1 or m2.
 */
void Vehicle::m_sub(double* o, const double* m1, const double* m2, int r, int c)
{
  int i, n;

  for(n = r*c, i = 0; i < n; i++)
    o[i] = m1[i] - m2[i];
}

/*
 * Matrix multiply.
 * ================
 *
 * Input
 *  m1 : Matrix #1.
 *  m2 : Matrix #2.
 *  r : Number of row elements of m1.
 *  m : Number of col elemtens of m1, and row elements of m2.
 *  c : Number of col elements of m2.
 *
 * Output
 *  o : Gets m1 * m2.
 *
 * Note
 *  Arg o can not be the same as m1 or m2.
 */
void Vehicle::m_mul(double* o, const double* m1, const double* m2, int r, int m, int c)
{
   int i, j, k;

   for(i=0; i<r; i++)
   {
      for(j=0; j<c; j++)
      {
         for(o[i*c+j]=0.0, k=0; k<m; k++)
            o[i*c+j] += m1[i*m+k] * m2[k*c+j];
      }
   }
}

/*
 * Matrix scalar multiply.
 * =======================
 *
 * Input
 *  m1 : Matrix #1.
 *  s : Scalar.
 *  r : Number of row elements.
 *  c : Number of col elements.
 *
 * Output
 *  o : Gets m1 * s.
 *
 * Note
 *  Arg o can be the same as m.
 */
void Vehicle::m_muls(double* o, const double* m, double s, int r, int c)
{
  int i, n;

  for(n=r*c, i=0; i<n; i++)
    o[i] = m[i] * s;
}

/*
 * Matrix transpose.
 * =================
 *
 * Input
 *  m : Matrix.
 *  r : Number of row elements.
 *  c : Number of col elements.
 *
 * Output
 *  o : Gets the transpose of m1.
 *
 * Note
 *  Arg o can not be the same as m.
 */
void Vehicle::m_transpose(double* o, const double* m, int r, int c)
{
   int i, j;

   for(i=0; i<r; i++)
   {
      for(j=0; j<c; j++)
         o[j*r+i] = m[i*c+j];
   }
}

/*
 * Internal. Matrix lud.
 * =====================
 */
int Vehicle::m_lud(double* m, int n, int* index)
{
  int i, j, k, i_max;
  double d_max, d_temp, d_dum;
  double* pivot = (double*) malloc(sizeof(double)*n);

  // Check memory allocation.
  if( !pivot )
    return 0;

  // Calculate pivots.
  for(i=0; i<n; i++)
  {
    // Find largest element.
    for(d_max = 0.0, j=0; j<n; j++)
    {
      d_temp = fabs(m[i*n+j]);
      if( d_temp > d_max )
         d_max = d_temp;
    }

    // Check for signularity.
    if( d_max == 0.0 )
      return 0;
      
    pivot[i] = 1.0 / d_max;
  }

  // Partition.
  for(j=0; j<n; j++)
  {
    for(i=0; i<j; i++)
    {
      for(d_temp = m[i*n+j], k=0; k<i; k++)
         d_temp -= m[i*n+k] * m[k*n+j];
         
      m[i*n+j] = d_temp;
    }
    
    for(d_max=0.0, i=j; i<n; i++)
    {
      for(d_temp = m[i*n+j], k=0; k<j; k++)
         d_temp -= m[i*n+k] * m[k*n+j];
         
      m[i*n+j] = d_temp;
      d_dum = pivot[i] * fabs(d_temp);
      
      if( d_dum >= d_max )
      {
         d_max = d_dum;
         i_max = i;
      }
    }
    
    if( j != i_max )
    {
      for(k=0; k<n; k++)
      {
         d_dum = m[i_max*n+k];
         m[i_max*n+k] = m[j*n+k];
         m[j*n+k] = d_dum;
      }
      
      pivot[i_max] = pivot[j];
    }
    
    index[j] = i_max;
    if( m[j*n+j] == 0.0 )
      m[j*n+j] = 1e-20;
      
    if( j != n )
    {
      d_dum = 1.0 / m[j*n+j];
      
      for(i=j+1; i<n; i++)
         m[i*n+j] *= d_dum;
    }
  }
  free(pivot);
  
  return 1;
}

/*
 * Internal. Matrix lub
 * =====================
 */
void Vehicle::m_lub(double* m, int n, int* index, double* b)
{
  int i, j, k = 0, ip;
  double d_sum;

  for(i=0; i<n; i++)
  {
    ip = index[i];
    d_sum = b[ip];
    b[ip] = b[i];
    if( k )
    {
      for(j=k-1; j<i; j++)
         d_sum -= m[i*n+j] * b[j];
    }
    else if( d_sum )
    {
      k = i+1;
    }
      
    b[i] = d_sum;
  }
  
  for(i=n-1; i>=0; i--)
  {
    for(d_sum=b[i], j=i+1; j<n; j++)
      d_sum -= m[i*n+j] * b[j];
      
    b[i] = d_sum / m[i*n+i];
  }

}

/*
 * Matrix inverse.
 * ===============
 *
 * Input
 *  m : Matrix.
 *  n : Number of row/col elements.
 *
 * Output
 *  o : Gets the inverse of m.
 *
 * Note
 *  Arg o can be the same as m.
 */
void Vehicle::m_invert(double* o, const double* m, int n)
{
  int i, j;
  int* index = (int*) malloc(sizeof(int)*n);
  double* col = (double*) malloc(sizeof(double)*n);
  double* t = (double*) malloc(sizeof(double)*n*n);

  // Check memory allocation.
  if( !index || !col || !t )
    return;

  // Save a copy of m.
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
      t[i*n+j] = m[i*n+j];
  }

  // Compute inv.
  if( m_lud(t, n, index) )
  {
    for(j=0; j<n; j++)
    {
      for(i=0; i<n; i++)
         col[i] = 0.0;
         
      col[j] = 1.0;
      m_lub(t, n, index, col);
      
      for(i=0; i<n; i++)
         o[i*n+j] = col[i];
    }
  }

  free(index);
  free(col);
  free(t);
}

/*
 * Matrix trace.
 * =============
 *
 * Input
 *  m : Matrix.
 *  n : Number of row/col elements.
 *
 * Return
 *  The trace of m.
 */
double Vehicle::m_trace(const double* m, int n)
{
  int i, j;
  double trace = 0.0;

  // Add diagonal elements.
   for(i = 0; i < n; i++)
   {
      for(j = 0; j < n; j++)
      {
         if(i == j)
            trace += m[i*n + j];
      }
   }

   return trace;
}


