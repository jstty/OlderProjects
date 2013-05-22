////////////////////////////////////////////////////////////////////////
//  Program Name: Sound.h
//  Programmer: Joseph Sutton
//  Description: Sound Header File
//  Date: 
////////////////////////////////////////////////////////////////////////
#define IDM_TITLE		"sound//Title.mid"
#define IDM_L1			"sound//L1.mid"
#define IDM_L2			"sound//L2.mid"
#define IDM_L3			"sound//L3.mid"
#define IDM_END			"sound//End.mid"

//MM_MCINOTIFY 
#define HANDLE_MM_MCINOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)(((HWNDdll)hwnd), (UINT)(wParam), (LONG)LOWORD(lParam)), 0L)  
#define FORWARD_MM_MCINOTIFY(hwnd, wFlags, lDevID, fn) \
    (void)(fn)(((HWNDdll)hwnd), MM_MCINOTIFY, (WPARAM)(wFlags), MAKELPARAM((lDevID), 0L))
//wParam = (WPARAM) wFlags 
//lParam = (LONG) lDevID
DllImport LPTSTR MIDI(UINT msg, HWNDdll hwnd);
DllImport void WAVE(WORD rcFile);
DllImport LPTSTR CDAudio(UINT msg, DWORD TrackNumber);
DllImport void Main_MciNotify(HWNDdll hwnd, UINT wFlags, LONG lDevID);
DllImport LPCSTR File;
DllImport int sec;
DllImport int MTimeRate;