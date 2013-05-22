	TITLE	D:\Game Programming\working Skull X\C++ Files\LoadGfx.cpp
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
;	COMDAT ??_C@_0P@CLI@gfx?2cursor?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@LLOH@gfx?2select_scrn?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_03HCBO@Bkg?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0FM@EIIL@Please?0?5make?5a?5selection?5using?5t@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04BNNJ@Text?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04PGNC@Tile?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@INDM@gfx?2tile01?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04BCJN@Win1?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_01FCOA@?5?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@JEEK@gfx?2mywin_tm?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@PHMP@gfx?2mywin_tr?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@FGMM@gfx?2mywin_ml?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@JFGM@gfx?2mywin_mr?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@BDKN@gfx?2mywin_bl?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@LDII@gfx?2mywin_bm?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@NAAN@gfx?2mywin_br?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BA@JPDC@gfx?2mytab_l?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BA@DPBH@gfx?2mytab_m?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BA@FMJC@gfx?2mytab_r?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0M@IMGB@save_Title1?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0M@GGJA@Save?5Game?5?5?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0M@JIIH@load_Title1?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0M@HCHG@Load?5Game?5?5?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05KNBK@Text1?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0DA@KKIK@SN?5Lvl?3?5?5?5?5?5hrs?5min?5sec?5RN?5Lvl?3?5@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05EFOO@File1?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_07ECCJ@No?5File?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04JDGB@Back?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0N@MBOA@gfx?2back?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@EMPP@gfx?2map_tile1?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05HPB@Tile1?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@KMJA@gfx?2map_tile2?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05PIEI@Tile2?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_03DIFO@Map?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@PHHP@gfx?2water_tile?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@GPMI@gfx?2village_tile?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@PIJ@gfx?2desert_tile?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@FCCB@gfx?2grasslands_tile?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@HDAC@gfx?2forest_tile?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@OAIF@gfx?2camp_tile1?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@BFGG@gfx?2safe_tile?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@CNMC@gfx?2bridge_tile?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@DMFI@gfx?2mountain?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0P@LGEO@gfx?2cavern?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04HGOJ@Camp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04OLBH@fire?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@OK@gfx?2camp_tile2?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@KAMP@gfx?2camp_tile3?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_06DJMK@RedGoo?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04IBJ@walk?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@PCC@gfx?2red_goo1?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@OPEN@gfx?2red_goo2?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_07NIEJ@BlueGoo?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@PIDO@gfx?2blue_goo1?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@BIFB@gfx?2blue_goo2?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05COAO@Super?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BA@JLOJ@gfx?2sn_map1?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BA@HLIG@gfx?2sn_map2?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04FKLJ@menu?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BB@DCJH@gfx?2map_menu?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05LCII@sStat?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BJ@GKNC@gfx?2sninja_stat_menu?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05BCKN@rStat?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BG@CHBC@gfx?2red_stat_menu?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04LEEA@sPic?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@BHAO@gfx?2sninja_pic?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04JBBC@rPic?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BA@FPGN@gfx?2red_pic?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0N@LOKF@gfx?2dark?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04IPGD@gray?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BG@KCBA@gfx?2fight?2land01a?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05MCMJ@LandA?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BG@ECHP@gfx?2fight?2land01b?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05DNHA@LandB?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BC@CLF@gfx?2fight?2tab?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_03CHMJ@Tab?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04LFF@Lupi?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@IOKG@gfx?2fight?2lupi1?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@GOMJ@gfx?2fight?2lupi2?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BE@MOOM@gfx?2fight?2lupi3?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_05KAIJ@Stand?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@PBLI@gfx?2fight?2sn_st2?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@BBNH@gfx?2fight?2sn_st1?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_03GOGG@Red?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@HOHK@gfx?2fight?2rn_st2?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BF@JOBF@gfx?2fight?2rn_st1?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0N@BPDI@gfx?2hand?4bmp?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_04LFM@Hand?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0L@CLNN@Load?5Mouse?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BD@LIDO@Set?5ColorKey?5Mouse?$AA@
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
;	COMDAT ??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@
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
;	COMDAT ?SetSize@MOUSE@@QAEXJJ@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetPos@MOUSE@@QAEXJJ@Z
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
;	COMDAT ?sLoop@VALUES@@QAE_NAAPAXPAD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?cLoop@VALUES@@QAE_NAAPAXP6GKPAX@ZPADH1@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?SetArray@@YAXPAPA_EPA_E_G@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?LoadGfx@DISPLAY@@QAEPAUGFX_LAYER_INFO@@PAD@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
;	COMDAT ?TransferGfx@DISPLAY@@QAE_NPAUGFX_LAYER_INFO@@@Z
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	?SetArray@@YAXPAPA_EPA_E_G@Z			; SetArray
EXTRN	??2@YAPAXI@Z:NEAR				; operator new
EXTRN	_memset:NEAR
;	COMDAT ?SetArray@@YAXPAPA_EPA_E_G@Z
_TEXT	SEGMENT
_d$ = 8
_a$ = 12
_w$ = 16
_k$ = -4
$T65331 = -8
?SetArray@@YAXPAPA_EPA_E_G@Z PROC NEAR			; SetArray, COMDAT

; 24   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi

; 25   : 	d[0] = new unsigned __int8[w];

	mov	eax, DWORD PTR _w$[ebp]
	and	eax, 65535				; 0000ffffH
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65331[ebp], eax
	mov	ecx, DWORD PTR _d$[ebp]
	mov	edx, DWORD PTR $T65331[ebp]
	mov	DWORD PTR [ecx], edx

; 26   : 	ZeroMemory(d[0], w*sizeof(unsigned char) );

	mov	eax, DWORD PTR _w$[ebp]
	and	eax, 65535				; 0000ffffH
	push	eax
	push	0
	mov	ecx, DWORD PTR _d$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 27   : 
; 28   : 	unsigned __int8 k;
; 29   : 	for(k = 0; k < w; k++)

	mov	BYTE PTR _k$[ebp], 0
	jmp	SHORT $L64932
$L64933:
	mov	al, BYTE PTR _k$[ebp]
	add	al, 1
	mov	BYTE PTR _k$[ebp], al
$L64932:
	mov	ecx, DWORD PTR _k$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	ecx, edx
	jge	SHORT $L64934

