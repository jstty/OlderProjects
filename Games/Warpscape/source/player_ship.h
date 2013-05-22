/****************************************
 filename:    player_ship.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/15
 description: 
 ****************************************/
#ifndef _PLAYER_SHIP_
#define _PLAYER_SHIP_

enum PlayerShipState{ PlayerShip_Alive, PlayerShip_Dying, PlayerShip_Dead };

class cPlayerShip : public cAnimModel
{
public:
   PlayerShipState   mState;
   bool              mHitable;
   
   cPlayerShip(vector<Point3D> p, PolygonType pt, uInt32 startTrack);
   
   virtual void Draw();
   virtual void Update();
   
   void MoveLeft();
   void MoveRight();
	void CalcRotate();
   uInt32  GetCurrentTrack();
   Point3D GetCenterPos();
   
protected:
   vector<Point3D> mPath;
   PolygonType     mPathType; 
   
   float				 mAngle;
   uInt32          mCurrentTrack; // pos in vector list

};

#endif // _PLAYER_SHIP_
