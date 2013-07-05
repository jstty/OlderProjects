/****************************************
 filename:    c_video.h
 description: Video class
 project:     Video Encoder/Decoder
 created by:  Joseph E. Sutton
 version:     
 date:        11/06/2009
****************************************/

#ifndef _VIDEO_
#define _VIDEO_

class Video
{
	public:
   	uInt16  width;
      uInt16  height;
      float fps;
      
      float rQ[NUM_LAYERS]; // quanlization used on encoding/decoding
   	float uQ[NUM_LAYERS]; // quanlization used on encoding/decoding
   
   	Ct2 *ct2;
      
      bool  printEncoderInfo;
      bool  showMotionVectors;
      bool  showDDMotionVectors;
      bool  showSegGrid;

   	//
   	Video(uInt16 w, uInt16 h, uInt16 f);
   	~Video();
      
      void Allocate();
      void Free();
      
      void PrintInfo();
      
      void SetQ(const float Q[NUM_LAYERS]);
   
		int LoadRaw(const char *filename); 
	   void CreateDiff();
         
      // encode
   	int Encode();
   	// decode
      int Decode();
      
      // save encoded data
      int SaveEncoded(const char *filename); 
      // load encoded data
   	int LoadEncoded(const char *filename);
   
   
      void DisplayInit(int argc, char *argv[]);
      void DisplayLoop();
      
      static void DisplayFunc();
      static void KeyboardFunc(unsigned char key, int x, int y);
      static void TimerFunc(int extra);
      
      void Display();
      void Keyboard(unsigned char key, int x, int y);
   	void Timer();
   
   private:
   	char filename[256];
   
   	Segmentation *seg;
	   DCTEncoder   *dct;
   
		uInt16  numFrames;
	   Frame	 *Frames;
      sInt16 currentFrame;
      
      uInt8 playState; // 0 - paused, 1 - playing
      
      uInt8 numTextures;
      GLuint *displayTextures;
      
      int prevTime, currentTime;
      
      void UpdateTextures();
      void drawTextures(uInt8 start = 0);
      void applyFrameToTexture(Frame *f, uInt8 textureID, uInt8 type);
      
      void drawText();
      void drawText(uInt16 x, uInt16 y, char *str);
      
      void drawMotionVectors();
      void drawDDMotionVectors();
      void drawSegGrid();
};

#endif
/* _VIDEO_ */
