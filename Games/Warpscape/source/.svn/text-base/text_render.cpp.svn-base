/****************************************
 filename:    text_render.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: 
 ****************************************/
#include "global.h"

cTextRender::cTextRender()
{
   mLineCharWidth = 1.0f;
   mLineSpacing   = 0.5f;

   mColor.r = 1.0;
   mColor.g = 0.0;
   mColor.b = 0.0;
   mColor.a = 1.0;
}

void cTextRender::SetColor(float r, float g, float b, float a)
{
   mColor.r = r;
   mColor.g = g;
   mColor.b = b;
   mColor.a = a;
}

void cTextRender::Draw2D(float x, float y, const char *format, ...)
{
   va_list va;
   uInt32 i, length;
   char   str[256];
   
   va_start(va, format);
   vsprintf(str, format, va);
   va_end(va);
   
   // turn off lighting
   glDisable(GL_LIGHTING);
   
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();   // push current model view on stack
   glLoadIdentity(); // reset model view
   
   glMatrixMode(GL_PROJECTION);
   glPushMatrix();   // push current projection on stack
   glLoadIdentity(); // reset projection
   // switch to 2D
   gluOrtho2D(0, game->mWidth, 0, game->mHeight);

   glMatrixMode(GL_MODELVIEW);
   
   glColor3f(mColor.r, mColor.g, mColor.b);
   glRasterPos2f((int)(game->mWidth*x), (int)(game->mHeight*y));
   
   // draw letter
   length = strlen(str);
   for(i = 0; i < length; ++i)
   {
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);
   }
      
   glMatrixMode(GL_PROJECTION);
   glPopMatrix(); // pop current projection off stack
   
   glMatrixMode(GL_MODELVIEW);
   glPopMatrix(); // pop current model view off stack

   glEnable(GL_LIGHTING);
}


void cTextRender::DrawLines(float x, float y, float scale, const char *format, ...)
{
   va_list va;
   uInt32  i, length, index;
   char    str[256];
   //
	GLdouble mv[16];
	GLdouble pro[16];
   GLint    vp[4];
   GLdouble px, py, pz;

   //
   va_start(va, format);
   vsprintf(str, format, va);
   va_end(va);

   //
   glGetDoublev(GL_MODELVIEW_MATRIX,  mv);
   glGetDoublev(GL_PROJECTION_MATRIX, pro);
   glGetIntegerv(GL_VIEWPORT,         vp);

   x = x*game->mWidth;
   y = y*game->mHeight;
   gluUnProject(
      x, y, 0.0,//0.809, 
      mv, pro, vp,
      &px, &py, &pz);

   //
   glPushMatrix();

   // translate
   glTranslatef(px, py, -1.002);  // -1.002; 2 because it's hehind the pause background
   x = 0;
   y = 0;

   // scale
   glScalef(scale, scale, 0.0f);

   // draw letter
   length = strlen(str);
   for(i = 0; i < length; ++i)
   { 
      str[i] = toupper(str[i]);
      if(str[i] != ' ')
      {
         index = mCharList[ str[i] ];
         if(mFontList[ index ] != NULL)
         {
            mFontList[ index ]->mColor = mColor;
            mFontList[ index ]->Draw();
         } else {
            mFontList[0]->mColor = mColor;
            mFontList[0]->Draw();
         }
         
         glTranslatef(mLineCharWidth + mLineSpacing, 0.0f, 0.0f);
      } else {
         glTranslatef(mLineCharWidth, 0.0f, 0.0f);
      }
   }

   //
   glPopMatrix();
}


int cTextRender::Load(const char *filename)
{
   FILE     *fp;
   cPolygon *poly;
   char tstr[256], *ostr, *fstr;
   uInt32 i, len, fsize;
   size_t result;

   fp = fopen(filename, "r");
   if(fp == NULL) return 1;

   memset(mCharList, 0, sizeof(char)*256);

   // get filesize
   fseek(fp, 0, SEEK_END);
   fsize = ftell(fp);
   rewind(fp);
   
   // read all file data to str
   ostr = new char[fsize+1];
   result = fread(ostr, 1, fsize, fp);
   if(result != fsize)
   {
      // error reading all the file
      delete [] ostr;
      fclose(fp);
      return 2;
   }

   // fstr is the temp point, ostr used to delete after scan
   fstr = ostr;

   //
   sscanf(fstr, "chars = %s\n", tstr);
   len    = strlen(tstr);
   MoveToNextLine(&fstr, fsize);

   for(i = 0; i < len; ++i)
   {
      mCharList[tstr[i]] = i;

      poly = new cPolygon();
      mFontList.push_back(poly);
      poly->Load(&fstr, fsize);
   }

   delete [] ostr;
   fclose(fp);
   return 0;
}


