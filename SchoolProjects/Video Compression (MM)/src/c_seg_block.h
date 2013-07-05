/****************************************
 filename:    c_seg_block.h
 description: Segmintation Block class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/

#ifndef _SEG_BLOCK_
#define _SEG_BLOCK_

class SegBlock
{
	public:
		uInt8  layer;
      // layer = 0 (foreground)
      // layer = 1 (background)

      // motion vector
      vector mv;
      /*
      // error mask
      // diff from data and real data at that point
      // data[i] - real[i]
      // problem! values could be -255 -> +255
      sInt8 error[SEG_BLOCKSIZE][NUM_COLORS];
		*/
      
      SegBlock &operator=(const SegBlock &src);
      
      void UpdateMV(point to, uInt16 index);
};

#endif
/* _SEG_BLOCK_ */
