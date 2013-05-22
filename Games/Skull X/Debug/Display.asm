	TITLE	D:\Game Programming\Moggie Software Games\old code\old Skull X\C++ Files\Display.cpp
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
;	COMDAT ??_C@_0BO@ODBN@LoadDDObject?3DirectDrawCreate?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_07LGIJ@DISPLAY?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BM@DLIO@LoadDDObject?3QueryInterface?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0CA@FHPG@LoadDDObject?3RestoreDisplayMode?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BK@LEKK@SetDisplay?3GetDisplayMode?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0FN@GLGE@Your?5current?5color?5palette?$CI?$CFd?$CJ?5i@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BP@FOIP@SetDisplay?3SetCooperativeLevel?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BK@DAPJ@SetDisplay?3SetDisplayMode?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BG@DKGM@SetDisplay?3DDCAPS_BLT?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BP@BPKL@SetDisplay?3DDCAPS_BLTCOLORFILL?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@MJMB@Create?5Primary?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@MFMM@Create?5Clipper?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@CLGM@LoadDrawS?3CreateClipper?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@DDFM@Set?5Child?5Hwnd?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@GJON@LoadDrawS?3SetHWnd?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0M@FHCD@Set?5Clipper?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@IGML@LoadDrawS?3SetClipper?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@PJDK@Create?5Background?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BG@LJFC@Flood?5Fill?5Background?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@GENF@DrawLayers?3Blt?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@IEE@Create?5Buffer1?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@HKKH@Flood?5Fill?5Buffer1?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@PHPN@Create?5Buffer2?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@OIHE@Set?5ColorKey?5Buffer2?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@IFBO@Flood?5Fill?5Buffer2?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0M@COPN@Create?5Dark?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@LHPB@SetColorKey?3Dark?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@DBLH@FloodFill?3Dark?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0N@LOKF@gfx?2dark?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_09JKHF@Load?3Dark?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BH@NNPG@SetColorKey?3Dark?5Image?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0M@CDCO@Dark?5Tiling?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0O@GKMC@gfx?2pause?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0L@PNGO@Load?5Pause?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@GOIN@Set?5ColorKey?5Pause?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@FLIM@Blt?3temp?5to?5dark?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0O@LPNO@gfx?2font1?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_09GIBO@Load?5font?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@CBIK@Set?5ColorKey?5Font?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0L@OMAG@level?$AA?4dat?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@PAAN@Buffer1?5onto?5Primary?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@NBHL@Buffer2?5onto?5Buffer1?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05CDDE@Mouse?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04DAIO@Dark?$AA@
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
;	COMDAT ?GetType@ERRORCLASS@@AAEHH@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?InitError@ERRORCLASS@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetError_Type@ERRORCLASS@@QAEXI@Z
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
;	COMDAT ?Restore@DISPLAY@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?ClipRectToScreen@DISPLAY@@AAE?AUtagRECT@@U2@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?ClipImageToScreen@DISPLAY@@AAE?AUtagRECT@@U2@0@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?End@MAIN@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?GetStretchState@MAIN@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Get_DelayRes@MAIN@@QAEGXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Get_ChildHwnd@MAIN@@QAEPAUHWND__@@XZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?sLoop@VALUES@@QAE_NAAPAXPAD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Setup_Display@DISPLAY@@QAE_NPAUtagRECT@@_N@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?LoadDDObject@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Load@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?FreeLayers@DISPLAY@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?FreeGfx@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DrawScreen@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DrawLayer@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DrawMouse@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Animate@DISPLAY@@AAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?ClipRectToRect@DISPLAY@@AAE?AUtagRECT@@U2@0@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Pause@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?SetError_Type@ERRORCLASS@@QAEXI@Z		; ERRORCLASS::SetError_Type
PUBLIC	?SetError_Format@ERRORCLASS@@QAEXPAD@Z		; ERRORCLASS::SetError_Format
PUBLIC	?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z	; ERRORCLASS::ReSetError_Format
PUBLIC	?Error@ERRORCLASS@@QAA_NPADZZ			; ERRORCLASS::Error
PUBLIC	??_C@_0BO@ODBN@LoadDDObject?3DirectDrawCreate?$AA@ ; `string'
PUBLIC	??_C@_07LGIJ@DISPLAY?$AA@			; `string'
PUBLIC	??_C@_0BM@DLIO@LoadDDObject?3QueryInterface?$AA@ ; `string'
PUBLIC	??_C@_0CA@FHPG@LoadDDObject?3RestoreDisplayMode?$AA@ ; `string'
PUBLIC	??_C@_0BK@LEKK@SetDisplay?3GetDisplayMode?$AA@	; `string'
PUBLIC	??_C@_0FN@GLGE@Your?5current?5color?5palette?$CI?$CFd?$CJ?5i@ ; `string'
PUBLIC	??_C@_0BP@FOIP@SetDisplay?3SetCooperativeLevel?$AA@ ; `string'
PUBLIC	??_C@_0BK@DAPJ@SetDisplay?3SetDisplayMode?$AA@	; `string'
PUBLIC	?Setup_Display@DISPLAY@@QAE_NPAUtagRECT@@_N@Z	; DISPLAY::Setup_Display
PUBLIC	?LoadDDObject@DISPLAY@@QAE_NXZ			; DISPLAY::LoadDDObject
PUBLIC	?GetStretchState@MAIN@@QAE_NXZ			; MAIN::GetStretchState
PUBLIC	?Get_ChildHwnd@MAIN@@QAEPAUHWND__@@XZ		; MAIN::Get_ChildHwnd
EXTRN	_IID_IDirectDraw7:BYTE
EXTRN	?Val@@3PAVVALUES@@A:DWORD			; Val
EXTRN	_DirectDrawCreate@12:NEAR
;	COMDAT ??_C@_0BO@ODBN@LoadDDObject?3DirectDrawCreate?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\display.cpp
CONST	SEGMENT
??_C@_0BO@ODBN@LoadDDObject?3DirectDrawCreate?$AA@ DB 'LoadDDObject:Direc'
	DB	'tDrawCreate', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_07LGIJ@DISPLAY?$AA@
CONST	SEGMENT
??_C@_07LGIJ@DISPLAY?$AA@ DB 'DISPLAY', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BM@DLIO@LoadDDObject?3QueryInterface?$AA@
CONST	SEGMENT
??_C@_0BM@DLIO@LoadDDObject?3QueryInterface?$AA@ DB 'LoadDDObject:QueryIn'
	DB	'terface', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_0CA@FHPG@LoadDDObject?3RestoreDisplayMode?$AA@
CONST	SEGMENT
??_C@_0CA@FHPG@LoadDDObject?3RestoreDisplayMode?$AA@ DB 'LoadDDObject:Res'
	DB	'toreDisplayMode', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BK@LEKK@SetDisplay?3GetDisplayMode?$AA@
CONST	SEGMENT
??_C@_0BK@LEKK@SetDisplay?3GetDisplayMode?$AA@ DB 'SetDisplay:GetDisplayM'
	DB	'ode', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0FN@GLGE@Your?5current?5color?5palette?$CI?$CFd?$CJ?5i@
CONST	SEGMENT
??_C@_0FN@GLGE@Your?5current?5color?5palette?$CI?$CFd?$CJ?5i@ DB 'Your cu'
	DB	'rrent color palette(%d) is below the recommended level(%d).', 0aH
	DB	' Do you wish to continue?', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BP@FOIP@SetDisplay?3SetCooperativeLevel?$AA@
CONST	SEGMENT
??_C@_0BP@FOIP@SetDisplay?3SetCooperativeLevel?$AA@ DB 'SetDisplay:SetCoo'
	DB	'perativeLevel', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_0BK@DAPJ@SetDisplay?3SetDisplayMode?$AA@