; 30   : 		d[0][k] = a[k];

	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _k$[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _d$[ebp]
	mov	edx, DWORD PTR [edx]
	mov	esi, DWORD PTR _a$[ebp]
	mov	al, BYTE PTR [esi+eax]
	mov	BYTE PTR [edx+ecx], al
	jmp	SHORT $L64933
$L64934:

; 31   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?SetArray@@YAXPAPA_EPA_E_G@Z ENDP			; SetArray
_TEXT	ENDS
PUBLIC	??_C@_0P@CLI@gfx?2cursor?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BE@LLOH@gfx?2select_scrn?4bmp?$AA@	; `string'
PUBLIC	??_C@_03HCBO@Bkg?$AA@				; `string'
PUBLIC	??_C@_0FM@EIIL@Please?0?5make?5a?5selection?5using?5t@ ; `string'
PUBLIC	??_C@_04BNNJ@Text?$AA@				; `string'
PUBLIC	??_C@_04PGNC@Tile?$AA@				; `string'
PUBLIC	??_C@_0P@INDM@gfx?2tile01?4bmp?$AA@		; `string'
PUBLIC	??_C@_04BCJN@Win1?$AA@				; `string'
PUBLIC	??_C@_01FCOA@?5?$AA@				; `string'
PUBLIC	??_C@_0BB@JEEK@gfx?2mywin_tm?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BB@PHMP@gfx?2mywin_tr?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BB@FGMM@gfx?2mywin_ml?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BB@JFGM@gfx?2mywin_mr?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BB@BDKN@gfx?2mywin_bl?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BB@LDII@gfx?2mywin_bm?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BB@NAAN@gfx?2mywin_br?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BA@JPDC@gfx?2mytab_l?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BA@DPBH@gfx?2mytab_m?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BA@FMJC@gfx?2mytab_r?4bmp?$AA@		; `string'
PUBLIC	??_C@_0M@IMGB@save_Title1?$AA@			; `string'
PUBLIC	??_C@_0M@GGJA@Save?5Game?5?5?$AA@		; `string'
PUBLIC	??_C@_0M@JIIH@load_Title1?$AA@			; `string'
PUBLIC	??_C@_0M@HCHG@Load?5Game?5?5?$AA@		; `string'
PUBLIC	??_C@_05KNBK@Text1?$AA@				; `string'
PUBLIC	??_C@_0DA@KKIK@SN?5Lvl?3?5?5?5?5?5hrs?5min?5sec?5RN?5Lvl?3?5@ ; `string'
PUBLIC	??_C@_05EFOO@File1?$AA@				; `string'
PUBLIC	??_C@_07ECCJ@No?5File?$AA@			; `string'
PUBLIC	??_C@_04JDGB@Back?$AA@				; `string'
PUBLIC	??_C@_0N@MBOA@gfx?2back?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BC@EMPP@gfx?2map_tile1?4bmp?$AA@		; `string'
PUBLIC	??_C@_05HPB@Tile1?$AA@				; `string'
PUBLIC	??_C@_0BC@KMJA@gfx?2map_tile2?4bmp?$AA@		; `string'
PUBLIC	??_C@_05PIEI@Tile2?$AA@				; `string'
PUBLIC	??_C@_03DIFO@Map?$AA@				; `string'
PUBLIC	??_C@_0BD@PHHP@gfx?2water_tile?4bmp?$AA@	; `string'
PUBLIC	??_C@_0BF@GPMI@gfx?2village_tile?4bmp?$AA@	; `string'
PUBLIC	??_C@_0BE@PIJ@gfx?2desert_tile?4bmp?$AA@	; `string'
PUBLIC	??_C@_0BI@FCCB@gfx?2grasslands_tile?4bmp?$AA@	; `string'
PUBLIC	??_C@_0BE@HDAC@gfx?2forest_tile?4bmp?$AA@	; `string'
PUBLIC	??_C@_0BD@OAIF@gfx?2camp_tile1?4bmp?$AA@	; `string'
PUBLIC	??_C@_0BC@BFGG@gfx?2safe_tile?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BE@CNMC@gfx?2bridge_tile?4bmp?$AA@	; `string'
PUBLIC	??_C@_0BB@DMFI@gfx?2mountain?4bmp?$AA@		; `string'
PUBLIC	??_C@_0P@LGEO@gfx?2cavern?4bmp?$AA@		; `string'
PUBLIC	??_C@_04HGOJ@Camp?$AA@				; `string'
PUBLIC	??_C@_04OLBH@fire?$AA@				; `string'
PUBLIC	??_C@_0BD@OK@gfx?2camp_tile2?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BD@KAMP@gfx?2camp_tile3?4bmp?$AA@	; `string'
PUBLIC	??_C@_06DJMK@RedGoo?$AA@			; `string'
PUBLIC	??_C@_04IBJ@walk?$AA@				; `string'
PUBLIC	??_C@_0BB@PCC@gfx?2red_goo1?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BB@OPEN@gfx?2red_goo2?4bmp?$AA@		; `string'
PUBLIC	??_C@_07NIEJ@BlueGoo?$AA@			; `string'
PUBLIC	??_C@_0BC@PIDO@gfx?2blue_goo1?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BC@BIFB@gfx?2blue_goo2?4bmp?$AA@		; `string'
PUBLIC	??_C@_05COAO@Super?$AA@				; `string'
PUBLIC	??_C@_0BA@JLOJ@gfx?2sn_map1?4bmp?$AA@		; `string'
PUBLIC	??_C@_0BA@HLIG@gfx?2sn_map2?4bmp?$AA@		; `string'
PUBLIC	??_C@_04FKLJ@menu?$AA@				; `string'
PUBLIC	??_C@_0BB@DCJH@gfx?2map_menu?4bmp?$AA@		; `string'
PUBLIC	??_C@_05LCII@sStat?$AA@				; `string'
PUBLIC	??_C@_0BJ@GKNC@gfx?2sninja_stat_menu?4bmp?$AA@	; `string'
PUBLIC	??_C@_05BCKN@rStat?$AA@				; `string'
PUBLIC	??_C@_0BG@CHBC@gfx?2red_stat_menu?4bmp?$AA@	; `string'
PUBLIC	??_C@_04LEEA@sPic?$AA@				; `string'
PUBLIC	??_C@_0BD@BHAO@gfx?2sninja_pic?4bmp?$AA@	; `string'
PUBLIC	??_C@_04JBBC@rPic?$AA@				; `string'
PUBLIC	??_C@_0BA@FPGN@gfx?2red_pic?4bmp?$AA@		; `string'
PUBLIC	??_C@_0N@LOKF@gfx?2dark?4bmp?$AA@		; `string'
PUBLIC	??_C@_04IPGD@gray?$AA@				; `string'
PUBLIC	??_C@_0BG@KCBA@gfx?2fight?2land01a?4bmp?$AA@	; `string'
PUBLIC	??_C@_05MCMJ@LandA?$AA@				; `string'
PUBLIC	??_C@_0BG@ECHP@gfx?2fight?2land01b?4bmp?$AA@	; `string'
PUBLIC	??_C@_05DNHA@LandB?$AA@				; `string'
PUBLIC	??_C@_0BC@CLF@gfx?2fight?2tab?4bmp?$AA@		; `string'
PUBLIC	??_C@_03CHMJ@Tab?$AA@				; `string'
PUBLIC	??_C@_04LFF@Lupi?$AA@				; `string'
PUBLIC	??_C@_0BE@IOKG@gfx?2fight?2lupi1?4bmp?$AA@	; `string'
PUBLIC	??_C@_0BE@GOMJ@gfx?2fight?2lupi2?4bmp?$AA@	; `string'
PUBLIC	??_C@_0BE@MOOM@gfx?2fight?2lupi3?4bmp?$AA@	; `string'
PUBLIC	??_C@_05KAIJ@Stand?$AA@				; `string'
PUBLIC	??_C@_0BF@PBLI@gfx?2fight?2sn_st2?4bmp?$AA@	; `string'
PUBLIC	??_C@_0BF@BBNH@gfx?2fight?2sn_st1?4bmp?$AA@	; `string'
PUBLIC	?LoadGfx@DISPLAY@@QAEPAUGFX_LAYER_INFO@@PAD@Z	; DISPLAY::LoadGfx
PUBLIC	??_C@_03GOGG@Red?$AA@				; `string'
PUBLIC	??_C@_0BF@HOHK@gfx?2fight?2rn_st2?4bmp?$AA@	; `string'
PUBLIC	??_C@_0BF@JOBF@gfx?2fight?2rn_st1?4bmp?$AA@	; `string'
PUBLIC	??_C@_0N@BPDI@gfx?2hand?4bmp?$AA@		; `string'
PUBLIC	??_C@_04LFM@Hand?$AA@				; `string'
EXTRN	?Val@@3PAVVALUES@@A:DWORD			; Val
EXTRN	?SetStr@DISPLAY@@QAEXPAPADPBD@Z:NEAR		; DISPLAY::SetStr
;	COMDAT ??_C@_0P@CLI@gfx?2cursor?4bmp?$AA@
; File D:\Game Programming\working Skull X\C++ Files\LoadGfx.cpp
CONST	SEGMENT
??_C@_0P@CLI@gfx?2cursor?4bmp?$AA@ DB 'gfx\cursor.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@LLOH@gfx?2select_scrn?4bmp?$AA@
CONST	SEGMENT
??_C@_0BE@LLOH@gfx?2select_scrn?4bmp?$AA@ DB 'gfx\select_scrn.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_03HCBO@Bkg?$AA@
CONST	SEGMENT
??_C@_03HCBO@Bkg?$AA@ DB 'Bkg', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0FM@EIIL@Please?0?5make?5a?5selection?5using?5t@
CONST	SEGMENT
??_C@_0FM@EIIL@Please?0?5make?5a?5selection?5using?5t@ DB 'Please, make a'
	DB	' selection using the game controller''s up or down arrows the'
	DB	'n the "X" button.', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_04BNNJ@Text?$AA@
CONST	SEGMENT
??_C@_04BNNJ@Text?$AA@ DB 'Text', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_04PGNC@Tile?$AA@
CONST	SEGMENT
??_C@_04PGNC@Tile?$AA@ DB 'Tile', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@INDM@gfx?2tile01?4bmp?$AA@
CONST	SEGMENT
??_C@_0P@INDM@gfx?2tile01?4bmp?$AA@ DB 'gfx\tile01.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_04BCJN@Win1?$AA@
CONST	SEGMENT
??_C@_04BCJN@Win1?$AA@ DB 'Win1', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_01FCOA@?5?$AA@
CONST	SEGMENT
??_C@_01FCOA@?5?$AA@ DB ' ', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@JEEK@gfx?2mywin_tm?4bmp?$AA@
CONST	SEGMENT
??_C@_0BB@JEEK@gfx?2mywin_tm?4bmp?$AA@ DB 'gfx\mywin_tm.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@PHMP@gfx?2mywin_tr?4bmp?$AA@
CONST	SEGMENT
??_C@_0BB@PHMP@gfx?2mywin_tr?4bmp?$AA@ DB 'gfx\mywin_tr.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@FGMM@gfx?2mywin_ml?4bmp?$AA@
CONST	SEGMENT
??_C@_0BB@FGMM@gfx?2mywin_ml?4bmp?$AA@ DB 'gfx\mywin_ml.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@JFGM@gfx?2mywin_mr?4bmp?$AA@
CONST	SEGMENT
??_C@_0BB@JFGM@gfx?2mywin_mr?4bmp?$AA@ DB 'gfx\mywin_mr.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@BDKN@gfx?2mywin_bl?4bmp?$AA@
CONST	SEGMENT
??_C@_0BB@BDKN@gfx?2mywin_bl?4bmp?$AA@ DB 'gfx\mywin_bl.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@LDII@gfx?2mywin_bm?4bmp?$AA@
CONST	SEGMENT
??_C@_0BB@LDII@gfx?2mywin_bm?4bmp?$AA@ DB 'gfx\mywin_bm.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@NAAN@gfx?2mywin_br?4bmp?$AA@
CONST	SEGMENT
??_C@_0BB@NAAN@gfx?2mywin_br?4bmp?$AA@ DB 'gfx\mywin_br.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BA@JPDC@gfx?2mytab_l?4bmp?$AA@
CONST	SEGMENT
??_C@_0BA@JPDC@gfx?2mytab_l?4bmp?$AA@ DB 'gfx\mytab_l.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BA@DPBH@gfx?2mytab_m?4bmp?$AA@
CONST	SEGMENT
??_C@_0BA@DPBH@gfx?2mytab_m?4bmp?$AA@ DB 'gfx\mytab_m.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BA@FMJC@gfx?2mytab_r?4bmp?$AA@
CONST	SEGMENT
??_C@_0BA@FMJC@gfx?2mytab_r?4bmp?$AA@ DB 'gfx\mytab_r.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0M@IMGB@save_Title1?$AA@
CONST	SEGMENT
??_C@_0M@IMGB@save_Title1?$AA@ DB 'save_Title1', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0M@GGJA@Save?5Game?5?5?$AA@
CONST	SEGMENT
??_C@_0M@GGJA@Save?5Game?5?5?$AA@ DB 'Save Game  ', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0M@JIIH@load_Title1?$AA@
CONST	SEGMENT
??_C@_0M@JIIH@load_Title1?$AA@ DB 'load_Title1', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0M@HCHG@Load?5Game?5?5?$AA@
CONST	SEGMENT
??_C@_0M@HCHG@Load?5Game?5?5?$AA@ DB 'Load Game  ', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_05KNBK@Text1?$AA@
CONST	SEGMENT
??_C@_05KNBK@Text1?$AA@ DB 'Text1', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0DA@KKIK@SN?5Lvl?3?5?5?5?5?5hrs?5min?5sec?5RN?5Lvl?3?5@
CONST	SEGMENT
??_C@_0DA@KKIK@SN?5Lvl?3?5?5?5?5?5hrs?5min?5sec?5RN?5Lvl?3?5@ DB 'SN Lvl:'
	DB	'     hrs min sec RN Lvl:        :   :   ', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_05EFOO@File1?$AA@
CONST	SEGMENT
??_C@_05EFOO@File1?$AA@ DB 'File1', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_07ECCJ@No?5File?$AA@
CONST	SEGMENT
??_C@_07ECCJ@No?5File?$AA@ DB 'No File', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_04JDGB@Back?$AA@
CONST	SEGMENT
??_C@_04JDGB@Back?$AA@ DB 'Back', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0N@MBOA@gfx?2back?4bmp?$AA@
CONST	SEGMENT
??_C@_0N@MBOA@gfx?2back?4bmp?$AA@ DB 'gfx\back.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@EMPP@gfx?2map_tile1?4bmp?$AA@
CONST	SEGMENT
??_C@_0BC@EMPP@gfx?2map_tile1?4bmp?$AA@ DB 'gfx\map_tile1.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_05HPB@Tile1?$AA@
CONST	SEGMENT
??_C@_05HPB@Tile1?$AA@ DB 'Tile1', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@KMJA@gfx?2map_tile2?4bmp?$AA@
CONST	SEGMENT
??_C@_0BC@KMJA@gfx?2map_tile2?4bmp?$AA@ DB 'gfx\map_tile2.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_05PIEI@Tile2?$AA@
CONST	SEGMENT
??_C@_05PIEI@Tile2?$AA@ DB 'Tile2', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_03DIFO@Map?$AA@
CONST	SEGMENT
??_C@_03DIFO@Map?$AA@ DB 'Map', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@PHHP@gfx?2water_tile?4bmp?$AA@
CONST	SEGMENT
??_C@_0BD@PHHP@gfx?2water_tile?4bmp?$AA@ DB 'gfx\water_tile.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@GPMI@gfx?2village_tile?4bmp?$AA@
CONST	SEGMENT
??_C@_0BF@GPMI@gfx?2village_tile?4bmp?$AA@ DB 'gfx\village_tile.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@PIJ@gfx?2desert_tile?4bmp?$AA@
CONST	SEGMENT
??_C@_0BE@PIJ@gfx?2desert_tile?4bmp?$AA@ DB 'gfx\desert_tile.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@FCCB@gfx?2grasslands_tile?4bmp?$AA@
CONST	SEGMENT
??_C@_0BI@FCCB@gfx?2grasslands_tile?4bmp?$AA@ DB 'gfx\grasslands_tile.bmp'
	DB	00H						; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@HDAC@gfx?2forest_tile?4bmp?$AA@
CONST	SEGMENT
??_C@_0BE@HDAC@gfx?2forest_tile?4bmp?$AA@ DB 'gfx\forest_tile.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@OAIF@gfx?2camp_tile1?4bmp?$AA@
CONST	SEGMENT
??_C@_0BD@OAIF@gfx?2camp_tile1?4bmp?$AA@ DB 'gfx\camp_tile1.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@BFGG@gfx?2safe_tile?4bmp?$AA@
CONST	SEGMENT
??_C@_0BC@BFGG@gfx?2safe_tile?4bmp?$AA@ DB 'gfx\safe_tile.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@CNMC@gfx?2bridge_tile?4bmp?$AA@
CONST	SEGMENT
??_C@_0BE@CNMC@gfx?2bridge_tile?4bmp?$AA@ DB 'gfx\bridge_tile.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@DMFI@gfx?2mountain?4bmp?$AA@
CONST	SEGMENT
??_C@_0BB@DMFI@gfx?2mountain?4bmp?$AA@ DB 'gfx\mountain.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@LGEO@gfx?2cavern?4bmp?$AA@
CONST	SEGMENT
??_C@_0P@LGEO@gfx?2cavern?4bmp?$AA@ DB 'gfx\cavern.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_04HGOJ@Camp?$AA@
CONST	SEGMENT
??_C@_04HGOJ@Camp?$AA@ DB 'Camp', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_04OLBH@fire?$AA@
CONST	SEGMENT
??_C@_04OLBH@fire?$AA@ DB 'fire', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@OK@gfx?2camp_tile2?4bmp?$AA@
CONST	SEGMENT
??_C@_0BD@OK@gfx?2camp_tile2?4bmp?$AA@ DB 'gfx\camp_tile2.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@KAMP@gfx?2camp_tile3?4bmp?$AA@
CONST	SEGMENT
??_C@_0BD@KAMP@gfx?2camp_tile3?4bmp?$AA@ DB 'gfx\camp_tile3.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_06DJMK@RedGoo?$AA@
CONST	SEGMENT
??_C@_06DJMK@RedGoo?$AA@ DB 'RedGoo', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_04IBJ@walk?$AA@
CONST	SEGMENT
??_C@_04IBJ@walk?$AA@ DB 'walk', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@PCC@gfx?2red_goo1?4bmp?$AA@
CONST	SEGMENT
??_C@_0BB@PCC@gfx?2red_goo1?4bmp?$AA@ DB 'gfx\red_goo1.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@OPEN@gfx?2red_goo2?4bmp?$AA@
CONST	SEGMENT
??_C@_0BB@OPEN@gfx?2red_goo2?4bmp?$AA@ DB 'gfx\red_goo2.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_07NIEJ@BlueGoo?$AA@
CONST	SEGMENT
??_C@_07NIEJ@BlueGoo?$AA@ DB 'BlueGoo', 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@PIDO@gfx?2blue_goo1?4bmp?$AA@
CONST	SEGMENT
??_C@_0BC@PIDO@gfx?2blue_goo1?4bmp?$AA@ DB 'gfx\blue_goo1.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@BIFB@gfx?2blue_goo2?4bmp?$AA@
CONST	SEGMENT
??_C@_0BC@BIFB@gfx?2blue_goo2?4bmp?$AA@ DB 'gfx\blue_goo2.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_05COAO@Super?$AA@
CONST	SEGMENT
??_C@_05COAO@Super?$AA@ DB 'Super', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BA@JLOJ@gfx?2sn_map1?4bmp?$AA@
CONST	SEGMENT
??_C@_0BA@JLOJ@gfx?2sn_map1?4bmp?$AA@ DB 'gfx\sn_map1.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BA@HLIG@gfx?2sn_map2?4bmp?$AA@
CONST	SEGMENT
??_C@_0BA@HLIG@gfx?2sn_map2?4bmp?$AA@ DB 'gfx\sn_map2.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_04FKLJ@menu?$AA@
CONST	SEGMENT
??_C@_04FKLJ@menu?$AA@ DB 'menu', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BB@DCJH@gfx?2map_menu?4bmp?$AA@
CONST	SEGMENT
??_C@_0BB@DCJH@gfx?2map_menu?4bmp?$AA@ DB 'gfx\map_menu.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_05LCII@sStat?$AA@
CONST	SEGMENT
??_C@_05LCII@sStat?$AA@ DB 'sStat', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BJ@GKNC@gfx?2sninja_stat_menu?4bmp?$AA@
CONST	SEGMENT
??_C@_0BJ@GKNC@gfx?2sninja_stat_menu?4bmp?$AA@ DB 'gfx\sninja_stat_menu.b'
	DB	'mp', 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_05BCKN@rStat?$AA@
CONST	SEGMENT
??_C@_05BCKN@rStat?$AA@ DB 'rStat', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BG@CHBC@gfx?2red_stat_menu?4bmp?$AA@
CONST	SEGMENT
??_C@_0BG@CHBC@gfx?2red_stat_menu?4bmp?$AA@ DB 'gfx\red_stat_menu.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_04LEEA@sPic?$AA@
CONST	SEGMENT
??_C@_04LEEA@sPic?$AA@ DB 'sPic', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@BHAO@gfx?2sninja_pic?4bmp?$AA@
CONST	SEGMENT
??_C@_0BD@BHAO@gfx?2sninja_pic?4bmp?$AA@ DB 'gfx\sninja_pic.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_04JBBC@rPic?$AA@
CONST	SEGMENT
??_C@_04JBBC@rPic?$AA@ DB 'rPic', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BA@FPGN@gfx?2red_pic?4bmp?$AA@
CONST	SEGMENT
??_C@_0BA@FPGN@gfx?2red_pic?4bmp?$AA@ DB 'gfx\red_pic.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0N@LOKF@gfx?2dark?4bmp?$AA@
CONST	SEGMENT
??_C@_0N@LOKF@gfx?2dark?4bmp?$AA@ DB 'gfx\dark.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_04IPGD@gray?$AA@
CONST	SEGMENT
??_C@_04IPGD@gray?$AA@ DB 'gray', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BG@KCBA@gfx?2fight?2land01a?4bmp?$AA@
CONST	SEGMENT
??_C@_0BG@KCBA@gfx?2fight?2land01a?4bmp?$AA@ DB 'gfx\fight\land01a.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_05MCMJ@LandA?$AA@
CONST	SEGMENT
??_C@_05MCMJ@LandA?$AA@ DB 'LandA', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BG@ECHP@gfx?2fight?2land01b?4bmp?$AA@
CONST	SEGMENT
??_C@_0BG@ECHP@gfx?2fight?2land01b?4bmp?$AA@ DB 'gfx\fight\land01b.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_05DNHA@LandB?$AA@
CONST	SEGMENT
??_C@_05DNHA@LandB?$AA@ DB 'LandB', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@CLF@gfx?2fight?2tab?4bmp?$AA@
CONST	SEGMENT
??_C@_0BC@CLF@gfx?2fight?2tab?4bmp?$AA@ DB 'gfx\fight\tab.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_03CHMJ@Tab?$AA@
CONST	SEGMENT
??_C@_03CHMJ@Tab?$AA@ DB 'Tab', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_04LFF@Lupi?$AA@
CONST	SEGMENT
??_C@_04LFF@Lupi?$AA@ DB 'Lupi', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@IOKG@gfx?2fight?2lupi1?4bmp?$AA@
CONST	SEGMENT
??_C@_0BE@IOKG@gfx?2fight?2lupi1?4bmp?$AA@ DB 'gfx\fight\lupi1.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@GOMJ@gfx?2fight?2lupi2?4bmp?$AA@
CONST	SEGMENT
??_C@_0BE@GOMJ@gfx?2fight?2lupi2?4bmp?$AA@ DB 'gfx\fight\lupi2.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BE@MOOM@gfx?2fight?2lupi3?4bmp?$AA@
CONST	SEGMENT
??_C@_0BE@MOOM@gfx?2fight?2lupi3?4bmp?$AA@ DB 'gfx\fight\lupi3.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_05KAIJ@Stand?$AA@
CONST	SEGMENT
??_C@_05KAIJ@Stand?$AA@ DB 'Stand', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@PBLI@gfx?2fight?2sn_st2?4bmp?$AA@
CONST	SEGMENT
??_C@_0BF@PBLI@gfx?2fight?2sn_st2?4bmp?$AA@ DB 'gfx\fight\sn_st2.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@BBNH@gfx?2fight?2sn_st1?4bmp?$AA@
CONST	SEGMENT
??_C@_0BF@BBNH@gfx?2fight?2sn_st1?4bmp?$AA@ DB 'gfx\fight\sn_st1.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_03GOGG@Red?$AA@
CONST	SEGMENT
??_C@_03GOGG@Red?$AA@ DB 'Red', 00H			; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@HOHK@gfx?2fight?2rn_st2?4bmp?$AA@
CONST	SEGMENT
??_C@_0BF@HOHK@gfx?2fight?2rn_st2?4bmp?$AA@ DB 'gfx\fight\rn_st2.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BF@JOBF@gfx?2fight?2rn_st1?4bmp?$AA@
CONST	SEGMENT
??_C@_0BF@JOBF@gfx?2fight?2rn_st1?4bmp?$AA@ DB 'gfx\fight\rn_st1.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0N@BPDI@gfx?2hand?4bmp?$AA@
CONST	SEGMENT
??_C@_0N@BPDI@gfx?2hand?4bmp?$AA@ DB 'gfx\hand.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_04LFM@Hand?$AA@
CONST	SEGMENT
??_C@_04LFM@Hand?$AA@ DB 'Hand', 00H			; `string'
CONST	ENDS
;	COMDAT ?LoadGfx@DISPLAY@@QAEPAUGFX_LAYER_INFO@@PAD@Z
_TEXT	SEGMENT
_this$ = -4
_gli$ = -8
_i$ = -12
_j$ = -16
_ai$ = -20
_li$ = -24
_LevelNum$ = -28
_a$65029 = -228
$T65334 = -232
$T65335 = -236
$T65336 = -240
$T65337 = -244
$T65338 = -248
$T65339 = -252
$T65340 = -256
$T65341 = -260
$T65342 = -264
$T65343 = -268
$T65344 = -272
$T65345 = -276
$T65346 = -280
$T65347 = -284
$T65348 = -288
$T65349 = -292
$T65350 = -296
$T65351 = -300
$T65352 = -304
$T65353 = -308
$T65354 = -312
$T65355 = -316
$T65356 = -320
$T65357 = -324
$T65358 = -328
$T65359 = -332
$T65360 = -336
?LoadGfx@DISPLAY@@QAEPAUGFX_LAYER_INFO@@PAD@Z PROC NEAR	; DISPLAY::LoadGfx, COMDAT

; 34   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 400				; 00000190H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 35   : 	GFX_LAYER_INFO *gli;
; 36   : 	gli = new GFX_LAYER_INFO;

	push	16					; 00000010H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65334[ebp], eax
	mov	eax, DWORD PTR $T65334[ebp]
	mov	DWORD PTR _gli$[ebp], eax

; 37   : 	unsigned __int8 i = 0, j = 0;

	mov	BYTE PTR _i$[ebp], 0
	mov	BYTE PTR _j$[ebp], 0

; 38   : 
; 39   : 	ANIM_INFO *ai;
; 40   : 	LAYER_INFO *li;
; 41   : 
; 42   : /*
; 43   : 	unsigned __int16 Size;
; 44   : 
; 45   : 	hFile = CreateFile(FileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
; 46   : 		if(hFile == NULL)	return Error(NULL, "DISPLAY:LoadGfx", "CreateFile", GetLastError());
; 47   : 
; 48   : 	// Load Header info
; 49   : 	Size = sizeof(GFX_LAYER_INFO) - sizeof(LAYER_INFO*);
; 50   : 	ReadFile(hFile, &gli, Size, &NumByteW, NULL);
; 51   : 	if(NumByteW != Size)
; 52   : 	{	CloseHandle(hFile);	return Error(NULL, "DISPLAY:LoadGfx", "ReadFile", GetLastError());	}
; 53   : 
; 54   : 	//
; 55   : 
; 56   : 	gli->l = new LAYER_INFO[gli->nLayer];
; 57   : 	memset(gli->l, 0, gli->nLayer*sizeof(LAYER_INFO) );
; 58   : 	Size = sizeof(LAYER_INFO) - sizeof(char*);
; 59   : 
; 60   : 	for(i = 0; i < gli->nLayer; i++)
; 61   : 	{
; 62   : 		ReadFile(hFile, &(gli->l[i]), Size, &NumByteW, NULL);
; 63   : 		if(NumByteW != Size)
; 64   : 			{	CloseHandle(hFile);	return Error(NULL, "DISPLAY:LoadGfx", "ReadFile", GetLastError());	}
; 65   : 
; 66   : 
; 67   : 		if(gli->l[i].type == LT_SPRITE)
; 68   : 		{
; 69   : 			gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
; 70   : 			memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
; 71   : 			Size = sizeof(CEL_INFO) - sizeof(char*);
; 72   : 
; 73   : 			for(j = 0; j < gli->l[i].nCel; j++)
; 74   : 			{
; 75   : 				ReadFile(hFile, &(gli->l[i].cel_info[j]), Size, &NumByteW, NULL);
; 76   : 				if(NumByteW != Size)
; 77   : 					{	CloseHandle(hFile);	return Error(NULL, "DISPLAY:LoadGfx", "ReadFile", GetLastError());	}
; 78   : 				
; 79   : 				gli->l[i].cel_info[j].fName = new char[gli->l[i].cel_info[j].fSize];
; 80   : 				ReadFile(hFile, gli->l[i].cel_info[j].fName, (gli->l[i].cel_info[j].fSize)*sizeof(char), &NumByteW, NULL);
; 81   : 				if(NumByteW != (gli->l[i].cel_info[j].fSize)*sizeof(char))
; 82   : 					{	CloseHandle(hFile);	return Error(NULL, "DISPLAY:LoadGfx", "ReadFile", GetLastError());	}
; 83   : 			}
; 84   : 		}
; 85   : 		else if((gli->l[i].type == LT_IMAGE) || (gli->l[i].type == LT_BKG))
; 86   : 		{		
; 87   : 			gli->l[i].fName = new char[gli->l[i].fSize];
; 88   : 			Size = gli->l[i].fSize*sizeof(char);
; 89   : 			ReadFile(hFile, gli->l[i].fName, Size, &NumByteW, NULL);
; 90   : 			if(NumByteW != Size)
; 91   : 				{	CloseHandle(hFile);	return Error(NULL, "DISPLAY:LoadGfx", "ReadFile", GetLastError());	}
; 92   : 		}
; 93   : 		else
; 94   : 			return Error(NULL, "DISPLAY:LoadGfx", "layer type error", 1)
; 95   : 
; 96   : 	}
; 97   : */
; 98   : 	unsigned __int16 LevelNum = Val->Game->gData.LevelNum;

	mov	ecx, DWORD PTR ?Val@@3PAVVALUES@@A	; Val
	mov	edx, DWORD PTR [ecx+76]
	mov	ax, WORD PTR [edx+16]
	mov	WORD PTR _LevelNum$[ebp], ax

; 99   : 
; 100  : 	gli->UseMouse = false;

	mov	ecx, DWORD PTR _gli$[ebp]
	mov	BYTE PTR [ecx], 0

; 101  : 	SetStr(&gli->Mouse_fName, "gfx\\cursor.bmp");

	push	OFFSET FLAT:??_C@_0P@CLI@gfx?2cursor?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _gli$[ebp]
	add	edx, 4
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 102  : 
; 103  : 	gli->l = new LAYER_INFO[99];

	push	5148					; 0000141cH
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65335[ebp], eax
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR $T65335[ebp]
	mov	DWORD PTR [eax+12], ecx

; 104  : 	ZeroMemory(gli->l, 99*sizeof(LAYER_INFO) );

	push	5148					; 0000141cH
	push	0
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 105  : 	i = 0;

	mov	BYTE PTR _i$[ebp], 0

; 106  : 
; 107  : 	if(LevelNum == 0)

	mov	ecx, DWORD PTR _LevelNum$[ebp]
	and	ecx, 65535				; 0000ffffH
	test	ecx, ecx
	jne	$L64951

; 109  : 		gli->l[i].visable = true;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+5], 1

