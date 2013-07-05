/****************************************
filename:    ct2.cpp
description: Cosine Transform Class
project:     
created by:  Joseph E. Sutton
version:     
****************************************/
#define FFTW
#include "global_include.h"

Ct2::Ct2()
{
   type = 0; // 0 - fast, 1 - slow
}

void Ct2::dct(double *out, double *in, uInt16 height, uInt16 width)
{
   if(type == 0)
   {
      FastDCT2(out, in, height, width);
   } else {
      SlowInit(height, width);
      SlowDCT2(&out, &in, height, width);
   }
      
}

void Ct2::idct(double *out, double *in, uInt16 height, uInt16 width)
{
   if(type == 0)
   {
      FastIDCT2(out, in, height, width);
   } else {
      SlowIDCT2(&out, &in, height, width);
   }
}

/*
## The discrete cosine transform X of x can be defined as follows:
##
##               N-1
##   X[k] = w(k) sum x[n] cos (pi (n - 1/2) k / N ),  k = 0, ..., N-1
##               n=0
##
## with w(0) = sqrt(1/N) and w(k) = sqrt(2/N), k = 1, ..., N-1.  There
## are other definitions with different scaling of X[k], but this form
## is common in image processing.

[Matlab DCT2]
28547.3258
-5200.2557
-419.6622
1570.9998
1088.7345
730.8264
206.9184
126.5577
-52.8661
525.6527

[C (slow) DCT2]
(0, 0):  60.0 -> 28547.326
(1, 0):  59.0 -> -5200.256
(2, 0):  63.0 -> -419.662
(3, 0):  73.0 -> 1571.000
(4, 0):  62.0 -> 1088.735
(5, 0):  71.0 -> 730.826
(6, 0):  80.0 -> 206.918
(7, 0):  79.0 -> 126.558
(8, 0):  82.0 -> -52.866
(9, 0):  80.0 -> 525.653
(10, 0): 79.0 -> -517.480


[C (slow) DCT1]
(0): 60.0 -> 2289.454
(1): 59.0 -> -219.247
(2): 63.0 -> -204.948
(3): 73.0 -> -20.160
(4): 62.0 -> -69.775
(5): 71.0 -> -29.472
(6): 80.0 -> -44.582
(7): 79.0 -> -12.096
(8): 82.0 -> -28.815
(9): 80.0 -> -8.234
(10): 79.0 -> -30.120
*/

void Ct2::FastDCT2(double *out, double *in, uInt16 height, uInt16 width)
{
   uInt32 x, y;
   fftw_plan plan;
   double sqrtN, sqrtM, sqrt2N, sqrt2M;
   
   /* DCT TYPE-II */
   plan = fftw_plan_r2r_2d(height, width,
                           in, out, 
                           FFTW_REDFT10,
                           FFTW_REDFT10,
                           FFTW_ESTIMATE);
   fftw_execute(plan);

   /* normalize */
   sqrtN  = 1.0/(sqrt((double)width));
   sqrtM  = 1.0/(sqrt((double)height));
   sqrt2N = 1.0/(sqrt((double)width/2.0));
   sqrt2M = 1.0/(sqrt((double)height/2.0));
   for(y = 0; y < height; y++)
   {
      for (x = 0; x < width; x++)
     	{
     	   out[y*width + x] *= 0.25;
     	   
     	   if((x == 0) && (y == 0))
     	   {
            out[0] *= sqrtN * sqrtM;
     	   }
         else
         {
            if(x == 0)  out[y*width + x] *= sqrtN;
        	   else        out[y*width + x] *= sqrt2N;
        	   
        	   if(y == 0)  out[y*width + x] *= sqrtM;
        	   else        out[y*width + x] *= sqrt2M;
         }
     	}
   }
  
   fftw_destroy_plan(plan);
}


void Ct2::FastIDCT2(double *out, double *in, uInt16 height, uInt16 width)
{
   uInt32 x, y;
   fftw_plan plan;
   double mult, sqrtN, sqrtM, sqrt2N, sqrt2M;
   
   /* inverse normalize */
   sqrtN  = sqrt((double)width);
   sqrtM  = sqrt((double)height);
   sqrt2N = sqrt((double)width/2.0);
   sqrt2M = sqrt((double)height/2.0);
   mult = 4;
   for(y = 0; y < height; y++)
   {
      for (x = 0; x < width; x++)
     	{
     	   in[y*width + x] *= mult;
     	   
     	   if((x == 0) && (y == 0))
     	   {
            in[0] *= sqrtN * sqrtM;
     	   }
         else
         {
            if(x == 0)  in[y*width + x] *= sqrtN;
        	   else        in[y*width + x] *= sqrt2N;
        	   
        	   if(y == 0)  in[y*width + x] *= sqrtM;
        	   else        in[y*width + x] *= sqrt2M;
         }
     	}
   }
   
   /* DCT TYPE-III (aka IDCT) */
   plan = fftw_plan_r2r_2d(height, width,
                           in, out, 
                           FFTW_REDFT01,
                           FFTW_REDFT01,
                           FFTW_ESTIMATE);
   fftw_execute(plan);
   
   /* normalize */
   mult = 1.0/(4 * height * width);
   for(y = 0; y < height; y++)
   {
      for (x = 0; x < width; x++)
     	{
     	   out[y*width + x] *= mult;
     	}
   }
  
   fftw_destroy_plan(plan);
}



