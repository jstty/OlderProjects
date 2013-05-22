////////////////////////////////////////////////////////////////////////
//  Program Name: GraphicsDll.h
//  Programmer: Joseph Sutton
//  Description: DLL Graphics Header File
//  Date:
////////////////////////////////////////////////////////////////////////
HBITMAP		GlobalH_Bkg;
HDC				GlobalDC_Bkg;
HGDIOBJ		GlobalOldH_Bkg;
HBITMAP SpriteB, SpriteM, TempBitmap;
HBITMAP SpriteP1, SpriteP1M, 
				SpriteP2, SpriteP2M, 
				SpriteEB, SpriteEBM;
void GetSprite(UINT Sprite);
int Abs(int value);
DllExport UINT BitmapX, BitmapY;
