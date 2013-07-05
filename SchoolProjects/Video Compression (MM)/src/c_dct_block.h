/****************************************
 filename:    c_dct_block.h
 description: DCT Block class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/

#ifndef _DCT_BLOCK_
#define _DCT_BLOCK_

class DCTBlock
{
	private:
   	uInt8	 i;
		double q;
      
	public:
      uInt8  layer;
      // layer = 0 (foreground)
      // layer = 1 (background)
      
      // if pFrame
      point from;
      point to;
      
      double raw[DCT_BLOCKSIZE]; // from seq block (either data or error)
      double dct[DCT_BLOCKSIZE]; // dct'd raw data
      sInt16 qd [DCT_BLOCKSIZE]; // quantized dct values for writing
   	
   	// convert raw data to DCT
		void DCTData(bool hide = false);
      // convert DCT to raw data
		void iDCTData(bool hide = false);
      
		// quantized dct values
		void qData(bool hide = false);
      // dequantized dct values
		void iqData();
      
      // ZigZag DCT data
      void ZigZag();
      // unZigZag DCT data
      void iZigZag();
      
      int Save(FILE *fp, bool pFrame);
      int Load(FILE *fp, bool pFrame);
};

#endif
/* _DCT_BLOCK_ */
