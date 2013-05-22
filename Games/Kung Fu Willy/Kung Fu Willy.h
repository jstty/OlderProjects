////////////////////////////////////////////////////////////////////////
//  Program Name: Kung Fu Willy.h
//  Programmer: Joseph Sutton
//  Description: Kung Fu Willy Header File
//  Date:
////////////////////////////////////////////////////////////////////////

	// Defined cases
#define STRICT       
#define Main_DefProc DefWindowProc
#define WinName "Kung Fu Willy"

	// Main Startup Functions
long FAR PASCAL WindowProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);   
BOOL Register(HINSTANCE hInst);
HWND Create(HINSTANCE hInst, int nCmdShow);             

	// Message Functions
BOOL Main_Create(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct);
void Main_Destroy(HWND hwnd);
void Main_Paint(HWND hwnd);
void Main_Move(HWND hwnd, int x, int y); 
void Main_Timer(HWND hwnd, UINT flags);   
void Main_Command(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);

	// Misc Funtions
void Error_Message(UINT Type, LPTSTR Message);
void Level(HWND hwnd, HINSTANCE hInst);

	// Globel Varables
static HWND hwnd; 
static HINSTANCE MainHInst;
HINSTANCE hInst;

DllExport void CALLBACK TimerProc( HWNDdll hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);

