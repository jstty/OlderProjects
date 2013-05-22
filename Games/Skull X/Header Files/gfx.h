#ifndef _GFX
#define _GFX

#include "..\Header Files\Program.h"

#define DD_INTERFACE	IID_IDirectDraw7
#define DD_OBJECT			LPDIRECTDRAW7
#define DD_SURFACE		LPDIRECTDRAWSURFACE7

#define DD_PALETTE		LPDIRECTDRAWPALETTE
#define DD_CLIPPER		LPDIRECTDRAWCLIPPER
#define DD_COLOR			LPDIRECTDRAWCOLORCONTROL
#define DD_SDESC			DDSURFACEDESC2
#define GFXDATA				DD_SURFACE
#define PAL						DD_PALETTE


// Game Vars
#define LT_IMAGE	1
#define LT_SPRITE	2
#define LT_TILE		3
#define LT_MAP		4
#define LT_TEXT		5
#define LT_WINDOW	6
#define LT_GROUP	7

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

	void	*next;
};

struct XY
{
	short x;
	short y;

	XY *next;
};

struct MOVE
{
	char *Name;

	unsigned long	delay;
	unsigned __int8 num;
	XY		*fd;

	/*
	bool	move;
	short dx;
	short dy;
	RECT *or;
	bool *redraw;
	MOVE *next;
	*/
};

//////////////////////////////
// From File
//////////////////////////////
struct RGB_PAL
{
	BYTE r;
	BYTE g;
	BYTE b;
};

struct GFX_INFO_HEADER
{
	WORD	w;
	WORD	h;
	BYTE	bpp;

	// Uncompressed Size
	DWORD	oSize;

	// Palette Entries
	DWORD	pSize;

	// Graphics Size
	DWORD	gSize;
};

struct GFX_INFO_DATA
{
	RGB_PAL	*pal;
	BYTE		*gfx;
};

struct GFX_INFO
{
	GFX_INFO_HEADER header;
	GFX_INFO_DATA		data;
};

struct GFX_INFO_LIST
{
	GFX_INFO_HEADER header;
	GFX_INFO_DATA		*data;
};

struct CEL_INFO
{
	unsigned long		delay;
	// hot spot
	short		hx;
	short		hy;

	// bullet spot
	short		bx;
	short		by;

	// gfx data
// to be added remove char* and sizeof(char*)
//GFX_INFO_HEADER gih;
//GFX_DATA gd;

	unsigned __int16 w;
	unsigned __int16 h;

	// graphic filename to be loaded
	unsigned __int8 fSize;
	char *fName;
};

struct ANIM_INFO
{
	char			*name;
	unsigned __int8 loop_type;
	unsigned __int8 loop_count;
	unsigned __int8 nCel;
	CEL_INFO	*cel_info;
};

struct MAP_INFO
{
	// image double array
	unsigned __int8 **data;

	// Filename size list
	unsigned __int8 *fSize;
	// Filename list
	char **fName;
};

struct TILE_INFO
{
	// Filename size list
	unsigned __int8 fSize;
	// Filename
	char *fName;
};

struct TAB_INFO
{
	// Window Tab Width
	unsigned __int8 w;
	unsigned __int8 h;

	char **img;
	unsigned __int8 wImg;
};

struct WIN_INFO
{
	// Window Tab info
	TAB_INFO *tab;

	char **img;

	DWORD	bgcolor;
};

struct LAYER_INFO
{	
	char *Name;
	unsigned __int8 type;
	bool visable;

	bool moveable;
	unsigned __int8 move_type;
	unsigned __int8 move_count;

	bool collidable;

	unsigned __int16 w;
	unsigned __int16 h;
	long x;
	long y;

	bool clip;
	long cx;
	long cy;
	unsigned __int16 cw;
	unsigned __int16 ch;
	
	short hx;
	short hy;

	union
	{
		// image file length
		unsigned __int8 fSize;

		// sprite animate
		bool animate;

		// map image width
		unsigned __int8 map_image_w;

		// tile image width
		unsigned __int8 tile_image_w;

		// Text Horz. Align
		unsigned __int8 hAlign;

		// Window Type
		unsigned __int8 wType;
		
		unsigned __int8 extra1;
	};

	union
	{
		// sprite number of animation sets
		unsigned __int8 NumAnim;

		// map image height
		unsigned __int8 map_image_h;

		// tile image height
		unsigned __int8 tile_image_h;

