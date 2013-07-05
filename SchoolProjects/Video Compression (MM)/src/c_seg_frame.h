/****************************************
 filename:    c_seg_frame.h
 description: Segmintation Video Frame class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/

#ifndef _SEG_FRAME_
#define _SEG_FRAME_

class SegFrame
{
	public:   	
   	uInt32       numSeg;
      SegBlock	    *Seg; // foreground/background, size numSeg
      
      //list<vector> *Clusters; // Clusters[NUM_LAYERS]
      vector *segVectorList;
      
      SegFrame();
      ~SegFrame();
      
      void Allocate(uInt32 ns);
      void SetData(const Frame *f);

		// calcs least error, FME Search
      void Search(SegFrame *next);
      
      void DrawMotionVectors();
      
      // set all blocks to foreground layer and mv.to = mv.from 
      void SetAsiFrame();

	private:
      uInt32  dSize; // width*height
      // size dSize
      // DON'T delete, allocated in another class
      // rawData from FrameColor
   	uInt8  *RGBYData[NUM_COLORS + 1];
      
      // current frame block data
      uInt8 cData[SEG_BLOCKSIZE];
      // next frame block data
      uInt8 nData[SEG_BLOCKSIZE];
      
      
      // Brute Force Motion Search
      void MADSearch(uInt8 k, SegFrame *next);
      
      // Logarithmic Motion Search
      void FMESearch(uInt8 k, SegFrame *next);
      void FMESearchError(point fP, sInt32 kx, sInt32 ky, SegFrame *next, double &mError, point &mP);
      
      double CalcError(uInt8 *A, uInt8 *B, uInt32 size);
};

#endif
/* _SEG_FRAME_ */

