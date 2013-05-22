/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLevelInfo.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-16
 Updated:       
 Version:       1.00
 Description:
   Level Info Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __LEVEL_INFO__
#define __LEVEL_INFO__

class cDisplay;
class cScriptEngine;
class cPlayerMngr;

class cLevelInfo
{
   public:
      bool paused;

      uInt8 ng; // number of game actions
      bool *g;  // game[action code]

      // Script Engine
      cScriptEngine *se; // DON'T DELETE
      cPlayerMngr   *pmngr; // DON'T DELETE

      // controls
      uInt8 np; // number of players
      uInt8 na; // number of actions
      bool **p; // player[player #][action code]

      // display
      cDisplay *display;

      // sound
      // todo

      cLevelInfo();
      ~cLevelInfo();

      int Init(uInt8 num_game_actions, uInt8 num_players, uInt8 num_player_actions);

      void Reset();

      // debug
      int DisplayActions();

};

#endif // __LEVEL_INFO__
