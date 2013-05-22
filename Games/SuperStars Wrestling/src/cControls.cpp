/* //////////////////////////////////////////////////////////////////////
 Program Name:  cControls.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-14
 Updated:       
 Version:       1.00
 Description:
   Controls Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


cControls::cControls()
{
   m_exited = false;
   
   m_gsize = 0;
   m_game = NULL;

   m_psize = 0;
   m_player = NULL;
}


cControls::~cControls()
{
   Exit();
}

int cControls::Init()
{
   install_keyboard();
   install_joystick(JOY_TYPE_AUTODETECT);
   install_mouse();

   return 0;
}

void cControls::FreeAll()
{
   DELETE_A(m_game);
   m_gsize = 0;

   DELETE_A(m_player);
   m_psize = 0;
}

int cControls::Exit()
{
   if(!m_exited)
   {
      remove_keyboard();
      remove_joystick();
      remove_mouse();

      FreeAll();

      m_exited = true;
   }

   return 0;
}

// data file struct
//
// <num game actions>
// <action> <key> <joy_num> <joy_type> <stick> <axis> <pos/button>
// ...
//
// <num players> <num actions>
// <player> <action> <key> <joy_num> <joy_type> <stick> <axis> <pos/button>
// ...
//
// joy_num  = -1 -> joy not used 
// joy_type = 0  -> joy not used
// joy_type = 1  -> stick,axis
// joy_type = 2  -> button
int cControls::Load(const char *filename)
{
   FILE *fp;
   fp = fopen(filename, "r");
   if(fp == NULL)
   {
      // error
      return 1;
   }

   FreeAll(); // makesure everthing is gone.

   uInt32 i;
   uInt8 num_players, num_player_actions;


   //
   fscanf(fp, "%d", &m_gsize);
   m_game   = new sControl[m_gsize];
   //

   for(i = 0; (i < m_gsize ) | (feof(fp)); ++i)
   {
      m_game[i].player = 0;

      fscanf(fp, "%d", &(m_game[i].action));

      fscanf(fp, "%d", &(m_game[i].key));

      fscanf(fp, "%d", &(m_game[i].joy_num));
      fscanf(fp, "%d", &(m_game[i].joy_type));
      fscanf(fp, "%d", &(m_game[i].joy_stick));
      fscanf(fp, "%d", &(m_game[i].joy_axis));
      fscanf(fp, "%d", &(m_game[i].joy_pos));
   }

   if(feof(fp))
   {
      fclose(fp);
      return 1;
   }

   //
   fscanf(fp, "%d", &num_players);
   fscanf(fp, "%d", &num_player_actions);

   m_psize   = num_players*num_player_actions;
   m_player   = new sControl[m_psize];

   info->Init(m_gsize, num_players, num_player_actions);
   //

   for(i = 0; (i < m_psize ) | (feof(fp)); ++i)
   {
      fscanf(fp, "%d", &(m_player[i].player));
      fscanf(fp, "%d", &(m_player[i].action));

      fscanf(fp, "%d", &(m_player[i].key));

      fscanf(fp, "%d", &(m_player[i].joy_num));
      fscanf(fp, "%d", &(m_player[i].joy_type));
      fscanf(fp, "%d", &(m_player[i].joy_stick));
      fscanf(fp, "%d", &(m_player[i].joy_axis));
      fscanf(fp, "%d", &(m_player[i].joy_pos));
   }

   fclose(fp);

   return 0;
}

int cControls::ProcessActions()
{
   uInt32 i;
   sControl ctrl;

   // allegro get keyboard, joystick, and mouse info
   poll_keyboard();
   poll_joystick();
   //

   // error check
   if(m_player == NULL) return 1;
   if(m_game == NULL)   return 1;

   if(info == NULL)
      return 2;

   info->Reset();
   //

   //////////////////////////////////////////////////////////////
   // check player
   for(i = 0; i < m_gsize; ++i)
   {
      ctrl =  m_game[i];

      // Keyboard
      if(ctrl.key != -1)
      {
         if( key[ ctrl.key ] ) // key is allegro variable
         {
            info->g[ ctrl.action ] = true;
         }
      }
      //

      // JoyStick
      if(ctrl.joy_num != -1)
      {
         if(ctrl.joy_type == 1) // stick
         {
            if( ctrl.joy_pos > 0) // if greater then zero, check if pressed is greater then
            {
               if( joy[ ctrl.joy_num ].
                   stick[ ctrl.joy_stick ].
                   axis[ ctrl.joy_axis ].pos > ctrl.joy_pos )
               {
                  info->g[ ctrl.action ] = true;
               }
            } else {  // if less then zero, check if pressed is less then
               if( joy[ ctrl.joy_num ].
                   stick[ ctrl.joy_stick ].
                   axis[ ctrl.joy_axis ].pos < ctrl.joy_pos )
               {
                  info->g[ ctrl.action ] = true;
               }
            }
         } 
         else if(ctrl.joy_type == 2) // button
         {
            if( joy[ ctrl.joy_num ].button[ ctrl.joy_button ].b == 1 )
            {
               info->g[ ctrl.action ] = true;  
            }
         }
      }
      //
   }
   //
   //////////////////////////////////////////////////////////////


   //////////////////////////////////////////////////////////////
   // check player
   for(i = 0; i < m_psize; ++i)
   {
      ctrl =  m_player[i];

      // Keyboard
      if(ctrl.key != -1)
      {
         if( key[ ctrl.key ] ) // key is allegro variable
         {
            info->p[ ctrl.player ][ ctrl.action ] = true;
         }
      }
      //

      // JoyStick
      if(ctrl.joy_num != -1)
      {
         if(ctrl.joy_type == 1) // stick
         {
            if( ctrl.joy_pos > 0) // if greater then zero, check if pressed is greater then
            {
               if( joy[ ctrl.joy_num ].
                   stick[ ctrl.joy_stick ].
                   axis[ ctrl.joy_axis ].pos > ctrl.joy_pos )
               {
                  info->p[ ctrl.player ][ ctrl.action ] = true;
               }
            } else {  // if less then zero, check if pressed is less then
               if( joy[ ctrl.joy_num ].
                   stick[ ctrl.joy_stick ].
                   axis[ ctrl.joy_axis ].pos < ctrl.joy_pos )
               {
                  info->p[ ctrl.player ][ ctrl.action ] = true;
               }
            }
         } 
         else if(ctrl.joy_type == 2) // button
         {
            if( joy[ ctrl.joy_num ].button[ ctrl.joy_button ].b == 1 )
            {
               info->p[ ctrl.player ][ ctrl.action ] = true;  
            }
         }
      }
      //
   }
   //
   //////////////////////////////////////////////////////////////

   // pointer, todo
   // mouse
   /*
      mouse_x
   */

   return 0;
}


// debugging
int cControls::DisplayJoyStick()
{
   int i, j, pos = 12;

   JOYSTICK_AXIS_INFO s;
   for(i = 0; i < joy[0].num_sticks; ++i)
   {
      for(j = 0; j < joy[0].stick[i].num_axis; ++j)
      {
         s = joy[0].stick[i].axis[j];
         textprintf(screen, font, 150, pos, 11, "%d,%d (%d,%d,%d)", i, j, s.d1, s.d2, s.pos);
         pos += 12;
      }
   }

   
   JOYSTICK_BUTTON_INFO b;
   for(i = 0; i < joy[0].num_buttons; ++i)
   {
      b = joy[0].button[i];
      textprintf(screen, font, 150, pos, 11, "button #%d %d", i, b.b);
      pos += 12;
   }

   return 0;
}

