////////////////////////////////////////////////////////////////////////
//	Program Name:	MainLevels.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Main Levels header File
//	Date: 
////////////////////////////////////////////////////////////////////////

	// Text bar words
#define USE						"Use "
#define EXAMINE				"Examine "
#define TALK					"Talk to "
#define OPEN					"Open "
#define CLOSE					"Close "
#define GET						"Get "
#define GIVE					"Give "
#define PUSH					"Push/Pull "
#define WITH					" with "
#define TO						" to "
	// Item words
#define KEY						"funky key"
#define SODA					"bottle of Super Spudzes(TM)"
#define ROBOARM				"Robust(TM) robot arm"
#define APP						"1234 page entry application"
#define CANDYBAR			"Googy Goos(TM) candy bar"
#define REMOTE				"Pentium(TM) powered remote control"
#define ENVELOP				"shiny white envelop"
#define SANTA					"mutilated Santa Moggie(TM)"
#define STAKE					"rusting bloody stake"
#define STAMP					"crapy prelicked stamp"
#define VEGGY					"ugly vicious mutant V.Eggy(TM)"
#define ENVELOP_APP		"envelop stuffed and licked"

// Global Varables
HINSTANCE					LevelhInst;
HDC								origBkgHdc;
char							SelectStr[MAXARRAY][MAXARRAY];
// Export Global Varables
DllExport LPLEVEL		level;
DllExport LPGAME		game;
DllExport LPGLOBAL	global;

	// External DialogUtils Function(s)
extern void ControlBar_OnNotify(HWND hwndDlg, int idCtrl, LPNMHDR pnmh);
	// External Graphics Function(s)
extern void CompileSprite(HWND hwnd, HDC origBkgHdc, LPLEVEL level);
extern BOOL CheckPath(HWND hwnd, LPLEVEL level, UINT spriteNum, UINT msg, int dS);
	// External DxSnd Function(s)
extern SOUND LoadWaveFile(HINSTANCE hInst, SOUND sound);

	// External Level_Proc##n Functions
extern void Level_Proc1(HWNDdll hwndDll);
extern void Level_Proc2(HWNDdll hwndDll);
extern void Level_Proc3(HWNDdll hwndDll);
extern void Level_Proc4(HWNDdll hwndDll);
	// External Level_Msg##n Functions
extern LPSTR Level_Msg2(HWNDdll hwndDll, LPSTR tempstr, UINT id, LPSTR item1, LPSTR item2);
extern LPSTR Level_Msg3(HWNDdll hwndDll, LPSTR tempstr, UINT id, LPSTR item1, LPSTR item2);
extern LPSTR Level_Msg4(HWNDdll hwndDll, LPSTR tempstr, UINT id, LPSTR item1, LPSTR item2);

	// Export GameProc Functions
DllExport void GameProc(HWNDdll hwndDll);
DllExport void MsgProc(HWNDdll hwndDll, UINT id, LPSTR item1, LPSTR item2);

	// Misc Functions
void LoadGraphics(UINT levelnum);
void DisplayIcon(void);
void Walk(void);
void RectCheck(void);
void LevelSwitch(HWNDdll hwndDll);
void MsgSwitch(HWNDdll hwndDll, char *S, UINT id, LPSTR item1, LPSTR item2);

	//////////////////////////////////////
	//			Level Jump Macro
	//////////////////////////////////////
#define LevelJump( n, hwndDll) \
				Level_Proc##n(hwndDll)

	//////////////////////////////////////
	//			Level Message Macro
	//////////////////////////////////////
#define LevelMsg( n, hwndDll, s, id, item1, item2) \
				Level_Msg##n(hwndDll, s, id, item1, item2)


