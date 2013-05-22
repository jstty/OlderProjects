	TITLE	D:\Game Programming\Moggie Software Games\old code\old Skull X\C++ Files\Action.cpp
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
;	COMDAT ??_C@_0CB@HOKB@Class?3?5?$CFs?6Function?3?5?$CFs?6Error?3?5?$CFd@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0CE@JLCM@Class?3?$CFs?5?$HM?$HM?5Function?3?$CFs?5?$HM?$HM?5Error@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0CG@NHNF@Class?3?$CC?$CFs?$CC?5?$HM?$HM?5Function?3?$CFs?5?$HM?$HM?5Err@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@OBLP@?$CFs?3?3?$CFs?5?$HM?$HM?5Error?5?$DN?5?$CFd?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@BKHE@Error?5?9?5?$CFs?5?$CFs?$CI?$CFd?$CJ?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_00A@?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05CKBG@Error?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0CE@EGEM@Could?5not?5find?5layer?5by?5the?5name@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05JKGE@?$CFs?5?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_09BONA@?$CF0?43d?4sav?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@MHLM@Could?5not?5load?5File?3?5?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EB@DKLJ@Could?5not?5read?5data?$CIgData?4type?$CJ?5@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EB@CLCH@Could?5not?5read?5data?$CIgData?4size?$CJ?5@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EB@OCLC@Could?5not?5read?5data?$CIgData?4data?$CJ?5@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@FNLG@Could?5not?5save?5File?3?5?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EC@IING@Could?5not?5write?5data?$CIgData?4type?$CJ@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EC@JJEI@Could?5not?5write?5data?$CIgData?4size?$CJ@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EC@FANN@Could?5not?5write?5data?$CIgData?4data?$CJ@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@OKMG@LoadAll?3GlobalAlloc?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_06KGMH@VALUES?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@ENLL@LoadAll?3GlobalLock?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@LKEM@FreeAll?3GlobalUnlock?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BG@MPEO@FreeAll?3GlobalDiscard?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04BOOC@MAIN?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@KDDN@CreateLoop?3Main_hThread?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@PFPA@StartLoops?3ResumeThread?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BJ@HCNJ@CreateLoops?3CreateThread?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BN@DFAJ@CreateLoop?3SetThreadPriority?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BL@HMPM@CreateLoop?3InvalidPriority?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0DJ@MEEM@?$CFs?5?$HM?$HM?5Time?5?$DN?5?$CFf?0?5Count?5?$DN?5?$CFd?0?5Mai@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04PGNC@Tile?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05HPB@Tile1?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_03DIFO@Map?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_07NIEJ@BlueGoo?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05PNPP@Right?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04MKGK@Left?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_02NCFM@Up?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04IH@Down?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_06DJMK@RedGoo?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05COAO@Super?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??8@YAHABU_GUID@@0@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?GetType@ERRORCLASS@@AAEHH@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?InitError@ERRORCLASS@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetError_Format@ERRORCLASS@@QAEX_E@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetError_Format@ERRORCLASS@@QAEXPAD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Error@ERRORCLASS@@QAA_NPADZZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?End@MAIN@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Get_DelayRes@MAIN@@QAEGXZ
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
;	COMDAT ?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?sLoop@VALUES@@QAE_NAAPAXPAD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetStr@@YAXPAPADPBD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Load@ACTION@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?MoveObject@ACTION@@QAEXPAVLAYER@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CheckCol@ACTION@@QAEXPAVLAYER@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?SetStr@@YAXPAPADPBD@Z				; SetStr
EXTRN	??2@YAPAXI@Z:NEAR				; operator new
EXTRN	_strcpy:NEAR
EXTRN	_strlen:NEAR
;	COMDAT ?SetStr@@YAXPAPADPBD@Z
_TEXT	SEGMENT
_a$ = 8
_b$ = 12
$T65506 = -4
?SetStr@@YAXPAPADPBD@Z PROC NEAR			; SetStr, COMDAT

; 37   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi

; 38   : 	*a = new char[ strlen(b) ];

	mov	eax, DWORD PTR _b$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65506[ebp], eax
	mov	ecx, DWORD PTR _a$[ebp]
	mov	edx, DWORD PTR $T65506[ebp]
	mov	DWORD PTR [ecx], edx

; 39   : 	strcpy(*a, b);

	mov	eax, DWORD PTR _b$[ebp]
	push	eax
	mov	ecx, DWORD PTR _a$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8

; 40   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?SetStr@@YAXPAPADPBD@Z ENDP				; SetStr
_TEXT	ENDS
PUBLIC	?Load@ACTION@@QAE_NXZ				; ACTION::Load
PUBLIC	??_C@_04PGNC@Tile?$AA@				; `string'
PUBLIC	??_C@_05HPB@Tile1?$AA@				; `string'
PUBLIC	??_C@_03DIFO@Map?$AA@				; `string'
PUBLIC	??_C@_07NIEJ@BlueGoo?$AA@			; `string'
PUBLIC	??_C@_05PNPP@Right?$AA@				; `string'
PUBLIC	??_C@_04MKGK@Left?$AA@				; `string'
PUBLIC	??_C@_02NCFM@Up?$AA@				; `string'
PUBLIC	??_C@_04IH@Down?$AA@				; `string'
PUBLIC	??_C@_06DJMK@RedGoo?$AA@			; `string'
PUBLIC	??_C@_05COAO@Super?$AA@				; `string'
PUBLIC	?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z		; DISPLAY::FindLayer
EXTRN	_memset:NEAR
EXTRN	?Val@@3PAVVALUES@@A:DWORD			; Val
EXTRN	?SetArray@@YAXPAPA_EPA_E_G@Z:NEAR		; SetArray
;	COMDAT ??_C@_04PGNC@Tile?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\action.cpp
CONST	SEGMENT
??_C@_04PGNC@Tile?$AA@ DB 'Tile', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_05HPB@Tile1?$AA@
CONST	SEGMENT
??_C@_05HPB@Tile1?$AA@ DB 'Tile1', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_03DIFO@Map?$AA@
CONST	SEGMENT
??_C@_03DIFO@Map?$AA@ DB 'Map', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_07NIEJ@BlueGoo?$AA@
CONST	SEGMENT
??_C@_07NIEJ@BlueGoo?$AA@ DB 'BlueGoo', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_05PNPP@Right?$AA@
CONST	SEGMENT
??_C@_05PNPP@Right?$AA@ DB 'Right', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_04MKGK@Left?$AA@
CONST	SEGMENT
??_C@_04MKGK@Left?$AA@ DB 'Left', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_02NCFM@Up?$AA@
CONST	SEGMENT
??_C@_02NCFM@Up?$AA@ DB 'Up', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_04IH@Down?$AA@
CONST	SEGMENT
??_C@_04IH@Down?$AA@ DB 'Down', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_06DJMK@RedGoo?$AA@
CONST	SEGMENT
??_C@_06DJMK@RedGoo?$AA@ DB 'RedGoo', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_05COAO@Super?$AA@
CONST	SEGMENT
??_C@_05COAO@Super?$AA@ DB 'Super', 00H			; `string'
CONST	ENDS
;	COMDAT ?Load@ACTION@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
_LevelNum$ = -8
_tl$65306 = -12
_d$65307 = -16
_nMove$65308 = -20
_j$65312 = -24
_tl$65321 = -28
_d$65322 = -32
_nMove$65323 = -36
_j$65327 = -40
_tl2$65368 = -44
_nCol$65371 = -48
_a1$65377 = -148
_a2$65389 = -248
$T65509 = -252
$T65510 = -256
$T65511 = -260
$T65512 = -264
$T65513 = -268
$T65514 = -272
$T65515 = -276
$T65516 = -280
$T65517 = -284
$T65518 = -288
$T65519 = -292
$T65520 = -296
$T65521 = -300
$T65522 = -304
$T65523 = -308
$T65524 = -312
$T65525 = -316
?Load@ACTION@@QAE_NXZ PROC NEAR				; ACTION::Load, COMDAT

; 46   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 380				; 0000017cH
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 47   : 	unsigned __int16 LevelNum = Val->Game->gData.LevelNum;

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+76]
	mov	dx, WORD PTR [ecx+16]
	mov	WORD PTR _LevelNum$[ebp], dx

; 48   : 
; 49   : 	if(LevelNum == 1)

	mov	eax, DWORD PTR _LevelNum$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 1
	jne	$L65305

; 51   : 		LAYER *tl;
; 52   : 
; 53   : 		DISPLAY *d = Val->Display;

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+64]
	mov	DWORD PTR _d$65307[ebp], edx

; 54   : 		Move = NULL;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+40], 0

; 55   : 
; 56   : 		unsigned __int8 nMove = 1;

	mov	BYTE PTR _nMove$65308[ebp], 1

; 57   : 		Move = new MOVE[nMove];

	mov	ecx, DWORD PTR _nMove$65308[ebp]
	and	ecx, 255				; 000000ffH
	shl	ecx, 4
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65509[ebp], eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR $T65509[ebp]
	mov	DWORD PTR [edx+40], eax

; 58   : 		ZeroMemory(Move, nMove*sizeof(MOVE) );

	mov	ecx, DWORD PTR _nMove$65308[ebp]
	and	ecx, 255				; 000000ffH
	shl	ecx, 4
	push	ecx
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 59   : 		unsigned __int8 j;
; 60   : 
; 61   : 		//
; 62   : 		//
; 63   : 		//
; 64   : 		i = 0;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+28], 0

; 65   : 		Move[i].fd = new XY[64];

	push	512					; 00000200H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65510[ebp], eax
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR $T65510[ebp]
	mov	DWORD PTR [edx+eax+12], ecx

; 66   : 		Move[i].delay = 100;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	DWORD PTR [edx+eax+4], 100		; 00000064H

; 67   : 
; 68   : 		for(j = 0; j < 63; j++)

	mov	BYTE PTR _j$65312[ebp], 0
	jmp	SHORT $L65315
$L65316:
	mov	al, BYTE PTR _j$65312[ebp]
	add	al, 1
	mov	BYTE PTR _j$65312[ebp], al
$L65315:
	mov	ecx, DWORD PTR _j$65312[ebp]
	and	ecx, 255				; 000000ffH
	cmp	ecx, 63					; 0000003fH
	jge	$L65317

; 70   : 			Move[i].fd[j].x = -2;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65312[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	mov	WORD PTR [edx+ecx*8], -2		; fffffffeH

; 71   : 			Move[i].fd[j].y = -2;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65312[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	WORD PTR [eax+edx*8+2], -2		; fffffffeH

; 72   : 			Move[i].fd[j].next = &Move[i].fd[j + 1];

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65312[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	lea	edx, DWORD PTR [ecx+eax*8+8]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+40]
	mov	esi, DWORD PTR _j$65312[ebp]
	and	esi, 255				; 000000ffH
	mov	ecx, DWORD PTR [eax+ecx+12]
	mov	DWORD PTR [ecx+esi*8+4], edx

; 73   : 		}

	jmp	$L65316
$L65317:

; 74   : 		Move[i].fd[j].x = 126;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65312[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	mov	WORD PTR [edx+ecx*8], 126		; 0000007eH

; 75   : 		Move[i].fd[j].y = 126;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65312[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	WORD PTR [eax+edx*8+2], 126		; 0000007eH

; 76   : 		Move[i].fd[j].next = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65312[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	mov	DWORD PTR [ecx+eax*8+4], 0

; 77   : 
; 78   : 		tl= d->FindLayer("Tile");

	push	OFFSET FLAT:??_C@_04PGNC@Tile?$AA@	; `string'
	mov	ecx, DWORD PTR _d$65307[ebp]
	call	?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z	; DISPLAY::FindLayer
	mov	DWORD PTR _tl$65306[ebp], eax

