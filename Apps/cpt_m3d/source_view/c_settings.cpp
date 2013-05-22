/****************************************
filename:    settings.cpp
description: Settings Class
project:     
created by:  Joseph E. Sutton
version:     
****************************************/

#include "../include/types_structs.h"
#include "../include/c_settings.h"

Settings::Settings()
{
   uInt32 i;
   
   listName  = new char *[256];
   listValue = new char *[256];
   for(i = 0; i < 256; i++)
   {
      listName[i] = new char[256];
      memset(listName[i], '\0', 256);
      
      listValue[i] = new char[1024];
      memset(listValue[i], '\0', 1024);
   }
   
   size = 0;
}

Settings::~Settings()
{
   uInt32 i;
   for(i = 0; i < 256; i++)
   {
      delete [] listName[i];
      delete [] listValue[i];
   }
   
   delete [] listName;
   delete [] listValue;
}

int Settings::load(const char *filename)
{
   FILE *fd;
   char line[1024];
   sInt64 e, endFirst, startSecond, len, pos;
   
   //system("pwd"); // print current directory
   fd = fopen(filename, "r");
   if(fd == NULL) return 1;
   
   memset(line, '\0', 1024);
   e = getLine(fd, line);
   while(e > 0)
   {   
      len = strlen(line);
      
      // ignore lines that start with #
      if( (line[0] != '#') &&
          (len > 1)
        )
      {
         pos = (sInt64)strchr(line, '=') - (sInt64)line + 1;
         if(pos > 0)
         {
            //printf("line: %s\n", line);
            
            for(endFirst = 0; endFirst < len; endFirst++)
            { if(line[endFirst] == ' ') break; }
            
            strncpy(listName[size], line, (int)endFirst);
            
            for(startSecond = pos; startSecond < len; startSecond++)
            { if(line[startSecond] != ' ') break; }
            
            strncpy(listValue[size], &(line[startSecond]), (int)(len - startSecond));
            
            //printf("line: (%d) %s = %s\n", size, listName[size], listValue[size]);
            size++;
         }
      }
      
      memset(line, '\0', 1024);
      e = getLine(fd, line);
   }
   
   return 0;
}

int Settings::getLine(FILE *fp, char *line)
{
   uInt32 n;
   
   n = 0;
   do
   {
      line[n] = fgetc(fp);
      if(line[n] == EOF)  {line[n] = '\0'; return 0;}
      if(line[n] == '\n') {line[n] = '\0'; return 1;}
      
      n++;
   } while(line[n] != EOF);
   
   return 0;
}

void Settings::getUInt32(const char *name, uInt32 &o)
{
   uInt32 i;
   for(i = 0; i < size; i++)
   {
      if(strcmp(name, listName[i]) == 0)
      {
         o = (uInt32)atol(listValue[i]);
         return;
      }
   }
}

void Settings::getUInt16(const char *name, uInt16 &o)
{
   uInt32 i;
   for(i = 0; i < size; i++)
   {
      if(strcmp(name, listName[i]) == 0)
      {
         o = (uInt16)atol(listValue[i]);
         return;
      }
   }
}

void Settings::getUInt8(const char *name, uInt8 &o)
{
   uInt32 i;
   for(i = 0; i < size; i++)
   {
      if(strcmp(name, listName[i]) == 0)
      {
         o = (uInt8)atoi(listValue[i]);
         return;
      }
   }
}

void Settings::getFloat(const char *name, float &o)
{
   uInt32 i;
   for(i = 0; i < size; i++)
   {
      if(strcmp(name, listName[i]) == 0)
      {
         o = (float)atof(listValue[i]);
         return;
      }
   }
}

void Settings::getDouble(const char *name, double &o)
{
   uInt32 i;
   for(i = 0; i < size; i++)
   {
      if(strcmp(name, listName[i]) == 0)
      {
         o = (double)atof(listValue[i]);
         return;
      }
   }
}

void Settings::getString(const char *name, char *out)
{
   uInt32 i;
   
   memset(out, '\0', strlen(out));
   // look at all lines
   for(i = 0; i < size; i++)
   {
      if(strcmp(name, listName[i]) == 0)
      {
         //printf("%s: (%d) %s = %s\n", name, i, listName[i], listValue[i]);
         strcpy(out, listValue[i]);
         break;
      }
   }
}

void Settings::getColor(const char *name, double *c)
{
   uInt32 i, j;
   char *t;
   
   // look at all lines
   for(i = 0; i < size; i++)
   {
      if(strcmp(name, listName[i]) == 0)
      {
         // parse by ","'s
         j = 0;
         t = strtok(listValue[i], ",");
         while(t != NULL)
         {
            c[j] = atof(t);
            t = strtok(NULL, ",");
            j++;
         }
         break;
      }
   }
}

void Settings::getColor(const char *name, Color &c)
{
   uInt32 i, j;
   char *t;
   
   // look at all lines
   for(i = 0; i < size; i++)
   {
      if(strcmp(name, listName[i]) == 0)
      {
         // parse by ","'s
         j = 0;
         t = strtok(listValue[i], ",");
         while(t != NULL)
         {
            if(j == 0) c.r = atof(t)/255.0f;
            if(j == 1) c.g = atof(t)/255.0f;
            if(j == 2) c.b = atof(t)/255.0f;
            
            t = strtok(NULL, ",");
            j++;
         }
         break;
      }
   }
}
