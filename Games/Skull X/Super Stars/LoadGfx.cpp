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


void SetStr(char **a, const char *b) 
{
	*a = new char[ strlen(b) ];
	strcpy(*a, b);
}

void SetArray(unsigned char **d, unsigned char *a, unsigned __int16 w)
{
	d[0] = new unsigned char[w];
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
	unsigned __int8 LevelNum = Val->Main->LevelNum;

	gli->UseMouse = true;
	SetStr(&gli->Mouse_fName, "gfx\\cursor.bmp");

	gli->l = new LAYER_INFO[99];
	memset(gli->l, 0, 99*sizeof(LAYER_INFO) );
	i = 0;


// logo
	gli->l[i].visable = true;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 320;
	gli->l[i].h = 240;
	gli->l[i].nCel = 3;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\fbi.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 2000;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\copyright.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 2000;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\bkg_color.bmp");
	i++;

// Star 1
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 55;
	gli->l[i].h = 65;
	gli->l[i].nCel = 9;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star1_1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star1_2.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star1_3.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star1_4.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star1_5.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star1_6.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star1_7.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star1_8.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star1_9.bmp");
	i++;

// Star 2
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 55;
	gli->l[i].h = 65;
	gli->l[i].nCel = 9;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star2_1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star2_2.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star2_3.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star2_4.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star2_5.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star2_6.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star2_7.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star2_8.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 50;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\star2_9.bmp");
	i++;

// Title
	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].w = 240;
	gli->l[i].h = 102;
	gli->l[i].x = 40;
	gli->l[i].y = 10;
	SetStr(&gli->l[i].fName, "gfx\\sstitle.bmp");
	i++;

// Select Background
	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].w = 320;
	gli->l[i].h = 240;
	SetStr(&gli->l[i].fName, "gfx\\select_bkg.bmp");
	i++;

// Bossman
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 64;
	gli->l[i].h = 64;
	gli->l[i].x = 7;
	gli->l[i].y = 23;
	gli->l[i].looptype = LT_NUMBER;
	gli->l[i].loopcount = 5;
	gli->l[i].nCel = 3;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\bossman1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\bossman2.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\bossman3.bmp");
	i++;

	// Hogan
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 64;
	gli->l[i].h = 64;
	gli->l[i].x = 87;
	gli->l[i].y = 7;
	gli->l[i].looptype = LT_NUMBER;
	gli->l[i].loopcount = 5;
	gli->l[i].nCel = 3;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\hogan1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\hogan2.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\hogan3.bmp");
	i++;

	// Andre
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 64;
	gli->l[i].h = 64;
	gli->l[i].x = 167;
	gli->l[i].y = 7;
	gli->l[i].looptype = LT_NUMBER;
	gli->l[i].loopcount = 5;
	gli->l[i].nCel = 3;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\andre1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\andre2.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\andre3.bmp");
	i++;

// Warrior
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 64;
	gli->l[i].h = 64;
	gli->l[i].x = 247;
	gli->l[i].y = 23;
	gli->l[i].looptype = LT_NUMBER;
	gli->l[i].loopcount = 5;
	gli->l[i].nCel = 3;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\warrior1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\warrior2.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\warrior3.bmp");
	i++;

// Honky
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 64;
	gli->l[i].h = 64;
	gli->l[i].x = 7;
	gli->l[i].y = 127;
	gli->l[i].looptype = LT_NUMBER;
	gli->l[i].loopcount = 5;
	gli->l[i].nCel = 3;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\honky1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\honky2.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\honky3.bmp");
	i++;

// Savage
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 64;
	gli->l[i].h = 64;
	gli->l[i].x = 87;
	gli->l[i].y = 144;
	gli->l[i].looptype = LT_NUMBER;
	gli->l[i].loopcount = 5;
	gli->l[i].nCel = 3;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\savage1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\savage2.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\savage3.bmp");
	i++;

