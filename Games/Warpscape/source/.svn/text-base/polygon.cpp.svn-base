/****************************************
 filename:    polygon.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/08
 description: 
 ****************************************/
#include "global.h"

cPolygon::cPolygon()
{
}

void cPolygon::Translate(float x, float y, float z)
{
   uInt32 i;
   for(i = 0; i < mVertices.size(); ++i)
   {
      mVertices[i].x += x;
      mVertices[i].y += y;
      mVertices[i].z += z;
   }
}

void cPolygon::SwapTranslate(cPolygon *old) {
	uInt32 i;
	for (i = 0; i < mVertices.size(); ++i) {
		mVertices[i].x = old->GetVertices()[i].x;
		mVertices[i].y = old->GetVertices()[i].y;
		//mVertices[i].z = old->GetVertices()[i].z;
		//mVertices[i].z = mVertices[i].z;
	}
}

float cPolygon::GetFirstZ()
{
   return mVertices[0].z;
}

vector<Point3D> cPolygon::GetVertices() {
	return mVertices;
}

void cPolygon::Draw()
{
   game->mGraphics->Draw(mVertices, mColor);
}


/*
 [# comment]
 color = <red:float>, <green:float>, <blue:float>
 type = < "open" | "closed" >
 < "data = {" | "" >
 <x:float>, <y:float>, <z:float>
 ...
 }
 */
/*
 Example:
 # ----------------
 # poly 1
 color = 1, 1, 1, 1
 type = open
 data = {
 0, 0, 0
 }
 */
int cPolygon::Load(char **str, uInt32 &size)
{
   Point3D p1, p2, p3;
   char  ts[32], c;
   
   //
   if((str == NULL) || (size < 1)) return 1; // error
   mVertices.clear();
   
   // remove comments
   RemoveStrComments(str, size);
   
   // read color
   sscanf(*str, "color = %f, %f, %f, %f\n", &(mColor.r), &(mColor.g), &(mColor.b), &(mColor.a));
   MoveToNextLine(str, size);

   sscanf(*str, "type = %s\n", ts);
   MoveToNextLine(str, size);
   if(strcmp(ts, "open") == 0)
   {
      mType = Polygon_Open;
   } else {
      mType = Polygon_Closed;
   }
   
   // read first point
   //sscanf(*str, "data = {\n");
   MoveToNextLine(str, size);
   sscanf(*str, "%f, %f, %f\n", &(p1.x), &(p1.y), &(p1.z));
   MoveToNextLine(str, size);
   
   while(size > 0)
   {
      // add point
      mVertices.push_back(p1);
      sscanf(*str, "%f, %f, %f", &(p3.x), &(p3.y), &(p3.z));
      MoveToNextLine(str, size);

      // calc midpoint
      p2.x = (p1.x + p3.x)*0.5;
      p2.y = (p1.y + p3.y)*0.5;
      p2.z = (p1.z + p3.z)*0.5;
      
      // add midpoint
      mVertices.push_back(p2);
      p1 = p3;
      
      c = (*str)[0];
      if(c == '}') break;
   }
   // remove last '}'
   MoveToNextLine(str, size);
   
   // add last point
   mVertices.push_back(p1);
   
   if(mType == Polygon_Closed)
   {
      // add midpoint and dup of last point
      Point3D lp, fp, mp;
      
      fp = mVertices[0];
      lp = mVertices[mVertices.size()-1];
      
      mp.x = (fp.x + lp.x)*0.5;
      mp.y = (fp.y + lp.y)*0.5;
      mp.z = (fp.z + lp.z)*0.5;
      
      mVertices.push_back(mp);
      mVertices.push_back(fp);
   }
   
   // get width, height and depth
   uInt32 i;
   float minX, minY, minZ, maxX, maxY, maxZ;
   minX = mVertices[0].x;
   minY = mVertices[0].y;
   minZ = mVertices[0].z;
   maxX = minX; maxY = minY; maxZ = minZ;
   for(i = 0; i < mVertices.size(); ++i)
   {
      if(mVertices[i].x < minX) minX = mVertices[i].x;
      if(mVertices[i].x > maxX) maxX = mVertices[i].x;
      if(mVertices[i].y < minY) minY = mVertices[i].y;
      if(mVertices[i].y > maxY) maxY = mVertices[i].y;
      if(mVertices[i].z < minZ) minZ = mVertices[i].z;
      if(mVertices[i].z > maxZ) maxZ = mVertices[i].z;
   }
   mWidth  = maxX - minX;
   mHeight = maxY - minY;
   mDepth  = maxZ - minZ;
   //

   return 0;
}

// load file and dump to string, pass string to string load
int cPolygon::Load(const char *filename)
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
