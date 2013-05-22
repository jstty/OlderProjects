	TITLE	D:\Game Programming\Moggie Software Games\old code\old Skull X\C++ Files\Controls.cpp
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
;	COMDAT ?Loop@TestSpeed@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Controls_Loop@CONTROLS@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Joy_Loop@CONTROLS@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Key_Loop@CONTROLS@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Sys_Loop@CONTROLS@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?TestKey@CONTROLS@@QAE_NUKey@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?OnMouse@CONTROLS@@QAEXPAUHWND__@@HHI@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?OnMouseLDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?OnMouseRDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?OnMouseMDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?OnMouseLUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?OnMouseRUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?OnMouseMUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?OnKey@CONTROLS@@QAEXPAUHWND__@@IHHI@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Controls_ThreadProc@@YGKPAX@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Set_data@CONTROLS@@QAEXUControlVar@@_N@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	__real@4@4008fa00000000000000
PUBLIC	?Loop@TestSpeed@@QAEXXZ				; TestSpeed::Loop
PUBLIC	?Controls_Loop@CONTROLS@@QAE_NXZ		; CONTROLS::Controls_Loop
PUBLIC	?Joy_Loop@CONTROLS@@QAEXXZ			; CONTROLS::Joy_Loop
PUBLIC	?Key_Loop@CONTROLS@@QAEXXZ			; CONTROLS::Key_Loop
PUBLIC	?Sys_Loop@CONTROLS@@QAEXXZ			; CONTROLS::Sys_Loop
EXTRN	__fltused:NEAR
EXTRN	__imp__GetCurrentThread@0:NEAR
EXTRN	__imp__WaitForSingleObject@8:NEAR
EXTRN	?tsControls@@3VTestSpeed@@A:BYTE		; tsControls
;	COMDAT __real@4@4008fa00000000000000
; File d:\game programming\moggie software games\old code\old skull x\c++ files\controls.cpp
CONST	SEGMENT
__real@4@4008fa00000000000000 DD 0447a0000r	; 1000
CONST	ENDS
;	COMDAT ?Controls_Loop@CONTROLS@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
_hThread$ = -8
?Controls_Loop@CONTROLS@@QAE_NXZ PROC NEAR		; CONTROLS::Controls_Loop, COMDAT

; 33   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 34   : 	HANDLE hThread = GetCurrentThread();

	call	DWORD PTR __imp__GetCurrentThread@0
	mov	DWORD PTR _hThread$[ebp], eax
$L73425:

; 35   : //	CRITICAL_SECTION cs;
; 36   : //	InitializeCriticalSection(&cs);
; 37   : 
; 38   : 	//SetFocus(Val->Main->Get_ChildHwnd());
; 39   : 
; 40   : 	while(ThreadLoop == 0)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	and	ecx, 3
	test	ecx, ecx
	jne	SHORT $L73426

; 42   : //		EnterCriticalSection(&cs);
; 43   : 
; 44   : 		// Test Speed
; 45   : 		#ifdef _DEBUG
; 46   : 			if(tsControls.Rate > 1000)

	fld	DWORD PTR ?tsControls@@3VTestSpeed@@A+40
	fcomp	DWORD PTR __real@4@4008fa00000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	jne	SHORT $L73427

; 47   : 				return 0;

	xor	al, al
	jmp	SHORT $L73422
$L73427:

; 48   : 
; 49   : 			tsControls.Loop();

	mov	ecx, OFFSET FLAT:?tsControls@@3VTestSpeed@@A
	call	?Loop@TestSpeed@@QAEXXZ			; TestSpeed::Loop

; 50   : 		#endif
; 51   : 
; 52   : // Code
; 53   : 
; 54   : 		Sys_Loop();

	mov	ecx, DWORD PTR _this$[ebp]
	call	?Sys_Loop@CONTROLS@@QAEXXZ		; CONTROLS::Sys_Loop

; 55   : 		Key_Loop();

	mov	ecx, DWORD PTR _this$[ebp]
	call	?Key_Loop@CONTROLS@@QAEXXZ		; CONTROLS::Key_Loop

; 56   : 		Joy_Loop();

	mov	ecx, DWORD PTR _this$[ebp]
	call	?Joy_Loop@CONTROLS@@QAEXXZ		; CONTROLS::Joy_Loop

; 57   : 
; 58   : // End Code
; 59   : 
; 60   : //		LeaveCriticalSection(&cs);
; 61   : 		WaitForSingleObject(hThread, Delay);

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+20]
	push	eax
	mov	ecx, DWORD PTR _hThread$[ebp]
	push	ecx
	call	DWORD PTR __imp__WaitForSingleObject@8

; 62   : 	}

	jmp	SHORT $L73425
$L73426:

; 63   : 
; 64   : 	ThreadLoop = 2;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	and	al, -4					; fffffffcH
	or	al, 2
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax

; 65   : 	return 0;

	xor	al, al
$L73422:

; 66   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Controls_Loop@CONTROLS@@QAE_NXZ ENDP			; CONTROLS::Controls_Loop
_TEXT	ENDS
EXTRN	__imp__GetTickCount@0:NEAR
;	COMDAT ?Loop@TestSpeed@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
?Loop@TestSpeed@@QAEXXZ PROC NEAR			; TestSpeed::Loop, COMDAT

; 55   : 			{

	push	ebp
	mov	ebp, esp
	sub	esp, 84					; 00000054H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 56   : 				Tick1 = GetTickCount();

	call	DWORD PTR __imp__GetTickCount@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax

; 57   : 				
; 58   : 				if(Start == 1)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+28], 1
	jne	SHORT $L73415

; 60   : 					Start = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+28], 0

; 61   : 					TickCount = Tick1;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR [ecx+32], eax
$L73415:

; 63   : 
; 64   : 				if( (Tick1 - TickCount) > 100)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+16]
	sub	eax, DWORD PTR [edx+32]
	cmp	eax, 100				; 00000064H
	jbe	SHORT $L73416

; 66   : 					Tick2 = Tick1 - TickCount;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+16]
	sub	eax, DWORD PTR [edx+32]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+20], eax

; 67   : 					Rate = (float)( LoopCount*1000)/( Tick2 );

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+24]
	imul	eax, 1000				; 000003e8H
	mov	DWORD PTR -12+[ebp], eax
	mov	DWORD PTR -12+[ebp+4], 0
	fild	QWORD PTR -12+[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	DWORD PTR -20+[ebp], edx
	mov	DWORD PTR -20+[ebp+4], 0
	fidiv	DWORD PTR -20+[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	fstp	DWORD PTR [eax+40]

; 68   : 
; 69   : 					LoopCount = 0;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+24], 0

; 70   : 					TickCount = Tick1;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	mov	DWORD PTR [edx+32], ecx
$L73416:

; 72   : 
; 73   : 
; 74   : /*
; 75   : 				Tick1 = GetTickCount();
; 76   : 				for(i = 0; i < 32; i++)
; 77   : 				{
; 78   : 					temp = 10;
; 79   : 					temp = (int)( (temp*37 + temp*23)*(0.3) );
; 80   : 					temp = (int)( (temp/3) + (temp/4) + (temp/5) );
; 81   : 					temp = (int)sin( (temp*37 + temp*23)*(0.3) );
; 82   : 					temp = (int)cos( (temp*37 + temp*23)*(0.3) );
; 83   : 					temp = (int)tan( (temp*37 + temp*23)*(0.3) );
; 84   : 				}
; 85   : 				Tick2 = GetTickCount();
; 86   : 				float TempRate = (float(Tick2 - Tick1))/1000;
; 87   : 				ForLoop = (float(ForLoop + TempRate) )/2;
; 88   : */
; 89   : 
; 90   : /*
; 91   : 				div_t result;
; 92   : 				result = div(LoopCount, 10);
; 93   : 				switch(result.rem)
; 94   : 				{
; 95   : 					case 0: LoopTest++;	break;
; 96   : 					case 1: LoopTest++;	break;
; 97   : 					case 2: LoopTest++;	break;
; 98   : 					case 3: LoopTest++;	break;
; 99   : 					case 4: LoopTest++;	break;
; 100  : 					case 5: LoopTest++;	break;
; 101  : 					case 6: LoopTest++;	break;
; 102  : 					case 7: LoopTest++;	break;
; 103  : 					case 8: LoopTest++;	break;
; 104  : 					case 9: LoopTest++;	break;
; 105  : 					default: LoopTest++;
; 106  : 				}
; 107  : 							if(result.rem == 0)	LoopCount++;
; 108  : 				else	if(result.rem == 1) LoopCount++;
; 109  : 				else	if(result.rem == 2) LoopCount++;
; 110  : 				else	if(result.rem == 3) LoopCount++;
; 111  : 				else	if(result.rem == 4) LoopCount++;
; 112  : 				else	if(result.rem == 5) LoopCount++;
; 113  : 				else	if(result.rem == 6) LoopCount++;
; 114  : 				else	if(result.rem == 7) LoopCount++;
; 115  : 				else	if(result.rem == 8) LoopCount++;
; 116  : 				else	if(result.rem == 9) LoopCount++;
; 117  : 				else	LoopCount++;
; 118  : */
; 119  : 				LoopCount++;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+24]
	add	eax, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+24], eax

; 120  : 			};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Loop@TestSpeed@@QAEXXZ ENDP				; TestSpeed::Loop
_TEXT	ENDS
EXTRN	__imp__joyGetPosEx@8:NEAR
;	COMDAT ?Joy_Loop@CONTROLS@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
?Joy_Loop@CONTROLS@@QAEXXZ PROC NEAR			; CONTROLS::Joy_Loop, COMDAT

; 72   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 73   : 	for(j = 0; j < NumJoy; j++)

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+52], 0
	jmp	SHORT $L73432
$L73433:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+52]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+52], dl
$L73432:
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+52]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+41]
	cmp	edx, ecx
	jge	$L73434

; 75   : 		TempJoy = &Joy[j];

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+52]
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	add	edx, eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+60], edx

; 76   : 
; 77   : 		if( TempJoy->Enabled )

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	test	eax, eax
	je	$L73469

; 79   : 			if( !joyGetPosEx(j, &JoyInfo ) )

	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 112				; 00000070H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+52]
	push	eax
	call	DWORD PTR __imp__joyGetPosEx@8
	test	eax, eax
	jne	$L73436

; 81   : 				TempPlayer = Player[ TempJoy->PlayerNum ];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+eax*4]
	mov	DWORD PTR [ecx+56], edx

; 82   : //
; 83   : 				// Vertical
; 84   : 					if(JoyInfo.dwYpos < TempJoy->Vert[0])

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+6]
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+124], edx
	jae	SHORT $L73437

; 86   : 						if( ( !TempPlayer[TempJoy->Button[DOWN]].v ) && ( TempPlayer[TempJoy->Button[UP]].c != C_KEY) )

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx+11]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax*8]
	test	ecx, ecx
	jne	SHORT $L73438
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+10]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR [eax+ecx*8+4]
	and	ecx, 3
	cmp	ecx, 2
	je	SHORT $L73438

; 88   : 							TempPlayer[TempJoy->Button[UP]].v = true;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+10]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	BYTE PTR [eax+ecx*8], 1

