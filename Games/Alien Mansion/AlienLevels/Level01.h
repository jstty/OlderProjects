////////////////////////////////////////////////////////////////////////
//	Program Name:	Level##n.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Levels header File
//	Date: 
////////////////////////////////////////////////////////////////////////

#define IDM_LEVEL01		"sound//megazone.mid"

// External Main Levels Varables
extern HINSTANCE	LevelhInst;
extern LPLEVEL		level;
extern LPGAME			game;
extern LPGLOBAL		global;
//
extern HDC			origBkgHdc;
//extern HDC			BkgHdc;
//extern BOOL			Redraw;
// Imported Child Window Varables
//DllImport HWNDdll	ChildHwnd;

	// Misc Functions
void Level_Proc1(HWNDdll hwndDll);
void Start_L1(void);
void Mid_L1(void);

	// Imported Child Window Functions
DllImport void ButtonUpdate(void);

	// Imported Graphics Functions
DllImport HDC CompileBitmap(HWND hwnd, LPLEVEL level);
DllImport HDC DisplayBG(HWND hwnd, HDC bitmap);
DllImport void CompileSprite(HWND hwnd, HDC origBkgHdc, LPLEVEL level);

	// Imported Midi Function(s)
DllImport void MidiProc(UINT msg);
	// Imported DxSnd Function(s)
DllImport void WaveProc(UINT uNum, UINT uControl, DWORD uMsg);