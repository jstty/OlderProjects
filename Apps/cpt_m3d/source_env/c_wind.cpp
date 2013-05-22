//////////////////////////////////////////////////////////////////////////////
// Program Name:	c_wind.cpp
// Programmer:		Joseph E. Sutton
// Description:	Class to generate Dynamic Wind
// Start Date:		2/27/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include <math.h>
#include "../include/c_wind.h"
//extern CpstSettings *settings;

Wind::Wind()
{
   first = 1;
   samplesZ = 0;
}

void Wind::SetSettings(double ssx, double ssy, double sdt, double sd, double sb, double sg)
{
   speed_x = ssx;
   speed_y = ssy;
   dt = sdt;
   damping = sd;
   bandwidth = sb;
   gain = sg;
}

void Wind::GetDir(Point3D &dir, Point3D p)
{
   double u_wind[3];
   Apply(p.x, p.y, u_wind);

   dir.x = u_wind[0];
   dir.y = u_wind[1];
   dir.z = u_wind[2];
}

void Wind::UpdateZ()
{
	/*
	double r, delta, mean;
	int i, x, y;
	int apos[4];

	if(samplesZ % 10)
	{
		delta = 2.0;
		for(i = 0; i < 10; i++)
		{
			x = (int)(MAX_NODE_X*((double)rand())/((double)RAND_MAX));
			y = (int)(MAX_NODE_Y*((double)rand())/((double)RAND_MAX));

			r = delta*((double)rand())/((double)RAND_MAX) - delta*0.5;
			mUzGrid[x][y] += r;
		}
	}

	for(x = 0; x < MAX_NODE_X; x++)
	{
		for(y = 0; y < MAX_NODE_Y; y++)
		{
			if(x - 1 >= 0) apos[0] = x-1;
			else           apos[0] = x;
			if(x + 1 < MAX_NODE_X) apos[1] = x+1;
			else				   apos[1] = x;

			if(y - 1 >= 0) apos[2] = y-1;
			else           apos[2] = y;
			if(y + 1 < MAX_NODE_Y) apos[3] = y+1;
			else				   apos[3] = y;

			mean = (mUzGrid[apos[0]][y] + mUzGrid[apos[1]][y] + mUzGrid[x][apos[2]] + mUzGrid[x][apos[3]])*0.25;

			if(mean > mUzGrid[x][y])	   mUzGrid[x][y] += 0.0001;
			else if (mean < mUzGrid[x][y]) mUzGrid[x][y] -= 0.0001;
		}
	}

    samplesZ++;
	*/
}


