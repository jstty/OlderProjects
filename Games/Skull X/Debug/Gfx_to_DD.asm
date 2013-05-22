	TITLE	D:\Game Programming\Moggie Software Games\old code\old Skull X\C++ Files\Gfx_to_DD.cpp
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
;	COMDAT ??_C@_0BM@GIBL@createcompatible?5dc?5failed?6?$AA@
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
;	COMDAT ?GfxToDD@@YAPAUIDirectDrawSurface7@@PAUIDirectDraw7@@PAD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DeCompress@@YAHPAPAURGB_PAL@@PAUGFX_INFO@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?LoadGfxFile@@YAHPADPAUGFX_INFO@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetBitmap@@YAJPAUIDirectDrawSurface7@@PAUHBITMAP__@@HH@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?DeCompress@@YAHPAPAURGB_PAL@@PAUGFX_INFO@@@Z	; DeCompress
PUBLIC	?LoadGfxFile@@YAHPADPAUGFX_INFO@@@Z		; LoadGfxFile
PUBLIC	?SetBitmap@@YAJPAUIDirectDrawSurface7@@PAUHBITMAP__@@HH@Z ; SetBitmap
PUBLIC	?GfxToDD@@YAPAUIDirectDrawSurface7@@PAUIDirectDraw7@@PAD@Z ; GfxToDD
EXTRN	??2@YAPAXI@Z:NEAR				; operator new
EXTRN	__imp__CreateBitmap@20:NEAR
EXTRN	__imp__DeleteObject@4:NEAR
EXTRN	_memset:NEAR
;	COMDAT ?GfxToDD@@YAPAUIDirectDrawSurface7@@PAUIDirectDraw7@@PAD@Z
_TEXT	SEGMENT
_pdd$ = 8
_FileName$ = 12
_hbm$ = -4
_ddsd$ = -128
_pdds$ = -132
_GfxInfo$ = -160
_RawData$ = -164
_i$ = -168
_j$ = -172
_k$ = -176
_count$ = -180
_TempData$ = -184
$T57299 = -188
?GfxToDD@@YAPAUIDirectDrawSurface7@@PAUIDirectDraw7@@PAD@Z PROC NEAR ; GfxToDD, COMDAT

; 8    : {

	push	ebp
	mov	ebp, esp
	sub	esp, 252				; 000000fcH
	push	ebx
	push	esi
	push	edi

; 9    :     HBITMAP                 hbm;
; 10   :     DD_SDESC			          ddsd;
; 11   :     DD_SURFACE						  pdds;
; 12   : 		GFX_INFO								GfxInfo;
; 13   : 		RGB_PAL								 *RawData;
; 14   : 
; 15   : 		//
; 16   :     // Load Graphics file then data
; 17   :     //
; 18   : 		LoadGfxFile(FileName, &GfxInfo);

	lea	eax, DWORD PTR _GfxInfo$[ebp]
	push	eax
	mov	ecx, DWORD PTR _FileName$[ebp]
	push	ecx
	call	?LoadGfxFile@@YAHPADPAUGFX_INFO@@@Z	; LoadGfxFile
	add	esp, 8

; 19   : 		//
; 20   :     // Decompress Graphics Data to raw rgb values
; 21   :     //
; 22   : 		DeCompress(&RawData, &GfxInfo);

	lea	edx, DWORD PTR _GfxInfo$[ebp]
	push	edx
	lea	eax, DWORD PTR _RawData$[ebp]
	push	eax
	call	?DeCompress@@YAHPAPAURGB_PAL@@PAUGFX_INFO@@@Z ; DeCompress
	add	esp, 8

; 23   : 
; 24   : 		// FlipData
; 25   : 		DWORD i, j, k, count = GfxInfo.header.oSize;

	mov	ecx, DWORD PTR _GfxInfo$[ebp+8]
	mov	DWORD PTR _count$[ebp], ecx

; 26   : 		RGB_PAL		*TempData = new RGB_PAL[count];

	mov	edx, DWORD PTR _count$[ebp]
	imul	edx, 3
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T57299[ebp], eax
	mov	eax, DWORD PTR $T57299[ebp]
	mov	DWORD PTR _TempData$[ebp], eax

; 27   : 
; 28   : 		for(i = 0, j = GfxInfo.header.w*(GfxInfo.header.h - 1); i < count; i++, j++)

	mov	DWORD PTR _i$[ebp], 0
	mov	ecx, DWORD PTR _GfxInfo$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _GfxInfo$[ebp+2]
	and	edx, 65535				; 0000ffffH
	sub	edx, 1
	imul	ecx, edx
	mov	DWORD PTR _j$[ebp], ecx
	jmp	SHORT $L57180
$L57181:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	mov	ecx, DWORD PTR _j$[ebp]
	add	ecx, 1
	mov	DWORD PTR _j$[ebp], ecx
$L57180:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _count$[ebp]
	jae	$L57182

; 30   : 			if( ( i%GfxInfo.header.w == 0 ) && (i != 0) )

	mov	ecx, DWORD PTR _GfxInfo$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _i$[ebp]
	xor	edx, edx
	div	ecx
	test	edx, edx
	jne	SHORT $L57185
	cmp	DWORD PTR _i$[ebp], 0
	je	SHORT $L57185

; 32   : 				k = GfxInfo.header.w*2;

	mov	edx, DWORD PTR _GfxInfo$[ebp]
	and	edx, 65535				; 0000ffffH
	shl	edx, 1
	mov	DWORD PTR _k$[ebp], edx

; 33   : 				if( j > k )

	mov	eax, DWORD PTR _j$[ebp]
	cmp	eax, DWORD PTR _k$[ebp]
	jbe	SHORT $L57184

; 34   : 					j -= k;

	mov	ecx, DWORD PTR _j$[ebp]
	sub	ecx, DWORD PTR _k$[ebp]
	mov	DWORD PTR _j$[ebp], ecx

; 35   : 				else

	jmp	SHORT $L57185
$L57184:

; 36   : 					j = 0;

	mov	DWORD PTR _j$[ebp], 0
$L57185:

; 38   : 
; 39   : 			TempData[i] = RawData[j];

	mov	edx, DWORD PTR _j$[ebp]
	imul	edx, 3
	mov	eax, DWORD PTR _RawData$[ebp]
	add	eax, edx
	mov	ecx, DWORD PTR _i$[ebp]
	imul	ecx, 3
	mov	edx, DWORD PTR _TempData$[ebp]
	add	edx, ecx
	mov	cx, WORD PTR [eax]
	mov	WORD PTR [edx], cx
	mov	al, BYTE PTR [eax+2]
	mov	BYTE PTR [edx+2], al

; 40   : 		}

	jmp	$L57181
