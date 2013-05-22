//////////////////////////////////////////////////////////////////////////////
// Program Name:  level.cpp
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/5/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "../pop/GraphicsOpenGL.h"
#include "level.h"
#include "tankwars2005.h"
extern cTankWars2005 *tws2005;
extern cGraphicsOpenGL *open_gfx;

cLevel::cLevel()
{
   music_file = NULL;
   bkgimg_file = NULL;
   parent = NULL;
}

cLevel::~cLevel()
{ 
   if(!music_file == NULL)   delete music_file;
   if(!bkgimg_file == NULL)   delete bkgimg_file;
}

void cLevel::SetParent(cLevelSelector *p)
{
   parent = p;
}

void cLevel::StartTimer()
{
   time_start = GetTickCount();
}

void cLevel::UpdateTimer()
{
   time_diff = GetTickCount() - time_start;
}

void cLevel::SelectLevel(unsigned char num)
{
   if( parent != NULL ) parent->SelectLevel(num);
}

void cLevel::NextLevel()
{
   if( parent != NULL ) parent->NextLevel();
}

void cLevel::PrevLevel()
{
   if( parent != NULL ) parent->PrevLevel();
}

void cLevel::FirstLevel()
{
   if( parent != NULL ) parent->FirstLevel();
}

void cLevel::LastLevel()
{
   if( parent != NULL ) parent->LastLevel();
}
   
//////////////////////////////////////////////
// Init
//////////////////////////////////////////////
void cLevel::Init()
{ }

void cLevel::SetBkgImg(const char *file)
{
   if(!bkgimg_file == NULL)   delete bkgimg_file;
   int len = strlen(file) + 1;
   bkgimg_file = new char[len];
   strncpy(bkgimg_file, file, len);

   tws2005->setBackgroundBitmap((int)(bkgimg_file));
}

void cLevel::FreeGfx()
{
   if(open_gfx != NULL)
      open_gfx->free();
}

void cLevel::SetMusic(const char *file)
{
   if(!music_file == NULL)   delete music_file;
   int len = strlen(file) + 1;
   music_file = new char[len];
   strncpy(music_file, file, len);
}

int cLevel::AddSound(const char *file)
{
   int len = strlen(file) + 1;
   char *buffer = new char[len];

   snd_list.insert(snd_list.size(), buffer);
   return snd_list.size() - 1;
}


void cLevel::DeleteCritterType(CRuntimeClass *pruntimeclass)
{
   tws2005->GetBiota()->purgeCritters(pruntimeclass);
}

int cLevel::GetCritterCount(CRuntimeClass *pruntimeclass)
{
   return tws2005->GetBiota()->count(pruntimeclass);
}


//////////////////////////////////////////////
// Loop
//////////////////////////////////////////////
void cLevel::Loop()
{ }

void cLevel::Exit()
{ }

void cLevel::KeyPressed(int key, int flag)
{ }

void cLevel::KeyUp(int key, int flag)
{ }

void cLevel::MouseClick(int button, int state, float x, float y)
{ }

void cLevel::MouseMoved(float x, float y)
{ }

void cLevel::PlaySnd(int num)
{
   tws2005->pop_app->playSound( snd_list.retrieve(num) );
}

void cLevel::PlayMusic()
{
   if(music_file != NULL)
      tws2005->pop_app->playMusic(music_file);
}

void cLevel::StopMusic()
{
   tws2005->pop_app->stopMusic();
}