// Wind_Integral
void Wind::Update()
{
    double  		temp_ux[MAX_NODE_X][MAX_NODE_Y], temp_uy[MAX_NODE_X][MAX_NODE_Y];
    double  		dudx,dudy,dvdx,dvdy;
    double  		speedxt,speedyt,lambda;
    static double   x_boundary[8]={0,0,0,0,0,0,0,0},
                    y_boundary[8]={0,0,0,0,0,0,0,0};
    double  		speedxc[4],speedyc[4];
    int         	i, j;   //Disp_x, Disp_y,  , delta_2px, delta_2py
    static double Bx,By,Bz;

  // Initialize the values of the velocity field
    if(first == 1)
    {
        first = 0;
        mDeltaX = (X_MAX-X_MIN)/double(MAX_NODE_X-1);  //calculate the intervals of x and y
        mDeltaY = (Y_MAX-Y_MIN)/double(MAX_NODE_Y-1);
        mDeltaZ = (Z_MAX-Z_MIN)/double(MAX_NODE_Z-1);

        Bx = 10.0/mDeltaX/mDeltaX;
        By = 10.0/mDeltaY/mDeltaY;
        Bz = 10.0/mDeltaZ/mDeltaZ;

        for(i = 0; i <= MAX_NODE_X - 1; i++)
        {
            for(j = 0; j <= MAX_NODE_Y - 1; j++)
            {
               mUxGrid[i][j] = 1.0;
               mUyGrid[i][j] = 0.0;
               mUzGrid[i][j] = 0.0;
            }
        }

    }

    // Generate colored noise boundary conditions
    // stochastic
    for(i = 0; i < 4; i++)
    {
      speedxc[i] = colored_noise(&(x_boundary[2*i]), dt)+speed_x;
      speedyc[i] = colored_noise(&(y_boundary[2*i]), dt)+speed_y;
    }

	// upper left corner
	// two boundary points with value ux_bound and uy_bound
    speedxt = speedxc[0];
    speedyt = speedyc[0];
    dudx = (mUxGrid[1][0]-speedxt)/(2*mDeltaX);
    dudy = (mUxGrid[0][1]-speedxt)/(2*mDeltaY);
    //dudz = (mUxGrid[0][0][1]-speedxt)/(2*mDeltaZ);
    temp_ux[0][0] = -2*(Bx+By)*mUxGrid[0][0]+Bx*(speedxt+mUxGrid[1][0])
                                            +By*(speedxt+mUxGrid[0][1])
                             -(mUxGrid[0][0]*dudx + mUyGrid[0][0]*dudy);

    dvdx = (mUyGrid[1][0]-speedyt)/(2*mDeltaX);
    dvdy = (mUyGrid[0][1]-speedyt)/(2*mDeltaY);
    //dvdz = (mUyGrid[0][0][1]-speedyt)/(2*mDeltaZ);
    temp_uy[0][0] = -2*(Bx+By)*mUyGrid[0][0]+Bx*(speedyt+mUyGrid[1][0])
                                            +By*(speedyt+mUyGrid[0][1])
                             -(mUxGrid[0][0]*dvdx + mUyGrid[0][0]*dvdy);

	// lower left corner
    speedxt = speedxc[1];
    speedyt = speedyc[1];
    dudx = (mUxGrid[1][MAX_NODE_X-1]-speedxt)/(2*mDeltaX);
    dudy = (speedxt-mUxGrid[0][MAX_NODE_X-2])/(2*mDeltaY);
    temp_ux[0][MAX_NODE_X-1] = -2*(Bx+By)*mUxGrid[0][MAX_NODE_X-1]+Bx*(speedxt+mUxGrid[1][MAX_NODE_X-1])
                                                                  +By*(speedxt+mUxGrid[0][MAX_NODE_X-2])
                                -(mUxGrid[0][MAX_NODE_X-1]*dudx+mUyGrid[0][MAX_NODE_X-1]*dudy);
    dvdx = (mUyGrid[1][MAX_NODE_X-1]-speedyt)/(2*mDeltaX);
    dvdy = (speedyt-mUyGrid[0][MAX_NODE_X-2])/(2*mDeltaY);
    temp_uy[0][MAX_NODE_X-1] = -2*(Bx+By)*mUyGrid[0][MAX_NODE_X-1]+Bx*(speedyt+mUyGrid[1][MAX_NODE_X-1])
                                                                  +By*(speedyt+mUyGrid[0][MAX_NODE_X-2])
                              -(mUxGrid[0][MAX_NODE_X-1]*dvdx + mUyGrid[0][MAX_NODE_X-1]*dvdy);

	// left side
	// three boundary points with value ux_bound and uy_bound
    for(j = 1; j < MAX_NODE_X - 1; j++)
    {
        lambda  = ((double)j/MAX_NODE_X);
        speedxt = (1.0-lambda)*speedxc[0]+lambda*speedxc[1];
        speedyt = (1.0-lambda)*speedyc[0]+lambda*speedyc[1];
        dudx = (mUxGrid[1][j]-speedxt)/(2*mDeltaX);
        dudy = (mUxGrid[0][j+1]-mUxGrid[0][j-1])/(2*mDeltaY);
        dvdx = (mUyGrid[1][j]-speedyt)/(2*mDeltaX);
        dvdy = (mUyGrid[0][j+1]-mUyGrid[0][j-1])/(2*mDeltaY);
        temp_ux[0][j] = -2*(Bx+By)*mUxGrid[0][j]+Bx*(speedxt+mUxGrid[1][j])
                                                +By*(mUxGrid[0][j+1]+mUxGrid[0][j-1])
                            -(mUxGrid[0][j]*dudx + mUyGrid[0][j]*dudy);
        temp_uy[0][j] = -2*(Bx+By)*mUyGrid[0][j]+Bx*(speedyt+mUyGrid[1][j])
                                                +By*(mUyGrid[0][j+1]+mUyGrid[0][j-1])
                            -(mUxGrid[0][j]*dvdx + mUyGrid[0][j]*dvdy);
    }

	// upper right corner
    speedxt = speedxc[3];
    speedyt = speedyc[3];
    dudx = (speedxt-mUxGrid[MAX_NODE_Y-2][0])/(2*mDeltaX);
    dudy = (mUxGrid[MAX_NODE_Y-1][1]-speedxt)/(2*mDeltaY);
    dvdx = (speedyt-mUyGrid[MAX_NODE_Y-2][0])/(2*mDeltaX);
    dvdy = (mUyGrid[MAX_NODE_Y-1][1]-speedyt)/(2*mDeltaY);
    temp_ux[MAX_NODE_Y-1][0] = -2*(Bx+By)*mUxGrid[MAX_NODE_Y-1][0]+Bx*(speedxt+mUxGrid[MAX_NODE_Y-2][0])
                                                                  +By*(speedxt+mUxGrid[MAX_NODE_Y-1][1])
                              -(mUxGrid[MAX_NODE_Y-1][0]*dudx + mUyGrid[MAX_NODE_Y-1][0]*dudy);
    temp_uy[MAX_NODE_Y-1][0] = -2*(Bx+By)*mUyGrid[MAX_NODE_Y-1][0]+Bx*(speedyt+mUyGrid[MAX_NODE_Y-2][0])
                                                                  +By*(speedyt+mUyGrid[MAX_NODE_Y-1][1])
                                  -(mUxGrid[MAX_NODE_Y-1][0]*dvdx + mUyGrid[MAX_NODE_Y-1][0]*dvdy);

	// lower right corner
    speedxt = speedxc[2];
    speedyt = speedyc[2];
    dudx = (speedxt-mUxGrid[MAX_NODE_Y-2][MAX_NODE_X-1])/(2*mDeltaX);
    dudy = (speedxt-mUxGrid[MAX_NODE_Y-1][MAX_NODE_X-2])/(2*mDeltaY);
    dvdx = (speedyt-mUyGrid[MAX_NODE_Y-2][MAX_NODE_X-1])/(2*mDeltaX);
    dvdy = (speedyt-mUyGrid[MAX_NODE_Y-1][MAX_NODE_X-2])/(2*mDeltaY);
    temp_ux[MAX_NODE_Y-1][MAX_NODE_X-1] = -2*(Bx+By)*mUxGrid[MAX_NODE_Y-1][MAX_NODE_X-1]+Bx*(speedxt+mUxGrid[MAX_NODE_Y-2][MAX_NODE_X-1])
                                                                                          +By*(speedxt+mUxGrid[MAX_NODE_Y-1][MAX_NODE_X-2])
                                            -(mUxGrid[MAX_NODE_Y-1][MAX_NODE_X-1]*dudx + mUyGrid[MAX_NODE_Y-1][MAX_NODE_X-1]*dudy);
    temp_uy[MAX_NODE_Y-1][MAX_NODE_X-1] = -2*(Bx+By)*mUyGrid[MAX_NODE_Y-1][MAX_NODE_X-1]+Bx*(speedyt+mUyGrid[MAX_NODE_Y-2][MAX_NODE_X-1])
                                                                                          +By*(speedyt+mUyGrid[MAX_NODE_Y-1][MAX_NODE_X-2])
                                            -(mUxGrid[MAX_NODE_Y-1][MAX_NODE_X-1]*dvdx + mUyGrid[MAX_NODE_Y-1][MAX_NODE_X-1]*dvdy);

	// right side
    for(j = 1; j < MAX_NODE_X - 1; j++)
    {
        lambda  = ((double)j/MAX_NODE_X);
        speedxt = (1.0-lambda)*speedxc[3]+lambda*speedxc[2];
        speedyt = (1.0-lambda)*speedyc[3]+lambda*speedyc[2];
        dudx = (speedxt-mUxGrid[MAX_NODE_Y-2][j])/(2*mDeltaX);
        dudy = (mUxGrid[MAX_NODE_Y-1][j+1]-mUxGrid[MAX_NODE_Y-1][j-1])/(2*mDeltaY);
        dvdx = (speedyt-mUyGrid[MAX_NODE_Y-2][j])/(2*mDeltaX);
        dvdy = (mUyGrid[MAX_NODE_Y-1][j+1]-mUyGrid[MAX_NODE_Y-1][j-1])/(2*mDeltaY);
        temp_ux[MAX_NODE_Y-1][j] = -2*(Bx+By)*mUxGrid[MAX_NODE_Y-1][j]+Bx*(speedxt+mUxGrid[MAX_NODE_Y-2][j])
                                                                            +By*(mUxGrid[MAX_NODE_Y-1][j+1]+mUxGrid[MAX_NODE_Y-1][j-1])
                                      -(mUxGrid[MAX_NODE_Y-1][j]*dudx + mUyGrid[MAX_NODE_Y-1][j]*dudy);
        temp_uy[MAX_NODE_Y-1][j] = -2*(Bx+By)*mUyGrid[MAX_NODE_Y-1][j]+Bx*(speedyt+mUyGrid[MAX_NODE_Y-2][j])
                                                                            +By*(mUyGrid[MAX_NODE_Y-1][j+1]+mUyGrid[MAX_NODE_Y-1][j-1])
                                  -(mUxGrid[MAX_NODE_Y-1][j]*dvdx + mUyGrid[MAX_NODE_Y-1][j]*dvdy);
    }

	// top side, corners already covered
    for(i = 1; i < MAX_NODE_Y - 1; i++)
    {
        lambda  = ((double)i/MAX_NODE_Y);
        speedxt = (1.0-lambda)*speedxc[0]+lambda*speedxc[3];
        speedyt = (1.0-lambda)*speedyc[0]+lambda*speedyc[3];
        dudx = (mUxGrid[i+1][0]-mUxGrid[i-1][0])/(2*mDeltaX);
        dudy = (mUxGrid[i][1]-speedxt)/(2*mDeltaY);
        dvdx = (mUyGrid[i+1][0]-mUyGrid[i-1][0])/(2*mDeltaX);
        dvdy = (mUyGrid[i][1]-speedyt)/(2*mDeltaY);
        temp_ux[i][0] = -2*(Bx+By)*mUxGrid[i][0]+Bx*(mUxGrid[i+1][0]+mUxGrid[i-1][0])
                                                         +By*(mUxGrid[i][1]+speedxt)
                             -(mUxGrid[i][0]*dudx + mUyGrid[i][0]*dudy);
        temp_uy[i][0] = -2*(Bx+By)*mUyGrid[i][0]+Bx*(mUyGrid[i+1][0]+mUyGrid[i-1][0])
                                                         +By*(mUyGrid[i][1]+speedyt)
                             -(mUxGrid[i][0]*dvdx + mUyGrid[i][0]*dvdy);
    }
	
	// bottom side, corners already covered
    for(i = 1; i < MAX_NODE_Y - 1; i++)
    {
        lambda  = ((double)i/MAX_NODE_Y);
        speedxt = (1.0-lambda)*speedxc[1]+lambda*speedxc[2];
        speedyt = (1.0-lambda)*speedyc[1]+lambda*speedyc[2];
        dudx = (mUxGrid[i+1][MAX_NODE_X-1]-mUxGrid[i-1][MAX_NODE_X-1])/(2*mDeltaX);
        dudy = (speedxt-mUxGrid[i][MAX_NODE_X-2])/(2*mDeltaY);
        dvdx = (mUyGrid[i+1][MAX_NODE_X-1]-mUyGrid[i-1][MAX_NODE_X-1])/(2*mDeltaX);
        dvdy = (speedyt-mUyGrid[i][MAX_NODE_X-2])/(2*mDeltaY);
        temp_ux[i][MAX_NODE_X-1] = -2*(Bx+By)*mUxGrid[i][MAX_NODE_X-1]+Bx*(mUxGrid[i+1][MAX_NODE_X-1]+mUxGrid[i-1][MAX_NODE_X-1])
                                                                            +By*(mUxGrid[i][MAX_NODE_X-2]+speedxt)
                                  -(mUxGrid[i][MAX_NODE_X-1]*dudx + mUyGrid[i][MAX_NODE_X-1]*dudy);
        temp_uy[i][MAX_NODE_X-1] = -2*(Bx+By)*mUyGrid[i][MAX_NODE_X-1]+Bx*(mUyGrid[i+1][MAX_NODE_X-1]+mUyGrid[i-1][MAX_NODE_X-1])
                                                                            +By*(mUyGrid[i][MAX_NODE_X-2]+speedyt)
                                  -(mUxGrid[i][MAX_NODE_X-1]*dvdx + mUyGrid[i][MAX_NODE_X-1]*dvdy);
    }

	// interior points
   for(i = 1; i < MAX_NODE_Y - 1; i++)
   {
      for(j = 1; j < MAX_NODE_X - 1; j++)
      {
         dudx = (mUxGrid[i+1][j]-mUxGrid[i-1][j])/(2*mDeltaX);
         dudy = (mUxGrid[i][j+1]-mUxGrid[i][j-1])/(2*mDeltaY);
         dvdx = (mUyGrid[i+1][j]-mUyGrid[i-1][j])/(2*mDeltaX);
         dvdy = (mUyGrid[i][j+1]-mUyGrid[i][j-1])/(2*mDeltaY);
         temp_ux[i][j] = -2*(Bx+By)*mUxGrid[i][j]+Bx*(mUxGrid[i+1][j]+mUxGrid[i-1][j])
                                                +By*(mUxGrid[i][j+1]+mUxGrid[i][j-1])
                                  -(mUxGrid[i][j]*dudx + mUyGrid[i][j]*dudy);
         temp_uy[i][j] = -2*(Bx+By)*mUyGrid[i][j]+Bx*(mUyGrid[i+1][j]+mUyGrid[i-1][j])
                                                 +By*(mUyGrid[i][j+1]+mUyGrid[i][j-1])
                                   -(mUxGrid[i][j]*dvdx + mUyGrid[i][j]*dvdy);
      }
   }

	// integrate velocity field
   for(i = 0; i < MAX_NODE_Y; i++)
   {
     for(j = 0; j < MAX_NODE_X; j++)
     {
        mUxGrid[i][j] += ((temp_ux[i][j]))*dt;
        mUyGrid[i][j] += ((temp_uy[i][j]))*dt;
     }
   }

}


