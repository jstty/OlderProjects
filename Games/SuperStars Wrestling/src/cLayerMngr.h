/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLayerMngr.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-26
 Updated:       
 Version:       1.00
 Description:
   Layer Manager Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __LAYER_MNGR__
#define __LAYER_MNGR__

class cLayerNode
{
   public:
      cLayerNode();
      cLayerNode(cLayer *layer);
      ~cLayerNode();

      cLayer *GetLayer();

   private:
      cLayer *m_layer;
};

class cLayerMngr
{
   public:
      cLayerMngr();
      ~cLayerMngr();

      int  Init(); // should only done once
      void FreeAll();

      int Add(cLayer *layer);
      int Draw(ImgData *out, bool clear_buffer = false);

      void FreeAllLayers();

      void ShiftXY(Int32 x, Int32 y);

   private:
      cLList<cLayerNode> *m_list;

};

#endif // __LAYER_MNGR__
