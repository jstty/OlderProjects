//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_chemical_trail.cpp
// Programmer:		Joseph E. Sutton
// Description:	Class to generate Dynamic Chemical Trail
// Start Date:		2/8/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/cpts.h"
#include "../include/c_chemical_trail.h"
extern Settings *settings;

// Constructor
ChemicalTrail::ChemicalTrail()
{
   Count = 0;

   wind = NULL;

   mChem = new Point3D[MAX_CHEM_POINTS];
   memset(mChem, 0, MAX_CHEM_POINTS*sizeof(Point3D));
   mCount = 0;

   mChemMaxY = -1000.0;
   mChemMinY =  1000.0;
}

ChemicalTrail::~ChemicalTrail()
{
   delete [] mChem;
}

void ChemicalTrail::SetSettings(double ddt, Point3D dsp, Point3D dsi, uInt32 donps, double dpl, double dpgr, double dth)
{
   dt = ddt;
   speed = dsp;
   sigma = dsi;
   odor_num_per_second = donps;
   plume_length = dpl;
   puffs_growth_rate = dpgr;
   threshold = dth;
}

void ChemicalTrail::Init(Wind *w, Point3D s)
{
   uInt32 i;
   double tst, tst1;
   double t, R_cubed;
   wind = w;
   start = s;

   // Assume 100 sec of prev. release
   mCount = odor_num_per_second*100;
   if(mCount > MAX_CHEM_POINTS)
   {
      mCount = MAX_CHEM_POINTS;
   }

   for(i = 0; i < MAX_CHEM_POINTS; i++)
   {
      //initialize the odor puff structure
      if(i < mCount)
      {
         // assume 1 m/s wind vel
         mChem[i].x = start.x + i * 1.0 / odor_num_per_second;

         
         tst  = ((double)rand()/RAND_MAX);
         tst1 = Boundary(mChem[i].x);

         mChem[i].y   = start.y + 
                        tst1 + 
                        0.1 * sqrt(mChem[i].x) * 
                       (2.0 * tst - 1.0);
         mChem[i].z   = 0.0;
         mChem[i].rad = 0.01;
      }
      else
      {
		  mChem[i].x = start.x;
		  mChem[i].y = start.y;

		  mChem[i].z = 0.000;
		  mChem[i].rad = 0.001;
      }
   }

   t = plume_length/speed.x;

   R_cubed = pow(puffs_growth_rate*t,1.5);
   mQQ = threshold * 15.7494 * R_cubed * 1e6;
}

uInt32  ChemicalTrail::GetMax()
{
   return mCount;
}

void ChemicalTrail::GetPoint(int i, Point3D &p)
{
   p.x = mChem[i].x;
   p.y = mChem[i].y;
   p.z = mChem[i].z;
   p.rad = mChem[i].rad;
   
   p.den = CalcDensity(mChem[i].x, mChem[i].y, mChem[i].z);
}


// called each loop to update chemical points
// Puff_Integral
void ChemicalTrail::Update()
{
   double  wx,wy,wz,u_wind[3];
   uInt32  i;
   
   /*
   fprintf(stderr, "p(%f, %f, %f), mCount: %d, MAX_CHEM_POINTS: %d\n", 
      start.x, start.y, start.z, 
      mCount, MAX_CHEM_POINTS);
   */

   // Simulate transport dynamics of odor filaments
   for(i = 0; i < mCount; i++)
   {
      // centerline relative dispersion
      wx = sigma.x * (((double)rand()/RAND_MAX)-0.5)*2.0; //(random(100)/50.-.99);    //get W, the random driving noise
      wy = sigma.y * (((double)rand()/RAND_MAX)-0.5)*2.0; //(random(100)/50.-.99);
      wz = sigma.z * (((double)rand()/RAND_MAX)-0.5)*2.0; //(random(100)/50.-.99);
   
      //advection
      wind->Apply(mChem[i].x, mChem[i].y, u_wind);
               
      // Euler integration of puff position
      mChem[i].x += (u_wind[0] + wx)*dt; //the position in meter
      mChem[i].y += (u_wind[1] + wy)*dt;
      mChem[i].z += (u_wind[2] + wz)*dt;

		if(mChemMaxY < mChem[i].y) mChemMaxY = mChem[i].y;
		if(mChemMinY > mChem[i].y) mChemMinY = mChem[i].y;

		// puff growth
      mChem[i].rad = mChem[i].rad +
                     puffs_growth_rate *
                     dt;
      //calculate the square of the radius.

      if( (mChem[i].x < X_MIN) ||
          (mChem[i].x > X_MAX) ||
          (mChem[i].y < Y_MIN-10.) || 
          (mChem[i].y > Y_MAX+10.))
      {
         //get rid of the puffs which are out of search area
         DeletePoint(i);
         i--;
      }
   }

   // Add puffs at appropriate times
   if( (Count++ > 1.0/dt/odor_num_per_second) || 
       (mCount < 1))
   {
      //set the odor releasing rate
      mCount++;

      if( mCount > MAX_CHEM_POINTS )
      {
         mCount = MAX_CHEM_POINTS;
      }

      Count = 1;
   }
}


