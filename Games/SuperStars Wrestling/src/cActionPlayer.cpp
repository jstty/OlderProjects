/* //////////////////////////////////////////////////////////////////////
 Program Name:  cActionPlayer.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-19
 Updated:       
 Version:       1.00
 Description:
   Action Player and Recorder Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


cActionPlayer::cActionPlayer()
{
   m_fp = NULL;

   m_pos = 0;
   m_num_actions = 0;
   m_paused = false;

   m_state = AP_NOTHING;
}


cActionPlayer::~cActionPlayer()
{
   Close();
}


void cActionPlayer::CloseFile()
{
   if(m_fp != NULL) {
      // 
      if(m_state == AP_RECORDING)
      {
         // update number of actions
         fseek(m_fp, 0, SEEK_SET);
         fwrite(&m_num_actions, sizeof(uInt32), 1, m_fp);
      }

      m_state = AP_NOTHING;
      fclose(m_fp);
      m_fp = NULL;
   }
}

void cActionPlayer::Close()
{
   CloseFile();
   UnPause();
   m_state = AP_NOTHING;
}

int cActionPlayer::Load(const char *filename)
{
   CloseFile();

   m_pos = 0;
   m_num_actions = 0;
   m_fp = fopen(filename, "r+");
   if(m_fp == NULL) {
      return 1;
   }

   fread(&m_num_actions, sizeof(uInt32), 1, m_fp);

   return 0;
}



int cActionPlayer::Save(const char *filename)
{
   CloseFile();

   m_num_actions = 0;
   m_fp = fopen(filename, "w+");
   if(m_fp == NULL) {
      return 1;
   }

   fwrite(&m_num_actions, sizeof(uInt32), 1, m_fp);

   return 0;
}


void cActionPlayer::Update()
{
   if(m_paused) return;

   uInt8 i;
   
   if(m_state == AP_PLAYING)
   {
      if(m_pos < m_num_actions) {
         ++m_pos;
      } else {
         return;
      }

      // read
      /*
      fread(&info->ng, sizeof(uInt8), 1, m_fp);
      fread(info->g, sizeof(bool), info->ng, m_fp);
      */

      fread(&info->np, sizeof(uInt8), 1, m_fp);
      fread(&info->na, sizeof(uInt8), 1, m_fp);
      for(i = 0; i < info->np; ++i) {
         fread(info->p[i], sizeof(bool), info->na, m_fp);
      }
      //

   } else 
   if(m_state == AP_RECORDING) {

      // write
      /*
      fwrite(&info->ng, sizeof(uInt8), 1, m_fp);
      fwrite(info->g, sizeof(bool), info->ng, m_fp);
      */

      fwrite(&info->np, sizeof(uInt8), 1, m_fp);
      fwrite(&info->na, sizeof(uInt8), 1, m_fp);
      for(i = 0; i < info->np; ++i) {
         fwrite(info->p[i], sizeof(bool), info->na, m_fp);
      }
      //

      ++m_num_actions;
   }
}


void cActionPlayer::Step()
{
   if(m_state != AP_PLAYING) return;

   bool old_paused = m_paused;

   m_paused = false;
   Update();
   m_paused = m_paused;
}

void cActionPlayer::SetPlaying()
{
   m_state = AP_PLAYING;
}

void cActionPlayer::SetRecording()
{
   m_state = AP_RECORDING;
}

void cActionPlayer::UnPause()
{
   m_paused = false;
}

void cActionPlayer::Pause()
{
   m_paused = true;
}

