/****************************************
 filename:    c_seg_frame.cpp
 description: Video Frame class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/
#include "global_include.h"

/****************************************
SegBlock
****************************************/
// copy
SegBlock& SegBlock::operator=(const SegBlock &src)
{
   this->layer = src.layer;
   
   this->mv.from.x = src.mv.from.x;
   this->mv.from.y = src.mv.from.y;
   
   this->mv.to.x = src.mv.to.x;
   this->mv.to.y = src.mv.to.y;
   
   return *this;
}   

void SegBlock::UpdateMV(point to, uInt16 index)
{
	mv.to = to;
   mv.x = mv.from.x - mv.to.x;
   mv.y = mv.from.y - mv.to.y;
   
	mv.SegBlockIndex = index;
}



/****************************************
SegFrame
****************************************/
SegFrame::SegFrame()
{
	uInt8 c;

	dSize = 0;
   
   for(c = 0; c < NUM_COLORS + 1; ++c)
   {
		RGBYData[c] = NULL;
   }
   
   numSeg = 0;
   Seg   = NULL;
}

SegFrame::~SegFrame()
{
   if(Seg != NULL) delete [] Seg;
   
   if(segVectorList != NULL) delete [] segVectorList;
}

void SegFrame::Allocate(uInt32 ns)
{   
   numSeg = ns;
   Seg   = new SegBlock[ns];
   
   segVectorList = new vector[numSeg];
}

void SegFrame::SetData(const Frame *f)
{
	uInt8 c;
   uInt32 i;
   uInt16 x, y;
   
	dSize = f->color[0].dSize;
   
   for(c = 0; c < NUM_COLORS + 1; ++c)
   {
		RGBYData[c] = f->color[c].rawData;
	}

	// setup positions
   x = 0;
   y = 0;
   for(i = 0; i < numSeg; ++i)
   {
		Seg[i].mv.from.x = x;
      Seg[i].mv.from.y = y;
      
      x += SEG_BLOCKWIDTH;
      if(x >= vid->width)
      {
      	x = 0;
         y += SEG_BLOCKWIDTH;
      }
   }
}

// Calcs least error
void SegFrame::Search(SegFrame *next)
{
	//vector v;
   uInt32 i;
     
   // Calcs least error
	//MADSearch(SEG_SEARCHSIZE >> 1, next);
   /*
   printf("\ndv <- matrix(c(\n");
   for(i = 0; i < numSeg; ++i)
   {
   	v = segVectorList[i];
      
      printf("%d, %d", v.x, v.y);
         
      if(i+1 < numSeg) printf(", ");
   }
   printf("\n), ncol=2, byrow = TRUE);\n");
   */
   
   FMESearch(SEG_SEARCHSIZE, next);
   /*
   printf("\ndv <- matrix(c(\n");
   for(i = 0; i < numSeg; ++i)
   {
   	v = segVectorList[i];
      
      printf("%d, %d", v.x, v.y);
         
      if(i+1 < numSeg) printf(", ");
   }
   printf("\n), ncol=2, byrow = TRUE);\n");
   */
   
   i = 0;
   
   // TODO maybe
   // create error blocks for each color
} 


// Logarithmic Motion Search
void SegFrame::FMESearch(uInt8 k, SegFrame *next)
{
	uInt32 i;
	double error;
   point  eP, mP;
   uInt8 ik;
   
	for(i = 0; i < numSeg; ++i)
   {
   	//if(i == 661)
      //	ik = 1;
   
   	// copy current image block at seg[i](x,y) to current seg block
      BlockCopy(
      	next->RGBYData[Y_INDEX],
      	nData, 
      	Seg[i].mv.from.x, Seg[i].mv.from.y, 
         vid->width, vid->height, 
         0, 0, 
         SEG_BLOCKWIDTH, SEG_BLOCKWIDTH);
   
   	mP = Seg[i].mv.from;
	   ik = k >> 1; // k = k/2;
   	while(ik > 0)
      {
         error = 10e100000;
         eP = mP;
         
         // preferance problem
         FMESearchError(mP,  ik,  ik, next, error, eP); // bottom/right
         FMESearchError(mP,   0,  ik, next, error, eP); // bottom/middle
         FMESearchError(mP, -ik,  ik, next, error, eP); // bottom/left
         
         FMESearchError(mP,  ik,   0, next, error, eP); // middle/right
         FMESearchError(mP, -ik,   0, next, error, eP); // middle/left
         
         FMESearchError(mP,  ik, -ik, next, error, eP); // top/right
         FMESearchError(mP,   0, -ik, next, error, eP); // top/middle
         FMESearchError(mP, -ik, -ik, next, error, eP); // top/left
         
         FMESearchError(mP,   0,   0, next, error, eP); // middle/middle
         
         if( (mP.x != eP.x) || 
             (mP.y != eP.y) )
         {
            mP = eP;
         }
         
         ik >>= 1; // k = k/2;
      }
      
      
      // assign seg block "to" with lowest error
      Seg[i].UpdateMV(mP, i);
      
      // save in vector list for k-means cluster
      segVectorList[i] = Seg[i].mv;
   }
}

