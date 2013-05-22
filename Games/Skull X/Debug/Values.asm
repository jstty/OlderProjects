	TITLE	D:\Game Programming\Moggie Software Games\old code\old Skull X\C++ Files\Values.cpp
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
;	COMDAT ??_C@_09BGFH@Setup?4ini?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BN@HCCH@Create?5File?5Error?5?$CD?5?$CFd?5?3?5?$CFd?5?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BL@JKLO@Read?5File?5Error?5?$CD?5?$CFd?5?3?5?$CFd?5?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0CM@MKFN@Could?5not?5Load?5setup?5file?4?5Loadi@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_09OBJG@LoadSetup?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0M@LINN@?$CFs?3?3?$CFs?5?6?5?$CFs?$AA@
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
;	COMDAT ?Set_data@MAIN@@QAEXVMainVar@@@Z
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
;	COMDAT ?Set_data@DISPLAY@@QAEXVDisplayVar@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Set_data@ACTION@@QAEXVActionVar@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Set_data@SOUND@@QAEXVSoundVar@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?sLoop@VALUES@@QAE_NAAPAXPAD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?LoadSetup@VALUES@@QAE_NPAUSETUPFILE@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetGlobal@VALUES@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?LoadSetup@VALUES@@QAE_NPAUSETUPFILE@@@Z	; VALUES::LoadSetup
PUBLIC	??_C@_09BGFH@Setup?4ini?$AA@			; `string'
PUBLIC	??_C@_0BN@HCCH@Create?5File?5Error?5?$CD?5?$CFd?5?3?5?$CFd?5?$AA@ ; `string'
PUBLIC	??_C@_0BL@JKLO@Read?5File?5Error?5?$CD?5?$CFd?5?3?5?$CFd?5?$AA@ ; `string'
PUBLIC	?Error@ERRORCLASS@@QAA_NPADZZ			; ERRORCLASS::Error
EXTRN	__imp__CreateFileA@28:NEAR
EXTRN	__imp__GetLastError@0:NEAR
EXTRN	__imp__ReadFile@20:NEAR
EXTRN	__imp__CloseHandle@4:NEAR
;	COMDAT ??_C@_09BGFH@Setup?4ini?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\values.cpp
CONST	SEGMENT
??_C@_09BGFH@Setup?4ini?$AA@ DB 'Setup.ini', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BN@HCCH@Create?5File?5Error?5?$CD?5?$CFd?5?3?5?$CFd?5?$AA@
CONST	SEGMENT
??_C@_0BN@HCCH@Create?5File?5Error?5?$CD?5?$CFd?5?3?5?$CFd?5?$AA@ DB 'Cre'
	DB	'ate File Error # %d : %d ', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BL@JKLO@Read?5File?5Error?5?$CD?5?$CFd?5?3?5?$CFd?5?$AA@
CONST	SEGMENT
??_C@_0BL@JKLO@Read?5File?5Error?5?$CD?5?$CFd?5?3?5?$CFd?5?$AA@ DB 'Read '
	DB	'File Error # %d : %d ', 00H			; `string'
CONST	ENDS
;	COMDAT ?LoadSetup@VALUES@@QAE_NPAUSETUPFILE@@@Z
_TEXT	SEGMENT
_f$ = 8
_this$ = -4
_hFile$ = -8
_NumberRead$ = -12
_Size$ = -16
_GameSetup$ = -124
?LoadSetup@VALUES@@QAE_NPAUSETUPFILE@@@Z PROC NEAR	; VALUES::LoadSetup, COMDAT

