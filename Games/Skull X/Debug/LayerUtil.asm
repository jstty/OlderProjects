	TITLE	D:\Game Programming\Moggie Software Games\old code\old Skull X\C++ Files\LayerUtil.cpp
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
;	COMDAT ??_C@_0BE@PJGD@CopyLayer?3new?5layer?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@BJFJ@DrawLayers?3FloodFill?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@MCEO@Create?3TextBox?3?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BH@GIHL@SetColorKey?3TextBox?3?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@FMGP@FloodFill?3TextBox?3?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@GENF@DrawLayers?3Blt?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@NLFM@Create?3TextBox?3temp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BJ@DFCB@SetColorKey?3TextBox?3temp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BH@MNFO@FloodFill?3TextBox?3temp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BJ@IJCF@Blt?3TextBox?3char?5to?5temp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BK@LHFH@Blt?3TextBox?3temp?5to?5layer?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@LOFJ@Load?3Sprite?3?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BG@OADL@SetColorKey?3Sprite?3?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0O@HIDH@Load?3Image?3?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@BKPH@SetColorKey?3Image?3?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_06GPIJ@Map?3?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@POGI@Map?3temp?5to?5gfx?3?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_07LPMI@Tile?3?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@LEAD@Tile?3temp?5to?5gfx?3?$CFs?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0M@CEJJ@Window?3Left?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@GLFJ@Window?3left?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0N@BMLL@Window?3right?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@CLK@Window?3right?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0L@KIBD@Window?3top?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BH@GPMC@Window?3tab?5Left?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@LGOP@Window?3tab?5right?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@DAPE@Window?3tab?5middle?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BJ@INLL@Window?3tab?5middle?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@ENDJ@Window?3top?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0O@DDMC@Window?3bottom?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@CDGK@Window?3bottom?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0O@KNHA@Window?3middle?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@CBAP@Window?3middle?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BJ@OIGE@Window?3top?5middle?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BP@GHII@Window?3top?5right?5middle?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BH@EJFD@Window?3top?5left?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@GJJI@Window?3top?5right?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@CCBN@Window?3bottom?5left?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BK@JMFA@Window?3bottom?5left?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@IOBH@Window?3bottom?5right?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BL@FFEN@Window?3bottom?5right?5to?5gfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@MLMK@DrawTile?3TempGfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BJ@LCGH@DrawTile?3tile?5to?5TempGfx?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@OJFJ@DrawTile?3TempGfx?5to?5out?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@PHM@SetCounter?3counter?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_02MECO@?$CFd?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0DH@EMLF@Class?3?5?$CFs?5?$HM?$HM?5Function?3?5?$CFs?6Error?3@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0FA@CEOG@Unable?5to?5match?5primary?5surface?5@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_07LGIJ@DISPLAY?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0ED@JKGC@One?5or?5more?5of?5the?5caps?5bits?5pas@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EF@LJOP@DirectDraw?5received?5a?5pointer?5th@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EN@OLML@One?5or?5more?5of?5the?5parameters?5pa@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0CH@FCNI@Pixel?5format?5was?5invalid?5as?5spec@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0GI@HBFO@Operation?5could?5not?5be?5carried?5o@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0FK@LBPK@Create?5function?5called?5without?5D@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0GG@LFFD@A?5hardware?5only?5DirectDraw?5objec@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0CC@MBLC@Software?5emulation?5not?5available@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0GM@GGHG@Operation?5requires?5the?5applicati@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0CM@JALL@Flipping?5visible?5surfaces?5is?5not@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0GO@IMM@Operation?5could?5not?5be?5carried?5o@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0FM@INDP@Operation?5could?5not?5be?5carried?5o@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EB@MKAC@DirectDraw?5does?5not?5have?5enough?5@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0DD@IGFL@This?5process?5already?5has?5created@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0DB@PJFD@The?5display?5is?5currently?5in?5an?5u@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0EH@DLMK@An?5exception?5was?5encountered?5whi@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@FNBO@Generic?5failure?4?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0CA@LBIE@Rectangle?5provided?5was?5invalid?4?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_09DBDE@No?5blter?4?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0GB@KBFD@Access?5to?5this?5surface?5is?5being?5@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0JP@HFMO@Access?5to?5this?5surface?5is?5being?5@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BG@BGLN@Action?5not?5supported?4?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0FI@IAJO@A?5DirectDraw?5object?5representing@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0FB@DPKI@The?5GUID?5passed?5to?5DirectDrawCre@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_03NMFM@?$DP?$DP?$DP?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??8@YAHABU_GUID@@0@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?Reset@LAYER@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?JumptoFirstCel@LAYER@@QAEXXZ
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetClipRect@LAYER@@QAEXJJJJ@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetSize@LAYER@@QAEXJJ@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetHotSpot@LAYER@@QAEXJJ@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetPos@LAYER@@QAEXJJ@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?GetType@ERRORCLASS@@AAEHH@Z
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
;	COMDAT ?SetStr@DISPLAY@@QAEXPAPADPBD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetStr@DISPLAY@@QAEXPAPADPBD_E@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?PlaceLayerAfter@DISPLAY@@QAEXPAVLAYER@@0@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?AppendLayer@DISPLAY@@QAEXPAVLAYER@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CopyLayer@DISPLAY@@QAEPAVLAYER@@PAV2@PAD_E@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CopyGfx@DISPLAY@@QAEPAUIDirectDrawSurface7@@PAU2@_G1@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CreateTextBox@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CreateSprite@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CreateImage@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CreateMap@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CreateTile@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CreateWin@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DrawTile@DISPLAY@@AAE_NPAUIDirectDrawSurface7@@0_G111@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?CreateCounter@DISPLAY@@QAEPAVLAYER@@JJ_EPAD001@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetCounter@DISPLAY@@QAE_NPAVLAYER@@PAD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetCounter@DISPLAY@@QAE_NPAVLAYER@@_I@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DestroyLayer@DISPLAY@@QAEXPAVLAYER@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?DDE@DISPLAY@@QAE_NPADJ0@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?SetStr@DISPLAY@@QAEXPAPADPBD@Z			; DISPLAY::SetStr
EXTRN	??2@YAPAXI@Z:NEAR				; operator new
EXTRN	_strcpy:NEAR
EXTRN	_strlen:NEAR
;	COMDAT ?SetStr@DISPLAY@@QAEXPAPADPBD@Z
_TEXT	SEGMENT
$T59124 = -8
_a$ = 8
_b$ = 12
_this$ = -4
?SetStr@DISPLAY@@QAEXPAPADPBD@Z PROC NEAR		; DISPLAY::SetStr, COMDAT

; 14   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 15   : 	*a = new char[ strlen(b) ];

	mov	eax, DWORD PTR _b$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59124[ebp], eax
	mov	ecx, DWORD PTR _a$[ebp]
	mov	edx, DWORD PTR $T59124[ebp]
	mov	DWORD PTR [ecx], edx

; 16   : 	strcpy(*a, b);

	mov	eax, DWORD PTR _b$[ebp]
	push	eax
	mov	ecx, DWORD PTR _a$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8

; 17   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?SetStr@DISPLAY@@QAEXPAPADPBD@Z ENDP			; DISPLAY::SetStr
_TEXT	ENDS
PUBLIC	?SetStr@DISPLAY@@QAEXPAPADPBD_E@Z		; DISPLAY::SetStr
EXTRN	_strncpy:NEAR
;	COMDAT ?SetStr@DISPLAY@@QAEXPAPADPBD_E@Z
_TEXT	SEGMENT
$T59127 = -8
_a$ = 8
_b$ = 12
_num$ = 16
_this$ = -4
?SetStr@DISPLAY@@QAEXPAPADPBD_E@Z PROC NEAR		; DISPLAY::SetStr, COMDAT

; 20   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 21   : 	*a = new char[ num + 1 ];

	mov	eax, DWORD PTR _num$[ebp]
	and	eax, 255				; 000000ffH
	add	eax, 1
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59127[ebp], eax
	mov	ecx, DWORD PTR _a$[ebp]
	mov	edx, DWORD PTR $T59127[ebp]
	mov	DWORD PTR [ecx], edx

; 22   : 	strncpy(*a, b, num);

	mov	eax, DWORD PTR _num$[ebp]
	and	eax, 255				; 000000ffH
	push	eax
	mov	ecx, DWORD PTR _b$[ebp]
	push	ecx
	mov	edx, DWORD PTR _a$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_strncpy
	add	esp, 12					; 0000000cH

; 23   : 	(*a)[num] = 0;

	mov	ecx, DWORD PTR _num$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _a$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	BYTE PTR [eax+ecx], 0

; 24   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	12					; 0000000cH
?SetStr@DISPLAY@@QAEXPAPADPBD_E@Z ENDP			; DISPLAY::SetStr
_TEXT	ENDS
PUBLIC	?PlaceLayerAfter@DISPLAY@@QAEXPAVLAYER@@0@Z	; DISPLAY::PlaceLayerAfter
;	COMDAT ?PlaceLayerAfter@DISPLAY@@QAEXPAVLAYER@@0@Z
_TEXT	SEGMENT
_layer$ = 8
_A$ = 12
_this$ = -4
?PlaceLayerAfter@DISPLAY@@QAEXPAVLAYER@@0@Z PROC NEAR	; DISPLAY::PlaceLayerAfter, COMDAT

; 27   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 28   : 	if((layer != NULL) && (A != NULL) )

	cmp	DWORD PTR _layer$[ebp], 0
	je	$L58141
	cmp	DWORD PTR _A$[ebp], 0
	je	$L58141

; 30   : 		if(EndLayer == NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+204], 0
	jne	SHORT $L58131

; 32   : 			EndLayer = layer;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _layer$[ebp]
	mov	DWORD PTR [ecx+204], edx

; 33   : 
; 34   : 			if(StartLayer == NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+200], 0
	jne	SHORT $L58132

; 35   : 				StartLayer = layer;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _layer$[ebp]
	mov	DWORD PTR [ecx+200], edx
$L58132:

; 37   : 		else

	jmp	$L58141
$L58131:

; 39   : 			if( (layer->prev != NULL) && (layer->next != NULL))

	mov	eax, DWORD PTR _layer$[ebp]
	cmp	DWORD PTR [eax+156], 0
	je	$L58134
	mov	ecx, DWORD PTR _layer$[ebp]
	cmp	DWORD PTR [ecx+160], 0
	je	$L58134

; 41   : 				// fill gap
; 42   : 				if(layer->prev != NULL)

	mov	edx, DWORD PTR _layer$[ebp]
	cmp	DWORD PTR [edx+156], 0
	je	SHORT $L58135

; 44   : 					if(layer->next != NULL)

	mov	eax, DWORD PTR _layer$[ebp]
	cmp	DWORD PTR [eax+160], 0
	je	SHORT $L58136

; 45   : 						layer->prev->next = layer->next;

	mov	ecx, DWORD PTR _layer$[ebp]
	mov	edx, DWORD PTR [ecx+156]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	ecx, DWORD PTR [eax+160]
	mov	DWORD PTR [edx+160], ecx
$L58136:

; 47   : 				// if no provious then it must be the first layer
; 48   : 				else if(StartLayer != NULL)

	jmp	SHORT $L58140
$L58135:
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+200], 0
	je	SHORT $L58138

; 49   : 					StartLayer = StartLayer->next;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+200]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+160]
	mov	DWORD PTR [edx+200], eax

; 50   : 				else if(StartLayer == NULL)

	jmp	SHORT $L58140
$L58138:
	mov	ecx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [ecx+200], 0
	jne	SHORT $L58140

; 51   : 					StartLayer = layer;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	DWORD PTR [edx+200], eax
$L58140:

; 52   : 
; 53   : 				layer->next = A->next;

	mov	ecx, DWORD PTR _layer$[ebp]
	mov	edx, DWORD PTR _A$[ebp]
	mov	eax, DWORD PTR [edx+160]
	mov	DWORD PTR [ecx+160], eax

; 54   : 				A->next = layer;

	mov	ecx, DWORD PTR _A$[ebp]
	mov	edx, DWORD PTR _layer$[ebp]
	mov	DWORD PTR [ecx+160], edx

; 56   : 			else

	jmp	SHORT $L58141
$L58134:

; 58   : 				layer->next = A->next;

	mov	eax, DWORD PTR _layer$[ebp]
	mov	ecx, DWORD PTR _A$[ebp]
	mov	edx, DWORD PTR [ecx+160]
	mov	DWORD PTR [eax+160], edx

; 59   : 				A->next = layer;

	mov	eax, DWORD PTR _A$[ebp]
	mov	ecx, DWORD PTR _layer$[ebp]
	mov	DWORD PTR [eax+160], ecx
$L58141:

; 63   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?PlaceLayerAfter@DISPLAY@@QAEXPAVLAYER@@0@Z ENDP	; DISPLAY::PlaceLayerAfter
_TEXT	ENDS
PUBLIC	?AppendLayer@DISPLAY@@QAEXPAVLAYER@@@Z		; DISPLAY::AppendLayer
;	COMDAT ?AppendLayer@DISPLAY@@QAEXPAVLAYER@@@Z
_TEXT	SEGMENT
_layer$ = 8
_this$ = -4
?AppendLayer@DISPLAY@@QAEXPAVLAYER@@@Z PROC NEAR	; DISPLAY::AppendLayer, COMDAT

; 67   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 68   : 	if(layer!= NULL)

	cmp	DWORD PTR _layer$[ebp], 0
	je	$L58157

; 70   : 		if(EndLayer == NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+204], 0
	jne	SHORT $L58147

; 72   : 			EndLayer = layer;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _layer$[ebp]
	mov	DWORD PTR [ecx+204], edx

; 73   : 
; 74   : 			if(StartLayer == NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+200], 0
	jne	SHORT $L58148

; 75   : 				StartLayer = layer;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _layer$[ebp]
	mov	DWORD PTR [ecx+200], edx
$L58148:

; 77   : 		else

	jmp	$L58157
$L58147:

; 79   : 			if( (layer->prev != NULL) && (layer->next != NULL))

	mov	eax, DWORD PTR _layer$[ebp]
	cmp	DWORD PTR [eax+156], 0
	je	$L58150
	mov	ecx, DWORD PTR _layer$[ebp]
	cmp	DWORD PTR [ecx+160], 0
	je	$L58150

; 81   : 				// fill gap
; 82   : 				if(layer->prev != NULL)

	mov	edx, DWORD PTR _layer$[ebp]
	cmp	DWORD PTR [edx+156], 0
	je	SHORT $L58151

; 84   : 					if(layer->next != NULL)

	mov	eax, DWORD PTR _layer$[ebp]
	cmp	DWORD PTR [eax+160], 0
	je	SHORT $L58152

; 85   : 						layer->prev->next = layer->next;

	mov	ecx, DWORD PTR _layer$[ebp]
	mov	edx, DWORD PTR [ecx+156]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	ecx, DWORD PTR [eax+160]
	mov	DWORD PTR [edx+160], ecx
$L58152:

; 87   : 				// if no provious then it must be the first layer
; 88   : 				else if(StartLayer != NULL)

	jmp	SHORT $L58156
$L58151:
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+200], 0
	je	SHORT $L58154

; 89   : 					StartLayer = StartLayer->next;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+200]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+160]
	mov	DWORD PTR [edx+200], eax

; 90   : 				else if(StartLayer == NULL)

	jmp	SHORT $L58156
$L58154:
	mov	ecx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [ecx+200], 0
	jne	SHORT $L58156

; 91   : 					StartLayer = layer;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	DWORD PTR [edx+200], eax
$L58156:

; 92   : 
; 93   : 				layer->prev = EndLayer;

	mov	ecx, DWORD PTR _layer$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+204]
	mov	DWORD PTR [ecx+156], eax

; 94   : 				EndLayer->next = layer;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+204]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	DWORD PTR [edx+160], eax

; 95   : 				EndLayer = layer;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _layer$[ebp]
	mov	DWORD PTR [ecx+204], edx

; 96   : 				EndLayer->next = NULL;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+204]
	mov	DWORD PTR [ecx+160], 0

; 98   : 			else

	jmp	SHORT $L58157
$L58150:

; 100  : 				layer->prev = EndLayer;

	mov	edx, DWORD PTR _layer$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+204]
	mov	DWORD PTR [edx+156], ecx

; 101  : 				EndLayer->next = layer;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+204]
	mov	ecx, DWORD PTR _layer$[ebp]
	mov	DWORD PTR [eax+160], ecx

; 102  : 				EndLayer = layer;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	DWORD PTR [edx+204], eax

; 103  : 				EndLayer->next = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+204]
	mov	DWORD PTR [edx+160], 0
$L58157:

; 107  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?AppendLayer@DISPLAY@@QAEXPAVLAYER@@@Z ENDP		; DISPLAY::AppendLayer
_TEXT	ENDS
PUBLIC	?Reset@LAYER@@QAEXXZ				; LAYER::Reset
PUBLIC	?CopyLayer@DISPLAY@@QAEPAVLAYER@@PAV2@PAD_E@Z	; DISPLAY::CopyLayer
PUBLIC	?CopyGfx@DISPLAY@@QAEPAUIDirectDrawSurface7@@PAU2@_G1@Z ; DISPLAY::CopyGfx
EXTRN	_memset:NEAR
;	COMDAT ?CopyLayer@DISPLAY@@QAEPAVLAYER@@PAV2@PAD_E@Z
_TEXT	SEGMENT
$T59134 = -28
$T59135 = -32
$T59136 = -36
_layer$ = 8
_name$ = 12
_PlacementType$ = 16
_this$ = -4
_temp$ = -8
_ta$58172 = -12
_tc$58173 = -16
_i$58174 = -20
_j$58175 = -24
?CopyLayer@DISPLAY@@QAEPAVLAYER@@PAV2@PAD_E@Z PROC NEAR	; DISPLAY::CopyLayer, COMDAT

; 110  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 100				; 00000064H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 111  : 	LAYER *temp = new LAYER;

	push	164					; 000000a4H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59134[ebp], eax
	mov	eax, DWORD PTR $T59134[ebp]
	mov	DWORD PTR _temp$[ebp], eax

; 112  : 	ZeroMemory(temp, sizeof(LAYER));

	push	164					; 000000a4H
	push	0
	mov	ecx, DWORD PTR _temp$[ebp]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 113  : 
; 114  : 	temp->extra1 = layer->extra1;

	mov	edx, DWORD PTR _temp$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	cl, BYTE PTR [eax+5]
	mov	BYTE PTR [edx+5], cl

; 115  : 	temp->extra2 = layer->extra2;

	mov	edx, DWORD PTR _temp$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	cl, BYTE PTR [eax+6]
	mov	BYTE PTR [edx+6], cl

; 116  : 	temp->extra3 = layer->extra3;

	mov	edx, DWORD PTR _temp$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	cl, BYTE PTR [eax+7]
	mov	BYTE PTR [edx+7], cl

; 117  : 
; 118  : 	temp->redraw = layer->redraw;

	mov	edx, DWORD PTR _temp$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	cl, BYTE PTR [eax+8]
	mov	BYTE PTR [edx+8], cl

; 119  : 	temp->visable = layer->visable;

	mov	edx, DWORD PTR _temp$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	cl, BYTE PTR [eax+9]
	mov	BYTE PTR [edx+9], cl

; 120  : 	
; 121  : 	temp->type = layer->type;

	mov	edx, DWORD PTR _temp$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	cl, BYTE PTR [eax+4]
	mov	BYTE PTR [edx+4], cl

; 122  : 
; 123  : 	temp->clear_dd = layer->clear_dd;

	mov	edx, DWORD PTR _temp$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	cl, BYTE PTR [eax+10]
	mov	BYTE PTR [edx+10], cl

; 124  : 	temp->tick = layer->tick;

	mov	edx, DWORD PTR _temp$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [edx+12], ecx

; 125  : 
; 126  : 	if(name == NULL)

	cmp	DWORD PTR _name$[ebp], 0
	jne	SHORT $L58168

; 127  : 		temp->Name = layer->Name;

	mov	edx, DWORD PTR _temp$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx

; 128  : 	else

	jmp	SHORT $L58169
$L58168:

; 129  : 		SetStr(&temp->Name, name);

	mov	edx, DWORD PTR _name$[ebp]
	push	edx
	mov	eax, DWORD PTR _temp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr
$L58169:

; 130  : 
; 131  : 	temp->mList = layer->mList;

	mov	ecx, DWORD PTR _temp$[ebp]
	mov	edx, DWORD PTR _layer$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR [ecx+16], eax

; 132  : 	temp->move = layer->move;

	mov	ecx, DWORD PTR _temp$[ebp]
	mov	edx, DWORD PTR _layer$[ebp]
	mov	eax, DWORD PTR [edx+20]
	mov	DWORD PTR [ecx+20], eax

; 133  : 
; 134  : 	if(layer->move != NULL)

	mov	ecx, DWORD PTR _layer$[ebp]
	cmp	DWORD PTR [ecx+20], 0
	je	SHORT $L58170

; 135  : 		temp->d = layer->move->fd;

	mov	edx, DWORD PTR _layer$[ebp]
	mov	eax, DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _temp$[ebp]
	mov	edx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+32], edx
$L58170:

; 136  : 	/*
; 137  : 	// not sure
; 138  : 	if(layer->move != NULL)
; 139  : 	{
; 140  : 		temp->move = new MOVE;
; 141  : 		unsigned __int8 num = layer->move->num - 1;
; 142  : 		temp->move->fd = new XY[num];
; 143  : 		temp->move->delay = layer->move->delay;
; 144  : 		for(j = 0; j < num; j++)
; 145  : 		{
; 146  : 			temp->move->fd[j].x = layer->move->fd[j].x;
; 147  : 			temp->move->fd[j].y = layer->move->fd[j].y;
; 148  : 			temp->move->fd[j].next = &temp->move->fd[j + 1];
; 149  : 		}
; 150  : 		temp->move->fd[j].x = layer->move->fd[j].x;
; 151  : 		temp->move->fd[j].y = layer->move->fd[j].y;
; 152  : 		temp->move->fd[j].next = NULL;
; 153  : 		temp->d = temp->move->fd;
; 154  : 	}
; 155  : 	*/
; 156  : 
; 157  : 	temp->moveable = layer->moveable;

	mov	eax, DWORD PTR _temp$[ebp]
	mov	ecx, DWORD PTR _layer$[ebp]
	mov	dl, BYTE PTR [ecx+24]
	mov	BYTE PTR [eax+24], dl

; 158  : 	temp->movement_done = layer->movement_done;

	mov	eax, DWORD PTR _temp$[ebp]
	mov	ecx, DWORD PTR _layer$[ebp]
	mov	dl, BYTE PTR [ecx+25]
	mov	BYTE PTR [eax+25], dl

; 159  : 	temp->move_type = layer->move_type;

	mov	eax, DWORD PTR _temp$[ebp]
	mov	ecx, DWORD PTR _layer$[ebp]
	mov	dl, BYTE PTR [ecx+26]
	mov	BYTE PTR [eax+26], dl

; 160  : 	temp->move_count = layer->move_count;

	mov	eax, DWORD PTR _temp$[ebp]
	mov	ecx, DWORD PTR _layer$[ebp]
	mov	dl, BYTE PTR [ecx+27]
	mov	BYTE PTR [eax+27], dl

; 161  : 	temp->o_move_count = layer->o_move_count;

	mov	eax, DWORD PTR _temp$[ebp]
	mov	ecx, DWORD PTR _layer$[ebp]
	mov	dl, BYTE PTR [ecx+28]
	mov	BYTE PTR [eax+28], dl

; 162  : 	temp->move_tick = layer->move_tick;

	mov	eax, DWORD PTR _temp$[ebp]
	mov	ecx, DWORD PTR _layer$[ebp]
	mov	edx, DWORD PTR [ecx+36]
	mov	DWORD PTR [eax+36], edx

; 163  : 
; 164  : 	temp->col = layer->col;

	mov	eax, DWORD PTR _temp$[ebp]
	mov	ecx, DWORD PTR _layer$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	DWORD PTR [eax+40], edx

; 165  : 	temp->collidable = layer->collidable;

	mov	eax, DWORD PTR _temp$[ebp]
	mov	ecx, DWORD PTR _layer$[ebp]
	mov	dl, BYTE PTR [ecx+44]
	mov	BYTE PTR [eax+44], dl

; 166  : 
; 167  : 	temp->clip = layer->clip;

	mov	eax, DWORD PTR _temp$[ebp]
	mov	ecx, DWORD PTR _layer$[ebp]
	mov	dl, BYTE PTR [ecx+52]
	mov	BYTE PTR [eax+52], dl

; 168  : 	temp->cr = layer->cr;

	mov	eax, DWORD PTR _layer$[ebp]
	add	eax, 56					; 00000038H
	mov	ecx, DWORD PTR _temp$[ebp]
	add	ecx, 56					; 00000038H
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax

; 169  : 
; 170  : 	temp->hx = layer->hx;

	mov	ecx, DWORD PTR _temp$[ebp]
	mov	edx, DWORD PTR _layer$[ebp]
	mov	eax, DWORD PTR [edx+72]
	mov	DWORD PTR [ecx+72], eax

; 171  : 	temp->hy = layer->hy;

	mov	ecx, DWORD PTR _temp$[ebp]
	mov	edx, DWORD PTR _layer$[ebp]
	mov	eax, DWORD PTR [edx+76]
	mov	DWORD PTR [ecx+76], eax

; 172  : 	temp->r = layer->r;

	mov	ecx, DWORD PTR _layer$[ebp]
	add	ecx, 80					; 00000050H
	mov	edx, DWORD PTR _temp$[ebp]
	add	edx, 80					; 00000050H
	mov	eax, DWORD PTR [ecx]
	mov	DWORD PTR [edx], eax
	mov	eax, DWORD PTR [ecx+4]
	mov	DWORD PTR [edx+4], eax
	mov	eax, DWORD PTR [ecx+8]
	mov	DWORD PTR [edx+8], eax
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+12], ecx

; 173  : 	temp->ir = layer->ir;

	mov	edx, DWORD PTR _layer$[ebp]
	add	edx, 96					; 00000060H
	mov	eax, DWORD PTR _temp$[ebp]
	add	eax, 96					; 00000060H
	mov	ecx, DWORD PTR [edx]
	mov	DWORD PTR [eax], ecx
	mov	ecx, DWORD PTR [edx+4]
	mov	DWORD PTR [eax+4], ecx
	mov	ecx, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+8], ecx
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+12], edx

; 174  : 	temp->old_r = layer->old_r;

	mov	eax, DWORD PTR _layer$[ebp]
	add	eax, 112				; 00000070H
	mov	ecx, DWORD PTR _temp$[ebp]
	add	ecx, 112				; 00000070H
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	edx, DWORD PTR [eax+4]
	mov	DWORD PTR [ecx+4], edx
	mov	edx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+8], edx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+12], eax

; 175  : 	temp->old_ir = layer->old_ir;

	mov	ecx, DWORD PTR _layer$[ebp]
	add	ecx, 128				; 00000080H
	mov	edx, DWORD PTR _temp$[ebp]
	add	edx, 128				; 00000080H
	mov	eax, DWORD PTR [ecx]
	mov	DWORD PTR [edx], eax
	mov	eax, DWORD PTR [ecx+4]
	mov	DWORD PTR [edx+4], eax
	mov	eax, DWORD PTR [ecx+8]
	mov	DWORD PTR [edx+8], eax
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+12], ecx

; 176  : 
; 177  : 	if(layer->startanim != NULL)

	mov	edx, DWORD PTR _layer$[ebp]
	cmp	DWORD PTR [edx+152], 0
	je	$L58171

; 179  : 		ANIM *ta;
; 180  : 		CEL *tc;
; 181  : 		unsigned __int8 i, j;
; 182  : 
; 183  : 		ta = temp->anim = temp->startanim = new ANIM[layer->NumAnim];

	mov	eax, DWORD PTR _layer$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+6]
	imul	ecx, 24					; 00000018H
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59135[ebp], eax
	mov	edx, DWORD PTR _temp$[ebp]
	mov	eax, DWORD PTR $T59135[ebp]
	mov	DWORD PTR [edx+152], eax
	mov	ecx, DWORD PTR _temp$[ebp]
	mov	edx, DWORD PTR $T59135[ebp]
	mov	DWORD PTR [ecx+148], edx
	mov	eax, DWORD PTR $T59135[ebp]
	mov	DWORD PTR _ta$58172[ebp], eax

; 184  : 		ZeroMemory(ta, layer->NumAnim*sizeof(ANIM));

	mov	ecx, DWORD PTR _layer$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+6]
	imul	edx, 24					; 00000018H
	push	edx
	push	0
	mov	eax, DWORD PTR _ta$58172[ebp]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 185  : 
; 186  : 		for(i = 0, a = layer->startanim; (a != NULL) || (ta != NULL); i++, a = a->next, ta = ta->next)

	mov	BYTE PTR _i$58174[ebp], 0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _layer$[ebp]
	mov	eax, DWORD PTR [edx+152]
	mov	DWORD PTR [ecx+364], eax
	jmp	SHORT $L58179
$L58180:
	mov	cl, BYTE PTR _i$58174[ebp]
	add	cl, 1
	mov	BYTE PTR _i$58174[ebp], cl
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+364]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [eax+20]
	mov	DWORD PTR [ecx+364], edx
	mov	eax, DWORD PTR _ta$58172[ebp]
	mov	ecx, DWORD PTR [eax+20]
	mov	DWORD PTR _ta$58172[ebp], ecx
$L58179:
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+364], 0
	jne	SHORT $L58182
	cmp	DWORD PTR _ta$58172[ebp], 0
	je	$L58181
$L58182:

; 188  : 			ta->name = a->name;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR _ta$58172[ebp]
	mov	eax, DWORD PTR [ecx]
	mov	DWORD PTR [edx], eax

