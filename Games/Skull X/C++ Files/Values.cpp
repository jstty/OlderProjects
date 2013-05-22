////////////////////////////////////////////////////////////////////////
//	Program Name:	Values.cpp
//	Programmer:		Joseph E. Sutton
//	Company:		Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Controls File
//	Date:			4/01/2000
//	Version:		1.00
////////////////////////////////////////////////////////////////////////

#include "..\Header Files\ValuesClass.h"

bool VALUES::LoadSetup(SETUPFILE *f)
{	
		HANDLE hFile;
		ULONG NumberRead;
		DWORD Size = 0;

		hFile = CreateFile("Setup.ini", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if(hFile == NULL)
		{
			Error("Create File Error # %d : %d ", 101, GetLastError());
			return 1;
		}
		//
		
		GAMESETUP GameSetup;

		Size = sizeof(GAMESETUP);
		ReadFile( hFile, &GameSetup, Size, &NumberRead, NULL);
		if(NumberRead != Size)
		{
			Error("Read File Error # %d : %d ", 102, GetLastError());
			return 1;
		}
		//
		CloseHandle(hFile);

		f->mv.Delay = GameSetup.mv.Delay;
		f->mv.UseDX = GameSetup.mv.FullScreen;
		f->mv.Stretch = GameSetup.mv.Stretch;
		f->mv.InWindow = false;
		f->mv.FullScreen = false;

		if( (f->mv.Stretch) || (f->mv.UseDX) )
		{
			f->dv.xMax = GameSetup.mv.Xmax;
			f->dv.yMax = GameSetup.mv.Ymax;
		}
		else
		{
			f->dv.xMax = D_XRES;
			f->dv.yMax = D_YRES;
		}

		f->dv.bpp = GameSetup.mv.Bpp;

		f->sv.PlayFx = GameSetup.mv.SndFx;
		f->sv.PlayMidi = GameSetup.mv.Midi;
//
// Controls
//
//
/*
		f->cv.NumPlayer = 2;
		f->cv.NumsKey = NUMSYSTEM;
		unsigned __int8 i;

		f->cv.sKey = new Key[f->cv.NumsKey];
		memset(f->cv.sKey, 0, f->cv.NumsKey*sizeof(Key) );

		for(i = 0; i < f->cv.NumsKey; i++)
			f->cv.sKey[i].Code = (unsigned char)GameSetup.cv.System[i].Code;

		f->cv.sKey[0].Code = VK_ESCAPE;
//		f->cv.sKey[1].Code = VK_F1;

		if(GameSetup.cv.KeyPlayer > 0)
			f->cv.kPlayerNum	= GameSetup.cv.KeyPlayer - 1;
		else
			f->cv.kPlayerNum = 0;

		f->cv.NumpKey = NUMDIRECT + NUMBUTTON;
		f->cv.pKey = new Key[f->cv.NumpKey];
		memset(f->cv.pKey, 0, f->cv.NumpKey*sizeof(Key) );

		f->cv.pKey[0].Code = (unsigned char)GameSetup.cv.Key[2].Code;
		f->cv.pKey[1].Code = (unsigned char)GameSetup.cv.Key[3].Code;
		f->cv.pKey[2].Code = (unsigned char)GameSetup.cv.Key[0].Code;
		f->cv.pKey[3].Code = (unsigned char)GameSetup.cv.Key[1].Code;
		//
		f->cv.pKey[4].Code = (unsigned char)GameSetup.cv.Key[4].Code;
		f->cv.pKey[5].Code = (unsigned char)GameSetup.cv.Key[5].Code;
		f->cv.pKey[6].Code = (unsigned char)GameSetup.cv.Key[6].Code;


		f->cv.NumJoy = 2;
		f->cv.Joy = new JoyStick[f->cv.NumJoy];
		memset(f->cv.Joy, 0, f->cv.NumJoy*sizeof(JoyStick) );

		i = 0;
		f->cv.Joy[i].Enabled		= GameSetup.cv.EnableJoy1;

		if(GameSetup.cv.Joy1Player > 0)
			f->cv.Joy[i].PlayerNum	= GameSetup.cv.Joy1Player - 1;
		else
			f->cv.Joy[i].PlayerNum = 0;

		f->cv.Joy[i].Button[UP]		= UP;
		f->cv.Joy[i].Button[DOWN]	= DOWN;
		f->cv.Joy[i].Button[LEFT]	= LEFT;
		f->cv.Joy[i].Button[RIGHT] = RIGHT;
		f->cv.Joy[i].Button[0]	= GameSetup.cv.bJoy1[0].B > 0 ? GameSetup.cv.bJoy1[0].B - 1 : 0;
		f->cv.Joy[i].Button[1]	= GameSetup.cv.bJoy1[1].B > 0 ? GameSetup.cv.bJoy1[1].B - 1 : 0;

		i++;
		f->cv.Joy[i].Enabled		= GameSetup.cv.EnableJoy2;
		if(GameSetup.cv.Joy2Player > 0)
			f->cv.Joy[i].PlayerNum	= GameSetup.cv.Joy2Player - 1;
		else
			f->cv.Joy[i].PlayerNum = 0;

		f->cv.Joy[i].Button[UP]		= UP;
		f->cv.Joy[i].Button[DOWN]	= DOWN;
		f->cv.Joy[i].Button[LEFT]	= LEFT;
		f->cv.Joy[i].Button[RIGHT] = RIGHT;
		f->cv.Joy[i].Button[0]	= GameSetup.cv.bJoy1[0].B > 0 ? GameSetup.cv.bJoy1[0].B - 1 : 0;
		f->cv.Joy[i].Button[1]	= GameSetup.cv.bJoy1[1].B > 0 ? GameSetup.cv.bJoy1[1].B - 1 : 0;
*/
	return 0;
}

void VALUES::SetGlobal(void)
{
		// Load default from .ini
	SETUPFILE sf;
	memset(&sf, 0, sizeof(SETUPFILE));
	bool Load_Default = false;

	if( LoadSetup(&sf) )
	{
		Error("%s::%s \n %s", "VALUES", "LoadSetup", "Could not Load setup file. Loading default.");

		Load_Default = true;
		// Default Values
		//////////////////////////////////////////////
		sf.mv.Delay = D_DELAY;
		sf.mv.DelayRes = D_DRES;
		//
		sf.mv.UseDX = D_USEDX;
		sf.mv.InWindow = D_INWINDOW;
		sf.mv.FullScreen = D_FULLSCREEN;
		sf.mv.Stretch = D_STRETCH;
		//////////////////////////////////////////////
//		sf.cv.Delay = D_DELAY;
//		sf.cv.DelayRes = D_DRES;
		//////////////////////////////////////////////
//		sf.dv.Delay = D_DELAY;
//		sf.dv.DelayRes = D_DRES;
		sf.dv.xMax = D_XRES;
		sf.dv.yMax = D_YRES;
		sf.dv.bpp = G_BPP;
		//////////////////////////////////////////////
//		sf.av.Delay = D_DELAY;
//		sf.av.DelayRes = D_DRES;
		//////////////////////////////////////////////
//		sf.sv.Delay = D_DELAY;
//		sf.sv.DelayRes = D_DRES;
	}

	sf.mv.DelayRes = D_DRES;

	// copy data from SetupFile.MainVar to Main.MainVar
	Main->Set_data(sf.mv);
	// always set display before controls because of the mouse pos.
	Display->Set_data(sf.dv);
		// copy data from SetupFile.ControlsVar to Main.ControlsVar
	Controls->Set_data(sf.cv, Load_Default);
		//
	Action->Set_data(sf.av);
		//
	Sound->Set_data(sf.sv);

}
