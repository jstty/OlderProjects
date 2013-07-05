/****************************************
 filename:    c_dct_frame.h
 description: DCT Video Frame class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/

#ifndef _DCT_FRAME_
#define _DCT_FRAME_

class DCTFrameColor
{
	public:
		uInt32  dSize; // width*height
      // size dSize
      // DON'T delete, allocated in another class
      // qdData and rawData from FrameColor
   	uInt8  *rawData;
      uInt8  *qdData;
   	
      
   	uInt32    numDCT;
      DCTBlock	*DCT; // size numDCT
      
      DCTFrameColor();
      ~DCTFrameColor();
      
      void Allocate(uInt32 ds);
		void SetData(const FrameColor *f);
      
      void Encode(const SegFrame *sf,             bool pFrame);
      void Decode(const DCTFrameColor *prevFrame, bool pFrame);
      
      int Save(FILE *fp, bool pFrame);
      int Load(FILE *fp, bool pFrame);

	private:
};

class DCTFrame
{
	public:
      DCTFrameColor color[NUM_COLORS];
      
      void Allocate(uInt32 ds);
		void SetData(const FrameColor fc[NUM_COLORS]);

		void Encode(const SegFrame *sf,        bool pFrame = false);
		void Decode(const DCTFrame *prevFrame, bool pFrame);

		int Save(FILE *fp, bool pFrame);
      int Load(FILE *fp, bool pFrame);

	private:
	   
};


#endif
/* _DCT_FRAME_ */

