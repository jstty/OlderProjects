/****************************************
filename:    ct2.h
description: Cosine Transform Class
project:     
created by:  Joseph E. Sutton
version:     
****************************************/

#ifndef _CT2_
#define _CT2_

class Ct2
{
   public:
      Ct2();
   
      void  dct(double *out, double *in, uInt16 height, uInt16 width);
      void idct(double *out, double *in, uInt16 height, uInt16 width);
   
      uInt8 type;
   
   protected:
      
      // Fast :)
      void FastDCT2(double *out, double *in, uInt16 height, uInt16 width);
      void FastIDCT2(double *out, double *in, uInt16 height, uInt16 width);
      
      // SLOW :(
      void SlowInit(unsigned short M, unsigned short N);
      void SlowDCT1(double *B, double *A, unsigned short N);
      void SlowDCT2(double **B, double **A, unsigned short M, unsigned short N);
      void SlowIDCT2(double **A, double **B, unsigned short M, unsigned short N);
      
      // used with slow algo
      double **g_ctCosCacheM;
      double **g_ctCosCacheN;
};

#endif
/* _CT2_ */
