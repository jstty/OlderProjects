////////////////////////////////////////////////////////////////////////
//	Program Name:	Display.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Display Graphics File
//	Date:					04/03/2000
//	Version:			2.00
////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <ddraw.h>
#include <stdio.h>
#include <stdarg.h>
//
	#include "..\Resource Files\resource.h"
//
#include "..\Header Files\Program.h"

#include "..\Header Files\DisplayClass.h"
#include "..\Header Files\ValuesClass.h"
extern VALUES		*Val;

#include "..\Header Files\Gfx_to_DD.h"
/*
#ifdef _DEBUG
	#include "..\Header Files\TestSpeed.h"
	extern TestSpeed tsDisplay;
#endif
*/
///////////////////////////////////////////////////////
// Display_ThreadProc
///////////////////////////////////////////////////////
/*
DWORD WINAPI Display_ThreadProc(LPVOID msg)
{
	return Val->Display->Loop();
}
//
bool DISPLAY::Loop(void)
{
	HANDLE hThread = GetCurrentThread();
	CRITICAL_SECTION cs;
	InitializeCriticalSection(&cs);

	while(ThreadLoop == 0)
	{
		EnterCriticalSection(&cs);

// Debug info.
		#ifdef _DEBUG
				if(tsDisplay.Rate > 1000)
					return 0;

				tsDisplay.Loop();
		#endif

// Code

		DrawScreen();
		//Val->Action->MoveObject();

//

		LeaveCriticalSection(&cs);
		WaitForSingleObject(hThread, Delay);
	}

	FreeGfx();

	ThreadLoop = 2;
	return 0;
}
*/
//
//
//
bool DISPLAY::Setup_Display(RECT *r, bool dx)
{
	LPDIRECTDRAW	pDD;

	// slow func. wait cursor will appear
	if( (e = DirectDrawCreate( NULL, &pDD, NULL )) != DD_OK )
		return Error(NULL, "DISPLAY", "LoadDDObject:DirectDrawCreate", e );

	// Fetch DirectDraw4 interface
  if( (e = pDD->QueryInterface(DD_INTERFACE, (LPVOID *)&DD_Object)) != DD_OK)
		return Error(NULL, "DISPLAY", "LoadDDObject:QueryInterface", e );

	if( (e = DD_Object->RestoreDisplayMode()) != DD_OK )
		return Error(NULL, "DISPLAY", "LoadDDObject:RestoreDisplayMode", e );

//
// Get Display Info.
//
	DD_SDESC DDSurfaceDesc;
	DDSurfaceDesc.dwSize = sizeof(DD_SDESC);
	DDSurfaceDesc.dwFlags = DDSD_ALL;

	if((e = DD_Object->GetDisplayMode(&DDSurfaceDesc)) != DD_OK)
		return Error(NULL, "DISPLAY", "SetDisplay:GetDisplayMode", e );

	unsigned __int8 BitsPerPlane = (unsigned __int8)DDSurfaceDesc.ddpfPixelFormat.dwRGBBitCount;
	if(BitsPerPlane < bpp)
	{
		SetError_Format("Your current color palette(%d) is below the recommended level(%d).\n Do you wish to continue?");
		SetError_Type(ETYPE_YESNO);

		if( Error(NULL, BitsPerPlane, bpp) )
			return 1;
		else
			BitsPerPlane = bpp;

		ReSetError_Format();
		SetError_Type();
	}

	WndRect = r;
	if( (BitsPerPlane > 0) && (dx == true) )
	{
		if( (e = DD_Object->SetCooperativeLevel(Val->Main->Get_ChildHwnd(), DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN) != DD_OK ))
					return Error(NULL, "DISPLAY", "SetDisplay:SetCooperativeLevel", e );

		if((e = DD_Object->SetDisplayMode(xMax, yMax, BitsPerPlane, 0, 0)) != DD_OK)
			return Error(NULL, "DISPLAY", "SetDisplay:SetDisplayMode", e );
		
		if( Val->Main->GetStretchState() )
		{
			WndRect->top = WndRect->left = 0;
			WndRect->right = xMax;
			WndRect->bottom = yMax;
		}
		else
		{
			WndRect->left = (xMax - G_XRES) >> 1;
			WndRect->top = (yMax - G_YRES) >> 1;
			WndRect->right = WndRect->left + G_XRES;
			WndRect->bottom = WndRect->top + G_YRES;
		}
	}
	else
	{
		if( (e = DD_Object->SetCooperativeLevel(Val->Main->Get_ChildHwnd(), DDSCL_NORMAL) != DD_OK ))
			return Error(NULL, "DISPLAY", "SetDisplay:SetCooperativeLevel", e );
	}


	if(LoadDDObject())
		return 1;

	return 0;
}
///////////////////////////////////////////////////////
// Load DD Object
///////////////////////////////////////////////////////
bool DISPLAY::LoadDDObject(void)
{
	e = 0;

	DDCAPS ddc;
	ddc.dwSize = sizeof(DDCAPS);

	DD_Object->GetCaps(&ddc, NULL);

	if(!GETBIT(ddc.dwCaps, DDCAPS_BLT))
		return Error(NULL, "DISPLAY", "SetDisplay:DDCAPS_BLT", DDCAPS_BLT );

	if(!GETBIT(ddc.dwCaps, DDCAPS_BLTCOLORFILL))
		return Error(NULL, "DISPLAY", "SetDisplay:DDCAPS_BLTCOLORFILL", DDCAPS_BLTCOLORFILL );

	DD_SDESC	ddsd;
	// Create the primary surface
	ZeroMemory(&ddsd, sizeof(DD_SDESC));
	ddsd.dwSize = sizeof( DD_SDESC );
	ddsd.dwFlags = DDSD_CAPS;
	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_VIDEOMEMORY;
	if( (e = DD_Object->CreateSurface(&ddsd, &DDS_Primary, NULL)) != DD_OK )
		return DDE("LoadDrawS:CreateSurface", e, "Create Primary");

//	DDS_Primary->SetPalette(DrawP[0].Data);

	// create a clipper for the primary surface
	if( (e = DD_Object->CreateClipper( 0, &DD_Clipper, NULL )) != DD_OK )
		return DDE("LoadDrawS:CreateClipper", e, "Create Clipper");

	if( (e = DD_Clipper->SetHWnd(0, Val->Main->Get_ChildHwnd())) != DD_OK )
		return DDE("LoadDrawS:SetHWnd", e, "Set Child Hwnd");

	if( (e = DDS_Primary->SetClipper(DD_Clipper)) != DD_OK )
		return DDE("LoadDrawS:SetClipper", e, "Set Clipper");

//
// Create the background surface
//
	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize		= sizeof(ddsd);
	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	ddsd.dwWidth	= G_XRES;
	ddsd.dwHeight	= G_YRES;
	//DDSCAPS_OFFSCREENPLAIN
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;// DDSCAPS_TEXTURE | DDSCAPS_3DDEVICE;
	if( (e = DD_Object->CreateSurface(&ddsd, &DDS_Bkg, NULL)) != DD_OK )
		return DDE("LoadDrawS:CreateSurface", e, "Create Background");

	FxBkg.dwSize			= sizeof(DDBLTFX);
	FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, RGB(0, 0, 0));

	if(	(e = DDS_Bkg->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
			return DDE("DrawLayers:Blt", e, "Flood Fill Background");
//
// Create the Buffer surface 1
//
	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize		= sizeof(ddsd);
	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	ddsd.dwWidth	= G_XRES;
	ddsd.dwHeight	= G_YRES;
	//
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
	if( (e = DD_Object->CreateSurface(&ddsd, &DDS_Buffer1, NULL)) != DD_OK )
		return DDE("LoadDrawS:CreateSurface", e, "Create Buffer1");

	if(	(e = DDS_Buffer1->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
		return DDE("DrawLayers:Blt", e, "Flood Fill Buffer1");

//
// Create the Buffer surface 2
//
	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize		= sizeof(ddsd);
	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	ddsd.dwWidth	= G_XRES;
	ddsd.dwHeight	= G_YRES;
	//DDSCAPS_SYSTEMMEMORY
	//DDSCAPS_VIDEOMEMORY
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
	if( (e = DD_Object->CreateSurface(&ddsd, &DDS_Buffer2, NULL)) != DD_OK )
		return DDE("LoadDrawS:CreateSurface", e, "Create Buffer2");

	if( (e = DDSetColorKey(DDS_Buffer2,  TRANS_COLOR1 ) ) != DD_OK)
			return DDE("LoadDrawS:DDSetColorKey", e, "Set ColorKey Buffer2");

	if(	(e = DDS_Buffer2->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
		return DDE("DrawLayers:Blt", e, "Flood Fill Buffer2");

	BkgRect.left = 0;
	BkgRect.top = 0;
	BkgRect.right = G_XRES;
	BkgRect.bottom = G_YRES;


//
// Load Info from File Then create Pause and Fonts.
//

	//
	// Draw Pause Screen
	//
		GFXDATA TempGfx;
		unsigned __int16 k, w, h, iw, ih;
		Dark.ir = BkgRect;
		
		iw = 8;	ih = 8;

		w = G_XRES/iw;
		if(G_XRES%iw)
			w++;

		h = G_YRES/ih;
		if(G_YRES%ih)
			h++;

		r2.top = r2.left = 0;
		r2.right = iw;
		r2.bottom = ih;

		//
		ZeroMemory(&ddsd, sizeof(ddsd));
		ddsd.dwSize		= sizeof(ddsd);
		ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
		ddsd.dwWidth	= w*iw;
		ddsd.dwHeight	= h*ih;
		//
		ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
		if( (e = DD_Object->CreateSurface(&ddsd, &Dark.gfx, NULL)) != DD_OK )
			return DDE("LoadDrawS:CreateSurface", e, "Create Dark");

		if( (e = DDSetColorKey(Dark.gfx,  TRANS_COLOR1 ) ) != DD_OK)
				return DDE("LoadDrawS:DDSetColorKey", e, "SetColorKey:Dark");

		FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);

		if(	(e = Dark.gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
			return DDE("DrawLayers:Blt", e, "FloodFill:Dark");
		//

		if( (TempGfx = DDLoadBitmap(DD_Object, "gfx\\dark.bmp", 0, 0)) == NULL )
			return DDE("LoadDrawS:DDLoadBitmap", i, "Load:Dark");
		if( (e = DDSetColorKey(TempGfx,  TRANS_COLOR1 ) ) != DD_OK)
			return DDE("LoadDrawS:DDSetColorKey", e, "SetColorKey:Dark Image");

		k = 0;
		for(j = 0; k < h;)
		{
			r1.left = j*iw;
			r1.top = k*ih;
			r1.right = r1.left + iw;
			r1.bottom = r1.top + ih;

			if(	(e = Dark.gfx->Blt(&r1, TempGfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
				return DDE("DrawLayers:Blt", e, "Dark Tiling");

			j++;
			if((j%w) == 0)
			{
				j = 0;
				k++;
			}
		}

		if( (TempGfx = DDLoadBitmap(DD_Object, "gfx\\pause.bmp", 0, 0)) == NULL )
			return DDE("LoadDrawS:DDLoadBitmap", i, "Load Pause");
		if( (e = DDSetColorKey(TempGfx,  TRANS_COLOR1 ) ) != DD_OK)
			return DDE("LoadDrawS:DDSetColorKey", e, "Set ColorKey Pause");

		r1.left		= (G_XRES - 189) >> 1;
		r1.top		= (G_YRES - 40) >> 1;
		r1.right	= r1.left + 189;
		r1.bottom	= r1.top + 40;

		if(	(e = Dark.gfx->Blt(&r1, TempGfx, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)
			return DDE("DrawLayers:Blt", e, "Blt:temp to dark");

	//
	// Create Fonts
	//
	
	NumFonts = 1;
	Font = new FONT[NumFonts];
	Font[0].cw = 10;
	Font[0].ch = 16;
	for(i = 0; i < NumFonts; i++)
	{
		if( (Font[i].gfx = DDLoadBitmap(DD_Object, "gfx\\font1.bmp", 0, 0)) == NULL )
				return DDE("LoadDrawS:DDLoadBitmap", i, "Load font");
		if( (e = DDSetColorKey(Font[i].gfx,  TRANS_COLOR1 ) ) != DD_OK)
				return DDE("LoadDrawS:DDSetColorKey", e, "Set ColorKey Font");
	}

	return 0;
}

bool DISPLAY::Load(void)
{
	// Get gfx info from file
	if( TransferGfx( LoadGfx("level\000.dat") ) )
		return 1;

	return 0;
}

void DISPLAY::FreeLayers(void)
{
	l = StartLayer;
	for(i = 0; (i < nLayers) && (l != NULL); i++)
	{
		if(l->type == LT_SPRITE)
		{
			for(a = l->startanim; a != NULL; a = a->next)
			{
				for(c = a->startcel; c != NULL; c = c->next)
				{
					if(c->gfx)
					{
						c->gfx->Release();
						c->gfx = NULL;
					}
				}				
			}
		}
		else
		{
			if(l->gfx)
				l->gfx->Release();

			l->gfx = NULL;
		}
		l = l->next;
	}
	StartLayer = NULL;
}

bool DISPLAY::FreeGfx(void)
{

	FreeLayers();

	if(DDS_Buffer2)
	{
		DDS_Buffer2->Release();
		DDS_Buffer2 = NULL;
	}

	if(DDS_Buffer1)
	{
		DDS_Buffer1->Release();
		DDS_Buffer1 = NULL;
	}

	if(DDS_Bkg)
	{
		DDS_Bkg->Release();
		DDS_Bkg = NULL;
	}

	if(DDS_Primary)
	{
		DDS_Primary->Release();
		DDS_Primary = NULL;
	}

	if(DD_Object)
	{
		Restore();
		DD_Object->Release();
		DD_Object = NULL;
	}

	return 0;
}

///////////////////////////////////////////////////////
// DrawLayers
///////////////////////////////////////////////////////
bool DISPLAY::DrawScreen(void)
{
	if( (DDS_Buffer1 != NULL) && (DDS_Buffer2 != NULL) && (DDS_Primary != NULL) && (StartLayer != NULL))
	{
		l = StartLayer;
		
		for(i = 0; (i < nLayers) && (l != NULL); i++)
		{
			if(l->gfx != NULL)
			{
				//
				// Move
				//
				#ifdef _DEBUG
					tick = GetTickCount();
				#endif
				if( (!l->movement_done) && (l->moveable) && (l->move != NULL) )
				{
					Val->Action->MoveObject(l);
				}
				#ifdef _DEBUG
					tick = GetTickCount() - tick;
					if(tick > 0)
						move_rate = (float)( 1000/tick );
					else
						move_rate = (float)( 1000 );
				#endif

				//
				// Collision
				//
				if( (l->collidable) && (l->col != NULL) )
					Val->Action->CheckCol(l);

				//
				// Animate
				//
				#ifdef _DEBUG
					tick = GetTickCount();
				#endif
				if(l->type == LT_SPRITE)
				{
					if( (l->animate) && (!l->anim->done) )
						Animate();
				}
				#ifdef _DEBUG
					tick = GetTickCount() - tick;
					if(tick > 0)
						anim_rate = (float)( 1000/tick );
					else
						anim_rate = (float)( 1000 );
				#endif

				if(l->visable)
				{
					//
					// Clip Image
					//
					if(l->clip)
					{
						t_r = l->r;	l->r = l->cr;	t_ir = l->ir;
						if(l->cr.left > t_r.left)
							l->ir.left = l->cr.left - t_r.left;
						if(l->cr.top > t_r.top)
							l->ir.top = l->cr.top - t_r.top;
						if(l->cr.right < t_r.right)
							l->ir.right -= t_r.right - l->cr.right;
						if(l->cr.bottom < t_r.bottom)
							l->ir.bottom -= t_r.bottom - l->cr.bottom;
					}
					//
					// Draw Layer
					//
					#ifdef _DEBUG
						tick = GetTickCount();
					#endif
					if( (ONSCREEN_RECT(l->r, G_XRES, G_YRES)) && ( (l->redraw) || (Re_Draw == RE_ALL) ) )
					{
						if( DrawLayer() )
							return 1;
					}
					#ifdef _DEBUG
						tick = GetTickCount() - tick;
						if(tick > 0)
							draw_rate = (float)( 1000/tick );
						else
							draw_rate = (float)( 1000 );
					#endif

					if(l->clip)
					{
						l->r = t_r;
						l->ir = t_ir;
					}
				}
			}
			l = (LAYER *)l->next;
		}
	}

	//
	// Mouse
	//
	if( (UseMouse) && ONSCREEN_RECT(Mouse->r, G_XRES, G_YRES) && ( (Mouse->draw) || (Re_Draw == RE_ALL) ) )
	{
		if( DrawMouse() )
			return 1;
	}
	
	if( (GlobalReDraw) || (Re_Draw == RE_ALL) )
	{
		#ifdef _DEBUG
			tick = GetTickCount();
		#endif
		if(	(e = DDS_Primary->Blt(WndRect, DDS_Buffer1, NULL, 0, NULL)) != DD_OK)
			return DDE("DrawLayers:Blt", e, "Buffer1 onto Primary");
		#ifdef _DEBUG
			tick = GetTickCount() - tick;
			if(tick > 0)
				screen_rate = (float)( 1000/tick );
			else
				screen_rate = (float)( 1000 );
		#endif

		Re_Draw = false;
		GlobalReDraw = false;
	}

	return 0;
}

bool DISPLAY::DrawLayer(void)
{
	r1 = ClipRectToScreen(l->r);
	r2 = ClipImageToScreen(l->r, l->ir);
	if(	(e = DDS_Buffer1->Blt(&r1, l->gfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
		return DDE("DrawLayers:Blt", e, l->Name);

	l->redraw = false;
	GlobalReDraw = true;
	return 0;
}


bool DISPLAY::DrawMouse(void)
{
	// clean up old image
		redraw_old = false;
		r1 = ClipRectToScreen(Mouse->old_r);

		TempLayer = StartLayer;
		for(j = 0; (j < nLayers) && (TempLayer != NULL); j++)
		{
			if( (!TempLayer->redraw) && (TempLayer->visable) && (TempLayer->gfx != NULL) && ( IN_RECT(TempLayer->r, r1) ) )
			{
				if(!redraw_old)
				{
					if(	(e = DDS_Buffer2->Blt(&r1, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
						return DDE("DrawLayers:Blt", e, "Flood Fill Buffer2");
				}

				// clip draw layer
				r3 = ClipRectToRect(TempLayer->r, r1);
				// clip temp layer
				r4 = ClipRectToRect(r1, TempLayer->r);

				if(	(e = DDS_Buffer2->Blt(&r3, TempLayer->gfx, &r4, DDBLT_KEYSRC, NULL)) != DD_OK)
					return DDE("DrawLayers:Blt", e, TempLayer->Name);

				redraw_old = true;
			}

			TempLayer = TempLayer->next;
		}

		if(redraw_old)
		{
			r2 = ClipImageToScreen(Mouse->old_r, Mouse->old_ir);
			if(	(e = DDS_Buffer1->Blt(&r1, DDS_Buffer2, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
				return DDE("DrawLayers:Blt", e, "Buffer2 onto Buffer1");
		}

		Mouse->old_r = Mouse->r;
		Mouse->old_ir = Mouse->ir;
	//

	r1 = ClipRectToScreen(Mouse->r);
	r2 = ClipImageToScreen(Mouse->r, Mouse->ir);
	if(	(e = DDS_Buffer1->Blt(&r1, Mouse->gfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
		return DDE("DrawLayers:Blt", e, "Mouse");

	GlobalReDraw = true;
	Mouse->draw = false;

	return 0;
}

//
//
//
void DISPLAY::Animate(void)
{
	a = l->anim;
	if(a != NULL)
	{
		tick = GetTickCount();

		c = a->cel;
		if((unsigned)(tick - l->tick) > c->delay)
		{
			l->tick = tick;				
			if(c->next != NULL)
			{
				l->gfx = c->gfx;
				l->SetSize(c->w, c->h);
				l->SetHotSpot( c->hx, c->hy);

				a->cel = c->next;
				l->redraw = true;
			}
			else
			{
				l->gfx = c->gfx;
				l->SetSize(c->w, c->h);
				l->SetHotSpot( c->hx, c->hy);

				if(a->loop_type == LT_FOREVER)
					a->cel = a->startcel;
				else if( (a->loop_type == LT_ONCE) || (a->loop_count == 0) )
					a->done = true;
				else if( (a->loop_type == LT_NUMBER) && (a->loop_count > 0) )
				{
					a->loop_count--;
					a->cel = a->startcel;
				}

				l->redraw = true;
			}
		}
	}
}

RECT DISPLAY::ClipRectToRect(RECT a, RECT b)
{
	RECT r;

	if(b.left < a.left)
		r.left = a.left - b.left;
	else
		r.left = 0;

	if(b.top < a.top)
		r.top = a.top - b.top;
	else
		r.top = 0;

	// prob
	if( (b.right > a.right) && ( (b.right - b.left) > (b.right - a.right) ) )
	{
		// r.right = (b.right - b.left) - (b.right - a.right);
		r.right = a.right - b.left;
	}
	else
		r.right = b.right - b.left;

	if( (b.bottom > a.bottom) && ( (b.bottom - b.top) > (b.bottom - a.bottom) ) )
	{
		// r.bottom = (b.bottom - b.top) - (b.bottom - a.bottom);
		r.bottom = a.bottom - b.top;
	}
	else
		r.bottom = b.bottom - b.top;

	return r;
}

bool DISPLAY::Pause(void)
{
	r2 = ClipRectToScreen(Dark.ir);

	if(	(e = DDS_Primary->Blt(WndRect, Dark.gfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
		return DDE("DrawLayers:Blt", e, "Dark");

	return 0;
}

/*
///////////////////////////////////////////////////////
// DrawLayers
///////////////////////////////////////////////////////
bool DISPLAY::DrawScreen(void)
{
	if( (DDS_Buffer1 != NULL) && (DDS_Buffer2 != NULL) && (DDS_Primary != NULL) && (StartLayer != NULL))
	{
		l = StartLayer;
		for(i = 0; (i < nLayers) && (l != NULL); i++)
		{
			if((l->visable) && (l->gfx != NULL))
			{
				tick = GetTickCount();
				if( (l->moveable) && (l->move != NULL) )
				{
					Val->Action->MoveObject(l);
				}
				tick = GetTickCount() - tick;
				if(tick > 0)
					move_rate = (float)( 1000/tick );
				else
					move_rate = (float)( 1000 );

				tick = GetTickCount();
				if(l->type == LT_SPRITE)
				{
					if( (l->animate) && (!l->anim_done) )
						l->redraw = Animate(l);
				}
				tick = GetTickCount() - tick;
				if(tick > 0)
					anim_rate = (float)( 1000/tick );
				else
					anim_rate = (float)( 1000 );

				// Image\Sprite layer
				if( (ONSCREEN_RECT(l->r, G_XRES, G_YRES)) )// && (l->redraw) )
				{
					redraw_old = false;
					// clear out old data
					tick = GetTickCount();
					if(ONSCREEN_RECT(l->old_r, xMax, yMax))
					{
						r1 = ClipRectToScreen(l->old_r);

						TempLayer = StartLayer;
						for(j = 0; (j < nLayers) && (TempLayer != NULL); j++)
						{
							if( (TempLayer != l) && (!TempLayer->redraw) && (TempLayer->visable) && (TempLayer->gfx != NULL) && ( IN_RECT(TempLayer->r, r1) ) )
							{
								if(!redraw_old)
								{
									if(	(e = DDS_Buffer2->Blt(&r1, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
										return DDE("DrawLayers:Blt", e);
								}

								//r2 = ClipRectToImage(TempLayer->r);

								// clip draw layer
								r3 = ClipRectToRect(TempLayer->r, r1);
								// clip temp layer
								r4 = ClipRectToRect(r1, TempLayer->r);

								if(	(e = DDS_Buffer2->Blt(&r3, TempLayer->gfx, &r4, DDBLT_KEYSRC, NULL)) != DD_OK)
									return DDE("DrawLayers:Blt", e);

								redraw_old = true;
							}

							TempLayer = TempLayer->next;
						}

						if(redraw_old)
						{
							r2 = ClipRectToScreen(l->old_ir);
							if(	(e = DDS_Buffer1->Blt(&r1, DDS_Buffer2, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
								return DDE("DrawLayers:Blt", e);
						}
					}
												
					l->old_r = l->r;
					l->old_ir = l->ir;

					tick = GetTickCount() - tick;
					if(tick > 0)
						clean_rate = (float)( 1000/tick );
					else
						clean_rate = (float)( 1000 );
					//


					tick = GetTickCount();
					// clear old data
					r1 = ClipRectToScreen(l->ir);
					if(	(e = DDS_Buffer2->Blt(&r1, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
						return DDE("DrawLayers:Blt", e);
					// copy gfx
					r2 = ClipImageToScreen(l->r, l->ir);
					if(	(e = DDS_Buffer2->Blt(&r1, l->gfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
						return DDE("DrawLayers:Blt", e);

					tick = GetTickCount() - tick;
					if(tick > 0)
						draw_rate = (float)( 1000/tick );
					else
						draw_rate = (float)( 1000 );

					// print layer all overlapping layers
					r1 = ClipRectToScreen(l->r);

					TempLayer = l->next;
					for(j = 1; (j < (nLayers - i)) && (TempLayer != NULL); j++)
					{
						if( (!TempLayer->redraw) && (TempLayer->visable) && (TempLayer->gfx != NULL) && ( IN_RECT(TempLayer->r, r1) ) )
						{
							r2 = ClipRectToScreen(TempLayer->r);

							// clip draw layer
							r3 = ClipRectToRect(r2, r1);
							// clip temp layer
							r4 = ClipRectToRect(r1, r2);

							if(	(e = DDS_Buffer2->Blt(&r3, TempLayer->gfx, &r4, DDBLT_KEYSRC, NULL)) != DD_OK)
								return DDE("DrawLayers:Blt", e);
						}

						TempLayer = TempLayer->next;
					}

					r2 = ClipRectToScreen(l->ir);
					if(	(e = DDS_Buffer1->Blt(&r1, DDS_Buffer2, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
						return DDE("DrawLayers:Blt", e);


					r1 = ClipRectToScreen(l->r);
					r2 = ClipImageToScreen(l->r, l->ir);
					if(	(e = DDS_Buffer1->Blt(&r1, l->gfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
						return DDE("DrawLayers:Blt", e);

					GlobalReDraw = true;
					l->redraw = false;
				}
			}
			else if( (!l->visable) && (l->clear_dd) )
			{

				// clean up image
						r1 = ClipRectToScreen(l->old_ir);
						if(	(e = DDS_Buffer2->Blt(&r1, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
							return DDE("DrawLayers:Blt", e);

						r1 = ClipRectToScreen(l->old_r);
						TempLayer = StartLayer;
						for(j = 0; (j < nLayers) && (TempLayer != NULL); j++)
						{
							if( (TempLayer->visable) && (TempLayer->gfx != NULL) && ( IN_RECT(TempLayer->r, r1) ) )
							{
								r2 = ClipRectToScreen(TempLayer->r);

								// clip draw layer
								r3 = ClipRectToRect(r2, r1);
								// clip temp layer
								r4 = ClipRectToRect(r1, r2);

								if(	(e = DDS_Buffer2->Blt(&r3, TempLayer->gfx, &r4, DDBLT_KEYSRC, NULL)) != DD_OK)
									return DDE("DrawLayers:Blt", e);
							}

							TempLayer = TempLayer->next;
						}

						r2 = ClipImageToScreen(l->r, l->ir);
						if(	(e = DDS_Buffer1->Blt(&r1, DDS_Buffer2, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
							return DDE("DrawLayers:Blt", e);
					//

				l->clear_dd = false;
				GlobalReDraw = true;
				l->redraw = false;
			}


			l = (LAYER *)l->next;
		}
	}

//
// Mouse
//
	if( (UseMouse) && ONSCREEN_RECT(Mouse->r, G_XRES, G_YRES) && (Mouse->draw))
	{
		// clean up image
			r1 = ClipRectToScreen(Mouse->old_ir);
			if(	(e = DDS_Buffer2->Blt(&r1, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
				return DDE("DrawLayers:Blt", e);

			r1 = ClipRectToScreen(Mouse->old_r);
			TempLayer = StartLayer;
			for(j = 0; (j < nLayers) && (TempLayer != NULL); j++)
			{
				if( (!TempLayer->redraw) && (TempLayer->visable) && (TempLayer->gfx != NULL) && ( IN_RECT(TempLayer->r, r1) ) )
				{
					r2 = ClipRectToScreen(TempLayer->r);

					// clip draw layer
					r3 = ClipRectToRect(r2, r1);
					// clip temp layer
					r4 = ClipRectToRect(r1, r2);

					if(	(e = DDS_Buffer2->Blt(&r3, TempLayer->gfx, &r4, DDBLT_KEYSRC, NULL)) != DD_OK)
						return DDE("DrawLayers:Blt", e);
				}

				TempLayer = TempLayer->next;
			}

			r2 = ClipImageToScreen(Mouse->old_r, Mouse->old_ir);
			if(	(e = DDS_Buffer1->Blt(&r1, DDS_Buffer2, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
				return DDE("DrawLayers:Blt", e);

			Mouse->old_r = Mouse->r;
			Mouse->old_ir = Mouse->ir;
		//
	
		r1 = ClipRectToScreen(Mouse->r);
		r2 = ClipImageToScreen(Mouse->r, Mouse->ir);
		if(	(e = DDS_Buffer1->Blt(&r1, Mouse->gfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
			return DDE("DrawLayers:Blt", e);

		GlobalReDraw = true;
		Mouse->draw = false;
	}

	if(GlobalReDraw)
	{
		tick = GetTickCount();
		if(	(e = DDS_Primary->Blt(WndRect, DDS_Buffer1, NULL, 0, NULL)) != DD_OK)
			return DDE("DrawLayers:Blt", e);
		tick = GetTickCount() - tick;
		if(tick > 0)
			screen_rate = (float)( 1000/tick );
		else
			screen_rate = (float)( 1000 );

		GlobalReDraw = false;
	}

	return 0;
}
*/