; 189  : 			ta->done = a->done;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	mov	eax, DWORD PTR _ta$58172[ebp]
	mov	cl, BYTE PTR [edx+4]
	mov	BYTE PTR [eax+4], cl

; 190  : 			ta->loop_type = a->loop_type;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+364]
	mov	ecx, DWORD PTR _ta$58172[ebp]
	mov	dl, BYTE PTR [eax+5]
	mov	BYTE PTR [ecx+5], dl

; 191  : 			ta->loop_count = a->loop_count;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR _ta$58172[ebp]
	mov	al, BYTE PTR [ecx+6]
	mov	BYTE PTR [edx+6], al

; 192  : 			ta->o_loop_count =  a->o_loop_count;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	mov	eax, DWORD PTR _ta$58172[ebp]
	mov	cl, BYTE PTR [edx+7]
	mov	BYTE PTR [eax+7], cl

; 193  : 
; 194  : 			if(i < (layer->NumAnim - 1) )

	mov	edx, DWORD PTR _i$58174[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _layer$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+6]
	sub	ecx, 1
	cmp	edx, ecx
	jge	SHORT $L58183

; 195  : 				ta->next = &temp->anim[i + 1];

	mov	edx, DWORD PTR _i$58174[ebp]
	and	edx, 255				; 000000ffH
	add	edx, 1
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _temp$[ebp]
	mov	ecx, DWORD PTR [eax+148]
	add	ecx, edx
	mov	edx, DWORD PTR _ta$58172[ebp]
	mov	DWORD PTR [edx+20], ecx

; 196  : 			else

	jmp	SHORT $L58184
$L58183:

; 197  : 				ta->next = NULL;

	mov	eax, DWORD PTR _ta$58172[ebp]
	mov	DWORD PTR [eax+20], 0
$L58184:

; 198  : 
; 199  : 			ta->nCel = a->nCel;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	mov	eax, DWORD PTR _ta$58172[ebp]
	mov	cl, BYTE PTR [edx+8]
	mov	BYTE PTR [eax+8], cl

; 200  : 			
; 201  : 			tc = ta->cel = ta->startcel = new CEL[a->nCel];

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+364]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+8]
	imul	ecx, 24					; 00000018H
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59136[ebp], eax
	mov	edx, DWORD PTR _ta$58172[ebp]
	mov	eax, DWORD PTR $T59136[ebp]
	mov	DWORD PTR [edx+12], eax
	mov	ecx, DWORD PTR _ta$58172[ebp]
	mov	edx, DWORD PTR $T59136[ebp]
	mov	DWORD PTR [ecx+16], edx
	mov	eax, DWORD PTR $T59136[ebp]
	mov	DWORD PTR _tc$58173[ebp], eax

; 202  : 			ZeroMemory(tc, a->nCel*sizeof(CEL));

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	xor	eax, eax
	mov	al, BYTE PTR [edx+8]
	imul	eax, 24					; 00000018H
	push	eax
	push	0
	mov	ecx, DWORD PTR _tc$58173[ebp]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 203  : 			
; 204  : 			for(j = 0, c = a->startcel; (c != NULL) || (tc != NULL) ; j++, c = c->next, tc = tc->next)

	mov	BYTE PTR _j$58175[ebp], 0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+364]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+368], edx
	jmp	SHORT $L58188
$L58189:
	mov	al, BYTE PTR _j$58175[ebp]
	add	al, 1
	mov	BYTE PTR _j$58175[ebp], al
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+20]
	mov	DWORD PTR [eax+368], ecx
	mov	edx, DWORD PTR _tc$58173[ebp]
	mov	eax, DWORD PTR [edx+20]
	mov	DWORD PTR _tc$58173[ebp], eax
$L58188:
	mov	ecx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [ecx+368], 0
	jne	SHORT $L58191
	cmp	DWORD PTR _tc$58173[ebp], 0
	je	$L58190
$L58191:

; 206  : 				tc->delay = c->delay;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	ecx, DWORD PTR _tc$58173[ebp]
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx

; 207  : 				tc->w = c->w;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	mov	edx, DWORD PTR _tc$58173[ebp]
	mov	ax, WORD PTR [ecx+4]
	mov	WORD PTR [edx+4], ax

; 208  : 				tc->h = c->h;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	mov	eax, DWORD PTR _tc$58173[ebp]
	mov	cx, WORD PTR [edx+6]
	mov	WORD PTR [eax+6], cx

; 209  : 				tc->hx = c->hx;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	ecx, DWORD PTR _tc$58173[ebp]
	mov	dx, WORD PTR [eax+8]
	mov	WORD PTR [ecx+8], dx

; 210  : 				tc->hy = c->hy;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	mov	edx, DWORD PTR _tc$58173[ebp]
	mov	ax, WORD PTR [ecx+10]
	mov	WORD PTR [edx+10], ax

; 211  : 				tc->bx = c->bx;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	mov	eax, DWORD PTR _tc$58173[ebp]
	mov	cx, WORD PTR [edx+12]
	mov	WORD PTR [eax+12], cx

; 212  : 				tc->by = c->by;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	ecx, DWORD PTR _tc$58173[ebp]
	mov	dx, WORD PTR [eax+14]
	mov	WORD PTR [ecx+14], dx

; 213  : 				tc->gfx = CopyGfx(c->gfx, c->w, c->h);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	mov	dx, WORD PTR [ecx+6]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	mov	dx, WORD PTR [ecx+4]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?CopyGfx@DISPLAY@@QAEPAUIDirectDrawSurface7@@PAU2@_G1@Z ; DISPLAY::CopyGfx
	mov	ecx, DWORD PTR _tc$58173[ebp]
	mov	DWORD PTR [ecx+16], eax

; 214  : 
; 215  : 				if(j < (a->nCel - 1) )

	mov	edx, DWORD PTR _j$58175[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+8]
	sub	eax, 1
	cmp	edx, eax
	jge	SHORT $L58192

; 216  : 					tc->next = &ta->cel[j + 1];

	mov	ecx, DWORD PTR _j$58175[ebp]
	and	ecx, 255				; 000000ffH
	add	ecx, 1
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ta$58172[ebp]
	mov	eax, DWORD PTR [edx+16]
	add	eax, ecx
	mov	ecx, DWORD PTR _tc$58173[ebp]
	mov	DWORD PTR [ecx+20], eax

; 217  : 				else

	jmp	SHORT $L58193
$L58192:

; 218  : 					tc->next = NULL;

	mov	edx, DWORD PTR _tc$58173[ebp]
	mov	DWORD PTR [edx+20], 0
$L58193:

; 219  : 			}

	jmp	$L58189
$L58190:

; 220  : 		}

	jmp	$L58180
$L58181:

; 221  : 		temp->Reset();

	mov	ecx, DWORD PTR _temp$[ebp]
	call	?Reset@LAYER@@QAEXXZ			; LAYER::Reset

; 223  : 	else

	jmp	SHORT $L58194
$L58171:

; 225  : 		temp->gfx = CopyGfx(layer->gfx, (unsigned __int16)temp->ir.right, (unsigned __int16)temp->ir.bottom);

	mov	eax, DWORD PTR _temp$[ebp]
	mov	cx, WORD PTR [eax+108]
	push	ecx
	mov	edx, DWORD PTR _temp$[ebp]
	mov	ax, WORD PTR [edx+104]
	push	eax
	mov	ecx, DWORD PTR _layer$[ebp]
	mov	edx, DWORD PTR [ecx+144]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?CopyGfx@DISPLAY@@QAEPAUIDirectDrawSurface7@@PAU2@_G1@Z ; DISPLAY::CopyGfx
	mov	ecx, DWORD PTR _temp$[ebp]
	mov	DWORD PTR [ecx+144], eax

; 226  : 		temp->object = layer->object;

	mov	edx, DWORD PTR _temp$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	ecx, DWORD PTR [eax+148]
	mov	DWORD PTR [edx+148], ecx

; 227  : 		temp->lobject = layer->lobject;

	mov	edx, DWORD PTR _temp$[ebp]
	mov	eax, DWORD PTR _layer$[ebp]
	mov	ecx, DWORD PTR [eax+152]
	mov	DWORD PTR [edx+152], ecx
$L58194:

; 229  : 
; 230  : 	if(PlacementType)

	mov	edx, DWORD PTR _PlacementType$[ebp]
	and	edx, 255				; 000000ffH
	test	edx, edx
	je	SHORT $L58197

; 231  : 		PlaceLayerAfter(temp, layer);

	mov	eax, DWORD PTR _layer$[ebp]
	push	eax
	mov	ecx, DWORD PTR _temp$[ebp]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?PlaceLayerAfter@DISPLAY@@QAEXPAVLAYER@@0@Z ; DISPLAY::PlaceLayerAfter

; 232  : 	else

	jmp	SHORT $L58198
$L58197:

; 233  : 		AppendLayer(temp);

	mov	edx, DWORD PTR _temp$[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?AppendLayer@DISPLAY@@QAEXPAVLAYER@@@Z	; DISPLAY::AppendLayer
$L58198:

; 234  : 
; 235  : 	nLayers++;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+372]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+372], cl

; 236  : 
; 237  : 	return temp;

	mov	eax, DWORD PTR _temp$[ebp]

; 238  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	12					; 0000000cH
?CopyLayer@DISPLAY@@QAEPAVLAYER@@PAV2@PAD_E@Z ENDP	; DISPLAY::CopyLayer
_TEXT	ENDS
PUBLIC	?JumptoFirstCel@LAYER@@QAEXXZ			; LAYER::JumptoFirstCel
;	COMDAT ?Reset@LAYER@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
?Reset@LAYER@@QAEXXZ PROC NEAR				; LAYER::Reset, COMDAT

; 521  : 	{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 522  : 		anim->done = false;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+148]
	mov	BYTE PTR [ecx+4], 0

; 523  : 		anim->loop_count = anim->o_loop_count;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+148]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+148]
	mov	al, BYTE PTR [eax+7]
	mov	BYTE PTR [edx+6], al

; 524  : 		JumptoFirstCel();

	mov	ecx, DWORD PTR _this$[ebp]
	call	?JumptoFirstCel@LAYER@@QAEXXZ		; LAYER::JumptoFirstCel

; 525  : 	};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?Reset@LAYER@@QAEXXZ ENDP				; LAYER::Reset
_TEXT	ENDS
PUBLIC	?SetSize@LAYER@@QAEXJJ@Z			; LAYER::SetSize
PUBLIC	?SetHotSpot@LAYER@@QAEXJJ@Z			; LAYER::SetHotSpot
;	COMDAT ?JumptoFirstCel@LAYER@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4
?JumptoFirstCel@LAYER@@QAEXXZ PROC NEAR			; LAYER::JumptoFirstCel, COMDAT

; 537  : 	{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 538  : 		anim->cel = anim->startcel;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+148]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+148]
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [eax+16], ecx

; 539  : 		gfx = anim->cel->gfx;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+148]
	mov	ecx, DWORD PTR [eax+16]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+16]
	mov	DWORD PTR [edx+144], eax

; 540  : 		SetSize(anim->cel->w, anim->cel->h);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+148]
	mov	eax, DWORD PTR [edx+16]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+6]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+148]
	mov	ecx, DWORD PTR [eax+16]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+4]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetSize@LAYER@@QAEXJJ@Z		; LAYER::SetSize

; 541  : 		SetHotSpot(anim->cel->hx, anim->cel->hy);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+148]
	mov	edx, DWORD PTR [ecx+16]
	movsx	eax, WORD PTR [edx+10]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+148]
	mov	eax, DWORD PTR [edx+16]
	movsx	ecx, WORD PTR [eax+8]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetHotSpot@LAYER@@QAEXJJ@Z		; LAYER::SetHotSpot

; 542  : 		redraw = true;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+8], 1

; 543  : 	};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?JumptoFirstCel@LAYER@@QAEXXZ ENDP			; LAYER::JumptoFirstCel
_TEXT	ENDS
PUBLIC	?DDE@DISPLAY@@QAE_NPADJ0@Z			; DISPLAY::DDE
PUBLIC	??_C@_0BE@PJGD@CopyLayer?3new?5layer?$AA@	; `string'
PUBLIC	??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@	; `string'
PUBLIC	??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@	; `string'
PUBLIC	??_C@_0BF@BJFJ@DrawLayers?3FloodFill?$AA@	; `string'
EXTRN	_DDColorMatch:NEAR
EXTRN	_DDSetColorKey:NEAR
;	COMDAT ??_C@_0BE@PJGD@CopyLayer?3new?5layer?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\layerutil.cpp
CONST	SEGMENT
??_C@_0BE@PJGD@CopyLayer?3new?5layer?$AA@ DB 'CopyLayer:new layer', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@
CONST	SEGMENT
??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ DB 'LoadDrawS:CreateSurface', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@
CONST	SEGMENT
??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ DB 'LoadDrawS:DDSetColorKey', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@BJFJ@DrawLayers?3FloodFill?$AA@
CONST	SEGMENT
??_C@_0BF@BJFJ@DrawLayers?3FloodFill?$AA@ DB 'DrawLayers:FloodFill', 00H ; `string'
CONST	ENDS
;	COMDAT ?CopyGfx@DISPLAY@@QAEPAUIDirectDrawSurface7@@PAU2@_G1@Z
_TEXT	SEGMENT
_src$ = 8
_w$ = 12
_h$ = 16
_this$ = -4
_gfx$ = -8
_ddsd$ = -132
?CopyGfx@DISPLAY@@QAEPAUIDirectDrawSurface7@@PAU2@_G1@Z PROC NEAR ; DISPLAY::CopyGfx, COMDAT

; 241  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 196				; 000000c4H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 242  : 	GFXDATA gfx;
; 243  : 	r1.left = r1.top = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+260], 0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+256], 0

; 244  : 	r1.right = w;

	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+264], edx

; 245  : 	r1.bottom = h;

	mov	ecx, DWORD PTR _h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+268], ecx

; 246  : 	//
; 247  : 	DD_SDESC	ddsd;
; 248  : 	ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	eax, DWORD PTR _ddsd$[ebp]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 249  : 	ddsd.dwSize		= sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 250  : 	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 251  : 	ddsd.dwWidth	= w;

	mov	ecx, DWORD PTR _w$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+12], ecx

; 252  : 	ddsd.dwHeight	= h;

	mov	edx, DWORD PTR _h$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+8], edx

; 253  : 	//
; 254  : 	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

	mov	DWORD PTR _ddsd$[ebp+104], 2112		; 00000840H

; 255  : 	if( (e = DD_Object->CreateSurface(&ddsd, &gfx, NULL)) != DD_OK )

	push	0
	lea	eax, DWORD PTR _gfx$[ebp]
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
	je	SHORT $L58209

; 257  : 		if( DDE("LoadDrawS:CreateSurface", e, "CopyLayer:new layer") )

	push	OFFSET FLAT:??_C@_0BE@PJGD@CopyLayer?3new?5layer?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L58209

; 258  : 			return NULL;

	xor	eax, eax
	jmp	$L58204
$L58209:

; 260  : 	if( (e = DDSetColorKey(gfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	eax, DWORD PTR _gfx$[ebp]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58220

; 262  : 		if( DDE("LoadDrawS:DDSetColorKey", e, "CopyLayer:new layer") )

	push	OFFSET FLAT:??_C@_0BE@PJGD@CopyLayer?3new?5layer?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L58220

; 263  : 			return NULL;

	xor	eax, eax
	jmp	$L58204
$L58220:

; 265  : 	
; 266  : 	FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+228]
	push	eax
	call	_DDColorMatch
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+136], eax

; 267  : 	if(	(e = gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 56					; 00000038H
	push	edx
	push	1024					; 00000400H
	push	0
	push	0
	push	0
	mov	eax, DWORD PTR _gfx$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _gfx$[ebp]
	push	edx
	call	DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58230

; 269  : 		if( DDE("DrawLayers:FloodFill", e, "CopyLayer:new layer") )

	push	OFFSET FLAT:??_C@_0BE@PJGD@CopyLayer?3new?5layer?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BF@BJFJ@DrawLayers?3FloodFill?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L58230

; 270  : 			return NULL;

	xor	eax, eax
	jmp	SHORT $L58204
$L58230:

; 272  : 
; 273  : 	if(	(e = gfx->Blt(&r1, src, NULL,  DDBLT_KEYSRC, &FxBkg)) != DD_OK)

	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 56					; 00000038H
	push	edx
	push	32768					; 00008000H
	push	0
	mov	eax, DWORD PTR _src$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 256				; 00000100H
	push	ecx
	mov	edx, DWORD PTR _gfx$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _gfx$[ebp]
	push	ecx
	call	DWORD PTR [eax+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L58234

; 275  : 		if( DDE("DrawLayers:FloodFill", e, "CopyLayer:new layer") )

	push	OFFSET FLAT:??_C@_0BE@PJGD@CopyLayer?3new?5layer?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BF@BJFJ@DrawLayers?3FloodFill?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	and	eax, 255				; 000000ffH
	test	eax, eax
	je	SHORT $L58234

; 276  : 			return NULL;

	xor	eax, eax
	jmp	SHORT $L58204
$L58234:

; 278  : 
; 279  : 	return gfx;

	mov	eax, DWORD PTR _gfx$[ebp]
$L58204:

; 280  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	12					; 0000000cH
?CopyGfx@DISPLAY@@QAEPAUIDirectDrawSurface7@@PAU2@_G1@Z ENDP ; DISPLAY::CopyGfx
_TEXT	ENDS
PUBLIC	?CreateTextBox@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateTextBox
PUBLIC	?SetClipRect@LAYER@@QAEXJJJJ@Z			; LAYER::SetClipRect
PUBLIC	?SetPos@LAYER@@QAEXJJ@Z				; LAYER::SetPos
PUBLIC	??_C@_0BC@MCEO@Create?3TextBox?3?$CFs?$AA@	; `string'
PUBLIC	??_C@_0BH@GIHL@SetColorKey?3TextBox?3?$CFs?$AA@	; `string'
PUBLIC	??_C@_0BF@FMGP@FloodFill?3TextBox?3?$CFs?$AA@	; `string'
PUBLIC	??_C@_0P@GENF@DrawLayers?3Blt?$AA@		; `string'
PUBLIC	??_C@_0BE@NLFM@Create?3TextBox?3temp?$AA@	; `string'
PUBLIC	??_C@_0BJ@DFCB@SetColorKey?3TextBox?3temp?$AA@	; `string'
PUBLIC	??_C@_0BH@MNFO@FloodFill?3TextBox?3temp?$AA@	; `string'
PUBLIC	??_C@_0BJ@IJCF@Blt?3TextBox?3char?5to?5temp?$AA@ ; `string'
PUBLIC	??_C@_0BK@LHFH@Blt?3TextBox?3temp?5to?5layer?$AA@ ; `string'
EXTRN	_sprintf:NEAR
EXTRN	_strchr:NEAR
;	COMDAT ??_C@_0BC@MCEO@Create?3TextBox?3?$CFs?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\layerutil.cpp
CONST	SEGMENT
??_C@_0BC@MCEO@Create?3TextBox?3?$CFs?$AA@ DB 'Create:TextBox:%s', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BH@GIHL@SetColorKey?3TextBox?3?$CFs?$AA@
CONST	SEGMENT
??_C@_0BH@GIHL@SetColorKey?3TextBox?3?$CFs?$AA@ DB 'SetColorKey:TextBox:%'
	DB	's', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@FMGP@FloodFill?3TextBox?3?$CFs?$AA@
CONST	SEGMENT
??_C@_0BF@FMGP@FloodFill?3TextBox?3?$CFs?$AA@ DB 'FloodFill:TextBox:%s', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@GENF@DrawLayers?3Blt?$AA@
CONST	SEGMENT
??_C@_0P@GENF@DrawLayers?3Blt?$AA@ DB 'DrawLayers:Blt', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@NLFM@Create?3TextBox?3temp?$AA@
CONST	SEGMENT
??_C@_0BE@NLFM@Create?3TextBox?3temp?$AA@ DB 'Create:TextBox:temp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BJ@DFCB@SetColorKey?3TextBox?3temp?$AA@
CONST	SEGMENT
??_C@_0BJ@DFCB@SetColorKey?3TextBox?3temp?$AA@ DB 'SetColorKey:TextBox:te'
	DB	'mp', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BH@MNFO@FloodFill?3TextBox?3temp?$AA@
CONST	SEGMENT
??_C@_0BH@MNFO@FloodFill?3TextBox?3temp?$AA@ DB 'FloodFill:TextBox:temp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BJ@IJCF@Blt?3TextBox?3char?5to?5temp?$AA@
CONST	SEGMENT
??_C@_0BJ@IJCF@Blt?3TextBox?3char?5to?5temp?$AA@ DB 'Blt:TextBox:char to '
	DB	'temp', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BK@LHFH@Blt?3TextBox?3temp?5to?5layer?$AA@
CONST	SEGMENT
??_C@_0BK@LHFH@Blt?3TextBox?3temp?5to?5layer?$AA@ DB 'Blt:TextBox:temp to'
	DB	' layer', 00H				; `string'
CONST	ENDS
;	COMDAT ?CreateTextBox@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z
_TEXT	SEGMENT
$T59145 = -936
_l_info$ = 8
_this$ = -4
_i$ = -8
_ddsd$ = -132
_f$ = -136
_S1$ = -140
_S2$ = -144
_pos$ = -148
_row$ = -152
_last$ = -156
_chardone$ = -160
_TempGfx$ = -164
_S$58254 = -420
_S$58264 = -676
_S$58268 = -932
?CreateTextBox@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z PROC NEAR ; DISPLAY::CreateTextBox, COMDAT

; 283  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 1000				; 000003e8H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 284  : 	l = new LAYER;

	push	164					; 000000a4H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59145[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T59145[ebp]
	mov	DWORD PTR [eax+360], ecx

; 285  : 	ZeroMemory(l, sizeof(LAYER));

	push	164					; 000000a4H
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 286  : 
; 287  : 	l->type = LT_TEXT;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	BYTE PTR [edx+4], 5

; 288  : 	l->Name = l_info->Name;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax

; 289  : 	l->visable = l_info->visable;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+5]
	mov	BYTE PTR [edx+9], cl

; 290  : 	l->moveable = l_info->moveable;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+6]
	mov	BYTE PTR [eax+24], dl

; 291  : 	l->clip = l_info->clip;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+24]
	mov	BYTE PTR [ecx+52], al

; 292  : 	l->move_type = l_info->move_type;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+7]
	mov	BYTE PTR [edx+26], cl

; 293  : 	l->o_move_count = l->move_count = l_info->move_count;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+8]
	mov	BYTE PTR [eax+27], dl
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	cl, BYTE PTR [ecx+27]
	mov	BYTE PTR [eax+28], cl

; 294  : 	l->collidable = l_info->collidable;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+9]
	mov	BYTE PTR [eax+44], dl

; 295  : 	l->extra1 = l_info->extra1;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+44]
	mov	BYTE PTR [ecx+5], al

; 296  : 	l->extra2 = l_info->extra2;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+45]
	mov	BYTE PTR [edx+6], cl

; 297  : 	l->extra3 = l_info->extra3;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+46]
	mov	BYTE PTR [eax+7], dl

; 298  : 	l->SetSize(l_info->w, l_info->h);

	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+12]
	push	ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+10]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+360]
	call	?SetSize@LAYER@@QAEXJJ@Z		; LAYER::SetSize

; 299  : 
; 300  : 	l->SetClipRect(l_info->cx, l_info->cy, l_info->cw, l_info->ch);

	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+38]
	push	eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+36]
	push	edx
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	push	ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+28]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+360]
	call	?SetClipRect@LAYER@@QAEXJJJJ@Z		; LAYER::SetClipRect

; 301  : 	l->SetPos(l_info->x, l_info->y);

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+20]
	push	eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	call	?SetPos@LAYER@@QAEXJJ@Z			; LAYER::SetPos

; 302  : 	l->SetHotSpot(l_info->hx, l_info->hy);

	mov	ecx, DWORD PTR _l_info$[ebp]
	movsx	edx, WORD PTR [ecx+42]
	push	edx
	mov	eax, DWORD PTR _l_info$[ebp]
	movsx	ecx, WORD PTR [eax+40]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+360]
	call	?SetHotSpot@LAYER@@QAEXJJ@Z		; LAYER::SetHotSpot

; 303  : 	l->old_r = l->r;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 80					; 00000050H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	add	eax, 112				; 00000070H
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR [eax+4], edx
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [eax+8], edx
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [eax+12], ecx

; 304  : 	l->old_ir = l->ir;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	add	eax, 96					; 00000060H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	add	edx, 128				; 00000080H
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR [edx+4], ecx
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [edx+8], ecx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [edx+12], eax

; 305  : 
; 306  : 	l->redraw = true;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	BYTE PTR [edx+8], 1

; 307  : 
; 308  : 	l->text = l_info->text;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	DWORD PTR [ecx+148], eax

; 309  : 
; 310  : 	unsigned __int8 i;
; 311  : 	DD_SDESC	ddsd;
; 312  : 	FONT *f = &Font[l->FontNum];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	xor	eax, eax
	mov	al, BYTE PTR [edx+7]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+188]
	lea	eax, DWORD PTR [edx+eax*8]
	mov	DWORD PTR _f$[ebp], eax

; 313  : 	char *S1, *S2;
; 314  : 	unsigned __int16 pos = 0, row = 0, last = 0, chardone = 0;

	mov	WORD PTR _pos$[ebp], 0
	mov	WORD PTR _row$[ebp], 0
	mov	WORD PTR _last$[ebp], 0
	mov	WORD PTR _chardone$[ebp], 0

; 315  : 	GFXDATA TempGfx;
; 316  : 	
; 317  : 	r2.top = 0;	r2.bottom = f->ch;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+276], 0
	mov	edx, DWORD PTR _f$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+284], eax

; 318  : 
; 319  : 	ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	edx, DWORD PTR _ddsd$[ebp]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 320  : 	ddsd.dwSize		= sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 321  : 	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 322  : 	ddsd.dwWidth	= l->ir.right;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx+104]
	mov	DWORD PTR _ddsd$[ebp+12], edx

; 323  : 	ddsd.dwHeight	= l->ir.bottom;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx+108]
	mov	DWORD PTR _ddsd$[ebp+8], edx

; 324  : 	//
; 325  : 	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

	mov	DWORD PTR _ddsd$[ebp+104], 2112		; 00000840H

; 326  : 	if( (e = DD_Object->CreateSurface(&ddsd, &l->gfx, NULL)) != DD_OK )

	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 144				; 00000090H
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
	je	SHORT $L58253

; 328  : 		char S[256];
; 329  : 		sprintf(S, "Create:TextBox:%s", l->Name);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:??_C@_0BC@MCEO@Create?3TextBox?3?$CFs?$AA@ ; `string'
	lea	eax, DWORD PTR _S$58254[ebp]
	push	eax
	call	_sprintf
	add	esp, 12					; 0000000cH

