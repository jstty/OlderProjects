#include "stdafx.h"
#include "critter.h"
#include "sprite.h"
#include "spritepolygon.h"
 
//=============== CONST Mutationflags =========
const int cCritter::MF_NUDGE = 0x00000001;
const int cCritter::MF_POSITION = 0x00000002;
const int cCritter::MF_VELOCITY = 0x00000004;
const int cCritter::MF_ALL = cCritter::MF_POSITION | cCritter::MF_VELOCITY;
//******** CONST STATICS **********************************************
const int cSprite::MF_RADIUS = 0x00000008;
const int cSprite::MF_ROTATION = 0x00000010;
const int cSprite::MF_ALL = cSprite::MF_RADIUS | cSprite::MF_ROTATION;
//******** CONST STATICS **********************************************
const int cPolygon::MF_COLOR = 0x00000020;
const int cPolygon::MF_FILLING = 0x00000040;
const int cPolygon::MF_LINEWIDTH = 0x00000080;
const int cPolygon::MF_DOTS = 0x00000100;
const int cPolygon::MF_VERTCOUNT = 0x00000200;
const int cPolygon::MF_ALL = cPolygon::MF_COLOR | cPolygon::MF_FILLING | cPolygon::MF_LINEWIDTH | 
 	cPolygon::MF_DOTS |cPolygon::MF_VERTCOUNT;
