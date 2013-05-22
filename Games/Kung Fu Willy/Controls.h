////////////////////////////////////////////////////////////////////////
//  Program Name: Controls.h
//  Programmer: Joseph Sutton
//  Description: Controls Header File
//  Date:
////////////////////////////////////////////////////////////////////////
//	MM_JOY1MOVE
#define HANDLE_MM_JOY1MOVE(hwnd, wParam, lParam, fn) \
    ((fn)(((HWNDdll)hwnd), (UINT)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)  
#define FORWARD_MM_JOY1MOVE(hwnd, fwButtons, xPos, yPos, fn) \
    (void)(fn)(((HWNDdll)hwnd), MM_JOY1MOVE, (WPARAM)(fwButtons), MAKELPARAM((xPos), (yPos)))
//	MM_JOY1BUTTONDOWN
#define HANDLE_MM_JOY1BUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)(((HWNDdll)hwnd), (UINT)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)  
#define FORWARD_MM_JOY1BUTTONDOWN(hwnd, fwButtons, xPos, yPos, fn) \
    (void)(fn)(((HWNDdll)hwnd), MM_JOY1BUTTONDOWN, (WPARAM)(fwButtons), MAKELPARAM((xPos), (yPos)))

//	MM_JOY2MOVE
#define HANDLE_MM_JOY2MOVE(hwnd, wParam, lParam, fn) \
    ((fn)(((HWNDdll)hwnd), (UINT)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)  
#define FORWARD_MM_JOY2MOVE(hwnd, fwButtons, xPos, yPos, fn) \
    (void)(fn)(((HWNDdll)hwnd), MM_JOY2MOVE, (WPARAM)(fwButtons), MAKELPARAM((xPos), (yPos)))
//	MM_JOY2BUTTONDOWN
#define HANDLE_MM_JOY2BUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)(((HWNDdll)hwnd), (UINT)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)  
#define FORWARD_MM_JOY2BUTTONDOWN(hwnd, fwButtons, xPos, yPos, fn) \
    (void)(fn)(((HWNDdll)hwnd), MM_JOY2BUTTONDOWN, (WPARAM)(fwButtons), MAKELPARAM((xPos), (yPos)))

//	WM_KEYDOWN
#pragma warning( disable : 4005 )
#define HANDLE_WM_KEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)(((HWNDdll)hwnd), (UINT)(wParam), TRUE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), 0L)
#define FORWARD_WM_KEYDOWN(hwnd, vk, cRepeat, flags, fn) \
    (void)(fn)(((HWNDdll)hwnd), WM_KEYDOWN, (WPARAM)(UINT)(vk), MAKELPARAM((cRepeat), (flags)))
#pragma warning( default : 4005 )

DllImport void Main_Joy1(HWNDdll hwnd, UINT fwButtons, UINT xPos, UINT yPos);
DllImport void Main_Joy2(HWNDdll hwnd, UINT fwButtons, UINT xPos, UINT yPos);
DllImport void Main_Key(HWNDdll hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags);
DllImport void ButtonUpdate(HWNDdll hwnd, HINST hInst);
DllImport CONTROL c;