/**************************************************************
Wind
This function takes a position as input, operates on the finite
element wind model, and returns the wind vector at the input position.
****************************************************************/
void Wind::Apply(double x, double y, double *u, double *ux_grid, double *uy_grid)
{
	int    i_grid,j_grid;
	double x_grid,y_grid,lambda,mu;
	double *uz_grid;

   if(ux_grid == NULL) ux_grid = (double *)mUxGrid;
   if(uy_grid == NULL) uy_grid = (double *)mUyGrid;
   uz_grid = (double *)mUzGrid;

   // find the integer node coordinates to the upper left
   // of the i-th puff position

   if( mDeltaX == 0 ) mDeltaX = 0.001;
   if( mDeltaY == 0 ) mDeltaY = 0.001;

   i_grid = (int)floor((x-X_MIN)/mDeltaX);
   j_grid = (int)floor((y-Y_MIN)/mDeltaY);

   // truncate to region of operation
   if(i_grid < 0) i_grid = 0;
   if(j_grid < 0) j_grid = 0;
   if(i_grid > MAX_NODE_Y-2) i_grid = MAX_NODE_Y-2;
   if(j_grid > MAX_NODE_X-2) j_grid = MAX_NODE_X-2;

   // find the position of the upper left finite element node
   x_grid = (mDeltaX*i_grid + X_MIN);
   y_grid = (mDeltaY*j_grid + Y_MIN);

   // find the percentage distance from upper left node
   lambda = (x - x_grid)/mDeltaX;
   if(lambda > 1.0) lambda = 1.0;
   if(lambda < 0.0) lambda = 0.0;

   mu = (y - y_grid)/mDeltaY;
   if(mu > 1.0) mu = 1.0;
   if(mu < 0.0) mu = 0.0;

   // interpolate between nodes to determine velocity
   u[0] = (1-mu)*((1-lambda)*ux_grid[(i_grid)*MAX_NODE_X + j_grid] +
                      lambda*ux_grid[(i_grid+1)*MAX_NODE_X + j_grid]) +
              mu*((1-lambda)*ux_grid[(i_grid)*MAX_NODE_X + (j_grid+1)] +
                      lambda*ux_grid[(i_grid+1)*MAX_NODE_X + (j_grid+1)]);

   u[1] = (1-mu)*((1-lambda)*uy_grid[(i_grid)*MAX_NODE_X +j_grid] + 
                      lambda*uy_grid[(i_grid+1)*MAX_NODE_X + j_grid]) +
              mu*((1-lambda)*uy_grid[(i_grid)*MAX_NODE_X + (j_grid+1)] + 
                      lambda*uy_grid[(i_grid+1)*MAX_NODE_X + (j_grid+1)]);


   //
   u[2] = 0.0;
   /*
   u[2] = (1-mu)*((1-lambda)*uz_grid[(i_grid)*MAX_NODE_X +j_grid] + 
                      lambda*uz_grid[(i_grid+1)*MAX_NODE_X + j_grid]) +
              mu*((1-lambda)*uz_grid[(i_grid)*MAX_NODE_X + (j_grid+1)] + 
                      lambda*uz_grid[(i_grid+1)*MAX_NODE_X + (j_grid+1)]);
	
   */
   //


   if( (u[0] == 0) && (u[1] == 0) )
   {
      u[0] = 1e-20;
   }

}



/*
* produces a colored noise process. With coloring process
*                      G wind_bandwidth*wind_bandwidth
*            H(s)=--------------------
*                  s*s+2*z*wind_bandwidth*s+wind_bandwidth*wind_bandwidth
*   G = wind_gain is the DC gain (variance)
*   wind_bandwidth is the natural frequency (bandwidth)
*   z = wind_damping is the damping coefficient
*   all three parameters are predfined.
*/
double Wind::colored_noise(double *x,double ddt)
{
	double u,dx[3];
	
   u = nrand();
	dx[0]= x[1];
	dx[1]= -2.0 * 
           damping *
           bandwidth * 
           x[1] +
           bandwidth * 
           bandwidth * 
           (-x[0] + gain * u);

   dx[2]= -2.0 * 
           damping *
           bandwidth * 
           x[1] +
           bandwidth * 
           bandwidth * 
           (-x[0] + gain * u);

	x[0] += dx[0]*ddt;
	x[1] += dx[1]*ddt;

   x[2] += dx[2]*ddt; // Z

  
	return(x[0]);
}