		// Text Counter
		unsigned __int8 NumDigits;

		// Window Image Width
		unsigned __int8 win_image_w;

		unsigned __int8	extra2;
	};

	union
	{
		// map number of diffrent images
		unsigned __int8 map_num_images;

		//Text Font Number
		unsigned __int8 FontNum;

		// Window Image Height
		unsigned __int8 win_image_h;

		unsigned __int8	extra3;
	};


	union
	{
		// sprite
		ANIM_INFO *anim_info;

		// image
		char *fName;

		// map
		MAP_INFO *map_info;

		// text
		char *text;

		// Window Info
		WIN_INFO *win;

		// tile info
		TILE_INFO *tile_info;
	};
};

struct GFX_LAYER_INFO
{
	// Mouse Info
	bool UseMouse;
	char *Mouse_fName;
	//

	unsigned __int8 nLayer;
	LAYER_INFO *l;
};

struct CEL
{
	unsigned long		delay;

	// Width & Height
	unsigned short	w;
	unsigned short	h;

	// Hot spot
	short		hx;
	short		hy;

	// Bullet spot
	short		bx;
	short		by;

	GFXDATA	gfx;
//	PAL			*pal;
//	FX			*fx;
//	ZONE		*zones;

	CEL			*next;
};

struct ANIM
{
	char *name;
	bool done;

	unsigned __int8 loop_type;
	unsigned __int8 loop_count;
	unsigned __int8 o_loop_count;

	unsigned __int8 nCel;

	CEL		*startcel;
	// current cel
	CEL	*cel;

	ANIM *next;
};

struct XY_WH
{
	__int16 x;
	__int16 y;

	unsigned __int16 w;
	unsigned __int16 h;
};

struct MAP
{	
	// Map
	unsigned __int8 nRow;
	// Map
	unsigned __int8 nCol;

	// Map Title Width/Height
	unsigned __int8 w;
	unsigned __int8 h;

	unsigned __int8 **data;
};

#define CT_MAP	1
#define CT_ZONE	2
#define CT_BOTH	3

struct COL
{
	unsigned __int8 type;

	// Zone
	unsigned __int8 nZone;
	// Zone
	XY_WH	*zone;

	// Map
	MAP *map;
};

// loop type
#define LT_ONCE			0
#define LT_NUMBER		1
#define LT_FOREVER	2

// text align type
#define AT_CENTER		0
#define AT_LEFT			1
#define AT_RIGHT		2
#define AT_MIDDLE		0
#define AT_TOP			1
#define AT_BOTTOM		2

// window type
#define WT_TAB			1
#define WT_BGCOLOR	2

// window images
#define W_TOP_LEFT			0
#define W_TOP						1
#define W_TOP_RIGHT			2
#define W_LEFT					3
#define W_MIDDLE				4
#define W_RIGHT					5
#define W_BOTTOM_LEFT		6
#define W_BOTTOM				7
#define W_BOTTOM_RIGHT	8

// window tab images
#define T_LEFT		0
#define T_MIDDLE	1
#define T_RIGHT		2

// tile type
#define TT_VERT 1
#define TT_HORZ 2
#define TT_BOTH 3

class LAYER
{
public:
	char *Name;
	unsigned __int8 type;

	// image	-> 
	// sprite	-> loop type
	// tile		-> 
	// map		-> map_image_w (Number of images across)
	// group	-> gSize (Number of objects)
	union
	{
		bool animate;

		// map image width
		unsigned __int8 map_image_w;

		// tile image width
		unsigned __int8 tile_image_w;

		// Text
		unsigned __int8 hAlign;

		// Window Type
		unsigned __int8 wType;

		unsigned __int8 gSize;
		unsigned __int8 extra1;
	};

	// sprite	-> loop count
	union
	{
		unsigned __int8	NumAnim;
		
		// map image height
		unsigned __int8 map_image_h;

		// tile image height
		unsigned __int8 tile_image_h;

		// Counter Number of Digits
		unsigned __int8 NumDigits;

		// Window Image Width
		unsigned __int8 win_image_w;

		unsigned __int8	extra2;
	};

	// image	-> 
	// sprite	-> Number of cels
	// tile		-> 
	// map		-> 
	// group	-> 
	// Image Clip width/height
	// Tile number of times to loop Horz, and Vert.
	// Map Number of images across
	union
	{
		// map number of diffrent images
		unsigned __int8 map_num_images;

