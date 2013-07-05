/****************************************
 filename:    c_segmentation.h
 description: Segmintation class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/

#ifndef _SEGMENTATION_
#define _SEGMENTATION_

class Segmentation
{
   public:
      uInt16    numFrames;
      SegFrame *Frames;
      
      vector **ddVectorList;
      
      Segmentation();
      ~Segmentation();
      
      void Allocate(uInt16 n);
      void SetFrameData(Frame *f);
      
      // for ALL frames
      // 	calcs least error
      // 	clusters like vectors
      // 	assignest layers
      int Split();
      
      void DrawMotionVectors(uInt32 cFrame);
      void DrawDDMotionVectors(uInt32 cFrame);
      void DrawGrid();
};

#endif
/* _SEGMENTATION_ */
