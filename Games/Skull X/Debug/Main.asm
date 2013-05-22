	TITLE	D:\Game Programming\Moggie Software Games\old code\old Skull X\C++ Files\Main.cpp
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
_BSS	SEGMENT PARA USE32 PUBLIC 'BSS'
_BSS	ENDS
$$SYMBOLS	SEGMENT BYTE USE32 'DEBSYM'
$$SYMBOLS	ENDS
$$TYPES	SEGMENT BYTE USE32 'DEBTYP'
$$TYPES	ENDS
_TLS	SEGMENT DWORD USE32 PUBLIC 'TLS'
_TLS	ENDS
;	COMDAT ??_C@_0BB@NAAD@Magellan?5MSWHEEL?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_06FPAF@MouseZ?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BA@CLBL@MSWHEEL_ROLLMSG?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@DLPD@MSH_WHEELSUPPORT_MSG?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@ODOJ@MSH_SCROLL_LINES_MSG?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EE@LGAC@c?3?2program?5files?2microsoft?5visua@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
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
;	COMDAT ??_C@_0M@EEDH@Main?5Window?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0N@PNLA@Child?5Window?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@EBLG@?$CFs?3?$CFs?9?$DOError?5?$DN?5?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BO@MCCM@Could?5not?5recover?5from?5error?4?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05IMKO@Start?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_09OFON@LevelProc?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_03BGOI@dll?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@OKAL@?$CFs?2levels?2level?$CF0?43d?4?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@NKK@Could?5not?5load?5file?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@HJCJ@MAIN?3LoadLibrary?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@MLGD@LoadDefaultVar?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@OIOL@Level?5incorrect?5Version?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@ENHG@MAIN?3LevelProc?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BJ@IFHB@?$CFs?3?6?5?$CFs?4?6?5Error?5?$DN?5?$CFd?0?5?$CFd?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BO@MACO@Could?5not?5find?5LoadDefaultVar?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@CEKK@MAIN?3GetProcAddress?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_09FHA@LevelCode?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BJ@CKEK@Could?5not?5find?5LevelCode?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
CRT$XCA	SEGMENT DWORD USE32 PUBLIC 'DATA'
CRT$XCA	ENDS
CRT$XCU	SEGMENT DWORD USE32 PUBLIC 'DATA'
CRT$XCU	ENDS
CRT$XCL	SEGMENT DWORD USE32 PUBLIC 'DATA'
CRT$XCL	ENDS
CRT$XCC	SEGMENT DWORD USE32 PUBLIC 'DATA'
CRT$XCC	ENDS
CRT$XCZ	SEGMENT DWORD USE32 PUBLIC 'DATA'
CRT$XCZ	ENDS
;	COMDAT ?GetNextPtr@CSimpleList@@QBEPAPAXPAX@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ??1CNoTrackObject@@UAE@XZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ??_GCNoTrackObject@@UAEPAXI@Z
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
;	COMDAT ?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z
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
;	COMDAT ?LoadAll@VALUES@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?FreeAll@VALUES@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?InitObjects@VALUES@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CreateLoops@VALUES@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?StartLoops@VALUES@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?sLoop@VALUES@@QAE_NAAPAXPAD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ??0TestSpeed@@QAE@XZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Loop@TestSpeed@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _$E28
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _$E29
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _$E31
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _$E32
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _$E34
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _$E35
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _$E37
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _$E38
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _$E40
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _$E41
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT _WinMain@16
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Register@MAIN@@QAEHPAUHINSTANCE__@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Create@MAIN@@QAEPAUHWND__@@PAUHINSTANCE__@@H@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Main_WindowProc@@YGJPAUHWND__@@IIJ@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Main_Create@MAIN@@QAEHPAUHWND__@@PAUtagCREATESTRUCTA@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CreateChildWindow@MAIN@@QAEXPAUHWND__@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Main_Paint@MAIN@@QAEXPAUHWND__@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Main_Move@MAIN@@QAEXPAUHWND__@@HH@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Main_Activate@MAIN@@QAEXPAUHWND__@@I0H@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Child_WindowProc@@YGJPAUHWND__@@IIJ@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Child_Create@MAIN@@QAEHPAUHWND__@@PAUtagCREATESTRUCTA@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Child_Destroy@MAIN@@QAEXPAUHWND__@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Child_Paint@MAIN@@QAEXPAUHWND__@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Start@MAIN@@QAEXPAUHWND__@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Loop@MAIN@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Main_Destroy@MAIN@@QAEXPAUHWND__@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?End@@YAXPAUHWND__@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Main_ThreadProc@@YGKPAX@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Load@MAIN@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ??_7CNoTrackObject@@6B@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
FLAT	GROUP _DATA, CONST, _BSS, CRT$XCA, CRT$XCU, CRT$XCL, CRT$XCC, CRT$XCZ
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?Val@@3PAVVALUES@@A				; Val
PUBLIC	?hVal@@3PAXA					; hVal
PUBLIC	?Debug@@3VDEBUGCLASS@@A				; Debug
PUBLIC	?tsMain@@3VTestSpeed@@A				; tsMain
PUBLIC	?tsDisplay@@3VTestSpeed@@A			; tsDisplay
PUBLIC	?tsControls@@3VTestSpeed@@A			; tsControls
PUBLIC	?tsAction@@3VTestSpeed@@A			; tsAction
PUBLIC	?tsSound@@3VTestSpeed@@A			; tsSound
_BSS	SEGMENT
?Val@@3PAVVALUES@@A DD 01H DUP (?)			; Val
?hVal@@3PAXA DD	01H DUP (?)				; hVal
?Debug@@3VDEBUGCLASS@@A DB 024H DUP (?)			; Debug
?tsMain@@3VTestSpeed@@A DB 02cH DUP (?)			; tsMain
?tsDisplay@@3VTestSpeed@@A DB 02cH DUP (?)		; tsDisplay
?tsControls@@3VTestSpeed@@A DB 02cH DUP (?)		; tsControls
?tsAction@@3VTestSpeed@@A DB 02cH DUP (?)		; tsAction
?tsSound@@3VTestSpeed@@A DB 02cH DUP (?)		; tsSound
_BSS	ENDS
CRT$XCU	SEGMENT
_$S30	DD	FLAT:_$E29
_$S33	DD	FLAT:_$E32
_$S36	DD	FLAT:_$E35
_$S39	DD	FLAT:_$E38
_$S42	DD	FLAT:_$E41
CRT$XCU	ENDS
;	COMDAT _$E29
_TEXT	SEGMENT
_$E29	PROC NEAR					; COMDAT
	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi
	call	_$E28
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_$E29	ENDP
_TEXT	ENDS
PUBLIC	??0TestSpeed@@QAE@XZ				; TestSpeed::TestSpeed
;	COMDAT _$E28
_TEXT	SEGMENT
_$E28	PROC NEAR					; COMDAT

; 43   : 	TestSpeed tsMain;

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi
	mov	ecx, OFFSET FLAT:?tsMain@@3VTestSpeed@@A
	call	??0TestSpeed@@QAE@XZ			; TestSpeed::TestSpeed
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_$E28	ENDP
_TEXT	ENDS
PUBLIC	??_C@_0DJ@MEEM@?$CFs?5?$HM?$HM?5Time?5?$DN?5?$CFf?0?5Count?5?$DN?5?$CFd?0?5Mai@ ; `string'
PUBLIC	?SetError_Format@ERRORCLASS@@QAEXPAD@Z		; ERRORCLASS::SetError_Format
EXTRN	__fltused:NEAR
;	COMDAT ??_C@_0DJ@MEEM@?$CFs?5?$HM?$HM?5Time?5?$DN?5?$CFf?0?5Count?5?$DN?5?$CFd?0?5Mai@
; File d:\game programming\moggie software games\old code\old skull x\header files\testspeed.h
CONST	SEGMENT
??_C@_0DJ@MEEM@?$CFs?5?$HM?$HM?5Time?5?$DN?5?$CFf?0?5Count?5?$DN?5?$CFd?0?5Mai@ DB '%'
	DB	's || Time = %f, Count = %d, MainRate = %f, ForRate = %f', 00H ; `string'
CONST	ENDS
;	COMDAT ??0TestSpeed@@QAE@XZ
_TEXT	SEGMENT
_this$ = -4
??0TestSpeed@@QAE@XZ PROC NEAR				; TestSpeed::TestSpeed, COMDAT

; 30   : 			TestSpeed()

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 31   : 			{
; 32   : 				Rate = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+40], 0

; 33   : 				LoopCount = 0;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+24], 0

; 34   : 				Start = 1;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+28], 1

; 35   : 				TickCount = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+32], 0

; 36   : 				ForLoop = 0;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+36], 0

; 37   : 				SetError_Format("%s || Time = %f, Count = %d, MainRate = %f, ForRate = %f");

	push	OFFSET FLAT:??_C@_0DJ@MEEM@?$CFs?5?$HM?$HM?5Time?5?$DN?5?$CFf?0?5Count?5?$DN?5?$CFd?0?5Mai@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetError_Format@ERRORCLASS@@QAEXPAD@Z	; ERRORCLASS::SetError_Format

; 38   : 			};

	mov	eax, DWORD PTR _this$[ebp]
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
??0TestSpeed@@QAE@XZ ENDP				; TestSpeed::TestSpeed
_TEXT	ENDS
;	COMDAT _$E32
_TEXT	SEGMENT
_$E32	PROC NEAR					; COMDAT
	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi
	call	_$E31
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_$E32	ENDP
_TEXT	ENDS
;	COMDAT _$E31
_TEXT	SEGMENT
_$E31	PROC NEAR					; COMDAT

; 44   : 	TestSpeed tsDisplay;

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi
	mov	ecx, OFFSET FLAT:?tsDisplay@@3VTestSpeed@@A
	call	??0TestSpeed@@QAE@XZ			; TestSpeed::TestSpeed
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_$E31	ENDP
_TEXT	ENDS
;	COMDAT _$E35
_TEXT	SEGMENT
_$E35	PROC NEAR					; COMDAT
	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi
	call	_$E34
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_$E35	ENDP
_TEXT	ENDS
;	COMDAT _$E34
_TEXT	SEGMENT
_$E34	PROC NEAR					; COMDAT

; 45   : 	TestSpeed tsControls;

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi
	mov	ecx, OFFSET FLAT:?tsControls@@3VTestSpeed@@A
	call	??0TestSpeed@@QAE@XZ			; TestSpeed::TestSpeed
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_$E34	ENDP
_TEXT	ENDS
;	COMDAT _$E38
_TEXT	SEGMENT
_$E38	PROC NEAR					; COMDAT
	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi
	call	_$E37
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_$E38	ENDP
_TEXT	ENDS
;	COMDAT _$E37
_TEXT	SEGMENT
_$E37	PROC NEAR					; COMDAT

; 46   : 	TestSpeed tsAction;

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi
	mov	ecx, OFFSET FLAT:?tsAction@@3VTestSpeed@@A
	call	??0TestSpeed@@QAE@XZ			; TestSpeed::TestSpeed
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_$E37	ENDP
_TEXT	ENDS
;	COMDAT _$E41
_TEXT	SEGMENT
_$E41	PROC NEAR					; COMDAT
	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi
	call	_$E40
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_$E41	ENDP
_TEXT	ENDS
;	COMDAT _$E40
_TEXT	SEGMENT
_$E40	PROC NEAR					; COMDAT

; 47   : 	TestSpeed tsSound;

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi
	mov	ecx, OFFSET FLAT:?tsSound@@3VTestSpeed@@A
	call	??0TestSpeed@@QAE@XZ			; TestSpeed::TestSpeed
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_$E40	ENDP
_TEXT	ENDS
PUBLIC	?Register@MAIN@@QAEHPAUHINSTANCE__@@@Z		; MAIN::Register
PUBLIC	?Create@MAIN@@QAEPAUHWND__@@PAUHINSTANCE__@@H@Z	; MAIN::Create
PUBLIC	_WinMain@16
PUBLIC	?LoadAll@VALUES@@QAE_NXZ			; VALUES::LoadAll
EXTRN	__imp__TranslateMessage@4:NEAR
EXTRN	__imp__DispatchMessageA@4:NEAR
EXTRN	__imp__GetLastError@0:NEAR
EXTRN	__imp__SetLastError@4:NEAR
EXTRN	_srand:NEAR
EXTRN	_time:NEAR
EXTRN	__imp__GlobalAlloc@8:NEAR
EXTRN	__imp__GlobalLock@4:NEAR
EXTRN	__imp__GetMessageA@16:NEAR
;	COMDAT _WinMain@16
_TEXT	SEGMENT
_hInst$ = 8
_hPrevInst$ = 12
_nCmdShow$ = 20
_Msg$ = -28
_WinMain@16 PROC NEAR					; COMDAT

; 60   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 92					; 0000005cH
	push	ebx
	push	esi
	push	edi

; 61   : 	SetLastError(0);

	push	0
	call	DWORD PTR __imp__SetLastError@4

; 62   : 	srand( (unsigned int)time(NULL) );

	push	0
	call	_time
	add	esp, 4
	push	eax
	call	_srand
	add	esp, 4

; 63   : 
; 64   : 	hVal = GlobalAlloc(GHND, sizeof(VALUES) );

	push	80					; 00000050H
	push	66					; 00000042H
	call	DWORD PTR __imp__GlobalAlloc@8
	mov	DWORD PTR ?hVal@@3PAXA, eax		; hVal

; 65   : 	if(GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L67192

; 66   : 		return FALSE;

	xor	eax, eax
	jmp	$L67189
$L67192:

; 67   : 
; 68   : 	Val = (VALUES*)GlobalLock(hVal);

	mov	eax, DWORD PTR ?hVal@@3PAXA		; hVal
	push	eax
	call	DWORD PTR __imp__GlobalLock@4
	mov	DWORD PTR ?Val@@3PAVVALUES@@A, eax	; Val

; 69   : 	if(GetLastError() != 0)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L67194

; 70   : 		return FALSE;

	xor	eax, eax
	jmp	SHORT $L67189
$L67194:

; 71   : 
; 72   : 	Val->LoadAll();

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	call	?LoadAll@VALUES@@QAE_NXZ		; VALUES::LoadAll

; 73   : 
; 74   : //
; 75   :   if(hPrevInst)

	cmp	DWORD PTR _hPrevInst$[ebp], 0
	je	SHORT $L67195

; 76   :     return FALSE;

	xor	eax, eax
	jmp	SHORT $L67189
$L67195:

; 78   :     if(!Val->Main->Register(hInst))

	mov	ecx, DWORD PTR _hInst$[ebp]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+56]
	call	?Register@MAIN@@QAEHPAUHINSTANCE__@@@Z	; MAIN::Register
	test	eax, eax
	jne	SHORT $L67197

; 79   :       return FALSE;

	xor	eax, eax
	jmp	SHORT $L67189
$L67197:

; 80   : 
; 81   :   if(!Val->Main->Create(hInst, nCmdShow))

	mov	eax, DWORD PTR _nCmdShow$[ebp]
	push	eax
	mov	ecx, DWORD PTR _hInst$[ebp]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+56]
	call	?Create@MAIN@@QAEPAUHWND__@@PAUHINSTANCE__@@H@Z ; MAIN::Create
	test	eax, eax
	jne	SHORT $L67198

; 82   :     return FALSE;

	xor	eax, eax
	jmp	SHORT $L67189
$L67198:

; 85   :   while(GetMessage(&Msg, NULL, 0, 0))

	push	0
	push	0
	push	0
	lea	eax, DWORD PTR _Msg$[ebp]
	push	eax
	call	DWORD PTR __imp__GetMessageA@16
	test	eax, eax
	je	SHORT $L67202

; 87   :      TranslateMessage(&Msg);

	lea	ecx, DWORD PTR _Msg$[ebp]
	push	ecx
	call	DWORD PTR __imp__TranslateMessage@4

; 88   :      DispatchMessage(&Msg);

	lea	edx, DWORD PTR _Msg$[ebp]
	push	edx
	call	DWORD PTR __imp__DispatchMessageA@4

; 89   :   }

	jmp	SHORT $L67198
$L67202:

; 90   : 
; 91   :   return Msg.wParam;

	mov	eax, DWORD PTR _Msg$[ebp+8]
$L67189:

; 92   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
_WinMain@16 ENDP
_TEXT	ENDS
PUBLIC	?Main_WindowProc@@YGJPAUHWND__@@IIJ@Z		; Main_WindowProc
PUBLIC	?Child_WindowProc@@YGJPAUHWND__@@IIJ@Z		; Child_WindowProc
PUBLIC	??_C@_0M@EEDH@Main?5Window?$AA@			; `string'
PUBLIC	??_C@_0N@PNLA@Child?5Window?$AA@		; `string'
PUBLIC	?InitObjects@VALUES@@QAEXXZ			; VALUES::InitObjects
EXTRN	__imp__LoadCursorA@8:NEAR
EXTRN	__imp__RegisterClassA@4:NEAR
EXTRN	__imp__LoadIconA@8:NEAR
EXTRN	__imp__CreateSolidBrush@4:NEAR
;	COMDAT ??_C@_0M@EEDH@Main?5Window?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\main.cpp
CONST	SEGMENT
??_C@_0M@EEDH@Main?5Window?$AA@ DB 'Main Window', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0N@PNLA@Child?5Window?$AA@
CONST	SEGMENT
??_C@_0N@PNLA@Child?5Window?$AA@ DB 'Child Window', 00H	; `string'
CONST	ENDS
;	COMDAT ?Register@MAIN@@QAEHPAUHINSTANCE__@@@Z
_TEXT	SEGMENT
_hInst$ = 8
_this$ = -4
_WndClass$ = -44
?Register@MAIN@@QAEHPAUHINSTANCE__@@@Z PROC NEAR	; MAIN::Register, COMDAT

; 97   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 108				; 0000006cH
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 98   : 	Val->InitObjects();

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	call	?InitObjects@VALUES@@QAEXXZ		; VALUES::InitObjects

; 99   : 	Closing = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+36], 0

; 100  : 
; 101  :   WNDCLASS WndClass;
; 102  : 
; 103  :   WndClass.style          = CS_HREDRAW | CS_VREDRAW;

	mov	DWORD PTR _WndClass$[ebp], 3

; 104  :   WndClass.lpfnWndProc    = Main_WindowProc;

	mov	DWORD PTR _WndClass$[ebp+4], OFFSET FLAT:?Main_WindowProc@@YGJPAUHWND__@@IIJ@Z ; Main_WindowProc

; 105  :   WndClass.cbClsExtra     = 0;

	mov	DWORD PTR _WndClass$[ebp+8], 0

; 106  :   WndClass.cbWndExtra     = 0;

	mov	DWORD PTR _WndClass$[ebp+12], 0

; 107  :   WndClass.hInstance      = hInst;

	mov	ecx, DWORD PTR _hInst$[ebp]
	mov	DWORD PTR _WndClass$[ebp+16], ecx

; 108  :   WndClass.hIcon          = LoadIcon(hInst, MAKEINTRESOURCE(IDI_MAIN));

	push	101					; 00000065H
	mov	edx, DWORD PTR _hInst$[ebp]
	push	edx
	call	DWORD PTR __imp__LoadIconA@8
	mov	DWORD PTR _WndClass$[ebp+20], eax

; 109  :   WndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);

	push	32512					; 00007f00H
	push	0
	call	DWORD PTR __imp__LoadCursorA@8
	mov	DWORD PTR _WndClass$[ebp+24], eax

; 110  :   WndClass.hbrBackground  = CreateSolidBrush(RGB(32, 32, 32));

	push	2105376					; 00202020H
	call	DWORD PTR __imp__CreateSolidBrush@4
	mov	DWORD PTR _WndClass$[ebp+28], eax

; 111  :   WndClass.lpszMenuName   = NULL;

	mov	DWORD PTR _WndClass$[ebp+32], 0

; 112  :   WndClass.lpszClassName  = MAINWINDOW;

	mov	DWORD PTR _WndClass$[ebp+36], OFFSET FLAT:??_C@_0M@EEDH@Main?5Window?$AA@ ; `string'

; 113  : 	RegisterClass (&WndClass);

	lea	eax, DWORD PTR _WndClass$[ebp]
	push	eax
	call	DWORD PTR __imp__RegisterClassA@4

; 114  : 
; 115  : 	WndClass.lpfnWndProc    = Child_WindowProc;

	mov	DWORD PTR _WndClass$[ebp+4], OFFSET FLAT:?Child_WindowProc@@YGJPAUHWND__@@IIJ@Z ; Child_WindowProc

; 116  : 	WndClass.cbWndExtra     = sizeof(WORD);

	mov	DWORD PTR _WndClass$[ebp+12], 2

; 117  : 	WndClass.hIcon          = LoadIcon(hInst, MAKEINTRESOURCE(IDI_MAIN));

	push	101					; 00000065H
	mov	ecx, DWORD PTR _hInst$[ebp]
	push	ecx
	call	DWORD PTR __imp__LoadIconA@8
	mov	DWORD PTR _WndClass$[ebp+20], eax

; 118  : 	WndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);

	push	32512					; 00007f00H
	push	0
	call	DWORD PTR __imp__LoadCursorA@8
	mov	DWORD PTR _WndClass$[ebp+24], eax

; 119  :   WndClass.hbrBackground  = CreateSolidBrush(RGB(32, 32, 32));

	push	2105376					; 00202020H
	call	DWORD PTR __imp__CreateSolidBrush@4
	mov	DWORD PTR _WndClass$[ebp+28], eax

; 120  :   WndClass.lpszMenuName   = NULL;

	mov	DWORD PTR _WndClass$[ebp+32], 0

; 121  :   WndClass.lpszClassName  = CHILDWINDOW;

	mov	DWORD PTR _WndClass$[ebp+36], OFFSET FLAT:??_C@_0N@PNLA@Child?5Window?$AA@ ; `string'

; 122  :   return RegisterClass (&WndClass);

	lea	edx, DWORD PTR _WndClass$[ebp]
	push	edx
	call	DWORD PTR __imp__RegisterClassA@4
	and	eax, 65535				; 0000ffffH

; 123  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?Register@MAIN@@QAEHPAUHINSTANCE__@@@Z ENDP		; MAIN::Register
_TEXT	ENDS
EXTRN	__imp__GetSystemMenu@8:NEAR
EXTRN	__imp__DeleteMenu@12:NEAR
EXTRN	__imp__CreateWindowExA@48:NEAR
EXTRN	__imp__ShowWindow@8:NEAR
EXTRN	__imp__UpdateWindow@4:NEAR
EXTRN	__imp__GetSystemMetrics@4:NEAR
EXTRN	?SetGlobal@VALUES@@QAEXXZ:NEAR			; VALUES::SetGlobal
;	COMDAT ?Create@MAIN@@QAEPAUHWND__@@PAUHINSTANCE__@@H@Z
_TEXT	SEGMENT
_hInst$ = 8
_Show$ = 12
_this$ = -4
_x$ = -8
_y$ = -12
_w$ = -16
_h$ = -20
_Style$ = -24
_MainHwnd$ = -28
?Create@MAIN@@QAEPAUHWND__@@PAUHINSTANCE__@@H@Z PROC NEAR ; MAIN::Create, COMDAT

; 128  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 92					; 0000005cH
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 129  : 	MainhInst =  hInst;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _hInst$[ebp]
	mov	DWORD PTR [eax+92], ecx

; 130  : 
; 131  : 	Val->SetGlobal();

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	call	?SetGlobal@VALUES@@QAEXXZ		; VALUES::SetGlobal

; 132  : 
; 133  : 	xMax = Val->Display->xMax;

	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	eax, DWORD PTR [edx+64]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	dx, WORD PTR [eax+44]
	mov	WORD PTR [ecx+68], dx

; 134  : 	yMax = Val->Display->yMax;

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+64]
	mov	edx, DWORD PTR _this$[ebp]
	mov	ax, WORD PTR [ecx+46]
	mov	WORD PTR [edx+70], ax

; 135  : 	
; 136  : 	__int16  x, y;
; 137  : 	unsigned __int16  w, h;
; 138  : 	if(data.FullScreen)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+58]
	test	edx, edx
	je	SHORT $L67244

; 140  : 		x = 0;

	mov	WORD PTR _x$[ebp], 0

; 141  : 		y = 0;

	mov	WORD PTR _y$[ebp], 0

; 142  : 		w = GetSystemMetrics(SM_CXSCREEN);

	push	0
	call	DWORD PTR __imp__GetSystemMetrics@4
	mov	WORD PTR _w$[ebp], ax

; 143  : 		h = GetSystemMetrics(SM_CYSCREEN);

	push	1
	call	DWORD PTR __imp__GetSystemMetrics@4
	mov	WORD PTR _h$[ebp], ax

; 145  : 	else

	jmp	$L67249
$L67244:

; 147  : 	 // Xmax/2 - (w + 2)/2
; 148  : 		x = ( ( GetSystemMetrics(SM_CXSCREEN) - xMax) >> 1) - (GetSystemMetrics(SM_CXFIXEDFRAME) << 2);

	push	0
	call	DWORD PTR __imp__GetSystemMetrics@4
	mov	esi, eax
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+68]
	sub	esi, ecx
	sar	esi, 1
	push	7
	call	DWORD PTR __imp__GetSystemMetrics@4
	shl	eax, 2
	sub	esi, eax
	mov	WORD PTR _x$[ebp], si

; 149  : 		y = ( ( GetSystemMetrics(SM_CYSCREEN) - yMax) >> 1) - (GetSystemMetrics(SM_CYFIXEDFRAME) << 2) - GetSystemMetrics(SM_CYCAPTION);

	push	1
	call	DWORD PTR __imp__GetSystemMetrics@4
	mov	esi, eax
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+70]
	sub	esi, eax
	sar	esi, 1
	push	8
	call	DWORD PTR __imp__GetSystemMetrics@4
	shl	eax, 2
	sub	esi, eax
	push	4
	call	DWORD PTR __imp__GetSystemMetrics@4
	sub	esi, eax
	mov	WORD PTR _y$[ebp], si

; 150  : 		w = xMax + 10;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+68]
	add	edx, 10					; 0000000aH
	mov	WORD PTR _w$[ebp], dx

; 151  : 		h = yMax + 10 + GetSystemMetrics(SM_CYCAPTION);

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+70]
	mov	esi, ecx
	push	4
	call	DWORD PTR __imp__GetSystemMetrics@4
	lea	edx, DWORD PTR [esi+eax+10]
	mov	WORD PTR _h$[ebp], dx

; 152  : 
; 153  : 		if(w > GetSystemMetrics(SM_CXSCREEN))

	mov	esi, DWORD PTR _w$[ebp]
	and	esi, 65535				; 0000ffffH
	push	0
	call	DWORD PTR __imp__GetSystemMetrics@4
	cmp	esi, eax
	jle	SHORT $L67246

; 155  : 			x = 0;

	mov	WORD PTR _x$[ebp], 0

; 156  : 			w = GetSystemMetrics(SM_CXSCREEN);

	push	0
	call	DWORD PTR __imp__GetSystemMetrics@4
	mov	WORD PTR _w$[ebp], ax
$L67246:

; 158  : 		if(h > GetSystemMetrics(SM_CYSCREEN))

	mov	esi, DWORD PTR _h$[ebp]
	and	esi, 65535				; 0000ffffH
	push	1
	call	DWORD PTR __imp__GetSystemMetrics@4
	cmp	esi, eax
	jle	SHORT $L67247

; 160  : 			y = 0;

	mov	WORD PTR _y$[ebp], 0

; 161  : 			h = GetSystemMetrics(SM_CYSCREEN);

	push	1
	call	DWORD PTR __imp__GetSystemMetrics@4
	mov	WORD PTR _h$[ebp], ax
$L67247:

; 163  : 
; 164  : 		if(x < 0)

	movsx	eax, WORD PTR _x$[ebp]
	test	eax, eax
	jge	SHORT $L67248

; 165  : 			x = 0;

	mov	WORD PTR _x$[ebp], 0
$L67248:

; 166  : 		if(y < 0)

	movsx	ecx, WORD PTR _y$[ebp]
	test	ecx, ecx
	jge	SHORT $L67249

; 167  : 			y = 0;

	mov	WORD PTR _y$[ebp], 0
$L67249:

; 170  : 
; 171  : 	DWORD Style;
; 172  : 	if(!data.InWindow)

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+57]
	test	eax, eax
	jne	SHORT $L67251

; 173  : 		Style = WS_POPUPWINDOW;

	mov	DWORD PTR _Style$[ebp], -2138570752	; 80880000H

; 174  : 	else

	jmp	SHORT $L67252
$L67251:

; 175  : 		Style = WS_SYSMENU | WS_CAPTION |WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_VISIBLE;

	mov	DWORD PTR _Style$[ebp], 281739264	; 10cb0000H
$L67252:

; 176  : 		
; 177  : 	HWND MainHwnd = CreateWindow(MAINWINDOW, MAINWINDOW,
; 178  : 													Style,	x,	y,	w,	h,
; 179  : 													NULL, NULL, hInst, NULL);

	push	0
	mov	ecx, DWORD PTR _hInst$[ebp]
	push	ecx
	push	0
	push	0
	mov	edx, DWORD PTR _h$[ebp]
	and	edx, 65535				; 0000ffffH
	push	edx
	mov	eax, DWORD PTR _w$[ebp]
	and	eax, 65535				; 0000ffffH
	push	eax
	movsx	ecx, WORD PTR _y$[ebp]
	push	ecx
	movsx	edx, WORD PTR _x$[ebp]
	push	edx
	mov	eax, DWORD PTR _Style$[ebp]
	push	eax
	push	OFFSET FLAT:??_C@_0M@EEDH@Main?5Window?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_0M@EEDH@Main?5Window?$AA@ ; `string'
	push	0
	call	DWORD PTR __imp__CreateWindowExA@48
	mov	DWORD PTR _MainHwnd$[ebp], eax

; 180  : 
; 181  : 	if(!data.InWindow)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+57]
	test	edx, edx
	jne	SHORT $L67254

; 182  : 		DeleteMenu(GetSystemMenu(MainHwnd, FALSE),  SC_MOVE, MF_BYCOMMAND);

	push	0
	push	61456					; 0000f010H
	push	0
	mov	eax, DWORD PTR _MainHwnd$[ebp]
	push	eax
	call	DWORD PTR __imp__GetSystemMenu@8
	push	eax
	call	DWORD PTR __imp__DeleteMenu@12
$L67254:

; 183  : 
; 184  : 	DeleteMenu(GetSystemMenu(MainHwnd, FALSE),  SC_SIZE, MF_BYCOMMAND);

	push	0
	push	61440					; 0000f000H
	push	0
	mov	ecx, DWORD PTR _MainHwnd$[ebp]
	push	ecx
	call	DWORD PTR __imp__GetSystemMenu@8
	push	eax
	call	DWORD PTR __imp__DeleteMenu@12

; 185  : 
; 186  : 	if (MainHwnd == NULL)

	cmp	DWORD PTR _MainHwnd$[ebp], 0
	jne	SHORT $L67255

; 187  :      return MainHwnd;

	mov	eax, DWORD PTR _MainHwnd$[ebp]
	jmp	SHORT $L67239
$L67255:

; 188  :   
; 189  : 
; 190  : 	if(!data.InWindow)

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+57]
	test	eax, eax
	jne	SHORT $L67256

; 191  : 		Style = Show | SW_SHOWMAXIMIZED;

	mov	ecx, DWORD PTR _Show$[ebp]
	or	ecx, 3
	mov	DWORD PTR _Style$[ebp], ecx

; 192  : 	else

	jmp	SHORT $L67257
$L67256:

; 193  : 		Style = Show;

	mov	edx, DWORD PTR _Show$[ebp]
	mov	DWORD PTR _Style$[ebp], edx
$L67257:

; 194  : 
; 195  :   ShowWindow(MainHwnd, Style);

	mov	eax, DWORD PTR _Style$[ebp]
	push	eax
	mov	ecx, DWORD PTR _MainHwnd$[ebp]
	push	ecx
	call	DWORD PTR __imp__ShowWindow@8

; 196  :   UpdateWindow(MainHwnd);

	mov	edx, DWORD PTR _MainHwnd$[ebp]
	push	edx
	call	DWORD PTR __imp__UpdateWindow@4

; 197  : 
; 198  :   return MainHwnd;

	mov	eax, DWORD PTR _MainHwnd$[ebp]
$L67239:

; 199  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?Create@MAIN@@QAEPAUHWND__@@PAUHINSTANCE__@@H@Z ENDP	; MAIN::Create
_TEXT	ENDS
PUBLIC	??_C@_00A@?$AA@					; `string'
EXTRN	??2@YAPAXI@Z:NEAR				; operator new
EXTRN	_strcpy:NEAR
EXTRN	_strlen:NEAR
;	COMDAT ??_C@_00A@?$AA@
; File d:\game programming\moggie software games\old code\old skull x\header files\errorclass.h
CONST	SEGMENT
??_C@_00A@?$AA@ DB 00H					; `string'
CONST	ENDS
;	COMDAT ?SetError_Format@ERRORCLASS@@QAEXPAD@Z
_TEXT	SEGMENT
$T67756 = -8
$T67757 = -12
$T67758 = -16
_m$ = 8
_this$ = -4
?SetError_Format@ERRORCLASS@@QAEXPAD@Z PROC NEAR	; ERRORCLASS::SetError_Format, COMDAT

; 78   : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 80					; 00000050H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 79   : 			if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L34637

