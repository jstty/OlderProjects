////////////////////////////////////////////////////////////////////////
//	Program Name:	AlienMansion.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Alien Mansion header File
//	Date: 
////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <dsound.h>

// Defined cases
#define WM_START			(WM_USER + 0)
#define DllExport			__declspec( dllexport )
#define DllImport			__declspec( dllimport )
#define HWNDdll				struct HWND__ *
#define HINST					struct HINSTANCE__ *
#define DLLFILE				"Alienlevels.dll"
#define NEWFILE				"untitled"
#define LEVELSFILE		"levels.dat"
#define SAVEFILE			"Save.dat"
#define SETUPFILE			"GameSetup.dat"
#define GAMEDIR				"E:\\My Code\\Alien Mansion\\"
// Timer Rate
#define MAINTIME			500
#define CHILDTIME			100
// Window Size
#define XMAX					640
#define YMAX					480
// MAX
#define MAXSTR				65535
#define MAXICON				11
#define MAXSAVE				8
#define MAXARRAY			256
#define MAXLEVEL			25
#define MAXVAR				16
// Current Level
#define	CL						8
// Button ID's
#define ID_NEWBUTTON	1001
#define ID_LOADBUTTON	1002
#define ID_EXITBUTTON	1003
// Timer ID's
#define IDT_MAIN			100
#define IDT_START1		101
#define IDT_START2		102
#define IDT_CHILD			103
#define IDT_MIDI			104
#define IDT_CDPLAYER	105		// Sec. Timer In Dialog Box
#define IDT_CDTIMER		106		// Adds One Sec To Timer.
#define IDT_CDTRACK		107
// LEVEL state ID's
#define TITLE					0
#define START					0
// SOUND ID's
#define IDM_OPEN			101
#define IDM_PLAY			102
#define IDM_CLOSE			103
#define IDM_STOP			104
#define IDM_SEEK_RW		105
#define IDM_SEEK_FF		106
#define IDM_PAUSE			107
#define IDM_TRACK			108
#define IDM_DISK			109
#define IDM_NULL			111
#define LOOP					DSBPLAY_LOOPING
// GRAPCHICS ID's
#define HORZ			0
#define VERT			1

	// Handle WM_START message
/* void Cls_OnStart(HWND hwnd) */
#define	HANDLE_WM_START(hwnd, wParam, lParam, fn) \
												((fn)(hwnd), 0L)
#define FORWARD_WM_START(hwnd, fn) \
												(void)(fn)((hwnd), WM_START, 0L, 0L)

// MIDIFILE struct case
typedef struct tagMIDIFILE{
char			file[MAXARRAY];
UINT			sec;
}	MIDIFILE;

// MIDISOUND struct case
typedef struct tagMIDISOUND{
int				MidiId;
UINT			MidiStat;
UINT			MidiTimeRate;
LPSTR			error;
MIDIFILE	mf;
}	MIDISOUND;

// CDSOUND struct case
typedef struct tagCDSOUND{
UINT			PlayCDId;
UINT			CDGStat;
UINT			CDRStat;
UINT			CTrack;
//UINT			CTime;
DWORD			TrackNumber[MAXARRAY];
UINT			nTrack;
UINT			TArray;
UINT			TMin;
UINT			TSec;
UINT			TFrm;
LPSTR			error;
MCIERROR	MciError;
}	CDSOUND;

// WAVSOUND struct case
typedef struct tagWAVSOUND{
IDirectSoundBuffer	*DSBuffer[MAXARRAY];
UINT								file[MAXARRAY];
UINT								nfile;
UINT								WavStat;
LPSTR								error;
}	WAVSOUND;

// SOUND struct case
typedef struct tagSOUND{
MIDISOUND	midi;
CDSOUND		cd;
WAVSOUND	wav;
}	SOUND, *PSOUND, FAR *LPSOUND;

// SOUND struct case
typedef struct tagGAMESOUND{
UINT	MidiStat;
UINT	CDGStat;
UINT	WavStat;
}	GAMESOUND, *PGAMESOUND, FAR *LPGAMESOUND;

// MOUSE struct case
typedef struct tagMOUSE{
UINT			x;					// x position on screen
UINT			y;					// y position on screen
UINT			m1;					// did mouse move
UINT			m2;					// 
}	MOUSE;

