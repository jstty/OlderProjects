/****************************************
 filename:    warp_path.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: 
 ****************************************/
#include "global.h"

cWarpPath::cWarpPath()
{
   // settings
   mNumPolys = 25;
   mStepSize = 1.5;
   mMoveRate = 0.100;

   mAnimStepSize = 5;
   mAnimStart = mAnimStepSize-1;
   mAnimColor.r = 1.0;
   mAnimColor.g = 0.0;
   mAnimColor.b = 0.0;
   mAnimColor.a = 0.4;

   mAnimHighlightColor.r = 1.0;
   mAnimHighlightColor.g = 0.0;
   mAnimHighlightColor.b = 0.0;
   mAnimHighlightColor.a = 1.0;

   mAnimTimer.SetExpirePerSec(0.11);
   mAnimTimer.Start();

   mSelectionColor.r = 1.0;
   mSelectionColor.g = 1.0;
   mSelectionColor.b = 0.0;
   mSelectionColor.a = 0.6;
	
   mPickNewPointTimer.SetExpirePerSec(1);
   mMoveTimer.SetExpirePerSec(0.09);
   mPickNewPointTimer.Start();
   mMoveTimer.Start();
   
   mMoveTowardsMin = -2.0;
   mMoveTowardsMax =  2.0;
   mMoveTowardsStep = 0.12;
   
   mDegradeCutoff = 5;
   
   if(mDegradeCutoff > mNumPolys-1) mDegradeCutoff = mNumPolys-1;
   mPathState = WarpPath_Moving;
}

void cWarpPath::Draw()
{
   for(i = 0; i < mShape.size(); ++i)
   {
      glPushMatrix();
         Point3D p;
         p.x = mPath[i][0].x - mShape[i]->mVertices[0].x;
         p.y = mPath[i][0].y - mShape[i]->mVertices[0].y;
         glTranslatef(p.x, p.y, 0.0);

         mShape[i]->Draw();
      glPopMatrix();

      // draw lines connecting the polys
      if(i != (mShape.size() - 1))
      {
         // build list of lines
         for(j = 0, k = 0; j < mPath[i].size(); ++j)
         {
            if(j % 2 == 0)
            {
               mConnectingLines[k].p1 = mPath[i  ][j];
               mConnectingLines[k].p2 = mPath[i+1][j];
               mConnectingLines[k].c1 = mAnimColor;
               mConnectingLines[k].c2 = mAnimColor;
               k++;
            }
         }
         // draw lines
         game->mGraphics->Draw(mConnectingLines, mNumConnectingLines);
      }
   }
   
   // draw selected track
   if(mPath.size() > 0)
   {
      if( ((sInt32)mPath[0].size() > mCurrentSelectedTrack) &&
       (mCurrentSelectedTrack > -1)
       )
      {
         game->mGraphics->Draw(mSelectionPath, mSelectionColor);
      }
   }
}

void cWarpPath::Update()
{   
   // Step Animation
   // sync the sharpes to the path
   mAnimTimer.Update();
   if(mAnimTimer.HasExpired())
   {
      mAnimTimer.Start();
      
      // set color back to darker color
      for(i = 0; i < mShape.size(); ++i)
      {
         mShape[i]->mColor = mAnimColor;
      }
      
      mAnimStart--;
      
      if(mAnimStart < 0)
         mAnimStart = mAnimStepSize-1;
      
      for(i = mAnimStart; i < mShape.size(); i += mAnimStepSize)
      {
         mShape[i]->mColor = mAnimHighlightColor;
      }   
   }
   
   // pick random point around first point in last path
   mPickNewPointTimer.Update();
   if(mPickNewPointTimer.HasExpired())
   {
      mPickNewPointTimer.Start();
      
      if(mPathState == WarpPath_Reset)
      {
         mMoveTowardsPoint = mOriginalPathPoint;
      } else {
         mMoveTowardsPoint.x = mOriginalPathPoint.x + Random(mMoveTowardsMin, mMoveTowardsMax);
         mMoveTowardsPoint.y = mOriginalPathPoint.y + Random(mMoveTowardsMin, mMoveTowardsMax);
      }
   }
   
   mMoveTimer.Update();
   if(mMoveTimer.HasExpired())
   {
      mMoveTimer.Start();
      
      // ripple points up, expect the first and last
      for(j = 1; j < (mNumPolys-1); ++j)
      {
         for(i = 0; i < mPath[j].size(); ++i)
         {
            mPath[j][i].x = mPath[j+1][i].x;
            mPath[j][i].y = mPath[j+1][i].y;
         }
      }
      
      // ripple points up, expect the first and last
      for(j = 1; j < (mDegradeCutoff); ++j)
      {
         for(i = 0; i < mPath[j].size(); ++i)
         {
            mPath[j][i].x = mShape[j]->mVertices[i].x + (mPath[j][i].x - mShape[j]->mVertices[i].x)*j/mDegradeCutoff;
            mPath[j][i].y = mShape[j]->mVertices[i].y + (mPath[j][i].y - mShape[j]->mVertices[i].y)*j/mDegradeCutoff;
         }
      }
      
      mMoveTowardsDiff.x = 0;
      mMoveTowardsDiff.y = 0;
      if( (mMoveTowardsPoint.x > ((*mLastPath)[0].x - mMoveTowardsStep)) &&
          (mMoveTowardsPoint.x > ((*mLastPath)[0].x + mMoveTowardsStep)) )
           mMoveTowardsDiff.x =  mMoveTowardsStep;
      if( (mMoveTowardsPoint.x < ((*mLastPath)[0].x - mMoveTowardsStep)) &&
          (mMoveTowardsPoint.x < ((*mLastPath)[0].x + mMoveTowardsStep)) )
           mMoveTowardsDiff.x = -mMoveTowardsStep;
      
      if( (mMoveTowardsPoint.y > ((*mLastPath)[0].y - mMoveTowardsStep)) &&
          (mMoveTowardsPoint.y > ((*mLastPath)[0].y + mMoveTowardsStep)) )
           mMoveTowardsDiff.y =  mMoveTowardsStep;
      if( (mMoveTowardsPoint.y < ((*mLastPath)[0].y - mMoveTowardsStep)) &&
          (mMoveTowardsPoint.y < ((*mLastPath)[0].y + mMoveTowardsStep)) )
           mMoveTowardsDiff.y = -mMoveTowardsStep;
      
      // move last path
      for(i = 0; i < mLastPath->size(); ++i)
      {
         (*mLastPath)[i].x += mMoveTowardsDiff.x;
         (*mLastPath)[i].y += mMoveTowardsDiff.y;
      }
      
      // finished resetting
      if( (mPathState == WarpPath_Reset) && 
          (mMoveTowardsDiff.x == 0) &&
          (mMoveTowardsDiff.y == 0) )
      {
         mPathState = WarpPath_ResetDone;
      }
      
      
   }
	
   // build selection track, of player
   mSelectionPath.clear();
   if(mCurrentSelectedTrack > -1)
   {
      Point3D p;
      p = mPath[0][mCurrentSelectedTrack+2];
      //p.x += 0.001; p.y += 0.001;
      mSelectionPath.push_back(p);
      
      for(i = 1; i < mPath.size(); ++i)
      {
         p = mPath[i][mCurrentSelectedTrack+2];
         //p.x += 0.001; p.y += 0.001;
         mSelectionPath.push_back(p);
      }
      
      for(i = mPath.size()-1; i > 0; --i)
      { 
         p = mPath[i][mCurrentSelectedTrack];
         //p.x += 0.001; p.y += 0.001;
         mSelectionPath.push_back(p);
      }
      
      // back to start
      p = mPath[0][mCurrentSelectedTrack];
      //p.x += 0.001; p.y += 0.001;
      mSelectionPath.push_back(p);
   }
}


