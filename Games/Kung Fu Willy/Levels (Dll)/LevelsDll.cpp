////////////////////////////////////////////////////////////////////////
//  Program Name: LevelsDll.cpp
//  Programmer: Joseph Sutton
//  Description: DLL Levels File
//  Date:
////////////////////////////////////////////////////////////////////////
#define STRICT
#include <windows.h>
#include <stdio.h>
#include <string.h>   
// For Random Function
	#include <iostream.h>
	#include <algorithm>
	#include <functional>
	#include <vector>         
#include <mmsystem.h>
#include <vfw.h>
#include <Game.h>
#include "resource.h"
#include "Sound.h"
#include "Controls.h"
#include "Graphics.h"
#include "LevelsDll.h"

			//////////////////////////////////////
			// DLLMain
			//////////////////////////////////////
BOOL APIENTRY DllEntryPoint(HINSTANCE hInstDLL, WORD wDataSeg, LPVOID lpReserved)
{
  return TRUE;
}
////////////////////////////////////////////////////////////////////////
//  Title Start/Mid/End
////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////
			// Title Start
			//////////////////////////////////////
DllExport void TitleStart(HWNDdll hwnd, HINST hInst)
{
	int PWidth1  = MidX + 98,
			PHight   = MidY + 312,
			PWidth2  = MidX + 417,
			PbWidth  = 125, 	PbHight = 35;
// Play Title Song
	sec = 0;
// P1_VS_COM Button
	hwndP1 = CreateWindowEx(WS_EX_TOPMOST, "button", "One Player", 
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 
		PWidth1, PHight, PbWidth, PbHight, hwnd,
		HMENU(ID_P1BUTTON), hInst, NULL);
// P1_VS_P2 Button
	hwndP2 = CreateWindowEx(WS_EX_TOPMOST, "button", "Two Players", 
		WS_CHILD | WS_VISIBLE, 
		PWidth2, PHight, PbWidth, PbHight, hwnd,
		HMENU(ID_P2BUTTON), hInst, NULL);
	ButtonUpdate(hwnd, hInst);
	i = (-1)*((int)SpriteSize + 4);
	j = 644;
	k = 1;
	delta = 6;
	l.stat = MID;
	TimeRate = 0;
}
			//////////////////////////////////////
			// Title Middle
			//////////////////////////////////////
DllExport void TitleMid(HWNDdll hwnd, HINST hInst)
{
LoadSprites();
if( i	!= (GScreenW)*(0.50) - SpriteSize && j != (GScreenW)*(0.50))
	WalkOn(hwnd, IDS_P1, IDS_P2);
// Display Sprite Random direction
	else 
		{
			TimeRate = 200;
			DisplaySp(hwnd, IDS_P1, qRandom(1, 8), i, (GScreenH)*(0.40), SpriteSize, delta);
			DisplaySp(hwnd, IDS_P2, qRandom(1, 8), j, (GScreenH)*(0.40), SpriteSize, (-1)*delta);
		}
}
			//////////////////////////////////////
			// Title End
			//////////////////////////////////////
DllExport void TitleEnd(HWNDdll hwnd, HINST hInst)
{
	if(l.number == P1_VS_COM)
		WAVE(IDW_TITLE1);
	if(l.number == P1_VS_P2)
		WAVE(IDW_TITLE2);
	DestroyWindow(hwndP1);
	DestroyWindow(hwndP2);
	i = rRandom(0,4);
	switch(i)	{
		case 0:	{
			File = IDM_L1;
			}	break;
		case 1:	{
			File = IDM_L1;
			}	break;
		case 2:	{
			File = IDM_L2;
			}	break;
		case 3:	{
			File = IDM_L3;
			sec = 3;
			}	break;
		case 4:	{
			File = IDM_L3;
			sec = 3;
			}	break;
	}
	MIDI(STOP, hwnd);
	l.stat = START;
	m = 0;
	delta = 6;
	TimeRate = 0;
	SetTimer(hwnd, ID_GTIMER, GTimeRate, TimerProc);
}
////////////////////////////////////////////////////////////////////////
//  Player 1 VS Player 2 Start/Mid/End
////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////
			// P1 VS P2 Start
			//////////////////////////////////////
