/****************************************
 filename:    warp_path.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: 
 ****************************************/
#ifndef _WARP_PATH_
#define _WARP_PATH_

enum WarpPathState { WarpPath_Moving, WarpPath_Reset, WarpPath_ResetDone };

class cWarpPath
{
protected:
   uInt16             i, j, k, size, mNumPolys;
   float              mStepSize; 
   float              mMoveRate;
   cPolygon *         mTmpPoly;
   
   cTimer             mAnimTimer;
   uInt32             mAnimStepSize;
   sInt32             mAnimStart;
   Color4D            mAnimColor;
   Color4D            mAnimHighlightColor;

   sInt32             mCurrentSelectedTrack;
   Color4D            mSelectionColor;
   vector<Point3D>    mSelectionPath;
	
   float              mMoveTowardsStep;
   float              mMoveTowardsMin;
   float              mMoveTowardsMax;
   cTimer             mMoveTimer;
   cTimer             mPickNewPointTimer;
   Point3D            mMoveTowardsPoint;
   Point3D            mMoveTowardsDiff;
   vector<Point3D>   *mLastPath;
   
   Point3D            mOriginalPathPoint;
   WarpPathState      mPathState;
   uInt32             mDegradeCutoff;
   
   // moves along Z in update, also linked to mPath
   vector<cPolygon *> mShape;
   
public:
   // x is polynumber
   // [x][0], each point on the poly, no centers
   // only moves x, y. NO z change
   vector< vector<Point3D> > mPath;
   Line3D                   *mConnectingLines;
   uInt32                    mNumConnectingLines;

   cWarpPath();
   ~cWarpPath();
   
   int Load(const char *filename);
   
   vector<Point3D> GetPoly();
   float           GetMinZ();
   float           GetWidth();
   float           GetHeight();
   PolygonType     GetPolyType();
   
   void            SetCurrentSelectedTrack(sInt32 track);
   
   void ResetBackToStart();
   bool ResetDone();
   
   void Draw();
   void Update();
};

#endif // _WARP_PATH_
