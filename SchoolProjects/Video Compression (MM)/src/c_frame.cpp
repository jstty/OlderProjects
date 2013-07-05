/****************************************
 filename:    c_frame.cpp
 description: Video Frame class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/
#include "global_include.h"

/****************************************
Frame
****************************************/
void Frame::Allocate(uInt32 s)
{
	uInt8 c;
	for(c = 0; c < NUM_COLORS + 1; c++)
   {
   	color[c].Allocate(s);
	}
}

void Frame::CreateDiff()
{
	uInt8 c;
	for(c = 0; c < NUM_COLORS; c++)
   {
   	color[c].CreateDiff();
	}
}



/****************************************
FrameColor
****************************************/
FrameColor::FrameColor()
{
	dSize = 0;
	rawData  = NULL;
   qdData   = NULL;
   diffData = NULL;
}

FrameColor::~FrameColor()
{
	if(rawData  != NULL) delete [] rawData;
   if(qdData   != NULL) delete [] qdData;
   if(diffData != NULL) delete [] diffData;
}

void FrameColor::Allocate(uInt32 s)
{
	dSize    = s;
   rawData  = new uInt8[s];
   qdData   = new uInt8[s];
   diffData = new uInt8[s];
}


void FrameColor::CreateDiff()
{
	uInt32 i;
	for(i = 0; i < dSize; ++i)
   {
   	diffData[i] = abs(rawData[i] - qdData[i]);
   }
}



