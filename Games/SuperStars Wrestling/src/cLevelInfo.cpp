/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLevelInfo.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-16
 Updated:       
 Version:       1.00
 Description:
   Level Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cLevelInfo::cLevelInfo()
{
   ng = 0;
   g = NULL;
   
   se = NULL;
   pmngr = NULL;

   np = 0;
   na = 0;
   p = NULL;

   display = NULL;
}

cLevelInfo::~cLevelInfo()
{
   DELETE_A(g);
   ng = 0;

   if(p != NULL)
   {
      uInt8 i;
      for(i = 0; i < np; ++i)
      {
         DELETE_A(p[i]);
      }

      delete [] p;
   }

   np = 0;
   na = 0;
}

int cLevelInfo::Init(uInt8 num_game_actions, uInt8 num_players, uInt8 num_player_actions)
{
   uInt8 i;

   // game
   ng = num_game_actions;
   g = new bool[ng];
   memset(g, 0, ng*sizeof(bool));

   // player
   np = num_players;
   na = num_player_actions;
   p = new bool *[np];
   for(i = 0; i < np; ++i)
   {
      p[i] = new bool[na];
      memset(p[i], 0, na*sizeof(bool));
   }

   return 0;
}

void cLevelInfo::Reset()
{
   // game
   memset(g, 0, ng*sizeof(bool));

   // player
   uInt8 i;
   for(i = 0; i < np; ++i)
   {
      memset(p[i], 0, na*sizeof(bool));
   }
}

int cLevelInfo::DisplayActions()
{
   char s[256];
   uInt32 i, j, pos;

   pos = 12;
   for(i = 0; i < np; ++i)
   {
      sprintf(s, "player #%d", i);
      textout(screen, font, s, 1, pos, 11);

      pos += 12;
      for(j = 0; j < na; ++j)
      {
         if( p[i][j] )
         {
            sprintf(s, "  action #%d ON", j);
         } else {
            sprintf(s, "  action #%d OFF", j);
         }

         textout(screen, font, s, 1, pos, 11);
         pos += 12;
      }

      pos += 12;
   }

   return 0;
}

