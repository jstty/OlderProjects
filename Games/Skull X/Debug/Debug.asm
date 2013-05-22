	TITLE	D:\Game Programming\Moggie Software Games\old code\old Skull X\C++ Files\Debug.cpp
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
;	COMDAT ??_C@_04GGHG@Rate?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_09PNCL@Rate?5?$DN?5?$CFf?$AA@
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
;	COMDAT ?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ
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
;	COMDAT ?sLoop@VALUES@@QAE_NAAPAXPAD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Start@DEBUGCLASS@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CreateRoot@DEBUGCLASS@@AAEPAU_TREEITEM@@PAD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?End@DEBUGCLASS@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?AddToList@DEBUGCLASS@@AAEPAU_TREEITEM@@PAU2@PADPAXI@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CreateSub@DEBUGCLASS@@AAEPAU_TREEITEM@@PAU2@PADPAXI@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?ReFresh@DEBUGCLASS@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DebugProc@@YGHPAUHWND__@@IIJ@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?W@@3IA						; W
PUBLIC	?H@@3IA						; H
_BSS	SEGMENT
?W@@3IA	DD	01H DUP (?)				; W
?H@@3IA	DD	01H DUP (?)				; H
_BSS	ENDS
PUBLIC	?ReFresh@DEBUGCLASS@@QAEXXZ			; DEBUGCLASS::ReFresh
PUBLIC	?Start@DEBUGCLASS@@QAEXXZ			; DEBUGCLASS::Start
PUBLIC	?CreateRoot@DEBUGCLASS@@AAEPAU_TREEITEM@@PAD@Z	; DEBUGCLASS::CreateRoot
PUBLIC	??_C@_04GGHG@Rate?$AA@				; `string'
PUBLIC	??_C@_09PNCL@Rate?5?$DN?5?$CFf?$AA@		; `string'
PUBLIC	?CreateSub@DEBUGCLASS@@AAEPAU_TREEITEM@@PAU2@PADPAXI@Z ; DEBUGCLASS::CreateSub
EXTRN	?tsMain@@3VTestSpeed@@A:BYTE			; tsMain
EXTRN	__imp__SendMessageA@16:NEAR
;	COMDAT ??_C@_04GGHG@Rate?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\debug.cpp
CONST	SEGMENT
??_C@_04GGHG@Rate?$AA@ DB 'Rate', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_09PNCL@Rate?5?$DN?5?$CFf?$AA@
CONST	SEGMENT
??_C@_09PNCL@Rate?5?$DN?5?$CFf?$AA@ DB 'Rate = %f', 00H	; `string'
CONST	ENDS
;	COMDAT ?Start@DEBUGCLASS@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
_i$ = -8
_hTreeMain$ = -12
?Start@DEBUGCLASS@@QAEXXZ PROC NEAR			; DEBUGCLASS::Start, COMDAT

; 36   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 76					; 0000004cH
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 37   : 	__int8 i = 0;

	mov	BYTE PTR _i$[ebp], 0

; 38   : 	HTREEITEM hTreeMain;
; 39   : 
; 40   : //	HTREEITEM hTreeControls;
; 41   : //	HTREEITEM hTreeP1, hTreeP2;
; 42   : //	HTREEITEM hTree;
; 43   : //	HTREEITEM hTreeSub;
; 44   : //	HTREEITEM hTreeSprite[4];
; 45   : 
; 46   : 
; 47   : 	ListCount = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+24], 0

; 48   : 
; 49   : 	hTreeMain = CreateRoot("Rate");

	push	OFFSET FLAT:??_C@_04GGHG@Rate?$AA@	; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?CreateRoot@DEBUGCLASS@@AAEPAU_TREEITEM@@PAD@Z ; DEBUGCLASS::CreateRoot
	mov	DWORD PTR _hTreeMain$[ebp], eax

; 50   : 	CreateSub(hTreeMain, "Rate = %f",				&(tsMain.Rate), E_FLOAT);

	push	4
	push	OFFSET FLAT:?tsMain@@3VTestSpeed@@A+40
	push	OFFSET FLAT:??_C@_09PNCL@Rate?5?$DN?5?$CFf?$AA@ ; `string'
	mov	ecx, DWORD PTR _hTreeMain$[ebp]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?CreateSub@DEBUGCLASS@@AAEPAU_TREEITEM@@PAU2@PADPAXI@Z ; DEBUGCLASS::CreateSub

