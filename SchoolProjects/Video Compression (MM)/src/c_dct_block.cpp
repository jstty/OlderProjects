/****************************************
 filename:    c_dct_block.cpp
 description: DCT Block class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/
#include "global_include.h"

// convert raw data to DCT
void DCTBlock::DCTData(bool hide)
{
/*
	if(hide)
   {
      printf(" -- raw --\n");
      PrintBlock(raw, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
	}
*/
/*
	if(hide)
   {
      for(i = 0; i < DCT_BLOCKSIZE; ++i)
      {
         raw[i] = 0;
      }
   }
  */ 
      
	vid->ct2->dct(dct, raw, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
   
   
/*
   if(hide)
   {
   	printf(" -- dct --\n");
   	PrintBlock(dct, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
	}
*/
}

// convert DCT to raw data
void DCTBlock::iDCTData(bool hide)
{
/*
	if(hide)
   {
      printf(" -- qd --\n");
      PrintBlock(qd, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
      printf(" -- dct --\n");
      PrintBlock(dct, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
   }
*/

	vid->ct2->idct(raw, dct, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
   
   for(i = 0; i < DCT_BLOCKSIZE; ++i)
   {
      if(raw[i] > 0)    raw[i] = raw[i] + 0.5;
      else              raw[i] = raw[i] - 0.5;
      
      if(raw[i] > 255)	raw[i] = 255;
      if(raw[i] < 0)	   raw[i] = 0;
      
      raw[i] = uInt8(raw[i]);
   }
   
   /*
   if(layer == 0)
   {
	   q = vid->uQ[layer];
      for(i = 0; i < DCT_BLOCKSIZE; ++i)
      {
         raw[i] = (raw[i] + 0)*0.5;
      }
   }
   */
   
/*
   if(hide)
   {
      printf(" -- raw --\n");
      PrintBlock(raw, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
   }
*/ 
}

// quantized dct values
void DCTBlock::qData(bool hide)
{
	// uniform quantization table is 2^n.
   q = vid->uQ[layer];

	// ZigZag dct data
   ZigZag();

	/*
	if((float)dct[0]/(float)q > 0)
   {
      ac = sInt16((float)dct[0]/(float)q + 0.5);
   } else {
      ac = sInt16((float)dct[0]/(float)q - 0.5);
   }
   */
   
   for(i = 0; i < DCT_BLOCKSIZE; ++i)
   {
   	if((float)dct[i]/(float)q > 0)
      {
         qd[i] = sInt16((float)dct[i]/(float)q + 0.5);
      } else {
         qd[i] = sInt16((float)dct[i]/(float)q - 0.5);
      }
   }
   
   /*
   if(hide)
   {
      printf(" -- raw --\n");
      PrintBlock(raw, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
      printf(" -- dct --\n");
      PrintBlock(dct, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
      printf(" -- qd --\n");
      PrintBlock(qd, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
   }
   */
   
   //BlockCopy(raw, qd, 0, 0, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH, 0, 0, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
}

// dequantized dct values
void DCTBlock::iqData()
{
	// uniform quantization table is 2^n.
   q = vid->uQ[layer];
   
   //dct[0] = ac*q;
   for(i = 0; i < DCT_BLOCKSIZE; ++i)
   {
	   dct[i] = qd[i]*q;
   }

   // unZigZag dct data
   iZigZag();

   /*
   printf(" -- qd --\n");
   PrintBlock(qd, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
   printf(" -- dct --\n");
   PrintBlock(dct, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
   */
   
   //BlockCopy(qd, raw, 0, 0, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH, 0, 0, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
}

int DCTBlock::Save(FILE *fp, bool pFrame)
{
	sInt8 t;
    
	// layer
	fwrite(&layer, 1, sizeof(uInt8), fp);
   
   if(pFrame)
   {
   	// from
   	fwrite(&(from.x), 1, sizeof(uInt16), fp);
      fwrite(&(from.y), 1, sizeof(uInt16), fp);
      // to
   	fwrite(&(to.x), 1, sizeof(uInt16), fp);
      fwrite(&(to.y), 1, sizeof(uInt16), fp);
   }
   
   // ac
   //fwrite(&ac, 1, sizeof(sInt16), fp);
   // dq
   //fwrite(&(qd[1]), DCT_BLOCKSIZE-1, sizeof(sInt8), fp);
   
   
   // dq
   for(i = 0; i < DCT_16BITBLOCKS; ++i)
   {
   	fwrite(&(qd[i]), 1, sizeof(sInt16), fp);
   }
   for(; i < DCT_BLOCKSIZE; ++i)
   {
   	t = qd[i];
   	fwrite(&t, 1, sizeof(sInt8), fp);
   }
   
   
   return 0;
}

int DCTBlock::Load(FILE *fp, bool pFrame)
{
	sInt8 t;

	// layer
	fread(&layer, 1, sizeof(uInt8), fp);
   
   if(pFrame)
   {
   	// from
   	fread(&(from.x), 1, sizeof(uInt16), fp);
      fread(&(from.y), 1, sizeof(uInt16), fp);
      // to
   	fread(&(to.x), 1, sizeof(uInt16), fp);
      fread(&(to.y), 1, sizeof(uInt16), fp);
   }
   
   // ac
   //fread(&ac, 1, sizeof(sInt16), fp);
   // dq
   //fread(&(qd[1]), DCT_BLOCKSIZE-1, sizeof(sInt8), fp);
   
   // dq
   for(i = 0; i < DCT_16BITBLOCKS; ++i)
   {
   	fread(&(qd[i]), 1, sizeof(sInt16), fp);
   }
   for(; i < DCT_BLOCKSIZE; ++i)
   {
	   //qd[i] = 0; // set to zero
   	fread(&t, 1, sizeof(sInt8), fp);
      qd[i] = t;
   }
   
   
   return 0;
}


// ZigZag dct data
void DCTBlock::ZigZag()
{
	uInt8	 l, n, zzi, j, c, pos;
   double zz [DCT_BLOCKSIZE]; // zigzap dct data
   
   memset(zz, 0, sizeof(double)*DCT_BLOCKSIZE);
   
   // top half
   zzi = 0;
   i = 0;
   j = 0;
   c = 0;
   for(n = 0; n < DCT_BLOCKWIDTH*0.5; ++n)
   {
   	for(l = 0; l <= c; ++l)
   	{
   		pos = j*DCT_BLOCKWIDTH + i;
         zz[zzi] = dct[pos];
         //dct[pos] = 0;
         
         zzi++;
         i++;
         j--;
   	}
      c++;
      j++;
      
      for(l = 0; l <= c; ++l)
   	{
      	pos = j*DCT_BLOCKWIDTH + i;
         zz[zzi] = dct[pos];
         //dct[pos] = 0;
         
         zzi++;
         i--;
         j++;
      }
      c++;
      i++;
   }

	
   // bottom half
   zzi = (DCT_BLOCKSIZE + DCT_BLOCKWIDTH)*0.5;
   i = 1;
   j = DCT_BLOCKWIDTH - 1;
   c = DCT_BLOCKWIDTH - 2;
   for(n = 0; n < DCT_BLOCKWIDTH*0.5; ++n)
   {
   	for(l = 0; l <= c; ++l)
   	{
      	pos = j*DCT_BLOCKWIDTH + i;
         zz[zzi] = dct[pos];
         //dct[pos] = 0;
         
         zzi++;
         i++;
         j--;
      }
      c--;
      i--;
      j += 2;
    	
      if( (i >= DCT_BLOCKWIDTH) || (j >= DCT_BLOCKWIDTH))
      	break;

		for(l = 0; l <= c; ++l)
   	{
      	pos = j*DCT_BLOCKWIDTH + i;
         zz[zzi] = dct[pos];
         //dct[pos] = 0;
         
         zzi++;
         i--;
         j++;
      }
      c--;
      i += 2;
      j--;
   }
   //
   
   /*
   printf(" -- dct --\n");
   PrintBlock(dct, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
   printf(" -- zz --\n");
   PrintBlock(zz, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
   */
   
   /*
	for(i = 0; i < DCT_BLOCKSIZE; ++i)
   {
   	zz[i] = dct[i];
   }
   */
   
   //
   for(i = 0; i < DCT_BLOCKSIZE; ++i)
   {
   	dct[i] = zz[i];
   }
}


// unZigZag qd data
void DCTBlock::iZigZag()
{
	uInt8	 l, n, zzi, j, c, pos;
   double zz [DCT_BLOCKSIZE]; // zigzap dct data
   
   memset(zz, 0, sizeof(double)*DCT_BLOCKSIZE);
   
   // top half
   zzi = 0;
   i = 0;
   j = 0;
   c = 0;
   for(n = 0; n < DCT_BLOCKWIDTH*0.5; ++n)
   {
   	for(l = 0; l <= c; ++l)
   	{
   		pos = j*DCT_BLOCKWIDTH + i;
         zz[pos] = dct[zzi];
         //dct[pos] = 0;
         
         zzi++;
         i++;
         j--;
   	}
      c++;
      j++;
      
      for(l = 0; l <= c; ++l)
   	{
      	pos = j*DCT_BLOCKWIDTH + i;
         zz[pos] = dct[zzi];
         //dct[pos] = 0;
         
         zzi++;
         i--;
         j++;
      }
      c++;
      i++;
   }

	
   // bottom half
   zzi = (DCT_BLOCKSIZE + DCT_BLOCKWIDTH)*0.5;
   i = 1;
   j = DCT_BLOCKWIDTH - 1;
   c = DCT_BLOCKWIDTH - 2;
   for(n = 0; n < DCT_BLOCKWIDTH*0.5; ++n)
   {
   	for(l = 0; l <= c; ++l)
   	{
      	pos = j*DCT_BLOCKWIDTH + i;
         zz[pos] = dct[zzi];
         //dct[pos] = 0;
         
         zzi++;
         i++;
         j--;
      }
      c--;
      i--;
      j += 2;
    	
      if( (i >= DCT_BLOCKWIDTH) || (j >= DCT_BLOCKWIDTH))
      	break;

		for(l = 0; l <= c; ++l)
   	{
      	pos = j*DCT_BLOCKWIDTH + i;
         zz[pos] = dct[zzi];
         //dct[pos] = 0;
         
         zzi++;
         i--;
         j++;
      }
      c--;
      i += 2;
      j--;
   }
   //
   
   /*
   printf(" -- dct --\n");
   PrintBlock(dct, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
   printf(" -- zz --\n");
   PrintBlock(zz, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
   */
	/*
	for(i = 0; i < DCT_BLOCKSIZE; ++i)
   {
   	zz[i] = dct[i];
   }
   */
   
   //
   for(i = 0; i < DCT_BLOCKSIZE; ++i)
   {
   	dct[i] = zz[i];
   }
}