; 79   : 		tl->d = Move[i].fd;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _tl$65306[ebp]
	mov	edx, DWORD PTR [edx+eax+12]
	mov	DWORD PTR [ecx+32], edx

; 80   : 		tl->move = &Move[i];

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	add	eax, ecx
	mov	ecx, DWORD PTR _tl$65306[ebp]
	mov	DWORD PTR [ecx+20], eax

; 83   : 	else if(LevelNum == 3)

	jmp	$L65320
$L65305:
	mov	edx, DWORD PTR _LevelNum$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 3
	jne	$L65320

; 85   : 		LAYER *tl;
; 86   : 		DISPLAY *d = Val->Display;

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+64]
	mov	DWORD PTR _d$65322[ebp], ecx

; 87   : 		Move = NULL;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+40], 0

; 88   : 
; 89   : 		unsigned __int8 nMove = 6;

	mov	BYTE PTR _nMove$65323[ebp], 6

; 90   : 		Move = new MOVE[nMove];

	mov	eax, DWORD PTR _nMove$65323[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65511[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T65511[ebp]
	mov	DWORD PTR [ecx+40], edx

; 91   : 		ZeroMemory(Move, nMove*sizeof(MOVE) );

	mov	eax, DWORD PTR _nMove$65323[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 4
	push	eax
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 92   : 		unsigned __int8 j;
; 93   : 
; 94   : 		//
; 95   : 		//
; 96   : 		//
; 97   : 		i = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+28], 0

; 98   : 		Move[i].num = 11;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	BYTE PTR [ecx+edx+8], 11		; 0000000bH

; 99   : 		Move[i].fd = new XY[11];

	push	88					; 00000058H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65512[ebp], eax
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR $T65512[ebp]
	mov	DWORD PTR [edx+eax+12], ecx

; 100  : 		Move[i].delay = 100;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	DWORD PTR [edx+eax+4], 100		; 00000064H

; 101  : 		for(j = 0; j < 9; j++)

	mov	BYTE PTR _j$65327[ebp], 0
	jmp	SHORT $L65330
$L65331:
	mov	al, BYTE PTR _j$65327[ebp]
	add	al, 1
	mov	BYTE PTR _j$65327[ebp], al
$L65330:
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	cmp	ecx, 9
	jge	$L65332

; 103  : 			Move[i].fd[j].x = 0;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	mov	WORD PTR [edx+ecx*8], 0

; 104  : 			Move[i].fd[j].y = -2;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	WORD PTR [eax+edx*8+2], -2		; fffffffeH

; 105  : 
; 106  : 			Move[i].fd[j].next = &Move[i].fd[j + 1];

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	lea	edx, DWORD PTR [ecx+eax*8+8]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+40]
	mov	esi, DWORD PTR _j$65327[ebp]
	and	esi, 255				; 000000ffH
	mov	ecx, DWORD PTR [eax+ecx+12]
	mov	DWORD PTR [ecx+esi*8+4], edx

; 107  : 		}

	jmp	$L65331
$L65332:

; 108  : 		Move[i].fd[j].x = 0;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	mov	WORD PTR [edx+ecx*8], 0

; 109  : 		Move[i].fd[j].y = 18;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	WORD PTR [eax+edx*8+2], 18		; 00000012H

; 110  : 		Move[i].fd[j].next = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	mov	DWORD PTR [ecx+eax*8+4], 0

; 111  : 
; 112  : 		tl= d->FindLayer("Tile1");

	push	OFFSET FLAT:??_C@_05HPB@Tile1?$AA@	; `string'
	mov	ecx, DWORD PTR _d$65322[ebp]
	call	?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z	; DISPLAY::FindLayer
	mov	DWORD PTR _tl$65321[ebp], eax

; 113  : 		tl->d = Move[i].fd;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _tl$65321[ebp]
	mov	edx, DWORD PTR [edx+eax+12]
	mov	DWORD PTR [ecx+32], edx

; 114  : 		tl->move = &Move[i];

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	add	eax, ecx
	mov	ecx, DWORD PTR _tl$65321[ebp]
	mov	DWORD PTR [ecx+20], eax

; 115  : 		i++;

	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR [edx+28]
	add	al, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+28], al

; 116  : 
; 117  : 		//
; 118  : 		//
; 119  : 		//
; 120  : 		Move[i].num = 50;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	BYTE PTR [edx+eax+8], 50		; 00000032H

; 121  : 		Move[i].fd = new XY[Move[i].num];

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx+8]
	shl	edx, 3
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65513[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR $T65513[ebp]
	mov	DWORD PTR [eax+ecx+12], edx

; 122  : 		Move[i].delay = 100;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	DWORD PTR [eax+ecx+4], 100		; 00000064H

; 123  : 		for(j = 0; j < 49; j++)

	mov	BYTE PTR _j$65327[ebp], 0
	jmp	SHORT $L65336
$L65337:
	mov	cl, BYTE PTR _j$65327[ebp]
	add	cl, 1
	mov	BYTE PTR _j$65327[ebp], cl
$L65336:
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	cmp	edx, 49					; 00000031H
	jge	$L65338

; 125  : 			Move[i].fd[j].x = 4;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	WORD PTR [eax+edx*8], 4

; 126  : 			Move[i].fd[j].y = 0;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	mov	WORD PTR [ecx+eax*8+2], 0

; 127  : 
; 128  : 			Move[i].fd[j].next = &Move[i].fd[j + 1];

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	lea	eax, DWORD PTR [edx+ecx*8+8]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+40]
	mov	esi, DWORD PTR _j$65327[ebp]
	and	esi, 255				; 000000ffH
	mov	edx, DWORD PTR [ecx+edx+12]
	mov	DWORD PTR [edx+esi*8+4], eax

; 129  : 		}

	jmp	$L65337
$L65338:

; 130  : 		Move[i].fd[j].x = 4;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	WORD PTR [eax+edx*8], 4

; 131  : 		Move[i].fd[j].y = 0;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	mov	WORD PTR [ecx+eax*8+2], 0

; 132  : 		Move[i].fd[j].next = NULL;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	mov	DWORD PTR [edx+ecx*8+4], 0

; 133  : 
; 134  : 		tl= d->FindLayer("Map");

	push	OFFSET FLAT:??_C@_03DIFO@Map?$AA@	; `string'
	mov	ecx, DWORD PTR _d$65322[ebp]
	call	?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z	; DISPLAY::FindLayer
	mov	DWORD PTR _tl$65321[ebp], eax

; 135  : 		tl->d = Move[i].fd;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _tl$65321[ebp]
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	DWORD PTR [edx+32], eax

; 136  : 		tl->move = &Move[i];

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	add	ecx, edx
	mov	edx, DWORD PTR _tl$65321[ebp]
	mov	DWORD PTR [edx+20], ecx

; 137  : 		i++;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+28]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+28], cl

