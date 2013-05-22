/* //////////////////////////////////////////////////////////////////////
 Program Name:  cAnim.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Animation Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


cAnim::cAnim()
{
   m_delay = 0;

   m_nframe = 0;
   m_frame = NULL;

   m_cframe = NULL;
   m_frame_done = false;

   m_cseq = 0;
   m_num_seq = 0;
   m_seq = NULL;
   m_csfrm = NULL;

   m_play = false;
}


cAnim::cAnim(const cAnim &src)
{
   uInt32 i;
   m_frame_done = src.m_frame_done;
   m_delay = src.m_delay;

   m_play = src.m_play;
   m_cframe = src.m_cframe;

   m_nframe = src.m_nframe;
   m_frame = new cFrame[m_nframe];
   for(i = 0; i < m_nframe; ++i) {
      m_frame[i] = src.m_frame[i];
   }

   m_num_seq = src.m_num_seq;
   m_seq = new cSeq[m_num_seq];
   for(i = 0; i < m_num_seq; ++i) {
      m_seq[i] = src.m_seq[i];
   }

   m_csfrm = src.m_csfrm;
   m_cseq = src.m_cseq;
}


cAnim::~cAnim()
{
   ClearList();

   DELETE_A(m_seq);
}

void cAnim::ClearList()
{
   DELETE_A(m_frame);
}


int cAnim::Load(const char *filename, uInt8 style_dir)
{
   char s[256], path[256];
      
   // get file path
   Int32 path_len = (Int32)(strrchr(filename, '/') - filename + 1);
   strncpy(path, filename, sizeof(char)*path_len);
   path[path_len] = '\0';
   //

   cTextFileReader tfr;
   if( tfr.Load(filename) ) {
      return 1; // error, could not load file
   }

   sprintf(s, "%s%d/", path, style_dir);

   return Load(&tfr, s);
}


int cAnim::Load(const char *filename)
{
   char path[256];
      
   // get file path
   Int32 path_len = (Int32)(strrchr(filename, '/') - filename + 1);
   strncpy(path, filename, sizeof(char)*path_len);
   path[path_len] = '\0';
   //

   cTextFileReader tfr;
   if( tfr.Load(filename) ) {
      return 1; // error, could not load file
   }

   return Load(&tfr, path);
}


// -- file struct -- 
// <bool, all in one file>
// -- if 1 --
//   <filename>
//   <number of frames>
//   [frame 0]
//   <width> <height> <shift x> <shift y> <hot x> <hot y>
//   [frame 1]
//   ...
//
// -- if 0 --
//   <dir/file format>
//   <number of frames> <number of frames not using default>
//   <type normal(0)>
//   -- if type normal --
//      <frame num> <shift x> <shift y> <hot x> <hot y>
//   ...
// 
// [seq 0]
// <name of seq> <loop type, 0-forever, 1-once> <num frames in seq>
// [seq frame 1]
// <delay> <frame number>
// [seq frame 1]
// ...
//
// [seq 1]
// ...
//
int cAnim::Load(cTextFileReader *tfr, const char *path)
{
   char s[256], tmp_file[256];
   Int32 ti, e = 0;
   uInt32 i, old_size = 0;
   Int32 x_img_offset, y_img_offset;

   bool all_in_one_file;
   // <bool, all in one file>
   tfr->ReadInt(ti);
   all_in_one_file = ti > 0;

   if(all_in_one_file)
   {
      ImgData *tmp_img;

      // get load file
      tfr->ReadString(s);
      sprintf(tmp_file, "%s%s", path, s); // build full path and filename

      tmp_img = load_bitmap(tmp_file, NULL);
      if(tmp_img == NULL) {
         // error,
         return 2;
      }

      tfr->ReadInt(m_nframe);
      old_size = m_nframe;

      ClearList();
      m_frame = new cFrame[m_nframe];
      for(i = 0; i < m_nframe; ++i)
      {
         y_img_offset = 0;

         if(i == 0) {
            x_img_offset = 0;
         } else {
            x_img_offset += m_frame[i-1].w;
         }

         m_frame[i].Load(tfr, tmp_img, x_img_offset, y_img_offset);
      }
      //

      destroy_bitmap(tmp_img);

   // NOT all in one
   } else {
      uInt32 j, frame_num, num_frames;

      tfr->ReadString(s);
      sprintf(tmp_file, "%s%s", path, s); // build full path and filename

      // number of frames to load
      tfr->ReadInt(m_nframe);
      old_size = m_nframe;
      
      // number of frames to modify
      tfr->ReadInt(num_frames);

      if(!all_in_one_file) {
         m_nframe *= 2;
      }

      // load half of all the frames
      ClearList();
      m_frame = new cFrame[m_nframe];
      for(i = 0; i < old_size; ++i)
      {
         sprintf(s, tmp_file, i);
         m_frame[i].Load(s);
      }

      // process update of frame info
      for(j = 0; j < num_frames; ++j)
      {
         tfr->ReadInt(frame_num);
         m_frame[frame_num].Load(tfr);
      }

      // create mirroed frames
      for(i = old_size; i < m_nframe; ++i)
      {
         m_frame[i].MakeMirror(&(m_frame[i - old_size]), old_size);
      }
   } // end NOT all in one

   e = LoadSeq(tfr, all_in_one_file, old_size);
   
   //
   Reset();

   return e;
}


int cAnim::AddFrameImage(const char *filename)
{
   uInt32 i;
   cFrame *old = m_frame;

   // allocate new, and copy
   ++m_nframe;
   cFrame *tmp = new cFrame[m_nframe];

   if(m_frame != NULL)
   {
      for(i = 0; i < m_nframe-1; ++i) {
         tmp[i] = m_frame[i];
      }
   }

   i = m_nframe-1;
   m_frame = tmp;
   //

   ImgData *tmp_img = load_bitmap(filename, NULL);
   if(tmp_img == NULL) {
      if(m_frame != NULL) delete [] m_frame;
      m_frame = old;
      return 2;
   }

   m_frame[i].img = tmp_img;
   m_cframe = &(m_frame[i]);
   
   // if all ok, remove old
   if(old != NULL) delete [] old;
   
   return 0;
}


void cAnim::Reset()
{
   Select((uInt16)0, 0);
   
   m_frame_done = 0;
}


cFrame *cAnim::NextFrame()
{
   if(m_frame == NULL) return NULL;

   m_csfrm  = m_cseq->Step();

   if(m_csfrm == NULL)
   {
      m_cframe = NULL;
      return NULL;
   }

   if(m_csfrm->fn >= m_nframe)
   {
      m_cframe = NULL;
      return NULL;
   }

   m_cframe = &(m_frame[ m_csfrm->fn ]);
   m_delay  = m_csfrm->delay; // set current delay

   return m_cframe;
}


cFrame *cAnim::GetCurrent()
{
   return m_cframe;
}

void cAnim::Play()
{
   m_play = true;
}

void cAnim::Pause()
{
   m_play = false;
}


bool cAnim::IsPlaying()
{
   return m_play;
}


cFrame * cAnim::Step()
{
   if(m_nframe < 2) // one or no animations
      return m_cframe;

   if(m_play) // if playing
   {
      if(m_frame_done) { // at end now, switch to next frame
         m_frame_done = false;
         return NextFrame();
      }

       if(m_delay < 1) {
         m_frame_done = true; // reached end.
      } else {
         --m_delay; // reduce delay by one
      }
   }

   return m_cframe;
}

bool cAnim::FrameDone()
{
   return m_frame_done;
}

// animation done
bool cAnim::Done()
{
   if(m_cseq != NULL)
      return m_cseq->AnimDone();
   else
      return false;
}


int cAnim::Select(uInt16 seq_num, uInt16 frame_num)
{
   if( (m_frame == NULL) ||
       (m_seq == NULL) || 
       (seq_num >= m_num_seq)
     ) return 1;

   m_cseq = &(m_seq[seq_num]);

   SetFrame(frame_num);
   return 0;
}

int cAnim::Select(const char *name, uInt16 frame_num)
{
   uInt16 i;
   for(i = 0; i < m_num_seq; ++i)
   {
      if(strcmp(m_seq[i].GetName(), name) == 0) {
         return Select(i, frame_num);
      }
   }

   return 1;
}

void cAnim::SetFrame(uInt16 frame_num)
{
   m_csfrm = m_cseq->SetCurrent(frame_num);

   if(m_csfrm == NULL)
   {
      m_cframe = NULL;
      return;
   }
   if(m_csfrm->fn >= m_nframe)
   {
      m_cframe = NULL;
      return;
   }

   m_cframe = &(m_frame[ m_csfrm->fn ]);
   m_delay  = m_csfrm->delay; // set current delay
}


char *cAnim::GetName()
{
   return m_cseq->GetName();
}


uInt32 cAnim::GetFrame()
{
   return m_cseq->GetCurrentIndex();
}


void cAnim::InitFrames(cAnim *base)
{
   // double for mirror
   m_nframe = base->m_nframe * 2;
   m_frame = new cFrame[m_nframe];
}


void cAnim::UpdateFrames(ImgData **list)
{
   uInt32 i, size;
   size = m_nframe/2;

   for(i = 0; i < size; ++i)
   {
      m_frame[i].w = list[ m_frame[i].frm ]->w;
      m_frame[i].h = list[ m_frame[i].frm ]->h;
   }
}


// call after call UpdateFrames
void cAnim::MirrorFrames(uInt32 num_frames, uInt32 num_layers)
{
   uInt32 i, old_size;
   old_size = m_nframe/2;

   // mirror
   for(i = old_size; i < m_nframe; ++i)
   {
      m_frame[i].MakeMirror(&(m_frame[i - old_size]), num_frames, num_layers);
   }
}


int cAnim::LoadFrames(const char *filename, cAnim *base)
{
   cTextFileReader fr;
   int e;
   uInt32 i, j, size, old_size;
   FILE *fp;
   char s[256], datafile[256], path[256];

   // get file path
   Int32 path_len = (Int32)(strrchr(filename, '/') - filename + 1);
   strncpy(path, filename, sizeof(char)*path_len);
   path[path_len] = '\0';
   //

   old_size = m_nframe/2;
   for(i = 0; i < old_size; ++i)
   {
      m_frame[i].frm = base->m_frame[i].frm;

      m_frame[i].state = base->m_frame[i].state;
      m_frame[i].attack = base->m_frame[i].attack;

      m_frame[i].mvx = base->m_frame[i].mvx;
      m_frame[i].mvy = base->m_frame[i].mvy;
      m_frame[i].mvz = base->m_frame[i].mvz;
      m_frame[i].ofx = base->m_frame[i].ofx;
      m_frame[i].ofy = base->m_frame[i].ofy;
      m_frame[i].scp = base->m_frame[i].scp;

      m_frame[i].col_type = base->m_frame[i].col_type;
      m_frame[i].nap = base->m_frame[i].nap;
      if(m_frame[i].nap > 0)
      {
         m_frame[i].ap = new sAction[m_frame[i].nap];
         for(j = 0; j < m_frame[i].nap; ++j)
         {
            m_frame[i].ap[j].x1 = base->m_frame[i].ap[j].x1;
            m_frame[i].ap[j].x2 = base->m_frame[i].ap[j].x2;
         }
      }

      // Layer
      m_frame[i].lyr_frm = base->m_frame[i].lyr_frm;
      m_frame[i].lyr_ofx = base->m_frame[i].lyr_ofx;
      m_frame[i].lyr_ofy = base->m_frame[i].lyr_ofy;
      m_frame[i].lyr_mvx = base->m_frame[i].lyr_mvx;
      m_frame[i].lyr_mvy = base->m_frame[i].lyr_mvy;
   }

   e = fr.Load(filename);
   if(e) return e;

   fr.ReadString(datafile);

   //
   sprintf(s, "%s%s", path, datafile);
   fp = fopen(s, "r+");
   if(fp == NULL) return 2;

   // <state> <attack>
   // <offset x> <offset y>
   // <scope>
   // <layer offset x> <layer offset y>
   uInt32 frmnum;
   fread(&size, sizeof(size), 1, fp);
   for(i = 0; i < size; ++i)
   {
      fread(&(frmnum), sizeof(uInt32), 1, fp); // Frame Index to change

      fread(&(m_frame[frmnum].ofx), sizeof(Int32), 1, fp); // GFX X-Offset
      fread(&(m_frame[frmnum].ofy), sizeof(Int32), 1, fp); // GFX Y-Offset
      fread(&(m_frame[frmnum].scp), sizeof(Int32), 1, fp); // Horizontal Spacial Scope

      // Attack
      // TODO
      //fread(&(uitmp), sizeof(Int32), 1, fp); // Attack X 1
      //fread(&(uitmp), sizeof(Int32), 1, fp); // Attack X 2

      // Layer
      fread(&(m_frame[frmnum].lyr_ofx), sizeof(Int32), 1, fp); // GFX X-Offset
      fread(&(m_frame[frmnum].lyr_ofy), sizeof(Int32), 1, fp); // GFX Y-Offset
   }
   fclose(fp);
   //

   // copy seq
   m_num_seq = base->m_num_seq;
   m_seq = new cSeq[m_num_seq];
   for(i = 0; i < m_num_seq; ++i)
   {
      m_seq[i] = base->m_seq[i];
   }

   return 0;
}


// for base
int cAnim::LoadFrames(const char *filename)
{
   Int32 itmp;
   uInt32 i;
   FILE *fp;

   fp = fopen(filename, "r+b");
   if(fp == NULL) return 1;

   fread(&m_nframe, sizeof(Int32), 1, fp);

   m_frame = new cFrame[m_nframe];
   for(i = 0; i < m_nframe; ++i)
   {
      //
      fread(&(m_frame[i].frm), sizeof(Int32), 1, fp);    // GFX Frame
      fread(&(m_frame[i].state), sizeof(Int32), 1, fp);  // Animation State Value
      fread(&(m_frame[i].attack), sizeof(Int32), 1, fp); // Animation Attack Value

      // in seq class
      fread(&(itmp), sizeof(Int32), 1, fp); // Object Animation Delay till Next Frame
      // not used, defined in seq
      fread(&(itmp), sizeof(Int32), 1, fp); // Object Animation Next Frame

      fread(&(m_frame[i].mvx), sizeof(Int32), 1, fp); // X Movement (Tween) Permanent
      fread(&(m_frame[i].mvy), sizeof(Int32), 1, fp); // Y Movement (Tween) Tempoary Offset
      fread(&(m_frame[i].mvz), sizeof(Int32), 1, fp); // Y Movement (Tween) Permanent
      fread(&(m_frame[i].ofx), sizeof(Int32), 1, fp); // GFX X-Offset
      fread(&(m_frame[i].ofy), sizeof(Int32), 1, fp); // GFX Y-Offset
      fread(&(m_frame[i].scp), sizeof(Int32), 1, fp); // Horizontal Spacial Scope

      // Attack
      Int32 x1, x2;
      fread(&(m_frame[i].col_type), sizeof(Int32), 1, fp); // Collision Type
      fread(&(x1), sizeof(Int32), 1, fp); // Attack X 1
      fread(&(x2), sizeof(Int32), 1, fp); // Attack X 2

      if(x1 != x2)
      {
         m_frame[i].nap = 1;
         m_frame[i].ap = new sAction[m_frame[i].nap];
         m_frame[i].ap[0].x1 = x1;
         m_frame[i].ap[0].x2 = x2;
      } else {
         m_frame[i].nap = 0;
         m_frame[i].ap = NULL;
      }
      //

      // Layer
      fread(&(m_frame[i].lyr_frm), sizeof(Int32), 1, fp); // GFX Frame to Display
      fread(&(m_frame[i].lyr_ofx), sizeof(Int32), 1, fp); // GFX X-Offset
      fread(&(m_frame[i].lyr_ofy), sizeof(Int32), 1, fp); // GFX Y-Offset
      fread(&(m_frame[i].lyr_mvx), sizeof(Int32), 1, fp); // X Movement (Tween) Tempoary Offset
      fread(&(m_frame[i].lyr_mvy), sizeof(Int32), 1, fp); // Y Movement (Tween) Tempoary Offset
      //
   }
   fclose(fp);

   return 0;
}


int cAnim::LoadSeq(cTextFileReader *tfr, bool all_in_one_file, uInt32 old_size)
{
   int e;
   uInt32 i;

   if(old_size == 0) {
      old_size = m_nframe;
   }

   //////////////////////////////////////////////
   // read ahead to get number of sequences
   uInt32 pos = tfr->GetPos();
   m_num_seq = 0;
   while( !tfr->AtEnd() )
   {
      cSeq tmpseq;
      e = tmpseq.Load(tfr, !all_in_one_file, old_size);
      if(!e) {
         ++m_num_seq;
      } else {
         break;
      }
   }
   
   // seek back
   tfr->SetPos(pos);
   //////////////////////////////////////////////

   // number of sequences
   uInt32 old_num_seq = m_num_seq;

   if(!all_in_one_file) {
      m_num_seq *= 2;
   }

   m_seq = new cSeq[m_num_seq];
   for(i = 0; i < old_num_seq; ++i) {
      m_seq[i].Load(tfr, !all_in_one_file, old_size);
   }

   //
   if(!all_in_one_file) {
      // make mirror
      for(i = old_num_seq; i < m_num_seq; ++i) {
         m_seq[i].MakeMirror(&m_seq[i - old_num_seq], old_size);
      }
   }

   return 0;
}

