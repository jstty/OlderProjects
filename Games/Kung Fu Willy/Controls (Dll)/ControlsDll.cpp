////////////////////////////////////////////////////////////////////////
//  Program Name: ControlsDll.cpp
//  Programmer: Joseph Sutton
//  Description: DLL Controls File
//  Date:
////////////////////////////////////////////////////////////////////////
#define STRICT
#include <windows.h>
#include <stdio.h>
#include <string.h>            
#include <mmsystem.h>
#include <Game.h>
#include "Sound.h"
#include "Levels.h"
#include "ControlsDll.h"

			//////////////////////////////////////
			// DLLMain
			//////////////////////////////////////
BOOL APIENTRY DllEntryPoint(HINSTANCE hInstDLL, WORD wDataSeg, LPVOID lpReserved)
{
  return TRUE;
}
			//////////////////////////////////////
			// Handles MM_JOW1MOVE messages
			//////////////////////////////////////
DllExport void Main_Joy1(HWNDdll hwnd, UINT fwButtons, UINT xPos, UINT yPos)
{
	if(l.stat != END)
		c.JB = 0;
	if(c.player == P1)	{
		c.JD = JoyTest(JOYSTICKID1, xPos, yPos);
		c.JB = fwButtons;	}
	joyReleaseCapture(JOYSTICKID1);
	joySetCapture(hwnd, JOYSTICKID2, TimeRate, FALSE);
}
			//////////////////////////////////////
			// Handles MM_JOW2MOVE messages
			//////////////////////////////////////
DllExport void Main_Joy2(HWNDdll hwnd, UINT fwButtons, UINT xPos, UINT yPos)
{
	if(l.stat != END)
		c.JB = 0;
	if(c.player == P2)	{
		c.JD = JoyTest(JOYSTICKID2, xPos, yPos);
		c.JB = fwButtons;	}
	joyReleaseCapture(JOYSTICKID2);
	joySetCapture(hwnd, JOYSTICKID1, TimeRate, FALSE);
}
			//////////////////////////////////////
			// Handles WM_KEYDOWN messages
			//////////////////////////////////////
DllExport void Main_Key(HWNDdll hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
if(c.player == P2)	{
//	c.JD = CENTER;
	if(vk == VK_LEFT)
			c.JD = LEFT;
	if(vk == VK_RIGHT)
			c.JD = RIGHT;
	if(vk == VK_UP)
			c.JD = UP;
	if(vk == VK_DOWN)
			c.JD = DOWN;
	if(vk == 'Z')
			c.JB = 1;
	if(vk == 'X')
			c.JB = 2;
}
// CD Player Keys
	if(vk == '1')
			CDAudio(PLAY, 1);
	if(vk == '2')
			CDAudio(PLAY, 2);
	if(vk == '3')
			CDAudio(PLAY, 3);
	if(vk == '4')
			CDAudio(PLAY, 4);
	if(vk == '5')
			CDAudio(PLAY, 5);
	if(vk == '6')
			CDAudio(PLAY, 6);
	if(vk == '7')
			CDAudio(PLAY, 7);
	if(vk == '8')
			CDAudio(PLAY, 8);
	if(vk == '9')
			CDAudio(PLAY, 9);
	if(vk == '0')
			CDAudio(PLAY, 10);
	if(vk == 0xC0)
		CDAudio(PAUSE, NULL);
	if(vk == 'S')
		MIDI(STOP, hwnd);
	if(vk == 'R')
		MIDI(PLAY, hwnd);
	if(vk == 'E')
		{
		Difficulty(1);
		}
	if(vk == 'M')
		{
		Difficulty(2);
		}
	if(vk == 'H')
		{
		Difficulty(3);
		}
}
			//////////////////////////////////////
			// JoyStick Test Functions
			//////////////////////////////////////
UINT JoyTest(UINT JoyStickNum, UINT xPos, UINT yPos)
{
  JOYCAPS joyc;
  UINT xmin,xmax,ymin,ymax;
	double xmidL,xmidR,ymidU,ymidD;
  joyGetDevCaps(JoyStickNum, &joyc, sizeof(joyc));
  xmin = joyc.wXmin;
  xmax = joyc.wXmax;
	ymin = joyc.wYmin;
  ymax = joyc.wYmax;
	xmidL = (xmax - xmin)*(0.25) + xmin;
	xmidR = (xmax - xmin)*(0.75) + xmin;
	ymidU = (ymax - ymin)*(0.25) + ymin;
	ymidD = (ymax - ymin)*(0.75) + ymin;

	if(xPos > xmidR)
		return RIGHT;
	if(xPos < xmidL)
		return LEFT;
	if(yPos > ymidD)
		return DOWN;
	if(yPos < ymidU)
		return UP;
return CENTER;
}

DllExport void ButtonUpdate(HWNDdll hwnd, HINST hInst)
{
	RECT Rect;
	GetWindowRect(GetDesktopWindow(), &Rect);
	LONG ScreenW = Rect.right, ScreenH = Rect.bottom;
	int bWidth = GetSystemMetrics(SM_CXSIZE), bHight = GetSystemMetrics(SM_CYSIZE);
// Minimize Button		
	CreateWindowEx(WS_EX_TOPMOST, "button", "_", 
		WS_CHILD | WS_VISIBLE, 
		ScreenW - 2*bWidth, ScreenH - bHight, bWidth, bHight, hwnd,
		HMENU(ID_MINBUTTON), hInst, NULL);
// Close Button		
	CreateWindowEx(WS_EX_TOPMOST, "button", "X", 
		WS_CHILD | WS_VISIBLE, 
		ScreenW - bWidth, ScreenH - bHight, bWidth, bHight, hwnd,
		HMENU(ID_CLOSEBUTTON), hInst, NULL);
}
