/* //////////////////////////////////////////////////////////////////////
 Program Name:  cAnim.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Animation Class Header File
   frame number starts at ZERO
////////////////////////////////////////////////////////////////////// */
#ifndef __ANIMATION__
#define __ANIMATION__


class cAnim
{
   public:
      cAnim();
      cAnim(const cAnim &src); // copy constructor
      ~cAnim();

      int  Load(const char *filename);
      int  Load(const char *filename, uInt8 style_dir);

      int  AddFrameImage(const char *filename);

      void Play();
      void Pause();
      bool IsPlaying();

      cFrame  *Step(); // check and move to next frame
      cFrame  *GetCurrent();

      void SetFrame(uInt16 frame_num);

      int Select(uInt16 seq_num, uInt16 frame_num = 0); // set current sequence
      int Select(const char *name, uInt16 frame_num = 0); // set current sequence

      bool Done(); // animation done
      bool FrameDone();

      void Reset();     // back to first frame and such
      void ClearList(); // empty list

      char  *GetName();
      uInt32 GetFrame();

      //
      void InitFrames(cAnim *base);
      void UpdateFrames(ImgData **list);
      void MirrorFrames(uInt32 num_frames, uInt32 num_layers);
      int  LoadFrames(const char *filename, cAnim *base);

      int  LoadFrames(const char *filename);
      int  LoadSeq(cTextFileReader *tfr, bool all_in_one_file, uInt32 old_size);

   private:
      bool    m_frame_done;
      Int32   m_delay;     // temp delay to hold frame

      bool    m_play;
      cFrame *m_cframe;    // current animation frame, DON'T DELETE
      
      uInt32  m_nframe;
      cFrame *m_frame;     // array of frames, NEED TO DELETE

      sSeqFrame *m_csfrm;  // current sequence frame, DON'T DELETE
      cSeq   *m_cseq;      // current sequence, DON'T DELETE
      uInt16  m_num_seq;   //
      cSeq   *m_seq;       // NEED TO DELETE

      // in current animation
      cFrame *NextFrame();

      //
      int Load(cTextFileReader *tfr, const char *path);
};


#endif // __ANIMATION__