; 110  : 		gli->l[i].type = LT_IMAGE;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+4], 1

; 111  : 		gli->l[i].x = 0;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+16], 0

; 112  : 		gli->l[i].y = 0;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+20], 0

; 113  : 		gli->l[i].w = 320;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+10], 320		; 00000140H

; 114  : 		gli->l[i].h = 240;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+12], 240		; 000000f0H

; 115  : 		SetStr(&gli->l[i].fName, "gfx\\select_scrn.bmp");

	push	OFFSET FLAT:??_C@_0BE@LLOH@gfx?2select_scrn?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	lea	edx, DWORD PTR [ecx+edx+48]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 116  : 		SetStr(&gli->l[i].Name, "Bkg");

	push	OFFSET FLAT:??_C@_03HCBO@Bkg?$AA@	; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 117  : 		i++;

	mov	al, BYTE PTR _i$[ebp]
	add	al, 1
	mov	BYTE PTR _i$[ebp], al

; 118  : 
; 119  : 		gli->l[i].visable = true;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+5], 1

; 120  : 		gli->l[i].type = LT_TEXT;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+4], 5

; 121  : 		gli->l[i].hAlign = AT_CENTER;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+44], 0

; 122  : 		gli->l[i].x = 24;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+ecx+16], 24		; 00000018H

; 123  : 		gli->l[i].y = 165;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+ecx+20], 165		; 000000a5H

; 124  : 		gli->l[i].w = 272;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+10], 272		; 00000110H

; 125  : 		gli->l[i].h = 75;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+12], 75		; 0000004bH

; 126  : 		SetStr(&gli->l[i].text, "Please, make a selection using the game controller's up or down arrows then the \"X\" button.");

	push	OFFSET FLAT:??_C@_0FM@EIIL@Please?0?5make?5a?5selection?5using?5t@ ; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	lea	ecx, DWORD PTR [eax+ecx+48]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 127  : 		SetStr(&gli->l[i].Name, "Text");

	push	OFFSET FLAT:??_C@_04BNNJ@Text?$AA@	; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	add	ecx, edx
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 128  : 		i++;

	mov	dl, BYTE PTR _i$[ebp]
	add	dl, 1
	mov	BYTE PTR _i$[ebp], dl

; 224  : 	else if(LevelNum == 1)

	jmp	$L65086
$L64951:
	mov	eax, DWORD PTR _LevelNum$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 1
	jne	$L64957

; 226  : 		SetStr(&gli->l[i].Name, "Tile");

	push	OFFSET FLAT:??_C@_04PGNC@Tile?$AA@	; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	add	eax, ecx
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 227  : 		gli->l[i].visable = true;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+5], 1

; 228  : 		gli->l[i].moveable = true;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+6], 1

; 229  : 		gli->l[i].move_type = LT_FOREVER;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+7], 2

; 230  : 		gli->l[i].type = LT_TILE;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+4], 3

; 231  : 
; 232  : 		gli->l[i].x = 0;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+ecx+16], 0

; 233  : 		gli->l[i].y = 0;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+ecx+20], 0

; 234  : 		gli->l[i].w = 4;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+10], 4

; 235  : 		gli->l[i].h = 6;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+12], 6

; 236  : 		gli->l[i].tile_image_w = 128;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+44], 128		; 00000080H

; 237  : 		gli->l[i].tile_image_h = 64;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+45], 64		; 00000040H

; 238  : 
; 239  : 		gli->l[i].tile_info = new TILE_INFO;

	push	8
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65336[ebp], eax
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	edx, DWORD PTR $T65336[ebp]
	mov	DWORD PTR [eax+ecx+48], edx

; 240  : 		SetStr(&gli->l[i].tile_info->fName, "gfx\\tile01.bmp");

	push	OFFSET FLAT:??_C@_0P@INDM@gfx?2tile01?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR [edx+eax+48]
	add	eax, 4
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 241  : 		i++;

	mov	cl, BYTE PTR _i$[ebp]
	add	cl, 1
	mov	BYTE PTR _i$[ebp], cl

; 242  : 
; 243  : 		SetStr(&gli->l[i].Name, "Win1");

	push	OFFSET FLAT:??_C@_04BCJN@Win1?$AA@	; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	add	ecx, edx
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 244  : 		gli->l[i].visable = true;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+5], 1

; 245  : 		gli->l[i].type = LT_WINDOW;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+4], 6

; 246  : 		gli->l[i].x = 32;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+16], 32		; 00000020H

; 247  : 		gli->l[i].y = 6;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+20], 6

; 248  : 		gli->l[i].w = 256;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+10], 256		; 00000100H

; 249  : 		gli->l[i].h = 43;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+12], 43		; 0000002bH

; 250  : 
; 251  : 		gli->l[i].win_image_w = 5;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+45], 5

; 252  : 		gli->l[i].win_image_h = 5;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+46], 5

; 253  : 		gli->l[i].wType = WT_TAB | WT_BGCOLOR;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+44], 3

; 254  : 
; 255  : 		gli->l[i].win = new WIN_INFO;

	push	12					; 0000000cH
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65337[ebp], eax
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	eax, DWORD PTR $T65337[ebp]
	mov	DWORD PTR [ecx+edx+48], eax

; 256  : 		ZeroMemory(gli->l[i].win, sizeof(WIN_INFO));

	push	12					; 0000000cH
	push	0
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [eax+ecx+48]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 257  : 		gli->l[i].win->bgcolor = RGB(159, 159, 159);

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	DWORD PTR [edx+8], 10461087		; 009f9f9fH

; 258  : 		// 9 images if no tab
; 259  : 		gli->l[i].win->img = new char*[9];

	push	36					; 00000024H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65338[ebp], eax
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR [edx+eax+48]
	mov	ecx, DWORD PTR $T65338[ebp]
	mov	DWORD PTR [eax+4], ecx

; 260  : 		ZeroMemory(gli->l[i].win->img, 9*sizeof(char*));

	push	36					; 00000024H
	push	0
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx+4]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 261  : 		SetStr(&gli->l[i].win->img[W_TOP_LEFT],			" ");

	push	OFFSET FLAT:??_C@_01FCOA@?5?$AA@	; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [eax+ecx+48]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 262  : 		SetStr(&gli->l[i].win->img[W_TOP],					"gfx\\mywin_tm.bmp");

	push	OFFSET FLAT:??_C@_0BB@JEEK@gfx?2mywin_tm?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR [edx+eax+48]
	mov	ecx, DWORD PTR [eax+4]
	add	ecx, 4
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 263  : 		SetStr(&gli->l[i].win->img[W_TOP_RIGHT],		"gfx\\mywin_tr.bmp");

	push	OFFSET FLAT:??_C@_0BB@PHMP@gfx?2mywin_tr?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx+4]
	add	eax, 8
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 264  : 		SetStr(&gli->l[i].win->img[W_LEFT],					"gfx\\mywin_ml.bmp");

	push	OFFSET FLAT:??_C@_0BB@FGMM@gfx?2mywin_ml?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [eax+ecx+48]
	mov	edx, DWORD PTR [ecx+4]
	add	edx, 12					; 0000000cH
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 265  : 		SetStr(&gli->l[i].win->img[W_MIDDLE],				" ");

	push	OFFSET FLAT:??_C@_01FCOA@?5?$AA@	; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR [edx+eax+48]
	mov	ecx, DWORD PTR [eax+4]
	add	ecx, 16					; 00000010H
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 266  : 		SetStr(&gli->l[i].win->img[W_RIGHT],				"gfx\\mywin_mr.bmp");

	push	OFFSET FLAT:??_C@_0BB@JFGM@gfx?2mywin_mr?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx+4]
	add	eax, 20					; 00000014H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 267  : 		SetStr(&gli->l[i].win->img[W_BOTTOM_LEFT],	"gfx\\mywin_bl.bmp");

	push	OFFSET FLAT:??_C@_0BB@BDKN@gfx?2mywin_bl?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [eax+ecx+48]
	mov	edx, DWORD PTR [ecx+4]
	add	edx, 24					; 00000018H
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 268  : 		SetStr(&gli->l[i].win->img[W_BOTTOM],				"gfx\\mywin_bm.bmp");

	push	OFFSET FLAT:??_C@_0BB@LDII@gfx?2mywin_bm?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR [edx+eax+48]
	mov	ecx, DWORD PTR [eax+4]
	add	ecx, 28					; 0000001cH
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 269  : 		SetStr(&gli->l[i].win->img[W_BOTTOM_RIGHT], "gfx\\mywin_br.bmp");

	push	OFFSET FLAT:??_C@_0BB@NAAN@gfx?2mywin_br?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx+4]
	add	eax, 32					; 00000020H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 270  : 
; 271  : 		gli->l[i].win->tab = new TAB_INFO;

	push	12					; 0000000cH
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65339[ebp], eax
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [eax+ecx+48]
	mov	edx, DWORD PTR $T65339[ebp]
	mov	DWORD PTR [ecx], edx

; 272  : 		ZeroMemory(gli->l[i].win->tab, sizeof(TAB_INFO));

	push	12					; 0000000cH
	push	0
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR [edx+eax+48]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 273  : 			gli->l[i].win->tab->w = 144;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx]
	mov	BYTE PTR [eax], 144			; 00000090H

; 274  : 			gli->l[i].win->tab->h = 23;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [eax+ecx+48]
	mov	edx, DWORD PTR [ecx]
	mov	BYTE PTR [edx+1], 23			; 00000017H

; 275  : 			gli->l[i].win->tab->wImg = 17;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR [edx+eax+48]
	mov	ecx, DWORD PTR [eax]
	mov	BYTE PTR [ecx+8], 17			; 00000011H

; 276  : 			gli->l[i].win->tab->img = new char*[3];

	push	12					; 0000000cH
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65340[ebp], eax
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR $T65340[ebp]
	mov	DWORD PTR [eax+4], ecx

; 277  : 			memset(gli->l[i].win->tab->img, 0,  3*sizeof(char*));

	push	12					; 0000000cH
	push	0
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 278  : 			SetStr(&gli->l[i].win->tab->img[0], "gfx\\mytab_l.bmp");

	push	OFFSET FLAT:??_C@_0BA@JPDC@gfx?2mytab_l?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 279  : 			SetStr(&gli->l[i].win->tab->img[1], "gfx\\mytab_m.bmp");

	push	OFFSET FLAT:??_C@_0BA@DPBH@gfx?2mytab_m?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR [eax+4]
	add	ecx, 4
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 280  : 			SetStr(&gli->l[i].win->tab->img[2], "gfx\\mytab_r.bmp");

	push	OFFSET FLAT:??_C@_0BA@FMJC@gfx?2mytab_r?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR [eax+4]
	add	ecx, 8
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 281  : 		i++;

	mov	dl, BYTE PTR _i$[ebp]
	add	dl, 1
	mov	BYTE PTR _i$[ebp], dl

; 282  : 
; 283  : 		/*
; 284  : 		// window 2
; 285  : 		gli->l[i].x = 32;
; 286  : 		gli->l[i].y = 76;
; 287  : 		*/
; 288  : 		/*
; 289  : 		// window 3
; 290  : 		gli->l[i].x = 32;
; 291  : 		gli->l[i].y = 146;
; 292  : 		*/
; 293  : 		/*
; 294  : 		// Title 1
; 295  : 		gli->l[i].x = 51;
; 296  : 		gli->l[i].y = 11;
; 297  : 		gli->l[i].w = 122;
; 298  : 		gli->l[i].h = 13;
; 299  : 		*/
; 300  : 
; 301  : 		SetStr(&gli->l[i].Name, "save_Title1");

	push	OFFSET FLAT:??_C@_0M@IMGB@save_Title1?$AA@ ; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 302  : 		gli->l[i].visable = false;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+5], 0

; 303  : 		gli->l[i].type = LT_TEXT;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+4], 5

; 304  : 		gli->l[i].hAlign = AT_LEFT;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+44], 1

; 305  : 		gli->l[i].x = 56;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+16], 56		; 00000038H

; 306  : 		gli->l[i].y = 10;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+20], 10		; 0000000aH

; 307  : 		gli->l[i].w = 122;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+10], 122		; 0000007aH

; 308  : 		gli->l[i].h = 16;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+12], 16		; 00000010H

; 309  : 		SetStr(&gli->l[i].text, "Save Game  ");

	push	OFFSET FLAT:??_C@_0M@GGJA@Save?5Game?5?5?$AA@ ; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	lea	eax, DWORD PTR [edx+eax+48]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 310  : 		i++;

	mov	cl, BYTE PTR _i$[ebp]
	add	cl, 1
	mov	BYTE PTR _i$[ebp], cl

; 311  : 
; 312  : 		SetStr(&gli->l[i].Name, "load_Title1");

	push	OFFSET FLAT:??_C@_0M@JIIH@load_Title1?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	add	ecx, edx
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 313  : 		gli->l[i].visable = false;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+5], 0

; 314  : 		gli->l[i].type = LT_TEXT;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+4], 5

; 315  : 		gli->l[i].hAlign = AT_LEFT;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+44], 1

; 316  : 		gli->l[i].x = 56;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+16], 56		; 00000038H

; 317  : 		gli->l[i].y = 10;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+20], 10		; 0000000aH

; 318  : 		gli->l[i].w = 122;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+10], 122		; 0000007aH

; 319  : 		gli->l[i].h = 16;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+12], 16		; 00000010H

; 320  : 		SetStr(&gli->l[i].text, "Load Game  ");

	push	OFFSET FLAT:??_C@_0M@HCHG@Load?5Game?5?5?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	lea	edx, DWORD PTR [ecx+edx+48]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 321  : 		i++;

	mov	al, BYTE PTR _i$[ebp]
	add	al, 1
	mov	BYTE PTR _i$[ebp], al