; 138  : 
; 139  : 
; 140  : 		//
; 141  : 		// Blue Goo move
; 142  : 		//
; 143  : 		tl= d->FindLayer("BlueGoo");

	push	OFFSET FLAT:??_C@_07NIEJ@BlueGoo?$AA@	; `string'
	mov	ecx, DWORD PTR _d$65322[ebp]
	call	?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z	; DISPLAY::FindLayer
	mov	DWORD PTR _tl$65321[ebp], eax

; 144  : 
; 145  : 		tl->mList = new MOVE*[4];

	push	16					; 00000010H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65514[ebp], eax
	mov	eax, DWORD PTR _tl$65321[ebp]
	mov	ecx, DWORD PTR $T65514[ebp]
	mov	DWORD PTR [eax+16], ecx

; 146  : 		ZeroMemory(tl->mList, 4*sizeof(MOVE));

	push	64					; 00000040H
	push	0
	mov	edx, DWORD PTR _tl$65321[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 147  : 		tl->move = &Move[i];

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	add	ecx, edx
	mov	edx, DWORD PTR _tl$65321[ebp]
	mov	DWORD PTR [edx+20], ecx

; 148  : 
; 149  : 		//
; 150  : 		// Right
; 151  : 		SetStr(&Move[i].Name, "Right");

	push	OFFSET FLAT:??_C@_05PNPP@Right?$AA@	; `string'
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	add	eax, ecx
	push	eax
	call	?SetStr@@YAXPAPADPBD@Z			; SetStr
	add	esp, 8

; 152  : 		Move[i].num = 5;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	BYTE PTR [ecx+edx+8], 5

; 153  : 		Move[i].fd = new XY[Move[i].num];

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax+8]
	shl	ecx, 3
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65515[ebp], eax
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR $T65515[ebp]
	mov	DWORD PTR [edx+eax+12], ecx

; 154  : 		Move[i].delay = 100;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	DWORD PTR [edx+eax+4], 100		; 00000064H

; 155  : 		for(j = 0; j < 4; j++)

	mov	BYTE PTR _j$65327[ebp], 0
	jmp	SHORT $L65347
$L65348:
	mov	al, BYTE PTR _j$65327[ebp]
	add	al, 1
	mov	BYTE PTR _j$65327[ebp], al
$L65347:
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	cmp	ecx, 4
	jge	$L65349

; 157  : 			Move[i].fd[j].x = 4;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	mov	WORD PTR [edx+ecx*8], 4

; 158  : 			Move[i].fd[j].y = 0;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	WORD PTR [eax+edx*8+2], 0

; 159  : 
; 160  : 			Move[i].fd[j].next = &Move[i].fd[j + 1];

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	lea	edx, DWORD PTR [ecx+eax*8+8]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+40]
	mov	esi, DWORD PTR _j$65327[ebp]
	and	esi, 255				; 000000ffH
	mov	ecx, DWORD PTR [eax+ecx+12]
	mov	DWORD PTR [ecx+esi*8+4], edx

; 161  : 		}

	jmp	$L65348
$L65349:

; 162  : 		Move[i].fd[j].x = 4;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	mov	WORD PTR [edx+ecx*8], 4

; 163  : 		Move[i].fd[j].y = 0;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	WORD PTR [eax+edx*8+2], 0

; 164  : 		Move[i].fd[j].next = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	mov	DWORD PTR [ecx+eax*8+4], 0

; 165  : 
; 166  : 		tl->d = Move[i].fd;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _tl$65321[ebp]
	mov	edx, DWORD PTR [edx+eax+12]
	mov	DWORD PTR [ecx+32], edx

; 167  : 		tl->mList[0] = &Move[i];

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	add	eax, ecx
	mov	ecx, DWORD PTR _tl$65321[ebp]
	mov	edx, DWORD PTR [ecx+16]
	mov	DWORD PTR [edx], eax

; 168  : 		i++;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+28]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+28], cl

; 169  : 
; 170  : 		// Left
; 171  : 		SetStr(&Move[i].Name, "Left");

	push	OFFSET FLAT:??_C@_04MKGK@Left?$AA@	; `string'
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	add	eax, ecx
	push	eax
	call	?SetStr@@YAXPAPADPBD@Z			; SetStr
	add	esp, 8

; 172  : 		Move[i].num = 5;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	BYTE PTR [ecx+edx+8], 5

; 173  : 		Move[i].fd = new XY[Move[i].num];

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax+8]
	shl	ecx, 3
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65516[ebp], eax
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR $T65516[ebp]
	mov	DWORD PTR [edx+eax+12], ecx

; 174  : 		Move[i].delay = 100;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	DWORD PTR [edx+eax+4], 100		; 00000064H

; 175  : 		for(j = 0; j < 4; j++)

	mov	BYTE PTR _j$65327[ebp], 0
	jmp	SHORT $L65353
$L65354:
	mov	al, BYTE PTR _j$65327[ebp]
	add	al, 1
	mov	BYTE PTR _j$65327[ebp], al
$L65353:
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	cmp	ecx, 4
	jge	$L65355

; 177  : 			Move[i].fd[j].x = -4;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	mov	WORD PTR [edx+ecx*8], -4		; fffffffcH

; 178  : 			Move[i].fd[j].y = 0;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	WORD PTR [eax+edx*8+2], 0

; 179  : 
; 180  : 			Move[i].fd[j].next = &Move[i].fd[j + 1];

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	lea	edx, DWORD PTR [ecx+eax*8+8]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+40]
	mov	esi, DWORD PTR _j$65327[ebp]
	and	esi, 255				; 000000ffH
	mov	ecx, DWORD PTR [eax+ecx+12]
	mov	DWORD PTR [ecx+esi*8+4], edx

; 181  : 		}

	jmp	$L65354
$L65355:

; 182  : 		Move[i].fd[j].x = -4;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	mov	WORD PTR [edx+ecx*8], -4		; fffffffcH

; 183  : 		Move[i].fd[j].y = 0;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	WORD PTR [eax+edx*8+2], 0

; 184  : 		Move[i].fd[j].next = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	mov	DWORD PTR [ecx+eax*8+4], 0

; 185  : 
; 186  : 		tl->mList[1] = &Move[i];

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	add	edx, eax
	mov	eax, DWORD PTR _tl$65321[ebp]
	mov	ecx, DWORD PTR [eax+16]
	mov	DWORD PTR [ecx+4], edx

; 187  : 		i++;

	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR [edx+28]
	add	al, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+28], al

; 188  : 
; 189  : 		// Up
; 190  : 		SetStr(&Move[i].Name, "Up");

	push	OFFSET FLAT:??_C@_02NCFM@Up?$AA@	; `string'
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	add	edx, eax
	push	edx
	call	?SetStr@@YAXPAPADPBD@Z			; SetStr
	add	esp, 8

; 191  : 		Move[i].num = 5;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	BYTE PTR [eax+ecx+8], 5

; 192  : 		Move[i].fd = new XY[Move[i].num];

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx+8]
	shl	eax, 3
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65517[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR $T65517[ebp]
	mov	DWORD PTR [ecx+edx+12], eax

; 193  : 		Move[i].delay = 100;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	DWORD PTR [ecx+edx+4], 100		; 00000064H

; 194  : 		for(j = 0; j < 4; j++)

	mov	BYTE PTR _j$65327[ebp], 0
	jmp	SHORT $L65359
$L65360:
	mov	dl, BYTE PTR _j$65327[ebp]
	add	dl, 1
	mov	BYTE PTR _j$65327[ebp], dl
$L65359:
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	cmp	eax, 4
	jge	$L65361

; 196  : 			Move[i].fd[j].x = 0;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	mov	WORD PTR [ecx+eax*8], 0

; 197  : 			Move[i].fd[j].y = -4;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	mov	WORD PTR [edx+ecx*8+2], -4		; fffffffcH

; 198  : 
; 199  : 			Move[i].fd[j].next = &Move[i].fd[j + 1];

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	lea	ecx, DWORD PTR [eax+edx*8+8]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+40]
	mov	esi, DWORD PTR _j$65327[ebp]
	and	esi, 255				; 000000ffH
	mov	eax, DWORD PTR [edx+eax+12]
	mov	DWORD PTR [eax+esi*8+4], ecx

; 200  : 		}

	jmp	$L65360
$L65361:

; 201  : 		Move[i].fd[j].x = 0;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	mov	WORD PTR [ecx+eax*8], 0

; 202  : 		Move[i].fd[j].y = -4;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	mov	WORD PTR [edx+ecx*8+2], -4		; fffffffcH

; 203  : 		Move[i].fd[j].next = NULL;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	DWORD PTR [eax+edx*8+4], 0

; 204  : 
; 205  : 		tl->mList[2] = &Move[i];

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	add	ecx, edx
	mov	edx, DWORD PTR _tl$65321[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR [eax+8], ecx

; 206  : 		i++;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+28]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+28], dl

; 207  : 
; 208  : 		// Down
; 209  : 		SetStr(&Move[i].Name, "Down");

	push	OFFSET FLAT:??_C@_04IH@Down?$AA@	; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	add	ecx, edx
	push	ecx
	call	?SetStr@@YAXPAPADPBD@Z			; SetStr
	add	esp, 8

; 210  : 		Move[i].num = 5;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	BYTE PTR [edx+eax+8], 5

