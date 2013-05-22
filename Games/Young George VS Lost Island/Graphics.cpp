////////////////////////////////////////////////////////////////////////
//	Program Name:	Graphics.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Graphics File
//	Date: 
////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include "E:\My Code\Young George VS Lost Island\YoungGeroge.h"
#include "Graphics.h"

//////////////////////////////////////////////////
// 								Misc Functions								//
//////////////////////////////////////////////////
			//////////////////////////////////////
			// CompileBitmap Function
			//////////////////////////////////////
HDC CompileBitmap(HWND hwnd, LPLEVEL level)
{
HDC hdc = GetDC(hwnd);

HBITMAP	bitmap			= CreateCompatibleBitmap(hdc, XMAX, YMAX);
HDC			BitHdc			= CreateCompatibleDC(hdc);
HGDIOBJ	Old_BitHdc	=	SelectObject(BitHdc, bitmap);

for(UINT i = 0; level->bitmapNum > i; i++)
	{
HDC			TempHdc			= CreateCompatibleDC(hdc);
HGDIOBJ	Old_TempHdc	=	SelectObject(TempHdc, level->lBitmapA[i].bitmap);

BitBlt(BitHdc, 
			 level->lZoneA[level->lBitmapA[i].zNum].x1, 
			 level->lZoneA[level->lBitmapA[i].zNum].y1, 
			 level->lZoneA[level->lBitmapA[i].zNum].w, 
			 level->lZoneA[level->lBitmapA[i].zNum].h, 
			 TempHdc, 0, 0, SRCCOPY);

SelectObject(TempHdc, Old_TempHdc);
DeleteDC(TempHdc);

ReleaseDC(hwnd, hdc);
	}
return BitHdc;
}
			//////////////////////////////////////
			// CompileSprite Function
			//////////////////////////////////////
