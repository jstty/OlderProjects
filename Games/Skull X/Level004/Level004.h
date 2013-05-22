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

VALUES		*Val;
GAME_DATA *gData;
DISPLAY		*Display;
GAME_VAR	gv;
//
DBOOL *P1;
//

LAYER *LandA;
LAYER *LandB;
LAYER *Tab;
LAYER *Hand;
LAYER *Name;

LAYER *s_hp;
LAYER *s_t_hp;
LAYER *s_mp;
LAYER *s_t_mp;

LAYER *r_hp;
LAYER *r_t_hp;
LAYER *r_mp;
LAYER *r_t_mp;

LAYER *Lupi;
LAYER *Super;
LAYER *Red;

bool mItem[6];
XY Pos[6];
bool uButton, dButton, b1Button, b2Button, lButton, rButton;
unsigned __int8 i, j, End, mNum;
unsigned __int16 mDelay;
DWORD mTick;

#endif
