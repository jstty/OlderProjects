	TITLE	D:\Game Programming\Moggie Software Games\old code\old Skull X\C++ Files\ddutil.cpp
	.386P
include listing.inc
if @Version gt 510
.model FLAT
else
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
_DATA	SEGMENT DWORD USE32 PUBLIC 'DATA'
_DATA	ENDS
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
_BSS	SEGMENT DWORD USE32 PUBLIC 'BSS'
_BSS	ENDS
$$SYMBOLS	SEGMENT BYTE USE32 'DEBSYM'
$$SYMBOLS	ENDS
$$TYPES	SEGMENT BYTE USE32 'DEBTYP'
$$TYPES	ENDS
_TLS	SEGMENT DWORD USE32 PUBLIC 'TLS'
_TLS	ENDS
;	COMDAT ??_C@_0BA@MHBC@handle?5is?5null?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@HDAN@ddcopybitmap?5failed?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BM@GIBL@createcompatible?5dc?5failed?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BG@IDLN@lock?5resource?5failed?6?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??8@YAHABU_GUID@@0@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?JumptoFirstCel@LAYER@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetSize@LAYER@@QAEXJJ@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetHotSpot@LAYER@@QAEXJJ@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _DDLoadBitmap
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _DDReLoadBitmap
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _DDCopyBitmap
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _DDLoadPalette
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _DDColorMatch
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _DDSetColorKey
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	_DDLoadBitmap
PUBLIC	_DDCopyBitmap
EXTRN	__imp__GetModuleHandleA@4:NEAR
EXTRN	__imp__LoadImageA@24:NEAR
EXTRN	__imp__DeleteObject@4:NEAR
EXTRN	_memset:NEAR
EXTRN	__imp__GetObjectA@12:NEAR
;	COMDAT _DDLoadBitmap
_TEXT	SEGMENT
_pdd$ = 8
_szBitmap$ = 12
_dx$ = 16
_dy$ = 20
_hbm$ = -4
_bm$ = -28
_ddsd$ = -152
_pdds$ = -156
_DDLoadBitmap PROC NEAR					; COMDAT

; 28   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 220				; 000000dcH
	push	ebx
	push	esi
	push	edi

; 29   :     HBITMAP                 hbm;
; 30   :     BITMAP                  bm;
; 31   :     DD_SDESC								ddsd;
; 32   :     DD_SURFACE							pdds;
; 33   : 
; 34   :     //
; 35   :     //  Try to load the bitmap as a resource, if that fails, try it as a file
; 36   :     //
; 37   :     hbm = (HBITMAP) LoadImage(GetModuleHandle(NULL), szBitmap, IMAGE_BITMAP, dx,
; 38   :                               dy, LR_CREATEDIBSECTION);

	push	8192					; 00002000H
	mov	eax, DWORD PTR _dy$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dx$[ebp]
	push	ecx
	push	0
	mov	edx, DWORD PTR _szBitmap$[ebp]
	push	edx
	push	0
	call	DWORD PTR __imp__GetModuleHandleA@4
	push	eax
	call	DWORD PTR __imp__LoadImageA@24
	mov	DWORD PTR _hbm$[ebp], eax

; 39   :     if (hbm == NULL)

	cmp	DWORD PTR _hbm$[ebp], 0
	jne	SHORT $L46892

; 41   :                                   LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	push	8208					; 00002010H
	mov	eax, DWORD PTR _dy$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dx$[ebp]
	push	ecx
	push	0
	mov	edx, DWORD PTR _szBitmap$[ebp]
	push	edx
	push	0
	call	DWORD PTR __imp__LoadImageA@24
	mov	DWORD PTR _hbm$[ebp], eax
$L46892:

; 42   :     if (hbm == NULL)

	cmp	DWORD PTR _hbm$[ebp], 0
	jne	SHORT $L46894

; 43   :         return NULL;

	xor	eax, eax
	jmp	$L46886
$L46894:

; 44   :     //
; 45   :     // Get size of the bitmap
; 46   :     //
; 47   :     GetObject(hbm, sizeof(bm), &bm);

	lea	eax, DWORD PTR _bm$[ebp]
	push	eax
	push	24					; 00000018H
	mov	ecx, DWORD PTR _hbm$[ebp]
	push	ecx
	call	DWORD PTR __imp__GetObjectA@12

; 48   :     //
; 49   :     // Create a DirectDrawSurface for this bitmap
; 50   :     //
; 51   :     ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	edx, DWORD PTR _ddsd$[ebp]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 52   :     ddsd.dwSize = sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 53   :     ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 54   :     ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;

	mov	DWORD PTR _ddsd$[ebp+104], 64		; 00000040H

