////////////////////////////////////////////////////////////////////////
//	Program Name:	DisplayClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Gfx Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _DISPLAY
#define _DISPLAY

#include <ddraw.h>
#include "..\Header Files\ddutil.h"

#include "..\Header Files\ErrorClass.h"

#include "..\Header Files\DisplayVarClass.h"

#include "..\Header Files\Gfx.h"
#include "..\Header Files\MainVarClass.h"

#include "..\Header Files\ControlVarClass.h"

DWORD WINAPI ThreadProc(LPVOID msg);

class DISPLAY : public ERRORCLASS{//, public GFX ,public DRAW{
	public:
		// Error var.
		HRESULT	e;

		float clean_rate;
		float draw_rate;
		float anim_rate;
		float move_rate;
		float screen_rate;

		unsigned __int16	Delay;
		unsigned __int16	DelayRes;
		unsigned __int16	xMax;
		unsigned __int16	yMax;
		unsigned __int8		bpp;

		unsigned int			Re_Draw:2;

		DDBLTFX		FxBkg;
//		bool Drawing;
		unsigned int ThreadLoop:2;

		bool Loop(void);
		void End(void){ ThreadLoop = 1;	};
		void Set_data(DisplayVar v)
		{
			Delay = v.Delay;
			DelayRes = v.DelayRes;
			xMax = v.xMax;
			yMax = v.yMax;
			bpp = v.bpp;
		};

		bool Setup_Display(RECT *r, bool dx);
		bool LoadDDObject(void);

		bool Load(void);
		bool FreeGfx(void);
		void Restore(void){	DD_Object->RestoreDisplayMode(); };

		GFX_LAYER_INFO *LoadGfx(char *FileName);
		bool TransferGfx(GFX_LAYER_INFO *gfx_layer_info);
		void FreeGfx_LayerInfo(GFX_LAYER_INFO *gli);
			
		bool DDE(char *n, HRESULT e1, char *name);

		bool DrawScreen(void);
		bool DrawMouse(void);
		bool DrawLayer(void);

		bool redraw_old;
		DWORD tick;
		//LAYER *Layer;

		//
		struct PAUSE_SCREEN
		{
			RECT ir;
			GFXDATA	gfx;
		};
		PAUSE_SCREEN Dark;

		struct FONT
		{
			unsigned __int8 cw;
			unsigned __int8 ch;
			GFXDATA	gfx;
		};
		FONT *Font;
		unsigned __int8 NumFonts;

		//
		bool	UseMouse;
		MOUSE *Mouse;

		LAYER *StartLayer;
		LAYER *EndLayer;
		void FreeLayers(void);
		bool Pause(void);

		//
		// Layer Functions
		//
		LAYER *FindLayer(char *name)
		{
			l = StartLayer;
			for(; l != NULL;)
			{
				if( _stricmp(name, l->Name) == 0 )
					return l;
				l = l->next;
			}
			Error("%s %s", "Could not find layer by the name of", name);
			return NULL;
		};

		LAYER *CreateTextBox(LAYER_INFO *l_info);

		LAYER *CreateSprite(LAYER_INFO *l_info);
		LAYER *CreateImage(LAYER_INFO *l_info);
		LAYER *CreateMap(LAYER_INFO *l_info);
		LAYER *CreateTile(LAYER_INFO *l_info);
		LAYER *CreateWin(LAYER_INFO *l_info);

/*
		bool CreateSprite(LAYER *l, LAYER_INFO *l_info);
		bool CreateImage(LAYER *l, LAYER_INFO *l_info);
		bool CreateMap(LAYER *l, LAYER_INFO *l_info);
		bool CreateTile(LAYER *l, LAYER_INFO *l_info);
		bool CreateWin(LAYER *l, LAYER_INFO *l_info);
*/
		LAYER *CreateCounter(long x, long y, unsigned __int8 NumDigits = 3, char *StartText = NULL, unsigned __int8 type = AT_RIGHT, unsigned __int8 fontNum = 0, char *name = "counter");
		bool SetCounter(LAYER *counter, char *text);
		bool SetCounter(LAYER *counter, unsigned __int32 num);

		void PlaceLayerAfter(LAYER *tobeplaced, LAYER *A);
		void AppendLayer(LAYER *layer);

		LAYER *CopyLayer(LAYER *layer, char *name = NULL, unsigned __int8 PlacementType = 0);
		GFXDATA CopyGfx(GFXDATA src, unsigned __int16 w, unsigned __int16 h);

