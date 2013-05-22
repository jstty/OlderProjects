////////////////////////////////////////////////////////////////////////
//	Program Name:	FileUtils.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	File Utils File
//	Date: 
////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "AlienMansion.h"
#include "FileUtils.h"

//////////////////////////////////////////////////
// 								Misc Functions								//
//////////////////////////////////////////////////
			//////////////////////////////////////
			// Save Game File Function
			//////////////////////////////////////
void SaveGameFile(LPSTR file)
{
	int i;
	FILE *fp;
	char cPath[MAXARRAY];
	strcpy(cPath, GAMEDIR);
	if((fp = fopen(strcat(cPath, file), "w+")) == NULL)
		{
		fclose(fp);
		strcpy(cPath, GAMEDIR);
		NewGameFile(file);
		return;
		}
	fwrite(&GameInfo[0], sizeof(GameInfo[0]), 1, fp);
	fclose(fp);

	strcpy(cPath, GAMEDIR);
	fp = fopen(strcat(cPath, file), "a");
	for(i = 1; i < MAXSAVE; i++)
		{
		fwrite(&GameInfo[i], sizeof(GameInfo[i]), 1, fp);
		}
	fclose(fp);
}

			//////////////////////////////////////
			// New Game File Function
			//////////////////////////////////////
void NewGameFile(LPSTR file)
{
	int i, j;
	FILE *fp;
	char cPath[MAXARRAY];

	memset(GameInfo, '\0', sizeof(GameInfo));
	strcpy(GameInfo[0].game.name, NEWFILE);

	strcpy(cPath, GAMEDIR);
	fp = fopen(strcat(cPath, file), "w+");
	fwrite(&GameInfo[0], sizeof(GameInfo[0]), 1, fp);
	fclose(fp);

	strcpy(cPath, GAMEDIR);
	fp = fopen(strcat(cPath, file), "a");
	for(i = 1; i < MAXSAVE; i++)
		{
		for(j = 0; j < MAXICON; j++)
			GameInfo[i].game.item[j] = -1;
		fwrite(&GameInfo[i], sizeof(GameInfo[i]), 1, fp);
		}
	fclose(fp);
}
			//////////////////////////////////////
			// New Game File Function
			//////////////////////////////////////
void NewLevelFile(LPSTR file, LEVELINFO li[])
{
	FILE *fp;
	char cPath[MAXARRAY];
	strcpy(cPath, GAMEDIR);
	fp = fopen(strcat(cPath, file), "w+");
	memset(li, '\0', sizeof(li));
	fwrite(&li, sizeof(li), MAXSAVE, fp);
	fclose(fp);
}
			//////////////////////////////////////
			// Load Setup File Function
			//////////////////////////////////////
GAMESOUND LoadSetupFile(LPSTR file)
{
GAMESOUND SoundSetup;
FILE *fp;
char cPath[MAXARRAY];
strcpy(cPath, GAMEDIR);
if((fp = fopen(strcat(cPath, file), "r")) == NULL)
	{
	fclose(fp);
	strcpy(cPath, GAMEDIR);
	fp = fopen(strcat(cPath, file), "w+");
	strcpy(cPath, GAMEDIR);
	SoundSetup.MidiStat = IDM_PAUSE;
	SoundSetup.WavStat	= IDM_PAUSE;
	SoundSetup.CDGStat	= IDM_NULL;
	fwrite(&SoundSetup, sizeof(SoundSetup), 1, fp);
	fclose(fp);
	return SoundSetup;
	}
fread(&SoundSetup, sizeof(SoundSetup), 1, fp);
fclose(fp);
return SoundSetup;
}


