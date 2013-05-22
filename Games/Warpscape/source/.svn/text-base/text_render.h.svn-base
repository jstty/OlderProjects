/****************************************
 filename:    text_render.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: 
 ****************************************/
#ifndef _TEXT_RENDER_
#define _TEXT_RENDER_

class cTextRender
{
protected:
   float mLineCharWidth, mLineSpacing;
   char  mCharList[256];
   vector<cPolygon *> mFontList; // mFontList[ mCharList[i] ]->Draw()
   Color4D mColor;

public:
   cTextRender();
   int  Load(const char *filename);

   void SetColor(float r, float g, float b, float a = 1.0);

   void Draw2D(float x, float y, const char *format, ...);
   void DrawLines(float x, float y, float scale, const char *format, ...);
};

#endif // _TEXT_RENDER_