; 211  : 		Move[i].fd = new XY[Move[i].num];

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx+8]
	shl	edx, 3
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65518[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR $T65518[ebp]
	mov	DWORD PTR [eax+ecx+12], edx

; 212  : 		Move[i].delay = 100;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	DWORD PTR [eax+ecx+4], 100		; 00000064H

; 213  : 		for(j = 0; j < 4; j++)

	mov	BYTE PTR _j$65327[ebp], 0
	jmp	SHORT $L65365
$L65366:
	mov	cl, BYTE PTR _j$65327[ebp]
	add	cl, 1
	mov	BYTE PTR _j$65327[ebp], cl
$L65365:
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	cmp	edx, 4
	jge	$L65367

; 215  : 			Move[i].fd[j].x = 0;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	WORD PTR [eax+edx*8], 0

; 216  : 			Move[i].fd[j].y = 4;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	mov	WORD PTR [ecx+eax*8+2], 4

; 217  : 
; 218  : 			Move[i].fd[j].next = &Move[i].fd[j + 1];

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	lea	eax, DWORD PTR [edx+ecx*8+8]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+40]
	mov	esi, DWORD PTR _j$65327[ebp]
	and	esi, 255				; 000000ffH
	mov	edx, DWORD PTR [ecx+edx+12]
	mov	DWORD PTR [edx+esi*8+4], eax

; 219  : 		}

	jmp	$L65366
$L65367:

; 220  : 		Move[i].fd[j].x = 0;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR [eax+ecx+12]
	mov	WORD PTR [eax+edx*8], 0

; 221  : 		Move[i].fd[j].y = 4;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+28]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	eax, DWORD PTR _j$65327[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [ecx+edx+12]
	mov	WORD PTR [ecx+eax*8+2], 4

; 222  : 		Move[i].fd[j].next = NULL;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+28]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [edx+eax+12]
	mov	DWORD PTR [edx+ecx*8+4], 0

; 223  : 
; 224  : 		tl->mList[3] = &Move[i];

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+28]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	add	eax, ecx
	mov	ecx, DWORD PTR _tl$65321[ebp]
	mov	edx, DWORD PTR [ecx+16]
	mov	DWORD PTR [edx+12], eax

; 225  : 		i++;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+28]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+28], cl

; 226  : 
; 227  : 		LAYER *tl2 = d->FindLayer("RedGoo");

	push	OFFSET FLAT:??_C@_06DJMK@RedGoo?$AA@	; `string'
	mov	ecx, DWORD PTR _d$65322[ebp]
	call	?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z	; DISPLAY::FindLayer
	mov	DWORD PTR _tl2$65368[ebp], eax

; 228  : 		tl2->mList = tl->mList;

	mov	eax, DWORD PTR _tl2$65368[ebp]
	mov	ecx, DWORD PTR _tl$65321[ebp]
	mov	edx, DWORD PTR [ecx+16]
	mov	DWORD PTR [eax+16], edx

; 229  : 		tl2->move = tl->move;

	mov	eax, DWORD PTR _tl2$65368[ebp]
	mov	ecx, DWORD PTR _tl$65321[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	DWORD PTR [eax+20], edx

; 230  : 
; 231  : 		tl2 = d->FindLayer("Super");

	push	OFFSET FLAT:??_C@_05COAO@Super?$AA@	; `string'
	mov	ecx, DWORD PTR _d$65322[ebp]
	call	?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z	; DISPLAY::FindLayer
	mov	DWORD PTR _tl2$65368[ebp], eax

; 232  : 		tl2->mList = tl->mList;

	mov	eax, DWORD PTR _tl2$65368[ebp]
	mov	ecx, DWORD PTR _tl$65321[ebp]
	mov	edx, DWORD PTR [ecx+16]
	mov	DWORD PTR [eax+16], edx

; 233  : 		tl2->move = tl->move;

	mov	eax, DWORD PTR _tl2$65368[ebp]
	mov	ecx, DWORD PTR _tl$65321[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	DWORD PTR [eax+20], edx

; 234  : 
; 235  : 		//
; 236  : 		//
; 237  : 		//
; 238  : 		unsigned __int8 nCol = 2;

	mov	BYTE PTR _nCol$65371[ebp], 2

; 239  : 		Col = new COL[nCol];

	mov	eax, DWORD PTR _nCol$65371[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 12					; 0000000cH
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65519[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T65519[ebp]
	mov	DWORD PTR [ecx+44], edx

; 240  : 		ZeroMemory(Col, nCol*sizeof(COL) );

	mov	eax, DWORD PTR _nCol$65371[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 12					; 0000000cH
	push	eax
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 241  : 		
; 242  : 		Col[0].type = CT_BOTH;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	BYTE PTR [ecx], 3

; 243  : 		Col[0].map = new MAP;

	push	8
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65520[ebp], eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+44]
	mov	ecx, DWORD PTR $T65520[ebp]
	mov	DWORD PTR [eax+8], ecx

; 244  : 		Col[0].map->nCol = 10;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+44]
	mov	ecx, DWORD PTR [eax+8]
	mov	BYTE PTR [ecx+1], 10			; 0000000aH

; 245  : 		Col[0].map->nRow = 10;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+44]
	mov	ecx, DWORD PTR [eax+8]
	mov	BYTE PTR [ecx], 10			; 0000000aH

; 246  : 		unsigned __int8 a1[10][10] =
; 247  : 		{
; 248  : 			{0,0,0,0,0, 0,0,0,0,0}, 

	mov	BYTE PTR _a1$65377[ebp], 0
	mov	BYTE PTR _a1$65377[ebp+1], 0
	mov	BYTE PTR _a1$65377[ebp+2], 0
	mov	BYTE PTR _a1$65377[ebp+3], 0
	mov	BYTE PTR _a1$65377[ebp+4], 0
	mov	BYTE PTR _a1$65377[ebp+5], 0
	mov	BYTE PTR _a1$65377[ebp+6], 0
	mov	BYTE PTR _a1$65377[ebp+7], 0
	mov	BYTE PTR _a1$65377[ebp+8], 0
	mov	BYTE PTR _a1$65377[ebp+9], 0

; 249  : 			{0,0,1,1,0, 0,0,0,0,0},

	mov	BYTE PTR _a1$65377[ebp+10], 0
	mov	BYTE PTR _a1$65377[ebp+11], 0
	mov	BYTE PTR _a1$65377[ebp+12], 1
	mov	BYTE PTR _a1$65377[ebp+13], 1
	mov	BYTE PTR _a1$65377[ebp+14], 0
	mov	BYTE PTR _a1$65377[ebp+15], 0
	mov	BYTE PTR _a1$65377[ebp+16], 0
	mov	BYTE PTR _a1$65377[ebp+17], 0
	mov	BYTE PTR _a1$65377[ebp+18], 0
	mov	BYTE PTR _a1$65377[ebp+19], 0

; 250  : 			{0,1,1,1,0, 0,0,1,0,0},

	mov	BYTE PTR _a1$65377[ebp+20], 0
	mov	BYTE PTR _a1$65377[ebp+21], 1
	mov	BYTE PTR _a1$65377[ebp+22], 1
	mov	BYTE PTR _a1$65377[ebp+23], 1
	mov	BYTE PTR _a1$65377[ebp+24], 0
	mov	BYTE PTR _a1$65377[ebp+25], 0
	mov	BYTE PTR _a1$65377[ebp+26], 0
	mov	BYTE PTR _a1$65377[ebp+27], 1
	mov	BYTE PTR _a1$65377[ebp+28], 0
	mov	BYTE PTR _a1$65377[ebp+29], 0

; 251  : 			{0,1,1,1,1, 1,1,1,1,0},

	mov	BYTE PTR _a1$65377[ebp+30], 0
	mov	BYTE PTR _a1$65377[ebp+31], 1
	mov	BYTE PTR _a1$65377[ebp+32], 1
	mov	BYTE PTR _a1$65377[ebp+33], 1
	mov	BYTE PTR _a1$65377[ebp+34], 1
	mov	BYTE PTR _a1$65377[ebp+35], 1
	mov	BYTE PTR _a1$65377[ebp+36], 1
	mov	BYTE PTR _a1$65377[ebp+37], 1
	mov	BYTE PTR _a1$65377[ebp+38], 1
	mov	BYTE PTR _a1$65377[ebp+39], 0

; 252  : 			{0,1,1,1,1, 1,1,1,1,0},

	mov	BYTE PTR _a1$65377[ebp+40], 0
	mov	BYTE PTR _a1$65377[ebp+41], 1
	mov	BYTE PTR _a1$65377[ebp+42], 1
	mov	BYTE PTR _a1$65377[ebp+43], 1
	mov	BYTE PTR _a1$65377[ebp+44], 1
	mov	BYTE PTR _a1$65377[ebp+45], 1
	mov	BYTE PTR _a1$65377[ebp+46], 1
	mov	BYTE PTR _a1$65377[ebp+47], 1
	mov	BYTE PTR _a1$65377[ebp+48], 1
	mov	BYTE PTR _a1$65377[ebp+49], 0

; 253  : 
; 254  : 			{0,1,0,1,0, 0,1,1,1,0},

	mov	BYTE PTR _a1$65377[ebp+50], 0
	mov	BYTE PTR _a1$65377[ebp+51], 1
	mov	BYTE PTR _a1$65377[ebp+52], 0
	mov	BYTE PTR _a1$65377[ebp+53], 1
	mov	BYTE PTR _a1$65377[ebp+54], 0
	mov	BYTE PTR _a1$65377[ebp+55], 0
	mov	BYTE PTR _a1$65377[ebp+56], 1
	mov	BYTE PTR _a1$65377[ebp+57], 1
	mov	BYTE PTR _a1$65377[ebp+58], 1
	mov	BYTE PTR _a1$65377[ebp+59], 0

; 255  : 			{0,1,1,0,1, 1,0,1,1,0},

	mov	BYTE PTR _a1$65377[ebp+60], 0
	mov	BYTE PTR _a1$65377[ebp+61], 1
	mov	BYTE PTR _a1$65377[ebp+62], 1
	mov	BYTE PTR _a1$65377[ebp+63], 0
	mov	BYTE PTR _a1$65377[ebp+64], 1
	mov	BYTE PTR _a1$65377[ebp+65], 1
	mov	BYTE PTR _a1$65377[ebp+66], 0
	mov	BYTE PTR _a1$65377[ebp+67], 1
	mov	BYTE PTR _a1$65377[ebp+68], 1
	mov	BYTE PTR _a1$65377[ebp+69], 0

; 256  : 			{0,0,0,0,1, 1,1,0,1,0},

	mov	BYTE PTR _a1$65377[ebp+70], 0
	mov	BYTE PTR _a1$65377[ebp+71], 0
	mov	BYTE PTR _a1$65377[ebp+72], 0
	mov	BYTE PTR _a1$65377[ebp+73], 0
	mov	BYTE PTR _a1$65377[ebp+74], 1
	mov	BYTE PTR _a1$65377[ebp+75], 1
	mov	BYTE PTR _a1$65377[ebp+76], 1
	mov	BYTE PTR _a1$65377[ebp+77], 0
	mov	BYTE PTR _a1$65377[ebp+78], 1
	mov	BYTE PTR _a1$65377[ebp+79], 0

; 257  : 			{0,1,1,1,1, 1,1,1,1,0},

	mov	BYTE PTR _a1$65377[ebp+80], 0
	mov	BYTE PTR _a1$65377[ebp+81], 1
	mov	BYTE PTR _a1$65377[ebp+82], 1
	mov	BYTE PTR _a1$65377[ebp+83], 1
	mov	BYTE PTR _a1$65377[ebp+84], 1
	mov	BYTE PTR _a1$65377[ebp+85], 1
	mov	BYTE PTR _a1$65377[ebp+86], 1
	mov	BYTE PTR _a1$65377[ebp+87], 1
	mov	BYTE PTR _a1$65377[ebp+88], 1
	mov	BYTE PTR _a1$65377[ebp+89], 0

; 258  : 			{0,0,0,0,0, 0,0,0,0,0}

	mov	BYTE PTR _a1$65377[ebp+90], 0
	mov	BYTE PTR _a1$65377[ebp+91], 0
	mov	BYTE PTR _a1$65377[ebp+92], 0
	mov	BYTE PTR _a1$65377[ebp+93], 0
	mov	BYTE PTR _a1$65377[ebp+94], 0
	mov	BYTE PTR _a1$65377[ebp+95], 0
	mov	BYTE PTR _a1$65377[ebp+96], 0
	mov	BYTE PTR _a1$65377[ebp+97], 0
	mov	BYTE PTR _a1$65377[ebp+98], 0
	mov	BYTE PTR _a1$65377[ebp+99], 0

; 259  : 		};
; 260  : 
; 261  : 
; 262  : 		Col[0].map->data = new unsigned __int8*[Col[0].map->nRow];

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+44]
	mov	ecx, DWORD PTR [eax+8]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 2
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65521[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR [ecx+8]
	mov	eax, DWORD PTR $T65521[ebp]
	mov	DWORD PTR [edx+4], eax

; 263  : 		ZeroMemory(Col[0].map->data, Col[0].map->nRow*sizeof(unsigned __int8*) );

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	mov	eax, DWORD PTR [edx+8]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 2
	push	ecx
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+44]
	mov	ecx, DWORD PTR [eax+8]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 264  : 		for(j = 0; j < Col[0].map->nRow; j++)

	mov	BYTE PTR _j$65327[ebp], 0
	jmp	SHORT $L65381
