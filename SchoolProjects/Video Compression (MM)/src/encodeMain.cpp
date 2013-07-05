/****************************************
filename:    encodeMain.cpp
description: main file, handles entry point and commandline flags
project:     Video Encoding Main
created by:  Joseph E. Sutton
version:     

Format: encodeVideo <filename> <scale(0.01 to 10.00)> <rotate(0 to 359)> <filter(1 or 0)>
Example: encodeVideo video.576v 1.0 1.0
****************************************/
#define MAIN
#include "global_include.h"

int main(int argc, char *argv[])
{
   int pos;
	struct timeb sTime, eTime;
   
   char rawFile[256], cmpFile[256];
   float Q[NUM_LAYERS]; // foreground/background quantization
   uInt16 frameWidth, frameHeight;
	float fps;
	//   

	// set start time
	ftime(&sTime);
   
   // seed random
	srand ( time(NULL) );


   // Default
   frameWidth = 480;
   frameHeight = 368;
   fps = 12;
   strcpy(rawFile, "static_camera2" VIDEO_EXT);
   Q[0] = 1.0;
   Q[1] = 1.0;

   // Read args
   if(argc < 3)
   {
      printf("Invalid Number of Arguments\n"
            "Format: %s <filename> <foreground quantization(0.01 to 1.00)> <background quantization(0.01 to 1.00)>\n"
            "Example: %s video%s 1.0 1.0\n", "encodeVideo", "encodeVideo", VIDEO_EXT);
      return 1;
   }
   
   strncpy(rawFile, argv[1], 255);
   Q[0] = atof(argv[2]);
   Q[1] = atof(argv[3]);
   
   // find ext and replace end for new files
   pos = (int)(strstr(rawFile, VIDEO_EXT) - rawFile);
   memset(cmpFile, 0, 255*sizeof(char));
   strncpy(cmpFile, rawFile, pos);
   strcpy(&(cmpFile[pos]), COMPRESSED_EXT);
   
   // allocate
	vid = new Video(frameWidth, frameHeight, fps);
   vid->SetQ(Q);
   
   // Load Video
   vid->LoadRaw(rawFile);
   
   vid->PrintInfo();
   
   //
   vid->Encode();
   vid->SaveEncoded(cmpFile);
   
   printf("\n");
   printf("------------------------------------------------------------\n");
   printf("Done\n");
   
   ftime(&eTime);
   
   time_t t;
   struct tm * timeinfo;
   t = eTime.time - sTime.time;
   timeinfo = localtime(&t);
   printf("Total Time: %0.2d:%0.2d\n", timeinfo->tm_min, timeinfo->tm_sec);
   
   printf("------------------------------------------------------------\n");
   
   
	
   // For Display
   vid->printEncoderInfo    = true;
   vid->showMotionVectors   = true;
   vid->showDDMotionVectors = false;
   vid->showSegGrid         = true;
   
   vid->Decode();     // fill dqData
   
   vid->CreateDiff();
   vid->DisplayInit(argc, argv);
   vid->DisplayLoop();
   
   //
   
   
   // free
   delete vid;
   
	return 0;
}
