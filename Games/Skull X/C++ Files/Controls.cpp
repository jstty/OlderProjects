////////////////////////////////////////////////////////////////////////
//	Program Name:	Controls.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Controls File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <windows.h>
#include <dinput.h>

#include "..\Header Files\Program.h"
#include "..\Header Files\ControlsClass.h"
//#include "..\Header Files\GameClass.h"

#include "..\Header Files\ValuesClass.h"
extern VALUES		*Val;

#ifdef _DEBUG
	#include "..\Header Files\DebugClass.h"
	extern DEBUGCLASS Debug;

	#include "..\Header Files\TestSpeed.h"
	extern TestSpeed tsControls;
#endif

///////////////////////////////////////////////////////
// Controls Loop
///////////////////////////////////////////////////////
bool CONTROLS::Controls_Loop(void)
{
	HANDLE hThread = GetCurrentThread();
//	CRITICAL_SECTION cs;
//	InitializeCriticalSection(&cs);

	//SetFocus(Val->Main->Get_ChildHwnd());

	while(ThreadLoop == 0)
	{
//		EnterCriticalSection(&cs);

		// Test Speed
		#ifdef _DEBUG
			if(tsControls.Rate > 1000)
				return 0;

			tsControls.Loop();
		#endif

// Code

		Sys_Loop();
		Key_Loop();
		Joy_Loop();

// End Code

//		LeaveCriticalSection(&cs);
		WaitForSingleObject(hThread, Delay);
	}

	ThreadLoop = 2;
	return 0;
}

