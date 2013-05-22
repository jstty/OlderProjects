/* //////////////////////////////////////////////////////////////////////
 Program Name:  cSeq.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-16
 Updated:       
 Version:       1.00
 Description:
   Sequence of Frames Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


cSeq::cSeq()
{
   m_anim_done = false;
   m_loop_type = 0;
   m_loop_count = 0;

   m_current = 0;
   m_size = 0;
   m_list = NULL;

   memset(m_name, 0, 128*sizeof(char));
}

void cSeq::operator =(const cSeq &src)
{
   uInt32 i;
   strcpy(m_name, src.m_name);
   m_loop_type = src.m_loop_type;

   m_size = src.m_size;
   m_list = new sSeqFrame[m_size];
   for(i = 0; i < m_size; ++i) {
      m_list[i] = src.m_list[i];
   }

   m_current = src.m_current;
   m_loop_count = src.m_loop_count;

   m_anim_done = src.m_anim_done;
}


cSeq::~cSeq()
{
   DELETE_A(m_list);
   m_size = 0;
}


sSeqFrame *cSeq::SetCurrent(uInt16 num)
{
   m_anim_done = false;

   m_current = num;
   return GetCurrent();
}


sSeqFrame *cSeq::GetCurrent()
{
   sSeqFrame *seqfrm = NULL;

   if(m_current >= m_size) {
      m_current = 0;
   }

   if(m_list != NULL) {
      seqfrm = &(m_list[m_current]);
      ++m_current; // current is always next
   }

   return seqfrm;
}


sSeqFrame *cSeq::Step()
{
   sSeqFrame *seqfrm = NULL;

   if(m_anim_done)
   {
      if(m_loop_type)
      {
         if(m_loop_count > 0) {
            --m_loop_count;
            m_anim_done = false;
            m_current = 0;
         }
      } else { // loop forever
         m_anim_done = false;
         m_current = 0;
      }
   }

   if(m_list != NULL) {
      seqfrm = &(m_list[m_current]);
   }

   if(!m_anim_done)
   {
      ++m_current; // increase by one

      if(m_current >= m_size) {
         m_current = m_size - 1; // should be last frame
         m_anim_done = true;
      }
   }

   return seqfrm;
}


int cSeq::Load(cTextFileReader *tfr, bool has_mirror, uInt32 last_frame)
{
   int e = 0;
   uInt16 i, t;

   // name of seq
   e = tfr->ReadString(m_name);
   if(e) return e;

   if(has_mirror) {
      strcat(m_name, "_r"); // auto append
   }

   // loop type
   e = tfr->ReadInt(m_loop_type);
   if(e) return e;

   m_loop_count = m_loop_type; // loop type is the number of loops allowed

   // num frames in seq
   tfr->ReadInt(m_size);
   
   m_list = new sSeqFrame[ m_size ];
   for(i = 0; i < m_size; ++i)
   {
      // delay
      e = tfr->ReadInt(m_list[i].delay);
      if(e) return e;

      // frame number
      e = tfr->ReadInt(m_list[i].fn);
      if(e) return e;

      if(has_mirror)
      {
         // use mirror
         e = tfr->ReadInt(t);
         if(e) return e;

         // if flip
         if(t) {
            m_list[i].fn += last_frame;
         }
      }
   }
   m_current = 0;

   return 0;
}


int cSeq::MakeMirror(cSeq *src, uInt32 last_frame)
{
   uInt16 i;
   
   strncpy(m_name, src->m_name, strlen(src->m_name) - 2);
   strcat(m_name, "_l");

   // loop type
   m_loop_type  = src->m_loop_type;
   m_loop_count = m_loop_type; // loop type is the number of loops allowed

   // num frames in seq
   m_size = src->m_size;
   
   m_list = new sSeqFrame[ m_size ];
   for(i = 0; i < m_size; ++i)
   {
      m_list[i].delay = src->m_list[i].delay;

      if(src->m_list[i].fn >= last_frame)
         m_list[i].fn = src->m_list[i].fn - last_frame;
      else
         m_list[i].fn = src->m_list[i].fn + last_frame;
   }
   m_current = 0;

   return 0;
}

bool cSeq::AnimDone()
{
   return m_anim_done;
}


char *cSeq::GetName()
{
   return m_name;
}


uInt16 cSeq::GetCurrentIndex()
{
   return m_current;
}