; 55   :     ddsd.dwWidth = bm.bmWidth;

	mov	eax, DWORD PTR _bm$[ebp+4]
	mov	DWORD PTR _ddsd$[ebp+12], eax

; 56   :     ddsd.dwHeight = bm.bmHeight;

	mov	ecx, DWORD PTR _bm$[ebp+8]
	mov	DWORD PTR _ddsd$[ebp+8], ecx

; 57   :     if (pdd->CreateSurface(&ddsd, &pdds, NULL) != DD_OK)

	push	0
	lea	edx, DWORD PTR _pdds$[ebp]
	push	edx
	lea	eax, DWORD PTR _ddsd$[ebp]
	push	eax
	mov	ecx, DWORD PTR _pdd$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _pdd$[ebp]
	push	eax
	call	DWORD PTR [edx+24]
	test	eax, eax
	je	SHORT $L46896

; 58   :         return NULL;

	xor	eax, eax
	jmp	SHORT $L46886
$L46896:

; 59   :     DDCopyBitmap(pdds, hbm, 0, 0, 0, 0);

	push	0
	push	0
	push	0
	push	0
	mov	ecx, DWORD PTR _hbm$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pdds$[ebp]
	push	edx
	call	_DDCopyBitmap
	add	esp, 24					; 00000018H

; 60   :     DeleteObject(hbm);

	mov	eax, DWORD PTR _hbm$[ebp]
	push	eax
	call	DWORD PTR __imp__DeleteObject@4

; 61   :     return pdds;

	mov	eax, DWORD PTR _pdds$[ebp]
$L46886:

; 62   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_DDLoadBitmap ENDP
_TEXT	ENDS
PUBLIC	_DDReLoadBitmap
PUBLIC	??_C@_0BA@MHBC@handle?5is?5null?6?$AA@		; `string'
PUBLIC	??_C@_0BF@HDAN@ddcopybitmap?5failed?6?$AA@	; `string'
EXTRN	__imp__OutputDebugStringA@4:NEAR
;	COMDAT ??_C@_0BA@MHBC@handle?5is?5null?6?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\ddutil.cpp
CONST	SEGMENT
??_C@_0BA@MHBC@handle?5is?5null?6?$AA@ DB 'handle is null', 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@HDAN@ddcopybitmap?5failed?6?$AA@
CONST	SEGMENT
??_C@_0BF@HDAN@ddcopybitmap?5failed?6?$AA@ DB 'ddcopybitmap failed', 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT _DDReLoadBitmap
_TEXT	SEGMENT
_pdds$ = 8
_szBitmap$ = 12
_hbm$ = -4
_hr$ = -8
_DDReLoadBitmap PROC NEAR				; COMDAT

; 74   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi

; 75   :     HBITMAP                 hbm;
; 76   :     HRESULT                 hr;
; 77   : 
; 78   :     //
; 79   :     //  Try to load the bitmap as a resource, if that fails, try it as a file
; 80   :     //
; 81   :     hbm = (HBITMAP) LoadImage(GetModuleHandle(NULL), szBitmap, IMAGE_BITMAP, 0,
; 82   :                               0, LR_CREATEDIBSECTION);

	push	8192					; 00002000H
	push	0
	push	0
	push	0
	mov	eax, DWORD PTR _szBitmap$[ebp]
	push	eax
	push	0
	call	DWORD PTR __imp__GetModuleHandleA@4
	push	eax
	call	DWORD PTR __imp__LoadImageA@24
	mov	DWORD PTR _hbm$[ebp], eax

; 83   :     if (hbm == NULL)

	cmp	DWORD PTR _hbm$[ebp], 0
	jne	SHORT $L46904

; 85   :                                   LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	push	8208					; 00002010H
	push	0
	push	0
	push	0
	mov	ecx, DWORD PTR _szBitmap$[ebp]
	push	ecx
	push	0
	call	DWORD PTR __imp__LoadImageA@24
	mov	DWORD PTR _hbm$[ebp], eax
$L46904:

; 86   :     if (hbm == NULL)

	cmp	DWORD PTR _hbm$[ebp], 0
	jne	SHORT $L46906

