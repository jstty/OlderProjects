/* //////////////////////////////////////////////////////////////////////
 Program Name:  cSeq.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-16
 Updated:       
 Version:       1.00
 Description:
   Sequence of Frames Class Header File

////////////////////////////////////////////////////////////////////// */
#ifndef __SEQUENCE__
#define __SEQUENCE__


typedef struct _sSeqFrame
{
   uInt16 delay;
   uInt32 fn;     // frame number
} sSeqFrame;


class cSeq
{
   public:
      cSeq();
      ~cSeq();

      void operator =(const cSeq &src);

      char *GetName();
      //bool CmpName(const char *name);

      int Load(cTextFileReader *tfr, bool has_mirror = false, uInt32 last_frame = 0);
      int MakeMirror(cSeq *src, uInt32 last_frame);

      sSeqFrame *GetCurrent();
      sSeqFrame *SetCurrent(uInt16 num);

      sSeqFrame *Step(); // change current to next, return new frame

      uInt16 GetCurrentIndex();
      
      //
      bool       AnimDone();

   private:
      char       m_name[128];
      uInt8      m_loop_type;  // 0 - forever, 1 - once, ...

      uInt16     m_size;
      sSeqFrame *m_list;

      uInt16     m_current;    // current index in this sequence
      
      uInt8      m_loop_count;
      bool       m_anim_done;
};


#endif // __SEQUENCE__
