/****************************************
 filename:    anim_model_gfx.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/08
 description: 
 ****************************************/
#include "global.h"

cAnimModelGfx::cAnimModelGfx()
{
}

cAnimModelGfx::~cAnimModelGfx()
{
   Clear();
}

void cAnimModelGfx::Clear()
{
   uInt32 i;
   cModel *m;
   
   for(i = 0; i < mModels.size(); ++i)
   {
      m = mModels[i];
      if(m != NULL)
         delete m;
   }
   
   mModels.clear();
}

/*
 [# comment]
 name = <name_of_animation:string>
 [# comment]
 delay = <frame_display_second:float>
 < model1 >
 [# comment]
 delay = <frame_display_second:float>
 < model2 >
 ...
 */
/*
 Example:
 # ================
 # Animation Data
 name = Flipper_Walk
 # ----------------
 # frame 1
 delay = 0.1
 model = [
 # ---------
 # poly 1
 color = 1, 1, 1, 1
 type = open
 data = {
 0, 0, 0
 }
 # ---------
 # poly 2
 color = 1, 1, 1, 1
 type = open
 data = {
 0, 0, 0
 }
 ]
 # ----------------
 # frame 2
 delay = 0.1
 model = [
 # ---------
 # poly 1
 color = 1, 1, 1, 1
 type = open
 data = {
 0, 0, 0
 }
 ]
 # ================
 */
int cAnimModelGfx::Load(char **str, uInt32 &size)
{
   cModel *m;
   
   // remove comments
   RemoveStrComments(str, size);
   
   // read name
   sscanf(*str, "name = %s\n", mName);
   MoveToNextLine(str, size);
      
   while(size > 0)
   {
      // remove comments
      RemoveStrComments(str, size);
      
      m = new cModel();
      
      // read delay
      sscanf(*str, "delay = %f\n", &(m->mDelay));
      MoveToNextLine(str, size);
      
      m->Load(str, size);
      
      mModels.push_back(m);
   }
   
   return 0;
}

// load file and dump to string, pass string to string load
int cAnimModelGfx::Load(const char *filename)
{
   FILE *fp;
   char *ostr, *fstr;
   uInt32 fsize, pos;
   size_t result;
   int e;
   
   fp = fopen(filename, "r");
   if(fp == NULL) return 1;
   
   // get filesize
   fseek(fp, 0, SEEK_END);
   fsize = ftell(fp);
   rewind(fp);
   
   // read all file data to str
   ostr = new char[fsize+1];
   pos = 0;
   result = 1;
   while(result)
   {
      result = fread(&(ostr[pos]), 1, fsize - pos, fp);
      pos += result;
   }
   fclose(fp);
   
   // fstr is the temp point, ostr used to delete after scan
   fsize = pos;
   fstr = ostr;
   //
   e = Load(&fstr, fsize);
   
   delete [] ostr;
   return e;
}