; 88   :         OutputDebugString("handle is null\n");

	push	OFFSET FLAT:??_C@_0BA@MHBC@handle?5is?5null?6?$AA@ ; `string'
	call	DWORD PTR __imp__OutputDebugStringA@4

; 89   :         return E_FAIL;

	mov	eax, -2147467259			; 80004005H
	jmp	SHORT $L46900
$L46906:

; 91   :     hr = DDCopyBitmap(pdds, hbm, 0, 0, 0, 0);

	push	0
	push	0
	push	0
	push	0
	mov	edx, DWORD PTR _hbm$[ebp]
	push	edx
	mov	eax, DWORD PTR _pdds$[ebp]
	push	eax
	call	_DDCopyBitmap
	add	esp, 24					; 00000018H
	mov	DWORD PTR _hr$[ebp], eax

; 92   :     if (hr != DD_OK)

	cmp	DWORD PTR _hr$[ebp], 0
	je	SHORT $L46910

; 94   :         OutputDebugString("ddcopybitmap failed\n");

	push	OFFSET FLAT:??_C@_0BF@HDAN@ddcopybitmap?5failed?6?$AA@ ; `string'
	call	DWORD PTR __imp__OutputDebugStringA@4
$L46910:

; 96   :     DeleteObject(hbm);

	mov	ecx, DWORD PTR _hbm$[ebp]
	push	ecx
	call	DWORD PTR __imp__DeleteObject@4

; 97   :     return hr;

	mov	eax, DWORD PTR _hr$[ebp]
$L46900:

; 98   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_DDReLoadBitmap ENDP
_TEXT	ENDS
PUBLIC	??_C@_0BM@GIBL@createcompatible?5dc?5failed?6?$AA@ ; `string'
EXTRN	__imp__SelectObject@8:NEAR
EXTRN	__imp__StretchBlt@44:NEAR
EXTRN	__imp__CreateCompatibleDC@4:NEAR
EXTRN	__imp__DeleteDC@4:NEAR
;	COMDAT ??_C@_0BM@GIBL@createcompatible?5dc?5failed?6?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\ddutil.cpp
CONST	SEGMENT
??_C@_0BM@GIBL@createcompatible?5dc?5failed?6?$AA@ DB 'createcompatible d'
	DB	'c failed', 0aH, 00H				; `string'
CONST	ENDS
;	COMDAT _DDCopyBitmap
_TEXT	SEGMENT
_pdds$ = 8
_hbm$ = 12
_x$ = 16
_y$ = 20
_dx$ = 24
_dy$ = 28
_hdcImage$ = -4
_hdc$ = -8
_bm$ = -32
_ddsd$ = -156
_hr$ = -160
_DDCopyBitmap PROC NEAR					; COMDAT

; 110  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 232				; 000000e8H
	push	ebx
	push	esi
	push	edi

; 111  :     HDC                     hdcImage;
; 112  :     HDC                     hdc;
; 113  :     BITMAP                  bm;
; 114  :     DD_SDESC          ddsd;
; 115  :     HRESULT                 hr;
; 116  : 
; 117  :     if (hbm == NULL || pdds == NULL)

	cmp	DWORD PTR _hbm$[ebp], 0
	je	SHORT $L46926
	cmp	DWORD PTR _pdds$[ebp], 0
	jne	SHORT $L46925
$L46926:

; 118  :         return E_FAIL;

	mov	eax, -2147467259			; 80004005H
	jmp	$L46919
$L46925:

; 119  :     //
; 120  :     // Make sure this surface is restored.
; 121  :     //
; 122  :     pdds->Restore();

	mov	eax, DWORD PTR _pdds$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _pdds$[ebp]
	push	edx
	call	DWORD PTR [ecx+108]

; 123  :     //
; 124  :     // Select bitmap into a memoryDC so we can use it.
; 125  :     //
; 126  :     hdcImage = CreateCompatibleDC(NULL);

	push	0
	call	DWORD PTR __imp__CreateCompatibleDC@4
	mov	DWORD PTR _hdcImage$[ebp], eax

; 127  :     if (!hdcImage)

	cmp	DWORD PTR _hdcImage$[ebp], 0
	jne	SHORT $L46928

