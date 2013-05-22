////////////////////////////////////////////////////////////////////////
//	Program Name:	Level???.h
//	Programmer:		Joseph E. Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Level Header File
//	Date:					02/23/2000
////////////////////////////////////////////////////////////////////////
#ifndef	_LEVEL
#define _LEVEL
#include "..\Header Files\ValuesClass.h"
#include "..\Header Files\GameVar.h"

VALUES			*Val;
GAME				*g;
GAME_DATA		*gData;
GAME_VAR		gv;
//
DBOOL *P1;

MOUSE_INFO	*cInfo;
MOUSE				*cSprite;
DISPLAY			*Display;
//

LAYER *Tile1;
LAYER *Tile2;
LAYER *Map;
LAYER *Camp;

LAYER **Goo;
LAYER *Super;

LAYER *Menu;

LAYER *Stat[2];
LAYER *Pic[2];
unsigned __int8 sPlayer;

LAYER *Items;

LAYER *Gray;

LAYER *Hand;

LAYER *xCounter;
LAYER *yCounter;
//

LAYER *c_level;
LAYER *c_gold;
LAYER *c_next;
LAYER *c_exp;

LAYER *c_hps;
LAYER *c_t_hps;

LAYER *c_mps;
LAYER *c_t_mps;

LAYER *c_ba;
LAYER *c_bd;
LAYER *c_bm;
LAYER *c_bs;

LAYER *c_ia;
LAYER *c_id;
LAYER *c_im;
LAYER *c_is;

LAYER *c_ta;
LAYER *c_td;
LAYER *c_tm;
LAYER *c_ts;

//
bool mItem[5];
XY Pos[5];
unsigned __int8 i, j, Goo_Movement_done, Start, nGoo;
unsigned __int8 End;
unsigned __int8 mNum;
unsigned __int16 mDelay;
bool uButton, dButton, bButton, b2Button, lButton, rButton;
DWORD mTick, Tick;

char S[4];
__int16 x, y, s_x, s_y;

bool WalkOnMap;

unsigned __int8 Level;

#endif