$L57182:

; 41   : 		RawData = TempData;

	mov	ecx, DWORD PTR _TempData$[ebp]
	mov	DWORD PTR _RawData$[ebp], ecx

; 42   : 
; 43   : 		hbm = CreateBitmap(GfxInfo.header.w, GfxInfo.header.h, 1, 24, RawData);

	mov	edx, DWORD PTR _RawData$[ebp]
	push	edx
	push	24					; 00000018H
	push	1
	mov	eax, DWORD PTR _GfxInfo$[ebp+2]
	and	eax, 65535				; 0000ffffH
	push	eax
	mov	ecx, DWORD PTR _GfxInfo$[ebp]
	and	ecx, 65535				; 0000ffffH
	push	ecx
	call	DWORD PTR __imp__CreateBitmap@20
	mov	DWORD PTR _hbm$[ebp], eax

; 44   : 
; 45   :     //
; 46   :     // Create a DirectDrawSurface for this bitmap
; 47   :     //
; 48   :     ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	edx, DWORD PTR _ddsd$[ebp]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 49   :     ddsd.dwSize = sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 50   :     ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 51   :     ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;

	mov	DWORD PTR _ddsd$[ebp+104], 64		; 00000040H

; 52   :     ddsd.dwWidth = GfxInfo.header.w;

	mov	eax, DWORD PTR _GfxInfo$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+12], eax

; 53   :     ddsd.dwHeight = GfxInfo.header.h;

	mov	ecx, DWORD PTR _GfxInfo$[ebp+2]
	and	ecx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+8], ecx

; 54   :     if (pdd->CreateSurface(&ddsd, &pdds, NULL) != DD_OK)

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
	je	SHORT $L57187

; 55   :         return NULL;

	xor	eax, eax
	jmp	SHORT $L57167
$L57187:

; 56   : 
; 57   :     SetBitmap(pdds, hbm, GfxInfo.header.w, GfxInfo.header.h);

	mov	ecx, DWORD PTR _GfxInfo$[ebp+2]
	and	ecx, 65535				; 0000ffffH
	push	ecx
	mov	edx, DWORD PTR _GfxInfo$[ebp]
	and	edx, 65535				; 0000ffffH
	push	edx
	mov	eax, DWORD PTR _hbm$[ebp]
	push	eax
	mov	ecx, DWORD PTR _pdds$[ebp]
	push	ecx
	call	?SetBitmap@@YAJPAUIDirectDrawSurface7@@PAUHBITMAP__@@HH@Z ; SetBitmap
	add	esp, 16					; 00000010H

; 58   : 
; 59   :     DeleteObject(hbm);

	mov	edx, DWORD PTR _hbm$[ebp]
	push	edx
	call	DWORD PTR __imp__DeleteObject@4

; 60   :     return pdds;

	mov	eax, DWORD PTR _pdds$[ebp]
$L57167:

; 61   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?GfxToDD@@YAPAUIDirectDrawSurface7@@PAUIDirectDraw7@@PAD@Z ENDP ; GfxToDD
_TEXT	ENDS
;	COMDAT ?DeCompress@@YAHPAPAURGB_PAL@@PAUGFX_INFO@@@Z
_TEXT	SEGMENT
_data$ = 8
_gi$ = 12
_i$ = -4
_l$ = -8
_c$ = -12
_t$ = -16
_j$ = -20
_lc$ = -24
_d$ = -28
$T57302 = -32
?DeCompress@@YAHPAPAURGB_PAL@@PAUGFX_INFO@@@Z PROC NEAR	; DeCompress, COMDAT

; 64   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 96					; 00000060H
	push	ebx
	push	esi
	push	edi