CONST	SEGMENT
??_C@_0BK@DAPJ@SetDisplay?3SetDisplayMode?$AA@ DB 'SetDisplay:SetDisplayM'
	DB	'ode', 00H					; `string'
CONST	ENDS
;	COMDAT ?Setup_Display@DISPLAY@@QAE_NPAUtagRECT@@_N@Z
_TEXT	SEGMENT
_r$ = 8
_dx$ = 12
_this$ = -4
_pDD$ = -8
_DDSurfaceDesc$ = -132
_BitsPerPlane$ = -136
?Setup_Display@DISPLAY@@QAE_NPAUtagRECT@@_N@Z PROC NEAR	; DISPLAY::Setup_Display, COMDAT

; 79   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 200				; 000000c8H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 80   : 	LPDIRECTDRAW	pDD;
; 81   : 
; 82   : 	// slow func. wait cursor will appear
; 83   : 	if( (e = DirectDrawCreate( NULL, &pDD, NULL )) != DD_OK )

	push	0
	lea	eax, DWORD PTR _pDD$[ebp]
	push	eax
	push	0
	call	_DirectDrawCreate@12
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L64937

; 84   : 		return Error(NULL, "DISPLAY", "LoadDDObject:DirectDrawCreate", e );

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BO@ODBN@LoadDDObject?3DirectDrawCreate?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	$L64934
$L64937:

; 85   : 
; 86   : 	// Fetch DirectDraw4 interface
; 87   :   if( (e = pDD->QueryInterface(DD_INTERFACE, (LPVOID *)&DD_Object)) != DD_OK)

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 208				; 000000d0H
	push	eax
	push	OFFSET FLAT:_IID_IDirectDraw7
	mov	ecx, DWORD PTR _pDD$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _pDD$[ebp]
	push	eax
	call	DWORD PTR [edx]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L64942

; 88   : 		return Error(NULL, "DISPLAY", "LoadDDObject:QueryInterface", e );

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BM@DLIO@LoadDDObject?3QueryInterface?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	$L64934
$L64942:

; 89   : 
; 90   : 	if( (e = DD_Object->RestoreDisplayMode()) != DD_OK )

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+76]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L64945

; 91   : 		return Error(NULL, "DISPLAY", "LoadDDObject:RestoreDisplayMode", e );

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0CA@FHPG@LoadDDObject?3RestoreDisplayMode?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	$L64934
$L64945:

; 97   : 	DDSurfaceDesc.dwSize = sizeof(DD_SDESC);

	mov	DWORD PTR _DDSurfaceDesc$[ebp], 124	; 0000007cH

; 98   : 	DDSurfaceDesc.dwFlags = DDSD_ALL;

	mov	DWORD PTR _DDSurfaceDesc$[ebp+4], 16775662 ; 00fff9eeH

; 99   : 
; 100  : 	if((e = DD_Object->GetDisplayMode(&DDSurfaceDesc)) != DD_OK)

	lea	eax, DWORD PTR _DDSurfaceDesc$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+208]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	mov	eax, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR [eax+48]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L64950

; 101  : 		return Error(NULL, "DISPLAY", "SetDisplay:GetDisplayMode", e );

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BK@LEKK@SetDisplay?3GetDisplayMode?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	$L64934
$L64950:

; 102  : 
; 103  : 	unsigned __int8 BitsPerPlane = (unsigned __int8)DDSurfaceDesc.ddpfPixelFormat.dwRGBBitCount;

	mov	al, BYTE PTR _DDSurfaceDesc$[ebp+84]
	mov	BYTE PTR _BitsPerPlane$[ebp], al

; 104  : 	if(BitsPerPlane < bpp)

	mov	ecx, DWORD PTR _BitsPerPlane$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+48]
	cmp	ecx, eax
	jge	SHORT $L64954

; 106  : 		SetError_Format("Your current color palette(%d) is below the recommended level(%d).\n Do you wish to continue?");

	push	OFFSET FLAT:??_C@_0FN@GLGE@Your?5current?5color?5palette?$CI?$CFd?$CJ?5i@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetError_Format@ERRORCLASS@@QAEXPAD@Z	; ERRORCLASS::SetError_Format

; 107  : 		SetError_Type(ETYPE_YESNO);

	push	1
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetError_Type@ERRORCLASS@@QAEXI@Z	; ERRORCLASS::SetError_Type

; 108  : 
; 109  : 		if( Error(NULL, BitsPerPlane, bpp) )

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+48]
	push	edx
	mov	eax, DWORD PTR _BitsPerPlane$[ebp]
	and	eax, 255				; 000000ffH
	push	eax
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	push	ecx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 16					; 00000010H
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L64956

; 110  : 			return 1;

	mov	al, 1
	jmp	$L64934
$L64956:

; 112  : 			BitsPerPlane = bpp;

	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR [edx+48]
	mov	BYTE PTR _BitsPerPlane$[ebp], al

; 113  : 
; 114  : 		ReSetError_Format();

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z ; ERRORCLASS::ReSetError_Format

; 115  : 		SetError_Type();

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetError_Type@ERRORCLASS@@QAEXI@Z	; ERRORCLASS::SetError_Type
$L64954:

; 117  : 
; 118  : 	WndRect = r;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _r$[ebp]
	mov	DWORD PTR [ecx+236], edx

; 119  : 	if( (BitsPerPlane > 0) && (dx == true) )

	mov	eax, DWORD PTR _BitsPerPlane$[ebp]
	and	eax, 255				; 000000ffH
	test	eax, eax
	jle	$L64958
	mov	ecx, DWORD PTR _dx$[ebp]
	and	ecx, 255				; 000000ffH
	cmp	ecx, 1
	jne	$L64958

; 121  : 		if( (e = DD_Object->SetCooperativeLevel(Val->Main->Get_ChildHwnd(), DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN) != DD_OK ))

	push	17					; 00000011H
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+56]
	call	?Get_ChildHwnd@MAIN@@QAEPAUHWND__@@XZ	; MAIN::Get_ChildHwnd
	push	eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+80]
	neg	eax
	sbb	eax, eax
	neg	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L64960

; 122  : 					return Error(NULL, "DISPLAY", "SetDisplay:SetCooperativeLevel", e );

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BP@FOIP@SetDisplay?3SetCooperativeLevel?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	$L64934
$L64960:

; 123  : 
; 124  : 		if((e = DD_Object->SetDisplayMode(xMax, yMax, BitsPerPlane, 0, 0)) != DD_OK)

	push	0
	push	0
	mov	eax, DWORD PTR _BitsPerPlane$[ebp]
	and	eax, 255				; 000000ffH
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+46]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+44]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+208]
	mov	ecx, DWORD PTR [edx]
	push	eax
	call	DWORD PTR [ecx+84]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L64963

; 125  : 			return Error(NULL, "DISPLAY", "SetDisplay:SetDisplayMode", e );

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BK@DAPJ@SetDisplay?3SetDisplayMode?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	push	eax
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	$L64934
$L64963:

; 126  : 		
; 127  : 		if( Val->Main->GetStretchState() )

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [ecx+56]
	call	?GetStretchState@MAIN@@QAE_NXZ		; MAIN::GetStretchState
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L64965

; 129  : 			WndRect->top = WndRect->left = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+236]
	mov	DWORD PTR [eax], 0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+236]
	mov	DWORD PTR [edx+4], 0

; 130  : 			WndRect->right = xMax;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+44]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+236]
	mov	DWORD PTR [eax+8], ecx

; 131  : 			WndRect->bottom = yMax;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+46]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+236]
	mov	DWORD PTR [ecx+12], edx

; 133  : 		else

	jmp	SHORT $L64966
$L64965:

; 135  : 			WndRect->left = (xMax - G_XRES) >> 1;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+44]
	sub	eax, 320				; 00000140H
	sar	eax, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+236]
	mov	DWORD PTR [edx], eax

; 136  : 			WndRect->top = (yMax - G_YRES) >> 1;

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+46]
	sub	ecx, 240				; 000000f0H
	sar	ecx, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+236]
	mov	DWORD PTR [eax+4], ecx

; 137  : 			WndRect->right = WndRect->left + G_XRES;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+236]
	mov	eax, DWORD PTR [edx]
	add	eax, 320				; 00000140H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+236]
	mov	DWORD PTR [edx+8], eax

; 138  : 			WndRect->bottom = WndRect->top + G_YRES;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+236]
	mov	edx, DWORD PTR [ecx+4]
	add	edx, 240				; 000000f0H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+236]
	mov	DWORD PTR [ecx+12], edx
$L64966:

; 141  : 	else

	jmp	SHORT $L64969
$L64958:

; 143  : 		if( (e = DD_Object->SetCooperativeLevel(Val->Main->Get_ChildHwnd(), DDSCL_NORMAL) != DD_OK ))

	push	8
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+56]
	call	?Get_ChildHwnd@MAIN@@QAEPAUHWND__@@XZ	; MAIN::Get_ChildHwnd
	push	eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+80]
	neg	eax
	sbb	eax, eax
	neg	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L64969

; 144  : 			return Error(NULL, "DISPLAY", "SetDisplay:SetCooperativeLevel", e );

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BP@FOIP@SetDisplay?3SetCooperativeLevel?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	SHORT $L64934
$L64969:

; 146  : 
; 147  : 
; 148  : 	if(LoadDDObject())

	mov	ecx, DWORD PTR _this$[ebp]
	call	?LoadDDObject@DISPLAY@@QAE_NXZ		; DISPLAY::LoadDDObject
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L64970

; 149  : 		return 1;

	mov	al, 1
	jmp	SHORT $L64934
$L64970:

; 150  : 
; 151  : 	return 0;

	xor	al, al
$L64934:

; 152  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?Setup_Display@DISPLAY@@QAE_NPAUtagRECT@@_N@Z ENDP	; DISPLAY::Setup_Display
_TEXT	ENDS
PUBLIC	??_C@_0BG@DKGM@SetDisplay?3DDCAPS_BLT?$AA@	; `string'
PUBLIC	??_C@_0BP@BPKL@SetDisplay?3DDCAPS_BLTCOLORFILL?$AA@ ; `string'
PUBLIC	??_C@_0P@MJMB@Create?5Primary?$AA@		; `string'
PUBLIC	??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@	; `string'
PUBLIC	??_C@_0P@MFMM@Create?5Clipper?$AA@		; `string'
PUBLIC	??_C@_0BI@CLGM@LoadDrawS?3CreateClipper?$AA@	; `string'
PUBLIC	??_C@_0P@DDFM@Set?5Child?5Hwnd?$AA@		; `string'
PUBLIC	??_C@_0BC@GJON@LoadDrawS?3SetHWnd?$AA@		; `string'
PUBLIC	??_C@_0M@FHCD@Set?5Clipper?$AA@			; `string'
PUBLIC	??_C@_0BF@IGML@LoadDrawS?3SetClipper?$AA@	; `string'
PUBLIC	??_C@_0BC@PJDK@Create?5Background?$AA@		; `string'
PUBLIC	??_C@_0BG@LJFC@Flood?5Fill?5Background?$AA@	; `string'
PUBLIC	??_C@_0P@GENF@DrawLayers?3Blt?$AA@		; `string'
PUBLIC	??_C@_0P@IEE@Create?5Buffer1?$AA@		; `string'
PUBLIC	??_C@_0BD@HKKH@Flood?5Fill?5Buffer1?$AA@	; `string'
PUBLIC	??_C@_0P@PHPN@Create?5Buffer2?$AA@		; `string'
PUBLIC	??_C@_0BF@OIHE@Set?5ColorKey?5Buffer2?$AA@	; `string'
PUBLIC	??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@	; `string'
PUBLIC	??_C@_0BD@IFBO@Flood?5Fill?5Buffer2?$AA@	; `string'
PUBLIC	??_C@_0M@COPN@Create?5Dark?$AA@			; `string'
PUBLIC	??_C@_0BB@LHPB@SetColorKey?3Dark?$AA@		; `string'
PUBLIC	??_C@_0P@DBLH@FloodFill?3Dark?$AA@		; `string'
PUBLIC	??_C@_0N@LOKF@gfx?2dark?4bmp?$AA@		; `string'
PUBLIC	??_C@_09JKHF@Load?3Dark?$AA@			; `string'
PUBLIC	??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@	; `string'
PUBLIC	??_C@_0BH@NNPG@SetColorKey?3Dark?5Image?$AA@	; `string'
PUBLIC	??_C@_0M@CDCO@Dark?5Tiling?$AA@			; `string'
PUBLIC	??_C@_0O@GKMC@gfx?2pause?4bmp?$AA@		; `string'
PUBLIC	??_C@_0L@PNGO@Load?5Pause?$AA@			; `string'
PUBLIC	??_C@_0BD@GOIN@Set?5ColorKey?5Pause?$AA@	; `string'
PUBLIC	??_C@_0BB@FLIM@Blt?3temp?5to?5dark?$AA@		; `string'
PUBLIC	??_C@_0O@LPNO@gfx?2font1?4bmp?$AA@		; `string'
PUBLIC	??_C@_09GIBO@Load?5font?$AA@			; `string'
PUBLIC	??_C@_0BC@CBIK@Set?5ColorKey?5Font?$AA@		; `string'
EXTRN	_DDLoadBitmap:NEAR
EXTRN	??2@YAPAXI@Z:NEAR				; operator new
EXTRN	_DDColorMatch:NEAR
EXTRN	_DDSetColorKey:NEAR
EXTRN	?DDE@DISPLAY@@QAE_NPADJ0@Z:NEAR			; DISPLAY::DDE
EXTRN	_memset:NEAR
;	COMDAT ??_C@_0BG@DKGM@SetDisplay?3DDCAPS_BLT?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\display.cpp
CONST	SEGMENT
??_C@_0BG@DKGM@SetDisplay?3DDCAPS_BLT?$AA@ DB 'SetDisplay:DDCAPS_BLT', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BP@BPKL@SetDisplay?3DDCAPS_BLTCOLORFILL?$AA@
CONST	SEGMENT
??_C@_0BP@BPKL@SetDisplay?3DDCAPS_BLTCOLORFILL?$AA@ DB 'SetDisplay:DDCAPS'
	DB	'_BLTCOLORFILL', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@MJMB@Create?5Primary?$AA@
CONST	SEGMENT
??_C@_0P@MJMB@Create?5Primary?$AA@ DB 'Create Primary', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@
CONST	SEGMENT
??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ DB 'LoadDrawS:CreateSurface', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@MFMM@Create?5Clipper?$AA@
CONST	SEGMENT
??_C@_0P@MFMM@Create?5Clipper?$AA@ DB 'Create Clipper', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@CLGM@LoadDrawS?3CreateClipper?$AA@
CONST	SEGMENT
??_C@_0BI@CLGM@LoadDrawS?3CreateClipper?$AA@ DB 'LoadDrawS:CreateClipper', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@DDFM@Set?5Child?5Hwnd?$AA@
CONST	SEGMENT
??_C@_0P@DDFM@Set?5Child?5Hwnd?$AA@ DB 'Set Child Hwnd', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@GJON@LoadDrawS?3SetHWnd?$AA@
CONST	SEGMENT
??_C@_0BC@GJON@LoadDrawS?3SetHWnd?$AA@ DB 'LoadDrawS:SetHWnd', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0M@FHCD@Set?5Clipper?$AA@
CONST	SEGMENT
??_C@_0M@FHCD@Set?5Clipper?$AA@ DB 'Set Clipper', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@IGML@LoadDrawS?3SetClipper?$AA@
CONST	SEGMENT
??_C@_0BF@IGML@LoadDrawS?3SetClipper?$AA@ DB 'LoadDrawS:SetClipper', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@PJDK@Create?5Background?$AA@
CONST	SEGMENT
??_C@_0BC@PJDK@Create?5Background?$AA@ DB 'Create Background', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BG@LJFC@Flood?5Fill?5Background?$AA@
CONST	SEGMENT
??_C@_0BG@LJFC@Flood?5Fill?5Background?$AA@ DB 'Flood Fill Background', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@GENF@DrawLayers?3Blt?$AA@
CONST	SEGMENT
??_C@_0P@GENF@DrawLayers?3Blt?$AA@ DB 'DrawLayers:Blt', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@IEE@Create?5Buffer1?$AA@
CONST	SEGMENT
??_C@_0P@IEE@Create?5Buffer1?$AA@ DB 'Create Buffer1', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@HKKH@Flood?5Fill?5Buffer1?$AA@
CONST	SEGMENT
??_C@_0BD@HKKH@Flood?5Fill?5Buffer1?$AA@ DB 'Flood Fill Buffer1', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@PHPN@Create?5Buffer2?$AA@
CONST	SEGMENT
??_C@_0P@PHPN@Create?5Buffer2?$AA@ DB 'Create Buffer2', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@OIHE@Set?5ColorKey?5Buffer2?$AA@
CONST	SEGMENT
??_C@_0BF@OIHE@Set?5ColorKey?5Buffer2?$AA@ DB 'Set ColorKey Buffer2', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@
CONST	SEGMENT
??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ DB 'LoadDrawS:DDSetColorKey', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@IFBO@Flood?5Fill?5Buffer2?$AA@
CONST	SEGMENT
??_C@_0BD@IFBO@Flood?5Fill?5Buffer2?$AA@ DB 'Flood Fill Buffer2', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0M@COPN@Create?5Dark?$AA@
CONST	SEGMENT
??_C@_0M@COPN@Create?5Dark?$AA@ DB 'Create Dark', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@LHPB@SetColorKey?3Dark?$AA@
CONST	SEGMENT
??_C@_0BB@LHPB@SetColorKey?3Dark?$AA@ DB 'SetColorKey:Dark', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@DBLH@FloodFill?3Dark?$AA@
CONST	SEGMENT
??_C@_0P@DBLH@FloodFill?3Dark?$AA@ DB 'FloodFill:Dark', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0N@LOKF@gfx?2dark?4bmp?$AA@
CONST	SEGMENT
??_C@_0N@LOKF@gfx?2dark?4bmp?$AA@ DB 'gfx\dark.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_09JKHF@Load?3Dark?$AA@
CONST	SEGMENT
??_C@_09JKHF@Load?3Dark?$AA@ DB 'Load:Dark', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@
CONST	SEGMENT
??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ DB 'LoadDrawS:DDLoadBitmap', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BH@NNPG@SetColorKey?3Dark?5Image?$AA@
CONST	SEGMENT
??_C@_0BH@NNPG@SetColorKey?3Dark?5Image?$AA@ DB 'SetColorKey:Dark Image', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0M@CDCO@Dark?5Tiling?$AA@
CONST	SEGMENT
??_C@_0M@CDCO@Dark?5Tiling?$AA@ DB 'Dark Tiling', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0O@GKMC@gfx?2pause?4bmp?$AA@
CONST	SEGMENT
??_C@_0O@GKMC@gfx?2pause?4bmp?$AA@ DB 'gfx\pause.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0L@PNGO@Load?5Pause?$AA@
CONST	SEGMENT
??_C@_0L@PNGO@Load?5Pause?$AA@ DB 'Load Pause', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@GOIN@Set?5ColorKey?5Pause?$AA@
CONST	SEGMENT
??_C@_0BD@GOIN@Set?5ColorKey?5Pause?$AA@ DB 'Set ColorKey Pause', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@FLIM@Blt?3temp?5to?5dark?$AA@
CONST	SEGMENT
??_C@_0BB@FLIM@Blt?3temp?5to?5dark?$AA@ DB 'Blt:temp to dark', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0O@LPNO@gfx?2font1?4bmp?$AA@
CONST	SEGMENT
??_C@_0O@LPNO@gfx?2font1?4bmp?$AA@ DB 'gfx\font1.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_09GIBO@Load?5font?$AA@
CONST	SEGMENT
??_C@_09GIBO@Load?5font?$AA@ DB 'Load font', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@CBIK@Set?5ColorKey?5Font?$AA@
CONST	SEGMENT
??_C@_0BC@CBIK@Set?5ColorKey?5Font?$AA@ DB 'Set ColorKey Font', 00H ; `string'
CONST	ENDS
;	COMDAT ?LoadDDObject@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
_ddc$ = -384
_ddsd$ = -508
_TempGfx$ = -512
_k$ = -516
_w$ = -520
_h$ = -524
_iw$ = -528
_ih$ = -532
$T65401 = -536
?LoadDDObject@DISPLAY@@QAE_NXZ PROC NEAR		; DISPLAY::LoadDDObject, COMDAT

; 157  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 600				; 00000258H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 158  : 	e = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+16], 0

