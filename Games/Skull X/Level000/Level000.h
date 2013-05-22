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

VALUES	*Val;
GAME_DATA *gData;
//
DBOOL *P1;

MOUSE_INFO	*cInfo;
MOUSE				*cSprite;
DISPLAY			*Display;
//

LAYER *Bkg;
LAYER *Text;
LAYER *Hand;
LAYER *Guardian;
LAYER *gCopy;

bool mItem[3];
XY Pos[3];
unsigned __int8 i;
unsigned __int8 End;
unsigned __int8 mNum;
unsigned __int16 mDelay;
bool uButton, dButton, bButton;
DWORD Tick;

#endif