; 322  : 
; 323  : 		SetStr(&gli->l[i].Name, "Text1");

	push	OFFSET FLAT:??_C@_05KNBK@Text1?$AA@	; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	add	eax, ecx
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 324  : 		gli->l[i].visable = false;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+5], 0

; 325  : 		gli->l[i].type = LT_TEXT;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+4], 5

; 326  : 		gli->l[i].hAlign = AT_LEFT;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+44], 1

; 327  : 		gli->l[i].x = 45;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+ecx+16], 45		; 0000002dH

; 328  : 		gli->l[i].y = 32;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+ecx+20], 32		; 00000020H

; 329  : 		gli->l[i].w = 240;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+10], 240		; 000000f0H

; 330  : 		gli->l[i].h = 32;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+12], 32		; 00000020H

; 331  : 		SetStr(&gli->l[i].text, "SN Lvl:     hrs min sec RN Lvl:        :   :   ");

	push	OFFSET FLAT:??_C@_0DA@KKIK@SN?5Lvl?3?5?5?5?5?5hrs?5min?5sec?5RN?5Lvl?3?5@ ; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	lea	ecx, DWORD PTR [eax+ecx+48]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 332  : 		i++;

	mov	dl, BYTE PTR _i$[ebp]
	add	dl, 1
	mov	BYTE PTR _i$[ebp], dl

; 333  : 
; 334  : 		SetStr(&gli->l[i].Name, "File1");

	push	OFFSET FLAT:??_C@_05EFOO@File1?$AA@	; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 335  : 		gli->l[i].visable = false;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+5], 0

; 336  : 		gli->l[i].type = LT_TEXT;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+4], 5

; 337  : 		gli->l[i].hAlign = AT_CENTER;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+44], 0

; 338  : 		gli->l[i].x = 37;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+16], 37		; 00000025H

; 339  : 		gli->l[i].y = 40;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+20], 40		; 00000028H

; 340  : 		gli->l[i].w = 246;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+10], 246		; 000000f6H

; 341  : 		gli->l[i].h = 16;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+12], 16		; 00000010H

; 342  : 		SetStr(&gli->l[i].text, "No File");

	push	OFFSET FLAT:??_C@_07ECCJ@No?5File?$AA@	; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	lea	eax, DWORD PTR [edx+eax+48]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 343  : 		i++;

	mov	cl, BYTE PTR _i$[ebp]
	add	cl, 1
	mov	BYTE PTR _i$[ebp], cl

; 344  : 
; 345  : 		SetStr(&gli->l[i].Name, "Back");

	push	OFFSET FLAT:??_C@_04JDGB@Back?$AA@	; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	add	ecx, edx
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 346  : 		gli->l[i].visable = true;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+5], 1

; 347  : 		gli->l[i].type = LT_IMAGE;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+4], 1

; 348  : 		gli->l[i].x = 32;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+16], 32		; 00000020H

; 349  : 		gli->l[i].y = 216;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+20], 216		; 000000d8H

; 350  : 		gli->l[i].w = 63;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+10], 63		; 0000003fH

; 351  : 		gli->l[i].h = 19;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+12], 19		; 00000013H

; 352  : 		SetStr(&gli->l[i].fName, "gfx\\back.bmp");

	push	OFFSET FLAT:??_C@_0N@MBOA@gfx?2back?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	lea	edx, DWORD PTR [ecx+edx+48]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 353  : 		i++;

	mov	al, BYTE PTR _i$[ebp]
	add	al, 1
	mov	BYTE PTR _i$[ebp], al

; 356  : 	else if(LevelNum == 3)

	jmp	$L65086
$L64957:
	mov	ecx, DWORD PTR _LevelNum$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 3
	jne	$L65003

; 358  : 	//
; 359  : 	//
; 360  : 	//
; 361  : 		gli->l[i].visable = true;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+5], 1

; 362  : 		gli->l[i].moveable = true;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+6], 1

; 363  : 		gli->l[i].move_type = LT_FOREVER;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+7], 2

; 364  : 		gli->l[i].type = LT_TILE;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+4], 3

; 365  : 
; 366  : 		gli->l[i].x = 0;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+16], 0

; 367  : 		gli->l[i].y = 0;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+20], 0

; 368  : 		gli->l[i].w = 16;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+10], 16		; 00000010H

; 369  : 		gli->l[i].h = 13;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+12], 13		; 0000000dH

; 370  : 		gli->l[i].tile_image_w = 20;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+44], 20		; 00000014H

; 371  : 		gli->l[i].tile_image_h = 20;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+45], 20		; 00000014H

; 372  : 
; 373  : 		gli->l[i].tile_info = new TILE_INFO;

	push	8
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65341[ebp], eax
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	eax, DWORD PTR $T65341[ebp]
	mov	DWORD PTR [ecx+edx+48], eax

; 374  : 		SetStr(&gli->l[i].tile_info->fName, "gfx\\map_tile1.bmp");

	push	OFFSET FLAT:??_C@_0BC@EMPP@gfx?2map_tile1?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [eax+ecx+48]
	add	ecx, 4
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 375  : 		SetStr(&gli->l[i].Name, "Tile1");

	push	OFFSET FLAT:??_C@_05HPB@Tile1?$AA@	; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	add	ecx, edx
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 376  : 		i++;

	mov	dl, BYTE PTR _i$[ebp]
	add	dl, 1
	mov	BYTE PTR _i$[ebp], dl

; 377  : 	//
; 378  : 	//
; 379  : 	//
; 380  : 		gli->l[i].visable = true;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+5], 1

; 381  : 		gli->l[i].type = LT_TILE;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+4], 3

; 382  : 
; 383  : 		gli->l[i].x = 90;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+16], 90		; 0000005aH

; 384  : 		gli->l[i].y = 10;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+20], 10		; 0000000aH

; 385  : 		gli->l[i].w = 11;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+10], 11		; 0000000bH

; 386  : 		gli->l[i].h = 11;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+12], 11		; 0000000bH

; 387  : 		gli->l[i].tile_image_w = 20;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+44], 20		; 00000014H

; 388  : 		gli->l[i].tile_image_h = 20;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+45], 20		; 00000014H

; 389  : 
; 390  : 		gli->l[i].tile_info = new TILE_INFO;

	push	8
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65342[ebp], eax
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	ecx, DWORD PTR $T65342[ebp]
	mov	DWORD PTR [edx+eax+48], ecx

; 391  : 		SetStr(&gli->l[i].tile_info->fName, "gfx\\map_tile2.bmp");

	push	OFFSET FLAT:??_C@_0BC@KMJA@gfx?2map_tile2?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	add	edx, 4
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 392  : 		SetStr(&gli->l[i].Name, "Tile2");

	push	OFFSET FLAT:??_C@_05PIEI@Tile2?$AA@	; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 393  : 		i++;

	mov	al, BYTE PTR _i$[ebp]
	add	al, 1
	mov	BYTE PTR _i$[ebp], al

; 394  : 	//
; 395  : 	//
; 396  : 	//
; 397  : 		SetStr(&gli->l[i].Name, "Map");

	push	OFFSET FLAT:??_C@_03DIFO@Map?$AA@	; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	add	eax, ecx
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 398  : 		gli->l[i].visable = true;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+5], 1

; 399  : 		gli->l[i].map_info = new MAP_INFO;

	push	12					; 0000000cH
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65343[ebp], eax
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	edx, DWORD PTR $T65343[ebp]
	mov	DWORD PTR [eax+ecx+48], edx

; 400  : 		gli->l[i].map_info->data = new unsigned __int8 *[ gli->l[i].map_image_w ];

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax+44]
	shl	ecx, 2
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65344[ebp], eax
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR $T65344[ebp]
	mov	DWORD PTR [edx], eax

; 401  : 		gli->l[i].map_info->fName = new char *[ gli->l[i].map_num_images ];

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+ecx+46]
	shl	edx, 2
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65345[ebp], eax
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR [edx+eax+48]
	mov	ecx, DWORD PTR $T65345[ebp]
	mov	DWORD PTR [eax+8], ecx

; 402  : 		gli->l[i].type = LT_MAP;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+4], 4

; 403  : 
; 404  : 		gli->l[i].moveable = false;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+6], 0

; 405  : 		gli->l[i].clip = true;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+24], 1

; 406  : 		gli->l[i].cx = 100;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+28], 100		; 00000064H

; 407  : 		gli->l[i].cy = 20;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+32], 20		; 00000014H

; 408  : 		gli->l[i].cw = 200;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+36], 200		; 000000c8H

; 409  : 		gli->l[i].ch = 200;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+38], 200		; 000000c8H

; 410  : 
; 411  : 		gli->l[i].x = -100;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+16], -100		; ffffff9cH

; 412  : 		gli->l[i].y = 20;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+20], 20		; 00000014H

; 413  : 		gli->l[i].map_image_w = 20;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+44], 20		; 00000014H

; 414  : 		gli->l[i].map_image_h = 20;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+45], 20		; 00000014H

; 415  : 		gli->l[i].map_num_images = 10;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+46], 10		; 0000000aH

; 416  : 		SetStr(&gli->l[i].map_info->fName[0], "gfx\\water_tile.bmp");

	push	OFFSET FLAT:??_C@_0BD@PHHP@gfx?2water_tile?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx+8]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 417  : 		SetStr(&gli->l[i].map_info->fName[1], "gfx\\village_tile.bmp");

	push	OFFSET FLAT:??_C@_0BF@GPMI@gfx?2village_tile?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [eax+ecx+48]
	mov	edx, DWORD PTR [ecx+8]
	add	edx, 4
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 418  : 		SetStr(&gli->l[i].map_info->fName[2], "gfx\\desert_tile.bmp");

	push	OFFSET FLAT:??_C@_0BE@PIJ@gfx?2desert_tile?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR [edx+eax+48]
	mov	ecx, DWORD PTR [eax+8]
	add	ecx, 8
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 419  : 		SetStr(&gli->l[i].map_info->fName[3], "gfx\\grasslands_tile.bmp");

	push	OFFSET FLAT:??_C@_0BI@FCCB@gfx?2grasslands_tile?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx+8]
	add	eax, 12					; 0000000cH
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 420  : 		SetStr(&gli->l[i].map_info->fName[4], "gfx\\forest_tile.bmp");

	push	OFFSET FLAT:??_C@_0BE@HDAC@gfx?2forest_tile?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [eax+ecx+48]
	mov	edx, DWORD PTR [ecx+8]
	add	edx, 16					; 00000010H
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 421  : 		SetStr(&gli->l[i].map_info->fName[5], "gfx\\camp_tile1.bmp");

	push	OFFSET FLAT:??_C@_0BD@OAIF@gfx?2camp_tile1?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR [edx+eax+48]
	mov	ecx, DWORD PTR [eax+8]
	add	ecx, 20					; 00000014H
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 422  : 		SetStr(&gli->l[i].map_info->fName[6], "gfx\\safe_tile.bmp");

	push	OFFSET FLAT:??_C@_0BC@BFGG@gfx?2safe_tile?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx+8]
	add	eax, 24					; 00000018H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 423  : 		SetStr(&gli->l[i].map_info->fName[7], "gfx\\bridge_tile.bmp");

	push	OFFSET FLAT:??_C@_0BE@CNMC@gfx?2bridge_tile?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR [eax+ecx+48]
	mov	edx, DWORD PTR [ecx+8]
	add	edx, 28					; 0000001cH
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 424  : 		SetStr(&gli->l[i].map_info->fName[8], "gfx\\mountain.bmp");

	push	OFFSET FLAT:??_C@_0BB@DMFI@gfx?2mountain?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR [edx+eax+48]
	mov	ecx, DWORD PTR [eax+8]
	add	ecx, 32					; 00000020H
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 425  : 		SetStr(&gli->l[i].map_info->fName[9], "gfx\\cavern.bmp");

	push	OFFSET FLAT:??_C@_0P@LGEO@gfx?2cavern?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR [edx+8]
	add	eax, 36					; 00000024H
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 426  : /*
; 427  : 			{0,0,0,0,0, 0,1,0,0,0}, 
; 428  : 			{0,6,2,3,7, 3,3,0,0,0},
; 429  : 			{0,2,2,2,0, 0,0,3,0,0},
; 430  : 			{0,3,2,2,2, 3,3,3,3,0},
; 431  : 			{0,3,2,2,2, 2,3,3,3,0},
; 432  : 
; 433  : 			{0,3,0,2,0, 0,2,2,3,0},
; 434  : 			{0,3,3,0,3, 3,0,2,3,0},
; 435  : 			{0,0,0,0,4, 3,3,0,3,0},
; 436  : 			{5,4,4,4,4, 3,3,3,3,0},
; 437  : 			{0,0,0,0,0, 0,0,0,0,0}
; 438  : */
; 439  : 		gli->l[i].w = 20;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+10], 20		; 00000014H

; 440  : 		gli->l[i].h = 10;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+12], 10		; 0000000aH