$L65382:
	mov	al, BYTE PTR _j$65327[ebp]
	add	al, 1
	mov	BYTE PTR _j$65327[ebp], al
$L65381:
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+44]
	mov	edx, DWORD PTR [eax+8]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	cmp	ecx, eax
	jge	SHORT $L65383

; 265  : 			SetArray(&Col[0].map->data[j], &a1[j][0], Col[0].map->nCol);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	mov	eax, DWORD PTR [edx+8]
	movzx	cx, BYTE PTR [eax+1]
	push	ecx
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 10					; 0000000aH
	lea	eax, DWORD PTR _a1$65377[ebp+edx]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	mov	eax, DWORD PTR [edx+8]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [eax+4]
	lea	eax, DWORD PTR [edx+ecx*4]
	push	eax
	call	?SetArray@@YAXPAPA_EPA_E_G@Z		; SetArray
	add	esp, 12					; 0000000cH
	jmp	SHORT $L65382
$L65383:

; 266  : 
; 267  : 		Col[0].nZone = 1;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	mov	BYTE PTR [edx+1], 1

; 268  : 		Col[0].zone = new XY_WH[Col[0].nZone];

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	shl	edx, 3
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65522[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR $T65522[ebp]
	mov	DWORD PTR [ecx+4], edx

; 269  : 		ZeroMemory(Col[0].zone, Col[0].nZone*sizeof(XY_WH));

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	shl	edx, 3
	push	edx
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 270  : 		Col[0].zone[0].x = 5;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR [ecx+4]
	mov	WORD PTR [edx], 5

; 271  : 		Col[0].zone[0].y = 5;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR [ecx+4]
	mov	WORD PTR [edx+2], 5

; 272  : 		Col[0].zone[0].w = 10;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR [ecx+4]
	mov	WORD PTR [edx+4], 10			; 0000000aH

; 273  : 		Col[0].zone[0].h = 10;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR [ecx+4]
	mov	WORD PTR [edx+6], 10			; 0000000aH

; 274  : 
; 275  : 		tl= d->FindLayer("BlueGoo");

	push	OFFSET FLAT:??_C@_07NIEJ@BlueGoo?$AA@	; `string'
	mov	ecx, DWORD PTR _d$65322[ebp]
	call	?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z	; DISPLAY::FindLayer
	mov	DWORD PTR _tl$65321[ebp], eax

; 276  : 		tl->col = &Col[0];

	mov	eax, DWORD PTR _tl$65321[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	mov	DWORD PTR [eax+40], edx

; 277  : 
; 278  : 		tl= d->FindLayer("RedGoo");

	push	OFFSET FLAT:??_C@_06DJMK@RedGoo?$AA@	; `string'
	mov	ecx, DWORD PTR _d$65322[ebp]
	call	?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z	; DISPLAY::FindLayer
	mov	DWORD PTR _tl$65321[ebp], eax

; 279  : 		tl->col = &Col[0];

	mov	eax, DWORD PTR _tl$65321[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	mov	DWORD PTR [eax+40], edx

; 280  : 
; 281  : 		Col[1].type = CT_BOTH;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	BYTE PTR [ecx+12], 3

; 282  : 		Col[1].map = new MAP;

	push	8
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65523[ebp], eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+44]
	mov	ecx, DWORD PTR $T65523[ebp]
	mov	DWORD PTR [eax+20], ecx

; 283  : 		Col[1].map->nCol = 10;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+44]
	mov	ecx, DWORD PTR [eax+20]
	mov	BYTE PTR [ecx+1], 10			; 0000000aH

; 284  : 		Col[1].map->nRow = 10;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+44]
	mov	ecx, DWORD PTR [eax+20]
	mov	BYTE PTR [ecx], 10			; 0000000aH

