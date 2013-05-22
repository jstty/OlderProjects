// Save game info

//Non animating Map
struct MAP
{
	// Gfx double array
	unsigned char	**GfxNum;
	unsigned __int16	w;
	unsigned __int16	h;
	unsigned __int16	NumW;

	// IMG
	bool		Visable;
	short		x;
	short		y;
	//GFX			*Gfx;
	//PAL			*Pal;
	unsigned char PalNum;
	//FX			*Fx;
	unsigned char FxNum;
	//ZONE		*Zone;
	unsigned char ZoneNum;
	//XY			*Move;
	unsigned char MoveNum;
	//XY			*Path;
	unsigned char PathNum;

	//void	*next;
};

//
#define IT_HORZ 1
#define IT_VERT 2
#define IT_BOTH 3

struct TILE
{
	// HORZ, VERT, BOTH
	unsigned __int8 type;

	unsigned __int8 NumCel;
	T_CEL			*Cel;

	// IMG
	bool		Visable;
	short		x;
	short		y;	
	//GFX			*Gfx;
	unsigned char GfxNum;
	//PAL			*Pal;
	unsigned char PalNum;
	//FX			*Fx;
	unsigned char FxNum;
	//ZONE		*Zone;
	unsigned char ZoneNum;
	//XY			*Move;
	unsigned char MoveNum;
	//XY			*Path;
	unsigned char PathNum;

	//void	*next;
};

struct T_CEL
{
	long		Delay;
	//GFX			*Gfx;
	unsigned char GfxNum;
	//PAL			*Pal;
	unsigned char PalNum;
	//FX			*Fx;
	unsigned char FxNum;

	//GFX			*TiledGfx;

	//T_CEL		*next;
};

//
struct IMG
{
	bool		Visable;
	short		x;
	short		y;
	//GFX			*Gfx;
	unsigned char GfxNum;
	//PAL			*Pal;
	unsigned char PalNum;
	//FX			*Fx;
	unsigned char FxNum;
	//ZONE		*Zone;
	unsigned char ZoneNum;
	//XY			*Move;
	unsigned char MoveNum;
	//XY			*Path;
	unsigned char PathNum;

	//void *next;
};

//
struct SPRITE
{
	bool		Visable;
	bool		Animate;
	short		X;
	short		Y;
	//ANIM		*Anim;
	unsigned char AnimNum;
	//void	*next;
};

struct ANIM
{
	//CEL			*StartCel;
	unsigned char NumCel;
	CEL			*Cel;
	HGLOBAL	hCel;

	short		LoopCount;
	//XY			*Move;
	unsigned char MoveNum;
	//XY			*Path;
	unsigned char PathNum;
};

struct CEL
{
	long		Delay;
	short		Hx;
	short		Hy;
	short		Bx;
	short		By;

	//GFX			*Gfx;
	unsigned char GfxNum;
	//PAL			*Pal;
	unsigned char PalNum;
	//FX			Fx;
	unsigned char FxNum;
	//ZONE		*Zone;
	unsigned char ZoneNum;

	//CEL			*next;
};

struct GFX
{
	unsigned __int16			w;
	unsigned __int16			h;
};

struct FX
{
	unsigned char type;
	long	v1;
	long	v2;
};

struct ZONE
{
	short		x1;
	short		x2;
	short		y1;
	short		y2;
	//ZONE		next;
};

struct XY
{
	short x;
	short y;
	//MOVE next;
};