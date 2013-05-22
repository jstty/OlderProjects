////////////////////////////////////////////////////////////////////////
//	Program Name:	Level##n.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Levels header File
//	Date: 
////////////////////////////////////////////////////////////////////////

#define IDM_LEVEL02		"sound//title.mid"

// External Main Levels Varables
extern LPLEVEL		level;
extern LPGAME			game;
extern LPGLOBAL		global;
//
extern HDC				origBkgHdc;
extern HINSTANCE	LevelhInst;
extern char				SelectStr[MAXARRAY][MAXARRAY];
//extern HDC				BkgHdc;
//extern UINT				George;
//extern BOOL				Redraw;
//extern int				iconloop;
// Imported DialopUitls Varables
//DllImport HWNDdll	DlgHwnd;
//DllImport HWNDdll	TextHwnd;
//DllImport BOOL		loadfile;
// Imported Child Window Varables
//DllImport HWNDdll	ChildHwnd;

	// Misc Functions
void Level_Proc2(HWNDdll hwndDll);
void Start_L2(void);
void Mid_L2(void);
LPSTR Level_Msg2(HWNDdll hwndDll, LPSTR tempstr, UINT id, LPSTR item1, LPSTR item2);

// External Main Levels Function(s)
extern void DisplayIcon(void);
extern void Walk(void);

	// Imported Graphics Function(s)
DllImport HDC CompileBitmap(HWND hwnd, LPLEVEL level);
DllImport HDC DisplayBG(HWND hwnd, HDC bitmap);
DllImport void CompileSprite(HWND hwnd, HDC origBkgHdc, LPLEVEL level);

	// Imported Sound Function(s)
DllImport void MidiProc(UINT msg);
	// Imported Sound Function(s)
DllImport SOUND WaveLoad(HINSTANCE hInst, SOUND sound);
DllImport void WaveProc(SOUND sound, UINT msg);