; 159  : 
; 160  : 	DDCAPS ddc;
; 161  : 	ddc.dwSize = sizeof(DDCAPS);

	mov	DWORD PTR _ddc$[ebp], 380		; 0000017cH

; 162  : 
; 163  : 	DD_Object->GetCaps(&ddc, NULL);

	push	0
	lea	ecx, DWORD PTR _ddc$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+208]
	mov	ecx, DWORD PTR [edx]
	push	eax
	call	DWORD PTR [ecx+44]

; 164  : 
; 165  : 	if(!GETBIT(ddc.dwCaps, DDCAPS_BLT))

	mov	edx, DWORD PTR _ddc$[ebp+4]
	or	edx, -65				; ffffffbfH
	xor	edx, 64					; 00000040H
	not	edx
	test	edx, edx
	jne	SHORT $L64977

; 166  : 		return Error(NULL, "DISPLAY", "SetDisplay:DDCAPS_BLT", DDCAPS_BLT );

	push	64					; 00000040H
	push	OFFSET FLAT:??_C@_0BG@DKGM@SetDisplay?3DDCAPS_BLT?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	push	eax
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	$L64974
$L64977:

; 167  : 
; 168  : 	if(!GETBIT(ddc.dwCaps, DDCAPS_BLTCOLORFILL))

	mov	ecx, DWORD PTR _ddc$[ebp+4]
	or	ecx, -67108865				; fbffffffH
	xor	ecx, 67108864				; 04000000H
	not	ecx
	test	ecx, ecx
	jne	SHORT $L64979

