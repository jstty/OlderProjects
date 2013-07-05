/****************************************
 filename:    c_segmentation.cpp
 description: Segmentation class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/
#include "global_include.h"

Segmentation::Segmentation()
{
   numFrames = 0;
   Frames = NULL;
}

Segmentation::~Segmentation()
{
   if(Frames != NULL) delete [] Frames;
   
   uInt32 i;
   for(i = 0; i < numFrames; ++i)
   {
   	if(ddVectorList[i] != NULL) delete [] ddVectorList[i];
   }
   
   if(ddVectorList != NULL) delete [] ddVectorList;
}

void Segmentation::Allocate(uInt16 n)
{
   numFrames = n;
   Frames = new SegFrame[n];
   
   ddVectorList = new vector*[n];
}

void Segmentation::SetFrameData(Frame *f)
{
   uInt32 i, numSeqBlocks;
   uInt32 size;
   
   size = (vid->width)*(vid->height);
   numSeqBlocks = uInt32(float(size)/float(SEG_BLOCKSIZE));
   
   for(i = 0; i < numFrames; ++i)
   {
      Frames[i].Allocate(numSeqBlocks);
      Frames[i].SetData(&(f[i]));
   }
}


int Segmentation::Split()
{
	uInt32 i, j;
   
   // -------------------------------------------
   // Searching
   printf("Searching:\n   ");
   // num Frames - 1, because using next frame
   for(i = 0; i < (numFrames-1); ++i)
   {      
      Frames[i].Search(&(Frames[i+1]));
      printf(".");
   }
   printf("\n  ");
	// -------------------------------------------

	// -------------------------------------------
   // Grouping   
   printf("Grouping:\n   ");
   for(i = 0; i < (numFrames-1); ++i)
   {
	   ddVectorList[i] = new vector[Frames[0].numSeg];
   	for(j = 0; j < Frames[0].numSeg; ++j)
   	{
   		ddVectorList[i][j].x = Frames[i].segVectorList[j].x - Frames[i+1].segVectorList[j].x;
         ddVectorList[i][j].y = Frames[i].segVectorList[j].y - Frames[i+1].segVectorList[j].y;
         
         
         // zero or constant
         if(
             ( ((Frames[i].segVectorList[j].x > -SEG_THRESHOLD) && (Frames[i].segVectorList[j].x < SEG_THRESHOLD)) &&
               ((Frames[i].segVectorList[j].y > -SEG_THRESHOLD) && (Frames[i].segVectorList[j].y < SEG_THRESHOLD)) )
             || 
         	 ( ((ddVectorList[i][j].x > -SEG_THRESHOLD) && (ddVectorList[i][j].x < SEG_THRESHOLD)) &&
               ((ddVectorList[i][j].y > -SEG_THRESHOLD) && (ddVectorList[i][j].y < SEG_THRESHOLD)) )
           )
			{
         	Frames[i].Seg[ Frames[i].segVectorList[j].SegBlockIndex ].layer = LAYER_BACKGROUND;
         } else {
         	Frames[i].Seg[ Frames[i].segVectorList[j].SegBlockIndex ].layer = LAYER_FOREGROUND;
         }
         
         
         /*
         if(j == 660)
         {
         	Frames[i].Seg[ Frames[i].segVectorList[j].SegBlockIndex ].layer = LAYER_BACKGROUND;
         } else {
         	Frames[i].Seg[ Frames[i].segVectorList[j].SegBlockIndex ].layer = LAYER_FOREGROUND;
         }
         */
   	}
   
      printf(".");
   }
   printf("\n");
   // -------------------------------------------
   
   // set last frame to iFrame because there is not frame after that
   Frames[numFrames-1].SetAsiFrame();
   
   return 0;
}


void Segmentation::DrawMotionVectors(uInt32 cFrame)
{
	Frames[cFrame].DrawMotionVectors();
}


void Segmentation::DrawDDMotionVectors(uInt32 cFrame)
{
	uInt32 i;
	float x, y;
   
   // ddVector is not defined for the last frame
   if(cFrame >= numFrames-1) return;
   
   
   for(i = 0; i < Frames[0].numSeg; ++i)
   {
      if(Frames[cFrame].Seg[i].layer == LAYER_FOREGROUND) glColor3f( 1.0, 1.0, 0.0 ); // yellow - foreground
      else                                                glColor3f( 0.0, 0.0, 1.0 ); // blue   - background
   
   	x = Frames[cFrame].Seg[i].mv.from.x + vid->width + (SEG_BLOCKWIDTH >> 1);
      y = Frames[cFrame].Seg[i].mv.from.y + (SEG_BLOCKWIDTH >> 1);
   	glVertex2f(x, y); 
   
	   x = ddVectorList[cFrame][i].x + Frames[cFrame].Seg[i].mv.from.x + vid->width + (SEG_BLOCKWIDTH >> 1);
      y = ddVectorList[cFrame][i].y + Frames[cFrame].Seg[i].mv.from.y + (SEG_BLOCKWIDTH >> 1);
   	glVertex2f(x, y); 
      
   }
}


void Segmentation::DrawGrid()
{
	uInt16 x, y;
   uInt16 w, h;
   
   w = vid->width/SEG_BLOCKWIDTH;
   h = vid->height/SEG_BLOCKWIDTH;

	glBegin(GL_LINES);
   
	for(x = 1; x < w; ++x)
   {
   	glVertex2f( 16*x + vid->width, 0 );
		glVertex2f( 16*x + vid->width, vid->height );
	}

   for(y = 1; y < h; ++y)
   {
      glVertex2f(   vid->width, 16*y);
		glVertex2f( 2*vid->width, 16*y);
   }
   glEnd();
   
}


