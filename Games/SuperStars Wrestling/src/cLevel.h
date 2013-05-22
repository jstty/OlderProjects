/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLevel.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-16
 Updated:       
 Version:       1.00
 Description:
   Level Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __LEVEL__
#define __LEVEL__

class cLevel
{
   public:
      cLevel();
      ~cLevel();

      virtual int Init();  // called when level is starting, load...

      virtual int Loop();  // called each loop, check collison, actions...

      virtual int Draw();  // update display, only
      virtual int Sound(); // update sound, only

      virtual int Exit();  // called when leaving level

   protected:
      cDisplay   *m_display;
};

#endif // __LEVEL__