void CompileSprite(HWND hwnd, HDC origBkgHdc, LPLEVEL level)
{
HDC bkgHdc = GetDC(hwnd);
UINT j = 0;
/*	check for collision
COLSPRITE cSprite;
HBITMAP	blackBit			= CreateCompatibleBitmap(origBkgHdc, XMAX, YMAX);
HDC			blackHdc			= CreateCompatibleDC(origBkgHdc);
HGDIOBJ	Old_blackHdc	=	SelectObject(blackHdc, blackBit);
BitBlt(blackHdc, 0, 0, XMAX, YMAX, origBkgHdc, 0, 0, BLACKNESS);
spriteA[0]->cSprite.hdcBkg = blackHdc;
for(i = 0; ; i++)
	{
		SelectObject(hdcM, spriteA[i]->spriteM);
		CheckCollision(spriteA[i]->cSprite.hdcBkg , hdcM, spriteA, i);
	}
*/
/*
//	clean up from old sprite
while(level->lSpriteA[j].oldSprite != (POLDSPRITE)0xcdcdcdcd)
	{
	if(level->lSpriteA[j].zOrder == j)
		{
		if(((level->lSpriteA[j].oldSprite->rt.x != level->lSpriteA[j].rt.x) ||
				(level->lSpriteA[j].oldSprite->rt.y != level->lSpriteA[j].rt.y)) &&
				(level->lSpriteA[j].oldSprite != (POLDSPRITE)0xcdcdcdcd) )
			{
			BitBlt(bkgHdc,	level->lSpriteA[j].oldSprite->rt.x, 
											level->lSpriteA[j].oldSprite->rt.y, 
											level->lSpriteA[j].oldSprite->rt.w, 
											level->lSpriteA[j].oldSprite->rt.h, 
											level->lSpriteA[j].oldSprite->spriteHdc, 
											0, 0, SRCCOPY);
			}
		j++;
		}
	else zOrderSort(level);
	}
//	copy screen from new to old sprite for clean up
j = 0;
while(level->spriteNum > j)
{
if(level->lSpriteA[j].oldSprite != (POLDSPRITE)0xcdcdcdcd)
	 {
		HBITMAP	bitM			= CreateCompatibleBitmap(origBkgHdc, level->lSpriteA[j].rt.w, level->lSpriteA[j].rt.h);
		level->lSpriteA[j].oldSprite->spriteHdc	= CreateCompatibleDC(origBkgHdc);
		HGDIOBJ	Old_hdcM	=	SelectObject(level->lSpriteA[j].oldSprite->spriteHdc, bitM);

			level->lSpriteA[j].oldSprite->rt.x = level->lSpriteA[j].rt.x;
			level->lSpriteA[j].oldSprite->rt.y = level->lSpriteA[j].rt.y;
			level->lSpriteA[j].oldSprite->rt.w = level->lSpriteA[j].rt.w;
			level->lSpriteA[j].oldSprite->rt.h = level->lSpriteA[j].rt.h;

			BitBlt(level->lSpriteA[j].oldSprite->spriteHdc,
						0, 0, level->lSpriteA[j].rt.w, level->lSpriteA[j].rt.h, origBkgHdc, 
						level->lSpriteA[j].rt.x, level->lSpriteA[j].rt.y, SRCCOPY);
		SelectObject(hdcM, level->lSpriteA[j].spriteM);

			BitBlt(level->lSpriteA[j].oldSprite->spriteHdc,
						0, 0, level->lSpriteA[j].rt.w, level->lSpriteA[j].rt.h, hdcM, 
						0, 0, SRCPAINT); 
		j++;
	}
else 
	{
	level->lSpriteA[j].oldSprite = (POLDSPRITE)malloc(sizeof(OLDSPRITE));
	level->lSpriteA[j].oldSprite->spriteHdc = (HDC)malloc(sizeof(HDC));
	}
}
*/
//	main graphics loop  level->lBitmapA[0].rt.w
	HBITMAP	BkgTemp					= CreateCompatibleBitmap(origBkgHdc, 
															level->lZoneA[level->lBitmapA[0].zNum].w, 
															level->lZoneA[level->lBitmapA[0].zNum].h);
	HDC			BkgTempHdc			= CreateCompatibleDC(origBkgHdc);
	HGDIOBJ	Old_BkgTempHdc	=	SelectObject(BkgTempHdc, BkgTemp);
	BitBlt(BkgTempHdc, 0, 0, 
				level->lZoneA[level->lBitmapA[0].zNum].w, 
				level->lZoneA[level->lBitmapA[0].zNum].h, 
				origBkgHdc, 0, 0, SRCCOPY);

j = 0;
while(level->spriteNum > j)
{
int SpXPos = (level->lZoneA[level->lSpriteA[j].zNum].w)*(level->lSpriteA[j].cel), SpYPos = 0;
int x = level->lZoneA[level->lSpriteA[j].zNum].x1, y = level->lZoneA[level->lSpriteA[j].zNum].y1,
		w = level->lZoneA[level->lSpriteA[j].zNum].w,	 h = level->lZoneA[level->lSpriteA[j].zNum].h;
//	out side view area test and resolve
/*
	if(x <= 0)
		{
		w += x;
		SpXPos += (-1)*x;
		x = 0;
		}
	else if((x+w) >= XMAX)
		w = XMAX - x;
	if(y <= 0)
		{
		h += y;
		SpYPos += (-1)*y;
		y = 0;
		}
	else if((y+h) >= YMAX)
		h = YMAX - y;
*/
//	out side view area test and resolve
		////////////////////////////////////
		//	Store zOrder displaying
		/////////////////////////////////////
if(level->lSpriteA[j].zOrder == j)
		{
//	create SpTemp
		HBITMAP	SpTemp			= CreateCompatibleBitmap(bkgHdc, w, h);
		HDC			SpTempHdc			= CreateCompatibleDC(bkgHdc);
		HGDIOBJ	Old_SpTempHdc	=	SelectObject(bkgHdc, SpTemp);
//	create bkgtemp
/*
		HBITMAP	BkgTemp			= CreateCompatibleBitmap(bkgHdc, w, h);
		HDC			BkgTempHdc			= CreateCompatibleDC(bkgHdc);
		HGDIOBJ	Old_BkgTempHdc	=	SelectObject(BkgTempHdc, BkgTemp);
//	copy background to bkgtemp
		BitBlt(BkgTempHdc, 0, 0, w, h,
					 bkgHdc, x, y, SRCCOPY);
*/

//	bitmap mask ANDcopy to bkgtemp
		SelectObject(SpTempHdc, level->lSpriteA[j].spriteM);
		BitBlt(BkgTempHdc, x, y, w, h,
					 SpTempHdc, SpXPos, SpYPos, SRCAND);
//	bitmap ORcopy to bkgtemp
		SelectObject(SpTempHdc, level->lSpriteA[j].sprite);
		BitBlt(BkgTempHdc, x, y, w, h, 
					 SpTempHdc, SpXPos, SpYPos, SRCPAINT);
//	copy bkgtemp to background
/*
		BitBlt(bkgHdc, x, y, w, h, 
					 BkgTempHdc, 0, 0, SRCCOPY);
*/
//	mem cleanup
		SelectObject(SpTempHdc, Old_SpTempHdc);
		DeleteObject(SpTemp);
		DeleteDC(SpTempHdc);
		j++;
		}
	else zOrderSort(level);
}
		/////////////////////////////////////
		//	Display zOrder displaying
		/////////////////////////////////////
j = 0;
while(level->spriteNum > j)
{
int x, y,	
		w = (level->lZoneA[level->lSpriteA[j].zNum].w + level->lSpriteA[j].xDelta),
		h = (level->lZoneA[level->lSpriteA[j].zNum].h + level->lSpriteA[j].yDelta);

if(level->lSpriteA[j].xDelta >= 0)
	x = (level->lZoneA[level->lSpriteA[j].zNum].x1 - level->lSpriteA[j].xDelta);
else if(level->lSpriteA[j].xDelta < 0)
	{
	x = level->lZoneA[level->lSpriteA[j].zNum].x1;
	w = (level->lZoneA[level->lSpriteA[j].zNum].w - level->lSpriteA[j].xDelta);
	}
if(level->lSpriteA[j].yDelta >= 0)
	y = (level->lZoneA[level->lSpriteA[j].zNum].y1 - level->lSpriteA[j].yDelta);
else if(level->lSpriteA[j].yDelta < 0)
	{
	y = level->lZoneA[level->lSpriteA[j].zNum].y1;
	h = (level->lZoneA[level->lSpriteA[j].zNum].h - level->lSpriteA[j].yDelta);
	}

//	out side view area test and resolve
/*
	if(x <= 0)
		{
		w += x;
		x = 0;
		}
	else if((x+w) >= XMAX)
		w = (XMAX - x);
	if(y <= 0)
		{
		h += y;
		y = 0;
		}
	else if((y+h) >= YMAX)
		h = (YMAX - y);
*/
//	out side view area test and resolve
	BitBlt(bkgHdc, x, y, w, h, BkgTempHdc, x, y, SRCCOPY);
j++;
}

	SelectObject(BkgTempHdc, Old_BkgTempHdc);
	DeleteObject(BkgTemp);
	DeleteDC(BkgTempHdc);
/*
SelectObject(blackHdc, Old_blackHdc);
DeleteObject(blackBit);
DeleteDC(blackHdc);
DeleteDC(hdcM);
*/
ReleaseDC(hwnd, bkgHdc);
}
			//////////////////////////////////////
			// DisplayBG Function
			//////////////////////////////////////
