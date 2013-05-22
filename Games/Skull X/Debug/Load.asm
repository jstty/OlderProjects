	TITLE	D:\Game Programming\Moggie Software Games\old code\old Skull X\C++ Files\Load.cpp
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
;	COMDAT ??_C@_04PDLA@LOAD?$AA@
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
;	COMDAT ?LoadProc@@YGHPAUHWND__@@IIJ@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Load_ThreadProc@@YGKPAX@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?MainHwnd@@3PAUHWND__@@A			; MainHwnd
PUBLIC	?Prog@@3PAUHWND__@@A				; Prog
PUBLIC	?Load_hThread@@3PAXA				; Load_hThread
PUBLIC	?hThread@@3PAXA					; hThread
_BSS	SEGMENT
?MainHwnd@@3PAUHWND__@@A DD 01H DUP (?)			; MainHwnd
?Prog@@3PAUHWND__@@A DD 01H DUP (?)			; Prog
?Load_hThread@@3PAXA DD 01H DUP (?)			; Load_hThread
?hThread@@3PAXA DD 01H DUP (?)				; hThread
_BSS	ENDS
PUBLIC	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ		; MAIN::Get_MainHwnd
PUBLIC	?sLoop@VALUES@@QAE_NAAPAXPAD@Z			; VALUES::sLoop
PUBLIC	?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z	; VALUES::cLoop
PUBLIC	?Load_ThreadProc@@YGKPAX@Z			; Load_ThreadProc
PUBLIC	?LoadProc@@YGHPAUHWND__@@IIJ@Z			; LoadProc
PUBLIC	??_C@_04PDLA@LOAD?$AA@				; `string'
EXTRN	__imp__DestroyWindow@4:NEAR
EXTRN	__imp__SetWindowPos@28:NEAR
EXTRN	__imp__GetDlgItem@8:NEAR
EXTRN	?Val@@3PAVVALUES@@A:DWORD			; Val
EXTRN	__imp__GetClientRect@8:NEAR
EXTRN	__imp__GetWindowRect@8:NEAR
;	COMDAT ??_C@_04PDLA@LOAD?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\load.cpp
CONST	SEGMENT
??_C@_04PDLA@LOAD?$AA@ DB 'LOAD', 00H			; `string'
CONST	ENDS
;	COMDAT ?LoadProc@@YGHPAUHWND__@@IIJ@Z
_TEXT	SEGMENT
_hwnd$ = 8
_msg$ = 12
_wParam$ = 16
_Rect1$69019 = -16
_Rect2$69020 = -32
_xMax$69021 = -36
_yMax$69022 = -40
?LoadProc@@YGHPAUHWND__@@IIJ@Z PROC NEAR		; LoadProc, COMDAT

; 28   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 104				; 00000068H
	push	ebx
	push	esi
	push	edi

; 29   : 	if(msg == WM_INITDIALOG)

	cmp	DWORD PTR _msg$[ebp], 272		; 00000110H
	jne	$L69018

; 31   : 		RECT Rect1, Rect2;
; 32   : 		int xMax, yMax;
; 33   : 
; 34   : 		GetWindowRect(hwnd, &Rect1);

	lea	eax, DWORD PTR _Rect1$69019[ebp]
	push	eax
	mov	ecx, DWORD PTR _hwnd$[ebp]
	push	ecx
	call	DWORD PTR __imp__GetWindowRect@8

; 35   : 		GetClientRect(Val->Main->Get_MainHwnd(), &Rect2);

	lea	edx, DWORD PTR _Rect2$69020[ebp]
	push	edx
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+56]
	call	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ	; MAIN::Get_MainHwnd
	push	eax
	call	DWORD PTR __imp__GetClientRect@8

; 36   : 		xMax = ( ( Rect2.right + Rect2.left - Rect1.right + Rect1.left ) >> 1) ;

	mov	ecx, DWORD PTR _Rect2$69020[ebp+8]
	add	ecx, DWORD PTR _Rect2$69020[ebp]
	sub	ecx, DWORD PTR _Rect1$69019[ebp+8]
	add	ecx, DWORD PTR _Rect1$69019[ebp]
	sar	ecx, 1
	mov	DWORD PTR _xMax$69021[ebp], ecx