; 169  : 		return Error(NULL, "DISPLAY", "SetDisplay:DDCAPS_BLTCOLORFILL", DDCAPS_BLTCOLORFILL );

	push	67108864				; 04000000H
	push	OFFSET FLAT:??_C@_0BP@BPKL@SetDisplay?3DDCAPS_BLTCOLORFILL?$AA@ ; `string'
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 20					; 00000014H
	jmp	$L64974
$L64979:

; 172  : 	// Create the primary surface
; 173  : 	ZeroMemory(&ddsd, sizeof(DD_SDESC));

	push	124					; 0000007cH
	push	0
	lea	eax, DWORD PTR _ddsd$[ebp]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 174  : 	ddsd.dwSize = sizeof( DD_SDESC );

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 175  : 	ddsd.dwFlags = DDSD_CAPS;

	mov	DWORD PTR _ddsd$[ebp+4], 1

; 176  : 	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_VIDEOMEMORY;

	mov	DWORD PTR _ddsd$[ebp+104], 16896	; 00004200H

; 177  : 	if( (e = DD_Object->CreateSurface(&ddsd, &DDS_Primary, NULL)) != DD_OK )

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 212				; 000000d4H
	push	ecx
	lea	edx, DWORD PTR _ddsd$[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+24]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L64985

; 178  : 		return DDE("LoadDrawS:CreateSurface", e, "Create Primary");

	push	OFFSET FLAT:??_C@_0P@MJMB@Create?5Primary?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L64985:

; 179  : 
; 180  : //	DDS_Primary->SetPalette(DrawP[0].Data);
; 181  : 
; 182  : 	// create a clipper for the primary surface
; 183  : 	if( (e = DD_Object->CreateClipper( 0, &DD_Clipper, NULL )) != DD_OK )

	push	0
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 216				; 000000d8H
	push	edx
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+16]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L64989

; 184  : 		return DDE("LoadDrawS:CreateClipper", e, "Create Clipper");

	push	OFFSET FLAT:??_C@_0P@MFMM@Create?5Clipper?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@CLGM@LoadDrawS?3CreateClipper?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L64989:

; 185  : 
; 186  : 	if( (e = DD_Clipper->SetHWnd(0, Val->Main->Get_ChildHwnd())) != DD_OK )

	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+56]
	call	?Get_ChildHwnd@MAIN@@QAEPAUHWND__@@XZ	; MAIN::Get_ChildHwnd
	push	eax
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+216]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+216]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+32]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L64993

; 187  : 		return DDE("LoadDrawS:SetHWnd", e, "Set Child Hwnd");

	push	OFFSET FLAT:??_C@_0P@DDFM@Set?5Child?5Hwnd?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BC@GJON@LoadDrawS?3SetHWnd?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L64993:

; 188  : 
; 189  : 	if( (e = DDS_Primary->SetClipper(DD_Clipper)) != DD_OK )

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+216]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+212]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+212]
	mov	eax, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR [eax+112]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L64997

; 190  : 		return DDE("LoadDrawS:SetClipper", e, "Set Clipper");

	push	OFFSET FLAT:??_C@_0M@FHCD@Set?5Clipper?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BF@IGML@LoadDrawS?3SetClipper?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L64997:

; 191  : 
; 192  : //
; 193  : // Create the background surface
; 194  : //
; 195  : 	ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	edx, DWORD PTR _ddsd$[ebp]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 196  : 	ddsd.dwSize		= sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 197  : 	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 198  : 	ddsd.dwWidth	= G_XRES;

	mov	DWORD PTR _ddsd$[ebp+12], 320		; 00000140H

; 199  : 	ddsd.dwHeight	= G_YRES;

	mov	DWORD PTR _ddsd$[ebp+8], 240		; 000000f0H

; 200  : 	//DDSCAPS_OFFSCREENPLAIN
; 201  : 	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;// DDSCAPS_TEXTURE | DDSCAPS_3DDEVICE;

	mov	DWORD PTR _ddsd$[ebp+104], 2112		; 00000840H

; 202  : 	if( (e = DD_Object->CreateSurface(&ddsd, &DDS_Bkg, NULL)) != DD_OK )

	push	0
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 228				; 000000e4H
	push	eax
	lea	ecx, DWORD PTR _ddsd$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+208]
	mov	ecx, DWORD PTR [edx]
	push	eax
	call	DWORD PTR [ecx+24]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L65001

; 203  : 		return DDE("LoadDrawS:CreateSurface", e, "Create Background");

	push	OFFSET FLAT:??_C@_0BC@PJDK@Create?5Background?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65001:

; 204  : 
; 205  : 	FxBkg.dwSize			= sizeof(DDBLTFX);

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+56], 100			; 00000064H

; 206  : 	FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, RGB(0, 0, 0));

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+228]
	push	edx
	call	_DDColorMatch
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+136], eax

; 207  : 
; 208  : 	if(	(e = DDS_Bkg->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 56					; 00000038H
	push	edx
	push	1024					; 00000400H
	push	0
	push	0
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+228]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+228]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65011

; 209  : 			return DDE("DrawLayers:Blt", e, "Flood Fill Background");

	push	OFFSET FLAT:??_C@_0BG@LJFC@Flood?5Fill?5Background?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65011:

; 210  : //
; 211  : // Create the Buffer surface 1
; 212  : //
; 213  : 	ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	edx, DWORD PTR _ddsd$[ebp]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 214  : 	ddsd.dwSize		= sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 215  : 	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 216  : 	ddsd.dwWidth	= G_XRES;

	mov	DWORD PTR _ddsd$[ebp+12], 320		; 00000140H

; 217  : 	ddsd.dwHeight	= G_YRES;

	mov	DWORD PTR _ddsd$[ebp+8], 240		; 000000f0H

; 218  : 	//
; 219  : 	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

	mov	DWORD PTR _ddsd$[ebp+104], 2112		; 00000840H

; 220  : 	if( (e = DD_Object->CreateSurface(&ddsd, &DDS_Buffer1, NULL)) != DD_OK )

	push	0
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 220				; 000000dcH
	push	eax
	lea	ecx, DWORD PTR _ddsd$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+208]
	mov	ecx, DWORD PTR [edx]
	push	eax
	call	DWORD PTR [ecx+24]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L65015

; 221  : 		return DDE("LoadDrawS:CreateSurface", e, "Create Buffer1");

	push	OFFSET FLAT:??_C@_0P@IEE@Create?5Buffer1?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65015:

; 222  : 
; 223  : 	if(	(e = DDS_Buffer1->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 56					; 00000038H
	push	eax
	push	1024					; 00000400H
	push	0
	push	0
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+220]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+220]
	mov	eax, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR [eax+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65018

; 224  : 		return DDE("DrawLayers:Blt", e, "Flood Fill Buffer1");

	push	OFFSET FLAT:??_C@_0BD@HKKH@Flood?5Fill?5Buffer1?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65018:

; 225  : 
; 226  : //
; 227  : // Create the Buffer surface 2
; 228  : //
; 229  : 	ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	edx, DWORD PTR _ddsd$[ebp]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 230  : 	ddsd.dwSize		= sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 231  : 	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 232  : 	ddsd.dwWidth	= G_XRES;

	mov	DWORD PTR _ddsd$[ebp+12], 320		; 00000140H

; 233  : 	ddsd.dwHeight	= G_YRES;

	mov	DWORD PTR _ddsd$[ebp+8], 240		; 000000f0H

; 234  : 	//DDSCAPS_SYSTEMMEMORY
; 235  : 	//DDSCAPS_VIDEOMEMORY
; 236  : 	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

	mov	DWORD PTR _ddsd$[ebp+104], 2112		; 00000840H

; 237  : 	if( (e = DD_Object->CreateSurface(&ddsd, &DDS_Buffer2, NULL)) != DD_OK )

	push	0
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 224				; 000000e0H
	push	eax
	lea	ecx, DWORD PTR _ddsd$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+208]
	mov	ecx, DWORD PTR [edx]
	push	eax
	call	DWORD PTR [ecx+24]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L65021

; 238  : 		return DDE("LoadDrawS:CreateSurface", e, "Create Buffer2");

	push	OFFSET FLAT:??_C@_0P@PHPN@Create?5Buffer2?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65021:

; 239  : 
; 240  : 	if( (e = DDSetColorKey(DDS_Buffer2,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+224]
	push	ecx
	call	_DDSetColorKey
	add	esp, 8
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L65030

; 241  : 			return DDE("LoadDrawS:DDSetColorKey", e, "Set ColorKey Buffer2");

	push	OFFSET FLAT:??_C@_0BF@OIHE@Set?5ColorKey?5Buffer2?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65030:

; 242  : 
; 243  : 	if(	(e = DDS_Buffer2->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 56					; 00000038H
	push	eax
	push	1024					; 00000400H
	push	0
	push	0
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+224]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+224]
	mov	eax, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR [eax+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65034

; 244  : 		return DDE("DrawLayers:Blt", e, "Flood Fill Buffer2");

	push	OFFSET FLAT:??_C@_0BD@IFBO@Flood?5Fill?5Buffer2?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65034:

; 245  : 
; 246  : 	BkgRect.left = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+240], 0

; 247  : 	BkgRect.top = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+244], 0

; 248  : 	BkgRect.right = G_XRES;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+248], 320		; 00000140H

; 249  : 	BkgRect.bottom = G_YRES;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+252], 240		; 000000f0H

; 250  : 
; 251  : 
; 252  : //
; 253  : // Load Info from File Then create Pause and Fonts.
; 254  : //
; 255  : 
; 256  : 	//
; 257  : 	// Draw Pause Screen
; 258  : 	//
; 259  : 		GFXDATA TempGfx;
; 260  : 		unsigned __int16 k, w, h, iw, ih;
; 261  : 		Dark.ir = BkgRect;

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 240				; 000000f0H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 168				; 000000a8H
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax

; 262  : 		
; 263  : 		iw = 8;	ih = 8;

	mov	WORD PTR _iw$[ebp], 8
	mov	WORD PTR _ih$[ebp], 8

; 264  : 
; 265  : 		w = G_XRES/iw;

	mov	ecx, DWORD PTR _iw$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	eax, 320				; 00000140H
	cdq
	idiv	ecx
	mov	WORD PTR _w$[ebp], ax

; 266  : 		if(G_XRES%iw)

	mov	ecx, DWORD PTR _iw$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	eax, 320				; 00000140H
	cdq
	idiv	ecx
	test	edx, edx
	je	SHORT $L65042

; 267  : 			w++;

	mov	dx, WORD PTR _w$[ebp]
	add	dx, 1
	mov	WORD PTR _w$[ebp], dx
$L65042:

; 268  : 
; 269  : 		h = G_YRES/ih;

	mov	ecx, DWORD PTR _ih$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	eax, 240				; 000000f0H
	cdq
	idiv	ecx
	mov	WORD PTR _h$[ebp], ax

; 270  : 		if(G_YRES%ih)

	mov	ecx, DWORD PTR _ih$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	eax, 240				; 000000f0H
	cdq
	idiv	ecx
	test	edx, edx
	je	SHORT $L65043

; 271  : 			h++;

	mov	dx, WORD PTR _h$[ebp]
	add	dx, 1
	mov	WORD PTR _h$[ebp], dx
$L65043:

; 272  : 
; 273  : 		r2.top = r2.left = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+272], 0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+276], 0

; 274  : 		r2.right = iw;

	mov	edx, DWORD PTR _iw$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+280], edx

; 275  : 		r2.bottom = ih;

	mov	ecx, DWORD PTR _ih$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+284], ecx

; 276  : 
; 277  : 		//
; 278  : 		ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	eax, DWORD PTR _ddsd$[ebp]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 279  : 		ddsd.dwSize		= sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 280  : 		ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 281  : 		ddsd.dwWidth	= w*iw;

	mov	ecx, DWORD PTR _w$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _iw$[ebp]
	and	edx, 65535				; 0000ffffH
	imul	ecx, edx
	mov	DWORD PTR _ddsd$[ebp+12], ecx

; 282  : 		ddsd.dwHeight	= h*ih;

	mov	eax, DWORD PTR _h$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _ih$[ebp]
	and	ecx, 65535				; 0000ffffH
	imul	eax, ecx
	mov	DWORD PTR _ddsd$[ebp+8], eax

; 283  : 		//
; 284  : 		ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

	mov	DWORD PTR _ddsd$[ebp+104], 2112		; 00000840H

; 285  : 		if( (e = DD_Object->CreateSurface(&ddsd, &Dark.gfx, NULL)) != DD_OK )

	push	0
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 184				; 000000b8H
	push	edx
	lea	eax, DWORD PTR _ddsd$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+208]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	mov	eax, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR [eax+24]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65045

; 286  : 			return DDE("LoadDrawS:CreateSurface", e, "Create Dark");

	push	OFFSET FLAT:??_C@_0M@COPN@Create?5Dark?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65045:

; 287  : 
; 288  : 		if( (e = DDSetColorKey(Dark.gfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+184]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65054

; 289  : 				return DDE("LoadDrawS:DDSetColorKey", e, "SetColorKey:Dark");

	push	OFFSET FLAT:??_C@_0BB@LHPB@SetColorKey?3Dark?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65054:

; 290  : 
; 291  : 		FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+228]
	push	eax
	call	_DDColorMatch
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+136], eax

; 292  : 
; 293  : 		if(	(e = Dark.gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 56					; 00000038H
	push	edx
	push	1024					; 00000400H
	push	0
	push	0
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+184]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65063

; 294  : 			return DDE("DrawLayers:Blt", e, "FloodFill:Dark");

	push	OFFSET FLAT:??_C@_0P@DBLH@FloodFill?3Dark?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65063:

; 295  : 		//
; 296  : 
; 297  : 		if( (TempGfx = DDLoadBitmap(DD_Object, "gfx\\dark.bmp", 0, 0)) == NULL )

	push	0
	push	0
	push	OFFSET FLAT:??_C@_0N@LOKF@gfx?2dark?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	push	eax
	call	_DDLoadBitmap
	add	esp, 16					; 00000010H
	mov	DWORD PTR _TempGfx$[ebp], eax
	cmp	DWORD PTR _TempGfx$[ebp], 0
	jne	SHORT $L65065

; 298  : 			return DDE("LoadDrawS:DDLoadBitmap", i, "Load:Dark");

	push	OFFSET FLAT:??_C@_09JKHF@Load?3Dark?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+232]
	push	edx
	push	OFFSET FLAT:??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65065:

; 299  : 		if( (e = DDSetColorKey(TempGfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	eax, DWORD PTR _TempGfx$[ebp]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65076

; 300  : 			return DDE("LoadDrawS:DDSetColorKey", e, "SetColorKey:Dark Image");

	push	OFFSET FLAT:??_C@_0BH@NNPG@SetColorKey?3Dark?5Image?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65076:

; 301  : 
; 302  : 		k = 0;

	mov	WORD PTR _k$[ebp], 0

; 303  : 		for(j = 0; k < h;)

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+233], 0
$L65079:
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _h$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	eax, ecx
	jge	$L65080

; 305  : 			r1.left = j*iw;

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+233]
	mov	ecx, DWORD PTR _iw$[ebp]
	and	ecx, 65535				; 0000ffffH
	imul	eax, ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+256], eax

; 306  : 			r1.top = k*ih;

	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _ih$[ebp]
	and	ecx, 65535				; 0000ffffH
	imul	eax, ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+260], eax

; 307  : 			r1.right = r1.left + iw;

	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+256]
	add	edx, eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+264], edx

; 308  : 			r1.bottom = r1.top + ih;

	mov	ecx, DWORD PTR _ih$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+260]
	add	eax, ecx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+268], eax

; 309  : 
; 310  : 			if(	(e = Dark.gfx->Blt(&r1, TempGfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 272				; 00000110H
	push	edx
	mov	eax, DWORD PTR _TempGfx$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 256				; 00000100H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+184]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	ecx, DWORD PTR [edx]
	push	eax
	call	DWORD PTR [ecx+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L65082

; 311  : 				return DDE("DrawLayers:Blt", e, "Dark Tiling");

	push	OFFSET FLAT:??_C@_0M@CDCO@Dark?5Tiling?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65082:

; 312  : 
; 313  : 			j++;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+233]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+233], cl

; 314  : 			if((j%w) == 0)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	eax, ecx
	mov	ecx, DWORD PTR _w$[ebp]
	and	ecx, 65535				; 0000ffffH
	cdq
	idiv	ecx
	test	edx, edx
	jne	SHORT $L65084

; 316  : 				j = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+233], 0

; 317  : 				k++;

	mov	ax, WORD PTR _k$[ebp]
	add	ax, 1
	mov	WORD PTR _k$[ebp], ax
$L65084:

; 319  : 		}

	jmp	$L65079
$L65080:

; 320  : 
; 321  : 		if( (TempGfx = DDLoadBitmap(DD_Object, "gfx\\pause.bmp", 0, 0)) == NULL )

	push	0
	push	0
	push	OFFSET FLAT:??_C@_0O@GKMC@gfx?2pause?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+208]
	push	edx
	call	_DDLoadBitmap
	add	esp, 16					; 00000010H
	mov	DWORD PTR _TempGfx$[ebp], eax
	cmp	DWORD PTR _TempGfx$[ebp], 0
	jne	SHORT $L65085

; 322  : 			return DDE("LoadDrawS:DDLoadBitmap", i, "Load Pause");

	push	OFFSET FLAT:??_C@_0L@PNGO@Load?5Pause?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+232]
	push	ecx
	push	OFFSET FLAT:??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65085:

; 323  : 		if( (e = DDSetColorKey(TempGfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _TempGfx$[ebp]
	push	edx
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65095

; 324  : 			return DDE("LoadDrawS:DDSetColorKey", e, "Set ColorKey Pause");

	push	OFFSET FLAT:??_C@_0BD@GOIN@Set?5ColorKey?5Pause?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65095:

; 325  : 
; 326  : 		r1.left		= (G_XRES - 189) >> 1;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+256], 65			; 00000041H

; 327  : 		r1.top		= (G_YRES - 40) >> 1;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+260], 100		; 00000064H

; 328  : 		r1.right	= r1.left + 189;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+256]
	add	edx, 189				; 000000bdH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+264], edx

; 329  : 		r1.bottom	= r1.top + 40;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+260]
	add	edx, 40					; 00000028H
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+268], edx

; 330  : 
; 331  : 		if(	(e = Dark.gfx->Blt(&r1, TempGfx, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	push	0
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 256				; 00000100H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+184]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65098

; 332  : 			return DDE("DrawLayers:Blt", e, "Blt:temp to dark");

	push	OFFSET FLAT:??_C@_0BB@FLIM@Blt?3temp?5to?5dark?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L64974
$L65098:

; 333  : 
; 334  : 	//
; 335  : 	// Create Fonts
; 336  : 	//
; 337  : 	
; 338  : 	NumFonts = 1;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+192], 1

; 339  : 	Font = new FONT[NumFonts];

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+192]
	shl	ecx, 3
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65401[ebp], eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR $T65401[ebp]
	mov	DWORD PTR [edx+188], eax

; 340  : 	Font[0].cw = 10;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+188]
	mov	BYTE PTR [edx], 10			; 0000000aH

; 341  : 	Font[0].ch = 16;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+188]
	mov	BYTE PTR [ecx+1], 16			; 00000010H

; 342  : 	for(i = 0; i < NumFonts; i++)

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+232], 0
	jmp	SHORT $L65102
$L65103:
	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+232]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+232], cl
$L65102:
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+232]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+192]
	cmp	ecx, eax
	jge	$L65104

; 344  : 		if( (Font[i].gfx = DDLoadBitmap(DD_Object, "gfx\\font1.bmp", 0, 0)) == NULL )

	push	0
	push	0
	push	OFFSET FLAT:??_C@_0O@LPNO@gfx?2font1?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+208]
	push	edx
	call	_DDLoadBitmap
	add	esp, 16					; 00000010H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+232]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+188]
	mov	DWORD PTR [ecx+edx*8+4], eax
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+188]
	cmp	DWORD PTR [edx+eax*8+4], 0
	jne	SHORT $L65105

; 345  : 				return DDE("LoadDrawS:DDLoadBitmap", i, "Load font");

	push	OFFSET FLAT:??_C@_09GIBO@Load?5font?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+232]
	push	ecx
	push	OFFSET FLAT:??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	SHORT $L64974
$L65105:

; 346  : 		if( (e = DDSetColorKey(Font[i].gfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+188]
	mov	eax, DWORD PTR [edx+eax*8+4]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65115

; 347  : 				return DDE("LoadDrawS:DDSetColorKey", e, "Set ColorKey Font");

	push	OFFSET FLAT:??_C@_0BC@CBIK@Set?5ColorKey?5Font?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	SHORT $L64974
$L65115:

; 348  : 	}

	jmp	$L65103
$L65104:

; 349  : 
; 350  : 	return 0;

	xor	al, al
$L64974:

; 351  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?LoadDDObject@DISPLAY@@QAE_NXZ ENDP			; DISPLAY::LoadDDObject
_TEXT	ENDS
PUBLIC	?Load@DISPLAY@@QAE_NXZ				; DISPLAY::Load
PUBLIC	??_C@_0L@OMAG@level?$AA?4dat?$AA@		; `string'
EXTRN	?LoadGfx@DISPLAY@@QAEPAUGFX_LAYER_INFO@@PAD@Z:NEAR ; DISPLAY::LoadGfx
EXTRN	?TransferGfx@DISPLAY@@QAE_NPAUGFX_LAYER_INFO@@@Z:NEAR ; DISPLAY::TransferGfx
;	COMDAT ??_C@_0L@OMAG@level?$AA?4dat?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\display.cpp
CONST	SEGMENT
??_C@_0L@OMAG@level?$AA?4dat?$AA@ DB 'level', 00H, '.dat', 00H ; `string'
CONST	ENDS
;	COMDAT ?Load@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
?Load@DISPLAY@@QAE_NXZ PROC NEAR			; DISPLAY::Load, COMDAT

; 354  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 355  : 	// Get gfx info from file
; 356  : 	if( TransferGfx( LoadGfx("level\000.dat") ) )

	push	OFFSET FLAT:??_C@_0L@OMAG@level?$AA?4dat?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?LoadGfx@DISPLAY@@QAEPAUGFX_LAYER_INFO@@PAD@Z ; DISPLAY::LoadGfx
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?TransferGfx@DISPLAY@@QAE_NPAUGFX_LAYER_INFO@@@Z ; DISPLAY::TransferGfx
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L65121

; 357  : 		return 1;

	mov	al, 1
	jmp	SHORT $L65120
$L65121:

; 358  : 
; 359  : 	return 0;

	xor	al, al
$L65120:

; 360  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Load@DISPLAY@@QAE_NXZ ENDP				; DISPLAY::Load
_TEXT	ENDS
PUBLIC	?FreeLayers@DISPLAY@@QAEXXZ			; DISPLAY::FreeLayers
;	COMDAT ?FreeLayers@DISPLAY@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
?FreeLayers@DISPLAY@@QAEXXZ PROC NEAR			; DISPLAY::FreeLayers, COMDAT

; 363  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 364  : 	l = StartLayer;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+200]
	mov	DWORD PTR [eax+360], edx

; 365  : 	for(i = 0; (i < nLayers) && (l != NULL); i++)

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+232], 0
	jmp	SHORT $L65127
$L65128:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+232]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+232], dl
$L65127:
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+232]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+372]
	cmp	edx, ecx
	jge	$L65129
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+360], 0
	je	$L65129

; 367  : 		if(l->type == LT_SPRITE)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+4]
	cmp	edx, 2
	jne	$L65130

; 369  : 			for(a = l->startanim; a != NULL; a = a->next)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+152]
	mov	DWORD PTR [edx+364], eax
	jmp	SHORT $L65131
$L65132:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+20]
	mov	DWORD PTR [eax+364], ecx
$L65131:
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+364], 0
	je	SHORT $L65133

; 371  : 				for(c = a->startcel; c != NULL; c = c->next)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+368], eax
	jmp	SHORT $L65134
$L65135:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+20]
	mov	DWORD PTR [eax+368], ecx
$L65134:
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+368], 0
	je	SHORT $L65136

; 373  : 					if(c->gfx)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	cmp	DWORD PTR [ecx+16], 0
	je	SHORT $L65137

; 375  : 						c->gfx->Release();

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	ecx, DWORD PTR [eax+16]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	edx, DWORD PTR [eax+16]
	mov	eax, DWORD PTR [edx]
	push	ecx
	call	DWORD PTR [eax+8]

; 376  : 						c->gfx = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	mov	DWORD PTR [edx+16], 0
$L65137:

; 378  : 				}				

	jmp	SHORT $L65135
$L65136:

; 379  : 			}

	jmp	$L65132
$L65133:

; 381  : 		else

	jmp	SHORT $L65138
$L65130:

; 383  : 			if(l->gfx)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	cmp	DWORD PTR [ecx+144], 0
	je	SHORT $L65139

; 384  : 				l->gfx->Release();

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR [eax+144]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	edx, DWORD PTR [eax+144]
	mov	eax, DWORD PTR [edx]
	push	ecx
	call	DWORD PTR [eax+8]
$L65139:

; 385  : 
; 386  : 			l->gfx = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	DWORD PTR [edx+144], 0
$L65138:

; 388  : 		l = l->next;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+160]
	mov	DWORD PTR [edx+360], eax

; 389  : 	}

	jmp	$L65128
$L65129:

; 390  : 	StartLayer = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+200], 0

; 391  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?FreeLayers@DISPLAY@@QAEXXZ ENDP			; DISPLAY::FreeLayers
_TEXT	ENDS
PUBLIC	?FreeGfx@DISPLAY@@QAE_NXZ			; DISPLAY::FreeGfx
PUBLIC	?Restore@DISPLAY@@QAEXXZ			; DISPLAY::Restore
;	COMDAT ?FreeGfx@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
?FreeGfx@DISPLAY@@QAE_NXZ PROC NEAR			; DISPLAY::FreeGfx, COMDAT

; 394  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 395  : 
; 396  : 	FreeLayers();

	mov	ecx, DWORD PTR _this$[ebp]
	call	?FreeLayers@DISPLAY@@QAEXXZ		; DISPLAY::FreeLayers

; 397  : 
; 398  : 	if(DDS_Buffer2)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+224], 0
	je	SHORT $L65144

; 400  : 		DDS_Buffer2->Release();

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+224]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+224]
	mov	eax, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR [eax+8]

; 401  : 		DDS_Buffer2 = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+224], 0
$L65144:

; 403  : 
; 404  : 	if(DDS_Buffer1)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+220], 0
	je	SHORT $L65145

; 406  : 		DDS_Buffer1->Release();

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+220]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+220]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+8]

; 407  : 		DDS_Buffer1 = NULL;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+220], 0
$L65145:

; 409  : 
; 410  : 	if(DDS_Bkg)

	mov	ecx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [ecx+228], 0
	je	SHORT $L65146

; 412  : 		DDS_Bkg->Release();

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+228]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+228]
	mov	ecx, DWORD PTR [edx]
	push	eax
	call	DWORD PTR [ecx+8]

; 413  : 		DDS_Bkg = NULL;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+228], 0
$L65146:

; 415  : 
; 416  : 	if(DDS_Primary)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+212], 0
	je	SHORT $L65147

; 418  : 		DDS_Primary->Release();

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+212]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+212]
	mov	eax, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR [eax+8]

; 419  : 		DDS_Primary = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+212], 0
$L65147:

; 421  : 
; 422  : 	if(DD_Object)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+208], 0
	je	SHORT $L65148

; 424  : 		Restore();

	mov	ecx, DWORD PTR _this$[ebp]
	call	?Restore@DISPLAY@@QAEXXZ		; DISPLAY::Restore

; 425  : 		DD_Object->Release();

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+8]

; 426  : 		DD_Object = NULL;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+208], 0
$L65148:

; 428  : 
; 429  : 	return 0;

	xor	al, al

; 430  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?FreeGfx@DISPLAY@@QAE_NXZ ENDP				; DISPLAY::FreeGfx
_TEXT	ENDS
PUBLIC	?DrawScreen@DISPLAY@@QAE_NXZ			; DISPLAY::DrawScreen
PUBLIC	?DrawMouse@DISPLAY@@QAE_NXZ			; DISPLAY::DrawMouse
PUBLIC	?DrawLayer@DISPLAY@@QAE_NXZ			; DISPLAY::DrawLayer
PUBLIC	??_C@_0BF@PAAN@Buffer1?5onto?5Primary?$AA@	; `string'
PUBLIC	?Animate@DISPLAY@@AAEXXZ			; DISPLAY::Animate
EXTRN	?MoveObject@ACTION@@QAEXPAVLAYER@@@Z:NEAR	; ACTION::MoveObject
EXTRN	?CheckCol@ACTION@@QAEXPAVLAYER@@@Z:NEAR		; ACTION::CheckCol
EXTRN	__imp__GetTickCount@0:NEAR
EXTRN	__fltused:NEAR
;	COMDAT ??_C@_0BF@PAAN@Buffer1?5onto?5Primary?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\display.cpp
CONST	SEGMENT
??_C@_0BF@PAAN@Buffer1?5onto?5Primary?$AA@ DB 'Buffer1 onto Primary', 00H ; `string'
CONST	ENDS
;	COMDAT ?DrawScreen@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
?DrawScreen@DISPLAY@@QAE_NXZ PROC NEAR			; DISPLAY::DrawScreen, COMDAT

; 436  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 100				; 00000064H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 437  : 	if( (DDS_Buffer1 != NULL) && (DDS_Buffer2 != NULL) && (DDS_Primary != NULL) && (StartLayer != NULL))

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+220], 0
	je	$L65156
	mov	ecx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [ecx+224], 0
	je	$L65156
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+212], 0
	je	$L65156
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+200], 0
	je	$L65156

; 439  : 		l = StartLayer;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+200]
	mov	DWORD PTR [ecx+360], eax

; 440  : 		
; 441  : 		for(i = 0; (i < nLayers) && (l != NULL); i++)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+232], 0
	jmp	SHORT $L65154
$L65155:
	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR [edx+232]
	add	al, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+232], al
$L65154:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+372]
	cmp	eax, edx
	jge	$L65156
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+360], 0
	je	$L65156

; 443  : 			if(l->gfx != NULL)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	cmp	DWORD PTR [edx+144], 0
	je	$L65183

; 445  : 				//
; 446  : 				// Move
; 447  : 				//
; 448  : 				#ifdef _DEBUG
; 449  : 					tick = GetTickCount();

	call	DWORD PTR __imp__GetTickCount@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+164], eax

; 450  : 				#endif
; 451  : 				if( (!l->movement_done) && (l->moveable) && (l->move != NULL) )

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+25]
	test	ecx, ecx
	jne	SHORT $L65158
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+24]
	test	ecx, ecx
	je	SHORT $L65158
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	cmp	DWORD PTR [eax+20], 0
	je	SHORT $L65158

; 453  : 					Val->Action->MoveObject(l);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	push	edx
	mov	eax, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [eax+68]
	call	?MoveObject@ACTION@@QAEXPAVLAYER@@@Z	; ACTION::MoveObject
$L65158:

; 455  : 				#ifdef _DEBUG
; 456  : 					tick = GetTickCount() - tick;

	call	DWORD PTR __imp__GetTickCount@0
	mov	ecx, DWORD PTR _this$[ebp]
	sub	eax, DWORD PTR [ecx+164]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+164], eax

; 457  : 					if(tick > 0)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+164], 0
	jbe	SHORT $L65159

; 458  : 						move_rate = (float)( 1000/tick );

	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, 1000				; 000003e8H
	xor	edx, edx
	div	DWORD PTR [ecx+164]
	mov	DWORD PTR -12+[ebp], eax
	mov	DWORD PTR -12+[ebp+4], 0
	fild	QWORD PTR -12+[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	fstp	DWORD PTR [edx+32]

; 459  : 					else

	jmp	SHORT $L65161
$L65159:

; 460  : 						move_rate = (float)( 1000 );

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+32], 1148846080		; 447a0000H
$L65161:

; 461  : 				#endif
; 462  : 
; 463  : 				//
; 464  : 				// Collision
; 465  : 				//
; 466  : 				if( (l->collidable) && (l->col != NULL) )

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	xor	eax, eax
	mov	al, BYTE PTR [edx+44]
	test	eax, eax
	je	SHORT $L65163
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	cmp	DWORD PTR [edx+40], 0
	je	SHORT $L65163

; 467  : 					Val->Action->CheckCol(l);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	push	ecx
	mov	edx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	ecx, DWORD PTR [edx+68]
	call	?CheckCol@ACTION@@QAEXPAVLAYER@@@Z	; ACTION::CheckCol
$L65163:

; 468  : 
; 469  : 				//
; 470  : 				// Animate
; 471  : 				//
; 472  : 				#ifdef _DEBUG
; 473  : 					tick = GetTickCount();

	call	DWORD PTR __imp__GetTickCount@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+164], eax

; 474  : 				#endif
; 475  : 				if(l->type == LT_SPRITE)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+4]
	cmp	ecx, 2
	jne	SHORT $L65165

; 477  : 					if( (l->animate) && (!l->anim->done) )

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+5]
	test	ecx, ecx
	je	SHORT $L65165
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR [eax+148]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+4]
	test	edx, edx
	jne	SHORT $L65165

; 478  : 						Animate();

	mov	ecx, DWORD PTR _this$[ebp]
	call	?Animate@DISPLAY@@AAEXXZ		; DISPLAY::Animate
$L65165:

; 480  : 				#ifdef _DEBUG
; 481  : 					tick = GetTickCount() - tick;

	call	DWORD PTR __imp__GetTickCount@0
	mov	ecx, DWORD PTR _this$[ebp]
	sub	eax, DWORD PTR [ecx+164]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+164], eax

; 482  : 					if(tick > 0)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+164], 0
	jbe	SHORT $L65166

; 483  : 						anim_rate = (float)( 1000/tick );

	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, 1000				; 000003e8H
	xor	edx, edx
	div	DWORD PTR [ecx+164]
	mov	DWORD PTR -20+[ebp], eax
	mov	DWORD PTR -20+[ebp+4], 0
	fild	QWORD PTR -20+[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	fstp	DWORD PTR [edx+28]

; 484  : 					else

	jmp	SHORT $L65168
$L65166:

; 485  : 						anim_rate = (float)( 1000 );

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+28], 1148846080		; 447a0000H
$L65168:

; 486  : 				#endif
; 487  : 
; 488  : 				if(l->visable)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	xor	eax, eax
	mov	al, BYTE PTR [edx+9]
	test	eax, eax
	je	$L65183

; 490  : 					//
; 491  : 					// Clip Image
; 492  : 					//
; 493  : 					if(l->clip)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	xor	eax, eax
	mov	al, BYTE PTR [edx+52]
	test	eax, eax
	je	$L65175

; 495  : 						t_r = l->r;	l->r = l->cr;	t_ir = l->ir;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	add	edx, 80					; 00000050H
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 320				; 00000140H
	mov	ecx, DWORD PTR [edx]
	mov	DWORD PTR [eax], ecx
	mov	ecx, DWORD PTR [edx+4]
	mov	DWORD PTR [eax+4], ecx
	mov	ecx, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+8], ecx
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+12], edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 56					; 00000038H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	add	eax, 80					; 00000050H
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR [eax+4], edx
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [eax+8], edx
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [eax+12], ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	add	eax, 96					; 00000060H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 336				; 00000150H
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax

; 496  : 						if(l->cr.left > t_r.left)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+56]
	cmp	ecx, DWORD PTR [eax+320]
	jle	SHORT $L65172

; 497  : 							l->ir.left = l->cr.left - t_r.left;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [eax+56]
	sub	edx, DWORD PTR [ecx+320]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	DWORD PTR [ecx+96], edx
$L65172:

; 498  : 						if(l->cr.top > t_r.top)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [eax+60]
	cmp	edx, DWORD PTR [ecx+324]
	jle	SHORT $L65173

; 499  : 							l->ir.top = l->cr.top - t_r.top;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+60]
	sub	eax, DWORD PTR [edx+324]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	DWORD PTR [edx+100], eax
$L65173:

; 500  : 						if(l->cr.right < t_r.right)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+64]
	cmp	eax, DWORD PTR [edx+328]
	jge	SHORT $L65174

; 501  : 							l->ir.right -= t_r.right - l->cr.right;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+328]
	sub	eax, DWORD PTR [ecx+64]
	mov	ecx, DWORD PTR [edx+104]
	sub	ecx, eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	DWORD PTR [eax+104], ecx
$L65174:

; 502  : 						if(l->cr.bottom < t_r.bottom)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+68]
	cmp	ecx, DWORD PTR [eax+332]
	jge	SHORT $L65175

; 503  : 							l->ir.bottom -= t_r.bottom - l->cr.bottom;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+332]
	sub	ecx, DWORD PTR [edx+68]
	mov	edx, DWORD PTR [eax+108]
	sub	edx, ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	DWORD PTR [ecx+108], edx
$L65175:

; 505  : 					//
; 506  : 					// Draw Layer
; 507  : 					//
; 508  : 					#ifdef _DEBUG
; 509  : 						tick = GetTickCount();

	call	DWORD PTR __imp__GetTickCount@0
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+164], eax

; 510  : 					#endif
; 511  : 					if( (ONSCREEN_RECT(l->r, G_XRES, G_YRES)) && ( (l->redraw) || (Re_Draw == RE_ALL) ) )

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	cmp	DWORD PTR [ecx+88], 0
	jle	SHORT $L65178
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	cmp	DWORD PTR [eax+92], 0
	jle	SHORT $L65178
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	cmp	DWORD PTR [edx+80], 320			; 00000140H
	jge	SHORT $L65178
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	cmp	DWORD PTR [ecx+84], 240			; 000000f0H
	jge	SHORT $L65178
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+8]
	test	ecx, ecx
	jne	SHORT $L65177
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+52]
	and	eax, 3
	cmp	eax, 2
	jne	SHORT $L65178
$L65177:

; 513  : 						if( DrawLayer() )

	mov	ecx, DWORD PTR _this$[ebp]
	call	?DrawLayer@DISPLAY@@QAE_NXZ		; DISPLAY::DrawLayer
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L65178

; 514  : 							return 1;

	mov	al, 1
	jmp	$L65152
$L65178:

; 516  : 					#ifdef _DEBUG
; 517  : 						tick = GetTickCount() - tick;

	call	DWORD PTR __imp__GetTickCount@0
	mov	ecx, DWORD PTR _this$[ebp]
	sub	eax, DWORD PTR [ecx+164]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+164], eax

; 518  : 						if(tick > 0)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+164], 0
	jbe	SHORT $L65179

; 519  : 							draw_rate = (float)( 1000/tick );

	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, 1000				; 000003e8H
	xor	edx, edx
	div	DWORD PTR [ecx+164]
	mov	DWORD PTR -28+[ebp], eax
	mov	DWORD PTR -28+[ebp+4], 0
	fild	QWORD PTR -28+[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	fstp	DWORD PTR [edx+24]

; 520  : 						else

	jmp	SHORT $L65181
$L65179:

; 521  : 							draw_rate = (float)( 1000 );

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+24], 1148846080		; 447a0000H
$L65181:

; 522  : 					#endif
; 523  : 
; 524  : 					if(l->clip)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	xor	eax, eax
	mov	al, BYTE PTR [edx+52]
	test	eax, eax
	je	SHORT $L65183

; 526  : 						l->r = t_r;

	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 320				; 00000140H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	add	eax, 80					; 00000050H
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR [eax+4], edx
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [eax+8], edx
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [eax+12], ecx

; 527  : 						l->ir = t_ir;

	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 336				; 00000150H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 96					; 00000060H
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR [ecx+4], eax
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR [ecx+8], eax
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [ecx+12], edx
$L65183:

; 531  : 			l = (LAYER *)l->next;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+160]
	mov	DWORD PTR [edx+360], eax

; 532  : 		}

	jmp	$L65155
$L65156:

; 534  : 
; 535  : 	//
; 536  : 	// Mouse
; 537  : 	//
; 538  : 	if( (UseMouse) && ONSCREEN_RECT(Mouse->r, G_XRES, G_YRES) && ( (Mouse->draw) || (Re_Draw == RE_ALL) ) )

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+193]
	test	edx, edx
	je	SHORT $L65187
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+196]
	cmp	DWORD PTR [ecx+64], 0
	jle	SHORT $L65187
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+196]
	cmp	DWORD PTR [eax+68], 0
	jle	SHORT $L65187
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+196]
	cmp	DWORD PTR [edx+56], 320			; 00000140H
	jge	SHORT $L65187
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+196]
	cmp	DWORD PTR [ecx+60], 240			; 000000f0H
	jge	SHORT $L65187
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+196]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+4]
	test	ecx, ecx
	jne	SHORT $L65186
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+52]
	and	eax, 3
	cmp	eax, 2
	jne	SHORT $L65187
$L65186:

; 540  : 		if( DrawMouse() )

	mov	ecx, DWORD PTR _this$[ebp]
	call	?DrawMouse@DISPLAY@@QAE_NXZ		; DISPLAY::DrawMouse
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L65187

; 541  : 			return 1;

	mov	al, 1
	jmp	$L65152
$L65187:

; 543  : 	
; 544  : 	if( (GlobalReDraw) || (Re_Draw == RE_ALL) )

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+352]
	test	edx, edx
	jne	SHORT $L65189
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	and	ecx, 3
	cmp	ecx, 2
	jne	$L65188
$L65189:

; 546  : 		#ifdef _DEBUG
; 547  : 			tick = GetTickCount();

	call	DWORD PTR __imp__GetTickCount@0
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+164], eax

; 548  : 		#endif
; 549  : 		if(	(e = DDS_Primary->Blt(WndRect, DDS_Buffer1, NULL, 0, NULL)) != DD_OK)

	push	0
	push	0
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+220]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+236]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+212]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+212]
	mov	eax, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR [eax+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65191

; 550  : 			return DDE("DrawLayers:Blt", e, "Buffer1 onto Primary");

	push	OFFSET FLAT:??_C@_0BF@PAAN@Buffer1?5onto?5Primary?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	SHORT $L65152
$L65191:

; 551  : 		#ifdef _DEBUG
; 552  : 			tick = GetTickCount() - tick;

	call	DWORD PTR __imp__GetTickCount@0
	mov	edx, DWORD PTR _this$[ebp]
	sub	eax, DWORD PTR [edx+164]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+164], eax

; 553  : 			if(tick > 0)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+164], 0
	jbe	SHORT $L65193

; 554  : 				screen_rate = (float)( 1000/tick );

	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, 1000				; 000003e8H
	xor	edx, edx
	div	DWORD PTR [ecx+164]
	mov	DWORD PTR -36+[ebp], eax
	mov	DWORD PTR -36+[ebp+4], 0
	fild	QWORD PTR -36+[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	fstp	DWORD PTR [edx+36]

; 555  : 			else

	jmp	SHORT $L65195
$L65193:

; 556  : 				screen_rate = (float)( 1000 );

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+36], 1148846080		; 447a0000H
$L65195:

; 557  : 		#endif
; 558  : 
; 559  : 		Re_Draw = false;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+52]
	and	edx, -4					; fffffffcH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+52], edx

; 560  : 		GlobalReDraw = false;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+352], 0
$L65188:

; 562  : 
; 563  : 	return 0;

	xor	al, al
$L65152:

; 564  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?DrawScreen@DISPLAY@@QAE_NXZ ENDP			; DISPLAY::DrawScreen
_TEXT	ENDS
;	COMDAT ?SetError_Type@ERRORCLASS@@QAEXI@Z
_TEXT	SEGMENT
_t$ = 8
_this$ = -4
?SetError_Type@ERRORCLASS@@QAEXI@Z PROC NEAR		; ERRORCLASS::SetError_Type, COMDAT

; 52   : 		void SetError_Type(unsigned int t = 0){ Type = t; };

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _t$[ebp]
	and	eax, 3
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	and	edx, -4					; fffffffcH
	or	edx, eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+8], edx
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?SetError_Type@ERRORCLASS@@QAEXI@Z ENDP			; ERRORCLASS::SetError_Type
_TEXT	ENDS
PUBLIC	??_C@_00A@?$AA@					; `string'
EXTRN	_strcpy:NEAR
EXTRN	_strlen:NEAR
;	COMDAT ??_C@_00A@?$AA@
; File d:\game programming\moggie software games\old code\old skull x\header files\errorclass.h
CONST	SEGMENT
??_C@_00A@?$AA@ DB 00H					; `string'
CONST	ENDS
;	COMDAT ?SetError_Format@ERRORCLASS@@QAEXPAD@Z
_TEXT	SEGMENT
_m$ = 8
_this$ = -4
$T65415 = -8
$T65416 = -12
$T65417 = -16
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
	je	SHORT $L57646

; 81   : 				PrevMsgFormat = new char[strlen(MsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65415[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T65415[ebp]
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
$L57646:

; 84   : 
; 85   : 			if(m != NULL)

	cmp	DWORD PTR _m$[ebp], 0
	je	SHORT $L57649

; 87   : 				MsgFormat = new char[strlen(m)];

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65416[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T65416[ebp]
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

	jmp	SHORT $L57652
$L57649:

; 92   : 				MsgFormat = new char[2];

	push	2
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65417[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T65417[ebp]
	mov	DWORD PTR [eax], ecx

; 93   : 				strcpy(MsgFormat, "");

	push	OFFSET FLAT:??_C@_00A@?$AA@		; `string'
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_strcpy
	add	esp, 8