; 51   : /*
; 52   : 	CreateSub(hTreeMain, "Control = %f",			&(Val->Main->controls_rate), E_FLOAT);
; 53   : 	CreateSub(hTreeMain, "Level = %f",				&(Val->Main->level_rate), E_FLOAT);
; 54   : 	CreateSub(hTreeMain, "Display = %f",			&(Val->Main->display_rate), E_FLOAT);
; 55   : 	
; 56   : 	CreateSub(hTreeMain, "Move = %f",				&(Val->Display->move_rate), E_FLOAT);
; 57   : 	CreateSub(hTreeMain, "Anim = %f",				&(Val->Display->anim_rate), E_FLOAT);
; 58   : 	CreateSub(hTreeMain, "Clean = %f",				&(Val->Display->clean_rate), E_FLOAT);
; 59   : 	CreateSub(hTreeMain, "Draw = %f",				&(Val->Display->draw_rate), E_FLOAT);
; 60   : 	CreateSub(hTreeMain, "Screen = %f",				&(Val->Display->screen_rate), E_FLOAT);
; 61   : */
; 62   : 
; 63   : 	/*
; 64   : 	hTreeControls = CreateRoot("Controls");
; 65   : //
; 66   : 	hTreeP1 = CreateSub(hTreeControls, "Player1");
; 67   : 	hTreeP2 = CreateSub(hTreeControls, "Player2");
; 68   : 	TreeView_Expand(hCView, hTreeP1, TVE_EXPAND);
; 69   : 	TreeView_Expand(hCView, hTreeP2, TVE_EXPAND);
; 70   : //
; 71   : 	CreateSub(hTreeP1, "Up = %d",				&(Val->Controls->Player[0][UP]), E_BOOL );
; 72   : 	CreateSub(hTreeP1, "Down = %d",			&(Val->Controls->Player[0][DOWN]), E_BOOL );
; 73   : 	CreateSub(hTreeP1, "Left = %d",			&(Val->Controls->Player[0][LEFT]), E_BOOL );
; 74   : 	CreateSub(hTreeP1, "Right = %d",		&(Val->Controls->Player[0][RIGHT]), E_BOOL );
; 75   : 	CreateSub(hTreeP1, "Button 1 = %d",	&(Val->Controls->Player[0][B1]), E_BOOL );
; 76   : 	CreateSub(hTreeP1, "Button 2 = %d",	&(Val->Controls->Player[0][B2]), E_BOOL );
; 77   : 	CreateSub(hTreeP1, "Button 3 = %d",	&(Val->Controls->Player[0][B3]), E_BOOL );
; 78   : 	CreateSub(hTreeP1, "Button 4 = %d",	&(Val->Controls->Player[0][B4]), E_BOOL );
; 79   : 	CreateSub(hTreeP2, "Up = %d",				&(Val->Controls->Player[1][UP]), E_BOOL );
; 80   : 	CreateSub(hTreeP2, "Down = %d",			&(Val->Controls->Player[1][DOWN]), E_BOOL );
; 81   : 	CreateSub(hTreeP2, "Left = %d",			&(Val->Controls->Player[1][LEFT]), E_BOOL );
; 82   : 	CreateSub(hTreeP2, "Right = %d",		&(Val->Controls->Player[1][RIGHT]), E_BOOL );
; 83   : 	CreateSub(hTreeP2, "Button 1 = %d",	&(Val->Controls->Player[1][B1]), E_BOOL );
; 84   : 	CreateSub(hTreeP2, "Button 2 = %d",	&(Val->Controls->Player[1][B2]), E_BOOL );
; 85   : 	CreateSub(hTreeP2, "Button 3 = %d",	&(Val->Controls->Player[1][B3]), E_BOOL );
; 86   : 	CreateSub(hTreeP2, "Button 4 = %d",	&(Val->Controls->Player[1][B4]), E_BOOL );
; 87   : */
; 88   : 
; 89   : /*
; 90   : 	hTreeControls = CreateRoot("Controls");
; 91   : 	hTree = CreateSub(hTreeControls, "Mouse");
; 92   : 
; 93   : 	CreateSub(hTree, "d Mouse X Pos = %d",	&(Val->Display->Mouse->r.left), E_INT16 );
; 94   : 	CreateSub(hTree, "d Mouse Y Pos = %d",	&(Val->Display->Mouse->r.top), E_INT16 );
; 95   : 	
; 96   : 	CreateSub(hTree, "c Mouse X Pos = %d",	&(Val->Controls->Mouse.x), E_INT16 );
; 97   : 	CreateSub(hTree, "c Mouse Y Pos = %d",	&(Val->Controls->Mouse.y), E_INT16 );
; 98   : 
; 99   : 	CreateSub(hTree, "Mouse Left Click = %d",	&(Val->Controls->Mouse.Left), E_BOOL );
; 100  : 	CreateSub(hTree, "Mouse Right Click = %d",	&(Val->Controls->Mouse.Right), E_BOOL );
; 101  : 	CreateSub(hTree, "Mouse Mibble Click = %d",	&(Val->Controls->Mouse.Middle), E_BOOL );
; 102  : 	CreateSub(hTree, "Mouse Start X = %d",	&(Val->Controls->Mouse.StartX), E_INT16 );
; 103  : 	CreateSub(hTree, "Mouse Start Y = %d",	&(Val->Controls->Mouse.StartY), E_INT16 );
; 104  : 	CreateSub(hTree, "Mouse End X = %d",	&(Val->Controls->Mouse.EndX), E_INT16 );
; 105  : 	CreateSub(hTree, "Mouse End Y = %d",	&(Val->Controls->Mouse.EndY), E_INT16 );
; 106  : 
; 107  : 	TreeView_Expand(hCView, hTree, TVE_EXPAND);
; 108  : */
; 109  : 
; 110  : 	TreeView_Expand(hCView, hTreeMain, TVE_EXPAND);

	mov	edx, DWORD PTR _hTreeMain$[ebp]
	push	edx
	push	2
	push	4354					; 00001102H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	push	ecx
	call	DWORD PTR __imp__SendMessageA@16