cWarpPath::~cWarpPath()
{
   for(i = 0; i < mNumPolys; ++i)
   {
      if(mShape[i] != NULL) delete (mShape[i]);
   }
}

void cWarpPath::SetCurrentSelectedTrack(sInt32 track)
{
   mCurrentSelectedTrack = track << 1;
}

// get Max Z from path
float cWarpPath::GetMinZ()
{
   float min, z;
   
   min = 0;
   for(i = 0; i < mNumPolys; ++i)
   {
      z = mPath[i][0].z;
      if(z < min) min = z;
   }
   
   return min;
}


float cWarpPath::GetWidth()
{
   if(mShape.size() > 0)
      return mShape[0]->mWidth;
   else
      return 0;
}

float cWarpPath::GetHeight()
{
   if(mShape.size() > 0)
      return mShape[0]->mHeight;
   else
      return 0;
}

vector<Point3D> cWarpPath::GetPoly()
{
   vector<Point3D> p;
   vector<Point3D> *v;
   
   v = &(mShape[0]->mVertices);
   size = v->size();
   for(i = 0; i < size; ++i)
   {
      p.push_back( (*v)[i] );
   }
   
   return p;
}


PolygonType cWarpPath::GetPolyType()
{
   if(mShape.size() > 0)
      return mShape[0]->mType;
   else
      return Polygon_Open;
}

bool cWarpPath::ResetDone()
{
   //return true;
   return (mPathState == WarpPath_ResetDone);
}


void cWarpPath::ResetBackToStart()
{
   mPathState = WarpPath_Reset;
   mMoveTowardsPoint = mOriginalPathPoint;
}


int cWarpPath::Load(const char *filename)
{
   float z = 0;
   for(i = 0; i < mNumPolys; ++i)
   {
      mShape.push_back(new cPolygon());

      if( mShape[i]->Load(filename) ) return 1; // error

      mShape[i]->Translate(0, 0, z);
      z -= mStepSize;

      // set color of shape
      mShape[i]->mColor = mAnimHighlightColor;
   }

   // copy points list
   // center points don't move in Z, only along X,Y
   for(j = 0; j < mNumPolys; ++j)
   {
      size = mShape[j]->mVertices.size();
      mPath.push_back( vector<Point3D>(size) );
      
      for(i = 0; i < size; ++i)
      {
         mPath[j][i] = mShape[j]->mVertices[i];
      }
   }

   mLastPath = &(mPath[mNumPolys-1]);
   mMoveTowardsPoint.x = (*mLastPath)[0].x + Random(mMoveTowardsMin, mMoveTowardsMax);
   mMoveTowardsPoint.y = (*mLastPath)[0].y + Random(mMoveTowardsMin, mMoveTowardsMax);
   
   mOriginalPathPoint = (*mLastPath)[0];
   
   // allocate connecting lines
   mNumConnectingLines = (uInt32)((float)mShape[0]->mVertices.size()*0.5 + 0.5); // div by 2
   mConnectingLines = new Line3D[mNumConnectingLines];
   
   for(j = 0; j < mNumConnectingLines; ++j)
   {
      mConnectingLines[j].normal.x = 0;
      mConnectingLines[j].normal.y = 0;
      mConnectingLines[j].normal.z = -1;
   }
   
   return 0;
}

