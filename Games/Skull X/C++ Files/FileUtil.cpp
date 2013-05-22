////////////////////////////////////////////////////////////////////////
//	Program Name:	FileUtil.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	File Util File
//	Date: 
////////////////////////////////////////////////////////////////////////
#include <stdio.h>

#include "..\Header Files\FileUtilClass.h"

//
//
//
bool FILE_UTIL::LoadMem(HGLOBAL &var, HGLOBAL &hmem, UINT size, __int8 *lc)
{
	SetLastError(0);

	if(hmem == NULL)
	{
		if((&lc) != NULL)
			lc = 0;

		//hmem = GlobalAlloc(GHND, size);

		//var = GlobalLock(hmem);

		hmem = GlobalAlloc(GHND, size);
		if( GetLastError() != NO_ERROR)
			return Error(NULL, "FILE_UTIL", "LoadMem:GlobalAlloc", GetLastError());

		var = GlobalLock(hmem);
		if((&lc) != NULL)
			lc++;

		if( GetLastError() != NO_ERROR )
			return Error(NULL, "FILE_UTIL", "LoadMem:GlobalLock", GetLastError());
	}
	else
	{
		if(ReLoadMem(var, hmem, size, lc))
			return 1;
	}

	return 0;
}
//
//
//
bool FILE_UTIL::ReLoadMem(HGLOBAL &var, HGLOBAL &hmem, UINT size, __int8 *lc)
{
	SetLastError(0);

	GlobalUnlock(hmem);
	if((&lc) != NULL)
		lc--;

	if( GetLastError() != NO_ERROR)
		return Error(NULL, "FILE_UTIL", "ReLoadMem:GlobalUnlock", GetLastError());

//	if((error = GetLastError()) != 0)
//			return 104;

	if(hmem != NULL)
	{
		hmem = GlobalReAlloc(hmem, size, GMEM_ZEROINIT);
		if( GetLastError() != NO_ERROR)
			return Error(NULL, "FILE_UTIL", "ReLoadMem:GlobalReAlloc", GetLastError());

//		hmem = GlobalReAlloc(hmem, size, GMEM_ZEROINIT);
//		if((error = GetLastError()) != 0)
//			return 104;

		var = GlobalLock(hmem);
		if((&lc) != NULL)
			lc++;

		if( GetLastError() != NO_ERROR )
			return Error(NULL, "FILE_UTIL", "LoadMem:GlobalLock", GetLastError());
	}
	else
		return Error(NULL, "FILE_UTIL", "ReLoadMem:???", GetLastError());

	return 0;
}
//
//
//
bool FILE_UTIL::FreeMem(HGLOBAL &hmem, __int8 *lc)
{
	SetLastError(0);

	if(hmem != NULL)
	{
		GlobalUnlock(hmem);
		if((&lc) != NULL)
			lc--;

		if( GetLastError() != NO_ERROR)
			return Error(NULL, "FILE_UTIL", "FreeMem:GlobalUnlock", GetLastError());


		GlobalDiscard(hmem);

		if( GetLastError() != NO_ERROR)
			return Error(NULL, "FILE_UTIL", "FreeMem:GlobalDiscard", GetLastError());

	}
	else
		return Error(NULL, "FILE_UTIL", "FreeMem:???", GetLastError());

	return 0;
}	
//
//
//
HRESULT FILE_UTIL::SaveDataFile(char *FileName, unsigned __int16 *n, bool **p, unsigned __int16 *s, unsigned __int8 num)
{
/*
	HANDLE CreateFile( 
		LPCTSTR lpFileName, // pointer to name of the file 
		DWORD dwDesiredAccess, // access (read-write) mode 
		DWORD dwShareMode, // share mode 
		LPSECURITY_ATTRIBUTES lpSecurityAttributes, // pointer to security attributes 
		DWORD dwCreationDistribution, // how to create 
		DWORD dwFlagsAndAttributes, // file attributes 
		HANDLE hTemplateFile // handle to file with attributes to copy 
		); 
	BOOL WriteFile( 
		HANDLE hFile, // handle to file to write to 
		LPCVOID lpBuffer, // pointer to data to write to file 
		DWORD nNumberOfBytesToWrite, // number of bytes to write 
		LPDWORD lpNumberOfBytesWritten, // pointer to number of bytes written 
		LPOVERLAPPED lpOverlapped // pointer to structure needed for overlapped I/O
		); 
*/
	HANDLE hFile;
	DWORD NumByteW = 0;
	//

	hFile = CreateFile(FileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);

	WriteFile(hFile, &num, sizeof(__int8), &NumByteW, NULL);

	unsigned __int16 Size = num*sizeof(__int16);
	WriteFile(hFile, n, Size, &NumByteW, NULL);
	if(NumByteW != Size)
	{
		if(!CloseHandle(hFile))
			return GetLastError();
		else
			return 105;
	}

	WriteFile(hFile, s, Size, &NumByteW, NULL);
	if(NumByteW != Size)
	{
		if(!CloseHandle(hFile))
			return GetLastError();
		else
			return 105;
	}

	for(int i = 0; i < NumfData; i++)
	{
		WriteFile(hFile, p[i], s[i], &NumByteW, NULL);
		if(NumByteW != s[i])
		{
			if(!CloseHandle(hFile))
				return GetLastError();
			else
				return 105;
		}
	}

	if(!CloseHandle(hFile))
		return GetLastError();

	return 0;
}
//
//
//
HRESULT FILE_UTIL::Load_Pointer_DataFile(char *FileName, bool **p, unsigned __int16 *s)
{
	HRESULT e = 0;
	HANDLE hFile = NULL;
	DWORD NumByteW = 0;
	USHORT NumD = 0;

	//
	hFile = CreateFile(FileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	if(hFile == NULL)
		return GetLastError();

	ReadFile(hFile, &NumD, sizeof(__int8), &NumByteW, NULL);
	if(NumByteW != 1)
	{
		if(!CloseHandle(hFile))
			return GetLastError();
		else
			return 105;
	}
	//
	NumByteW = 0;
	USHORT *Temp = new USHORT[2*NumD];
	ReadFile(hFile, Temp, 2*NumD*sizeof(__int16), &NumByteW, NULL);
	delete Temp;
	if(NumByteW != (2*NumD*sizeof(__int16)))
	{
		if(!CloseHandle(hFile))
			return GetLastError();
		else
			return 105;
	}
	//
	for(int i = 0; i < NumfData; i++)
	{
		//
		ReadFile(hFile, &(p[i]), s[i], &NumByteW, NULL);
		if(NumByteW != s[i])
		{
			if(!CloseHandle(hFile))
				return GetLastError();
			else
				return 105;
		}
	}

	if(!CloseHandle(hFile))
		return GetLastError();

	return 0;
}
//
//
//
HRESULT FILE_UTIL::Load_NumSize_DataFile(char *File, unsigned __int8 *NumD, unsigned __int16 *n, unsigned __int16 *s)
{
	HRESULT e = 0;
	HANDLE hFile = NULL;
	DWORD NumByteW = 0;
	//

	hFile = CreateFile(File, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	if(hFile == NULL)
		return GetLastError();

	ReadFile(hFile, &NumD, sizeof(__int8), &NumByteW, NULL);
	if(NumByteW != 1)
	{
		if(!CloseHandle(hFile))
			return GetLastError();
		else
			return 105;
	}
	//
	//
	NumByteW = 0;
	ReadFile(hFile, n, (*NumD)*(sizeof(__int16)), &NumByteW, NULL);
	if(NumByteW != ((*NumD)*(sizeof(__int16))))
	{
		if(!CloseHandle(hFile))
			return GetLastError();
		else
			return 105;
	}
	//
	//
	NumByteW = 0;
	ReadFile(hFile, s, (*NumD)*(sizeof(__int16)), &NumByteW, NULL);
	if(NumByteW != ((*NumD)*(sizeof(__int16))))
	{
		if(!CloseHandle(hFile))
			return GetLastError();
		else
			return 105;
	}

	if(!CloseHandle(hFile))
		return GetLastError();

	return 0;
}