		void DestroyLayer(LAYER *l);

		void SetStr(char **a, const char *b);
		void SetStr(char **a, const char *b, unsigned __int8 num); 

	private:
		// Direct Draw objects.
		DD_OBJECT		DD_Object;				// DirectDraw object
		DD_SURFACE	DDS_Primary;			// DirectDraw primary surface
		DD_CLIPPER	DD_Clipper;				// clipper for primary
//		DD_PALETTE		DD_Pal;						// Main Palette
		DD_SURFACE	DDS_Buffer1;		// DirectDraw Buffer surface 1
		DD_SURFACE	DDS_Buffer2;		// DirectDraw Buffer surface 2
		DD_SURFACE	DDS_Bkg;				// DirectDraw Background surface

		//
		unsigned __int8 i, j;

		// Display Window info.
		RECT									*WndRect;
		RECT									BkgRect;
		RECT									r1, r2, r3, r4, t_r, t_ir;

		bool GlobalReDraw;

		// Temp Draw Layers
		LAYER *TempLayer;
		LAYER *l;

		ANIM *a;
		CEL *c;

		unsigned __int8 nLayers;

		void Animate(void);

		bool DrawTile(GFXDATA out, GFXDATA tile, unsigned __int16 w, unsigned __int16 h, unsigned __int16 iw, unsigned __int16 ih);

		RECT ClipRectToRect(RECT r2, RECT r1);

		RECT ClipRectToScreen(RECT a)
		{
			if(a.left < 0)
				a.left = 0;
			if(a.right > G_XRES)
				a.right = G_XRES;
			if(a.top < 0)
				a.top = 0;
			if(a.bottom > G_YRES)
				a.bottom = G_YRES;

			return a;
		};

		RECT ClipRectToImage(RECT a)
		{
			if(a.left < 0)
			{
				a.left = (-1)*a.left;

				if(a.right > G_XRES)
					a.right = G_XRES + a.left;
			}
			else
			{
				if(a.right > G_XRES)
					a.right = G_XRES;
			}

			if(a.top < 0)
			{
				a.top = (-1)*a.top;

				if(a.bottom > G_YRES)
					a.bottom = G_YRES + a.top;
			}
			else
			{
				if(a.bottom > G_YRES)
					a.bottom = G_YRES;
			}

			return a;
		};

		RECT ClipImageToScreen(RECT s, RECT i)
		{
			if(s.left < 0)
				i.left -= s.left;

			if(s.right > G_XRES)
				i.right -= s.right - G_XRES;

			if(s.top < 0)
				i.top -= s.top;

			if(s.bottom > G_YRES)
				i.bottom -= s.bottom - G_YRES;

			return i;
		};

/*
		bool LoadDrawS(void);
		
		//
		bool CheckOnScreen(RECT r, int x, int y)
		{
			if((r.right > 0) && (r.bottom > 0) && (r.left < x) && (r.top < y))
				return 1;
			else
				return 0;
		}

		bool CheckOnScreen(RECT r1, RECT r2)
		{
			// r1=object; r2=window;
			if(	(r1.right > r2.left) && (r1.bottom > r2.top) && (r1.left < r2.right) && (r1.top < r2.bottom))
				return 1;
			else
				return 0;
		}


		//
		bool DrawLayers(void);
		bool dLayer(LAYER *pl, SPRITE *ps, DRAWS	*pds);
		//
		unsigned __int16 CreateTitle(unsigned __int16 gn, unsigned __int16 w, unsigned __int16 h);
		bool OldDrawAlpha(LPDIRECTDRAWSURFACE4 sSrc, LPDIRECTDRAWSURFACE4 sDes, XYWH dSrc, XYWH dDes, unsigned __int8 p);
//
		bool Load(void);

		bool Anim_Loop(SPRITE *s);
		bool Move_Loop(SPRITE *s);
//
		bool CreateAnim(SPRITE *s);
		bool StartAnim(SPRITE *s = NULL);
		bool KillAnim(SPRITE *s = NULL);
	//
		void ReDrawAll(void)
		{	unsigned __int16 sn;
			for(sn = 0; sn < NumLayer; sn++)
				Layer[sn].ReDraw = 1;
			for(sn = 0; sn < NumSprite; sn++)
				Sprite[sn].ReDraw = 1; 
		};
*/
};

typedef DISPLAY *P_DISPLAY, FAR *FP_DISPLAY;

#endif
