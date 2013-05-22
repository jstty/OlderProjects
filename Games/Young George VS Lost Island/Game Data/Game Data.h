////////////////////////////////////////////////////////////////////////
//	Program Name:	Game Data.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Game Data header File
//	Date: 
////////////////////////////////////////////////////////////////////////

// Defined cases
#define Main_DefProc	DefWindowProc
#define MAINWINDOW		"Game Data Window"
#define IDT_MAIN			100

// Globel Varables
BOOL	mouseswitch;
BOOL	Mstart;
UINT	n, k, l, w, b;
UINT error;
extern LPLEVELARRAY level[MAXLEVEL];
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

void SaveLevels(void);
	// Misc Functions
extern void Level1(void);
extern void Level2(void);
extern void Level3(void);
extern void Level4(void);
extern void Level5(void);
extern void Level6(void);
extern void Level7(void);
extern void Level8(void);
extern void LevelLast(void);

