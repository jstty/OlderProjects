////////////////////////////////////////////////////////////////////////
//  Program Name: LevelsDll.h
//  Programmer: Joseph Sutton
//  Description: DLL Levels Header File
//  Date:
////////////////////////////////////////////////////////////////////////
#define MAXHIT		205

DllExport void Reset(HWNDdll hwnd);
DllImport void CALLBACK TimerProc( HWNDdll hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
DllExport void Quit(HWNDdll hwnd);
DllExport void Difficulty(int dl);

DllExport LEVEL l;
//DllExport GRAPHIC g;
DllExport PGRAPHIC pg;
DllExport int TimeRate;
// Export to controls
int GTimeRate;
int hit;
DllExport double percent;

DllExport BOOL fight;   
DllExport BOOL gtimer;
DllExport UINT ScreenW, ScreenH, MidX, MidY, GScreenW, GScreenH;
DllExport int EnergyP1, EnergyP2;

int qRandom(int StartSize, int EndSize);
int rRandom(int StartSize, int EndSize);
void ScreenClean(HWNDdll hwnd);
void WalkOn(HWNDdll hwnd, UINT Sprite1, UINT Sprite2);
void LoadBitmaps(void);
void FLF(HWNDdll hwnd, HINST hInst);
void EndRoundF(HWNDdll hwnd);
void LOSSER(HWNDdll hwnd);
void QA(HWNDdll hwnd, LPCTSTR message);

HWND hwndP1, hwndP2;
int i, j, k, m, n, delta;
BOOL endround;
const UINT SpriteSize = 41;
using namespace std;