; 330  : 		DDE("LoadDrawS:CreateSurface", e, S);

	lea	ecx, DWORD PTR _S$58254[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 331  : 		return NULL;

	xor	eax, eax
	jmp	$L58238
$L58253:

; 333  : 	if( (e = DDSetColorKey(l->gfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx+144]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58263

; 335  : 		char S[256];
; 336  : 		sprintf(S, "SetColorKey:TextBox:%s", l->Name);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:??_C@_0BH@GIHL@SetColorKey?3TextBox?3?$CFs?$AA@ ; `string'
	lea	eax, DWORD PTR _S$58264[ebp]
	push	eax
	call	_sprintf
	add	esp, 12					; 0000000cH

; 337  : 		DDE("LoadDrawS:DDSetColorKey", e, S );

	lea	ecx, DWORD PTR _S$58264[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 338  : 		return NULL;

	xor	eax, eax
	jmp	$L58238
$L58263:

; 340  : 	if(	(e = l->gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 56					; 00000038H
	push	ecx
	push	1024					; 00000400H
	push	0
	push	0
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR [eax+144]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	edx, DWORD PTR [eax+144]
	mov	eax, DWORD PTR [edx]
	push	ecx
	call	DWORD PTR [eax+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58267

; 342  : 		char S[256];
; 343  : 		sprintf(S, "FloodFill:TextBox:%s", l->Name);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:??_C@_0BF@FMGP@FloodFill?3TextBox?3?$CFs?$AA@ ; `string'
	lea	eax, DWORD PTR _S$58268[ebp]
	push	eax
	call	_sprintf
	add	esp, 12					; 0000000cH

; 344  : 		DDE("DrawLayers:Blt", e, S);

	lea	ecx, DWORD PTR _S$58268[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 345  : 		return NULL;

	xor	eax, eax
	jmp	$L58238
$L58267:

; 347  : 
; 348  : 	ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	ecx, DWORD PTR _ddsd$[ebp]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 349  : 	ddsd.dwSize		= sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 350  : 	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 351  : 	ddsd.dwWidth	= l->ir.right;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR [eax+104]
	mov	DWORD PTR _ddsd$[ebp+12], ecx

; 352  : 	ddsd.dwHeight	= l->ir.bottom;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR [eax+108]
	mov	DWORD PTR _ddsd$[ebp+8], ecx

; 353  : 	//
; 354  : 	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

	mov	DWORD PTR _ddsd$[ebp+104], 2112		; 00000840H

; 355  : 	if( (e = DD_Object->CreateSurface(&ddsd, &TempGfx, NULL)) != DD_OK )

	push	0
	lea	edx, DWORD PTR _TempGfx$[ebp]
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
	je	SHORT $L58272

; 357  : 		DDE("LoadDrawS:CreateSurface", e, "Create:TextBox:temp");

	push	OFFSET FLAT:??_C@_0BE@NLFM@Create?3TextBox?3temp?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 358  : 		return NULL;

	xor	eax, eax
	jmp	$L58238
$L58272:

; 360  : 	if( (e = DDSetColorKey(TempGfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _TempGfx$[ebp]
	push	edx
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58281

; 362  : 		DDE("LoadDrawS:DDSetColorKey", e, "SetColorKey:TextBox:temp");

	push	OFFSET FLAT:??_C@_0BJ@DFCB@SetColorKey?3TextBox?3temp?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 363  : 		return NULL;

	xor	eax, eax
	jmp	$L58238
$L58281:

; 365  : 
; 366  : 	S1 = l->text;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR [eax+148]
	mov	DWORD PTR _S1$[ebp], ecx

; 367  : 	for(i = 0; S1 != NULL; i++)

	mov	BYTE PTR _i$[ebp], 0
	jmp	SHORT $L58283
$L58284:
	mov	dl, BYTE PTR _i$[ebp]
	add	dl, 1
	mov	BYTE PTR _i$[ebp], dl
$L58283:
	cmp	DWORD PTR _S1$[ebp], 0
	je	$L58285

; 369  : 		S2 = strchr(S1, ' ');

	push	32					; 00000020H
	mov	eax, DWORD PTR _S1$[ebp]
	push	eax
	call	_strchr
	add	esp, 8
	mov	DWORD PTR _S2$[ebp], eax

; 370  : 
; 371  : 		if(S2 != NULL)

	cmp	DWORD PTR _S2$[ebp], 0
	je	SHORT $L58286

; 372  : 			pos += S2 - S1 + 1;

	mov	ecx, DWORD PTR _S2$[ebp]
	sub	ecx, DWORD PTR _S1$[ebp]
	add	ecx, 1
	mov	dx, WORD PTR _pos$[ebp]
	add	dx, cx
	mov	WORD PTR _pos$[ebp], dx
$L58286:

; 373  : 
; 374  : 		if( ((pos*f->cw) > l->ir.right) || (S2 == NULL) )

	mov	eax, DWORD PTR _pos$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _f$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	imul	eax, edx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	cmp	eax, DWORD PTR [edx+104]
	jg	SHORT $L58288
	cmp	DWORD PTR _S2$[ebp], 0
	jne	$L58287
$L58288:

; 376  : 			if(S2 != NULL)

	cmp	DWORD PTR _S2$[ebp], 0
	je	SHORT $L58289

; 377  : 				last += pos - (S2 - S1 + 1);

	mov	eax, DWORD PTR _pos$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _S2$[ebp]
	sub	ecx, DWORD PTR _S1$[ebp]
	add	ecx, 1
	sub	eax, ecx
	mov	dx, WORD PTR _last$[ebp]
	add	dx, ax
	mov	WORD PTR _last$[ebp], dx

; 378  : 			else

	jmp	SHORT $L58290
$L58289:

; 379  : 				last += pos + strlen(S1);

	mov	esi, DWORD PTR _pos$[ebp]
	and	esi, 65535				; 0000ffffH
	mov	eax, DWORD PTR _S1$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	add	esi, eax
	mov	cx, WORD PTR _last$[ebp]
	add	cx, si
	mov	WORD PTR _last$[ebp], cx
$L58290:

; 380  : 
; 381  : 			if(	(e = TempGfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 56					; 00000038H
	push	edx
	push	1024					; 00000400H
	push	0
	push	0
	push	0
	mov	eax, DWORD PTR _TempGfx$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _TempGfx$[ebp]
	push	edx
	call	DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58292

; 383  : 				DDE("DrawLayers:Blt", e, "FloodFill:TextBox:temp");

	push	OFFSET FLAT:??_C@_0BH@MNFO@FloodFill?3TextBox?3temp?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 384  : 				return NULL;

	xor	eax, eax
	jmp	$L58238
$L58292:

; 386  : 
; 387  : 			r1.top = 0;		r1.bottom = f->ch;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+260], 0
	mov	eax, DWORD PTR _f$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+268], ecx

; 388  : 			for(j = 0; (j + chardone) < last; j++)

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+233], 0
	jmp	SHORT $L58294
$L58295:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+233]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+233], dl
$L58294:
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+233]
	mov	eax, DWORD PTR _chardone$[ebp]
	and	eax, 65535				; 0000ffffH
	add	edx, eax
	mov	ecx, DWORD PTR _last$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	edx, ecx
	jge	$L58296

; 390  : 				r1.left = j*(f->cw);

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+233]
	mov	ecx, DWORD PTR _f$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	imul	eax, edx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+256], eax

; 391  : 				r1.right = r1.left + f->cw;		

	mov	edx, DWORD PTR _f$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+256]
	add	edx, eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+264], edx

; 392  : 
; 393  : 				r2.left = (l->text[j + chardone] - 32 )*(f->cw);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	eax, DWORD PTR _chardone$[ebp]
	and	eax, 65535				; 0000ffffH
	add	ecx, eax
	mov	edx, DWORD PTR [edx+148]
	movsx	eax, BYTE PTR [edx+ecx]
	sub	eax, 32					; 00000020H
	mov	ecx, DWORD PTR _f$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	imul	eax, edx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+272], eax

; 394  : 				r2.right = r2.left + f->cw;

	mov	edx, DWORD PTR _f$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+272]
	add	edx, eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+280], edx

; 395  : 				
; 396  : 				if(	(e = TempGfx->Blt(&r1, f->gfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 272				; 00000110H
	push	ecx
	mov	edx, DWORD PTR _f$[ebp]
	mov	eax, DWORD PTR [edx+4]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 256				; 00000100H
	push	ecx
	mov	edx, DWORD PTR _TempGfx$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	push	ecx
	call	DWORD PTR [eax+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L58298

; 398  : 					DDE("DrawLayers:Blt", e, "Blt:TextBox:char to temp");

	push	OFFSET FLAT:??_C@_0BJ@IJCF@Blt?3TextBox?3char?5to?5temp?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 399  : 					return NULL;

	xor	eax, eax
	jmp	$L58238
$L58298:

; 401  : 			}

	jmp	$L58295
$L58296:

; 402  : 
; 403  : 			if(l->hAlign == AT_CENTER)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+5]
	test	edx, edx
	jne	SHORT $L58300

; 405  : 				r1.left = ( l->ir.right - j*(f->cw) ) >> 1;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+233]
	mov	edx, DWORD PTR _f$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx]
	imul	eax, ebx
	mov	ecx, DWORD PTR [ecx+104]
	sub	ecx, eax
	sar	ecx, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+256], ecx

; 406  : 				r1.right = r1.left + j*(f->cw);

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	edx, DWORD PTR _f$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	imul	ecx, eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+256]
	add	eax, ecx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+264], eax

; 408  : 			else if(l->hAlign == AT_LEFT)

	jmp	$L58303
$L58300:
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+5]
	cmp	ecx, 1
	jne	SHORT $L58302

; 410  : 				r1.left = 0;	r1.right = j*(f->cw);

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+256], 0
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	edx, DWORD PTR _f$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	imul	ecx, eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+264], ecx

; 412  : 			else

	jmp	SHORT $L58303
$L58302:

; 414  : 				r1.left = l->ir.right - j*(f->cw);

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+233]
	mov	edx, DWORD PTR _f$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx]
	imul	eax, ebx
	mov	ecx, DWORD PTR [ecx+104]
	sub	ecx, eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+256], ecx

; 415  : 				r1.right = l->ir.right;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+104]
	mov	DWORD PTR [edx+264], eax
$L58303:

; 417  : 
; 418  : 			r1.top = row*(f->ch);

	mov	ecx, DWORD PTR _row$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _f$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	imul	ecx, eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+260], ecx

; 419  : 			r1.bottom = r1.top + f->ch;

	mov	eax, DWORD PTR _f$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+260]
	add	eax, ecx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+268], eax

; 420  : 
; 421  : 			r2.left = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+272], 0

; 422  : 			r2.right = j*(f->cw);

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	edx, DWORD PTR _f$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	imul	ecx, eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+280], ecx

; 423  : 			
; 424  : 			if(	(e = l->gfx->Blt(&r1, TempGfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 272				; 00000110H
	push	eax
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 256				; 00000100H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx+144]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	eax, DWORD PTR [ecx+144]
	mov	ecx, DWORD PTR [eax]
	push	edx
	call	DWORD PTR [ecx+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L58305

; 426  : 				DDE("DrawLayers:Blt", e, "Blt:TextBox:temp to layer");

	push	OFFSET FLAT:??_C@_0BK@LHFH@Blt?3TextBox?3temp?5to?5layer?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 427  : 				return NULL;

	xor	eax, eax
	jmp	$L58238
$L58305:

; 429  : 
; 430  : 			chardone += j;

	mov	eax, DWORD PTR _this$[ebp]
	movzx	cx, BYTE PTR [eax+233]
	mov	dx, WORD PTR _chardone$[ebp]
	add	dx, cx
	mov	WORD PTR _chardone$[ebp], dx

; 431  : 			pos = 0;

	mov	WORD PTR _pos$[ebp], 0

; 432  : 			row++;

	mov	ax, WORD PTR _row$[ebp]
	add	ax, 1
	mov	WORD PTR _row$[ebp], ax

; 433  : 			if(S2 == NULL)

	cmp	DWORD PTR _S2$[ebp], 0
	jne	SHORT $L58307

; 434  : 				S1 = NULL;

	mov	DWORD PTR _S1$[ebp], 0
$L58307:

; 437  : 		else

	jmp	SHORT $L58308
$L58287:

; 438  : 			S1 = S2 + 1;

	mov	ecx, DWORD PTR _S2$[ebp]
	add	ecx, 1
	mov	DWORD PTR _S1$[ebp], ecx
$L58308:

; 439  : 	}

	jmp	$L58284
$L58285:

; 440  : 	
; 441  : 	TempGfx->Release();

	mov	edx, DWORD PTR _TempGfx$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	push	ecx
	call	DWORD PTR [eax+8]

; 442  : 
; 443  : 	AppendLayer(l);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?AppendLayer@DISPLAY@@QAEXPAVLAYER@@@Z	; DISPLAY::AppendLayer

; 444  : 	nLayers++;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+372]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+372], dl

; 445  : 	return l;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+360]
$L58238:

; 446  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?CreateTextBox@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ENDP ; DISPLAY::CreateTextBox
_TEXT	ENDS
;	COMDAT ?SetClipRect@LAYER@@QAEXJJJJ@Z
_TEXT	SEGMENT
_x$ = 8
_y$ = 12
_w$ = 16
_h$ = 20
_this$ = -4
?SetClipRect@LAYER@@QAEXJJJJ@Z PROC NEAR		; LAYER::SetClipRect, COMDAT

; 633  : 	void SetClipRect(long x, long y, long w, long h)	{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 634  : 		cr.left = x;	cr.right = cr.left + w;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	mov	DWORD PTR [eax+56], ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+56]
	add	eax, DWORD PTR _w$[ebp]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+64], eax

; 635  : 		cr.top = y;		cr.bottom = cr.top + h;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	mov	DWORD PTR [edx+60], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	add	edx, DWORD PTR _h$[ebp]
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+68], edx

; 636  : 	};

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	16					; 00000010H
?SetClipRect@LAYER@@QAEXJJJJ@Z ENDP			; LAYER::SetClipRect
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
;	COMDAT ?SetPos@LAYER@@QAEXJJ@Z
_TEXT	SEGMENT
_x$ = 8
_y$ = 12
_this$ = -4
?SetPos@LAYER@@QAEXJJ@Z PROC NEAR			; LAYER::SetPos, COMDAT

; 660  : 	{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 661  : 		r.left = x - hx;								r.top = y - hy;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	sub	ecx, DWORD PTR [eax+72]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+80], ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _y$[ebp]
	sub	ecx, DWORD PTR [eax+76]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+84], ecx

; 662  : 		r.right = r.left + ir.right;		r.bottom = r.top + ir.bottom;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+80]
	mov	edx, DWORD PTR _this$[ebp]
	add	ecx, DWORD PTR [edx+104]
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+88], ecx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+84]
	mov	eax, DWORD PTR _this$[ebp]
	add	edx, DWORD PTR [eax+108]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+92], edx

; 663  : 		redraw = true;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+8], 1

; 664  :   };

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?SetPos@LAYER@@QAEXJJ@Z ENDP				; LAYER::SetPos
_TEXT	ENDS
PUBLIC	?CreateSprite@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateSprite
PUBLIC	??_C@_0P@LOFJ@Load?3Sprite?3?$CFs?$AA@		; `string'
PUBLIC	??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@	; `string'
PUBLIC	??_C@_0BG@OADL@SetColorKey?3Sprite?3?$CFs?$AA@	; `string'
EXTRN	_DDLoadBitmap:NEAR
;	COMDAT ??_C@_0P@LOFJ@Load?3Sprite?3?$CFs?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\layerutil.cpp
CONST	SEGMENT
??_C@_0P@LOFJ@Load?3Sprite?3?$CFs?$AA@ DB 'Load:Sprite:%s', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@
CONST	SEGMENT
??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ DB 'LoadDrawS:DDLoadBitmap', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BG@OADL@SetColorKey?3Sprite?3?$CFs?$AA@
CONST	SEGMENT
??_C@_0BG@OADL@SetColorKey?3Sprite?3?$CFs?$AA@ DB 'SetColorKey:Sprite:%s', 00H ; `string'
CONST	ENDS
;	COMDAT ?CreateSprite@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z
_TEXT	SEGMENT
$T59156 = -532
$T59157 = -536
$T59158 = -540
_l_info$ = 8
_this$ = -4
_ai$58320 = -8
_ci$58321 = -12
_k$58322 = -16
_S$58338 = -272
_S$58349 = -528
?CreateSprite@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z PROC NEAR ; DISPLAY::CreateSprite, COMDAT

; 449  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 604				; 0000025cH
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 450  : 	l = new LAYER;

	push	164					; 000000a4H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59156[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T59156[ebp]
	mov	DWORD PTR [eax+360], ecx

; 451  : 	ZeroMemory(l, sizeof(LAYER));

	push	164					; 000000a4H
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 452  : 
; 453  : 	l->type = LT_SPRITE;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	BYTE PTR [edx+4], 2

; 454  : 	l->Name = l_info->Name;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax

; 455  : 	l->visable = l_info->visable;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+5]
	mov	BYTE PTR [edx+9], cl

; 456  : 	l->moveable = l_info->moveable;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+6]
	mov	BYTE PTR [eax+24], dl

; 457  : 	l->clip = l_info->clip;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+24]
	mov	BYTE PTR [ecx+52], al

; 458  : 	l->move_type = l_info->move_type;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+7]
	mov	BYTE PTR [edx+26], cl

; 459  : 	l->o_move_count = l->move_count = l_info->move_count;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+8]
	mov	BYTE PTR [eax+27], dl
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	cl, BYTE PTR [ecx+27]
	mov	BYTE PTR [eax+28], cl

; 460  : 	l->extra1 = l_info->extra1;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+44]
	mov	BYTE PTR [eax+5], dl

; 461  : 	l->extra2 = l_info->extra2;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+45]
	mov	BYTE PTR [ecx+6], al

; 462  : 	l->extra3 = l_info->extra3;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+46]
	mov	BYTE PTR [edx+7], cl

; 463  : 	l->collidable = l_info->collidable;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+9]
	mov	BYTE PTR [eax+44], dl

; 464  : 
; 465  : 	l->SetSize(l_info->w, l_info->h);

	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+12]
	push	ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+10]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+360]
	call	?SetSize@LAYER@@QAEXJJ@Z		; LAYER::SetSize

; 466  : 	l->SetClipRect(l_info->cx, l_info->cy, l_info->cw, l_info->ch);

	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+38]
	push	eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+36]
	push	edx
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	push	ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+28]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+360]
	call	?SetClipRect@LAYER@@QAEXJJJJ@Z		; LAYER::SetClipRect

; 467  : 	l->SetPos(l_info->x, l_info->y);

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+20]
	push	eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	call	?SetPos@LAYER@@QAEXJJ@Z			; LAYER::SetPos

; 468  : 	l->SetHotSpot(l_info->hx, l_info->hy);

	mov	ecx, DWORD PTR _l_info$[ebp]
	movsx	edx, WORD PTR [ecx+42]
	push	edx
	mov	eax, DWORD PTR _l_info$[ebp]
	movsx	ecx, WORD PTR [eax+40]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+360]
	call	?SetHotSpot@LAYER@@QAEXJJ@Z		; LAYER::SetHotSpot

; 469  : 	l->old_r = l->r;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 80					; 00000050H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	add	eax, 112				; 00000070H
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR [eax+4], edx
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [eax+8], edx
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [eax+12], ecx

; 470  : 	l->old_ir = l->ir;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	add	eax, 96					; 00000060H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	add	edx, 128				; 00000080H
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR [edx+4], ecx
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [edx+8], ecx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [edx+12], eax

; 471  : 
; 472  : 	l->redraw = true;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	BYTE PTR [edx+8], 1

; 473  : 
; 474  : 	if(l_info->NumAnim)

	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+45]
	test	ecx, ecx
	je	$L58325

; 476  : 		a = l->startanim = l->anim= new ANIM[ l_info->NumAnim ];

	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+45]
	imul	eax, 24					; 00000018H
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59157[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR $T59157[ebp]
	mov	DWORD PTR [edx+148], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR $T59157[ebp]
	mov	DWORD PTR [edx+152], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T59157[ebp]
	mov	DWORD PTR [ecx+364], edx

; 477  : 		ZeroMemory(l->anim, l_info->NumAnim*sizeof(ANIM) );

	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+45]
	imul	ecx, 24					; 00000018H
	push	ecx
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR [eax+148]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 478  : 
; 479  : 		ANIM_INFO *ai;
; 480  : 		CEL_INFO *ci;
; 481  : 		unsigned __int8 k;
; 482  : 		for(k = 0; (k < l_info->NumAnim) || (a != NULL); k++, a = a->next)

	mov	BYTE PTR _k$58322[ebp], 0
	jmp	SHORT $L58323
$L58324:
	mov	dl, BYTE PTR _k$58322[ebp]
	add	dl, 1
	mov	BYTE PTR _k$58322[ebp], dl
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+20]
	mov	DWORD PTR [edx+364], eax
$L58323:
	mov	ecx, DWORD PTR _k$58322[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+45]
	cmp	ecx, eax
	jl	SHORT $L58326
	mov	ecx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [ecx+364], 0
	je	$L58325
$L58326:

; 484  : 			ai = &l_info->anim_info[k];

	mov	edx, DWORD PTR _k$58322[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 12					; 0000000cH
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	add	ecx, edx
	mov	DWORD PTR _ai$58320[ebp], ecx

; 485  : 			a->loop_type = ai->loop_type;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+364]
	mov	ecx, DWORD PTR _ai$58320[ebp]
	mov	dl, BYTE PTR [ecx+4]
	mov	BYTE PTR [eax+5], dl

; 486  : 			a->loop_count = a->o_loop_count = ai->loop_count;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR _ai$58320[ebp]
	mov	al, BYTE PTR [edx+5]
	mov	BYTE PTR [ecx+7], al
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	dl, BYTE PTR [edx+7]
	mov	BYTE PTR [ecx+6], dl

; 487  : 			a->name = ai->name;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR _ai$58320[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax

; 488  : 
; 489  : 			if(k < (l_info->NumAnim - 1) )

	mov	ecx, DWORD PTR _k$58322[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+45]
	sub	eax, 1
	cmp	ecx, eax
	jge	SHORT $L58327

; 490  : 				a->next = &l->anim[k + 1];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _k$58322[ebp]
	and	eax, 255				; 000000ffH
	add	eax, 1
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR [edx+148]
	add	ecx, eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+364]
	mov	DWORD PTR [eax+20], ecx

; 491  : 			else

	jmp	SHORT $L58328
$L58327:

; 492  : 				a->next = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	mov	DWORD PTR [edx+20], 0
$L58328:

; 493  : 
; 494  : 			a->nCel = ai->nCel;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR _ai$58320[ebp]
	mov	al, BYTE PTR [edx+6]
	mov	BYTE PTR [ecx+8], al

; 495  : 			c = a->startcel = a->cel= new CEL[ ai->nCel ];

	mov	ecx, DWORD PTR _ai$58320[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+6]
	imul	edx, 24					; 00000018H
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59158[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR $T59158[ebp]
	mov	DWORD PTR [ecx+16], edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR $T59158[ebp]
	mov	DWORD PTR [ecx+12], edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T59158[ebp]
	mov	DWORD PTR [eax+368], ecx

; 496  : 			ZeroMemory(a->cel, ai->nCel*sizeof(CEL) );

	mov	edx, DWORD PTR _ai$58320[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	imul	eax, 24					; 00000018H
	push	eax
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 497  : 			
; 498  : 			for(j = 0; j < ai->nCel; j++, c = c->next)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+233], 0
	jmp	SHORT $L58332
$L58333:
	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR [edx+233]
	add	al, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+233], al
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [eax+20]
	mov	DWORD PTR [ecx+368], edx
$L58332:
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	edx, DWORD PTR _ai$58320[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	cmp	ecx, eax
	jge	$L58334

; 500  : 				ci = &ai->cel_info[j];

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+233]
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$58320[ebp]
	mov	ecx, DWORD PTR [eax+8]
	add	ecx, edx
	mov	DWORD PTR _ci$58321[ebp], ecx

; 501  : 				c->delay = ci->delay;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	ecx, DWORD PTR _ci$58321[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx

; 502  : 				c->hx = ci->hx;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	mov	edx, DWORD PTR _ci$58321[ebp]
	mov	ax, WORD PTR [edx+4]
	mov	WORD PTR [ecx+8], ax

; 503  : 				c->hy = ci->hy;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	mov	eax, DWORD PTR _ci$58321[ebp]
	mov	cx, WORD PTR [eax+6]
	mov	WORD PTR [edx+10], cx

; 504  : 				c->bx = ci->bx;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	ecx, DWORD PTR _ci$58321[ebp]
	mov	dx, WORD PTR [ecx+8]
	mov	WORD PTR [eax+12], dx

; 505  : 				c->by = ci->by;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	mov	edx, DWORD PTR _ci$58321[ebp]
	mov	ax, WORD PTR [edx+10]
	mov	WORD PTR [ecx+14], ax

; 506  : 				c->w = ci->w;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	mov	eax, DWORD PTR _ci$58321[ebp]
	mov	cx, WORD PTR [eax+12]
	mov	WORD PTR [edx+4], cx

; 507  : 				c->h = ci->h;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	ecx, DWORD PTR _ci$58321[ebp]
	mov	dx, WORD PTR [ecx+14]
	mov	WORD PTR [eax+6], dx

; 508  : 
; 509  : 				if(j < (ai->nCel - 1) )

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	edx, DWORD PTR _ai$58320[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	sub	eax, 1
	cmp	ecx, eax
	jge	SHORT $L58335

; 510  : 					c->next = &a->cel[j + 1];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	add	ecx, 1
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR [edx+16]
	add	edx, ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	mov	DWORD PTR [ecx+20], edx

; 511  : 				else

	jmp	SHORT $L58336
$L58335:

; 512  : 					c->next = NULL;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	DWORD PTR [eax+20], 0
$L58336:

; 513  : 
; 514  : 				/*
; 515  : 				if( (l->gfx = GfxToDD(DD_Object, "gfx\\01.gfx")) == NULL )
; 516  : 					return DDE("LoadDrawS:DDLoadBitmap", i);
; 517  : 				*/
; 518  : 				if( (c->gfx = DDLoadBitmap(DD_Object, ci->fName, 0, 0)) == NULL )

	push	0
	push	0
	mov	ecx, DWORD PTR _ci$58321[ebp]
	mov	edx, DWORD PTR [ecx+20]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	push	ecx
	call	_DDLoadBitmap
	add	esp, 16					; 00000010H
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+368]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	cmp	DWORD PTR [eax+16], 0
	jne	SHORT $L58337

; 520  : 					char S[256];
; 521  : 					sprintf(S, "Load:Sprite:%s", ci->fName);

	mov	ecx, DWORD PTR _ci$58321[ebp]
	mov	edx, DWORD PTR [ecx+20]
	push	edx
	push	OFFSET FLAT:??_C@_0P@LOFJ@Load?3Sprite?3?$CFs?$AA@ ; `string'
	lea	eax, DWORD PTR _S$58338[ebp]
	push	eax
	call	_sprintf
	add	esp, 12					; 0000000cH

; 522  : 					DDE("LoadDrawS:DDLoadBitmap", i, S);

	lea	ecx, DWORD PTR _S$58338[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	push	eax
	push	OFFSET FLAT:??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 523  : 					return NULL;

	xor	eax, eax
	jmp	$L58312
$L58337:

; 525  : 				if( (e = DDSetColorKey(c->gfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58348

; 527  : 					char S[256];
; 528  : 					sprintf(S, "SetColorKey:Sprite:%s", ci->fName);

	mov	eax, DWORD PTR _ci$58321[ebp]
	mov	ecx, DWORD PTR [eax+20]
	push	ecx
	push	OFFSET FLAT:??_C@_0BG@OADL@SetColorKey?3Sprite?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58349[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 529  : 					DDE("LoadDrawS:DDSetColorKey", e, S);

	lea	eax, DWORD PTR _S$58349[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 530  : 					return NULL;

	xor	eax, eax
	jmp	SHORT $L58312
$L58348:

; 532  : 				if( (k == 0) && (j == 0) )

	mov	eax, DWORD PTR _k$58322[ebp]
	and	eax, 255				; 000000ffH
	test	eax, eax
	jne	SHORT $L58351
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+233]
	test	edx, edx
	jne	SHORT $L58351

; 533  : 					l->gfx = c->gfx;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR [ecx+16]
	mov	DWORD PTR [eax+144], ecx
$L58351:

; 534  : 
; 535  : 			}

	jmp	$L58333
$L58334:

; 536  : 		}

	jmp	$L58324
$L58325:

; 538  : 
; 539  : 	AppendLayer(l);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?AppendLayer@DISPLAY@@QAEXPAVLAYER@@@Z	; DISPLAY::AppendLayer

; 540  : 	nLayers++;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+372]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+372], dl

; 541  : 	return l;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+360]
$L58312:

; 542  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?CreateSprite@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ENDP ; DISPLAY::CreateSprite
_TEXT	ENDS
PUBLIC	??_C@_0BF@BKPH@SetColorKey?3Image?3?$CFs?$AA@	; `string'
PUBLIC	?CreateImage@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateImage
PUBLIC	??_C@_0O@HIDH@Load?3Image?3?$CFs?$AA@		; `string'
;	COMDAT ??_C@_0O@HIDH@Load?3Image?3?$CFs?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\layerutil.cpp
CONST	SEGMENT
??_C@_0O@HIDH@Load?3Image?3?$CFs?$AA@ DB 'Load:Image:%s', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@BKPH@SetColorKey?3Image?3?$CFs?$AA@
CONST	SEGMENT
??_C@_0BF@BKPH@SetColorKey?3Image?3?$CFs?$AA@ DB 'SetColorKey:Image:%s', 00H ; `string'
CONST	ENDS
;	COMDAT ?CreateImage@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z
_TEXT	SEGMENT
_S$58370 = -516
$T59161 = -520
_l_info$ = 8
_this$ = -4
_S$58360 = -260
?CreateImage@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z PROC NEAR ; DISPLAY::CreateImage, COMDAT

; 545  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 584				; 00000248H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 546  : 	l = new LAYER;

	push	164					; 000000a4H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59161[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T59161[ebp]
	mov	DWORD PTR [eax+360], ecx

; 547  : 	ZeroMemory(l, sizeof(LAYER));

	push	164					; 000000a4H
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 548  : 
; 549  : 	l->type = LT_IMAGE;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	BYTE PTR [edx+4], 1

; 550  : 	l->Name = l_info->Name;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax

; 551  : 	l->visable = l_info->visable;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+5]
	mov	BYTE PTR [edx+9], cl

; 552  : 	l->moveable = l_info->moveable;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+6]
	mov	BYTE PTR [eax+24], dl

; 553  : 	l->clip = l_info->clip;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+24]
	mov	BYTE PTR [ecx+52], al

; 554  : 	l->move_type = l_info->move_type;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+7]
	mov	BYTE PTR [edx+26], cl

; 555  : 	l->o_move_count = l->move_count = l_info->move_count;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+8]
	mov	BYTE PTR [eax+27], dl
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	cl, BYTE PTR [ecx+27]
	mov	BYTE PTR [eax+28], cl

; 556  : 	l->extra1 = l_info->extra1;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+44]
	mov	BYTE PTR [eax+5], dl

; 557  : 	l->extra2 = l_info->extra2;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+45]
	mov	BYTE PTR [ecx+6], al

; 558  : 	l->extra3 = l_info->extra3;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+46]
	mov	BYTE PTR [edx+7], cl

; 559  : 	l->collidable = l_info->collidable;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+9]
	mov	BYTE PTR [eax+44], dl

; 560  : 
; 561  : 	l->SetSize(l_info->w, l_info->h);

	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+12]
	push	ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+10]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+360]
	call	?SetSize@LAYER@@QAEXJJ@Z		; LAYER::SetSize

; 562  : 	l->SetClipRect(l_info->cx, l_info->cy, l_info->cw, l_info->ch);

	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+38]
	push	eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+36]
	push	edx
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	push	ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+28]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+360]
	call	?SetClipRect@LAYER@@QAEXJJJJ@Z		; LAYER::SetClipRect

; 563  : 	l->SetPos(l_info->x, l_info->y);

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+20]
	push	eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	call	?SetPos@LAYER@@QAEXJJ@Z			; LAYER::SetPos

; 564  : 	l->SetHotSpot(l_info->hx, l_info->hy);

	mov	ecx, DWORD PTR _l_info$[ebp]
	movsx	edx, WORD PTR [ecx+42]
	push	edx
	mov	eax, DWORD PTR _l_info$[ebp]
	movsx	ecx, WORD PTR [eax+40]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+360]
	call	?SetHotSpot@LAYER@@QAEXJJ@Z		; LAYER::SetHotSpot

