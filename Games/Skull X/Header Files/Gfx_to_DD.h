////////////////////////////////////////////////////////////////////////
//	Program Name:	Gfx_to_DD.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Gfx to Direct Draw header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _GFX_TO_DD
#define _GFX_TO_DD

// Decompressed "gi" into "data"
int DeCompress(RGB_PAL **data, GFX_INFO *gi);

// Load Graphics file
int LoadGfxFile(char *name, GFX_INFO *gi);

// Copy Bitmap Object to DDSuface
HRESULT SetBitmap(DD_SURFACE pdds, HBITMAP hbm, int dx, int dy);

DD_SURFACE GfxToDD(DD_OBJECT pdd, char *FileName);

#endif