DllExport void PvsPStart(HWNDdll hwnd, HINST hInst)
{
	if(m == 0)	{
		LoadSprites();
		LoadBitmaps();
		CompileBitmaps(hwnd);
		DisplayBG(hwnd);
		MIDI(PLAY, hwnd);
		ButtonUpdate(hwnd, hInst);
		i = (-1)*((int)SpriteSize + 4);
		j = 644;
		k = 1;
		m = 1;	}
if( i	!= (GScreenW)*(0.50) - SpriteSize && j != (GScreenW)*(0.50))
	WalkOn(hwnd, IDS_P1, IDS_P2);
// Display Sprite Random direction
	else 
		{
			j = 2;
			k = 2;
			c.player = P1;
			fight = TRUE;
			l.stat = MID;
			endround = TRUE;
			EnergyP1 = MAXHIT;
			EnergyP2 = MAXHIT;
		}
}
			//////////////////////////////////////
			// P1 VS P2 Middle
			//////////////////////////////////////
DllExport void PvsPMid(HWNDdll hwnd, HINST hInst)
{
FLF(hwnd, hInst);
}
			//////////////////////////////////////
			// P1 VS P2 End
			//////////////////////////////////////
DllExport void PvsPEnd(HWNDdll hwnd, HINST hInst)
{
	if(m == 0)
		{
			DisplayBG(hwnd);
			MIDI(PLAY, hwnd);

			i = IDS_P1;
			j = IDS_P2;
			if(c.player == P1)
				{
					j = IDS_P2DEAD;
					n = 12;
				}
			else if(c.player == P2)
				{
					i = IDS_P1DEAD;
					n = 1;
				}
			m = 1;
			k = 1;
			GTimeRate = 0;
			gtimer = TRUE;
		}
	else if(fight == TRUE && gtimer == TRUE)
		{
		DisplaySp(hwnd, i, m, 
			(GScreenW)*(0.50) - 41, (GScreenH)*(0.40), SpriteSize, 0);
		DisplaySp(hwnd, j, n,
			(GScreenW)*(0.50), (GScreenH)*(0.40), SpriteSize, 0);

		if(c.JB == 1 && c.player == P1)
			{
			k = 0;
			GTimeRate = 500;
			m = 3;
			}
		else if(c.JB == 1 && c.player == P2)
			{
			k = 0;
			GTimeRate = 500;
			n = 3;
			c.JB = 0;
			}
		
		if((m == 12 && i == IDS_P1DEAD) || 
				(n == 1 && j == IDS_P2DEAD))
			{
				fight = TRUE;
				QA(hwnd, "PLAY AGAIN?");
			}
		else if(c.JD != CENTER)
			{
				fight = FALSE;
				QA(hwnd, "Play again?");
			}

		if(k == 0)
			{
			if(i == IDS_P1DEAD)
				m++;
			else if(j == IDS_P2DEAD)
				n--;
			WAVE(IDW_END2B);
			}
		SetTimer(hwnd, ID_GTIMER, GTimeRate, TimerProc);
		gtimer = FALSE;
		}
}
////////////////////////////////////////////////////////////////////////
//  Player 1 VS Computer Start/Mid/End
////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////
			// P1 VS Com Start
			//////////////////////////////////////
DllExport void PvsCStart(HWNDdll hwnd, HINST hInst)
{
	if(m == 0)	{
		LoadSprites();
		LoadBitmaps();
		CompileBitmaps(hwnd);
		DisplayBG(hwnd);
		MIDI(PLAY, hwnd);
		ButtonUpdate(hwnd, hInst);
		i = (-1)*((int)SpriteSize + 4);
		j = 644;
		k = 1;
		m = 1;	}
if( i	!= (GScreenW)*(0.50) - SpriteSize && j != (GScreenW)*(0.50))
	WalkOn(hwnd, IDS_P1, IDS_COM);
// Display Sprite Random direction
	else 
		{
			j = 2;
			k = 2;
			fight = TRUE;
			c.player = COM;
			l.stat = MID;
			endround = TRUE;
			EnergyP1 = MAXHIT;
			EnergyP2 = MAXHIT;
		}
}
			//////////////////////////////////////
			// P1 VS Com Middle
			//////////////////////////////////////
DllExport void PvsCMid(HWNDdll hwnd, HINST hInst)
{
FLF(hwnd, hInst);
}
			//////////////////////////////////////
			// P1 VS Com End
			//////////////////////////////////////