; 89   : 							TempPlayer[TempJoy->Button[UP]].c = C_JOY;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx+10]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	al, -4					; fffffffcH
	or	al, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+10]
	mov	edx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+56]
	mov	DWORD PTR [edx+ecx*8+4], eax
$L73438:

; 92   : 					else	if(JoyInfo.dwYpos > TempJoy->Vert[1])

	jmp	$L73444
$L73437:
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+8]
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+124], edx
	jbe	SHORT $L73440

; 94   : 						if( ( !TempPlayer[TempJoy->Button[UP]].v ) && ( TempPlayer[TempJoy->Button[DOWN]].c != C_KEY )  )

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx+10]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax*8]
	test	ecx, ecx
	jne	SHORT $L73441
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+11]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR [eax+ecx*8+4]
	and	ecx, 3
	cmp	ecx, 2
	je	SHORT $L73441

; 96   : 							TempPlayer[TempJoy->Button[DOWN]].v = true;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+11]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	BYTE PTR [eax+ecx*8], 1

; 97   : 							TempPlayer[TempJoy->Button[DOWN]].c = C_JOY;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx+11]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	al, -4					; fffffffcH
	or	al, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+11]
	mov	edx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+56]
	mov	DWORD PTR [edx+ecx*8+4], eax
$L73441:

; 100  : 					else

	jmp	$L73444
$L73440:

; 102  : 						if(TempPlayer[TempJoy->Button[UP]].c != C_KEY)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+10]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	edx, DWORD PTR [ecx+edx*8+4]
	and	edx, 3
	cmp	edx, 2
	je	SHORT $L73443

; 104  : 							TempPlayer[TempJoy->Button[UP]].v = false;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+10]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	BYTE PTR [ecx+edx*8], 0

; 105  : 							TempPlayer[TempJoy->Button[UP]].c = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+10]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR [eax+ecx*8+4]
	and	ecx, -4					; fffffffcH
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+10]
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+56]
	mov	DWORD PTR [eax+edx*8+4], ecx
$L73443:

; 107  : 
; 108  : 						if(TempPlayer[TempJoy->Button[DOWN]].c != C_KEY)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx+11]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	eax, 3
	cmp	eax, 2
	je	SHORT $L73444

; 110  : 							TempPlayer[TempJoy->Button[DOWN]].v = false;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx+11]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	BYTE PTR [edx+eax*8], 0

; 111  : 							TempPlayer[TempJoy->Button[DOWN]].c = false;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+11]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	edx, DWORD PTR [ecx+edx*8+4]
	and	edx, -4					; fffffffcH
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+11]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+56]
	mov	DWORD PTR [ecx+eax*8+4], edx
$L73444:

; 114  : 				// Horizontal
; 115  : 					if(JoyInfo.dwXpos < TempJoy->Horz[0])

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+120], ecx
	jae	$L73445

; 117  : 						if(	(!TempPlayer[ TempJoy->Button[RIGHT]].v) && ( TempPlayer[TempJoy->Button[LEFT]].c != C_KEY ) )

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+13]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx*8]
	test	eax, eax
	jne	SHORT $L73446
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx+12]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	eax, 3
	cmp	eax, 2
	je	SHORT $L73446

; 119  : 							TempPlayer[TempJoy->Button[LEFT]].v = true;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx+12]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	BYTE PTR [edx+eax*8], 1

; 120  : 							TempPlayer[TempJoy->Button[LEFT]].c = C_JOY;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+12]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	edx, DWORD PTR [ecx+edx*8+4]
	and	edx, -4					; fffffffcH
	or	edx, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+12]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+56]
	mov	DWORD PTR [ecx+eax*8+4], edx
$L73446:

; 123  : 					else	if(JoyInfo.dwXpos > TempJoy->Horz[1])

	jmp	$L73452
$L73445:
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+4]
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+120], ecx
	jbe	$L73448

; 125  : 						if(	(!TempPlayer[TempJoy->Button[LEFT]].v) && ( TempPlayer[TempJoy->Button[RIGHT]].c != C_KEY ) )

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+12]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx*8]
	test	eax, eax
	jne	SHORT $L73449
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx+13]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	eax, 3
	cmp	eax, 2
	je	SHORT $L73449

; 127  : 							TempPlayer[TempJoy->Button[RIGHT]].v = true;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx+13]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	BYTE PTR [edx+eax*8], 1

; 128  : 							TempPlayer[TempJoy->Button[RIGHT]].c = C_JOY;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+13]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	edx, DWORD PTR [ecx+edx*8+4]
	and	edx, -4					; fffffffcH
	or	edx, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+13]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+56]
	mov	DWORD PTR [ecx+eax*8+4], edx
$L73449:

; 131  : 					else

	jmp	$L73452
$L73448:

; 133  : 						if(TempPlayer[TempJoy->Button[LEFT]].c != C_KEY)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+12]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR [eax+ecx*8+4]
	and	ecx, 3
	cmp	ecx, 2
	je	SHORT $L73451

; 135  : 							TempPlayer[TempJoy->Button[LEFT]].v = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+12]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	BYTE PTR [eax+ecx*8], 0

; 136  : 							TempPlayer[TempJoy->Button[LEFT]].c = false;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	eax, eax
	mov	al, BYTE PTR [edx+12]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	al, -4					; fffffffcH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+12]
	mov	edx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+56]
	mov	DWORD PTR [edx+ecx*8+4], eax
$L73451:

; 138  : 
; 139  : 						if(TempPlayer[TempJoy->Button[RIGHT]].c != C_KEY)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+13]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	edx, DWORD PTR [ecx+edx*8+4]
	and	edx, 3
	cmp	edx, 2
	je	SHORT $L73452

; 141  : 							TempPlayer[TempJoy->Button[RIGHT]].v = false;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+13]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	BYTE PTR [ecx+edx*8], 0

; 142  : 							TempPlayer[TempJoy->Button[RIGHT]].c = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+13]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR [eax+ecx*8+4]
	and	ecx, -4					; fffffffcH
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+13]
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+56]
	mov	DWORD PTR [eax+edx*8+4], ecx
$L73452:

; 145  : 				// Button #
; 146  : 				for(b = 0; b < 4; b++)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+53], 0
	jmp	SHORT $L73453
$L73454:
	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR [edx+53]
	add	al, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+53], al
$L73453:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+53]
	cmp	eax, 4
	jge	$L73455

; 148  : 					k = 1 << b;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+53]
	mov	ecx, edx
	mov	eax, 1
	shl	eax, cl
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+54], al

; 149  : 					if( GETBIT(JoyInfo.dwButtons, k ) )

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	not	edx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+144]
	or	ecx, edx
	xor	eax, ecx
	not	eax
	test	eax, eax
	je	$L73456

; 151  : 						k = TempJoy->Button[b + 4];

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+53]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [eax+edx+14]
	mov	BYTE PTR [ecx+54], dl

; 152  : 						if( !TempPlayer[k].v )

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx*8]
	test	edx, edx
	jne	$L73466

; 154  : 							if( (k == UP) && ( !TempPlayer[DOWN].v ) )

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	test	ecx, ecx
	jne	SHORT $L73458
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+8]
	test	ecx, ecx
	jne	SHORT $L73458

; 156  : 								TempPlayer[k].v = true;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	BYTE PTR [edx+eax*8], 1

; 157  : 								TempPlayer[k].c = C_JOY;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR [eax+ecx*8+4]
	and	ecx, -4					; fffffffcH
	or	ecx, 1
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+56]
	mov	DWORD PTR [edx+eax*8+4], ecx

; 159  : 							else if( (k == DOWN) && ( !TempPlayer[UP].v ) )

	jmp	$L73466
$L73458:
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	cmp	ecx, 1
	jne	SHORT $L73460
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	test	ecx, ecx
	jne	SHORT $L73460

; 161  : 								TempPlayer[k].v = true;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	BYTE PTR [edx+eax*8], 1

; 162  : 								TempPlayer[k].c = C_JOY;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR [eax+ecx*8+4]
	and	ecx, -4					; fffffffcH
	or	ecx, 1
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+56]
	mov	DWORD PTR [edx+eax*8+4], ecx

; 164  : 							else if( (k == LEFT) && ( !TempPlayer[RIGHT].v ) )

	jmp	$L73466
$L73460:
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	cmp	ecx, 2
	jne	SHORT $L73462
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+24]
	test	ecx, ecx
	jne	SHORT $L73462

; 166  : 								TempPlayer[k].v = true;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	BYTE PTR [edx+eax*8], 1

; 167  : 								TempPlayer[k].c = C_JOY;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR [eax+ecx*8+4]
	and	ecx, -4					; fffffffcH
	or	ecx, 1
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+56]
	mov	DWORD PTR [edx+eax*8+4], ecx

; 169  : 							else if( (k == RIGHT) && ( !TempPlayer[LEFT].v ) )

	jmp	$L73466
$L73462:
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	cmp	ecx, 3
	jne	SHORT $L73464
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+16]
	test	ecx, ecx
	jne	SHORT $L73464

; 171  : 								TempPlayer[k].v = true;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	BYTE PTR [edx+eax*8], 1

; 172  : 								TempPlayer[k].c = C_JOY;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR [eax+ecx*8+4]
	and	ecx, -4					; fffffffcH
	or	ecx, 1
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+56]
	mov	DWORD PTR [edx+eax*8+4], ecx

; 174  : 							else if(k > 3)

	jmp	SHORT $L73466
$L73464:
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	cmp	ecx, 3
	jle	SHORT $L73466

; 176  : 								TempPlayer[k].v = true;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	BYTE PTR [edx+eax*8], 1

; 177  : 								TempPlayer[k].c = C_JOY;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR [eax+ecx*8+4]
	and	ecx, -4					; fffffffcH
	or	ecx, 1
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+56]
	mov	DWORD PTR [edx+eax*8+4], ecx
$L73466:

; 181  : 					else

	jmp	SHORT $L73468
$L73456:

; 183  : 						k = TempJoy->Button[b + 4];

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+53]
	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR [ecx+eax+14]
	mov	BYTE PTR [edx+54], al

; 184  : 
; 185  : 						if(TempPlayer[ k ].c != C_KEY)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	edx, DWORD PTR [ecx+edx*8+4]
	and	edx, 3
	cmp	edx, 2
	je	SHORT $L73468

; 187  : 							TempPlayer[ k ].v = false;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	BYTE PTR [eax+ecx*8], 0

; 188  : 							TempPlayer[ k ].c = false;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	edx, DWORD PTR [ecx+edx*8+4]
	and	edx, -4					; fffffffcH
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+56]
	mov	DWORD PTR [eax+ecx*8+4], edx
$L73468:

; 191  : 				}

	jmp	$L73454
$L73455:

; 193  : 			else

	jmp	SHORT $L73469
$L73436:

; 194  : 				TempJoy->Enabled = false;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	mov	BYTE PTR [edx], 0
$L73469:

; 196  : 	}

	jmp	$L73433
$L73434:

; 197  : 
; 198  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Joy_Loop@CONTROLS@@QAEXXZ ENDP				; CONTROLS::Joy_Loop
_TEXT	ENDS
PUBLIC	?TestKey@CONTROLS@@QAE_NUKey@@@Z		; CONTROLS::TestKey
;	COMDAT ?Key_Loop@CONTROLS@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
?Key_Loop@CONTROLS@@QAEXXZ PROC NEAR			; CONTROLS::Key_Loop, COMDAT

; 203  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 204  : 	for(k = 0; k < NumpKey; k++)

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+54], 0
	jmp	SHORT $L73474
$L73475:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+54]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+54], dl
$L73474:
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+32]
	cmp	edx, ecx
	jge	$L73476

; 206  : 		TempPlayer = Player[ kPlayerNum ];

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+40]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+eax*4]
	mov	DWORD PTR [ecx+56], edx

; 207  : 	
; 208  : 		if(	TestKey( pKey[k] ) )

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+54]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+36]
	mov	ecx, DWORD PTR [eax+ecx*4]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?TestKey@CONTROLS@@QAE_NUKey@@@Z	; CONTROLS::TestKey
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	$L73477

; 210  : 			if( (k == UP) && ( !TempPlayer[UP].v ) && ( !TempPlayer[DOWN].v ) )

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	test	eax, eax
	jne	SHORT $L73478
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	test	eax, eax
	jne	SHORT $L73478
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	xor	eax, eax
	mov	al, BYTE PTR [edx+8]
	test	eax, eax
	jne	SHORT $L73478

; 212  : 				TempPlayer[k].v = true;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	BYTE PTR [ecx+edx*8], 1

; 213  : 				TempPlayer[k].c = C_KEY;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	al, -4					; fffffffcH
	or	al, 2
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+56]
	mov	DWORD PTR [ecx+edx*8+4], eax

; 215  : 			else if( (k == DOWN) && ( !TempPlayer[DOWN].v ) && ( !TempPlayer[UP].v ) )

	jmp	$L73486
$L73478:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	cmp	eax, 1
	jne	SHORT $L73480
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	xor	eax, eax
	mov	al, BYTE PTR [edx+8]
	test	eax, eax
	jne	SHORT $L73480
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	test	eax, eax
	jne	SHORT $L73480

; 217  : 				TempPlayer[k].v = true;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	BYTE PTR [ecx+edx*8], 1

; 218  : 				TempPlayer[k].c = C_KEY;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	al, -4					; fffffffcH
	or	al, 2
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+56]
	mov	DWORD PTR [ecx+edx*8+4], eax

; 220  : 			else if( (k == LEFT) && ( !TempPlayer[LEFT].v ) && ( !TempPlayer[RIGHT].v ) )

	jmp	$L73486
$L73480:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	cmp	eax, 2
	jne	SHORT $L73482
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	xor	eax, eax
	mov	al, BYTE PTR [edx+16]
	test	eax, eax
	jne	SHORT $L73482
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	xor	eax, eax
	mov	al, BYTE PTR [edx+24]
	test	eax, eax
	jne	SHORT $L73482

; 222  : 				TempPlayer[k].v = true;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	BYTE PTR [ecx+edx*8], 1

; 223  : 				TempPlayer[k].c = C_KEY;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	al, -4					; fffffffcH
	or	al, 2
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+56]
	mov	DWORD PTR [ecx+edx*8+4], eax

; 225  : 			else if( (k == RIGHT) && ( !TempPlayer[RIGHT].v ) && ( !TempPlayer[LEFT].v ) )

	jmp	$L73486
$L73482:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	cmp	eax, 3
	jne	SHORT $L73484
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	xor	eax, eax
	mov	al, BYTE PTR [edx+24]
	test	eax, eax
	jne	SHORT $L73484
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	xor	eax, eax
	mov	al, BYTE PTR [edx+16]
	test	eax, eax
	jne	SHORT $L73484

; 227  : 				TempPlayer[k].v = true;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	BYTE PTR [ecx+edx*8], 1

; 228  : 				TempPlayer[k].c = C_KEY;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	al, -4					; fffffffcH
	or	al, 2
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+56]
	mov	DWORD PTR [ecx+edx*8+4], eax

; 230  : 			else if( (k > 3) && ( !TempPlayer[k].v ) )

	jmp	SHORT $L73486
$L73484:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	cmp	eax, 3
	jle	SHORT $L73486
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx*8]
	test	eax, eax
	jne	SHORT $L73486

; 232  : 				TempPlayer[k].v = true;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	BYTE PTR [ecx+edx*8], 1

; 233  : 				TempPlayer[k].c = C_KEY;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	al, -4					; fffffffcH
	or	al, 2
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+56]
	mov	DWORD PTR [ecx+edx*8+4], eax
$L73486:

; 236  : 		else

	jmp	SHORT $L73488
$L73477:

; 238  : 			if( TempPlayer[k].c != C_JOY )

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	eax, 3
	cmp	eax, 1
	je	SHORT $L73488

; 240  : 				TempPlayer[k].v = false;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	BYTE PTR [ecx+edx*8], 0

; 241  : 				TempPlayer[k].c = false;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR [edx+eax*8+4]
	and	al, -4					; fffffffcH
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+56]
	mov	DWORD PTR [ecx+edx*8+4], eax
$L73488:

; 244  : //
; 245  : 	}

	jmp	$L73475
$L73476:

; 246  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Key_Loop@CONTROLS@@QAEXXZ ENDP				; CONTROLS::Key_Loop
_TEXT	ENDS
PUBLIC	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ		; MAIN::Get_MainHwnd
EXTRN	?Val@@3PAVVALUES@@A:DWORD			; Val
EXTRN	__imp__PostMessageA@16:NEAR
EXTRN	?Pause@DISPLAY@@QAE_NXZ:NEAR			; DISPLAY::Pause
EXTRN	__imp__GetAsyncKeyState@4:NEAR
;	COMDAT ?Sys_Loop@CONTROLS@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
_Close$73500 = -8
?Sys_Loop@CONTROLS@@QAEXXZ PROC NEAR			; CONTROLS::Sys_Loop, COMDAT

; 249  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 250  : 	for(k = 0; k < NumsKey; k++)

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+54], 0
	jmp	SHORT $L73493
$L73494:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+54]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+54], dl
$L73493:
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+25]
	cmp	edx, ecx
	jge	$L73495

; 252  : 		if(	TestKey( sKey[k] ) )

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+54]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	mov	eax, DWORD PTR [edx+eax*4]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?TestKey@CONTROLS@@QAE_NUKey@@@Z	; CONTROLS::TestKey
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	$L73499

; 254  : 			if(k == 0)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	test	edx, edx
	jne	SHORT $L73497

; 256  : 				PostMessage(Val->Main->Get_MainHwnd(), WM_DESTROY, 0, 0);

	push	0
	push	0
	push	2
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+56]
	call	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ	; MAIN::Get_MainHwnd
	push	eax
	call	DWORD PTR __imp__PostMessageA@16

; 258  : 			else if(k == 1)

	jmp	$L73499
$L73497:
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+54]
	cmp	edx, 1
	jne	$L73499

; 260  : 				bool Close = false;

	mov	BYTE PTR _Close$73500[ebp], 0

; 261  : 				Val->Display->Pause();

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+64]
	call	?Pause@DISPLAY@@QAE_NXZ			; DISPLAY::Pause
$L73502:

; 262  : 
; 263  : 				while( !GetAsyncKeyState(VK_SPACE) )

	push	32					; 00000020H
	call	DWORD PTR __imp__GetAsyncKeyState@4
	movsx	ecx, ax
	test	ecx, ecx
	jne	SHORT $L73503

; 265  : 					if(TestKey( sKey[0] ) )

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?TestKey@CONTROLS@@QAE_NUKey@@@Z	; CONTROLS::TestKey
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L73504

; 267  : 						Close = true;

	mov	BYTE PTR _Close$73500[ebp], 1

; 268  : 						break;

	jmp	SHORT $L73503
$L73504:

; 270  : 				}

	jmp	SHORT $L73502
$L73503:

; 271  : 
; 272  : 				if(Close)

	mov	edx, DWORD PTR _Close$73500[ebp]
	and	edx, 255				; 000000ffH
	test	edx, edx
	je	SHORT $L73505

; 273  : 					PostMessage(Val->Main->Get_MainHwnd(), WM_DESTROY, 0, 0);

	push	0
	push	0
	push	2
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+56]
	call	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ	; MAIN::Get_MainHwnd
	push	eax
	call	DWORD PTR __imp__PostMessageA@16
$L73505:

; 274  : 				
; 275  : 				Val->Display->Re_Draw = RE_ALL;

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+64]
	mov	eax, DWORD PTR [edx+52]
	and	al, -4					; fffffffcH
	or	al, 2
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+64]
	mov	DWORD PTR [edx+52], eax
$L73499:

; 278  : //
; 279  : 	}

	jmp	$L73494
$L73495:

; 280  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Sys_Loop@CONTROLS@@QAEXXZ ENDP				; CONTROLS::Sys_Loop
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
;	COMDAT ?TestKey@CONTROLS@@QAE_NUKey@@@Z
_TEXT	SEGMENT
_kb$ = 8
_this$ = -4
?TestKey@CONTROLS@@QAE_NUKey@@@Z PROC NEAR		; CONTROLS::TestKey, COMDAT

; 283  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 284  : 	if(kb.Code == 0)

	mov	eax, DWORD PTR _kb$[ebp]
	and	eax, 255				; 000000ffH
	test	eax, eax
	jne	SHORT $L73510

; 285  : 		return 0;

	xor	al, al
	jmp	$L73509
$L73510:

; 286  : 
; 287  : 	if( GetAsyncKeyState(kb.Code) )

	mov	ecx, DWORD PTR _kb$[ebp]
	and	ecx, 255				; 000000ffH
	push	ecx
	call	DWORD PTR __imp__GetAsyncKeyState@4
	movsx	edx, ax
	test	edx, edx
	je	$L73511

; 289  : 		j = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+52], 0

; 290  : 		if(kb.a){	if(GetAsyncKeyState(VK_MENU) )		j++; }

	mov	ecx, DWORD PTR _kb$[ebp+1]
	and	ecx, 255				; 000000ffH
	test	ecx, ecx
	je	SHORT $L73513
	push	18					; 00000012H
	call	DWORD PTR __imp__GetAsyncKeyState@4
	movsx	edx, ax
	test	edx, edx
	je	SHORT $L73513
	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+52]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+52], cl
$L73513:

; 291  : 		if(kb.c){	if(GetAsyncKeyState(VK_CONTROL) )	j++; }

	mov	eax, DWORD PTR _kb$[ebp+2]
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L73515
	push	17					; 00000011H
	call	DWORD PTR __imp__GetAsyncKeyState@4
	movsx	ecx, ax
	test	ecx, ecx
	je	SHORT $L73515
	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR [edx+52]
	add	al, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+52], al
$L73515:

; 292  : 		if(kb.s){	if(GetAsyncKeyState(VK_SHIFT) )		j++; }

	mov	edx, DWORD PTR _kb$[ebp+3]
	and	edx, 255				; 000000ffH
	test	edx, edx
	je	SHORT $L73517
	push	16					; 00000010H
	call	DWORD PTR __imp__GetAsyncKeyState@4
	movsx	eax, ax
	test	eax, eax
	je	SHORT $L73517
	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+52]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+52], dl