; 37   : 		//
; 38   : 		yMax = ( ( Rect2.bottom + Rect2.top - Rect1.bottom + Rect1.top ) >> 1);

	mov	edx, DWORD PTR _Rect2$69020[ebp+12]
	add	edx, DWORD PTR _Rect2$69020[ebp+4]
	sub	edx, DWORD PTR _Rect1$69019[ebp+12]
	add	edx, DWORD PTR _Rect1$69019[ebp+4]
	sar	edx, 1
	mov	DWORD PTR _yMax$69022[ebp], edx

; 39   : 
; 40   : 		if(xMax < 0)

	cmp	DWORD PTR _xMax$69021[ebp], 0
	jge	SHORT $L69023

; 41   : 			xMax = 0;

	mov	DWORD PTR _xMax$69021[ebp], 0
$L69023:

; 42   : 		if(yMax < 0)

	cmp	DWORD PTR _yMax$69022[ebp], 0
	jge	SHORT $L69024

; 43   : 			yMax = 0;

	mov	DWORD PTR _yMax$69022[ebp], 0
$L69024:

; 44   : 
; 45   : 		SetWindowPos(hwnd, HWND_TOPMOST, xMax, yMax, 0, 0, SWP_NOSIZE);

	push	1
	push	0
	push	0
	mov	eax, DWORD PTR _yMax$69022[ebp]
	push	eax
	mov	ecx, DWORD PTR _xMax$69021[ebp]
	push	ecx
	push	-1
	mov	edx, DWORD PTR _hwnd$[ebp]
	push	edx
	call	DWORD PTR __imp__SetWindowPos@28

; 46   : 
; 47   : 		Prog = GetDlgItem(hwnd, IDC_PROG);

	push	1008					; 000003f0H
	mov	eax, DWORD PTR _hwnd$[ebp]
	push	eax
	call	DWORD PTR __imp__GetDlgItem@8
	mov	DWORD PTR ?Prog@@3PAUHWND__@@A, eax	; Prog

; 48   : 		MainHwnd = hwnd;

	mov	ecx, DWORD PTR _hwnd$[ebp]
	mov	DWORD PTR ?MainHwnd@@3PAUHWND__@@A, ecx	; MainHwnd

; 49   : 
; 50   : 		if( Val->cLoop(Load_hThread, Load_ThreadProc, "LOAD", THREAD_PRIORITY_NORMAL) )

	push	0
	push	0
	push	OFFSET FLAT:??_C@_04PDLA@LOAD?$AA@	; `string'
	push	OFFSET FLAT:?Load_ThreadProc@@YGKPAX@Z	; Load_ThreadProc
	push	OFFSET FLAT:?Load_hThread@@3PAXA	; Load_hThread
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	call	?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z ; VALUES::cLoop
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L69026

; 51   : 				return 1;

	mov	eax, 1
	jmp	SHORT $L69017
$L69026:

; 52   : 
; 53   : 		if( Val->sLoop(Load_hThread, "LOAD") )

	push	OFFSET FLAT:??_C@_04PDLA@LOAD?$AA@	; `string'
	push	OFFSET FLAT:?Load_hThread@@3PAXA	; Load_hThread
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	call	?sLoop@VALUES@@QAE_NAAPAXPAD@Z		; VALUES::sLoop
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L69028

; 54   : 				return 1;

	mov	eax, 1
	jmp	SHORT $L69017
$L69028:

; 55   : 
; 56   : 		return 1;

	mov	eax, 1
	jmp	SHORT $L69017
$L69018:

; 58   : 	else if((msg == WM_COMMAND) || (msg == WM_DESTROY))

	cmp	DWORD PTR _msg$[ebp], 273		; 00000111H
	je	SHORT $L69031
	cmp	DWORD PTR _msg$[ebp], 2
	jne	SHORT $L69030
$L69031:

; 60   : 		if((UINT)LOWORD(wParam) == IDCANCEL )

	mov	edx, DWORD PTR _wParam$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 2
	jne	SHORT $L69034