; 65   : 	DWORD i, l, c = gi->header.oSize, t, j, lc;

	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR _c$[ebp], ecx

; 66   : 	RGB_PAL *d;
; 67   : 
; 68   : 	if(c)

	cmp	DWORD PTR _c$[ebp], 0
	je	SHORT $L57199

; 69   : 		d = new RGB_PAL[c];

	mov	edx, DWORD PTR _c$[ebp]
	imul	edx, 3
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T57302[ebp], eax
	mov	eax, DWORD PTR $T57302[ebp]
	mov	DWORD PTR _d$[ebp], eax

; 70   : 	else

	jmp	SHORT $L57202
$L57199:

; 72   : 		// Count Error
; 73   : 		return 2;

	mov	eax, 2
	jmp	$L57191
$L57202:

; 75   : 
; 76   : 	c = 0;

	mov	DWORD PTR _c$[ebp], 0

; 77   : 	for(i = 0; i < gi->header.gSize;)

	mov	DWORD PTR _i$[ebp], 0
$L57204:
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR [ecx+16]
	jae	$L57205

; 79   : 		// one value
; 80   : 		if(gi->data.gfx[i] == 1)

	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	mov	edx, DWORD PTR _i$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx]
	cmp	eax, 1
	jne	$L57206

; 82   : 			t = gi->data.gfx[++i];

	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+24]
	mov	ecx, DWORD PTR _i$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx]
	mov	DWORD PTR _t$[ebp], edx

; 83   : 
; 84   : 				d[j].r = gi->data.pal[t].b;

	mov	eax, DWORD PTR _t$[ebp]
	imul	eax, 3
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _j$[ebp]
	imul	ecx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	dl, BYTE PTR [edx+eax+2]
	mov	BYTE PTR [esi+ecx], dl

; 85   : 				d[j].g = gi->data.pal[t].g;

	mov	eax, DWORD PTR _t$[ebp]
	imul	eax, 3
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _j$[ebp]
	imul	ecx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	dl, BYTE PTR [edx+eax+1]
	mov	BYTE PTR [esi+ecx+1], dl

; 86   : 				d[j].b = gi->data.pal[t].r;

	mov	eax, DWORD PTR _t$[ebp]
	imul	eax, 3
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _j$[ebp]
	imul	ecx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	dl, BYTE PTR [edx+eax]
	mov	BYTE PTR [esi+ecx+2], dl

; 87   : 
; 88   : 			i++;	c++;

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	mov	ecx, DWORD PTR _c$[ebp]
	add	ecx, 1
	mov	DWORD PTR _c$[ebp], ecx

; 90   : 		// value with 8-bit length
; 91   : 		else if(gi->data.gfx[i] == 2)

	jmp	$L57237
$L57206:
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+24]
	mov	ecx, DWORD PTR _i$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx]
	cmp	edx, 2
	jne	$L57208

; 93   : 			l = gi->data.gfx[++i];

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	eax, DWORD PTR _i$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax]
	mov	DWORD PTR _l$[ebp], ecx

; 94   : 			lc = l + c;

	mov	edx, DWORD PTR _l$[ebp]
	add	edx, DWORD PTR _c$[ebp]
	mov	DWORD PTR _lc$[ebp], edx

; 95   : 			t = gi->data.gfx[++i];

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	eax, DWORD PTR _i$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax]
	mov	DWORD PTR _t$[ebp], ecx

; 96   : 
; 97   : 			for(j = c; j < lc; j++)

	mov	edx, DWORD PTR _c$[ebp]
	mov	DWORD PTR _j$[ebp], edx
	jmp	SHORT $L57209
$L57210:
	mov	eax, DWORD PTR _j$[ebp]
	add	eax, 1
	mov	DWORD PTR _j$[ebp], eax
$L57209:
	mov	ecx, DWORD PTR _j$[ebp]
	cmp	ecx, DWORD PTR _lc$[ebp]
	jae	SHORT $L57211

; 99   : 				d[j].r = gi->data.pal[t].b;

	mov	edx, DWORD PTR _t$[ebp]
	imul	edx, 3
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	mov	eax, DWORD PTR _j$[ebp]
	imul	eax, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	cl, BYTE PTR [ecx+edx+2]
	mov	BYTE PTR [esi+eax], cl

; 100  : 				d[j].g = gi->data.pal[t].g;

	mov	edx, DWORD PTR _t$[ebp]
	imul	edx, 3
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	mov	eax, DWORD PTR _j$[ebp]
	imul	eax, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	cl, BYTE PTR [ecx+edx+1]
	mov	BYTE PTR [esi+eax+1], cl

; 101  : 				d[j].b = gi->data.pal[t].r;

	mov	edx, DWORD PTR _t$[ebp]
	imul	edx, 3
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	mov	eax, DWORD PTR _j$[ebp]
	imul	eax, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	cl, BYTE PTR [ecx+edx]
	mov	BYTE PTR [esi+eax+2], cl

; 102  : 			}

	jmp	SHORT $L57210
$L57211:

; 103  : 
; 104  : 			c = lc;	i++;

	mov	edx, DWORD PTR _lc$[ebp]
	mov	DWORD PTR _c$[ebp], edx
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax

; 106  : 		// value with 16-bit length
; 107  : 		else if(gi->data.gfx[i] == 3)

	jmp	$L57237
$L57208:
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	eax, DWORD PTR _i$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax]
	cmp	ecx, 3
	jne	$L57213

; 109  : 			l = (gi->data.gfx[++i] << 8);

	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	mov	edx, DWORD PTR _i$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx]
	shl	eax, 8
	mov	DWORD PTR _l$[ebp], eax

; 110  : 			l |= gi->data.gfx[++i];

	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+24]
	mov	ecx, DWORD PTR _i$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx]
	mov	eax, DWORD PTR _l$[ebp]
	or	eax, edx
	mov	DWORD PTR _l$[ebp], eax

; 111  : 			lc = l + c;

	mov	ecx, DWORD PTR _l$[ebp]
	add	ecx, DWORD PTR _c$[ebp]
	mov	DWORD PTR _lc$[ebp], ecx

; 112  : 			t = gi->data.gfx[++i];

	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	mov	edx, DWORD PTR _i$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx]
	mov	DWORD PTR _t$[ebp], eax

; 113  : 
; 114  : 			for(j = c; j < lc; j++)

	mov	ecx, DWORD PTR _c$[ebp]
	mov	DWORD PTR _j$[ebp], ecx
	jmp	SHORT $L57214
$L57215:
	mov	edx, DWORD PTR _j$[ebp]
	add	edx, 1
	mov	DWORD PTR _j$[ebp], edx
$L57214:
	mov	eax, DWORD PTR _j$[ebp]
	cmp	eax, DWORD PTR _lc$[ebp]
	jae	SHORT $L57216

; 116  : 				d[j].r = gi->data.pal[t].b;

	mov	ecx, DWORD PTR _t$[ebp]
	imul	ecx, 3
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+20]
	mov	edx, DWORD PTR _j$[ebp]
	imul	edx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	al, BYTE PTR [eax+ecx+2]
	mov	BYTE PTR [esi+edx], al

; 117  : 				d[j].g = gi->data.pal[t].g;

	mov	ecx, DWORD PTR _t$[ebp]
	imul	ecx, 3
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+20]
	mov	edx, DWORD PTR _j$[ebp]
	imul	edx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	al, BYTE PTR [eax+ecx+1]
	mov	BYTE PTR [esi+edx+1], al

; 118  : 				d[j].b = gi->data.pal[t].r;

	mov	ecx, DWORD PTR _t$[ebp]
	imul	ecx, 3
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+20]
	mov	edx, DWORD PTR _j$[ebp]
	imul	edx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	al, BYTE PTR [eax+ecx]
	mov	BYTE PTR [esi+edx+2], al

; 119  : 			}

	jmp	SHORT $L57215
$L57216:

; 120  : 
; 121  : 			c = lc;		i++;

	mov	ecx, DWORD PTR _lc$[ebp]
	mov	DWORD PTR _c$[ebp], ecx
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx

; 123  : 		// value with 32-bit length
; 124  : 		else if(gi->data.gfx[i] == 4)

	jmp	$L57237
$L57213:
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	mov	edx, DWORD PTR _i$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx]
	cmp	eax, 4
	jne	$L57218

; 126  : 			l = (gi->data.gfx[++i] << 16);

	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+24]
	mov	ecx, DWORD PTR _i$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx]
	shl	edx, 16					; 00000010H
	mov	DWORD PTR _l$[ebp], edx

; 127  : 			l |= (gi->data.gfx[++i] << 8);

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	eax, DWORD PTR _i$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax]
	shl	ecx, 8
	mov	edx, DWORD PTR _l$[ebp]
	or	edx, ecx
	mov	DWORD PTR _l$[ebp], edx

; 128  : 			l |= gi->data.gfx[++i];

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	eax, DWORD PTR _i$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax]
	mov	edx, DWORD PTR _l$[ebp]
	or	edx, ecx
	mov	DWORD PTR _l$[ebp], edx

; 129  : 			lc = l + c;

	mov	eax, DWORD PTR _l$[ebp]
	add	eax, DWORD PTR _c$[ebp]
	mov	DWORD PTR _lc$[ebp], eax

; 130  : 			t = gi->data.gfx[++i];

	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+24]
	mov	ecx, DWORD PTR _i$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx]
	mov	DWORD PTR _t$[ebp], edx

; 131  : 
; 132  : 			for(j = c; j < lc; j++)

	mov	eax, DWORD PTR _c$[ebp]
	mov	DWORD PTR _j$[ebp], eax
	jmp	SHORT $L57219
$L57220:
	mov	ecx, DWORD PTR _j$[ebp]
	add	ecx, 1
	mov	DWORD PTR _j$[ebp], ecx
$L57219:
	mov	edx, DWORD PTR _j$[ebp]
	cmp	edx, DWORD PTR _lc$[ebp]
	jae	SHORT $L57221

; 134  : 				d[j].r = gi->data.pal[t].b;

	mov	eax, DWORD PTR _t$[ebp]
	imul	eax, 3
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _j$[ebp]
	imul	ecx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	dl, BYTE PTR [edx+eax+2]
	mov	BYTE PTR [esi+ecx], dl