DllExport void PvsCEnd(HWNDdll hwnd, HINST hInst)
{
	if(m == 0)
		{
			DisplayBG(hwnd);
			MIDI(PLAY, hwnd);

			i = IDS_P1;
			j = IDS_COM;
			if(c.player == P1)
				{
					j = IDS_P2DEAD;
					n = 12;
				}
			else if(c.player == COM)
				{
					i = IDS_P1DEAD;
					n = 1;
				}
			m = 1;
			k = 1;
			GTimeRate = 0;
			gtimer = TRUE;
		}
	else if(fight == TRUE && gtimer == TRUE)
		{
		DisplaySp(hwnd, i, m, 
			(GScreenW)*(0.50) - 41, (GScreenH)*(0.40), SpriteSize, 0);
		DisplaySp(hwnd, j, n,
			(GScreenW)*(0.50), (GScreenH)*(0.40), SpriteSize, 0);

		if(c.JB == 1 && c.player == P1)
			{
			k = 0;
			GTimeRate = 500;
			m = 3;
			}
		else if(c.player == COM)
			{
			k = 0;
			GTimeRate = 500;
			n = 3;
			c.JB = 0;
			}

		if((m == 12 && i == IDS_P1DEAD) || 
				(n == 1 && j == IDS_P2DEAD))
			{
				fight = TRUE;
				QA(hwnd, "Play again?");
			}
		else if(c.JD != CENTER)
			{
				fight = FALSE;
				QA(hwnd, "Play again? LOSSER!");
			}

		if(k == 0)
			{
			if(i == IDS_P1DEAD)
				m++;
			else if(j == IDS_P2DEAD)
				n--;
			WAVE(IDW_END2B);
			}
		SetTimer(hwnd, ID_GTIMER, GTimeRate, TimerProc);
		gtimer = FALSE;
		}
}
////////////////////////////////////////////////////////////////////////
//  Random Function(s)
////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////
			// Quick Random Function
			//////////////////////////////////////
int qRandom(int StartSize, int EndSize)
{
	const int VECTOR_SIZE = EndSize - StartSize;
// Define a template class vector of int
  typedef vector<int> IntVector ;
//Define an iterator for template class vector of strings
  typedef IntVector::iterator IntVectorIt ;
  IntVector Numbers(VECTOR_SIZE) ;
  IntVectorIt start, end;
// Initialize vector Numbers
	int k2 = StartSize;
	for(int k1 = 0; k1 != VECTOR_SIZE; k1++)
		{
			Numbers[k1] = k2;
			k2++;
		}
  start = Numbers.begin() ;   // location of first
                              // element of Numbers
  end = Numbers.end() ;       // one past the location
                              // last element of Numbers
// shuffle the elements in a random order
	random_shuffle(start, end) ;
	return *start;
}
			//////////////////////////////////////
			// Quick Random Function
			//////////////////////////////////////
int rRandom(int StartSize, int EndSize)
{
	int temp1, temp2;
	SYSTEMTIME s;
	GetSystemTime(&s);
	temp2 = s.wMilliseconds;
	const int VECTOR_SIZE = EndSize - StartSize;
// Define a template class vector of int
  typedef vector<int> IntVector ;
//Define an iterator for template class vector of strings
  typedef IntVector::iterator IntVectorIt ;
  IntVector Numbers(VECTOR_SIZE) ;
  IntVectorIt start, end;
// Initialize vector Numbers
	int k2 = StartSize;
	for(int k1 = 0; k1 != VECTOR_SIZE; k1++)
		{
			Numbers[k1] = k2;
			k2++;
		}
  
	start = Numbers.begin();
  end = Numbers.end();
// shuffle the elements in a random order
	for(temp1 = 0; temp1 != temp2; temp1++)	{
			random_shuffle(start, end);	}

	return *start;
}
////////////////////////////////////////////////////////////////////////
//  Screen Function(s)
////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////
			// Middle Screen Function
			//////////////////////////////////////
DllExport void MidScreen(void)
{
	RECT Rect;
	GetWindowRect(GetDesktopWindow(), &Rect);
	ScreenW = Rect.right;
	ScreenH = Rect.bottom;
	GScreenW = 640;
	GScreenH = 480;

	MidX = (ScreenW)*(0.50) - (GScreenW)*(0.50);
	MidY = (ScreenH)*(0.50) - (GScreenH)*(0.50);
}
			//////////////////////////////////////
			// Reset Function
			//////////////////////////////////////