$L73517:

; 293  : 
; 294  : 		if( (unsigned)(kb.a + kb.c + kb.s) == j)

	mov	ecx, DWORD PTR _kb$[ebp+1]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _kb$[ebp+2]
	and	edx, 255				; 000000ffH
	add	ecx, edx
	mov	eax, DWORD PTR _kb$[ebp+3]
	and	eax, 255				; 000000ffH
	add	ecx, eax
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+52]
	cmp	ecx, eax
	jne	SHORT $L73519

; 295  : 			return 1;

	mov	al, 1
	jmp	SHORT $L73509
$L73519:

; 297  : 			return 0;

	xor	al, al
	jmp	SHORT $L73509
$L73511:

; 300  : 		return 0;

	xor	al, al
$L73509:

; 301  : 
; 302  : 	return 0;
; 303  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?TestKey@CONTROLS@@QAE_NUKey@@@Z ENDP			; CONTROLS::TestKey
_TEXT	ENDS
PUBLIC	?OnMouse@CONTROLS@@QAEXPAUHWND__@@HHI@Z		; CONTROLS::OnMouse
EXTRN	__imp__ShowCursor@4:NEAR
;	COMDAT ?OnMouse@CONTROLS@@QAEXPAUHWND__@@HHI@Z
_TEXT	SEGMENT
_hwnd$ = 8
_x$ = 12
_y$ = 16
_this$ = -4
?OnMouse@CONTROLS@@QAEXPAUHWND__@@HHI@Z PROC NEAR	; CONTROLS::OnMouse, COMDAT

; 308  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 309  : 	if(hwnd == hWnd)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _hwnd$[ebp]
	cmp	ecx, DWORD PTR [eax+68]
	jne	SHORT $L73529

; 311  : 		if(Cursor)

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+88]
	test	eax, eax
	je	SHORT $L73530

; 313  : 			Mouse.show = false;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+106], 0

; 314  : 			ShowCursor(false);

	push	0
	call	DWORD PTR __imp__ShowCursor@4
$L73530:

; 316  : 
; 317  : 		Mouse.x = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	edx, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+108]
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+94], ax

; 318  : 		Mouse.y = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+96], ax

; 320  : 	else

	jmp	$L73531
$L73529:

; 322  : 		if(Cursor)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+88]
	test	ecx, ecx
	je	SHORT $L73532

; 324  : 			Mouse.show = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+106], 0

; 325  : 			ShowCursor(true);

	push	1
	call	DWORD PTR __imp__ShowCursor@4
$L73532:

; 327  : 		
; 328  : 
; 329  : 		if(x > ChildRect.right)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	cmp	ecx, DWORD PTR [eax+80]
	jle	SHORT $L73533

; 330  : 			x = (short)(ChildRect.right - ChildRect.left) - 5;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+80]
	sub	ecx, DWORD PTR [eax+72]
	movsx	edx, cx
	sub	edx, 5
	mov	DWORD PTR _x$[ebp], edx

; 331  : 		else if(x < ChildRect.left)

	jmp	SHORT $L73537
$L73533:
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	cmp	ecx, DWORD PTR [eax+72]
	jge	SHORT $L73536

; 332  : 			x = 0;

	mov	DWORD PTR _x$[ebp], 0

; 333  : 		else

	jmp	SHORT $L73537
$L73536:

; 334  : 			x = (short)(x - ChildRect.left);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _x$[ebp]
	sub	eax, DWORD PTR [edx+72]
	movsx	ecx, ax
	mov	DWORD PTR _x$[ebp], ecx
$L73537:

; 335  : 
; 336  : 		if(y > ChildRect.bottom)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	cmp	eax, DWORD PTR [edx+84]
	jle	SHORT $L73539

; 337  : 			y = (short)(ChildRect.bottom - ChildRect.top) - 10;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+84]
	sub	eax, DWORD PTR [edx+76]
	movsx	ecx, ax
	sub	ecx, 10					; 0000000aH
	mov	DWORD PTR _y$[ebp], ecx

; 338  : 		else if(y < ChildRect.top)

	jmp	SHORT $L73543
$L73539:
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	cmp	eax, DWORD PTR [edx+76]
	jge	SHORT $L73542

; 339  : 			y = 0;

	mov	DWORD PTR _y$[ebp], 0

; 340  : 		else

	jmp	SHORT $L73543
$L73542:

; 341  : 			y = (short)(y - ChildRect.top);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _y$[ebp]
	sub	edx, DWORD PTR [ecx+76]
	movsx	eax, dx
	mov	DWORD PTR _y$[ebp], eax
$L73543:

; 342  : 
; 343  : 		Mouse.x = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+108]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+94], ax

; 344  : 		Mouse.y = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+96], ax
$L73531:

; 346  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?OnMouse@CONTROLS@@QAEXPAUHWND__@@HHI@Z ENDP		; CONTROLS::OnMouse
_TEXT	ENDS
PUBLIC	?OnMouseLDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z	; CONTROLS::OnMouseLDown
EXTRN	__imp__SetCapture@4:NEAR
;	COMDAT ?OnMouseLDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z
_TEXT	SEGMENT
_hwnd$ = 8
_x$ = 16
_y$ = 20
_this$ = -4
?OnMouseLDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z PROC NEAR	; CONTROLS::OnMouseLDown, COMDAT

; 348  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 349  : 	SetCapture(hwnd);

	mov	eax, DWORD PTR _hwnd$[ebp]
	push	eax
	call	DWORD PTR __imp__SetCapture@4

; 350  : 
; 351  : 	if(hwnd == hWnd)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _hwnd$[ebp]
	cmp	edx, DWORD PTR [ecx+68]
	jne	SHORT $L73553

; 353  : 		if(Cursor)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+88]
	test	ecx, ecx
	je	SHORT $L73554

; 355  : 			Mouse.show = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+106], 0

; 356  : 			ShowCursor(false);

	push	0
	call	DWORD PTR __imp__ShowCursor@4
$L73554:

; 358  : 
; 359  : 		Mouse.StartX = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+108]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+98], ax

; 360  : 		Mouse.StartY = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+100], ax

; 361  : 		Mouse.left = true;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+90], 1

; 363  : 	else

	jmp	$L73555
$L73553:

; 365  : 		if(Cursor)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+88]
	test	edx, edx
	je	SHORT $L73556

; 367  : 			Mouse.show = false;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+106], 0

; 368  : 			ShowCursor(true);

	push	1
	call	DWORD PTR __imp__ShowCursor@4
$L73556:

; 370  : 		
; 371  : 
; 372  : 		if(x > ChildRect.right)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	cmp	edx, DWORD PTR [ecx+80]
	jle	SHORT $L73557

; 373  : 			x = (short)(ChildRect.right - ChildRect.left) - 5;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [eax+80]
	sub	edx, DWORD PTR [ecx+72]
	movsx	eax, dx
	sub	eax, 5
	mov	DWORD PTR _x$[ebp], eax

; 374  : 		else if(x < ChildRect.left)

	jmp	SHORT $L73561
$L73557:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	cmp	edx, DWORD PTR [ecx+72]
	jge	SHORT $L73560

; 375  : 			x = 0;

	mov	DWORD PTR _x$[ebp], 0

; 376  : 		else

	jmp	SHORT $L73561
$L73560:

; 377  : 			x = (short)(x - ChildRect.left);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	sub	ecx, DWORD PTR [eax+72]
	movsx	edx, cx
	mov	DWORD PTR _x$[ebp], edx
$L73561:

; 378  : 
; 379  : 		if(y > ChildRect.bottom)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _y$[ebp]
	cmp	ecx, DWORD PTR [eax+84]
	jle	SHORT $L73563

; 380  : 			y = (short)(ChildRect.bottom - ChildRect.top) - 10;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+84]
	sub	ecx, DWORD PTR [eax+76]
	movsx	edx, cx
	sub	edx, 10					; 0000000aH
	mov	DWORD PTR _y$[ebp], edx

; 381  : 		else if(y < ChildRect.top)

	jmp	SHORT $L73567
$L73563:
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _y$[ebp]
	cmp	ecx, DWORD PTR [eax+76]
	jge	SHORT $L73566

; 382  : 			y = 0;

	mov	DWORD PTR _y$[ebp], 0

; 383  : 		else

	jmp	SHORT $L73567
$L73566:

; 384  : 			y = (short)(y - ChildRect.top);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	sub	eax, DWORD PTR [edx+76]
	movsx	ecx, ax
	mov	DWORD PTR _y$[ebp], ecx
$L73567:

; 385  : 
; 386  : 		Mouse.StartX = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	edx, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+108]
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+98], ax

; 387  : 		Mouse.StartY = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+100], ax
$L73555:

; 389  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	20					; 00000014H
?OnMouseLDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z ENDP	; CONTROLS::OnMouseLDown
_TEXT	ENDS
PUBLIC	?OnMouseRDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z	; CONTROLS::OnMouseRDown
;	COMDAT ?OnMouseRDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z
_TEXT	SEGMENT
_hwnd$ = 8
_x$ = 16
_y$ = 20
_this$ = -4
?OnMouseRDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z PROC NEAR	; CONTROLS::OnMouseRDown, COMDAT

; 391  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 392  : 	SetCapture(hwnd);

	mov	eax, DWORD PTR _hwnd$[ebp]
	push	eax
	call	DWORD PTR __imp__SetCapture@4

; 393  : 
; 394  : 	if(hwnd == hWnd)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _hwnd$[ebp]
	cmp	edx, DWORD PTR [ecx+68]
	jne	SHORT $L73577

; 396  : 		if(Cursor)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+88]
	test	ecx, ecx
	je	SHORT $L73578

; 398  : 			Mouse.show = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+106], 0

; 399  : 			ShowCursor(false);

	push	0
	call	DWORD PTR __imp__ShowCursor@4
$L73578:

; 401  : 
; 402  : 		Mouse.StartX = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+108]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+98], ax

; 403  : 		Mouse.StartY = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+100], ax

; 404  : 		Mouse.right = true;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+91], 1

; 406  : 	else

	jmp	$L73579
$L73577:

; 408  : 		if(Cursor)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+88]
	test	edx, edx
	je	SHORT $L73580

; 410  : 			Mouse.show = false;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+106], 0

; 411  : 			ShowCursor(true);

	push	1
	call	DWORD PTR __imp__ShowCursor@4
$L73580:

; 413  : 		
; 414  : 		if(x > ChildRect.right)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	cmp	edx, DWORD PTR [ecx+80]
	jle	SHORT $L73581

; 415  : 			x = (short)(ChildRect.right - ChildRect.left) - 5;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [eax+80]
	sub	edx, DWORD PTR [ecx+72]
	movsx	eax, dx
	sub	eax, 5
	mov	DWORD PTR _x$[ebp], eax

; 416  : 		else if(x < ChildRect.left)

	jmp	SHORT $L73585
$L73581:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	cmp	edx, DWORD PTR [ecx+72]
	jge	SHORT $L73584

; 417  : 			x = 0;

	mov	DWORD PTR _x$[ebp], 0

