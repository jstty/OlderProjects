////////////////////////////////////////////////////////////////////////
//	Program Name:	DialogUtils.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Dialog Utils File
//	Date: 
////////////////////////////////////////////////////////////////////////

// Macro(s)
#define ShowItem(hwnd, id, flag) \
				SetWindowPos(GetDlgItem(hwnd, id), NULL, 0, 0, 0, 0, flag | SWP_NOMOVE | SWP_NOSIZE)

// Defined cases
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

	// other stuff
#define CDTIME				1000
#define STARTITEM			118
#define ENDITEM				131
#define CX_ICON				32
#define CY_ICON				32
#define ID_GENERAL		0
#define ID_LOADSAVE		1
#define ID_CDPLAYER		2
#define	NEW						0
#define	LOAD					1
#define	SAVE					2

// Imported Varables
#ifdef DLLIMPORT
	DllImport LPGAME		game;
	DllImport LPGLOBAL	global;
#else
	extern LPGAME		game;
	extern LPGLOBAL	global;
#endif
// Globel Varables
HIMAGELIST	himl;
GAMEINFO		GameInfo[MAXSAVE];
char				textbox[MAXARRAY];
char				item1[MAXARRAY];
char				item2[MAXARRAY];
UINT				controlstat;
UINT				TabIndex;
//////////////////////////////
char				string[100];
 
	// Global Functions
BOOL CALLBACK ControlBar_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Loadfile_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Savefile_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Text_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Options_DialogProc(HWNDdll hwndDlg, UINT Message, WPARAM wParam, LPARAM lParam);

	// Message Functions
void Load_OnCommand(HWND hwndDlg, int id);
void Save_OnCommand(HWND hwndDlg, int id);
void ControlBar_OnCommand(HWND hwndDlg, int id);
void Options_OnCommand(HWND hwndDlg, int id);
void ControlBar_OnNotify(HWND hwndDlg, int idCtrl, LPNMHDR pnmh);

	// File Utils Functions
extern void SaveGameFile(LPSTR file);
extern void NewGameFile(LPSTR file);
//extern void SaveLevelFile(LPSTR file, LEVELINFO li[]);
//extern void NewLevelFile(LPSTR file, LEVELINFO li[]);

	// Imported Main Level Functions
#ifdef DLLFile
	DllImport void MsgProc(HWNDdll hwndDll, UINT id, LPSTR item1, LPSTR item2);
#else
	extern void MsgProc(HWNDdll hwndDll, UINT id, LPSTR item1, LPSTR item2);
#endif

	// External Child Func.
extern void CALLBACK CD_TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);

	// External CDPlayer Func.
extern void CALLBACK CD_DlgTimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
extern void PlayList(HWND hwndDlg, UINT msg);
extern void CDProc(UINT msg);

extern void StartCD(HWND hwndDlg);
extern void TabCD(HWND hwndDlg);
extern void PlayCD(HWND hwndDlg);
extern void PauseCD(HWND hwndDlg);
extern void RewindCD(HWND hwndDlg);
extern void FastFCD(HWND hwndDlg);
extern void StopCD(HWND hwndDlg);
extern void EjectCD(HWND hwndDlg);
extern void EditPL(HWND hwndDlg);
extern void Shuffle(HWND hwndDlg);
extern void RTrack(HWND hwndDlg);
extern void RDisk(HWND hwndDlg);

	// External Midi Proc.
extern void MidiProc(UINT msg);
