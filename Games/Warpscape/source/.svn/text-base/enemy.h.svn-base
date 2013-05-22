/****************************************
 filename:    enemy.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/15
 description: enemy interface
 ****************************************/
#ifndef _ENEMY_
#define _ENEMY_

enum EnemyState{ Enemy_Alive, Enemy_Dying, Enemy_Dead };

class cEnemy : public cAnimModel
{
public:
   vector< vector<Point3D> > * mPath;
   PolygonType                 mPathType;
   
   EnemyState        mState;
   bool              mHitable;
   
   cEnemy() { mState = Enemy_Alive; mHitable = true; }
   
   cEnemy(vector< vector<Point3D> > *p, PolygonType pt)
   {
      mPath = p;
      mPathType = pt;
      mState = Enemy_Alive;
   }
   
   virtual void Draw()   { cAnimModel::Draw(); }
   virtual void Update() { cAnimModel::Update(); }

   virtual void Killed() { mState = Enemy_Dying; }
   virtual bool isDead() { return (mState == Enemy_Dead); }
   
   virtual Point3D GetCenterPos()
   {
      Point3D p;
      if(mCurrentGfx != NULL)
      {
         p.x = mCurrentPos.x + 0.5*GetWidth();
         p.y = mCurrentPos.y + 0.5*GetHeight();
         p.z = mCurrentPos.z + 0.5*GetDepth();
      }
      return p;
   }

   virtual uInt32 GetCurrentTrack(){ return mCurrentTrack; }

protected:
   uInt32 mCurrentTrack;
};

#endif // _ENEMY_
