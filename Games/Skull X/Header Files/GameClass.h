////////////////////////////////////////////////////////////////////////
//	Program Name:	GameClass.cpp
//	Programmer:		Joseph E. Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Game Class Header File
//	Date:					02/27/2000
//	Version:			1.00
////////////////////////////////////////////////////////////////////////

#ifndef _GAME_CLASS
#define _GAME_CLASS

#include "..\Header Files\ErrorClass.h"
#include "..\Header Files\GameVar.h"
#include <stdlib.h>

struct GAME_DATA
{
	unsigned __int16 LevelNum;
	unsigned __int32 SubLevelNum;
	unsigned __int8 type;

	// sizeof(data)
	unsigned __int16 size;
	void *data;
};

class GAME : public ERRORCLASS {
public:
	GAME_DATA gData;

	int Rand(int start, int end)
	{
		int a = rand();
		return start + (a%(end - start + 1));
	};

	bool CheckFile(unsigned __int8 num)
	{
		char S[8];
		HANDLE hFile;

		sprintf(S, "%0.3d.sav", num);
		hFile = CreateFile(S, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
		if(hFile == INVALID_HANDLE_VALUE)
		{
			CloseHandle(hFile);
			return 0;
		}

		CloseHandle(hFile);
		return 1;
	}

	GAME_DATA *Load(unsigned __int8 num)
	{
		char S[8];
		DWORD NumBytes = 0, size = 0;
		HANDLE hFile;

		sprintf(S, "%0.3d.sav", num);
		hFile = CreateFile(S, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
		if(hFile == INVALID_HANDLE_VALUE)
		{
			Error("Could not load File: %s", S);
			CloseHandle(hFile);
			return 0;
		}

		GAME_DATA *TempData = new GAME_DATA;
		TempData->data = new GAME_VAR;

		/*
		size = sizeof(unsigned __int16);
		ReadFile(hFile, &gData.LevelNum, size, &NumBytes, NULL);
		if(size != NumBytes)
		{
			Error("Could not read data(gData.LevelNum) from file(%s) at data point %d .", S, size);
			CloseHandle(hFile);
			return 0;
		}

		size = sizeof(unsigned __int32);
		ReadFile(hFile, &gData.SubLevelNum, size, &NumBytes, NULL);
		if(size != NumBytes)
		{
			Error("Could not read data(gData.SubLevelNum) from file(%s) at data point %d .", S, size);
			CloseHandle(hFile);
			return 0;
		}
		*/

		size = sizeof(unsigned __int8);
		ReadFile(hFile, &TempData->type, size, &NumBytes, NULL);
		if(size != NumBytes)
		{
			Error("Could not read data(gData.type) from file(%s) at data point %d .", S, size);
			CloseHandle(hFile);
			return 0;
		}

		size = sizeof(unsigned __int16);
		ReadFile(hFile, &TempData->size, size, &NumBytes, NULL);
		if(size != NumBytes)
		{
			Error("Could not read data(gData.size) from file(%s) at data point %d .", S, size);
			CloseHandle(hFile);
			return 0;
		}

		size = TempData->size;
		ReadFile(hFile, TempData->data, size, &NumBytes, NULL);
		if(size != NumBytes)
		{
			Error("Could not read data(gData.data) from file(%s) at data point %d .", S, size);
			CloseHandle(hFile);
			return 0;
		}

		CloseHandle(hFile);
		return TempData;
	};

	bool Save(unsigned __int8 num)
	{
		char S[8];
		DWORD NumBytes = 0, size = 0;
		HANDLE hFile;

		sprintf(S, "%0.3d.sav", num);
		hFile = CreateFile(S , GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if(hFile == INVALID_HANDLE_VALUE)
		{
			Error("Could not save File: %s", S);
			CloseHandle(hFile);
			return 0;
		}

		/*
		size = sizeof(unsigned __int16);
		WriteFile(hFile, &gData.LevelNum, size, &NumBytes, NULL);
		if(size != NumBytes)
		{
			Error("Could not write data(gData.LevelNum) from file(%s) at data point %d .", S, size);
			CloseHandle(hFile);
			return 0;
		}

		size = sizeof(unsigned __int32);
		WriteFile(hFile, &gData.SubLevelNum, size, &NumBytes, NULL);
		if(size != NumBytes)
		{
			Error("Could not write data(gData.SubLevelNum) from file(%s) at data point %d .", S, size);
			CloseHandle(hFile);
			return 0;
		}
		*/

		size = sizeof(unsigned __int8);
		WriteFile(hFile, &gData.type, size, &NumBytes, NULL);
		if(size != NumBytes)
		{
			Error("Could not write data(gData.type) from file(%s) at data point %d .", S, size);
			CloseHandle(hFile);
			return 0;
		}

		size = sizeof(unsigned __int16);
		WriteFile(hFile, &gData.size, size, &NumBytes, NULL);
		if(size != NumBytes)
		{
			Error("Could not write data(gData.size) from file(%s) at data point %d .", S, size);
			CloseHandle(hFile);
			return 0;
		}

		size = gData.size;
		WriteFile(hFile, gData.data, size, &NumBytes, NULL);
		if(size != NumBytes)
		{
			Error("Could not write data(gData.data) from file(%s) at data point %d .", S, size);
			CloseHandle(hFile);
			return 0;
		}

		CloseHandle(hFile);
		return 1;
	};

};


#endif