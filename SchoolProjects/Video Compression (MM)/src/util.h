/****************************************
 filename:    util.h
 description: Utility Functions
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/11/2009
****************************************/

#ifndef _UTIL_
#define _UTIL_

template<class T1, class T2>
void BlockCopy(T1 *src, T2 *des, 
	uInt16 srcX, uInt16 srcY, 
   uInt16 srcWidth, uInt16 srcHeight, 
   uInt16 desX, uInt16 desY, 
   uInt16 desWidth, uInt16 desHeight)
{
	uInt32 x, y, srcPos, desPos;
   
   for(y = 0; ((y + srcY) < srcHeight) && ((y + desY) < desHeight); ++y)
   {
   	for(x = 0; ((x + srcX) < srcWidth) && ((x + desX) < desWidth); ++x)
      {
      	srcPos = (y + srcY)*srcWidth + (x + srcX);
         desPos = (y + desY)*desWidth + (x + desX);
         des[desPos] = src[srcPos];
      }
   }
}

template<class T1>
void PrintBlock(T1 *data, uInt16 width, uInt16 height)
{
	uInt32 x, y, pos;
   
   for(y = 0; y < height; ++y)
   {
   	printf("%0.2d) [", y);
   	for(x = 0; x < width; ++x)
      {
      	pos = y*width + x;
         
         if(data[pos] == 0)
         	printf(" ---");
         else
	         printf("%+0.1f", (float)data[pos]);
         
         if((x + 1) < width) printf(", ");
      }
      printf("]\n");
   }
}


#endif
/* _UTIL_ */
