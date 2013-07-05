/****************************************
 filename:    c_dct_encoder.h
 description: Segmintation class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/

#ifndef _DCT_ENCODER_
#define _DCT_ENCODER_

class DCTEncoder
{
   public:
      uInt16    numFrames;
      DCTFrame *Frames;
      
      DCTEncoder();
      ~DCTEncoder();
      
      void Allocate(uInt16 n);
      void SetFrameData(Frame *f);
      
      // 1) copy raw data to dct size blocks
	   // 2) convert blocks to DCT
   	// 3) quantize DCT
      int Encode(SegFrame *sf);
      
      // 1) deQuantize to DCT
      // 2) convert DCT to blocks(pixels)
   	// 3) copies blocks to rawData
      int Decode();
      
      int Save(FILE *fp);
      int Load(FILE *fp);
};

#endif
/* _DCT_ENCODER_ */
