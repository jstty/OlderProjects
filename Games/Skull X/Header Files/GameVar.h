////////////////////////////////////////////////////////////////////////
//	Program Name:	GameVar.h
//	Programmer:		Joseph E. Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Game Variable File
//	Date:					04/17/2000
////////////////////////////////////////////////////////////////////////

#ifndef _GAME_VAR
#define _GAME_VAR

// 8bit		-> 2  chars
// 16bit	-> 4  chars
// 32bit	-> 9  chars
// 64bit	-> 19 chars
struct C_INFO
{
unsigned __int8 level;	//								2
unsigned __int32 exp;		// Total Exp			7
unsigned __int32 next;	// Exp till next	7
unsigned __int32 gold;	//								7

unsigned __int16 hp;		// Hit Points				3
unsigned __int16 t_hp;	// Total Hit Points	3

unsigned __int16 mp;		// Magic Points				3
unsigned __int16 t_mp;	// Total Magic Points	3

// Base
unsigned __int8 a;	// Attack	2
unsigned __int8 d;	// Defend	2
unsigned __int8 m;	// Magic	2
unsigned __int8 s;	// Speed	2

// Item
unsigned __int8 a_item;	// Attack Item - Sword	2
unsigned __int8 d_item;	// Defend Item - Armor	2
unsigned __int8 m_item;	// Magic	Item - Shield	2
unsigned __int8 s_item;	// Speed	Item - Boots	2
};

struct SAVE_MAP_XY
{
	unsigned __int8 x;	// Goo map x pos in blocks
	unsigned __int8 y;	// Goo map y pos in blocks

};

struct SAVE_MAP_INFO
{
	SAVE_MAP_XY goo_xy[5];
	bool goo_killed[5];
};

struct GAME_VAR
{
	unsigned __int16 ScreenNum;
	unsigned __int32 SubScreenNum;

	C_INFO char_info[2]; // 0 Super	Ninja || 1 Red		Ninja

	SAVE_MAP_INFO mi;

	unsigned __int16	h; // Hour
	unsigned __int8		m; // Minute
	unsigned __int8		s; // Second
};

#endif