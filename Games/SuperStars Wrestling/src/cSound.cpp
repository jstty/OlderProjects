/* //////////////////////////////////////////////////////////////////////
 Program Name:  cSound.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-18
 Updated:       
 Version:       1.00
 Description:
   Controls Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


cSound::cSound()
{
   m_exited = false;
}


cSound::~cSound()
{
   Exit();
}

int cSound::Init()
{
   if(install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0) 
   {
      // allegro_message("Error initialising sound system");
      // error
      return 1;
   }

   return 0;
}

int cSound::Exit()
{
   if(!m_exited)
   {
      remove_sound();

      m_exited = true;
   }

   return 0;
}