; 441  : 		unsigned __int8 a[10][20] =
; 442  : 		{
; 443  : 			{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,1,0,0,0}, 

	mov	BYTE PTR _a$65029[ebp], 0
	mov	BYTE PTR _a$65029[ebp+1], 0
	mov	BYTE PTR _a$65029[ebp+2], 0
	mov	BYTE PTR _a$65029[ebp+3], 0
	mov	BYTE PTR _a$65029[ebp+4], 0
	mov	BYTE PTR _a$65029[ebp+5], 0
	mov	BYTE PTR _a$65029[ebp+6], 0
	mov	BYTE PTR _a$65029[ebp+7], 0
	mov	BYTE PTR _a$65029[ebp+8], 0
	mov	BYTE PTR _a$65029[ebp+9], 0
	mov	BYTE PTR _a$65029[ebp+10], 0
	mov	BYTE PTR _a$65029[ebp+11], 0
	mov	BYTE PTR _a$65029[ebp+12], 0
	mov	BYTE PTR _a$65029[ebp+13], 0
	mov	BYTE PTR _a$65029[ebp+14], 0
	mov	BYTE PTR _a$65029[ebp+15], 0
	mov	BYTE PTR _a$65029[ebp+16], 1
	mov	BYTE PTR _a$65029[ebp+17], 0
	mov	BYTE PTR _a$65029[ebp+18], 0
	mov	BYTE PTR _a$65029[ebp+19], 0

; 444  : 			{0,8,9,8,8, 2,4,0,0,0, 0,6,2,3,7, 3,3,0,0,0},

	mov	BYTE PTR _a$65029[ebp+20], 0
	mov	BYTE PTR _a$65029[ebp+21], 8
	mov	BYTE PTR _a$65029[ebp+22], 9
	mov	BYTE PTR _a$65029[ebp+23], 8
	mov	BYTE PTR _a$65029[ebp+24], 8
	mov	BYTE PTR _a$65029[ebp+25], 2
	mov	BYTE PTR _a$65029[ebp+26], 4
	mov	BYTE PTR _a$65029[ebp+27], 0
	mov	BYTE PTR _a$65029[ebp+28], 0
	mov	BYTE PTR _a$65029[ebp+29], 0
	mov	BYTE PTR _a$65029[ebp+30], 0
	mov	BYTE PTR _a$65029[ebp+31], 6
	mov	BYTE PTR _a$65029[ebp+32], 2
	mov	BYTE PTR _a$65029[ebp+33], 3
	mov	BYTE PTR _a$65029[ebp+34], 7
	mov	BYTE PTR _a$65029[ebp+35], 3
	mov	BYTE PTR _a$65029[ebp+36], 3
	mov	BYTE PTR _a$65029[ebp+37], 0
	mov	BYTE PTR _a$65029[ebp+38], 0
	mov	BYTE PTR _a$65029[ebp+39], 0

; 445  : 			{0,8,2,2,2, 2,3,4,0,0, 0,2,2,2,0, 0,0,3,0,0},

	mov	BYTE PTR _a$65029[ebp+40], 0
	mov	BYTE PTR _a$65029[ebp+41], 8
	mov	BYTE PTR _a$65029[ebp+42], 2
	mov	BYTE PTR _a$65029[ebp+43], 2
	mov	BYTE PTR _a$65029[ebp+44], 2
	mov	BYTE PTR _a$65029[ebp+45], 2
	mov	BYTE PTR _a$65029[ebp+46], 3
	mov	BYTE PTR _a$65029[ebp+47], 4
	mov	BYTE PTR _a$65029[ebp+48], 0
	mov	BYTE PTR _a$65029[ebp+49], 0
	mov	BYTE PTR _a$65029[ebp+50], 0
	mov	BYTE PTR _a$65029[ebp+51], 2
	mov	BYTE PTR _a$65029[ebp+52], 2
	mov	BYTE PTR _a$65029[ebp+53], 2
	mov	BYTE PTR _a$65029[ebp+54], 0
	mov	BYTE PTR _a$65029[ebp+55], 0
	mov	BYTE PTR _a$65029[ebp+56], 0
	mov	BYTE PTR _a$65029[ebp+57], 3
	mov	BYTE PTR _a$65029[ebp+58], 0
	mov	BYTE PTR _a$65029[ebp+59], 0

; 446  : 			{0,8,8,8,2, 2,2,2,0,0, 0,3,2,2,2, 3,3,3,3,0},

	mov	BYTE PTR _a$65029[ebp+60], 0
	mov	BYTE PTR _a$65029[ebp+61], 8
	mov	BYTE PTR _a$65029[ebp+62], 8
	mov	BYTE PTR _a$65029[ebp+63], 8
	mov	BYTE PTR _a$65029[ebp+64], 2
	mov	BYTE PTR _a$65029[ebp+65], 2
	mov	BYTE PTR _a$65029[ebp+66], 2
	mov	BYTE PTR _a$65029[ebp+67], 2
	mov	BYTE PTR _a$65029[ebp+68], 0
	mov	BYTE PTR _a$65029[ebp+69], 0
	mov	BYTE PTR _a$65029[ebp+70], 0
	mov	BYTE PTR _a$65029[ebp+71], 3
	mov	BYTE PTR _a$65029[ebp+72], 2
	mov	BYTE PTR _a$65029[ebp+73], 2
	mov	BYTE PTR _a$65029[ebp+74], 2
	mov	BYTE PTR _a$65029[ebp+75], 3
	mov	BYTE PTR _a$65029[ebp+76], 3
	mov	BYTE PTR _a$65029[ebp+77], 3
	mov	BYTE PTR _a$65029[ebp+78], 3
	mov	BYTE PTR _a$65029[ebp+79], 0

; 447  : 			{0,2,2,2,2, 2,2,8,0,0, 0,3,2,2,2, 2,3,3,3,0},

	mov	BYTE PTR _a$65029[ebp+80], 0
	mov	BYTE PTR _a$65029[ebp+81], 2
	mov	BYTE PTR _a$65029[ebp+82], 2
	mov	BYTE PTR _a$65029[ebp+83], 2
	mov	BYTE PTR _a$65029[ebp+84], 2
	mov	BYTE PTR _a$65029[ebp+85], 2
	mov	BYTE PTR _a$65029[ebp+86], 2
	mov	BYTE PTR _a$65029[ebp+87], 8
	mov	BYTE PTR _a$65029[ebp+88], 0
	mov	BYTE PTR _a$65029[ebp+89], 0
	mov	BYTE PTR _a$65029[ebp+90], 0
	mov	BYTE PTR _a$65029[ebp+91], 3
	mov	BYTE PTR _a$65029[ebp+92], 2
	mov	BYTE PTR _a$65029[ebp+93], 2
	mov	BYTE PTR _a$65029[ebp+94], 2
	mov	BYTE PTR _a$65029[ebp+95], 2
	mov	BYTE PTR _a$65029[ebp+96], 3
	mov	BYTE PTR _a$65029[ebp+97], 3
	mov	BYTE PTR _a$65029[ebp+98], 3
	mov	BYTE PTR _a$65029[ebp+99], 0

; 448  : 
; 449  : 			{0,2,8,8,8, 8,8,8,8,0, 0,3,0,2,0, 0,2,2,3,0},

	mov	BYTE PTR _a$65029[ebp+100], 0
	mov	BYTE PTR _a$65029[ebp+101], 2
	mov	BYTE PTR _a$65029[ebp+102], 8
	mov	BYTE PTR _a$65029[ebp+103], 8
	mov	BYTE PTR _a$65029[ebp+104], 8
	mov	BYTE PTR _a$65029[ebp+105], 8
	mov	BYTE PTR _a$65029[ebp+106], 8
	mov	BYTE PTR _a$65029[ebp+107], 8
	mov	BYTE PTR _a$65029[ebp+108], 8
	mov	BYTE PTR _a$65029[ebp+109], 0
	mov	BYTE PTR _a$65029[ebp+110], 0
	mov	BYTE PTR _a$65029[ebp+111], 3
	mov	BYTE PTR _a$65029[ebp+112], 0
	mov	BYTE PTR _a$65029[ebp+113], 2
	mov	BYTE PTR _a$65029[ebp+114], 0
	mov	BYTE PTR _a$65029[ebp+115], 0
	mov	BYTE PTR _a$65029[ebp+116], 2
	mov	BYTE PTR _a$65029[ebp+117], 2
	mov	BYTE PTR _a$65029[ebp+118], 3
	mov	BYTE PTR _a$65029[ebp+119], 0

; 450  : 			{0,3,8,8,4, 1,4,4,4,0, 0,3,3,0,3, 3,0,2,3,0},

	mov	BYTE PTR _a$65029[ebp+120], 0
	mov	BYTE PTR _a$65029[ebp+121], 3
	mov	BYTE PTR _a$65029[ebp+122], 8
	mov	BYTE PTR _a$65029[ebp+123], 8
	mov	BYTE PTR _a$65029[ebp+124], 4
	mov	BYTE PTR _a$65029[ebp+125], 1
	mov	BYTE PTR _a$65029[ebp+126], 4
	mov	BYTE PTR _a$65029[ebp+127], 4
	mov	BYTE PTR _a$65029[ebp+128], 4
	mov	BYTE PTR _a$65029[ebp+129], 0
	mov	BYTE PTR _a$65029[ebp+130], 0
	mov	BYTE PTR _a$65029[ebp+131], 3
	mov	BYTE PTR _a$65029[ebp+132], 3
	mov	BYTE PTR _a$65029[ebp+133], 0
	mov	BYTE PTR _a$65029[ebp+134], 3
	mov	BYTE PTR _a$65029[ebp+135], 3
	mov	BYTE PTR _a$65029[ebp+136], 0
	mov	BYTE PTR _a$65029[ebp+137], 2
	mov	BYTE PTR _a$65029[ebp+138], 3
	mov	BYTE PTR _a$65029[ebp+139], 0

; 451  : 			{0,3,3,4,4, 4,4,4,3,0, 0,0,0,0,4, 3,3,0,3,0},

	mov	BYTE PTR _a$65029[ebp+140], 0
	mov	BYTE PTR _a$65029[ebp+141], 3
	mov	BYTE PTR _a$65029[ebp+142], 3
	mov	BYTE PTR _a$65029[ebp+143], 4
	mov	BYTE PTR _a$65029[ebp+144], 4
	mov	BYTE PTR _a$65029[ebp+145], 4
	mov	BYTE PTR _a$65029[ebp+146], 4
	mov	BYTE PTR _a$65029[ebp+147], 4
	mov	BYTE PTR _a$65029[ebp+148], 3
	mov	BYTE PTR _a$65029[ebp+149], 0
	mov	BYTE PTR _a$65029[ebp+150], 0
	mov	BYTE PTR _a$65029[ebp+151], 0
	mov	BYTE PTR _a$65029[ebp+152], 0
	mov	BYTE PTR _a$65029[ebp+153], 0
	mov	BYTE PTR _a$65029[ebp+154], 4
	mov	BYTE PTR _a$65029[ebp+155], 3
	mov	BYTE PTR _a$65029[ebp+156], 3
	mov	BYTE PTR _a$65029[ebp+157], 0
	mov	BYTE PTR _a$65029[ebp+158], 3
	mov	BYTE PTR _a$65029[ebp+159], 0

; 452  : 			{0,0,3,4,4, 4,4,3,3,7, 5,4,4,4,4, 3,3,3,3,0},

	mov	BYTE PTR _a$65029[ebp+160], 0
	mov	BYTE PTR _a$65029[ebp+161], 0
	mov	BYTE PTR _a$65029[ebp+162], 3
	mov	BYTE PTR _a$65029[ebp+163], 4
	mov	BYTE PTR _a$65029[ebp+164], 4
	mov	BYTE PTR _a$65029[ebp+165], 4
	mov	BYTE PTR _a$65029[ebp+166], 4
	mov	BYTE PTR _a$65029[ebp+167], 3
	mov	BYTE PTR _a$65029[ebp+168], 3
	mov	BYTE PTR _a$65029[ebp+169], 7
	mov	BYTE PTR _a$65029[ebp+170], 5
	mov	BYTE PTR _a$65029[ebp+171], 4
	mov	BYTE PTR _a$65029[ebp+172], 4
	mov	BYTE PTR _a$65029[ebp+173], 4
	mov	BYTE PTR _a$65029[ebp+174], 4
	mov	BYTE PTR _a$65029[ebp+175], 3
	mov	BYTE PTR _a$65029[ebp+176], 3
	mov	BYTE PTR _a$65029[ebp+177], 3
	mov	BYTE PTR _a$65029[ebp+178], 3
	mov	BYTE PTR _a$65029[ebp+179], 0

; 453  : 			{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0}

	mov	BYTE PTR _a$65029[ebp+180], 0
	mov	BYTE PTR _a$65029[ebp+181], 0
	mov	BYTE PTR _a$65029[ebp+182], 0
	mov	BYTE PTR _a$65029[ebp+183], 0
	mov	BYTE PTR _a$65029[ebp+184], 0
	mov	BYTE PTR _a$65029[ebp+185], 0
	mov	BYTE PTR _a$65029[ebp+186], 0
	mov	BYTE PTR _a$65029[ebp+187], 0
	mov	BYTE PTR _a$65029[ebp+188], 0
	mov	BYTE PTR _a$65029[ebp+189], 0
	mov	BYTE PTR _a$65029[ebp+190], 0
	mov	BYTE PTR _a$65029[ebp+191], 0
	mov	BYTE PTR _a$65029[ebp+192], 0
	mov	BYTE PTR _a$65029[ebp+193], 0
	mov	BYTE PTR _a$65029[ebp+194], 0
	mov	BYTE PTR _a$65029[ebp+195], 0
	mov	BYTE PTR _a$65029[ebp+196], 0
	mov	BYTE PTR _a$65029[ebp+197], 0
	mov	BYTE PTR _a$65029[ebp+198], 0
	mov	BYTE PTR _a$65029[ebp+199], 0

; 454  : 		};
; 455  : 
; 456  : 		for(j = 0; j < gli->l[i].h; j++)

	mov	BYTE PTR _j$[ebp], 0
	jmp	SHORT $L65030
$L65031:
	mov	cl, BYTE PTR _j$[ebp]
	add	cl, 1
	mov	BYTE PTR _j$[ebp], cl
$L65030:
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [ecx+12]
	xor	esi, esi
	mov	si, WORD PTR [ecx+eax+12]
	cmp	edx, esi
	jge	SHORT $L65032

; 457  : 			SetArray(&gli->l[i].map_info->data[j], &a[j][0], gli->l[i].w);

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	dx, WORD PTR [ecx+edx+10]
	push	edx
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 20					; 00000014H
	lea	ecx, DWORD PTR _a$65029[ebp+eax]
	push	ecx
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR [edx]
	lea	edx, DWORD PTR [ecx+eax*4]
	push	edx
	call	?SetArray@@YAXPAPA_EPA_E_G@Z		; SetArray
	add	esp, 12					; 0000000cH
	jmp	$L65031
$L65032:

; 458  : 		i++;

	mov	al, BYTE PTR _i$[ebp]
	add	al, 1
	mov	BYTE PTR _i$[ebp], al

; 459  : 	//
; 460  : 	//
; 461  : 		li = &gli->l[i];

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	add	eax, ecx
	mov	DWORD PTR _li$[ebp], eax

; 462  : 		SetStr(&li->Name, "Camp");

	push	OFFSET FLAT:??_C@_04HGOJ@Camp?$AA@	; `string'
	mov	ecx, DWORD PTR _li$[ebp]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 463  : 		li->type = LT_SPRITE;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+4], 2

; 464  : 		li->visable = true;

	mov	eax, DWORD PTR _li$[ebp]
	mov	BYTE PTR [eax+5], 1

; 465  : 		li->animate = true;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+44], 1

; 466  : 		li->x = 100;

	mov	edx, DWORD PTR _li$[ebp]
	mov	DWORD PTR [edx+16], 100			; 00000064H

; 467  : 		li->y = 180;

	mov	eax, DWORD PTR _li$[ebp]
	mov	DWORD PTR [eax+20], 180			; 000000b4H

; 468  : 		li->NumAnim = 1;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+45], 1

; 469  : 
; 470  : 		li->anim_info = new ANIM_INFO[li->NumAnim];

	mov	edx, DWORD PTR _li$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+45]
	imul	eax, 12					; 0000000cH
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65346[ebp], eax
	mov	ecx, DWORD PTR _li$[ebp]
	mov	edx, DWORD PTR $T65346[ebp]
	mov	DWORD PTR [ecx+48], edx

; 471  : 		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

	mov	eax, DWORD PTR _li$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+45]
	imul	ecx, 12					; 0000000cH
	push	ecx
	push	0
	mov	edx, DWORD PTR _li$[ebp]
	mov	eax, DWORD PTR [edx+48]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 472  : 
; 473  : 			ai = &li->anim_info[0];

	mov	ecx, DWORD PTR _li$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	DWORD PTR _ai$[ebp], edx

; 474  : 			SetStr(&ai->name, "fire");

	push	OFFSET FLAT:??_C@_04OLBH@fire?$AA@	; `string'
	mov	eax, DWORD PTR _ai$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 475  : 	
; 476  : 			ai->loop_type = LT_FOREVER;

	mov	ecx, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [ecx+4], 2

; 477  : 
; 478  : 			ai->nCel = 3;

	mov	edx, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [edx+6], 3

; 479  : 			ai->cel_info = new CEL_INFO[ai->nCel];

	mov	eax, DWORD PTR _ai$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+6]
	imul	ecx, 24					; 00000018H
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65347[ebp], eax
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR $T65347[ebp]
	mov	DWORD PTR [edx+8], eax

; 480  : 			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

	mov	ecx, DWORD PTR _ai$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+6]
	imul	edx, 24					; 00000018H
	push	edx
	push	0
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 481  : 
; 482  : 			j = 0;

	mov	BYTE PTR _j$[ebp], 0

; 483  : 				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+12], 20		; 00000014H
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+14], 20		; 00000014H

; 484  : 				ai->cel_info[j].delay = 100;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+edx], 100		; 00000064H

; 485  : 				SetStr(&ai->cel_info[j].fName, "gfx\\camp_tile1.bmp");

	push	OFFSET FLAT:??_C@_0BD@OAIF@gfx?2camp_tile1?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	lea	edx, DWORD PTR [ecx+edx+20]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 486  : 			j++;

	mov	al, BYTE PTR _j$[ebp]
	add	al, 1
	mov	BYTE PTR _j$[ebp], al

; 487  : 				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+12], 20		; 00000014H
	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+14], 20		; 00000014H

; 488  : 				ai->cel_info[j].delay = 100;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+ecx], 100		; 00000064H

; 489  : 				SetStr(&ai->cel_info[j].fName, "gfx\\camp_tile2.bmp");

	push	OFFSET FLAT:??_C@_0BD@OK@gfx?2camp_tile2?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	lea	ecx, DWORD PTR [eax+ecx+20]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 490  : 			j++;

	mov	dl, BYTE PTR _j$[ebp]
	add	dl, 1
	mov	BYTE PTR _j$[ebp], dl

; 491  : 				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+12], 20		; 00000014H
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+14], 20		; 00000014H

; 492  : 				ai->cel_info[j].delay = 100;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [edx+eax], 100		; 00000064H

; 493  : 				SetStr(&ai->cel_info[j].fName, "gfx\\camp_tile3.bmp");

	push	OFFSET FLAT:??_C@_0BD@KAMP@gfx?2camp_tile3?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	lea	eax, DWORD PTR [edx+eax+20]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 494  : 		i++;

	mov	cl, BYTE PTR _i$[ebp]
	add	cl, 1
	mov	BYTE PTR _i$[ebp], cl

; 495  : //
; 496  : 		li = &gli->l[i];

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	add	ecx, edx
	mov	DWORD PTR _li$[ebp], ecx

; 497  : 		SetStr(&li->Name, "RedGoo");

	push	OFFSET FLAT:??_C@_06DJMK@RedGoo?$AA@	; `string'
	mov	edx, DWORD PTR _li$[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 498  : 		li->type = LT_SPRITE;

	mov	eax, DWORD PTR _li$[ebp]
	mov	BYTE PTR [eax+4], 2

; 499  : 		li->visable = false;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+5], 0

; 500  : 		li->animate = false;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+44], 0

; 501  : 		li->moveable = false;

	mov	eax, DWORD PTR _li$[ebp]
	mov	BYTE PTR [eax+6], 0

; 502  : 		li->collidable = true;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+9], 1

; 503  : 		li->move_type = LT_ONCE;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+7], 0

; 504  : 		li->x = 140;

	mov	eax, DWORD PTR _li$[ebp]
	mov	DWORD PTR [eax+16], 140			; 0000008cH

; 505  : 		li->y = 40;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	DWORD PTR [ecx+20], 40			; 00000028H

; 506  : 		li->hx = -100;

	mov	edx, DWORD PTR _li$[ebp]
	mov	WORD PTR [edx+40], -100			; ffffff9cH

; 507  : 		li->hy = -20;

	mov	eax, DWORD PTR _li$[ebp]
	mov	WORD PTR [eax+42], -20			; ffffffecH

; 508  : 		li->NumAnim = 1;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+45], 1

; 509  : 
; 510  : 		li->anim_info = new ANIM_INFO[li->NumAnim];

	mov	edx, DWORD PTR _li$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+45]
	imul	eax, 12					; 0000000cH
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65348[ebp], eax
	mov	ecx, DWORD PTR _li$[ebp]
	mov	edx, DWORD PTR $T65348[ebp]
	mov	DWORD PTR [ecx+48], edx

; 511  : 		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

	mov	eax, DWORD PTR _li$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+45]
	imul	ecx, 12					; 0000000cH
	push	ecx
	push	0
	mov	edx, DWORD PTR _li$[ebp]
	mov	eax, DWORD PTR [edx+48]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 512  : 
; 513  : 			ai = &li->anim_info[0];

	mov	ecx, DWORD PTR _li$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	DWORD PTR _ai$[ebp], edx

; 514  : 			SetStr(&ai->name, "walk");

	push	OFFSET FLAT:??_C@_04IBJ@walk?$AA@	; `string'
	mov	eax, DWORD PTR _ai$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 515  : 	
; 516  : 			ai->loop_type = LT_FOREVER;

	mov	ecx, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [ecx+4], 2

