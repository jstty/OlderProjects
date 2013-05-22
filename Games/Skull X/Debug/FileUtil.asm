	TITLE	D:\Game Programming\Moggie Software Games\old code\old Skull X\C++ Files\FileUtil.cpp
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
;	COMDAT ??_C@_0BE@GPC@LoadMem?3GlobalAlloc?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_09LIHE@FILE_UTIL?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@HJJN@LoadMem?3GlobalLock?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BH@BJBH@ReLoadMem?3GlobalUnlock?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@BFDB@ReLoadMem?3GlobalReAlloc?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0O@HEDF@ReLoadMem?3?$DP?$DP?$DP?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@EEKA@FreeMem?3GlobalUnlock?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BG@FDLA@FreeMem?3GlobalDiscard?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0M@HEGK@FreeMem?3?$DP?$DP?$DP?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??8@YAHABU_GUID@@0@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?GetType@ERRORCLASS@@AAEHH@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetError_Format@ERRORCLASS@@QAEX_E@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Error@ERRORCLASS@@QAA_NPADZZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?ReLoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SaveDataFile@FILE_UTIL@@QAEJPADPA_GPAPA_N1_E@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Load_Pointer_DataFile@FILE_UTIL@@QAEJPADPAPA_NPA_G@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Load_NumSize_DataFile@FILE_UTIL@@QAEJPADPA_EPA_G2@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?Error@ERRORCLASS@@QAA_NPADZZ			; ERRORCLASS::Error
PUBLIC	?ReLoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z	; FILE_UTIL::ReLoadMem
PUBLIC	?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z		; FILE_UTIL::LoadMem
PUBLIC	??_C@_0BE@GPC@LoadMem?3GlobalAlloc?$AA@		; `string'
PUBLIC	??_C@_09LIHE@FILE_UTIL?$AA@			; `string'
PUBLIC	??_C@_0BD@HJJN@LoadMem?3GlobalLock?$AA@		; `string'
EXTRN	__imp__GlobalAlloc@8:NEAR
EXTRN	__imp__GlobalLock@4:NEAR
EXTRN	__imp__GetLastError@0:NEAR
EXTRN	__imp__SetLastError@4:NEAR
;	COMDAT ??_C@_0BE@GPC@LoadMem?3GlobalAlloc?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\fileutil.cpp
CONST	SEGMENT
??_C@_0BE@GPC@LoadMem?3GlobalAlloc?$AA@ DB 'LoadMem:GlobalAlloc', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_09LIHE@FILE_UTIL?$AA@
CONST	SEGMENT
??_C@_09LIHE@FILE_UTIL?$AA@ DB 'FILE_UTIL', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@HJJN@LoadMem?3GlobalLock?$AA@
CONST	SEGMENT
??_C@_0BD@HJJN@LoadMem?3GlobalLock?$AA@ DB 'LoadMem:GlobalLock', 00H ; `string'
CONST	ENDS
;	COMDAT ?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z
_TEXT	SEGMENT
_var$ = 8
_hmem$ = 12
_size$ = 16
_lc$ = 20
_this$ = -4
?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z PROC NEAR	; FILE_UTIL::LoadMem, COMDAT

; 17   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 18   : 	SetLastError(0);

	push	0
	call	DWORD PTR __imp__SetLastError@4

; 19   : 
; 20   : 	if(hmem == NULL)

	mov	eax, DWORD PTR _hmem$[ebp]
	cmp	DWORD PTR [eax], 0
	jne	$L54115

; 22   : 		if((&lc) != NULL)

	lea	ecx, DWORD PTR _lc$[ebp]
	test	ecx, ecx
	je	SHORT $L54116

; 23   : 			lc = 0;

	mov	DWORD PTR _lc$[ebp], 0
$L54116:

; 24   : 
; 25   : 		//hmem = GlobalAlloc(GHND, size);
; 26   : 
; 27   : 		//var = GlobalLock(hmem);
; 28   : 
; 29   : 		hmem = GlobalAlloc(GHND, size);

	mov	edx, DWORD PTR _size$[ebp]
	push	edx
	push	66					; 00000042H
	call	DWORD PTR __imp__GlobalAlloc@8
	mov	ecx, DWORD PTR _hmem$[ebp]
	mov	DWORD PTR [ecx], eax

