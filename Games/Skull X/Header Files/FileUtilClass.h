////////////////////////////////////////////////////////////////////////
//	Program Name:	FileClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	File Util Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _FILE_UTIL
#define _FILE_UTIL

#include <windows.h>

#include "..\Header Files\ErrorClass.h"

class FILE_UTIL : public ERRORCLASS{
	private:
		//
		struct FILE_DATA{
			unsigned __int16 *Num;
			unsigned __int16 *Size;
			bool **Pointer;
			HGLOBAL	hNum;
			HGLOBAL	hSize;
			HGLOBAL	*hPointer;
			HGLOBAL	hP;
		};
		//FILE_DATA fData;
		unsigned __int8 NumfData;
	public:
		HMODULE			hDllFile;
		// Func.
		bool ReLoadMem(HGLOBAL &var, HGLOBAL &hmem, UINT size, __int8 *lc = NULL);
		bool LoadMem(HGLOBAL &var, HGLOBAL &hmem, UINT size, __int8 *lc = NULL);
		bool FreeMem(HGLOBAL &hmem, __int8 *lc = NULL);
		//
		HRESULT SaveDataFile(char *FileName, unsigned __int16 *n, bool **p, unsigned __int16 *s, unsigned __int8 num);
		HRESULT Load_Pointer_DataFile(char *FileName, bool **p, unsigned __int16 *s);
		HRESULT Load_NumSize_DataFile(char *File, unsigned __int8 *NumD, unsigned __int16 *n, unsigned __int16 *s);
		HRESULT FreeTempData(void);
};
typedef FILE_UTIL *P_FILE_UTIL, FAR *FP_FILE_UTIL;

#endif
