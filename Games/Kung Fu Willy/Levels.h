////////////////////////////////////////////////////////////////////////
//  Program Name: Levels.h
//  Programmer: Joseph Sutton
//  Description: Levels Header File
//  Date:
////////////////////////////////////////////////////////////////////////
#define IDB_TITLE                       3000

DllImport void TitleStart(HWNDdll hwnd, HINST hInst);
DllImport void TitleMid(HWNDdll hwnd, HINST hInst);
DllImport void TitleEnd(HWNDdll hwnd, HINST hInst);
DllImport void PvsPStart(HWNDdll hwnd, HINST hInst);
DllImport void PvsPMid(HWNDdll hwnd, HINST hInst);
DllImport void PvsPEnd(HWNDdll hwnd, HINST hInst);
DllImport void PvsCStart(HWNDdll hwnd, HINST hInst);
DllImport void PvsCMid(HWNDdll hwnd, HINST hInst);
DllImport void PvsCEnd(HWNDdll hwnd, HINST hInst);
DllImport void MidScreen(void);
DllImport void Reset(HWNDdll hwnd);
DllImport void Quit(HWNDdll hwnd);
//DllImport GRAPHIC g;
DllImport PGRAPHIC pg;
DllImport int TimeRate;  
DllImport int GTimeRate;  
DllImport BOOL fight; 
DllImport BOOL gtimer; 
DllImport LEVEL l;
DllImport UINT ScreenW, ScreenH, MidX, MidY, GScreenW, GScreenH;
DllImport int EnergyP1, EnergyP2;
