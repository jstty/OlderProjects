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
GAME_DATA	*gData;
DISPLAY		*Display;
GAME_VAR	gv;
//
DBOOL *P1;
//

GAME_DATA *TempGD[3];
GAME_VAR *TempGV[3];

LAYER *Tile;

LAYER *Win[3];
LAYER *Text[3];
LAYER *Title[3];
LAYER *Num[3];
LAYER *File[3];

LAYER *snLvl[3];
LAYER *rnLvl[3];
LAYER *hour[3];
LAYER *min[3];
LAYER *sec[3];

LAYER *Back;

LAYER *Hand;

bool mItem[4];
XY Pos[4];
unsigned __int8 i;
unsigned __int8 End;
unsigned __int8 mNum;
unsigned __int16 mDelay;
bool uButton, dButton, bButton;
DWORD Tick;

#endif
