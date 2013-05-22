/****************************************
 filename:    polygon.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: 
 ****************************************/
#ifndef _POLYGON_
#define _POLYGON_

enum PolygonType { Polygon_Open, Polygon_Closed };

class cPolygon
{
public:
   PolygonType     mType;
   Point3D         mNormal;
   Color4D         mColor;
   vector<Point3D> mVertices;
   float           mWidth, mHeight, mDepth;
   
   //
   cPolygon();
   
   int   Load(const char *filename);
   int   Load(char **str, uInt32 &size);

    void Translate(float x, float y, float z);
	void SwapTranslate(cPolygon *old);

   float GetFirstZ();
	
	vector<Point3D> GetVertices();
   
   void Draw();
};

#endif // _POLYGON_