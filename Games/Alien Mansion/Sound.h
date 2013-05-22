////////////////////////////////////////////////////////////////////////
//  Program Name: SoundDll.h
//  Programmer: Joseph Sutton
//  Description: DLL Sound Header File
//  Date:
////////////////////////////////////////////////////////////////////////

// Globel Exported Varables
//UINT		MidiId, PlayCDId;
//LPTSTR	error;
//LPSTR		File;
//UINT		sec, MidiTimeRate;
DllImport LPGLOBAL global;

	// Misc Exported Functions
DllExport LPTSTR MidiProc(HWNDdll hwnd, SOUND sound, UINT msg);
DllExport LPTSTR CDAudio(SOUND sound, UINT msg, DWORD TrackNumber);
DllExport void WaveProc(HINST hInst, WORD rcFile);
	// Misc Functions
void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