; 81   : 				PrevMsgFormat = new char[strlen(MsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T67756[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T67756[ebp]
	mov	DWORD PTR [eax+4], ecx

; 82   : 				strcpy(PrevMsgFormat, MsgFormat);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	call	_strcpy
	add	esp, 8
$L34637:

; 84   : 
; 85   : 			if(m != NULL)

	cmp	DWORD PTR _m$[ebp], 0
	je	SHORT $L34640

; 87   : 				MsgFormat = new char[strlen(m)];

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T67757[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T67757[ebp]
	mov	DWORD PTR [ecx], edx

; 88   : 				strcpy(MsgFormat, m);

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8

; 90   : 			else

	jmp	SHORT $L34643
$L34640:

; 92   : 				MsgFormat = new char[2];

	push	2
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T67758[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T67758[ebp]
	mov	DWORD PTR [eax], ecx

; 93   : 				strcpy(MsgFormat, "");

	push	OFFSET FLAT:??_C@_00A@?$AA@		; `string'
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_strcpy
	add	esp, 8
$L34643:

; 95   : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?SetError_Format@ERRORCLASS@@QAEXPAD@Z ENDP		; ERRORCLASS::SetError_Format
_TEXT	ENDS
PUBLIC	?End@@YAXPAUHWND__@@@Z				; End
PUBLIC	?Main_Create@MAIN@@QAEHPAUHWND__@@PAUtagCREATESTRUCTA@@@Z ; MAIN::Main_Create
PUBLIC	?Main_Destroy@MAIN@@QAEXPAUHWND__@@@Z		; MAIN::Main_Destroy
PUBLIC	?Main_Paint@MAIN@@QAEXPAUHWND__@@@Z		; MAIN::Main_Paint
PUBLIC	?Main_Move@MAIN@@QAEXPAUHWND__@@HH@Z		; MAIN::Main_Move
PUBLIC	?Main_Activate@MAIN@@QAEXPAUHWND__@@I0H@Z	; MAIN::Main_Activate
PUBLIC	?Start@MAIN@@QAEXPAUHWND__@@@Z			; MAIN::Start
EXTRN	__imp__DefWindowProcA@16:NEAR
EXTRN	?OnMouse@CONTROLS@@QAEXPAUHWND__@@HHI@Z:NEAR	; CONTROLS::OnMouse
EXTRN	?OnKey@CONTROLS@@QAEXPAUHWND__@@IHHI@Z:NEAR	; CONTROLS::OnKey
;	COMDAT ?Main_WindowProc@@YGJPAUHWND__@@IIJ@Z
_TEXT	SEGMENT
_hwnd$ = 8
_Message$ = 12
_wParam$ = 16
_lParam$ = 20
?Main_WindowProc@@YGJPAUHWND__@@IIJ@Z PROC NEAR		; Main_WindowProc, COMDAT

; 205  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi

; 207  :   {

	mov	eax, DWORD PTR _Message$[ebp]
	mov	DWORD PTR -4+[ebp], eax
	cmp	DWORD PTR -4+[ebp], 15			; 0000000fH
	ja	SHORT $L67761
	cmp	DWORD PTR -4+[ebp], 15			; 0000000fH
	je	SHORT $L67269
	mov	ecx, DWORD PTR -4+[ebp]
	sub	ecx, 1
	mov	DWORD PTR -4+[ebp], ecx
	cmp	DWORD PTR -4+[ebp], 5
	ja	$L67307
	mov	edx, DWORD PTR -4+[ebp]
	jmp	DWORD PTR $L67763[edx*4]
$L67761:
	cmp	DWORD PTR -4+[ebp], 1024		; 00000400H
	ja	SHORT $L67762
	cmp	DWORD PTR -4+[ebp], 1024		; 00000400H
	je	$L67288
	cmp	DWORD PTR -4+[ebp], 256			; 00000100H
	je	$L67290
	cmp	DWORD PTR -4+[ebp], 512			; 00000200H
	je	$L67298
	jmp	$L67307
$L67762:
	cmp	DWORD PTR -4+[ebp], 1025		; 00000401H
	je	$L67289
	jmp	$L67307
$L67268:

; 208  : 		HANDLE_MSG(hwnd, WM_DESTROY		, Val->Main->Main_Destroy);

	mov	eax, DWORD PTR _hwnd$[ebp]
	push	eax
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [ecx+56]
	call	?Main_Destroy@MAIN@@QAEXPAUHWND__@@@Z	; MAIN::Main_Destroy
	xor	eax, eax
	jmp	$L67265
$L67269:

; 209  : 		HANDLE_MSG(hwnd, WM_PAINT  		, Val->Main->Main_Paint);

	mov	edx, DWORD PTR _hwnd$[ebp]
	push	edx
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+56]
	call	?Main_Paint@MAIN@@QAEXPAUHWND__@@@Z	; MAIN::Main_Paint
	xor	eax, eax
	jmp	$L67265
$L67270:

; 210  : 		HANDLE_MSG(hwnd, WM_CREATE 		, Val->Main->Main_Create);

	mov	ecx, DWORD PTR _lParam$[ebp]
	push	ecx
	mov	edx, DWORD PTR _hwnd$[ebp]
	push	edx
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+56]
	call	?Main_Create@MAIN@@QAEHPAUHWND__@@PAUtagCREATESTRUCTA@@@Z ; MAIN::Main_Create
	neg	eax
	sbb	eax, eax
	neg	eax
	dec	eax
	jmp	$L67265
$L67273:

; 211  : 		HANDLE_MSG(hwnd, WM_MOVE 			, Val->Main->Main_Move);

	mov	ecx, DWORD PTR _lParam$[ebp]
	shr	ecx, 16					; 00000010H
	and	ecx, 65535				; 0000ffffH
	movsx	edx, cx
	push	edx
	movsx	eax, WORD PTR _lParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _hwnd$[ebp]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+56]
	call	?Main_Move@MAIN@@QAEXPAUHWND__@@HH@Z	; MAIN::Main_Move
	xor	eax, eax
	jmp	$L67265
$L67281:

; 212  : 		HANDLE_MSG(hwnd, WM_ACTIVATE 	, Val->Main->Main_Activate);

	mov	eax, DWORD PTR _wParam$[ebp]
	shr	eax, 16					; 00000010H
	and	eax, 65535				; 0000ffffH
	and	eax, 65535				; 0000ffffH
	push	eax
	mov	ecx, DWORD PTR _lParam$[ebp]
	push	ecx
	mov	edx, DWORD PTR _wParam$[ebp]
	and	edx, 65535				; 0000ffffH
	push	edx
	mov	eax, DWORD PTR _hwnd$[ebp]
	push	eax
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [ecx+56]
	call	?Main_Activate@MAIN@@QAEXPAUHWND__@@I0H@Z ; MAIN::Main_Activate
	xor	eax, eax
	jmp	$L67265
$L67288:

; 213  : 		HANDLE_MSG(hwnd, WM_START			, Val->Main->Start);

	mov	edx, DWORD PTR _hwnd$[ebp]
	push	edx
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+56]
	call	?Start@MAIN@@QAEXPAUHWND__@@@Z		; MAIN::Start
	xor	eax, eax
	jmp	$L67265
$L67289:

; 214  : 		HANDLE_MSG(hwnd, WM_END				, ::End);

	mov	ecx, DWORD PTR _hwnd$[ebp]
	push	ecx
	call	?End@@YAXPAUHWND__@@@Z			; End
	add	esp, 4
	xor	eax, eax
	jmp	SHORT $L67265
$L67290:

; 215  : 
; 216  : 		HANDLE_MSG(hwnd, WM_KEYDOWN 	, Val->Controls->OnKey);

	mov	edx, DWORD PTR _lParam$[ebp]
	shr	edx, 16					; 00000010H
	and	edx, 65535				; 0000ffffH
	and	edx, 65535				; 0000ffffH
	push	edx
	movsx	eax, WORD PTR _lParam$[ebp]
	push	eax
	push	1
	mov	ecx, DWORD PTR _wParam$[ebp]
	push	ecx
	mov	edx, DWORD PTR _hwnd$[ebp]
	push	edx
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+60]
	call	?OnKey@CONTROLS@@QAEXPAUHWND__@@IHHI@Z	; CONTROLS::OnKey
	xor	eax, eax
	jmp	SHORT $L67265
$L67298:

; 217  : 		HANDLE_MSG(hwnd, WM_MOUSEMOVE	, Val->Controls->OnMouse);

	mov	ecx, DWORD PTR _wParam$[ebp]
	push	ecx
	mov	edx, DWORD PTR _lParam$[ebp]
	shr	edx, 16					; 00000010H
	and	edx, 65535				; 0000ffffH
	movsx	eax, dx
	push	eax
	movsx	ecx, WORD PTR _lParam$[ebp]
	push	ecx
	mov	edx, DWORD PTR _hwnd$[ebp]
	push	edx
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+60]
	call	?OnMouse@CONTROLS@@QAEXPAUHWND__@@HHI@Z	; CONTROLS::OnMouse
	xor	eax, eax
	jmp	SHORT $L67265
$L67307:

; 218  : 		default:
; 219  : 			return DefWindowProc(hwnd, Message, wParam, lParam);

	mov	ecx, DWORD PTR _lParam$[ebp]
	push	ecx
	mov	edx, DWORD PTR _wParam$[ebp]
	push	edx
	mov	eax, DWORD PTR _Message$[ebp]
	push	eax
	mov	ecx, DWORD PTR _hwnd$[ebp]
	push	ecx
	call	DWORD PTR __imp__DefWindowProcA@16
$L67265:

; 221  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
$L67763:
	DD	$L67270
	DD	$L67268
	DD	$L67273
	DD	$L67307
	DD	$L67307
	DD	$L67281
?Main_WindowProc@@YGJPAUHWND__@@IIJ@Z ENDP		; Main_WindowProc
_TEXT	ENDS
PUBLIC	?CreateChildWindow@MAIN@@QAEXPAUHWND__@@@Z	; MAIN::CreateChildWindow
;	COMDAT ?Main_Create@MAIN@@QAEHPAUHWND__@@PAUtagCREATESTRUCTA@@@Z
_TEXT	SEGMENT
_hwnd$ = 8
_this$ = -4
?Main_Create@MAIN@@QAEHPAUHWND__@@PAUtagCREATESTRUCTA@@@Z PROC NEAR ; MAIN::Main_Create, COMDAT

; 226  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 227  : 	CreateChildWindow(hwnd);

	mov	eax, DWORD PTR _hwnd$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?CreateChildWindow@MAIN@@QAEXPAUHWND__@@@Z ; MAIN::CreateChildWindow

; 228  : 	return TRUE;

	mov	eax, 1

; 229  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?Main_Create@MAIN@@QAEHPAUHWND__@@PAUtagCREATESTRUCTA@@@Z ENDP ; MAIN::Main_Create
_TEXT	ENDS
EXTRN	_abs:NEAR
EXTRN	__imp__GetWindowRect@8:NEAR
;	COMDAT ?CreateChildWindow@MAIN@@QAEXPAUHWND__@@@Z
_TEXT	SEGMENT
_hwnd$ = 8
_this$ = -4
_Rect$ = -20
?CreateChildWindow@MAIN@@QAEXPAUHWND__@@@Z PROC NEAR	; MAIN::CreateChildWindow, COMDAT

; 232  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 84					; 00000054H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 233  : 	MainHwnd = 	hwnd;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _hwnd$[ebp]
	mov	DWORD PTR [eax+88], ecx

; 234  : 	RECT Rect;
; 235  : 
; 236  : 	x = 0; y = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+60], 0
	mov	eax, DWORD PTR _this$[ebp]
	mov	WORD PTR [eax+62], 0

; 237  : //	unsigned int w = abs( (Rect2.right - Rect2.left) - (Rect1.right - Rect1.left) );
; 238  : //	unsigned int h = abs( (Rect2.bottom - Rect2.top) - (Rect1.bottom - Rect1.top) - w);
; 239  : //	MainPos + ( 1/2(MainWidth) - 1/2(ChildWidth) )
; 240  : //	x = (unsigned __int16)( Rect.left + (GetSystemMetrics(SM_CXFIXEDFRAME) << 1) );
; 241  : //	y =	(unsigned __int16)( Rect.top  + (GetSystemMetrics(SM_CXFIXEDFRAME) << 1) + GetSystemMetrics(SM_CYCAPTION) );
; 242  : 
; 243  : 	if(data.Stretch)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+59]
	test	edx, edx
	je	$L67318

; 245  : 		if(!data.FullScreen)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+58]
	test	ecx, ecx
	jne	SHORT $L67319

; 247  : 			w = xMax;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	cx, WORD PTR [eax+68]
	mov	WORD PTR [edx+64], cx

; 248  : 			h = yMax;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	cx, WORD PTR [eax+70]
	mov	WORD PTR [edx+66], cx

; 249  : 
; 250  : 			GetWindowRect(MainHwnd, &Rect);

	lea	edx, DWORD PTR _Rect$[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+88]
	push	ecx
	call	DWORD PTR __imp__GetWindowRect@8

; 251  : 			x = (Rect.right - Rect.left - w) >> 1;

	mov	edx, DWORD PTR _Rect$[ebp+8]
	sub	edx, DWORD PTR _Rect$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+64]
	sub	edx, ecx
	sar	edx, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	WORD PTR [eax+60], dx

; 252  : 			y =	(Rect.bottom - Rect.top - h) >> 1;

	mov	ecx, DWORD PTR _Rect$[ebp+12]
	sub	ecx, DWORD PTR _Rect$[ebp+4]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+66]
	sub	ecx, eax
	sar	ecx, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+62], cx

; 254  : 		else

	jmp	$L67320
$L67319:

; 256  : 			Rect.left = 0;

	mov	DWORD PTR _Rect$[ebp], 0

; 257  : 			Rect.top = 0;

	mov	DWORD PTR _Rect$[ebp+4], 0

; 258  : 			Rect.right = GetSystemMetrics(SM_CXSCREEN);

	push	0
	call	DWORD PTR __imp__GetSystemMetrics@4
	mov	DWORD PTR _Rect$[ebp+8], eax

; 259  : 			Rect.bottom = GetSystemMetrics(SM_CYSCREEN);

	push	1
	call	DWORD PTR __imp__GetSystemMetrics@4
	mov	DWORD PTR _Rect$[ebp+12], eax

; 260  : 
; 261  : 			w = (short)abs(Rect.right - Rect.left - 10 );

	mov	eax, DWORD PTR _Rect$[ebp+8]
	sub	eax, DWORD PTR _Rect$[ebp]
	sub	eax, 10					; 0000000aH
	push	eax
	call	_abs
	add	esp, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	WORD PTR [ecx+64], ax

; 262  : 			h = (short)abs(Rect.bottom - Rect.top - 10  - GetSystemMetrics(SM_CYCAPTION));

	mov	esi, DWORD PTR _Rect$[ebp+12]
	sub	esi, DWORD PTR _Rect$[ebp+4]
	sub	esi, 10					; 0000000aH
	push	4
	call	DWORD PTR __imp__GetSystemMetrics@4
	sub	esi, eax
	push	esi
	call	_abs
	add	esp, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+66], ax

; 263  : 
; 264  : 			if( (w - xMax) > (h - yMax) )

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+64]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+68]
	sub	ecx, eax
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+66]
	mov	edx, DWORD PTR _this$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+70]
	sub	eax, esi
	cmp	ecx, eax
	jle	SHORT $L67323

; 265  : 				w = (h*xMax)/(yMax);

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+66]
	mov	eax, ecx
	mov	edx, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+68]
	imul	eax, ecx
	mov	edx, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+70]
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+64], ax

; 266  : 			else

	jmp	SHORT $L67324
$L67323:

; 267  : 				h = (w*yMax)/(xMax);

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+64]
	mov	eax, ecx
	mov	edx, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+70]
	imul	eax, ecx
	mov	edx, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+68]
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+66], ax
$L67324:

; 268  : 			
; 269  : 			x = (Rect.right - Rect.left - w) >> 1;

	mov	eax, DWORD PTR _Rect$[ebp+8]
	sub	eax, DWORD PTR _Rect$[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+64]
	sub	eax, edx
	sar	eax, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	WORD PTR [ecx+60], ax

; 270  : 			y =	(Rect.bottom - Rect.top - h) >> 1;

	mov	edx, DWORD PTR _Rect$[ebp+12]
	sub	edx, DWORD PTR _Rect$[ebp+4]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+66]
	sub	edx, ecx
	sar	edx, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	WORD PTR [eax+62], dx
$L67320:

; 272  : 
; 273  : 		if(data.InWindow)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+57]
	test	edx, edx
	je	SHORT $L67325

; 275  : 			x += (short)Rect.left;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cx, WORD PTR [eax+60]
	add	cx, WORD PTR _Rect$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+60], cx

; 276  : 			y += Rect.top + (GetSystemMetrics(SM_CYCAPTION) >> 1);

	push	4
	call	DWORD PTR __imp__GetSystemMetrics@4
	sar	eax, 1
	mov	ecx, DWORD PTR _Rect$[ebp+4]
	add	ecx, eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	ax, WORD PTR [edx+62]
	add	ax, cx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	WORD PTR [ecx+62], ax
$L67325:

; 279  : 	else

	jmp	$L67328
$L67318:

; 281  : 		w = xMax;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	cx, WORD PTR [eax+68]
	mov	WORD PTR [edx+64], cx

; 282  : 		h = yMax;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	cx, WORD PTR [eax+70]
	mov	WORD PTR [edx+66], cx

; 283  : 
; 284  : 		Rect.left = 0;

	mov	DWORD PTR _Rect$[ebp], 0

; 285  : 		Rect.top = 0;

	mov	DWORD PTR _Rect$[ebp+4], 0

; 286  : 		Rect.right = GetSystemMetrics(SM_CXSCREEN);

	push	0
	call	DWORD PTR __imp__GetSystemMetrics@4
	mov	DWORD PTR _Rect$[ebp+8], eax

; 287  : 		Rect.bottom = GetSystemMetrics(SM_CYSCREEN);

	push	1
	call	DWORD PTR __imp__GetSystemMetrics@4
	mov	DWORD PTR _Rect$[ebp+12], eax

; 288  : 
; 289  : 		x = (Rect.right - Rect.left - w) >> 1;

	mov	edx, DWORD PTR _Rect$[ebp+8]
	sub	edx, DWORD PTR _Rect$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+64]
	sub	edx, ecx
	sar	edx, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	WORD PTR [eax+60], dx

; 290  : 		y =	(Rect.bottom - Rect.top - h) >> 1;

	mov	ecx, DWORD PTR _Rect$[ebp+12]
	sub	ecx, DWORD PTR _Rect$[ebp+4]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+66]
	sub	ecx, eax
	sar	ecx, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+62], cx

; 291  : 
; 292  : 		if(data.InWindow)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+57]
	test	ecx, ecx
	je	SHORT $L67328

; 293  : 			y += GetSystemMetrics(SM_CYCAPTION) >> 1;

	push	4
	call	DWORD PTR __imp__GetSystemMetrics@4
	sar	eax, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	cx, WORD PTR [edx+62]
	add	cx, ax
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+62], cx
$L67328:

; 295  : 
; 296  : 	ChildRect.left = x;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+60]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+72], ecx

; 297  : 	ChildRect.right = w + x;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+64]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+60]
	add	ecx, eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+80], ecx

; 298  : 	ChildRect.top = y;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+62]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+76], ecx

; 299  : 	ChildRect.bottom = h + y;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+66]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+62]
	add	ecx, eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+84], ecx

; 300  : 
; 301  : 	//WS_POPUPWINDOW
; 302  : 	CreateWindow(CHILDWINDOW, NULL, WS_POPUPWINDOW | WS_VISIBLE,	x, y, w, h,	MainHwnd,	NULL, MainhInst, NULL);

	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+92]
	push	ecx
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+88]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+66]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+64]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+62]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+60]
	push	edx
	push	-1870135296				; 90880000H
	push	0
	push	OFFSET FLAT:??_C@_0N@PNLA@Child?5Window?$AA@ ; `string'
	push	0
	call	DWORD PTR __imp__CreateWindowExA@48

; 303  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?CreateChildWindow@MAIN@@QAEXPAUHWND__@@@Z ENDP		; MAIN::CreateChildWindow
_TEXT	ENDS
EXTRN	__imp__BeginPaint@8:NEAR
EXTRN	__imp__EndPaint@8:NEAR
;	COMDAT ?Main_Paint@MAIN@@QAEXPAUHWND__@@@Z
_TEXT	SEGMENT
_hwnd$ = 8
_this$ = -4
_PaintStruct$ = -68
_PaintDC$ = -72
?Main_Paint@MAIN@@QAEXPAUHWND__@@@Z PROC NEAR		; MAIN::Main_Paint, COMDAT

; 308  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 136				; 00000088H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 309  : 	PAINTSTRUCT PaintStruct;
; 310  : 	HDC PaintDC = BeginPaint(hwnd, &PaintStruct);

	lea	eax, DWORD PTR _PaintStruct$[ebp]
	push	eax
	mov	ecx, DWORD PTR _hwnd$[ebp]
	push	ecx
	call	DWORD PTR __imp__BeginPaint@8
	mov	DWORD PTR _PaintDC$[ebp], eax

; 311  : 	// Insert paint stuff hear
; 312  : 	EndPaint(hwnd, &PaintStruct);

	lea	edx, DWORD PTR _PaintStruct$[ebp]
	push	edx
	mov	eax, DWORD PTR _hwnd$[ebp]
	push	eax
	call	DWORD PTR __imp__EndPaint@8

; 313  : 	//
; 314  : 	Val->Display->Re_Draw = RE_ALL;

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+64]
	mov	eax, DWORD PTR [edx+52]
	and	al, -4					; fffffffcH
	or	al, 2
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+64]
	mov	DWORD PTR [edx+52], eax

; 315  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?Main_Paint@MAIN@@QAEXPAUHWND__@@@Z ENDP		; MAIN::Main_Paint
_TEXT	ENDS
EXTRN	__imp__SetWindowPos@28:NEAR
EXTRN	__imp__IsIconic@4:NEAR
EXTRN	__imp__IsZoomed@4:NEAR
;	COMDAT ?Main_Move@MAIN@@QAEXPAUHWND__@@HH@Z
_TEXT	SEGMENT
_x$ = 12
_y$ = 16
_this$ = -4
_zoom$67342 = -8
_Rect$67343 = -24
?Main_Move@MAIN@@QAEXPAUHWND__@@HH@Z PROC NEAR		; MAIN::Main_Move, COMDAT

; 320  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 88					; 00000058H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 321  : 	if( (ChildHwnd != NULL) && ( !IsIconic(MainHwnd) ) )

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+96], 0
	je	$L67344
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+88]
	push	edx
	call	DWORD PTR __imp__IsIconic@4
	test	eax, eax
	jne	$L67344

; 323  : 		bool zoom = IsZoomed(MainHwnd) > 0 ? 1 : 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+88]
	push	ecx
	call	DWORD PTR __imp__IsZoomed@4
	xor	edx, edx
	test	eax, eax
	setg	dl
	mov	BYTE PTR _zoom$67342[ebp], dl