; 565  : 	l->old_r = l->r;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 80					; 00000050H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	add	eax, 112				; 00000070H
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR [eax+4], edx
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [eax+8], edx
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [eax+12], ecx

; 566  : 	l->old_ir = l->ir;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	add	eax, 96					; 00000060H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	add	edx, 128				; 00000080H
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR [edx+4], ecx
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [edx+8], ecx
	mov	eax, DWORD PTR [eax+12]
	mov	DWORD PTR [edx+12], eax

; 567  : 
; 568  : 	l->redraw = true;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	BYTE PTR [edx+8], 1

; 569  : 
; 570  : 	if( (l->gfx = DDLoadBitmap(DD_Object, l_info->fName, 0, 0)) == NULL )

	push	0
	push	0
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+208]
	push	eax
	call	_DDLoadBitmap
	add	esp, 16					; 00000010H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	DWORD PTR [edx+144], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	cmp	DWORD PTR [ecx+144], 0
	jne	SHORT $L58359

; 572  : 		char S[256];
; 573  : 		sprintf(S, "Load:Image:%s", l_info->fName);

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+48]
	push	eax
	push	OFFSET FLAT:??_C@_0O@HIDH@Load?3Image?3?$CFs?$AA@ ; `string'
	lea	ecx, DWORD PTR _S$58360[ebp]
	push	ecx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 574  : 		DDE("LoadDrawS:DDLoadBitmap", i, S);

	lea	edx, DWORD PTR _S$58360[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+232]
	push	ecx
	push	OFFSET FLAT:??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 575  : 		return NULL;

	xor	eax, eax
	jmp	$L58355
$L58359:

; 577  : 	if( (e = DDSetColorKey(l->gfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR [eax+144]
	push	ecx
	call	_DDSetColorKey
	add	esp, 8
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L58369

; 579  : 		char S[256];
; 580  : 		sprintf(S, "SetColorKey:Image:%s", l_info->fName);

	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	push	edx
	push	OFFSET FLAT:??_C@_0BF@BKPH@SetColorKey?3Image?3?$CFs?$AA@ ; `string'
	lea	eax, DWORD PTR _S$58370[ebp]
	push	eax
	call	_sprintf
	add	esp, 12					; 0000000cH

; 581  : 		DDE("LoadDrawS:DDSetColorKey", e, S);

	lea	ecx, DWORD PTR _S$58370[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 582  : 		return NULL;

	xor	eax, eax
	jmp	SHORT $L58355
$L58369:

; 584  : 
; 585  : 	AppendLayer(l);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?AppendLayer@DISPLAY@@QAEXPAVLAYER@@@Z	; DISPLAY::AppendLayer

; 586  : 	nLayers++;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+372]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+372], cl

; 587  : 	return l;

	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+360]
$L58355:

; 588  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?CreateImage@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ENDP ; DISPLAY::CreateImage
_TEXT	ENDS
PUBLIC	??_C@_06GPIJ@Map?3?$CFs?$AA@			; `string'
PUBLIC	??_C@_0BD@POGI@Map?3temp?5to?5gfx?3?$CFs?$AA@	; `string'
PUBLIC	?CreateMap@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateMap
;	COMDAT ??_C@_06GPIJ@Map?3?$CFs?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\layerutil.cpp
CONST	SEGMENT
??_C@_06GPIJ@Map?3?$CFs?$AA@ DB 'Map:%s', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@POGI@Map?3temp?5to?5gfx?3?$CFs?$AA@
CONST	SEGMENT
??_C@_0BD@POGI@Map?3temp?5to?5gfx?3?$CFs?$AA@ DB 'Map:temp to gfx:%s', 00H ; `string'
CONST	ENDS
;	COMDAT ?CreateMap@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z
_TEXT	SEGMENT
_l_info$ = 8
_this$ = -4
_ddsd$ = -128
_k$ = -132
_TempGfx$ = -136
_w$ = -140
_h$ = -144
_iw$ = -148
_ih$ = -152
_data$ = -156
_S$58391 = -412
_S$58401 = -668
_S$58404 = -924
_S$58409 = -1180
_S$58418 = -1436
_S$58424 = -1692
$T59164 = -1696
$T59165 = -1700
?CreateMap@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z PROC NEAR ; DISPLAY::CreateMap, COMDAT

; 591  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 1764				; 000006e4H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 592  : 	l = new LAYER;

	push	164					; 000000a4H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59164[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T59164[ebp]
	mov	DWORD PTR [eax+360], ecx

; 593  : 	ZeroMemory(l, sizeof(LAYER));

	push	164					; 000000a4H
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 594  : 
; 595  : 	l->type = LT_MAP;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	BYTE PTR [edx+4], 4

; 596  : 	l->Name = l_info->Name;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax

; 597  : 	l->visable = l_info->visable;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+5]
	mov	BYTE PTR [edx+9], cl

; 598  : 	l->moveable = l_info->moveable;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+6]
	mov	BYTE PTR [eax+24], dl

; 599  : 	l->clip = l_info->clip;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+24]
	mov	BYTE PTR [ecx+52], al

; 600  : 	l->move_type = l_info->move_type;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+7]
	mov	BYTE PTR [edx+26], cl

; 601  : 	l->o_move_count = l->move_count = l_info->move_count;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+8]
	mov	BYTE PTR [eax+27], dl
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	cl, BYTE PTR [ecx+27]
	mov	BYTE PTR [eax+28], cl

; 602  : 	l->extra1 = l_info->extra1;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+44]
	mov	BYTE PTR [eax+5], dl

; 603  : 	l->extra2 = l_info->extra2;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+45]
	mov	BYTE PTR [ecx+6], al

; 604  : 	l->extra3 = l_info->extra3;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+46]
	mov	BYTE PTR [edx+7], cl

; 605  : 	l->collidable = l_info->collidable;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+9]
	mov	BYTE PTR [eax+44], dl

; 606  : 
; 607  : 	l->redraw = true;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	BYTE PTR [ecx+8], 1

; 608  : 
; 609  : 	DD_SDESC	ddsd;
; 610  : 	unsigned __int8 k = l_info->map_num_images;

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+46]
	mov	BYTE PTR _k$[ebp], al

; 611  : 	GFXDATA *TempGfx = new GFXDATA[k];

	mov	ecx, DWORD PTR _k$[ebp]
	and	ecx, 255				; 000000ffH
	shl	ecx, 2
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59165[ebp], eax
	mov	edx, DWORD PTR $T59165[ebp]
	mov	DWORD PTR _TempGfx$[ebp], edx

; 612  : 	unsigned __int16 w, h, iw, ih;
; 613  : 	unsigned __int8 **data = l_info->map_info->data;

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _data$[ebp], edx

; 614  : 
; 615  : 	// number of images horz
; 616  : 	w = l_info->w;

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cx, WORD PTR [eax+10]
	mov	WORD PTR _w$[ebp], cx

; 617  : 	// number of images vert
; 618  : 	h = l_info->h;

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	ax, WORD PTR [edx+12]
	mov	WORD PTR _h$[ebp], ax

; 619  : 
; 620  : 	// number of images horz
; 621  : 	iw = l_info->map_image_w;

	mov	ecx, DWORD PTR _l_info$[ebp]
	movzx	dx, BYTE PTR [ecx+44]
	mov	WORD PTR _iw$[ebp], dx

; 622  : 	// number of images vert
; 623  : 	ih = l_info->map_image_h;

	mov	eax, DWORD PTR _l_info$[ebp]
	movzx	cx, BYTE PTR [eax+45]
	mov	WORD PTR _ih$[ebp], cx

; 624  : 
; 625  : 	r2.top = r2.left = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+272], 0
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+276], 0

; 626  : 	r2.right = iw;

	mov	ecx, DWORD PTR _iw$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+280], ecx

; 627  : 	r2.bottom = ih;

	mov	eax, DWORD PTR _ih$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+284], eax

; 628  : 
; 629  : 	// create layer gfx to place images into
; 630  : 		ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	edx, DWORD PTR _ddsd$[ebp]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 631  : 		ddsd.dwSize		= sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 632  : 		ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 633  : 		ddsd.dwWidth	= l_info->w = w*iw;

	mov	eax, DWORD PTR _w$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _iw$[ebp]
	and	ecx, 65535				; 0000ffffH
	imul	eax, ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	WORD PTR [edx+10], ax
	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+10]
	mov	DWORD PTR _ddsd$[ebp+12], ecx

; 634  : 		ddsd.dwHeight	= l_info->h = h*ih;

	mov	edx, DWORD PTR _h$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _ih$[ebp]
	and	eax, 65535				; 0000ffffH
	imul	edx, eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	WORD PTR [ecx+12], dx
	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+12]
	mov	DWORD PTR _ddsd$[ebp+8], eax

; 635  : 		//
; 636  : 		ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

	mov	DWORD PTR _ddsd$[ebp+104], 2112		; 00000840H

; 637  : 		if( (e = DD_Object->CreateSurface(&ddsd, &l->gfx, NULL)) != DD_OK )

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	add	edx, 144				; 00000090H
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
	je	SHORT $L58390

; 639  : 			char S[256];
; 640  : 			sprintf(S, "Map:%s", l_info->fName);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	push	OFFSET FLAT:??_C@_06GPIJ@Map?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58391[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 641  : 			DDE("LoadDrawS:CreateSurface", e, S);

	lea	eax, DWORD PTR _S$58391[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 642  : 			return NULL;

	xor	eax, eax
	jmp	$L58375
$L58390:

; 644  : 
; 645  : 		if( (e = DDSetColorKey(l->gfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx+144]
	push	edx
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58400

; 647  : 			char S[256];
; 648  : 			sprintf(S, "Map:%s", l_info->fName);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	push	OFFSET FLAT:??_C@_06GPIJ@Map?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58401[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 649  : 			DDE("LoadDrawS:DDSetColorKey", e, S);

	lea	eax, DWORD PTR _S$58401[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 650  : 			return NULL;

	xor	eax, eax
	jmp	$L58375
$L58400:

; 652  : 
; 653  : 		if(	(e = l->gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 56					; 00000038H
	push	eax
	push	1024					; 00000400H
	push	0
	push	0
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx+144]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	ecx, DWORD PTR [edx+144]
	mov	edx, DWORD PTR [ecx]
	push	eax
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58403

; 655  : 			char S[256];
; 656  : 			sprintf(S, "Map:%s", l_info->fName);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	push	OFFSET FLAT:??_C@_06GPIJ@Map?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58404[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 657  : 			DDE("DrawLayers:FloodFill", e, S);

	lea	eax, DWORD PTR _S$58404[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BF@BJFJ@DrawLayers?3FloodFill?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 658  : 			return NULL;

	xor	eax, eax
	jmp	$L58375
$L58403:

; 660  : 	//
; 661  : 
; 662  : 	for(j = 0; j < k; j++)

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+233], 0
	jmp	SHORT $L58405
$L58406:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+233]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+233], dl
$L58405:
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+233]
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 255				; 000000ffH
	cmp	edx, eax
	jge	$L58407

; 664  : 		if( (TempGfx[j] = DDLoadBitmap(DD_Object, l_info->map_info->fName[j], 0, 0)) == NULL )

	push	0
	push	0
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	edx, DWORD PTR [edx+8]
	mov	eax, DWORD PTR [edx+ecx*4]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+208]
	push	edx
	call	_DDLoadBitmap
	add	esp, 16					; 00000010H
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+233]
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	mov	DWORD PTR [ecx+edx*4], eax
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+233]
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	cmp	DWORD PTR [ecx+eax*4], 0
	jne	SHORT $L58408

; 666  : 			char S[256];
; 667  : 			sprintf(S, "Map:%s", l_info->map_info->fName[j]);

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+233]
	mov	eax, DWORD PTR [eax+8]
	mov	ecx, DWORD PTR [eax+edx*4]
	push	ecx
	push	OFFSET FLAT:??_C@_06GPIJ@Map?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58409[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 668  : 			DDE("LoadDrawS:DDLoadBitmap", i, S);

	lea	eax, DWORD PTR _S$58409[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+232]
	push	edx
	push	OFFSET FLAT:??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 669  : 			return NULL;

	xor	eax, eax
	jmp	$L58375
$L58408:

; 671  : 		if( (e = DDSetColorKey(TempGfx[j],  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	edx, DWORD PTR _TempGfx$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58417

; 673  : 			char S[256];
; 674  : 			sprintf(S, "Map:%s", l_info->map_info->fName[j]);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+233]
	mov	ecx, DWORD PTR [ecx+8]
	mov	edx, DWORD PTR [ecx+eax*4]
	push	edx
	push	OFFSET FLAT:??_C@_06GPIJ@Map?3?$CFs?$AA@ ; `string'
	lea	eax, DWORD PTR _S$58418[ebp]
	push	eax
	call	_sprintf
	add	esp, 12					; 0000000cH

; 675  : 			DDE("LoadDrawS:DDSetColorKey", e, S);

	lea	ecx, DWORD PTR _S$58418[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 676  : 			return NULL;

	xor	eax, eax
	jmp	$L58375
$L58417:

; 678  : 	}

	jmp	$L58406
$L58407:

; 679  : 
; 680  : 	k = 0;

	mov	BYTE PTR _k$[ebp], 0

; 681  : 	for(j = 0; k < h;)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+233], 0
$L58420:
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _h$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	edx, eax
	jge	$L58421

; 683  : 		r1.left = j*iw;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+233]
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	imul	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+256], edx

; 684  : 		r1.top = k*ih;

	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _ih$[ebp]
	and	eax, 65535				; 0000ffffH
	imul	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+260], edx

; 685  : 		r1.right = r1.left + iw;

	mov	edx, DWORD PTR _iw$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+256]
	add	ecx, edx
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+264], ecx

; 686  : 		r1.bottom = r1.top + ih;

	mov	eax, DWORD PTR _ih$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+260]
	add	edx, eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+268], edx

; 687  : 
; 688  : 		if(	(e = l->gfx->Blt(&r1, TempGfx[ data[k][j] ], &r2, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 272				; 00000110H
	push	ecx
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	eax, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	mov	edx, DWORD PTR [ecx+eax*4]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 256				; 00000100H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx+144]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	ecx, DWORD PTR [edx+144]
	mov	edx, DWORD PTR [ecx]
	push	eax
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58423

; 690  : 			char S[256];
; 691  : 			sprintf(S, "Map:temp to gfx:%s", l_info->fName);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	push	OFFSET FLAT:??_C@_0BD@POGI@Map?3temp?5to?5gfx?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58424[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 692  : 			DDE("DrawLayers:Blt", e, S);

	lea	eax, DWORD PTR _S$58424[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 693  : 			return NULL;

	xor	eax, eax
	jmp	$L58375
$L58423:

; 695  : 
; 696  : 		j++;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+233]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+233], cl

; 697  : 		if((j%w) == 0)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	eax, ecx
	mov	ecx, DWORD PTR _w$[ebp]
	and	ecx, 65535				; 0000ffffH
	cdq
	idiv	ecx
	test	edx, edx
	jne	SHORT $L58426

; 699  : 			j = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+233], 0

; 700  : 			k++;

	mov	al, BYTE PTR _k$[ebp]
	add	al, 1
	mov	BYTE PTR _k$[ebp], al
$L58426:

; 702  : 	}

	jmp	$L58420
$L58421:

; 703  : 
; 704  : 	l->SetSize(l_info->w, l_info->h);

	mov	ecx, DWORD PTR _l_info$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+12]
	push	edx
	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+10]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+360]
	call	?SetSize@LAYER@@QAEXJJ@Z		; LAYER::SetSize

; 705  : 	l->SetClipRect(l_info->cx, l_info->cy, l_info->cw, l_info->ch);

	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+38]
	push	ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+36]
	push	eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+32]
	push	edx
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+360]
	call	?SetClipRect@LAYER@@QAEXJJJJ@Z		; LAYER::SetClipRect

; 706  : 	l->SetPos(l_info->x, l_info->y);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	push	ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+360]
	call	?SetPos@LAYER@@QAEXJJ@Z			; LAYER::SetPos

; 707  : 	l->SetHotSpot(l_info->hx, l_info->hy);

	mov	edx, DWORD PTR _l_info$[ebp]
	movsx	eax, WORD PTR [edx+42]
	push	eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	movsx	edx, WORD PTR [ecx+40]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	call	?SetHotSpot@LAYER@@QAEXJJ@Z		; LAYER::SetHotSpot

; 708  : 	l->old_r = l->r;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	add	edx, 80					; 00000050H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 112				; 00000070H
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR [ecx+4], eax
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR [ecx+8], eax
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [ecx+12], edx

; 709  : 	l->old_ir = l->ir;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 96					; 00000060H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	add	eax, 128				; 00000080H
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR [eax+4], edx
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [eax+8], edx
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [eax+12], ecx

; 710  : 
; 711  : 	k = l_info->map_num_images;

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+46]
	mov	BYTE PTR _k$[ebp], al

; 712  : 	for(j = 0; j < k; j++)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+233], 0
	jmp	SHORT $L58427
$L58428:
	mov	edx, DWORD PTR _this$[ebp]
	mov	al, BYTE PTR [edx+233]
	add	al, 1
	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+233], al
$L58427:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+233]
	mov	ecx, DWORD PTR _k$[ebp]
	and	ecx, 255				; 000000ffH
	cmp	eax, ecx
	jge	SHORT $L58429

; 713  : 		TempGfx[j]->Release();

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+233]
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	mov	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	eax, DWORD PTR _TempGfx$[ebp]
	mov	ecx, DWORD PTR [eax+ecx*4]
	mov	eax, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR [eax+8]
	jmp	SHORT $L58428
$L58429:

; 714  : 
; 715  : 	AppendLayer(l);

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?AppendLayer@DISPLAY@@QAEXPAVLAYER@@@Z	; DISPLAY::AppendLayer

; 716  : 	nLayers++;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+372]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+372], cl

; 717  : 	return l;

	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+360]
$L58375:

; 718  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?CreateMap@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ENDP	; DISPLAY::CreateMap
_TEXT	ENDS
PUBLIC	??_C@_07LPMI@Tile?3?$CFs?$AA@			; `string'
PUBLIC	??_C@_0BE@LEAD@Tile?3temp?5to?5gfx?3?$CFs?$AA@	; `string'
PUBLIC	?CreateTile@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateTile
;	COMDAT ??_C@_07LPMI@Tile?3?$CFs?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\layerutil.cpp
CONST	SEGMENT
??_C@_07LPMI@Tile?3?$CFs?$AA@ DB 'Tile:%s', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@LEAD@Tile?3temp?5to?5gfx?3?$CFs?$AA@
CONST	SEGMENT
??_C@_0BE@LEAD@Tile?3temp?5to?5gfx?3?$CFs?$AA@ DB 'Tile:temp to gfx:%s', 00H ; `string'
CONST	ENDS
;	COMDAT ?CreateTile@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z
_TEXT	SEGMENT
_l_info$ = 8
_this$ = -4
_ddsd$ = -128
_k$ = -132
_TempGfx$ = -136
_w$ = -140
_h$ = -144
_iw$ = -148
_ih$ = -152
_S$58446 = -408
_S$58456 = -664
_S$58459 = -920
_S$58461 = -1176
_S$58470 = -1432
_S$58476 = -1688
$T59168 = -1692
?CreateTile@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z PROC NEAR ; DISPLAY::CreateTile, COMDAT

; 721  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 1756				; 000006dcH
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 722  : 	l = new LAYER;

	push	164					; 000000a4H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59168[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T59168[ebp]
	mov	DWORD PTR [eax+360], ecx

; 723  : 	ZeroMemory(l, sizeof(LAYER));

	push	164					; 000000a4H
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 724  : 
; 725  : 	l->type = LT_TILE;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	BYTE PTR [edx+4], 3

; 726  : 	l->Name = l_info->Name;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax

; 727  : 	l->visable = l_info->visable;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+5]
	mov	BYTE PTR [edx+9], cl

; 728  : 	l->moveable = l_info->moveable;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+6]
	mov	BYTE PTR [eax+24], dl

; 729  : 	l->clip = l_info->clip;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+24]
	mov	BYTE PTR [ecx+52], al

; 730  : 	l->move_type = l_info->move_type;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+7]
	mov	BYTE PTR [edx+26], cl

; 731  : 	l->o_move_count = l->move_count = l_info->move_count;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+8]
	mov	BYTE PTR [eax+27], dl
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	cl, BYTE PTR [ecx+27]
	mov	BYTE PTR [eax+28], cl

; 732  : 	l->extra1 = l_info->extra1;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+44]
	mov	BYTE PTR [eax+5], dl

; 733  : 	l->extra2 = l_info->extra2;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+45]
	mov	BYTE PTR [ecx+6], al

; 734  : 	l->extra3 = l_info->extra3;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+46]
	mov	BYTE PTR [edx+7], cl

; 735  : 	l->collidable = l_info->collidable;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+9]
	mov	BYTE PTR [eax+44], dl

; 736  : 
; 737  : 	l->redraw = true;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	BYTE PTR [ecx+8], 1

; 738  : 
; 739  : 	DD_SDESC	ddsd;
; 740  : 	unsigned __int8 k = 0;

	mov	BYTE PTR _k$[ebp], 0

; 741  : 	GFXDATA TempGfx;
; 742  : 	unsigned __int16 w, h, iw, ih;
; 743  : 
; 744  : 	// number of images horz
; 745  : 	w = l_info->w;

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	ax, WORD PTR [edx+10]
	mov	WORD PTR _w$[ebp], ax

; 746  : 	// number of images vert
; 747  : 	h = l_info->h;

	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dx, WORD PTR [ecx+12]
	mov	WORD PTR _h$[ebp], dx

; 748  : 
; 749  : 	// number of images horz
; 750  : 	iw = l_info->tile_image_w;

	mov	eax, DWORD PTR _l_info$[ebp]
	movzx	cx, BYTE PTR [eax+44]
	mov	WORD PTR _iw$[ebp], cx

; 751  : 	// number of images vert
; 752  : 	ih = l_info->tile_image_h;

	mov	edx, DWORD PTR _l_info$[ebp]
	movzx	ax, BYTE PTR [edx+45]
	mov	WORD PTR _ih$[ebp], ax

; 753  : 
; 754  : 	r2.top = r2.left = 0;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+272], 0
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+276], 0

; 755  : 	r2.right = iw;

	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+280], eax

; 756  : 	r2.bottom = ih;

	mov	edx, DWORD PTR _ih$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+284], edx

; 757  : 
; 758  : 	// create layer gfx to place images into
; 759  : 		ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	ecx, DWORD PTR _ddsd$[ebp]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 760  : 		ddsd.dwSize		= sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 761  : 		ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 762  : 		ddsd.dwWidth	= l_info->w = w*iw;

	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	imul	edx, eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	WORD PTR [ecx+10], dx
	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+10]
	mov	DWORD PTR _ddsd$[ebp+12], eax

; 763  : 		ddsd.dwHeight	= l_info->h = h*ih;

	mov	ecx, DWORD PTR _h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _ih$[ebp]
	and	edx, 65535				; 0000ffffH
	imul	ecx, edx
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	WORD PTR [eax+12], cx
	mov	ecx, DWORD PTR _l_info$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+12]
	mov	DWORD PTR _ddsd$[ebp+8], edx

; 764  : 		//
; 765  : 		ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

	mov	DWORD PTR _ddsd$[ebp+104], 2112		; 00000840H

; 766  : 		if( (e = DD_Object->CreateSurface(&ddsd, &l->gfx, NULL)) != DD_OK )

	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 144				; 00000090H
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
	je	SHORT $L58445

; 768  : 			char S[256];
; 769  : 			sprintf(S, "Tile:%s", l_info->fName);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	push	OFFSET FLAT:??_C@_07LPMI@Tile?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58446[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 770  : 			DDE("LoadDrawS:CreateSurface", e, S);

	lea	eax, DWORD PTR _S$58446[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 771  : 			return NULL;

	xor	eax, eax
	jmp	$L58433
$L58445:

; 773  : 
; 774  : 		if( (e = DDSetColorKey(l->gfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx+144]
	push	edx
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58455

; 776  : 			char S[256];
; 777  : 			sprintf(S, "Tile:%s", l_info->fName);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	push	OFFSET FLAT:??_C@_07LPMI@Tile?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58456[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 778  : 			DDE("LoadDrawS:DDSetColorKey", e, S);

	lea	eax, DWORD PTR _S$58456[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 779  : 			return NULL;

	xor	eax, eax
	jmp	$L58433
$L58455:

; 781  : 
; 782  : 		if(	(e = l->gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 56					; 00000038H
	push	eax
	push	1024					; 00000400H
	push	0
	push	0
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx+144]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	ecx, DWORD PTR [edx+144]
	mov	edx, DWORD PTR [ecx]
	push	eax
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58458

; 784  : 			char S[256];
; 785  : 			sprintf(S, "Tile:%s", l_info->fName);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	push	OFFSET FLAT:??_C@_07LPMI@Tile?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58459[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 786  : 			DDE("DrawLayers:FloodFill", e, S);

	lea	eax, DWORD PTR _S$58459[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BF@BJFJ@DrawLayers?3FloodFill?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 787  : 			return NULL;

	xor	eax, eax
	jmp	$L58433
$L58458:

; 789  : 	//
; 790  : 
; 791  : 	if( (TempGfx = DDLoadBitmap(DD_Object, l_info->tile_info->fName, 0, 0)) == NULL )

	push	0
	push	0
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	push	ecx
	call	_DDLoadBitmap
	add	esp, 16					; 00000010H
	mov	DWORD PTR _TempGfx$[ebp], eax
	cmp	DWORD PTR _TempGfx$[ebp], 0
	jne	SHORT $L58460

; 793  : 		char S[256];
; 794  : 		sprintf(S, "Tile:%s", l_info->tile_info->fName);

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	push	OFFSET FLAT:??_C@_07LPMI@Tile?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58461[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 795  : 		DDE("LoadDrawS:DDLoadBitmap", i, S);

	lea	eax, DWORD PTR _S$58461[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+232]
	push	edx
	push	OFFSET FLAT:??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 796  : 		return NULL;

	xor	eax, eax
	jmp	$L58433
$L58460:

; 798  : 	if( (e = DDSetColorKey(TempGfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	eax, DWORD PTR _TempGfx$[ebp]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58469

; 800  : 		char S[256];
; 801  : 		sprintf(S, "Tile:%s", l_info->tile_info->fName);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	push	OFFSET FLAT:??_C@_07LPMI@Tile?3?$CFs?$AA@ ; `string'
	lea	eax, DWORD PTR _S$58470[ebp]
	push	eax
	call	_sprintf
	add	esp, 12					; 0000000cH

; 802  : 		DDE("LoadDrawS:DDSetColorKey", e, S);

	lea	ecx, DWORD PTR _S$58470[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 803  : 		return NULL;

	xor	eax, eax
	jmp	$L58433
$L58469:

; 805  : 
; 806  : 	k = 0;

	mov	BYTE PTR _k$[ebp], 0

; 807  : 	for(j = 0; k < h;)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+233], 0
$L58472:
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _h$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	edx, eax
	jge	$L58473

; 809  : 		r1.left = j*iw;

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+233]
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	imul	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+256], edx

; 810  : 		r1.top = k*ih;

	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _ih$[ebp]
	and	eax, 65535				; 0000ffffH
	imul	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+260], edx

; 811  : 		r1.right = r1.left + iw;

	mov	edx, DWORD PTR _iw$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+256]
	add	ecx, edx
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+264], ecx

; 812  : 		r1.bottom = r1.top + ih;

	mov	eax, DWORD PTR _ih$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+260]
	add	edx, eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+268], edx

; 813  : 
; 814  : 		if(	(e = l->gfx->Blt(&r1, TempGfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 272				; 00000110H
	push	ecx
	mov	edx, DWORD PTR _TempGfx$[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 256				; 00000100H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx+144]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	ecx, DWORD PTR [edx+144]
	mov	edx, DWORD PTR [ecx]
	push	eax
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58475

; 816  : 			char S[256];
; 817  : 			sprintf(S, "Tile:temp to gfx:%s", l_info->fName);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	push	OFFSET FLAT:??_C@_0BE@LEAD@Tile?3temp?5to?5gfx?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58476[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 818  : 			DDE("DrawLayers:Blt", e, S);

	lea	eax, DWORD PTR _S$58476[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 819  : 			return NULL;

	xor	eax, eax
	jmp	$L58433
$L58475:

; 821  : 
; 822  : 		j++;

	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+233]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+233], cl

; 823  : 		if((j%w) == 0)

	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+233]
	mov	eax, ecx
	mov	ecx, DWORD PTR _w$[ebp]
	and	ecx, 65535				; 0000ffffH
	cdq
	idiv	ecx
	test	edx, edx
	jne	SHORT $L58478

; 825  : 			j = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+233], 0

; 826  : 			k++;

	mov	al, BYTE PTR _k$[ebp]
	add	al, 1
	mov	BYTE PTR _k$[ebp], al
$L58478:

; 828  : 	}

	jmp	$L58472
$L58473:

; 829  : 
; 830  : 	l->SetSize(l_info->w, l_info->h);

	mov	ecx, DWORD PTR _l_info$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+12]
	push	edx
	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+10]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+360]
	call	?SetSize@LAYER@@QAEXJJ@Z		; LAYER::SetSize

; 831  : 	l->SetClipRect(l_info->cx, l_info->cy, l_info->cw, l_info->ch);

	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+38]
	push	ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+36]
	push	eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+32]
	push	edx
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+360]
	call	?SetClipRect@LAYER@@QAEXJJJJ@Z		; LAYER::SetClipRect

; 832  : 	l->SetPos(l_info->x, l_info->y);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	push	ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+360]
	call	?SetPos@LAYER@@QAEXJJ@Z			; LAYER::SetPos