// MAIN struct case
typedef struct tagMAINVAR{
HINSTANCE	MainhInst;
HWND			MainHwnd;
HWND			ChildHwnd;
HWND			ControlsHwnd;
HWND			TextHwnd;
HWND			OptionsHwnd;
HACCEL		hAccControls;
HACCEL		hAccOptions;
HACCEL		hAccFileUtil;
BOOL			LoadFile;
BOOL			SaveFile;
BOOL			DelEntry;
} MAINVAR;

// LEVELDLL struct case
typedef struct tagLEVELVAR{
BOOL		LoadLevel;
BOOL		Redraw;
int			iconloop;
char		ScreenItem[MAXARRAY];
} LEVELVAR;

// Zone struct case
typedef struct tagZONE{
char			zoneName[MAXARRAY];	// long pointer string
UINT			x1;					// x1 position on screen
UINT			y1;					// y1 position on screen
UINT			x2;					// x2 position on screen
UINT			y2;					// y2 position on screen
UINT			w;					// width
UINT			h;					// height
}	ZONE, ZONEARRAY;

// BITMAPARRAY struct case
typedef struct tagBITMAPARRAY{
HBITMAP		bitmap;								// Bitmap
UINT			zNum;									// Zone Number
}	BITMAPARRAY, *PBITMAPARRAY, FAR *LPBITMAPARRAY;
/*
// COLSPRITE struct case
typedef struct tagCOLSPRITE{
HDC				hdcBkg;
int				SpriteNum[MAXARRAY];
UINT			x;								// x position on screen
UINT			y;								// y position on screen
}	COLSPRITE, *PCOLSPRITE;

// OLDSPRITE struct case
typedef struct tagOLDSPRITE{
//HDC				spriteHdc;
UINT			x;								// x position on screen
UINT			y;								// y position on screen
}	OLDSPRITE, *POLDSPRITE;
*/
// SPRITE struct case
typedef struct tagSPRITEARRAY{
HBITMAP			sprite;								// sprite bitmap
HBITMAP			spriteM;							// sprite mask bitmap 
//COLSPRITE		cSprite;							// Collided sprite.
//OLDSPRITE		oldSprite;						// old sprite info
UINT				zNum;									// Zone Number
UINT				zOrder;								// sprite z dimentional placement
UINT				cel;									// animation
int					xDelta;								// change in the x direction
int					yDelta;								// change in the y direction
UINT				xHotspot;							// sprites x hotspot.
UINT				yHotspot;							// sprites y hotspot.
}	SPRITE, SPRITEARRAY, *PSPRITEARRAY, FAR *LPSPRITEARRAY;

// LEVEL/LEVELARRAY struct case
typedef struct tagLEVEL{
MIDIFILE				midi;
int							lWaveA[MAXARRAY];
UINT						waveNum;
BITMAPARRAY			lBitmapA[MAXARRAY];
UINT						bitmapNum;
SPRITEARRAY			lSpriteA[MAXARRAY];
UINT						spriteNum;
ZONEARRAY				lZoneA[MAXARRAY];
UINT						zoneNum;					
HBITMAP					bkgPath;
}	LEVEL, *PLEVEL, FAR *LPLEVEL,
	LEVELARRAY, *PLEVELARRAY, FAR *LPLEVELARRAY;

// GLOBAL struct case
typedef struct tagGLOBAL{
UINT						levelState;
UINT						MidX;
UINT						MidY;
SOUND						sound;
MOUSE						mouse;
MAINVAR					MainVar;
LEVELVAR				LevelVar;
GAMESOUND				Default;
} GLOBAL, *PGLOBAL, FAR *LPGLOBAL;

// GAME struct case
typedef struct tagGAME{
UINT						levelNum;
char						name[MAXARRAY];
int							item[MAXICON];
int							var[MAXVAR];
MOUSE						MainChar;
GAMESOUND				GameSound;
}	GAME, *PGAME, FAR *LPGAME;

// GAMEINFO struct cases
typedef struct tagGAMEINFO	{
GAME					game;
}	GAMEINFO;

// LEVELINFO struct cases
typedef struct tagLEVELINFO	{
	LEVEL level[MAXARRAY];
}	LEVELINFO;
