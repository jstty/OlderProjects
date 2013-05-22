////////////////////////////////////////////////////////////////////////
//  Program Name: Midi.h
//  Programmer: Joseph Sutton
//  Description: Midi Header File
//  Date: 10/26/97
////////////////////////////////////////////////////////////////////////
#ifdef DLLIMPORT
	DllImport LPGLOBAL	global;
#else
	extern LPGLOBAL	global;
#endif

	// Misc Exported Functions
DllExport void MidiProc(UINT msg);
	// Misc Functions
void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
