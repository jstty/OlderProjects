/****************************************
 filename:    model.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: 
 ****************************************/
#ifndef _MODEL_
#define _MODEL_

class cModel
{
protected:
   vector<cPolygon *> mPolygons;
   
public:
   // for animation, should be moved to struct in the animation, but no time
   float              mDelay;
   float              mWidth, mHeight, mDepth;
   
   cModel();
   ~cModel();
   
   void Clear();
   
   int Load(const char *filename);
   int Load(char **str, uInt32 &size);

   void Draw(bool movex = false, bool movey = false, float offsetx = 0.00, float offsety = 0.00);
};

#endif // _MODEL_
