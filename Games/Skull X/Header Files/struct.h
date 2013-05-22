// Game Vars

//Non animating Map
struct MAP
{
	// Gfx double array
	GFXDATA	**Gfx;
	unsigned __int16	w;
	unsigned __int16	h;
	unsigned __int16	NumW;

	// IMG
	bool		Visable;
	short		x;
	short		y;
	// Compiled gfx
	GFX			*Gfx;
	//
	FX			*Fx;
	PAL			*Pal;
	ZONE		*Zone;
	XY			*Move;
	XY			*Path;

	void	*next;
};

//
#define IT_HORZ 1
#define IT_VERT 2
#define IT_BOTH 3

struct TILE
{
	// HORZ, VERT, BOTH
	unsigned __int8 type;

	// if(Cel == NULL) then Gfx is a single image
	// End with NULL
	T_CEL			*Cel;

	// IMG
	bool		Visable;
	short		x;
	short		y;
	// compiled TiledGfx or Single Image tiled
	GFX			*Gfx;
	//
	PAL			*Pal;
	FX			*Fx;
	ZONE		*Zone;
	XY			*Move;
	XY			*Path;

	void	*next;
};

struct T_CEL
{
	long		Delay;
	GFX			*Gfx;
	PAL			*Pal;
	FX			*Fx;

	GFX			*TiledGfx;

	T_CEL		*next;
};

// A still image for animation see SPRITE
struct IMG
{
	bool		Visable;
	short		x;
	short		y;
	GFX			*Gfx;
	PAL			*Pal;
	FX			*Fx;
	ZONE		*Zone;
	XY			*Move;
	XY			*Path;

	void	*next;
};

// An Animated Image
struct SPRITE
{
	bool		Visable;
	bool		Animate;
	short		x;
	short		y;
	ANIM		*Anim;

	void	*next;
};

////////////////////////////////////////
struct ANIM
{
	CEL			*StartCel;
	CEL			*Cel;
	short		LoopCount;
	XY			*Move;
	XY			*Path;
};

struct CEL
{
	long		Delay;
	short		Hx;
	short		Hy;
	short		Bx;
	short		By;
	GFX			*Gfx;
	PAL			*Pal;
	FX			*Fx;
	ZONE		*Zones;

	CEL			*next;
};

struct GFX
{
	GFXDATA						Data;
	unsigned __int16	w;
	unsigned __int16	h;
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

	ZONE		next;
};

struct XY
{
	short x;
	short y;

	MOVE next;
};