// Ted
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 64;
	gli->l[i].h = 64;
	gli->l[i].x = 167;
	gli->l[i].y = 144;
	gli->l[i].looptype = LT_NUMBER;
	gli->l[i].loopcount = 5;
	gli->l[i].nCel = 3;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\ted1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\ted2.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\ted3.bmp");
	i++;

// Jim Duggan
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 64;
	gli->l[i].h = 64;
	gli->l[i].x = 247;
	gli->l[i].y = 127;
	gli->l[i].looptype = LT_NUMBER;
	gli->l[i].loopcount = 5;
	gli->l[i].nCel = 3;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\jim1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\jim2.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 100;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\jim3.bmp");
	i++;

// Select Background
	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].w = 64;
	gli->l[i].h = 70;
	gli->l[i].x = 7;
	gli->l[i].y = 17;
	SetStr(&gli->l[i].fName, "gfx\\play_selector_1.bmp");
	i++;

// Select Background
	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].w = 64;
	gli->l[i].h = 70;
	gli->l[i].x = 87;
	gli->l[i].y = 7;
	SetStr(&gli->l[i].fName, "gfx\\play_selector_2.bmp");
	i++;

// Next Level
	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].w = 320;
	gli->l[i].h = 240;
	gli->l[i].x = 0;
	gli->l[i].y = 0;
	SetStr(&gli->l[i].fName, "gfx\\next.bmp");
	i++;

// Far Crowd
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 240;
	gli->l[i].h = 96;
	gli->l[i].x = 80;
	gli->l[i].y = 0;
	gli->l[i].looptype = LT_FOREVER;
	gli->l[i].loopcount = gli->l[i].nCel = 4;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\farcrowd_1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\farcrowd_2.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\farcrowd_3.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\farcrowd_4.bmp");
	i++;

// mobilecart base
	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].w = 90;
	gli->l[i].h = 112;
	gli->l[i].x = 27;
	gli->l[i].y = 39;
	SetStr(&gli->l[i].fName, "gfx\\mobilecart_base.bmp");
	i++;

//
// Entrance Honkey
//
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 58;
	gli->l[i].h = 77;
	gli->l[i].x = 52;
	gli->l[i].y = 20;
	gli->l[i].looptype = LT_FOREVER;
	gli->l[i].loopcount = gli->l[i].nCel = 2;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\honky_entrance_1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\honky_entrance_2.bmp");
	i++;

//
// Entrance Savage
//
	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].w = 35;
	gli->l[i].h = 79;
	gli->l[i].x = 41;
	gli->l[i].y = 30;
	SetStr(&gli->l[i].fName, "gfx\\savage_entrance_1.bmp");
	i++;

// mobilecart mask
	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].w = 90;
	gli->l[i].h = 112;
	gli->l[i].x = 27;
	gli->l[i].y = 39;
	SetStr(&gli->l[i].fName, "gfx\\mobilecart_mask.bmp");
	i++;

// Far Crowd
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 320;
	gli->l[i].h = 106;
	gli->l[i].x = 0;
	gli->l[i].y = 134;
	gli->l[i].looptype = LT_FOREVER;
	gli->l[i].loopcount = gli->l[i].nCel = 4;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\nearcrowd_1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\nearcrowd_2.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\nearcrowd_3.bmp");
			j++;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\nearcrowd_4.bmp");
	i++;
	
// Ring
	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].w = 714;
	gli->l[i].h = 501;
	gli->l[i].x = -100;
	gli->l[i].y = -100;
	SetStr(&gli->l[i].fName, "gfx\\ring2.bmp");
	i++;