$L57652:

; 95   : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?SetError_Format@ERRORCLASS@@QAEXPAD@Z ENDP		; ERRORCLASS::SetError_Format
_TEXT	ENDS
;	COMDAT ?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z
_TEXT	SEGMENT
_n$ = 8
_this$ = -4
$T65420 = -8
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
	je	SHORT $L57658

; 101  : 				MsgFormat = new char[strlen(PrevMsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65420[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T65420[ebp]
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
$L57658:

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
EXTRN	_vsprintf:NEAR
EXTRN	__imp__MessageBoxA@16:NEAR
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
_m$ = 12
_this$ = 8
_mTemp$ = -256
_vl$ = -260
_Ok$ = -264
$T65423 = -268
$T65424 = -272
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
	je	SHORT $L57665

; 114  : 				if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L57666

; 116  : 					PrevMsgFormat = new char[strlen(MsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65423[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T65423[ebp]
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
$L57666:

; 119  : 
; 120  : 				MsgFormat = new char[strlen(m)];

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65424[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T65424[ebp]
	mov	DWORD PTR [ecx], edx

; 121  : 				strcpy(MsgFormat, m);

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8
$L57665:

; 123  : 
; 124  : 			if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L57671

; 126  : 				if(strlen(MsgFormat) > 0)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	test	eax, eax
	jbe	SHORT $L57672

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

	jmp	SHORT $L57677
$L57672:

; 133  : 					strcpy(mTemp, "Problem with error message.");

	push	OFFSET FLAT:??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ ; `string'
	lea	edx, DWORD PTR _mTemp$[ebp]
	push	edx
	call	_strcpy
	add	esp, 8
$L57677:

; 135  : 			else

	jmp	SHORT $L57679
$L57671:

; 136  : 				return 1;

	mov	al, 1
	jmp	$L57686
$L57679:

; 137  : 
; 138  : 			if(Type < 0)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	and	ecx, 3
	test	ecx, ecx
	jae	SHORT $L57680

; 139  : 				Type = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	al, -4					; fffffffcH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+8], eax
$L57680:

; 140  : 			
; 141  : 			if(hWnd == NULL)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+12], 0
	jne	SHORT $L57681

; 142  : 				hWnd = GetDesktopWindow();

	call	DWORD PTR __imp__GetDesktopWindow@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L57681:

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
	je	SHORT $L57685
	cmp	DWORD PTR _Ok$[ebp], 7
	je	SHORT $L57685
	cmp	DWORD PTR _Ok$[ebp], 2
	jne	SHORT $L57684
$L57685:

; 147  : 				return 1;

	mov	al, 1
	jmp	SHORT $L57686
$L57684:

; 149  : 				return 0;

	xor	al, al
$L57686:

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
	jne	SHORT $L57605

; 32   : 				return MB_OK;

	xor	eax, eax
	jmp	SHORT $L57610
$L57605:

; 33   : 			else if(Type == ETYPE_YESNO)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	eax, 3
	cmp	eax, 1
	jne	SHORT $L57607

; 34   : 				return MB_YESNO;

	mov	eax, 4
	jmp	SHORT $L57610
$L57607:

; 35   : 			else if(Type == ETYPE_RETRY)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	and	edx, 3
	cmp	edx, 2
	jne	SHORT $L57609

; 36   : 				return MB_RETRYCANCEL;

	mov	eax, 5
	jmp	SHORT $L57610
$L57609:

; 38   : 				return MB_OK;

	xor	eax, eax
$L57610:

; 39   : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?GetType@ERRORCLASS@@AAEHH@Z ENDP			; ERRORCLASS::GetType
_TEXT	ENDS
PUBLIC	?ClipRectToScreen@DISPLAY@@AAE?AUtagRECT@@U2@@Z	; DISPLAY::ClipRectToScreen
PUBLIC	?ClipImageToScreen@DISPLAY@@AAE?AUtagRECT@@U2@0@Z ; DISPLAY::ClipImageToScreen
;	COMDAT ?DrawLayer@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
$T65429 = -20
$T65430 = -36
?DrawLayer@DISPLAY@@QAE_NXZ PROC NEAR			; DISPLAY::DrawLayer, COMDAT

; 567  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 100				; 00000064H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 568  : 	r1 = ClipRectToScreen(l->r);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 80					; 00000050H
	sub	esp, 16					; 00000010H
	mov	edx, esp
	mov	eax, DWORD PTR [ecx]
	mov	DWORD PTR [edx], eax
	mov	eax, DWORD PTR [ecx+4]
	mov	DWORD PTR [edx+4], eax
	mov	eax, DWORD PTR [ecx+8]
	mov	DWORD PTR [edx+8], eax
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+12], ecx
	lea	edx, DWORD PTR $T65429[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ClipRectToScreen@DISPLAY@@AAE?AUtagRECT@@U2@@Z ; DISPLAY::ClipRectToScreen
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 256				; 00000100H
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax

; 569  : 	r2 = ClipImageToScreen(l->r, l->ir);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	add	edx, 96					; 00000060H
	sub	esp, 16					; 00000010H
	mov	eax, esp
	mov	ecx, DWORD PTR [edx]
	mov	DWORD PTR [eax], ecx
	mov	ecx, DWORD PTR [edx+4]
	mov	DWORD PTR [eax+4], ecx
	mov	ecx, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+8], ecx
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+12], edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 80					; 00000050H
	sub	esp, 16					; 00000010H
	mov	edx, esp
	mov	eax, DWORD PTR [ecx]
	mov	DWORD PTR [edx], eax
	mov	eax, DWORD PTR [ecx+4]
	mov	DWORD PTR [edx+4], eax
	mov	eax, DWORD PTR [ecx+8]
	mov	DWORD PTR [edx+8], eax
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+12], ecx
	lea	edx, DWORD PTR $T65430[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ClipImageToScreen@DISPLAY@@AAE?AUtagRECT@@U2@0@Z ; DISPLAY::ClipImageToScreen
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 272				; 00000110H
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax

; 570  : 	if(	(e = DDS_Buffer1->Blt(&r1, l->gfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 272				; 00000110H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR [eax+144]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 256				; 00000100H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+220]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+220]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65204

; 571  : 		return DDE("DrawLayers:Blt", e, l->Name);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	SHORT $L65200
$L65204:

; 572  : 
; 573  : 	l->redraw = false;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	BYTE PTR [eax+8], 0

; 574  : 	GlobalReDraw = true;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+352], 1

; 575  : 	return 0;

	xor	al, al
$L65200:

; 576  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?DrawLayer@DISPLAY@@QAE_NXZ ENDP			; DISPLAY::DrawLayer
_TEXT	ENDS
PUBLIC	??_C@_0BF@NBHL@Buffer2?5onto?5Buffer1?$AA@	; `string'
PUBLIC	??_C@_05CDDE@Mouse?$AA@				; `string'
PUBLIC	?ClipRectToRect@DISPLAY@@AAE?AUtagRECT@@U2@0@Z	; DISPLAY::ClipRectToRect
;	COMDAT ??_C@_0BF@NBHL@Buffer2?5onto?5Buffer1?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\display.cpp
CONST	SEGMENT
??_C@_0BF@NBHL@Buffer2?5onto?5Buffer1?$AA@ DB 'Buffer2 onto Buffer1', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_05CDDE@Mouse?$AA@
CONST	SEGMENT
??_C@_05CDDE@Mouse?$AA@ DB 'Mouse', 00H			; `string'
CONST	ENDS
;	COMDAT ?DrawMouse@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
$T65433 = -20
$T65434 = -36
$T65435 = -52
$T65436 = -68
$T65437 = -84
$T65438 = -100
?DrawMouse@DISPLAY@@QAE_NXZ PROC NEAR			; DISPLAY::DrawMouse, COMDAT

; 580  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 164				; 000000a4H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 581  : 	// clean up old image
; 582  : 		redraw_old = false;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+160], 0

; 583  : 		r1 = ClipRectToScreen(Mouse->old_r);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+196]
	add	edx, 8
	sub	esp, 16					; 00000010H
	mov	eax, esp
	mov	ecx, DWORD PTR [edx]
	mov	DWORD PTR [eax], ecx
	mov	ecx, DWORD PTR [edx+4]
	mov	DWORD PTR [eax+4], ecx
	mov	ecx, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+8], ecx
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+12], edx
	lea	eax, DWORD PTR $T65433[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ClipRectToScreen@DISPLAY@@AAE?AUtagRECT@@U2@@Z ; DISPLAY::ClipRectToScreen
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 256				; 00000100H
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax

; 584  : 
; 585  : 		TempLayer = StartLayer;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+200]
	mov	DWORD PTR [ecx+356], eax

; 586  : 		for(j = 0; (j < nLayers) && (TempLayer != NULL); j++)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+233], 0
	jmp	SHORT $L65210
$L65211:
	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR [edx+233]
	add	al, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+233], al
$L65210:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+233]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+372]
	cmp	eax, edx
	jge	$L65212
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+356], 0
	je	$L65212