; 418  : 		else

	jmp	SHORT $L73585
$L73584:

; 419  : 			x = (short)(x - ChildRect.left);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	sub	ecx, DWORD PTR [eax+72]
	movsx	edx, cx
	mov	DWORD PTR _x$[ebp], edx
$L73585:

; 420  : 
; 421  : 		if(y > ChildRect.bottom)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _y$[ebp]
	cmp	ecx, DWORD PTR [eax+84]
	jle	SHORT $L73587

; 422  : 			y = (short)(ChildRect.bottom - ChildRect.top) - 10;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+84]
	sub	ecx, DWORD PTR [eax+76]
	movsx	edx, cx
	sub	edx, 10					; 0000000aH
	mov	DWORD PTR _y$[ebp], edx

; 423  : 		else if(y < ChildRect.top)

	jmp	SHORT $L73591
$L73587:
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _y$[ebp]
	cmp	ecx, DWORD PTR [eax+76]
	jge	SHORT $L73590

; 424  : 			y = 0;

	mov	DWORD PTR _y$[ebp], 0

; 425  : 		else

	jmp	SHORT $L73591
$L73590:

; 426  : 			y = (short)(y - ChildRect.top);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	sub	eax, DWORD PTR [edx+76]
	movsx	ecx, ax
	mov	DWORD PTR _y$[ebp], ecx
$L73591:

; 427  : 
; 428  : 		Mouse.StartX = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	edx, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+108]
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+98], ax

; 429  : 		Mouse.StartY = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+100], ax
$L73579:

; 431  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	20					; 00000014H
?OnMouseRDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z ENDP	; CONTROLS::OnMouseRDown
_TEXT	ENDS
PUBLIC	?OnMouseMDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z	; CONTROLS::OnMouseMDown
;	COMDAT ?OnMouseMDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z
_TEXT	SEGMENT
_hwnd$ = 8
_x$ = 16
_y$ = 20
_this$ = -4
?OnMouseMDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z PROC NEAR	; CONTROLS::OnMouseMDown, COMDAT

; 433  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 434  : 	SetCapture(hwnd);

	mov	eax, DWORD PTR _hwnd$[ebp]
	push	eax
	call	DWORD PTR __imp__SetCapture@4

; 435  : 
; 436  : 	if(hwnd == hWnd)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _hwnd$[ebp]
	cmp	edx, DWORD PTR [ecx+68]
	jne	SHORT $L73601

; 438  : 		if(Cursor)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+88]
	test	ecx, ecx
	je	SHORT $L73602

; 440  : 			Mouse.show = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+106], 0

; 441  : 			ShowCursor(false);

	push	0
	call	DWORD PTR __imp__ShowCursor@4
$L73602:

; 443  : 
; 444  : 		Mouse.StartX = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+108]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+98], ax

; 445  : 		Mouse.StartY = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+100], ax

; 446  : 		Mouse.middle = true;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+92], 1

; 448  : 	else

	jmp	$L73603
$L73601:

; 450  : 		if(Cursor)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+88]
	test	edx, edx
	je	SHORT $L73604

; 452  : 			Mouse.show = false;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+106], 0

; 453  : 			ShowCursor(true);

	push	1
	call	DWORD PTR __imp__ShowCursor@4
$L73604:

; 455  : 		
; 456  : 
; 457  : 		if(x > ChildRect.right)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	cmp	edx, DWORD PTR [ecx+80]
	jle	SHORT $L73605

; 458  : 			x = (short)(ChildRect.right - ChildRect.left) - 5;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [eax+80]
	sub	edx, DWORD PTR [ecx+72]
	movsx	eax, dx
	sub	eax, 5
	mov	DWORD PTR _x$[ebp], eax

; 459  : 		else if(x < ChildRect.left)

	jmp	SHORT $L73609
$L73605:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	cmp	edx, DWORD PTR [ecx+72]
	jge	SHORT $L73608

; 460  : 			x = 0;

	mov	DWORD PTR _x$[ebp], 0

; 461  : 		else

	jmp	SHORT $L73609
$L73608:

; 462  : 			x = (short)(x - ChildRect.left);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	sub	ecx, DWORD PTR [eax+72]
	movsx	edx, cx
	mov	DWORD PTR _x$[ebp], edx
$L73609:

; 463  : 
; 464  : 		if(y > ChildRect.bottom)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _y$[ebp]
	cmp	ecx, DWORD PTR [eax+84]
	jle	SHORT $L73611

; 465  : 			y = (short)(ChildRect.bottom - ChildRect.top) - 10;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+84]
	sub	ecx, DWORD PTR [eax+76]
	movsx	edx, cx
	sub	edx, 10					; 0000000aH
	mov	DWORD PTR _y$[ebp], edx

; 466  : 		else if(y < ChildRect.top)

	jmp	SHORT $L73615
$L73611:
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _y$[ebp]
	cmp	ecx, DWORD PTR [eax+76]
	jge	SHORT $L73614

; 467  : 			y = 0;

	mov	DWORD PTR _y$[ebp], 0

; 468  : 		else

	jmp	SHORT $L73615
$L73614:

; 469  : 			y = (short)(y - ChildRect.top);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	sub	eax, DWORD PTR [edx+76]
	movsx	ecx, ax
	mov	DWORD PTR _y$[ebp], ecx
$L73615:

; 470  : 
; 471  : 		Mouse.StartX = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	edx, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+108]
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+98], ax

; 472  : 		Mouse.StartY = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+100], ax
$L73603:

; 474  : 
; 475  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	20					; 00000014H
?OnMouseMDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z ENDP	; CONTROLS::OnMouseMDown
_TEXT	ENDS
PUBLIC	?OnMouseLUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z	; CONTROLS::OnMouseLUp
EXTRN	__imp__ReleaseCapture@0:NEAR
;	COMDAT ?OnMouseLUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z
_TEXT	SEGMENT
_hwnd$ = 8
_x$ = 12
_y$ = 16
_this$ = -4
?OnMouseLUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z PROC NEAR	; CONTROLS::OnMouseLUp, COMDAT

; 477  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 478  : 	ReleaseCapture();

	call	DWORD PTR __imp__ReleaseCapture@0

; 479  : 
; 480  : 	Mouse.left = false;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+90], 0

; 481  : 
; 482  : 	if(hwnd == hWnd)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _hwnd$[ebp]
	cmp	edx, DWORD PTR [ecx+68]
	jne	SHORT $L73624

; 484  : 		if(Cursor)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+88]
	test	ecx, ecx
	je	SHORT $L73625

; 486  : 			Mouse.show = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+106], 0

; 487  : 			ShowCursor(false);

	push	0
	call	DWORD PTR __imp__ShowCursor@4
$L73625:

; 489  : 
; 490  : 		Mouse.EndX = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+108]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+102], ax

; 491  : 		Mouse.EndX = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+102], ax

; 493  : 	else

	jmp	$L73626
$L73624:

; 495  : 		if(Cursor)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+88]
	test	ecx, ecx
	je	SHORT $L73627

; 497  : 			Mouse.show = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+106], 0

; 498  : 			ShowCursor(true);

	push	1
	call	DWORD PTR __imp__ShowCursor@4
$L73627:

; 500  : 		
; 501  : 
; 502  : 		if(x > ChildRect.right)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	cmp	ecx, DWORD PTR [eax+80]
	jle	SHORT $L73628

; 503  : 			x = (short)(ChildRect.right - ChildRect.left) - 5;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+80]
	sub	ecx, DWORD PTR [eax+72]
	movsx	edx, cx
	sub	edx, 5
	mov	DWORD PTR _x$[ebp], edx

; 504  : 		else if(x < ChildRect.left)

	jmp	SHORT $L73632
$L73628:
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	cmp	ecx, DWORD PTR [eax+72]
	jge	SHORT $L73631

; 505  : 			x = 0;

	mov	DWORD PTR _x$[ebp], 0

; 506  : 		else

	jmp	SHORT $L73632
$L73631:

; 507  : 			x = (short)(x - ChildRect.left);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _x$[ebp]
	sub	eax, DWORD PTR [edx+72]
	movsx	ecx, ax
	mov	DWORD PTR _x$[ebp], ecx
$L73632:

; 508  : 
; 509  : 		if(y > ChildRect.bottom)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	cmp	eax, DWORD PTR [edx+84]
	jle	SHORT $L73634

; 510  : 			y = (short)(ChildRect.bottom - ChildRect.top) - 10;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+84]
	sub	eax, DWORD PTR [edx+76]
	movsx	ecx, ax
	sub	ecx, 10					; 0000000aH
	mov	DWORD PTR _y$[ebp], ecx

; 511  : 		else if(y < ChildRect.top)

	jmp	SHORT $L73638
$L73634:
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	cmp	eax, DWORD PTR [edx+76]
	jge	SHORT $L73637

; 512  : 			y = 0;

	mov	DWORD PTR _y$[ebp], 0

; 513  : 		else

	jmp	SHORT $L73638
$L73637:

; 514  : 			y = (short)(y - ChildRect.top);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _y$[ebp]
	sub	edx, DWORD PTR [ecx+76]
	movsx	eax, dx
	mov	DWORD PTR _y$[ebp], eax
$L73638:

; 515  : 
; 516  : 		Mouse.EndX = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+108]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+102], ax

; 517  : 		Mouse.EndX = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+102], ax
$L73626:

; 519  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?OnMouseLUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z ENDP		; CONTROLS::OnMouseLUp
_TEXT	ENDS
PUBLIC	?OnMouseRUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z	; CONTROLS::OnMouseRUp
;	COMDAT ?OnMouseRUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z
_TEXT	SEGMENT
_hwnd$ = 8
_x$ = 12
_y$ = 16
_this$ = -4
?OnMouseRUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z PROC NEAR	; CONTROLS::OnMouseRUp, COMDAT

; 521  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 522  : 	ReleaseCapture();

	call	DWORD PTR __imp__ReleaseCapture@0

; 523  : 
; 524  : 	Mouse.right = false;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+91], 0

; 525  : 
; 526  : 	if(hwnd == hWnd)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _hwnd$[ebp]
	cmp	edx, DWORD PTR [ecx+68]
	jne	SHORT $L73647

; 528  : 		if(Cursor)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+88]
	test	ecx, ecx
	je	SHORT $L73648

; 530  : 			Mouse.show = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+106], 0

; 531  : 			ShowCursor(false);

	push	0
	call	DWORD PTR __imp__ShowCursor@4
$L73648:

; 533  : 
; 534  : 		Mouse.EndX = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+108]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+102], ax

; 535  : 		Mouse.EndX = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+102], ax

; 537  : 	else

	jmp	$L73649
$L73647:

; 539  : 		if(Cursor)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+88]
	test	ecx, ecx
	je	SHORT $L73650

; 541  : 			Mouse.show = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+106], 0

; 542  : 			ShowCursor(true);

	push	1
	call	DWORD PTR __imp__ShowCursor@4
$L73650:

; 544  : 
; 545  : 		if(x > ChildRect.right)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	cmp	ecx, DWORD PTR [eax+80]
	jle	SHORT $L73651