DllExport void Reset(HWNDdll hwnd)
{
//	MCIWndSetVolume(hwnd, 800);
	Difficulty(2);
	TimeRate = 0;
	MTimeRate = 0;
	l.number = TITLE;
	l.stat = START;
	c.player = COM;
	c.JD = CENTER;
	fight = TRUE;
	EnergyP1 = MAXHIT;
	EnergyP2 = MAXHIT;

	MidScreen();
  pg = (PGRAPHIC)malloc(sizeof(GRAPHIC));
	pg->bitmap = IDB_TITLE;
  pg->xPos = 0;
	pg->yPos = 0;
	CompileBitmaps(hwnd);
	File = IDM_TITLE;
	SetTimer(hwnd, ID_TIMER, TimeRate, TimerProc);
	SetTimer(hwnd, ID_MTIMER, MTimeRate, TimerProc);
}
			//////////////////////////////////////
			// Quit Function
			//////////////////////////////////////
DllExport void Quit(HWNDdll hwnd)
{
	HDC PaintDC = GetDC(hwnd);
	HBRUSH Brush = CreateSolidBrush(RGB(0,0,0));
	HBRUSH OldBrush = (HBRUSH)SelectObject(PaintDC, Brush);
	Rectangle(PaintDC, MidX, MidY, MidX + GScreenW, MidY + GScreenH);
	SelectObject(PaintDC, OldBrush);
	DeleteObject(Brush);
	ReleaseDC(hwnd, PaintDC);

	CDAudio(STOP, NULL);
	MIDI(STOP, hwnd);
	joyReleaseCapture(JOYSTICKID1);
	joyReleaseCapture(JOYSTICKID2);
	DelBitmaps();

	PostQuitMessage(0);
}
			//////////////////////////////////////
			// Walk On Function
			//////////////////////////////////////
void WalkOn(HWNDdll hwnd, UINT Sprite1, UINT Sprite2)
{
			switch(k)	{
				case	1:	{
					DisplaySp(hwnd, Sprite1, k, i, (GScreenH)*(0.40), SpriteSize, delta);
					DisplaySp(hwnd, Sprite2, k, j, (GScreenH)*(0.40), SpriteSize, (-1)*delta);
					k = 2;
					}	break;
				case 2:	{
					DisplaySp(hwnd, Sprite1, k, i, (GScreenH)*(0.40), SpriteSize, delta);
					DisplaySp(hwnd, Sprite2, k, j, (GScreenH)*(0.40), SpriteSize, (-1)*delta);
					k = 1;
					}	break;
			}
		i += delta, j -= delta;
}
			//////////////////////////////////////
			// Load Bitmaps Function
			//////////////////////////////////////
void LoadBitmaps(void)
{
	if(l.stat != END)
		{
			pg->xPos = 0;
			pg->yPos = 0;
			i = rRandom(0,4);
			switch(i)	
			{
				case 0:	
				{
					pg->bitmap = IDB_BK1;
				}	break;
				case 1:	
				{
					pg->bitmap = IDB_BK1;
				}	break;
				case 2:	
				{
					pg->bitmap = IDB_BK2;
				}	break;
				case 3:	
				{
					pg->bitmap = IDB_BK3;
				}	break;
				case 4:	
				{
					pg->bitmap = IDB_BK3;
				}	break;
			}
			PGRAPHIC pg1;
			pg1 = (PGRAPHIC)malloc(sizeof(GRAPHIC));
			pg1->xPos = 0;
			pg1->yPos = 0;
			pg1->bitmap = IDB_SB;
			pg->next = pg1;
//
			PGRAPHIC pg2;
			pg2 = (PGRAPHIC)malloc(sizeof(GRAPHIC));
			pg2->xPos = 320;
			pg2->yPos = 0;
			pg2->bitmap = IDB_SB;
			pg1->next = pg2;
//
			PGRAPHIC pg3;
			pg3 = (PGRAPHIC)malloc(sizeof(GRAPHIC));
			pg3->xPos = 22;
			pg3->yPos = 7;
			pg3->bitmap = IDB_SBP1;
			pg2->next = pg3;
//			
			PGRAPHIC pg4;
			pg4 = (PGRAPHIC)malloc(sizeof(GRAPHIC));
			if(l.number == P1_VS_P2)	
				{
					pg4->xPos = 320 + 21;
					pg4->yPos = 8;
					pg4->bitmap = IDB_SBP2;
					pg3->next = pg4;
				}
			else if(l.number == P1_VS_COM)
				{
					pg4->xPos = 320 + 4;
					pg4->yPos = 10;
					pg4->bitmap = IDB_SBCOM;
					pg3->next = pg4;
				}
			PGRAPHIC pg5;
			pg5 = (PGRAPHIC)malloc(sizeof(GRAPHIC));
			pg5->xPos = 0;
			pg5->yPos = (GScreenH)*(0.40) + 72;
			pg5->bitmap = IDB_FLOOR;
			pg4->next = pg5;	
		}
	else if(l.stat == END)
		{
			if(pg->bitmap == IDB_BK1)
				pg->bitmap = IDB_BK1D;
			else if(pg->bitmap == IDB_BK2)
				pg->bitmap = IDB_BK2D;
			else if(pg->bitmap == IDB_BK3)
				pg->bitmap = IDB_BK3D;
//
			PGRAPHIC pg1;
			pg1 = (PGRAPHIC)malloc(sizeof(GRAPHIC));
			pg1->xPos = 0;
			pg1->yPos = (GScreenH)*(0.40) + 72;
			pg1->bitmap = IDB_FLOOR;
			pg->next = pg1;
		}
}
			//////////////////////////////////////
			// Fight Loop Function
			//////////////////////////////////////