; 128  :         OutputDebugString("createcompatible dc failed\n");

	push	OFFSET FLAT:??_C@_0BM@GIBL@createcompatible?5dc?5failed?6?$AA@ ; `string'
	call	DWORD PTR __imp__OutputDebugStringA@4
$L46928:

; 129  :     SelectObject(hdcImage, hbm);

	mov	eax, DWORD PTR _hbm$[ebp]
	push	eax
	mov	ecx, DWORD PTR _hdcImage$[ebp]
	push	ecx
	call	DWORD PTR __imp__SelectObject@8

; 130  :     //
; 131  :     // Get size of the bitmap
; 132  :     //
; 133  :     GetObject(hbm, sizeof(bm), &bm);

	lea	edx, DWORD PTR _bm$[ebp]
	push	edx
	push	24					; 00000018H
	mov	eax, DWORD PTR _hbm$[ebp]
	push	eax
	call	DWORD PTR __imp__GetObjectA@12

; 134  :     dx = dx == 0 ? bm.bmWidth : dx;     // Use the passed size, unless zero

	cmp	DWORD PTR _dx$[ebp], 0
	jne	SHORT $L47055
	mov	ecx, DWORD PTR _bm$[ebp+4]
	mov	DWORD PTR -164+[ebp], ecx
	jmp	SHORT $L47056
$L47055:
	mov	edx, DWORD PTR _dx$[ebp]
	mov	DWORD PTR -164+[ebp], edx
$L47056:
	mov	eax, DWORD PTR -164+[ebp]
	mov	DWORD PTR _dx$[ebp], eax

; 135  :     dy = dy == 0 ? bm.bmHeight : dy;

	cmp	DWORD PTR _dy$[ebp], 0
	jne	SHORT $L47057
	mov	ecx, DWORD PTR _bm$[ebp+8]
	mov	DWORD PTR -168+[ebp], ecx
	jmp	SHORT $L47058
$L47057:
	mov	edx, DWORD PTR _dy$[ebp]
	mov	DWORD PTR -168+[ebp], edx
$L47058:
	mov	eax, DWORD PTR -168+[ebp]
	mov	DWORD PTR _dy$[ebp], eax

; 136  :     //
; 137  :     // Get size of surface.
; 138  :     //
; 139  :     ddsd.dwSize = sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 140  :     ddsd.dwFlags = DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 6

; 141  :     pdds->GetSurfaceDesc(&ddsd);

	lea	ecx, DWORD PTR _ddsd$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pdds$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _pdds$[ebp]
	push	ecx
	call	DWORD PTR [eax+88]

; 142  : 
; 143  :     if ((hr = pdds->GetDC(&hdc)) == DD_OK)

	lea	edx, DWORD PTR _hdc$[ebp]
	push	edx
	mov	eax, DWORD PTR _pdds$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _pdds$[ebp]
	push	edx
	call	DWORD PTR [ecx+68]
	mov	DWORD PTR _hr$[ebp], eax
	cmp	DWORD PTR _hr$[ebp], 0
	jne	SHORT $L46931

; 145  :         StretchBlt(hdc, 0, 0, ddsd.dwWidth, ddsd.dwHeight, hdcImage, x, y,
; 146  :                    dx, dy, SRCCOPY);

	push	13369376				; 00cc0020H
	mov	eax, DWORD PTR _dy$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _y$[ebp]
	push	edx
	mov	eax, DWORD PTR _x$[ebp]
	push	eax
	mov	ecx, DWORD PTR _hdcImage$[ebp]
	push	ecx
	mov	edx, DWORD PTR _ddsd$[ebp+8]
	push	edx
	mov	eax, DWORD PTR _ddsd$[ebp+12]
	push	eax
	push	0
	push	0
	mov	ecx, DWORD PTR _hdc$[ebp]
	push	ecx
	call	DWORD PTR __imp__StretchBlt@44

; 147  :         pdds->ReleaseDC(hdc);

	mov	edx, DWORD PTR _hdc$[ebp]
	push	edx
	mov	eax, DWORD PTR _pdds$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _pdds$[ebp]
	push	edx
	call	DWORD PTR [ecx+104]
$L46931:

; 149  :     DeleteDC(hdcImage);

	mov	eax, DWORD PTR _hdcImage$[ebp]
	push	eax
	call	DWORD PTR __imp__DeleteDC@4

; 150  :     return hr;

	mov	eax, DWORD PTR _hr$[ebp]
$L46919:

; 151  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_DDCopyBitmap ENDP
_TEXT	ENDS
PUBLIC	_DDLoadPalette
PUBLIC	??_C@_0BG@IDLN@lock?5resource?5failed?6?$AA@	; `string'
EXTRN	__imp__FindResourceA@12:NEAR
EXTRN	__imp__LoadResource@8:NEAR
EXTRN	__imp___lopen@8:NEAR
EXTRN	__imp__LockResource@4:NEAR
EXTRN	__imp___lread@12:NEAR
EXTRN	__imp___lclose@4:NEAR
;	COMDAT ??_C@_0BG@IDLN@lock?5resource?5failed?6?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\ddutil.cpp
CONST	SEGMENT
??_C@_0BG@IDLN@lock?5resource?5failed?6?$AA@ DB 'lock resource failed', 0aH
	DB	00H						; `string'
CONST	ENDS
;	COMDAT _DDLoadPalette
_TEXT	SEGMENT
_pdd$ = 8
_szBitmap$ = 12
_ddpal$ = -4
_i$ = -8
_n$ = -12
_fh$ = -16
_h$ = -20
_lpbi$ = -24
_ape$ = -1048
_prgb$ = -1052
_bf$46974 = -1068
_bi$46975 = -1108
_r$46986 = -1112
_DDLoadPalette PROC NEAR				; COMDAT

; 164  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 1176				; 00000498H
	push	ebx
	push	esi
	push	edi

; 165  :     DD_PALETTE							ddpal;
; 166  :     int                     i;
; 167  :     int                     n;
; 168  :     int                     fh;
; 169  :     HRSRC                   h;
; 170  :     LPBITMAPINFOHEADER      lpbi;
; 171  :     PALETTEENTRY            ape[256];
; 172  :     RGBQUAD                *prgb;
; 173  : 
; 174  :     //
; 175  :     // Build a 332 palette as the default.
; 176  :     //
; 177  :     for (i = 0; i < 256; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L46945
$L46946:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L46945:
	cmp	DWORD PTR _i$[ebp], 256			; 00000100H
	jge	SHORT $L46947

; 179  :         ape[i].peRed = (BYTE) (((i >> 5) & 0x07) * 255 / 7);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 5
	and	eax, 7
	imul	eax, 255				; 000000ffH
	cdq
	mov	ecx, 7
	idiv	ecx
	mov	edx, DWORD PTR _i$[ebp]
	mov	BYTE PTR _ape$[ebp+edx*4], al

; 180  :         ape[i].peGreen = (BYTE) (((i >> 2) & 0x07) * 255 / 7);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 2
	and	eax, 7
	imul	eax, 255				; 000000ffH
	cdq
	mov	ecx, 7
	idiv	ecx
	mov	edx, DWORD PTR _i$[ebp]
	mov	BYTE PTR _ape$[ebp+edx*4+1], al

; 181  :         ape[i].peBlue = (BYTE) (((i >> 0) & 0x03) * 255 / 3);

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 3
	imul	eax, 255				; 000000ffH
	cdq
	mov	ecx, 3
	idiv	ecx
	mov	edx, DWORD PTR _i$[ebp]
	mov	BYTE PTR _ape$[ebp+edx*4+2], al

; 182  :         ape[i].peFlags = (BYTE) 0;

	mov	eax, DWORD PTR _i$[ebp]
	mov	BYTE PTR _ape$[ebp+eax*4+3], 0

; 183  :     }

	jmp	SHORT $L46946
$L46947:

; 184  :     //
; 185  :     // Get a pointer to the bitmap resource.
; 186  :     //
; 187  :     if (szBitmap && (h = FindResource(NULL, szBitmap, RT_BITMAP)))

	cmp	DWORD PTR _szBitmap$[ebp], 0
	je	$L46955
	push	2
	mov	ecx, DWORD PTR _szBitmap$[ebp]
	push	ecx
	push	0
	call	DWORD PTR __imp__FindResourceA@12
	mov	DWORD PTR _h$[ebp], eax
	cmp	DWORD PTR _h$[ebp], 0
	je	$L46955

; 189  :         lpbi = (LPBITMAPINFOHEADER) LockResource(LoadResource(NULL, h));

	mov	edx, DWORD PTR _h$[ebp]
	push	edx
	push	0
	call	DWORD PTR __imp__LoadResource@8
	push	eax
	call	DWORD PTR __imp__LockResource@4
	mov	DWORD PTR _lpbi$[ebp], eax

; 190  :         if (!lpbi)

	cmp	DWORD PTR _lpbi$[ebp], 0
	jne	SHORT $L46957

; 191  :             OutputDebugString("lock resource failed\n");

	push	OFFSET FLAT:??_C@_0BG@IDLN@lock?5resource?5failed?6?$AA@ ; `string'
	call	DWORD PTR __imp__OutputDebugStringA@4
