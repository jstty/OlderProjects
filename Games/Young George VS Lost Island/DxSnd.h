////////////////////////////////////////////////////////////////////////
//	Program Name:	DxSnd.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	DirectX Sound header File
//	Date: 
////////////////////////////////////////////////////////////////////////

// def
#ifdef DLLIMPORT
	DllImport LPGLOBAL	global;
#else
	extern LPGLOBAL	global;
#endif

DllExport SOUND LoadWaveFile(HINSTANCE hInst, SOUND sound);
DllExport void WaveProc(UINT uNum, UINT uControl, DWORD uMsg);
