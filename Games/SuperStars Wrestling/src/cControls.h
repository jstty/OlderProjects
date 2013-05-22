/* //////////////////////////////////////////////////////////////////////
 Program Name:  cControls.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Controls Class Header File
  
  90% done!
  todo:
   - return player list, or use wrapper functions, not sure.
   - add mouse controls???
   
////////////////////////////////////////////////////////////////////// */
#ifndef __CONTROLS__
#define __CONTROLS__

typedef struct _sControl
{
   uInt8 player;
   uInt8 action;

   Int32 key;
   Int8 joy_num;
   Int8 joy_type;
   Int8 joy_stick;
   Int8 joy_axis;
   union
   {
      Int8 joy_pos;
      Int8 joy_button;
   };

} sControl;

class cControls
{
   public:
      cControls();
      ~cControls();

      int ProcessActions();

      int Init();
      int Exit();
      int Load(const char *filename); // load config settings
 
      // debug
      int DisplayJoyStick();
      
   private:
      bool      m_exited;

      uInt32    m_gsize;
      sControl *m_game;

      uInt32    m_psize;
      sControl *m_player;

      void FreeAll();
};

#endif // __CONTROLS__