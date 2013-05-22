////////////////////////////////////////////////////////////////////////
//	Program Name:	LayerUtil.cpp
//	Programmer:		Joseph E. Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Layer Util File
//	Date:					04/10/2000
//	Version:			2.00
////////////////////////////////////////////////////////////////////////

#include "..\Header Files\DisplayClass.h"

void DISPLAY::SetStr(char **a, const char *b) 
{
	*a = new char[ strlen(b) ];
	strcpy(*a, b);
}

void DISPLAY::SetStr(char **a, const char *b, unsigned __int8 num) 
{
	*a = new char[ num + 1 ];
	strncpy(*a, b, num);
	(*a)[num] = 0;
}

void DISPLAY::PlaceLayerAfter(LAYER *layer, LAYER *A)
{
	if((layer != NULL) && (A != NULL) )
	{
		if(EndLayer == NULL)
		{
			EndLayer = layer;

			if(StartLayer == NULL)
				StartLayer = layer;
		}
		else
		{
			if( (layer->prev != NULL) && (layer->next != NULL))
			{
				// fill gap
				if(layer->prev != NULL)
				{
					if(layer->next != NULL)
						layer->prev->next = layer->next;
				}
				// if no provious then it must be the first layer
				else if(StartLayer != NULL)
					StartLayer = StartLayer->next;
				else if(StartLayer == NULL)
					StartLayer = layer;

				layer->next = A->next;
				A->next = layer;
			}
			else
			{
				layer->next = A->next;
				A->next = layer;
			}
		}
	}
}

// Placed layer at end of the layer stack
void DISPLAY::AppendLayer(LAYER *layer)
{
	if(layer!= NULL)
	{
		if(EndLayer == NULL)
		{
			EndLayer = layer;

			if(StartLayer == NULL)
				StartLayer = layer;
		}
		else
		{
			if( (layer->prev != NULL) && (layer->next != NULL))
			{
				// fill gap
				if(layer->prev != NULL)
				{
					if(layer->next != NULL)
						layer->prev->next = layer->next;
				}
				// if no provious then it must be the first layer
				else if(StartLayer != NULL)
					StartLayer = StartLayer->next;
				else if(StartLayer == NULL)
					StartLayer = layer;

				layer->prev = EndLayer;
				EndLayer->next = layer;
				EndLayer = layer;
				EndLayer->next = NULL;
			}
			else
			{
				layer->prev = EndLayer;
				EndLayer->next = layer;
				EndLayer = layer;
				EndLayer->next = NULL;
			}
		}
	}
}

LAYER *DISPLAY::CopyLayer(LAYER *layer, char *name, unsigned __int8 PlacementType)
{
	LAYER *temp = new LAYER;
	ZeroMemory(temp, sizeof(LAYER));

	temp->extra1 = layer->extra1;
	temp->extra2 = layer->extra2;
	temp->extra3 = layer->extra3;

	temp->redraw = layer->redraw;
	temp->visable = layer->visable;
	
	temp->type = layer->type;

	temp->clear_dd = layer->clear_dd;
	temp->tick = layer->tick;

	if(name == NULL)
		temp->Name = layer->Name;
	else
		SetStr(&temp->Name, name);

	temp->mList = layer->mList;
	temp->move = layer->move;

	if(layer->move != NULL)
		temp->d = layer->move->fd;
	/*
	// not sure
	if(layer->move != NULL)
	{
		temp->move = new MOVE;
		unsigned __int8 num = layer->move->num - 1;
		temp->move->fd = new XY[num];
		temp->move->delay = layer->move->delay;
		for(j = 0; j < num; j++)
		{
			temp->move->fd[j].x = layer->move->fd[j].x;
			temp->move->fd[j].y = layer->move->fd[j].y;
			temp->move->fd[j].next = &temp->move->fd[j + 1];
		}
		temp->move->fd[j].x = layer->move->fd[j].x;
		temp->move->fd[j].y = layer->move->fd[j].y;
		temp->move->fd[j].next = NULL;
		temp->d = temp->move->fd;
	}
	*/

	temp->moveable = layer->moveable;
	temp->movement_done = layer->movement_done;
	temp->move_type = layer->move_type;
	temp->move_count = layer->move_count;
	temp->o_move_count = layer->o_move_count;
	temp->move_tick = layer->move_tick;

	temp->col = layer->col;
	temp->collidable = layer->collidable;

	temp->clip = layer->clip;
	temp->cr = layer->cr;

	temp->hx = layer->hx;
	temp->hy = layer->hy;
	temp->r = layer->r;
	temp->ir = layer->ir;
	temp->old_r = layer->old_r;
	temp->old_ir = layer->old_ir;

	if(layer->startanim != NULL)
	{
		ANIM *ta;
		CEL *tc;
		unsigned __int8 i, j;

		ta = temp->anim = temp->startanim = new ANIM[layer->NumAnim];
		ZeroMemory(ta, layer->NumAnim*sizeof(ANIM));

		for(i = 0, a = layer->startanim; (a != NULL) || (ta != NULL); i++, a = a->next, ta = ta->next)
		{
			ta->name = a->name;
			ta->done = a->done;
			ta->loop_type = a->loop_type;
			ta->loop_count = a->loop_count;
			ta->o_loop_count =  a->o_loop_count;

			if(i < (layer->NumAnim - 1) )
				ta->next = &temp->anim[i + 1];
			else
				ta->next = NULL;

			ta->nCel = a->nCel;
			
			tc = ta->cel = ta->startcel = new CEL[a->nCel];
			ZeroMemory(tc, a->nCel*sizeof(CEL));
			
			for(j = 0, c = a->startcel; (c != NULL) || (tc != NULL) ; j++, c = c->next, tc = tc->next)
			{
				tc->delay = c->delay;
				tc->w = c->w;
				tc->h = c->h;
				tc->hx = c->hx;
				tc->hy = c->hy;
				tc->bx = c->bx;
				tc->by = c->by;
				tc->gfx = CopyGfx(c->gfx, c->w, c->h);

				if(j < (a->nCel - 1) )
					tc->next = &ta->cel[j + 1];
				else
					tc->next = NULL;
			}
		}
		temp->Reset();
	}
	else
	{
		temp->gfx = CopyGfx(layer->gfx, (unsigned __int16)temp->ir.right, (unsigned __int16)temp->ir.bottom);
		temp->object = layer->object;
		temp->lobject = layer->lobject;
	}

	if(PlacementType)
		PlaceLayerAfter(temp, layer);
	else
		AppendLayer(temp);

	nLayers++;

	return temp;
}