; 285  : 		unsigned __int8 a2[10][10] =
; 286  : 		{
; 287  : 			{0,0,0,0,0, 0,1,0,0,0}, 

	mov	BYTE PTR _a2$65389[ebp], 0
	mov	BYTE PTR _a2$65389[ebp+1], 0
	mov	BYTE PTR _a2$65389[ebp+2], 0
	mov	BYTE PTR _a2$65389[ebp+3], 0
	mov	BYTE PTR _a2$65389[ebp+4], 0
	mov	BYTE PTR _a2$65389[ebp+5], 0
	mov	BYTE PTR _a2$65389[ebp+6], 1
	mov	BYTE PTR _a2$65389[ebp+7], 0
	mov	BYTE PTR _a2$65389[ebp+8], 0
	mov	BYTE PTR _a2$65389[ebp+9], 0

; 288  : 			{0,6,2,3,7, 3,3,0,0,0},

	mov	BYTE PTR _a2$65389[ebp+10], 0
	mov	BYTE PTR _a2$65389[ebp+11], 6
	mov	BYTE PTR _a2$65389[ebp+12], 2
	mov	BYTE PTR _a2$65389[ebp+13], 3
	mov	BYTE PTR _a2$65389[ebp+14], 7
	mov	BYTE PTR _a2$65389[ebp+15], 3
	mov	BYTE PTR _a2$65389[ebp+16], 3
	mov	BYTE PTR _a2$65389[ebp+17], 0
	mov	BYTE PTR _a2$65389[ebp+18], 0
	mov	BYTE PTR _a2$65389[ebp+19], 0

; 289  : 			{0,2,2,2,0, 0,0,3,0,0},

	mov	BYTE PTR _a2$65389[ebp+20], 0
	mov	BYTE PTR _a2$65389[ebp+21], 2
	mov	BYTE PTR _a2$65389[ebp+22], 2
	mov	BYTE PTR _a2$65389[ebp+23], 2
	mov	BYTE PTR _a2$65389[ebp+24], 0
	mov	BYTE PTR _a2$65389[ebp+25], 0
	mov	BYTE PTR _a2$65389[ebp+26], 0
	mov	BYTE PTR _a2$65389[ebp+27], 3
	mov	BYTE PTR _a2$65389[ebp+28], 0
	mov	BYTE PTR _a2$65389[ebp+29], 0

; 290  : 			{0,3,2,2,2, 3,3,3,3,0},

	mov	BYTE PTR _a2$65389[ebp+30], 0
	mov	BYTE PTR _a2$65389[ebp+31], 3
	mov	BYTE PTR _a2$65389[ebp+32], 2
	mov	BYTE PTR _a2$65389[ebp+33], 2
	mov	BYTE PTR _a2$65389[ebp+34], 2
	mov	BYTE PTR _a2$65389[ebp+35], 3
	mov	BYTE PTR _a2$65389[ebp+36], 3
	mov	BYTE PTR _a2$65389[ebp+37], 3
	mov	BYTE PTR _a2$65389[ebp+38], 3
	mov	BYTE PTR _a2$65389[ebp+39], 0

; 291  : 			{0,3,2,2,2, 2,3,3,3,0},

	mov	BYTE PTR _a2$65389[ebp+40], 0
	mov	BYTE PTR _a2$65389[ebp+41], 3
	mov	BYTE PTR _a2$65389[ebp+42], 2
	mov	BYTE PTR _a2$65389[ebp+43], 2
	mov	BYTE PTR _a2$65389[ebp+44], 2
	mov	BYTE PTR _a2$65389[ebp+45], 2
	mov	BYTE PTR _a2$65389[ebp+46], 3
	mov	BYTE PTR _a2$65389[ebp+47], 3
	mov	BYTE PTR _a2$65389[ebp+48], 3
	mov	BYTE PTR _a2$65389[ebp+49], 0

; 292  : 
; 293  : 			{0,3,0,2,0, 0,2,2,3,0},

	mov	BYTE PTR _a2$65389[ebp+50], 0
	mov	BYTE PTR _a2$65389[ebp+51], 3
	mov	BYTE PTR _a2$65389[ebp+52], 0
	mov	BYTE PTR _a2$65389[ebp+53], 2
	mov	BYTE PTR _a2$65389[ebp+54], 0
	mov	BYTE PTR _a2$65389[ebp+55], 0
	mov	BYTE PTR _a2$65389[ebp+56], 2
	mov	BYTE PTR _a2$65389[ebp+57], 2
	mov	BYTE PTR _a2$65389[ebp+58], 3
	mov	BYTE PTR _a2$65389[ebp+59], 0

; 294  : 			{0,3,3,0,3, 3,0,2,3,0},

	mov	BYTE PTR _a2$65389[ebp+60], 0
	mov	BYTE PTR _a2$65389[ebp+61], 3
	mov	BYTE PTR _a2$65389[ebp+62], 3
	mov	BYTE PTR _a2$65389[ebp+63], 0
	mov	BYTE PTR _a2$65389[ebp+64], 3
	mov	BYTE PTR _a2$65389[ebp+65], 3
	mov	BYTE PTR _a2$65389[ebp+66], 0
	mov	BYTE PTR _a2$65389[ebp+67], 2
	mov	BYTE PTR _a2$65389[ebp+68], 3
	mov	BYTE PTR _a2$65389[ebp+69], 0

; 295  : 			{0,0,0,0,4, 3,3,0,3,0},

	mov	BYTE PTR _a2$65389[ebp+70], 0
	mov	BYTE PTR _a2$65389[ebp+71], 0
	mov	BYTE PTR _a2$65389[ebp+72], 0
	mov	BYTE PTR _a2$65389[ebp+73], 0
	mov	BYTE PTR _a2$65389[ebp+74], 4
	mov	BYTE PTR _a2$65389[ebp+75], 3
	mov	BYTE PTR _a2$65389[ebp+76], 3
	mov	BYTE PTR _a2$65389[ebp+77], 0
	mov	BYTE PTR _a2$65389[ebp+78], 3
	mov	BYTE PTR _a2$65389[ebp+79], 0

; 296  : 			{5,4,4,4,4, 3,3,3,3,0},

	mov	BYTE PTR _a2$65389[ebp+80], 5
	mov	BYTE PTR _a2$65389[ebp+81], 4
	mov	BYTE PTR _a2$65389[ebp+82], 4
	mov	BYTE PTR _a2$65389[ebp+83], 4
	mov	BYTE PTR _a2$65389[ebp+84], 4
	mov	BYTE PTR _a2$65389[ebp+85], 3
	mov	BYTE PTR _a2$65389[ebp+86], 3
	mov	BYTE PTR _a2$65389[ebp+87], 3
	mov	BYTE PTR _a2$65389[ebp+88], 3
	mov	BYTE PTR _a2$65389[ebp+89], 0

; 297  : 			{0,0,0,0,0, 0,0,0,0,0}

	mov	BYTE PTR _a2$65389[ebp+90], 0
	mov	BYTE PTR _a2$65389[ebp+91], 0
	mov	BYTE PTR _a2$65389[ebp+92], 0
	mov	BYTE PTR _a2$65389[ebp+93], 0
	mov	BYTE PTR _a2$65389[ebp+94], 0
	mov	BYTE PTR _a2$65389[ebp+95], 0
	mov	BYTE PTR _a2$65389[ebp+96], 0
	mov	BYTE PTR _a2$65389[ebp+97], 0
	mov	BYTE PTR _a2$65389[ebp+98], 0
	mov	BYTE PTR _a2$65389[ebp+99], 0

; 298  : 		};
; 299  : 
; 300  : 		Col[1].map->data = new unsigned __int8*[Col[1].map->nRow];

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+44]
	mov	ecx, DWORD PTR [eax+20]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 2
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65524[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR [ecx+20]
	mov	eax, DWORD PTR $T65524[ebp]
	mov	DWORD PTR [edx+4], eax

; 301  : 		ZeroMemory(Col[1].map->data, Col[1].map->nRow*sizeof(unsigned __int8*) );

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	mov	eax, DWORD PTR [edx+20]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 2
	push	ecx
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+44]
	mov	ecx, DWORD PTR [eax+20]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 302  : 		for(j = 0; j < Col[1].map->nRow; j++)

	mov	BYTE PTR _j$65327[ebp], 0
	jmp	SHORT $L65393
$L65394:
	mov	al, BYTE PTR _j$65327[ebp]
	add	al, 1
	mov	BYTE PTR _j$65327[ebp], al
$L65393:
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+44]
	mov	edx, DWORD PTR [eax+20]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	cmp	ecx, eax
	jge	SHORT $L65395

; 303  : 			SetArray(&Col[1].map->data[j], &a2[j][0], Col[1].map->nCol);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	mov	eax, DWORD PTR [edx+20]
	movzx	cx, BYTE PTR [eax+1]
	push	ecx
	mov	edx, DWORD PTR _j$65327[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 10					; 0000000aH
	lea	eax, DWORD PTR _a2$65389[ebp+edx]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	mov	eax, DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _j$65327[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [eax+4]
	lea	eax, DWORD PTR [edx+ecx*4]
	push	eax
	call	?SetArray@@YAXPAPA_EPA_E_G@Z		; SetArray
	add	esp, 12					; 0000000cH
	jmp	SHORT $L65394
$L65395:

; 304  : 
; 305  : 		Col[1].nZone = 1;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	mov	BYTE PTR [edx+13], 1

; 306  : 		Col[1].zone = new XY_WH[Col[1].nZone];

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+13]
	shl	edx, 3
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65525[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR $T65525[ebp]
	mov	DWORD PTR [ecx+16], edx

; 307  : 		ZeroMemory(Col[1].zone, Col[1].nZone*sizeof(XY_WH));

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+13]
	shl	edx, 3
	push	edx
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 308  : 		Col[1].zone[0].x = 5;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR [ecx+16]
	mov	WORD PTR [edx], 5

; 309  : 		Col[1].zone[0].y = 5;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR [ecx+16]
	mov	WORD PTR [edx+2], 5

; 310  : 		Col[1].zone[0].w = 10;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR [ecx+16]
	mov	WORD PTR [edx+4], 10			; 0000000aH

; 311  : 		Col[1].zone[0].h = 10;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR [ecx+16]
	mov	WORD PTR [edx+6], 10			; 0000000aH

; 312  : 
; 313  : 		tl= d->FindLayer("Super");

	push	OFFSET FLAT:??_C@_05COAO@Super?$AA@	; `string'
	mov	ecx, DWORD PTR _d$65322[ebp]
	call	?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z	; DISPLAY::FindLayer
	mov	DWORD PTR _tl$65321[ebp], eax

; 314  : 		tl->col = &Col[1];

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	add	ecx, 12					; 0000000cH
	mov	edx, DWORD PTR _tl$65321[ebp]
	mov	DWORD PTR [edx+40], ecx
$L65320:

; 316  : 
; 317  : 	return 0;

	xor	al, al

; 318  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Load@ACTION@@QAE_NXZ ENDP				; ACTION::Load
_TEXT	ENDS
PUBLIC	??_C@_0CE@EGEM@Could?5not?5find?5layer?5by?5the?5name@ ; `string'
PUBLIC	??_C@_05JKGE@?$CFs?5?$CFs?$AA@			; `string'
PUBLIC	?Error@ERRORCLASS@@QAA_NPADZZ			; ERRORCLASS::Error
EXTRN	__stricmp:NEAR
;	COMDAT ??_C@_0CE@EGEM@Could?5not?5find?5layer?5by?5the?5name@
; File d:\game programming\moggie software games\old code\old skull x\header files\displayclass.h
CONST	SEGMENT
??_C@_0CE@EGEM@Could?5not?5find?5layer?5by?5the?5name@ DB 'Could not find'
	DB	' layer by the name of', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_05JKGE@?$CFs?5?$CFs?$AA@
CONST	SEGMENT
??_C@_05JKGE@?$CFs?5?$CFs?$AA@ DB '%s %s', 00H		; `string'
CONST	ENDS
;	COMDAT ?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z
_TEXT	SEGMENT
_this$ = -4
_name$ = 8
?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z PROC NEAR	; DISPLAY::FindLayer, COMDAT

; 112  : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 113  : 			l = StartLayer;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+200]
	mov	DWORD PTR [eax+360], edx
