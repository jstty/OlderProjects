/* //////////////////////////////////////////////////////////////////////
 Program Name:  cImage.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Basic Image Class Source File
   Does not have multi-animations, see cSprite
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cImage::cImage() : cGfxObj()
{
   m_type = OBJTYPE_IMAGE;
   m_anim = new cAnim();
}

cImage::cImage(const char *name) : cGfxObj()
{
   strcpy(m_name, name);
   m_anim = new cAnim();
}


cImage::cImage(const cImage &src) : cGfxObj(src)
{
   m_anim = new cAnim(*(src.m_anim));
}


cImage::~cImage()
{
   DELETE(m_anim);
}

// load animation file
int cImage::Load(const char *filename)
{
   int e;
   e = m_anim->Load(filename);
   if(e) return e;

   m_cframe = m_anim->GetCurrent();
   if(m_cframe == NULL) return 1; // error

   return e;
}


// load single image(bitmap) file
int cImage::LoadImage(const char *filename)
{
   int e;
   e = m_anim->AddFrameImage(filename);
   if(e) return e;

   m_cframe = m_anim->GetCurrent();
   if(m_cframe == NULL) return 1; // error

   return e;
}


// step animation
void cImage::Step()
{
   m_cframe = m_anim->Step();
   if(m_cframe == NULL) return; // error

   xpos += m_cframe->mvx;
   ypos += m_cframe->mvy;
   zpos += m_cframe->mvz;

   xhot = m_cframe->ofx;
   yhot = m_cframe->ofy;

   scope = m_cframe->scp;
}


cAnim *cImage::Anim()
{
   return m_anim;
}


void cImage::AnimSelect(const char *name, uInt16 frame_num)
{
   m_anim->Select(name, frame_num);
   m_cframe = m_anim->GetCurrent();
   if(m_cframe == NULL) return;

   xhot = m_cframe->ofx;
   yhot = m_cframe->ofy;

   scope = m_cframe->scp;
}


void cImage::AnimSelect(uInt16 seq_num, uInt16 frame_num)
{
   m_anim->Select(seq_num, frame_num);
   m_cframe = m_anim->GetCurrent();
   if(m_cframe == NULL) return;

   xhot = m_cframe->ofx;
   yhot = m_cframe->ofy;

   scope = m_cframe->scp;
}


void cImage::AnimSetFrame(uInt16 frame_num)
{
   m_anim->SetFrame(frame_num);
   m_cframe = m_anim->GetCurrent();
}