; 546  : 			x = (short)(ChildRect.right - ChildRect.left) - 5;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+80]
	sub	ecx, DWORD PTR [eax+72]
	movsx	edx, cx
	sub	edx, 5
	mov	DWORD PTR _x$[ebp], edx

; 547  : 		else if(x < ChildRect.left)

	jmp	SHORT $L73655
$L73651:
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	cmp	ecx, DWORD PTR [eax+72]
	jge	SHORT $L73654

; 548  : 			x = 0;

	mov	DWORD PTR _x$[ebp], 0

; 549  : 		else

	jmp	SHORT $L73655
$L73654:

; 550  : 			x = (short)(x - ChildRect.left);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _x$[ebp]
	sub	eax, DWORD PTR [edx+72]
	movsx	ecx, ax
	mov	DWORD PTR _x$[ebp], ecx
$L73655:

; 551  : 
; 552  : 		if(y > ChildRect.bottom)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	cmp	eax, DWORD PTR [edx+84]
	jle	SHORT $L73657

; 553  : 			y = (short)(ChildRect.bottom - ChildRect.top) - 10;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+84]
	sub	eax, DWORD PTR [edx+76]
	movsx	ecx, ax
	sub	ecx, 10					; 0000000aH
	mov	DWORD PTR _y$[ebp], ecx

; 554  : 		else if(y < ChildRect.top)

	jmp	SHORT $L73661
$L73657:
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	cmp	eax, DWORD PTR [edx+76]
	jge	SHORT $L73660

; 555  : 			y = 0;

	mov	DWORD PTR _y$[ebp], 0

; 556  : 		else

	jmp	SHORT $L73661
$L73660:

; 557  : 			y = (short)(y - ChildRect.top);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _y$[ebp]
	sub	edx, DWORD PTR [ecx+76]
	movsx	eax, dx
	mov	DWORD PTR _y$[ebp], eax
$L73661:

; 558  : 
; 559  : 		Mouse.EndX = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+108]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+102], ax

; 560  : 		Mouse.EndX = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+102], ax
$L73649:

; 562  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?OnMouseRUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z ENDP		; CONTROLS::OnMouseRUp
_TEXT	ENDS
PUBLIC	?OnMouseMUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z	; CONTROLS::OnMouseMUp
;	COMDAT ?OnMouseMUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z
_TEXT	SEGMENT
_hwnd$ = 8
_x$ = 12
_y$ = 16
_this$ = -4
?OnMouseMUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z PROC NEAR	; CONTROLS::OnMouseMUp, COMDAT

; 564  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 565  : 	ReleaseCapture();

	call	DWORD PTR __imp__ReleaseCapture@0

; 566  : 
; 567  : 	Mouse.middle = false;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+92], 0

; 568  : 
; 569  : 	if(hwnd == hWnd)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _hwnd$[ebp]
	cmp	edx, DWORD PTR [ecx+68]
	jne	SHORT $L73670

; 571  : 		if(Cursor)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+88]
	test	ecx, ecx
	je	SHORT $L73671

; 573  : 			Mouse.show = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+106], 0

; 574  : 			ShowCursor(false);

	push	0
	call	DWORD PTR __imp__ShowCursor@4
$L73671:

; 576  : 
; 577  : 		Mouse.EndX = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+108]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+102], ax

; 578  : 		Mouse.EndX = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+102], ax

; 580  : 	else

	jmp	$L73672
$L73670:

; 582  : 		if(Cursor)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+88]
	test	ecx, ecx
	je	SHORT $L73673

; 584  : 			Mouse.show = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+106], 0

; 585  : 			ShowCursor(true);

	push	1
	call	DWORD PTR __imp__ShowCursor@4
$L73673:

; 587  : 		
; 588  : 
; 589  : 		if(x > ChildRect.right)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	cmp	ecx, DWORD PTR [eax+80]
	jle	SHORT $L73674

; 590  : 			x = (short)(ChildRect.right - ChildRect.left) - 5;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+80]
	sub	ecx, DWORD PTR [eax+72]
	movsx	edx, cx
	sub	edx, 5
	mov	DWORD PTR _x$[ebp], edx

; 591  : 		else if(x < ChildRect.left)

	jmp	SHORT $L73678
$L73674:
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	cmp	ecx, DWORD PTR [eax+72]
	jge	SHORT $L73677

; 592  : 			x = 0;

	mov	DWORD PTR _x$[ebp], 0

; 593  : 		else

	jmp	SHORT $L73678
$L73677:

; 594  : 			x = (short)(x - ChildRect.left);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _x$[ebp]
	sub	eax, DWORD PTR [edx+72]
	movsx	ecx, ax
	mov	DWORD PTR _x$[ebp], ecx
$L73678:

; 595  : 
; 596  : 		if(y > ChildRect.bottom)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	cmp	eax, DWORD PTR [edx+84]
	jle	SHORT $L73680

; 597  : 			y = (short)(ChildRect.bottom - ChildRect.top) - 10;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+84]
	sub	eax, DWORD PTR [edx+76]
	movsx	ecx, ax
	sub	ecx, 10					; 0000000aH
	mov	DWORD PTR _y$[ebp], ecx

; 598  : 		else if(y < ChildRect.top)

	jmp	SHORT $L73684
$L73680:
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	cmp	eax, DWORD PTR [edx+76]
	jge	SHORT $L73683

; 599  : 			y = 0;

	mov	DWORD PTR _y$[ebp], 0

; 600  : 		else

	jmp	SHORT $L73684
$L73683:

; 601  : 			y = (short)(y - ChildRect.top);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _y$[ebp]
	sub	edx, DWORD PTR [ecx+76]
	movsx	eax, dx
	mov	DWORD PTR _y$[ebp], eax
$L73684:

; 602  : 
; 603  : 		Mouse.EndX = (x*G_XRES)/xMax;

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 320				; 00000140H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+108]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+102], ax

; 604  : 		Mouse.EndX = (y*G_YRES)/yMax;

	mov	eax, DWORD PTR _y$[ebp]
	imul	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+110]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+102], ax
$L73672:

; 606  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?OnMouseMUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z ENDP		; CONTROLS::OnMouseMUp
_TEXT	ENDS
PUBLIC	?OnKey@CONTROLS@@QAEXPAUHWND__@@IHHI@Z		; CONTROLS::OnKey
;	COMDAT ?OnKey@CONTROLS@@QAEXPAUHWND__@@IHHI@Z
_TEXT	SEGMENT
_this$ = -4
?OnKey@CONTROLS@@QAEXPAUHWND__@@IHHI@Z PROC NEAR	; CONTROLS::OnKey, COMDAT

; 611  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 612  : 	Sys_Loop();

	mov	ecx, DWORD PTR _this$[ebp]
	call	?Sys_Loop@CONTROLS@@QAEXXZ		; CONTROLS::Sys_Loop

; 613  : 	Key_Loop();

	mov	ecx, DWORD PTR _this$[ebp]
	call	?Key_Loop@CONTROLS@@QAEXXZ		; CONTROLS::Key_Loop

; 614  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	20					; 00000014H
?OnKey@CONTROLS@@QAEXPAUHWND__@@IHHI@Z ENDP		; CONTROLS::OnKey
_TEXT	ENDS
PUBLIC	?Controls_ThreadProc@@YGKPAX@Z			; Controls_ThreadProc
;	COMDAT ?Controls_ThreadProc@@YGKPAX@Z
_TEXT	SEGMENT
?Controls_ThreadProc@@YGKPAX@Z PROC NEAR		; Controls_ThreadProc, COMDAT

; 617  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi

; 618  : 	return Val->Controls->Controls_Loop();

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+60]
	call	?Controls_Loop@CONTROLS@@QAE_NXZ	; CONTROLS::Controls_Loop
	and	eax, 255				; 000000ffH

; 619  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?Controls_ThreadProc@@YGKPAX@Z ENDP			; Controls_ThreadProc
_TEXT	ENDS
PUBLIC	?Set_data@CONTROLS@@QAEXUControlVar@@_N@Z	; CONTROLS::Set_data
EXTRN	_memset:NEAR
EXTRN	??2@YAPAXI@Z:NEAR				; operator new
;	COMDAT ?Set_data@CONTROLS@@QAEXUControlVar@@_N@Z
_TEXT	SEGMENT
$T73891 = -12
$T73892 = -16
$T73893 = -20
$T73894 = -24
$T73895 = -28
$T73896 = -32
$T73897 = -36
$T73898 = -40
_cv$ = 8
_load_default$ = 36
_this$ = -4
_n$ = -8
?Set_data@CONTROLS@@QAEXUControlVar@@_N@Z PROC NEAR	; CONTROLS::Set_data, COMDAT

; 622  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 104				; 00000068H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 623  : 	Mouse.show = true;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+106], 1

; 624  : 	Cursor = Val->Display->UseMouse;

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+64]
	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [edx+193]
	mov	BYTE PTR [eax+88], cl

; 625  : 
; 626  : //
; 627  : 	xMax = Val->Display->xMax;

	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	eax, DWORD PTR [edx+64]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	dx, WORD PTR [eax+44]
	mov	WORD PTR [ecx+108], dx

; 628  : 	yMax = Val->Display->yMax;

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+64]
	mov	edx, DWORD PTR _this$[ebp]
	mov	ax, WORD PTR [ecx+46]
	mov	WORD PTR [edx+110], ax

; 629  : //
; 630  : 	memset(&JoyInfo, 0, sizeof(JOYINFOEX));

	push	52					; 00000034H
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 112				; 00000070H
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 631  : 	JoyInfo.dwSize = sizeof(JOYINFOEX);

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+112], 52			; 00000034H

; 632  : 	JoyInfo.dwFlags = JOY_RETURNALL;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+116], 255		; 000000ffH

; 633  : //
; 634  : 	unsigned char n = 0;

	mov	BYTE PTR _n$[ebp], 0

; 635  : 	if(!load_default)

	mov	ecx, DWORD PTR _load_default$[ebp]
	and	ecx, 255				; 000000ffH
	test	ecx, ecx
	jne	$L73705

; 637  : 		cv.NumPlayer = 2;

	mov	BYTE PTR _cv$[ebp+4], 2

; 638  : 
; 639  : 		cv.NumsKey = 3;

	mov	BYTE PTR _cv$[ebp+5], 3

; 640  : 		cv.sKey = new Key[cv.NumsKey];

	mov	edx, DWORD PTR _cv$[ebp+5]
	and	edx, 255				; 000000ffH
	shl	edx, 2
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T73891[ebp], eax
	mov	eax, DWORD PTR $T73891[ebp]
	mov	DWORD PTR _cv$[ebp+8], eax

; 641  : 		memset(cv.sKey, 0, (cv.NumsKey)*sizeof(Key) );

	mov	ecx, DWORD PTR _cv$[ebp+5]
	and	ecx, 255				; 000000ffH
	shl	ecx, 2
	push	ecx
	push	0
	mov	edx, DWORD PTR _cv$[ebp+8]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 642  : 
; 643  : 		cv.sKey[0].Code = VK_ESCAPE;

	mov	eax, DWORD PTR _cv$[ebp+8]
	mov	BYTE PTR [eax], 27			; 0000001bH