; 588  : 			if( (!TempLayer->redraw) && (TempLayer->visable) && (TempLayer->gfx != NULL) && ( IN_RECT(TempLayer->r, r1) ) )

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	xor	eax, eax
	mov	al, BYTE PTR [edx+8]
	test	eax, eax
	jne	$L65213
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	xor	eax, eax
	mov	al, BYTE PTR [edx+9]
	test	eax, eax
	je	$L65213
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	cmp	DWORD PTR [edx+144], 0
	je	$L65213
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+88]
	cmp	eax, DWORD PTR [edx+256]
	jle	$L65213
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+92]
	cmp	ecx, DWORD PTR [eax+260]
	jle	$L65213
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+356]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [eax+80]
	cmp	edx, DWORD PTR [ecx+264]
	jge	$L65213
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+84]
	cmp	eax, DWORD PTR [edx+268]
	jge	$L65213

; 590  : 				if(!redraw_old)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+160]
	test	edx, edx
	jne	SHORT $L65216

; 592  : 					if(	(e = DDS_Buffer2->Blt(&r1, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 56					; 00000038H
	push	eax
	push	1024					; 00000400H
	push	0
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 256				; 00000100H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+224]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+224]
	mov	ecx, DWORD PTR [edx]
	push	eax
	call	DWORD PTR [ecx+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L65216

; 593  : 						return DDE("DrawLayers:Blt", e, "Flood Fill Buffer2");

	push	OFFSET FLAT:??_C@_0BD@IFBO@Flood?5Fill?5Buffer2?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L65208
$L65216:

; 595  : 
; 596  : 				// clip draw layer
; 597  : 				r3 = ClipRectToRect(TempLayer->r, r1);

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 256				; 00000100H
	sub	esp, 16					; 00000010H
	mov	ecx, esp
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	add	edx, 80					; 00000050H
	sub	esp, 16					; 00000010H
	mov	eax, esp
	mov	ecx, DWORD PTR [edx]
	mov	DWORD PTR [eax], ecx
	mov	ecx, DWORD PTR [edx+4]
	mov	DWORD PTR [eax+4], ecx
	mov	ecx, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+8], ecx
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+12], edx
	lea	eax, DWORD PTR $T65434[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ClipRectToRect@DISPLAY@@AAE?AUtagRECT@@U2@0@Z ; DISPLAY::ClipRectToRect
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 288				; 00000120H
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax

; 598  : 				// clip temp layer
; 599  : 				r4 = ClipRectToRect(r1, TempLayer->r);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	add	edx, 80					; 00000050H
	sub	esp, 16					; 00000010H
	mov	eax, esp
	mov	ecx, DWORD PTR [edx]
	mov	DWORD PTR [eax], ecx
	mov	ecx, DWORD PTR [edx+4]
	mov	DWORD PTR [eax+4], ecx
	mov	ecx, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+8], ecx
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+12], edx
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 256				; 00000100H
	sub	esp, 16					; 00000010H
	mov	ecx, esp
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax
	lea	ecx, DWORD PTR $T65435[ebp]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ClipRectToRect@DISPLAY@@AAE?AUtagRECT@@U2@0@Z ; DISPLAY::ClipRectToRect
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 304				; 00000130H
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR [edx+4], ecx
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [edx+8], ecx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [edx+12], eax

