/****************************************
filename:    decodeMain.cpp
description: main file, handles entry point and commandline flags
project:     Video Decoding Main
created by:  Joseph E. Sutton
version:     

Format: decodeVideo <filename>
Example: decodeVideo video.cmp
****************************************/
#define MAIN
#include "global_include.h"

int main(int argc, char *argv[])
{
   int pos;
	struct timeb sTime, eTime;
   
   char cmpFile[256], rawFile[256];
   uInt16 frameWidth, frameHeight;
	float fps;
	//
   
   ftime(&sTime);
   
   // Default
   frameWidth = 480;
   frameHeight = 368;
   fps = 12;
   strcpy(cmpFile, "static_camera2" COMPRESSED_EXT);

   // Read args
   if(argc < 1)
   {
      printf("Invalid Number of Arguments\n"
            "Format: %s <filename>\n"
            "Example: %s video%s\n", "decodeVideo", "decodeVideo", COMPRESSED_EXT);
      return 1;
   }
   
   strncpy(cmpFile, argv[1], 255);

   // find ext and replace end for new files
   pos = (int)(strstr(cmpFile, COMPRESSED_EXT) - cmpFile);
   memset(rawFile, 0, 255*sizeof(char));
   strncpy(rawFile, cmpFile, pos);
   strcpy(&(rawFile[pos]), VIDEO_EXT);
   
   // allocate
	vid = new Video(frameWidth, frameHeight, fps);

   // Load Video
   vid->LoadRaw(rawFile);
   
   //
   if( !vid->LoadEncoded(cmpFile) )
   {
   	vid->PrintInfo();
   
      vid->Decode();
	}
   
   
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
   
   //
   // Create Diff from Raw and Qd Data
   vid->CreateDiff();
   vid->DisplayInit(argc, argv);
   vid->DisplayLoop();
   
   // free
   delete vid;
   
	return 0;
}