HDC DisplayBG(HWND hwnd, HDC bitmap)
{
RECT r;
GetWindowRect(hwnd, &r);
HDC PaintDC = GetDC(hwnd);
BitBlt(PaintDC, 0, 0, r.right, r.bottom, bitmap, 0, 0, SRCCOPY);
ReleaseDC(hwnd, PaintDC);
return PaintDC;
}
			//////////////////////////////////////
			// CheckPath Function
			//////////////////////////////////////
BOOL CheckPath(HWND hwnd, LPLEVEL level, UINT spriteNum, UINT msg, int dS)
{
HDC hdc			= GetDC(hwnd);
HDC	TempHdc	= CreateCompatibleDC(hdc);
HGDIOBJ	Old_TempHdc	=	SelectObject(TempHdc, level->bkgPath);

if(msg == HORZ)
	{
	UINT x =	level->lZoneA[level->lSpriteA[spriteNum].zNum].x1 + 
						level->lSpriteA[spriteNum].xHotspot +
						(dS)*(level->lSpriteA[spriteNum].xDelta);
	UINT y =	level->lZoneA[level->lSpriteA[spriteNum].zNum].y1 + 
						level->lSpriteA[spriteNum].yHotspot;
	COLORREF	rgb1 = GetPixel(TempHdc, x, y),
						rgb2 = RGB(255, 255, 255);
	if(rgb1 == rgb2)
		{
		SelectObject(TempHdc, Old_TempHdc);
		DeleteDC(TempHdc);
		ReleaseDC(hwnd, hdc);
		return TRUE;
		}
	else 
		{
		SelectObject(TempHdc, Old_TempHdc);
		DeleteDC(TempHdc);
		ReleaseDC(hwnd, hdc);
		return FALSE;
		}
	}
else if(msg == VERT)
	{
	UINT x =	level->lZoneA[level->lSpriteA[spriteNum].zNum].x1 + 
						level->lSpriteA[spriteNum].xHotspot;
	UINT y =	level->lZoneA[level->lSpriteA[spriteNum].zNum].y1 + 
						level->lSpriteA[spriteNum].yHotspot +
						(dS)*(level->lSpriteA[spriteNum].yDelta);
	if((GetPixel(level->bkgPath, x, y)) == (RGB(255, 255, 255)))
		{
		SelectObject(TempHdc, Old_TempHdc);
		DeleteDC(TempHdc);
		ReleaseDC(hwnd, hdc);
		return TRUE;
		}
	else 
		{
		SelectObject(TempHdc, Old_TempHdc);
		DeleteDC(TempHdc);
		ReleaseDC(hwnd, hdc);
		return FALSE;
		}
	}
else
	{
	SelectObject(TempHdc, Old_TempHdc);
	DeleteDC(TempHdc);
	ReleaseDC(hwnd, hdc);
	return FALSE;
	}
}
			//////////////////////////////////////
			// CheckCollision Function
			//////////////////////////////////////