; 111  : //	TreeView_Expand(hCView, hTree, TVE_EXPAND);
; 112  : 
; 113  : 	ReFresh();

	mov	ecx, DWORD PTR _this$[ebp]
	call	?ReFresh@DEBUGCLASS@@QAEXXZ		; DEBUGCLASS::ReFresh

; 114  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Start@DEBUGCLASS@@QAEXXZ ENDP				; DEBUGCLASS::Start
_TEXT	ENDS
EXTRN	_strlen:NEAR
;	COMDAT ?CreateRoot@DEBUGCLASS@@AAEPAU_TREEITEM@@PAD@Z
_TEXT	SEGMENT
_Name$ = 8
_this$ = -4
_tvInsert$ = -56
_tvItem$ = -96
?CreateRoot@DEBUGCLASS@@AAEPAU_TREEITEM@@PAD@Z PROC NEAR ; DEBUGCLASS::CreateRoot, COMDAT

; 119  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 160				; 000000a0H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 120  : 	TV_INSERTSTRUCT tvInsert;
; 121  : 	tvInsert.hParent = NULL;

	mov	DWORD PTR _tvInsert$[ebp], 0

; 122  : 	tvInsert.hInsertAfter = TVI_LAST;

	mov	DWORD PTR _tvInsert$[ebp+4], -65534	; ffff0002H

; 123  : 
; 124  : 	TV_ITEM tvItem;
; 125  : 	tvItem.mask = LVIF_TEXT;

	mov	DWORD PTR _tvItem$[ebp], 1

; 126  : 	tvItem.pszText = Name;

	mov	eax, DWORD PTR _Name$[ebp]
	mov	DWORD PTR _tvItem$[ebp+16], eax

; 127  : 	tvItem.cchTextMax = sizeof(char)*strlen(Name);

	mov	ecx, DWORD PTR _Name$[ebp]
	push	ecx
	call	_strlen
	add	esp, 4
	mov	DWORD PTR _tvItem$[ebp+20], eax

; 128  : 
; 129  : 	tvInsert.item = tvItem;

	mov	ecx, 10					; 0000000aH
	lea	esi, DWORD PTR _tvItem$[ebp]
	lea	edi, DWORD PTR _tvInsert$[ebp+8]
	rep movsd

; 130  : 
; 131  : 	return TreeView_InsertItem(hCView, &tvInsert);

	lea	edx, DWORD PTR _tvInsert$[ebp]
	push	edx
	push	0
	push	4352					; 00001100H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	push	ecx
	call	DWORD PTR __imp__SendMessageA@16

; 132  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?CreateRoot@DEBUGCLASS@@AAEPAU_TREEITEM@@PAD@Z ENDP	; DEBUGCLASS::CreateRoot
_TEXT	ENDS
PUBLIC	?End@DEBUGCLASS@@QAEXXZ				; DEBUGCLASS::End
EXTRN	?Val@@3PAVVALUES@@A:DWORD			; Val
EXTRN	?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z:NEAR	; FILE_UTIL::FreeMem
;	COMDAT ?End@DEBUGCLASS@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
?End@DEBUGCLASS@@QAEXXZ PROC NEAR			; DEBUGCLASS::End, COMDAT

; 137  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 138  : 	if( (htList != NULL) && (ListCount == 0) )

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+32], 0
	je	SHORT $L70052
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+24]
	test	edx, edx
	jne	SHORT $L70052

; 139  : 		Val->File_Util->FreeMem(htList);

	push	0
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 32					; 00000020H
	push	eax
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [ecx+52]
	call	?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z	; FILE_UTIL::FreeMem
$L70052:

; 140  : 
; 141  : 	ListCount = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+24], 0

; 142  : 	htList = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+32], 0

