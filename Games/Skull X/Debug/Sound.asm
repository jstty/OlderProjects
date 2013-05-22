	TITLE	D:\Game Programming\Moggie Software Games\old code\old Skull X\C++ Files\Sound.cpp
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
;	COMDAT ?Loop@SOUND@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Sound_ThreadProc@@YGKPAX@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Load@SOUND@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?Loop@SOUND@@QAE_NXZ				; SOUND::Loop
PUBLIC	?Loop@TestSpeed@@QAEXXZ				; TestSpeed::Loop
PUBLIC	__real@4@4005c800000000000000
EXTRN	__imp__GetCurrentThread@0:NEAR
EXTRN	__imp__WaitForSingleObject@8:NEAR
EXTRN	?tsSound@@3VTestSpeed@@A:BYTE			; tsSound
EXTRN	__fltused:NEAR
;	COMDAT __real@4@4005c800000000000000
; File d:\game programming\moggie software games\old code\old skull x\c++ files\sound.cpp
CONST	SEGMENT
__real@4@4005c800000000000000 DD 042c80000r	; 100
CONST	ENDS
;	COMDAT ?Loop@SOUND@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
_hThread$ = -8
?Loop@SOUND@@QAE_NXZ PROC NEAR				; SOUND::Loop, COMDAT

; 29   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 30   : 	HANDLE hThread = GetCurrentThread();

	call	DWORD PTR __imp__GetCurrentThread@0
	mov	DWORD PTR _hThread$[ebp], eax
$L65296:

; 31   : //	CRITICAL_SECTION cs;
; 32   : //	InitializeCriticalSection(&cs);
; 33   : 
; 34   : //
; 35   : 	while(ThreadLoop == 0)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 3
	test	ecx, ecx
	jne	SHORT $L65297

; 37   : //		EnterCriticalSection(&cs);
; 38   : //
; 39   : 		#ifdef _DEBUG
; 40   : 				if(tsSound.Rate > 100)

	fld	DWORD PTR ?tsSound@@3VTestSpeed@@A+40
	fcomp	DWORD PTR __real@4@4005c800000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	jne	SHORT $L65298

; 41   : 					return 0;

	xor	al, al
	jmp	SHORT $L65293
$L65298:

; 42   : 
; 43   : 				tsSound.Loop();

	mov	ecx, OFFSET FLAT:?tsSound@@3VTestSpeed@@A
	call	?Loop@TestSpeed@@QAEXXZ			; TestSpeed::Loop

; 44   : 		#endif
; 45   : // Code
; 46   : 
; 47   : 	//	Fx();
; 48   : 	//	Midi();
; 49   : 
; 50   : //
; 51   : //		LeaveCriticalSection(&cs);
; 52   : 		WaitForSingleObject(hThread, Delay);

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+20]
	push	eax
	mov	ecx, DWORD PTR _hThread$[ebp]
	push	ecx
	call	DWORD PTR __imp__WaitForSingleObject@8

; 53   : 	}

	jmp	SHORT $L65296
$L65297:

; 54   : 
; 55   : 	ThreadLoop = 2;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	al, -4					; fffffffcH
	or	al, 2
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+24], eax

; 56   : 	return 0;

	xor	al, al
$L65293:

; 57   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Loop@SOUND@@QAE_NXZ ENDP				; SOUND::Loop
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
	jne	SHORT $L65286

; 60   : 					Start = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+28], 0

; 61   : 					TickCount = Tick1;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR [ecx+32], eax
$L65286:

; 63   : 
; 64   : 				if( (Tick1 - TickCount) > 100)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+16]
	sub	eax, DWORD PTR [edx+32]
	cmp	eax, 100				; 00000064H
	jbe	SHORT $L65287

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
$L65287:

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
PUBLIC	?Sound_ThreadProc@@YGKPAX@Z			; Sound_ThreadProc
EXTRN	?Val@@3PAVVALUES@@A:DWORD			; Val
;	COMDAT ?Sound_ThreadProc@@YGKPAX@Z
_TEXT	SEGMENT
?Sound_ThreadProc@@YGKPAX@Z PROC NEAR			; Sound_ThreadProc, COMDAT

; 62   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi

; 63   : 	return Val->Sound->Loop();

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+72]
	call	?Loop@SOUND@@QAE_NXZ			; SOUND::Loop
	and	eax, 255				; 000000ffH

; 64   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?Sound_ThreadProc@@YGKPAX@Z ENDP			; Sound_ThreadProc
_TEXT	ENDS
PUBLIC	?Load@SOUND@@QAE_NXZ				; SOUND::Load
;	COMDAT ?Load@SOUND@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
?Load@SOUND@@QAE_NXZ PROC NEAR				; SOUND::Load, COMDAT

; 69   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 70   : 	// Init Sound
; 71   : 	/*
; 72   : 		e = CoInitialize(NULL);
; 73   : 
; 74   : 		e = CoCreateInstance(CLSID_DirectMusicLoader, NULL, CLSCTX_INPROC, IID_IDirectMusicLoader, (void**)&dmLoader);
; 75   : 
; 76   : 		e = CoCreateInstance(CLSID_DirectMusicPerformance, NULL, CLSCTX_INPROC, IID_IDirectMusicPerformance, (void**)&dmPerf);
; 77   : 
; 78   : 		e = InitializeSynth();
; 79   : 
; 80   : 		e = LoadSegment(0);
; 81   : 
; 82   : 		dmSeg->SetRepeats(200);
; 83   : 
; 84   : 		GUID guid = GUID_IDirectMusicStyle;
; 85   : 		e = g_pSegment->GetParam( guid, 0xffffffff, 0, 0, NULL, (void*)&g_pStyle );
; 86   : 	*/
; 87   : 
; 88   : 	return 0;

	xor	al, al

; 89   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Load@SOUND@@QAE_NXZ ENDP				; SOUND::Load
_TEXT	ENDS
END
