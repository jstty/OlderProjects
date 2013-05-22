///////////////////////////////////////////////////////////////////////
//	Program Name:	ChildWindow.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Child Window header File
//	Date: 
////////////////////////////////////////////////////////////////////////

// Imported Varables
DllImport LPGAME		game;
DllImport LPGLOBAL	global;
// Global Varables
BOOL		LoadButton, NewButton, ExitButton;
HBITMAP	BitmapLoad1, BitmapLoad2,
				BitmapNew1, BitmapNew2,
				BitmapExit1, BitmapExit2;

	// Global Functions
long CALLBACK ChildWindowProc(HWNDdll childHwnd, UINT Message, WPARAM wParam, LPARAM lParam);
	// Message Functions
BOOL Child_OnCreate(HWND childhwnd, CREATESTRUCT FAR* lpCreateStruct);
void Child_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void Child_DrawItem(HWND hwnd, const DRAWITEMSTRUCT *lpdis);
void Child_OnPaint(HWND hwnd);
void Child_Timer(HWND hwnd, UINT id);
void Child_Mouse(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags);
	// Export Functions
DllExport void ButtonUpdate(void);

	// Dialog Utils Functions
extern BOOL CALLBACK Loadfile_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);
extern BOOL CALLBACK Savefile_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);

	// Imported Main Level Functions
DllImport void GameProc(HWNDdll hwndDll);

	// External CDPlayer Func.
extern void PlayList(HWND hwndDlg, UINT msg);
extern void CDProc(UINT msg);

	// External Load Setup File Func.
extern GAMESOUND LoadSetupFile(LPSTR file);

	// External AI Func.
extern int RandomNum(int iRanMax);
extern void RandomList(int *iRanArray, int iListMax, int iRanMax);