; 143  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?End@DEBUGCLASS@@QAEXXZ ENDP				; DEBUGCLASS::End
_TEXT	ENDS
PUBLIC	?AddToList@DEBUGCLASS@@AAEPAU_TREEITEM@@PAU2@PADPAXI@Z ; DEBUGCLASS::AddToList
EXTRN	??2@YAPAXI@Z:NEAR				; operator new
EXTRN	?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z:NEAR	; FILE_UTIL::LoadMem
EXTRN	_strcpy:NEAR
;	COMDAT ?AddToList@DEBUGCLASS@@AAEPAU_TREEITEM@@PAU2@PADPAXI@Z
_TEXT	SEGMENT
_ht$ = 8
_n$ = 12
_p$ = 16
_t$ = 20
_this$ = -4
_i$ = -8
$T70234 = -12
?AddToList@DEBUGCLASS@@AAEPAU_TREEITEM@@PAU2@PADPAXI@Z PROC NEAR ; DEBUGCLASS::AddToList, COMDAT

; 148  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 76					; 0000004cH
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 149  : 	ListCount++;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+24]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+24], cl

; 150  : 
; 151  : 	Val->File_Util->LoadMem((HGLOBAL &)tList, htList, sizeof(TreeList)*ListCount);

	push	0
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+24]
	shl	ecx, 4
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 32					; 00000020H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 28					; 0000001cH
	push	eax
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [ecx+52]
	call	?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z	; FILE_UTIL::LoadMem

; 152  : 
; 153  : 	unsigned int i = ListCount - 1;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+24]
	sub	eax, 1
	mov	DWORD PTR _i$[ebp], eax

; 154  : 
; 155  : 	tList[i].hTree = ht;

	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	edx, DWORD PTR _ht$[ebp]
	mov	DWORD PTR [eax+ecx], edx

; 156  : 	tList[i].Name = new char[strlen(n)];

	mov	eax, DWORD PTR _n$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T70234[ebp], eax
	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	edx, DWORD PTR $T70234[ebp]
	mov	DWORD PTR [eax+ecx+4], edx

; 157  : 	strcpy(tList[i].Name, n);

	mov	eax, DWORD PTR _n$[ebp]
	push	eax
	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	ecx, DWORD PTR [eax+ecx+4]
	push	ecx
	call	_strcpy
	add	esp, 8

; 158  : 	tList[i].Param = p;

	mov	edx, DWORD PTR _i$[ebp]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	mov	eax, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx+edx+8], eax

; 159  : 	tList[i].Type = t;

	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	edx, DWORD PTR _t$[ebp]
	and	edx, 7
	mov	eax, DWORD PTR [eax+ecx+12]
	and	al, -8					; fffffff8H
	or	eax, edx
	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+28]
	mov	DWORD PTR [edx+ecx+12], eax

; 160  : 
; 161  : 	return ht;

	mov	eax, DWORD PTR _ht$[ebp]

; 162  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?AddToList@DEBUGCLASS@@AAEPAU_TREEITEM@@PAU2@PADPAXI@Z ENDP ; DEBUGCLASS::AddToList
_TEXT	ENDS
;	COMDAT ?CreateSub@DEBUGCLASS@@AAEPAU_TREEITEM@@PAU2@PADPAXI@Z
_TEXT	SEGMENT
_hTree$ = 8
_Name$ = 12
_param$ = 16
_t$ = 20
_this$ = -4
_tvInsert$ = -56
_tvItem$ = -96
?CreateSub@DEBUGCLASS@@AAEPAU_TREEITEM@@PAU2@PADPAXI@Z PROC NEAR ; DEBUGCLASS::CreateSub, COMDAT

; 167  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 160				; 000000a0H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 168  : 	TV_INSERTSTRUCT tvInsert;
; 169  : 	tvInsert.hParent = hTree;

	mov	eax, DWORD PTR _hTree$[ebp]
	mov	DWORD PTR _tvInsert$[ebp], eax

; 170  : 	tvInsert.hInsertAfter = TVI_LAST;

	mov	DWORD PTR _tvInsert$[ebp+4], -65534	; ffff0002H

; 171  : 
; 172  : 	TV_ITEM tvItem;
; 173  : 	tvItem.mask = LVIF_TEXT;

	mov	DWORD PTR _tvItem$[ebp], 1

; 174  : 	tvItem.pszText = Name;

	mov	ecx, DWORD PTR _Name$[ebp]
	mov	DWORD PTR _tvItem$[ebp+16], ecx

; 175  : 	tvItem.cchTextMax = sizeof(char)*strlen(Name);

	mov	edx, DWORD PTR _Name$[ebp]
	push	edx
	call	_strlen
	add	esp, 4
	mov	DWORD PTR _tvItem$[ebp+20], eax

; 176  : 	
; 177  : 	tvInsert.item = tvItem;

	mov	ecx, 10					; 0000000aH
	lea	esi, DWORD PTR _tvItem$[ebp]
	lea	edi, DWORD PTR _tvInsert$[ebp+8]
	rep movsd