; 329  : 			if(data.Stretch)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+59]
	test	ecx, ecx
	je	$L67344

; 331  : 				if(!data.FullScreen)

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+58]
	test	eax, eax
	jne	SHORT $L67345

; 333  : 					w = xMax;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	ax, WORD PTR [edx+68]
	mov	WORD PTR [ecx+64], ax

; 334  : 					h = yMax;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	ax, WORD PTR [edx+70]
	mov	WORD PTR [ecx+66], ax

; 335  : 
; 336  : 					GetWindowRect(MainHwnd, &Rect);

	lea	ecx, DWORD PTR _Rect$67343[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+88]
	push	eax
	call	DWORD PTR __imp__GetWindowRect@8

; 337  : 					x = (Rect.right - Rect.left - w) >> 1;

	mov	ecx, DWORD PTR _Rect$67343[ebp+8]
	sub	ecx, DWORD PTR _Rect$67343[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+64]
	sub	ecx, eax
	sar	ecx, 1
	mov	DWORD PTR _x$[ebp], ecx

; 338  : 					y =	(Rect.bottom - Rect.top - h) >> 1;

	mov	ecx, DWORD PTR _Rect$67343[ebp+12]
	sub	ecx, DWORD PTR _Rect$67343[ebp+4]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+66]
	sub	ecx, eax
	sar	ecx, 1
	mov	DWORD PTR _y$[ebp], ecx

; 340  : 				else

	jmp	$L67346
$L67345:

; 342  : 					Rect.left = 0;

	mov	DWORD PTR _Rect$67343[ebp], 0

; 343  : 					Rect.top = 0;

	mov	DWORD PTR _Rect$67343[ebp+4], 0

; 344  : 					Rect.right = GetSystemMetrics(SM_CXSCREEN);

	push	0
	call	DWORD PTR __imp__GetSystemMetrics@4
	mov	DWORD PTR _Rect$67343[ebp+8], eax

; 345  : 					Rect.bottom = GetSystemMetrics(SM_CYSCREEN);

	push	1
	call	DWORD PTR __imp__GetSystemMetrics@4
	mov	DWORD PTR _Rect$67343[ebp+12], eax

; 346  : 
; 347  : 					w = (short)abs(Rect.right - Rect.left - 10 );

	mov	ecx, DWORD PTR _Rect$67343[ebp+8]
	sub	ecx, DWORD PTR _Rect$67343[ebp]
	sub	ecx, 10					; 0000000aH
	push	ecx
	call	_abs
	add	esp, 4
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+64], ax

; 348  : 					h = (short)abs(Rect.bottom - Rect.top - 10  - GetSystemMetrics(SM_CYCAPTION));

	mov	esi, DWORD PTR _Rect$67343[ebp+12]
	sub	esi, DWORD PTR _Rect$67343[ebp+4]
	sub	esi, 10					; 0000000aH
	push	4
	call	DWORD PTR __imp__GetSystemMetrics@4
	sub	esi, eax
	push	esi
	call	_abs
	add	esp, 4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	WORD PTR [ecx+66], ax

; 349  : 
; 350  : 					if( (w - xMax) > (h - yMax) )

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+64]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+68]
	sub	eax, edx
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+66]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [ecx+70]
	sub	edx, esi
	cmp	eax, edx
	jle	SHORT $L67349

; 351  : 						w = (h*xMax)/(yMax);

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+66]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+68]
	imul	eax, edx
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+70]
	mov	ecx, edx
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+64], ax

; 352  : 					else

	jmp	SHORT $L67350
$L67349:

; 353  : 						h = (w*yMax)/(xMax);

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+64]
	mov	eax, ecx
	mov	edx, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+70]
	imul	eax, ecx
	mov	edx, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+68]
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	WORD PTR [edx+66], ax
$L67350:

; 354  : 					
; 355  : 					x = (Rect.right - Rect.left - w) >> 1;

	mov	eax, DWORD PTR _Rect$67343[ebp+8]
	sub	eax, DWORD PTR _Rect$67343[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+64]
	sub	eax, edx
	sar	eax, 1
	mov	DWORD PTR _x$[ebp], eax

; 356  : 					y =	(Rect.bottom - Rect.top - h) >> 1;

	mov	eax, DWORD PTR _Rect$67343[ebp+12]
	sub	eax, DWORD PTR _Rect$67343[ebp+4]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+66]
	sub	eax, edx
	sar	eax, 1
	mov	DWORD PTR _y$[ebp], eax
$L67346:

; 358  : 
; 359  : 				if(data.InWindow)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+57]
	test	ecx, ecx
	je	SHORT $L67351

; 361  : 					x += (short)Rect.left;

	movsx	edx, WORD PTR _Rect$67343[ebp]
	mov	eax, DWORD PTR _x$[ebp]
	add	eax, edx
	mov	DWORD PTR _x$[ebp], eax

; 362  : 					y += Rect.top + (GetSystemMetrics(SM_CYCAPTION) >> 1);

	push	4
	call	DWORD PTR __imp__GetSystemMetrics@4
	sar	eax, 1
	mov	ecx, DWORD PTR _Rect$67343[ebp+4]
	add	ecx, eax
	mov	edx, DWORD PTR _y$[ebp]
	add	edx, ecx
	mov	DWORD PTR _y$[ebp], edx
$L67351:

; 364  : 
; 365  : 				if(x < 0)

	cmp	DWORD PTR _x$[ebp], 0
	jge	SHORT $L67353

; 366  : 					x = 0;

	mov	DWORD PTR _x$[ebp], 0
$L67353:

; 367  : 				if(y < 0)

	cmp	DWORD PTR _y$[ebp], 0
	jge	SHORT $L67354

; 368  : 					y = 0;

	mov	DWORD PTR _y$[ebp], 0
$L67354:

; 369  : 
; 370  : 				ChildRect.left = x;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	mov	DWORD PTR [eax+72], ecx

; 371  : 				ChildRect.right = w + x;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+64]
	add	eax, DWORD PTR _x$[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+80], eax

; 372  : 				ChildRect.top = y;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	mov	DWORD PTR [edx+76], eax

; 373  : 				ChildRect.bottom = h + y;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+66]
	add	edx, DWORD PTR _y$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+84], edx

; 374  : 
; 375  : 				SetWindowPos(ChildHwnd, HWND_TOP, x, y, w, h, 0 );

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+66]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+64]
	push	ecx
	mov	edx, DWORD PTR _y$[ebp]
	push	edx
	mov	eax, DWORD PTR _x$[ebp]
	push	eax
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+96]
	push	edx
	call	DWORD PTR __imp__SetWindowPos@28
$L67344:

; 422  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	12					; 0000000cH
?Main_Move@MAIN@@QAEXPAUHWND__@@HH@Z ENDP		; MAIN::Main_Move
_TEXT	ENDS
;	COMDAT ?Main_Activate@MAIN@@QAEXPAUHWND__@@I0H@Z
_TEXT	SEGMENT
_this$ = -4
?Main_Activate@MAIN@@QAEXPAUHWND__@@I0H@Z PROC NEAR	; MAIN::Main_Activate, COMDAT

; 427  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 428  : 	
; 429  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?Main_Activate@MAIN@@QAEXPAUHWND__@@I0H@Z ENDP		; MAIN::Main_Activate
_TEXT	ENDS
PUBLIC	?Child_Create@MAIN@@QAEHPAUHWND__@@PAUtagCREATESTRUCTA@@@Z ; MAIN::Child_Create
PUBLIC	?Child_Destroy@MAIN@@QAEXPAUHWND__@@@Z		; MAIN::Child_Destroy
PUBLIC	?Child_Paint@MAIN@@QAEXPAUHWND__@@@Z		; MAIN::Child_Paint
EXTRN	?OnMouseLDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z:NEAR ; CONTROLS::OnMouseLDown
EXTRN	?OnMouseRDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z:NEAR ; CONTROLS::OnMouseRDown
EXTRN	?OnMouseMDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z:NEAR ; CONTROLS::OnMouseMDown
EXTRN	?OnMouseLUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z:NEAR	; CONTROLS::OnMouseLUp
EXTRN	?OnMouseRUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z:NEAR	; CONTROLS::OnMouseRUp
EXTRN	?OnMouseMUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z:NEAR	; CONTROLS::OnMouseMUp
;	COMDAT ?Child_WindowProc@@YGJPAUHWND__@@IIJ@Z
_TEXT	SEGMENT
_childHwnd$ = 8
_Message$ = 12
_wParam$ = 16
_lParam$ = 20
?Child_WindowProc@@YGJPAUHWND__@@IIJ@Z PROC NEAR	; Child_WindowProc, COMDAT

; 435  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi

; 437  :   {

	mov	eax, DWORD PTR _Message$[ebp]
	mov	DWORD PTR -4+[ebp], eax
	cmp	DWORD PTR -4+[ebp], 513			; 00000201H
	ja	SHORT $L67776
	cmp	DWORD PTR -4+[ebp], 513			; 00000201H
	je	$L67395
	cmp	DWORD PTR -4+[ebp], 15			; 0000000fH
	ja	SHORT $L67777
	cmp	DWORD PTR -4+[ebp], 15			; 0000000fH
	je	$L67377
	cmp	DWORD PTR -4+[ebp], 1
	je	SHORT $L67373
	cmp	DWORD PTR -4+[ebp], 2
	je	SHORT $L67376
	jmp	$L67449
$L67777:
	cmp	DWORD PTR -4+[ebp], 256			; 00000100H
	je	$L67378
	cmp	DWORD PTR -4+[ebp], 512			; 00000200H
	je	$L67386
	jmp	$L67449
$L67776:
	mov	ecx, DWORD PTR -4+[ebp]
	sub	ecx, 514				; 00000202H
	mov	DWORD PTR -4+[ebp], ecx
	cmp	DWORD PTR -4+[ebp], 6
	ja	$L67449
	mov	edx, DWORD PTR -4+[ebp]
	jmp	DWORD PTR $L67778[edx*4]
$L67373:

; 438  : 		HANDLE_MSG(childHwnd, WM_CREATE 			, Val->Main->Child_Create);

	mov	eax, DWORD PTR _lParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _childHwnd$[ebp]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+56]
	call	?Child_Create@MAIN@@QAEHPAUHWND__@@PAUtagCREATESTRUCTA@@@Z ; MAIN::Child_Create
	neg	eax
	sbb	eax, eax
	neg	eax
	dec	eax
	jmp	$L67370
$L67376:

; 439  : 		HANDLE_MSG(childHwnd, WM_DESTROY			, Val->Main->Child_Destroy);

	mov	eax, DWORD PTR _childHwnd$[ebp]
	push	eax
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [ecx+56]
	call	?Child_Destroy@MAIN@@QAEXPAUHWND__@@@Z	; MAIN::Child_Destroy
	xor	eax, eax
	jmp	$L67370
$L67377:

; 440  : 		HANDLE_MSG(childHwnd, WM_PAINT  			, Val->Main->Child_Paint);

	mov	edx, DWORD PTR _childHwnd$[ebp]
	push	edx
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+56]
	call	?Child_Paint@MAIN@@QAEXPAUHWND__@@@Z	; MAIN::Child_Paint
	xor	eax, eax
	jmp	$L67370
$L67378:

; 441  : 
; 442  : 		HANDLE_MSG(childHwnd, WM_KEYDOWN 			, Val->Controls->OnKey);

	mov	ecx, DWORD PTR _lParam$[ebp]
	shr	ecx, 16					; 00000010H
	and	ecx, 65535				; 0000ffffH
	and	ecx, 65535				; 0000ffffH
	push	ecx
	movsx	edx, WORD PTR _lParam$[ebp]
	push	edx
	push	1
	mov	eax, DWORD PTR _wParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _childHwnd$[ebp]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+60]
	call	?OnKey@CONTROLS@@QAEXPAUHWND__@@IHHI@Z	; CONTROLS::OnKey
	xor	eax, eax
	jmp	$L67370
$L67386:

; 443  : 
; 444  : 		HANDLE_MSG(childHwnd, WM_MOUSEMOVE		, Val->Controls->OnMouse);

	mov	eax, DWORD PTR _wParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _lParam$[ebp]
	shr	ecx, 16					; 00000010H
	and	ecx, 65535				; 0000ffffH
	movsx	edx, cx
	push	edx
	movsx	eax, WORD PTR _lParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _childHwnd$[ebp]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+60]
	call	?OnMouse@CONTROLS@@QAEXPAUHWND__@@HHI@Z	; CONTROLS::OnMouse
	xor	eax, eax
	jmp	$L67370
$L67395:

; 445  : 
; 446  : 		HANDLE_MSG(childHwnd, WM_LBUTTONDOWN	, Val->Controls->OnMouseLDown);

	mov	eax, DWORD PTR _wParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _lParam$[ebp]
	shr	ecx, 16					; 00000010H
	and	ecx, 65535				; 0000ffffH
	movsx	edx, cx
	push	edx
	movsx	eax, WORD PTR _lParam$[ebp]
	push	eax
	push	0
	mov	ecx, DWORD PTR _childHwnd$[ebp]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+60]
	call	?OnMouseLDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z ; CONTROLS::OnMouseLDown
	xor	eax, eax
	jmp	$L67370
$L67404:

; 447  : 		HANDLE_MSG(childHwnd, WM_RBUTTONDOWN	, Val->Controls->OnMouseRDown);

	mov	eax, DWORD PTR _wParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _lParam$[ebp]
	shr	ecx, 16					; 00000010H
	and	ecx, 65535				; 0000ffffH
	movsx	edx, cx
	push	edx
	movsx	eax, WORD PTR _lParam$[ebp]
	push	eax
	push	0
	mov	ecx, DWORD PTR _childHwnd$[ebp]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+60]
	call	?OnMouseRDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z ; CONTROLS::OnMouseRDown
	xor	eax, eax
	jmp	$L67370
$L67413:

; 448  : 		HANDLE_MSG(childHwnd, WM_MBUTTONDOWN	, Val->Controls->OnMouseMDown);

	mov	eax, DWORD PTR _wParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _lParam$[ebp]
	shr	ecx, 16					; 00000010H
	and	ecx, 65535				; 0000ffffH
	movsx	edx, cx
	push	edx
	movsx	eax, WORD PTR _lParam$[ebp]
	push	eax
	push	0
	mov	ecx, DWORD PTR _childHwnd$[ebp]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+60]
	call	?OnMouseMDown@CONTROLS@@QAEXPAUHWND__@@HHHI@Z ; CONTROLS::OnMouseMDown
	xor	eax, eax
	jmp	$L67370
$L67422:

; 449  : 
; 450  : 		HANDLE_MSG(childHwnd, WM_LBUTTONUP	, Val->Controls->OnMouseLUp);

	mov	eax, DWORD PTR _wParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _lParam$[ebp]
	shr	ecx, 16					; 00000010H
	and	ecx, 65535				; 0000ffffH
	movsx	edx, cx
	push	edx
	movsx	eax, WORD PTR _lParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _childHwnd$[ebp]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+60]
	call	?OnMouseLUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z ; CONTROLS::OnMouseLUp
	xor	eax, eax
	jmp	SHORT $L67370
$L67431:

; 451  : 		HANDLE_MSG(childHwnd, WM_RBUTTONUP	, Val->Controls->OnMouseRUp);

	mov	eax, DWORD PTR _wParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _lParam$[ebp]
	shr	ecx, 16					; 00000010H
	and	ecx, 65535				; 0000ffffH
	movsx	edx, cx
	push	edx
	movsx	eax, WORD PTR _lParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _childHwnd$[ebp]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+60]
	call	?OnMouseRUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z ; CONTROLS::OnMouseRUp
	xor	eax, eax
	jmp	SHORT $L67370
$L67440:

; 452  : 		HANDLE_MSG(childHwnd, WM_MBUTTONUP	, Val->Controls->OnMouseMUp);

	mov	eax, DWORD PTR _wParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _lParam$[ebp]
	shr	ecx, 16					; 00000010H
	and	ecx, 65535				; 0000ffffH
	movsx	edx, cx
	push	edx
	movsx	eax, WORD PTR _lParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _childHwnd$[ebp]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+60]
	call	?OnMouseMUp@CONTROLS@@QAEXPAUHWND__@@HHI@Z ; CONTROLS::OnMouseMUp
	xor	eax, eax
	jmp	SHORT $L67370
$L67449:

; 453  : 		default:
; 454  : 			return DefWindowProc(childHwnd, Message, wParam, lParam);

	mov	eax, DWORD PTR _lParam$[ebp]
	push	eax
	mov	ecx, DWORD PTR _wParam$[ebp]
	push	ecx
	mov	edx, DWORD PTR _Message$[ebp]
	push	edx
	mov	eax, DWORD PTR _childHwnd$[ebp]
	push	eax
	call	DWORD PTR __imp__DefWindowProcA@16
$L67370:

; 456  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
$L67778:
	DD	$L67422
	DD	$L67449
	DD	$L67404
	DD	$L67431
	DD	$L67449
	DD	$L67413
	DD	$L67440
?Child_WindowProc@@YGJPAUHWND__@@IIJ@Z ENDP		; Child_WindowProc
_TEXT	ENDS
EXTRN	__imp__PostMessageA@16:NEAR
;	COMDAT ?Child_Create@MAIN@@QAEHPAUHWND__@@PAUtagCREATESTRUCTA@@@Z
_TEXT	SEGMENT
_childhwnd$ = 8
_this$ = -4
?Child_Create@MAIN@@QAEHPAUHWND__@@PAUtagCREATESTRUCTA@@@Z PROC NEAR ; MAIN::Child_Create, COMDAT

; 461  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 462  : 	ChildHwnd = childhwnd;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _childhwnd$[ebp]
	mov	DWORD PTR [eax+96], ecx

; 463  : 	Val->Controls->hWnd = ChildHwnd;

	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	eax, DWORD PTR [edx+60]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+96]
	mov	DWORD PTR [eax+68], edx

; 464  : 
; 465  : 	DeleteMenu(GetSystemMenu(ChildHwnd, FALSE),  SC_MOVE, MF_BYCOMMAND);

	push	0
	push	61456					; 0000f010H
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+96]
	push	ecx
	call	DWORD PTR __imp__GetSystemMenu@8
	push	eax
	call	DWORD PTR __imp__DeleteMenu@12

; 466  : 	DeleteMenu(GetSystemMenu(ChildHwnd, FALSE),  SC_SIZE, MF_BYCOMMAND);

	push	0
	push	61440					; 0000f000H
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+96]
	push	eax
	call	DWORD PTR __imp__GetSystemMenu@8
	push	eax
	call	DWORD PTR __imp__DeleteMenu@12

; 467  : 
; 468  : 	PostMessage(MainHwnd, WM_START, 0, 0);

	push	0
	push	0
	push	1024					; 00000400H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+88]
	push	edx
	call	DWORD PTR __imp__PostMessageA@16

; 469  : 	return TRUE;

	mov	eax, 1

; 470  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?Child_Create@MAIN@@QAEHPAUHWND__@@PAUtagCREATESTRUCTA@@@Z ENDP ; MAIN::Child_Create
_TEXT	ENDS
;	COMDAT ?Child_Destroy@MAIN@@QAEXPAUHWND__@@@Z
_TEXT	SEGMENT
_hwnd$ = 8
_this$ = -4
?Child_Destroy@MAIN@@QAEXPAUHWND__@@@Z PROC NEAR	; MAIN::Child_Destroy, COMDAT

; 473  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 474  : 	Main_Destroy(hwnd);

	mov	eax, DWORD PTR _hwnd$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?Main_Destroy@MAIN@@QAEXPAUHWND__@@@Z	; MAIN::Main_Destroy

; 475  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?Child_Destroy@MAIN@@QAEXPAUHWND__@@@Z ENDP		; MAIN::Child_Destroy
_TEXT	ENDS
;	COMDAT ?Child_Paint@MAIN@@QAEXPAUHWND__@@@Z
_TEXT	SEGMENT
_hwnd$ = 8
_this$ = -4
_PaintStruct$ = -68
_PaintDC$ = -72
?Child_Paint@MAIN@@QAEXPAUHWND__@@@Z PROC NEAR		; MAIN::Child_Paint, COMDAT

; 478  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 136				; 00000088H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 479  : 	PAINTSTRUCT PaintStruct;
; 480  : 	HDC PaintDC = BeginPaint(hwnd, &PaintStruct);

	lea	eax, DWORD PTR _PaintStruct$[ebp]
	push	eax
	mov	ecx, DWORD PTR _hwnd$[ebp]
	push	ecx
	call	DWORD PTR __imp__BeginPaint@8
	mov	DWORD PTR _PaintDC$[ebp], eax

; 481  : // Insert paint stuff hear
; 482  : 	EndPaint(hwnd, &PaintStruct);

	lea	edx, DWORD PTR _PaintStruct$[ebp]
	push	edx
	mov	eax, DWORD PTR _hwnd$[ebp]
	push	eax
	call	DWORD PTR __imp__EndPaint@8

; 483  : //
; 484  : 	Val->Display->Re_Draw = RE_ALL;

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+64]
	mov	eax, DWORD PTR [edx+52]
	and	al, -4					; fffffffcH
	or	al, 2
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+64]
	mov	DWORD PTR [edx+52], eax

; 485  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?Child_Paint@MAIN@@QAEXPAUHWND__@@@Z ENDP		; MAIN::Child_Paint
_TEXT	ENDS
PUBLIC	??_C@_04BOOC@MAIN?$AA@				; `string'
PUBLIC	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ		; MAIN::Get_MainHwnd
PUBLIC	?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z	; ERRORCLASS::ReSetError_Format
PUBLIC	?Error@ERRORCLASS@@QAA_NPADZZ			; ERRORCLASS::Error
PUBLIC	??_C@_0BC@EBLG@?$CFs?3?$CFs?9?$DOError?5?$DN?5?$CFs?$AA@ ; `string'
PUBLIC	??_C@_0BO@MCCM@Could?5not?5recover?5from?5error?4?$AA@ ; `string'
PUBLIC	??_C@_05IMKO@Start?$AA@				; `string'
PUBLIC	?CreateLoops@VALUES@@QAE_NXZ			; VALUES::CreateLoops
PUBLIC	?StartLoops@VALUES@@QAE_NXZ			; VALUES::StartLoops
EXTRN	__imp__GetCurrentProcess@0:NEAR
EXTRN	__imp__GetCurrentThread@0:NEAR
EXTRN	__imp__SetThreadPriority@8:NEAR
EXTRN	?DebugProc@@YGHPAUHWND__@@IIJ@Z:NEAR		; DebugProc
EXTRN	__imp__SetPriorityClass@8:NEAR
EXTRN	__imp__InitCommonControls@0:NEAR
EXTRN	__imp__DialogBoxParamA@20:NEAR
EXTRN	?Setup_Display@DISPLAY@@QAE_NPAUtagRECT@@_N@Z:NEAR ; DISPLAY::Setup_Display
;	COMDAT ??_C@_04BOOC@MAIN?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\main.cpp
CONST	SEGMENT
??_C@_04BOOC@MAIN?$AA@ DB 'MAIN', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@EBLG@?$CFs?3?$CFs?9?$DOError?5?$DN?5?$CFs?$AA@
CONST	SEGMENT
??_C@_0BC@EBLG@?$CFs?3?$CFs?9?$DOError?5?$DN?5?$CFs?$AA@ DB '%s:%s->Error'
	DB	' = %s', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BO@MCCM@Could?5not?5recover?5from?5error?4?$AA@
CONST	SEGMENT
??_C@_0BO@MCCM@Could?5not?5recover?5from?5error?4?$AA@ DB 'Could not reco'
	DB	'ver from error.', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_05IMKO@Start?$AA@
CONST	SEGMENT
??_C@_05IMKO@Start?$AA@ DB 'Start', 00H			; `string'
CONST	ENDS
;	COMDAT ?Start@MAIN@@QAEXPAUHWND__@@@Z
_TEXT	SEGMENT
_this$ = -4
?Start@MAIN@@QAEXPAUHWND__@@@Z PROC NEAR		; MAIN::Start, COMDAT

; 491  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 492  : 	Val->Controls->ChildRect = ChildRect;

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 72					; 00000048H
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+60]
	add	edx, 72					; 00000048H
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR [edx+4], ecx
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [edx+8], ecx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [edx+12], eax

; 493  : 
; 494  : 	if( Val->Display->Setup_Display(&ChildRect, data.UseDX) )

	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+56]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 72					; 00000048H
	push	eax
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [ecx+64]
	call	?Setup_Display@DISPLAY@@QAE_NPAUtagRECT@@_N@Z ; DISPLAY::Setup_Display
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L67469

; 496  : 		SetError_Format("%s:%s->Error = %s");

	push	OFFSET FLAT:??_C@_0BC@EBLG@?$CFs?3?$CFs?9?$DOError?5?$DN?5?$CFs?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetError_Format@ERRORCLASS@@QAEXPAD@Z	; ERRORCLASS::SetError_Format

; 497  : 		Error(NULL, "MAIN", "Start", "Could not recover from error.");

	push	OFFSET FLAT:??_C@_0BO@MCCM@Could?5not?5recover?5from?5error?4?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_05IMKO@Start?$AA@	; `string'
	push	OFFSET FLAT:??_C@_04BOOC@MAIN?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H

; 498  : 		ReSetError_Format();

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z ; ERRORCLASS::ReSetError_Format

; 499  : 		PostMessage(Val->Main->Get_MainHwnd(), WM_END, 0, 0);

	push	0
	push	0
	push	1025					; 00000401H
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+56]
	call	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ	; MAIN::Get_MainHwnd
	push	eax
	call	DWORD PTR __imp__PostMessageA@16

; 500  : 		return;

	jmp	$L67468
$L67469:

; 502  : 
; 503  : 	//NORMAL_PRIORITY_CLASS
; 504  : 	//THREAD_PRIORITY_NORMAL
; 505  : 	//REALTIME_PRIORITY_CLASS
; 506  : 	//THREAD_PRIORITY_HIGHEST
; 507  : 	SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);

	push	32					; 00000020H
	call	DWORD PTR __imp__GetCurrentProcess@0
	push	eax
	call	DWORD PTR __imp__SetPriorityClass@8

; 508  : 	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_NORMAL);

	push	0
	call	DWORD PTR __imp__GetCurrentThread@0
	push	eax
	call	DWORD PTR __imp__SetThreadPriority@8

; 509  : 
; 510  : 	// Create
; 511  : 	if(	Val->CreateLoops() )

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	call	?CreateLoops@VALUES@@QAE_NXZ		; VALUES::CreateLoops
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L67473

; 513  : 		PostMessage(Val->Main->Get_MainHwnd(), WM_END, 0, 0);

	push	0
	push	0
	push	1025					; 00000401H
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [ecx+56]
	call	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ	; MAIN::Get_MainHwnd
	push	eax
	call	DWORD PTR __imp__PostMessageA@16

; 514  : 		return;

	jmp	SHORT $L67468
$L67473:

; 516  : 
; 517  : 	// Start
; 518  : 	if(	Val->StartLoops() )

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	call	?StartLoops@VALUES@@QAE_NXZ		; VALUES::StartLoops
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L67474

; 520  : 		PostMessage(Val->Main->Get_MainHwnd(), WM_END, 0, 0);

	push	0
	push	0
	push	1025					; 00000401H
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+56]
	call	?Get_MainHwnd@MAIN@@QAEPAUHWND__@@XZ	; MAIN::Get_MainHwnd
	push	eax
	call	DWORD PTR __imp__PostMessageA@16

; 521  : 		return;

	jmp	SHORT $L67468
$L67474:

; 523  : 
; 524  : #ifdef _DEBUG
; 525  : 	InitCommonControls();

	call	DWORD PTR __imp__InitCommonControls@0

; 526  : 	DialogBox(MainhInst, MAKEINTRESOURCE(IDD_DEBUG), NULL, (DLGPROC)DebugProc);

	push	0
	push	OFFSET FLAT:?DebugProc@@YGHPAUHWND__@@IIJ@Z ; DebugProc
	push	0
	push	110					; 0000006eH
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+92]
	push	ecx
	call	DWORD PTR __imp__DialogBoxParamA@20
$L67468:

; 527  : #endif
; 528  : 
; 529  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?Start@MAIN@@QAEXPAUHWND__@@@Z ENDP			; MAIN::Start
_TEXT	ENDS
;	COMDAT ?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z
_TEXT	SEGMENT
$T67789 = -8
_n$ = 8
_this$ = -4
?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z PROC NEAR	; ERRORCLASS::ReSetError_Format, COMDAT

; 98   : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 99   : 			if(PrevMsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+4], 0
	je	SHORT $L34649

