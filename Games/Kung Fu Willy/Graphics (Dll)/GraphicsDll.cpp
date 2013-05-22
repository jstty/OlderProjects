////////////////////////////////////////////////////////////////////////
//  Program Name: GraphicsDll.cpp
//  Programmer: Joseph Sutton
//  Description: DLL Graphics File
//  Date:
////////////////////////////////////////////////////////////////////////
#define STRICT
#include <windows.h>
#include <stdio.h>
#include <string.h>   
#include <mmsystem.h>
#include <Game.h>
#include "Levels.h"
#include "Controls.h"
#include "GraphicsDll.h"


			//////////////////////////////////////
			// DLLMain
			//////////////////////////////////////
BOOL APIENTRY DllEntryPoint(HINSTANCE hInstDLL, WORD wDataSeg, LPVOID lpReserved)
{
  return TRUE;
}
////////////////////////////////////////////////////////////////////////
// Graphics Function(s)
////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////
			// Display BackGround Function
			//////////////////////////////////////
DllExport void CALLBACK DisplayBG(HWNDdll hwnd)
{
	HDC PaintDC = GetDC(hwnd);

	BitBlt(PaintDC, MidX, MidY, GScreenW, GScreenH,
					GlobalDC_Bkg, 0, 0, SRCCOPY);

	ReleaseDC(hwnd, PaintDC);
}
			//////////////////////////////////////
			// Display Sprite Function
			//////////////////////////////////////
DllExport void CALLBACK DisplaySp(HWNDdll hwnd, UINT Sprite,int frame, int x, int y, int SpriteW, int delta)
{
	GetSprite(Sprite);
	BITMAP bm; 
	HDC PaintDC = GetDC(hwnd);

	GetObject(SpriteB, sizeof(bm), (LPSTR)&bm);
	int SpriteH = bm.bmHeight, SpriteP = bm.bmWidth;
	int SpPos = (SpriteW  + 1) * (frame - 1);

	HBITMAP H_Sprite = CreateCompatibleBitmap(PaintDC, SpriteW, SpriteH);
  HDC DC_Sprite = CreateCompatibleDC(PaintDC);
	HGDIOBJ OldH_Sprite =	SelectObject(PaintDC, H_Sprite);
   
  HBITMAP H_Temp = CreateCompatibleBitmap(PaintDC, SpriteW, SpriteH);
  HDC DC_Temp = CreateCompatibleDC(PaintDC);
	HGDIOBJ OldH_Temp =	SelectObject(DC_Temp, H_Temp);

//	MaskBlt(PaintDC, xPos, yPos, SpriteW, SpriteH, 
//			DC_Bkg, SpPos, 0, SpMask, SpPos, 0, SRCAND);
int startX = 0, globalX = 0, startY = 0;
	if(delta > 0)
		{
		startX	= x - delta + MidX;
		globalX	= x - delta;
		startY	= y + MidY;
		}
	else if(delta < 0)
		{
		startX	= x + SpriteW + MidX;
		globalX	= x + SpriteW;
		startY	= y + MidY;
		}

	if(x <= 0)
		{
		SpriteW += x;
		SpPos += (-1)*x;
		x = 0;
		}
	if((x+SpriteW) >= XMAX)
		{
		SpriteW = XMAX - x;
		if(SpriteW == 0)
			SpriteW = 1;
		}

// Clean up
	BitBlt(PaintDC, startX, startY, Abs(delta), SpriteH, 
					GlobalDC_Bkg, globalX, y, SRCCOPY);
// Copy BackGround to Temp
	BitBlt(DC_Temp, 0, 0, SpriteW, SpriteH, GlobalDC_Bkg, x, y, SRCCOPY); 
// Copy SpMask to Sprite DC
	SelectObject(DC_Sprite, SpriteM);
// ANDcopy Sprite DC to Temp
	BitBlt(DC_Temp, 0, 0, SpriteW, SpriteH, DC_Sprite, SpPos, 0, SRCAND); 
// Copy SpBitmap to Sprite DC
	SelectObject(DC_Sprite, SpriteB);
// ORcopy Sprite DC to Temp
  BitBlt(DC_Temp, 0, 0, SpriteW, SpriteH, DC_Sprite, SpPos, 0, SRCPAINT);
// Copy Temp to Paint DC
	BitBlt(PaintDC, x + MidX, y + MidY, SpriteW, SpriteH, DC_Temp, 0, 0, SRCCOPY);
	ReleaseDC(hwnd, PaintDC);
    	
	SelectObject(DC_Sprite, OldH_Sprite);
	DeleteObject(H_Sprite);
	DeleteDC(DC_Sprite);
     
	SelectObject(DC_Temp, OldH_Temp);
	DeleteObject(H_Temp);
	DeleteDC(DC_Temp);   
}
			//////////////////////////////////////
			// Load Sprites Function
			//////////////////////////////////////