//
// Entrance Honkey
//
	gli->l[i].visable = false;
	gli->l[i].animate = true;
	gli->l[i].type = LT_SPRITE;
	gli->l[i].w = 58;
	gli->l[i].h = 77;
	gli->l[i].x = 213;
	gli->l[i].y = 200;
	gli->l[i].hx = -213;
	gli->l[i].hy = -200;
	gli->l[i].looptype = LT_FOREVER;
	gli->l[i].loopcount = gli->l[i].nCel = 2;

	gli->l[i].cel_info = new CEL_INFO[gli->l[i].nCel];
	memset(gli->l[i].cel_info, 0,  gli->l[i].nCel*sizeof(CEL_INFO));
		j = 0;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\honky_entrance_1.bmp");
		j++;
			gli->l[i].cel_info[j].delay = 0;
			SetStr(&gli->l[i].cel_info[j].fName, "gfx\\honky_entrance_2.bmp");
	i++;


// Bottom Rope 1
	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].w = 290;
	gli->l[i].h = 5;
	gli->l[i].x = 212;
	gli->l[i].y = 285;
	gli->l[i].hx = -212;
	gli->l[i].hy = -285;

	SetStr(&gli->l[i].fName, "gfx\\brope1.bmp");
	i++;

// Bottom Rope 2
	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].w = 290;
	gli->l[i].h = 5;
	gli->l[i].x = 212;
	gli->l[i].y = 301;
	gli->l[i].hx = -212;
	gli->l[i].hy = -301;
	SetStr(&gli->l[i].fName, "gfx\\brope2.bmp");
	i++;

// Bottom Rope 3
	gli->l[i].visable = false;
	gli->l[i].type = LT_IMAGE;
	gli->l[i].w = 290;
	gli->l[i].h = 5;
	gli->l[i].x = 212;
	gli->l[i].y = 317;
	gli->l[i].hx = -212;
	gli->l[i].hy = -317;
	SetStr(&gli->l[i].fName, "gfx\\brope3.bmp");
	i++;

	return gli;
}