; 14   : {	

	push	ebp
	mov	ebp, esp
	sub	esp, 188				; 000000bcH
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 15   : 		HANDLE hFile;
; 16   : 		ULONG NumberRead;
; 17   : 		DWORD Size = 0;

	mov	DWORD PTR _Size$[ebp], 0

; 18   : 
; 19   : 		hFile = CreateFile("Setup.ini", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	push	0
	push	128					; 00000080H
	push	3
	push	0
	push	0
	push	-2147483648				; 80000000H
	push	OFFSET FLAT:??_C@_09BGFH@Setup?4ini?$AA@ ; `string'
	call	DWORD PTR __imp__CreateFileA@28
	mov	DWORD PTR _hFile$[ebp], eax

; 20   : 		if(hFile == NULL)

	cmp	DWORD PTR _hFile$[ebp], 0
	jne	SHORT $L64889

; 22   : 			Error("Create File Error # %d : %d ", 101, GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	101					; 00000065H
	push	OFFSET FLAT:??_C@_0BN@HCCH@Create?5File?5Error?5?$CD?5?$CFd?5?3?5?$CFd?5?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	push	eax
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 16					; 00000010H

; 23   : 			return 1;

	mov	al, 1
	jmp	$L64884
$L64889:

; 28   : 
; 29   : 		Size = sizeof(GAMESETUP);

	mov	DWORD PTR _Size$[ebp], 108		; 0000006cH

; 30   : 		ReadFile( hFile, &GameSetup, Size, &NumberRead, NULL);

	push	0
	lea	ecx, DWORD PTR _NumberRead$[ebp]
	push	ecx
	mov	edx, DWORD PTR _Size$[ebp]
	push	edx
	lea	eax, DWORD PTR _GameSetup$[ebp]
	push	eax
	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__ReadFile@20

; 31   : 		if(NumberRead != Size)

	mov	edx, DWORD PTR _NumberRead$[ebp]
	cmp	edx, DWORD PTR _Size$[ebp]
	je	SHORT $L64893

; 33   : 			Error("Read File Error # %d : %d ", 102, GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	102					; 00000066H
	push	OFFSET FLAT:??_C@_0BL@JKLO@Read?5File?5Error?5?$CD?5?$CFd?5?3?5?$CFd?5?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	push	eax
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 16					; 00000010H

; 34   : 			return 1;

	mov	al, 1
	jmp	$L64884
$L64893:

; 36   : 		//
; 37   : 		CloseHandle(hFile);

	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__CloseHandle@4

; 38   : 
; 39   : 		f->mv.Delay = GameSetup.mv.Delay;

	mov	edx, DWORD PTR _f$[ebp]
	mov	ax, WORD PTR _GameSetup$[ebp+4]
	mov	WORD PTR [edx+2], ax

; 40   : 		f->mv.UseDX = GameSetup.mv.FullScreen;

	mov	ecx, DWORD PTR _f$[ebp]
	mov	dl, BYTE PTR _GameSetup$[ebp+10]
	mov	BYTE PTR [ecx+6], dl

; 41   : 		f->mv.Stretch = GameSetup.mv.Stretch;

	mov	eax, DWORD PTR _f$[ebp]
	mov	cl, BYTE PTR _GameSetup$[ebp+11]
	mov	BYTE PTR [eax+9], cl

; 42   : 		f->mv.InWindow = false;

	mov	edx, DWORD PTR _f$[ebp]
	mov	BYTE PTR [edx+7], 0

; 43   : 		f->mv.FullScreen = false;

	mov	eax, DWORD PTR _f$[ebp]
	mov	BYTE PTR [eax+8], 0

; 44   : 
; 45   : 		if( (f->mv.Stretch) || (f->mv.UseDX) )

	mov	ecx, DWORD PTR _f$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+9]
	test	edx, edx
	jne	SHORT $L64896
	mov	eax, DWORD PTR _f$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+6]
	test	ecx, ecx
	je	SHORT $L64895
$L64896:

; 47   : 			f->dv.xMax = GameSetup.mv.Xmax;

	mov	edx, DWORD PTR _f$[ebp]
	mov	ax, WORD PTR _GameSetup$[ebp+12]
	mov	WORD PTR [edx+44], ax

; 48   : 			f->dv.yMax = GameSetup.mv.Ymax;

	mov	ecx, DWORD PTR _f$[ebp]
	mov	dx, WORD PTR _GameSetup$[ebp+14]
	mov	WORD PTR [ecx+46], dx

; 50   : 		else

	jmp	SHORT $L64897
$L64895:

; 52   : 			f->dv.xMax = D_XRES;

	mov	eax, DWORD PTR _f$[ebp]
	mov	WORD PTR [eax+44], 320			; 00000140H

; 53   : 			f->dv.yMax = D_YRES;

	mov	ecx, DWORD PTR _f$[ebp]
	mov	WORD PTR [ecx+46], 240			; 000000f0H
$L64897:

; 55   : 
; 56   : 		f->dv.bpp = GameSetup.mv.Bpp;

	mov	edx, DWORD PTR _GameSetup$[ebp+16]
	and	edx, 63					; 0000003fH
	mov	eax, DWORD PTR _f$[ebp]
	mov	BYTE PTR [eax+48], dl

; 57   : 
; 58   : 		f->sv.PlayFx = GameSetup.mv.SndFx;

	mov	ecx, DWORD PTR _f$[ebp]
	mov	dl, BYTE PTR _GameSetup$[ebp+9]
	mov	BYTE PTR [ecx+58], dl

; 59   : 		f->sv.PlayMidi = GameSetup.mv.Midi;

	mov	eax, DWORD PTR _f$[ebp]
	mov	cl, BYTE PTR _GameSetup$[ebp+8]
	mov	BYTE PTR [eax+59], cl

; 60   : //
; 61   : // Controls
; 62   : //
; 63   : //
; 64   : /*
; 65   : 		f->cv.NumPlayer = 2;
; 66   : 		f->cv.NumsKey = NUMSYSTEM;
; 67   : 		unsigned __int8 i;
; 68   : 
; 69   : 		f->cv.sKey = new Key[f->cv.NumsKey];
; 70   : 		memset(f->cv.sKey, 0, f->cv.NumsKey*sizeof(Key) );
; 71   : 
; 72   : 		for(i = 0; i < f->cv.NumsKey; i++)
; 73   : 			f->cv.sKey[i].Code = (unsigned char)GameSetup.cv.System[i].Code;
; 74   : 
; 75   : 		f->cv.sKey[0].Code = VK_ESCAPE;
; 76   : //		f->cv.sKey[1].Code = VK_F1;
; 77   : 
; 78   : 		if(GameSetup.cv.KeyPlayer > 0)
; 79   : 			f->cv.kPlayerNum	= GameSetup.cv.KeyPlayer - 1;
; 80   : 		else
; 81   : 			f->cv.kPlayerNum = 0;
; 82   : 
; 83   : 		f->cv.NumpKey = NUMDIRECT + NUMBUTTON;
; 84   : 		f->cv.pKey = new Key[f->cv.NumpKey];
; 85   : 		memset(f->cv.pKey, 0, f->cv.NumpKey*sizeof(Key) );
; 86   : 
; 87   : 		f->cv.pKey[0].Code = (unsigned char)GameSetup.cv.Key[2].Code;
; 88   : 		f->cv.pKey[1].Code = (unsigned char)GameSetup.cv.Key[3].Code;
; 89   : 		f->cv.pKey[2].Code = (unsigned char)GameSetup.cv.Key[0].Code;
; 90   : 		f->cv.pKey[3].Code = (unsigned char)GameSetup.cv.Key[1].Code;
; 91   : 		//
; 92   : 		f->cv.pKey[4].Code = (unsigned char)GameSetup.cv.Key[4].Code;
; 93   : 		f->cv.pKey[5].Code = (unsigned char)GameSetup.cv.Key[5].Code;
; 94   : 		f->cv.pKey[6].Code = (unsigned char)GameSetup.cv.Key[6].Code;
; 95   : 
; 96   : 
; 97   : 		f->cv.NumJoy = 2;
; 98   : 		f->cv.Joy = new JoyStick[f->cv.NumJoy];
; 99   : 		memset(f->cv.Joy, 0, f->cv.NumJoy*sizeof(JoyStick) );
; 100  : 
; 101  : 		i = 0;
; 102  : 		f->cv.Joy[i].Enabled		= GameSetup.cv.EnableJoy1;
; 103  : 
; 104  : 		if(GameSetup.cv.Joy1Player > 0)
; 105  : 			f->cv.Joy[i].PlayerNum	= GameSetup.cv.Joy1Player - 1;
; 106  : 		else
; 107  : 			f->cv.Joy[i].PlayerNum = 0;
; 108  : 
; 109  : 		f->cv.Joy[i].Button[UP]		= UP;
; 110  : 		f->cv.Joy[i].Button[DOWN]	= DOWN;
; 111  : 		f->cv.Joy[i].Button[LEFT]	= LEFT;
; 112  : 		f->cv.Joy[i].Button[RIGHT] = RIGHT;
; 113  : 		f->cv.Joy[i].Button[0]	= GameSetup.cv.bJoy1[0].B > 0 ? GameSetup.cv.bJoy1[0].B - 1 : 0;
; 114  : 		f->cv.Joy[i].Button[1]	= GameSetup.cv.bJoy1[1].B > 0 ? GameSetup.cv.bJoy1[1].B - 1 : 0;
; 115  : 
; 116  : 		i++;
; 117  : 		f->cv.Joy[i].Enabled		= GameSetup.cv.EnableJoy2;
; 118  : 		if(GameSetup.cv.Joy2Player > 0)
; 119  : 			f->cv.Joy[i].PlayerNum	= GameSetup.cv.Joy2Player - 1;
; 120  : 		else
; 121  : 			f->cv.Joy[i].PlayerNum = 0;
; 122  : 
; 123  : 		f->cv.Joy[i].Button[UP]		= UP;
; 124  : 		f->cv.Joy[i].Button[DOWN]	= DOWN;
; 125  : 		f->cv.Joy[i].Button[LEFT]	= LEFT;
; 126  : 		f->cv.Joy[i].Button[RIGHT] = RIGHT;
; 127  : 		f->cv.Joy[i].Button[0]	= GameSetup.cv.bJoy1[0].B > 0 ? GameSetup.cv.bJoy1[0].B - 1 : 0;
; 128  : 		f->cv.Joy[i].Button[1]	= GameSetup.cv.bJoy1[1].B > 0 ? GameSetup.cv.bJoy1[1].B - 1 : 0;
; 129  : */
; 130  : 	return 0;

	xor	al, al
$L64884:

; 131  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?LoadSetup@VALUES@@QAE_NPAUSETUPFILE@@@Z ENDP		; VALUES::LoadSetup
_TEXT	ENDS
PUBLIC	?Set_data@SOUND@@QAEXVSoundVar@@@Z		; SOUND::Set_data
PUBLIC	?Set_data@MAIN@@QAEXVMainVar@@@Z		; MAIN::Set_data
PUBLIC	?Set_data@ACTION@@QAEXVActionVar@@@Z		; ACTION::Set_data
PUBLIC	?SetGlobal@VALUES@@QAEXXZ			; VALUES::SetGlobal
PUBLIC	??_C@_06KGMH@VALUES?$AA@			; `string'
PUBLIC	??_C@_0CM@MKFN@Could?5not?5Load?5setup?5file?4?5Loadi@ ; `string'
PUBLIC	??_C@_09OBJG@LoadSetup?$AA@			; `string'
PUBLIC	??_C@_0M@LINN@?$CFs?3?3?$CFs?5?6?5?$CFs?$AA@	; `string'
PUBLIC	?Set_data@DISPLAY@@QAEXVDisplayVar@@@Z		; DISPLAY::Set_data
EXTRN	_memset:NEAR
EXTRN	?Set_data@CONTROLS@@QAEXUControlVar@@_N@Z:NEAR	; CONTROLS::Set_data
;	COMDAT ??_C@_06KGMH@VALUES?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\values.cpp
CONST	SEGMENT
??_C@_06KGMH@VALUES?$AA@ DB 'VALUES', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0CM@MKFN@Could?5not?5Load?5setup?5file?4?5Loadi@
CONST	SEGMENT
??_C@_0CM@MKFN@Could?5not?5Load?5setup?5file?4?5Loadi@ DB 'Could not Load'
	DB	' setup file. Loading default.', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_09OBJG@LoadSetup?$AA@
CONST	SEGMENT
??_C@_09OBJG@LoadSetup?$AA@ DB 'LoadSetup', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0M@LINN@?$CFs?3?3?$CFs?5?6?5?$CFs?$AA@
CONST	SEGMENT
??_C@_0M@LINN@?$CFs?3?3?$CFs?5?6?5?$CFs?$AA@ DB '%s::%s ', 0aH, ' %s', 00H ; `string'
CONST	ENDS
;	COMDAT ?SetGlobal@VALUES@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
_sf$ = -64
_Load_Default$ = -68
?SetGlobal@VALUES@@QAEXXZ PROC NEAR			; VALUES::SetGlobal, COMDAT

; 134  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 132				; 00000084H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 135  : 		// Load default from .ini
; 136  : 	SETUPFILE sf;
; 137  : 	memset(&sf, 0, sizeof(SETUPFILE));

	push	60					; 0000003cH
	push	0
	lea	eax, DWORD PTR _sf$[ebp]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 138  : 	bool Load_Default = false;

	mov	BYTE PTR _Load_Default$[ebp], 0

; 139  : 
; 140  : 	if( LoadSetup(&sf) )

	lea	ecx, DWORD PTR _sf$[ebp]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?LoadSetup@VALUES@@QAE_NPAUSETUPFILE@@@Z ; VALUES::LoadSetup
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L64905

; 142  : 		Error("%s::%s \n %s", "VALUES", "LoadSetup", "Could not Load setup file. Loading default.");

	push	OFFSET FLAT:??_C@_0CM@MKFN@Could?5not?5Load?5setup?5file?4?5Loadi@ ; `string'
	push	OFFSET FLAT:??_C@_09OBJG@LoadSetup?$AA@	; `string'
	push	OFFSET FLAT:??_C@_06KGMH@VALUES?$AA@	; `string'
	push	OFFSET FLAT:??_C@_0M@LINN@?$CFs?3?3?$CFs?5?6?5?$CFs?$AA@ ; `string'
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H

; 143  : 
; 144  : 		Load_Default = true;

	mov	BYTE PTR _Load_Default$[ebp], 1

; 145  : 		// Default Values
; 146  : 		//////////////////////////////////////////////
; 147  : 		sf.mv.Delay = D_DELAY;

	mov	WORD PTR _sf$[ebp+2], 0

; 148  : 		sf.mv.DelayRes = D_DRES;

	mov	WORD PTR _sf$[ebp+4], 2

; 149  : 		//
; 150  : 		sf.mv.UseDX = D_USEDX;

	mov	BYTE PTR _sf$[ebp+6], 0

; 151  : 		sf.mv.InWindow = D_INWINDOW;

	mov	BYTE PTR _sf$[ebp+7], 0

; 152  : 		sf.mv.FullScreen = D_FULLSCREEN;

	mov	BYTE PTR _sf$[ebp+8], 0

; 153  : 		sf.mv.Stretch = D_STRETCH;

	mov	BYTE PTR _sf$[ebp+9], 1

; 154  : 		//////////////////////////////////////////////
; 155  : //		sf.cv.Delay = D_DELAY;
; 156  : //		sf.cv.DelayRes = D_DRES;
; 157  : 		//////////////////////////////////////////////
; 158  : //		sf.dv.Delay = D_DELAY;
; 159  : //		sf.dv.DelayRes = D_DRES;
; 160  : 		sf.dv.xMax = D_XRES;

	mov	WORD PTR _sf$[ebp+44], 320		; 00000140H

; 161  : 		sf.dv.yMax = D_YRES;

	mov	WORD PTR _sf$[ebp+46], 240		; 000000f0H

; 162  : 		sf.dv.bpp = G_BPP;

	mov	BYTE PTR _sf$[ebp+48], 16		; 00000010H
$L64905:

; 170  : 
; 171  : 	sf.mv.DelayRes = D_DRES;

	mov	WORD PTR _sf$[ebp+4], 2

; 172  : 
; 173  : 	// copy data from SetupFile.MainVar to Main.MainVar
; 174  : 	Main->Set_data(sf.mv);

	mov	eax, DWORD PTR _sf$[ebp+6]
	push	eax
	mov	ecx, DWORD PTR _sf$[ebp+2]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+56]
	call	?Set_data@MAIN@@QAEXVMainVar@@@Z	; MAIN::Set_data

; 175  : 	// always set display before controls because of the mouse pos.
; 176  : 	Display->Set_data(sf.dv);

	sub	esp, 12					; 0000000cH
	mov	eax, esp
	mov	ecx, DWORD PTR _sf$[ebp+40]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _sf$[ebp+44]
	mov	DWORD PTR [eax+4], edx
	mov	cx, WORD PTR _sf$[ebp+48]
	mov	WORD PTR [eax+8], cx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+64]
	call	?Set_data@DISPLAY@@QAEXVDisplayVar@@@Z	; DISPLAY::Set_data