; 600  : 
; 601  : 				if(	(e = DDS_Buffer2->Blt(&r3, TempLayer->gfx, &r4, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 304				; 00000130H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+356]
	mov	ecx, DWORD PTR [eax+144]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 288				; 00000120H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+224]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+224]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65220

; 602  : 					return DDE("DrawLayers:Blt", e, TempLayer->Name);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L65208
$L65220:

; 603  : 
; 604  : 				redraw_old = true;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+160], 1
$L65213:

; 606  : 
; 607  : 			TempLayer = TempLayer->next;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+160]
	mov	DWORD PTR [edx+356], eax

; 608  : 		}

	jmp	$L65211
$L65212:

; 609  : 
; 610  : 		if(redraw_old)

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+160]
	test	edx, edx
	je	$L65224

; 612  : 			r2 = ClipImageToScreen(Mouse->old_r, Mouse->old_ir);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+196]
	add	ecx, 24					; 00000018H
	sub	esp, 16					; 00000010H
	mov	edx, esp
	mov	eax, DWORD PTR [ecx]
	mov	DWORD PTR [edx], eax
	mov	eax, DWORD PTR [ecx+4]
	mov	DWORD PTR [edx+4], eax
	mov	eax, DWORD PTR [ecx+8]
	mov	DWORD PTR [edx+8], eax
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+12], ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+196]
	add	eax, 8
	sub	esp, 16					; 00000010H
	mov	ecx, esp
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax
	lea	ecx, DWORD PTR $T65436[ebp]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ClipImageToScreen@DISPLAY@@AAE?AUtagRECT@@U2@0@Z ; DISPLAY::ClipImageToScreen
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 272				; 00000110H
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR [edx+4], ecx
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [edx+8], ecx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [edx+12], eax

; 613  : 			if(	(e = DDS_Buffer1->Blt(&r1, DDS_Buffer2, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 272				; 00000110H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+224]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 256				; 00000100H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+220]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+220]
	mov	ecx, DWORD PTR [edx]
	push	eax
	call	DWORD PTR [ecx+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L65224

; 614  : 				return DDE("DrawLayers:Blt", e, "Buffer2 onto Buffer1");

	push	OFFSET FLAT:??_C@_0BF@NBHL@Buffer2?5onto?5Buffer1?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L65208
$L65224:

; 616  : 
; 617  : 		Mouse->old_r = Mouse->r;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+196]
	add	ecx, 56					; 00000038H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+196]
	add	eax, 8
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR [eax+4], edx
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [eax+8], edx
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [eax+12], ecx

; 618  : 		Mouse->old_ir = Mouse->ir;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+196]
	add	eax, 40					; 00000028H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+196]
	add	edx, 24					; 00000018H
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR [edx+4], ecx
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [edx+8], ecx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [edx+12], eax

; 619  : 	//
; 620  : 
; 621  : 	r1 = ClipRectToScreen(Mouse->r);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+196]
	add	edx, 56					; 00000038H
	sub	esp, 16					; 00000010H
	mov	eax, esp
	mov	ecx, DWORD PTR [edx]
	mov	DWORD PTR [eax], ecx
	mov	ecx, DWORD PTR [edx+4]
	mov	DWORD PTR [eax+4], ecx
	mov	ecx, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+8], ecx
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+12], edx
	lea	eax, DWORD PTR $T65437[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ClipRectToScreen@DISPLAY@@AAE?AUtagRECT@@U2@@Z ; DISPLAY::ClipRectToScreen
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 256				; 00000100H
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax

; 622  : 	r2 = ClipImageToScreen(Mouse->r, Mouse->ir);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+196]
	add	edx, 40					; 00000028H
	sub	esp, 16					; 00000010H
	mov	eax, esp
	mov	ecx, DWORD PTR [edx]
	mov	DWORD PTR [eax], ecx
	mov	ecx, DWORD PTR [edx+4]
	mov	DWORD PTR [eax+4], ecx
	mov	ecx, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+8], ecx
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+12], edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+196]
	add	ecx, 56					; 00000038H
	sub	esp, 16					; 00000010H
	mov	edx, esp
	mov	eax, DWORD PTR [ecx]
	mov	DWORD PTR [edx], eax
	mov	eax, DWORD PTR [ecx+4]
	mov	DWORD PTR [edx+4], eax
	mov	eax, DWORD PTR [ecx+8]
	mov	DWORD PTR [edx+8], eax
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+12], ecx
	lea	edx, DWORD PTR $T65438[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ClipImageToScreen@DISPLAY@@AAE?AUtagRECT@@U2@0@Z ; DISPLAY::ClipImageToScreen
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 272				; 00000110H
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax

; 623  : 	if(	(e = DDS_Buffer1->Blt(&r1, Mouse->gfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 272				; 00000110H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+196]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 256				; 00000100H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+220]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+220]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65229

; 624  : 		return DDE("DrawLayers:Blt", e, "Mouse");

	push	OFFSET FLAT:??_C@_05CDDE@Mouse?$AA@	; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	SHORT $L65208
$L65229:

; 625  : 
; 626  : 	GlobalReDraw = true;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+352], 1

; 627  : 	Mouse->draw = false;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+196]
	mov	BYTE PTR [ecx+4], 0

; 628  : 
; 629  : 	return 0;

	xor	al, al
$L65208:

; 630  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?DrawMouse@DISPLAY@@QAE_NXZ ENDP			; DISPLAY::DrawMouse
_TEXT	ENDS
;	COMDAT ?Restore@DISPLAY@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
?Restore@DISPLAY@@QAEXXZ PROC NEAR			; DISPLAY::Restore, COMDAT

; 66   : 		void Restore(void){	DD_Object->RestoreDisplayMode(); };

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+76]
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Restore@DISPLAY@@QAEXXZ ENDP				; DISPLAY::Restore
_TEXT	ENDS
;	COMDAT ?ClipRectToScreen@DISPLAY@@AAE?AUtagRECT@@U2@@Z
_TEXT	SEGMENT
_a$ = 12
___$ReturnUdt$ = 8
_this$ = -4
?ClipRectToScreen@DISPLAY@@AAE?AUtagRECT@@U2@@Z PROC NEAR ; DISPLAY::ClipRectToScreen, COMDAT

; 190  : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 191  : 			if(a.left < 0)

	cmp	DWORD PTR _a$[ebp], 0
	jge	SHORT $L58118

; 192  : 				a.left = 0;

	mov	DWORD PTR _a$[ebp], 0
$L58118:

; 193  : 			if(a.right > G_XRES)

	cmp	DWORD PTR _a$[ebp+8], 320		; 00000140H
	jle	SHORT $L58119

; 194  : 				a.right = G_XRES;

	mov	DWORD PTR _a$[ebp+8], 320		; 00000140H
$L58119:

; 195  : 			if(a.top < 0)

	cmp	DWORD PTR _a$[ebp+4], 0
	jge	SHORT $L58120

; 196  : 				a.top = 0;

	mov	DWORD PTR _a$[ebp+4], 0
$L58120:

; 197  : 			if(a.bottom > G_YRES)

	cmp	DWORD PTR _a$[ebp+12], 240		; 000000f0H
	jle	SHORT $L58121

; 198  : 				a.bottom = G_YRES;

	mov	DWORD PTR _a$[ebp+12], 240		; 000000f0H
$L58121:

; 199  : 
; 200  : 			return a;

	mov	eax, DWORD PTR ___$ReturnUdt$[ebp]
	mov	ecx, DWORD PTR _a$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _a$[ebp+4]
	mov	DWORD PTR [eax+4], edx
	mov	ecx, DWORD PTR _a$[ebp+8]
	mov	DWORD PTR [eax+8], ecx
	mov	edx, DWORD PTR _a$[ebp+12]
	mov	DWORD PTR [eax+12], edx
	mov	eax, DWORD PTR ___$ReturnUdt$[ebp]

; 201  : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	20					; 00000014H
?ClipRectToScreen@DISPLAY@@AAE?AUtagRECT@@U2@@Z ENDP	; DISPLAY::ClipRectToScreen
_TEXT	ENDS
PUBLIC	?SetSize@LAYER@@QAEXJJ@Z			; LAYER::SetSize
PUBLIC	?SetHotSpot@LAYER@@QAEXJJ@Z			; LAYER::SetHotSpot
;	COMDAT ?Animate@DISPLAY@@AAEXXZ
_TEXT	SEGMENT
_this$ = -4
?Animate@DISPLAY@@AAEXXZ PROC NEAR			; DISPLAY::Animate, COMDAT

; 636  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 637  : 	a = l->anim;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+148]
	mov	DWORD PTR [edx+364], eax

; 638  : 	if(a != NULL)

	mov	ecx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [ecx+364], 0
	je	$L65239

; 640  : 		tick = GetTickCount();

	call	DWORD PTR __imp__GetTickCount@0
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+164], eax

; 641  : 
; 642  : 		c = a->cel;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+16]
	mov	DWORD PTR [edx+368], eax

; 643  : 		if((unsigned)(tick - l->tick) > c->delay)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+164]
	sub	ecx, DWORD PTR [edx+12]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	cmp	ecx, DWORD PTR [eax]
	jbe	$L65239

; 645  : 			l->tick = tick;				

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+164]
	mov	DWORD PTR [edx+12], ecx

; 646  : 			if(c->next != NULL)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	cmp	DWORD PTR [eax+20], 0
	je	$L65238

; 648  : 				l->gfx = c->gfx;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [edx+16]
	mov	DWORD PTR [ecx+144], edx

; 649  : 				l->SetSize(c->w, c->h);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+6]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+4]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	call	?SetSize@LAYER@@QAEXJJ@Z		; LAYER::SetSize

; 650  : 				l->SetHotSpot( c->hx, c->hy);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	movsx	eax, WORD PTR [edx+10]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	movsx	eax, WORD PTR [edx+8]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+360]
	call	?SetHotSpot@LAYER@@QAEXJJ@Z		; LAYER::SetHotSpot

; 651  : 
; 652  : 				a->cel = c->next;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	mov	eax, DWORD PTR [eax+20]
	mov	DWORD PTR [edx+16], eax

; 653  : 				l->redraw = true;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	BYTE PTR [edx+8], 1

; 655  : 			else

	jmp	$L65239
$L65238:

; 657  : 				l->gfx = c->gfx;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR [ecx+16]
	mov	DWORD PTR [eax+144], ecx

; 658  : 				l->SetSize(c->w, c->h);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+6]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+360]
	call	?SetSize@LAYER@@QAEXJJ@Z		; LAYER::SetSize

; 659  : 				l->SetHotSpot( c->hx, c->hy);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	movsx	edx, WORD PTR [ecx+10]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	movsx	edx, WORD PTR [ecx+8]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	call	?SetHotSpot@LAYER@@QAEXJJ@Z		; LAYER::SetHotSpot

; 660  : 
; 661  : 				if(a->loop_type == LT_FOREVER)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	xor	eax, eax
	mov	al, BYTE PTR [edx+5]
	cmp	eax, 2
	jne	SHORT $L65240