; 517  : 
; 518  : 			ai->nCel = 2;

	mov	edx, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [edx+6], 2

; 519  : 			ai->cel_info = new CEL_INFO[ai->nCel];

	mov	eax, DWORD PTR _ai$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+6]
	imul	ecx, 24					; 00000018H
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65349[ebp], eax
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR $T65349[ebp]
	mov	DWORD PTR [edx+8], eax

; 520  : 			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

	mov	ecx, DWORD PTR _ai$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+6]
	imul	edx, 24					; 00000018H
	push	edx
	push	0
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 521  : 
; 522  : 			j = 0;

	mov	BYTE PTR _j$[ebp], 0

; 523  : 				ai->cel_info[j].hx = -100;	ai->cel_info[j].hy = -20;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+4], -100		; ffffff9cH
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+6], -20		; ffffffecH

; 524  : 				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+12], 20		; 00000014H
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+14], 20		; 00000014H

; 525  : 				ai->cel_info[j].delay = 100;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+edx], 100		; 00000064H

; 526  : 				SetStr(&ai->cel_info[j].fName, "gfx\\red_goo1.bmp");

	push	OFFSET FLAT:??_C@_0BB@PCC@gfx?2red_goo1?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	lea	edx, DWORD PTR [ecx+edx+20]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 527  : 			j++;

	mov	al, BYTE PTR _j$[ebp]
	add	al, 1
	mov	BYTE PTR _j$[ebp], al

; 528  : 				ai->cel_info[j].hx = -100;	ai->cel_info[j].hy = -20;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+4], -100		; ffffff9cH
	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+6], -20		; ffffffecH

; 529  : 				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+12], 20		; 00000014H
	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+14], 20		; 00000014H

; 530  : 				ai->cel_info[j].delay = 100;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+ecx], 100		; 00000064H

; 531  : 				SetStr(&ai->cel_info[j].fName, "gfx\\red_goo2.bmp");

	push	OFFSET FLAT:??_C@_0BB@OPEN@gfx?2red_goo2?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	lea	ecx, DWORD PTR [eax+ecx+20]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 532  : 		i++;

	mov	dl, BYTE PTR _i$[ebp]
	add	dl, 1
	mov	BYTE PTR _i$[ebp], dl

; 533  : 
; 534  : 		li = &gli->l[i];

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	mov	DWORD PTR _li$[ebp], edx

; 535  : 		SetStr(&li->Name, "BlueGoo");

	push	OFFSET FLAT:??_C@_07NIEJ@BlueGoo?$AA@	; `string'
	mov	eax, DWORD PTR _li$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 536  : 		li->type = LT_SPRITE;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+4], 2

; 537  : 		li->visable = false;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+5], 0

; 538  : 		li->animate = false;

	mov	eax, DWORD PTR _li$[ebp]
	mov	BYTE PTR [eax+44], 0

; 539  : 		li->moveable = false;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+6], 0

; 540  : 		li->collidable = true;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+9], 1

; 541  : 		li->move_type = LT_ONCE;

	mov	eax, DWORD PTR _li$[ebp]
	mov	BYTE PTR [eax+7], 0

; 542  : 		li->x = 40;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	DWORD PTR [ecx+16], 40			; 00000028H

; 543  : 		li->y = 80;

	mov	edx, DWORD PTR _li$[ebp]
	mov	DWORD PTR [edx+20], 80			; 00000050H

; 544  : 		li->hx = -100;

	mov	eax, DWORD PTR _li$[ebp]
	mov	WORD PTR [eax+40], -100			; ffffff9cH

; 545  : 		li->hy = -20;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	WORD PTR [ecx+42], -20			; ffffffecH

; 546  : 		li->NumAnim = 1;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+45], 1

; 547  : 
; 548  : 		li->anim_info = new ANIM_INFO[li->NumAnim];

	mov	eax, DWORD PTR _li$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+45]
	imul	ecx, 12					; 0000000cH
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65350[ebp], eax
	mov	edx, DWORD PTR _li$[ebp]
	mov	eax, DWORD PTR $T65350[ebp]
	mov	DWORD PTR [edx+48], eax

; 549  : 		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

	mov	ecx, DWORD PTR _li$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+45]
	imul	edx, 12					; 0000000cH
	push	edx
	push	0
	mov	eax, DWORD PTR _li$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 550  : 
; 551  : 			ai = &li->anim_info[0];

	mov	edx, DWORD PTR _li$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	DWORD PTR _ai$[ebp], eax

; 552  : 			SetStr(&ai->name, "walk");

	push	OFFSET FLAT:??_C@_04IBJ@walk?$AA@	; `string'
	mov	ecx, DWORD PTR _ai$[ebp]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 553  : 	
; 554  : 			ai->loop_type = LT_FOREVER;

	mov	edx, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [edx+4], 2

; 555  : 
; 556  : 			ai->nCel = 2;

	mov	eax, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [eax+6], 2

; 557  : 			ai->cel_info = new CEL_INFO[ai->nCel];

	mov	ecx, DWORD PTR _ai$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+6]
	imul	edx, 24					; 00000018H
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65351[ebp], eax
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR $T65351[ebp]
	mov	DWORD PTR [eax+8], ecx

; 558  : 			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

	mov	edx, DWORD PTR _ai$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	imul	eax, 24					; 00000018H
	push	eax
	push	0
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 559  : 
; 560  : 			j = 0;

	mov	BYTE PTR _j$[ebp], 0

; 561  : 				ai->cel_info[j].hx = -100;	ai->cel_info[j].hy = -20;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+4], -100		; ffffff9cH
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+6], -20		; ffffffecH

; 562  : 				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+12], 20		; 00000014H
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+14], 20		; 00000014H

; 563  : 				ai->cel_info[j].delay = 100;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [edx+eax], 100		; 00000064H

; 564  : 				SetStr(&ai->cel_info[j].fName, "gfx\\blue_goo1.bmp");

	push	OFFSET FLAT:??_C@_0BC@PIDO@gfx?2blue_goo1?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	lea	eax, DWORD PTR [edx+eax+20]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 565  : 			j++;

	mov	cl, BYTE PTR _j$[ebp]
	add	cl, 1
	mov	BYTE PTR _j$[ebp], cl

; 566  : 				ai->cel_info[j].hx = -100;	ai->cel_info[j].hy = -20;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+4], -100		; ffffff9cH
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+6], -20		; ffffffecH

; 567  : 				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+12], 20		; 00000014H
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+14], 20		; 00000014H

; 568  : 				ai->cel_info[j].delay = 100;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+edx], 100		; 00000064H

; 569  : 				SetStr(&ai->cel_info[j].fName, "gfx\\blue_goo2.bmp");

	push	OFFSET FLAT:??_C@_0BC@BIFB@gfx?2blue_goo2?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	lea	edx, DWORD PTR [ecx+edx+20]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 570  : 		i++;

	mov	al, BYTE PTR _i$[ebp]
	add	al, 1
	mov	BYTE PTR _i$[ebp], al

; 571  : 
; 572  : 		li = &gli->l[i];

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	add	eax, ecx
	mov	DWORD PTR _li$[ebp], eax

; 573  : 		SetStr(&li->Name, "Super");

	push	OFFSET FLAT:??_C@_05COAO@Super?$AA@	; `string'
	mov	ecx, DWORD PTR _li$[ebp]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 574  : 		li->type = LT_SPRITE;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+4], 2

; 575  : 		li->visable = false;

	mov	eax, DWORD PTR _li$[ebp]
	mov	BYTE PTR [eax+5], 0

; 576  : 		li->animate = false;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+44], 0

; 577  : 		li->moveable = false;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+6], 0

; 578  : 		li->collidable = true;

	mov	eax, DWORD PTR _li$[ebp]
	mov	BYTE PTR [eax+9], 1

; 579  : 		li->move_type = LT_ONCE;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+7], 0

; 580  : 		li->x = 20;

	mov	edx, DWORD PTR _li$[ebp]
	mov	DWORD PTR [edx+16], 20			; 00000014H

; 581  : 		li->y = 20;

	mov	eax, DWORD PTR _li$[ebp]
	mov	DWORD PTR [eax+20], 20			; 00000014H

; 582  : 		li->hx = -100;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	WORD PTR [ecx+40], -100			; ffffff9cH

; 583  : 		li->hy = -20;

	mov	edx, DWORD PTR _li$[ebp]
	mov	WORD PTR [edx+42], -20			; ffffffecH

; 584  : 		li->NumAnim = 1;

	mov	eax, DWORD PTR _li$[ebp]
	mov	BYTE PTR [eax+45], 1

; 585  : 
; 586  : 		li->anim_info = new ANIM_INFO[li->NumAnim];

	mov	ecx, DWORD PTR _li$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+45]
	imul	edx, 12					; 0000000cH
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65352[ebp], eax
	mov	eax, DWORD PTR _li$[ebp]
	mov	ecx, DWORD PTR $T65352[ebp]
	mov	DWORD PTR [eax+48], ecx

; 587  : 		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

	mov	edx, DWORD PTR _li$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+45]
	imul	eax, 12					; 0000000cH
	push	eax
	push	0
	mov	ecx, DWORD PTR _li$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 588  : 
; 589  : 			ai = &li->anim_info[0];

	mov	eax, DWORD PTR _li$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	mov	DWORD PTR _ai$[ebp], ecx

; 590  : 			SetStr(&ai->name, "walk");

	push	OFFSET FLAT:??_C@_04IBJ@walk?$AA@	; `string'
	mov	edx, DWORD PTR _ai$[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 591  : 	
; 592  : 			ai->loop_type = LT_FOREVER;

	mov	eax, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [eax+4], 2

; 593  : 
; 594  : 			ai->nCel = 2;

	mov	ecx, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [ecx+6], 2

; 595  : 			ai->cel_info = new CEL_INFO[ai->nCel];

	mov	edx, DWORD PTR _ai$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	imul	eax, 24					; 00000018H
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65353[ebp], eax
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR $T65353[ebp]
	mov	DWORD PTR [ecx+8], edx

; 596  : 			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

	mov	eax, DWORD PTR _ai$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+6]
	imul	ecx, 24					; 00000018H
	push	ecx
	push	0
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 597  : 
; 598  : 			j = 0;

	mov	BYTE PTR _j$[ebp], 0

; 599  : 				ai->cel_info[j].hx = -100;	ai->cel_info[j].hy = -20;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+4], -100		; ffffff9cH
	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+6], -20		; ffffffecH

; 600  : 				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+12], 20		; 00000014H
	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+14], 20		; 00000014H

; 601  : 				ai->cel_info[j].delay = 100;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+ecx], 100		; 00000064H

; 602  : 				SetStr(&ai->cel_info[j].fName, "gfx\\sn_map1.bmp");

	push	OFFSET FLAT:??_C@_0BA@JLOJ@gfx?2sn_map1?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	lea	ecx, DWORD PTR [eax+ecx+20]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 603  : 			j++;

	mov	dl, BYTE PTR _j$[ebp]
	add	dl, 1
	mov	BYTE PTR _j$[ebp], dl

; 604  : 				ai->cel_info[j].hx = -100;	ai->cel_info[j].hy = -20;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+4], -100		; ffffff9cH
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+6], -20		; ffffffecH

; 605  : 				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+12], 20		; 00000014H
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+14], 20		; 00000014H

; 606  : 				ai->cel_info[j].delay = 100;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [edx+eax], 100		; 00000064H

; 607  : 				SetStr(&ai->cel_info[j].fName, "gfx\\sn_map2.bmp");

	push	OFFSET FLAT:??_C@_0BA@HLIG@gfx?2sn_map2?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	lea	eax, DWORD PTR [edx+eax+20]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 608  : 		i++;

	mov	cl, BYTE PTR _i$[ebp]
	add	cl, 1
	mov	BYTE PTR _i$[ebp], cl

; 609  : 
; 610  : 	//
; 611  : 	//
; 612  : 		SetStr(&gli->l[i].Name, "menu");

	push	OFFSET FLAT:??_C@_04FKLJ@menu?$AA@	; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	add	ecx, edx
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 613  : 		gli->l[i].visable = true;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+5], 1

; 614  : 		gli->l[i].type = LT_IMAGE;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+4], 1

; 615  : 		gli->l[i].x = 19;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+16], 19		; 00000013H

; 616  : 		gli->l[i].y = 100;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+20], 100		; 00000064H

; 617  : 		gli->l[i].w = 60;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+10], 60		; 0000003cH

; 618  : 		gli->l[i].h = 83;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+12], 83		; 00000053H

; 619  : 		SetStr(&gli->l[i].fName, "gfx\\map_menu.bmp");

	push	OFFSET FLAT:??_C@_0BB@DCJH@gfx?2map_menu?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	lea	edx, DWORD PTR [ecx+edx+48]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 620  : 		i++;

	mov	al, BYTE PTR _i$[ebp]
	add	al, 1
	mov	BYTE PTR _i$[ebp], al

; 621  : 
; 622  : 	//
; 623  : 	//
; 624  : 	//
; 625  : 		SetStr(&gli->l[i].Name, "sStat");

	push	OFFSET FLAT:??_C@_05LCII@sStat?$AA@	; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	add	eax, ecx
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 626  : 		gli->l[i].visable = false;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+5], 0

; 627  : 		gli->l[i].type = LT_IMAGE;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+4], 1

; 628  : 		gli->l[i].x = 0;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+ecx+16], 0

; 629  : 		gli->l[i].y = 0;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+ecx+20], 0

; 630  : 		gli->l[i].w = 320;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+10], 320		; 00000140H

; 631  : 		gli->l[i].h = 240;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+12], 240		; 000000f0H

; 632  : 		SetStr(&gli->l[i].fName, "gfx\\sninja_stat_menu.bmp");

	push	OFFSET FLAT:??_C@_0BJ@GKNC@gfx?2sninja_stat_menu?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	lea	ecx, DWORD PTR [eax+ecx+48]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 633  : 		i++;

	mov	dl, BYTE PTR _i$[ebp]
	add	dl, 1
	mov	BYTE PTR _i$[ebp], dl

; 634  : 	//
; 635  : 	//
; 636  : 	//
; 637  : 		SetStr(&gli->l[i].Name, "rStat");

	push	OFFSET FLAT:??_C@_05BCKN@rStat?$AA@	; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 638  : 		gli->l[i].visable = false;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+5], 0

; 639  : 		gli->l[i].type = LT_IMAGE;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+4], 1

; 640  : 		gli->l[i].x = 0;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+16], 0

; 641  : 		gli->l[i].y = 0;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+20], 0

; 642  : 		gli->l[i].w = 320;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+10], 320		; 00000140H

; 643  : 		gli->l[i].h = 240;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+12], 240		; 000000f0H

; 644  : 		SetStr(&gli->l[i].fName, "gfx\\red_stat_menu.bmp");

	push	OFFSET FLAT:??_C@_0BG@CHBC@gfx?2red_stat_menu?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	lea	eax, DWORD PTR [edx+eax+48]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 645  : 		i++;

	mov	cl, BYTE PTR _i$[ebp]
	add	cl, 1
	mov	BYTE PTR _i$[ebp], cl

; 646  : 	//
; 647  : 	//
; 648  : 	//
; 649  : 		SetStr(&gli->l[i].Name, "sPic");

	push	OFFSET FLAT:??_C@_04LEEA@sPic?$AA@	; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	add	ecx, edx
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 650  : 		gli->l[i].visable = false;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+5], 0

; 651  : 		gli->l[i].type = LT_IMAGE;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+4], 1

; 652  : 		gli->l[i].x = 1;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+16], 1

; 653  : 		gli->l[i].y = 26;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+20], 26		; 0000001aH

; 654  : 		gli->l[i].w = 78;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+10], 78		; 0000004eH

; 655  : 		gli->l[i].h = 66;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+12], 66		; 00000042H

; 656  : 		SetStr(&gli->l[i].fName, "gfx\\sninja_pic.bmp");

	push	OFFSET FLAT:??_C@_0BD@BHAO@gfx?2sninja_pic?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	lea	edx, DWORD PTR [ecx+edx+48]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 657  : 		i++;

	mov	al, BYTE PTR _i$[ebp]
	add	al, 1
	mov	BYTE PTR _i$[ebp], al

; 658  : 	//
; 659  : 	//
; 660  : 	//
; 661  : 		SetStr(&gli->l[i].Name, "rPic");

	push	OFFSET FLAT:??_C@_04JBBC@rPic?$AA@	; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	add	eax, ecx
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 662  : 		gli->l[i].visable = false;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+5], 0

; 663  : 		gli->l[i].type = LT_IMAGE;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+4], 1

; 664  : 		gli->l[i].x = 1;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+ecx+16], 1

; 665  : 		gli->l[i].y = 26;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+ecx+20], 26		; 0000001aH

; 666  : 		gli->l[i].w = 78;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+10], 78		; 0000004eH

; 667  : 		gli->l[i].h = 66;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+12], 66		; 00000042H

; 668  : 		SetStr(&gli->l[i].fName, "gfx\\red_pic.bmp");

	push	OFFSET FLAT:??_C@_0BA@FPGN@gfx?2red_pic?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	lea	ecx, DWORD PTR [eax+ecx+48]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 669  : 		i++;

	mov	dl, BYTE PTR _i$[ebp]
	add	dl, 1
	mov	BYTE PTR _i$[ebp], dl

; 670  : 
; 671  : 		//
; 672  : 		gli->l[i].visable = false;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+5], 0

; 673  : 		gli->l[i].type = LT_TILE;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+4], 3

; 674  : 		gli->l[i].x = 0;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+16], 0