$L46957:

; 192  :         prgb = (RGBQUAD *) ((BYTE *) lpbi + lpbi->biSize);

	mov	eax, DWORD PTR _lpbi$[ebp]
	mov	ecx, DWORD PTR _lpbi$[ebp]
	add	ecx, DWORD PTR [eax]
	mov	DWORD PTR _prgb$[ebp], ecx

; 193  :         if (lpbi == NULL || lpbi->biSize < sizeof(BITMAPINFOHEADER))

	cmp	DWORD PTR _lpbi$[ebp], 0
	je	SHORT $L46963
	mov	edx, DWORD PTR _lpbi$[ebp]
	cmp	DWORD PTR [edx], 40			; 00000028H
	jae	SHORT $L46962
$L46963:

; 194  :             n = 0;

	mov	DWORD PTR _n$[ebp], 0

; 195  :         else if (lpbi->biBitCount > 8)

	jmp	SHORT $L46968
$L46962:
	mov	eax, DWORD PTR _lpbi$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+14]
	cmp	ecx, 8
	jle	SHORT $L46965

; 196  :             n = 0;

	mov	DWORD PTR _n$[ebp], 0

; 197  :         else if (lpbi->biClrUsed == 0)

	jmp	SHORT $L46968
$L46965:
	mov	edx, DWORD PTR _lpbi$[ebp]
	cmp	DWORD PTR [edx+32], 0
	jne	SHORT $L46967