; 177  : 		// copy data from SetupFile.ControlsVar to Main.ControlsVar
; 178  : 	Controls->Set_data(sf.cv, Load_Default);

	mov	al, BYTE PTR _Load_Default$[ebp]
	push	eax
	sub	esp, 28					; 0000001cH
	mov	ecx, 7
	lea	esi, DWORD PTR _sf$[ebp+12]
	mov	edi, esp
	rep movsd
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+60]
	call	?Set_data@CONTROLS@@QAEXUControlVar@@_N@Z ; CONTROLS::Set_data

; 179  : 		//
; 180  : 	Action->Set_data(sf.av);

	mov	edx, DWORD PTR _sf$[ebp+50]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+68]
	call	?Set_data@ACTION@@QAEXVActionVar@@@Z	; ACTION::Set_data

; 181  : 		//
; 182  : 	Sound->Set_data(sf.sv);

	sub	esp, 8
	mov	ecx, esp
	mov	edx, DWORD PTR _sf$[ebp+54]
	mov	DWORD PTR [ecx], edx
	mov	ax, WORD PTR _sf$[ebp+58]
	mov	WORD PTR [ecx+4], ax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+72]
	call	?Set_data@SOUND@@QAEXVSoundVar@@@Z	; SOUND::Set_data

; 183  : 
; 184  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?SetGlobal@VALUES@@QAEXXZ ENDP				; VALUES::SetGlobal
_TEXT	ENDS
PUBLIC	?GetType@ERRORCLASS@@AAEHH@Z			; ERRORCLASS::GetType
PUBLIC	??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ ; `string'
PUBLIC	??_C@_05CKBG@Error?$AA@				; `string'
EXTRN	__imp__MessageBoxA@16:NEAR
EXTRN	??2@YAPAXI@Z:NEAR				; operator new
EXTRN	_strcpy:NEAR
EXTRN	_strlen:NEAR
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
$T64988 = -268
$T64989 = -272
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
	je	SHORT $L54069