; 644  : 		cv.sKey[1].Code = VK_F1;

	mov	ecx, DWORD PTR _cv$[ebp+8]
	mov	BYTE PTR [ecx+4], 112			; 00000070H

; 645  : 		cv.sKey[2].Code = VK_SPACE;

	mov	edx, DWORD PTR _cv$[ebp+8]
	mov	BYTE PTR [edx+8], 32			; 00000020H

; 646  : 
; 647  : 		cv.NumpKey = 8;

	mov	BYTE PTR _cv$[ebp+12], 8

; 648  : 		cv.pKey = new Key[cv.NumpKey];

	mov	eax, DWORD PTR _cv$[ebp+12]
	and	eax, 255				; 000000ffH
	shl	eax, 2
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T73892[ebp], eax
	mov	ecx, DWORD PTR $T73892[ebp]
	mov	DWORD PTR _cv$[ebp+16], ecx

; 649  : 		memset(cv.pKey, 0, (cv.NumpKey)*sizeof(Key) );

	mov	edx, DWORD PTR _cv$[ebp+12]
	and	edx, 255				; 000000ffH
	shl	edx, 2
	push	edx
	push	0
	mov	eax, DWORD PTR _cv$[ebp+16]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 650  : 
; 651  : 		cv.pKey[0].Code = VK_UP;		// Up

	mov	ecx, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [ecx], 38			; 00000026H

; 652  : 		cv.pKey[1].Code = VK_DOWN;	// Down

	mov	edx, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [edx+4], 40			; 00000028H

; 653  : 		cv.pKey[2].Code = VK_LEFT;	// Left

	mov	eax, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [eax+8], 37			; 00000025H

; 654  : 		cv.pKey[3].Code = VK_RIGHT;	// Right

	mov	ecx, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [ecx+12], 39			; 00000027H

; 655  : 		cv.pKey[4].Code = 'Z';			// Button 1

	mov	edx, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [edx+16], 90			; 0000005aH

; 656  : 		cv.pKey[5].Code = 'X';			// Button 2

	mov	eax, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [eax+20], 88			; 00000058H

; 657  : 		cv.pKey[6].Code = 'C';			// Button 3

	mov	ecx, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [ecx+24], 67			; 00000043H

; 658  : 		cv.pKey[7].Code = 'V';			// Button 4

	mov	edx, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [edx+28], 86			; 00000056H

; 659  : 		cv.kPlayerNum = 0;

	mov	BYTE PTR _cv$[ebp+20], 0

; 660  : 
; 661  : 		cv.NumJoy = 2;

	mov	BYTE PTR _cv$[ebp+21], 2

; 662  : 		cv.Joy = new JoyStick[cv.NumJoy];

	mov	eax, DWORD PTR _cv$[ebp+21]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T73893[ebp], eax
	mov	ecx, DWORD PTR $T73893[ebp]
	mov	DWORD PTR _cv$[ebp+24], ecx

; 663  : 		memset(cv.Joy, 0, (cv.NumJoy)*sizeof(JoyStick) );

	mov	edx, DWORD PTR _cv$[ebp+21]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	push	edx
	push	0
	mov	eax, DWORD PTR _cv$[ebp+24]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 664  : 
; 665  : 		cv.Joy[n].Enabled = true;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [edx+ecx], 1

; 666  : 		cv.Joy[n].PlayerNum = 0;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax+1], 0

; 667  : 
; 668  : 		joyGetPosEx(cv.Joy[n].PlayerNum, &JoyInfo );

	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 112				; 00000070H
	push	edx
	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax+1]
	push	edx
	call	DWORD PTR __imp__joyGetPosEx@8

; 669  : 		if(JoyInfo.dwXpos > JOY_DIFF)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+120], 10000		; 00002710H
	jbe	SHORT $L73715

; 670  : 			cv.Joy[n].Horz[0] = (unsigned short)(JoyInfo.dwXpos - JOY_DIFF);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+120]
	sub	edx, 10000				; 00002710H
	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [ecx+eax+2], dx

; 671  : 		else

	jmp	SHORT $L73717
$L73715:

; 672  : 			cv.Joy[n].Horz[0] = 0;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [eax+edx+2], 0
$L73717:

; 673  : 		cv.Joy[n].Horz[1] = (unsigned short)(JoyInfo.dwXpos + JOY_DIFF);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+120]
	add	edx, 10000				; 00002710H
	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [ecx+eax+4], dx

; 674  : 
; 675  : 		if(JoyInfo.dwYpos > JOY_DIFF)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+124], 10000		; 00002710H
	jbe	SHORT $L73719

; 676  : 			cv.Joy[n].Vert[0] = (unsigned short)(JoyInfo.dwYpos - JOY_DIFF);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+124]
	sub	ecx, 10000				; 00002710H
	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [eax+edx+6], cx

; 677  : 		else

	jmp	SHORT $L73721
$L73719:

; 678  : 			cv.Joy[n].Vert[0] = 0;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [edx+ecx+6], 0
$L73721:

; 679  : 		cv.Joy[n].Vert[1] = (unsigned short)(JoyInfo.dwYpos + JOY_DIFF);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+124]
	add	ecx, 10000				; 00002710H
	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [eax+edx+8], cx

; 680  : 
; 681  : 		cv.Joy[n].Button[UP]		= UP;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [edx+ecx+10], 0

; 682  : 		cv.Joy[n].Button[DOWN]	= DOWN;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax+11], 1

; 683  : 		cv.Joy[n].Button[LEFT]	= LEFT;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+12], 2

; 684  : 		cv.Joy[n].Button[RIGHT] = RIGHT;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [edx+ecx+13], 3

; 685  : 		cv.Joy[n].Button[B1]		= B1;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax+14], 4

; 686  : 		cv.Joy[n].Button[B2]		= B2;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+15], 5

; 687  : 		cv.Joy[n].Button[B3]		= B3;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [edx+ecx+16], 6

; 688  : 		cv.Joy[n].Button[B4]		= B4;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax+17], 7

; 689  : 
; 690  : 		n++;

	mov	dl, BYTE PTR _n$[ebp]
	add	dl, 1
	mov	BYTE PTR _n$[ebp], dl

; 691  : 		cv.Joy[n].Enabled = true;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax], 1

; 692  : 		cv.Joy[n].PlayerNum = 1;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+1], 1

; 693  : 
; 694  : 		joyGetPosEx(cv.Joy[n].PlayerNum, &JoyInfo );

	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 112				; 00000070H
	push	ecx
	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx+1]
	push	ecx
	call	DWORD PTR __imp__joyGetPosEx@8

; 695  : 		if(JoyInfo.dwXpos > JOY_DIFF)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+120], 10000		; 00002710H
	jbe	SHORT $L73723

; 696  : 			cv.Joy[n].Horz[0] = (unsigned short)(JoyInfo.dwXpos - JOY_DIFF);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+120]
	sub	ecx, 10000				; 00002710H
	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [eax+edx+2], cx

; 697  : 		else

	jmp	SHORT $L73725
$L73723:

; 698  : 			cv.Joy[n].Horz[0] = 0;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [edx+ecx+2], 0
$L73725:

; 699  : 		cv.Joy[n].Horz[1] = (unsigned short)(JoyInfo.dwXpos + JOY_DIFF);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+120]
	add	ecx, 10000				; 00002710H
	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [eax+edx+4], cx

; 700  : 
; 701  : 		if(JoyInfo.dwYpos > JOY_DIFF)

	mov	ecx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [ecx+124], 10000		; 00002710H
	jbe	SHORT $L73727

; 702  : 			cv.Joy[n].Vert[0] = (unsigned short)(JoyInfo.dwYpos - JOY_DIFF);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+124]
	sub	eax, 10000				; 00002710H
	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [edx+ecx+6], ax

; 703  : 		else

	jmp	SHORT $L73729
$L73727:

; 704  : 			cv.Joy[n].Vert[0] = 0;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [ecx+eax+6], 0
$L73729:

; 705  : 		cv.Joy[n].Vert[1] = (unsigned short)(JoyInfo.dwYpos + JOY_DIFF);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+124]
	add	eax, 10000				; 00002710H
	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [edx+ecx+8], ax

; 706  : 
; 707  : 		cv.Joy[n].Button[UP]		= B1;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax+10], 4

; 708  : 		cv.Joy[n].Button[DOWN]	= B2;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+11], 5

; 709  : 		cv.Joy[n].Button[LEFT]	= B3;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [edx+ecx+12], 6

; 710  : 		cv.Joy[n].Button[RIGHT] = B4;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax+13], 7

; 711  : 		cv.Joy[n].Button[B1]		= LEFT;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+14], 2

; 712  : 		cv.Joy[n].Button[B2]		= RIGHT;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [edx+ecx+15], 3

; 713  : 		cv.Joy[n].Button[B3]		= UP;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax+16], 0

; 714  : 		cv.Joy[n].Button[B4]		= DOWN;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+17], 1

; 716  : 	else

	jmp	$L73731
$L73705:

; 718  : 		cv.NumPlayer = 2;

	mov	BYTE PTR _cv$[ebp+4], 2

; 719  : 
; 720  : 		cv.NumsKey = 3;

	mov	BYTE PTR _cv$[ebp+5], 3

; 721  : 		cv.sKey = new Key[cv.NumsKey];

	mov	ecx, DWORD PTR _cv$[ebp+5]
	and	ecx, 255				; 000000ffH
	shl	ecx, 2
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T73894[ebp], eax
	mov	edx, DWORD PTR $T73894[ebp]
	mov	DWORD PTR _cv$[ebp+8], edx

; 722  : 		memset(cv.sKey, 0, (cv.NumsKey)*sizeof(Key) );

	mov	eax, DWORD PTR _cv$[ebp+5]
	and	eax, 255				; 000000ffH
	shl	eax, 2
	push	eax
	push	0
	mov	ecx, DWORD PTR _cv$[ebp+8]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 723  : 
; 724  : 		cv.sKey[0].Code = VK_ESCAPE;

	mov	edx, DWORD PTR _cv$[ebp+8]
	mov	BYTE PTR [edx], 27			; 0000001bH

; 725  : 		cv.sKey[1].Code = VK_F1;

	mov	eax, DWORD PTR _cv$[ebp+8]
	mov	BYTE PTR [eax+4], 112			; 00000070H

; 726  : 		cv.sKey[2].Code = VK_SPACE;

	mov	ecx, DWORD PTR _cv$[ebp+8]
	mov	BYTE PTR [ecx+8], 32			; 00000020H

; 727  : 
; 728  : 		cv.NumpKey = 8;

	mov	BYTE PTR _cv$[ebp+12], 8

; 729  : 		cv.pKey = new Key[cv.NumpKey];

	mov	edx, DWORD PTR _cv$[ebp+12]
	and	edx, 255				; 000000ffH
	shl	edx, 2
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T73895[ebp], eax
	mov	eax, DWORD PTR $T73895[ebp]
	mov	DWORD PTR _cv$[ebp+16], eax