; 198  :             n = 1 << lpbi->biBitCount;

	mov	eax, DWORD PTR _lpbi$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+14]
	mov	edx, 1
	shl	edx, cl
	mov	DWORD PTR _n$[ebp], edx

; 199  :         else

	jmp	SHORT $L46968
$L46967:

; 200  :             n = lpbi->biClrUsed;

	mov	eax, DWORD PTR _lpbi$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	mov	DWORD PTR _n$[ebp], ecx
$L46968:

; 201  :         //
; 202  :         //  A DIB color table has its colors stored BGR not RGB
; 203  :         //  so flip them around.
; 204  :         //
; 205  :         for (i = 0; i < n; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L46969
$L46970:
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L46969:
	mov	eax, DWORD PTR _i$[ebp]
	cmp	eax, DWORD PTR _n$[ebp]
	jge	SHORT $L46971

; 207  :             ape[i].peRed = prgb[i].rgbRed;

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _prgb$[ebp]
	mov	dl, BYTE PTR [eax+edx*4+2]
	mov	BYTE PTR _ape$[ebp+ecx*4], dl

; 208  :             ape[i].peGreen = prgb[i].rgbGreen;

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _prgb$[ebp]
	mov	cl, BYTE PTR [edx+ecx*4+1]
	mov	BYTE PTR _ape$[ebp+eax*4+1], cl

; 209  :             ape[i].peBlue = prgb[i].rgbBlue;

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _prgb$[ebp]
	mov	al, BYTE PTR [ecx+eax*4]
	mov	BYTE PTR _ape$[ebp+edx*4+2], al

; 210  :             ape[i].peFlags = 0;

	mov	ecx, DWORD PTR _i$[ebp]
	mov	BYTE PTR _ape$[ebp+ecx*4+3], 0

; 211  :         }

	jmp	SHORT $L46970
$L46971:

; 213  :     else if (szBitmap && (fh = _lopen(szBitmap, OF_READ)) != -1)

	jmp	$L46985
$L46955:
	cmp	DWORD PTR _szBitmap$[ebp], 0
	je	$L46985
	push	0
	mov	edx, DWORD PTR _szBitmap$[ebp]
	push	edx
	call	DWORD PTR __imp___lopen@8
	mov	DWORD PTR _fh$[ebp], eax
	cmp	DWORD PTR _fh$[ebp], -1
	je	$L46985

; 215  :         BITMAPFILEHEADER        bf;
; 216  :         BITMAPINFOHEADER        bi;
; 217  : 
; 218  :         _lread(fh, &bf, sizeof(bf));

	push	14					; 0000000eH
	lea	eax, DWORD PTR _bf$46974[ebp]
	push	eax
	mov	ecx, DWORD PTR _fh$[ebp]
	push	ecx
	call	DWORD PTR __imp___lread@12

; 219  :         _lread(fh, &bi, sizeof(bi));

	push	40					; 00000028H
	lea	edx, DWORD PTR _bi$46975[ebp]
	push	edx
	mov	eax, DWORD PTR _fh$[ebp]
	push	eax
	call	DWORD PTR __imp___lread@12

; 220  :         _lread(fh, ape, sizeof(ape));

	push	1024					; 00000400H
	lea	ecx, DWORD PTR _ape$[ebp]
	push	ecx
	mov	edx, DWORD PTR _fh$[ebp]
	push	edx
	call	DWORD PTR __imp___lread@12

; 221  :         _lclose(fh);

	mov	eax, DWORD PTR _fh$[ebp]
	push	eax
	call	DWORD PTR __imp___lclose@4

; 222  :         if (bi.biSize != sizeof(BITMAPINFOHEADER))

	cmp	DWORD PTR _bi$46975[ebp], 40		; 00000028H
	je	SHORT $L46977

; 223  :             n = 0;

	mov	DWORD PTR _n$[ebp], 0

; 224  :         else if (bi.biBitCount > 8)

	jmp	SHORT $L46982
$L46977:
	mov	ecx, DWORD PTR _bi$46975[ebp+14]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 8
	jle	SHORT $L46979

; 225  :             n = 0;

	mov	DWORD PTR _n$[ebp], 0