; 833  : 	l->SetHotSpot(l_info->hx, l_info->hy);

	mov	edx, DWORD PTR _l_info$[ebp]
	movsx	eax, WORD PTR [edx+42]
	push	eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	movsx	edx, WORD PTR [ecx+40]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	call	?SetHotSpot@LAYER@@QAEXJJ@Z		; LAYER::SetHotSpot

; 834  : 	l->old_r = l->r;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	add	edx, 80					; 00000050H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 112				; 00000070H
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR [ecx+4], eax
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR [ecx+8], eax
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [ecx+12], edx

; 835  : 	l->old_ir = l->ir;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 96					; 00000060H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	add	eax, 128				; 00000080H
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR [eax+4], edx
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [eax+8], edx
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [eax+12], ecx

; 836  : 
; 837  : 	TempGfx->Release();

	mov	edx, DWORD PTR _TempGfx$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	push	ecx
	call	DWORD PTR [eax+8]

; 838  : 
; 839  : 	AppendLayer(l);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?AppendLayer@DISPLAY@@QAEXPAVLAYER@@@Z	; DISPLAY::AppendLayer

; 840  : 	nLayers++;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+372]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+372], dl

; 841  : 	return l;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+360]
$L58433:

; 842  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?CreateTile@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ENDP ; DISPLAY::CreateTile
_TEXT	ENDS
PUBLIC	??_C@_0M@CEJJ@Window?3Left?$AA@			; `string'
PUBLIC	??_C@_0BD@GLFJ@Window?3left?5to?5gfx?$AA@	; `string'
PUBLIC	??_C@_0N@BMLL@Window?3right?$AA@		; `string'
PUBLIC	??_C@_0BE@CLK@Window?3right?5to?5gfx?$AA@	; `string'
PUBLIC	??_C@_0L@KIBD@Window?3top?$AA@			; `string'
PUBLIC	??_C@_0BH@GPMC@Window?3tab?5Left?5to?5gfx?$AA@	; `string'
PUBLIC	??_C@_0BI@LGOP@Window?3tab?5right?5to?5gfx?$AA@	; `string'
PUBLIC	??_C@_0BC@DAPE@Window?3tab?5middle?$AA@		; `string'
PUBLIC	??_C@_0BJ@INLL@Window?3tab?5middle?5to?5gfx?$AA@ ; `string'
PUBLIC	??_C@_0BC@ENDJ@Window?3top?5to?5gfx?$AA@	; `string'
PUBLIC	??_C@_0O@DDMC@Window?3bottom?$AA@		; `string'
PUBLIC	??_C@_0BF@CDGK@Window?3bottom?5to?5gfx?$AA@	; `string'
PUBLIC	??_C@_0O@KNHA@Window?3middle?$AA@		; `string'
PUBLIC	??_C@_0BF@CBAP@Window?3middle?5to?5gfx?$AA@	; `string'
PUBLIC	??_C@_0BJ@OIGE@Window?3top?5middle?5to?5gfx?$AA@ ; `string'
PUBLIC	??_C@_0BP@GHII@Window?3top?5right?5middle?5to?5gfx?$AA@ ; `string'
PUBLIC	??_C@_0BH@EJFD@Window?3top?5left?5to?5gfx?$AA@	; `string'
PUBLIC	??_C@_0BI@GJJI@Window?3top?5right?5to?5gfx?$AA@	; `string'
PUBLIC	??_C@_0BD@CCBN@Window?3bottom?5left?$AA@	; `string'
PUBLIC	??_C@_0BK@JMFA@Window?3bottom?5left?5to?5gfx?$AA@ ; `string'
PUBLIC	??_C@_0BE@IOBH@Window?3bottom?5right?$AA@	; `string'
PUBLIC	??_C@_0BL@FFEN@Window?3bottom?5right?5to?5gfx?$AA@ ; `string'
PUBLIC	?CreateWin@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateWin
PUBLIC	?DrawTile@DISPLAY@@AAE_NPAUIDirectDrawSurface7@@0_G111@Z ; DISPLAY::DrawTile
;	COMDAT ??_C@_0M@CEJJ@Window?3Left?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\layerutil.cpp
CONST	SEGMENT
??_C@_0M@CEJJ@Window?3Left?$AA@ DB 'Window:Left', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@GLFJ@Window?3left?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BD@GLFJ@Window?3left?5to?5gfx?$AA@ DB 'Window:left to gfx', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0N@BMLL@Window?3right?$AA@
CONST	SEGMENT
??_C@_0N@BMLL@Window?3right?$AA@ DB 'Window:right', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@CLK@Window?3right?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BE@CLK@Window?3right?5to?5gfx?$AA@ DB 'Window:right to gfx', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0L@KIBD@Window?3top?$AA@
CONST	SEGMENT
??_C@_0L@KIBD@Window?3top?$AA@ DB 'Window:top', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BH@GPMC@Window?3tab?5Left?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BH@GPMC@Window?3tab?5Left?5to?5gfx?$AA@ DB 'Window:tab Left to gfx'
	DB	00H						; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@LGOP@Window?3tab?5right?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BI@LGOP@Window?3tab?5right?5to?5gfx?$AA@ DB 'Window:tab right to g'
	DB	'fx', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@DAPE@Window?3tab?5middle?$AA@
CONST	SEGMENT
??_C@_0BC@DAPE@Window?3tab?5middle?$AA@ DB 'Window:tab middle', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BJ@INLL@Window?3tab?5middle?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BJ@INLL@Window?3tab?5middle?5to?5gfx?$AA@ DB 'Window:tab middle to'
	DB	' gfx', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@ENDJ@Window?3top?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BC@ENDJ@Window?3top?5to?5gfx?$AA@ DB 'Window:top to gfx', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0O@DDMC@Window?3bottom?$AA@
CONST	SEGMENT
??_C@_0O@DDMC@Window?3bottom?$AA@ DB 'Window:bottom', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@CDGK@Window?3bottom?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BF@CDGK@Window?3bottom?5to?5gfx?$AA@ DB 'Window:bottom to gfx', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0O@KNHA@Window?3middle?$AA@
CONST	SEGMENT
??_C@_0O@KNHA@Window?3middle?$AA@ DB 'Window:middle', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@CBAP@Window?3middle?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BF@CBAP@Window?3middle?5to?5gfx?$AA@ DB 'Window:middle to gfx', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BJ@OIGE@Window?3top?5middle?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BJ@OIGE@Window?3top?5middle?5to?5gfx?$AA@ DB 'Window:top middle to'
	DB	' gfx', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BP@GHII@Window?3top?5right?5middle?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BP@GHII@Window?3top?5right?5middle?5to?5gfx?$AA@ DB 'Window:top ri'
	DB	'ght middle to gfx', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BH@EJFD@Window?3top?5left?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BH@EJFD@Window?3top?5left?5to?5gfx?$AA@ DB 'Window:top left to gfx'
	DB	00H						; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@GJJI@Window?3top?5right?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BI@GJJI@Window?3top?5right?5to?5gfx?$AA@ DB 'Window:top right to g'
	DB	'fx', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@CCBN@Window?3bottom?5left?$AA@
CONST	SEGMENT
??_C@_0BD@CCBN@Window?3bottom?5left?$AA@ DB 'Window:bottom left', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BK@JMFA@Window?3bottom?5left?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BK@JMFA@Window?3bottom?5left?5to?5gfx?$AA@ DB 'Window:bottom left '
	DB	'to gfx', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@IOBH@Window?3bottom?5right?$AA@
CONST	SEGMENT
??_C@_0BE@IOBH@Window?3bottom?5right?$AA@ DB 'Window:bottom right', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BL@FFEN@Window?3bottom?5right?5to?5gfx?$AA@
CONST	SEGMENT
??_C@_0BL@FFEN@Window?3bottom?5right?5to?5gfx?$AA@ DB 'Window:bottom righ'
	DB	't to gfx', 00H				; `string'
CONST	ENDS
;	COMDAT ?CreateWin@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z
_TEXT	SEGMENT
_l_info$ = 8
_this$ = -4
_ddsd$ = -128
_w$ = -132
_h$ = -136
_iw$ = -140
_ih$ = -144
_inside_w$ = -148
_inside_h$ = -152
_tab_w$ = -156
_tab_h$ = -160
_tab_iw$ = -164
_S$58500 = -420
_S$58509 = -676
_S$58512 = -932
_k$ = -936
_TempGfx$ = -940
_usebgcolor$ = -944
_S$58524 = -1200
_Left$ = -1204
_Right$ = -1208
_Bottom$ = -1212
_Middle$ = -1216
_Top$ = -1220
_TempTabGfx$58570 = -1224
_TabMiddle$58573 = -1228
_S$58575 = -1484
_S$58577 = -1740
_S$58579 = -1996
_TopMiddle$58647 = -2000
_tmW$58648 = -2004
$T59171 = -2008
$T59172 = -2012
$T59177 = -2016
?CreateWin@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z PROC NEAR ; DISPLAY::CreateWin, COMDAT

; 845  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 2088				; 00000828H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 846  : 	l = new LAYER;

	push	164					; 000000a4H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59171[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T59171[ebp]
	mov	DWORD PTR [eax+360], ecx

; 847  : 	ZeroMemory(l, sizeof(LAYER));

	push	164					; 000000a4H
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 848  : 
; 849  : 	l->type = LT_WINDOW;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	BYTE PTR [edx+4], 6

; 850  : 	l->Name = l_info->Name;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax

; 851  : 	l->visable = l_info->visable;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+5]
	mov	BYTE PTR [edx+9], cl

; 852  : 	l->moveable = l_info->moveable;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+6]
	mov	BYTE PTR [eax+24], dl

; 853  : 	l->clip = l_info->clip;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+24]
	mov	BYTE PTR [ecx+52], al

; 854  : 	l->move_type = l_info->move_type;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+7]
	mov	BYTE PTR [edx+26], cl

; 855  : 	l->o_move_count = l->move_count = l_info->move_count;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+8]
	mov	BYTE PTR [eax+27], dl
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	cl, BYTE PTR [ecx+27]
	mov	BYTE PTR [eax+28], cl

; 856  : 	l->extra1 = l_info->extra1;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+44]
	mov	BYTE PTR [eax+5], dl

; 857  : 	l->extra2 = l_info->extra2;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	al, BYTE PTR [edx+45]
	mov	BYTE PTR [ecx+6], al

; 858  : 	l->extra3 = l_info->extra3;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cl, BYTE PTR [eax+46]
	mov	BYTE PTR [edx+7], cl

; 859  : 	l->collidable = l_info->collidable;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dl, BYTE PTR [ecx+9]
	mov	BYTE PTR [eax+44], dl

; 860  : 	l->redraw = true;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	BYTE PTR [ecx+8], 1

; 861  : 
; 862  : 	DD_SDESC	ddsd;
; 863  : 	ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	edx, DWORD PTR _ddsd$[ebp]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 864  : 	ddsd.dwSize		= sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 865  : 	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 866  : 	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

	mov	DWORD PTR _ddsd$[ebp+104], 2112		; 00000840H

; 867  : 
; 868  : 	unsigned __int16 w, h, iw, ih, inside_w, inside_h, tab_w, tab_h;
; 869  : 
; 870  : 	iw = l_info->win_image_w;

	mov	eax, DWORD PTR _l_info$[ebp]
	movzx	cx, BYTE PTR [eax+45]
	mov	WORD PTR _iw$[ebp], cx

; 871  : 	ih = l_info->win_image_h;

	mov	edx, DWORD PTR _l_info$[ebp]
	movzx	ax, BYTE PTR [edx+46]
	mov	WORD PTR _ih$[ebp], ax

; 872  : 
; 873  : 	unsigned __int8 tab_iw = l_info->win->tab->wImg;

	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	eax, DWORD PTR [edx]
	mov	cl, BYTE PTR [eax+8]
	mov	BYTE PTR _tab_iw$[ebp], cl

; 874  : 
; 875  : 	w = l_info->w;

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	ax, WORD PTR [edx+10]
	mov	WORD PTR _w$[ebp], ax

; 876  : 	if( GETBIT(l->wType, WT_TAB) )

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	xor	eax, eax
	mov	al, BYTE PTR [edx+5]
	or	eax, -2					; fffffffeH
	xor	eax, 1
	not	eax
	test	eax, eax
	je	SHORT $L58496

; 878  : 		tab_w = l_info->win->tab->w;

	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	eax, DWORD PTR [edx]
	movzx	cx, BYTE PTR [eax]
	mov	WORD PTR _tab_w$[ebp], cx

; 879  : 		tab_h = l_info->win->tab->h;

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	ecx, DWORD PTR [eax]
	movzx	dx, BYTE PTR [ecx+1]
	mov	WORD PTR _tab_h$[ebp], dx

; 880  : 		h = l_info->h + tab_h;

	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+12]
	mov	edx, DWORD PTR _tab_h$[ebp]
	and	edx, 65535				; 0000ffffH
	add	ecx, edx
	mov	WORD PTR _h$[ebp], cx

; 881  : 		inside_h = l_info->h - ih;

	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+12]
	mov	edx, DWORD PTR _ih$[ebp]
	and	edx, 65535				; 0000ffffH
	sub	ecx, edx
	mov	WORD PTR _inside_h$[ebp], cx

; 883  : 	else

	jmp	SHORT $L58497
$L58496:

; 885  : 		h = l_info->h;

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	cx, WORD PTR [eax+12]
	mov	WORD PTR _h$[ebp], cx

; 886  : 		inside_h = l_info->h - (ih << 1);

	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+12]
	mov	ecx, DWORD PTR _ih$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 1
	sub	eax, ecx
	mov	WORD PTR _inside_h$[ebp], ax
$L58497:

; 888  : 
; 889  : 	inside_w = w - (iw << 1);

	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 1
	sub	edx, eax
	mov	WORD PTR _inside_w$[ebp], dx

; 890  : 	l_info->h += tab_h;

	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	dx, WORD PTR [ecx+12]
	add	dx, WORD PTR _tab_h$[ebp]
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	WORD PTR [eax+12], dx

; 891  : 
; 892  : 	// create layer gfx to place images into
; 893  : 		ddsd.dwWidth	= w;

	mov	ecx, DWORD PTR _w$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+12], ecx

; 894  : 		ddsd.dwHeight	= h;

	mov	edx, DWORD PTR _h$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+8], edx

; 895  : 		if( (e = DD_Object->CreateSurface(&ddsd, &l->gfx, NULL)) != DD_OK )

	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 144				; 00000090H
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
	je	SHORT $L58499

; 897  : 			char S[256];
; 898  : 			sprintf(S, "Tile:%s", l_info->fName);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	push	OFFSET FLAT:??_C@_07LPMI@Tile?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58500[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 899  : 			DDE("LoadDrawS:CreateSurface", e, S);

	lea	eax, DWORD PTR _S$58500[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 900  : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58499:

; 902  : 
; 903  : 		if( (e = DDSetColorKey(l->gfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx+144]
	push	edx
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58508

; 905  : 			char S[256];
; 906  : 			sprintf(S, "Tile:%s", l_info->fName);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	push	OFFSET FLAT:??_C@_07LPMI@Tile?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58509[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 907  : 			DDE("LoadDrawS:DDSetColorKey", e, S);

	lea	eax, DWORD PTR _S$58509[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 908  : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58508:

; 910  : 
; 911  : 		//FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, RGB(0, 255, 0));
; 912  : 		if(	(e = l->gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 56					; 00000038H
	push	eax
	push	1024					; 00000400H
	push	0
	push	0
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx+144]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	ecx, DWORD PTR [edx+144]
	mov	edx, DWORD PTR [ecx]
	push	eax
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58511

; 914  : 			char S[256];
; 915  : 			sprintf(S, "Tile:%s", l_info->fName);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	push	OFFSET FLAT:??_C@_07LPMI@Tile?3?$CFs?$AA@ ; `string'
	lea	edx, DWORD PTR _S$58512[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 916  : 			DDE("DrawLayers:FloodFill", e, S);

	lea	eax, DWORD PTR _S$58512[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BF@BJFJ@DrawLayers?3FloodFill?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 917  : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58511:

; 925  : 	GFXDATA *TempGfx;
; 926  : 	TempGfx = new GFXDATA[9];

	push	36					; 00000024H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59172[ebp], eax
	mov	eax, DWORD PTR $T59172[ebp]
	mov	DWORD PTR _TempGfx$[ebp], eax

; 927  : 	memset(TempGfx, 0,  9*sizeof(GFXDATA));

	push	36					; 00000024H
	push	0
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 928  : 
; 929  : 	bool usebgcolor = GETBIT(l->wType, WT_BGCOLOR) ? 1 : 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+5]
	or	ecx, -3					; fffffffdH
	xor	ecx, 2
	not	ecx
	neg	ecx
	sbb	ecx, ecx
	neg	ecx
	mov	BYTE PTR _usebgcolor$[ebp], cl

; 930  : 	k = GETBIT(l->wType, WT_TAB) ? 1 : 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+5]
	or	ecx, -2					; fffffffeH
	xor	ecx, 1
	not	ecx
	neg	ecx
	sbb	ecx, ecx
	neg	ecx
	mov	BYTE PTR _k$[ebp], cl

; 931  : 	for(; k < 9; k++)

	jmp	SHORT $L58519
$L58520:
	mov	dl, BYTE PTR _k$[ebp]
	add	dl, 1
	mov	BYTE PTR _k$[ebp], dl
$L58519:
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 255				; 000000ffH
	cmp	eax, 9
	jge	$L58521

; 933  : 		if( (usebgcolor) && (k == W_MIDDLE) )

	mov	ecx, DWORD PTR _usebgcolor$[ebp]
	and	ecx, 255				; 000000ffH
	test	ecx, ecx
	je	SHORT $L58522
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	cmp	edx, 4
	jne	SHORT $L58522

; 934  : 			k++;

	mov	al, BYTE PTR _k$[ebp]
	add	al, 1
	mov	BYTE PTR _k$[ebp], al
$L58522:

; 935  : 
; 936  : 		if( (TempGfx[k] = DDLoadBitmap(DD_Object, l_info->win->img[k], 0, 0)) == NULL )

	push	0
	push	0
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [edx+4]
	mov	edx, DWORD PTR [ecx+eax*4]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	push	ecx
	call	_DDLoadBitmap
	add	esp, 16					; 00000010H
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	mov	DWORD PTR [ecx+edx*4], eax
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _TempGfx$[ebp]
	cmp	DWORD PTR [eax+edx*4], 0
	jne	SHORT $L58523

; 938  : 			char S[256];
; 939  : 			sprintf(S, "Tile:%s", l_info->win->img[k]);

	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [edx+4]
	mov	edx, DWORD PTR [ecx+eax*4]
	push	edx
	push	OFFSET FLAT:??_C@_07LPMI@Tile?3?$CFs?$AA@ ; `string'
	lea	eax, DWORD PTR _S$58524[ebp]
	push	eax
	call	_sprintf
	add	esp, 12					; 0000000cH

; 940  : 			DDE("LoadDrawS:DDLoadBitmap", i, S);

	lea	ecx, DWORD PTR _S$58524[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	push	eax
	push	OFFSET FLAT:??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 941  : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58523:

; 943  : 	}

	jmp	$L58520
$L58521:

; 944  : 
; 945  : 	GFXDATA Left, Right, Bottom, Middle, Top;
; 946  : 	
; 947  : 	ddsd.dwWidth	= iw;	ddsd.dwHeight	= inside_h;

	mov	ecx, DWORD PTR _iw$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+12], ecx
	mov	edx, DWORD PTR _inside_h$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+8], edx

; 948  : 	//
; 949  : 	if( (e = DD_Object->CreateSurface(&ddsd, &Left, NULL)) != DD_OK )

	push	0
	lea	eax, DWORD PTR _Left$[ebp]
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
	je	SHORT $L58531

; 951  : 		DDE("LoadDrawS:CreateSurface", e, "Window:Left");

	push	OFFSET FLAT:??_C@_0M@CEJJ@Window?3Left?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 952  : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58531:

; 954  : 	if( (e = DDSetColorKey(Left,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	eax, DWORD PTR _Left$[ebp]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58540

; 956  : 		DDE("LoadDrawS:DDSetColorKey", e, "Window:Left");

	push	OFFSET FLAT:??_C@_0M@CEJJ@Window?3Left?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 957  : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58540:

; 959  : 	DrawTile(Left, TempGfx[W_LEFT], iw, inside_h, iw, ih);

	mov	dx, WORD PTR _ih$[ebp]
	push	edx
	mov	ax, WORD PTR _iw$[ebp]
	push	eax
	mov	cx, WORD PTR _inside_h$[ebp]
	push	ecx
	mov	dx, WORD PTR _iw$[ebp]
	push	edx
	mov	eax, DWORD PTR _TempGfx$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	push	ecx
	mov	edx, DWORD PTR _Left$[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DrawTile@DISPLAY@@AAE_NPAUIDirectDrawSurface7@@0_G111@Z ; DISPLAY::DrawTile

; 960  : 
; 961  : 	r1.top = GETBIT(l->wType, WT_TAB) ? tab_h : ih;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+5]
	or	edx, -2					; fffffffeH
	xor	edx, 1
	not	edx
	test	edx, edx
	je	SHORT $L59173
	mov	ax, WORD PTR _tab_h$[ebp]
	mov	WORD PTR -2020+[ebp], ax
	jmp	SHORT $L59174
$L59173:
	mov	cx, WORD PTR _ih$[ebp]
	mov	WORD PTR -2020+[ebp], cx
$L59174:
	mov	edx, DWORD PTR -2020+[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+260], edx

; 962  : 	r1.bottom = r1.top + inside_h;

	mov	ecx, DWORD PTR _inside_h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+260]
	add	eax, ecx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+268], eax

; 963  : 	r1.left = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+256], 0

; 964  : 	r1.right = iw;

	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+264], eax

; 965  : 	// Draw left to gfx
; 966  : 	if(	(e = l->gfx->Blt(&r1, Left, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	push	0
	mov	edx, DWORD PTR _Left$[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 256				; 00000100H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx+144]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	ecx, DWORD PTR [edx+144]
	mov	edx, DWORD PTR [ecx]
	push	eax
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58542

; 968  : 		DDE("DrawLayers:Blt", e, "Window:left to gfx");

	push	OFFSET FLAT:??_C@_0BD@GLFJ@Window?3left?5to?5gfx?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 969  : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58542:

; 971  : 
; 972  : 	Left->Release();

	mov	edx, DWORD PTR _Left$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _Left$[ebp]
	push	ecx
	call	DWORD PTR [eax+8]

; 973  : 
; 974  : 	//
; 975  : 	if( (e = DD_Object->CreateSurface(&ddsd, &Right, NULL)) != DD_OK )

	push	0
	lea	edx, DWORD PTR _Right$[ebp]
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
	je	SHORT $L58545

; 977  : 		DDE("LoadDrawS:CreateSurface", e, "Window:right");

	push	OFFSET FLAT:??_C@_0N@BMLL@Window?3right?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 978  : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58545:

; 980  : 	if( (e = DDSetColorKey(Right,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _Right$[ebp]
	push	edx
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58554

; 982  : 		DDE("LoadDrawS:DDSetColorKey", e, "Window:right");

	push	OFFSET FLAT:??_C@_0N@BMLL@Window?3right?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 983  : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58554:

; 985  : 	DrawTile(Right, TempGfx[W_RIGHT], iw, inside_h, iw, ih);

	mov	dx, WORD PTR _ih$[ebp]
	push	edx
	mov	ax, WORD PTR _iw$[ebp]
	push	eax
	mov	cx, WORD PTR _inside_h$[ebp]
	push	ecx
	mov	dx, WORD PTR _iw$[ebp]
	push	edx
	mov	eax, DWORD PTR _TempGfx$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	push	ecx
	mov	edx, DWORD PTR _Right$[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DrawTile@DISPLAY@@AAE_NPAUIDirectDrawSurface7@@0_G111@Z ; DISPLAY::DrawTile

; 986  : 
; 987  : 	r1.top = GETBIT(l->wType, WT_TAB) ? tab_h : ih;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+5]
	or	edx, -2					; fffffffeH
	xor	edx, 1
	not	edx
	test	edx, edx
	je	SHORT $L59175
	mov	ax, WORD PTR _tab_h$[ebp]
	mov	WORD PTR -2024+[ebp], ax
	jmp	SHORT $L59176
$L59175:
	mov	cx, WORD PTR _ih$[ebp]
	mov	WORD PTR -2024+[ebp], cx
$L59176:
	mov	edx, DWORD PTR -2024+[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+260], edx

; 988  : 	r1.bottom = r1.top + inside_h;

	mov	ecx, DWORD PTR _inside_h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+260]
	add	eax, ecx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+268], eax

; 989  : 	r1.left = w - iw;

	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	sub	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+256], edx

; 990  : 	r1.right = w;

	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+264], edx

; 991  : 	// Draw right to gfx
; 992  : 	if(	(e = l->gfx->Blt(&r1, Right, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	push	0
	mov	ecx, DWORD PTR _Right$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 256				; 00000100H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx+144]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	eax, DWORD PTR [ecx+144]
	mov	ecx, DWORD PTR [eax]
	push	edx
	call	DWORD PTR [ecx+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L58556

; 994  : 		DDE("DrawLayers:Blt", e, "Window:right to gfx");

	push	OFFSET FLAT:??_C@_0BE@CLK@Window?3right?5to?5gfx?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 995  : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58556:

; 997  : 
; 998  : 	Right->Release();

	mov	eax, DWORD PTR _Right$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _Right$[ebp]
	push	edx
	call	DWORD PTR [ecx+8]

; 999  : 
; 1000 : 	//
; 1001 : 	//
; 1002 : 	//
; 1003 : 	if( GETBIT(l->wType, WT_TAB) )

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+5]
	or	edx, -2					; fffffffeH
	xor	edx, 1
	not	edx
	test	edx, edx
	je	$L58558

; 1005 : 
; 1006 : 		ddsd.dwWidth	= tab_w;	ddsd.dwHeight	= tab_h;

	mov	eax, DWORD PTR _tab_w$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+12], eax
	mov	ecx, DWORD PTR _tab_h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+8], ecx

; 1007 : 		if( (e = DD_Object->CreateSurface(&ddsd, &Top, NULL)) != DD_OK )

	push	0
	lea	edx, DWORD PTR _Top$[ebp]
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
	je	SHORT $L58560

; 1009 : 			DDE("LoadDrawS:CreateSurface", e, "Window:top");

	push	OFFSET FLAT:??_C@_0L@KIBD@Window?3top?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1010 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58560:

; 1012 : 		if( (e = DDSetColorKey(Top,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _Top$[ebp]
	push	edx
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58569

; 1014 : 			DDE("LoadDrawS:DDSetColorKey", e, "Window:top");

	push	OFFSET FLAT:??_C@_0L@KIBD@Window?3top?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1015 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58569:

; 1017 : 
; 1018 : 		GFXDATA *TempTabGfx = new GFXDATA[3];

	push	12					; 0000000cH
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59177[ebp], eax
	mov	edx, DWORD PTR $T59177[ebp]
	mov	DWORD PTR _TempTabGfx$58570[ebp], edx

; 1019 : 		GFXDATA	TabMiddle;
; 1020 : 
; 1021 : 		k = 0;

	mov	BYTE PTR _k$[ebp], 0

; 1022 : 		if( (TempTabGfx[k] = DDLoadBitmap(DD_Object, l_info->win->tab->img[k], 0, 0)) == NULL )

	push	0
	push	0
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [edx+4]
	mov	edx, DWORD PTR [ecx+eax*4]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	push	ecx
	call	_DDLoadBitmap
	add	esp, 16					; 00000010H
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	ecx, DWORD PTR _TempTabGfx$58570[ebp]
	mov	DWORD PTR [ecx+edx*4], eax
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _TempTabGfx$58570[ebp]
	cmp	DWORD PTR [eax+edx*4], 0
	jne	SHORT $L58574

; 1024 : 			char S[256];
; 1025 : 			sprintf(S, "Tile:%s", l_info->win->tab->img[k]);

	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _k$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [eax+4]
	mov	eax, DWORD PTR [edx+ecx*4]
	push	eax
	push	OFFSET FLAT:??_C@_07LPMI@Tile?3?$CFs?$AA@ ; `string'
	lea	ecx, DWORD PTR _S$58575[ebp]
	push	ecx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 1026 : 			DDE("LoadDrawS:DDLoadBitmap", i, S);

	lea	edx, DWORD PTR _S$58575[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+232]
	push	ecx
	push	OFFSET FLAT:??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1027 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58574:

; 1029 : 		k++;

	mov	dl, BYTE PTR _k$[ebp]
	add	dl, 1
	mov	BYTE PTR _k$[ebp], dl

; 1030 : 
; 1031 : 		if( (TempTabGfx[k] = DDLoadBitmap(DD_Object, l_info->win->tab->img[k], 0, 0)) == NULL )

	push	0
	push	0
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [edx+4]
	mov	edx, DWORD PTR [ecx+eax*4]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	push	ecx
	call	_DDLoadBitmap
	add	esp, 16					; 00000010H
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	ecx, DWORD PTR _TempTabGfx$58570[ebp]
	mov	DWORD PTR [ecx+edx*4], eax
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _TempTabGfx$58570[ebp]
	cmp	DWORD PTR [eax+edx*4], 0
	jne	SHORT $L58576

