//////////////////////////////////////////////////////////////////////////////
// Program Name:  level.h
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/5/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _CLEVEL_
#define _CLEVEL_

#include "slist.h"
class cLevelSelector;   // so the compiler dosen't have a cow

class cLevel
{
public:
   cLevel();
   ~cLevel();

   void SetParent(cLevelSelector *p);
   void SelectLevel(unsigned char num);
   void NextLevel();
   void PrevLevel();
   void FirstLevel();
   void LastLevel();
   
   //////////////////////////////////////////////
   // Init
   //////////////////////////////////////////////
   virtual void Init();

   void FreeGfx();
   virtual void SetBkgImg(const char *file);
   virtual void SetMusic(const char *file);
   virtual int  AddSound(const char *file);

   virtual void DeleteCritterType(CRuntimeClass *pruntimeclass);
   virtual int GetCritterCount(CRuntimeClass *pruntimeclass);

   //////////////////////////////////////////////
   // Loop
   //////////////////////////////////////////////
   virtual void Loop();
   virtual void Exit();
   virtual void KeyPressed(int key, int flag);
   virtual void KeyUp(int key, int flag);
   virtual void MouseClick(int button, int state, float x, float y);
   virtual void MouseMoved(float x, float y);

   virtual void PlaySnd(int num);
   virtual void PlayMusic();
   virtual void StopMusic();

   void StartTimer();
   void UpdateTimer();
 
protected:
   cLevelSelector *parent;
   DWORD time_start;
   DWORD time_diff;

   char *bkgimg_file;
   char *music_file;
   List<char *> snd_list;
};


#endif