GFXDATA DISPLAY::CopyGfx(GFXDATA src, unsigned __int16 w, unsigned __int16 h)
{
	GFXDATA gfx;
	r1.left = r1.top = 0;
	r1.right = w;
	r1.bottom = h;
	//
	DD_SDESC	ddsd;
	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize		= sizeof(ddsd);
	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	ddsd.dwWidth	= w;
	ddsd.dwHeight	= h;
	//
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
	if( (e = DD_Object->CreateSurface(&ddsd, &gfx, NULL)) != DD_OK )
	{
		if( DDE("LoadDrawS:CreateSurface", e, "CopyLayer:new layer") )
			return NULL;
	}
	if( (e = DDSetColorKey(gfx,  TRANS_COLOR1 ) ) != DD_OK)
	{
		if( DDE("LoadDrawS:DDSetColorKey", e, "CopyLayer:new layer") )
			return NULL;
	}
	
	FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);
	if(	(e = gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
	{
		if( DDE("DrawLayers:FloodFill", e, "CopyLayer:new layer") )
			return NULL;
	}

	if(	(e = gfx->Blt(&r1, src, NULL,  DDBLT_KEYSRC, &FxBkg)) != DD_OK)
	{
		if( DDE("DrawLayers:FloodFill", e, "CopyLayer:new layer") )
			return NULL;
	}

	return gfx;
}

LAYER *DISPLAY::CreateTextBox(LAYER_INFO *l_info)
{
	l = new LAYER;
	ZeroMemory(l, sizeof(LAYER));

	l->type = LT_TEXT;
	l->Name = l_info->Name;
	l->visable = l_info->visable;
	l->moveable = l_info->moveable;
	l->clip = l_info->clip;
	l->move_type = l_info->move_type;
	l->o_move_count = l->move_count = l_info->move_count;
	l->collidable = l_info->collidable;
	l->extra1 = l_info->extra1;
	l->extra2 = l_info->extra2;
	l->extra3 = l_info->extra3;
	l->SetSize(l_info->w, l_info->h);

	l->SetClipRect(l_info->cx, l_info->cy, l_info->cw, l_info->ch);
	l->SetPos(l_info->x, l_info->y);
	l->SetHotSpot(l_info->hx, l_info->hy);
	l->old_r = l->r;
	l->old_ir = l->ir;

	l->redraw = true;

	l->text = l_info->text;

	unsigned __int8 i;
	DD_SDESC	ddsd;
	FONT *f = &Font[l->FontNum];
	char *S1, *S2;
	unsigned __int16 pos = 0, row = 0, last = 0, chardone = 0;
	GFXDATA TempGfx;
	
	r2.top = 0;	r2.bottom = f->ch;

	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize		= sizeof(ddsd);
	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	ddsd.dwWidth	= l->ir.right;
	ddsd.dwHeight	= l->ir.bottom;
	//
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
	if( (e = DD_Object->CreateSurface(&ddsd, &l->gfx, NULL)) != DD_OK )
	{
		char S[256];
		sprintf(S, "Create:TextBox:%s", l->Name);
		DDE("LoadDrawS:CreateSurface", e, S);
		return NULL;
	}
	if( (e = DDSetColorKey(l->gfx,  TRANS_COLOR1 ) ) != DD_OK)
	{
		char S[256];
		sprintf(S, "SetColorKey:TextBox:%s", l->Name);
		DDE("LoadDrawS:DDSetColorKey", e, S );
		return NULL;
	}
	if(	(e = l->gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
	{
		char S[256];
		sprintf(S, "FloodFill:TextBox:%s", l->Name);
		DDE("DrawLayers:Blt", e, S);
		return NULL;
	}

	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize		= sizeof(ddsd);
	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	ddsd.dwWidth	= l->ir.right;
	ddsd.dwHeight	= l->ir.bottom;
	//
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
	if( (e = DD_Object->CreateSurface(&ddsd, &TempGfx, NULL)) != DD_OK )
	{
		DDE("LoadDrawS:CreateSurface", e, "Create:TextBox:temp");
		return NULL;
	}
	if( (e = DDSetColorKey(TempGfx,  TRANS_COLOR1 ) ) != DD_OK)
	{
		DDE("LoadDrawS:DDSetColorKey", e, "SetColorKey:TextBox:temp");
		return NULL;
	}

	S1 = l->text;
	for(i = 0; S1 != NULL; i++)
	{
		S2 = strchr(S1, ' ');

		if(S2 != NULL)
			pos += S2 - S1 + 1;

		if( ((pos*f->cw) > l->ir.right) || (S2 == NULL) )
		{
			if(S2 != NULL)
				last += pos - (S2 - S1 + 1);
			else
				last += pos + strlen(S1);

			if(	(e = TempGfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
			{
				DDE("DrawLayers:Blt", e, "FloodFill:TextBox:temp");
				return NULL;
			}

			r1.top = 0;		r1.bottom = f->ch;
			for(j = 0; (j + chardone) < last; j++)
			{
				r1.left = j*(f->cw);
				r1.right = r1.left + f->cw;		

				r2.left = (l->text[j + chardone] - 32 )*(f->cw);
				r2.right = r2.left + f->cw;
				
				if(	(e = TempGfx->Blt(&r1, f->gfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
				{
					DDE("DrawLayers:Blt", e, "Blt:TextBox:char to temp");
					return NULL;
				}
			}

			if(l->hAlign == AT_CENTER)
			{
				r1.left = ( l->ir.right - j*(f->cw) ) >> 1;
				r1.right = r1.left + j*(f->cw);
			}
			else if(l->hAlign == AT_LEFT)
			{
				r1.left = 0;	r1.right = j*(f->cw);
			}
			else
			{
				r1.left = l->ir.right - j*(f->cw);
				r1.right = l->ir.right;
			}

			r1.top = row*(f->ch);
			r1.bottom = r1.top + f->ch;

			r2.left = 0;
			r2.right = j*(f->cw);
			
			if(	(e = l->gfx->Blt(&r1, TempGfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
			{
				DDE("DrawLayers:Blt", e, "Blt:TextBox:temp to layer");
				return NULL;
			}

			chardone += j;
			pos = 0;
			row++;
			if(S2 == NULL)
				S1 = NULL;
			//
		}
		else
			S1 = S2 + 1;
	}
	
	TempGfx->Release();

	AppendLayer(l);
	nLayers++;
	return l;
}

LAYER *DISPLAY::CreateSprite(LAYER_INFO *l_info)
{
	l = new LAYER;
	ZeroMemory(l, sizeof(LAYER));

	l->type = LT_SPRITE;
	l->Name = l_info->Name;
	l->visable = l_info->visable;
	l->moveable = l_info->moveable;
	l->clip = l_info->clip;
	l->move_type = l_info->move_type;
	l->o_move_count = l->move_count = l_info->move_count;
	l->extra1 = l_info->extra1;
	l->extra2 = l_info->extra2;
	l->extra3 = l_info->extra3;
	l->collidable = l_info->collidable;

	l->SetSize(l_info->w, l_info->h);
	l->SetClipRect(l_info->cx, l_info->cy, l_info->cw, l_info->ch);
	l->SetPos(l_info->x, l_info->y);
	l->SetHotSpot(l_info->hx, l_info->hy);
	l->old_r = l->r;
	l->old_ir = l->ir;

	l->redraw = true;

	if(l_info->NumAnim)
	{
		a = l->startanim = l->anim= new ANIM[ l_info->NumAnim ];
		ZeroMemory(l->anim, l_info->NumAnim*sizeof(ANIM) );

		ANIM_INFO *ai;
		CEL_INFO *ci;
		unsigned __int8 k;
		for(k = 0; (k < l_info->NumAnim) || (a != NULL); k++, a = a->next)
		{
			ai = &l_info->anim_info[k];
			a->loop_type = ai->loop_type;
			a->loop_count = a->o_loop_count = ai->loop_count;
			a->name = ai->name;

			if(k < (l_info->NumAnim - 1) )
				a->next = &l->anim[k + 1];
			else
				a->next = NULL;

			a->nCel = ai->nCel;
			c = a->startcel = a->cel= new CEL[ ai->nCel ];
			ZeroMemory(a->cel, ai->nCel*sizeof(CEL) );
			
			for(j = 0; j < ai->nCel; j++, c = c->next)
			{
				ci = &ai->cel_info[j];
				c->delay = ci->delay;
				c->hx = ci->hx;
				c->hy = ci->hy;
				c->bx = ci->bx;
				c->by = ci->by;
				c->w = ci->w;
				c->h = ci->h;

				if(j < (ai->nCel - 1) )
					c->next = &a->cel[j + 1];
				else
					c->next = NULL;

				/*
				if( (l->gfx = GfxToDD(DD_Object, "gfx\\01.gfx")) == NULL )
					return DDE("LoadDrawS:DDLoadBitmap", i);
				*/
				if( (c->gfx = DDLoadBitmap(DD_Object, ci->fName, 0, 0)) == NULL )
				{
					char S[256];
					sprintf(S, "Load:Sprite:%s", ci->fName);
					DDE("LoadDrawS:DDLoadBitmap", i, S);
					return NULL;
				}
				if( (e = DDSetColorKey(c->gfx,  TRANS_COLOR1 ) ) != DD_OK)
				{
					char S[256];
					sprintf(S, "SetColorKey:Sprite:%s", ci->fName);
					DDE("LoadDrawS:DDSetColorKey", e, S);
					return NULL;
				}
				if( (k == 0) && (j == 0) )
					l->gfx = c->gfx;

			}
		}
	}

	AppendLayer(l);
	nLayers++;
	return l;
}

LAYER *DISPLAY::CreateImage(LAYER_INFO *l_info)
{
	l = new LAYER;
	ZeroMemory(l, sizeof(LAYER));

	l->type = LT_IMAGE;
	l->Name = l_info->Name;
	l->visable = l_info->visable;
	l->moveable = l_info->moveable;
	l->clip = l_info->clip;
	l->move_type = l_info->move_type;
	l->o_move_count = l->move_count = l_info->move_count;
	l->extra1 = l_info->extra1;
	l->extra2 = l_info->extra2;
	l->extra3 = l_info->extra3;
	l->collidable = l_info->collidable;

	l->SetSize(l_info->w, l_info->h);
	l->SetClipRect(l_info->cx, l_info->cy, l_info->cw, l_info->ch);
	l->SetPos(l_info->x, l_info->y);
	l->SetHotSpot(l_info->hx, l_info->hy);
	l->old_r = l->r;
	l->old_ir = l->ir;

	l->redraw = true;

	if( (l->gfx = DDLoadBitmap(DD_Object, l_info->fName, 0, 0)) == NULL )
	{
		char S[256];
		sprintf(S, "Load:Image:%s", l_info->fName);
		DDE("LoadDrawS:DDLoadBitmap", i, S);
		return NULL;
	}
	if( (e = DDSetColorKey(l->gfx,  TRANS_COLOR1 ) ) != DD_OK)
	{
		char S[256];
		sprintf(S, "SetColorKey:Image:%s", l_info->fName);
		DDE("LoadDrawS:DDSetColorKey", e, S);
		return NULL;
	}

	AppendLayer(l);
	nLayers++;
	return l;
}

LAYER *DISPLAY::CreateMap(LAYER_INFO *l_info)
{
	l = new LAYER;
	ZeroMemory(l, sizeof(LAYER));

	l->type = LT_MAP;
	l->Name = l_info->Name;
	l->visable = l_info->visable;
	l->moveable = l_info->moveable;
	l->clip = l_info->clip;
	l->move_type = l_info->move_type;
	l->o_move_count = l->move_count = l_info->move_count;
	l->extra1 = l_info->extra1;
	l->extra2 = l_info->extra2;
	l->extra3 = l_info->extra3;
	l->collidable = l_info->collidable;

	l->redraw = true;

	DD_SDESC	ddsd;
	unsigned __int8 k = l_info->map_num_images;
	GFXDATA *TempGfx = new GFXDATA[k];
	unsigned __int16 w, h, iw, ih;
	unsigned __int8 **data = l_info->map_info->data;

	// number of images horz
	w = l_info->w;
	// number of images vert
	h = l_info->h;

	// number of images horz
	iw = l_info->map_image_w;
	// number of images vert
	ih = l_info->map_image_h;

	r2.top = r2.left = 0;
	r2.right = iw;
	r2.bottom = ih;

	// create layer gfx to place images into
		ZeroMemory(&ddsd, sizeof(ddsd));
		ddsd.dwSize		= sizeof(ddsd);
		ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
		ddsd.dwWidth	= l_info->w = w*iw;
		ddsd.dwHeight	= l_info->h = h*ih;
		//
		ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
		if( (e = DD_Object->CreateSurface(&ddsd, &l->gfx, NULL)) != DD_OK )
		{
			char S[256];
			sprintf(S, "Map:%s", l_info->fName);
			DDE("LoadDrawS:CreateSurface", e, S);
			return NULL;
		}

		if( (e = DDSetColorKey(l->gfx,  TRANS_COLOR1 ) ) != DD_OK)
		{
			char S[256];
			sprintf(S, "Map:%s", l_info->fName);
			DDE("LoadDrawS:DDSetColorKey", e, S);
			return NULL;
		}

		if(	(e = l->gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
		{
			char S[256];
			sprintf(S, "Map:%s", l_info->fName);
			DDE("DrawLayers:FloodFill", e, S);
			return NULL;
		}
	//

	for(j = 0; j < k; j++)
	{
		if( (TempGfx[j] = DDLoadBitmap(DD_Object, l_info->map_info->fName[j], 0, 0)) == NULL )
		{
			char S[256];
			sprintf(S, "Map:%s", l_info->map_info->fName[j]);
			DDE("LoadDrawS:DDLoadBitmap", i, S);
			return NULL;
		}
		if( (e = DDSetColorKey(TempGfx[j],  TRANS_COLOR1 ) ) != DD_OK)
		{
			char S[256];
			sprintf(S, "Map:%s", l_info->map_info->fName[j]);
			DDE("LoadDrawS:DDSetColorKey", e, S);
			return NULL;
		}
	}

	k = 0;
	for(j = 0; k < h;)
	{
		r1.left = j*iw;
		r1.top = k*ih;
		r1.right = r1.left + iw;
		r1.bottom = r1.top + ih;

		if(	(e = l->gfx->Blt(&r1, TempGfx[ data[k][j] ], &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
		{
			char S[256];
			sprintf(S, "Map:temp to gfx:%s", l_info->fName);
			DDE("DrawLayers:Blt", e, S);
			return NULL;
		}

		j++;
		if((j%w) == 0)
		{
			j = 0;
			k++;
		}
	}

	l->SetSize(l_info->w, l_info->h);
	l->SetClipRect(l_info->cx, l_info->cy, l_info->cw, l_info->ch);
	l->SetPos(l_info->x, l_info->y);
	l->SetHotSpot(l_info->hx, l_info->hy);
	l->old_r = l->r;
	l->old_ir = l->ir;

	k = l_info->map_num_images;
	for(j = 0; j < k; j++)
		TempGfx[j]->Release();

	AppendLayer(l);
	nLayers++;
	return l;
}

LAYER *DISPLAY::CreateTile(LAYER_INFO *l_info)
{
	l = new LAYER;
	ZeroMemory(l, sizeof(LAYER));

	l->type = LT_TILE;
	l->Name = l_info->Name;
	l->visable = l_info->visable;
	l->moveable = l_info->moveable;
	l->clip = l_info->clip;
	l->move_type = l_info->move_type;
	l->o_move_count = l->move_count = l_info->move_count;
	l->extra1 = l_info->extra1;
	l->extra2 = l_info->extra2;
	l->extra3 = l_info->extra3;
	l->collidable = l_info->collidable;

	l->redraw = true;

	DD_SDESC	ddsd;
	unsigned __int8 k = 0;
	GFXDATA TempGfx;
	unsigned __int16 w, h, iw, ih;

	// number of images horz
	w = l_info->w;
	// number of images vert
	h = l_info->h;

	// number of images horz
	iw = l_info->tile_image_w;
	// number of images vert
	ih = l_info->tile_image_h;

	r2.top = r2.left = 0;
	r2.right = iw;
	r2.bottom = ih;

	// create layer gfx to place images into
		ZeroMemory(&ddsd, sizeof(ddsd));
		ddsd.dwSize		= sizeof(ddsd);
		ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
		ddsd.dwWidth	= l_info->w = w*iw;
		ddsd.dwHeight	= l_info->h = h*ih;
		//
		ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
		if( (e = DD_Object->CreateSurface(&ddsd, &l->gfx, NULL)) != DD_OK )
		{
			char S[256];
			sprintf(S, "Tile:%s", l_info->fName);
			DDE("LoadDrawS:CreateSurface", e, S);
			return NULL;
		}

		if( (e = DDSetColorKey(l->gfx,  TRANS_COLOR1 ) ) != DD_OK)
		{
			char S[256];
			sprintf(S, "Tile:%s", l_info->fName);
			DDE("LoadDrawS:DDSetColorKey", e, S);
			return NULL;
		}

		if(	(e = l->gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
		{
			char S[256];
			sprintf(S, "Tile:%s", l_info->fName);
			DDE("DrawLayers:FloodFill", e, S);
			return NULL;
		}
	//

	if( (TempGfx = DDLoadBitmap(DD_Object, l_info->tile_info->fName, 0, 0)) == NULL )
	{
		char S[256];
		sprintf(S, "Tile:%s", l_info->tile_info->fName);
		DDE("LoadDrawS:DDLoadBitmap", i, S);
		return NULL;
	}
	if( (e = DDSetColorKey(TempGfx,  TRANS_COLOR1 ) ) != DD_OK)
	{
		char S[256];
		sprintf(S, "Tile:%s", l_info->tile_info->fName);
		DDE("LoadDrawS:DDSetColorKey", e, S);
		return NULL;
	}

	k = 0;
	for(j = 0; k < h;)
	{
		r1.left = j*iw;
		r1.top = k*ih;
		r1.right = r1.left + iw;
		r1.bottom = r1.top + ih;

		if(	(e = l->gfx->Blt(&r1, TempGfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
		{
			char S[256];
			sprintf(S, "Tile:temp to gfx:%s", l_info->fName);
			DDE("DrawLayers:Blt", e, S);
			return NULL;
		}

		j++;
		if((j%w) == 0)
		{
			j = 0;
			k++;
		}
	}

	l->SetSize(l_info->w, l_info->h);
	l->SetClipRect(l_info->cx, l_info->cy, l_info->cw, l_info->ch);
	l->SetPos(l_info->x, l_info->y);
	l->SetHotSpot(l_info->hx, l_info->hy);
	l->old_r = l->r;
	l->old_ir = l->ir;

	TempGfx->Release();

	AppendLayer(l);
	nLayers++;
	return l;
}

LAYER *DISPLAY::CreateWin(LAYER_INFO *l_info)
{
	l = new LAYER;
	ZeroMemory(l, sizeof(LAYER));

	l->type = LT_WINDOW;
	l->Name = l_info->Name;
	l->visable = l_info->visable;
	l->moveable = l_info->moveable;
	l->clip = l_info->clip;
	l->move_type = l_info->move_type;
	l->o_move_count = l->move_count = l_info->move_count;
	l->extra1 = l_info->extra1;
	l->extra2 = l_info->extra2;
	l->extra3 = l_info->extra3;
	l->collidable = l_info->collidable;
	l->redraw = true;

	DD_SDESC	ddsd;
	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize		= sizeof(ddsd);
	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

	unsigned __int16 w, h, iw, ih, inside_w, inside_h, tab_w, tab_h;

	iw = l_info->win_image_w;
	ih = l_info->win_image_h;

	unsigned __int8 tab_iw = l_info->win->tab->wImg;

	w = l_info->w;
	if( GETBIT(l->wType, WT_TAB) )
	{
		tab_w = l_info->win->tab->w;
		tab_h = l_info->win->tab->h;
		h = l_info->h + tab_h;
		inside_h = l_info->h - ih;
	}
	else
	{
		h = l_info->h;
		inside_h = l_info->h - (ih << 1);
	}

	inside_w = w - (iw << 1);
	l_info->h += tab_h;

	// create layer gfx to place images into
		ddsd.dwWidth	= w;
		ddsd.dwHeight	= h;
		if( (e = DD_Object->CreateSurface(&ddsd, &l->gfx, NULL)) != DD_OK )
		{
			char S[256];
			sprintf(S, "Tile:%s", l_info->fName);
			DDE("LoadDrawS:CreateSurface", e, S);
			return NULL;
		}

		if( (e = DDSetColorKey(l->gfx,  TRANS_COLOR1 ) ) != DD_OK)
		{
			char S[256];
			sprintf(S, "Tile:%s", l_info->fName);
			DDE("LoadDrawS:DDSetColorKey", e, S);
			return NULL;
		}

		//FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, RGB(0, 255, 0));
		if(	(e = l->gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
		{
			char S[256];
			sprintf(S, "Tile:%s", l_info->fName);
			DDE("DrawLayers:FloodFill", e, S);
			return NULL;
		}
		//FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);

//
//
//
	unsigned __int8 k;
	GFXDATA *TempGfx;
	TempGfx = new GFXDATA[9];
	memset(TempGfx, 0,  9*sizeof(GFXDATA));

	bool usebgcolor = GETBIT(l->wType, WT_BGCOLOR) ? 1 : 0;
	k = GETBIT(l->wType, WT_TAB) ? 1 : 0;
	for(; k < 9; k++)
	{
		if( (usebgcolor) && (k == W_MIDDLE) )
			k++;

		if( (TempGfx[k] = DDLoadBitmap(DD_Object, l_info->win->img[k], 0, 0)) == NULL )
		{
			char S[256];
			sprintf(S, "Tile:%s", l_info->win->img[k]);
			DDE("LoadDrawS:DDLoadBitmap", i, S);
			return NULL;
		}
	}

	GFXDATA Left, Right, Bottom, Middle, Top;
	
	ddsd.dwWidth	= iw;	ddsd.dwHeight	= inside_h;
	//
	if( (e = DD_Object->CreateSurface(&ddsd, &Left, NULL)) != DD_OK )
	{
		DDE("LoadDrawS:CreateSurface", e, "Window:Left");
		return NULL;
	}
	if( (e = DDSetColorKey(Left,  TRANS_COLOR1 ) ) != DD_OK)
	{
		DDE("LoadDrawS:DDSetColorKey", e, "Window:Left");
		return NULL;
	}
	DrawTile(Left, TempGfx[W_LEFT], iw, inside_h, iw, ih);

	r1.top = GETBIT(l->wType, WT_TAB) ? tab_h : ih;
	r1.bottom = r1.top + inside_h;
	r1.left = 0;
	r1.right = iw;
	// Draw left to gfx
	if(	(e = l->gfx->Blt(&r1, Left, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)
	{
		DDE("DrawLayers:Blt", e, "Window:left to gfx");
		return NULL;
	}

	Left->Release();

	//
	if( (e = DD_Object->CreateSurface(&ddsd, &Right, NULL)) != DD_OK )
	{
		DDE("LoadDrawS:CreateSurface", e, "Window:right");
		return NULL;
	}
	if( (e = DDSetColorKey(Right,  TRANS_COLOR1 ) ) != DD_OK)
	{
		DDE("LoadDrawS:DDSetColorKey", e, "Window:right");
		return NULL;
	}
	DrawTile(Right, TempGfx[W_RIGHT], iw, inside_h, iw, ih);

	r1.top = GETBIT(l->wType, WT_TAB) ? tab_h : ih;
	r1.bottom = r1.top + inside_h;
	r1.left = w - iw;
	r1.right = w;
	// Draw right to gfx
	if(	(e = l->gfx->Blt(&r1, Right, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)
	{
		DDE("DrawLayers:Blt", e, "Window:right to gfx");
		return NULL;
	}

	Right->Release();

	//
	//
	//
	if( GETBIT(l->wType, WT_TAB) )
	{

		ddsd.dwWidth	= tab_w;	ddsd.dwHeight	= tab_h;
		if( (e = DD_Object->CreateSurface(&ddsd, &Top, NULL)) != DD_OK )
		{
			DDE("LoadDrawS:CreateSurface", e, "Window:top");
			return NULL;
		}
		if( (e = DDSetColorKey(Top,  TRANS_COLOR1 ) ) != DD_OK)
		{
			DDE("LoadDrawS:DDSetColorKey", e, "Window:top");
			return NULL;
		}

		GFXDATA *TempTabGfx = new GFXDATA[3];
		GFXDATA	TabMiddle;

		k = 0;
		if( (TempTabGfx[k] = DDLoadBitmap(DD_Object, l_info->win->tab->img[k], 0, 0)) == NULL )
		{
			char S[256];
			sprintf(S, "Tile:%s", l_info->win->tab->img[k]);
			DDE("LoadDrawS:DDLoadBitmap", i, S);
			return NULL;
		}
		k++;

		if( (TempTabGfx[k] = DDLoadBitmap(DD_Object, l_info->win->tab->img[k], 0, 0)) == NULL )
		{
			char S[256];
			sprintf(S, "Tile:%s", l_info->win->tab->img[k]);
			DDE("LoadDrawS:DDLoadBitmap", i, S);
			return NULL;
		}
		k++;

		if( (TempTabGfx[k] = DDLoadBitmap(DD_Object, l_info->win->tab->img[k], 0, 0)) == NULL )
		{
			char S[256];
			sprintf(S, "Tile:%s", l_info->win->tab->img[k]);
			DDE("LoadDrawS:DDLoadBitmap", i, S);
			return NULL;
		}
		k++;

		r1.left = 0;	r1.right = tab_iw;
		r1.top = 0;	r1.bottom = tab_h;
		if(	(e = Top->Blt(&r1, TempTabGfx[T_LEFT], NULL, 0, NULL)) != DD_OK)
		{
			DDE("DrawLayers:Blt", e, "Window:tab Left to gfx");
			return NULL;
		}

		r1.left = tab_w - tab_iw;	r1.right = tab_w;
		r1.top = 0;	r1.bottom = tab_h;
		if(	(e = Top->Blt(&r1, TempTabGfx[T_RIGHT], NULL, 0, NULL)) != DD_OK)
		{
			DDE("DrawLayers:Blt", e, "Window:tab right to gfx");
			return NULL;
		}

		ddsd.dwWidth	= tab_w - (tab_iw << 1);	ddsd.dwHeight	= tab_h;
		if( (e = DD_Object->CreateSurface(&ddsd, &TabMiddle, NULL)) != DD_OK )
		{
			DDE("LoadDrawS:CreateSurface", e, "Window:tab middle");
			return NULL;
		}

		DrawTile(TabMiddle, TempTabGfx[T_MIDDLE], tab_w - (tab_iw << 1), tab_h, tab_iw, tab_h);

		r1.left = tab_iw;	r1.right = tab_w - tab_iw;
		r1.top = 0;	r1.bottom = tab_h;
		if(	(e = Top->Blt(&r1, TabMiddle, NULL, 0, NULL)) != DD_OK)
		{
			DDE("DrawLayers:Blt", e, "Window:tab middle to gfx");
			return NULL;
		}

		TabMiddle->Release();

		TempTabGfx[0]->Release();
		TempTabGfx[1]->Release();
		TempTabGfx[2]->Release();

		r1.left = 0;
		r1.right = tab_w;
		r1.top = 0;
		r1.bottom = tab_h;
	}
	else
	{

		ddsd.dwWidth	= inside_w;		ddsd.dwHeight	= ih;
		if( (e = DD_Object->CreateSurface(&ddsd, &Top, NULL)) != DD_OK )
		{
			DDE("LoadDrawS:CreateSurface", e, "Window:top");
			return NULL;
		}
		if( (e = DDSetColorKey(Top,  TRANS_COLOR1 ) ) != DD_OK)
		{
			DDE("LoadDrawS:DDSetColorKey", e, "Window:top");
			return NULL;
		}
		DrawTile(Top, TempGfx[W_TOP], inside_w, ih, iw, ih);

		r1.left = iw;
		r1.right = inside_w + iw;
		r1.top = 0;
		r1.bottom = ih;
	}
	
	// Draw top to gfx
	if(	(e = l->gfx->Blt(&r1, Top, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)
	{
		DDE("DrawLayers:Blt", e, "Window:top to gfx");
		return NULL;
	}

	Top->Release();

	ddsd.dwWidth	= inside_w;		ddsd.dwHeight	= ih;
	if( (e = DD_Object->CreateSurface(&ddsd, &Bottom, NULL)) != DD_OK )
	{
		DDE("LoadDrawS:CreateSurface", e, "Window:bottom");
		return NULL;
	}
	if( (e = DDSetColorKey(Bottom,  TRANS_COLOR1 ) ) != DD_OK)
	{
		DDE("LoadDrawS:DDSetColorKey", e, "Window:bottom");
		return NULL;
	}
	DrawTile(Bottom, TempGfx[W_BOTTOM], inside_w, ih, iw, ih);


	r1.left = iw;
	r1.right = inside_w + iw;
	r1.top = h - ih;
	r1.bottom = h;
	// Draw bottom to gfx
	if(	(e = l->gfx->Blt(&r1, Bottom, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)
	{
		DDE("DrawLayers:Blt", e, "Window:bottom to gfx");
		return NULL;
	}

	Bottom->Release();

//
//
//
	ddsd.dwWidth	= inside_w;
	ddsd.dwHeight	= inside_h;
	if( (e = DD_Object->CreateSurface(&ddsd, &Middle, NULL)) != DD_OK )
	{
		DDE("LoadDrawS:CreateSurface", e, "Window:middle");
		return NULL;
	}
	if( (e = DDSetColorKey(Middle,  TRANS_COLOR1 ) ) != DD_OK)
	{
		DDE("LoadDrawS:DDSetColorKey", e, "Window:middle");
		return NULL;
	}
	if( GETBIT(l->wType, WT_BGCOLOR) )
	{
		FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, l_info->win->bgcolor);
		
		if(	(e = Middle->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
		{
			DDE("DrawLayers:FloodFill", e, "Window:middle");
			return NULL;
		}

		FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);
	}
	else
		DrawTile(Middle, TempGfx[W_MIDDLE], inside_w, inside_h, iw, ih);

//
	if( GETBIT(l->wType, WT_TAB) )
		r1.top = tab_h;
	else
		r1.top = ih;

	r1.left = iw;
	r1.right = iw + inside_w;
	r1.bottom = r1.top + inside_h;
	
	// Draw Middle to gfx
	if(	(e = l->gfx->Blt(&r1, Middle, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)
	{
		DDE("DrawLayers:Blt", e, "Window:middle to gfx");
		return NULL;
	}

	Middle->Release();


	if( GETBIT(l->wType, WT_TAB) )
	{
		GFXDATA TopMiddle;
		unsigned __int16 tmW = w - tab_w - iw;

		ddsd.dwWidth	= tmW;
		ddsd.dwHeight	= tab_h;
		if( (e = DD_Object->CreateSurface(&ddsd, &TopMiddle, NULL)) != DD_OK )
		{
			DDE("LoadDrawS:CreateSurface", e, "Window:middle");
			return NULL;
		}
		if( (e = DDSetColorKey(TopMiddle,  TRANS_COLOR1 ) ) != DD_OK)
		{
			DDE("LoadDrawS:DDSetColorKey", e, "Window:middle");
			return NULL;
		}

		DrawTile(TopMiddle, TempGfx[W_TOP], tmW, tab_h, iw, tab_h);

		r1.left = tab_w;	r1.right = w - iw;
		r1.top = 0;	r1.bottom = tab_h;
		if(	(e = l->gfx->Blt(&r1, TopMiddle, NULL, DDBLT_KEYSRC, NULL)) != DD_OK)
		{
			DDE("DrawLayers:Blt", e, "Window:top middle to gfx");
			return NULL;
		}

		TopMiddle->Release();

		if( (e = DDSetColorKey(TempGfx[W_TOP_RIGHT],  TRANS_COLOR1 ) ) != DD_OK)
		{
			DDE("LoadDrawS:DDSetColorKey", e, "Window:middle");
			return NULL;
		}

		r1.left = w - iw;	r1.right = w;
		r1.top = 0;	r1.bottom = tab_h;
		if(	(e = l->gfx->Blt(&r1, TempGfx[W_TOP_RIGHT], NULL, DDBLT_KEYSRC, NULL)) != DD_OK)
		{
			DDE("DrawLayers:Blt", e, "Window:top right middle to gfx");
			return NULL;
		}
	}
	else
	{
		if( (e = DDSetColorKey(TempGfx[W_TOP_LEFT],  TRANS_COLOR1 ) ) != DD_OK)
		{
			DDE("LoadDrawS:DDSetColorKey", e, "Window:middle");
			return NULL;
		}

		r1.left = 0;	r1.right = iw;
		r1.top = 0;	r1.bottom = ih;
		if(	(e = l->gfx->Blt(&r1, TempGfx[W_TOP_LEFT], NULL, DDBLT_KEYSRC, NULL)) != DD_OK)
		{
			DDE("DrawLayers:Blt", e, "Window:top left to gfx");
			return NULL;
		}


		if( (e = DDSetColorKey(TempGfx[W_TOP_RIGHT],  TRANS_COLOR1 ) ) != DD_OK)
		{
			DDE("LoadDrawS:DDSetColorKey", e, "Window:middle");
			return NULL;
		}

		r1.left = w - iw;	r1.right = w;
		r1.top = 0;	r1.bottom = ih;
		if(	(e = l->gfx->Blt(&r1, TempGfx[W_TOP_RIGHT], NULL, DDBLT_KEYSRC, NULL)) != DD_OK)
		{
			DDE("DrawLayers:Blt", e, "Window:top right to gfx");
			return NULL;
		}
	}

//
//
//

	if( (e = DDSetColorKey(TempGfx[W_BOTTOM_LEFT],  TRANS_COLOR1 ) ) != DD_OK)
	{
		DDE("LoadDrawS:DDSetColorKey", e, "Window:bottom left");
		return NULL;
	}
	r1.left = 0;	r1.right = iw;
	r1.top = h - ih;	r1.bottom = h;
	if(	(e = l->gfx->Blt(&r1, TempGfx[W_BOTTOM_LEFT], NULL, DDBLT_KEYSRC, NULL)) != DD_OK)
	{
		DDE("DrawLayers:Blt", e, "Window:bottom left to gfx");
		return NULL;
	}


	if( (e = DDSetColorKey(TempGfx[W_BOTTOM_RIGHT],  TRANS_COLOR1 ) ) != DD_OK)
	{
		DDE("LoadDrawS:DDSetColorKey", e, "Window:bottom right");
		return NULL;
	}
	r1.left = w - iw;	r1.right = w;
	r1.top = h - ih;	r1.bottom = h;
	if(	(e = l->gfx->Blt(&r1, TempGfx[W_BOTTOM_RIGHT], NULL, DDBLT_KEYSRC, NULL)) != DD_OK)
	{
		DDE("DrawLayers:Blt", e, "Window:bottom right to gfx");
		return NULL;
	}

//
//
//
	k = GETBIT(l->wType, WT_TAB) ? 1 : 0;
	for(; k < 9; k++)
	{
		if(usebgcolor && (k == W_MIDDLE))
			k++;

		TempGfx[k]->Release();
	}

	l->SetSize(l_info->w, l_info->h);
	l->SetClipRect(l_info->cx, l_info->cy, l_info->cw, l_info->ch);
	l->SetPos(l_info->x, l_info->y);
	l->SetHotSpot(l_info->hx, l_info->hy);
	l->old_r = l->r;
	l->old_ir = l->ir;

	AppendLayer(l);
	nLayers++;
	return l;
}

bool DISPLAY::DrawTile(GFXDATA out, GFXDATA tile, unsigned __int16 w, unsigned __int16 h, unsigned __int16 iw, unsigned __int16 ih) 
{
	GFXDATA TempGfx;
	unsigned __int8 j, k;
	unsigned __int16 out_w = w, out_h = h;
	j = w%iw ? 1 : 0;
	w = w/iw + j;
	k = h%ih ? 1 : 0;
	h = h/ih + k;

	DD_SDESC	ddsd;
	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize		= sizeof(ddsd);
	ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
	ddsd.dwWidth	= w*iw;
	ddsd.dwHeight	= h*ih;

	if( (e = DD_Object->CreateSurface(&ddsd, &TempGfx, NULL)) != DD_OK )
		return DDE("LoadDrawS:CreateSurface", e, "DrawTile:TempGfx");

	for(j = 0, k = 0; k < h;)
	{
		r1.left = j*iw;
		r1.top = k*ih;
		r1.right = r1.left + iw;
		r1.bottom = r1.top + ih;

		if(	(e = TempGfx->Blt(&r1, tile, NULL, 0, NULL)) != DD_OK)
			return DDE("DrawLayers:Blt", e, "DrawTile:tile to TempGfx");

		j++;
		if((j%w) == 0)
		{
			j = 0;
			k++;
		}
	}

	r1.left = 0;	r1.top = 0;
	r1.right = out_w;	r1.bottom = out_h;
	if(	(e = out->Blt(&r1, TempGfx, NULL, 0, NULL)) != DD_OK)
		return DDE("DrawLayers:Blt", e, "DrawTile:TempGfx to out");

	return 0;
}

//
//
//
LAYER *DISPLAY::CreateCounter(long x, long y, unsigned __int8 NumDigits, char *StartText, unsigned __int8 type, unsigned __int8 fontNum, char *name)
{
	//
	LAYER_INFO *li = new LAYER_INFO;
	ZeroMemory(li, sizeof(LAYER_INFO));
	li->visable = true;
	li->hAlign = type;
	li->FontNum = fontNum;
	li->NumDigits = NumDigits;
	li->x = x;
	li->y = y;
	li->w = NumDigits*(Font[fontNum].cw);
	li->h = Font[fontNum].ch;
//	li->w = NumDigits;
//	li->h = 1;

	if(StartText == NULL)
	{
		char *S = new char[NumDigits + 1];
		memset(S, ' ', NumDigits*sizeof(char) );
		S[NumDigits] = 0;
		li->text = S;
	}
	else
		SetStr(&li->text, StartText, NumDigits);

	SetStr(&li->Name, name);

	return CreateTextBox(li);
}

//
bool DISPLAY::SetCounter(LAYER *counter, char *text)
{
	FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);
	if(	(e = counter->gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
		return DDE("DrawLayers:FloodFill", e, "SetCounter:counter");
	
	unsigned __int8 slen = strlen(text);
	unsigned __int8 c_x = 0;
	if( (counter->hAlign == AT_RIGHT) && (counter->NumDigits > slen))
		c_x = counter->ir.right - (slen*Font[counter->FontNum].cw);
	else if( (counter->hAlign == AT_CENTER) && (counter->NumDigits > slen) )
		c_x = (counter->ir.right - (slen*Font[counter->FontNum].cw)) >> 1;

	for(i = 0; (i < counter->NumDigits) && ( i < slen ); i++)
	{
		r1.left = c_x + i*Font[counter->FontNum].cw;
		r1.right = r1.left + Font[counter->FontNum].cw;

		r2.top = r1.top = 0;
		r2.bottom = r1.bottom = Font[counter->FontNum].ch;
		r2.left = (text[i] - 32)*(Font[counter->FontNum].cw);
		r2.right = r2.left + Font[counter->FontNum].cw;

		if(	(e = counter->gfx->Blt(&r1, Font[counter->FontNum].gfx, &r2,  DDBLT_KEYSRC, &FxBkg)) != DD_OK)
			return DDE("DrawLayers:Blt", e, "SetCounter:counter");
	}

	counter->redraw = true;

	return 0;
}

//
bool DISPLAY::SetCounter(LAYER *counter, unsigned __int32 num)
{
	char *text = new char[counter->NumDigits + 1];
	sprintf(text, "%d", num);

	SetCounter(counter, text );

	return 0;
}

void DISPLAY::DestroyLayer(LAYER *l)
{
	if(l->prev == NULL)
	{
		l->next->prev = NULL;
		StartLayer = l->next;
	}
	else if(l->next == NULL)
	{
		l->prev->next = NULL;
		EndLayer = l->prev;
	}
	else
	{
		l->prev->next = l->next;
		l->next->prev = l->prev;
	}

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
}

//
//
//
bool DISPLAY::DDE(char *n, HRESULT e1, char *name)
{
	SetError_Format("Class: %s || Function: %s\nError: %s(%d)\nLayer name: %s");

	if(DDERR_INCOMPATIBLEPRIMARY)
		Error(NULL, "DISPLAY", n, "Unable to match primary surface creation request with existing primary surface.", e, name);

	else if(DDERR_INVALIDCAPS)
		Error(NULL, "DISPLAY", n, "One or more of the caps bits passed to the callback are incorrect.", e, name);

	else if(DDERR_INVALIDOBJECT)
		Error(NULL, "DISPLAY", n, "DirectDraw received a pointer that was an invalid DIRECTDRAW object.", e, name);

	else if(DDERR_INVALIDPARAMS)
		Error(NULL, "DISPLAY", n, "One or more of the parameters passed to the callback function are incorrect.", e, name);

	else if(DDERR_INVALIDPIXELFORMAT)
		Error(NULL, "DISPLAY", n, "Pixel format was invalid as specified.", e, name);

	else if(DDERR_NOALPHAHW)
		Error(NULL, "DISPLAY", n, "Operation could not be carried out because there is no alpha accleration hardware present or available.", e, name);

	else if(DDERR_NOCOOPERATIVELEVELSET)
		Error(NULL, "DISPLAY", n, "Create function called without DirectDraw object method SetCooperativeLevel being called.", e, name);

	else if(DDERR_NODIRECTDRAWHW)
		Error(NULL, "DISPLAY", n, "A hardware only DirectDraw object creation was attempted but the driver did not support any hardware.", e, name);

	else if(DDERR_NOEMULATION)
		Error(NULL, "DISPLAY", n, "Software emulation not available.", e, name);

	else if(DDERR_NOEXCLUSIVEMODE)
		Error(NULL, "DISPLAY", n, "Operation requires the application to have exclusive mode but the application does not have exclusive mode.", e, name);

	else if(DDERR_NOFLIPHW)
		Error(NULL, "DISPLAY", n, "Flipping visible surfaces is not supported.", e, name);

	else if(DDERR_NOMIPMAPHW)
		Error(NULL, "DISPLAY", n, "Operation could not be carried out because there is no mip-map texture mapping hardware present or available.", e, name);

	else if(DDERR_NOZBUFFERHW)
		Error(NULL, "DISPLAY", n, "Operation could not be carried out because there is no hardware support for zbuffer blting.", e, name);

	else if(DDERR_OUTOFMEMORY)
		Error(NULL, "DISPLAY", n, "DirectDraw does not have enough memory to perform the operation.", e, name);

	else if(DDERR_OUTOFVIDEOMEMORY)
		Error(NULL, "DISPLAY", n, "DirectDraw does not have enough memory to perform the operation.", e, name);

	else if(DDERR_PRIMARYSURFACEALREADYEXISTS)
		Error(NULL, "DISPLAY", n, "This process already has created a primary surface", e, name);

	else if(DDERR_UNSUPPORTEDMODE)
		Error(NULL, "DISPLAY", n, "The display is currently in an unsupported mode.", e, name);

	else if(DDERR_EXCEPTION)
		Error(NULL, "DISPLAY", n, "An exception was encountered while performing the requested operation.", e, name);
		
	else if(DDERR_GENERIC)
		Error(NULL, "DISPLAY", n, "Generic failure.", e, name);
	
	else if(DDERR_INVALIDRECT)
		Error(NULL, "DISPLAY", n, "Rectangle provided was invalid.", e, name);
	
	else if(DDERR_NOBLTHW)
		Error(NULL, "DISPLAY", n, "No blter.", e, name);
	
	else if(DDERR_SURFACEBUSY)
		Error(NULL, "DISPLAY", n, "Access to this surface is being refused because the surface is already locked by another thread.", e, name);
	
	else if(DDERR_SURFACELOST)
		Error(NULL, "DISPLAY", n, "Access to this surface is being refused because the surface is gone.\n The DIRECTDRAWSURFACE object representing this surface should have Restore called on it.", e, name);
	
	else if(DDERR_UNSUPPORTED)
		Error(NULL, "DISPLAY", n, "Action not supported.", e, name);

	else if(DDERR_DIRECTDRAWALREADYCREATED)
		Error(NULL, "DISPLAY", n, "A DirectDraw object representing this driver has already been created for this process.", e, name);
	
	else if(DDERR_INVALIDDIRECTDRAWGUID)
		Error(NULL, "DISPLAY", n, "The GUID passed to DirectDrawCreate is not a valid DirectDraw driver identifier.", e, name);

	else
		Error(NULL, "DISPLAY", n, "???", e, name);

	ReSetError_Format();
	return (e1 != 0) ? 1 : 0;
}