/****************************************
desc:   Initialize cosine transform values
inputs: 
usage:  
****************************************/
void Ct2::SlowInit(unsigned short M, unsigned short N)
{
   unsigned short i, j;
   double Md, Nd;
   
   Md = PI/(double)M;
   g_ctCosCacheM = (double **) malloc(sizeof(double *) * M);
   for(i = 0; i < M; i++)
   {
      g_ctCosCacheM[i] = (double *) malloc(sizeof(double) * M);
      for(j = 0; j < M; j++)
      {
         g_ctCosCacheM[i][j] = cos(Md*(j + 0.5)*i);
      }
   }
   
   Nd = PI/(double)N;
   g_ctCosCacheN = (double **) malloc(sizeof(double *) * N);
   for(i = 0; i < N; i++)
   {
      g_ctCosCacheN[i] = (double *) malloc(sizeof(double) * N);
      for(j = 0; j < N; j++)
      {
         g_ctCosCacheN[i][j] = cos(Nd*(j + 0.5)*i);
      }
   }
}

/*
## The discrete cosine transform X of x can be defined as follows:
##
##               N-1
##   X[k] = w(k) sum x[n] cos (pi (n + 1/2) k / N ),  k = 0, ..., N-1
##               n=0
##
## with w(0) = sqrt(1/N) and w(k) = sqrt(2/N), k = 1, ..., N-1.  There
## are other definitions with different scaling of X[k], but this form
## is common in image processing.
*/
void Ct2::SlowDCT1(double *B, double *A, unsigned short N)
{
   unsigned short k, j;
   double sum, sqrtN;
   
   sqrtN = sqrt(2.0/(double)N);
      
   /* B_k =... */
   for(k = 0; k < N; k++)
   {
      sum = 0;
      /* SUM */ 
      for(j = 0; j < N; j++)
      {
         sum += A[j] * cos(PI*(j + 0.5)*k/N);
      }
   
      if(k == 0)   B[k] = 1.0/sqrt((double)N) * sum;
      else         B[k] = sqrtN * sum;
      
      printf("(%d), %0.1f, %0.3f\n", k, A[k], B[k]);
      
      if(k == 10) return ;
   }
}

/****************************************
desc:   2-D discrete cosine transform
inputs: 
usage:  
****************************************/
void Ct2::SlowDCT2(double **B, double **A, unsigned short M, unsigned short N)
{
   unsigned short p, q;
   unsigned short m, n;
   double sqrtM, sqrtN, sqrt2M, sqrt2N;
   double a_p, a_q;
   double sum;
     
   /* re-calc values */
   sqrtM  = sqrt(1.0/(double)M);
   sqrtN  = sqrt(1.0/(double)N);
   sqrt2M = sqrt(2.0/(double)M);
   sqrt2N = sqrt(2.0/(double)N);
   
   /* B_pq =... */
   for(p = 0; p < M; p++)
   {
      for(q = 0; q < N; q++)
      {
         sum = 0;
         /* double SUM */
         for(m = 0; m < M; m++)
         {
            for(n = 0; n < N; n++)
            {
               sum += A[m][n] * g_ctCosCacheM[p][m] * g_ctCosCacheN[q][n];
            }
         }
         
         /* determine Alpha P and Alpha Q */
         if(p == 0)  a_p = sqrtM;
         else        a_p = sqrt2M;
         
         if(q == 0)  a_q = sqrtN;
         else        a_q = sqrt2N;
      
         /* store B 
         B[p][q] = a_p * a_q * sum;
         B[p][q] = sum;
         */
         B[p][q] = a_p * a_q * sum;
         printf("(%d, %d): %0.1f -> %0.3f\n", q, p, A[p][q], B[p][q]);
         
         if(q == 10) return ;
      }
   }
   
}


/****************************************
desc:   2-D inverse discrete cosine transform
inputs: 
usage:  
****************************************/
void Ct2::SlowIDCT2(double **A, double **B, unsigned short M, unsigned short N)
{
   unsigned short p, q;
   unsigned short m, n;
   double Md, Nd;
   double sqrtM, sqrtN, sqrt2M, sqrt2N;
   double a_p, a_q;
   double sum;
   
   /* re-calc values */
   Md = PI_D2/(double)M;
   Nd = PI_D2/(double)N;
   sqrtM = sqrt(1/M);
   sqrtN = sqrt(1/N);
   sqrt2M = sqrt(2/M);
   sqrt2N = sqrt(2/N);
   
   /* A_mn */
   for(m = 0; m < M; p++)
   {
      for(n = 0; n < N; q++)
      {
         sum = 0;
         /* double SUM */
         for(p = 0; p < M; p++)
         {
            for(q = 0; q < N; q++)
            {
               /* determine Alpha P and Alpha Q */
               if(p == 0)  a_p = sqrtM;
               else        a_p = sqrt2M;
               
               if(q == 0)  a_q = sqrtN;
               else        a_q = sqrt2N;
               
               sum += a_p * a_q * B[p][q] * cos(Md*(2*m + 1)*p) * cos(Nd*(2*n + 1)*q);
            }
         }
         
         A[m][n] = sum;      
      }
   }
}


