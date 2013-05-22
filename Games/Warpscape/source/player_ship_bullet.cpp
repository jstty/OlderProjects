/****************************************
 filename:    player_ship_bullet.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/15
 description: 
 ****************************************/
#include "global.h"

cPlayerShipBullet::cPlayerShipBullet(uInt32 track, vector< vector<Point3D> > *p)
{
   mMoveRate = 0.350;
   
   mCurrentZ = 0.0;
   mCurrentTrack = track << 1;
   mPath = p;
   
   mColor.r = (167.0/255.0);
   mColor.g = (230.0/255.0);
   mColor.b = (255.0/255.0);
   mColor.a = 0.5;

   Point3D pt;
   pt.x = 0;
   pt.y = 0;
   pt.z = 0;
   mPoints.push_back(pt);
   mPoints.push_back(pt);
   mPoints.push_back(pt);
   mPoints.push_back(pt);
}

float cPlayerShipBullet::GetZ()
{
   return mCurrentZ;
}

void cPlayerShipBullet::Draw()
{
   game->mGraphics->DrawSolid(mPoints, mColor);

   /*
   for(i = 0; i < mPath->size()-1; ++i)
   {
      if( ((*mPath)[i  ][mCurrentTrack].z >= mCurrentZ) &&
          ((*mPath)[i+1][mCurrentTrack].z <  mCurrentZ)
      )
      {
         v.push_back( (*mPath)[i  ][mCurrentTrack  ] );
         v.push_back( (*mPath)[i  ][mCurrentTrack+1] );
         v.push_back( (*mPath)[i+1][mCurrentTrack+1] );
         v.push_back( (*mPath)[i+1][mCurrentTrack  ] );

         game->mGraphics->DrawSolid(v, mColor);       
         break; // done
      }
   }
   */
   
   //cAnimModel::Draw();
}

void cPlayerShipBullet::Update()
{
   mCurrentZ -= mMoveRate;
   //cAnimModel::Update();

   for(i = 0; i < mPath->size()-1; ++i)
   {
      if( ((*mPath)[i  ][mCurrentTrack].z >= mCurrentZ) &&
          ((*mPath)[i+1][mCurrentTrack].z <  mCurrentZ)
      )
      {
         mPoints[0] = (*mPath)[i  ][mCurrentTrack  ];
         mPoints[1] = (*mPath)[i  ][mCurrentTrack+2];
         mPoints[2] = (*mPath)[i+1][mCurrentTrack+2];
         mPoints[3] = (*mPath)[i+1][mCurrentTrack  ];
      }
   }
}

PointBox3D cPlayerShipBullet::GetHitRegion()
{
   PointBox3D b;
   b.s[0] = mPoints[0];
   b.s[1] = mPoints[1];
   b.s[2] = mPoints[2];
   b.s[3] = mPoints[3];
   return b;
}