		//Text Font Number
		unsigned __int8 FontNum;

		// Window Image Height
		unsigned __int8 win_image_h;

		unsigned __int8	extra3;
	};

	//
	//
	//

	void SetAnim(char *name)
	{
		ANIM *a = startanim;
		for(; a != NULL;)
		{
			if( _stricmp(name, a->name) == 0 )
			{
				anim = a;
				gfx = anim->cel->gfx;
				SetSize(anim->cel->w, anim->cel->h);
				SetHotSpot(anim->cel->hx, anim->cel->hy);
				redraw = true;
				return;
			}
			a = a->next;
		}
	};

	void Play(void)	{	animate = true;	};
	void Pause(void) {	animate = false; };
	void Reset(void)
	{
		anim->done = false;
		anim->loop_count = anim->o_loop_count;
		JumptoFirstCel();
	};

	void JumptoFirstAnim(void)
	{
		anim = startanim;
		gfx = anim->cel->gfx;
		SetSize(anim->cel->w, anim->cel->h);
		SetHotSpot(anim->cel->hx, anim->cel->hy);
		redraw = true;
	}

	void JumptoFirstCel(void)
	{
		anim->cel = anim->startcel;
		gfx = anim->cel->gfx;
		SetSize(anim->cel->w, anim->cel->h);
		SetHotSpot(anim->cel->hx, anim->cel->hy);
		redraw = true;
	};
	void JumptoLastCel(void)
	{	
		CEL *c = anim->cel;
		while(c->next != NULL)
			c = c->next;

		anim->cel = c;
		gfx = c->gfx;
		SetSize(c->w, c->h);
		SetHotSpot(c->hx, c->hy);
		redraw = true;
	};

	void JumpToCel(unsigned __int8 n)
	{	
		unsigned __int8 i = 0;
		CEL *c = anim->startcel;

		while( (c->next != NULL) || (i < n) )
			{	i++;	c = c->next;	}

		anim->cel = c;
		gfx = c->gfx;
		SetSize(c->w, c->h);
		SetHotSpot(c->hx, c->hy);
		redraw = true;
	};
	//

//
// Not Loaded info
//
	bool redraw;
	bool visable;
	// When Image turn nonvisable clear data left behind
	bool clear_dd;

	DWORD tick;

	void Hide(void){	clear_dd = true;	visable = false;	};
	void Show(void)	{	visable = true;	};

	MOVE **mList;
	MOVE *move;
	bool moveable;
	bool movement_done;
	unsigned __int8 move_type;
	unsigned __int8 move_count;
	unsigned __int8 o_move_count;

	XY		*d;
	DWORD	move_tick;

	void Move(void)	{	moveable = true;	};
	void Stop(void)	{	moveable = false;	};
	void ResetMove(void){
		movement_done = false;
		d = move->fd;
		move_count = o_move_count;
	};

	void SetMove(char *name)
	{
		unsigned __int8 z = 0;
		MOVE *a = mList[z];

		for(; a != NULL;)
		{
			if( _stricmp(name, a->Name) == 0 )
			{
				move = a;
				d = move->fd;
				move_count = o_move_count;
				return;
			}
			z++;
			a = mList[z];
		}
	};

	// Collision
	COL *col;
	bool collidable;

	bool hit;
	LAYER *hitby;

	bool clip;
	RECT cr;
	void SetClipRect(long x, long y, long w, long h)	{
		cr.left = x;	cr.right = cr.left + w;
		cr.top = y;		cr.bottom = cr.top + h;
	};

	long		hx, hy;
	RECT r, ir, old_r, old_ir;
	void SetSize(long w, long h)
	{
		ir.top = ir.left = 0;
		ir.right = w; ir.bottom = h;
		redraw = true;
  };

	void SetHotSpot(long thx, long thy)
	{
		r.left += hx - thx;
		r.top += hy - thy;
		r.right = r.left + ir.right;
		r.bottom = r.top + ir.bottom;

		hx = thx;
		hy = thy;
		redraw = true;
	};

	void SetPos(long x, long y)
	{
		r.left = x - hx;								r.top = y - hy;
		r.right = r.left + ir.right;		r.bottom = r.top + ir.bottom;
		redraw = true;
  };

	void ShiftPos(long x, long y)
	{
		r.left += x;										r.top += y;
		r.right = r.left + ir.right;		r.bottom = r.top + ir.bottom;
		redraw = true;
  };

