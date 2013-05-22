////////////////////////////////////////////////////////////////////////
//	Program Name:	FileUtils.cp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	File Utils File
//	Date: 
////////////////////////////////////////////////////////////////////////

// Dialog Utils Varables
extern GAMEINFO	GameInfo[MAXSAVE];

	// Global Functions
void SaveGameFile(LPSTR file);
void NewGameFile(LPSTR file);
void NewLevelFile(LPSTR file, LEVELINFO li[]);
GAMESOUND LoadSetupFile(LPSTR file);