; 1033 : 			char S[256];
; 1034 : 			sprintf(S, "Tile:%s", l_info->win->tab->img[k]);

	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _k$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [eax+4]
	mov	eax, DWORD PTR [edx+ecx*4]
	push	eax
	push	OFFSET FLAT:??_C@_07LPMI@Tile?3?$CFs?$AA@ ; `string'
	lea	ecx, DWORD PTR _S$58577[ebp]
	push	ecx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 1035 : 			DDE("LoadDrawS:DDLoadBitmap", i, S);

	lea	edx, DWORD PTR _S$58577[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+232]
	push	ecx
	push	OFFSET FLAT:??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1036 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58576:

; 1038 : 		k++;

	mov	dl, BYTE PTR _k$[ebp]
	add	dl, 1
	mov	BYTE PTR _k$[ebp], dl

; 1039 : 
; 1040 : 		if( (TempTabGfx[k] = DDLoadBitmap(DD_Object, l_info->win->tab->img[k], 0, 0)) == NULL )

	push	0
	push	0
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [edx+4]
	mov	edx, DWORD PTR [ecx+eax*4]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	push	ecx
	call	_DDLoadBitmap
	add	esp, 16					; 00000010H
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	ecx, DWORD PTR _TempTabGfx$58570[ebp]
	mov	DWORD PTR [ecx+edx*4], eax
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _TempTabGfx$58570[ebp]
	cmp	DWORD PTR [eax+edx*4], 0
	jne	SHORT $L58578

; 1042 : 			char S[256];
; 1043 : 			sprintf(S, "Tile:%s", l_info->win->tab->img[k]);

	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _k$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR [eax+4]
	mov	eax, DWORD PTR [edx+ecx*4]
	push	eax
	push	OFFSET FLAT:??_C@_07LPMI@Tile?3?$CFs?$AA@ ; `string'
	lea	ecx, DWORD PTR _S$58579[ebp]
	push	ecx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 1044 : 			DDE("LoadDrawS:DDLoadBitmap", i, S);

	lea	edx, DWORD PTR _S$58579[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+232]
	push	ecx
	push	OFFSET FLAT:??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1045 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58578:

; 1047 : 		k++;

	mov	dl, BYTE PTR _k$[ebp]
	add	dl, 1
	mov	BYTE PTR _k$[ebp], dl

; 1048 : 
; 1049 : 		r1.left = 0;	r1.right = tab_iw;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+256], 0
	mov	ecx, DWORD PTR _tab_iw$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+264], ecx

; 1050 : 		r1.top = 0;	r1.bottom = tab_h;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+260], 0
	mov	ecx, DWORD PTR _tab_h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+268], ecx

; 1051 : 		if(	(e = Top->Blt(&r1, TempTabGfx[T_LEFT], NULL, 0, NULL)) != DD_OK)

	push	0
	push	0
	push	0
	mov	eax, DWORD PTR _TempTabGfx$58570[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 256				; 00000100H
	push	edx
	mov	eax, DWORD PTR _Top$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _Top$[ebp]
	push	edx
	call	DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58581

; 1053 : 			DDE("DrawLayers:Blt", e, "Window:tab Left to gfx");

	push	OFFSET FLAT:??_C@_0BH@GPMC@Window?3tab?5Left?5to?5gfx?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1054 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58581:

; 1056 : 
; 1057 : 		r1.left = tab_w - tab_iw;	r1.right = tab_w;

	mov	edx, DWORD PTR _tab_w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _tab_iw$[ebp]
	and	eax, 255				; 000000ffH
	sub	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+256], edx
	mov	edx, DWORD PTR _tab_w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+264], edx

; 1058 : 		r1.top = 0;	r1.bottom = tab_h;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+260], 0
	mov	edx, DWORD PTR _tab_h$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+268], edx

; 1059 : 		if(	(e = Top->Blt(&r1, TempTabGfx[T_RIGHT], NULL, 0, NULL)) != DD_OK)

	push	0
	push	0
	push	0
	mov	ecx, DWORD PTR _TempTabGfx$58570[ebp]
	mov	edx, DWORD PTR [ecx+8]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 256				; 00000100H
	push	eax
	mov	ecx, DWORD PTR _Top$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _Top$[ebp]
	push	eax
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58584

; 1061 : 			DDE("DrawLayers:Blt", e, "Window:tab right to gfx");

	push	OFFSET FLAT:??_C@_0BI@LGOP@Window?3tab?5right?5to?5gfx?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1062 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58584:

; 1064 : 
; 1065 : 		ddsd.dwWidth	= tab_w - (tab_iw << 1);	ddsd.dwHeight	= tab_h;

	mov	edx, DWORD PTR _tab_w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _tab_iw$[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 1
	sub	edx, eax
	mov	DWORD PTR _ddsd$[ebp+12], edx
	mov	ecx, DWORD PTR _tab_h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+8], ecx

; 1066 : 		if( (e = DD_Object->CreateSurface(&ddsd, &TabMiddle, NULL)) != DD_OK )

	push	0
	lea	edx, DWORD PTR _TabMiddle$58573[ebp]
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
	je	SHORT $L58587

; 1068 : 			DDE("LoadDrawS:CreateSurface", e, "Window:tab middle");

	push	OFFSET FLAT:??_C@_0BC@DAPE@Window?3tab?5middle?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1069 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58587:

; 1071 : 
; 1072 : 		DrawTile(TabMiddle, TempTabGfx[T_MIDDLE], tab_w - (tab_iw << 1), tab_h, tab_iw, tab_h);

	mov	dx, WORD PTR _tab_h$[ebp]
	push	edx
	movzx	ax, BYTE PTR _tab_iw$[ebp]
	push	eax
	mov	cx, WORD PTR _tab_h$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tab_w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _tab_iw$[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 1
	sub	edx, eax
	push	edx
	mov	ecx, DWORD PTR _TempTabGfx$58570[ebp]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	mov	eax, DWORD PTR _TabMiddle$58573[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DrawTile@DISPLAY@@AAE_NPAUIDirectDrawSurface7@@0_G111@Z ; DISPLAY::DrawTile

; 1073 : 
; 1074 : 		r1.left = tab_iw;	r1.right = tab_w - tab_iw;

	mov	ecx, DWORD PTR _tab_iw$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+256], ecx
	mov	eax, DWORD PTR _tab_w$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _tab_iw$[ebp]
	and	ecx, 255				; 000000ffH
	sub	eax, ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+264], eax

; 1075 : 		r1.top = 0;	r1.bottom = tab_h;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+260], 0
	mov	ecx, DWORD PTR _tab_h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+268], ecx

; 1076 : 		if(	(e = Top->Blt(&r1, TabMiddle, NULL, 0, NULL)) != DD_OK)

	push	0
	push	0
	push	0
	mov	eax, DWORD PTR _TabMiddle$58573[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 256				; 00000100H
	push	ecx
	mov	edx, DWORD PTR _Top$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _Top$[ebp]
	push	ecx
	call	DWORD PTR [eax+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L58590

; 1078 : 			DDE("DrawLayers:Blt", e, "Window:tab middle to gfx");

	push	OFFSET FLAT:??_C@_0BJ@INLL@Window?3tab?5middle?5to?5gfx?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1079 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58590:

; 1081 : 
; 1082 : 		TabMiddle->Release();

	mov	eax, DWORD PTR _TabMiddle$58573[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _TabMiddle$58573[ebp]
	push	edx
	call	DWORD PTR [ecx+8]

; 1083 : 
; 1084 : 		TempTabGfx[0]->Release();

	mov	eax, DWORD PTR _TempTabGfx$58570[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _TempTabGfx$58570[ebp]
	mov	eax, DWORD PTR [edx]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+8]

; 1085 : 		TempTabGfx[1]->Release();

	mov	eax, DWORD PTR _TempTabGfx$58570[ebp]
	mov	ecx, DWORD PTR [eax+4]
	mov	edx, DWORD PTR _TempTabGfx$58570[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+8]

; 1086 : 		TempTabGfx[2]->Release();

	mov	eax, DWORD PTR _TempTabGfx$58570[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	edx, DWORD PTR _TempTabGfx$58570[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+8]

; 1087 : 
; 1088 : 		r1.left = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+256], 0

; 1089 : 		r1.right = tab_w;

	mov	ecx, DWORD PTR _tab_w$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+264], ecx

; 1090 : 		r1.top = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+260], 0

; 1091 : 		r1.bottom = tab_h;

	mov	ecx, DWORD PTR _tab_h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+268], ecx

; 1093 : 	else

	jmp	$L58592
$L58558:

; 1095 : 
; 1096 : 		ddsd.dwWidth	= inside_w;		ddsd.dwHeight	= ih;

	mov	eax, DWORD PTR _inside_w$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+12], eax
	mov	ecx, DWORD PTR _ih$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+8], ecx

; 1097 : 		if( (e = DD_Object->CreateSurface(&ddsd, &Top, NULL)) != DD_OK )

	push	0
	lea	edx, DWORD PTR _Top$[ebp]
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
	je	SHORT $L58594

; 1099 : 			DDE("LoadDrawS:CreateSurface", e, "Window:top");

	push	OFFSET FLAT:??_C@_0L@KIBD@Window?3top?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1100 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58594:

; 1102 : 		if( (e = DDSetColorKey(Top,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _Top$[ebp]
	push	edx
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58602

; 1104 : 			DDE("LoadDrawS:DDSetColorKey", e, "Window:top");

	push	OFFSET FLAT:??_C@_0L@KIBD@Window?3top?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1105 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58602:

; 1107 : 		DrawTile(Top, TempGfx[W_TOP], inside_w, ih, iw, ih);

	mov	dx, WORD PTR _ih$[ebp]
	push	edx
	mov	ax, WORD PTR _iw$[ebp]
	push	eax
	mov	cx, WORD PTR _ih$[ebp]
	push	ecx
	mov	dx, WORD PTR _inside_w$[ebp]
	push	edx
	mov	eax, DWORD PTR _TempGfx$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _Top$[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DrawTile@DISPLAY@@AAE_NPAUIDirectDrawSurface7@@0_G111@Z ; DISPLAY::DrawTile

; 1108 : 
; 1109 : 		r1.left = iw;

	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+256], eax

; 1110 : 		r1.right = inside_w + iw;

	mov	edx, DWORD PTR _inside_w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	add	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+264], edx

; 1111 : 		r1.top = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+260], 0

; 1112 : 		r1.bottom = ih;

	mov	eax, DWORD PTR _ih$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+268], eax
$L58592:

; 1114 : 	
; 1115 : 	// Draw top to gfx
; 1116 : 	if(	(e = l->gfx->Blt(&r1, Top, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	push	0
	mov	edx, DWORD PTR _Top$[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 256				; 00000100H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx+144]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	ecx, DWORD PTR [edx+144]
	mov	edx, DWORD PTR [ecx]
	push	eax
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58604

; 1118 : 		DDE("DrawLayers:Blt", e, "Window:top to gfx");

	push	OFFSET FLAT:??_C@_0BC@ENDJ@Window?3top?5to?5gfx?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1119 : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58604:

; 1121 : 
; 1122 : 	Top->Release();

	mov	edx, DWORD PTR _Top$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _Top$[ebp]
	push	ecx
	call	DWORD PTR [eax+8]

; 1123 : 
; 1124 : 	ddsd.dwWidth	= inside_w;		ddsd.dwHeight	= ih;

	mov	edx, DWORD PTR _inside_w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+12], edx
	mov	eax, DWORD PTR _ih$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+8], eax

; 1125 : 	if( (e = DD_Object->CreateSurface(&ddsd, &Bottom, NULL)) != DD_OK )

	push	0
	lea	ecx, DWORD PTR _Bottom$[ebp]
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
	je	SHORT $L58607

; 1127 : 		DDE("LoadDrawS:CreateSurface", e, "Window:bottom");

	push	OFFSET FLAT:??_C@_0O@DDMC@Window?3bottom?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1128 : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58607:

; 1130 : 	if( (e = DDSetColorKey(Bottom,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _Bottom$[ebp]
	push	edx
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58616

; 1132 : 		DDE("LoadDrawS:DDSetColorKey", e, "Window:bottom");

	push	OFFSET FLAT:??_C@_0O@DDMC@Window?3bottom?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1133 : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58616:

; 1135 : 	DrawTile(Bottom, TempGfx[W_BOTTOM], inside_w, ih, iw, ih);

	mov	dx, WORD PTR _ih$[ebp]
	push	edx
	mov	ax, WORD PTR _iw$[ebp]
	push	eax
	mov	cx, WORD PTR _ih$[ebp]
	push	ecx
	mov	dx, WORD PTR _inside_w$[ebp]
	push	edx
	mov	eax, DWORD PTR _TempGfx$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	push	ecx
	mov	edx, DWORD PTR _Bottom$[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DrawTile@DISPLAY@@AAE_NPAUIDirectDrawSurface7@@0_G111@Z ; DISPLAY::DrawTile

; 1136 : 
; 1137 : 
; 1138 : 	r1.left = iw;

	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+256], eax

; 1139 : 	r1.right = inside_w + iw;

	mov	edx, DWORD PTR _inside_w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	add	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+264], edx

; 1140 : 	r1.top = h - ih;

	mov	edx, DWORD PTR _h$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _ih$[ebp]
	and	eax, 65535				; 0000ffffH
	sub	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+260], edx

; 1141 : 	r1.bottom = h;

	mov	edx, DWORD PTR _h$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+268], edx

; 1142 : 	// Draw bottom to gfx
; 1143 : 	if(	(e = l->gfx->Blt(&r1, Bottom, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	push	0
	mov	ecx, DWORD PTR _Bottom$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 256				; 00000100H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx+144]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	eax, DWORD PTR [ecx+144]
	mov	ecx, DWORD PTR [eax]
	push	edx
	call	DWORD PTR [ecx+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L58618

; 1145 : 		DDE("DrawLayers:Blt", e, "Window:bottom to gfx");

	push	OFFSET FLAT:??_C@_0BF@CDGK@Window?3bottom?5to?5gfx?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1146 : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58618:

; 1148 : 
; 1149 : 	Bottom->Release();

	mov	eax, DWORD PTR _Bottom$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _Bottom$[ebp]
	push	edx
	call	DWORD PTR [ecx+8]

; 1150 : 
; 1151 : //
; 1152 : //
; 1153 : //
; 1154 : 	ddsd.dwWidth	= inside_w;

	mov	eax, DWORD PTR _inside_w$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+12], eax

; 1155 : 	ddsd.dwHeight	= inside_h;

	mov	ecx, DWORD PTR _inside_h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+8], ecx

; 1156 : 	if( (e = DD_Object->CreateSurface(&ddsd, &Middle, NULL)) != DD_OK )

	push	0
	lea	edx, DWORD PTR _Middle$[ebp]
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
	je	SHORT $L58621

; 1158 : 		DDE("LoadDrawS:CreateSurface", e, "Window:middle");

	push	OFFSET FLAT:??_C@_0O@KNHA@Window?3middle?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1159 : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58621:

; 1161 : 	if( (e = DDSetColorKey(Middle,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _Middle$[ebp]
	push	edx
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58630

; 1163 : 		DDE("LoadDrawS:DDSetColorKey", e, "Window:middle");

	push	OFFSET FLAT:??_C@_0O@KNHA@Window?3middle?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1164 : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58630:

; 1166 : 	if( GETBIT(l->wType, WT_BGCOLOR) )

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+5]
	or	ecx, -3					; fffffffdH
	xor	ecx, 2
	not	ecx
	test	ecx, ecx
	je	$L58631

; 1168 : 		FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, l_info->win->bgcolor);

	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	ecx, DWORD PTR [eax+8]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+228]
	push	eax
	call	_DDColorMatch
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+136], eax

; 1169 : 		
; 1170 : 		if(	(e = Middle->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 56					; 00000038H
	push	edx
	push	1024					; 00000400H
	push	0
	push	0
	push	0
	mov	eax, DWORD PTR _Middle$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _Middle$[ebp]
	push	edx
	call	DWORD PTR [ecx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58633

; 1172 : 			DDE("DrawLayers:FloodFill", e, "Window:middle");

	push	OFFSET FLAT:??_C@_0O@KNHA@Window?3middle?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BF@BJFJ@DrawLayers?3FloodFill?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1173 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58633:

; 1175 : 
; 1176 : 		FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+228]
	push	eax
	call	_DDColorMatch
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+136], eax

; 1178 : 	else

	jmp	SHORT $L58640
$L58631:

; 1179 : 		DrawTile(Middle, TempGfx[W_MIDDLE], inside_w, inside_h, iw, ih);

	mov	dx, WORD PTR _ih$[ebp]
	push	edx
	mov	ax, WORD PTR _iw$[ebp]
	push	eax
	mov	cx, WORD PTR _inside_h$[ebp]
	push	ecx
	mov	dx, WORD PTR _inside_w$[ebp]
	push	edx
	mov	eax, DWORD PTR _TempGfx$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	mov	edx, DWORD PTR _Middle$[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DrawTile@DISPLAY@@AAE_NPAUIDirectDrawSurface7@@0_G111@Z ; DISPLAY::DrawTile
$L58640:

; 1180 : 
; 1181 : //
; 1182 : 	if( GETBIT(l->wType, WT_TAB) )

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+5]
	or	edx, -2					; fffffffeH
	xor	edx, 1
	not	edx
	test	edx, edx
	je	SHORT $L58641

; 1183 : 		r1.top = tab_h;

	mov	eax, DWORD PTR _tab_h$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+260], eax

; 1184 : 	else

	jmp	SHORT $L58642
$L58641:

; 1185 : 		r1.top = ih;

	mov	edx, DWORD PTR _ih$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+260], edx
$L58642:

; 1186 : 
; 1187 : 	r1.left = iw;

	mov	ecx, DWORD PTR _iw$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+256], ecx

; 1188 : 	r1.right = iw + inside_w;

	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _inside_w$[ebp]
	and	ecx, 65535				; 0000ffffH
	add	eax, ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+264], eax

; 1189 : 	r1.bottom = r1.top + inside_h;

	mov	eax, DWORD PTR _inside_h$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+260]
	add	edx, eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+268], edx

; 1190 : 	
; 1191 : 	// Draw Middle to gfx
; 1192 : 	if(	(e = l->gfx->Blt(&r1, Middle, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	push	0
	mov	ecx, DWORD PTR _Middle$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 256				; 00000100H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx+144]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	eax, DWORD PTR [ecx+144]
	mov	ecx, DWORD PTR [eax]
	push	edx
	call	DWORD PTR [ecx+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L58644

; 1194 : 		DDE("DrawLayers:Blt", e, "Window:middle to gfx");

	push	OFFSET FLAT:??_C@_0BF@CBAP@Window?3middle?5to?5gfx?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1195 : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58644:

; 1197 : 
; 1198 : 	Middle->Release();

	mov	eax, DWORD PTR _Middle$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _Middle$[ebp]
	push	edx
	call	DWORD PTR [ecx+8]

; 1199 : 
; 1200 : 
; 1201 : 	if( GETBIT(l->wType, WT_TAB) )

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+5]
	or	edx, -2					; fffffffeH
	xor	edx, 1
	not	edx
	test	edx, edx
	je	$L58646

; 1203 : 		GFXDATA TopMiddle;
; 1204 : 		unsigned __int16 tmW = w - tab_w - iw;

	mov	eax, DWORD PTR _w$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _tab_w$[ebp]
	and	ecx, 65535				; 0000ffffH
	sub	eax, ecx
	mov	edx, DWORD PTR _iw$[ebp]
	and	edx, 65535				; 0000ffffH
	sub	eax, edx
	mov	WORD PTR _tmW$58648[ebp], ax

; 1205 : 
; 1206 : 		ddsd.dwWidth	= tmW;

	mov	eax, DWORD PTR _tmW$58648[ebp]
	and	eax, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+12], eax

; 1207 : 		ddsd.dwHeight	= tab_h;

	mov	ecx, DWORD PTR _tab_h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	DWORD PTR _ddsd$[ebp+8], ecx

; 1208 : 		if( (e = DD_Object->CreateSurface(&ddsd, &TopMiddle, NULL)) != DD_OK )

	push	0
	lea	edx, DWORD PTR _TopMiddle$58647[ebp]
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
	je	SHORT $L58650

; 1210 : 			DDE("LoadDrawS:CreateSurface", e, "Window:middle");

	push	OFFSET FLAT:??_C@_0O@KNHA@Window?3middle?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1211 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58650:

; 1213 : 		if( (e = DDSetColorKey(TopMiddle,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _TopMiddle$58647[ebp]
	push	edx
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58658

; 1215 : 			DDE("LoadDrawS:DDSetColorKey", e, "Window:middle");

	push	OFFSET FLAT:??_C@_0O@KNHA@Window?3middle?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1216 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58658:

; 1218 : 
; 1219 : 		DrawTile(TopMiddle, TempGfx[W_TOP], tmW, tab_h, iw, tab_h);

	mov	dx, WORD PTR _tab_h$[ebp]
	push	edx
	mov	ax, WORD PTR _iw$[ebp]
	push	eax
	mov	cx, WORD PTR _tab_h$[ebp]
	push	ecx
	mov	dx, WORD PTR _tmW$58648[ebp]
	push	edx
	mov	eax, DWORD PTR _TempGfx$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _TopMiddle$58647[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DrawTile@DISPLAY@@AAE_NPAUIDirectDrawSurface7@@0_G111@Z ; DISPLAY::DrawTile

; 1220 : 
; 1221 : 		r1.left = tab_w;	r1.right = w - iw;

	mov	eax, DWORD PTR _tab_w$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+256], eax
	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	sub	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+264], edx

; 1222 : 		r1.top = 0;	r1.bottom = tab_h;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+260], 0
	mov	eax, DWORD PTR _tab_h$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+268], eax

; 1223 : 		if(	(e = l->gfx->Blt(&r1, TopMiddle, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	push	0
	mov	edx, DWORD PTR _TopMiddle$58647[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 256				; 00000100H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx+144]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	ecx, DWORD PTR [edx+144]
	mov	edx, DWORD PTR [ecx]
	push	eax
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58660

; 1225 : 			DDE("DrawLayers:Blt", e, "Window:top middle to gfx");

	push	OFFSET FLAT:??_C@_0BJ@OIGE@Window?3top?5middle?5to?5gfx?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1226 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58660:

; 1228 : 
; 1229 : 		TopMiddle->Release();

	mov	edx, DWORD PTR _TopMiddle$58647[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _TopMiddle$58647[ebp]
	push	ecx
	call	DWORD PTR [eax+8]

; 1230 : 
; 1231 : 		if( (e = DDSetColorKey(TempGfx[W_TOP_RIGHT],  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _TempGfx$[ebp]
	mov	eax, DWORD PTR [edx+8]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58669

; 1233 : 			DDE("LoadDrawS:DDSetColorKey", e, "Window:middle");

	push	OFFSET FLAT:??_C@_0O@KNHA@Window?3middle?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1234 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58669:

; 1236 : 
; 1237 : 		r1.left = w - iw;	r1.right = w;

	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	sub	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+256], edx
	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+264], edx

; 1238 : 		r1.top = 0;	r1.bottom = tab_h;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+260], 0
	mov	edx, DWORD PTR _tab_h$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+268], edx

; 1239 : 		if(	(e = l->gfx->Blt(&r1, TempGfx[W_TOP_RIGHT], NULL, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	push	0
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 256				; 00000100H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx+144]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	ecx, DWORD PTR [edx+144]
	mov	edx, DWORD PTR [ecx]
	push	eax
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58671

; 1241 : 			DDE("DrawLayers:Blt", e, "Window:top right middle to gfx");

	push	OFFSET FLAT:??_C@_0BP@GHII@Window?3top?5right?5middle?5to?5gfx?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1242 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58671:

; 1245 : 	else

	jmp	$L58694
$L58646:

; 1247 : 		if( (e = DDSetColorKey(TempGfx[W_TOP_LEFT],  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _TempGfx$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58681

; 1249 : 			DDE("LoadDrawS:DDSetColorKey", e, "Window:middle");

	push	OFFSET FLAT:??_C@_0O@KNHA@Window?3middle?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1250 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58681:

; 1252 : 
; 1253 : 		r1.left = 0;	r1.right = iw;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+256], 0
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+264], eax

; 1254 : 		r1.top = 0;	r1.bottom = ih;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+260], 0
	mov	eax, DWORD PTR _ih$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+268], eax

; 1255 : 		if(	(e = l->gfx->Blt(&r1, TempGfx[W_TOP_LEFT], NULL, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	push	0
	mov	edx, DWORD PTR _TempGfx$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 256				; 00000100H
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	ecx, DWORD PTR [eax+144]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	edx, DWORD PTR [eax+144]
	mov	eax, DWORD PTR [edx]
	push	ecx
	call	DWORD PTR [eax+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58683

; 1257 : 			DDE("DrawLayers:Blt", e, "Window:top left to gfx");

	push	OFFSET FLAT:??_C@_0BH@EJFD@Window?3top?5left?5to?5gfx?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1258 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58683:

; 1260 : 
; 1261 : 
; 1262 : 		if( (e = DDSetColorKey(TempGfx[W_TOP_RIGHT],  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _TempGfx$[ebp]
	mov	eax, DWORD PTR [edx+8]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58692

; 1264 : 			DDE("LoadDrawS:DDSetColorKey", e, "Window:middle");

	push	OFFSET FLAT:??_C@_0O@KNHA@Window?3middle?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1265 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58692:

; 1267 : 
; 1268 : 		r1.left = w - iw;	r1.right = w;

	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	sub	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+256], edx
	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+264], edx

; 1269 : 		r1.top = 0;	r1.bottom = ih;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+260], 0
	mov	edx, DWORD PTR _ih$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+268], edx

; 1270 : 		if(	(e = l->gfx->Blt(&r1, TempGfx[W_TOP_RIGHT], NULL, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	push	0
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 256				; 00000100H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx+144]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	ecx, DWORD PTR [edx+144]
	mov	edx, DWORD PTR [ecx]
	push	eax
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58694

; 1272 : 			DDE("DrawLayers:Blt", e, "Window:top right to gfx");

	push	OFFSET FLAT:??_C@_0BI@GJJI@Window?3top?5right?5to?5gfx?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1273 : 			return NULL;

	xor	eax, eax
	jmp	$L58482
$L58694:

; 1276 : 
; 1277 : //
; 1278 : //
; 1279 : //
; 1280 : 
; 1281 : 	if( (e = DDSetColorKey(TempGfx[W_BOTTOM_LEFT],  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _TempGfx$[ebp]
	mov	eax, DWORD PTR [edx+24]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58703

; 1283 : 		DDE("LoadDrawS:DDSetColorKey", e, "Window:bottom left");

	push	OFFSET FLAT:??_C@_0BD@CCBN@Window?3bottom?5left?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1284 : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58703:

; 1286 : 	r1.left = 0;	r1.right = iw;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+256], 0
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+264], eax

; 1287 : 	r1.top = h - ih;	r1.bottom = h;

	mov	edx, DWORD PTR _h$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _ih$[ebp]
	and	eax, 65535				; 0000ffffH
	sub	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+260], edx
	mov	edx, DWORD PTR _h$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+268], edx

; 1288 : 	if(	(e = l->gfx->Blt(&r1, TempGfx[W_BOTTOM_LEFT], NULL, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	push	0
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 256				; 00000100H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	eax, DWORD PTR [edx+144]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	mov	ecx, DWORD PTR [edx+144]
	mov	edx, DWORD PTR [ecx]
	push	eax
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58706

; 1290 : 		DDE("DrawLayers:Blt", e, "Window:bottom left to gfx");

	push	OFFSET FLAT:??_C@_0BK@JMFA@Window?3bottom?5left?5to?5gfx?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1291 : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58706:

; 1293 : 
; 1294 : 
; 1295 : 	if( (e = DDSetColorKey(TempGfx[W_BOTTOM_RIGHT],  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	edx, DWORD PTR _TempGfx$[ebp]
	mov	eax, DWORD PTR [edx+32]
	push	eax
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58715

; 1297 : 		DDE("LoadDrawS:DDSetColorKey", e, "Window:bottom right");

	push	OFFSET FLAT:??_C@_0BE@IOBH@Window?3bottom?5right?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1298 : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58715:

; 1300 : 	r1.left = w - iw;	r1.right = w;

	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _iw$[ebp]
	and	eax, 65535				; 0000ffffH
	sub	edx, eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+256], edx
	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+264], edx

; 1301 : 	r1.top = h - ih;	r1.bottom = h;

	mov	ecx, DWORD PTR _h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _ih$[ebp]
	and	edx, 65535				; 0000ffffH
	sub	ecx, edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+260], ecx
	mov	ecx, DWORD PTR _h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+268], ecx

; 1302 : 	if(	(e = l->gfx->Blt(&r1, TempGfx[W_BOTTOM_RIGHT], NULL, DDBLT_KEYSRC, NULL)) != DD_OK)

	push	0
	push	32768					; 00008000H
	push	0
	mov	eax, DWORD PTR _TempGfx$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 256				; 00000100H
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	edx, DWORD PTR [ecx+144]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	mov	eax, DWORD PTR [ecx+144]
	mov	ecx, DWORD PTR [eax]
	push	edx
	call	DWORD PTR [ecx+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L58718

; 1304 : 		DDE("DrawLayers:Blt", e, "Window:bottom right to gfx");

	push	OFFSET FLAT:??_C@_0BL@FFEN@Window?3bottom?5right?5to?5gfx?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE

; 1305 : 		return NULL;

	xor	eax, eax
	jmp	$L58482
$L58718:

; 1307 : 
; 1308 : //
; 1309 : //
; 1310 : //
; 1311 : 	k = GETBIT(l->wType, WT_TAB) ? 1 : 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+5]
	or	edx, -2					; fffffffeH
	xor	edx, 1
	not	edx
	neg	edx
	sbb	edx, edx
	neg	edx
	mov	BYTE PTR _k$[ebp], dl

; 1312 : 	for(; k < 9; k++)

	jmp	SHORT $L58720
$L58721:
	mov	al, BYTE PTR _k$[ebp]
	add	al, 1
	mov	BYTE PTR _k$[ebp], al
$L58720:
	mov	ecx, DWORD PTR _k$[ebp]
	and	ecx, 255				; 000000ffH
	cmp	ecx, 9
	jge	SHORT $L58722

; 1314 : 		if(usebgcolor && (k == W_MIDDLE))

	mov	edx, DWORD PTR _usebgcolor$[ebp]
	and	edx, 255				; 000000ffH
	test	edx, edx
	je	SHORT $L58723
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 255				; 000000ffH
	cmp	eax, 4
	jne	SHORT $L58723

; 1315 : 			k++;

	mov	cl, BYTE PTR _k$[ebp]
	add	cl, 1
	mov	BYTE PTR _k$[ebp], cl
$L58723:

; 1316 : 
; 1317 : 		TempGfx[k]->Release();

	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _TempGfx$[ebp]
	mov	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _TempGfx$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR [edx]
	push	ecx
	call	DWORD PTR [eax+8]

; 1318 : 	}

	jmp	SHORT $L58721
$L58722:

; 1319 : 
; 1320 : 	l->SetSize(l_info->w, l_info->h);

	mov	ecx, DWORD PTR _l_info$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+12]
	push	edx
	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+10]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+360]
	call	?SetSize@LAYER@@QAEXJJ@Z		; LAYER::SetSize

; 1321 : 	l->SetClipRect(l_info->cx, l_info->cy, l_info->cw, l_info->ch);

	mov	eax, DWORD PTR _l_info$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+38]
	push	ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+36]
	push	eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	mov	edx, DWORD PTR [ecx+32]
	push	edx
	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+360]
	call	?SetClipRect@LAYER@@QAEXJJJJ@Z		; LAYER::SetClipRect

; 1322 : 	l->SetPos(l_info->x, l_info->y);

	mov	eax, DWORD PTR _l_info$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	push	ecx
	mov	edx, DWORD PTR _l_info$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+360]
	call	?SetPos@LAYER@@QAEXJJ@Z			; LAYER::SetPos

; 1323 : 	l->SetHotSpot(l_info->hx, l_info->hy);

	mov	edx, DWORD PTR _l_info$[ebp]
	movsx	eax, WORD PTR [edx+42]
	push	eax
	mov	ecx, DWORD PTR _l_info$[ebp]
	movsx	edx, WORD PTR [ecx+40]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	call	?SetHotSpot@LAYER@@QAEXJJ@Z		; LAYER::SetHotSpot

; 1324 : 	l->old_r = l->r;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+360]
	add	edx, 80					; 00000050H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 112				; 00000070H
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR [ecx+4], eax
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR [ecx+8], eax
	mov	edx, DWORD PTR [edx+12]
	mov	DWORD PTR [ecx+12], edx

; 1325 : 	l->old_ir = l->ir;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+360]
	add	ecx, 96					; 00000060H
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	add	eax, 128				; 00000080H
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR [eax+4], edx
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [eax+8], edx
	mov	ecx, DWORD PTR [ecx+12]
	mov	DWORD PTR [eax+12], ecx

; 1326 : 
; 1327 : 	AppendLayer(l);

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?AppendLayer@DISPLAY@@QAEXPAVLAYER@@@Z	; DISPLAY::AppendLayer

; 1328 : 	nLayers++;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+372]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+372], dl