; 61   : 			DestroyWindow(hwnd);

	mov	eax, DWORD PTR _hwnd$[ebp]
	push	eax
	call	DWORD PTR __imp__DestroyWindow@4
$L69034:

; 62   : 
; 63   : 		return 1;

	mov	eax, 1
	jmp	SHORT $L69017
$L69030:

; 65   : 
; 66   : 	return 0;

	xor	eax, eax
$L69017:

; 67   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?LoadProc@@YGHPAUHWND__@@IIJ@Z ENDP			; LoadProc
_TEXT	ENDS
EXTRN	?Load@MAIN@@QAEXXZ:NEAR				; MAIN::Load
EXTRN	__imp__PostMessageA@16:NEAR
EXTRN	__imp__GetCurrentThread@0:NEAR
EXTRN	?Load@SOUND@@QAE_NXZ:NEAR			; SOUND::Load
EXTRN	?Load@ACTION@@QAE_NXZ:NEAR			; ACTION::Load
EXTRN	__imp__WaitForSingleObject@8:NEAR
EXTRN	?Load@DISPLAY@@QAE_NXZ:NEAR			; DISPLAY::Load
EXTRN	?FreeLayers@DISPLAY@@QAEXXZ:NEAR		; DISPLAY::FreeLayers
EXTRN	__imp__SendMessageA@16:NEAR
;	COMDAT ?Load_ThreadProc@@YGKPAX@Z
_TEXT	SEGMENT
?Load_ThreadProc@@YGKPAX@Z PROC NEAR			; Load_ThreadProc, COMDAT

; 72   : {	

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi

; 73   : 	hThread = GetCurrentThread();

	call	DWORD PTR __imp__GetCurrentThread@0
	mov	DWORD PTR ?hThread@@3PAXA, eax		; hThread

; 76   : 		SendMessage(Prog, PBM_SETRANGE, 0, MAKELPARAM(0, 500)); 

	push	32768000				; 01f40000H
	push	0
	push	1025					; 00000401H
	mov	eax, DWORD PTR ?Prog@@3PAUHWND__@@A	; Prog
	push	eax
	call	DWORD PTR __imp__SendMessageA@16

; 77   : 		SendMessage(Prog, PBM_SETSTEP, (WPARAM) 100, 0); 

	push	0
	push	100					; 00000064H
	push	1028					; 00000404H
	mov	ecx, DWORD PTR ?Prog@@3PAUHWND__@@A	; Prog
	push	ecx
	call	DWORD PTR __imp__SendMessageA@16

; 78   : 
; 79   : 		Val->Display->FreeLayers();

	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+64]
	call	?FreeLayers@DISPLAY@@QAEXXZ		; DISPLAY::FreeLayers

; 80   : 		SendMessage(Prog, PBM_STEPIT, 0, 0);

	push	0
	push	0
	push	1029					; 00000405H
	mov	eax, DWORD PTR ?Prog@@3PAUHWND__@@A	; Prog
	push	eax
	call	DWORD PTR __imp__SendMessageA@16

; 81   : 
; 82   : 		Val->Display->Load();

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [ecx+64]
	call	?Load@DISPLAY@@QAE_NXZ			; DISPLAY::Load

; 83   : 		SendMessage(Prog, PBM_STEPIT, 0, 0);

	push	0
	push	0
	push	1029					; 00000405H
	mov	edx, DWORD PTR ?Prog@@3PAUHWND__@@A	; Prog
	push	edx
	call	DWORD PTR __imp__SendMessageA@16

; 84   : 
; 85   : 		Val->Action->Load();

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+68]
	call	?Load@ACTION@@QAE_NXZ			; ACTION::Load

; 86   : 		SendMessage(Prog, PBM_STEPIT, 0, 0);

	push	0
	push	0
	push	1029					; 00000405H
	mov	ecx, DWORD PTR ?Prog@@3PAUHWND__@@A	; Prog
	push	ecx
	call	DWORD PTR __imp__SendMessageA@16

; 87   : 
; 88   : 		Val->Sound->Load();

	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+72]
	call	?Load@SOUND@@QAE_NXZ			; SOUND::Load