DllExport void CALLBACK LoadSprites(void)
{
	HINSTANCE hInst = LoadLibrary("levels.dll");
if((l.number == P1_VS_P2) || (l.number == TITLE))
	{
	SpriteP1  = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P1));
	SpriteP1M = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P1M));
	SpriteP2  = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P2));
	SpriteP2M = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P2M));
	SpriteEB	= LoadBitmap(hInst, MAKEINTRESOURCE(IDS_EB));
	SpriteEBM	= LoadBitmap(hInst, MAKEINTRESOURCE(IDS_EBM));
	}
else if(l.number == P1_VS_COM )
	{
	SpriteP1  = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P1));
	SpriteP1M = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P1M));
	SpriteP2  = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_COM));
	SpriteP2M = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P2M));
	SpriteEB	= LoadBitmap(hInst, MAKEINTRESOURCE(IDS_EB));
	SpriteEBM	= LoadBitmap(hInst, MAKEINTRESOURCE(IDS_EBM));
	}

if((EnergyP1 >= MAXHIT*(percent)) && (EnergyP2 <= 0))
	{
	SpriteP1  = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P1));
	SpriteP1M = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P1M));
	SpriteP2	= LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P2DEAD));
	SpriteP2M	= LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P2MDEAD));
	}
else if((EnergyP2 >= MAXHIT*(percent)) && (EnergyP1 <= 0))
	{
	SpriteP1	= LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P1DEAD));
	SpriteP1M	= LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P1MDEAD));
	if(c.player == P2)
		SpriteP2  = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P2));
	else if(c.player == COM)
		SpriteP2  = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_COM));
	SpriteP2M = LoadBitmap(hInst, MAKEINTRESOURCE(IDS_P2M));
	}
}
			//////////////////////////////////////
			// Compile Bitmaps Function
			//////////////////////////////////////
DllExport void CompileBitmaps(HWNDdll hwnd)
{
	BITMAP bm; 
	HINSTANCE hInst = LoadLibrary("levels.dll");
	HDC PaintDC = GetDC(hwnd);

	GlobalH_Bkg = CreateCompatibleBitmap(PaintDC, ScreenW, ScreenH);
	GlobalDC_Bkg = CreateCompatibleDC(PaintDC);
	GlobalOldH_Bkg = SelectObject(GlobalDC_Bkg, GlobalH_Bkg);
	int n = 0;

	for(PGRAPHIC tempg = pg; tempg != (PGRAPHIC)0xcdcdcdcd ; tempg = tempg->next)
	{
		TempBitmap  = LoadBitmap(hInst, MAKEINTRESOURCE(tempg->bitmap));
		GetObject(TempBitmap, sizeof(bm), (LPSTR)&bm);
		BitmapY = bm.bmHeight;
		BitmapX = bm.bmWidth;

		HDC DC_Bkg = CreateCompatibleDC(PaintDC);
		HGDIOBJ HB_Bkg = SelectObject(DC_Bkg, TempBitmap); 

		BitBlt(GlobalDC_Bkg, tempg->xPos, tempg->yPos,
						BitmapX, BitmapY, DC_Bkg, 0, 0, SRCCOPY);

		SelectObject(DC_Bkg, HB_Bkg);
		DeleteDC(DC_Bkg);
		n++;
	}
	ReleaseDC(hwnd, PaintDC);
}
			//////////////////////////////////////
			// Get Sprite Function
			//////////////////////////////////////
void GetSprite(UINT Sprite)
{
	switch(Sprite)	{
		case IDS_P1:	{
			SpriteB = SpriteP1;
			SpriteM = SpriteP1M;
		}	break;
		case IDS_P2:	{
			SpriteB = SpriteP2;
			SpriteM = SpriteP2M;
		}	break;
			case IDS_COM:	{
			SpriteB = SpriteP2;
			SpriteM = SpriteP2M;
		}	break;
			case IDS_EB:	{
			SpriteB = SpriteEB;
			SpriteM = SpriteEBM;
		}	break;
			case IDS_P1DEAD:	{
			SpriteB = SpriteP1;
			SpriteM = SpriteP1M;
		}	break;
			case IDS_P2DEAD:	{
			SpriteB = SpriteP2;
			SpriteM = SpriteP2M;
		}	break;
	}
}
			//////////////////////////////////////
			// Absolute Value Function
			//////////////////////////////////////
int Abs(int value)
{
	if(value >= 0)
		return value;
	else if(value < 0)
		return (-1)*(value);
	else
		return 0;
}
			//////////////////////////////////////
			// Clean Bitmaps From RAM Function
			//////////////////////////////////////
DllExport void CALLBACK DelBitmaps(void)
{
	DeleteObject(SpriteB);
	DeleteObject(SpriteM);
	DeleteObject(SpriteP1);
	DeleteObject(SpriteP1M);
	DeleteObject(SpriteP2);
	DeleteObject(SpriteP2M);
	DeleteObject(SpriteEB);
	DeleteObject(SpriteEBM);
	DeleteObject(TempBitmap);
	SelectObject(GlobalDC_Bkg, GlobalOldH_Bkg);
	DeleteObject(GlobalH_Bkg);
	DeleteDC(GlobalDC_Bkg);
}