/*
void CheckCollision(HDC hdcBkg, HDC hdcM, LPSPRITEARRAY	spriteA[], UINT spriteNum)
{
int i;

HBITMAP bitmap1		= CreateCompatibleBitmap(hdcBkg, spriteA[spriteNum]->w, spriteA[spriteNum]->h);
HDC hdc1					= CreateCompatibleDC(hdcBkg);
HGDIOBJ Old_hdc1	=	SelectObject(hdc1, bitmap1);

HBITMAP bitmap2		= CreateCompatibleBitmap(hdcBkg, spriteA[spriteNum]->w, spriteA[spriteNum]->h);
HDC hdc2					= CreateCompatibleDC(hdcBkg);
HGDIOBJ Old_hdc2	=	SelectObject(hdc2, bitmap2);

//copy bitmapBkg from bitmap1
BitBlt(hdc1, 0, 0, spriteA[spriteNum]->w, spriteA[spriteNum]->h, 
			 hdcBkg, spriteA[spriteNum]->xPos, spriteA[spriteNum]->yPos, SRCCOPY);
//copy bitmapBkg to bitmap2
BitBlt(hdc2, 0, 0, spriteA[spriteNum]->w, spriteA[spriteNum]->h, 
			 hdcBkg, spriteA[spriteNum]->xPos, spriteA[spriteNum]->yPos, SRCCOPY);
//put bitmapM onto bitmap2
BitBlt(hdc2, 0, 0, spriteA[spriteNum]->w, spriteA[spriteNum]->h, 
			 hdcM, 0, 0, SRCAND);
//compare bitmap1 and bitmap2
if(hdc1 != hdc2)
	{
	BitBlt(hdcM, 0, 0, spriteA[spriteNum]->w, spriteA[spriteNum]->h, 
				 hdcM, 0, 0, NOTSRCCOPY);
	BitBlt(hdc1, 0, 0, spriteA[spriteNum]->w, spriteA[spriteNum]->h, 
				 hdcM, 0, 0, SRCAND);

	COLORREF black		= RGB(0, 0, 0);
	BOOL exitloop			= FALSE;
	POINT p;
	RECT r;
	UINT j, k;
	for(j = 0; j < spriteA[spriteNum]->w ; j++)
		{
			for(k = 0; k < spriteA[spriteNum]->h; k++)
				{
					if(GetPixel(hdc1, j, k) != black)
						{
						exitloop = TRUE;
						break;
						}
				}
			if(exitloop == TRUE)
				break;
		}

	p.x = (LONG)(j + spriteA[spriteNum]->xPos);
	p.y = (LONG)(k + spriteA[spriteNum]->yPos);
	spriteA[spriteNum]->cSprite.xPos = p.x;
	spriteA[spriteNum]->cSprite.yPos = p.y;
	j = 0;
	for(i = 0; (spriteA[spriteNum]->zOrder > spriteA[i]->zOrder) && (spriteA[i]->sprite != 0); i++)
		{
			r.left		= spriteA[i]->xPos;
			r.right		= spriteA[i]->xPos + spriteA[i]->w;
			r.top			= spriteA[i]->yPos;
			r.bottom	=	spriteA[i]->yPos + spriteA[i]->h;
		if(PtInRect((PRECT)&r, p) != FALSE)
			{
				spriteA[spriteNum]->cSprite.SpriteNum[j] = i;
				j++;
			}
		}
	}
else 	spriteA[spriteNum]->cSprite.SpriteNum[0] = -1;

BitBlt(hdcBkg, spriteA[spriteNum]->xPos, spriteA[spriteNum]->yPos, 
			 spriteA[spriteNum]->w, spriteA[spriteNum]->h, hdc2, 0, 0, SRCCOPY);

if(spriteA[spriteNum + 1]->cSprite.hdcBkg != (HBITMAP)0xcdcdcdcd)
	spriteA[spriteNum + 1]->cSprite.hdcBkg = hdcBkg;


SelectObject(hdc1, Old_hdc1);
DeleteObject(bitmap1);
DeleteDC(hdc1);

SelectObject(hdc2, Old_hdc2);
DeleteObject(bitmap2);
DeleteDC(hdc2);
}
*/
			//////////////////////////////////////
			// zOrderSort Function
			//////////////////////////////////////
void zOrderSort(LPLEVEL level)
{
LPSPRITEARRAY temp_sA[MAXARRAY];
UINT i = 0, j = 0, k = 0;
while(level->spriteNum > i)
	{
	for(j = 0; level->spriteNum < j; j++)
		{
		if(level->lSpriteA[j].zOrder == i)
			{
			temp_sA[k] = &(level->lSpriteA[j]);
			k++;
			break;
			}
		}
	i++;
	}
for(i = 0; level->spriteNum > i; i++)
	{
		level->lSpriteA[i] = *(temp_sA[i]);
	}
}
