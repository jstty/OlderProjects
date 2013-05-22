////////////////////////////////////////////////////////////////////////
//	Program Name:	ControlVar.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Control Var header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _CONTROLS_VAR
#define _CONTROLS_VAR

#include "..\Header Files\Program.h"

#define JOY_DIFF 10000

#define HOTKEYF_SHIFT           0x01
#define HOTKEYF_CONTROL         0x02
#define HOTKEYF_ALT             0x04

#define C_JOY 1
#define C_KEY 2

//
#define UP					0
#define DOWN				1
#define LEFT				2
#define RIGHT				3
#define B1					4
#define B2					5
#define B3					6
#define B4					7
//

#define NUM_B	8
#define NUM_S 2

struct Key
{
	unsigned __int8	Code;
	bool						a;
	bool						c;
	bool						s;
};

struct JoyStick
{
	bool							Enabled;
	unsigned __int8		PlayerNum;
	unsigned __int16	Horz[2];
	unsigned __int16	Vert[2];
	unsigned __int8		Button[NUM_B];
};

struct ControlVar
{
		unsigned __int16 Delay;
		unsigned __int16 DelayRes;

		unsigned __int8 NumPlayer;

		unsigned __int8 NumsKey;
		Key	*sKey;

		unsigned __int8 NumpKey;
		Key	*pKey;
		unsigned __int8 kPlayerNum;

		unsigned __int8 NumJoy;
		JoyStick	*Joy;
};

struct DBOOL
{
	bool v;
	unsigned int c:2;
};

struct MOUSE_INFO
{
	bool left;
	bool right;
	bool middle;
	unsigned __int16 x;
	unsigned __int16 y;

	unsigned __int16 StartX;
	unsigned __int16 StartY;
	unsigned __int16 EndX;
	unsigned __int16 EndY;

	bool show;
};

#define NUMDIRECT 4
#define NUMBUTTON 3
#define NUMSYSTEM 2

// Version 2
struct JoyStickButton
{	
	unsigned int B:3; 
};

class GSControlVar
{
	public:
		unsigned int	Delay:10;
		unsigned int	DelayRes:10;
	//
		unsigned int	KeyPlayer:3;

		struct KeyPOINTS
		{
			unsigned __int16 Code;
			unsigned __int16 ID;
		};

		KeyPOINTS				Key[NUMDIRECT + NUMBUTTON];
		KeyPOINTS				System[NUMSYSTEM];
// Version 2
		bool						EnableJoy1;
		bool						EnableJoy2;
		//
		unsigned int		Joy1Player:3;
		unsigned int		Joy2Player:3;
		//
		unsigned __int16	Joy1[NUMDIRECT];
		JoyStickButton		bJoy1[NUMBUTTON];
		unsigned __int16	Joy2[NUMDIRECT];
		JoyStickButton		bJoy2[NUMBUTTON];
};

#endif