; 89   : 		SendMessage(Prog, PBM_STEPIT, 0, 0);

	push	0
	push	0
	push	1029					; 00000405H
	mov	eax, DWORD PTR ?Prog@@3PAUHWND__@@A	; Prog
	push	eax
	call	DWORD PTR __imp__SendMessageA@16

; 90   : 
; 91   : 		Val->Main->Load();

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [ecx+56]
	call	?Load@MAIN@@QAEXXZ			; MAIN::Load

; 92   : 		SendMessage(Prog, PBM_STEPIT, 0, 0);

	push	0
	push	0
	push	1029					; 00000405H
	mov	edx, DWORD PTR ?Prog@@3PAUHWND__@@A	; Prog
	push	edx
	call	DWORD PTR __imp__SendMessageA@16

; 94   : 
; 95   : 	WaitForSingleObject(hThread, 500);

	push	500					; 000001f4H
	mov	eax, DWORD PTR ?hThread@@3PAXA		; hThread
	push	eax
	call	DWORD PTR __imp__WaitForSingleObject@8

; 96   : 
; 97   : 	PostMessage(MainHwnd, WM_COMMAND, IDCANCEL, 0);

	push	0
	push	2
	push	273					; 00000111H
	mov	ecx, DWORD PTR ?MainHwnd@@3PAUHWND__@@A	; MainHwnd
	push	ecx
	call	DWORD PTR __imp__PostMessageA@16

; 98   : 	return 0;

	xor	eax, eax

; 99   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?Load_ThreadProc@@YGKPAX@Z ENDP				; Load_ThreadProc
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
PUBLIC	??_C@_0BI@PFPA@StartLoops?3ResumeThread?$AA@	; `string'
PUBLIC	?Error@ERRORCLASS@@QAA_NPADZZ			; ERRORCLASS::Error
EXTRN	__imp__GetLastError@0:NEAR
EXTRN	__imp__ResumeThread@4:NEAR
;	COMDAT ??_C@_0BI@PFPA@StartLoops?3ResumeThread?$AA@
; File d:\game programming\moggie software games\old code\old skull x\header files\valuesclass.h
CONST	SEGMENT
??_C@_0BI@PFPA@StartLoops?3ResumeThread?$AA@ DB 'StartLoops:ResumeThread', 00H ; `string'
CONST	ENDS
;	COMDAT ?sLoop@VALUES@@QAE_NAAPAXPAD@Z
_TEXT	SEGMENT
_h$ = 8
_c$ = 12
_this$ = -4
?sLoop@VALUES@@QAE_NAAPAXPAD@Z PROC NEAR		; VALUES::sLoop, COMDAT

; 242  : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 243  : 			ResumeThread(h);

	mov	eax, DWORD PTR _h$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR __imp__ResumeThread@4

; 244  : 			if(GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L68991

; 245  : 				return Error(NULL, c, "StartLoops:ResumeThread", GetLastError() );

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BI@PFPA@StartLoops?3ResumeThread?$AA@ ; `string'
	mov	edx, DWORD PTR _c$[ebp]
	push	edx
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	push	eax
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L68990
$L68991:

; 246  : 
; 247  : 			return 0;

	xor	al, al
$L68990:

; 248  : 		}

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?sLoop@VALUES@@QAE_NAAPAXPAD@Z ENDP			; VALUES::sLoop
_TEXT	ENDS
PUBLIC	?GetType@ERRORCLASS@@AAEHH@Z			; ERRORCLASS::GetType
PUBLIC	??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ ; `string'
PUBLIC	??_C@_05CKBG@Error?$AA@				; `string'
EXTRN	??2@YAPAXI@Z:NEAR				; operator new
EXTRN	_vsprintf:NEAR
EXTRN	__imp__MessageBoxA@16:NEAR
EXTRN	_strcpy:NEAR
EXTRN	_strlen:NEAR
EXTRN	__imp__GetDesktopWindow@0:NEAR
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
$T69127 = -268
$T69128 = -272
_m$ = 12
_this$ = 8
_mTemp$ = -256
_vl$ = -260
_Ok$ = -264
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
	je	SHORT $L58198

; 114  : 				if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L58199

; 116  : 					PrevMsgFormat = new char[strlen(MsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T69127[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T69127[ebp]
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
$L58199:

; 119  : 
; 120  : 				MsgFormat = new char[strlen(m)];

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T69128[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T69128[ebp]
	mov	DWORD PTR [ecx], edx

; 121  : 				strcpy(MsgFormat, m);

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8
$L58198:

; 123  : 
; 124  : 			if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L58204

; 126  : 				if(strlen(MsgFormat) > 0)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	test	eax, eax
	jbe	SHORT $L58205

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

	jmp	SHORT $L58210
$L58205:

; 133  : 					strcpy(mTemp, "Problem with error message.");

	push	OFFSET FLAT:??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ ; `string'
	lea	edx, DWORD PTR _mTemp$[ebp]
	push	edx
	call	_strcpy
	add	esp, 8
$L58210:

; 135  : 			else

	jmp	SHORT $L58212
$L58204:

; 136  : 				return 1;

	mov	al, 1
	jmp	$L58219
$L58212:

; 137  : 
; 138  : 			if(Type < 0)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	and	ecx, 3
	test	ecx, ecx
	jae	SHORT $L58213

; 139  : 				Type = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	al, -4					; fffffffcH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+8], eax
$L58213:

; 140  : 			
; 141  : 			if(hWnd == NULL)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+12], 0
	jne	SHORT $L58214

; 142  : 				hWnd = GetDesktopWindow();

	call	DWORD PTR __imp__GetDesktopWindow@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L58214:

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
	je	SHORT $L58218
	cmp	DWORD PTR _Ok$[ebp], 7
	je	SHORT $L58218
	cmp	DWORD PTR _Ok$[ebp], 2
	jne	SHORT $L58217
$L58218:

; 147  : 				return 1;

	mov	al, 1
	jmp	SHORT $L58219
$L58217:

; 149  : 				return 0;

	xor	al, al
$L58219:

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
	jne	SHORT $L58138

; 32   : 				return MB_OK;

	xor	eax, eax
	jmp	SHORT $L58143
$L58138:

; 33   : 			else if(Type == ETYPE_YESNO)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	eax, 3
	cmp	eax, 1
	jne	SHORT $L58140

; 34   : 				return MB_YESNO;

	mov	eax, 4
	jmp	SHORT $L58143
$L58140:

; 35   : 			else if(Type == ETYPE_RETRY)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	and	edx, 3
	cmp	edx, 2
	jne	SHORT $L58142

; 36   : 				return MB_RETRYCANCEL;

	mov	eax, 5
	jmp	SHORT $L58143
$L58142:

; 38   : 				return MB_OK;

	xor	eax, eax
$L58143:

; 39   : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?GetType@ERRORCLASS@@AAEHH@Z ENDP			; ERRORCLASS::GetType
_TEXT	ENDS
PUBLIC	??_C@_0BJ@HCNJ@CreateLoops?3CreateThread?$AA@	; `string'
PUBLIC	??_C@_0BN@DFAJ@CreateLoop?3SetThreadPriority?$AA@ ; `string'
PUBLIC	??_C@_0BL@HMPM@CreateLoop?3InvalidPriority?$AA@	; `string'
EXTRN	__imp__CreateThread@24:NEAR
EXTRN	__imp__SetThreadPriority@8:NEAR
EXTRN	__imp__SetLastError@4:NEAR
;	COMDAT ??_C@_0BJ@HCNJ@CreateLoops?3CreateThread?$AA@
; File d:\game programming\moggie software games\old code\old skull x\header files\valuesclass.h
CONST	SEGMENT
??_C@_0BJ@HCNJ@CreateLoops?3CreateThread?$AA@ DB 'CreateLoops:CreateThrea'
	DB	'd', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BN@DFAJ@CreateLoop?3SetThreadPriority?$AA@
CONST	SEGMENT
??_C@_0BN@DFAJ@CreateLoop?3SetThreadPriority?$AA@ DB 'CreateLoop:SetThrea'
	DB	'dPriority', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_0BL@HMPM@CreateLoop?3InvalidPriority?$AA@
CONST	SEGMENT
??_C@_0BL@HMPM@CreateLoop?3InvalidPriority?$AA@ DB 'CreateLoop:InvalidPri'
	DB	'ority', 00H					; `string'