; 101  : 				MsgFormat = new char[strlen(PrevMsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T67789[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T67789[ebp]
	mov	DWORD PTR [eax], ecx

; 102  : 				strcpy(MsgFormat, PrevMsgFormat);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+4]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8
$L34649:

; 104  : 			return n;

	mov	al, BYTE PTR _n$[ebp]

; 105  : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z ENDP		; ERRORCLASS::ReSetError_Format
_TEXT	ENDS
PUBLIC	?GetType@ERRORCLASS@@AAEHH@Z			; ERRORCLASS::GetType
PUBLIC	??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ ; `string'
PUBLIC	??_C@_05CKBG@Error?$AA@				; `string'
EXTRN	__imp__MessageBoxA@16:NEAR
EXTRN	_vsprintf:NEAR
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
$T67792 = -268
$T67793 = -272
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
	je	SHORT $L34656

; 114  : 				if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L34657

; 116  : 					PrevMsgFormat = new char[strlen(MsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T67792[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T67792[ebp]
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
$L34657:

; 119  : 
; 120  : 				MsgFormat = new char[strlen(m)];

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T67793[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T67793[ebp]
	mov	DWORD PTR [ecx], edx

; 121  : 				strcpy(MsgFormat, m);

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8
$L34656:

; 123  : 
; 124  : 			if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L34662

; 126  : 				if(strlen(MsgFormat) > 0)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	test	eax, eax
	jbe	SHORT $L34663

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

	jmp	SHORT $L34668
$L34663:

; 133  : 					strcpy(mTemp, "Problem with error message.");

	push	OFFSET FLAT:??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ ; `string'
	lea	edx, DWORD PTR _mTemp$[ebp]
	push	edx
	call	_strcpy
	add	esp, 8
$L34668:

; 135  : 			else

	jmp	SHORT $L34670
$L34662:

; 136  : 				return 1;

	mov	al, 1
	jmp	$L34677
$L34670:

; 137  : 
; 138  : 			if(Type < 0)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	and	ecx, 3
	test	ecx, ecx
	jae	SHORT $L34671

; 139  : 				Type = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	al, -4					; fffffffcH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+8], eax
$L34671:

; 140  : 			
; 141  : 			if(hWnd == NULL)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+12], 0
	jne	SHORT $L34672

; 142  : 				hWnd = GetDesktopWindow();

	call	DWORD PTR __imp__GetDesktopWindow@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L34672:

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
	je	SHORT $L34676
	cmp	DWORD PTR _Ok$[ebp], 7
	je	SHORT $L34676
	cmp	DWORD PTR _Ok$[ebp], 2
	jne	SHORT $L34675
$L34676:

; 147  : 				return 1;

	mov	al, 1
	jmp	SHORT $L34677
$L34675:

; 149  : 				return 0;

	xor	al, al
$L34677:

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
	jne	SHORT $L34596

; 32   : 				return MB_OK;

	xor	eax, eax
	jmp	SHORT $L34601
$L34596:

; 33   : 			else if(Type == ETYPE_YESNO)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	eax, 3
	cmp	eax, 1
	jne	SHORT $L34598

; 34   : 				return MB_YESNO;

	mov	eax, 4
	jmp	SHORT $L34601
$L34598:

; 35   : 			else if(Type == ETYPE_RETRY)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	and	edx, 3
	cmp	edx, 2
	jne	SHORT $L34600

; 36   : 				return MB_RETRYCANCEL;

	mov	eax, 5
	jmp	SHORT $L34601
$L34600:

; 38   : 				return MB_OK;

	xor	eax, eax
$L34601:

; 39   : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?GetType@ERRORCLASS@@AAEHH@Z ENDP			; ERRORCLASS::GetType
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
PUBLIC	?Loop@MAIN@@QAE_NXZ				; MAIN::Loop
PUBLIC	?Loop@TestSpeed@@QAEXXZ				; TestSpeed::Loop
PUBLIC	??_C@_09OFON@LevelProc?$AA@			; `string'
EXTRN	?ReFresh@DEBUGCLASS@@QAEXXZ:NEAR		; DEBUGCLASS::ReFresh
EXTRN	?End@DEBUGCLASS@@QAEXXZ:NEAR			; DEBUGCLASS::End
EXTRN	__imp__WaitForSingleObject@8:NEAR
EXTRN	?Joy_Loop@CONTROLS@@QAEXXZ:NEAR			; CONTROLS::Joy_Loop
EXTRN	?Key_Loop@CONTROLS@@QAEXXZ:NEAR			; CONTROLS::Key_Loop
EXTRN	?Sys_Loop@CONTROLS@@QAEXXZ:NEAR			; CONTROLS::Sys_Loop
EXTRN	__imp__GetTickCount@0:NEAR
EXTRN	?LoadProc@@YGHPAUHWND__@@IIJ@Z:NEAR		; LoadProc
EXTRN	?FreeGfx@DISPLAY@@QAE_NXZ:NEAR			; DISPLAY::FreeGfx
EXTRN	?DrawScreen@DISPLAY@@QAE_NXZ:NEAR		; DISPLAY::DrawScreen
EXTRN	__imp__SetCursor@4:NEAR
;	COMDAT ??_C@_09OFON@LevelProc?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\main.cpp
CONST	SEGMENT
??_C@_09OFON@LevelProc?$AA@ DB 'LevelProc', 00H		; `string'
CONST	ENDS
;	COMDAT ?Loop@MAIN@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
_hThread$ = -8
_OldC$67488 = -12
?Loop@MAIN@@QAE_NXZ PROC NEAR				; MAIN::Loop, COMDAT

; 534  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 100				; 00000064H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 535  : 	LoadLevel = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+37], 0

; 536  : 	Val->Game->gData.LevelNum = 0;

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+76]
	mov	WORD PTR [edx+16], 0

; 537  : 
; 538  : 	HANDLE hThread = GetCurrentThread();

	call	DWORD PTR __imp__GetCurrentThread@0
	mov	DWORD PTR _hThread$[ebp], eax

; 539  : //	CRITICAL_SECTION cs;
; 540  : //	InitializeCriticalSection(&cs);
; 541  : 
; 542  : 	Val->Display->StartLayer = NULL;

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+64]
	mov	DWORD PTR [ecx+200], 0
$L67485:

; 543  : 
; 544  : 	while(ThreadLoop == 0)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+48]
	and	eax, 3
	test	eax, eax
	jne	$END$67504

; 546  : //		EnterCriticalSection(&cs);
; 547  : 
; 548  : 		if(!LoadLevel)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+37]
	test	edx, edx
	jne	SHORT $L67487

; 550  : 			HCURSOR OldC = SetCursor( LoadCursor(NULL, IDC_WAIT) );

	push	32514					; 00007f02H
	push	0
	call	DWORD PTR __imp__LoadCursorA@8
	push	eax
	call	DWORD PTR __imp__SetCursor@4
	mov	DWORD PTR _OldC$67488[ebp], eax

; 551  : 			//
; 552  : 
; 553  : 			DialogBox(MainhInst, MAKEINTRESOURCE(IDD_LOADLEVEL), NULL, (DLGPROC)LoadProc);

	push	0
	push	OFFSET FLAT:?LoadProc@@YGHPAUHWND__@@IIJ@Z ; LoadProc
	push	0
	push	194					; 000000c2H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+92]
	push	ecx
	call	DWORD PTR __imp__DialogBoxParamA@20

; 554  : 
; 555  : 			//
; 556  : 			SetCursor(OldC);

	mov	edx, DWORD PTR _OldC$67488[ebp]
	push	edx
	call	DWORD PTR __imp__SetCursor@4

; 557  : 			ReSetError_Format();

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z ; ERRORCLASS::ReSetError_Format

; 558  : 			LoadLevel = true;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+37], 1

; 560  : 		else

	jmp	$L67496
$L67487:

; 562  : 			tick = GetTickCount();

	call	DWORD PTR __imp__GetTickCount@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+32], eax

; 563  : 			Val->Controls->Sys_Loop();

	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+60]
	call	?Sys_Loop@CONTROLS@@QAEXXZ		; CONTROLS::Sys_Loop

; 564  : 			Val->Controls->Key_Loop();

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+60]
	call	?Key_Loop@CONTROLS@@QAEXXZ		; CONTROLS::Key_Loop

; 565  : 			Val->Controls->Joy_Loop();

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [ecx+60]
	call	?Joy_Loop@CONTROLS@@QAEXXZ		; CONTROLS::Joy_Loop

; 566  : 			tick = GetTickCount() - tick;

	call	DWORD PTR __imp__GetTickCount@0
	mov	edx, DWORD PTR _this$[ebp]
	sub	eax, DWORD PTR [edx+32]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+32], eax

; 567  : 			if(tick > 0)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+32], 0
	jbe	SHORT $L67497

; 568  : 				controls_rate = (float)( 1000/tick );

	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, 1000				; 000003e8H
	xor	edx, edx
	div	DWORD PTR [ecx+32]
	mov	DWORD PTR -20+[ebp], eax
	mov	DWORD PTR -20+[ebp+4], 0
	fild	QWORD PTR -20+[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	fstp	DWORD PTR [edx+28]

; 569  : 			else

	jmp	SHORT $L67499
$L67497:

; 570  : 				controls_rate = (float)(1000);

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+28], 1148846080		; 447a0000H
$L67499:

; 571  : 
; 572  : 			tick = GetTickCount();

	call	DWORD PTR __imp__GetTickCount@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+32], eax

; 573  : 			if(LevelProc != NULL)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+44], 0
	je	SHORT $L67501

; 575  : 				if( e = (* LevelProc)(Val, Val->Size))

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	call	DWORD PTR [eax+44]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L67502

; 577  : 					Error(NULL, "MAIN", "LevelProc", e);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_09OFON@LevelProc?$AA@	; `string'
	push	OFFSET FLAT:??_C@_04BOOC@MAIN?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H

; 578  : 					goto END;

	jmp	$L67505
$L67502:

; 581  : 			else

	jmp	SHORT $L67506
$L67501:

; 583  : 				Error(NULL, "MAIN", "LevelProc", e);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_09OFON@LevelProc?$AA@	; `string'
	push	OFFSET FLAT:??_C@_04BOOC@MAIN?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H

; 584  : 				goto END;

	jmp	$L67507
$L67506:

; 586  : 			tick = GetTickCount() - tick;

	call	DWORD PTR __imp__GetTickCount@0
	mov	ecx, DWORD PTR _this$[ebp]
	sub	eax, DWORD PTR [ecx+32]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+32], eax

; 587  : 			if(tick > 0)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+32], 0
	jbe	SHORT $L67508

; 588  : 				level_rate = (float)( 1000/tick );

	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, 1000				; 000003e8H
	xor	edx, edx
	div	DWORD PTR [ecx+32]
	mov	DWORD PTR -28+[ebp], eax
	mov	DWORD PTR -28+[ebp+4], 0
	fild	QWORD PTR -28+[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	fstp	DWORD PTR [edx+20]

; 589  : 			else

	jmp	SHORT $L67510
$L67508:

; 590  : 				level_rate = (float)(1000);

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+20], 1148846080		; 447a0000H
$L67510:

; 591  : 
; 592  : 			tick = GetTickCount();

	call	DWORD PTR __imp__GetTickCount@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+32], eax

; 593  : 			Val->Display->DrawScreen();

	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+64]
	call	?DrawScreen@DISPLAY@@QAE_NXZ		; DISPLAY::DrawScreen

; 594  : 			tick = GetTickCount() - tick;

	call	DWORD PTR __imp__GetTickCount@0
	mov	ecx, DWORD PTR _this$[ebp]
	sub	eax, DWORD PTR [ecx+32]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+32], eax

; 595  : 			if(tick > 0)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+32], 0
	jbe	SHORT $L67512

; 596  : 				display_rate = (float)( 1000/tick );

	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, 1000				; 000003e8H
	xor	edx, edx
	div	DWORD PTR [ecx+32]
	mov	DWORD PTR -36+[ebp], eax
	mov	DWORD PTR -36+[ebp+4], 0
	fild	QWORD PTR -36+[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	fstp	DWORD PTR [edx+24]

; 597  : 			else

	jmp	SHORT $L67514
$L67512:

; 598  : 				display_rate = (float)(1000);

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+24], 1148846080		; 447a0000H
$L67514:

; 599  : 
; 600  : 			#ifdef _DEBUG
; 601  : 				tsMain.Loop();

	mov	ecx, OFFSET FLAT:?tsMain@@3VTestSpeed@@A
	call	?Loop@TestSpeed@@QAEXXZ			; TestSpeed::Loop

; 602  : 				Debug.ReFresh();

	mov	ecx, OFFSET FLAT:?Debug@@3VDEBUGCLASS@@A
	call	?ReFresh@DEBUGCLASS@@QAEXXZ		; DEBUGCLASS::ReFresh
$L67496:

; 606  : 
; 607  : //		LeaveCriticalSection(&cs);
; 608  : 		if(data.Delay)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+52]
	test	edx, edx
	je	SHORT $L67516

; 609  : 			WaitForSingleObject(hThread, data.Delay);

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+52]
	push	ecx
	mov	edx, DWORD PTR _hThread$[ebp]
	push	edx
	call	DWORD PTR __imp__WaitForSingleObject@8
$L67516:

; 610  : 	}

	jmp	$L67485
$END$67504:

; 611  : 
; 612  : END:
; 613  : 
; 614  : //	ThreadLoop = 2;
; 615  : 
; 616  : 	Val->Display->FreeGfx();

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+64]
	call	?FreeGfx@DISPLAY@@QAE_NXZ		; DISPLAY::FreeGfx

; 617  : 
; 618  : 	// test speed
; 619  : 	#ifdef _DEBUG
; 620  : 		Debug.End();

	mov	ecx, OFFSET FLAT:?Debug@@3VDEBUGCLASS@@A
	call	?End@DEBUGCLASS@@QAEXXZ			; DEBUGCLASS::End

; 621  : 	#endif
; 622  : 	//
; 623  : 
; 624  : 	PostMessage(MainHwnd, WM_END, 0, 0);

	push	0
	push	0
	push	1025					; 00000401H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+88]
	push	edx
	call	DWORD PTR __imp__PostMessageA@16

; 625  : 	return 0;

	xor	al, al
	jmp	SHORT $L67482
$L67507:

; 626  : }

	jmp	SHORT $END$67504
$L67505:
	jmp	SHORT $END$67504
$L67482:
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Loop@MAIN@@QAE_NXZ ENDP				; MAIN::Loop
_TEXT	ENDS
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
	jne	SHORT $L67141

; 60   : 					Start = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+28], 0

; 61   : 					TickCount = Tick1;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR [ecx+32], eax
$L67141:

; 63   : 
; 64   : 				if( (Tick1 - TickCount) > 100)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+16]
	sub	eax, DWORD PTR [edx+32]
	cmp	eax, 100				; 00000064H
	jbe	SHORT $L67142

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
$L67142:

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
;	COMDAT ?Main_Destroy@MAIN@@QAEXPAUHWND__@@@Z
_TEXT	SEGMENT
_this$ = -4
?Main_Destroy@MAIN@@QAEXPAUHWND__@@@Z PROC NEAR		; MAIN::Main_Destroy, COMDAT

; 631  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 632  : 	if(!Closing)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+36]
	test	ecx, ecx
	jne	SHORT $L67521

; 634  : 		Closing = 1;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+36], 1

; 635  : 		ThreadLoop = 1;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	and	ecx, -4					; fffffffcH
	or	ecx, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+48], ecx
$L67521:

; 638  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?Main_Destroy@MAIN@@QAEXPAUHWND__@@@Z ENDP		; MAIN::Main_Destroy
_TEXT	ENDS
PUBLIC	?FreeAll@VALUES@@QAE_NXZ			; VALUES::FreeAll
EXTRN	__imp__PostQuitMessage@4:NEAR
EXTRN	__imp__GlobalReAlloc@12:NEAR
EXTRN	__imp__GlobalUnlock@4:NEAR
;	COMDAT ?End@@YAXPAUHWND__@@@Z
_TEXT	SEGMENT
?End@@YAXPAUHWND__@@@Z PROC NEAR			; End, COMDAT

; 641  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi

; 642  : 	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_NORMAL);

	push	0
	call	DWORD PTR __imp__GetCurrentThread@0
	push	eax
	call	DWORD PTR __imp__SetThreadPriority@8

; 643  : 	SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);

	push	32					; 00000020H
	call	DWORD PTR __imp__GetCurrentProcess@0
	push	eax
	call	DWORD PTR __imp__SetPriorityClass@8

; 644  : 
; 645  : 	Val->FreeAll();

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	call	?FreeAll@VALUES@@QAE_NXZ		; VALUES::FreeAll

; 646  : 
; 647  : 	GlobalUnlock(hVal);

	mov	eax, DWORD PTR ?hVal@@3PAXA		; hVal
	push	eax
	call	DWORD PTR __imp__GlobalUnlock@4

; 648  : 	GlobalDiscard(hVal);

	push	2
	push	0
	mov	ecx, DWORD PTR ?hVal@@3PAXA		; hVal
	push	ecx
	call	DWORD PTR __imp__GlobalReAlloc@12

; 649  : 
; 650  : 	PostQuitMessage(0);

	push	0
	call	DWORD PTR __imp__PostQuitMessage@4

; 651  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?End@@YAXPAUHWND__@@@Z ENDP				; End
_TEXT	ENDS
PUBLIC	?Main_ThreadProc@@YGKPAX@Z			; Main_ThreadProc
;	COMDAT ?Main_ThreadProc@@YGKPAX@Z
_TEXT	SEGMENT
?Main_ThreadProc@@YGKPAX@Z PROC NEAR			; Main_ThreadProc, COMDAT

; 657  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	ebx
	push	esi
	push	edi

; 658  : 	return Val->Main->Loop();

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+56]
	call	?Loop@MAIN@@QAE_NXZ			; MAIN::Loop
	and	eax, 255				; 000000ffH

; 659  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?Main_ThreadProc@@YGKPAX@Z ENDP				; Main_ThreadProc
_TEXT	ENDS
PUBLIC	?Load@MAIN@@QAEXXZ				; MAIN::Load
PUBLIC	??_C@_03BGOI@dll?$AA@				; `string'
PUBLIC	??_C@_0BI@OKAL@?$CFs?2levels?2level?$CF0?43d?4?$CFs?$AA@ ; `string'
PUBLIC	??_C@_0BE@NKK@Could?5not?5load?5file?$AA@	; `string'
PUBLIC	??_C@_0BB@HJCJ@MAIN?3LoadLibrary?$AA@		; `string'
PUBLIC	??_C@_0P@MLGD@LoadDefaultVar?$AA@		; `string'
PUBLIC	??_C@_0BI@OIOL@Level?5incorrect?5Version?$AA@	; `string'
PUBLIC	??_C@_0P@ENHG@MAIN?3LevelProc?$AA@		; `string'
PUBLIC	??_C@_0BJ@IFHB@?$CFs?3?6?5?$CFs?4?6?5Error?5?$DN?5?$CFd?0?5?$CFd?$AA@ ; `string'
PUBLIC	??_C@_0BO@MACO@Could?5not?5find?5LoadDefaultVar?$AA@ ; `string'
PUBLIC	??_C@_0BE@CEKK@MAIN?3GetProcAddress?$AA@	; `string'
PUBLIC	??_C@_09FHA@LevelCode?$AA@			; `string'
PUBLIC	??_C@_0BJ@CKEK@Could?5not?5find?5LevelCode?$AA@	; `string'
EXTRN	__imp__LoadLibraryA@4:NEAR
EXTRN	__imp__GetCurrentDirectoryA@8:NEAR
EXTRN	__imp__GetProcAddress@8:NEAR
EXTRN	_sprintf:NEAR
;	COMDAT ??_C@_03BGOI@dll?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\main.cpp
CONST	SEGMENT
??_C@_03BGOI@dll?$AA@ DB 'dll', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@OKAL@?$CFs?2levels?2level?$CF0?43d?4?$CFs?$AA@
CONST	SEGMENT
??_C@_0BI@OKAL@?$CFs?2levels?2level?$CF0?43d?4?$CFs?$AA@ DB '%s\levels\le'
	DB	'vel%0.3d.%s', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@NKK@Could?5not?5load?5file?$AA@
CONST	SEGMENT
??_C@_0BE@NKK@Could?5not?5load?5file?$AA@ DB 'Could not load file', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@HJCJ@MAIN?3LoadLibrary?$AA@
CONST	SEGMENT
??_C@_0BB@HJCJ@MAIN?3LoadLibrary?$AA@ DB 'MAIN:LoadLibrary', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@MLGD@LoadDefaultVar?$AA@
CONST	SEGMENT
??_C@_0P@MLGD@LoadDefaultVar?$AA@ DB 'LoadDefaultVar', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@OIOL@Level?5incorrect?5Version?$AA@
CONST	SEGMENT
??_C@_0BI@OIOL@Level?5incorrect?5Version?$AA@ DB 'Level incorrect Version'
	DB	00H						; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@ENHG@MAIN?3LevelProc?$AA@
CONST	SEGMENT
??_C@_0P@ENHG@MAIN?3LevelProc?$AA@ DB 'MAIN:LevelProc', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BJ@IFHB@?$CFs?3?6?5?$CFs?4?6?5Error?5?$DN?5?$CFd?0?5?$CFd?$AA@
CONST	SEGMENT
??_C@_0BJ@IFHB@?$CFs?3?6?5?$CFs?4?6?5Error?5?$DN?5?$CFd?0?5?$CFd?$AA@ DB '%'
	DB	's:', 0aH, ' %s.', 0aH, ' Error = %d, %d', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BO@MACO@Could?5not?5find?5LoadDefaultVar?$AA@
CONST	SEGMENT
??_C@_0BO@MACO@Could?5not?5find?5LoadDefaultVar?$AA@ DB 'Could not find L'
	DB	'oadDefaultVar', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@CEKK@MAIN?3GetProcAddress?$AA@
CONST	SEGMENT
??_C@_0BE@CEKK@MAIN?3GetProcAddress?$AA@ DB 'MAIN:GetProcAddress', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_09FHA@LevelCode?$AA@
CONST	SEGMENT
??_C@_09FHA@LevelCode?$AA@ DB 'LevelCode', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BJ@CKEK@Could?5not?5find?5LevelCode?$AA@
CONST	SEGMENT
??_C@_0BJ@CKEK@Could?5not?5find?5LevelCode?$AA@ DB 'Could not find LevelC'
	DB	'ode', 00H					; `string'
CONST	ENDS
;	COMDAT ?Load@MAIN@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
_S$ = -260
_dir$ = -516
?Load@MAIN@@QAEXXZ PROC NEAR				; MAIN::Load, COMDAT

; 662  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 580				; 00000244H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 663  : 	char  S[256], dir[256];
; 664  : 	GetCurrentDirectory(255, dir);

	lea	eax, DWORD PTR _dir$[ebp]
	push	eax
	push	255					; 000000ffH
	call	DWORD PTR __imp__GetCurrentDirectoryA@8

; 665  : 	sprintf(S, "%s\\levels\\level%0.3d.%s", dir, Val->Game->gData.LevelNum, FILE_EXT_LEVEL);

	push	OFFSET FLAT:??_C@_03BGOI@dll?$AA@	; `string'
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+76]
	xor	eax, eax
	mov	ax, WORD PTR [edx+16]
	push	eax
	lea	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@OKAL@?$CFs?2levels?2level?$CF0?43d?4?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$[ebp]
	push	edx
	call	_sprintf
	add	esp, 20					; 00000014H

; 666  : 	//SetError_Format("%s:\n %s(%s).\n Error = %d");
; 667  : 
; 668  : 		if((hLevel = LoadLibrary(S)) == NULL)

	lea	eax, DWORD PTR _S$[ebp]
	push	eax
	call	DWORD PTR __imp__LoadLibraryA@4
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+40], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+40], 0
	jne	SHORT $L67536

; 670  : 			Error(NULL, "MAIN:LoadLibrary", "Could not load file", S, GetLastError() );

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	lea	eax, DWORD PTR _S$[ebp]
	push	eax
	push	OFFSET FLAT:??_C@_0BE@NKK@Could?5not?5load?5file?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_0BB@HJCJ@MAIN?3LoadLibrary?$AA@ ; `string'
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	push	ecx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 24					; 00000018H

; 671  : 			ReSetError_Format();

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z ; ERRORCLASS::ReSetError_Format

; 672  : 			goto END;

	jmp	$L67540
$L67536:

; 674  : 
; 675  : 		if((Val->Main->LevelProc = (LEVELPROC)GetProcAddress(hLevel, "LoadDefaultVar")) != NULL )

	push	OFFSET FLAT:??_C@_0P@MLGD@LoadDefaultVar?$AA@ ; `string'
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+40]
	push	eax
	call	DWORD PTR __imp__GetProcAddress@8
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+56]
	mov	DWORD PTR [edx+44], eax
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+56]
	cmp	DWORD PTR [ecx+44], 0
	je	SHORT $L67542

; 677  : 			e = (* LevelProc)(Val, Val->Size);

	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	eax, DWORD PTR [edx+48]
	push	eax
	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	call	DWORD PTR [edx+44]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax

; 678  : 			if(e)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L67544

; 680  : 				Error("%s:\n %s.\n Error = %d, %d", "MAIN:LevelProc", "Level incorrect Version", e, Val->Size);

	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0BI@OIOL@Level?5incorrect?5Version?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_0P@ENHG@MAIN?3LevelProc?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_0BJ@IFHB@?$CFs?3?6?5?$CFs?4?6?5Error?5?$DN?5?$CFd?0?5?$CFd?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	push	ecx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 24					; 00000018H

; 681  : 				ReSetError_Format();

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z ; ERRORCLASS::ReSetError_Format

; 682  : 				goto END;

	jmp	$L67548
$L67544:

; 685  : 		else

	jmp	SHORT $L67549
$L67542:

; 687  : 			Error(NULL, "MAIN:GetProcAddress", "Could not find LoadDefaultVar", S, GetLastError() );

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	lea	edx, DWORD PTR _S$[ebp]
	push	edx
	push	OFFSET FLAT:??_C@_0BO@MACO@Could?5not?5find?5LoadDefaultVar?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_0BE@CEKK@MAIN?3GetProcAddress?$AA@ ; `string'
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	push	eax
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 24					; 00000018H

; 688  : 			ReSetError_Format();

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z ; ERRORCLASS::ReSetError_Format

; 689  : 			goto END;

	jmp	$L67552
$L67549:

; 691  : 
; 692  : 		if((LevelProc = (LEVELPROC)GetProcAddress(hLevel, "LevelCode")) == NULL )

	push	OFFSET FLAT:??_C@_09FHA@LevelCode?$AA@	; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	push	edx
	call	DWORD PTR __imp__GetProcAddress@8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+44], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+44], 0
	jne	SHORT $L67554

; 694  : 			Error(NULL, "MAIN:GetProcAddress", "Could not find LevelCode", S, GetLastError() );

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	lea	eax, DWORD PTR _S$[ebp]
	push	eax
	push	OFFSET FLAT:??_C@_0BJ@CKEK@Could?5not?5find?5LevelCode?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_0BE@CEKK@MAIN?3GetProcAddress?$AA@ ; `string'
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	push	ecx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 24					; 00000018H

; 695  : 			ReSetError_Format();

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z ; ERRORCLASS::ReSetError_Format

; 696  : 			goto END;

	jmp	SHORT $L67557
$L67554:

; 698  : 
; 699  : return;

	jmp	SHORT $L67531
$END$67539:

; 700  : 
; 701  : END:
; 702  : 	Val->Display->FreeGfx();

	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+64]
	call	?FreeGfx@DISPLAY@@QAE_NXZ		; DISPLAY::FreeGfx

; 703  : 
; 704  : 	// test speed
; 705  : 	#ifdef _DEBUG
; 706  : 		Debug.End();

	mov	ecx, OFFSET FLAT:?Debug@@3VDEBUGCLASS@@A
	call	?End@DEBUGCLASS@@QAEXXZ			; DEBUGCLASS::End

; 707  : 	#endif
; 708  : 	//
; 709  : 
; 710  : 	PostMessage(MainHwnd, WM_END, 0, 0);

	push	0
	push	0
	push	1025					; 00000401H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+88]
	push	ecx
	call	DWORD PTR __imp__PostMessageA@16

; 711  : }

	jmp	SHORT $L67531
$L67557:
	jmp	SHORT $END$67539
$L67552:
	jmp	SHORT $END$67539
$L67548:
	jmp	SHORT $END$67539
$L67540:
	jmp	SHORT $END$67539
$L67531:
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Load@MAIN@@QAEXXZ ENDP					; MAIN::Load
_TEXT	ENDS
PUBLIC	??_C@_0BE@OKMG@LoadAll?3GlobalAlloc?$AA@	; `string'
PUBLIC	??_C@_06KGMH@VALUES?$AA@			; `string'
PUBLIC	??_C@_0BD@ENLL@LoadAll?3GlobalLock?$AA@		; `string'
PUBLIC	?SetError_Format@ERRORCLASS@@QAEX_E@Z		; ERRORCLASS::SetError_Format
EXTRN	?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z:NEAR	; FILE_UTIL::LoadMem
;	COMDAT ??_C@_0BE@OKMG@LoadAll?3GlobalAlloc?$AA@
; File d:\game programming\moggie software games\old code\old skull x\header files\valuesclass.h
CONST	SEGMENT
??_C@_0BE@OKMG@LoadAll?3GlobalAlloc?$AA@ DB 'LoadAll:GlobalAlloc', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_06KGMH@VALUES?$AA@
CONST	SEGMENT
??_C@_06KGMH@VALUES?$AA@ DB 'VALUES', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@ENLL@LoadAll?3GlobalLock?$AA@
CONST	SEGMENT
??_C@_0BD@ENLL@LoadAll?3GlobalLock?$AA@ DB 'LoadAll:GlobalLock', 00H ; `string'
CONST	ENDS
;	COMDAT ?LoadAll@VALUES@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
?LoadAll@VALUES@@QAE_NXZ PROC NEAR			; VALUES::LoadAll, COMDAT

; 93   : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 94   : 			SetLastError(0);

	push	0
	call	DWORD PTR __imp__SetLastError@4

; 95   : 			SetError_Format();

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetError_Format@ERRORCLASS@@QAEX_E@Z	; ERRORCLASS::SetError_Format

; 96   : 
; 97   : 			hFile_Util = GlobalAlloc(GHND, sizeof(FILE_UTIL) );

	push	24					; 00000018H
	push	66					; 00000042H
	call	DWORD PTR __imp__GlobalAlloc@8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax

; 98   : 			if(GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L66581

; 99   : 				return Error(NULL, "VALUES", "LoadAll:GlobalAlloc", GetLastError() );

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BE@OKMG@LoadAll?3GlobalAlloc?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_06KGMH@VALUES?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	$L66579
$L66581:

; 100  : 
; 101  : 			File_Util = (FILE_UTIL*)GlobalLock(hFile_Util);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	call	DWORD PTR __imp__GlobalLock@4
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+52], eax

; 102  : 			if(GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L66585

; 103  : 				return Error(NULL, "VALUES", "LoadAll:GlobalLock", GetLastError() );

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BD@ENLL@LoadAll?3GlobalLock?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_06KGMH@VALUES?$AA@	; `string'
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	push	eax
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	$L66579
$L66585:

; 104  : 
; 105  : 			if(File_Util->LoadMem( (HGLOBAL &)Main, hMain, sizeof(MAIN) ) )

	push	0
	push	100					; 00000064H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 20					; 00000014H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 56					; 00000038H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	call	?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z	; FILE_UTIL::LoadMem
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66589

; 106  : 				return 1;

	mov	al, 1
	jmp	$L66579
$L66589:

; 107  : 
; 108  : 			if(File_Util->LoadMem( (HGLOBAL &)Controls, hControls, sizeof(CONTROLS) ) )

	push	0
	push	164					; 000000a4H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 24					; 00000018H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 60					; 0000003cH
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	call	?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z	; FILE_UTIL::LoadMem
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66592

; 109  : 				return 1;

	mov	al, 1
	jmp	$L66579
$L66592:

; 110  : 
; 111  : 			if(File_Util->LoadMem( (HGLOBAL &)Display, hDisplay, sizeof(DISPLAY) ) )

	push	0
	push	376					; 00000178H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 28					; 0000001cH
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 64					; 00000040H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	call	?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z	; FILE_UTIL::LoadMem
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66595

; 112  : 				return 1;

	mov	al, 1
	jmp	$L66579
$L66595:

; 113  : 
; 114  : 			if(File_Util->LoadMem( (HGLOBAL &)Action, hAction, sizeof(ACTION) ) )

	push	0
	push	60					; 0000003cH
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 32					; 00000020H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 68					; 00000044H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	call	?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z	; FILE_UTIL::LoadMem
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66598

; 115  : 				return 1;

	mov	al, 1
	jmp	SHORT $L66579
$L66598:

; 116  : 
; 117  : 			if(File_Util->LoadMem( (HGLOBAL &)Sound, hSound, sizeof(SOUND) ) )

	push	0
	push	28					; 0000001cH
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 36					; 00000024H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 72					; 00000048H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	call	?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z	; FILE_UTIL::LoadMem
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66601

; 118  : 				return 1;

	mov	al, 1
	jmp	SHORT $L66579
$L66601:

; 119  : 
; 120  : 			if(File_Util->LoadMem( (HGLOBAL &)Game, hGame, sizeof(GAME) ) )

	push	0
	push	32					; 00000020H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 40					; 00000028H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 76					; 0000004cH
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	call	?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z	; FILE_UTIL::LoadMem
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66604

; 121  : 				return 1;

	mov	al, 1
	jmp	SHORT $L66579
$L66604:

; 122  : 			
; 123  : 			return 0;

	xor	al, al
$L66579:

; 124  : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?LoadAll@VALUES@@QAE_NXZ ENDP				; VALUES::LoadAll
_TEXT	ENDS
PUBLIC	??_C@_0CB@HOKB@Class?3?5?$CFs?6Function?3?5?$CFs?6Error?3?5?$CFd@ ; `string'
PUBLIC	??_C@_0CE@JLCM@Class?3?$CFs?5?$HM?$HM?5Function?3?$CFs?5?$HM?$HM?5Error@ ; `string'
PUBLIC	??_C@_0CG@NHNF@Class?3?$CC?$CFs?$CC?5?$HM?$HM?5Function?3?$CFs?5?$HM?$HM?5Err@ ; `string'
PUBLIC	??_C@_0BF@OBLP@?$CFs?3?3?$CFs?5?$HM?$HM?5Error?5?$DN?5?$CFd?$AA@ ; `string'
PUBLIC	??_C@_0BC@BKHE@Error?5?9?5?$CFs?5?$CFs?$CI?$CFd?$CJ?$AA@ ; `string'
;	COMDAT ??_C@_0CB@HOKB@Class?3?5?$CFs?6Function?3?5?$CFs?6Error?3?5?$CFd@
; File d:\game programming\moggie software games\old code\old skull x\header files\errorclass.h
CONST	SEGMENT
??_C@_0CB@HOKB@Class?3?5?$CFs?6Function?3?5?$CFs?6Error?3?5?$CFd@ DB 'Cla'
	DB	'ss: %s', 0aH, 'Function: %s', 0aH, 'Error: %d', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0CE@JLCM@Class?3?$CFs?5?$HM?$HM?5Function?3?$CFs?5?$HM?$HM?5Error@
CONST	SEGMENT
??_C@_0CE@JLCM@Class?3?$CFs?5?$HM?$HM?5Function?3?$CFs?5?$HM?$HM?5Error@ DB 'C'
	DB	'lass:%s || Function:%s || Error:%d', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0CG@NHNF@Class?3?$CC?$CFs?$CC?5?$HM?$HM?5Function?3?$CFs?5?$HM?$HM?5Err@
CONST	SEGMENT
??_C@_0CG@NHNF@Class?3?$CC?$CFs?$CC?5?$HM?$HM?5Function?3?$CFs?5?$HM?$HM?5Err@ DB 'C'
	DB	'lass:"%s" || Function:%s || Error:%d', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@OBLP@?$CFs?3?3?$CFs?5?$HM?$HM?5Error?5?$DN?5?$CFd?$AA@
CONST	SEGMENT
??_C@_0BF@OBLP@?$CFs?3?3?$CFs?5?$HM?$HM?5Error?5?$DN?5?$CFd?$AA@ DB '%s::'
	DB	'%s || Error = %d', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@BKHE@Error?5?9?5?$CFs?5?$CFs?$CI?$CFd?$CJ?$AA@
CONST	SEGMENT
??_C@_0BC@BKHE@Error?5?9?5?$CFs?5?$CFs?$CI?$CFd?$CJ?$AA@ DB 'Error - %s %'
	DB	's(%d)', 00H					; `string'
CONST	ENDS
;	COMDAT ?SetError_Format@ERRORCLASS@@QAEX_E@Z
_TEXT	SEGMENT
$T67814 = -72
$T67815 = -76
_n$ = 8
_this$ = -4
_Temp$ = -68
?SetError_Format@ERRORCLASS@@QAEX_E@Z PROC NEAR		; ERRORCLASS::SetError_Format, COMDAT

; 59   : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 140				; 0000008cH
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 60   : 			if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L34616

; 62   : 				PrevMsgFormat = new char[strlen(MsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T67814[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T67814[ebp]
	mov	DWORD PTR [eax+4], ecx

; 63   : 				strcpy(PrevMsgFormat, MsgFormat);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	call	_strcpy
	add	esp, 8
$L34616:

; 67   : 						if(n == 0)	strcpy(Temp, "Class: %s\nFunction: %s\nError: %d");

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	test	eax, eax
	jne	SHORT $L34620
	push	OFFSET FLAT:??_C@_0CB@HOKB@Class?3?5?$CFs?6Function?3?5?$CFs?6Error?3?5?$CFd@ ; `string'
	lea	ecx, DWORD PTR _Temp$[ebp]
	push	ecx
	call	_strcpy
	add	esp, 8

; 68   : 			else	if(n == 1)	strcpy(Temp, "Class:%s || Function:%s || Error:%d");

	jmp	SHORT $L34631
$L34620:
	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 255				; 000000ffH
	cmp	edx, 1
	jne	SHORT $L34623
	push	OFFSET FLAT:??_C@_0CE@JLCM@Class?3?$CFs?5?$HM?$HM?5Function?3?$CFs?5?$HM?$HM?5Error@ ; `string'
	lea	eax, DWORD PTR _Temp$[ebp]
	push	eax
	call	_strcpy
	add	esp, 8

; 69   : 			else	if(n == 2)	strcpy(Temp, "Class:\"%s\" || Function:%s || Error:%d");

	jmp	SHORT $L34631
$L34623:
	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 255				; 000000ffH
	cmp	ecx, 2
	jne	SHORT $L34626
	push	OFFSET FLAT:??_C@_0CG@NHNF@Class?3?$CC?$CFs?$CC?5?$HM?$HM?5Function?3?$CFs?5?$HM?$HM?5Err@ ; `string'
	lea	edx, DWORD PTR _Temp$[ebp]
	push	edx
	call	_strcpy
	add	esp, 8

; 70   : 			else	if(n == 3)	strcpy(Temp, "%s::%s || Error = %d");

	jmp	SHORT $L34631
$L34626:
	mov	eax, DWORD PTR _n$[ebp]
	and	eax, 255				; 000000ffH
	cmp	eax, 3
	jne	SHORT $L34629
	push	OFFSET FLAT:??_C@_0BF@OBLP@?$CFs?3?3?$CFs?5?$HM?$HM?5Error?5?$DN?5?$CFd?$AA@ ; `string'
	lea	ecx, DWORD PTR _Temp$[ebp]
	push	ecx
	call	_strcpy
	add	esp, 8

; 71   : 			else							strcpy(Temp, "Error - %s %s(%d)");

	jmp	SHORT $L34631
$L34629:
	push	OFFSET FLAT:??_C@_0BC@BKHE@Error?5?9?5?$CFs?5?$CFs?$CI?$CFd?$CJ?$AA@ ; `string'
	lea	edx, DWORD PTR _Temp$[ebp]
	push	edx
	call	_strcpy
	add	esp, 8
$L34631:

; 72   : 
; 73   : 			MsgFormat = new char[strlen(Temp)];

	lea	eax, DWORD PTR _Temp$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T67815[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T67815[ebp]
	mov	DWORD PTR [ecx], edx

; 74   : 			strcpy(MsgFormat, Temp);

	lea	eax, DWORD PTR _Temp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8

; 75   : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?SetError_Format@ERRORCLASS@@QAEX_E@Z ENDP		; ERRORCLASS::SetError_Format
_TEXT	ENDS
PUBLIC	??_C@_0BF@LKEM@FreeAll?3GlobalUnlock?$AA@	; `string'
PUBLIC	??_C@_0BG@MPEO@FreeAll?3GlobalDiscard?$AA@	; `string'
EXTRN	?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z:NEAR	; FILE_UTIL::FreeMem
;	COMDAT ??_C@_0BF@LKEM@FreeAll?3GlobalUnlock?$AA@
; File d:\game programming\moggie software games\old code\old skull x\header files\valuesclass.h
CONST	SEGMENT
??_C@_0BF@LKEM@FreeAll?3GlobalUnlock?$AA@ DB 'FreeAll:GlobalUnlock', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BG@MPEO@FreeAll?3GlobalDiscard?$AA@
CONST	SEGMENT
??_C@_0BG@MPEO@FreeAll?3GlobalDiscard?$AA@ DB 'FreeAll:GlobalDiscard', 00H ; `string'
CONST	ENDS
;	COMDAT ?FreeAll@VALUES@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
?FreeAll@VALUES@@QAE_NXZ PROC NEAR			; VALUES::FreeAll, COMDAT

; 127  : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 128  : 			if( File_Util->FreeMem(hMain) )

	push	0
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 20					; 00000014H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+52]
	call	?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z	; FILE_UTIL::FreeMem
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66607

; 129  : 				return 1;

	mov	al, 1
	jmp	$L66606
$L66607:

; 130  : 
; 131  : 			if( File_Util->FreeMem(hControls) )

	push	0
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 24					; 00000018H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	call	?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z	; FILE_UTIL::FreeMem
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66608

; 132  : 				return 1;

	mov	al, 1
	jmp	$L66606
$L66608:

; 133  : 
; 134  : 			if( File_Util->FreeMem(hDisplay) )

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 28					; 0000001cH
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+52]
	call	?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z	; FILE_UTIL::FreeMem
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66609

; 135  : 				return 1;

	mov	al, 1
	jmp	$L66606
$L66609:

; 136  : 
; 137  : 			if( File_Util->FreeMem(hAction) )

	push	0
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 32					; 00000020H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+52]
	call	?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z	; FILE_UTIL::FreeMem
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66610

; 138  : 				return 1;

	mov	al, 1
	jmp	$L66606
$L66610:

; 139  : 
; 140  : 			if( File_Util->FreeMem(hSound) )

	push	0
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 36					; 00000024H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	call	?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z	; FILE_UTIL::FreeMem
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66611

; 141  : 				return 1;

	mov	al, 1
	jmp	SHORT $L66606
$L66611:

; 142  : 
; 143  : 			GlobalUnlock(hFile_Util);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	call	DWORD PTR __imp__GlobalUnlock@4

; 144  : 			if( GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L66612

; 145  : 				return Error(NULL, "VALUES", "FreeAll:GlobalUnlock", GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BF@LKEM@FreeAll?3GlobalUnlock?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_06KGMH@VALUES?$AA@	; `string'
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	push	eax
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L66606
$L66612:

; 146  : 
; 147  : 			GlobalDiscard(hFile_Util);

	push	2
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	call	DWORD PTR __imp__GlobalReAlloc@12

; 148  : 
; 149  : 			if( GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L66614

; 150  : 				return Error(NULL, "VALUES", "FreeAll:GlobalDiscard", GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BG@MPEO@FreeAll?3GlobalDiscard?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_06KGMH@VALUES?$AA@	; `string'
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	push	eax
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L66606
$L66614:

; 151  : 
; 152  : 			return 0;

	xor	al, al
$L66606:

; 153  : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?FreeAll@VALUES@@QAE_NXZ ENDP				; VALUES::FreeAll
_TEXT	ENDS
PUBLIC	?InitError@ERRORCLASS@@QAEXXZ			; ERRORCLASS::InitError
;	COMDAT ?InitObjects@VALUES@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
?InitObjects@VALUES@@QAEXXZ PROC NEAR			; VALUES::InitObjects, COMDAT

; 156  : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 157  : 			InitError();

	mov	ecx, DWORD PTR _this$[ebp]
	call	?InitError@ERRORCLASS@@QAEXXZ		; ERRORCLASS::InitError

; 158  : 			File_Util->InitError();

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	call	?InitError@ERRORCLASS@@QAEXXZ		; ERRORCLASS::InitError

; 159  : 			Main->InitError();

	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+56]
	call	?InitError@ERRORCLASS@@QAEXXZ		; ERRORCLASS::InitError

; 160  : 			Controls->InitError();

	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+60]
	call	?InitError@ERRORCLASS@@QAEXXZ		; ERRORCLASS::InitError

; 161  : 			Display->InitError();

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+64]
	call	?InitError@ERRORCLASS@@QAEXXZ		; ERRORCLASS::InitError

; 162  : 			Action->InitError();

	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+68]
	call	?InitError@ERRORCLASS@@QAEXXZ		; ERRORCLASS::InitError

; 163  : 			Sound->InitError();

	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+72]
	call	?InitError@ERRORCLASS@@QAEXXZ		; ERRORCLASS::InitError

; 164  : 		}

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?InitObjects@VALUES@@QAEXXZ ENDP			; VALUES::InitObjects
_TEXT	ENDS
;	COMDAT ?InitError@ERRORCLASS@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
?InitError@ERRORCLASS@@QAEXXZ PROC NEAR			; ERRORCLASS::InitError, COMDAT

