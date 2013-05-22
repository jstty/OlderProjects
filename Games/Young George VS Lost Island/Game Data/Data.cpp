////////////////////////////////////////////////////////////////////////
//	Program Name:	Data.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Data File
//	Date: 
////////////////////////////////////////////////////////////////////////
#include "E:\My Code\Young George VS Lost Island\YoungGeroge.h"
#include "E:\My Code\Young George VS Lost Island\Game Levels\resource.h"
#include "Data.h"

/////////////// ///////////////////////////////////////////////////
void Level1(void)
{
int i = 0, j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL01);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 1;
level[i]->zoneNum								= 1;

l = 0;
level[i]->lWaveA[l]							= -1;

j = 0;
level[i]->lBitmapA[j].zNum			=	0;

j = 0;
level[i]->lSpriteA[j].zNum			=	0;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL01);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	640;
level[i]->lZoneA[k].h			=	480;
level[i]->lZoneA[k].x2		=	(UINT)(level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w);
level[i]->lZoneA[k].y2		=	(UINT)(level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h);
}
//////////////////////////////////////////////////////////////////
void Level2(void)
{
int i = 1;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL02);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 1;
level[i]->zoneNum								= 3;

l = 0;
level[i]->lWaveA[l]							= -1;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 1;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL02);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	640;
level[i]->lZoneA[k].h			=	200;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL02);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL02);
level[i]->lZoneA[k].x1		=	556;
level[i]->lZoneA[k].y1		=	17;
level[i]->lZoneA[k].w			=	32;
level[i]->lZoneA[k].h			=	33;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
//////////////////////////////////////////////////////////////////
void Level3(void)
{
int i = 2;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL03);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 1;
level[i]->zoneNum								= 4;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;
j = 0;
level[i]->lSpriteA[j].zNum			= 1;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[j].zoneName, ID_ZONE01_LEVEL03);
level[i]->lZoneA[j].x1		=	0;
level[i]->lZoneA[j].y1		=	0;
level[i]->lZoneA[j].w			=	640;
level[i]->lZoneA[j].h			=	200;
level[i]->lZoneA[j].x2		=	level[i]->lZoneA[j].x1 + level[i]->lZoneA[j].w;
level[i]->lZoneA[j].y2		=	level[i]->lZoneA[j].y1 + level[i]->lZoneA[j].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL03);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL03);
level[i]->lZoneA[k].x1		=	464;
level[i]->lZoneA[k].y1		=	17;
level[i]->lZoneA[k].w			=	32;
level[i]->lZoneA[k].h			=	33;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 3;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE04_LEVEL03);
level[i]->lZoneA[k].x1		=	204;
level[i]->lZoneA[k].y1		=	96;
level[i]->lZoneA[k].w			=	108;
level[i]->lZoneA[k].h			=	50;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
//////////////////////////////////////////////////////////////////
void Level4(void)
{
int i = 3;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL04);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 3;
level[i]->zoneNum								= 5;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 2;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 1;
level[i]->lSpriteA[j].zNum			= 1;
level[i]->lSpriteA[j].zOrder		= 1;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 2;
level[i]->lSpriteA[j].zNum			= 3;
level[i]->lSpriteA[j].zOrder		= 2;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL04);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	640;
level[i]->lZoneA[k].h			=	200;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL04);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL04);
level[i]->lZoneA[k].x1		=	336;
level[i]->lZoneA[k].y1		=	94;
level[i]->lZoneA[k].w			=	48;
level[i]->lZoneA[k].h			=	68;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 3;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE04_LEVEL04);
level[i]->lZoneA[k].x1		=	588;
level[i]->lZoneA[k].y1		=	69;
level[i]->lZoneA[k].w			=	16;
level[i]->lZoneA[k].h			=	123;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 4;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE05_LEVEL04);
level[i]->lZoneA[k].x1		=	308;
level[i]->lZoneA[k].y1		=	17;
level[i]->lZoneA[k].w			=	32;
level[i]->lZoneA[k].h			=	33;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
//////////////////////////////////////////////////////////////////
void Level5(void)
{
int i = 4;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL05);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 2;
level[i]->zoneNum								= 5;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 3;
level[i]->lSpriteA[j].zOrder		= 1;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 1;
level[i]->lSpriteA[j].zNum			= 4;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL05);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	640;
level[i]->lZoneA[k].h			=	200;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL05);
level[i]->lZoneA[k].x1		=	148;
level[i]->lZoneA[k].y1		=	17;
level[i]->lZoneA[k].w			=	32;
level[i]->lZoneA[k].h			=	33;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL05);
level[i]->lZoneA[k].x1		=	412;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	8;
level[i]->lZoneA[k].h			=	150;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 3;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE04_LEVEL05);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 4;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE05_LEVEL05);
level[i]->lZoneA[k].x1		=	156;
level[i]->lZoneA[k].y1		=	92;
level[i]->lZoneA[k].w			=	32;
level[i]->lZoneA[k].h			=	77;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
//////////////////////////////////////////////////////////////////
void Level6(void)
{
int i = 5;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL06);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 2;
level[i]->zoneNum								= 4;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 2;
level[i]->lSpriteA[j].zOrder		= 1;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 1;
level[i]->lSpriteA[j].zNum			= 3;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL06);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	640;
level[i]->lZoneA[k].h			=	200;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL06);
level[i]->lZoneA[k].x1		=	224;
level[i]->lZoneA[k].y1		=	33;
level[i]->lZoneA[k].w			=	64;
level[i]->lZoneA[k].h			=	67;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL06);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 3;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE04_LEVEL06);
level[i]->lZoneA[k].x1		=	112;
level[i]->lZoneA[k].y1		=	17;
level[i]->lZoneA[k].w			=	40;
level[i]->lZoneA[k].h			=	104;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
//////////////////////////////////////////////////////////////////
void Level7(void)
{
int i = 6;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL07);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 2;
level[i]->zoneNum								= 4;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 2;
level[i]->lSpriteA[j].zOrder		= 1;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 1;
level[i]->lSpriteA[j].zNum			= 3;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL07);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	200;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL07);
level[i]->lZoneA[k].x1		=	256;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	156;
level[i]->lZoneA[k].h			=	65;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL07);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 3;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE04_LEVEL07);
level[i]->lZoneA[k].x1		=	428;
level[i]->lZoneA[k].y1		=	17;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	28;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
//////////////////////////////////////////////////////////////////
void Level8(void)
{
int i = 7;
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL08);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 3;
level[i]->zoneNum								= 6;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 3;
level[i]->lSpriteA[j].zOrder		= 2;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 14;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 1;
level[i]->lSpriteA[j].zNum			= 4;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;
j = 2;
level[i]->lSpriteA[j].zNum			= 5;
level[i]->lSpriteA[j].zOrder		= 1;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE01_LEVEL08);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	640;
level[i]->lZoneA[k].h			=	200;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE02_LEVEL08);
level[i]->lZoneA[k].x1		=	136;
level[i]->lZoneA[k].y1		=	56;
level[i]->lZoneA[k].w			=	40;
level[i]->lZoneA[k].h			=	40;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 2;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE03_LEVEL08);
level[i]->lZoneA[k].x1		=	216;
level[i]->lZoneA[k].y1		=	96;
level[i]->lZoneA[k].w			=	96;
level[i]->lZoneA[k].h			=	68;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 3;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE04_LEVEL08);
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	28;
level[i]->lZoneA[k].h			=	108;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 4;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE05_LEVEL08);
level[i]->lZoneA[k].x1		=	4;
level[i]->lZoneA[k].y1		=	48;
level[i]->lZoneA[k].w			=	24;
level[i]->lZoneA[k].h			=	148;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 5;
strcpy(level[i]->lZoneA[k].zoneName, ID_ZONE06_LEVEL08);
level[i]->lZoneA[k].x1		=	596;
level[i]->lZoneA[k].y1		=	28;
level[i]->lZoneA[k].w			=	36;
level[i]->lZoneA[k].h			=	164;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
/*
//////////////////////////////////////////////////////////////////
void LevelLast(void)
{
int i = (CL-1);
int j = 0, k = 0, l = 0;
strcpy(level[i]->midi.file			, IDM_LEVEL00);
level[i]->midi.sec							=	0;
level[i]->waveNum								= 1;
level[i]->bitmapNum							=	1;
level[i]->spriteNum							= 1;
level[i]->zoneNum								= 2;

l = 0;
level[i]->lWaveA[l]							= 0;

j = 0;
level[i]->lBitmapA[j].zNum			= 0;

j = 0;
level[i]->lSpriteA[j].zNum			= 1;
level[i]->lSpriteA[j].zOrder		= 0;
level[i]->lSpriteA[j].cel				= 0;
level[i]->lSpriteA[j].xDelta		= 0;
level[i]->lSpriteA[j].yDelta		= 0;
level[i]->lSpriteA[j].xHotspot	= 0;
level[i]->lSpriteA[j].yHotspot	= 0;

k = 0;
strcpy(level[i]->lZoneA[k].zoneName, "LAST BKG");
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	0;
level[i]->lZoneA[k].h			=	0;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
k = 1;
strcpy(level[i]->lZoneA[k].zoneName, "LAST SPR");
level[i]->lZoneA[k].x1		=	0;
level[i]->lZoneA[k].y1		=	0;
level[i]->lZoneA[k].w			=	0;
level[i]->lZoneA[k].h			=	0;
level[i]->lZoneA[k].x2		=	level[i]->lZoneA[k].x1 + level[i]->lZoneA[k].w;
level[i]->lZoneA[k].y2		=	level[i]->lZoneA[k].y1 + level[i]->lZoneA[k].h;
}
*/