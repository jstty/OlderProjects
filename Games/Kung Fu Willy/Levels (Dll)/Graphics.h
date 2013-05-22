////////////////////////////////////////////////////////////////////////
//  Program Name: Graphics.h
//  Programmer: Joseph Sutton
//  Description: Graphics Header File
//  Date:
////////////////////////////////////////////////////////////////////////

DllImport void CALLBACK DisplayBG(HWNDdll hwnd);
DllImport void CALLBACK DisplaySp(HWNDdll hwnd, UINT Sprite,int frame, int x, int y, int SpriteW, int delta);
DllImport void CALLBACK LoadSprites(void);
DllImport void CompileBitmaps(HWNDdll hwnd);
DllImport void CALLBACK DelBitmaps(void);
DllImport UINT BitmapX, BitmapY;