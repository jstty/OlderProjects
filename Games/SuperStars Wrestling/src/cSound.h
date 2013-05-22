/* //////////////////////////////////////////////////////////////////////
 Program Name:  cSound.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-18
 Updated:       
 Version:       1.00
 Description:
   cSound Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __SOUND__
#define __SOUND__

class cSound
{
   public:
      cSound();
      ~cSound();

      int Init();
      int Exit();

      //int Load(const char *filename); // load config settings
 
     
   private:
      bool m_exited;

};

#endif // __CONTROLS__