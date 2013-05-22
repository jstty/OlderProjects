////////////////////////////////////////////////////////////////////////
//	Program Name:	LoadGfx.cpp
//	Programmer:		Joseph E. Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Load Graphics File
//	Date:					04/03/2000
//	Version:			2.00
////////////////////////////////////////////////////////////////////////

#include <ddraw.h>
#include "..\Header Files\ddutil.h"

#include "..\Header Files\DisplayClass.h"
#include "..\Header Files\Gfx_to_DD.h"
#include "..\Header Files\DisplayClass.h"

//#include "..\Header Files\GameClass.h"

#include "..\Header Files\ValuesClass.h"
extern VALUES		*Val;

void SetArray(unsigned __int8 **d, unsigned __int8 *a, unsigned __int16 w)
{
	d[0] = new unsigned __int8[w];
	ZeroMemory(d[0], w*sizeof(unsigned char) );

	unsigned __int8 k;
	for(k = 0; k < w; k++)
		d[0][k] = a[k];
}

GFX_LAYER_INFO *DISPLAY::LoadGfx(char *FileName)
{
	GFX_LAYER_INFO *gli;
	gli = new GFX_LAYER_INFO;
	unsigned __int8 i = 0, j = 0;

	ANIM_INFO *ai;
	LAYER_INFO *li;

/*
	unsigned __int16 Size;

	hFile = CreateFile(FileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
		if(hFile == NULL)	return Error(NULL, "DISPLAY:LoadGfx", "CreateFile", GetLastError());

	// Load Header info
	Size = sizeof(GFX_LAYER_INFO) - sizeof(LAYER_INFO*);
	ReadFile(hFile, &gli, Size, &NumByteW, NULL);
	if(NumByteW != Size)
	{	CloseHandle(hFile);	return Error(NULL, "DISPLAY:LoadGfx", "ReadFile", GetLastError());	}

	//

	gli->l = new LAYER_INFO[gli->nLayer];
	memset(gli->l, 0, gli->nLayer*sizeof(LAYER_INFO) );
	Size = sizeof(LAYER_INFO) - sizeof(char*);

	for(i = 0; i < gli->nLayer; i++)
	{
		ReadFile(hFile, &(gli->l[i]), Size, &NumByteW, NULL);
		if(NumByteW != Size)
			{	CloseHandle(hFile);	return Error(NULL, "DISPLAY:LoadGfx", "ReadFile", GetLastError());	}


		if(gli->l[i].type == LT_SPRITE)
		{
			gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
			memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
			Size = sizeof(CEL_INFO) - sizeof(char*);

			for(j = 0; j < gli->l[i].nCel; j++)
			{
				ReadFile(hFile, &(gli->l[i].cel_info[j]), Size, &NumByteW, NULL);
				if(NumByteW != Size)
					{	CloseHandle(hFile);	return Error(NULL, "DISPLAY:LoadGfx", "ReadFile", GetLastError());	}
				
				gli->l[i].cel_info[j].fName = new char[gli->l[i].cel_info[j].fSize];
				ReadFile(hFile, gli->l[i].cel_info[j].fName, (gli->l[i].cel_info[j].fSize)*sizeof(char), &NumByteW, NULL);
				if(NumByteW != (gli->l[i].cel_info[j].fSize)*sizeof(char))
					{	CloseHandle(hFile);	return Error(NULL, "DISPLAY:LoadGfx", "ReadFile", GetLastError());	}
			}
		}
		else if((gli->l[i].type == LT_IMAGE) || (gli->l[i].type == LT_BKG))
		{		
			gli->l[i].fName = new char[gli->l[i].fSize];
			Size = gli->l[i].fSize*sizeof(char);
			ReadFile(hFile, gli->l[i].fName, Size, &NumByteW, NULL);
			if(NumByteW != Size)
				{	CloseHandle(hFile);	return Error(NULL, "DISPLAY:LoadGfx", "ReadFile", GetLastError());	}
		}
		else
			return Error(NULL, "DISPLAY:LoadGfx", "layer type error", 1)

	}
*/
	unsigned __int16 LevelNum = Val->Game->gData.LevelNum;

	gli->UseMouse = false;
	SetStr(&gli->Mouse_fName, "gfx\\cursor.bmp");

	gli->l = new LAYER_INFO[99];
	ZeroMemory(gli->l, 99*sizeof(LAYER_INFO) );
	i = 0;

	if(LevelNum == 0)
	{
		gli->l[i].visable = true;
		gli->l[i].type = LT_IMAGE;
		gli->l[i].x = 0;
		gli->l[i].y = 0;
		gli->l[i].w = 320;
		gli->l[i].h = 240;
		SetStr(&gli->l[i].fName, "gfx\\select_scrn.bmp");
		SetStr(&gli->l[i].Name, "Bkg");
		i++;

		gli->l[i].visable = true;
		gli->l[i].type = LT_TEXT;
		gli->l[i].hAlign = AT_CENTER;
		gli->l[i].x = 24;
		gli->l[i].y = 165;
		gli->l[i].w = 272;
		gli->l[i].h = 75;
		SetStr(&gli->l[i].text, "Please, make a selection using the game controller's up or down arrows then the \"X\" button.");
		SetStr(&gli->l[i].Name, "Text");
		i++;

/*
		li = &gli->l[i];
		SetStr(&li->Name, "guardian");
		li->visable = false;
		li->animate = true;
		li->type = LT_SPRITE;
		li->x = 100;
		li->y = 180;
		li->NumAnim = 2;

		li->anim_info = new ANIM_INFO[li->NumAnim];
		ZeroMemory(li->anim_info, 2*sizeof(ANIM_INFO) );

			ai = &li->anim_info[0];
			SetStr(&ai->name, "grow");

			ai->loop_type = LT_ONCE;

			ai->nCel = 9;
			ai->cel_info = new CEL_INFO[ai->nCel];
			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

			j = 0;
				ai->cel_info[j].hx = 4;	ai->cel_info[j].hy = 4;
				ai->cel_info[j].w = 8;	ai->cel_info[j].h = 4;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\grdian_grow1.bmp");
			j++;
				ai->cel_info[j].hx = 8;	ai->cel_info[j].hy = 9;
				ai->cel_info[j].w = 17;	ai->cel_info[j].h = 9;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\grdian_grow2.bmp");
			j++;
				ai->cel_info[j].hx = 13;	ai->cel_info[j].hy = 14;
				ai->cel_info[j].w = 26;	ai->cel_info[j].h = 14;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\grdian_grow3.bmp");
			j++;
				ai->cel_info[j].hx = 17;	ai->cel_info[j].hy = 19;
				ai->cel_info[j].w = 35;	ai->cel_info[j].h = 19;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\grdian_grow4.bmp");
			j++;
				ai->cel_info[j].hx = 22;	ai->cel_info[j].hy = 24;
				ai->cel_info[j].w = 44;	ai->cel_info[j].h = 24;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\grdian_grow5.bmp");
			j++;
				ai->cel_info[j].hx = 31;	ai->cel_info[j].hy = 33;
				ai->cel_info[j].w = 62;	ai->cel_info[j].h = 33;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\grdian_grow6.bmp");
			j++;
				ai->cel_info[j].hx = 35;	ai->cel_info[j].hy = 38;
				ai->cel_info[j].w = 71;	ai->cel_info[j].h = 38;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\grdian_grow7.bmp");
			j++;
				ai->cel_info[j].hx = 40;	ai->cel_info[j].hy = 43;
				ai->cel_info[j].w = 80;	ai->cel_info[j].h = 43;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\grdian_grow8.bmp");
			j++;
				ai->cel_info[j].hx = 45;	ai->cel_info[j].hy = 48;
				ai->cel_info[j].w = 89;	ai->cel_info[j].h = 48;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\grdian_grow9.bmp");

			ai = &li->anim_info[1];
			SetStr(&ai->name, "walk");
			ai->nCel = 3;
			ai->loop_type = LT_FOREVER;

			ai->cel_info = new CEL_INFO[ai->nCel];
			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));
			j = 0;
				ai->cel_info[j].hx = 49;	ai->cel_info[j].hy = 48;
				ai->cel_info[j].w = 93;	ai->cel_info[j].h = 48;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\guardian1.bmp");
			j++;
				ai->cel_info[j].hx = 49;	ai->cel_info[j].hy = 48;
				ai->cel_info[j].w = 93;	ai->cel_info[j].h = 48;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\guardian2.bmp");
			j++;
				ai->cel_info[j].hx = 49;	ai->cel_info[j].hy = 48;
				ai->cel_info[j].w = 93;	ai->cel_info[j].h = 48;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\guardian3.bmp");
		i++;
*/

	}
	else if(LevelNum == 1)
	{
		SetStr(&gli->l[i].Name, "Tile");
		gli->l[i].visable = true;
		gli->l[i].moveable = true;
		gli->l[i].move_type = LT_FOREVER;
		gli->l[i].type = LT_TILE;

		gli->l[i].x = 0;
		gli->l[i].y = 0;
		gli->l[i].w = 4;
		gli->l[i].h = 6;
		gli->l[i].tile_image_w = 128;
		gli->l[i].tile_image_h = 64;

		gli->l[i].tile_info = new TILE_INFO;
		SetStr(&gli->l[i].tile_info->fName, "gfx\\tile01.bmp");
		i++;

		SetStr(&gli->l[i].Name, "Win1");
		gli->l[i].visable = true;
		gli->l[i].type = LT_WINDOW;
		gli->l[i].x = 32;
		gli->l[i].y = 6;
		gli->l[i].w = 256;
		gli->l[i].h = 43;

		gli->l[i].win_image_w = 5;
		gli->l[i].win_image_h = 5;
		gli->l[i].wType = WT_TAB | WT_BGCOLOR;

		gli->l[i].win = new WIN_INFO;
		ZeroMemory(gli->l[i].win, sizeof(WIN_INFO));
		gli->l[i].win->bgcolor = RGB(159, 159, 159);
		// 9 images if no tab
		gli->l[i].win->img = new char*[9];
		ZeroMemory(gli->l[i].win->img, 9*sizeof(char*));
		SetStr(&gli->l[i].win->img[W_TOP_LEFT],			" ");
		SetStr(&gli->l[i].win->img[W_TOP],					"gfx\\mywin_tm.bmp");
		SetStr(&gli->l[i].win->img[W_TOP_RIGHT],		"gfx\\mywin_tr.bmp");
		SetStr(&gli->l[i].win->img[W_LEFT],					"gfx\\mywin_ml.bmp");
		SetStr(&gli->l[i].win->img[W_MIDDLE],				" ");
		SetStr(&gli->l[i].win->img[W_RIGHT],				"gfx\\mywin_mr.bmp");
		SetStr(&gli->l[i].win->img[W_BOTTOM_LEFT],	"gfx\\mywin_bl.bmp");
		SetStr(&gli->l[i].win->img[W_BOTTOM],				"gfx\\mywin_bm.bmp");
		SetStr(&gli->l[i].win->img[W_BOTTOM_RIGHT], "gfx\\mywin_br.bmp");

		gli->l[i].win->tab = new TAB_INFO;
		ZeroMemory(gli->l[i].win->tab, sizeof(TAB_INFO));
			gli->l[i].win->tab->w = 144;
			gli->l[i].win->tab->h = 23;
			gli->l[i].win->tab->wImg = 17;
			gli->l[i].win->tab->img = new char*[3];
			memset(gli->l[i].win->tab->img, 0,  3*sizeof(char*));
			SetStr(&gli->l[i].win->tab->img[0], "gfx\\mytab_l.bmp");
			SetStr(&gli->l[i].win->tab->img[1], "gfx\\mytab_m.bmp");
			SetStr(&gli->l[i].win->tab->img[2], "gfx\\mytab_r.bmp");
		i++;

		/*
		// window 2
		gli->l[i].x = 32;
		gli->l[i].y = 76;
		*/
		/*
		// window 3
		gli->l[i].x = 32;
		gli->l[i].y = 146;
		*/
		/*
		// Title 1
		gli->l[i].x = 51;
		gli->l[i].y = 11;
		gli->l[i].w = 122;
		gli->l[i].h = 13;
		*/

		SetStr(&gli->l[i].Name, "save_Title1");
		gli->l[i].visable = false;
		gli->l[i].type = LT_TEXT;
		gli->l[i].hAlign = AT_LEFT;
		gli->l[i].x = 56;
		gli->l[i].y = 10;
		gli->l[i].w = 122;
		gli->l[i].h = 16;
		SetStr(&gli->l[i].text, "Save Game  ");
		i++;

		SetStr(&gli->l[i].Name, "load_Title1");
		gli->l[i].visable = false;
		gli->l[i].type = LT_TEXT;
		gli->l[i].hAlign = AT_LEFT;
		gli->l[i].x = 56;
		gli->l[i].y = 10;
		gli->l[i].w = 122;
		gli->l[i].h = 16;
		SetStr(&gli->l[i].text, "Load Game  ");
		i++;

		SetStr(&gli->l[i].Name, "Text1");
		gli->l[i].visable = false;
		gli->l[i].type = LT_TEXT;
		gli->l[i].hAlign = AT_LEFT;
		gli->l[i].x = 45;
		gli->l[i].y = 32;
		gli->l[i].w = 240;
		gli->l[i].h = 32;
		SetStr(&gli->l[i].text, "SN Lvl:     hrs min sec RN Lvl:        :   :   ");
		i++;

		SetStr(&gli->l[i].Name, "File1");
		gli->l[i].visable = false;
		gli->l[i].type = LT_TEXT;
		gli->l[i].hAlign = AT_CENTER;
		gli->l[i].x = 37;
		gli->l[i].y = 40;
		gli->l[i].w = 246;
		gli->l[i].h = 16;
		SetStr(&gli->l[i].text, "No File");
		i++;

		SetStr(&gli->l[i].Name, "Back");
		gli->l[i].visable = true;
		gli->l[i].type = LT_IMAGE;
		gli->l[i].x = 32;
		gli->l[i].y = 216;
		gli->l[i].w = 63;
		gli->l[i].h = 19;
		SetStr(&gli->l[i].fName, "gfx\\back.bmp");
		i++;

	}
	else if(LevelNum == 3)
	{
	//
	//
	//
		gli->l[i].visable = true;
		gli->l[i].moveable = true;
		gli->l[i].move_type = LT_FOREVER;
		gli->l[i].type = LT_TILE;

		gli->l[i].x = 0;
		gli->l[i].y = 0;
		gli->l[i].w = 16;
		gli->l[i].h = 13;
		gli->l[i].tile_image_w = 20;
		gli->l[i].tile_image_h = 20;

		gli->l[i].tile_info = new TILE_INFO;
		SetStr(&gli->l[i].tile_info->fName, "gfx\\map_tile1.bmp");
		SetStr(&gli->l[i].Name, "Tile1");
		i++;
	//
	//
	//
		gli->l[i].visable = true;
		gli->l[i].type = LT_TILE;

		gli->l[i].x = 90;
		gli->l[i].y = 10;
		gli->l[i].w = 11;
		gli->l[i].h = 11;
		gli->l[i].tile_image_w = 20;
		gli->l[i].tile_image_h = 20;

		gli->l[i].tile_info = new TILE_INFO;
		SetStr(&gli->l[i].tile_info->fName, "gfx\\map_tile2.bmp");
		SetStr(&gli->l[i].Name, "Tile2");
		i++;
	//
	//
	//
		SetStr(&gli->l[i].Name, "Map");
		gli->l[i].visable = true;
		gli->l[i].map_info = new MAP_INFO;
		gli->l[i].map_info->data = new unsigned __int8 *[ gli->l[i].map_image_w ];
		gli->l[i].map_info->fName = new char *[ gli->l[i].map_num_images ];
		gli->l[i].type = LT_MAP;

		gli->l[i].moveable = false;
		gli->l[i].clip = true;
		gli->l[i].cx = 100;
		gli->l[i].cy = 20;
		gli->l[i].cw = 200;
		gli->l[i].ch = 200;

		gli->l[i].x = -100;
		gli->l[i].y = 20;
		gli->l[i].map_image_w = 20;
		gli->l[i].map_image_h = 20;
		gli->l[i].map_num_images = 10;
		SetStr(&gli->l[i].map_info->fName[0], "gfx\\water_tile.bmp");
		SetStr(&gli->l[i].map_info->fName[1], "gfx\\village_tile.bmp");
		SetStr(&gli->l[i].map_info->fName[2], "gfx\\desert_tile.bmp");
		SetStr(&gli->l[i].map_info->fName[3], "gfx\\grasslands_tile.bmp");
		SetStr(&gli->l[i].map_info->fName[4], "gfx\\forest_tile.bmp");
		SetStr(&gli->l[i].map_info->fName[5], "gfx\\camp_tile1.bmp");
		SetStr(&gli->l[i].map_info->fName[6], "gfx\\safe_tile.bmp");
		SetStr(&gli->l[i].map_info->fName[7], "gfx\\bridge_tile.bmp");
		SetStr(&gli->l[i].map_info->fName[8], "gfx\\mountain.bmp");
		SetStr(&gli->l[i].map_info->fName[9], "gfx\\cavern.bmp");
/*
			{0,0,0,0,0, 0,1,0,0,0}, 
			{0,6,2,3,7, 3,3,0,0,0},
			{0,2,2,2,0, 0,0,3,0,0},
			{0,3,2,2,2, 3,3,3,3,0},
			{0,3,2,2,2, 2,3,3,3,0},

			{0,3,0,2,0, 0,2,2,3,0},
			{0,3,3,0,3, 3,0,2,3,0},
			{0,0,0,0,4, 3,3,0,3,0},
			{5,4,4,4,4, 3,3,3,3,0},
			{0,0,0,0,0, 0,0,0,0,0}
*/
		gli->l[i].w = 20;
		gli->l[i].h = 10;
		unsigned __int8 a[10][20] =
		{
			{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,1,0,0,0}, 
			{0,8,9,8,8, 2,4,0,0,0, 0,6,2,3,7, 3,3,0,0,0},
			{0,8,2,2,2, 2,3,4,0,0, 0,2,2,2,0, 0,0,3,0,0},
			{0,8,8,8,2, 2,2,2,0,0, 0,3,2,2,2, 3,3,3,3,0},
			{0,2,2,2,2, 2,2,8,0,0, 0,3,2,2,2, 2,3,3,3,0},

			{0,2,8,8,8, 8,8,8,8,0, 0,3,0,2,0, 0,2,2,3,0},
			{0,3,8,8,4, 1,4,4,4,0, 0,3,3,0,3, 3,0,2,3,0},
			{0,3,3,4,4, 4,4,4,3,0, 0,0,0,0,4, 3,3,0,3,0},
			{0,0,3,4,4, 4,4,3,3,7, 5,4,4,4,4, 3,3,3,3,0},
			{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0}
		};

		for(j = 0; j < gli->l[i].h; j++)
			SetArray(&gli->l[i].map_info->data[j], &a[j][0], gli->l[i].w);
		i++;
	//
	//
		li = &gli->l[i];
		SetStr(&li->Name, "Camp");
		li->type = LT_SPRITE;
		li->visable = true;
		li->animate = true;
		li->x = 100;
		li->y = 180;
		li->NumAnim = 1;

		li->anim_info = new ANIM_INFO[li->NumAnim];
		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

			ai = &li->anim_info[0];
			SetStr(&ai->name, "fire");
	
			ai->loop_type = LT_FOREVER;

			ai->nCel = 3;
			ai->cel_info = new CEL_INFO[ai->nCel];
			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

			j = 0;
				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\camp_tile1.bmp");
			j++;
				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\camp_tile2.bmp");
			j++;
				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\camp_tile3.bmp");
		i++;
//
		li = &gli->l[i];
		SetStr(&li->Name, "RedGoo");
		li->type = LT_SPRITE;
		li->visable = false;
		li->animate = false;
		li->moveable = false;
		li->collidable = true;
		li->move_type = LT_ONCE;
		li->x = 140;
		li->y = 40;
		li->hx = -100;
		li->hy = -20;
		li->NumAnim = 1;

		li->anim_info = new ANIM_INFO[li->NumAnim];
		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

			ai = &li->anim_info[0];
			SetStr(&ai->name, "walk");
	
			ai->loop_type = LT_FOREVER;

			ai->nCel = 2;
			ai->cel_info = new CEL_INFO[ai->nCel];
			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

			j = 0;
				ai->cel_info[j].hx = -100;	ai->cel_info[j].hy = -20;
				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\red_goo1.bmp");
			j++;
				ai->cel_info[j].hx = -100;	ai->cel_info[j].hy = -20;
				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\red_goo2.bmp");
		i++;

		li = &gli->l[i];
		SetStr(&li->Name, "BlueGoo");
		li->type = LT_SPRITE;
		li->visable = false;
		li->animate = false;
		li->moveable = false;
		li->collidable = true;
		li->move_type = LT_ONCE;
		li->x = 40;
		li->y = 80;
		li->hx = -100;
		li->hy = -20;
		li->NumAnim = 1;

		li->anim_info = new ANIM_INFO[li->NumAnim];
		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

			ai = &li->anim_info[0];
			SetStr(&ai->name, "walk");
	
			ai->loop_type = LT_FOREVER;

			ai->nCel = 2;
			ai->cel_info = new CEL_INFO[ai->nCel];
			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

			j = 0;
				ai->cel_info[j].hx = -100;	ai->cel_info[j].hy = -20;
				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\blue_goo1.bmp");
			j++;
				ai->cel_info[j].hx = -100;	ai->cel_info[j].hy = -20;
				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\blue_goo2.bmp");
		i++;

		li = &gli->l[i];
		SetStr(&li->Name, "Super");
		li->type = LT_SPRITE;
		li->visable = false;
		li->animate = false;
		li->moveable = false;
		li->collidable = true;
		li->move_type = LT_ONCE;
		li->x = 20;
		li->y = 20;
		li->hx = -100;
		li->hy = -20;
		li->NumAnim = 1;

		li->anim_info = new ANIM_INFO[li->NumAnim];
		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

			ai = &li->anim_info[0];
			SetStr(&ai->name, "walk");
	
			ai->loop_type = LT_FOREVER;

			ai->nCel = 2;
			ai->cel_info = new CEL_INFO[ai->nCel];
			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

			j = 0;
				ai->cel_info[j].hx = -100;	ai->cel_info[j].hy = -20;
				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\sn_map1.bmp");
			j++;
				ai->cel_info[j].hx = -100;	ai->cel_info[j].hy = -20;
				ai->cel_info[j].w = 20;	ai->cel_info[j].h = 20;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\sn_map2.bmp");
		i++;

	//
	//
		SetStr(&gli->l[i].Name, "menu");
		gli->l[i].visable = true;
		gli->l[i].type = LT_IMAGE;
		gli->l[i].x = 19;
		gli->l[i].y = 100;
		gli->l[i].w = 60;
		gli->l[i].h = 83;
		SetStr(&gli->l[i].fName, "gfx\\map_menu.bmp");
		i++;

	//
	//
	//
		SetStr(&gli->l[i].Name, "sStat");
		gli->l[i].visable = false;
		gli->l[i].type = LT_IMAGE;
		gli->l[i].x = 0;
		gli->l[i].y = 0;
		gli->l[i].w = 320;
		gli->l[i].h = 240;
		SetStr(&gli->l[i].fName, "gfx\\sninja_stat_menu.bmp");
		i++;
	//
	//
	//
		SetStr(&gli->l[i].Name, "rStat");
		gli->l[i].visable = false;
		gli->l[i].type = LT_IMAGE;
		gli->l[i].x = 0;
		gli->l[i].y = 0;
		gli->l[i].w = 320;
		gli->l[i].h = 240;
		SetStr(&gli->l[i].fName, "gfx\\red_stat_menu.bmp");
		i++;
	//
	//
	//
		SetStr(&gli->l[i].Name, "sPic");
		gli->l[i].visable = false;
		gli->l[i].type = LT_IMAGE;
		gli->l[i].x = 1;
		gli->l[i].y = 26;
		gli->l[i].w = 78;
		gli->l[i].h = 66;
		SetStr(&gli->l[i].fName, "gfx\\sninja_pic.bmp");
		i++;
	//
	//
	//
		SetStr(&gli->l[i].Name, "rPic");
		gli->l[i].visable = false;
		gli->l[i].type = LT_IMAGE;
		gli->l[i].x = 1;
		gli->l[i].y = 26;
		gli->l[i].w = 78;
		gli->l[i].h = 66;
		SetStr(&gli->l[i].fName, "gfx\\red_pic.bmp");
		i++;

		//
		gli->l[i].visable = false;
		gli->l[i].type = LT_TILE;
		gli->l[i].x = 0;
		gli->l[i].y = 26;
		gli->l[i].w = 10;
		gli->l[i].h = 20;
		gli->l[i].tile_image_w = 8;
		gli->l[i].tile_image_h = 8;

		gli->l[i].tile_info = new TILE_INFO;
		SetStr(&gli->l[i].tile_info->fName, "gfx\\dark.bmp");
		SetStr(&gli->l[i].Name, "gray");
		i++;
	}
	else if(LevelNum == 4)
	{
		gli->l[i].visable = true;
		gli->l[i].type = LT_IMAGE;
		gli->l[i].x = 0;
		gli->l[i].y = 0;
		gli->l[i].w = 320;
		gli->l[i].h = 135;
		SetStr(&gli->l[i].fName, "gfx\\fight\\land01a.bmp");
		SetStr(&gli->l[i].Name, "LandA");
		i++;

		gli->l[i].visable = true;
		gli->l[i].type = LT_IMAGE;
		gli->l[i].x = 0;
		gli->l[i].y = 135;
		gli->l[i].w = 320;
		gli->l[i].h = 105;
		SetStr(&gli->l[i].fName, "gfx\\fight\\land01b.bmp");
		SetStr(&gli->l[i].Name, "LandB");
		i++;

		//
		//
		gli->l[i].visable = true;
		gli->l[i].type = LT_IMAGE;
		gli->l[i].x = 0;
		gli->l[i].y = 142;
		gli->l[i].w = 147;
		gli->l[i].h = 99;
		SetStr(&gli->l[i].fName, "gfx\\fight\\tab.bmp");
		SetStr(&gli->l[i].Name, "Tab");
		i++;

		//
		//
		//
		li = &gli->l[i];
		SetStr(&li->Name, "Lupi");
		li->type = LT_SPRITE;
		li->visable = true;
		li->animate = true;
		li->x = 146;
		li->y = 80;
		li->NumAnim = 1;

		li->anim_info = new ANIM_INFO[li->NumAnim];
		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

			ai = &li->anim_info[0];
			SetStr(&ai->name, "walk");
	
			ai->loop_type = LT_FOREVER;

			ai->nCel = 4;
			ai->cel_info = new CEL_INFO[ai->nCel];
			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

			j = 0;
				ai->cel_info[j].w = 28;	ai->cel_info[j].h = 36;
				ai->cel_info[j].delay = 250;
				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\lupi1.bmp");
			j++;
				ai->cel_info[j].w = 28;	ai->cel_info[j].h = 37;
				ai->cel_info[j].delay = 250;
				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\lupi2.bmp");
			j++;
				ai->cel_info[j].w = 28;	ai->cel_info[j].h = 36;
				ai->cel_info[j].delay = 250;
				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\lupi3.bmp");
			j++;
				ai->cel_info[j].w = 28;	ai->cel_info[j].h = 37;
				ai->cel_info[j].delay = 250;
				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\lupi2.bmp");
		i++;

		//
		//
		//
		li = &gli->l[i];
		SetStr(&li->Name, "Super");
		li->type = LT_SPRITE;
		li->visable = true;
		li->animate = true;
		li->x = 20;
		li->y = 93;
		li->NumAnim = 1;

		li->anim_info = new ANIM_INFO[li->NumAnim];
		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

			ai = &li->anim_info[0];
			SetStr(&ai->name, "Stand");
	
			ai->loop_type = LT_FOREVER;

			ai->nCel = 2;
			ai->cel_info = new CEL_INFO[ai->nCel];
			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

			j = 0;
				ai->cel_info[j].w = 31;	ai->cel_info[j].h = 35;
				ai->cel_info[j].delay = 2000;
				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\sn_st2.bmp");
			j++;
				ai->cel_info[j].w = 31;	ai->cel_info[j].h = 35;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\sn_st1.bmp");
		i++;
		//
		//
		//
		li = &gli->l[i];
		SetStr(&li->Name, "Red");
		li->type = LT_SPRITE;
		li->visable = true;
		li->animate = true;
		li->x = 266;
		li->y = 82;
		li->NumAnim = 1;

		li->anim_info = new ANIM_INFO[li->NumAnim];
		ZeroMemory(li->anim_info, li->NumAnim*sizeof(ANIM_INFO) );

			ai = &li->anim_info[0];
			SetStr(&ai->name, "Stand");
	
			ai->loop_type = LT_FOREVER;

			ai->nCel = 2;
			ai->cel_info = new CEL_INFO[ai->nCel];
			ZeroMemory(ai->cel_info, ai->nCel*sizeof(CEL_INFO));

			j = 0;
				ai->cel_info[j].w = 31;	ai->cel_info[j].h = 35;
				ai->cel_info[j].delay = 2500;
				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\rn_st2.bmp");
			j++;
				ai->cel_info[j].w = 31;	ai->cel_info[j].h = 35;
				ai->cel_info[j].delay = 100;
				SetStr(&ai->cel_info[j].fName, "gfx\\fight\\rn_st1.bmp");
		i++;
	}

	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].x = 0;
	gli->l[i].y = 0;
	gli->l[i].w = 28;
	gli->l[i].h = 17;
	gli->l[i].hx = 25;
	gli->l[i].hy = 5;
	SetStr(&gli->l[i].fName, "gfx\\hand.bmp");
	SetStr(&gli->l[i].Name, "Hand");
	i++;

	gli->nLayer = i;

	return gli;
}

