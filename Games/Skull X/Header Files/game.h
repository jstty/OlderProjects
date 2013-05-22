#include "..\Header Files\Gfx.h"

struct GAME
{
	unsigned __int8 Energy[2];
	unsigned __int8 Match_Type;
	unsigned __int8 Current_Match_Number;
	unsigned __int8 Number_of_Matchs;
	unsigned __int8 Char_Order[8];

	// single tree/tag linear
	unsigned __int8 Char_Win[4];
		// tag tree finals
	unsigned __int8 Char_SubWin[2];
	unsigned __int8 Char_Final;
};
/*
	// single linear
		Char_Order[0] = HONKY;
		Char_Order[1] = SAVAGE;

		Char_Order[2] = DUGGAN;
		Char_Order[3] = TED;
		Char_Order[4] = BOSSMAN;
		Char_Order[5] = HOGAN;
		Char_Order[6] = WARRIOR;
		Char_Order[7] = ANDRE;

	//tag linear
		// M1 easy
		Char_Order[0] = HONKY;
		Char_Order[1] = SAVAGE;
		Char_Order[2] = DUGGAN;
		Char_Order[3] = TED;

		// M2 mild
		Char_Order[4] = BOSSMAN;
		Char_Order[5] = HOGAN;

		// M3 hard
		Char_Order[6] = WARRIOR;
		Char_Order[7] = ANDRE;

		// FINAL mild
		RANDOM_PINED;
		RANDOM_PINED;

		// FINAL cheat_mode
		RANDOM_UNPINED;
		RANDOM_UNPINED;

	// Career Mode data table
		1,2
		3,4
		5,6
		7,8

		1,3
		2,4
		5,7
		6,8

		1,4
		2,3
		5,8
		6,7

		1,5
		2,6
		3,7
		4,8

		1,6
		3,5
		4,7
		2,8

		1,7
		2,5
		4,6
		3,8

		1,8
		2,7
		3,6
		4,5
	// tag
		1,2
		3,4

		1,3
		2,4

		1,4
		2,3
	//

	// one on two(tag) linear / 1 on 1 on 1 Linear
		// M1
		Char_Order[0] = HONKY;
		Char_Order[1] = SAVAGE;
		Char_Order[2] = DUGGAN;

		// M2
		Char_Order[3] = TED;
		Char_Order[4] = BOSSMAN;

		// M3
		Char_Order[5] = HOGAN;
		Char_Order[6] = WARRIOR;

		// M4
		Char_Order[7] = ANDRE;
		RANDOM_UNPINED or P2 if unpined;

*/

//1 on 1 Linear
#define MT_ONOL 1
//1 on 1 Tree
#define MT_ONOT 2
// Career Mode
#define MT_CM 0

//2 on 2 Linear
#define MT_TNTL 3
//2 on 2 Tree
#define MT_TNTT 4

//1 on 2(tag) Linear
#define MT_ONTL 5
//1 on 1 on 1 Linear
#define MT_ONONOL 7

//Battle Royal
#define MT_BR 9
//Royal Rumble
#define MT_RR 10
//Survivor
#define MT_SS 11
//3 Man Tag
#define MT_3MT 12

#define HOGAN		0
#define BOSSMAN	1
#define DUGGAN	2
#define HONKY		3
#define SAVAGE	4
#define WARRIOR	5
#define TED			6
#define ANDRE		7