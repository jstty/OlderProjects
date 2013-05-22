/****************************************
 filename:    game_engine.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/07
 description: 
 ****************************************/
#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

#define GAME_FRAME_TIME 0.03
#define GLUT_KEY_ESC 27

void display();
void reshape (int w, int h);
void idle();
void key_down(unsigned char key, int x, int y);
void key_special_down(int key, int x, int y);
void mouse_click(int button, int state, int x, int y);
void mouse_motion(int x, int y);
void mouse_passive(int x, int y);

enum GameState { Game_Loading, Game_DoneLoading };

class GameEngine
{
public:
   uInt16          mWidth, mHeight;
   cTextRender    *mText;
   cSoundBank     *mSound;
   cGraphics      *mGraphics;
   
   GameEngine();
   ~GameEngine();
   
   int Init(int argc, char* argv[]);
   void Run();
   
   // 
   void Display();
   void Idle();
   void Resize(int w, int h);
   void KeyDown(unsigned char key, int x, int y);
   void KeySpecialDown(int key, int x, int y);
   void MouseClick(int button, int state, int x, int y);
   void MouseMotion(int x, int y);
   void MousePassive(int x, int y);
   
   void ChangePerspective(float degree = 60);
   
   //
   void DrawLoading();
   
protected:
   GameState mGameState;
   cTimer    mGameTimer, mLoopTimer;
   float     mGameSpeed;
   string    mMessage;
   char      mMessageBuffer[256];
   
   bool   mShowFPS;
   bool   mGameMode;
   uInt16 mOldWidth, mOldHeight;
   
   float  mFPS;
   uInt32 mFrameCount;
   
   uInt32           mNextLevelNum, mLevelNum;
   cLevel          *mCurrentLevel;
   vector<cLevel *> mLevels;
   LevelInput       mInput;
   
   void GoFullScreen();
   void GoWindowMode();
};

#endif // _GAME_ENGINE_