bool DISPLAY::TransferGfx(GFX_LAYER_INFO *gfx_li)
{
	unsigned __int8 i, j;
///////////////////////////////////////////////////////
// load layer info
///////////////////////////////////////////////////////

	// create layers and clear junk
	nLayers = gfx_li->nLayer;
	Layer = new LAYER[gfx_li->nLayer];
	memset(Layer, 0, gfx_li->nLayer*sizeof(LAYER) );
	Mouse = new MOUSE;
	memset(Mouse, 0, sizeof(MOUSE) );
	StartLayer = &Layer[0];
	
///////////////////////////////////////////////////////
// load our bitmap
///////////////////////////////////////////////////////
FxBkg.dwSize			= sizeof(DDBLTFX);
FxBkg.dwFillColor = DDColorMatch(DDS_Bkg, TRANS_COLOR1);

	for(i = 0; i < gfx_li->nLayer; i++)
	{
		if(i < (gfx_li->nLayer - 1) )
			Layer[i].next = &Layer[i + 1];
		else
			Layer[i].next = NULL;

		Layer[i].visable = gfx_li->l[i].visable;
		Layer[i].moveable = gfx_li->l[i].moveable;

		Layer[i].move_type = gfx_li->l[i].move_type;
		Layer[i].o_move_count = Layer[i].move_count = gfx_li->l[i].move_count;

		Layer[i].type = gfx_li->l[i].type;

		Layer[i].extra0 = gfx_li->l[i].extra0;
		Layer[i].extra1 = gfx_li->l[i].extra1;
		Layer[i].extra2 = gfx_li->l[i].extra2;
		Layer[i].extra3 = gfx_li->l[i].extra3;

		Layer[i].redraw = true;

		if(Layer[i].type == LT_SPRITE)
		{
			Layer[i].startcel = Layer[i].cel = new CEL[ gfx_li->l[i].nCel ];
			memset(Layer[i].cel, 0, gfx_li->l[i].nCel*sizeof(CEL) );

			for(j = 0; j < gfx_li->l[i].nCel; j++)
			{
				Layer[i].cel[j].delay = gfx_li->l[i].cel_info[j].delay;
				
				Layer[i].cel[j].hx = gfx_li->l[i].cel_info[j].hx;
				Layer[i].cel[j].hy = gfx_li->l[i].cel_info[j].hy;

				Layer[i].cel[j].bx = gfx_li->l[i].cel_info[j].bx;
				Layer[i].cel[j].by = gfx_li->l[i].cel_info[j].by;

				Layer[i].cel[j].w = gfx_li->l[i].w;
				Layer[i].cel[j].h = gfx_li->l[i].h;
				

				/*
				if( (Layer[i].gfx = GfxToDD(DD_Object, "gfx\\01.gfx")) == NULL )
					return DDE("LoadDrawS:DDLoadBitmap", i);
				*/

				if( (Layer[i].cel[j].gfx = DDLoadBitmap(DD_Object, gfx_li->l[i].cel_info[j].fName, 0, 0)) == NULL )
					return DDE("LoadDrawS:DDLoadBitmap", i);
				if( (e = DDSetColorKey(Layer[i].cel[j].gfx,  TRANS_COLOR1 ) ) != DD_OK)
					return DDE("LoadDrawS:DDSetColorKey", e);

				if(j < (gfx_li->l[i].nCel - 1) )
					Layer[i].cel[j].next = &Layer[i].cel[j + 1];
				else
					Layer[i].cel[j].next = NULL;

				if(j == 0)
				{
					Layer[i].startcel = &Layer[i].cel[0];
					Layer[i].gfx = Layer[i].cel[0].gfx;
				}
			}
		}
		else if(Layer[i].type == LT_IMAGE)
		{
			if( (Layer[i].gfx = DDLoadBitmap(DD_Object, gfx_li->l[i].fName, 0, 0)) == NULL )
				return DDE("LoadDrawS:DDLoadBitmap", i);
			if( (e = DDSetColorKey(Layer[i].gfx,  TRANS_COLOR1 ) ) != DD_OK)
				return DDE("LoadDrawS:DDSetColorKey", e);
		}
		else if(Layer[i].type == LT_MAP)
		{
			DD_SDESC	ddsd;
			unsigned __int8 k = gfx_li->l[i].map_num_images;
			GFXDATA *TempGfx = new GFXDATA[k];
			unsigned __int16 w, h, iw, ih;
			unsigned __int8 **data = gfx_li->l[i].map_info->data;

			// number of images horz
			w = gfx_li->l[i].w;
			// number of images vert
			h = gfx_li->l[i].h;

			// number of images horz
			iw = gfx_li->l[i].map_image_w;
			// number of images vert
			ih = gfx_li->l[i].map_image_h;

			r2.top = r2.left = 0;
			r2.right = iw;
			r2.bottom = ih;

			// create layer gfx to place images into
				ZeroMemory(&ddsd, sizeof(ddsd));
				ddsd.dwSize		= sizeof(ddsd);
				ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
				ddsd.dwWidth	= gfx_li->l[i].w = w*iw;
				ddsd.dwHeight	= gfx_li->l[i].h = h*ih;
				//
				ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
				if( (e = DD_Object->CreateSurface(&ddsd, &Layer[i].gfx, NULL)) != DD_OK )
					return DDE("LoadDrawS:CreateSurface", e);

				if( (e = DDSetColorKey(Layer[i].gfx,  TRANS_COLOR1 ) ) != DD_OK)
						return DDE("LoadDrawS:DDSetColorKey", e);

				if(	(e = Layer[i].gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
					return DDE("DrawLayers:Blt", e);
			//

			for(j = 0; j < k; j++)
			{
				if( (TempGfx[j] = DDLoadBitmap(DD_Object, gfx_li->l[i].map_info->fName[j], 0, 0)) == NULL )
					return DDE("LoadDrawS:DDLoadBitmap", i);
				if( (e = DDSetColorKey(TempGfx[j],  TRANS_COLOR1 ) ) != DD_OK)
					return DDE("LoadDrawS:DDSetColorKey", e);
			}

			k = 0;
			for(j = 0; k < h;)
			{
				r1.left = j*iw;
				r1.top = k*ih;
				r1.right = r1.left + iw;
				r1.bottom = r1.top + ih;

				if(	(e = Layer[i].gfx->Blt(&r1, TempGfx[ data[k][j] ], &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
					return DDE("DrawLayers:Blt", e);

				j++;
				if((j%w) == 0)
				{
					j = 0;
					k++;
				}
			}
		}
		else if(Layer[i].type == LT_TILE)
		{
			DD_SDESC	ddsd;
			unsigned __int8 k = 0;
			GFXDATA TempGfx;
			unsigned __int16 w, h, iw, ih;

			// number of images horz
			w = gfx_li->l[i].w;
			// number of images vert
			h = gfx_li->l[i].h;

			// number of images horz
			iw = gfx_li->l[i].tile_image_w;
			// number of images vert
			ih = gfx_li->l[i].tile_image_h;

			r2.top = r2.left = 0;
			r2.right = iw;
			r2.bottom = ih;

			// create layer gfx to place images into
				ZeroMemory(&ddsd, sizeof(ddsd));
				ddsd.dwSize		= sizeof(ddsd);
				ddsd.dwFlags	= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
				ddsd.dwWidth	= gfx_li->l[i].w = w*iw;
				ddsd.dwHeight	= gfx_li->l[i].h = h*ih;
				//
				ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
				if( (e = DD_Object->CreateSurface(&ddsd, &Layer[i].gfx, NULL)) != DD_OK )
					return DDE("LoadDrawS:CreateSurface", e);

				if( (e = DDSetColorKey(Layer[i].gfx,  TRANS_COLOR1 ) ) != DD_OK)
						return DDE("LoadDrawS:DDSetColorKey", e);

				if(	(e = Layer[i].gfx->Blt(NULL, NULL, NULL,  DDBLT_COLORFILL, &FxBkg)) != DD_OK)
					return DDE("DrawLayers:Blt", e);
			//

			if( (TempGfx = DDLoadBitmap(DD_Object, gfx_li->l[i].tile_info->fName, 0, 0)) == NULL )
				return DDE("LoadDrawS:DDLoadBitmap", i);
			if( (e = DDSetColorKey(TempGfx,  TRANS_COLOR1 ) ) != DD_OK)
				return DDE("LoadDrawS:DDSetColorKey", e);

			k = 0;
			for(j = 0; k < h;)
			{
				r1.left = j*iw;
				r1.top = k*ih;
				r1.right = r1.left + iw;
				r1.bottom = r1.top + ih;

				if(	(e = Layer[i].gfx->Blt(&r1, TempGfx, &r2, DDBLT_KEYSRC, NULL)) != DD_OK)
					return DDE("DrawLayers:Blt", e);

				j++;
				if((j%w) == 0)
				{
					j = 0;
					k++;
				}
			}
		}

		Layer[i].SetSize(gfx_li->l[i].w, gfx_li->l[i].h);
		Layer[i].SetPos(gfx_li->l[i].x, gfx_li->l[i].y);
		Layer[i].SetHotSpot(gfx_li->l[i].hx, gfx_li->l[i].hy);

		Layer[i].old_r = Layer[i].r;
		Layer[i].old_ir = Layer[i].ir;
	}

///////////////////////////////////////////////////////
// Mouse
///////////////////////////////////////////////////////
	UseMouse = gfx_li->UseMouse;

	if(UseMouse)
	{
		if( (Mouse->gfx = DDLoadBitmap(DD_Object, gfx_li->Mouse_fName, 0, 0)) == NULL )
			return DDE("LoadDrawS:DDLoadBitmap", i);
		if( (e = DDSetColorKey(Mouse->gfx,  TRANS_COLOR1 ) ) != DD_OK)
			return DDE("LoadDrawS:DDSetColorKey", e);

		Mouse->SetSize(11, 19);
		Mouse->SetPos(0, 0);
		Mouse->draw = false;

		Mouse->old_r = Mouse->r;
		Mouse->old_ir = Mouse->ir;
	}

	GlobalReDraw = true;

	return 0;
}