///////////////////////////////////////////////////////
// GetControls
///////////////////////////////////////////////////////
void CONTROLS::Joy_Loop(void)
{
	for(j = 0; j < NumJoy; j++)
	{
		TempJoy = &Joy[j];

		if( TempJoy->Enabled )
		{
			if( !joyGetPosEx(j, &JoyInfo ) )
			{
				TempPlayer = Player[ TempJoy->PlayerNum ];
//
				// Vertical
					if(JoyInfo.dwYpos < TempJoy->Vert[0])
					{
						if( ( !TempPlayer[TempJoy->Button[DOWN]].v ) && ( TempPlayer[TempJoy->Button[UP]].c != C_KEY) )
						{
							TempPlayer[TempJoy->Button[UP]].v = true;
							TempPlayer[TempJoy->Button[UP]].c = C_JOY;
						}
					}
					else	if(JoyInfo.dwYpos > TempJoy->Vert[1])
					{
						if( ( !TempPlayer[TempJoy->Button[UP]].v ) && ( TempPlayer[TempJoy->Button[DOWN]].c != C_KEY )  )
						{
							TempPlayer[TempJoy->Button[DOWN]].v = true;
							TempPlayer[TempJoy->Button[DOWN]].c = C_JOY;
						}
					}
					else
					{
						if(TempPlayer[TempJoy->Button[UP]].c != C_KEY)
						{
							TempPlayer[TempJoy->Button[UP]].v = false;
							TempPlayer[TempJoy->Button[UP]].c = false;
						}

						if(TempPlayer[TempJoy->Button[DOWN]].c != C_KEY)
						{
							TempPlayer[TempJoy->Button[DOWN]].v = false;
							TempPlayer[TempJoy->Button[DOWN]].c = false;
						}
					}
				// Horizontal
					if(JoyInfo.dwXpos < TempJoy->Horz[0])
					{
						if(	(!TempPlayer[ TempJoy->Button[RIGHT]].v) && ( TempPlayer[TempJoy->Button[LEFT]].c != C_KEY ) )
						{
							TempPlayer[TempJoy->Button[LEFT]].v = true;
							TempPlayer[TempJoy->Button[LEFT]].c = C_JOY;
						}
					}
					else	if(JoyInfo.dwXpos > TempJoy->Horz[1])
					{
						if(	(!TempPlayer[TempJoy->Button[LEFT]].v) && ( TempPlayer[TempJoy->Button[RIGHT]].c != C_KEY ) )
						{
							TempPlayer[TempJoy->Button[RIGHT]].v = true;
							TempPlayer[TempJoy->Button[RIGHT]].c = C_JOY;
						}
					}
					else
					{
						if(TempPlayer[TempJoy->Button[LEFT]].c != C_KEY)
						{
							TempPlayer[TempJoy->Button[LEFT]].v = false;
							TempPlayer[TempJoy->Button[LEFT]].c = false;
						}

						if(TempPlayer[TempJoy->Button[RIGHT]].c != C_KEY)
						{
							TempPlayer[TempJoy->Button[RIGHT]].v = false;
							TempPlayer[TempJoy->Button[RIGHT]].c = false;
						}
					}
				// Button #
				for(b = 0; b < 4; b++)
				{
					k = 1 << b;
					if( GETBIT(JoyInfo.dwButtons, k ) )
					{
						k = TempJoy->Button[b + 4];
						if( !TempPlayer[k].v )
						{
							if( (k == UP) && ( !TempPlayer[DOWN].v ) )
							{
								TempPlayer[k].v = true;
								TempPlayer[k].c = C_JOY;
							}
							else if( (k == DOWN) && ( !TempPlayer[UP].v ) )
							{
								TempPlayer[k].v = true;
								TempPlayer[k].c = C_JOY;
							}
							else if( (k == LEFT) && ( !TempPlayer[RIGHT].v ) )
							{
								TempPlayer[k].v = true;
								TempPlayer[k].c = C_JOY;
							}
							else if( (k == RIGHT) && ( !TempPlayer[LEFT].v ) )
							{
								TempPlayer[k].v = true;
								TempPlayer[k].c = C_JOY;
							}
							else if(k > 3)
							{
								TempPlayer[k].v = true;
								TempPlayer[k].c = C_JOY;
							}
						}
					}
					else
					{
						k = TempJoy->Button[b + 4];

						if(TempPlayer[ k ].c != C_KEY)
						{
							TempPlayer[ k ].v = false;
							TempPlayer[ k ].c = false;
						}
					}
				}
			}
			else
				TempJoy->Enabled = false;
		}
	}

}
//
// Keyboard
//
void CONTROLS::Key_Loop(void)
{
	for(k = 0; k < NumpKey; k++)
	{
		TempPlayer = Player[ kPlayerNum ];
	
		if(	TestKey( pKey[k] ) )
		{	
			if( (k == UP) && ( !TempPlayer[UP].v ) && ( !TempPlayer[DOWN].v ) )
			{
				TempPlayer[k].v = true;
				TempPlayer[k].c = C_KEY;
			}
			else if( (k == DOWN) && ( !TempPlayer[DOWN].v ) && ( !TempPlayer[UP].v ) )
			{
				TempPlayer[k].v = true;
				TempPlayer[k].c = C_KEY;
			}
			else if( (k == LEFT) && ( !TempPlayer[LEFT].v ) && ( !TempPlayer[RIGHT].v ) )
			{
				TempPlayer[k].v = true;
				TempPlayer[k].c = C_KEY;
			}
			else if( (k == RIGHT) && ( !TempPlayer[RIGHT].v ) && ( !TempPlayer[LEFT].v ) )
			{
				TempPlayer[k].v = true;
				TempPlayer[k].c = C_KEY;
			}
			else if( (k > 3) && ( !TempPlayer[k].v ) )
			{
				TempPlayer[k].v = true;
				TempPlayer[k].c = C_KEY;
			}
		}
		else
		{
			if( TempPlayer[k].c != C_JOY )
			{
				TempPlayer[k].v = false;
				TempPlayer[k].c = false;
			}
		}
//
	}
}

void CONTROLS::Sys_Loop(void)
{
	for(k = 0; k < NumsKey; k++)
	{
		if(	TestKey( sKey[k] ) )
		{
			if(k == 0)
			{
				PostMessage(Val->Main->Get_MainHwnd(), WM_DESTROY, 0, 0);
			}
			else if(k == 1)
			{
				bool Close = false;
				Val->Display->Pause();

				while( !GetAsyncKeyState(VK_SPACE) )
				{
					if(TestKey( sKey[0] ) )
					{	
						Close = true;
						break;
					}
				}

				if(Close)
					PostMessage(Val->Main->Get_MainHwnd(), WM_DESTROY, 0, 0);
				
				Val->Display->Re_Draw = RE_ALL;
			}
		}
//
	}
}

