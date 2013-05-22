/****************************************
 filename:    model.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: 
 ****************************************/
#include "global.h"

cModel::cModel()
{
}

cModel::~cModel()
{
   Clear();
}

void cModel::Clear()
{
   uInt32 i;
   cPolygon *p;
   
   for(i = 0; i < mPolygons.size(); ++i)
   {
      p = mPolygons[i];
      if(p != NULL)
         delete p;
   }
   
   mPolygons.clear();
}

void cModel::Draw(bool movex, bool movey, float offsetx, float offsety)
{
   uInt32 i;
   for(i = 0; i < mPolygons.size(); ++i)
   {
      mPolygons[i]->Draw();
      
      if(movex)
      {
         glTranslatef(mPolygons[i]->mWidth + offsetx, 0, 0);
      }
      
      if(movey)
      {
         glTranslatef(0, mPolygons[i]->mHeight + offsety, 0);
      }
   }
}

/*
 [# comment]
 < "model = [" | "" >
 < polygon >
 ...
 ]
 */
/*
 Example:
 # ----------------
 # Model Data
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
 */
int cModel::Load(char **str, uInt32 &size)
{
   cPolygon *p;
   char  c;
   
   //
   if((str == NULL) || (size < 1)) return 1; // error
   Clear();
   
   // remove comments
   RemoveStrComments(str, size);
   
   //sscanf(*str, "model = [\n");
   MoveToNextLine(str, size);
   
   while(size > 0)
   {
      p = new cPolygon();
      p->Load(str, size);
      
      mPolygons.push_back(p);
      if((*str) == NULL) break;
      
      c = (*str)[0];
      if(c == ']') break;
   }
   
   if((*str) != NULL)
   {
      // remove last ']'
      MoveToNextLine(str, size);
   }

   // get width, height and depth
   uInt32 i, j;
   float minX, minY, minZ, maxX, maxY, maxZ;
   minX = mPolygons[0]->mVertices[0].x;
   minY = mPolygons[0]->mVertices[0].y;
   minZ = mPolygons[0]->mVertices[0].z;
   maxX = minX; maxY = minY; maxZ = minZ;
   for(j = 0; j < mPolygons.size(); ++j)
   {
      p = mPolygons[j];
      for(i = 0; i < p->mVertices.size(); ++i)
      {
         if(p->mVertices[i].x < minX) minX = p->mVertices[i].x;
         if(p->mVertices[i].x > maxX) maxX = p->mVertices[i].x;
         if(p->mVertices[i].y < minY) minY = p->mVertices[i].y;
         if(p->mVertices[i].y > maxY) maxY = p->mVertices[i].y;
         if(p->mVertices[i].z < minZ) minZ = p->mVertices[i].z;
         if(p->mVertices[i].z > maxZ) maxZ = p->mVertices[i].z;
      }
   }
   mWidth  = maxX - minX;
   mHeight = maxY - minY;
   mDepth  = maxZ - minZ;
   //
   
   return 0;
}

// load file and dump to string, pass string to string load
int cModel::Load(const char *filename)
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