// remove point from chemical point array
void ChemicalTrail::DeletePoint(int i)
{
   uInt32 j;

   for( j = i; 
        ((j < mCount) && (j < MAX_CHEM_POINTS - 1)); 
        j++)
   {
      mChem[j].x = mChem[j+1].x;
      mChem[j].y = mChem[j+1].y;
      mChem[j].z = mChem[j+1].z;
      mChem[j].rad = mChem[j+1].rad;
   }

   mCount = mCount - 1;
   for(j = mCount; j < mCount+1; j++)
   {
      InitOdorRelease(j);
   }
}


/*
// initializes the puff structures.
*/
void ChemicalTrail::InitOdorRelease(int i)
{   
   mChem[i].x = start.x;
   mChem[i].y = start.y;
   
   mChem[i].z = 0.000;
   mChem[i].rad = 0.001;
}


/*
// Calculate the density of the every piont with every odor puffs.
*/
double ChemicalTrail::CalcDensity(double x,  double y,  double z)
{
   double densi = 0.0, expon, domin, r3, conc;
   double difx, dify, difz;
   uInt32 i;

   for(i = 0; i < mCount; i++)
   {
      difx = x - mChem[i].x;
      dify = y - mChem[i].y;
      difz = z - mChem[i].z;
      r3 = ((difx)*(difx) + (dify)*(dify) + (difz)*(difz)); //+(1e-8);

      if(r3 < 25.0*mChem[i].rad)
      {
         expon = exp(-r3/mChem[i].rad);
         domin = sqrt(8*PI*PI*PI) * pow((mChem[i].rad), 1.5);
         densi +=  (mQQ*expon)/domin;    // total molucules per cm^3
      }
   }

   if(densi > 1.0e10)
   {
      densi = 1.0e10;
   }

   conc = (densi/mQQ)*0.01;     // norm. by source conc. and integrate over sensor
   if(conc > 0.0)
   {
      if(conc < threshold)
      {
         conc = 0.0;
      }
   }

   return(conc);          //
}

double ChemicalTrail::Boundary(double t)
{
   int i;
   double rtn;
   static double f[3] = { 0, 0, 0 };
   static double amp[3], phs[3];

	if( f[0] == 0 ) 
	{
	   //randomize();
		i = 1 + rand() % 2024;
		srand(i);

		f[0]   = 0.100 + 0.400 * ( (double)rand() / RAND_MAX );   // .10-.50
		f[1]   = 0.020 + 0.030 * ( (double)rand() / RAND_MAX );   // .02-.05
		f[2]   = 0.001 + 0.019 * ( (double)rand() / RAND_MAX );   // .001-.02

		amp[0] = 0.100 + 0.250 * ( (double)rand() / RAND_MAX );   // 0.1-.35                   // -1
		amp[1] = 0.100 + 0.150 * ( (double)rand() / RAND_MAX );   // 0.1-.25                   // -.1
		amp[2] = 0.010 + 0.090 * ( (double)rand() / RAND_MAX );   // 0.01-.1

		phs[0] = 2*PI*((double)rand()/RAND_MAX);
		phs[1] = 2*PI*((double)rand()/RAND_MAX);
		phs[2] = 2*PI*((double)rand()/RAND_MAX);
	}

	rtn = amp[0] * sin( t * f[0] + phs[0] ) + 
		   amp[1] * sin( t * f[1] + phs[1] ) + 
		   amp[2] * sin( t * f[2] + phs[2] );

	return(rtn);
}

/*
double ChemicalTrail::ReadConc(double *pos, double *vel)
{
   double snsd = 0.0;

   snsd = CalcDensity(pos[0], pos[1], 0);
   wind->Apply(pos[0], pos[1], vel);
   // wind at veh. pos

   return(snsd);
}
*/