; 178  : 
; 179  : 	return AddToList(TreeView_InsertItem(hCView, &tvInsert), Name, param, t);

	mov	eax, DWORD PTR _t$[ebp]
	push	eax
	mov	ecx, DWORD PTR _param$[ebp]
	push	ecx
	mov	edx, DWORD PTR _Name$[ebp]
	push	edx
	lea	eax, DWORD PTR _tvInsert$[ebp]
	push	eax
	push	0
	push	4352					; 00001100H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	push	edx
	call	DWORD PTR __imp__SendMessageA@16
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?AddToList@DEBUGCLASS@@AAEPAU_TREEITEM@@PAU2@PADPAXI@Z ; DEBUGCLASS::AddToList

; 180  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?CreateSub@DEBUGCLASS@@AAEPAU_TREEITEM@@PAU2@PADPAXI@Z ENDP ; DEBUGCLASS::CreateSub
_TEXT	ENDS
EXTRN	_sprintf:NEAR
EXTRN	__fltused:NEAR
;	COMDAT ?ReFresh@DEBUGCLASS@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
_tvItem$ = -44
_Temp$ = -300
_i$ = -304
_iParam$70091 = -308
_iParam$70095 = -312
_iParam$70099 = -316
_fParam$70103 = -320
_fParam$70107 = -324
?ReFresh@DEBUGCLASS@@QAEXXZ PROC NEAR			; DEBUGCLASS::ReFresh, COMDAT

; 185  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 388				; 00000184H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 186  : 	TV_ITEM tvItem;
; 187  : 	char Temp[256];
; 188  : 	unsigned int i;
; 189  : 
; 190  : 	for(i = 0; i < ListCount; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L70086
$L70087:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L70086:
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+24]
	cmp	DWORD PTR _i$[ebp], edx
	jae	$L70088

; 192  : 		if(tList[i].Param != 0)

	mov	eax, DWORD PTR _i$[ebp]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	cmp	DWORD PTR [edx+eax+8], 0
	je	$L70089

; 194  : 			if(tList[i].Type == E_INT8)

	mov	eax, DWORD PTR _i$[ebp]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	mov	eax, DWORD PTR [edx+eax+12]
	and	eax, 7
	cmp	eax, 1
	jne	SHORT $L70090

; 196  : 				unsigned __int8 *iParam;
; 197  : 				iParam = (unsigned __int8 *)tList[i].Param;

	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	ecx, DWORD PTR [eax+ecx+8]
	mov	DWORD PTR _iParam$70091[ebp], ecx