; 43   : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 44   : 			MsgFormat = NULL;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax], 0

; 45   : 			PrevMsgFormat = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+4], 0

; 46   : 			SetError_Format();

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetError_Format@ERRORCLASS@@QAEX_E@Z	; ERRORCLASS::SetError_Format

; 47   : 			Type = ETYPE_OK;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	al, -4					; fffffffcH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+8], eax

; 48   : 			hWnd = GetDesktopWindow();

	call	DWORD PTR __imp__GetDesktopWindow@0
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+12], eax

; 49   : 		}

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?InitError@ERRORCLASS@@QAEXXZ ENDP			; ERRORCLASS::InitError
_TEXT	ENDS
PUBLIC	?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z	; VALUES::cLoop
PUBLIC	?Get_DelayRes@MAIN@@QAEGXZ			; MAIN::Get_DelayRes
;	COMDAT ?CreateLoops@VALUES@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
?CreateLoops@VALUES@@QAE_NXZ PROC NEAR			; VALUES::CreateLoops, COMDAT

; 175  : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 176  : 			if( cLoop(Main_hThread,			Main_ThreadProc,			"MAIN",			Main->Get_DelayRes() ) )

	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	call	?Get_DelayRes@MAIN@@QAEGXZ		; MAIN::Get_DelayRes
	and	eax, 65535				; 0000ffffH
	push	eax
	push	OFFSET FLAT:??_C@_04BOOC@MAIN?$AA@	; `string'
	push	OFFSET FLAT:?Main_ThreadProc@@YGKPAX@Z	; Main_ThreadProc
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 44					; 0000002cH
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z ; VALUES::cLoop
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66620

; 177  : 				return 1;

	mov	al, 1
	jmp	SHORT $L66619
$L66620:

; 178  : 
; 179  : 			return 0;

	xor	al, al
$L66619:

; 180  : 		}

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?CreateLoops@VALUES@@QAE_NXZ ENDP			; VALUES::CreateLoops
_TEXT	ENDS
;	COMDAT ?Get_DelayRes@MAIN@@QAEGXZ
_TEXT	SEGMENT
_this$ = -4
?Get_DelayRes@MAIN@@QAEGXZ PROC NEAR			; MAIN::Get_DelayRes, COMDAT

; 91   : 		unsigned short Get_DelayRes(void){return data.DelayRes;};

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ax, WORD PTR [eax+54]
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Get_DelayRes@MAIN@@QAEGXZ ENDP				; MAIN::Get_DelayRes
_TEXT	ENDS
PUBLIC	?sLoop@VALUES@@QAE_NAAPAXPAD@Z			; VALUES::sLoop
PUBLIC	??_C@_0BI@KDDN@CreateLoop?3Main_hThread?$AA@	; `string'
;	COMDAT ??_C@_0BI@KDDN@CreateLoop?3Main_hThread?$AA@
; File d:\game programming\moggie software games\old code\old skull x\header files\valuesclass.h
CONST	SEGMENT
??_C@_0BI@KDDN@CreateLoop?3Main_hThread?$AA@ DB 'CreateLoop:Main_hThread', 00H ; `string'
CONST	ENDS
;	COMDAT ?StartLoops@VALUES@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
_loop$ = -8
_hThread$ = -12
?StartLoops@VALUES@@QAE_NXZ PROC NEAR			; VALUES::StartLoops, COMDAT

; 183  : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 76					; 0000004cH
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 184  : 			if(Main_hThread)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+44], 0
	je	SHORT $L66625

; 186  : 				if( sLoop(Main_hThread, "MAIN") )

	push	OFFSET FLAT:??_C@_04BOOC@MAIN?$AA@	; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 44					; 0000002cH
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?sLoop@VALUES@@QAE_NAAPAXPAD@Z		; VALUES::sLoop
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66625

; 188  : 					Main_hThread = NULL;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+44], 0

; 189  : 					/*
; 190  : 					Display_hThread = NULL;
; 191  : 					Action_hThread = NULL;
; 192  : 					Controls_hThread = NULL;
; 193  : 					Sound_hThread = NULL;
; 194  : 					*/
; 195  : 					return 1;

	mov	al, 1
	jmp	SHORT $L66623
$L66625:

; 198  : 
; 199  : 			bool loop = 1;

	mov	BYTE PTR _loop$[ebp], 1

; 200  : 			HANDLE hThread = GetCurrentThread();

	call	DWORD PTR __imp__GetCurrentThread@0
	mov	DWORD PTR _hThread$[ebp], eax
$L66629:

; 201  : 			while(loop)

	mov	eax, DWORD PTR _loop$[ebp]
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L66630

; 203  : 				WaitForSingleObject(hThread, 500);

	push	500					; 000001f4H
	mov	ecx, DWORD PTR _hThread$[ebp]
	push	ecx
	call	DWORD PTR __imp__WaitForSingleObject@8

; 204  : 				if(Main->LoadLevel == 1)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+37]
	cmp	ecx, 1
	jne	SHORT $L66631

; 205  : 					loop = 0;

	mov	BYTE PTR _loop$[ebp], 0

; 206  : 				else if(Main->ThreadLoop == 2)

	jmp	SHORT $L66633
$L66631:
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR [eax+48]
	and	ecx, 3
	cmp	ecx, 2
	jne	SHORT $L66633

; 208  : 					Error(NULL, "VALUES", "CreateLoop:Main_hThread", 100);

	push	100					; 00000064H
	push	OFFSET FLAT:??_C@_0BI@KDDN@CreateLoop?3Main_hThread?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_06KGMH@VALUES?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H

; 209  : 					/*
; 210  : 					Display_hThread = NULL;
; 211  : 					Action_hThread = NULL;
; 212  : 					Controls_hThread = NULL;
; 213  : 					Sound_hThread = NULL;
; 214  : 					*/
; 215  : 					return 1;

	mov	al, 1
	jmp	SHORT $L66623
$L66633:

; 217  : 			}

	jmp	SHORT $L66629
$L66630:

; 218  : 
; 219  : 			return 0;

	xor	al, al
$L66623:

; 220  : 		}

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?StartLoops@VALUES@@QAE_NXZ ENDP			; VALUES::StartLoops
_TEXT	ENDS
PUBLIC	??_C@_0BI@PFPA@StartLoops?3ResumeThread?$AA@	; `string'
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
	je	SHORT $L66641

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
	jmp	SHORT $L66640
