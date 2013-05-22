/*==========================================================================
 *
 *  Copyright (C) 1998 Microsoft Corporation. All Rights Reserved.
 *
 *  File:       ddutil.cpp
 *  Content:    Routines for loading bitmap and palettes from resources
 *
 ***************************************************************************/

#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++ */
#endif	/* __cplusplus */

#include "..\Header Files\gfx.h"

extern DD_PALETTE						DDLoadPalette(DD_OBJECT					pdd, LPCSTR szBitmap);
extern DD_SURFACE						 DDLoadBitmap(DD_OBJECT					pdd, LPCSTR szBitmap, int dx, int dy);
extern HRESULT              DDReLoadBitmap(DD_SURFACE	pdds, LPCSTR szBitmap);
extern HRESULT              DDCopyBitmap(DD_SURFACE		pdds, HBITMAP hbm, int x, int y, int dx, int dy);
extern DWORD                DDColorMatch(DD_SURFACE		pdds, COLORREF rgb);
extern HRESULT              DDSetColorKey(DD_SURFACE	pdds, COLORREF rgb);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