; 1329 : 	return l;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+360]
$L58482:

; 1330 : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?CreateWin@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ENDP	; DISPLAY::CreateWin
_TEXT	ENDS
PUBLIC	??_C@_0BB@MLMK@DrawTile?3TempGfx?$AA@		; `string'
PUBLIC	??_C@_0BJ@LCGH@DrawTile?3tile?5to?5TempGfx?$AA@	; `string'
PUBLIC	??_C@_0BI@OJFJ@DrawTile?3TempGfx?5to?5out?$AA@	; `string'
;	COMDAT ??_C@_0BB@MLMK@DrawTile?3TempGfx?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\layerutil.cpp
CONST	SEGMENT
??_C@_0BB@MLMK@DrawTile?3TempGfx?$AA@ DB 'DrawTile:TempGfx', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BJ@LCGH@DrawTile?3tile?5to?5TempGfx?$AA@
CONST	SEGMENT
??_C@_0BJ@LCGH@DrawTile?3tile?5to?5TempGfx?$AA@ DB 'DrawTile:tile to Temp'
	DB	'Gfx', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@OJFJ@DrawTile?3TempGfx?5to?5out?$AA@
CONST	SEGMENT
??_C@_0BI@OJFJ@DrawTile?3TempGfx?5to?5out?$AA@ DB 'DrawTile:TempGfx to ou'
	DB	't', 00H					; `string'
CONST	ENDS
;	COMDAT ?DrawTile@DISPLAY@@AAE_NPAUIDirectDrawSurface7@@0_G111@Z
_TEXT	SEGMENT
_out$ = 8
_tile$ = 12
_w$ = 16
_h$ = 20
_iw$ = 24
_ih$ = 28
_this$ = -4
_TempGfx$ = -8
_j$ = -12
_k$ = -16
_out_w$ = -20
_out_h$ = -24
_ddsd$ = -148
?DrawTile@DISPLAY@@AAE_NPAUIDirectDrawSurface7@@0_G111@Z PROC NEAR ; DISPLAY::DrawTile, COMDAT

; 1333 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 212				; 000000d4H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 1334 : 	GFXDATA TempGfx;
; 1335 : 	unsigned __int8 j, k;
; 1336 : 	unsigned __int16 out_w = w, out_h = h;

	mov	ax, WORD PTR _w$[ebp]
	mov	WORD PTR _out_w$[ebp], ax
	mov	cx, WORD PTR _h$[ebp]
	mov	WORD PTR _out_h$[ebp], cx

; 1337 : 	j = w%iw ? 1 : 0;

	mov	eax, DWORD PTR _w$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _iw$[ebp]
	and	ecx, 65535				; 0000ffffH
	cdq
	idiv	ecx
	neg	edx
	sbb	edx, edx
	neg	edx
	mov	BYTE PTR _j$[ebp], dl

; 1338 : 	w = w/iw + j;

	mov	eax, DWORD PTR _w$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _iw$[ebp]
	and	ecx, 65535				; 0000ffffH
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	add	eax, edx
	mov	WORD PTR _w$[ebp], ax

; 1339 : 	k = h%ih ? 1 : 0;

	mov	eax, DWORD PTR _h$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _ih$[ebp]
	and	ecx, 65535				; 0000ffffH
	cdq
	idiv	ecx
	neg	edx
	sbb	edx, edx
	neg	edx
	mov	BYTE PTR _k$[ebp], dl

; 1340 : 	h = h/ih + k;

	mov	eax, DWORD PTR _h$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _ih$[ebp]
	and	ecx, 65535				; 0000ffffH
	cdq
	idiv	ecx
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	add	eax, edx
	mov	WORD PTR _h$[ebp], ax

; 1341 : 
; 1342 : 	DD_SDESC	ddsd;
; 1343 : 	ZeroMemory(&ddsd, sizeof(ddsd));

	push	124					; 0000007cH
	push	0
	lea	eax, DWORD PTR _ddsd$[ebp]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 1344 : 	ddsd.dwSize		= sizeof(ddsd);

	mov	DWORD PTR _ddsd$[ebp], 124		; 0000007cH

; 1345 : 	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

	mov	DWORD PTR _ddsd$[ebp+4], 7

; 1346 : 	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

	mov	DWORD PTR _ddsd$[ebp+104], 2112		; 00000840H

; 1347 : 	ddsd.dwWidth	= w*iw;

	mov	ecx, DWORD PTR _w$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _iw$[ebp]
	and	edx, 65535				; 0000ffffH
	imul	ecx, edx
	mov	DWORD PTR _ddsd$[ebp+12], ecx

; 1348 : 	ddsd.dwHeight	= h*ih;

	mov	eax, DWORD PTR _h$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _ih$[ebp]
	and	ecx, 65535				; 0000ffffH
	imul	eax, ecx
	mov	DWORD PTR _ddsd$[ebp+8], eax

; 1349 : 
; 1350 : 	if( (e = DD_Object->CreateSurface(&ddsd, &TempGfx, NULL)) != DD_OK )

	push	0
	lea	edx, DWORD PTR _TempGfx$[ebp]
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
	je	SHORT $L58740

; 1351 : 		return DDE("LoadDrawS:CreateSurface", e, "DrawTile:TempGfx");

	push	OFFSET FLAT:??_C@_0BB@MLMK@DrawTile?3TempGfx?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@DBFO@LoadDrawS?3CreateSurface?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L58732
$L58740:

; 1352 : 
; 1353 : 	for(j = 0, k = 0; k < h;)

	mov	BYTE PTR _j$[ebp], 0
	mov	BYTE PTR _k$[ebp], 0
$L58743:
	mov	edx, DWORD PTR _k$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _h$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	edx, eax
	jge	$L58744

; 1355 : 		r1.left = j*iw;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _iw$[ebp]
	and	edx, 65535				; 0000ffffH
	imul	ecx, edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+256], ecx

; 1356 : 		r1.top = k*ih;

	mov	ecx, DWORD PTR _k$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _ih$[ebp]
	and	edx, 65535				; 0000ffffH
	imul	ecx, edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+260], ecx

; 1357 : 		r1.right = r1.left + iw;

	mov	ecx, DWORD PTR _iw$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+256]
	add	eax, ecx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+264], eax

; 1358 : 		r1.bottom = r1.top + ih;

	mov	edx, DWORD PTR _ih$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+260]
	add	ecx, edx
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+268], ecx

; 1359 : 
; 1360 : 		if(	(e = TempGfx->Blt(&r1, tile, NULL, 0, NULL)) != DD_OK)

	push	0
	push	0
	push	0
	mov	eax, DWORD PTR _tile$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 256				; 00000100H
	push	ecx
	mov	edx, DWORD PTR _TempGfx$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _TempGfx$[ebp]
	push	ecx
	call	DWORD PTR [eax+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L58746

; 1361 : 			return DDE("DrawLayers:Blt", e, "DrawTile:tile to TempGfx");

	push	OFFSET FLAT:??_C@_0BJ@LCGH@DrawTile?3tile?5to?5TempGfx?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L58732
$L58746:

; 1362 : 
; 1363 : 		j++;

	mov	al, BYTE PTR _j$[ebp]
	add	al, 1
	mov	BYTE PTR _j$[ebp], al

; 1364 : 		if((j%w) == 0)

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _w$[ebp]
	and	ecx, 65535				; 0000ffffH
	cdq
	idiv	ecx
	test	edx, edx
	jne	SHORT $L58748

; 1366 : 			j = 0;

	mov	BYTE PTR _j$[ebp], 0

; 1367 : 			k++;

	mov	dl, BYTE PTR _k$[ebp]
	add	dl, 1
	mov	BYTE PTR _k$[ebp], dl
$L58748:

; 1369 : 	}

	jmp	$L58743
$L58744:

; 1370 : 
; 1371 : 	r1.left = 0;	r1.top = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+256], 0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+260], 0

; 1372 : 	r1.right = out_w;	r1.bottom = out_h;

	mov	edx, DWORD PTR _out_w$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+264], edx
	mov	ecx, DWORD PTR _out_h$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+268], ecx

; 1373 : 	if(	(e = out->Blt(&r1, TempGfx, NULL, 0, NULL)) != DD_OK)

	push	0
	push	0
	push	0
	mov	eax, DWORD PTR _TempGfx$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 256				; 00000100H
	push	ecx
	mov	edx, DWORD PTR _out$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _out$[ebp]
	push	ecx
	call	DWORD PTR [eax+20]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+16], eax
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+16], 0
	je	SHORT $L58750

; 1374 : 		return DDE("DrawLayers:Blt", e, "DrawTile:TempGfx to out");

	push	OFFSET FLAT:??_C@_0BI@OJFJ@DrawTile?3TempGfx?5to?5out?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	SHORT $L58732
$L58750:

; 1375 : 
; 1376 : 	return 0;

	xor	al, al
$L58732:

; 1377 : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	24					; 00000018H
?DrawTile@DISPLAY@@AAE_NPAUIDirectDrawSurface7@@0_G111@Z ENDP ; DISPLAY::DrawTile
_TEXT	ENDS
PUBLIC	?CreateCounter@DISPLAY@@QAEPAVLAYER@@JJ_EPAD001@Z ; DISPLAY::CreateCounter
;	COMDAT ?CreateCounter@DISPLAY@@QAEPAVLAYER@@JJ_EPAD001@Z
_TEXT	SEGMENT
_x$ = 8
_y$ = 12
_NumDigits$ = 16
_StartText$ = 20
_type$ = 24
_fontNum$ = 28
_name$ = 32
_this$ = -4
_li$ = -8
_S$58767 = -12
$T59182 = -16
$T59183 = -20
?CreateCounter@DISPLAY@@QAEPAVLAYER@@JJ_EPAD001@Z PROC NEAR ; DISPLAY::CreateCounter, COMDAT

; 1383 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 84					; 00000054H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 1384 : 	//
; 1385 : 	LAYER_INFO *li = new LAYER_INFO;

	push	52					; 00000034H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59182[ebp], eax
	mov	eax, DWORD PTR $T59182[ebp]
	mov	DWORD PTR _li$[ebp], eax

; 1386 : 	ZeroMemory(li, sizeof(LAYER_INFO));

	push	52					; 00000034H
	push	0
	mov	ecx, DWORD PTR _li$[ebp]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 1387 : 	li->visable = true;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+5], 1

; 1388 : 	li->hAlign = type;

	mov	eax, DWORD PTR _li$[ebp]
	mov	cl, BYTE PTR _type$[ebp]
	mov	BYTE PTR [eax+44], cl

; 1389 : 	li->FontNum = fontNum;

	mov	edx, DWORD PTR _li$[ebp]
	mov	al, BYTE PTR _fontNum$[ebp]
	mov	BYTE PTR [edx+46], al

; 1390 : 	li->NumDigits = NumDigits;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	dl, BYTE PTR _NumDigits$[ebp]
	mov	BYTE PTR [ecx+45], dl

; 1391 : 	li->x = x;

	mov	eax, DWORD PTR _li$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	mov	DWORD PTR [eax+16], ecx

; 1392 : 	li->y = y;

	mov	edx, DWORD PTR _li$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	mov	DWORD PTR [edx+20], eax

; 1393 : 	li->w = NumDigits*(Font[fontNum].cw);

	mov	ecx, DWORD PTR _NumDigits$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _fontNum$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+188]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+edx*8]
	imul	ecx, ebx
	mov	edx, DWORD PTR _li$[ebp]
	mov	WORD PTR [edx+10], cx

; 1394 : 	li->h = Font[fontNum].ch;

	mov	eax, DWORD PTR _fontNum$[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+188]
	movzx	ax, BYTE PTR [edx+eax*8+1]
	mov	ecx, DWORD PTR _li$[ebp]
	mov	WORD PTR [ecx+12], ax

; 1395 : //	li->w = NumDigits;
; 1396 : //	li->h = 1;
; 1397 : 
; 1398 : 	if(StartText == NULL)

	cmp	DWORD PTR _StartText$[ebp], 0
	jne	SHORT $L58766

; 1400 : 		char *S = new char[NumDigits + 1];

	mov	edx, DWORD PTR _NumDigits$[ebp]
	and	edx, 255				; 000000ffH
	add	edx, 1
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59183[ebp], eax
	mov	eax, DWORD PTR $T59183[ebp]
	mov	DWORD PTR _S$58767[ebp], eax

; 1401 : 		memset(S, ' ', NumDigits*sizeof(char) );

	mov	ecx, DWORD PTR _NumDigits$[ebp]
	and	ecx, 255				; 000000ffH
	push	ecx
	push	32					; 00000020H
	mov	edx, DWORD PTR _S$58767[ebp]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 1402 : 		S[NumDigits] = 0;

	mov	eax, DWORD PTR _NumDigits$[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _S$58767[ebp]
	mov	BYTE PTR [ecx+eax], 0

; 1403 : 		li->text = S;

	mov	edx, DWORD PTR _li$[ebp]
	mov	eax, DWORD PTR _S$58767[ebp]
	mov	DWORD PTR [edx+48], eax

; 1405 : 	else

	jmp	SHORT $L58771
$L58766:

; 1406 : 		SetStr(&li->text, StartText, NumDigits);

	mov	cl, BYTE PTR _NumDigits$[ebp]
	push	ecx
	mov	edx, DWORD PTR _StartText$[ebp]
	push	edx
	mov	eax, DWORD PTR _li$[ebp]
	add	eax, 48					; 00000030H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD_E@Z	; DISPLAY::SetStr
$L58771:

; 1407 : 
; 1408 : 	SetStr(&li->Name, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _li$[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 1409 : 
; 1410 : 	return CreateTextBox(li);

	mov	eax, DWORD PTR _li$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?CreateTextBox@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateTextBox

; 1411 : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	28					; 0000001cH
?CreateCounter@DISPLAY@@QAEPAVLAYER@@JJ_EPAD001@Z ENDP	; DISPLAY::CreateCounter
_TEXT	ENDS
PUBLIC	??_C@_0BD@PHM@SetCounter?3counter?$AA@		; `string'
PUBLIC	?SetCounter@DISPLAY@@QAE_NPAVLAYER@@PAD@Z	; DISPLAY::SetCounter
;	COMDAT ??_C@_0BD@PHM@SetCounter?3counter?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\layerutil.cpp
CONST	SEGMENT
??_C@_0BD@PHM@SetCounter?3counter?$AA@ DB 'SetCounter:counter', 00H ; `string'
CONST	ENDS
;	COMDAT ?SetCounter@DISPLAY@@QAE_NPAVLAYER@@PAD@Z
_TEXT	SEGMENT
_counter$ = 8
_text$ = 12
_this$ = -4
_slen$ = -8
_c_x$ = -12
?SetCounter@DISPLAY@@QAE_NPAVLAYER@@PAD@Z PROC NEAR	; DISPLAY::SetCounter, COMDAT

; 1415 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 76					; 0000004cH
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 1416 : 	FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);

	push	15781032				; 00f0cca8H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+228]
	push	ecx
	call	_DDColorMatch
	add	esp, 8
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+136], eax

; 1417 : 	if(	(e = counter->gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)

	mov	eax, DWORD PTR _this$[ebp]
	add	eax, 56					; 00000038H
	push	eax
	push	1024					; 00000400H
	push	0
	push	0
	push	0
	mov	ecx, DWORD PTR _counter$[ebp]
	mov	edx, DWORD PTR [ecx+144]
	mov	eax, DWORD PTR _counter$[ebp]
	mov	ecx, DWORD PTR [eax+144]
	mov	eax, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR [eax+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58784

; 1418 : 		return DDE("DrawLayers:FloodFill", e, "SetCounter:counter");

	push	OFFSET FLAT:??_C@_0BD@PHM@SetCounter?3counter?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BF@BJFJ@DrawLayers?3FloodFill?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L58776
$L58784:

; 1419 : 	
; 1420 : 	unsigned __int8 slen = strlen(text);

	mov	edx, DWORD PTR _text$[ebp]
	push	edx
	call	_strlen
	add	esp, 4
	mov	BYTE PTR _slen$[ebp], al

; 1421 : 	unsigned __int8 c_x = 0;

	mov	BYTE PTR _c_x$[ebp], 0

; 1422 : 	if( (counter->hAlign == AT_RIGHT) && (counter->NumDigits > slen))

	mov	eax, DWORD PTR _counter$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+5]
	cmp	ecx, 2
	jne	SHORT $L58788
	mov	edx, DWORD PTR _counter$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	mov	ecx, DWORD PTR _slen$[ebp]
	and	ecx, 255				; 000000ffH
	cmp	eax, ecx
	jle	SHORT $L58788

; 1423 : 		c_x = counter->ir.right - (slen*Font[counter->FontNum].cw);

	mov	edx, DWORD PTR _slen$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _counter$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+7]
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+188]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx*8]
	imul	edx, ebx
	mov	ecx, DWORD PTR _counter$[ebp]
	mov	eax, DWORD PTR [ecx+104]
	sub	eax, edx
	mov	BYTE PTR _c_x$[ebp], al

; 1424 : 	else if( (counter->hAlign == AT_CENTER) && (counter->NumDigits > slen) )

	jmp	SHORT $L58790
$L58788:
	mov	ecx, DWORD PTR _counter$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+5]
	test	edx, edx
	jne	SHORT $L58790
	mov	eax, DWORD PTR _counter$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+6]
	mov	edx, DWORD PTR _slen$[ebp]
	and	edx, 255				; 000000ffH
	cmp	ecx, edx
	jle	SHORT $L58790

; 1425 : 		c_x = (counter->ir.right - (slen*Font[counter->FontNum].cw)) >> 1;

	mov	eax, DWORD PTR _slen$[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _counter$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+7]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+188]
	xor	ebx, ebx
	mov	bl, BYTE PTR [ecx+edx*8]
	imul	eax, ebx
	mov	edx, DWORD PTR _counter$[ebp]
	mov	ecx, DWORD PTR [edx+104]
	sub	ecx, eax
	sar	ecx, 1
	mov	BYTE PTR _c_x$[ebp], cl
$L58790:

; 1426 : 
; 1427 : 	for(i = 0; (i < counter->NumDigits) && ( i < slen ); i++)

	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+232], 0
	jmp	SHORT $L58791
$L58792:
	mov	eax, DWORD PTR _this$[ebp]
	mov	cl, BYTE PTR [eax+232]
	add	cl, 1
	mov	edx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [edx+232], cl
$L58791:
	mov	eax, DWORD PTR _this$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+232]
	mov	edx, DWORD PTR _counter$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	cmp	ecx, eax
	jge	$L58793
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+232]
	mov	eax, DWORD PTR _slen$[ebp]
	and	eax, 255				; 000000ffH
	cmp	edx, eax
	jge	$L58793

; 1429 : 		r1.left = c_x + i*Font[counter->FontNum].cw;

	mov	ecx, DWORD PTR _c_x$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	mov	esi, eax
	mov	edx, DWORD PTR _counter$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+7]
	mov	edx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+188]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ebx*8]
	imul	esi, eax
	add	ecx, esi
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+256], ecx

; 1430 : 		r1.right = r1.left + Font[counter->FontNum].cw;

	mov	ecx, DWORD PTR _counter$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+7]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+188]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx*8]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+256]
	add	edx, eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+264], edx

; 1431 : 
; 1432 : 		r2.top = r1.top = 0;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+260], 0
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+276], 0

; 1433 : 		r2.bottom = r1.bottom = Font[counter->FontNum].ch;

	mov	eax, DWORD PTR _counter$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+7]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+188]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx*8+1]
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+268], edx
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+268]
	mov	DWORD PTR [ecx+284], eax

; 1434 : 		r2.left = (text[i] - 32)*(Font[counter->FontNum].cw);

	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+232]
	mov	eax, DWORD PTR _text$[ebp]
	movsx	ecx, BYTE PTR [eax+edx]
	sub	ecx, 32					; 00000020H
	mov	edx, DWORD PTR _counter$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+7]
	mov	edx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx+188]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax*8]
	imul	ecx, ebx
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+272], ecx

; 1435 : 		r2.right = r2.left + Font[counter->FontNum].cw;

	mov	ecx, DWORD PTR _counter$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+7]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+188]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+edx*8]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+272]
	add	edx, eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+280], edx

; 1436 : 
; 1437 : 		if(	(e = counter->gfx->Blt(&r1, Font[counter->FontNum].gfx, &r2,  DDBLT_KEYSRC, &FxBkg)) != DD_OK)

	mov	ecx, DWORD PTR _this$[ebp]
	add	ecx, 56					; 00000038H
	push	ecx
	push	32768					; 00008000H
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 272				; 00000110H
	push	edx
	mov	eax, DWORD PTR _counter$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+7]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+188]
	mov	ecx, DWORD PTR [eax+ecx*8+4]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	add	edx, 256				; 00000100H
	push	edx
	mov	eax, DWORD PTR _counter$[ebp]
	mov	ecx, DWORD PTR [eax+144]
	mov	edx, DWORD PTR _counter$[ebp]
	mov	eax, DWORD PTR [edx+144]
	mov	edx, DWORD PTR [eax]
	push	ecx
	call	DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L58795

; 1438 : 			return DDE("DrawLayers:Blt", e, "SetCounter:counter");

	push	OFFSET FLAT:??_C@_0BD@PHM@SetCounter?3counter?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0P@GENF@DrawLayers?3Blt?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	SHORT $L58776
$L58795:

; 1439 : 	}

	jmp	$L58792
$L58793:

; 1440 : 
; 1441 : 	counter->redraw = true;

	mov	edx, DWORD PTR _counter$[ebp]
	mov	BYTE PTR [edx+8], 1

; 1442 : 
; 1443 : 	return 0;

	xor	al, al
$L58776:

; 1444 : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?SetCounter@DISPLAY@@QAE_NPAVLAYER@@PAD@Z ENDP		; DISPLAY::SetCounter
_TEXT	ENDS
PUBLIC	??_C@_02MECO@?$CFd?$AA@				; `string'
PUBLIC	?SetCounter@DISPLAY@@QAE_NPAVLAYER@@_I@Z	; DISPLAY::SetCounter
;	COMDAT ??_C@_02MECO@?$CFd?$AA@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\layerutil.cpp
CONST	SEGMENT
??_C@_02MECO@?$CFd?$AA@ DB '%d', 00H			; `string'
CONST	ENDS
;	COMDAT ?SetCounter@DISPLAY@@QAE_NPAVLAYER@@_I@Z
_TEXT	SEGMENT
_counter$ = 8
_num$ = 12
_this$ = -4
_text$ = -8
$T59188 = -12
?SetCounter@DISPLAY@@QAE_NPAVLAYER@@_I@Z PROC NEAR	; DISPLAY::SetCounter, COMDAT

; 1448 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 76					; 0000004cH
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 1449 : 	char *text = new char[counter->NumDigits + 1];

	mov	eax, DWORD PTR _counter$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+6]
	add	ecx, 1
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59188[ebp], eax
	mov	edx, DWORD PTR $T59188[ebp]
	mov	DWORD PTR _text$[ebp], edx