$L66641:

; 246  : 
; 247  : 			return 0;

	xor	al, al
$L66640:

; 248  : 		}

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?sLoop@VALUES@@QAE_NAAPAXPAD@Z ENDP			; VALUES::sLoop
_TEXT	ENDS
PUBLIC	??_C@_0BJ@HCNJ@CreateLoops?3CreateThread?$AA@	; `string'
PUBLIC	??_C@_0BN@DFAJ@CreateLoop?3SetThreadPriority?$AA@ ; `string'
PUBLIC	??_C@_0BL@HMPM@CreateLoop?3InvalidPriority?$AA@	; `string'
EXTRN	__imp__CreateThread@24:NEAR
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
	je	SHORT $L66646

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
	jmp	$L66644
$L66646:

; 260  : 					(p == THREAD_PRIORITY_LOWEST) ||
; 261  : 					(p == THREAD_PRIORITY_BELOW_NORMAL) ||
; 262  : 					(p == THREAD_PRIORITY_NORMAL) ||
; 263  : 					(p == THREAD_PRIORITY_ABOVE_NORMAL) ||
; 264  : 					(p == THREAD_PRIORITY_HIGHEST) ||
; 265  : 					(p == THREAD_PRIORITY_TIME_CRITICAL) )

	cmp	DWORD PTR _p$[ebp], -15			; fffffff1H
	je	SHORT $L66649
	cmp	DWORD PTR _p$[ebp], -2			; fffffffeH
	je	SHORT $L66649
	cmp	DWORD PTR _p$[ebp], -1
	je	SHORT $L66649
	cmp	DWORD PTR _p$[ebp], 0
	je	SHORT $L66649
	cmp	DWORD PTR _p$[ebp], 1
	je	SHORT $L66649
	cmp	DWORD PTR _p$[ebp], 2
	je	SHORT $L66649
	cmp	DWORD PTR _p$[ebp], 15			; 0000000fH
	jne	SHORT $L66648
$L66649:

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
	je	SHORT $L66650

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
	jmp	SHORT $L66644
$L66650:

; 271  : 			else

	jmp	SHORT $L66652
$L66648:

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
	jmp	SHORT $L66644
$L66652:

; 273  : 
; 274  : 			return 0;

	xor	al, al
$L66644:

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
