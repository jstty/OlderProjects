////////////////////////////////////////////////////////////////////////
//	Program Name:	MainWindow.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Main Window header File
//	Date: 
////////////////////////////////////////////////////////////////////////

// Defined cases
#define Main_DefProc	DefWindowProc
#define MAINWINDOW		"Young George VS. Lost Island"
#define CHILDWINDOW		"Child Window"

//	Imported LPGLOBAL
DllImport LPGAME		game;
DllImport LPGLOBAL	global;
// Globel Varables
BOOL						ScreenSize;
extern char			string[100];

	// Main Startup Functions
long FAR PASCAL WindowProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
BOOL Register(HINSTANCE hInst);
HWND Create(HINSTANCE hInst, int nCmdShow);

	// Message Functions
BOOL Main_OnCreate(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct);
void Main_OnDestroy(HWND hwnd);
void Main_OnPaint(HWND hwnd);
void Main_OnMove(HWND hwnd, int x, int y);
void Main_Timer(HWND hwnd, UINT id);
void Main_Start(HWNDdll hwnd);

	// Child Window Functions
extern long CALLBACK ChildWindowProc(HWNDdll childHwnd, UINT Message, WPARAM wParam, LPARAM lParam);
	// Dialog Utils Functions
extern BOOL CALLBACK ControlBar_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);
extern BOOL CALLBACK Loadfile_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);
extern BOOL CALLBACK Savefile_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);
extern BOOL CALLBACK Text_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);
extern BOOL CALLBACK Options_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);
extern BOOL CALLBACK General_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);


