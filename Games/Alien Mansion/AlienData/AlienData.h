////////////////////////////////////////////////////////////////////////
//	Program Name:	AlienData.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Alien Data header File
//	Date: 
////////////////////////////////////////////////////////////////////////

// Defined cases
#define Main_DefProc	DefWindowProc
#define MAINWINDOW		"Alien Data Window"
#define IDT_MAIN			100

// MIDI Defined cases
#define IDM_LEVEL01		"sound//megazone.mid"
#define IDM_LEVEL02		"sound//megazone.mid"
#define IDM_LEVEL03		"sound//megazone.mid"
#define IDM_LEVEL04		"sound//megazone.mid"
#define IDM_LEVEL05		"sound//megazone.mid"
#define IDM_LEVEL06		"sound//megazone.mid"
#define IDM_LEVEL07		"sound//megazone.mid"
#define IDM_LEVEL08		"sound//megazone.mid"

// ZONE Defined cases
	// Level 01
#define ID_ZONE01_LEVEL01		"Title background"
//#define ID_ZONE02_LEVEL01		"Title Sprite"
	// Level 02
#define ID_ZONE01_LEVEL02		"Starting Gate"
#define ID_ZONE02_LEVEL02		"George"
#define ID_ZONE03_LEVEL02		"big shiny fire ball"
	// Level 03
#define ID_ZONE01_LEVEL03		"Sign screen"
#define ID_ZONE02_LEVEL03		"George"
#define ID_ZONE03_LEVEL03		"scary light in the sky"
#define ID_ZONE04_LEVEL03		"brown crusty sign"
	// Level 04
#define ID_ZONE01_LEVEL04		"Manic Mailbox"
#define ID_ZONE02_LEVEL04		"George"
#define ID_ZONE03_LEVEL04		"Super Techno Mail Box(TM)"
#define ID_ZONE04_LEVEL04		"sign post"
#define ID_ZONE05_LEVEL04		"GOD's toilet"
	// Level 05
#define ID_ZONE01_LEVEL05		"Left side of the Mansion"
#define ID_ZONE02_LEVEL05		"M O O N spells toolbox sign"
#define ID_ZONE03_LEVEL05		"weak shaky hairy ladder"
#define ID_ZONE04_LEVEL05		"George"
#define ID_ZONE05_LEVEL05		"plain stake with ketchup"
	// Level 06
#define ID_ZONE01_LEVEL06		"Outside front door"
#define ID_ZONE02_LEVEL06		"window to my soul"
#define ID_ZONE03_LEVEL06		"George"
#define ID_ZONE04_LEVEL06		"curvy voluptuous door"
	// Level 07
#define ID_ZONE01_LEVEL07		"Tree with Key"
#define ID_ZONE02_LEVEL07		"flamboyantly gay tree"
#define ID_ZONE03_LEVEL07		"George"
#define ID_ZONE04_LEVEL07		"demon spwan key"
	// Level 08
#define ID_ZONE01_LEVEL08		"Entrance way"
#define ID_ZONE02_LEVEL08		"stinky pile of crunk"
#define ID_ZONE03_LEVEL08		"stair case"
#define ID_ZONE04_LEVEL08		"George"
#define ID_ZONE05_LEVEL08		"one ton door"
#define ID_ZONE06_LEVEL08		"Impenetrable barrier"

// Globel Varables
BOOL	mouseswitch;
BOOL	Mstart;
UINT	n, k, l, w, b;
UINT error;
LPLEVELARRAY level[MAXLEVEL];
LPLEVELARRAY leveltemp[MAXLEVEL];

	// Main Startup Functions
long FAR PASCAL WindowProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
BOOL Register(HINSTANCE hInst);
HWND Create(HINSTANCE hInst, int nCmdShow);

	// Message Functions
BOOL Main_OnCreate(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct);
void Main_OnDestroy(HWND hwnd);
void Main_OnPaint(HWND hwnd);
void Main_Timer(HWND hwnd, UINT id);
void Main_LMouse(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags);
void Main_RMouse(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags);
void Main_Key(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags);

	// Misc Functions
void SaveLevels(void);
void Level1(void);
void Level2(void);
void Level3(void);
void Level4(void);
void Level5(void);
void Level6(void);
void Level7(void);
void Level8(void);
void LevelLast(void);