bool CONTROLS::TestKey(Key kb)
{
	if(kb.Code == 0)
		return 0;

	if( GetAsyncKeyState(kb.Code) )
	{
		j = 0;
		if(kb.a){	if(GetAsyncKeyState(VK_MENU) )		j++; }
		if(kb.c){	if(GetAsyncKeyState(VK_CONTROL) )	j++; }
		if(kb.s){	if(GetAsyncKeyState(VK_SHIFT) )		j++; }

		if( (unsigned)(kb.a + kb.c + kb.s) == j)
			return 1;
		else
			return 0;
	}
	else
		return 0;

	return 0;
}
//////////////////////////////////////
// WM_MOUSE
//////////////////////////////////////
void CONTROLS::OnMouse(HWND hwnd, int x, int y, UINT keyFlags)
{
	if(hwnd == hWnd)
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(false);
		}

		Mouse.x = (x*G_XRES)/xMax;
		Mouse.y = (y*G_YRES)/yMax;
	}
	else
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(true);
		}
		

		if(x > ChildRect.right)
			x = (short)(ChildRect.right - ChildRect.left) - 5;
		else if(x < ChildRect.left)
			x = 0;
		else
			x = (short)(x - ChildRect.left);

		if(y > ChildRect.bottom)
			y = (short)(ChildRect.bottom - ChildRect.top) - 10;
		else if(y < ChildRect.top)
			y = 0;
		else
			y = (short)(y - ChildRect.top);

		Mouse.x = (x*G_XRES)/xMax;
		Mouse.y = (y*G_YRES)/yMax;
	}
}
void CONTROLS::OnMouseLDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	SetCapture(hwnd);

	if(hwnd == hWnd)
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(false);
		}

		Mouse.StartX = (x*G_XRES)/xMax;
		Mouse.StartY = (y*G_YRES)/yMax;
		Mouse.left = true;
	}
	else
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(true);
		}
		

		if(x > ChildRect.right)
			x = (short)(ChildRect.right - ChildRect.left) - 5;
		else if(x < ChildRect.left)
			x = 0;
		else
			x = (short)(x - ChildRect.left);

		if(y > ChildRect.bottom)
			y = (short)(ChildRect.bottom - ChildRect.top) - 10;
		else if(y < ChildRect.top)
			y = 0;
		else
			y = (short)(y - ChildRect.top);

		Mouse.StartX = (x*G_XRES)/xMax;
		Mouse.StartY = (y*G_YRES)/yMax;
	}
}
void CONTROLS::OnMouseRDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	SetCapture(hwnd);

	if(hwnd == hWnd)
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(false);
		}

		Mouse.StartX = (x*G_XRES)/xMax;
		Mouse.StartY = (y*G_YRES)/yMax;
		Mouse.right = true;
	}
	else
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(true);
		}
		
		if(x > ChildRect.right)
			x = (short)(ChildRect.right - ChildRect.left) - 5;
		else if(x < ChildRect.left)
			x = 0;
		else
			x = (short)(x - ChildRect.left);

		if(y > ChildRect.bottom)
			y = (short)(ChildRect.bottom - ChildRect.top) - 10;
		else if(y < ChildRect.top)
			y = 0;
		else
			y = (short)(y - ChildRect.top);

		Mouse.StartX = (x*G_XRES)/xMax;
		Mouse.StartY = (y*G_YRES)/yMax;
	}
}
void CONTROLS::OnMouseMDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
	SetCapture(hwnd);

	if(hwnd == hWnd)
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(false);
		}

		Mouse.StartX = (x*G_XRES)/xMax;
		Mouse.StartY = (y*G_YRES)/yMax;
		Mouse.middle = true;
	}
	else
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(true);
		}
		

		if(x > ChildRect.right)
			x = (short)(ChildRect.right - ChildRect.left) - 5;
		else if(x < ChildRect.left)
			x = 0;
		else
			x = (short)(x - ChildRect.left);

		if(y > ChildRect.bottom)
			y = (short)(ChildRect.bottom - ChildRect.top) - 10;
		else if(y < ChildRect.top)
			y = 0;
		else
			y = (short)(y - ChildRect.top);

		Mouse.StartX = (x*G_XRES)/xMax;
		Mouse.StartY = (y*G_YRES)/yMax;
	}

}
void CONTROLS::OnMouseLUp(HWND hwnd, int x, int y, UINT flags)
{
	ReleaseCapture();

	Mouse.left = false;

	if(hwnd == hWnd)
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(false);
		}

		Mouse.EndX = (x*G_XRES)/xMax;
		Mouse.EndX = (y*G_YRES)/yMax;
	}
	else
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(true);
		}
		

		if(x > ChildRect.right)
			x = (short)(ChildRect.right - ChildRect.left) - 5;
		else if(x < ChildRect.left)
			x = 0;
		else
			x = (short)(x - ChildRect.left);

		if(y > ChildRect.bottom)
			y = (short)(ChildRect.bottom - ChildRect.top) - 10;
		else if(y < ChildRect.top)
			y = 0;
		else
			y = (short)(y - ChildRect.top);

		Mouse.EndX = (x*G_XRES)/xMax;
		Mouse.EndX = (y*G_YRES)/yMax;
	}
}
void CONTROLS::OnMouseRUp(HWND hwnd, int x, int y, UINT flags)
{
	ReleaseCapture();

	Mouse.right = false;

	if(hwnd == hWnd)
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(false);
		}

		Mouse.EndX = (x*G_XRES)/xMax;
		Mouse.EndX = (y*G_YRES)/yMax;
	}
	else
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(true);
		}

		if(x > ChildRect.right)
			x = (short)(ChildRect.right - ChildRect.left) - 5;
		else if(x < ChildRect.left)
			x = 0;
		else
			x = (short)(x - ChildRect.left);

		if(y > ChildRect.bottom)
			y = (short)(ChildRect.bottom - ChildRect.top) - 10;
		else if(y < ChildRect.top)
			y = 0;
		else
			y = (short)(y - ChildRect.top);

		Mouse.EndX = (x*G_XRES)/xMax;
		Mouse.EndX = (y*G_YRES)/yMax;
	}
}
void CONTROLS::OnMouseMUp(HWND hwnd, int x, int y, UINT flags)
{
	ReleaseCapture();

	Mouse.middle = false;

	if(hwnd == hWnd)
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(false);
		}

		Mouse.EndX = (x*G_XRES)/xMax;
		Mouse.EndX = (y*G_YRES)/yMax;
	}
	else
	{
		if(Cursor)
		{
			Mouse.show = false;
			ShowCursor(true);
		}
		

		if(x > ChildRect.right)
			x = (short)(ChildRect.right - ChildRect.left) - 5;
		else if(x < ChildRect.left)
			x = 0;
		else
			x = (short)(x - ChildRect.left);

		if(y > ChildRect.bottom)
			y = (short)(ChildRect.bottom - ChildRect.top) - 10;
		else if(y < ChildRect.top)
			y = 0;
		else
			y = (short)(y - ChildRect.top);

		Mouse.EndX = (x*G_XRES)/xMax;
		Mouse.EndX = (y*G_YRES)/yMax;
	}
}
//////////////////////////////////////
// WM_KEYDOWN
//////////////////////////////////////
void CONTROLS::OnKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
	Sys_Loop();
	Key_Loop();
}
//
DWORD WINAPI Controls_ThreadProc(LPVOID msg)
{
	return Val->Controls->Controls_Loop();
}

