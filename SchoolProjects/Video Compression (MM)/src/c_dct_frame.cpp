/****************************************
 filename:    c_dct_frame.cpp
 description: Video Frame class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/
#include "global_include.h"

/****************************************
DCTFrame
****************************************/
void DCTFrame::Allocate(uInt32 nd)
{
	uInt8 c;
	for(c = 0; c < NUM_COLORS; c++)
   {
   	color[c].Allocate(nd);
	}
}

void DCTFrame::SetData(const FrameColor fc[NUM_COLORS])
{
	uInt8 c;
	for(c = 0; c < NUM_COLORS; c++)
   {
   	color[c].SetData(&(fc[c]));
	}
}

void DCTFrame::Encode(const SegFrame *sf, bool pFrame)
{
	uInt8 c;
	for(c = 0; c < NUM_COLORS; c++)
   {
   	color[c].Encode(sf, pFrame);
	}
}

void DCTFrame::Decode(const DCTFrame *prevFrame, bool pFrame)
{
	uInt8 c;
	for(c = 0; c < NUM_COLORS; c++)
   {
   	if(prevFrame != NULL)
      {
   		color[c].Decode(&(prevFrame->color[c]), pFrame);
      } else {
      	color[c].Decode(NULL, pFrame);
      }
	}
}

int DCTFrame::Save(FILE *fp, bool pFrame)
{
	int e = 0;
	uInt8 c;
	for(c = 0; c < NUM_COLORS; c++)
   {
   	e = color[c].Save(fp, pFrame);
      if(e)
      {
      	break;
      }
	}
   
   return 0;
}

int DCTFrame::Load(FILE *fp, bool pFrame)
{
	int e = 0;
	uInt8 c;
	for(c = 0; c < NUM_COLORS; c++)
   {
   	e = color[c].Load(fp, pFrame);
      if(e)
      {
      	break;
      }
	}
   
   return e;
}


/****************************************
DCTFrameColor
****************************************/
DCTFrameColor::DCTFrameColor()
{
	dSize = 0;
	qdData = NULL;

   numDCT = 0;
   DCT   = NULL;
}

DCTFrameColor::~DCTFrameColor()
{
	if(DCT != NULL) delete [] DCT;
}

void DCTFrameColor::Allocate(uInt32 nd)
{
   numDCT = nd;
   DCT   = new DCTBlock[nd];
}

void DCTFrameColor::SetData(const FrameColor *f)
{
	dSize = f->dSize;
	qdData = f->qdData;
   rawData = f->rawData;
}


void DCTFrameColor::Encode(const SegFrame *sf, bool pFrame)
{
	uInt32 i, j, a, b, size;
   
   size = (uInt32)(float(SEG_BLOCKWIDTH)/float(DCT_BLOCKWIDTH));
   
   // 1) copy segmintation data to dct size blocks   
   // copy raw data from color frame
   i = 0;
   for(j = 0; j < sf->numSeg; j++)
   {
   	for(a = 0; a < size; ++a)
   	{
         for(b = 0; b < size; ++b)
         {
            DCT[i].layer  = sf->Seg[j].layer;
            DCT[i].from.x = sf->Seg[j].mv.from.x + b*DCT_BLOCKWIDTH;
            DCT[i].from.y = sf->Seg[j].mv.from.y + a*DCT_BLOCKWIDTH;
            DCT[i].to.x   = sf->Seg[j].mv.to.x   + b*DCT_BLOCKWIDTH;
            DCT[i].to.y   = sf->Seg[j].mv.to.y   + a*DCT_BLOCKWIDTH;
         
            //iFrame
            BlockCopy(rawData, DCT[i].raw, DCT[i].from.x, DCT[i].from.y, vid->width, vid->height, 0, 0, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH);
            
            //pFrame
            // TODO
            // copy diff
            
            // 2) convert blocks to DCT
			   // 3) quantize DCT
            
            if(i == 374 )
            	DCT[i].DCTData(1);
            else
            	DCT[i].DCTData();
            
            if(i == 374 )
            	DCT[i].qData(1);
            else
            	DCT[i].qData();
            
            i++;
			}
   	}
   }
   
   
   /*
   // 4) copies DCT/qdData to dqData
   i = 0;
   for(y = 0; y < height; y += DCT_BLOCKWIDTH)
   {
   	for(x = 0; x < width; x += DCT_BLOCKWIDTH)
   	{
   		BlockCopy(DCT[i].qd, qdData, 0, 0, DCT_BLOCKWIDTH, DCT_BLOCKWIDTH, x, y, width, height);
         i++;
      }
   }
   */
}


void DCTFrameColor::Decode(const DCTFrameColor *prevFrame, bool pFrame)
{
	uInt32 i, x, y, a, b, size;
   //uInt32 xx, yy, pos;

	size = (uInt32)(float(SEG_BLOCKWIDTH)/float(DCT_BLOCKWIDTH));

	//
   i = 0;
   for(y = 0; y < vid->height; y += SEG_BLOCKWIDTH)
   {
   	for(x = 0; x < vid->width; x += SEG_BLOCKWIDTH)
   	{
      	for(a = 0; a < size; ++a)
   		{
   			for(b = 0; b < size; ++b)
   			{
            	// inverse quantize
               DCT[i].iqData();
               // inverse DCT
               
               if(i == 374 )
               	DCT[i].iDCTData(1);
               else
            		DCT[i].iDCTData();
               
               //iFrame
               BlockCopy(DCT[i].raw, qdData, 
                 0, 0,
                 DCT_BLOCKWIDTH, DCT_BLOCKWIDTH, 
                 x + b*DCT_BLOCKWIDTH,
                 y + a*DCT_BLOCKWIDTH,
                 vid->width, vid->height);
               
                 
               //pFrame (has from to pos), prevFrame != NULL
               // TODO
               // add to prevFrame
               
               i++;
				}
			}
		}
   }
   
}


int DCTFrameColor::Save(FILE *fp, bool pFrame)
{
	uInt32 i;
	int e = 0;
   
   if(pFrame)
   {
   	// number of DCT blocks
   	fwrite(&numDCT, 1, sizeof(uInt32), fp);
   }
   
   for(i = 0; i < numDCT; ++i)
   {
   	e = DCT[i].Save(fp, pFrame);
      if(e)
      {
      	break;
      }
   }
   
   return e;
}


int DCTFrameColor::Load(FILE *fp, bool pFrame)
{
	uInt32 i;
	int e = 0;
   
   if(pFrame)
   {
   	// number of DCT blocks
   	fread(&numDCT, 1, sizeof(uInt32), fp);
   }
   
   for(i = 0; i < numDCT; ++i)
   {
   	e = DCT[i].Load(fp, pFrame);
      if(e)
      {
      	break;
      }
   }
   
   return e;
}