; 226  :         else if (bi.biClrUsed == 0)

	jmp	SHORT $L46982
$L46979:
	cmp	DWORD PTR _bi$46975[ebp+32], 0
	jne	SHORT $L46981

; 227  :             n = 1 << bi.biBitCount;

	mov	ecx, DWORD PTR _bi$46975[ebp+14]
	and	ecx, 65535				; 0000ffffH
	mov	edx, 1
	shl	edx, cl
	mov	DWORD PTR _n$[ebp], edx

; 228  :         else

	jmp	SHORT $L46982
$L46981:

; 229  :             n = bi.biClrUsed;

	mov	eax, DWORD PTR _bi$46975[ebp+32]
	mov	DWORD PTR _n$[ebp], eax
$L46982:

; 230  :         //
; 231  :         //  A DIB color table has its colors stored BGR not RGB
; 232  :         //  so flip them around.
; 233  :         //
; 234  :         for (i = 0; i < n; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L46983
$L46984:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L46983:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _n$[ebp]
	jge	SHORT $L46985

; 236  :             BYTE        r = ape[i].peRed;

	mov	eax, DWORD PTR _i$[ebp]
	mov	cl, BYTE PTR _ape$[ebp+eax*4]
	mov	BYTE PTR _r$46986[ebp], cl

; 237  : 
; 238  :             ape[i].peRed = ape[i].peBlue;

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _i$[ebp]
	mov	cl, BYTE PTR _ape$[ebp+eax*4+2]
	mov	BYTE PTR _ape$[ebp+edx*4], cl

; 239  :             ape[i].peBlue = r;

	mov	edx, DWORD PTR _i$[ebp]
	mov	al, BYTE PTR _r$46986[ebp]
	mov	BYTE PTR _ape$[ebp+edx*4+2], al

; 240  :         }

	jmp	SHORT $L46984
$L46985:

; 242  :     pdd->CreatePalette(DDPCAPS_8BIT, ape, &ddpal, NULL);

	push	0
	lea	ecx, DWORD PTR _ddpal$[ebp]
	push	ecx
	lea	edx, DWORD PTR _ape$[ebp]
	push	edx
	push	4
	mov	eax, DWORD PTR _pdd$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _pdd$[ebp]
	push	edx
	call	DWORD PTR [ecx+20]

; 243  :     return ddpal;

	mov	eax, DWORD PTR _ddpal$[ebp]

; 244  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_DDLoadPalette ENDP
_TEXT	ENDS
PUBLIC	_DDColorMatch
EXTRN	__imp__SetPixel@16:NEAR
EXTRN	__imp__GetPixel@12:NEAR
;	COMDAT _DDColorMatch
_TEXT	SEGMENT
_pdds$ = 8
_rgb$ = 12
_rgbT$ = -4
_hdc$ = -8
_dw$ = -12
_ddsd$ = -136
_hres$ = -140
_DDColorMatch PROC NEAR					; COMDAT

; 257  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 204				; 000000ccH
	push	ebx
	push	esi
	push	edi

; 258  :     COLORREF                rgbT;
; 259  :     HDC                     hdc;
; 260  :     DWORD                   dw = CLR_INVALID;

	mov	DWORD PTR _dw$[ebp], -1

; 261  :     DD_SDESC          ddsd;
; 262  :     HRESULT                 hres;
; 263  : 
; 264  :     //
; 265  :     //  Use GDI SetPixel to color match for us
; 266  :     //
; 267  :     if (rgb != CLR_INVALID && pdds->GetDC(&hdc) == DD_OK)

	cmp	DWORD PTR _rgb$[ebp], -1
	je	SHORT $L46997
	lea	eax, DWORD PTR _hdc$[ebp]
	push	eax
	mov	ecx, DWORD PTR _pdds$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _pdds$[ebp]
	push	eax
	call	DWORD PTR [edx+68]
	test	eax, eax
	jne	SHORT $L46997

; 269  :         rgbT = GetPixel(hdc, 0, 0);     // Save current pixel value

	push	0
	push	0
	mov	ecx, DWORD PTR _hdc$[ebp]
	push	ecx
	call	DWORD PTR __imp__GetPixel@12
	mov	DWORD PTR _rgbT$[ebp], eax

; 270  :         SetPixel(hdc, 0, 0, rgb);       // Set our value

	mov	edx, DWORD PTR _rgb$[ebp]
	push	edx
	push	0
	push	0
	mov	eax, DWORD PTR _hdc$[ebp]
	push	eax
	call	DWORD PTR __imp__SetPixel@16

; 271  :         pdds->ReleaseDC(hdc);

	mov	ecx, DWORD PTR _hdc$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pdds$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _pdds$[ebp]
	push	ecx
	call	DWORD PTR [eax+104]