void CONTROLS::Set_data(ControlVar cv, bool load_default)
{
	Mouse.show = true;
	Cursor = Val->Display->UseMouse;

//
	xMax = Val->Display->xMax;
	yMax = Val->Display->yMax;
//
	memset(&JoyInfo, 0, sizeof(JOYINFOEX));
	JoyInfo.dwSize = sizeof(JOYINFOEX);
	JoyInfo.dwFlags = JOY_RETURNALL;
//
	unsigned char n = 0;
	if(!load_default)
	{
		cv.NumPlayer = 2;

		cv.NumsKey = 3;
		cv.sKey = new Key[cv.NumsKey];
		memset(cv.sKey, 0, (cv.NumsKey)*sizeof(Key) );

		cv.sKey[0].Code = VK_ESCAPE;
		cv.sKey[1].Code = VK_F1;
		cv.sKey[2].Code = VK_SPACE;

		cv.NumpKey = 8;
		cv.pKey = new Key[cv.NumpKey];
		memset(cv.pKey, 0, (cv.NumpKey)*sizeof(Key) );

		cv.pKey[0].Code = VK_UP;		// Up
		cv.pKey[1].Code = VK_DOWN;	// Down
		cv.pKey[2].Code = VK_LEFT;	// Left
		cv.pKey[3].Code = VK_RIGHT;	// Right
		cv.pKey[4].Code = 'Z';			// Button 1
		cv.pKey[5].Code = 'X';			// Button 2
		cv.pKey[6].Code = 'C';			// Button 3
		cv.pKey[7].Code = 'V';			// Button 4
		cv.kPlayerNum = 0;

		cv.NumJoy = 2;
		cv.Joy = new JoyStick[cv.NumJoy];
		memset(cv.Joy, 0, (cv.NumJoy)*sizeof(JoyStick) );

		cv.Joy[n].Enabled = true;
		cv.Joy[n].PlayerNum = 0;

		joyGetPosEx(cv.Joy[n].PlayerNum, &JoyInfo );
		if(JoyInfo.dwXpos > JOY_DIFF)
			cv.Joy[n].Horz[0] = (unsigned short)(JoyInfo.dwXpos - JOY_DIFF);
		else
			cv.Joy[n].Horz[0] = 0;
		cv.Joy[n].Horz[1] = (unsigned short)(JoyInfo.dwXpos + JOY_DIFF);

		if(JoyInfo.dwYpos > JOY_DIFF)
			cv.Joy[n].Vert[0] = (unsigned short)(JoyInfo.dwYpos - JOY_DIFF);
		else
			cv.Joy[n].Vert[0] = 0;
		cv.Joy[n].Vert[1] = (unsigned short)(JoyInfo.dwYpos + JOY_DIFF);

		cv.Joy[n].Button[UP]		= UP;
		cv.Joy[n].Button[DOWN]	= DOWN;
		cv.Joy[n].Button[LEFT]	= LEFT;
		cv.Joy[n].Button[RIGHT] = RIGHT;
		cv.Joy[n].Button[B1]		= B1;
		cv.Joy[n].Button[B2]		= B2;
		cv.Joy[n].Button[B3]		= B3;
		cv.Joy[n].Button[B4]		= B4;

		n++;
		cv.Joy[n].Enabled = true;
		cv.Joy[n].PlayerNum = 1;

		joyGetPosEx(cv.Joy[n].PlayerNum, &JoyInfo );
		if(JoyInfo.dwXpos > JOY_DIFF)
			cv.Joy[n].Horz[0] = (unsigned short)(JoyInfo.dwXpos - JOY_DIFF);
		else
			cv.Joy[n].Horz[0] = 0;
		cv.Joy[n].Horz[1] = (unsigned short)(JoyInfo.dwXpos + JOY_DIFF);

		if(JoyInfo.dwYpos > JOY_DIFF)
			cv.Joy[n].Vert[0] = (unsigned short)(JoyInfo.dwYpos - JOY_DIFF);
		else
			cv.Joy[n].Vert[0] = 0;
		cv.Joy[n].Vert[1] = (unsigned short)(JoyInfo.dwYpos + JOY_DIFF);

		cv.Joy[n].Button[UP]		= B1;
		cv.Joy[n].Button[DOWN]	= B2;
		cv.Joy[n].Button[LEFT]	= B3;
		cv.Joy[n].Button[RIGHT] = B4;
		cv.Joy[n].Button[B1]		= LEFT;
		cv.Joy[n].Button[B2]		= RIGHT;
		cv.Joy[n].Button[B3]		= UP;
		cv.Joy[n].Button[B4]		= DOWN;
	}
	else
	{
		cv.NumPlayer = 2;

		cv.NumsKey = 3;
		cv.sKey = new Key[cv.NumsKey];
		memset(cv.sKey, 0, (cv.NumsKey)*sizeof(Key) );

		cv.sKey[0].Code = VK_ESCAPE;
		cv.sKey[1].Code = VK_F1;
		cv.sKey[2].Code = VK_SPACE;

		cv.NumpKey = 8;
		cv.pKey = new Key[cv.NumpKey];
		memset(cv.pKey, 0, (cv.NumpKey)*sizeof(Key) );

		cv.pKey[0].Code = VK_UP;		// Up
		cv.pKey[1].Code = VK_DOWN;	// Down
		cv.pKey[2].Code = VK_LEFT;	// Left
		cv.pKey[3].Code = VK_RIGHT;	// Right
		cv.pKey[4].Code = 'Z';			// Button 1
		cv.pKey[5].Code = 'X';			// Button 2
		cv.pKey[6].Code = 'C';			// Button 3
		cv.pKey[7].Code = 'V';			// Button 4
		cv.kPlayerNum = 0;

		cv.NumJoy = 2;
		cv.Joy = new JoyStick[cv.NumJoy];
		memset(cv.Joy, 0, (cv.NumJoy)*sizeof(JoyStick) );

		cv.Joy[n].Enabled = true;
		cv.Joy[n].PlayerNum = 0;

		joyGetPosEx(cv.Joy[n].PlayerNum, &JoyInfo );
		if(JoyInfo.dwXpos > JOY_DIFF)
			cv.Joy[n].Horz[0] = (unsigned short)(JoyInfo.dwXpos - JOY_DIFF);
		else
			cv.Joy[n].Horz[0] = 0;
		cv.Joy[n].Horz[1] = (unsigned short)(JoyInfo.dwXpos + JOY_DIFF);

		if(JoyInfo.dwYpos > JOY_DIFF)
			cv.Joy[n].Vert[0] = (unsigned short)(JoyInfo.dwYpos - JOY_DIFF);
		else
			cv.Joy[n].Vert[0] = 0;
		cv.Joy[n].Vert[1] = (unsigned short)(JoyInfo.dwYpos + JOY_DIFF);

		cv.Joy[n].Button[UP]		= UP;
		cv.Joy[n].Button[DOWN]	= DOWN;
		cv.Joy[n].Button[LEFT]	= LEFT;
		cv.Joy[n].Button[RIGHT] = RIGHT;
		cv.Joy[n].Button[B1]		= B1;
		cv.Joy[n].Button[B2]		= B2;
		cv.Joy[n].Button[B3]		= B3;
		cv.Joy[n].Button[B4]		= B4;

		n++;
		cv.Joy[n].Enabled = true;
		cv.Joy[n].PlayerNum = 1;

		joyGetPosEx(cv.Joy[n].PlayerNum, &JoyInfo );
		if(JoyInfo.dwXpos > JOY_DIFF)
			cv.Joy[n].Horz[0] = (unsigned short)(JoyInfo.dwXpos - JOY_DIFF);
		else
			cv.Joy[n].Horz[0] = 0;
		cv.Joy[n].Horz[1] = (unsigned short)(JoyInfo.dwXpos + JOY_DIFF);

		if(JoyInfo.dwYpos > JOY_DIFF)
			cv.Joy[n].Vert[0] = (unsigned short)(JoyInfo.dwYpos - JOY_DIFF);
		else
			cv.Joy[n].Vert[0] = 0;
		cv.Joy[n].Vert[1] = (unsigned short)(JoyInfo.dwYpos + JOY_DIFF);

		cv.Joy[n].Button[UP]		= B1;
		cv.Joy[n].Button[DOWN]	= B2;
		cv.Joy[n].Button[LEFT]	= B3;
		cv.Joy[n].Button[RIGHT] = B4;
		cv.Joy[n].Button[B1]		= LEFT;
		cv.Joy[n].Button[B2]		= RIGHT;
		cv.Joy[n].Button[B3]		= UP;
		cv.Joy[n].Button[B4]		= DOWN;
	}

	//
		Delay = cv.Delay;
		DelayRes = cv.DelayRes;

		NumPlayer = cv.NumPlayer;

		NumsKey = cv.NumsKey;
		sKey = cv.sKey;

		NumpKey = cv.NumpKey;
		pKey = cv.pKey;
		kPlayerNum = cv.kPlayerNum;

		NumJoy = cv.NumJoy;
		Joy = cv.Joy;

		Player = new DBOOL*[NumPlayer];
		memset(Player, 0, (NumPlayer)*sizeof(DBOOL*) );

		for(j = 0; j < NumPlayer; j++)
		{
			Player[j] = new DBOOL[NUM_B];
			memset(Player[j], 0, (NUM_B)*sizeof(DBOOL) );
		}

}