; 675  : 		gli->l[i].y = 26;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+20], 26		; 0000001aH

; 676  : 		gli->l[i].w = 10;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+10], 10		; 0000000aH

; 677  : 		gli->l[i].h = 20;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+12], 20		; 00000014H

; 678  : 		gli->l[i].tile_image_w = 8;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+44], 8

; 679  : 		gli->l[i].tile_image_h = 8;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+45], 8

; 680  : 
; 681  : 		gli->l[i].tile_info = new TILE_INFO;

	push	8
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65354[ebp], eax
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	ecx, DWORD PTR $T65354[ebp]
	mov	DWORD PTR [edx+eax+48], ecx

; 682  : 		SetStr(&gli->l[i].tile_info->fName, "gfx\\dark.bmp");

	push	OFFSET FLAT:??_C@_0N@LOKF@gfx?2dark?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	edx, DWORD PTR [ecx+edx+48]
	add	edx, 4
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 683  : 		SetStr(&gli->l[i].Name, "gray");

	push	OFFSET FLAT:??_C@_04IPGD@gray?$AA@	; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 684  : 		i++;

	mov	al, BYTE PTR _i$[ebp]
	add	al, 1
	mov	BYTE PTR _i$[ebp], al

; 686  : 	else if(LevelNum == 4)

	jmp	$L65086
$L65003:
	mov	ecx, DWORD PTR _LevelNum$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 4
	jne	$L65086

; 688  : 		gli->l[i].visable = true;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+5], 1

; 689  : 		gli->l[i].type = LT_IMAGE;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	BYTE PTR [ecx+edx+4], 1

; 690  : 		gli->l[i].x = 0;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+16], 0

; 691  : 		gli->l[i].y = 0;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [ecx+edx+20], 0

; 692  : 		gli->l[i].w = 320;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+10], 320		; 00000140H

; 693  : 		gli->l[i].h = 135;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	WORD PTR [ecx+edx+12], 135		; 00000087H

; 694  : 		SetStr(&gli->l[i].fName, "gfx\\fight\\land01a.bmp");

	push	OFFSET FLAT:??_C@_0BG@KCBA@gfx?2fight?2land01a?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	lea	edx, DWORD PTR [ecx+edx+48]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 695  : 		SetStr(&gli->l[i].Name, "LandA");

	push	OFFSET FLAT:??_C@_05MCMJ@LandA?$AA@	; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 696  : 		i++;

	mov	al, BYTE PTR _i$[ebp]
	add	al, 1
	mov	BYTE PTR _i$[ebp], al

; 697  : 
; 698  : 		gli->l[i].visable = true;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+5], 1

; 699  : 		gli->l[i].type = LT_IMAGE;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	BYTE PTR [eax+ecx+4], 1

; 700  : 		gli->l[i].x = 0;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+ecx+16], 0

; 701  : 		gli->l[i].y = 135;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [eax+ecx+20], 135		; 00000087H

; 702  : 		gli->l[i].w = 320;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+10], 320		; 00000140H

; 703  : 		gli->l[i].h = 105;

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	WORD PTR [eax+ecx+12], 105		; 00000069H

; 704  : 		SetStr(&gli->l[i].fName, "gfx\\fight\\land01b.bmp");

	push	OFFSET FLAT:??_C@_0BG@ECHP@gfx?2fight?2land01b?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	lea	ecx, DWORD PTR [eax+ecx+48]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 705  : 		SetStr(&gli->l[i].Name, "LandB");

	push	OFFSET FLAT:??_C@_05DNHA@LandB?$AA@	; `string'
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	add	ecx, edx
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 706  : 		i++;

	mov	dl, BYTE PTR _i$[ebp]
	add	dl, 1
	mov	BYTE PTR _i$[ebp], dl

; 707  : 
; 708  : 		//
; 709  : 		//
; 710  : 		gli->l[i].visable = true;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+5], 1

; 711  : 		gli->l[i].type = LT_IMAGE;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+4], 1

; 712  : 		gli->l[i].x = 0;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+16], 0

; 713  : 		gli->l[i].y = 142;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+20], 142		; 0000008eH

; 714  : 		gli->l[i].w = 147;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+10], 147		; 00000093H

; 715  : 		gli->l[i].h = 99;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+12], 99		; 00000063H

; 716  : 		SetStr(&gli->l[i].fName, "gfx\\fight\\tab.bmp");

	push	OFFSET FLAT:??_C@_0BC@CLF@gfx?2fight?2tab?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	lea	eax, DWORD PTR [edx+eax+48]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 717  : 		SetStr(&gli->l[i].Name, "Tab");

	push	OFFSET FLAT:??_C@_03CHMJ@Tab?$AA@	; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	add	eax, ecx
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 718  : 		i++;

	mov	cl, BYTE PTR _i$[ebp]
	add	cl, 1
	mov	BYTE PTR _i$[ebp], cl

; 719  : 
; 720  : 		//
; 721  : 		//
; 722  : 		//
; 723  : 		li = &gli->l[i];

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	add	ecx, edx
	mov	DWORD PTR _li$[ebp], ecx

; 724  : 		SetStr(&li->Name, "Lupi");

	push	OFFSET FLAT:??_C@_04LFF@Lupi?$AA@	; `string'
	mov	edx, DWORD PTR _li$[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 725  : 		li->type = LT_SPRITE;

	mov	eax, DWORD PTR _li$[ebp]
	mov	BYTE PTR [eax+4], 2

; 726  : 		li->visable = true;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+5], 1

; 727  : 		li->animate = true;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+44], 1

; 728  : 		li->x = 146;

	mov	eax, DWORD PTR _li$[ebp]
	mov	DWORD PTR [eax+16], 146			; 00000092H

; 729  : 		li->y = 80;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	DWORD PTR [ecx+20], 80			; 00000050H

; 730  : 		li->NumAnim = 1;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+45], 1

; 731  : 
; 732  : 		li->anim_info = new ANIM_INFO[li->NumAnim];

	mov	eax, DWORD PTR _li$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+45]
	imul	ecx, 12					; 0000000cH
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65355[ebp], eax
	mov	edx, DWORD PTR _li$[ebp]
	mov	eax, DWORD PTR $T65355[ebp]
	mov	DWORD PTR [edx+48], eax

; 733  : 		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

	mov	ecx, DWORD PTR _li$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+45]
	imul	edx, 12					; 0000000cH
	push	edx
	push	0
	mov	eax, DWORD PTR _li$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 734  : 
; 735  : 			ai = &li->anim_info[0];

	mov	edx, DWORD PTR _li$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	DWORD PTR _ai$[ebp], eax

; 736  : 			SetStr(&ai->name, "walk");

	push	OFFSET FLAT:??_C@_04IBJ@walk?$AA@	; `string'
	mov	ecx, DWORD PTR _ai$[ebp]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 737  : 	
; 738  : 			ai->loop_type = LT_FOREVER;

	mov	edx, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [edx+4], 2

; 739  : 
; 740  : 			ai->nCel = 4;

	mov	eax, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [eax+6], 4

; 741  : 			ai->cel_info = new CEL_INFO[ai->nCel];

	mov	ecx, DWORD PTR _ai$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+6]
	imul	edx, 24					; 00000018H
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65356[ebp], eax
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR $T65356[ebp]
	mov	DWORD PTR [eax+8], ecx

; 742  : 			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

	mov	edx, DWORD PTR _ai$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	imul	eax, 24					; 00000018H
	push	eax
	push	0
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 743  : 
; 744  : 			j = 0;

	mov	BYTE PTR _j$[ebp], 0

; 745  : 				ai->cel_info[j].w = 28;	ai->cel_info[j].h = 36;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+12], 28		; 0000001cH
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+14], 36		; 00000024H

; 746  : 				ai->cel_info[j].delay = 250;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [edx+eax], 250		; 000000faH

; 747  : 				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\lupi1.bmp");

	push	OFFSET FLAT:??_C@_0BE@IOKG@gfx?2fight?2lupi1?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	lea	eax, DWORD PTR [edx+eax+20]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 748  : 			j++;

	mov	cl, BYTE PTR _j$[ebp]
	add	cl, 1
	mov	BYTE PTR _j$[ebp], cl

; 749  : 				ai->cel_info[j].w = 28;	ai->cel_info[j].h = 37;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+12], 28		; 0000001cH
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+14], 37		; 00000025H

; 750  : 				ai->cel_info[j].delay = 250;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+edx], 250		; 000000faH

; 751  : 				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\lupi2.bmp");

	push	OFFSET FLAT:??_C@_0BE@GOMJ@gfx?2fight?2lupi2?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	lea	edx, DWORD PTR [ecx+edx+20]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 752  : 			j++;

	mov	al, BYTE PTR _j$[ebp]
	add	al, 1
	mov	BYTE PTR _j$[ebp], al

; 753  : 				ai->cel_info[j].w = 28;	ai->cel_info[j].h = 36;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+12], 28		; 0000001cH
	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+14], 36		; 00000024H

; 754  : 				ai->cel_info[j].delay = 250;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+ecx], 250		; 000000faH

; 755  : 				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\lupi3.bmp");

	push	OFFSET FLAT:??_C@_0BE@MOOM@gfx?2fight?2lupi3?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	lea	ecx, DWORD PTR [eax+ecx+20]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 756  : 			j++;

	mov	dl, BYTE PTR _j$[ebp]
	add	dl, 1
	mov	BYTE PTR _j$[ebp], dl

; 757  : 				ai->cel_info[j].w = 28;	ai->cel_info[j].h = 37;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+12], 28		; 0000001cH
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+14], 37		; 00000025H

; 758  : 				ai->cel_info[j].delay = 250;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [edx+eax], 250		; 000000faH

; 759  : 				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\lupi2.bmp");

	push	OFFSET FLAT:??_C@_0BE@GOMJ@gfx?2fight?2lupi2?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	lea	eax, DWORD PTR [edx+eax+20]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 760  : 		i++;

	mov	cl, BYTE PTR _i$[ebp]
	add	cl, 1
	mov	BYTE PTR _i$[ebp], cl

; 761  : 
; 762  : 		//
; 763  : 		//
; 764  : 		//
; 765  : 		li = &gli->l[i];

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 52					; 00000034H
	mov	eax, DWORD PTR _gli$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	add	ecx, edx
	mov	DWORD PTR _li$[ebp], ecx

; 766  : 		SetStr(&li->Name, "Super");

	push	OFFSET FLAT:??_C@_05COAO@Super?$AA@	; `string'
	mov	edx, DWORD PTR _li$[ebp]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 767  : 		li->type = LT_SPRITE;

	mov	eax, DWORD PTR _li$[ebp]
	mov	BYTE PTR [eax+4], 2

; 768  : 		li->visable = true;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+5], 1

; 769  : 		li->animate = true;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+44], 1

; 770  : 		li->x = 20;

	mov	eax, DWORD PTR _li$[ebp]
	mov	DWORD PTR [eax+16], 20			; 00000014H

; 771  : 		li->y = 93;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	DWORD PTR [ecx+20], 93			; 0000005dH

; 772  : 		li->NumAnim = 1;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+45], 1

; 773  : 
; 774  : 		li->anim_info = new ANIM_INFO[li->NumAnim];

	mov	eax, DWORD PTR _li$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+45]
	imul	ecx, 12					; 0000000cH
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65357[ebp], eax
	mov	edx, DWORD PTR _li$[ebp]
	mov	eax, DWORD PTR $T65357[ebp]
	mov	DWORD PTR [edx+48], eax

; 775  : 		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

	mov	ecx, DWORD PTR _li$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+45]
	imul	edx, 12					; 0000000cH
	push	edx
	push	0
	mov	eax, DWORD PTR _li$[ebp]
	mov	ecx, DWORD PTR [eax+48]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 776  : 
; 777  : 			ai = &li->anim_info[0];

	mov	edx, DWORD PTR _li$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	DWORD PTR _ai$[ebp], eax

; 778  : 			SetStr(&ai->name, "Stand");

	push	OFFSET FLAT:??_C@_05KAIJ@Stand?$AA@	; `string'
	mov	ecx, DWORD PTR _ai$[ebp]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 779  : 	
; 780  : 			ai->loop_type = LT_FOREVER;

	mov	edx, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [edx+4], 2

; 781  : 
; 782  : 			ai->nCel = 2;

	mov	eax, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [eax+6], 2

; 783  : 			ai->cel_info = new CEL_INFO[ai->nCel];

	mov	ecx, DWORD PTR _ai$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+6]
	imul	edx, 24					; 00000018H
	push	edx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65358[ebp], eax
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR $T65358[ebp]
	mov	DWORD PTR [eax+8], ecx

; 784  : 			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

	mov	edx, DWORD PTR _ai$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	imul	eax, 24					; 00000018H
	push	eax
	push	0
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 785  : 
; 786  : 			j = 0;

	mov	BYTE PTR _j$[ebp], 0

; 787  : 				ai->cel_info[j].w = 31;	ai->cel_info[j].h = 35;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+12], 31		; 0000001fH
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	WORD PTR [edx+eax+14], 35		; 00000023H

; 788  : 				ai->cel_info[j].delay = 2000;

	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR [edx+eax], 2000		; 000007d0H

; 789  : 				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\sn_st2.bmp");

	push	OFFSET FLAT:??_C@_0BF@PBLI@gfx?2fight?2sn_st2?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _j$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _ai$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	lea	eax, DWORD PTR [edx+eax+20]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 790  : 			j++;

	mov	cl, BYTE PTR _j$[ebp]
	add	cl, 1
	mov	BYTE PTR _j$[ebp], cl

; 791  : 				ai->cel_info[j].w = 31;	ai->cel_info[j].h = 35;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+12], 31		; 0000001fH
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+14], 35		; 00000023H

; 792  : 				ai->cel_info[j].delay = 100;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+edx], 100		; 00000064H

; 793  : 				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\sn_st1.bmp");

	push	OFFSET FLAT:??_C@_0BF@BBNH@gfx?2fight?2sn_st1?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	lea	edx, DWORD PTR [ecx+edx+20]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 794  : 		i++;

	mov	al, BYTE PTR _i$[ebp]
	add	al, 1
	mov	BYTE PTR _i$[ebp], al

; 795  : 		//
; 796  : 		//
; 797  : 		//
; 798  : 		li = &gli->l[i];

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	add	eax, ecx
	mov	DWORD PTR _li$[ebp], eax

; 799  : 		SetStr(&li->Name, "Red");

	push	OFFSET FLAT:??_C@_03GOGG@Red?$AA@	; `string'
	mov	ecx, DWORD PTR _li$[ebp]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 800  : 		li->type = LT_SPRITE;

	mov	edx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [edx+4], 2

; 801  : 		li->visable = true;

	mov	eax, DWORD PTR _li$[ebp]
	mov	BYTE PTR [eax+5], 1

; 802  : 		li->animate = true;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+44], 1

; 803  : 		li->x = 266;

	mov	edx, DWORD PTR _li$[ebp]
	mov	DWORD PTR [edx+16], 266			; 0000010aH

; 804  : 		li->y = 82;

	mov	eax, DWORD PTR _li$[ebp]
	mov	DWORD PTR [eax+20], 82			; 00000052H

; 805  : 		li->NumAnim = 1;

	mov	ecx, DWORD PTR _li$[ebp]
	mov	BYTE PTR [ecx+45], 1

; 806  : 
; 807  : 		li->anim_info = new ANIM_INFO[li->NumAnim];

	mov	edx, DWORD PTR _li$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+45]
	imul	eax, 12					; 0000000cH
	push	eax
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65359[ebp], eax
	mov	ecx, DWORD PTR _li$[ebp]
	mov	edx, DWORD PTR $T65359[ebp]
	mov	DWORD PTR [ecx+48], edx

; 808  : 		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

	mov	eax, DWORD PTR _li$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+45]
	imul	ecx, 12					; 0000000cH
	push	ecx
	push	0
	mov	edx, DWORD PTR _li$[ebp]
	mov	eax, DWORD PTR [edx+48]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 809  : 
; 810  : 			ai = &li->anim_info[0];

	mov	ecx, DWORD PTR _li$[ebp]
	mov	edx, DWORD PTR [ecx+48]
	mov	DWORD PTR _ai$[ebp], edx

; 811  : 			SetStr(&ai->name, "Stand");

	push	OFFSET FLAT:??_C@_05KAIJ@Stand?$AA@	; `string'
	mov	eax, DWORD PTR _ai$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 812  : 	
; 813  : 			ai->loop_type = LT_FOREVER;

	mov	ecx, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [ecx+4], 2

; 814  : 
; 815  : 			ai->nCel = 2;

	mov	edx, DWORD PTR _ai$[ebp]
	mov	BYTE PTR [edx+6], 2

; 816  : 			ai->cel_info = new CEL_INFO[ai->nCel];

	mov	eax, DWORD PTR _ai$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+6]
	imul	ecx, 24					; 00000018H
	push	ecx
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65360[ebp], eax
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR $T65360[ebp]
	mov	DWORD PTR [edx+8], eax

; 817  : 			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

	mov	ecx, DWORD PTR _ai$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+6]
	imul	edx, 24					; 00000018H
	push	edx
	push	0
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 818  : 
; 819  : 			j = 0;

	mov	BYTE PTR _j$[ebp], 0

; 820  : 				ai->cel_info[j].w = 31;	ai->cel_info[j].h = 35;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+12], 31		; 0000001fH
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	WORD PTR [ecx+edx+14], 35		; 00000023H

; 821  : 				ai->cel_info[j].delay = 2500;

	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [ecx+edx], 2500		; 000009c4H

; 822  : 				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\rn_st2.bmp");

	push	OFFSET FLAT:??_C@_0BF@HOHK@gfx?2fight?2rn_st2?4bmp?$AA@ ; `string'
	mov	edx, DWORD PTR _j$[ebp]
	and	edx, 255				; 000000ffH
	imul	edx, 24					; 00000018H
	mov	eax, DWORD PTR _ai$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	lea	edx, DWORD PTR [ecx+edx+20]
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 823  : 			j++;

	mov	al, BYTE PTR _j$[ebp]
	add	al, 1
	mov	BYTE PTR _j$[ebp], al

