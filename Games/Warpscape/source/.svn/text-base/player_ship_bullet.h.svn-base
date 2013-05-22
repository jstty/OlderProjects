/****************************************
 filename:    player_ship_bullet.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/15
 description: 
 ****************************************/
#ifndef _PLAYER_SHIP_BULLET_
#define _PLAYER_SHIP_BULLET_

class cPlayerShipBullet : public cAnimModel
{
public:
   float  mMoveRate;
   vector< vector<Point3D> > *mPath;
   vector<Point3D>            mPoints;
   
   cPlayerShipBullet(uInt32 track, vector< vector<Point3D> > *p);
   
   virtual void Draw();
   virtual void Update();

   PointBox3D GetHitRegion();
   
   float GetZ();

protected:
   uInt32   i;
   Color4D  mColor;
   
   float  mCurrentZ;
   uInt32 mCurrentTrack;     // pos in vector list
};

#endif // _PLAYER_SHIP_
