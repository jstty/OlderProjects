////////////////////////////////////////////////////////////////////////
//	Program Name:	CDPlayer.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	CD Player header File
//	Date: 
////////////////////////////////////////////////////////////////////////

// Macro(s)
#define ShowItem(hwnd, id, flag) \
				SetWindowPos(GetDlgItem(hwnd, id), NULL, 0, 0, 0, 0, flag | SWP_NOMOVE | SWP_NOSIZE)

	// Def
#define CDTIME				250
#define STARTITEM			118
#define ENDITEM				131
#define CX_ICON				32
#define CY_ICON				32
#define ID_GENERAL		0
#define ID_LOADSAVE		1
#define ID_CDPLAYER		2
#define	NEW_CD				0
#define	LOAD_CD				1
#define	SAVE_CD				2

	// Global Var.
#ifdef DLLIMPORT
	DllImport LPGLOBAL	global;
#else
	extern LPGLOBAL	global;
#endif
	// Other Var.
extern UINT					TabIndex;
int									BoxReturn;

// Misc.
void CALLBACK CD_DlgTimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
void CALLBACK CDTimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
void PlayList(HWND hwndDlg, UINT msg);
void CDProc(UINT msg);

// Button Func.
void StartCD(HWND hwndDlg);
void TabCD(HWND hwndDlg);
void PlayCD(HWND hwndDlg);
void PauseCD(HWND hwndDlg);
void RewindCD(HWND hwndDlg);
void FastFCD(HWND hwndDlg);
void StopCD(HWND hwndDlg);
void EjectCD(HWND hwndDlg);
void EditPL(HWND hwndDlg);
void Shuffle(HWND hwndDlg);
void RTrack(HWND hwndDlg);
void RDisk(HWND hwndDlg);

	// External AI Func.
extern void RandomList(int *iRanArray, int iListMax, int iRanMax);
