////////////////////////////////////////////////////////////////////////
//  Program Name: SoundDll.h
//  Programmer: Joseph Sutton
//  Description: DLL Sound Header File
//  Date:
////////////////////////////////////////////////////////////////////////

DllExport LPTSTR MIDI(UINT msg, HWNDdll hwnd);
DllExport LPCSTR File;
DllExport int sec;
DllExport int MTimeRate;
UINT MidiId, PlayCDId;
LPTSTR error;