; 1450 : 	sprintf(text, "%d", num);

	mov	eax, DWORD PTR _num$[ebp]
	push	eax
	push	OFFSET FLAT:??_C@_02MECO@?$CFd?$AA@	; `string'
	mov	ecx, DWORD PTR _text$[ebp]
	push	ecx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 1451 : 
; 1452 : 	SetCounter(counter, text );

	mov	edx, DWORD PTR _text$[ebp]
	push	edx
	mov	eax, DWORD PTR _counter$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetCounter@DISPLAY@@QAE_NPAVLAYER@@PAD@Z ; DISPLAY::SetCounter

; 1453 : 
; 1454 : 	return 0;

	xor	al, al

; 1455 : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?SetCounter@DISPLAY@@QAE_NPAVLAYER@@_I@Z ENDP		; DISPLAY::SetCounter
_TEXT	ENDS
PUBLIC	?DestroyLayer@DISPLAY@@QAEXPAVLAYER@@@Z		; DISPLAY::DestroyLayer
;	COMDAT ?DestroyLayer@DISPLAY@@QAEXPAVLAYER@@@Z
_TEXT	SEGMENT
_l$ = 8
_this$ = -4
?DestroyLayer@DISPLAY@@QAEXPAVLAYER@@@Z PROC NEAR	; DISPLAY::DestroyLayer, COMDAT

; 1458 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 1459 : 	if(l->prev == NULL)

	mov	eax, DWORD PTR _l$[ebp]
	cmp	DWORD PTR [eax+156], 0
	jne	SHORT $L58809

; 1461 : 		l->next->prev = NULL;

	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+160]
	mov	DWORD PTR [edx+156], 0

; 1462 : 		StartLayer = l->next;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+160]
	mov	DWORD PTR [eax+200], edx

; 1464 : 	else if(l->next == NULL)

	jmp	SHORT $L58812
$L58809:
	mov	eax, DWORD PTR _l$[ebp]
	cmp	DWORD PTR [eax+160], 0
	jne	SHORT $L58811

; 1466 : 		l->prev->next = NULL;

	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+156]
	mov	DWORD PTR [edx+160], 0

; 1467 : 		EndLayer = l->prev;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+156]
	mov	DWORD PTR [eax+204], edx

; 1469 : 	else

	jmp	SHORT $L58812
$L58811:

; 1471 : 		l->prev->next = l->next;

	mov	eax, DWORD PTR _l$[ebp]
	mov	ecx, DWORD PTR [eax+156]
	mov	edx, DWORD PTR _l$[ebp]
	mov	eax, DWORD PTR [edx+160]
	mov	DWORD PTR [ecx+160], eax

; 1472 : 		l->next->prev = l->prev;

	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+160]
	mov	eax, DWORD PTR _l$[ebp]
	mov	ecx, DWORD PTR [eax+156]
	mov	DWORD PTR [edx+156], ecx
$L58812:

; 1474 : 
; 1475 : 	if(l->type == LT_SPRITE)

	mov	edx, DWORD PTR _l$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+4]
	cmp	eax, 2
	jne	$L58813

; 1477 : 		for(a = l->startanim; a != NULL; a = a->next)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _l$[ebp]
	mov	eax, DWORD PTR [edx+152]
	mov	DWORD PTR [ecx+364], eax
	jmp	SHORT $L58814
$L58815:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+364]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+20]
	mov	DWORD PTR [eax+364], ecx
$L58814:
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+364], 0
	je	SHORT $L58816

; 1479 : 			for(c = a->startcel; c != NULL; c = c->next)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+368], eax
	jmp	SHORT $L58817
$L58818:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+20]
	mov	DWORD PTR [eax+368], ecx
$L58817:
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+368], 0
	je	SHORT $L58819

; 1481 : 				if(c->gfx)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+368]
	cmp	DWORD PTR [ecx+16], 0
	je	SHORT $L58820

; 1483 : 					c->gfx->Release();

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	ecx, DWORD PTR [eax+16]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+368]
	mov	edx, DWORD PTR [eax+16]
	mov	eax, DWORD PTR [edx]
	push	ecx
	call	DWORD PTR [eax+8]

; 1484 : 					c->gfx = NULL;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	mov	DWORD PTR [edx+16], 0
$L58820:

; 1486 : 			}				

	jmp	SHORT $L58818
$L58819:

; 1487 : 		}

	jmp	$L58815
$L58816:

; 1489 : 	else

	jmp	SHORT $L58821
$L58813:

; 1491 : 		if(l->gfx)

	mov	eax, DWORD PTR _l$[ebp]
	cmp	DWORD PTR [eax+144], 0
	je	SHORT $L58822

; 1492 : 			l->gfx->Release();

	mov	ecx, DWORD PTR _l$[ebp]
	mov	edx, DWORD PTR [ecx+144]
	mov	eax, DWORD PTR _l$[ebp]
	mov	ecx, DWORD PTR [eax+144]
	mov	eax, DWORD PTR [ecx]
	push	edx
	call	DWORD PTR [eax+8]
$L58822:

; 1493 : 
; 1494 : 		l->gfx = NULL;

	mov	ecx, DWORD PTR _l$[ebp]
	mov	DWORD PTR [ecx+144], 0
$L58821:

; 1496 : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?DestroyLayer@DISPLAY@@QAEXPAVLAYER@@@Z ENDP		; DISPLAY::DestroyLayer
_TEXT	ENDS
PUBLIC	?SetError_Format@ERRORCLASS@@QAEXPAD@Z		; ERRORCLASS::SetError_Format
PUBLIC	?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z	; ERRORCLASS::ReSetError_Format
PUBLIC	?Error@ERRORCLASS@@QAA_NPADZZ			; ERRORCLASS::Error
PUBLIC	??_C@_0DH@EMLF@Class?3?5?$CFs?5?$HM?$HM?5Function?3?5?$CFs?6Error?3@ ; `string'
PUBLIC	??_C@_0FA@CEOG@Unable?5to?5match?5primary?5surface?5@ ; `string'
PUBLIC	??_C@_07LGIJ@DISPLAY?$AA@			; `string'
PUBLIC	??_C@_0ED@JKGC@One?5or?5more?5of?5the?5caps?5bits?5pas@ ; `string'
PUBLIC	??_C@_0EF@LJOP@DirectDraw?5received?5a?5pointer?5th@ ; `string'
PUBLIC	??_C@_0EN@OLML@One?5or?5more?5of?5the?5parameters?5pa@ ; `string'
PUBLIC	??_C@_0CH@FCNI@Pixel?5format?5was?5invalid?5as?5spec@ ; `string'
PUBLIC	??_C@_0GI@HBFO@Operation?5could?5not?5be?5carried?5o@ ; `string'
PUBLIC	??_C@_0FK@LBPK@Create?5function?5called?5without?5D@ ; `string'
PUBLIC	??_C@_0GG@LFFD@A?5hardware?5only?5DirectDraw?5objec@ ; `string'
PUBLIC	??_C@_0CC@MBLC@Software?5emulation?5not?5available@ ; `string'
PUBLIC	??_C@_0GM@GGHG@Operation?5requires?5the?5applicati@ ; `string'
PUBLIC	??_C@_0CM@JALL@Flipping?5visible?5surfaces?5is?5not@ ; `string'
PUBLIC	??_C@_0GO@IMM@Operation?5could?5not?5be?5carried?5o@ ; `string'
PUBLIC	??_C@_0FM@INDP@Operation?5could?5not?5be?5carried?5o@ ; `string'
PUBLIC	??_C@_0EB@MKAC@DirectDraw?5does?5not?5have?5enough?5@ ; `string'
PUBLIC	??_C@_0DD@IGFL@This?5process?5already?5has?5created@ ; `string'
PUBLIC	??_C@_0DB@PJFD@The?5display?5is?5currently?5in?5an?5u@ ; `string'
PUBLIC	??_C@_0EH@DLMK@An?5exception?5was?5encountered?5whi@ ; `string'
PUBLIC	??_C@_0BB@FNBO@Generic?5failure?4?$AA@		; `string'
PUBLIC	??_C@_0CA@LBIE@Rectangle?5provided?5was?5invalid?4?$AA@ ; `string'
PUBLIC	??_C@_09DBDE@No?5blter?4?$AA@			; `string'
PUBLIC	??_C@_0GB@KBFD@Access?5to?5this?5surface?5is?5being?5@ ; `string'
PUBLIC	??_C@_0JP@HFMO@Access?5to?5this?5surface?5is?5being?5@ ; `string'
PUBLIC	??_C@_0BG@BGLN@Action?5not?5supported?4?$AA@	; `string'
PUBLIC	??_C@_0FI@IAJO@A?5DirectDraw?5object?5representing@ ; `string'
PUBLIC	??_C@_0FB@DPKI@The?5GUID?5passed?5to?5DirectDrawCre@ ; `string'
PUBLIC	??_C@_03NMFM@?$DP?$DP?$DP?$AA@			; `string'
;	COMDAT ??_C@_0DH@EMLF@Class?3?5?$CFs?5?$HM?$HM?5Function?3?5?$CFs?6Error?3@
; File d:\game programming\moggie software games\old code\old skull x\c++ files\layerutil.cpp
CONST	SEGMENT
??_C@_0DH@EMLF@Class?3?5?$CFs?5?$HM?$HM?5Function?3?5?$CFs?6Error?3@ DB 'C'
	DB	'lass: %s || Function: %s', 0aH, 'Error: %s(%d)', 0aH, 'Layer '
	DB	'name: %s', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_0FA@CEOG@Unable?5to?5match?5primary?5surface?5@
CONST	SEGMENT
??_C@_0FA@CEOG@Unable?5to?5match?5primary?5surface?5@ DB 'Unable to match'
	DB	' primary surface creation request with existing primary surfa'
	DB	'ce.', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_07LGIJ@DISPLAY?$AA@
CONST	SEGMENT
??_C@_07LGIJ@DISPLAY?$AA@ DB 'DISPLAY', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0ED@JKGC@One?5or?5more?5of?5the?5caps?5bits?5pas@
CONST	SEGMENT
??_C@_0ED@JKGC@One?5or?5more?5of?5the?5caps?5bits?5pas@ DB 'One or more o'
	DB	'f the caps bits passed to the callback are incorrect.', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0EF@LJOP@DirectDraw?5received?5a?5pointer?5th@
CONST	SEGMENT
??_C@_0EF@LJOP@DirectDraw?5received?5a?5pointer?5th@ DB 'DirectDraw recei'
	DB	'ved a pointer that was an invalid DIRECTDRAW object.', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0EN@OLML@One?5or?5more?5of?5the?5parameters?5pa@
CONST	SEGMENT
??_C@_0EN@OLML@One?5or?5more?5of?5the?5parameters?5pa@ DB 'One or more of'
	DB	' the parameters passed to the callback function are incorrect'
	DB	'.', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0CH@FCNI@Pixel?5format?5was?5invalid?5as?5spec@
CONST	SEGMENT
??_C@_0CH@FCNI@Pixel?5format?5was?5invalid?5as?5spec@ DB 'Pixel format wa'
	DB	's invalid as specified.', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0GI@HBFO@Operation?5could?5not?5be?5carried?5o@
CONST	SEGMENT
??_C@_0GI@HBFO@Operation?5could?5not?5be?5carried?5o@ DB 'Operation could'
	DB	' not be carried out because there is no alpha accleration har'
	DB	'dware present or available.', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0FK@LBPK@Create?5function?5called?5without?5D@
CONST	SEGMENT
??_C@_0FK@LBPK@Create?5function?5called?5without?5D@ DB 'Create function '
	DB	'called without DirectDraw object method SetCooperativeLevel b'
	DB	'eing called.', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_0GG@LFFD@A?5hardware?5only?5DirectDraw?5objec@
CONST	SEGMENT
??_C@_0GG@LFFD@A?5hardware?5only?5DirectDraw?5objec@ DB 'A hardware only '
	DB	'DirectDraw object creation was attempted but the driver did n'
	DB	'ot support any hardware.', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0CC@MBLC@Software?5emulation?5not?5available@
CONST	SEGMENT
??_C@_0CC@MBLC@Software?5emulation?5not?5available@ DB 'Software emulatio'
	DB	'n not available.', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0GM@GGHG@Operation?5requires?5the?5applicati@
CONST	SEGMENT
??_C@_0GM@GGHG@Operation?5requires?5the?5applicati@ DB 'Operation require'
	DB	's the application to have exclusive mode but the application '
	DB	'does not have exclusive mode.', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0CM@JALL@Flipping?5visible?5surfaces?5is?5not@
CONST	SEGMENT
??_C@_0CM@JALL@Flipping?5visible?5surfaces?5is?5not@ DB 'Flipping visible'
	DB	' surfaces is not supported.', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0GO@IMM@Operation?5could?5not?5be?5carried?5o@
CONST	SEGMENT
??_C@_0GO@IMM@Operation?5could?5not?5be?5carried?5o@ DB 'Operation could '
	DB	'not be carried out because there is no mip-map texture mappin'
	DB	'g hardware present or available.', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0FM@INDP@Operation?5could?5not?5be?5carried?5o@
CONST	SEGMENT
??_C@_0FM@INDP@Operation?5could?5not?5be?5carried?5o@ DB 'Operation could'
	DB	' not be carried out because there is no hardware support for '
	DB	'zbuffer blting.', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0EB@MKAC@DirectDraw?5does?5not?5have?5enough?5@
CONST	SEGMENT
??_C@_0EB@MKAC@DirectDraw?5does?5not?5have?5enough?5@ DB 'DirectDraw does'
	DB	' not have enough memory to perform the operation.', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0DD@IGFL@This?5process?5already?5has?5created@
CONST	SEGMENT
??_C@_0DD@IGFL@This?5process?5already?5has?5created@ DB 'This process alr'
	DB	'eady has created a primary surface', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0DB@PJFD@The?5display?5is?5currently?5in?5an?5u@
CONST	SEGMENT
??_C@_0DB@PJFD@The?5display?5is?5currently?5in?5an?5u@ DB 'The display is'
	DB	' currently in an unsupported mode.', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0EH@DLMK@An?5exception?5was?5encountered?5whi@
CONST	SEGMENT
??_C@_0EH@DLMK@An?5exception?5was?5encountered?5whi@ DB 'An exception was'
	DB	' encountered while performing the requested operation.', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@FNBO@Generic?5failure?4?$AA@
CONST	SEGMENT
??_C@_0BB@FNBO@Generic?5failure?4?$AA@ DB 'Generic failure.', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0CA@LBIE@Rectangle?5provided?5was?5invalid?4?$AA@
CONST	SEGMENT
??_C@_0CA@LBIE@Rectangle?5provided?5was?5invalid?4?$AA@ DB 'Rectangle pro'
	DB	'vided was invalid.', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_09DBDE@No?5blter?4?$AA@
CONST	SEGMENT
??_C@_09DBDE@No?5blter?4?$AA@ DB 'No blter.', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0GB@KBFD@Access?5to?5this?5surface?5is?5being?5@
CONST	SEGMENT
??_C@_0GB@KBFD@Access?5to?5this?5surface?5is?5being?5@ DB 'Access to this'
	DB	' surface is being refused because the surface is already lock'
	DB	'ed by another thread.', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0JP@HFMO@Access?5to?5this?5surface?5is?5being?5@
CONST	SEGMENT
??_C@_0JP@HFMO@Access?5to?5this?5surface?5is?5being?5@ DB 'Access to this'
	DB	' surface is being refused because the surface is gone.', 0aH, ' '
	DB	'The DIRECTDRAWSURFACE object representing this surface should'
	DB	' have Restore called on it.', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BG@BGLN@Action?5not?5supported?4?$AA@
CONST	SEGMENT
??_C@_0BG@BGLN@Action?5not?5supported?4?$AA@ DB 'Action not supported.', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0FI@IAJO@A?5DirectDraw?5object?5representing@
CONST	SEGMENT
??_C@_0FI@IAJO@A?5DirectDraw?5object?5representing@ DB 'A DirectDraw obje'
	DB	'ct representing this driver has already been created for this'
	DB	' process.', 00H				; `string'
CONST	ENDS
;	COMDAT ??_C@_0FB@DPKI@The?5GUID?5passed?5to?5DirectDrawCre@
CONST	SEGMENT
??_C@_0FB@DPKI@The?5GUID?5passed?5to?5DirectDrawCre@ DB 'The GUID passed '
	DB	'to DirectDrawCreate is not a valid DirectDraw driver identifi'
	DB	'er.', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_03NMFM@?$DP?$DP?$DP?$AA@
CONST	SEGMENT
??_C@_03NMFM@?$DP?$DP?$DP?$AA@ DB '???', 00H		; `string'
CONST	ENDS
;	COMDAT ?DDE@DISPLAY@@QAE_NPADJ0@Z
_TEXT	SEGMENT
_n$ = 8
_e1$ = 12
_name$ = 16
_this$ = -4
?DDE@DISPLAY@@QAE_NPADJ0@Z PROC NEAR			; DISPLAY::DDE, COMDAT

; 1502 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 1503 : 	SetError_Format("Class: %s || Function: %s\nError: %s(%d)\nLayer name: %s");

	push	OFFSET FLAT:??_C@_0DH@EMLF@Class?3?5?$CFs?5?$HM?$HM?5Function?3?5?$CFs?6Error?3@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetError_Format@ERRORCLASS@@QAEXPAD@Z	; ERRORCLASS::SetError_Format

; 1504 : 
; 1505 : 	if(DDERR_INCOMPATIBLEPRIMARY)

	mov	eax, -2005532577			; 8876005fH
	test	eax, eax
	je	SHORT $L58834

; 1506 : 		Error(NULL, "DISPLAY", n, "Unable to match primary surface creation request with existing primary surface.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0FA@CEOG@Unable?5to?5match?5primary?5surface?5@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1507 : 
; 1508 : 	else if(DDERR_INVALIDCAPS)

	jmp	$L58999
$L58834:
	mov	eax, -2005532572			; 88760064H
	test	eax, eax
	je	SHORT $L58842

; 1509 : 		Error(NULL, "DISPLAY", n, "One or more of the caps bits passed to the callback are incorrect.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0ED@JKGC@One?5or?5more?5of?5the?5caps?5bits?5pas@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1510 : 
; 1511 : 	else if(DDERR_INVALIDOBJECT)

	jmp	$L58999
$L58842:
	mov	eax, -2005532542			; 88760082H
	test	eax, eax
	je	SHORT $L58849

; 1512 : 		Error(NULL, "DISPLAY", n, "DirectDraw received a pointer that was an invalid DIRECTDRAW object.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0EF@LJOP@DirectDraw?5received?5a?5pointer?5th@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1513 : 
; 1514 : 	else if(DDERR_INVALIDPARAMS)

	jmp	$L58999
$L58849:
	mov	eax, -2147024809			; 80070057H
	test	eax, eax
	je	SHORT $L58853

; 1515 : 		Error(NULL, "DISPLAY", n, "One or more of the parameters passed to the callback function are incorrect.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0EN@OLML@One?5or?5more?5of?5the?5parameters?5pa@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1516 : 
; 1517 : 	else if(DDERR_INVALIDPIXELFORMAT)

	jmp	$L58999
$L58853:
	mov	eax, -2005532527			; 88760091H
	test	eax, eax
	je	SHORT $L58860

; 1518 : 		Error(NULL, "DISPLAY", n, "Pixel format was invalid as specified.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0CH@FCNI@Pixel?5format?5was?5invalid?5as?5spec@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1519 : 
; 1520 : 	else if(DDERR_NOALPHAHW)

	jmp	$L58999
$L58860:
	mov	eax, -2005532492			; 887600b4H
	test	eax, eax
	je	SHORT $L58867

; 1521 : 		Error(NULL, "DISPLAY", n, "Operation could not be carried out because there is no alpha accleration hardware present or available.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0GI@HBFO@Operation?5could?5not?5be?5carried?5o@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1522 : 
; 1523 : 	else if(DDERR_NOCOOPERATIVELEVELSET)

	jmp	$L58999
$L58867:
	mov	eax, -2005532460			; 887600d4H
	test	eax, eax
	je	SHORT $L58874

; 1524 : 		Error(NULL, "DISPLAY", n, "Create function called without DirectDraw object method SetCooperativeLevel being called.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0FK@LBPK@Create?5function?5called?5without?5D@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1525 : 
; 1526 : 	else if(DDERR_NODIRECTDRAWHW)

	jmp	$L58999
$L58874:
	mov	eax, -2005532109			; 88760233H
	test	eax, eax
	je	SHORT $L58881

; 1527 : 		Error(NULL, "DISPLAY", n, "A hardware only DirectDraw object creation was attempted but the driver did not support any hardware.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0GG@LFFD@A?5hardware?5only?5DirectDraw?5objec@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1528 : 
; 1529 : 	else if(DDERR_NOEMULATION)

	jmp	$L58999
$L58881:
	mov	eax, -2005532107			; 88760235H
	test	eax, eax
	je	SHORT $L58888

; 1530 : 		Error(NULL, "DISPLAY", n, "Software emulation not available.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0CC@MBLC@Software?5emulation?5not?5available@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1531 : 
; 1532 : 	else if(DDERR_NOEXCLUSIVEMODE)

	jmp	$L58999
$L58888:
	mov	eax, -2005532447			; 887600e1H
	test	eax, eax
	je	SHORT $L58895

; 1533 : 		Error(NULL, "DISPLAY", n, "Operation requires the application to have exclusive mode but the application does not have exclusive mode.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0GM@GGHG@Operation?5requires?5the?5applicati@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1534 : 
; 1535 : 	else if(DDERR_NOFLIPHW)

	jmp	$L58999
$L58895:
	mov	eax, -2005532442			; 887600e6H
	test	eax, eax
	je	SHORT $L58902

; 1536 : 		Error(NULL, "DISPLAY", n, "Flipping visible surfaces is not supported.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0CM@JALL@Flipping?5visible?5surfaces?5is?5not@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1537 : 
; 1538 : 	else if(DDERR_NOMIPMAPHW)

	jmp	$L58999
$L58902:
	mov	eax, -2005532081			; 8876024fH
	test	eax, eax
	je	SHORT $L58909

; 1539 : 		Error(NULL, "DISPLAY", n, "Operation could not be carried out because there is no mip-map texture mapping hardware present or available.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0GO@IMM@Operation?5could?5not?5be?5carried?5o@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1540 : 
; 1541 : 	else if(DDERR_NOZBUFFERHW)

	jmp	$L58999
$L58909:
	mov	eax, -2005532332			; 88760154H
	test	eax, eax
	je	SHORT $L58916

; 1542 : 		Error(NULL, "DISPLAY", n, "Operation could not be carried out because there is no hardware support for zbuffer blting.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0FM@INDP@Operation?5could?5not?5be?5carried?5o@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1543 : 
; 1544 : 	else if(DDERR_OUTOFMEMORY)

	jmp	$L58999
$L58916:
	mov	eax, -2147024882			; 8007000eH
	test	eax, eax
	je	SHORT $L58920

; 1545 : 		Error(NULL, "DISPLAY", n, "DirectDraw does not have enough memory to perform the operation.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0EB@MKAC@DirectDraw?5does?5not?5have?5enough?5@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1546 : 
; 1547 : 	else if(DDERR_OUTOFVIDEOMEMORY)

	jmp	$L58999
$L58920:
	mov	eax, -2005532292			; 8876017cH
	test	eax, eax
	je	SHORT $L58927

; 1548 : 		Error(NULL, "DISPLAY", n, "DirectDraw does not have enough memory to perform the operation.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0EB@MKAC@DirectDraw?5does?5not?5have?5enough?5@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1549 : 
; 1550 : 	else if(DDERR_PRIMARYSURFACEALREADYEXISTS)

	jmp	$L58999
$L58927:
	mov	eax, -2005532108			; 88760234H
	test	eax, eax
	je	SHORT $L58933

; 1551 : 		Error(NULL, "DISPLAY", n, "This process already has created a primary surface", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0DD@IGFL@This?5process?5already?5has?5created@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1552 : 
; 1553 : 	else if(DDERR_UNSUPPORTEDMODE)

	jmp	$L58999
$L58933:
	mov	eax, -2005532082			; 8876024eH
	test	eax, eax
	je	SHORT $L58940

; 1554 : 		Error(NULL, "DISPLAY", n, "The display is currently in an unsupported mode.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0DB@PJFD@The?5display?5is?5currently?5in?5an?5u@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1555 : 
; 1556 : 	else if(DDERR_EXCEPTION)

	jmp	$L58999
$L58940:
	mov	eax, -2005532617			; 88760037H
	test	eax, eax
	je	SHORT $L58947

; 1557 : 		Error(NULL, "DISPLAY", n, "An exception was encountered while performing the requested operation.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0EH@DLMK@An?5exception?5was?5encountered?5whi@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1558 : 		
; 1559 : 	else if(DDERR_GENERIC)

	jmp	$L58999
$L58947:
	mov	eax, -2147467259			; 80004005H
	test	eax, eax
	je	SHORT $L58951

; 1560 : 		Error(NULL, "DISPLAY", n, "Generic failure.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0BB@FNBO@Generic?5failure?4?$AA@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1561 : 	
; 1562 : 	else if(DDERR_INVALIDRECT)

	jmp	$L58999
$L58951:
	mov	eax, -2005532522			; 88760096H
	test	eax, eax
	je	SHORT $L58958

; 1563 : 		Error(NULL, "DISPLAY", n, "Rectangle provided was invalid.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0CA@LBIE@Rectangle?5provided?5was?5invalid?4?$AA@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1564 : 	
; 1565 : 	else if(DDERR_NOBLTHW)

	jmp	$L58999
$L58958:
	mov	eax, -2005532097			; 8876023fH
	test	eax, eax
	je	SHORT $L58965

; 1566 : 		Error(NULL, "DISPLAY", n, "No blter.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_09DBDE@No?5blter?4?$AA@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1567 : 	
; 1568 : 	else if(DDERR_SURFACEBUSY)

	jmp	$L58999
$L58965:
	mov	eax, -2005532242			; 887601aeH
	test	eax, eax
	je	SHORT $L58972

; 1569 : 		Error(NULL, "DISPLAY", n, "Access to this surface is being refused because the surface is already locked by another thread.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0GB@KBFD@Access?5to?5this?5surface?5is?5being?5@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1570 : 	
; 1571 : 	else if(DDERR_SURFACELOST)

	jmp	$L58999
$L58972:
	mov	eax, -2005532222			; 887601c2H
	test	eax, eax
	je	SHORT $L58979

; 1572 : 		Error(NULL, "DISPLAY", n, "Access to this surface is being refused because the surface is gone.\n The DIRECTDRAWSURFACE object representing this surface should have Restore called on it.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0JP@HFMO@Access?5to?5this?5surface?5is?5being?5@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1573 : 	
; 1574 : 	else if(DDERR_UNSUPPORTED)

	jmp	$L58999
$L58979:
	mov	eax, -2147467263			; 80004001H
	test	eax, eax
	je	SHORT $L58983

; 1575 : 		Error(NULL, "DISPLAY", n, "Action not supported.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0BG@BGLN@Action?5not?5supported?4?$AA@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1576 : 
; 1577 : 	else if(DDERR_DIRECTDRAWALREADYCREATED)

	jmp	$L58999
$L58983:
	mov	eax, -2005532110			; 88760232H
	test	eax, eax
	je	SHORT $L58990

; 1578 : 		Error(NULL, "DISPLAY", n, "A DirectDraw object representing this driver has already been created for this process.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0FI@IAJO@A?5DirectDraw?5object?5representing@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1579 : 	
; 1580 : 	else if(DDERR_INVALIDDIRECTDRAWGUID)

	jmp	SHORT $L58999
$L58990:
	mov	eax, -2005532111			; 88760231H
	test	eax, eax
	je	SHORT $L58997

; 1581 : 		Error(NULL, "DISPLAY", n, "The GUID passed to DirectDrawCreate is not a valid DirectDraw driver identifier.", e, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	push	OFFSET FLAT:??_C@_0FB@DPKI@The?5GUID?5passed?5to?5DirectDrawCre@ ; `string'
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	push	edx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH

; 1582 : 
; 1583 : 	else

	jmp	SHORT $L58999
$L58997:

; 1584 : 		Error(NULL, "DISPLAY", n, "???", e, name);

	mov	eax, DWORD PTR _name$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	push	OFFSET FLAT:??_C@_03NMFM@?$DP?$DP?$DP?$AA@ ; `string'
	mov	eax, DWORD PTR _n$[ebp]
	push	eax
	push	OFFSET FLAT:??_C@_07LGIJ@DISPLAY?$AA@	; `string'
	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	push	ecx
	call	?Error@ERRORCLASS@@QAA_NPADZZ		; ERRORCLASS::Error
	add	esp, 28					; 0000001cH
$L58999:

; 1585 : 
; 1586 : 	ReSetError_Format();

	push	0
	mov	ecx, DWORD PTR _this$[ebp]
	call	?ReSetError_Format@ERRORCLASS@@QAE_N_N@Z ; ERRORCLASS::ReSetError_Format

; 1587 : 	return (e1 != 0) ? 1 : 0;

	xor	eax, eax
	cmp	DWORD PTR _e1$[ebp], 0
	setne	al

; 1588 : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	12					; 0000000cH
?DDE@DISPLAY@@QAE_NPADJ0@Z ENDP				; DISPLAY::DDE
_TEXT	ENDS
PUBLIC	??_C@_00A@?$AA@					; `string'
;	COMDAT ??_C@_00A@?$AA@
; File d:\game programming\moggie software games\old code\old skull x\header files\errorclass.h
CONST	SEGMENT
??_C@_00A@?$AA@ DB 00H					; `string'
CONST	ENDS
;	COMDAT ?SetError_Format@ERRORCLASS@@QAEXPAD@Z
_TEXT	SEGMENT
_m$ = 8
_this$ = -4
$T59195 = -8
$T59196 = -12
$T59197 = -16
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
	je	SHORT $L57613

; 81   : 				PrevMsgFormat = new char[strlen(MsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59195[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T59195[ebp]
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
$L57613:

; 84   : 
; 85   : 			if(m != NULL)

	cmp	DWORD PTR _m$[ebp], 0
	je	SHORT $L57616

; 87   : 				MsgFormat = new char[strlen(m)];

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59196[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T59196[ebp]
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

	jmp	SHORT $L57619
$L57616:

; 92   : 				MsgFormat = new char[2];

	push	2
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59197[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T59197[ebp]
	mov	DWORD PTR [eax], ecx

; 93   : 				strcpy(MsgFormat, "");

	push	OFFSET FLAT:??_C@_00A@?$AA@		; `string'
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_strcpy
	add	esp, 8
$L57619:

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
$T59200 = -8
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
	je	SHORT $L57625

; 101  : 				MsgFormat = new char[strlen(PrevMsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59200[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T59200[ebp]
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
$L57625:

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
$T59203 = -268
$T59204 = -272
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
	je	SHORT $L57632

; 114  : 				if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L57633

; 116  : 					PrevMsgFormat = new char[strlen(MsgFormat)];

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59203[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T59203[ebp]
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
$L57633:

; 119  : 
; 120  : 				MsgFormat = new char[strlen(m)];

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T59204[ebp], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR $T59204[ebp]
	mov	DWORD PTR [ecx], edx

; 121  : 				strcpy(MsgFormat, m);

	mov	eax, DWORD PTR _m$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8
$L57632:

; 123  : 
; 124  : 			if(MsgFormat != NULL)

	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L57638

; 126  : 				if(strlen(MsgFormat) > 0)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strlen
	add	esp, 4
	test	eax, eax
	jbe	SHORT $L57639

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

	jmp	SHORT $L57644
$L57639:

; 133  : 					strcpy(mTemp, "Problem with error message.");

	push	OFFSET FLAT:??_C@_0BM@JPJE@Problem?5with?5error?5message?4?$AA@ ; `string'
	lea	edx, DWORD PTR _mTemp$[ebp]
	push	edx
	call	_strcpy
	add	esp, 8
$L57644:

; 135  : 			else

	jmp	SHORT $L57646
$L57638:

; 136  : 				return 1;

	mov	al, 1
	jmp	$L57653
$L57646:

; 137  : 
; 138  : 			if(Type < 0)

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	and	ecx, 3
	test	ecx, ecx
	jae	SHORT $L57647

; 139  : 				Type = 0;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	al, -4					; fffffffcH
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+8], eax
$L57647:

; 140  : 			
; 141  : 			if(hWnd == NULL)

	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+12], 0
	jne	SHORT $L57648

; 142  : 				hWnd = GetDesktopWindow();

	call	DWORD PTR __imp__GetDesktopWindow@0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L57648:

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
	je	SHORT $L57652
	cmp	DWORD PTR _Ok$[ebp], 7
	je	SHORT $L57652
	cmp	DWORD PTR _Ok$[ebp], 2
	jne	SHORT $L57651
$L57652:

; 147  : 				return 1;

	mov	al, 1
	jmp	SHORT $L57653
$L57651:

; 149  : 				return 0;

	xor	al, al
$L57653:

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
	jne	SHORT $L57572

; 32   : 				return MB_OK;

	xor	eax, eax
	jmp	SHORT $L57577
$L57572:

; 33   : 			else if(Type == ETYPE_YESNO)

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	eax, 3
	cmp	eax, 1
	jne	SHORT $L57574

; 34   : 				return MB_YESNO;

	mov	eax, 4
	jmp	SHORT $L57577
$L57574:

; 35   : 			else if(Type == ETYPE_RETRY)

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	and	edx, 3
	cmp	edx, 2
	jne	SHORT $L57576

; 36   : 				return MB_RETRYCANCEL;

	mov	eax, 5
	jmp	SHORT $L57577
$L57576:

; 38   : 				return MB_OK;

	xor	eax, eax
$L57577:

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
