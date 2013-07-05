/****************************************
 filename:    c_frame.h
 description: Video Frame class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/

#ifndef _FRAME_
#define _FRAME_

class FrameColor
{
	public:
		uInt32  dSize;    // width*height
   	uInt8  *rawData;  // size dSize
      uInt8  *qdData;   // size dSize
      uInt8  *diffData; // size dSize
      
      FrameColor();
      ~FrameColor();
      
      void Allocate(uInt32 s);
      void CreateDiff();

	private:
	   
};


class Frame
{
	public:
      FrameColor color[NUM_COLORS + 1];
      
      void Allocate(uInt32 s);
		void CreateDiff();
      
	private:
	   
};


#endif
/* _FRAME_ */

