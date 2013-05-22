/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLayerMngr.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-16
 Updated:       
 Version:       1.00
 Description:
   Level Manager Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


cLayerNode::cLayerNode()
{

}


cLayerNode::cLayerNode(cLayer *layer)
{
   m_layer = layer;
}

cLayerNode::~cLayerNode()
{
}

/*
bool cLayerNode::operator ==(const cLayerNode &src) const
{
   if(m_order == src.m_order)
      return true;
   else 
      return false;
}

bool cLayerNode::operator !=(const cLayerNode &src) const
{
   if(m_order != src.m_order)
      return true;
   else 
      return false;
}


bool cLayerNode::operator  >(const cLayerNode &src) const
{
   if(m_order > src.m_order)
      return true;
   else 
      return false;
}

bool cLayerNode::operator  <(const cLayerNode &src) const
{
   if(m_order < src.m_order)
      return true;
   else 
      return false;
}
*/

cLayer *cLayerNode::GetLayer()
{
   return m_layer;
}



cLayerMngr::cLayerMngr()
{
   m_list = new cLList<cLayerNode>();
}


cLayerMngr::~cLayerMngr()
{
   FreeAll();
}


void cLayerMngr::FreeAll()
{
   if(m_list != NULL)
   {
      m_list->clear();
      delete m_list;
      m_list = NULL;
   }
}

void cLayerMngr::FreeAllLayers()
{
   if(m_list != NULL) {
      m_list->clear();
   }
}


int cLayerMngr::Init()
{
   return 0;
}


int cLayerMngr::Add(cLayer *layer)
{
   if( (m_list != NULL) && (layer != NULL) )
   {
      cLayerNode tmp(layer);
      m_list->append(tmp);
   }

   return 0;
}


int cLayerMngr::Draw(ImgData *out, bool clear_buffer)
{
   if(m_list != NULL)
   {
      cLayerNode *tmp;
      cLayer     *layer;

      // walk linked list
      tmp = m_list->front();
      while(tmp != NULL)
      {
         layer = tmp->GetLayer();
         if(layer != NULL)
            layer->Draw(out);

         tmp = m_list->next();
      }
   }

   return 0;
}

void cLayerMngr::ShiftXY(Int32 x, Int32 y)
{
   if(m_list != NULL)
   {
      cLayerNode *tmp;
      cLayer     *layer;

      // walk linked list
      tmp = m_list->front();
      while(tmp != NULL)
      {
         layer = tmp->GetLayer();
         if(layer != NULL){
            layer->ShiftX(x);
            layer->ShiftY(y);
         }

         tmp = m_list->next();
      }
   }
}

