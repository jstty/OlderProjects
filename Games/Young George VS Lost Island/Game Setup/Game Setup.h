////////////////////////////////////////////////////////////////////////
//	Program Name:	Game Setup.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Game Setup header File
//	Date: 
////////////////////////////////////////////////////////////////////////

// Defined cases
#define Main_DefProc	DefWindowProc
#define MAINWINDOW		"Game Setup"

// Global Var.
HWND				MainHwnd;
HWND				DlgHwnd;
HINSTANCE		MainhInst;
HACCEL			hAccel;
GAMESOUND		SoundSetup;
GAMEINFO		GameInfo[MAXSAVE];

	// Main Startup Function(s)
long FAR PASCAL WindowProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam); 
BOOL Register(HINSTANCE hInst);
HWND Create(HINSTANCE hInst, int nCmdShow);

	// Message Function(s)
BOOL Main_OnCreate(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct);
void Main_OnDestroy(HWND hwnd);
void Main_OnPaint(HWND hwnd);
void Main_Timer(HWND hwnd, UINT id);

	// Misc. Function(s)
void DefaultSetup(void);
void LoadSetup(void);
void LoadList(void);
void LoadStat(void);
void SaveStat(void);
void SaveSetupFile(LPSTR file);
void NewSetupFile(LPSTR file);

	// External Function(s)
extern void NewGameFile(LPSTR file);
extern void SaveGameFile(LPSTR file);
extern GAMESOUND LoadSetupFile(LPSTR file);

