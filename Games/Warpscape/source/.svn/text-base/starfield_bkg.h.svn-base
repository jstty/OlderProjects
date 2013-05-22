/****************************************
 filename:    starfield_bkg.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/08
 description: starfield background
 ****************************************/
#ifndef _STARFIELD_BACKGROUND_
#define _STARFIELD_BACKGROUND_

class cStarfield : public cBackground
{
public:
   cStarfield();
   ~cStarfield();
   
   virtual void Draw();
   virtual void Update();

protected:
   uInt16   mNumStars;
   Line3D  *mStars;
   Color4D  mStarColor;
   Point3D  mNormal;
   float    mMoveStep;
   float    mBlurLength;
   
   float   GetNormal(uInt16 i);
   
   Point3D RandomPoint();
};

#endif // _STARFIELD_BACKGROUND_