void SegFrame::FMESearchError(point fP, sInt32 kx, sInt32 ky, SegFrame *next, double &mError, point &mP)
{
	double cError;
	sInt32 x, y;

	x = fP.x + kx;
   y = fP.y + ky;
   if(x < 0) return;
   if(y < 0) return;
	if(x + SEG_BLOCKWIDTH > vid->width)  return;
   if(y + SEG_BLOCKWIDTH > vid->height) return;         
   
   BlockCopy(
      RGBYData[Y_INDEX],
      cData, 
      x, y, 
      vid->width, vid->height, 
      0, 0, 
      SEG_BLOCKWIDTH, SEG_BLOCKWIDTH);
      
   cError = CalcError(cData, nData, SEG_BLOCKSIZE);
   if(cError <= mError)
   {
      mError = cError;
      mP.x = x;
      mP.y = y;
   }
}


// Brute Force Motion Search
void SegFrame::MADSearch(uInt8 k, SegFrame *next)
{
	uInt32 i;
	sInt32 y, x;
	uInt8 kSize;
   double cError, mError;
   point  mP;

   
   kSize = 2*k + SEG_BLOCKWIDTH;
   
   for(i = 0; i < numSeg; ++i)
   {
   	// copy current image block at seg[i](x,y) to current seg block
      BlockCopy(
      	next->RGBYData[Y_INDEX],
      	nData, 
      	Seg[i].mv.from.x, Seg[i].mv.from.y, 
         vid->width, vid->height, 
         0, 0, 
         SEG_BLOCKWIDTH, SEG_BLOCKWIDTH);
      
      mError = 10e100000;
      mP.x = 0;
      mP.y = 0;
	   for(y = Seg[i].mv.from.y - k; y < Seg[i].mv.from.y + kSize; ++y)
   	{
      	for(x = Seg[i].mv.from.x - k; x < Seg[i].mv.from.x + kSize; ++x)
   		{
         	// make sure x,y is inside video frame
         	if(x < 0) x = 0;
            if(y < 0) y = 0;
            if(x > vid->width)  continue;
            if(y > vid->height) continue;
            
            // copy next image block at (x,y) to next seg block
            BlockCopy(
               RGBYData[Y_INDEX],
               cData, 
               x, y, 
               vid->width, vid->height, 
               0, 0, 
               SEG_BLOCKWIDTH, SEG_BLOCKWIDTH);
            
            cError = CalcError(cData, nData, SEG_BLOCKSIZE);
            
            if(cError < mError)
            {
            	mError = cError;
            	mP.x = x;
               mP.y = y;
            }
         }
      }
      
      // assign seg block "to" with lowest error
      Seg[i].UpdateMV(mP, i);
      
      
      // save in vector list for k-means cluster
      segVectorList[i] = Seg[i].mv;
   }
}

// use mean absolute differance (MAD)
double SegFrame::CalcError(uInt8 *A, uInt8 *B, uInt32 size)
{
	uInt32 i;
   double e;
   e = 0;

	// mean absolute differance (MAD)
	for(i = 0; i < size; i++)
   {
   	e += abs(A[i] - B[i]);
   }
   e = e/(double)size;

   /*
   // mean square difference (MDS)
   for(i = 0; i < size; i++)
   {
   	e += (A[i] - B[i])*(A[i] - B[i]);
   }
   e = e/(double)size;
   */
   
   return e;
}


void SegFrame::SetAsiFrame()
{
	uInt32 i;

	for(i = 0; i < numSeg; ++i)
   {
   	Seg[i].mv.to = Seg[i].mv.from;
   	Seg[i].layer = 0; // foreground
   }
}

void SegFrame::DrawMotionVectors()
{
	uInt32 i;
   float x, y;

	for(i = 0; i < numSeg; ++i)
   {
   	if(Seg[i].layer == LAYER_FOREGROUND) glColor3f( 1.0, 0.0, 0.0 ); // red   - foreground
      else                                 glColor3f( 0.0, 1.0, 0.0 ); // green - background
   
   	x = Seg[i].mv.from.x + vid->width + (SEG_BLOCKWIDTH >> 1);
      y = Seg[i].mv.from.y + (SEG_BLOCKWIDTH >> 1);
   	glVertex2f(x, y); 
   
	   x = Seg[i].mv.to.x + vid->width + (SEG_BLOCKWIDTH >> 1);
      y = Seg[i].mv.to.y + (SEG_BLOCKWIDTH >> 1);
   	glVertex2f(x, y); 
   }
}


