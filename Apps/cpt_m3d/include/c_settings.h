/****************************************
filename:    settings.h
description: Settings Class
project:     
created by:  Joseph E. Sutton
version:     
****************************************/
#ifndef __SETTINGS__
#define __SETTINGS__

#include <stdio.h>
#include <string.h>

class Settings
{
   public:
      uInt32 width;
      uInt32 height;
   
      Settings();
      ~Settings();
      
      int load(const char *filename);
      
      void getUInt32(const char *name, uInt32 &o);
      void getUInt16(const char *name, uInt16 &o);
      void getUInt8 (const char *name, uInt8  &o);
      
      void getFloat (const char *name, float  &o);
      void getDouble(const char *name, double &o);
      
      void getString(const char *name, char *out);
      
      void getColor(const char *name, double *c);
      void getColor(const char *name, Color &c);
   
   protected:
      uInt32 size;
      char **listName;
      char **listValue;
      
      int getLine(FILE *fp, char *line);
};

#endif
/* __SETTINGS__ */