; 135  : 				d[j].g = gi->data.pal[t].g;

	mov	eax, DWORD PTR _t$[ebp]
	imul	eax, 3
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _j$[ebp]
	imul	ecx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	dl, BYTE PTR [edx+eax+1]
	mov	BYTE PTR [esi+ecx+1], dl

; 136  : 				d[j].b = gi->data.pal[t].r;

	mov	eax, DWORD PTR _t$[ebp]
	imul	eax, 3
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _j$[ebp]
	imul	ecx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	dl, BYTE PTR [edx+eax]
	mov	BYTE PTR [esi+ecx+2], dl

; 137  : 			}

	jmp	SHORT $L57220
$L57221:

; 138  : 
; 139  : 			c = lc;		i++;

	mov	eax, DWORD PTR _lc$[ebp]
	mov	DWORD PTR _c$[ebp], eax
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx

; 141  : 		// data with 8-bit length
; 142  : 		else if(gi->data.gfx[i] == 5)

	jmp	$L57237
$L57218:
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+24]
	mov	ecx, DWORD PTR _i$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx]
	cmp	edx, 5
	jne	$L57223

; 144  : 			l = gi->data.gfx[++i];

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	eax, DWORD PTR _i$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax]
	mov	DWORD PTR _l$[ebp], ecx

; 145  : 			lc = l + c;

	mov	edx, DWORD PTR _l$[ebp]
	add	edx, DWORD PTR _c$[ebp]
	mov	DWORD PTR _lc$[ebp], edx

; 146  : 			t = gi->data.gfx[++i];

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	eax, DWORD PTR _i$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax]
	mov	DWORD PTR _t$[ebp], ecx

; 147  : 
; 148  : 			for(j = c; j < lc; j++)

	mov	edx, DWORD PTR _c$[ebp]
	mov	DWORD PTR _j$[ebp], edx
	jmp	SHORT $L57224
$L57225:
	mov	eax, DWORD PTR _j$[ebp]
	add	eax, 1
	mov	DWORD PTR _j$[ebp], eax
$L57224:
	mov	ecx, DWORD PTR _j$[ebp]
	cmp	ecx, DWORD PTR _lc$[ebp]
	jae	SHORT $L57226

; 150  : 				d[j].r = gi->data.pal[t].b;

	mov	edx, DWORD PTR _t$[ebp]
	imul	edx, 3
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	mov	eax, DWORD PTR _j$[ebp]
	imul	eax, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	cl, BYTE PTR [ecx+edx+2]
	mov	BYTE PTR [esi+eax], cl

; 151  : 				d[j].g = gi->data.pal[t].g;

	mov	edx, DWORD PTR _t$[ebp]
	imul	edx, 3
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	mov	eax, DWORD PTR _j$[ebp]
	imul	eax, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	cl, BYTE PTR [ecx+edx+1]
	mov	BYTE PTR [esi+eax+1], cl

; 152  : 				d[j].b = gi->data.pal[t].r;

	mov	edx, DWORD PTR _t$[ebp]
	imul	edx, 3
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	mov	eax, DWORD PTR _j$[ebp]
	imul	eax, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	cl, BYTE PTR [ecx+edx]
	mov	BYTE PTR [esi+eax+2], cl

; 153  : 			}

	jmp	SHORT $L57225
$L57226:

; 154  : 
; 155  : 			c = lc;		i += l;

	mov	edx, DWORD PTR _lc$[ebp]
	mov	DWORD PTR _c$[ebp], edx
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, DWORD PTR _l$[ebp]
	mov	DWORD PTR _i$[ebp], eax

; 157  : 
; 158  : 		// data with 16-bit lenght
; 159  : 		else if(gi->data.gfx[i] == 6)

	jmp	$L57237
$L57223:
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	eax, DWORD PTR _i$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax]
	cmp	ecx, 6
	jne	$L57228

; 161  : 			l = (gi->data.gfx[++i] << 8);

	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	mov	edx, DWORD PTR _i$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx]
	shl	eax, 8
	mov	DWORD PTR _l$[ebp], eax

; 162  : 			l |= gi->data.gfx[++i];

	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+24]
	mov	ecx, DWORD PTR _i$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx]
	mov	eax, DWORD PTR _l$[ebp]
	or	eax, edx
	mov	DWORD PTR _l$[ebp], eax

; 163  : 			lc = l + c;

	mov	ecx, DWORD PTR _l$[ebp]
	add	ecx, DWORD PTR _c$[ebp]
	mov	DWORD PTR _lc$[ebp], ecx

; 164  : 			t = gi->data.gfx[++i];

	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	mov	edx, DWORD PTR _i$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx]
	mov	DWORD PTR _t$[ebp], eax

; 165  : 
; 166  : 			for(j = c; j < lc; j++)

	mov	ecx, DWORD PTR _c$[ebp]
	mov	DWORD PTR _j$[ebp], ecx
	jmp	SHORT $L57229
$L57230:
	mov	edx, DWORD PTR _j$[ebp]
	add	edx, 1
	mov	DWORD PTR _j$[ebp], edx