; 662  : 					a->cel = a->startcel;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [ecx+16], edx

; 663  : 				else if( (a->loop_type == LT_ONCE) || (a->loop_count == 0) )

	jmp	$L65245
$L65240:
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+5]
	test	edx, edx
	je	SHORT $L65243
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+6]
	test	edx, edx
	jne	SHORT $L65242
$L65243:

; 664  : 					a->done = true;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	BYTE PTR [ecx+4], 1

; 665  : 				else if( (a->loop_type == LT_NUMBER) && (a->loop_count > 0) )

	jmp	SHORT $L65245
$L65242:
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+364]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+5]
	cmp	ecx, 1
	jne	SHORT $L65245
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+364]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+6]
	test	ecx, ecx
	jle	SHORT $L65245

; 667  : 					a->loop_count--;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+364]
	mov	cl, BYTE PTR [eax+6]
	sub	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+364]
	mov	BYTE PTR [eax+6], cl

; 668  : 					a->cel = a->startcel;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [ecx+16], edx
$L65245:

; 670  : 
; 671  : 				l->redraw = true;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	BYTE PTR [ecx+8], 1
$L65239:

; 675  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Animate@DISPLAY@@AAEXXZ ENDP				; DISPLAY::Animate
_TEXT	ENDS
;	COMDAT ?SetSize@LAYER@@QAEXJJ@Z
_TEXT	SEGMENT
_w$ = 8
_h$ = 12
_this$ = -4
?SetSize@LAYER@@QAEXJJ@Z PROC NEAR			; LAYER::SetSize, COMDAT

; 641  : 	{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 642  : 		ir.top = ir.left = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+96], 0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+100], 0

; 643  : 		ir.right = w; ir.bottom = h;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR [edx+104], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _h$[ebp]
	mov	DWORD PTR [ecx+108], edx

; 644  : 		redraw = true;

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+8], 1

; 645  :   };

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?SetSize@LAYER@@QAEXJJ@Z ENDP				; LAYER::SetSize
_TEXT	ENDS
;	COMDAT ?SetHotSpot@LAYER@@QAEXJJ@Z
_TEXT	SEGMENT
_thx$ = 8
_thy$ = 12
_this$ = -4
?SetHotSpot@LAYER@@QAEXJJ@Z PROC NEAR			; LAYER::SetHotSpot, COMDAT

; 648  : 	{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 649  : 		r.left += hx - thx;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+72]
	sub	ecx, DWORD PTR _thx$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+80]
	add	eax, ecx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+80], eax

; 650  : 		r.top += hy - thy;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+76]
	sub	eax, DWORD PTR _thy$[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+84]
	add	edx, eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+84], edx

; 651  : 		r.right = r.left + ir.right;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+80]
	mov	eax, DWORD PTR _this$[ebp]
	add	edx, DWORD PTR [eax+104]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+88], edx

; 652  : 		r.bottom = r.top + ir.bottom;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+84]
	mov	ecx, DWORD PTR _this$[ebp]
	add	eax, DWORD PTR [ecx+108]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+92], eax

; 653  : 
; 654  : 		hx = thx;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _thx$[ebp]
	mov	DWORD PTR [eax+72], ecx

; 655  : 		hy = thy;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _thy$[ebp]
	mov	DWORD PTR [edx+76], eax

; 656  : 		redraw = true;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+8], 1

; 657  : 	};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?SetHotSpot@LAYER@@QAEXJJ@Z ENDP			; LAYER::SetHotSpot
_TEXT	ENDS
;	COMDAT ?ClipImageToScreen@DISPLAY@@AAE?AUtagRECT@@U2@0@Z
_TEXT	SEGMENT
_s$ = 12
_i$ = 28
___$ReturnUdt$ = 8
_this$ = -4
?ClipImageToScreen@DISPLAY@@AAE?AUtagRECT@@U2@0@Z PROC NEAR ; DISPLAY::ClipImageToScreen, COMDAT

; 235  : 		{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 236  : 			if(s.left < 0)

	cmp	DWORD PTR _s$[ebp], 0
	jge	SHORT $L58136

; 237  : 				i.left -= s.left;

	mov	eax, DWORD PTR _i$[ebp]
	sub	eax, DWORD PTR _s$[ebp]
	mov	DWORD PTR _i$[ebp], eax
$L58136:

; 238  : 
; 239  : 			if(s.right > G_XRES)

	cmp	DWORD PTR _s$[ebp+8], 320		; 00000140H
	jle	SHORT $L58137

; 240  : 				i.right -= s.right - G_XRES;

	mov	ecx, DWORD PTR _s$[ebp+8]
	sub	ecx, 320				; 00000140H
	mov	edx, DWORD PTR _i$[ebp+8]
	sub	edx, ecx
	mov	DWORD PTR _i$[ebp+8], edx
$L58137:

; 241  : 
; 242  : 			if(s.top < 0)

	cmp	DWORD PTR _s$[ebp+4], 0
	jge	SHORT $L58138

; 243  : 				i.top -= s.top;

	mov	eax, DWORD PTR _i$[ebp+4]
	sub	eax, DWORD PTR _s$[ebp+4]
	mov	DWORD PTR _i$[ebp+4], eax
$L58138:

; 244  : 
; 245  : 			if(s.bottom > G_YRES)

	cmp	DWORD PTR _s$[ebp+12], 240		; 000000f0H
	jle	SHORT $L58139

; 246  : 				i.bottom -= s.bottom - G_YRES;

	mov	ecx, DWORD PTR _s$[ebp+12]
	sub	ecx, 240				; 000000f0H
	mov	edx, DWORD PTR _i$[ebp+12]
	sub	edx, ecx
	mov	DWORD PTR _i$[ebp+12], edx
$L58139:

; 247  : 
; 248  : 			return i;

	mov	eax, DWORD PTR ___$ReturnUdt$[ebp]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _i$[ebp+4]
	mov	DWORD PTR [eax+4], edx
	mov	ecx, DWORD PTR _i$[ebp+8]
	mov	DWORD PTR [eax+8], ecx
	mov	edx, DWORD PTR _i$[ebp+12]
	mov	DWORD PTR [eax+12], edx
	mov	eax, DWORD PTR ___$ReturnUdt$[ebp]

; 249  : 		};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	36					; 00000024H
?ClipImageToScreen@DISPLAY@@AAE?AUtagRECT@@U2@0@Z ENDP	; DISPLAY::ClipImageToScreen
_TEXT	ENDS
;	COMDAT ?GetStretchState@MAIN@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
?GetStretchState@MAIN@@QAE_NXZ PROC NEAR		; MAIN::GetStretchState, COMDAT

; 54   : 		bool GetStretchState(void){ return data.Stretch; };

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR [eax+59]
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?GetStretchState@MAIN@@QAE_NXZ ENDP			; MAIN::GetStretchState
_TEXT	ENDS
;	COMDAT ?Get_ChildHwnd@MAIN@@QAEPAUHWND__@@XZ
_TEXT	SEGMENT
_this$ = -4
?Get_ChildHwnd@MAIN@@QAEPAUHWND__@@XZ PROC NEAR		; MAIN::Get_ChildHwnd, COMDAT

; 96   : 		HWND Get_ChildHwnd(void){ return ChildHwnd; };

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+96]
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Get_ChildHwnd@MAIN@@QAEPAUHWND__@@XZ ENDP		; MAIN::Get_ChildHwnd
_TEXT	ENDS
;	COMDAT ?ClipRectToRect@DISPLAY@@AAE?AUtagRECT@@U2@0@Z
_TEXT	SEGMENT
_a$ = 12
_b$ = 28
___$ReturnUdt$ = 8
_this$ = -4
_r$ = -20
?ClipRectToRect@DISPLAY@@AAE?AUtagRECT@@U2@0@Z PROC NEAR ; DISPLAY::ClipRectToRect, COMDAT

; 678  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 84					; 00000054H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 679  : 	RECT r;
; 680  : 
; 681  : 	if(b.left < a.left)

	mov	eax, DWORD PTR _b$[ebp]
	cmp	eax, DWORD PTR _a$[ebp]
	jge	SHORT $L65253

; 682  : 		r.left = a.left - b.left;

	mov	ecx, DWORD PTR _a$[ebp]
	sub	ecx, DWORD PTR _b$[ebp]
	mov	DWORD PTR _r$[ebp], ecx

; 683  : 	else

	jmp	SHORT $L65254
$L65253:

; 684  : 		r.left = 0;

	mov	DWORD PTR _r$[ebp], 0
$L65254:

; 685  : 
; 686  : 	if(b.top < a.top)

	mov	edx, DWORD PTR _b$[ebp+4]
	cmp	edx, DWORD PTR _a$[ebp+4]
	jge	SHORT $L65255

; 687  : 		r.top = a.top - b.top;

	mov	eax, DWORD PTR _a$[ebp+4]
	sub	eax, DWORD PTR _b$[ebp+4]
	mov	DWORD PTR _r$[ebp+4], eax

; 688  : 	else

	jmp	SHORT $L65256
$L65255:

; 689  : 		r.top = 0;

	mov	DWORD PTR _r$[ebp+4], 0
$L65256:

; 690  : 
; 691  : 	// prob
; 692  : 	if( (b.right > a.right) && ( (b.right - b.left) > (b.right - a.right) ) )

	mov	ecx, DWORD PTR _b$[ebp+8]
	cmp	ecx, DWORD PTR _a$[ebp+8]
	jle	SHORT $L65257
	mov	edx, DWORD PTR _b$[ebp+8]
	sub	edx, DWORD PTR _b$[ebp]
	mov	eax, DWORD PTR _b$[ebp+8]
	sub	eax, DWORD PTR _a$[ebp+8]
	cmp	edx, eax
	jle	SHORT $L65257

; 694  : 		// r.right = (b.right - b.left) - (b.right - a.right);
; 695  : 		r.right = a.right - b.left;

	mov	ecx, DWORD PTR _a$[ebp+8]
	sub	ecx, DWORD PTR _b$[ebp]
	mov	DWORD PTR _r$[ebp+8], ecx

; 697  : 	else

	jmp	SHORT $L65258
$L65257:

; 698  : 		r.right = b.right - b.left;

	mov	edx, DWORD PTR _b$[ebp+8]
	sub	edx, DWORD PTR _b$[ebp]
	mov	DWORD PTR _r$[ebp+8], edx
$L65258:

; 699  : 
; 700  : 	if( (b.bottom > a.bottom) && ( (b.bottom - b.top) > (b.bottom - a.bottom) ) )

	mov	eax, DWORD PTR _b$[ebp+12]
	cmp	eax, DWORD PTR _a$[ebp+12]
	jle	SHORT $L65259
	mov	ecx, DWORD PTR _b$[ebp+12]
	sub	ecx, DWORD PTR _b$[ebp+4]
	mov	edx, DWORD PTR _b$[ebp+12]
	sub	edx, DWORD PTR _a$[ebp+12]
	cmp	ecx, edx
	jle	SHORT $L65259

; 702  : 		// r.bottom = (b.bottom - b.top) - (b.bottom - a.bottom);
; 703  : 		r.bottom = a.bottom - b.top;

	mov	eax, DWORD PTR _a$[ebp+12]
	sub	eax, DWORD PTR _b$[ebp+4]
	mov	DWORD PTR _r$[ebp+12], eax

; 705  : 	else

	jmp	SHORT $L65260
$L65259:

; 706  : 		r.bottom = b.bottom - b.top;

	mov	ecx, DWORD PTR _b$[ebp+12]
	sub	ecx, DWORD PTR _b$[ebp+4]
	mov	DWORD PTR _r$[ebp+12], ecx
$L65260:

; 707  : 
; 708  : 	return r;

	mov	edx, DWORD PTR ___$ReturnUdt$[ebp]
	mov	eax, DWORD PTR _r$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _r$[ebp+4]
	mov	DWORD PTR [edx+4], ecx
	mov	eax, DWORD PTR _r$[ebp+8]
	mov	DWORD PTR [edx+8], eax
	mov	ecx, DWORD PTR _r$[ebp+12]
	mov	DWORD PTR [edx+12], ecx
	mov	eax, DWORD PTR ___$ReturnUdt$[ebp]

; 709  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	36					; 00000024H
?ClipRectToRect@DISPLAY@@AAE?AUtagRECT@@U2@0@Z ENDP	; DISPLAY::ClipRectToRect
_TEXT	ENDS
PUBLIC	?Pause@DISPLAY@@QAE_NXZ				; DISPLAY::Pause
PUBLIC	??_C@_04DAIO@Dark?$AA@				; `string'
;	COMDAT ??_C@_04DAIO@Dark?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\display.cpp
CONST	SEGMENT
??_C@_04DAIO@Dark?$AA@ DB 'Dark', 00H			; `string'
CONST	ENDS
;	COMDAT ?Pause@DISPLAY@@QAE_NXZ
_TEXT	SEGMENT
_this$ = -4
$T65459 = -20
?Pause@DISPLAY@@QAE_NXZ PROC NEAR			; DISPLAY::Pause, COMDAT

; 712  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 84					; 00000054H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 713  : 	r2 = ClipRectToScreen(Dark.ir);

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 168				; 000000a8H
	sub	esp, 16					; 00000010H
	mov	ecx, esp
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax
	lea	ecx, DWORD PTR $T65459[ebp]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ClipRectToScreen@DISPLAY@@AAE?AUtagRECT@@U2@@Z ; DISPLAY::ClipRectToScreen
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 272				; 00000110H
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR [edx+4], ecx
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [edx+8], ecx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [edx+12], eax

; 714  : 
; 715  : 	if(	(e = DDS_Primary->Blt(WndRect, Dark.gfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 272				; 00000110H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+184]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+236]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+212]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+212]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65267

; 716  : 		return DDE("DrawLayers:Blt", e, "Dark");

	push	OFFSET FLAT:??_C@_04DAIO@Dark?$AA@	; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	SHORT $L65264
$L65267:

; 717  : 
; 718  : 	return 0;

	xor	al, al
$L65264:

; 719  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Pause@DISPLAY@@QAE_NXZ ENDP				; DISPLAY::Pause
_TEXT	ENDS
END