void FLF(HWNDdll hwnd, HINST hInst)
{
if(l.number == P1_VS_P2)
	i = IDS_P2;
else if(l.number == P1_VS_COM)
	i = IDS_COM;

if(c.JB == 1 && gtimer == FALSE && c.player != COM)
	{
	if(endround == TRUE)
		{
			EndRoundF(hwnd);
		}
	else if(fight == TRUE)
		{
		if(c.player == P1)
			{
			if(c.JD == UP)
					j = 5;
			else if(c.JD == DOWN)
					j = 7;
			else if(c.JD == LEFT || c.JD == RIGHT)
					j = 3;
			else
					j = 3;
			if(l.number == P1_VS_P2)
				c.player = P2;
			else if(l.number == P1_VS_COM)
				c.player = COM;
			}
		else if(c.player == P2)
			{
			if(c.JD == UP)
					k = 5;
			else if(c.JD == DOWN)
					k = 7;
			else if(c.JD == LEFT || c.JD == RIGHT)
					k = 3;
			else
					k = 3;
			c.player = P1;
			}
		c.JD = CENTER;
		fight = FALSE;
		}
	else if(fight == FALSE)
		{
		if(c.player == P1)
			{
			if(c.JD == UP)
					j = 6;
			else if(c.JD == DOWN)
					j = 8;
			else if(c.JD == LEFT || c.JD == RIGHT)
					j = 4;
			else
					j = 4;
			}
		else if(c.player == P2)
			{
			if(c.JD == UP)
					k = 6;
			else if(c.JD == DOWN)
					k = 8;
			else if(c.JD == LEFT || c.JD == RIGHT)
					k = 4;
			else
					k = 4;
			}
		endround = TRUE;
		fight = TRUE;
		}
	SetTimer(hwnd, ID_GTIMER, GTimeRate, TimerProc);
	}

else if(c.player == COM)
	{
	if(endround == TRUE)
		{
			EndRoundF(hwnd);
		}
	else if(fight == TRUE)
		{
			while(k == 1 || k == 2 || k == 4 || k == 6 || k == 8)
				k = rRandom(2, 8);
			c.player = P1;
			fight = FALSE;
		}
	else if(fight == FALSE)
		{
			while(k == 1 || k == 3 || k == 5 || k == 7 || k == 9)
				k = rRandom(3, 9);
			endround = TRUE;
			fight = TRUE;
		}
	SetTimer(hwnd, ID_GTIMER, GTimeRate, TimerProc);
	}

else if(gtimer == TRUE)
	{
	if(endround == TRUE)
		{
			EndRoundF(hwnd);
		}
	else if(fight == TRUE)
		{
			if(c.player == P1)
			{
				j = 3;
				if(l.number == P1_VS_P2)
					c.player = P2;
				else if(l.number == P1_VS_COM)
					c.player = COM;
			}
			else if(c.player == P2)
			{
				k = 3;
				c.player = P1;
			}
			fight = FALSE;
		}
	else if(fight == FALSE)
		{
			if(c.player == P1)
			{
				j = 4;
			}
			else if(c.player == P2)
			{
				k = 4;
			}
			endround = TRUE;
			fight = TRUE;
		}
	SetTimer(hwnd, ID_GTIMER, GTimeRate, TimerProc);
	}
// Player 1 Sprite
DisplaySp(hwnd, IDS_P1, j, 
		(GScreenW)*(0.50) - 41, (GScreenH)*(0.40), SpriteSize, delta);
// Player 2 or COM Sprite
DisplaySp(hwnd, i, k,
		(GScreenW)*(0.50), (GScreenH)*(0.40), SpriteSize, (-1)*delta);
// Player 1's Energy
DisplaySp(hwnd, IDS_EB, 1, 109, 6, EnergyP1, (-1)*hit);
// Player 2 or COM's Energy
DisplaySp(hwnd, IDS_EB, 1, 429, 6, EnergyP2, (-1)*hit); 
}
			//////////////////////////////////////
			// End Round Function
			//////////////////////////////////////