bool DISPLAY::TransferGfx(GFX_LAYER_INFO *gfx_li)
{
///////////////////////////////////////////////////////
// load layer info
///////////////////////////////////////////////////////

	// create layers and clear junk
/*
	nLayers = gfx_li->nLayer;
	Layer = new LAYER[gfx_li->nLayer];
	memset(Layer, 0, gfx_li->nLayer*sizeof(LAYER) );
*/

	Mouse = new MOUSE;
	ZeroMemory(Mouse, sizeof(MOUSE) );
	
///////////////////////////////////////////////////////
// load our bitmap
///////////////////////////////////////////////////////
	// load our bitmap
FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);

	EndLayer = NULL;
	for(i = 0; i < gfx_li->nLayer; i++)
	{
		/*
		if(i < (gfx_li->nLayer - 1) )
			Layer[i].next = &Layer[i + 1];
		else
			Layer[i].next = NULL;

		Layer[i].type = gfx_li->l[i].type;

		if(Layer[i].type == LT_SPRITE)	
			CreateSprite(&Layer[i], &gfx_li->l[i]);
		else if(Layer[i].type == LT_IMAGE)
			CreateImage(&Layer[i], &gfx_li->l[i]);
		else if(Layer[i].type == LT_MAP)
			CreateMap(&Layer[i], &gfx_li->l[i]);
		else if(Layer[i].type == LT_TILE)
			CreateTile(&Layer[i], &gfx_li->l[i]);
		else if(Layer[i].type == LT_TEXT)
		{
			l = CreateTextBox(&gfx_li->l[i]);
			if(i > 0)
				Layer[i-1].next = l;
			else
				StartLayer = l;

			l->next = &Layer[i+1];
		}
		else if(Layer[i].type == LT_WINDOW)
			CreateWin(&Layer[i], &gfx_li->l[i]);
		*/

		if(gfx_li->l[i].type == LT_SPRITE)	
			l = CreateSprite(&gfx_li->l[i]);

		else if(gfx_li->l[i].type == LT_IMAGE)
			l = CreateImage(&gfx_li->l[i]);

		else if(gfx_li->l[i].type == LT_MAP)
			l = CreateMap(&gfx_li->l[i]);

		else if(gfx_li->l[i].type == LT_TILE)
			l = CreateTile(&gfx_li->l[i]);

		else if(gfx_li->l[i].type == LT_TEXT)
			l = CreateTextBox(&gfx_li->l[i]);

		else if(gfx_li->l[i].type == LT_WINDOW)
			l = CreateWin(&gfx_li->l[i]);


		// Copy all to master layer



		if(i == 0)
			StartLayer = l;

		EndLayer = l;
	}

FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);

///////////////////////////////////////////////////////
// Mouse
///////////////////////////////////////////////////////
	UseMouse = gfx_li->UseMouse;

	if(UseMouse)
	{
		if( (Mouse->gfx = DDLoadBitmap(DD_Object, gfx_li->Mouse_fName, 0, 0)) == NULL )
			return DDE("LoadDrawS:DDLoadBitmap", i, "Load Mouse");
		if( (e = DDSetColorKey(Mouse->gfx,  TRANS_COLOR1 ) ) != DD_OK)
			return DDE("LoadDrawS:DDSetColorKey", e, "Set ColorKey Mouse");

		Mouse->SetSize(11, 19);
		Mouse->SetPos(0, 0);
		Mouse->draw = false;

		Mouse->old_r = Mouse->r;
		Mouse->old_ir = Mouse->ir;
	}

	GlobalReDraw = true;

	return 0;
}
