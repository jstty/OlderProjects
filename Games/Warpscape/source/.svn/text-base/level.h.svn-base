/****************************************
 filename:    level.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: level interface
 ****************************************/
#ifndef _LEVEL_
#define _LEVEL_

enum LevelStateType { LevelState_Enter, LevelState_Running, LevelState_Paused, LevelState_Exit };

struct LevelInput
{
   bool  Up;
   bool  Down;
   bool  Left;
   bool  Right;
   bool  Action1;
   bool  Action2;
   uInt8 Key;
   int   SKey;
   
   int  MouseX;
   int  MouseY;
   int  MouseButton;
};

class cLevel
{
public:
   cLevel() { }
   ~cLevel() { }
   
   virtual uInt32 Enter(uInt32 level_num) { mLevelNum = level_num; return mLevelNum; }
   virtual uInt32 Exit() { return (++mLevelNum); }
   virtual void   Draw() { }
   virtual void   Update() { }
   virtual void   Input(LevelInput input) { }
   virtual int    LoadSettings(const char *filename) { return 0; }
   
   virtual uInt32 GetNextLevelNum() { return (mLevelNum+1); }
   virtual bool   isLevelOver()     { return (mLevelState == LevelState_Exit); }

protected:
   sInt32 mLevelNum;
   LevelStateType mLevelState;
};

#endif // _LEVEL_
