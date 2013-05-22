/****************************************
 filename:    anim_model_bank.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/08
 description: 
 ****************************************/
#include "global.h"

cAnimModelBank::cAnimModelBank()
{
}

void cAnimModelBank::Clear()
{
   for(i = 0; i < mAnimModelGfxs.size(); ++i)
   {
      mTmpGfx = mAnimModelGfxs[i];
      if(mTmpGfx != NULL)
         delete mTmpGfx;
   }
   
   mAnimModelGfxs.clear();
}

// List of files to load
/*
 models/../blah_1.anim
 models/../blah_2.anim
 */
int cAnimModelBank::Load(const char *filename)
{
   uInt16 len;
   FILE *fp;
   char file[1024];
   
   //
   Clear();
   
   fp = fopen(filename, "r");
   if(fp == NULL) return 1; // error
   
   while(!feof(fp))
   {
      fgets(file, 1024, fp);
      len = strlen(file);
      file[len-1] = '\0';
      
      // not comment
      if(file[0] != '#')
      {
         mTmpGfx = new cAnimModelGfx();
         mTmpGfx->Load(file);
      
         mAnimModelGfxs.push_back(mTmpGfx);
      }
   }
   
   fclose(fp);
   
   return 0;
}


cAnimModelGfx *cAnimModelBank::Find(const char *name)
{
   for(i = 0; i < mAnimModelGfxs.size(); ++i)
   {
      mTmpGfx = mAnimModelGfxs[i];
      
      if(strcmp(mTmpGfx->mName, name) == 0)
      {
         return mTmpGfx;
      }
   }
   
   return NULL;
}