void EndRoundF(HWNDdll hwnd)
{
// Player 1
			if( (j == 7 && k == 4) || (j == 7 && k == 8) || 
					(j == 5 && k == 4) || (j == 5 && k == 6) || 
					(j == 3 && k == 8) || (j == 3 && k == 6))
			{
				EnergyP2 -= hit;
				if(l.number == P1_VS_P2)
					WAVE(IDW_HIT2);
				else if(l.number == P1_VS_COM)
					WAVE(IDW_HIT3);
			}
// Player 2 or COM
			else	if( (k == 7 && j == 4) || (k == 7 && j == 8) || 
								(k == 5 && j == 4) || (k == 5 && j == 6) || 
								(k == 3 && j == 8) || (k == 3 && j == 6))
			{
				EnergyP1 -= hit;
				WAVE(IDW_HIT1);
			}
// Player 1 WON
			if( EnergyP1 >= MAXHIT*(percent) && EnergyP2 <= 0 )
			{
				m = 0;
				l.stat = END;
				c.player = P1;
				fight = TRUE;

				LoadSprites();
				LoadBitmaps();
				CompileBitmaps(hwnd);
				DisplayBG(hwnd);
				File = IDM_END;
				MIDI(STOP, hwnd);
				WAVE(IDW_END2A);
			}
			else if( EnergyP1 < MAXHIT*(percent) && EnergyP2 <= 0 )
			{
				fight = FALSE;
				c.player = P1;
				LOSSER(hwnd);
			}
// Player 2 or COM WON
			else if( EnergyP2 >= MAXHIT*(percent) && EnergyP1 <= 0 )
			{
				m = 0;
				l.stat = END;
				if(l.number == P1_VS_P2)
					c.player = P2;
				else if(l.number == P1_VS_COM)
					c.player = COM;
				fight = TRUE;

				LoadSprites();
				LoadBitmaps();
				CompileBitmaps(hwnd);
				DisplayBG(hwnd);
				File = IDM_END;
				MIDI(STOP, hwnd);
				WAVE(IDW_END2A);
			}
			else if( EnergyP2 < MAXHIT*(percent) && EnergyP1 <= 0 )
			{
				fight = FALSE;
				if(l.number == P1_VS_P2)
					c.player = P2;
				else if(l.number == P1_VS_COM)
					c.player = COM;
				LOSSER(hwnd);
			}
			j = 1;
			k = 1;
			endround = FALSE;
}

void LOSSER(HWNDdll hwnd)
{
	WAVE(IDW_END1);
	QA(hwnd, "Play again? LOSSER!");
}

DllExport void Difficulty(int dl)
{
switch(dl)
	{
	case 1:
		{
		GTimeRate = 1000;
		percent = 0.15;
		hit = 10;
		} break;
	case 2:
		{
		GTimeRate = 500;
		percent = 0.35;
		hit = 15;
		} break;
	case 3:
		{
		GTimeRate = 100;
		percent = 0.65;
		hit = 20;
		} break;
	}
}

void QA(HWNDdll hwnd, LPCTSTR message)
{
	l.stat = END;

	i = IDS_P1;
	j = IDS_COM;
	if(c.player == P1)
		{
			j = IDS_P2DEAD;
			m = 1;
			if(fight == FALSE)
				n = 12;
			if(fight == TRUE)
				n = 1;
		}
	else if(c.player == P2 || c.player == COM)
		{
			i = IDS_P1DEAD;
			n = 1;
			if(fight == FALSE)
				m = 1;
			if(fight == TRUE)
				m = 12;

		}
	DisplaySp(hwnd, i, m, 
		(GScreenW)*(0.50) - 41, (GScreenH)*(0.40), SpriteSize, delta);
	DisplaySp(hwnd, j, n,
		(GScreenW)*(0.50), (GScreenH)*(0.40), SpriteSize, (-1)*delta);

	fight = FALSE;
	int answer = MessageBox(hwnd, message, "Kung Fu Willy", MB_YESNO | MB_ICONQUESTION);
	if(answer == IDYES)
		Reset(hwnd);
	else if(answer == IDNO)
		Quit(hwnd);
}