; 114  : 				if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L54070

; 116  : 					PrevMsgFormat = new char[strlen(MsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T64988[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T64988[ebp]
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
$L54070:

; 119  : 
; 120  : 				MsgFormat = new char[strlen(m)];

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T64989[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T64989[ebp]
	mov	DWORD PTR [ecx], edx

; 121  : 				strcpy(MsgFormat, m);

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8
$L54069:

; 123  : 
; 124  : 			if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L54075

; 126  : 				if(strlen(MsgFormat) > 0)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	test	eax, eax
	jbe	SHORT $L54076

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

	jmp	SHORT $L54081
$L54076:

; 133  : 					strcpy(mTemp, "Problem with error message.");

	push	OFFSET FLAT:??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ ; `string'
	lea	edx, DWORD PTR _mTemp$[ebp]
	push	edx
	call	_strcpy
	add	esp, 8
$L54081:

; 135  : 			else

	jmp	SHORT $L54083
$L54075:

; 136  : 				return 1;

	mov	al, 1
	jmp	$L54090
$L54083:

; 137  : 
; 138  : 			if(Type < 0)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	and	ecx, 3
	test	ecx, ecx
	jae	SHORT $L54084

; 139  : 				Type = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	al, -4					; fffffffcH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+8], eax
$L54084:

; 140  : 			
; 141  : 			if(hWnd == NULL)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+12], 0
	jne	SHORT $L54085

; 142  : 				hWnd = GetDesktopWindow();

	call	DWORD PTR __imp__GetDesktopWindow@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L54085:

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
	je	SHORT $L54089
	cmp	DWORD PTR _Ok$[ebp], 7
	je	SHORT $L54089
	cmp	DWORD PTR _Ok$[ebp], 2
	jne	SHORT $L54088
$L54089:

; 147  : 				return 1;

	mov	al, 1
	jmp	SHORT $L54090
$L54088:

; 149  : 				return 0;

	xor	al, al
$L54090:

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
	jne	SHORT $L54009

; 32   : 				return MB_OK;

	xor	eax, eax
	jmp	SHORT $L54014
$L54009:

; 33   : 			else if(Type == ETYPE_YESNO)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	eax, 3
	cmp	eax, 1
	jne	SHORT $L54011

; 34   : 				return MB_YESNO;

	mov	eax, 4
	jmp	SHORT $L54014
$L54011:

; 35   : 			else if(Type == ETYPE_RETRY)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	and	edx, 3
	cmp	edx, 2
	jne	SHORT $L54013

; 36   : 				return MB_RETRYCANCEL;

	mov	eax, 5
	jmp	SHORT $L54014
$L54013:

; 38   : 				return MB_OK;

	xor	eax, eax
$L54014:

; 39   : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?GetType@ERRORCLASS@@AAEHH@Z ENDP			; ERRORCLASS::GetType
_TEXT	ENDS
;	COMDAT ?Set_data@MAIN@@QAEXVMainVar@@@Z
_TEXT	SEGMENT
_d$ = 8
_this$ = -4
?Set_data@MAIN@@QAEXVMainVar@@@Z PROC NEAR		; MAIN::Set_data, COMDAT

; 99   : 		void Set_data(MainVar d){ data = d; };

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _d$[ebp]
	mov	DWORD PTR [eax+52], ecx
	mov	edx, DWORD PTR _d$[ebp+4]
	mov	DWORD PTR [eax+56], edx
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?Set_data@MAIN@@QAEXVMainVar@@@Z ENDP			; MAIN::Set_data
_TEXT	ENDS
;	COMDAT ?Set_data@DISPLAY@@QAEXVDisplayVar@@@Z
_TEXT	SEGMENT
_this$ = -4
_v$ = 8
?Set_data@DISPLAY@@QAEXVDisplayVar@@@Z PROC NEAR	; DISPLAY::Set_data, COMDAT

; 53   : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 54   : 			Delay = v.Delay;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cx, WORD PTR _v$[ebp]
	mov	WORD PTR [eax+40], cx

; 55   : 			DelayRes = v.DelayRes;

	mov	edx, DWORD PTR _this$[ebp]
	mov	ax, WORD PTR _v$[ebp+2]
	mov	WORD PTR [edx+42], ax

; 56   : 			xMax = v.xMax;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	dx, WORD PTR _v$[ebp+4]
	mov	WORD PTR [ecx+44], dx

; 57   : 			yMax = v.yMax;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cx, WORD PTR _v$[ebp+6]
	mov	WORD PTR [eax+46], cx

; 58   : 			bpp = v.bpp;

	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR _v$[ebp+8]
	mov	BYTE PTR [edx+48], al

; 59   : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	12					; 0000000cH
?Set_data@DISPLAY@@QAEXVDisplayVar@@@Z ENDP		; DISPLAY::Set_data
_TEXT	ENDS
;	COMDAT ?Set_data@ACTION@@QAEXVActionVar@@@Z
_TEXT	SEGMENT
_v$ = 8
_this$ = -4
?Set_data@ACTION@@QAEXVActionVar@@@Z PROC NEAR		; ACTION::Set_data, COMDAT

; 32   : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 33   : 			Delay = v.Delay;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cx, WORD PTR _v$[ebp]
	mov	WORD PTR [eax+20], cx

; 34   : 			DelayRes = v.DelayRes;

	mov	edx, DWORD PTR _this$[ebp]
	mov	ax, WORD PTR _v$[ebp+2]
	mov	WORD PTR [edx+22], ax

; 35   : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?Set_data@ACTION@@QAEXVActionVar@@@Z ENDP		; ACTION::Set_data
_TEXT	ENDS
;	COMDAT ?Set_data@SOUND@@QAEXVSoundVar@@@Z
_TEXT	SEGMENT
_v$ = 8
_this$ = -4
?Set_data@SOUND@@QAEXVSoundVar@@@Z PROC NEAR		; SOUND::Set_data, COMDAT

; 43   : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 44   : 			Delay = v.Delay;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cx, WORD PTR _v$[ebp]
	mov	WORD PTR [eax+20], cx

; 45   : 			DelayRes = v.DelayRes;

	mov	edx, DWORD PTR _this$[ebp]
	mov	ax, WORD PTR _v$[ebp+2]
	mov	WORD PTR [edx+22], ax

; 46   : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?Set_data@SOUND@@QAEXVSoundVar@@@Z ENDP			; SOUND::Set_data
_TEXT	ENDS
END