; 730  : 		memset(cv.pKey, 0, (cv.NumpKey)*sizeof(Key) );

	mov	ecx, DWORD PTR _cv$[ebp+12]
	and	ecx, 255				; 000000ffH
	shl	ecx, 2
	push	ecx
	push	0
	mov	edx, DWORD PTR _cv$[ebp+16]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 731  : 
; 732  : 		cv.pKey[0].Code = VK_UP;		// Up

	mov	eax, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [eax], 38			; 00000026H

; 733  : 		cv.pKey[1].Code = VK_DOWN;	// Down

	mov	ecx, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [ecx+4], 40			; 00000028H

; 734  : 		cv.pKey[2].Code = VK_LEFT;	// Left

	mov	edx, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [edx+8], 37			; 00000025H

; 735  : 		cv.pKey[3].Code = VK_RIGHT;	// Right

	mov	eax, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [eax+12], 39			; 00000027H

; 736  : 		cv.pKey[4].Code = 'Z';			// Button 1

	mov	ecx, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [ecx+16], 90			; 0000005aH

; 737  : 		cv.pKey[5].Code = 'X';			// Button 2

	mov	edx, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [edx+20], 88			; 00000058H

; 738  : 		cv.pKey[6].Code = 'C';			// Button 3

	mov	eax, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [eax+24], 67			; 00000043H

; 739  : 		cv.pKey[7].Code = 'V';			// Button 4

	mov	ecx, DWORD PTR _cv$[ebp+16]
	mov	BYTE PTR [ecx+28], 86			; 00000056H

; 740  : 		cv.kPlayerNum = 0;

	mov	BYTE PTR _cv$[ebp+20], 0

; 741  : 
; 742  : 		cv.NumJoy = 2;

	mov	BYTE PTR _cv$[ebp+21], 2

; 743  : 		cv.Joy = new JoyStick[cv.NumJoy];

	mov	edx, DWORD PTR _cv$[ebp+21]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T73896[ebp], eax
	mov	eax, DWORD PTR $T73896[ebp]
	mov	DWORD PTR _cv$[ebp+24], eax

; 744  : 		memset(cv.Joy, 0, (cv.NumJoy)*sizeof(JoyStick) );

	mov	ecx, DWORD PTR _cv$[ebp+21]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	push	ecx
	push	0
	mov	edx, DWORD PTR _cv$[ebp+24]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 745  : 
; 746  : 		cv.Joy[n].Enabled = true;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax], 1

; 747  : 		cv.Joy[n].PlayerNum = 0;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+1], 0

; 748  : 
; 749  : 		joyGetPosEx(cv.Joy[n].PlayerNum, &JoyInfo );

	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 112				; 00000070H
	push	ecx
	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx+1]
	push	ecx
	call	DWORD PTR __imp__joyGetPosEx@8

; 750  : 		if(JoyInfo.dwXpos > JOY_DIFF)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+120], 10000		; 00002710H
	jbe	SHORT $L73741

; 751  : 			cv.Joy[n].Horz[0] = (unsigned short)(JoyInfo.dwXpos - JOY_DIFF);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+120]
	sub	ecx, 10000				; 00002710H
	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [eax+edx+2], cx

; 752  : 		else

	jmp	SHORT $L73743
$L73741:

; 753  : 			cv.Joy[n].Horz[0] = 0;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [edx+ecx+2], 0
$L73743:

; 754  : 		cv.Joy[n].Horz[1] = (unsigned short)(JoyInfo.dwXpos + JOY_DIFF);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+120]
	add	ecx, 10000				; 00002710H
	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [eax+edx+4], cx

; 755  : 
; 756  : 		if(JoyInfo.dwYpos > JOY_DIFF)

	mov	ecx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [ecx+124], 10000		; 00002710H
	jbe	SHORT $L73745

; 757  : 			cv.Joy[n].Vert[0] = (unsigned short)(JoyInfo.dwYpos - JOY_DIFF);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+124]
	sub	eax, 10000				; 00002710H
	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [edx+ecx+6], ax

; 758  : 		else

	jmp	SHORT $L73747
$L73745:

; 759  : 			cv.Joy[n].Vert[0] = 0;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [ecx+eax+6], 0
$L73747:

; 760  : 		cv.Joy[n].Vert[1] = (unsigned short)(JoyInfo.dwYpos + JOY_DIFF);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+124]
	add	eax, 10000				; 00002710H
	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [edx+ecx+8], ax

; 761  : 
; 762  : 		cv.Joy[n].Button[UP]		= UP;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax+10], 0

; 763  : 		cv.Joy[n].Button[DOWN]	= DOWN;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+11], 1

; 764  : 		cv.Joy[n].Button[LEFT]	= LEFT;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [edx+ecx+12], 2

; 765  : 		cv.Joy[n].Button[RIGHT] = RIGHT;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax+13], 3

; 766  : 		cv.Joy[n].Button[B1]		= B1;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+14], 4

; 767  : 		cv.Joy[n].Button[B2]		= B2;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [edx+ecx+15], 5

; 768  : 		cv.Joy[n].Button[B3]		= B3;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax+16], 6

; 769  : 		cv.Joy[n].Button[B4]		= B4;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+17], 7

; 770  : 
; 771  : 		n++;

	mov	cl, BYTE PTR _n$[ebp]
	add	cl, 1
	mov	BYTE PTR _n$[ebp], cl

; 772  : 		cv.Joy[n].Enabled = true;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx], 1

; 773  : 		cv.Joy[n].PlayerNum = 1;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [edx+ecx+1], 1

; 774  : 
; 775  : 		joyGetPosEx(cv.Joy[n].PlayerNum, &JoyInfo );

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 112				; 00000070H
	push	eax
	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx+1]
	push	eax
	call	DWORD PTR __imp__joyGetPosEx@8

; 776  : 		if(JoyInfo.dwXpos > JOY_DIFF)

	mov	ecx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [ecx+120], 10000		; 00002710H
	jbe	SHORT $L73749

; 777  : 			cv.Joy[n].Horz[0] = (unsigned short)(JoyInfo.dwXpos - JOY_DIFF);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+120]
	sub	eax, 10000				; 00002710H
	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [edx+ecx+2], ax

; 778  : 		else

	jmp	SHORT $L73751
$L73749:

; 779  : 			cv.Joy[n].Horz[0] = 0;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [ecx+eax+2], 0
$L73751:

; 780  : 		cv.Joy[n].Horz[1] = (unsigned short)(JoyInfo.dwXpos + JOY_DIFF);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+120]
	add	eax, 10000				; 00002710H
	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [edx+ecx+4], ax

; 781  : 
; 782  : 		if(JoyInfo.dwYpos > JOY_DIFF)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+124], 10000		; 00002710H
	jbe	SHORT $L73753

; 783  : 			cv.Joy[n].Vert[0] = (unsigned short)(JoyInfo.dwYpos - JOY_DIFF);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+124]
	sub	edx, 10000				; 00002710H
	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [ecx+eax+6], dx

; 784  : 		else

	jmp	SHORT $L73755
$L73753:

; 785  : 			cv.Joy[n].Vert[0] = 0;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [eax+edx+6], 0
$L73755:

; 786  : 		cv.Joy[n].Vert[1] = (unsigned short)(JoyInfo.dwYpos + JOY_DIFF);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+124]
	add	edx, 10000				; 00002710H
	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	WORD PTR [ecx+eax+8], dx

; 787  : 
; 788  : 		cv.Joy[n].Button[UP]		= B1;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+10], 4

; 789  : 		cv.Joy[n].Button[DOWN]	= B2;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [edx+ecx+11], 5

; 790  : 		cv.Joy[n].Button[LEFT]	= B3;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax+12], 6

; 791  : 		cv.Joy[n].Button[RIGHT] = B4;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+13], 7

; 792  : 		cv.Joy[n].Button[B1]		= LEFT;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [edx+ecx+14], 2

; 793  : 		cv.Joy[n].Button[B2]		= RIGHT;

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 18					; 00000012H
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [ecx+eax+15], 3

; 794  : 		cv.Joy[n].Button[B3]		= UP;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 18					; 00000012H
	mov	eax, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [eax+edx+16], 0

; 795  : 		cv.Joy[n].Button[B4]		= DOWN;

	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 18					; 00000012H
	mov	edx, DWORD PTR _cv$[ebp+24]
	mov	BYTE PTR [edx+ecx+17], 1
$L73731:

; 797  : 
; 798  : 	//
; 799  : 		Delay = cv.Delay;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cx, WORD PTR _cv$[ebp]
	mov	WORD PTR [eax+20], cx

; 800  : 		DelayRes = cv.DelayRes;

	mov	edx, DWORD PTR _this$[ebp]
	mov	ax, WORD PTR _cv$[ebp+2]
	mov	WORD PTR [edx+22], ax

; 801  : 
; 802  : 		NumPlayer = cv.NumPlayer;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR _cv$[ebp+4]
	mov	BYTE PTR [ecx+24], dl

; 803  : 
; 804  : 		NumsKey = cv.NumsKey;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR _cv$[ebp+5]
	mov	BYTE PTR [eax+25], cl

; 805  : 		sKey = cv.sKey;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _cv$[ebp+8]
	mov	DWORD PTR [edx+28], eax

; 806  : 
; 807  : 		NumpKey = cv.NumpKey;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR _cv$[ebp+12]
	mov	BYTE PTR [ecx+32], dl

; 808  : 		pKey = cv.pKey;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _cv$[ebp+16]
	mov	DWORD PTR [eax+36], ecx

; 809  : 		kPlayerNum = cv.kPlayerNum;

	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR _cv$[ebp+20]
	mov	BYTE PTR [edx+40], al

; 810  : 
; 811  : 		NumJoy = cv.NumJoy;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR _cv$[ebp+21]
	mov	BYTE PTR [ecx+41], dl

; 812  : 		Joy = cv.Joy;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _cv$[ebp+24]
	mov	DWORD PTR [eax+44], ecx

; 813  : 
; 814  : 		Player = new DBOOL*[NumPlayer];

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+24]
	shl	eax, 2
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T73897[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T73897[ebp]
	mov	DWORD PTR [ecx+48], edx

; 815  : 		memset(Player, 0, (NumPlayer)*sizeof(DBOOL*) );

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+24]
	shl	ecx, 2
	push	ecx
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+48]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 816  : 
; 817  : 		for(j = 0; j < NumPlayer; j++)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+52], 0
	jmp	SHORT $L73760
$L73761:
	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR [edx+52]
	add	al, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+52], al
$L73760:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+52]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+24]
	cmp	eax, edx
	jge	SHORT $L73762

; 819  : 			Player[j] = new DBOOL[NUM_B];

	push	64					; 00000040H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T73898[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+52]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	edx, DWORD PTR $T73898[ebp]
	mov	DWORD PTR [eax+ecx*4], edx

; 820  : 			memset(Player[j], 0, (NUM_B)*sizeof(DBOOL) );

	push	64					; 00000040H
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+52]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	ecx, DWORD PTR [eax+ecx*4]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 821  : 		}

	jmp	SHORT $L73761
$L73762:

; 822  : 
; 823  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	32					; 00000020H
?Set_data@CONTROLS@@QAEXUControlVar@@_N@Z ENDP		; CONTROLS::Set_data
_TEXT	ENDS
END
