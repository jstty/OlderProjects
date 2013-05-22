////////////////////////////////////////////////////////////////////////
//  Program Name: Midi.h
//  Programmer: Joseph Sutton
//  Description: Midi Header File
//  Date: 10/26/97
////////////////////////////////////////////////////////////////////////

DllImport LPGLOBAL global;

	// Misc Exported Functions
DllExport void MidiProc(UINT msg);
	// Misc Functions
void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
