/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLayer.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Basic Gfx Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


//
//
//
cLayer::cLayer()
{
   m_xpos = 0;
   m_ypos = 0;

   m_width  = 0;
   m_height = 0;

   m_show = true;
   m_use_buffer = 0;
   m_buffer = NULL;

   m_list = new cSList<cGfxNode>;

   m_use_fx = false;
   m_fx = new cFx();
}


cLayer::~cLayer()
{
   if(m_buffer != NULL)
   {
      destroy_bitmap(m_buffer);
      m_buffer = NULL;
   }

   ClearList();

   DELETE(m_list);
   DELETE(m_fx);
}


void cLayer::ClearList()
{
   m_list->clear();
}


void cLayer::Show()
{
   m_show = true;
}

void cLayer::Hide()
{
   m_show = false;
}

void cLayer::SetName(const char *name)
{
   strcpy(m_name, name);
}

const char *cLayer::GetName()
{
   return m_name;
}


//
int cLayer::Draw(ImgData *out)
{
   if(!m_show) return 0;

   if( (m_list == NULL) ||
       (out == NULL) ) return 1;

   m_linfo.out = out; // default use out buffer

   //
   if(m_use_buffer)
   {
      if(m_buffer == NULL) {
         return 2;
      }

      // offset going to be handled my buffer
      m_linfo.offset_x = 0;
      m_linfo.offset_y = 0;

      // clear buffer
      rectfill(m_buffer, 0, 0, m_width, m_height, COLOR_BLACK);
      m_linfo.out = m_buffer; // if m_use_buffer then use layer buffer
   } else {
      // no buffer, need to offset image
      m_linfo.offset_x = m_xpos;
      m_linfo.offset_y = m_ypos;
   }


   /////////////////////////////////////////////////////////
   // go though list of Simple and Advanced Sprites, calling there Draw function
   if(m_list != NULL)
   {
      cGfxNode   *tmp;
      cGfxObj    *gfxobj;

      // walk linked list
      tmp = m_list->front();
      while(tmp != NULL)
      {
         gfxobj = tmp->GetGfxObj();
         if(gfxobj != NULL)
            gfxobj->Draw(m_linfo.out, m_linfo.offset_x, m_linfo.offset_y);

         tmp = m_list->next();
      }
   }
   //
   /////////////////////////////////////////////////////////


   //
   if( m_use_buffer && 
       m_use_fx &&
       (m_fx != NULL) )
   {
      // alpha trans
      drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
         set_trans_blender(0, 0, 0, m_fx->GetFade() );
         draw_trans_sprite(out, m_linfo.out, m_xpos, m_ypos);
      drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);

   } else if(m_use_buffer) {
      masked_blit(m_linfo.out, out, 
         0, 0, 
         m_xpos, m_ypos, 
         m_linfo.out->w, m_linfo.out->h
         );
   }

   return 0;
}



/*
cSprite *cLayer::FindSprite(const char *name)
{
   cGfxNode tmp(-1, name);

   cGfxNode *ft = m_list->find(tmp);
   if(ft != NULL) // if found
   {
      return ft->GetSprite();
   }

   return NULL;
}

cImage *cLayer::FindImage(const char *name)
{
   cGfxNode tmp(-1, name);

   cGfxNode *ft = m_list->find(tmp);
   if(ft != NULL) // if found
   {
      return ft->GetImage();
   }

   return NULL;
}
*/


///////////////////////////////////////////////////////////
int cLayer::Add(cSprite *sprite)
{
   cGfxNode tn(sprite->GetName(), sprite);

   return m_list->append(tn);
}

int cLayer::Add(cImage  *img)
{
   cGfxNode tn(img->GetName(), img);

   return m_list->append(tn);
}

int cLayer::Add(cGfxObj *gfx)
{
   cGfxNode tn(gfx->GetName(), gfx);

   return m_list->append(tn);
}


int cLayer::Add(const char *name, cSprite *sprite)
{
   cGfxNode tn(name, sprite);

   return m_list->append(tn);
}


int cLayer::Add(const char *name, cImage  *img)
{
   cGfxNode tn(name, img);

   return m_list->append(tn);
}

int cLayer::Add(const char *name, cGfxObj *gfx)
{
   cGfxNode tn(name, gfx);

   return m_list->append(tn);
}
///////////////////////////////////////////////////////////


int cLayer::Update()
{
   /////////////////////////////////////////////////////////
   // go though list of Simple and Advanced Sprites, calling there Update function
   if(m_list != NULL)
   {
      cGfxNode   *tmp;
      cGfxObj    *gfxobj;

      // walk linked list
      tmp = m_list->front();
      while(tmp != NULL)
      {
         gfxobj = tmp->GetGfxObj();
         if(gfxobj != NULL)
            gfxobj->Step();

         tmp = m_list->next();
      }
   }
   //
   /////////////////////////////////////////////////////////


   UpdateFade();

   /////////////////////////////////////////////////////////
   //m_list->walk(NULL, cb_UpdateCollision);
   //
   /////////////////////////////////////////////////////////

   return 0;
}

/*
void cLayer::cb_UpdateCollision(void *o, cGfxNode gfx_node)
{
   cGfxObj *gfxobj = gfx_node.GetGfxObj();
   if(gfxobj != NULL)
   {
      if(gfxobj->collidable) {
         //pass in polygon to check if collided with
         //gfxobj->CheckCollision(m_poly->mp);
      }
   }
}
*/


// sets x, y pos
void cLayer::SetXY(Int32 x, Int32 y)
{
   m_xpos = x;
   m_ypos = y;
}


void cLayer::ShiftX(Int32 pos)
{
   m_xpos += pos;
}


void cLayer::ShiftY(Int32 pos)
{
   m_ypos += pos;
}

// sets width, height
void cLayer::SetSize(uInt32 w, uInt32 h, bool use_buffer)
{
   m_width  = w;
   m_height = h;
   m_use_buffer = use_buffer;

   if(m_use_buffer)
   {
      if(m_buffer != NULL) delete m_buffer;
   
      m_buffer = create_bitmap(m_width, m_height);
   }
}

//

//
void cLayer::FadeIn(uInt8 step, uInt8 min, uInt8 max)
{
   if(m_fx != NULL) {
      m_use_buffer = true;
      m_use_fx = true;
      m_fx->FadeIn(step, min, max);
   }
}

void cLayer::FadeOut(uInt8 step, uInt8 min, uInt8 max)
{
   if(m_fx != NULL) {
      m_use_buffer = true;
      m_use_fx = true;
      m_fx->FadeOut(step, min, max);
   }
}

void cLayer::UpdateFade()
{
   if(m_fx != NULL) {
      m_fx->FadeUpdate();
   }
}


bool cLayer::FadeDone()
{
   if(m_fx != NULL) {
      return m_fx->FadeDone();
   }

   return true;
}