$L57229:
	mov	eax, DWORD PTR _j$[ebp]
	cmp	eax, DWORD PTR _lc$[ebp]
	jae	SHORT $L57231

; 168  : 				d[j].r = gi->data.pal[t].b;

	mov	ecx, DWORD PTR _t$[ebp]
	imul	ecx, 3
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+20]
	mov	edx, DWORD PTR _j$[ebp]
	imul	edx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	al, BYTE PTR [eax+ecx+2]
	mov	BYTE PTR [esi+edx], al

; 169  : 				d[j].g = gi->data.pal[t].g;

	mov	ecx, DWORD PTR _t$[ebp]
	imul	ecx, 3
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+20]
	mov	edx, DWORD PTR _j$[ebp]
	imul	edx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	al, BYTE PTR [eax+ecx+1]
	mov	BYTE PTR [esi+edx+1], al

; 170  : 				d[j].b = gi->data.pal[t].r;

	mov	ecx, DWORD PTR _t$[ebp]
	imul	ecx, 3
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+20]
	mov	edx, DWORD PTR _j$[ebp]
	imul	edx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	al, BYTE PTR [eax+ecx]
	mov	BYTE PTR [esi+edx+2], al

; 171  : 			}

	jmp	SHORT $L57230
$L57231:

; 172  : 
; 173  : 			c = lc;		i += l;

	mov	ecx, DWORD PTR _lc$[ebp]
	mov	DWORD PTR _c$[ebp], ecx
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, DWORD PTR _l$[ebp]
	mov	DWORD PTR _i$[ebp], edx

; 175  : 		
; 176  : 		// data with 32-bit length
; 177  : 		else if(gi->data.gfx[i] == 7)

	jmp	$L57237
$L57228:
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	mov	edx, DWORD PTR _i$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx]
	cmp	eax, 7
	jne	$L57233

; 179  : 			l = (gi->data.gfx[++i] << 16);

	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+24]
	mov	ecx, DWORD PTR _i$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx]
	shl	edx, 16					; 00000010H
	mov	DWORD PTR _l$[ebp], edx

; 180  : 			l |= (gi->data.gfx[++i] << 8);

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	eax, DWORD PTR _i$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax]
	shl	ecx, 8
	mov	edx, DWORD PTR _l$[ebp]
	or	edx, ecx
	mov	DWORD PTR _l$[ebp], edx

; 181  : 			l |= gi->data.gfx[++i];

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	eax, DWORD PTR _i$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax]
	mov	edx, DWORD PTR _l$[ebp]
	or	edx, ecx
	mov	DWORD PTR _l$[ebp], edx

; 182  : 			lc = l + c;

	mov	eax, DWORD PTR _l$[ebp]
	add	eax, DWORD PTR _c$[ebp]
	mov	DWORD PTR _lc$[ebp], eax

; 183  : 			t = gi->data.gfx[++i];

	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+24]
	mov	ecx, DWORD PTR _i$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx]
	mov	DWORD PTR _t$[ebp], edx

; 184  : 
; 185  : 			for(j = c; j < lc; j++)

	mov	eax, DWORD PTR _c$[ebp]
	mov	DWORD PTR _j$[ebp], eax
	jmp	SHORT $L57234
$L57235:
	mov	ecx, DWORD PTR _j$[ebp]
	add	ecx, 1
	mov	DWORD PTR _j$[ebp], ecx
$L57234:
	mov	edx, DWORD PTR _j$[ebp]
	cmp	edx, DWORD PTR _lc$[ebp]
	jae	SHORT $L57236

; 187  : 				d[j].r = gi->data.pal[t].b;

	mov	eax, DWORD PTR _t$[ebp]
	imul	eax, 3
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _j$[ebp]
	imul	ecx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	dl, BYTE PTR [edx+eax+2]
	mov	BYTE PTR [esi+ecx], dl

; 188  : 				d[j].g = gi->data.pal[t].g;

	mov	eax, DWORD PTR _t$[ebp]
	imul	eax, 3
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _j$[ebp]
	imul	ecx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	dl, BYTE PTR [edx+eax+1]
	mov	BYTE PTR [esi+ecx+1], dl

; 189  : 				d[j].b = gi->data.pal[t].r;

	mov	eax, DWORD PTR _t$[ebp]
	imul	eax, 3
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _j$[ebp]
	imul	ecx, 3
	mov	esi, DWORD PTR _d$[ebp]
	mov	dl, BYTE PTR [edx+eax]
	mov	BYTE PTR [esi+ecx+2], dl

; 190  : 			}

	jmp	SHORT $L57235
$L57236:

; 191  : 
; 192  : 			c = lc;		i += l;

	mov	eax, DWORD PTR _lc$[ebp]
	mov	DWORD PTR _c$[ebp], eax
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, DWORD PTR _l$[ebp]
	mov	DWORD PTR _i$[ebp], ecx

; 194  : 		
; 195  : 		else

	jmp	SHORT $L57237
$L57233:

; 197  : 			// Compression Error
; 198  : 			return 1;

	mov	eax, 1
	jmp	SHORT $L57191
$L57237:

; 200  : 	}

	jmp	$L57204
$L57205:

; 201  : 
; 202  : 	*data = d;

	mov	edx, DWORD PTR _data$[ebp]
	mov	eax, DWORD PTR _d$[ebp]
	mov	DWORD PTR [edx], eax

; 203  : 
; 204  : 	return 0;

	xor	eax, eax
$L57191:

; 205  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?DeCompress@@YAHPAPAURGB_PAL@@PAUGFX_INFO@@@Z ENDP	; DeCompress
_TEXT	ENDS
EXTRN	__imp__ReadFile@20:NEAR
EXTRN	__imp__CloseHandle@4:NEAR
EXTRN	__imp__CreateFileA@28:NEAR
;	COMDAT ?LoadGfxFile@@YAHPADPAUGFX_INFO@@@Z
_TEXT	SEGMENT
_name$ = 8
_gi$ = 12
_NumBytes$ = -4
_hFile$ = -8
$T57305 = -12
$T57306 = -16
?LoadGfxFile@@YAHPADPAUGFX_INFO@@@Z PROC NEAR		; LoadGfxFile, COMDAT

; 208  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 80					; 00000050H
	push	ebx
	push	esi
	push	edi

; 209  : 	DWORD NumBytes = 0;

	mov	DWORD PTR _NumBytes$[ebp], 0

; 210  : 
; 211  : 	HANDLE hFile = CreateFile(name, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

	push	0
	push	32					; 00000020H
	push	3
	push	0
	push	0
	push	-2147483648				; 80000000H
	mov	eax, DWORD PTR _name$[ebp]
	push	eax
	call	DWORD PTR __imp__CreateFileA@28
	mov	DWORD PTR _hFile$[ebp], eax

; 212  : 	if(hFile == INVALID_HANDLE_VALUE)

	cmp	DWORD PTR _hFile$[ebp], -1
	jne	SHORT $L57245

; 213  : 		{	CloseHandle(hFile);		return 1;	}

	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__CloseHandle@4
	mov	eax, 1
	jmp	$L57241
$L57245:

; 214  : 
; 215  : 	ReadFile(hFile, &(gi->header), sizeof(GFX_INFO_HEADER), &NumBytes, NULL);

	push	0
	lea	edx, DWORD PTR _NumBytes$[ebp]
	push	edx
	push	20					; 00000014H
	mov	eax, DWORD PTR _gi$[ebp]
	push	eax
	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__ReadFile@20

; 216  : 	if(NumBytes != sizeof(GFX_INFO_HEADER))

	cmp	DWORD PTR _NumBytes$[ebp], 20		; 00000014H
	je	SHORT $L57248

; 217  : 		{	CloseHandle(hFile);		return 2;	}

	mov	edx, DWORD PTR _hFile$[ebp]
	push	edx
	call	DWORD PTR __imp__CloseHandle@4
	mov	eax, 2
	jmp	$L57241
$L57248:

; 218  : 
; 219  : 	gi->data.pal = new RGB_PAL[gi->header.pSize];

	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	imul	ecx, 3
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T57305[ebp], eax
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR $T57305[ebp]
	mov	DWORD PTR [edx+20], eax

; 220  : 	ReadFile(hFile, gi->data.pal, gi->header.pSize*sizeof(RGB_PAL), &NumBytes, NULL);

	push	0
	lea	ecx, DWORD PTR _NumBytes$[ebp]
	push	ecx
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+12]
	imul	eax, 3
	push	eax
	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	push	edx
	mov	eax, DWORD PTR _hFile$[ebp]
	push	eax
	call	DWORD PTR __imp__ReadFile@20

; 221  : 	if(NumBytes != gi->header.pSize*sizeof(RGB_PAL))

	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	imul	edx, 3
	cmp	DWORD PTR _NumBytes$[ebp], edx
	je	SHORT $L57253

; 222  : 		{	CloseHandle(hFile);		return 3;	}

	mov	eax, DWORD PTR _hFile$[ebp]
	push	eax
	call	DWORD PTR __imp__CloseHandle@4
	mov	eax, 3
	jmp	SHORT $L57241
$L57253:

; 223  : 
; 224  : 	gi->data.gfx = new BYTE[gi->header.gSize];

	mov	ecx, DWORD PTR _gi$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T57306[ebp], eax
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR $T57306[ebp]
	mov	DWORD PTR [eax+24], ecx

; 225  : 	ReadFile(hFile, gi->data.gfx, gi->header.gSize*sizeof(BYTE), &NumBytes, NULL);

	push	0
	lea	edx, DWORD PTR _NumBytes$[ebp]
	push	edx
	mov	eax, DWORD PTR _gi$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR [edx+24]
	push	eax
	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__ReadFile@20

; 226  : 	if(NumBytes != gi->header.gSize*sizeof(BYTE))

	mov	edx, DWORD PTR _gi$[ebp]
	mov	eax, DWORD PTR _NumBytes$[ebp]
	cmp	eax, DWORD PTR [edx+16]
	je	SHORT $L57258

; 227  : 		{	CloseHandle(hFile);		return 4;	}

	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__CloseHandle@4
	mov	eax, 4
	jmp	SHORT $L57241
$L57258:

; 228  : 
; 229  : 	CloseHandle(hFile);

	mov	edx, DWORD PTR _hFile$[ebp]
	push	edx
	call	DWORD PTR __imp__CloseHandle@4

; 230  : 	return 0;

	xor	eax, eax
$L57241:

; 231  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?LoadGfxFile@@YAHPADPAUGFX_INFO@@@Z ENDP		; LoadGfxFile
_TEXT	ENDS
PUBLIC	??_C@_0BM@GIBL@createcompatible?5dc?5failed?6?$AA@ ; `string'
EXTRN	__imp__OutputDebugStringA@4:NEAR
EXTRN	__imp__SelectObject@8:NEAR
EXTRN	__imp__BitBlt@36:NEAR
EXTRN	__imp__CreateCompatibleDC@4:NEAR
EXTRN	__imp__DeleteDC@4:NEAR
;	COMDAT ??_C@_0BM@GIBL@createcompatible?5dc?5failed?6?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\gfx_to_dd.cpp
CONST	SEGMENT
??_C@_0BM@GIBL@createcompatible?5dc?5failed?6?$AA@ DB 'createcompatible d'
	DB	'c failed', 0aH, 00H				; `string'
CONST	ENDS
;	COMDAT ?SetBitmap@@YAJPAUIDirectDrawSurface7@@PAUHBITMAP__@@HH@Z
_TEXT	SEGMENT
_pdds$ = 8
_hbm$ = 12
_dx$ = 16
_hdcImage$ = -4
_hdc$ = -8
_hr$ = -12
?SetBitmap@@YAJPAUIDirectDrawSurface7@@PAUHBITMAP__@@HH@Z PROC NEAR ; SetBitmap, COMDAT

; 235  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 76					; 0000004cH
	push	ebx
	push	esi
	push	edi

; 236  :     HDC                     hdcImage;
; 237  :     HDC                     hdc;
; 238  :     HRESULT                 hr;
; 239  : 
; 240  :     if (hbm == NULL || pdds == NULL)

	cmp	DWORD PTR _hbm$[ebp], 0
	je	SHORT $L57269
	cmp	DWORD PTR _pdds$[ebp], 0
	jne	SHORT $L57268
$L57269:

; 241  :         return E_FAIL;

	mov	eax, -2147467259			; 80004005H
	jmp	$L57264
$L57268:

; 242  :     //
; 243  :     // Make sure this surface is restored.
; 244  :     //
; 245  :     pdds->Restore();

	mov	eax, DWORD PTR _pdds$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _pdds$[ebp]
	push	edx
	call	DWORD PTR [ecx+108]

; 246  :     //
; 247  :     // Select bitmap into a memoryDC so we can use it.
; 248  :     //
; 249  :     hdcImage = CreateCompatibleDC(NULL);

	push	0
	call	DWORD PTR __imp__CreateCompatibleDC@4
	mov	DWORD PTR _hdcImage$[ebp], eax

; 250  :     if (!hdcImage)

	cmp	DWORD PTR _hdcImage$[ebp], 0
	jne	SHORT $L57271

; 251  :         OutputDebugString("createcompatible dc failed\n");

	push	OFFSET FLAT:??_C@_0BM@GIBL@createcompatible?5dc?5failed?6?$AA@ ; `string'
	call	DWORD PTR __imp__OutputDebugStringA@4
$L57271:

; 252  :     SelectObject(hdcImage, hbm);

	mov	eax, DWORD PTR _hbm$[ebp]
	push	eax
	mov	ecx, DWORD PTR _hdcImage$[ebp]
	push	ecx
	call	DWORD PTR __imp__SelectObject@8

; 253  : 
; 254  :     if ((hr = pdds->GetDC(&hdc)) == DD_OK)

	lea	edx, DWORD PTR _hdc$[ebp]
	push	edx
	mov	eax, DWORD PTR _pdds$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _pdds$[ebp]
	push	edx
	call	DWORD PTR [ecx+68]
	mov	DWORD PTR _hr$[ebp], eax
	cmp	DWORD PTR _hr$[ebp], 0
	jne	SHORT $L57274

; 256  :         BitBlt(hdc, 0, 0, dx, dx, hdcImage, 0, 0, SRCCOPY);

	push	13369376				; 00cc0020H
	push	0
	push	0
	mov	eax, DWORD PTR _hdcImage$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dx$[ebp]
	push	edx
	push	0
	push	0
	mov	eax, DWORD PTR _hdc$[ebp]
	push	eax
	call	DWORD PTR __imp__BitBlt@36

; 257  :         pdds->ReleaseDC(hdc);

	mov	ecx, DWORD PTR _hdc$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pdds$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _pdds$[ebp]
	push	ecx
	call	DWORD PTR [eax+104]
$L57274:

; 259  :     DeleteDC(hdcImage);

	mov	edx, DWORD PTR _hdcImage$[ebp]
	push	edx
	call	DWORD PTR __imp__DeleteDC@4

; 260  :     return hr;

	mov	eax, DWORD PTR _hr$[ebp]
$L57264:

; 261  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?SetBitmap@@YAJPAUIDirectDrawSurface7@@PAUHBITMAP__@@HH@Z ENDP ; SetBitmap
_TEXT	ENDS
END
