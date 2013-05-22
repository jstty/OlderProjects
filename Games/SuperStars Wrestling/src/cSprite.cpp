/* //////////////////////////////////////////////////////////////////////
 Program Name:  cSprite.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Sprite Class Source File
   Sprite can only collide with objects

   Not for use with a single image, or non colliable objects. use cImage
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


cColInfoNode::cColInfoNode()
{
}


cColInfoNode::cColInfoNode(const sColInfo & ci)
{
   colinfo = ci;
}


cColInfoNode::~cColInfoNode()
{
}



//////////////////////////////////////////////////////////////////////
cSprite::cSprite() : cImage()
{
   m_type = OBJTYPE_SPRITE;
   m_collidable = false;

   m_list = new cLList<cColInfoNode>();
}


cSprite::~cSprite()
{
}

/*
int cSprite::Load(const char *filename)
{
   // TODO
   return 0;
}
*/


void cSprite::Collidable()
{
   m_collidable = true;
}

void cSprite::NotCollidable()
{
   m_collidable = false;
}


bool cSprite::IsCollidable()
{
   if( m_cframe != NULL) {
      return (  m_collidable &&
               (m_cframe->nap > 0)
             );
   }
   
   return m_collidable;
}

sPoint *cSprite::GetColPoints(uInt8 num) // num is ZONE_*
{
   /*
   if(m_cframe != NULL) {
      return &(m_cframe->ap[num]);
   }
   */

   return NULL;
}


void cSprite::ResetColInfo()
{
   m_list->clear();
}


int cSprite::AddColInfo(uInt32 id, uInt16 type, void *data)
{
   sColInfo ci;
   ci.id = id;
   ci.type = type;
   ci.data = data;

   cColInfoNode cin(ci);
   m_list->append(cin);

   return 0;
}