; 198  : 				sprintf(Temp, tList[i].Name, *iParam);

	mov	edx, DWORD PTR _iParam$70091[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	ecx, DWORD PTR [eax+ecx+4]
	push	ecx
	lea	edx, DWORD PTR _Temp$[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 200  : 			else if(tList[i].Type == E_INT16)

	jmp	$L70109
$L70090:
	mov	eax, DWORD PTR _i$[ebp]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	mov	eax, DWORD PTR [edx+eax+12]
	and	eax, 7
	cmp	eax, 2
	jne	SHORT $L70094

; 202  : 				unsigned __int16 *iParam;
; 203  : 				iParam = (unsigned __int16 *)tList[i].Param;

	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	ecx, DWORD PTR [eax+ecx+8]
	mov	DWORD PTR _iParam$70095[ebp], ecx

; 204  : 				sprintf(Temp, tList[i].Name, *iParam);

	mov	edx, DWORD PTR _iParam$70095[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	ecx, DWORD PTR [eax+ecx+4]
	push	ecx
	lea	edx, DWORD PTR _Temp$[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 206  : 			else if(tList[i].Type == E_INT32)

	jmp	$L70109
$L70094:
	mov	eax, DWORD PTR _i$[ebp]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	mov	eax, DWORD PTR [edx+eax+12]
	and	eax, 7
	cmp	eax, 3
	jne	SHORT $L70098

; 208  : 				unsigned __int32 *iParam;
; 209  : 				iParam = (unsigned __int32 *)tList[i].Param;

	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	ecx, DWORD PTR [eax+ecx+8]
	mov	DWORD PTR _iParam$70099[ebp], ecx

; 210  : 				sprintf(Temp, tList[i].Name, *iParam);

	mov	edx, DWORD PTR _iParam$70099[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	ecx, DWORD PTR [eax+ecx+4]
	push	ecx
	lea	edx, DWORD PTR _Temp$[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 212  : 			else if(tList[i].Type == E_FLOAT)

	jmp	$L70109
$L70098:
	mov	eax, DWORD PTR _i$[ebp]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	mov	eax, DWORD PTR [edx+eax+12]
	and	eax, 7
	cmp	eax, 4
	jne	SHORT $L70102

; 214  : 				float *fParam;
; 215  : 				fParam = (float *)tList[i].Param;

	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	ecx, DWORD PTR [eax+ecx+8]
	mov	DWORD PTR _fParam$70103[ebp], ecx

; 216  : 				sprintf(Temp, tList[i].Name, *fParam);

	mov	edx, DWORD PTR _fParam$70103[ebp]
	fld	DWORD PTR [edx]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _i$[ebp]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	mov	eax, DWORD PTR [edx+eax+4]
	push	eax
	lea	ecx, DWORD PTR _Temp$[ebp]
	push	ecx
	call	_sprintf
	add	esp, 16					; 00000010H

; 218  : 			else if(tList[i].Type == E_BOOL)

	jmp	SHORT $L70109
$L70102:
	mov	edx, DWORD PTR _i$[ebp]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	mov	edx, DWORD PTR [ecx+edx+12]
	and	edx, 7
	cmp	edx, 5
	jne	SHORT $L70106

; 220  : 				bool *fParam;
; 221  : 				fParam = (bool *)tList[i].Param;

	mov	eax, DWORD PTR _i$[ebp]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	mov	eax, DWORD PTR [edx+eax+8]
	mov	DWORD PTR _fParam$70107[ebp], eax

; 222  : 				sprintf(Temp, tList[i].Name, *fParam);

	mov	ecx, DWORD PTR _fParam$70107[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _i$[ebp]
	shl	eax, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	mov	eax, DWORD PTR [edx+eax+4]
	push	eax
	lea	ecx, DWORD PTR _Temp$[ebp]
	push	ecx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 224  : 			else

	jmp	SHORT $L70109
$L70106:

; 225  : 				return;

	jmp	SHORT $L70082
$L70109:

; 226  : 
; 227  : 			tvItem.mask = LVIF_TEXT;

	mov	DWORD PTR _tvItem$[ebp], 1

; 228  : 			tvItem.hItem = tList[i].hTree;

	mov	edx, DWORD PTR _i$[ebp]
	shl	edx, 4
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	mov	edx, DWORD PTR [ecx+edx]
	mov	DWORD PTR _tvItem$[ebp+4], edx

; 229  : 			tvItem.pszText = Temp;

	lea	eax, DWORD PTR _Temp$[ebp]
	mov	DWORD PTR _tvItem$[ebp+16], eax

; 230  : 			tvItem.cchTextMax = sizeof(char)*strlen(Temp);

	lea	ecx, DWORD PTR _Temp$[ebp]
	push	ecx
	call	_strlen
	add	esp, 4
	mov	DWORD PTR _tvItem$[ebp+20], eax

; 231  : 
; 232  : 			TreeView_SetItem(hCView, &tvItem);

	lea	edx, DWORD PTR _tvItem$[ebp]
	push	edx
	push	0
	push	4365					; 0000110dH
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	push	ecx
	call	DWORD PTR __imp__SendMessageA@16
$L70089:

; 234  : 	}

	jmp	$L70087
$L70088:
$L70082:

; 235  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?ReFresh@DEBUGCLASS@@QAEXXZ ENDP			; DEBUGCLASS::ReFresh
_TEXT	ENDS
PUBLIC	?DebugProc@@YGHPAUHWND__@@IIJ@Z			; DebugProc
PUBLIC	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ		; MAIN::Get_MainHwnd
EXTRN	__imp__DestroyWindow@4:NEAR
EXTRN	__imp__SetWindowPos@28:NEAR
EXTRN	?Debug@@3VDEBUGCLASS@@A:BYTE			; Debug
EXTRN	__imp__GetDlgItem@8:NEAR
EXTRN	_abs:NEAR
EXTRN	__imp__GetClientRect@8:NEAR
EXTRN	__imp__GetWindowRect@8:NEAR
EXTRN	__imp__SetFocus@4:NEAR
;	COMDAT ?DebugProc@@YGHPAUHWND__@@IIJ@Z
_TEXT	SEGMENT
_hwnd$ = 8
_msg$ = 12
_wParam$ = 16
_lParam$ = 20
_Rect1$70121 = -16
_Rect2$70122 = -32
_xMax$70123 = -36
_yMax$70124 = -40
_w$70140 = -44
_h$70141 = -48
_Rect$70142 = -64
?DebugProc@@YGHPAUHWND__@@IIJ@Z PROC NEAR		; DebugProc, COMDAT

; 241  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 128				; 00000080H
	push	ebx
	push	esi
	push	edi

; 242  : 	if(msg == WM_INITDIALOG)

	cmp	DWORD PTR _msg$[ebp], 272		; 00000110H
	jne	$L70120

; 244  : 		Debug.End();

	mov	ecx, OFFSET FLAT:?Debug@@3VDEBUGCLASS@@A
	call	?End@DEBUGCLASS@@QAEXXZ			; DEBUGCLASS::End

; 245  : 		RECT Rect1, Rect2;
; 246  : 		int xMax, yMax;
; 247  : 
; 248  : 		GetWindowRect(Val->Main->Get_MainHwnd(), &Rect1);

	lea	eax, DWORD PTR _Rect1$70121[ebp]
	push	eax
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [ecx+56]
	call	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ	; MAIN::Get_MainHwnd
	push	eax
	call	DWORD PTR __imp__GetWindowRect@8

; 249  : 		GetClientRect(Val->Main->Get_MainHwnd(), &Rect2);

	lea	edx, DWORD PTR _Rect2$70122[ebp]
	push	edx
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+56]
	call	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ	; MAIN::Get_MainHwnd
	push	eax
	call	DWORD PTR __imp__GetClientRect@8

; 250  : 		xMax = (int)( Rect1.right + Rect2.left - Rect2.right );

	mov	ecx, DWORD PTR _Rect1$70121[ebp+8]
	add	ecx, DWORD PTR _Rect2$70122[ebp]
	sub	ecx, DWORD PTR _Rect2$70122[ebp+8]
	mov	DWORD PTR _xMax$70123[ebp], ecx

; 251  : 		yMax = (int)( Rect1.bottom + Rect2.top - Rect2.bottom );

	mov	edx, DWORD PTR _Rect1$70121[ebp+12]
	add	edx, DWORD PTR _Rect2$70122[ebp+4]
	sub	edx, DWORD PTR _Rect2$70122[ebp+12]
	mov	DWORD PTR _yMax$70124[ebp], edx

; 252  : 
; 253  : 		if(xMax < 0)

	cmp	DWORD PTR _xMax$70123[ebp], 0
	jge	SHORT $L70127

; 254  : 			xMax = 0;

	mov	DWORD PTR _xMax$70123[ebp], 0
$L70127:

; 255  : 		if(yMax < 0)

	cmp	DWORD PTR _yMax$70124[ebp], 0
	jge	SHORT $L70128

; 256  : 			yMax = 0;

	mov	DWORD PTR _yMax$70124[ebp], 0
$L70128:

; 257  : 
; 258  : //		xMax = 10;
; 259  : //		xMax = (GetSystemMetrics(SM_CYSCREEN) - Rect1.bottom + Rect1.top) >> 1 - 50;
; 260  : 
; 261  : 		SetWindowPos(hwnd, HWND_TOPMOST, 10, 10, 0, 0, SWP_NOSIZE);

	push	1
	push	0
	push	0
	push	10					; 0000000aH
	push	10					; 0000000aH
	push	-1
	mov	eax, DWORD PTR _hwnd$[ebp]
	push	eax
	call	DWORD PTR __imp__SetWindowPos@28

; 262  : 
; 263  : 		if(hwnd != NULL)

	cmp	DWORD PTR _hwnd$[ebp], 0
	je	SHORT $L70130

; 264  : 			Debug.hwndDlg = hwnd;

	mov	ecx, DWORD PTR _hwnd$[ebp]
	mov	DWORD PTR ?Debug@@3VDEBUGCLASS@@A+16, ecx

; 265  : 		else

	jmp	SHORT $L70131
$L70130:

; 266  : 			return 0;

	xor	eax, eax
	jmp	$L70119
$L70131:

; 267  : 
; 268  : 		Debug.hCView = GetDlgItem(hwnd, IDC_TREE);

	push	1002					; 000003eaH
	mov	edx, DWORD PTR _hwnd$[ebp]
	push	edx
	call	DWORD PTR __imp__GetDlgItem@8
	mov	DWORD PTR ?Debug@@3VDEBUGCLASS@@A+20, eax

; 269  : 		if(Debug.hCView == NULL)

	cmp	DWORD PTR ?Debug@@3VDEBUGCLASS@@A+20, 0
	jne	SHORT $L70132

; 270  : 			return 0;

	xor	eax, eax
	jmp	$L70119
$L70132:

; 271  : 
; 272  : 		GetWindowRect(hwnd, &Rect1);

	lea	eax, DWORD PTR _Rect1$70121[ebp]
	push	eax
	mov	ecx, DWORD PTR _hwnd$[ebp]
	push	ecx
	call	DWORD PTR __imp__GetWindowRect@8

; 273  : 		GetWindowRect(Debug.hCView, &Rect2);

	lea	edx, DWORD PTR _Rect2$70122[ebp]
	push	edx
	mov	eax, DWORD PTR ?Debug@@3VDEBUGCLASS@@A+20
	push	eax
	call	DWORD PTR __imp__GetWindowRect@8

; 274  : 		W = abs(Rect2.left - Rect1.left);

	mov	ecx, DWORD PTR _Rect2$70122[ebp]
	sub	ecx, DWORD PTR _Rect1$70121[ebp]
	push	ecx
	call	_abs
	add	esp, 4
	mov	DWORD PTR ?W@@3IA, eax			; W

; 275  : 		H = abs(Rect2.top - Rect1.top);

	mov	edx, DWORD PTR _Rect2$70122[ebp+4]
	sub	edx, DWORD PTR _Rect1$70121[ebp+4]
	push	edx
	call	_abs
	add	esp, 4
	mov	DWORD PTR ?H@@3IA, eax			; H

; 276  : 
; 277  : 		SetFocus(Val->Main->Get_MainHwnd());

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+56]
	call	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ	; MAIN::Get_MainHwnd
	push	eax
	call	DWORD PTR __imp__SetFocus@4

; 278  : 
; 279  : 		Debug.Start();

	mov	ecx, OFFSET FLAT:?Debug@@3VDEBUGCLASS@@A
	call	?Start@DEBUGCLASS@@QAEXXZ		; DEBUGCLASS::Start

; 280  : 
; 281  : 		return 1;

	mov	eax, 1
	jmp	$L70119
$L70120:

; 283  : 	else if(msg == WM_COMMAND)

	cmp	DWORD PTR _msg$[ebp], 273		; 00000111H
	jne	SHORT $L70134

; 285  : 		if((UINT)LOWORD(wParam) == IDCANCEL )

	mov	ecx, DWORD PTR _wParam$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 2
	jne	SHORT $L70137

; 287  : 			// GetPos
; 288  : 
; 289  : 			// SaveInfo
; 290  : 
; 291  : 			// Close
; 292  : 			Debug.End();

	mov	ecx, OFFSET FLAT:?Debug@@3VDEBUGCLASS@@A
	call	?End@DEBUGCLASS@@QAEXXZ			; DEBUGCLASS::End

; 293  : 			DestroyWindow(hwnd);

	mov	edx, DWORD PTR _hwnd$[ebp]
	push	edx
	call	DWORD PTR __imp__DestroyWindow@4
$L70137:

; 295  : 		return 1;

	mov	eax, 1
	jmp	$L70119
$L70134:

; 297  : 	else if(msg == WM_SIZING)

	cmp	DWORD PTR _msg$[ebp], 532		; 00000214H
	jne	SHORT $L70139

; 299  : 		unsigned int w, h;
; 300  : 		RECT Rect;
; 301  : 		//
; 302  : 		Rect = *(LPRECT)lParam;

	mov	eax, DWORD PTR _lParam$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _Rect$70142[ebp], ecx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR _Rect$70142[ebp+4], edx
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR _Rect$70142[ebp+8], ecx
	mov	edx, DWORD PTR [eax+12]
	mov	DWORD PTR _Rect$70142[ebp+12], edx

; 303  : 
; 304  : 		w = abs(Rect.right - Rect.left) - ( W << 1 );

	mov	eax, DWORD PTR _Rect$70142[ebp+8]
	sub	eax, DWORD PTR _Rect$70142[ebp]
	push	eax
	call	_abs
	add	esp, 4
	mov	ecx, DWORD PTR ?W@@3IA			; W
	shl	ecx, 1
	sub	eax, ecx
	mov	DWORD PTR _w$70140[ebp], eax

; 305  : 		h = abs(Rect.bottom - Rect.top) - H - W;

	mov	edx, DWORD PTR _Rect$70142[ebp+12]
	sub	edx, DWORD PTR _Rect$70142[ebp+4]
	push	edx
	call	_abs
	add	esp, 4
	sub	eax, DWORD PTR ?H@@3IA			; H
	sub	eax, DWORD PTR ?W@@3IA			; W
	mov	DWORD PTR _h$70141[ebp], eax

; 306  : 
; 307  : 		SetWindowPos(Debug.hCView, NULL, 0, 0, w, h, SWP_NOMOVE | SWP_SHOWWINDOW | SWP_NOZORDER );

	push	70					; 00000046H
	mov	eax, DWORD PTR _h$70141[ebp]
	push	eax
	mov	ecx, DWORD PTR _w$70140[ebp]
	push	ecx
	push	0
	push	0
	push	0
	mov	edx, DWORD PTR ?Debug@@3VDEBUGCLASS@@A+20
	push	edx
	call	DWORD PTR __imp__SetWindowPos@28

; 308  : 
; 309  : 		return 1;

	mov	eax, 1
	jmp	SHORT $L70119
$L70139:

; 311  : 
; 312  : 	return 0;

	xor	eax, eax
$L70119:

; 313  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?DebugProc@@YGHPAUHWND__@@IIJ@Z ENDP			; DebugProc
_TEXT	ENDS
;	COMDAT ?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ
_TEXT	SEGMENT
_this$ = -4
?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ PROC NEAR		; MAIN::Get_MainHwnd, COMDAT

; 95   : 		HWND Get_MainHwnd(void){ return MainHwnd; };

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+88]
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ ENDP		; MAIN::Get_MainHwnd
_TEXT	ENDS
END
