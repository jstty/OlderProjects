/****************************************
 filename:    c_dct_encoder.cpp
 description: DCT Encoder class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/
#include "global_include.h"

DCTEncoder::DCTEncoder()
{
   numFrames = 0;
   Frames = NULL;
}

DCTEncoder::~DCTEncoder()
{
   if(Frames != NULL) delete [] Frames;
}

void DCTEncoder::Allocate(uInt16 n)
{
   numFrames = n;
   Frames = new DCTFrame[n];
}

void DCTEncoder::SetFrameData(Frame *f)
{
   uInt32 i, numDCTBlocks;
   uInt32 size;
   
   if(vid == NULL) return; // error
   
   size = (vid->width)*(vid->height);
   numDCTBlocks = uInt32(float(size)/float(DCT_BLOCKSIZE));
   
   for(i = 0; i < numFrames; ++i)
   {
      Frames[i].Allocate(numDCTBlocks);
      Frames[i].SetData(f[i].color);
   }
}

int DCTEncoder::Encode(SegFrame *sf)
{
	uInt16 i;
	for(i = 0; i < numFrames; ++i)
   {
   	// iFrame
   	Frames[i].Encode(&(sf[i]), false);
      
      // pFrame, i > 0
      //Frames[i].Encode(&(sf[i-1]), true);
      
      printf(".");
   }
   printf("\n");
   
   return 0;
}


int DCTEncoder::Decode()
{
	uInt16 i;
	for(i = 0; i < numFrames; ++i)
   {
   	// iFrame
   	Frames[i].Decode(NULL, false);
      
      // pFrame, i > 0
      //Frames[i].Decode(Frames[i-1], true);
      
      printf(".");
   }
   printf("\n");
   
   return 0;
}


int DCTEncoder::Save(FILE *fp)
{
	int e = 0;
   uInt16 i;
	for(i = 0; i < numFrames; ++i)
   {
   	// iFrame
   	e = Frames[i].Save(fp, false);
      if(e != 0)
      {
      	break;
      }
      
      // pFrame
   	//e = Frames[i].Save(fp, true);
      
      printf(".");
   }
   printf("\n");
   
	return e;
}

int DCTEncoder::Load(FILE *fp)
{
	int e = 0;
   uInt16 i;
	for(i = 0; i < numFrames; ++i)
   {
   	// iFrame
   	e = Frames[i].Load(fp, false);
      if(e != 0)
      {
      	break;
      }
      
      // pFrame
   	//e = Frames[i].Load(fp, true);
      
      printf(".");
   }
   printf("\n");
   
	return e;
}