; 824  : 				ai->cel_info[j].w = 31;	ai->cel_info[j].h = 35;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+12], 31		; 0000001fH
	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	WORD PTR [eax+ecx+14], 35		; 00000023H

; 825  : 				ai->cel_info[j].delay = 100;

	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR [eax+ecx], 100		; 00000064H

; 826  : 				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\rn_st1.bmp");

	push	OFFSET FLAT:??_C@_0BF@JOBF@gfx?2fight?2rn_st1?4bmp?$AA@ ; `string'
	mov	ecx, DWORD PTR _j$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 24					; 00000018H
	mov	edx, DWORD PTR _ai$[ebp]
	mov	eax, DWORD PTR [edx+8]
	lea	ecx, DWORD PTR [eax+ecx+20]
	push	ecx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 827  : 		i++;

	mov	dl, BYTE PTR _i$[ebp]
	add	dl, 1
	mov	BYTE PTR _i$[ebp], dl
$L65086:

; 829  : 
; 830  : 	gli->l[i].visable = false;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+5], 0

; 831  : 	gli->l[i].type = LT_IMAGE;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	BYTE PTR [edx+eax+4], 1

; 832  : 	gli->l[i].x = 0;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+16], 0

; 833  : 	gli->l[i].y = 0;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR [edx+eax+20], 0

; 834  : 	gli->l[i].w = 28;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+10], 28		; 0000001cH

; 835  : 	gli->l[i].h = 17;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+12], 17		; 00000011H

; 836  : 	gli->l[i].hx = 25;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+40], 25		; 00000019H

; 837  : 	gli->l[i].hy = 5;

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	WORD PTR [edx+eax+42], 5

; 838  : 	SetStr(&gli->l[i].fName, "gfx\\hand.bmp");

	push	OFFSET FLAT:??_C@_0N@BPDI@gfx?2hand?4bmp?$AA@ ; `string'
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 255				; 000000ffH
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gli$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	lea	eax, DWORD PTR [edx+eax+48]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 839  : 	SetStr(&gli->l[i].Name, "Hand");

	push	OFFSET FLAT:??_C@_04LFM@Hand?$AA@	; `string'
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 255				; 000000ffH
	imul	ecx, 52					; 00000034H
	mov	edx, DWORD PTR _gli$[ebp]
	mov	eax, DWORD PTR [edx+12]
	add	eax, ecx
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	call	?SetStr@DISPLAY@@QAEXPAPADPBD@Z		; DISPLAY::SetStr

; 840  : 	i++;

	mov	cl, BYTE PTR _i$[ebp]
	add	cl, 1
	mov	BYTE PTR _i$[ebp], cl

; 841  : 
; 842  : 	gli->nLayer = i;

	mov	edx, DWORD PTR _gli$[ebp]
	mov	al, BYTE PTR _i$[ebp]
	mov	BYTE PTR [edx+8], al

; 843  : 
; 844  : 	return gli;

	mov	eax, DWORD PTR _gli$[ebp]

; 845  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?LoadGfx@DISPLAY@@QAEPAUGFX_LAYER_INFO@@PAD@Z ENDP	; DISPLAY::LoadGfx
_TEXT	ENDS
PUBLIC	?TransferGfx@DISPLAY@@QAE_NPAUGFX_LAYER_INFO@@@Z ; DISPLAY::TransferGfx
PUBLIC	??_C@_0L@CLNN@Load?5Mouse?$AA@			; `string'
PUBLIC	??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@	; `string'
PUBLIC	??_C@_0BD@LIDO@Set?5ColorKey?5Mouse?$AA@	; `string'
PUBLIC	??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@	; `string'
PUBLIC	?SetSize@MOUSE@@QAEXJJ@Z			; MOUSE::SetSize
PUBLIC	?SetPos@MOUSE@@QAEXJJ@Z				; MOUSE::SetPos
EXTRN	?DDE@DISPLAY@@QAE_NPADJ0@Z:NEAR			; DISPLAY::DDE
EXTRN	?CreateTextBox@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z:NEAR ; DISPLAY::CreateTextBox
EXTRN	?CreateSprite@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z:NEAR ; DISPLAY::CreateSprite
EXTRN	?CreateImage@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z:NEAR ; DISPLAY::CreateImage
EXTRN	?CreateMap@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z:NEAR ; DISPLAY::CreateMap
EXTRN	?CreateTile@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z:NEAR ; DISPLAY::CreateTile
EXTRN	?CreateWin@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z:NEAR ; DISPLAY::CreateWin
EXTRN	_DDLoadBitmap:NEAR
EXTRN	_DDColorMatch:NEAR
EXTRN	_DDSetColorKey:NEAR
;	COMDAT ??_C@_0L@CLNN@Load?5Mouse?$AA@
; File D:\Game Programming\working Skull X\C++ Files\LoadGfx.cpp
CONST	SEGMENT
??_C@_0L@CLNN@Load?5Mouse?$AA@ DB 'Load Mouse', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@
CONST	SEGMENT
??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ DB 'LoadDrawS:DDLoadBitmap', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@LIDO@Set?5ColorKey?5Mouse?$AA@
CONST	SEGMENT
??_C@_0BD@LIDO@Set?5ColorKey?5Mouse?$AA@ DB 'Set ColorKey Mouse', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@
CONST	SEGMENT
??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ DB 'LoadDrawS:DDSetColorKey', 00H ; `string'
CONST	ENDS
;	COMDAT ?TransferGfx@DISPLAY@@QAE_NPAUGFX_LAYER_INFO@@@Z
_TEXT	SEGMENT
_gfx_li$ = 8
_this$ = -4
$T65363 = -8
?TransferGfx@DISPLAY@@QAE_NPAUGFX_LAYER_INFO@@@Z PROC NEAR ; DISPLAY::TransferGfx, COMDAT

; 848  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 849  : ///////////////////////////////////////////////////////
; 850  : // load layer info
; 851  : ///////////////////////////////////////////////////////
; 852  : 
; 853  : 	// create layers and clear junk
; 854  : /*
; 855  : 	nLayers = gfx_li->nLayer;
; 856  : 	Layer = new LAYER[gfx_li->nLayer];
; 857  : 	memset(Layer, 0, gfx_li->nLayer*sizeof(LAYER) );
; 858  : */
; 859  : 
; 860  : 	Mouse = new MOUSE;

	push	72					; 00000048H
	call	??2@YAPAXI@Z				; operator new
	add	esp, 4
	mov	DWORD PTR $T65363[ebp], eax
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR $T65363[ebp]
	mov	DWORD PTR [eax+196], ecx

; 861  : 	ZeroMemory(Mouse, sizeof(MOUSE) );

	push	72					; 00000048H
	push	0
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+196]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 862  : 	
; 863  : ///////////////////////////////////////////////////////
; 864  : // load our bitmap
; 865  : ///////////////////////////////////////////////////////
; 866  : 	// load our bitmap
; 867  : FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);

	push	15781032				; 00f0cca8H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+228]
	push	edx
	call	_DDColorMatch
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+136], eax

; 868  : 
; 869  : 	EndLayer = NULL;

	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+204], 0

; 870  : 	for(i = 0; i < gfx_li->nLayer; i++)

	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+232], 0
	jmp	SHORT $L65136
$L65137:
	mov	ecx, DWORD PTR _this$[ebp]
	mov	dl, BYTE PTR [ecx+232]
	add	dl, 1
	mov	eax, DWORD PTR _this$[ebp]
	mov	BYTE PTR [eax+232], dl
$L65136:
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+232]
	mov	eax, DWORD PTR _gfx_li$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+8]
	cmp	edx, ecx
	jge	$L65138

; 872  : 		/*
; 873  : 		if(i < (gfx_li->nLayer - 1) )
; 874  : 			Layer[i].next = &Layer[i + 1];
; 875  : 		else
; 876  : 			Layer[i].next = NULL;
; 877  : 
; 878  : 		Layer[i].type = gfx_li->l[i].type;
; 879  : 
; 880  : 		if(Layer[i].type == LT_SPRITE)	
; 881  : 			CreateSprite(&Layer[i], &gfx_li->l[i]);
; 882  : 		else if(Layer[i].type == LT_IMAGE)
; 883  : 			CreateImage(&Layer[i], &gfx_li->l[i]);
; 884  : 		else if(Layer[i].type == LT_MAP)
; 885  : 			CreateMap(&Layer[i], &gfx_li->l[i]);
; 886  : 		else if(Layer[i].type == LT_TILE)
; 887  : 			CreateTile(&Layer[i], &gfx_li->l[i]);
; 888  : 		else if(Layer[i].type == LT_TEXT)
; 889  : 		{
; 890  : 			l = CreateTextBox(&gfx_li->l[i]);
; 891  : 			if(i > 0)
; 892  : 				Layer[i-1].next = l;
; 893  : 			else
; 894  : 				StartLayer = l;
; 895  : 
; 896  : 			l->next = &Layer[i+1];
; 897  : 		}
; 898  : 		else if(Layer[i].type == LT_WINDOW)
; 899  : 			CreateWin(&Layer[i], &gfx_li->l[i]);
; 900  : 		*/
; 901  : 
; 902  : 		if(gfx_li->l[i].type == LT_SPRITE)	

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax+4]
	cmp	ecx, 2
	jne	SHORT $L65139

; 903  : 			l = CreateSprite(&gfx_li->l[i]);

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?CreateSprite@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateSprite
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+360], eax

; 904  : 
; 905  : 		else if(gfx_li->l[i].type == LT_IMAGE)

	jmp	$L65149
$L65139:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax+4]
	cmp	ecx, 1
	jne	SHORT $L65141

; 906  : 			l = CreateImage(&gfx_li->l[i]);

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?CreateImage@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateImage
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+360], eax

; 907  : 
; 908  : 		else if(gfx_li->l[i].type == LT_MAP)

	jmp	$L65149
$L65141:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax+4]
	cmp	ecx, 4
	jne	SHORT $L65143

; 909  : 			l = CreateMap(&gfx_li->l[i]);

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?CreateMap@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateMap
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+360], eax

; 910  : 
; 911  : 		else if(gfx_li->l[i].type == LT_TILE)

	jmp	$L65149
$L65143:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax+4]
	cmp	ecx, 3
	jne	SHORT $L65145

; 912  : 			l = CreateTile(&gfx_li->l[i]);

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?CreateTile@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateTile
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+360], eax

; 913  : 
; 914  : 		else if(gfx_li->l[i].type == LT_TEXT)

	jmp	$L65149
$L65145:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax+4]
	cmp	ecx, 5
	jne	SHORT $L65147

; 915  : 			l = CreateTextBox(&gfx_li->l[i]);

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?CreateTextBox@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateTextBox
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+360], eax

; 916  : 
; 917  : 		else if(gfx_li->l[i].type == LT_WINDOW)

	jmp	SHORT $L65149
$L65147:
	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+eax+4]
	cmp	ecx, 6
	jne	SHORT $L65149

; 918  : 			l = CreateWin(&gfx_li->l[i]);

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	imul	eax, 52					; 00000034H
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	add	edx, eax
	push	edx
	mov	ecx, DWORD PTR _this$[ebp]
	call	?CreateWin@DISPLAY@@QAEPAVLAYER@@PAULAYER_INFO@@@Z ; DISPLAY::CreateWin
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+360], eax
$L65149:

; 919  : 
; 920  : 
; 921  : 		// Copy all to master layer
; 922  : 
; 923  : 
; 924  : 
; 925  : 		if(i == 0)

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+232]
	test	eax, eax
	jne	SHORT $L65150

; 926  : 			StartLayer = l;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	DWORD PTR [ecx+200], eax
$L65150:

; 927  : 
; 928  : 		EndLayer = l;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+360]
	mov	DWORD PTR [ecx+204], eax

; 929  : 	}

	jmp	$L65137
$L65138:

; 930  : 
; 931  : FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);

	push	15781032				; 00f0cca8H
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+228]
	push	edx
	call	_DDColorMatch
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+136], eax

; 932  : 
; 933  : ///////////////////////////////////////////////////////
; 934  : // Mouse
; 935  : ///////////////////////////////////////////////////////
; 936  : 	UseMouse = gfx_li->UseMouse;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _gfx_li$[ebp]
	mov	cl, BYTE PTR [eax]
	mov	BYTE PTR [edx+193], cl

; 937  : 
; 938  : 	if(UseMouse)

	mov	edx, DWORD PTR _this$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+193]
	test	eax, eax
	je	$L65157

; 940  : 		if( (Mouse->gfx = DDLoadBitmap(DD_Object, gfx_li->Mouse_fName, 0, 0)) == NULL )

	push	0
	push	0
	mov	ecx, DWORD PTR _gfx_li$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+208]
	push	ecx
	call	_DDLoadBitmap
	add	esp, 16					; 00000010H
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+196]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+196]
	cmp	DWORD PTR [eax], 0
	jne	SHORT $L65158

; 941  : 			return DDE("LoadDrawS:DDLoadBitmap", i, "Load Mouse");

	push	OFFSET FLAT:??_C@_0L@CLNN@Load?5Mouse?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+232]
	push	edx
	push	OFFSET FLAT:??_C@_0BH@MDPO@LoadDrawS?3DDLoadBitmap?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L65126
$L65158:

; 942  : 		if( (e = DDSetColorKey(Mouse->gfx,  TRANS_COLOR1 ) ) != DD_OK)

	push	15781032				; 00f0cca8H
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+196]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_DDSetColorKey
	add	esp, 8
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+16], eax
	mov	edx, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [edx+16], 0
	je	SHORT $L65168

; 943  : 			return DDE("LoadDrawS:DDSetColorKey", e, "Set ColorKey Mouse");

	push	OFFSET FLAT:??_C@_0BD@LIDO@Set?5ColorKey?5Mouse?$AA@ ; `string'
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:??_C@_0BI@KGPH@LoadDrawS?3DDSetColorKey?$AA@ ; `string'
	mov	ecx, DWORD PTR _this$[ebp]
	call	?DDE@DISPLAY@@QAE_NPADJ0@Z		; DISPLAY::DDE
	jmp	$L65126
$L65168:

; 944  : 
; 945  : 		Mouse->SetSize(11, 19);

	push	19					; 00000013H
	push	11					; 0000000bH
	mov	edx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [edx+196]
	call	?SetSize@MOUSE@@QAEXJJ@Z		; MOUSE::SetSize

; 946  : 		Mouse->SetPos(0, 0);

	push	0
	push	0
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+196]
	call	?SetPos@MOUSE@@QAEXJJ@Z			; MOUSE::SetPos

; 947  : 		Mouse->draw = false;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+196]
	mov	BYTE PTR [edx+4], 0

; 948  : 
; 949  : 		Mouse->old_r = Mouse->r;

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

; 950  : 		Mouse->old_ir = Mouse->ir;

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
$L65157:

; 952  : 
; 953  : 	GlobalReDraw = true;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	BYTE PTR [ecx+352], 1

; 954  : 
; 955  : 	return 0;

	xor	al, al
$L65126:

; 956  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	4
?TransferGfx@DISPLAY@@QAE_NPAUGFX_LAYER_INFO@@@Z ENDP	; DISPLAY::TransferGfx
_TEXT	ENDS
;	COMDAT ?SetSize@MOUSE@@QAEXJJ@Z
_TEXT	SEGMENT
_w$ = 8
_h$ = 12
_this$ = -4
?SetSize@MOUSE@@QAEXJJ@Z PROC NEAR			; MOUSE::SetSize, COMDAT

; 876  : 	{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 877  : 		ir.top = ir.left = 0;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+40], 0
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+44], 0

; 878  : 		ir.right = w; ir.bottom = h;

	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR [edx+48], eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR _h$[ebp]
	mov	DWORD PTR [ecx+52], edx

; 879  :   };

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?SetSize@MOUSE@@QAEXJJ@Z ENDP				; MOUSE::SetSize
_TEXT	ENDS
;	COMDAT ?SetPos@MOUSE@@QAEXJJ@Z
_TEXT	SEGMENT
_x$ = 8
_y$ = 12
_this$ = -4
?SetPos@MOUSE@@QAEXJJ@Z PROC NEAR			; MOUSE::SetPos, COMDAT

; 882  : 	{

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H
	push	ebx
	push	esi
	push	edi
	mov	DWORD PTR _this$[ebp], ecx

; 883  : 		r.left = x;											r.top = y;

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	mov	DWORD PTR [eax+56], ecx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	mov	DWORD PTR [edx+60], eax

; 884  : 		r.right = r.left + ir.right;		r.bottom = r.top + ir.bottom;

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR _this$[ebp]
	add	edx, DWORD PTR [eax+48]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [ecx+64], edx
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+60]
	mov	ecx, DWORD PTR _this$[ebp]
	add	eax, DWORD PTR [ecx+52]
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+68], eax

; 885  :   };

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	8
?SetPos@MOUSE@@QAEXJJ@Z ENDP				; MOUSE::SetPos
_TEXT	ENDS
END
