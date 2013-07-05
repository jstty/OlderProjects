/****************************************
filename:    main.cpp
description: main file, handles entry point and command-line flags
project:     astar
created by:  Joseph E. Sutton
version:   

Format: Astar -i <filename> [-A] [-backwards] [-smallg] [-noprint-search] [-print-timestep]
                            [-m <number> (filename is the string format)]
Examples:
   Forward   A*           > Astar -i inputfile0.txt
   Adaptive  A*           > Astar -i inputfile0.txt -A
   Backwards A*           > Astar -i inputfile0.txt -backwards
   Favor Smaller G-Value  > Astar -i inputfile0.txt -smallg
   Don't Display Searches > Astar -i inputfile0.txt -noprint-search
   Display Time Step      > Astar -i inputfile0.txt -print-timestep
   Multiple files & Don't Display Searches > Astar -i inputfile%d.txt -m 2 -noprint-search
 
****************************************/

#include "global.h"

void PrintHelp();

int main(int argc, char * const argv[])
{
   char filename[256], tmp[256];
   bool Adaptive, Backwards, useSmallerG, Verbose, showTimeStep;
   int  i, NumFiles;
   struct timeval	tv1, tv2;
   float  runtime, avgRuntime;
   Astar *astar;
   Map   *map;
   
   NumFiles     = 1;
   Adaptive     = false;
   Backwards    = false;
   useSmallerG  = false;
   Verbose      = true;
   showTimeStep = false;
   
   if(argc < 3)
   {
   	printf("ERROR: Invalid number of arguments\n");
   	PrintHelp();
      return 1;
   } else {
   
      // set options
   	int i;
   	for(i = 1; i < argc; ++i)
      {
         // file
         if( strcmp(argv[i], "-i") == 0 )
         {
         	if(i+1 < argc)
            {
            	strcpy(filename, argv[i+1]);
            } else {
            	printf("ERROR: Invalid argument\n");
            	PrintHelp();
            	return 1;
            }
         }
         // adaptive
         else if( strcmp(argv[i], "-A") == 0 )
         {
         	Adaptive = true;
         }
         // Backwards
         else if( strcmp(argv[i], "-backwards") == 0 )
         {
            Backwards = true;
         }
         // useHigherG
         else if( strcmp(argv[i], "-smallg") == 0 )
         {
            useSmallerG = true;
         }
         // Verbose
         else if( strcmp(argv[i], "-noprint-search") == 0 )
         {
            Verbose = false;
         }
         // showTimeStep
         else if( strcmp(argv[i], "-print-timestep") == 0 )
         {
            showTimeStep = true;
         }
         // multi-file
         else if( strcmp(argv[i], "-m") == 0 )
         {  
            if(i+1 < argc)
            {
            	NumFiles = atoi(argv[i+1]);
            }
         }
      }
   }
   
   printf("Adaptive      : %s\n", (Adaptive)     ?"yes":"no");
   printf("Backwards     : %s\n", (Backwards)    ?"yes":"no");
   printf("Use Smaller G : %s\n", (useSmallerG)  ?"yes":"no");
   printf("Show Searches : %s\n", (Verbose)      ?"yes":"no");
   printf("Show Time Step: %s\n", (showTimeStep) ?"yes":"no");
   
   // loop though the files, default NumFiles = 1
   avgRuntime = 0;
   for(i = 0; i < NumFiles; ++i)
   {
      if(Verbose)
         printf("----------------------------------\n");
      
      map   = new Map();
      astar = new Astar(map, Adaptive, Backwards, useSmallerG, Verbose, showTimeStep);      
   	sprintf(tmp, filename, i);
      
      // load input file
      if( map->Load(tmp) )
      {
         printf("ERROR: Loading file \"%s\"\n", tmp);
         return 1;
      }
      
      // load input file
      if( astar->Load(tmp) )
      {
         printf("ERROR: Loading file \"%s\"\n", tmp);
         return 1;
      }
      
      // start time
      gettimeofday(&tv1, NULL);
      
      // run search
      astar->Run();
      
      // end time
      gettimeofday(&tv2, NULL);
      runtime = (float)(tv2.tv_sec - tv1.tv_sec) + (float)(tv2.tv_usec - tv1.tv_usec)/1000000.0f;
      
      printf("----------------------------------\n");
      printf("File      : %s\n", tmp);
      printf("Searches  : %d\n", (int)astar->GetNumOfSearches());
      printf("Time Steps: %d\n", (int)astar->GetNumOfTimeSteps());
      printf("Cells Exp : %d\n", (int)astar->GetNumOfCellsExpanded());
      printf("Runtime   : %f\n", runtime);
      printf("----------------------------------\n");
      avgRuntime += runtime;
      
   	if(astar != NULL)
		   delete astar;
      
      if(map != NULL)
         delete map;
   }
   
   avgRuntime /= (float)NumFiles;
   
   printf("==================================\n");
   printf("Avg Runtime: %f\n", avgRuntime);
   printf("----------------------------------\n");

	return 0;
}

void PrintHelp()
{
   printf(
      "Format: Astar -i <filename> [-A] [-backwards] [-smallg] [-noprint-search] [-print-timestep]\n"
      "                            [-m <number> (filename is the string format)]\n"
      "Examples:\n"
      "   Forward   A*           > Astar -i inputfile0.txt\n"
      "   Adaptive  A*           > Astar -i inputfile0.txt -A\n"
      "   Backwards A*           > Astar -i inputfile0.txt -backwards\n"
      "   Favor Smaller G-Value  > Astar -i inputfile0.txt -smallg\n"
      "   Don't Display Searches > Astar -i inputfile0.txt -noprint-search\n"
      "   Display Time Step      > Astar -i inputfile0.txt -print-timestep\n"
      "   Multiple files & Don't Display Searches > Astar -i inputfile%%d.txt -m 2 -noprint-search\n"
   );
}