CONST	ENDS
;	COMDAT ?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z
_TEXT	SEGMENT
_h$ = 8
_Proc$ = 12
_c$ = 16
_p$ = 20
_Var$ = 24
_this$ = -4
_ID$ = -8
?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z PROC NEAR	; VALUES::cLoop, COMDAT

; 251  : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 252  : 			DWORD ID;
; 253  : 			SetLastError(0);

	push	0
	call	DWORD PTR __imp__SetLastError@4

; 254  : 
; 255  : 			h = CreateThread(NULL, 0,  Proc, Var, CREATE_SUSPENDED, &ID);

	lea	eax, DWORD PTR _ID$[ebp]
	push	eax
	push	4
	mov	ecx, DWORD PTR _Var$[ebp]
	push	ecx
	mov	edx, DWORD PTR _Proc$[ebp]
	push	edx
	push	0
	push	0
	call	DWORD PTR __imp__CreateThread@24
	mov	ecx, DWORD PTR _h$[ebp]
	mov	DWORD PTR [ecx], eax

; 256  : 			if(GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L68996

; 257  : 				return Error(NULL, c, "CreateLoops:CreateThread", GetLastError() );

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BJ@HCNJ@CreateLoops?3CreateThread?$AA@ ; `string'
	mov	edx, DWORD PTR _c$[ebp]
	push	edx
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	push	eax
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	$L68994
$L68996:

; 260  : 					(p == THREAD_PRIORITY_LOWEST) ||
; 261  : 					(p == THREAD_PRIORITY_BELOW_NORMAL) ||
; 262  : 					(p == THREAD_PRIORITY_NORMAL) ||
; 263  : 					(p == THREAD_PRIORITY_ABOVE_NORMAL) ||
; 264  : 					(p == THREAD_PRIORITY_HIGHEST) ||
; 265  : 					(p == THREAD_PRIORITY_TIME_CRITICAL) )

	cmp	DWORD PTR _p$[ebp], -15			; fffffff1H
	je	SHORT $L68999
	cmp	DWORD PTR _p$[ebp], -2			; fffffffeH
	je	SHORT $L68999
	cmp	DWORD PTR _p$[ebp], -1
	je	SHORT $L68999
	cmp	DWORD PTR _p$[ebp], 0
	je	SHORT $L68999
	cmp	DWORD PTR _p$[ebp], 1
	je	SHORT $L68999
	cmp	DWORD PTR _p$[ebp], 2
	je	SHORT $L68999
	cmp	DWORD PTR _p$[ebp], 15			; 0000000fH
	jne	SHORT $L68998
$L68999:

; 267  : 				SetThreadPriority(h, p);

	mov	ecx, DWORD PTR _p$[ebp]
	push	ecx
	mov	edx, DWORD PTR _h$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	DWORD PTR __imp__SetThreadPriority@8

; 268  : 				if(GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L69000

; 269  : 					return Error(NULL, c, "CreateLoop:SetThreadPriority", GetLastError() );

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BN@DFAJ@CreateLoop?3SetThreadPriority?$AA@ ; `string'
	mov	ecx, DWORD PTR _c$[ebp]
	push	ecx
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L68994
$L69000:

; 271  : 			else

	jmp	SHORT $L69002
$L68998:

; 272  : 				return Error(NULL, c, "CreateLoop:InvalidPriority", p );

	mov	eax, DWORD PTR _p$[ebp]
	push	eax
	push	OFFSET FLAT:??_C@_0BL@HMPM@CreateLoop?3InvalidPriority?$AA@ ; `string'
	mov	ecx, DWORD PTR _c$[ebp]
	push	ecx
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L68994
$L69002:

; 273  : 
; 274  : 			return 0;

	xor	al, al
$L68994:

; 275  : 		}

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	20					; 00000014H
?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z ENDP		; VALUES::cLoop
_TEXT	ENDS
END