$L46997:

; 273  :     //
; 274  :     // Now lock the surface so we can read back the converted color
; 275  :     //
; 276  :     ddsd.dwSize = sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH
$L46999:

; 277  :     while ((hres = pdds->Lock(NULL, &ddsd, 0, NULL)) == DDERR_WASSTILLDRAWING)

	push	0
	push	0
	lea	edx, DWORD PTR _ddsd$[ebp]
	push	edx
	push	0
	mov	eax, DWORD PTR _pdds$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _pdds$[ebp]
	push	edx
	call	DWORD PTR [ecx+100]
	mov	DWORD PTR _hres$[ebp], eax
	cmp	DWORD PTR _hres$[ebp], -2005532132	; 8876021cH
	jne	SHORT $L47000

; 278  :         ;

	jmp	SHORT $L46999
$L47000:

; 279  :     if (hres == DD_OK)

	cmp	DWORD PTR _hres$[ebp], 0
	jne	SHORT $L47006

; 281  :         dw = *(DWORD *) ddsd.lpSurface;                 // Get DWORD

	mov	eax, DWORD PTR _ddsd$[ebp+36]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _dw$[ebp], ecx

; 282  :         if (ddsd.ddpfPixelFormat.dwRGBBitCount < 32)

	cmp	DWORD PTR _ddsd$[ebp+84], 32		; 00000020H
	jae	SHORT $L47008

; 283  :             dw &= (1 << ddsd.ddpfPixelFormat.dwRGBBitCount) - 1;  // Mask it to bpp

	mov	edx, 1
	mov	ecx, DWORD PTR _ddsd$[ebp+84]
	shl	edx, cl
	sub	edx, 1
	mov	eax, DWORD PTR _dw$[ebp]
	and	eax, edx
	mov	DWORD PTR _dw$[ebp], eax
$L47008:

; 284  :         pdds->Unlock(NULL);

	push	0
	mov	ecx, DWORD PTR _pdds$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _pdds$[ebp]
	push	eax
	call	DWORD PTR [edx+128]
$L47006:

; 286  :     //
; 287  :     //  Now put the color that was there back.
; 288  :     //
; 289  :     if (rgb != CLR_INVALID && pdds->GetDC(&hdc) == DD_OK)

	cmp	DWORD PTR _rgb$[ebp], -1
	je	SHORT $L47010
	lea	ecx, DWORD PTR _hdc$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pdds$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _pdds$[ebp]
	push	ecx
	call	DWORD PTR [eax+68]
	test	eax, eax
	jne	SHORT $L47010

; 291  :         SetPixel(hdc, 0, 0, rgbT);

	mov	edx, DWORD PTR _rgbT$[ebp]
	push	edx
	push	0
	push	0
	mov	eax, DWORD PTR _hdc$[ebp]
	push	eax
	call	DWORD PTR __imp__SetPixel@16

; 292  :         pdds->ReleaseDC(hdc);

	mov	ecx, DWORD PTR _hdc$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pdds$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _pdds$[ebp]
	push	ecx
	call	DWORD PTR [eax+104]
$L47010:

; 294  :     return dw;

	mov	eax, DWORD PTR _dw$[ebp]

; 295  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_DDColorMatch ENDP
_TEXT	ENDS
PUBLIC	_DDSetColorKey
;	COMDAT _DDSetColorKey
_TEXT	SEGMENT
_pdds$ = 8
_rgb$ = 12
_ddck$ = -8
_DDSetColorKey PROC NEAR				; COMDAT

; 308  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi

; 309  :     DDCOLORKEY              ddck;
; 310  : 
; 311  :     ddck.dwColorSpaceLowValue = DDColorMatch(pdds, rgb);

	mov	eax, DWORD PTR _rgb$[ebp]
	push	eax
	mov	ecx, DWORD PTR _pdds$[ebp]
	push	ecx
	call	_DDColorMatch
	add	esp, 8
	mov	DWORD PTR _ddck$[ebp], eax

; 312  :     ddck.dwColorSpaceHighValue = ddck.dwColorSpaceLowValue;

	mov	edx, DWORD PTR _ddck$[ebp]
	mov	DWORD PTR _ddck$[ebp+4], edx

; 313  :     return pdds->SetColorKey(DDCKEY_SRCBLT, &ddck);

	lea	eax, DWORD PTR _ddck$[ebp]
	push	eax
	push	8
	mov	ecx, DWORD PTR _pdds$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _pdds$[ebp]
	push	eax
	call	DWORD PTR [edx+116]

; 314  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_DDSetColorKey ENDP
_TEXT	ENDS
END