	void SetX(long x){	OffsetRect(&r, (x - r.left - hx), 0 );	redraw = true;};
	void SetY(long y){	OffsetRect(&r, 0, (y - r.top - hy) );		redraw = true;};

	// Compiled
	GFXDATA gfx;
//	PAL			*pal;

	// image	-> NULL
	// sprite	-> ANIM
	// tile		-> T_CEL
	// map		-> NULL
	// group	-> tList
	union
	{
		// current anim
		ANIM	*anim;

		// map
		unsigned __int8 *tList;

		// text
		char *text;

		// Window Info
		WIN_INFO *win;	
		
		void						*object;
	};

	// image	-> NULL
	// sprite	-> Start Cel
	// tile		-> NULL
	// group	-> ObjectList
	union
	{
		// first animation set
		ANIM	*startanim;
		void **lobject;
	};

	LAYER *prev;
	LAYER *next;
};

/*
struct ANIM
{
	unsigned __int8 NumCel;
	CEL							*Cel;
	unsigned short	LoopCount;
};

// An Animated Image
struct SPRITE
{
	bool		NonVisable;
	bool		Animate;
	short		x;
	short		y;
	ANIM		*Anim;

	// Current Cel Gfx
	GFXDATA	*Gfx;
};

//Non animating Map
struct MAP
{
	// Gfx double array
	GFXDATA	**gArray;
	// Total Width
	unsigned __int16	w;
	// Total Height
	unsigned __int16	h;

	// Number that can fit across
	unsigned __int16	NumW;

	// IMG
	bool		NonVisable;
	short		x;
	short		y;
	// Compiled gfx
	GFXDATA	*Gfx;
	PAL			*Pal;
	//
	
	FX			*Fx;

	ZONE		*Zone;
	XY			*Move;
	XY			*Path;
};

// if Animating
#define TT_ANIM 1

// NonAnimating Horz.
#define TT_NA_HORZ 2
// NonAnimating Vert.
#define TT_NA_VERT 4
// NonAnimating Both = TT_NA_HORZ | TT_NA_VERT
#define TT_NA_BOTH 6

// Animating Horz.
#define TT_A_HORZ 8
// Animating Vert.
#define TT_A_VERT 12
// Animating Both = TT_A_HORZ | TT_A_VERT
#define TT_A_BOTH 14

struct T_CEL
{
	long		Delay;
	// original image
	GFXDATA	*Gfx;
	PAL			*Pal;

	FX			*Fx;

	GFXDATA	*TiledGfx;

	T_CEL		*next;
};

struct TILE
{
	// HORZ, VERT, BOTH
	unsigned __int8 type;

	bool		NonVisable;
	bool		Animate;
	short		x;
	short		y;
	unsigned __int16	w;
	unsigned __int16	h;

	// if(Cel == NULL) then Gfx is a single image
	// End with NULL
	T_CEL			*Cel;
	short		LoopCount;

	// compiled TiledGfx or Single Image tiled
	GFXDATA	*Gfx;
	PAL			*Pal;

	FX			*Fx;

	ZONE		*Zone;
	XY			*Move;
	XY			*Path;
};

#define GT_IMAGE	0
#define GT_SPRITE	1
#define GT_TILE		2
#define GT_MAP		3
#define GT_GROUP	4
#define GT_SOME		5
#define GT_OTHER	5
#define GT_MISC		5

struct GROUP
{
	unsigned __int8 type;

	bool		Visable;

	short		x;
	short		y;
	unsigned __int16	w;
	unsigned __int16	h;

	// Compiled Gfx
	GFXDATA	*Gfx;
	PAL			*Pal;

	FX			*Fx;

	ZONE		*Zone;
	XY			*Move;
	XY			*Path;

	unsigned __int8 *tList;
	unsigned __int8 Num;
	void **ObjectList;
};
*/
////////////////////////////////////////

struct MOUSE
{
	GFXDATA gfx;
//	PAL			*pal;

	bool draw;

	RECT old_r;
	RECT old_ir;

	RECT ir;
	RECT r;
	void SetSize(long w, long h)
	{
		ir.top = ir.left = 0;
		ir.right = w; ir.bottom = h;
  };

	void SetPos(long x, long y)
	{
		r.left = x;											r.top = y;
		r.right = r.left + ir.right;		r.bottom = r.top + ir.bottom;
  };
};

#endif