$L58430:

; 114  : 			for(; l != NULL;)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+360], 0
	je	SHORT $L58431

; 116  : 				if( _stricmp(name, l->Name) == 0 )

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	call	__stricmp
	add	esp, 8
	test	eax, eax
	jne	SHORT $L58432

; 117  : 					return l;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	jmp	SHORT $L58428
$L58432:

; 118  : 				l = l->next;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+160]
	mov	DWORD PTR [edx+360], eax

; 119  : 			}

	jmp	SHORT $L58430
$L58431:

; 120  : 			Error("%s %s", "Could not find layer by the name of", name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_0CE@EGEM@Could?5not?5find?5layer?5by?5the?5name@ ; `string'
	push	OFFSET FLAT:??_C@_05JKGE@?$CFs?5?$CFs?$AA@ ; `string'
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 16					; 00000010H

; 121  : 			return NULL;

	xor	eax, eax
$L58428:

; 122  : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?FindLayer@DISPLAY@@QAEPAVLAYER@@PAD@Z ENDP		; DISPLAY::FindLayer
_TEXT	ENDS
PUBLIC	?GetType@ERRORCLASS@@AAEHH@Z			; ERRORCLASS::GetType
PUBLIC	??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ ; `string'
PUBLIC	??_C@_05CKBG@Error?$AA@				; `string'
EXTRN	__imp__MessageBoxA@16:NEAR
EXTRN	__imp__GetDesktopWindow@0:NEAR
EXTRN	_vsprintf:NEAR
;	COMDAT ??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@
; File d:\game programming\moggie software games\old code\old skull x\header files\errorclass.h
CONST	SEGMENT
??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ DB 'Problem with erro'
	DB	'r message.', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_05CKBG@Error?$AA@
CONST	SEGMENT
??_C@_05CKBG@Error?$AA@ DB 'Error', 00H			; `string'
CONST	ENDS
;	COMDAT ?Error@ERRORCLASS@@QAA_NPADZZ
_TEXT	SEGMENT
_m$ = 12
_this$ = 8
_mTemp$ = -256
_vl$ = -260
_Ok$ = -264
$T65530 = -268
$T65531 = -272
?Error@ERRORCLASS@@QAA_NPADZZ PROC NEAR			; ERRORCLASS::Error, COMDAT

; 108  : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 336				; 00000150H
	push	ebx
	push	esi
	push	edi

; 109  : 			char		mTemp[256];
; 110  : 			va_list	vl;
; 111  : 
; 112  : 			if(m != NULL)

	cmp	DWORD PTR _m$[ebp], 0
	je	SHORT $L54070

; 114  : 				if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L54071

; 116  : 					PrevMsgFormat = new char[strlen(MsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65530[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T65530[ebp]
	mov	DWORD PTR [eax+4], ecx

; 117  : 					strcpy(PrevMsgFormat, MsgFormat);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	call	_strcpy
	add	esp, 8
$L54071:

; 119  : 
; 120  : 				MsgFormat = new char[strlen(m)];

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65531[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T65531[ebp]
	mov	DWORD PTR [ecx], edx

; 121  : 				strcpy(MsgFormat, m);

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8
$L54070:

; 123  : 
; 124  : 			if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L54076

; 126  : 				if(strlen(MsgFormat) > 0)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	test	eax, eax
	jbe	SHORT $L54077

; 128  : 					va_start(vl, m);

	lea	eax, DWORD PTR _m$[ebp+4]
	mov	DWORD PTR _vl$[ebp], eax

; 129  : 					vsprintf(mTemp, MsgFormat, vl);

	mov	ecx, DWORD PTR _vl$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	lea	ecx, DWORD PTR _mTemp$[ebp]
	push	ecx
	call	_vsprintf
	add	esp, 12					; 0000000cH

; 130  : 					va_end(vl);

	mov	DWORD PTR _vl$[ebp], 0

; 132  : 				else

	jmp	SHORT $L54082
$L54077:

; 133  : 					strcpy(mTemp, "Problem with error message.");

	push	OFFSET FLAT:??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ ; `string'
	lea	edx, DWORD PTR _mTemp$[ebp]
	push	edx
	call	_strcpy
	add	esp, 8
$L54082:

; 135  : 			else

	jmp	SHORT $L54084
$L54076:

; 136  : 				return 1;

	mov	al, 1
	jmp	$L54091
$L54084:

; 137  : 
; 138  : 			if(Type < 0)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	and	ecx, 3
	test	ecx, ecx
	jae	SHORT $L54085

; 139  : 				Type = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	al, -4					; fffffffcH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+8], eax
$L54085:

; 140  : 			
; 141  : 			if(hWnd == NULL)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+12], 0
	jne	SHORT $L54086

; 142  : 				hWnd = GetDesktopWindow();

	call	DWORD PTR __imp__GetDesktopWindow@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L54086:

; 143  : 
; 144  : 			int Ok = MessageBox(hWnd, mTemp, "Error", GetType(Type) | MB_SYSTEMMODAL );

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	eax, 3
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?GetType@ERRORCLASS@@AAEHH@Z		; ERRORCLASS::GetType
	or	ah, 16					; 00000010H
	push	eax
	push	OFFSET FLAT:??_C@_05CKBG@Error?$AA@	; `string'
	lea	ecx, DWORD PTR _mTemp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+12]
	push	eax
	call	DWORD PTR __imp__MessageBoxA@16
	mov	DWORD PTR _Ok$[ebp], eax

; 145  : 
; 146  : 			if( (Ok == IDOK ) || ( Ok == IDNO ) || ( Ok == IDCANCEL ) )

	cmp	DWORD PTR _Ok$[ebp], 1
	je	SHORT $L54090
	cmp	DWORD PTR _Ok$[ebp], 7
	je	SHORT $L54090
	cmp	DWORD PTR _Ok$[ebp], 2
	jne	SHORT $L54089
$L54090:

; 147  : 				return 1;

	mov	al, 1
	jmp	SHORT $L54091
$L54089:

; 149  : 				return 0;

	xor	al, al
$L54091:

; 150  : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Error@ERRORCLASS@@QAA_NPADZZ ENDP			; ERRORCLASS::Error
_TEXT	ENDS
;	COMDAT ?GetType@ERRORCLASS@@AAEHH@Z
_TEXT	SEGMENT
_this$ = -4
?GetType@ERRORCLASS@@AAEHH@Z PROC NEAR			; ERRORCLASS::GetType, COMDAT

; 30   : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 31   : 			if(Type == ETYPE_OK)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	and	ecx, 3
	test	ecx, ecx
	jne	SHORT $L54010

; 32   : 				return MB_OK;

	xor	eax, eax
	jmp	SHORT $L54015
$L54010:

; 33   : 			else if(Type == ETYPE_YESNO)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	eax, 3
	cmp	eax, 1
	jne	SHORT $L54012

; 34   : 				return MB_YESNO;

	mov	eax, 4
	jmp	SHORT $L54015
$L54012:

; 35   : 			else if(Type == ETYPE_RETRY)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	and	edx, 3
	cmp	edx, 2
	jne	SHORT $L54014

; 36   : 				return MB_RETRYCANCEL;

	mov	eax, 5
	jmp	SHORT $L54015
$L54014:

; 38   : 				return MB_OK;

	xor	eax, eax
$L54015:

; 39   : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?GetType@ERRORCLASS@@AAEHH@Z ENDP			; ERRORCLASS::GetType
_TEXT	ENDS
PUBLIC	?MoveObject@ACTION@@QAEXPAVLAYER@@@Z		; ACTION::MoveObject
EXTRN	__imp__OffsetRect@12:NEAR
EXTRN	__imp__GetTickCount@0:NEAR
;	COMDAT ?MoveObject@ACTION@@QAEXPAVLAYER@@@Z
_TEXT	SEGMENT
_l$ = 8
_this$ = -4
?MoveObject@ACTION@@QAEXPAVLAYER@@@Z PROC NEAR		; ACTION::MoveObject, COMDAT

; 321  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 322  : 	tm = l->move;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	DWORD PTR [eax+36], edx

; 323  : 
; 324  : 	tick = GetTickCount();

	call	DWORD PTR __imp__GetTickCount@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+32], eax

; 325  : 	if( (unsigned)(tick - l->move_tick) > tm->delay)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _l$[ebp]
	mov	ecx, DWORD PTR [edx+32]
	sub	ecx, DWORD PTR [eax+36]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+36]
	cmp	ecx, DWORD PTR [eax+4]
	jbe	$L65411

; 327  : 		l->move_tick = tick;

	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+32]
	mov	DWORD PTR [ecx+36], eax

; 328  : 		OffsetRect(&l->r, l->d->x, l->d->y);

	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+32]
	movsx	eax, WORD PTR [edx+2]
	push	eax
	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+32]
	movsx	eax, WORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _l$[ebp]
	add	ecx, 80					; 00000050H
	push	ecx
	call	DWORD PTR __imp__OffsetRect@12

; 329  : 
; 330  : 		l->redraw = true;

	mov	edx, DWORD PTR _l$[ebp]
	mov	BYTE PTR [edx+8], 1

; 331  : 
; 332  : 		l->d = l->d->next;

	mov	eax, DWORD PTR _l$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	mov	edx, DWORD PTR _l$[ebp]
	mov	eax, DWORD PTR [ecx+4]
	mov	DWORD PTR [edx+32], eax

; 333  : 		if(l->d == NULL)

	mov	ecx, DWORD PTR _l$[ebp]
	cmp	DWORD PTR [ecx+32], 0
	jne	SHORT $L65411

; 335  : 			if(l->move_type == LT_FOREVER)

	mov	edx, DWORD PTR _l$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+26]
	cmp	eax, 2
	jne	SHORT $L65406

; 336  : 				l->d = tm->fd;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+36]
	mov	eax, DWORD PTR _l$[ebp]
	mov	ecx, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+32], ecx

; 337  : 			else if( (l->move_type == LT_ONCE) || (l->move_count == 0) )

	jmp	SHORT $L65411
$L65406:
	mov	edx, DWORD PTR _l$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+26]
	test	eax, eax
	je	SHORT $L65409
	mov	ecx, DWORD PTR _l$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+27]
	test	edx, edx
	jne	SHORT $L65408
$L65409:

; 338  : 				l->movement_done = true;

	mov	eax, DWORD PTR _l$[ebp]
	mov	BYTE PTR [eax+25], 1

; 339  : 			else if( (l->move_type == LT_NUMBER) && (l->move_count > 0) )

	jmp	SHORT $L65411
$L65408:
	mov	ecx, DWORD PTR _l$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+26]
	cmp	edx, 1
	jne	SHORT $L65411
	mov	eax, DWORD PTR _l$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+27]
	test	ecx, ecx
	jle	SHORT $L65411

; 341  : 				l->move_count--;

	mov	edx, DWORD PTR _l$[ebp]
	mov	al, BYTE PTR [edx+27]
	sub	al, 1
	mov	ecx, DWORD PTR _l$[ebp]
	mov	BYTE PTR [ecx+27], al

; 342  : 				l->d = tm->fd;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+36]
	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+32], edx
$L65411:

; 346  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?MoveObject@ACTION@@QAEXPAVLAYER@@@Z ENDP		; ACTION::MoveObject
_TEXT	ENDS
PUBLIC	?CheckCol@ACTION@@QAEXPAVLAYER@@@Z		; ACTION::CheckCol
;	COMDAT ?CheckCol@ACTION@@QAEXPAVLAYER@@@Z
_TEXT	SEGMENT
_l$ = 8
_this$ = -4
_r1$ = -20
_r2$ = -36
_hit_something$ = -40
?CheckCol@ACTION@@QAEXPAVLAYER@@@Z PROC NEAR		; ACTION::CheckCol, COMDAT

; 349  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 104				; 00000068H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 350  : 	tc1 = l->col;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	DWORD PTR [eax+48], edx

; 351  : 
; 352  : 	RECT r1, r2;
; 353  : 	bool hit_something = false;

	mov	BYTE PTR _hit_something$[ebp], 0

; 354  : 	
; 355  : 	for(tl = l->prev; tl != NULL; tl = tl->prev)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+156]
	mov	DWORD PTR [eax+56], edx
	jmp	SHORT $L65419
$L65420:
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+156]
	mov	DWORD PTR [edx+56], eax
$L65419:
	mov	ecx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [ecx+56], 0
	je	$L65421

; 357  : 		tc2 = tl->col;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [eax+40]
	mov	DWORD PTR [ecx+52], edx

; 358  : 		if(!tl->hit && tl->collidable && GETBIT(tc2->type, CT_ZONE) )

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+45]
	test	edx, edx
	jne	$L65423
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+44]
	test	edx, edx
	je	$L65423
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	or	edx, -3					; fffffffdH
	xor	edx, 2
	not	edx
	test	edx, edx
	je	$L65423

; 360  : 			r1.left		= l->r.left + tc1->zone[0].x;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	mov	edx, DWORD PTR [ecx+4]
	movsx	eax, WORD PTR [edx]
	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+80]
	add	edx, eax
	mov	DWORD PTR _r1$[ebp], edx

; 361  : 			r1.top		= l->r.top + tc1->zone[0].y;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	mov	edx, DWORD PTR [ecx+4]
	movsx	eax, WORD PTR [edx+2]
	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+84]
	add	edx, eax
	mov	DWORD PTR _r1$[ebp+4], edx

; 362  : 			r1.right	= r1.left + tc1->zone[0].w;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	mov	edx, DWORD PTR [ecx+4]
	xor	eax, eax
	mov	ax, WORD PTR [edx+4]
	mov	ecx, DWORD PTR _r1$[ebp]
	add	ecx, eax
	mov	DWORD PTR _r1$[ebp+8], ecx

; 363  : 			r1.bottom	= r1.top + tc1->zone[0].h;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	ecx, DWORD PTR [eax+4]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+6]
	mov	eax, DWORD PTR _r1$[ebp+4]
	add	eax, edx
	mov	DWORD PTR _r1$[ebp+12], eax

; 364  : 			r2.left		= tl->r.left + tc2->zone[0].x;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	mov	eax, DWORD PTR [ecx+4]
	movsx	ecx, WORD PTR [eax]
	mov	edx, DWORD PTR [edx+80]
	add	edx, ecx
	mov	DWORD PTR _r2$[ebp], edx

; 365  : 			r2.top		= tl->r.top + tc2->zone[0].y;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+52]
	mov	edx, DWORD PTR [eax+4]
	movsx	eax, WORD PTR [edx+2]
	mov	ecx, DWORD PTR [ecx+84]
	add	ecx, eax
	mov	DWORD PTR _r2$[ebp+4], ecx

; 366  : 			r2.right	= r2.left + tc2->zone[0].w;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+52]
	mov	ecx, DWORD PTR [eax+4]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+4]
	mov	eax, DWORD PTR _r2$[ebp]
	add	eax, edx
	mov	DWORD PTR _r2$[ebp+8], eax

; 367  : 			r2.bottom	= r2.top + tc2->zone[0].h;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+52]
	mov	eax, DWORD PTR [edx+4]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+6]
	mov	edx, DWORD PTR _r2$[ebp+4]
	add	edx, ecx
	mov	DWORD PTR _r2$[ebp+12], edx

; 368  : 
; 369  : 			if( IN_RECT(r1, r2) )

	mov	eax, DWORD PTR _r1$[ebp+8]
	cmp	eax, DWORD PTR _r2$[ebp]
	jle	SHORT $L65423
	mov	ecx, DWORD PTR _r1$[ebp+12]
	cmp	ecx, DWORD PTR _r2$[ebp+4]
	jle	SHORT $L65423
	mov	edx, DWORD PTR _r1$[ebp]
	cmp	edx, DWORD PTR _r2$[ebp+8]
	jge	SHORT $L65423
	mov	eax, DWORD PTR _r1$[ebp+4]
	cmp	eax, DWORD PTR _r2$[ebp+12]
	jge	SHORT $L65423

; 371  : 				l->hit = true;

	mov	ecx, DWORD PTR _l$[ebp]
	mov	BYTE PTR [ecx+45], 1

; 372  : 				l->hitby = tl;

	mov	edx, DWORD PTR _l$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	DWORD PTR [edx+48], ecx

; 373  : 
; 374  : 				tl->hit = true;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	BYTE PTR [eax+45], 1

; 375  : 				tl->hitby = l;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR _l$[ebp]
	mov	DWORD PTR [edx+48], eax

; 376  : 
; 377  : 				hit_something = true;

	mov	BYTE PTR _hit_something$[ebp], 1
$L65423:

; 380  : 	}

	jmp	$L65420
$L65421:

; 381  : 
; 382  : 	if(!hit_something)

	mov	ecx, DWORD PTR _hit_something$[ebp]
	and	ecx, 255				; 000000ffH
	test	ecx, ecx
	jne	SHORT $L65424

; 383  : 		l->hit = false;

	mov	edx, DWORD PTR _l$[ebp]
	mov	BYTE PTR [edx+45], 0
$L65424:

; 384  : 
; 385  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?CheckCol@ACTION@@QAEXPAVLAYER@@@Z ENDP			; ACTION::CheckCol
_TEXT	ENDS
END