; 30   : 		if( GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L54117

; 31   : 			return Error(NULL, "FILE_UTIL", "LoadMem:GlobalAlloc", GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BE@GPC@LoadMem?3GlobalAlloc?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_09LIHE@FILE_UTIL?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L54114
$L54117:

; 32   : 
; 33   : 		var = GlobalLock(hmem);

	mov	eax, DWORD PTR _hmem$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR __imp__GlobalLock@4
	mov	edx, DWORD PTR _var$[ebp]
	mov	DWORD PTR [edx], eax

; 34   : 		if((&lc) != NULL)

	lea	eax, DWORD PTR _lc$[ebp]
	test	eax, eax
	je	SHORT $L54120

; 35   : 			lc++;

	mov	ecx, DWORD PTR _lc$[ebp]
	add	ecx, 1
	mov	DWORD PTR _lc$[ebp], ecx
$L54120:

; 36   : 
; 37   : 		if( GetLastError() != NO_ERROR )

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L54121

; 38   : 			return Error(NULL, "FILE_UTIL", "LoadMem:GlobalLock", GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BD@HJJN@LoadMem?3GlobalLock?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_09LIHE@FILE_UTIL?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L54114
$L54121:

; 40   : 	else

	jmp	SHORT $L54124
$L54115:

; 42   : 		if(ReLoadMem(var, hmem, size, lc))

	mov	eax, DWORD PTR _lc$[ebp]
	push	eax
	mov	ecx, DWORD PTR _size$[ebp]
	push	ecx
	mov	edx, DWORD PTR _hmem$[ebp]
	push	edx
	mov	eax, DWORD PTR _var$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ReLoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z ; FILE_UTIL::ReLoadMem
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L54124

; 43   : 			return 1;

	mov	al, 1
	jmp	SHORT $L54114
$L54124:

; 45   : 
; 46   : 	return 0;

	xor	al, al
$L54114:

; 47   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?LoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z ENDP		; FILE_UTIL::LoadMem
_TEXT	ENDS
PUBLIC	??_C@_0BH@BJBH@ReLoadMem?3GlobalUnlock?$AA@	; `string'
PUBLIC	??_C@_0BI@BFDB@ReLoadMem?3GlobalReAlloc?$AA@	; `string'
PUBLIC	??_C@_0O@HEDF@ReLoadMem?3?$DP?$DP?$DP?$AA@	; `string'
EXTRN	__imp__GlobalReAlloc@12:NEAR
EXTRN	__imp__GlobalUnlock@4:NEAR
;	COMDAT ??_C@_0BH@BJBH@ReLoadMem?3GlobalUnlock?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\fileutil.cpp
CONST	SEGMENT
??_C@_0BH@BJBH@ReLoadMem?3GlobalUnlock?$AA@ DB 'ReLoadMem:GlobalUnlock', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@BFDB@ReLoadMem?3GlobalReAlloc?$AA@
CONST	SEGMENT
??_C@_0BI@BFDB@ReLoadMem?3GlobalReAlloc?$AA@ DB 'ReLoadMem:GlobalReAlloc', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0O@HEDF@ReLoadMem?3?$DP?$DP?$DP?$AA@
CONST	SEGMENT
??_C@_0O@HEDF@ReLoadMem?3?$DP?$DP?$DP?$AA@ DB 'ReLoadMem:???', 00H ; `string'
CONST	ENDS
;	COMDAT ?ReLoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z
_TEXT	SEGMENT
_var$ = 8
_hmem$ = 12
_size$ = 16
_lc$ = 20
_this$ = -4
?ReLoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z PROC NEAR	; FILE_UTIL::ReLoadMem, COMDAT

; 52   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 53   : 	SetLastError(0);

	push	0
	call	DWORD PTR __imp__SetLastError@4

; 54   : 
; 55   : 	GlobalUnlock(hmem);

	mov	eax, DWORD PTR _hmem$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR __imp__GlobalUnlock@4

; 56   : 	if((&lc) != NULL)

	lea	edx, DWORD PTR _lc$[ebp]
	test	edx, edx
	je	SHORT $L54132

; 57   : 		lc--;

	mov	eax, DWORD PTR _lc$[ebp]
	sub	eax, 1
	mov	DWORD PTR _lc$[ebp], eax
$L54132:

; 58   : 
; 59   : 	if( GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L54133

; 60   : 		return Error(NULL, "FILE_UTIL", "ReLoadMem:GlobalUnlock", GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BH@BJBH@ReLoadMem?3GlobalUnlock?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_09LIHE@FILE_UTIL?$AA@	; `string'
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	push	ecx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	$L54131
$L54133:

; 61   : 
; 62   : //	if((error = GetLastError()) != 0)
; 63   : //			return 104;
; 64   : 
; 65   : 	if(hmem != NULL)

	mov	edx, DWORD PTR _hmem$[ebp]
	cmp	DWORD PTR [edx], 0
	je	$L54135

; 67   : 		hmem = GlobalReAlloc(hmem, size, GMEM_ZEROINIT);

	push	64					; 00000040H
	mov	eax, DWORD PTR _size$[ebp]
	push	eax
	mov	ecx, DWORD PTR _hmem$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR __imp__GlobalReAlloc@12
	mov	ecx, DWORD PTR _hmem$[ebp]
	mov	DWORD PTR [ecx], eax

; 68   : 		if( GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L54136

; 69   : 			return Error(NULL, "FILE_UTIL", "ReLoadMem:GlobalReAlloc", GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BI@BFDB@ReLoadMem?3GlobalReAlloc?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_09LIHE@FILE_UTIL?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L54131
$L54136:

; 70   : 
; 71   : //		hmem = GlobalReAlloc(hmem, size, GMEM_ZEROINIT);
; 72   : //		if((error = GetLastError()) != 0)
; 73   : //			return 104;
; 74   : 
; 75   : 		var = GlobalLock(hmem);

	mov	eax, DWORD PTR _hmem$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR __imp__GlobalLock@4
	mov	edx, DWORD PTR _var$[ebp]
	mov	DWORD PTR [edx], eax

; 76   : 		if((&lc) != NULL)

	lea	eax, DWORD PTR _lc$[ebp]
	test	eax, eax
	je	SHORT $L54138

; 77   : 			lc++;

	mov	ecx, DWORD PTR _lc$[ebp]
	add	ecx, 1
	mov	DWORD PTR _lc$[ebp], ecx
$L54138:

; 78   : 
; 79   : 		if( GetLastError() != NO_ERROR )

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L54139

; 80   : 			return Error(NULL, "FILE_UTIL", "LoadMem:GlobalLock", GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BD@HJJN@LoadMem?3GlobalLock?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_09LIHE@FILE_UTIL?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L54131
$L54139:

; 82   : 	else

	jmp	SHORT $L54140
$L54135:

; 83   : 		return Error(NULL, "FILE_UTIL", "ReLoadMem:???", GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0O@HEDF@ReLoadMem?3?$DP?$DP?$DP?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_09LIHE@FILE_UTIL?$AA@	; `string'
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	push	eax
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L54131
$L54140:

; 84   : 
; 85   : 	return 0;

	xor	al, al
$L54131:

; 86   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?ReLoadMem@FILE_UTIL@@QAE_NAAPAX0IPA_D@Z ENDP		; FILE_UTIL::ReLoadMem
_TEXT	ENDS
PUBLIC	?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z		; FILE_UTIL::FreeMem
PUBLIC	??_C@_0BF@EEKA@FreeMem?3GlobalUnlock?$AA@	; `string'
PUBLIC	??_C@_0BG@FDLA@FreeMem?3GlobalDiscard?$AA@	; `string'
PUBLIC	??_C@_0M@HEGK@FreeMem?3?$DP?$DP?$DP?$AA@	; `string'
;	COMDAT ??_C@_0BF@EEKA@FreeMem?3GlobalUnlock?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\fileutil.cpp
CONST	SEGMENT
??_C@_0BF@EEKA@FreeMem?3GlobalUnlock?$AA@ DB 'FreeMem:GlobalUnlock', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BG@FDLA@FreeMem?3GlobalDiscard?$AA@
CONST	SEGMENT
??_C@_0BG@FDLA@FreeMem?3GlobalDiscard?$AA@ DB 'FreeMem:GlobalDiscard', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0M@HEGK@FreeMem?3?$DP?$DP?$DP?$AA@
CONST	SEGMENT
??_C@_0M@HEGK@FreeMem?3?$DP?$DP?$DP?$AA@ DB 'FreeMem:???', 00H ; `string'
CONST	ENDS
;	COMDAT ?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z
_TEXT	SEGMENT
_hmem$ = 8
_lc$ = 12
_this$ = -4
?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z PROC NEAR		; FILE_UTIL::FreeMem, COMDAT

; 91   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 92   : 	SetLastError(0);

	push	0
	call	DWORD PTR __imp__SetLastError@4

; 93   : 
; 94   : 	if(hmem != NULL)

	mov	eax, DWORD PTR _hmem$[ebp]
	cmp	DWORD PTR [eax], 0
	je	$L54147

; 96   : 		GlobalUnlock(hmem);

	mov	ecx, DWORD PTR _hmem$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR __imp__GlobalUnlock@4

; 97   : 		if((&lc) != NULL)

	lea	eax, DWORD PTR _lc$[ebp]
	test	eax, eax
	je	SHORT $L54148

; 98   : 			lc--;

	mov	ecx, DWORD PTR _lc$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _lc$[ebp], ecx
$L54148:

; 99   : 
; 100  : 		if( GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L54149

; 101  : 			return Error(NULL, "FILE_UTIL", "FreeMem:GlobalUnlock", GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BF@EEKA@FreeMem?3GlobalUnlock?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_09LIHE@FILE_UTIL?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L54146
$L54149:

; 102  : 
; 103  : 
; 104  : 		GlobalDiscard(hmem);

	push	2
	push	0
	mov	eax, DWORD PTR _hmem$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR __imp__GlobalReAlloc@12

; 105  : 
; 106  : 		if( GetLastError() != NO_ERROR)

	call	DWORD PTR __imp__GetLastError@0
	test	eax, eax
	je	SHORT $L54151

; 107  : 			return Error(NULL, "FILE_UTIL", "FreeMem:GlobalDiscard", GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0BG@FDLA@FreeMem?3GlobalDiscard?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_09LIHE@FILE_UTIL?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L54146
$L54151:

; 110  : 	else

	jmp	SHORT $L54153
$L54147:

; 111  : 		return Error(NULL, "FILE_UTIL", "FreeMem:???", GetLastError());

	call	DWORD PTR __imp__GetLastError@0
	push	eax
	push	OFFSET FLAT:??_C@_0M@HEGK@FreeMem?3?$DP?$DP?$DP?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_09LIHE@FILE_UTIL?$AA@	; `string'
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	push	eax
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L54146
$L54153:

; 112  : 
; 113  : 	return 0;

	xor	al, al
$L54146:

; 114  : }	

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?FreeMem@FILE_UTIL@@QAE_NAAPAXPA_D@Z ENDP		; FILE_UTIL::FreeMem
_TEXT	ENDS
PUBLIC	?SaveDataFile@FILE_UTIL@@QAEJPADPA_GPAPA_N1_E@Z	; FILE_UTIL::SaveDataFile
EXTRN	__imp__WriteFile@20:NEAR
EXTRN	__imp__CloseHandle@4:NEAR
EXTRN	__imp__CreateFileA@28:NEAR
;	COMDAT ?SaveDataFile@FILE_UTIL@@QAEJPADPA_GPAPA_N1_E@Z
_TEXT	SEGMENT
_FileName$ = 8
_n$ = 12
_p$ = 16
_s$ = 20
_num$ = 24
_this$ = -4
_hFile$ = -8
_NumByteW$ = -12
_Size$ = -16
_i$ = -20
?SaveDataFile@FILE_UTIL@@QAEJPADPA_GPAPA_N1_E@Z PROC NEAR ; FILE_UTIL::SaveDataFile, COMDAT

; 119  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 84					; 00000054H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 120  : /*
; 121  : 	HANDLE CreateFile( 
; 122  : 		LPCTSTR lpFileName, // pointer to name of the file 
; 123  : 		DWORD dwDesiredAccess, // access (read-write) mode 
; 124  : 		DWORD dwShareMode, // share mode 
; 125  : 		LPSECURITY_ATTRIBUTES lpSecurityAttributes, // pointer to security attributes 
; 126  : 		DWORD dwCreationDistribution, // how to create 
; 127  : 		DWORD dwFlagsAndAttributes, // file attributes 
; 128  : 		HANDLE hTemplateFile // handle to file with attributes to copy 
; 129  : 		); 
; 130  : 	BOOL WriteFile( 
; 131  : 		HANDLE hFile, // handle to file to write to 
; 132  : 		LPCVOID lpBuffer, // pointer to data to write to file 
; 133  : 		DWORD nNumberOfBytesToWrite, // number of bytes to write 
; 134  : 		LPDWORD lpNumberOfBytesWritten, // pointer to number of bytes written 
; 135  : 		LPOVERLAPPED lpOverlapped // pointer to structure needed for overlapped I/O
; 136  : 		); 
; 137  : */
; 138  : 	HANDLE hFile;
; 139  : 	DWORD NumByteW = 0;

	mov	DWORD PTR _NumByteW$[ebp], 0

; 140  : 	//
; 141  : 
; 142  : 	hFile = CreateFile(FileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);

	push	0
	push	32					; 00000020H
	push	2
	push	0
	push	0
	push	1073741824				; 40000000H
	mov	eax, DWORD PTR _FileName$[ebp]
	push	eax
	call	DWORD PTR __imp__CreateFileA@28
	mov	DWORD PTR _hFile$[ebp], eax

; 143  : 
; 144  : 	WriteFile(hFile, &num, sizeof(__int8), &NumByteW, NULL);

	push	0
	lea	ecx, DWORD PTR _NumByteW$[ebp]
	push	ecx
	push	1
	lea	edx, DWORD PTR _num$[ebp]
	push	edx
	mov	eax, DWORD PTR _hFile$[ebp]
	push	eax
	call	DWORD PTR __imp__WriteFile@20

; 145  : 
; 146  : 	unsigned __int16 Size = num*sizeof(__int16);

	mov	ecx, DWORD PTR _num$[ebp]
	and	ecx, 255				; 000000ffH
	shl	ecx, 1
	mov	WORD PTR _Size$[ebp], cx

; 147  : 	WriteFile(hFile, n, Size, &NumByteW, NULL);

	push	0
	lea	edx, DWORD PTR _NumByteW$[ebp]
	push	edx
	mov	eax, DWORD PTR _Size$[ebp]
	and	eax, 65535				; 0000ffffH
	push	eax
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	mov	edx, DWORD PTR _hFile$[ebp]
	push	edx
	call	DWORD PTR __imp__WriteFile@20

; 148  : 	if(NumByteW != Size)

	mov	eax, DWORD PTR _Size$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	DWORD PTR _NumByteW$[ebp], eax
	je	SHORT $L54170

; 150  : 		if(!CloseHandle(hFile))

	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__CloseHandle@4
	test	eax, eax
	jne	SHORT $L54169

; 151  : 			return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	$L54162
$L54169:

; 153  : 			return 105;

	mov	eax, 105				; 00000069H
	jmp	$L54162
$L54170:

; 155  : 
; 156  : 	WriteFile(hFile, s, Size, &NumByteW, NULL);

	push	0
	lea	edx, DWORD PTR _NumByteW$[ebp]
	push	edx
	mov	eax, DWORD PTR _Size$[ebp]
	and	eax, 65535				; 0000ffffH
	push	eax
	mov	ecx, DWORD PTR _s$[ebp]
	push	ecx
	mov	edx, DWORD PTR _hFile$[ebp]
	push	edx
	call	DWORD PTR __imp__WriteFile@20

; 157  : 	if(NumByteW != Size)

	mov	eax, DWORD PTR _Size$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	DWORD PTR _NumByteW$[ebp], eax
	je	SHORT $L54173

; 159  : 		if(!CloseHandle(hFile))

	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__CloseHandle@4
	test	eax, eax
	jne	SHORT $L54172

; 160  : 			return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	$L54162
$L54172:

; 162  : 			return 105;

	mov	eax, 105				; 00000069H
	jmp	$L54162
$L54173:

; 164  : 
; 165  : 	for(int i = 0; i < NumfData; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L54175
$L54176:
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L54175:
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+16]
	cmp	DWORD PTR _i$[ebp], ecx
	jge	SHORT $L54177

; 167  : 		WriteFile(hFile, p[i], s[i], &NumByteW, NULL);

	push	0
	lea	edx, DWORD PTR _NumByteW$[ebp]
	push	edx
	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _s$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+eax*2]
	push	edx
	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _p$[ebp]
	mov	edx, DWORD PTR [ecx+eax*4]
	push	edx
	mov	eax, DWORD PTR _hFile$[ebp]
	push	eax
	call	DWORD PTR __imp__WriteFile@20

; 168  : 		if(NumByteW != s[i])

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _s$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	cmp	DWORD PTR _NumByteW$[ebp], eax
	je	SHORT $L54180

; 170  : 			if(!CloseHandle(hFile))

	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__CloseHandle@4
	test	eax, eax
	jne	SHORT $L54179

; 171  : 				return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	SHORT $L54162
$L54179:

; 173  : 				return 105;

	mov	eax, 105				; 00000069H
	jmp	SHORT $L54162
$L54180:

; 175  : 	}

	jmp	SHORT $L54176
$L54177:

; 176  : 
; 177  : 	if(!CloseHandle(hFile))

	mov	edx, DWORD PTR _hFile$[ebp]
	push	edx
	call	DWORD PTR __imp__CloseHandle@4
	test	eax, eax
	jne	SHORT $L54181

; 178  : 		return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	SHORT $L54162
$L54181:

; 179  : 
; 180  : 	return 0;

	xor	eax, eax
$L54162:

; 181  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	20					; 00000014H
?SaveDataFile@FILE_UTIL@@QAEJPADPA_GPAPA_N1_E@Z ENDP	; FILE_UTIL::SaveDataFile
_TEXT	ENDS
PUBLIC	?Load_Pointer_DataFile@FILE_UTIL@@QAEJPADPAPA_NPA_G@Z ; FILE_UTIL::Load_Pointer_DataFile
EXTRN	??2@YAPAXI@Z:NEAR				; operator new
EXTRN	??3@YAXPAX@Z:NEAR				; operator delete
EXTRN	__imp__ReadFile@20:NEAR
;	COMDAT ?Load_Pointer_DataFile@FILE_UTIL@@QAEJPADPAPA_NPA_G@Z
_TEXT	SEGMENT
$T54290 = -32
$T54291 = -36
_FileName$ = 8
_p$ = 12
_s$ = 16
_this$ = -4
_e$ = -8
_hFile$ = -12
_NumByteW$ = -16
_NumD$ = -20
_Temp$ = -24
_i$ = -28
?Load_Pointer_DataFile@FILE_UTIL@@QAEJPADPAPA_NPA_G@Z PROC NEAR ; FILE_UTIL::Load_Pointer_DataFile, COMDAT

; 186  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 100				; 00000064H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 187  : 	HRESULT e = 0;

	mov	DWORD PTR _e$[ebp], 0

; 188  : 	HANDLE hFile = NULL;

	mov	DWORD PTR _hFile$[ebp], 0

; 189  : 	DWORD NumByteW = 0;

	mov	DWORD PTR _NumByteW$[ebp], 0

; 190  : 	USHORT NumD = 0;

	mov	WORD PTR _NumD$[ebp], 0

; 191  : 
; 192  : 	//
; 193  : 	hFile = CreateFile(FileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

	push	0
	push	32					; 00000020H
	push	3
	push	0
	push	0
	push	-2147483648				; 80000000H
	mov	eax, DWORD PTR _FileName$[ebp]
	push	eax
	call	DWORD PTR __imp__CreateFileA@28
	mov	DWORD PTR _hFile$[ebp], eax

; 194  : 	if(hFile == NULL)

	cmp	DWORD PTR _hFile$[ebp], 0
	jne	SHORT $L54192

; 195  : 		return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	$L54187
$L54192:

; 196  : 
; 197  : 	ReadFile(hFile, &NumD, sizeof(__int8), &NumByteW, NULL);

	push	0
	lea	ecx, DWORD PTR _NumByteW$[ebp]
	push	ecx
	push	1
	lea	edx, DWORD PTR _NumD$[ebp]
	push	edx
	mov	eax, DWORD PTR _hFile$[ebp]
	push	eax
	call	DWORD PTR __imp__ReadFile@20

; 198  : 	if(NumByteW != 1)

	cmp	DWORD PTR _NumByteW$[ebp], 1
	je	SHORT $L54196

; 200  : 		if(!CloseHandle(hFile))

	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__CloseHandle@4
	test	eax, eax
	jne	SHORT $L54195

; 201  : 			return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	$L54187
$L54195:

; 203  : 			return 105;

	mov	eax, 105				; 00000069H
	jmp	$L54187
$L54196:

; 205  : 	//
; 206  : 	NumByteW = 0;

	mov	DWORD PTR _NumByteW$[ebp], 0

; 207  : 	USHORT *Temp = new USHORT[2*NumD];

	mov	edx, DWORD PTR _NumD$[ebp]
	and	edx, 65535				; 0000ffffH
	shl	edx, 1
	shl	edx, 1
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T54290[ebp], eax
	mov	eax, DWORD PTR $T54290[ebp]
	mov	DWORD PTR _Temp$[ebp], eax

; 208  : 	ReadFile(hFile, Temp, 2*NumD*sizeof(__int16), &NumByteW, NULL);

	push	0
	lea	ecx, DWORD PTR _NumByteW$[ebp]
	push	ecx
	mov	edx, DWORD PTR _NumD$[ebp]
	and	edx, 65535				; 0000ffffH
	shl	edx, 1
	shl	edx, 1
	push	edx
	mov	eax, DWORD PTR _Temp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__ReadFile@20

; 209  : 	delete Temp;

	mov	edx, DWORD PTR _Temp$[ebp]
	mov	DWORD PTR $T54291[ebp], edx
	mov	eax, DWORD PTR $T54291[ebp]
	push	eax
	call	??3@YAXPAX@Z				; operator delete
	add	esp, 4

; 210  : 	if(NumByteW != (2*NumD*sizeof(__int16)))

	mov	ecx, DWORD PTR _NumD$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 1
	shl	ecx, 1
	cmp	DWORD PTR _NumByteW$[ebp], ecx
	je	SHORT $L54205

; 212  : 		if(!CloseHandle(hFile))

	mov	edx, DWORD PTR _hFile$[ebp]
	push	edx
	call	DWORD PTR __imp__CloseHandle@4
	test	eax, eax
	jne	SHORT $L54204

; 213  : 			return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	$L54187
$L54204:

; 215  : 			return 105;

	mov	eax, 105				; 00000069H
	jmp	$L54187
$L54205:

; 217  : 	//
; 218  : 	for(int i = 0; i < NumfData; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L54207
$L54208:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L54207:
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+16]
	cmp	DWORD PTR _i$[ebp], edx
	jge	SHORT $L54209

; 220  : 		//
; 221  : 		ReadFile(hFile, &(p[i]), s[i], &NumByteW, NULL);

	push	0
	lea	eax, DWORD PTR _NumByteW$[ebp]
	push	eax
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _s$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	push	eax
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _p$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	push	eax
	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__ReadFile@20

; 222  : 		if(NumByteW != s[i])

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _s$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+edx*2]
	cmp	DWORD PTR _NumByteW$[ebp], ecx
	je	SHORT $L54212

; 224  : 			if(!CloseHandle(hFile))

	mov	edx, DWORD PTR _hFile$[ebp]
	push	edx
	call	DWORD PTR __imp__CloseHandle@4
	test	eax, eax
	jne	SHORT $L54211

; 225  : 				return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	SHORT $L54187
$L54211:

; 227  : 				return 105;

	mov	eax, 105				; 00000069H
	jmp	SHORT $L54187
$L54212:

; 229  : 	}

	jmp	SHORT $L54208
$L54209:

; 230  : 
; 231  : 	if(!CloseHandle(hFile))

	mov	eax, DWORD PTR _hFile$[ebp]
	push	eax
	call	DWORD PTR __imp__CloseHandle@4
	test	eax, eax
	jne	SHORT $L54213

; 232  : 		return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	SHORT $L54187
$L54213:

; 233  : 
; 234  : 	return 0;

	xor	eax, eax
$L54187:

; 235  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	12					; 0000000cH
?Load_Pointer_DataFile@FILE_UTIL@@QAEJPADPAPA_NPA_G@Z ENDP ; FILE_UTIL::Load_Pointer_DataFile
_TEXT	ENDS
PUBLIC	?Load_NumSize_DataFile@FILE_UTIL@@QAEJPADPA_EPA_G2@Z ; FILE_UTIL::Load_NumSize_DataFile
;	COMDAT ?Load_NumSize_DataFile@FILE_UTIL@@QAEJPADPA_EPA_G2@Z
_TEXT	SEGMENT
_File$ = 8
_NumD$ = 12
_n$ = 16
_s$ = 20
_this$ = -4
_e$ = -8
_hFile$ = -12
_NumByteW$ = -16
?Load_NumSize_DataFile@FILE_UTIL@@QAEJPADPA_EPA_G2@Z PROC NEAR ; FILE_UTIL::Load_NumSize_DataFile, COMDAT

; 240  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 80					; 00000050H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 241  : 	HRESULT e = 0;

	mov	DWORD PTR _e$[ebp], 0

; 242  : 	HANDLE hFile = NULL;

	mov	DWORD PTR _hFile$[ebp], 0

; 243  : 	DWORD NumByteW = 0;

	mov	DWORD PTR _NumByteW$[ebp], 0

; 244  : 	//
; 245  : 
; 246  : 	hFile = CreateFile(File, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

	push	0
	push	32					; 00000020H
	push	3
	push	0
	push	0
	push	-2147483648				; 80000000H
	mov	eax, DWORD PTR _File$[ebp]
	push	eax
	call	DWORD PTR __imp__CreateFileA@28
	mov	DWORD PTR _hFile$[ebp], eax

; 247  : 	if(hFile == NULL)

	cmp	DWORD PTR _hFile$[ebp], 0
	jne	SHORT $L54224

; 248  : 		return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	$L54220
$L54224:

; 249  : 
; 250  : 	ReadFile(hFile, &NumD, sizeof(__int8), &NumByteW, NULL);

	push	0
	lea	ecx, DWORD PTR _NumByteW$[ebp]
	push	ecx
	push	1
	lea	edx, DWORD PTR _NumD$[ebp]
	push	edx
	mov	eax, DWORD PTR _hFile$[ebp]
	push	eax
	call	DWORD PTR __imp__ReadFile@20

; 251  : 	if(NumByteW != 1)

	cmp	DWORD PTR _NumByteW$[ebp], 1
	je	SHORT $L54228

; 253  : 		if(!CloseHandle(hFile))

	mov	ecx, DWORD PTR _hFile$[ebp]
	push	ecx
	call	DWORD PTR __imp__CloseHandle@4
	test	eax, eax
	jne	SHORT $L54227

; 254  : 			return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	$L54220
$L54227:

; 256  : 			return 105;

	mov	eax, 105				; 00000069H
	jmp	$L54220
$L54228:

; 258  : 	//
; 259  : 	//
; 260  : 	NumByteW = 0;

	mov	DWORD PTR _NumByteW$[ebp], 0

; 261  : 	ReadFile(hFile, n, (*NumD)*(sizeof(__int16)), &NumByteW, NULL);

	push	0
	lea	edx, DWORD PTR _NumByteW$[ebp]
	push	edx
	mov	eax, DWORD PTR _NumD$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 1
	push	ecx
	mov	edx, DWORD PTR _n$[ebp]
	push	edx
	mov	eax, DWORD PTR _hFile$[ebp]
	push	eax
	call	DWORD PTR __imp__ReadFile@20

; 262  : 	if(NumByteW != ((*NumD)*(sizeof(__int16))))

	mov	ecx, DWORD PTR _NumD$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 1
	cmp	DWORD PTR _NumByteW$[ebp], edx
	je	SHORT $L54233

; 264  : 		if(!CloseHandle(hFile))

	mov	eax, DWORD PTR _hFile$[ebp]
	push	eax
	call	DWORD PTR __imp__CloseHandle@4
	test	eax, eax
	jne	SHORT $L54232

; 265  : 			return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	SHORT $L54220
$L54232:

; 267  : 			return 105;

	mov	eax, 105				; 00000069H
	jmp	SHORT $L54220
$L54233:

; 269  : 	//
; 270  : 	//
; 271  : 	NumByteW = 0;

	mov	DWORD PTR _NumByteW$[ebp], 0

; 272  : 	ReadFile(hFile, s, (*NumD)*(sizeof(__int16)), &NumByteW, NULL);

	push	0
	lea	ecx, DWORD PTR _NumByteW$[ebp]
	push	ecx
	mov	edx, DWORD PTR _NumD$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 1
	push	eax
	mov	ecx, DWORD PTR _s$[ebp]
	push	ecx
	mov	edx, DWORD PTR _hFile$[ebp]
	push	edx
	call	DWORD PTR __imp__ReadFile@20

; 273  : 	if(NumByteW != ((*NumD)*(sizeof(__int16))))

	mov	eax, DWORD PTR _NumD$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 1
	cmp	DWORD PTR _NumByteW$[ebp], ecx
	je	SHORT $L54238

; 275  : 		if(!CloseHandle(hFile))

	mov	edx, DWORD PTR _hFile$[ebp]
	push	edx
	call	DWORD PTR __imp__CloseHandle@4
	test	eax, eax
	jne	SHORT $L54237

; 276  : 			return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	SHORT $L54220
$L54237:

; 278  : 			return 105;

	mov	eax, 105				; 00000069H
	jmp	SHORT $L54220
$L54238:

; 280  : 
; 281  : 	if(!CloseHandle(hFile))

	mov	eax, DWORD PTR _hFile$[ebp]
	push	eax
	call	DWORD PTR __imp__CloseHandle@4
	test	eax, eax
	jne	SHORT $L54239

; 282  : 		return GetLastError();

	call	DWORD PTR __imp__GetLastError@0
	jmp	SHORT $L54220
$L54239:

; 283  : 
; 284  : 	return 0;

	xor	eax, eax
$L54220:

; 285  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?Load_NumSize_DataFile@FILE_UTIL@@QAEJPADPA_EPA_G2@Z ENDP ; FILE_UTIL::Load_NumSize_DataFile
_TEXT	ENDS
PUBLIC	?GetType@ERRORCLASS@@AAEHH@Z			; ERRORCLASS::GetType
PUBLIC	??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ ; `string'
PUBLIC	??_C@_05CKBG@Error?$AA@				; `string'
EXTRN	_strcpy:NEAR
EXTRN	_strlen:NEAR
EXTRN	__imp__GetDesktopWindow@0:NEAR
EXTRN	_vsprintf:NEAR
EXTRN	__imp__MessageBoxA@16:NEAR
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
$T54296 = -268
$T54297 = -272
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
	je	SHORT $L53988

; 114  : 				if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L53989

; 116  : 					PrevMsgFormat = new char[strlen(MsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T54296[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T54296[ebp]
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
$L53989:

; 119  : 
; 120  : 				MsgFormat = new char[strlen(m)];

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T54297[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T54297[ebp]
	mov	DWORD PTR [ecx], edx

; 121  : 				strcpy(MsgFormat, m);

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8
$L53988:

; 123  : 
; 124  : 			if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L53994

; 126  : 				if(strlen(MsgFormat) > 0)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	test	eax, eax
	jbe	SHORT $L53995

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

	jmp	SHORT $L54000
$L53995:

; 133  : 					strcpy(mTemp, "Problem with error message.");

	push	OFFSET FLAT:??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ ; `string'
	lea	edx, DWORD PTR _mTemp$[ebp]
	push	edx
	call	_strcpy
	add	esp, 8
$L54000:

; 135  : 			else

	jmp	SHORT $L54002
$L53994:

; 136  : 				return 1;

	mov	al, 1
	jmp	$L54009
$L54002:

; 137  : 
; 138  : 			if(Type < 0)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	and	ecx, 3
	test	ecx, ecx
	jae	SHORT $L54003

; 139  : 				Type = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	al, -4					; fffffffcH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+8], eax
$L54003:

; 140  : 			
; 141  : 			if(hWnd == NULL)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+12], 0
	jne	SHORT $L54004

; 142  : 				hWnd = GetDesktopWindow();

	call	DWORD PTR __imp__GetDesktopWindow@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L54004:

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
	je	SHORT $L54008
	cmp	DWORD PTR _Ok$[ebp], 7
	je	SHORT $L54008
	cmp	DWORD PTR _Ok$[ebp], 2
	jne	SHORT $L54007
$L54008:

; 147  : 				return 1;

	mov	al, 1
	jmp	SHORT $L54009
$L54007:

; 149  : 				return 0;

	xor	al, al
$L54009:

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
	jne	SHORT $L53928

; 32   : 				return MB_OK;

	xor	eax, eax
	jmp	SHORT $L53933
$L53928:

; 33   : 			else if(Type == ETYPE_YESNO)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	eax, 3
	cmp	eax, 1
	jne	SHORT $L53930

; 34   : 				return MB_YESNO;

	mov	eax, 4
	jmp	SHORT $L53933
$L53930:

; 35   : 			else if(Type == ETYPE_RETRY)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	and	edx, 3
	cmp	edx, 2
	jne	SHORT $L53932

; 36   : 				return MB_RETRYCANCEL;

	mov	eax, 5
	jmp	SHORT $L53933
$L53932:

; 38   : 				return MB_OK;

	xor	eax, eax
$L53933:

; 39   : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?GetType@ERRORCLASS@@AAEHH@Z ENDP			; ERRORCLASS::GetType
_TEXT	ENDS
END
