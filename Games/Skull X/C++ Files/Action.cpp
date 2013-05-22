////////////////////////////////////////////////////////////////////////
//	Program Name:	Action.cpp
//	Programmer:		Joseph E. Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Action Class header File
//	Date:					2/22/2000
//	Version:			2.00
////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdarg.h>

#include "..\Header Files\ValuesClass.h"
extern VALUES		*Val;

#ifdef _DEBUG
	#include "..\Header Files\TestSpeed.h"
	extern TestSpeed tsAction;
#endif

void SetArray(unsigned __int8 **d, unsigned __int8 *a, unsigned __int16 w);

	/*
void SetArray(unsigned __int8 **d, unsigned __int8 *a, unsigned __int16 w)
{
	d[0] = new unsigned __int8[w];
	ZeroMemory(d[0], w*sizeof(unsigned __int8) );

	unsigned __int8 k;
	for(k = 0; k < w; k++)
		d[0][k] = a[k];
}
*/

void SetStr(char **a, const char *b) 
{
	*a = new char[ strlen(b) ];
	strcpy(*a, b);
}

//////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////
bool ACTION::Load(void)
{
	unsigned __int16 LevelNum = Val->Game->gData.LevelNum;

	if(LevelNum == 1)
	{
		LAYER *tl;

		DISPLAY *d = Val->Display;
		Move = NULL;

		unsigned __int8 nMove = 1;
		Move = new MOVE[nMove];
		ZeroMemory(Move, nMove*sizeof(MOVE) );
		unsigned __int8 j;

		//
		//
		//
		i = 0;
		Move[i].fd = new XY[64];
		Move[i].delay = 100;

		for(j = 0; j < 63; j++)
		{
			Move[i].fd[j].x = -2;
			Move[i].fd[j].y = -2;
			Move[i].fd[j].next = &Move[i].fd[j + 1];
		}
		Move[i].fd[j].x = 126;
		Move[i].fd[j].y = 126;
		Move[i].fd[j].next = NULL;

		tl= d->FindLayer("Tile");
		tl->d = Move[i].fd;
		tl->move = &Move[i];

	}
	else if(LevelNum == 3)
	{
		LAYER *tl;
		DISPLAY *d = Val->Display;
		Move = NULL;

		unsigned __int8 nMove = 6;
		Move = new MOVE[nMove];
		ZeroMemory(Move, nMove*sizeof(MOVE) );
		unsigned __int8 j;

		//
		//
		//
		i = 0;
		Move[i].num = 11;
		Move[i].fd = new XY[11];
		Move[i].delay = 100;
		for(j = 0; j < 9; j++)
		{
			Move[i].fd[j].x = 0;
			Move[i].fd[j].y = -2;

			Move[i].fd[j].next = &Move[i].fd[j + 1];
		}
		Move[i].fd[j].x = 0;
		Move[i].fd[j].y = 18;
		Move[i].fd[j].next = NULL;

		tl= d->FindLayer("Tile1");
		tl->d = Move[i].fd;
		tl->move = &Move[i];
		i++;

		//
		//
		//
		Move[i].num = 50;
		Move[i].fd = new XY[Move[i].num];
		Move[i].delay = 100;
		for(j = 0; j < 49; j++)
		{
			Move[i].fd[j].x = 4;
			Move[i].fd[j].y = 0;

			Move[i].fd[j].next = &Move[i].fd[j + 1];
		}
		Move[i].fd[j].x = 4;
		Move[i].fd[j].y = 0;
		Move[i].fd[j].next = NULL;

		tl= d->FindLayer("Map");
		tl->d = Move[i].fd;
		tl->move = &Move[i];
		i++;


		//
		// Blue Goo move
		//
		tl= d->FindLayer("BlueGoo");

		tl->mList = new MOVE*[4];
		ZeroMemory(tl->mList, 4*sizeof(MOVE));
		tl->move = &Move[i];

		//
		// Right
		SetStr(&Move[i].Name, "Right");
		Move[i].num = 5;
		Move[i].fd = new XY[Move[i].num];
		Move[i].delay = 100;
		for(j = 0; j < 4; j++)
		{
			Move[i].fd[j].x = 4;
			Move[i].fd[j].y = 0;

			Move[i].fd[j].next = &Move[i].fd[j + 1];
		}
		Move[i].fd[j].x = 4;
		Move[i].fd[j].y = 0;
		Move[i].fd[j].next = NULL;

		tl->d = Move[i].fd;
		tl->mList[0] = &Move[i];
		i++;

		// Left
		SetStr(&Move[i].Name, "Left");
		Move[i].num = 5;
		Move[i].fd = new XY[Move[i].num];
		Move[i].delay = 100;
		for(j = 0; j < 4; j++)
		{
			Move[i].fd[j].x = -4;
			Move[i].fd[j].y = 0;

			Move[i].fd[j].next = &Move[i].fd[j + 1];
		}
		Move[i].fd[j].x = -4;
		Move[i].fd[j].y = 0;
		Move[i].fd[j].next = NULL;

		tl->mList[1] = &Move[i];
		i++;

		// Up
		SetStr(&Move[i].Name, "Up");
		Move[i].num = 5;
		Move[i].fd = new XY[Move[i].num];
		Move[i].delay = 100;
		for(j = 0; j < 4; j++)
		{
			Move[i].fd[j].x = 0;
			Move[i].fd[j].y = -4;

			Move[i].fd[j].next = &Move[i].fd[j + 1];
		}
		Move[i].fd[j].x = 0;
		Move[i].fd[j].y = -4;
		Move[i].fd[j].next = NULL;

		tl->mList[2] = &Move[i];
		i++;

		// Down
		SetStr(&Move[i].Name, "Down");
		Move[i].num = 5;
		Move[i].fd = new XY[Move[i].num];
		Move[i].delay = 100;
		for(j = 0; j < 4; j++)
		{
			Move[i].fd[j].x = 0;
			Move[i].fd[j].y = 4;

			Move[i].fd[j].next = &Move[i].fd[j + 1];
		}
		Move[i].fd[j].x = 0;
		Move[i].fd[j].y = 4;
		Move[i].fd[j].next = NULL;

		tl->mList[3] = &Move[i];
		i++;

		LAYER *tl2 = d->FindLayer("RedGoo");
		tl2->mList = tl->mList;
		tl2->move = tl->move;

		tl2 = d->FindLayer("Super");
		tl2->mList = tl->mList;
		tl2->move = tl->move;

		//
		//
		//
		unsigned __int8 nCol = 2;
		Col = new COL[nCol];
		ZeroMemory(Col, nCol*sizeof(COL) );
		
		Col[0].type = CT_BOTH;
		Col[0].map = new MAP;
		Col[0].map->nCol = 10;
		Col[0].map->nRow = 10;
		unsigned __int8 a1[10][10] =
		{
			{0,0,0,0,0, 0,0,0,0,0}, 
			{0,0,1,1,0, 0,0,0,0,0},
			{0,1,1,1,0, 0,0,1,0,0},
			{0,1,1,1,1, 1,1,1,1,0},
			{0,1,1,1,1, 1,1,1,1,0},

			{0,1,0,1,0, 0,1,1,1,0},
			{0,1,1,0,1, 1,0,1,1,0},
			{0,0,0,0,1, 1,1,0,1,0},
			{0,1,1,1,1, 1,1,1,1,0},
			{0,0,0,0,0, 0,0,0,0,0}
		};


		Col[0].map->data = new unsigned __int8*[Col[0].map->nRow];
		ZeroMemory(Col[0].map->data, Col[0].map->nRow*sizeof(unsigned __int8*) );
		for(j = 0; j < Col[0].map->nRow; j++)
			SetArray(&Col[0].map->data[j], &a1[j][0], Col[0].map->nCol);

		Col[0].nZone = 1;
		Col[0].zone = new XY_WH[Col[0].nZone];
		ZeroMemory(Col[0].zone, Col[0].nZone*sizeof(XY_WH));
		Col[0].zone[0].x = 5;
		Col[0].zone[0].y = 5;
		Col[0].zone[0].w = 10;
		Col[0].zone[0].h = 10;

		tl= d->FindLayer("BlueGoo");
		tl->col = &Col[0];

		tl= d->FindLayer("RedGoo");
		tl->col = &Col[0];

		Col[1].type = CT_BOTH;
		Col[1].map = new MAP;
		Col[1].map->nCol = 10;
		Col[1].map->nRow = 10;
		unsigned __int8 a2[10][10] =
		{
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
		};

		Col[1].map->data = new unsigned __int8*[Col[1].map->nRow];
		ZeroMemory(Col[1].map->data, Col[1].map->nRow*sizeof(unsigned __int8*) );
		for(j = 0; j < Col[1].map->nRow; j++)
			SetArray(&Col[1].map->data[j], &a2[j][0], Col[1].map->nCol);

		Col[1].nZone = 1;
		Col[1].zone = new XY_WH[Col[1].nZone];
		ZeroMemory(Col[1].zone, Col[1].nZone*sizeof(XY_WH));
		Col[1].zone[0].x = 5;
		Col[1].zone[0].y = 5;
		Col[1].zone[0].w = 10;
		Col[1].zone[0].h = 10;

		tl= d->FindLayer("Super");
		tl->col = &Col[1];
	}

	return 0;
}

void ACTION::MoveObject(LAYER *l)
{
	tm = l->move;

	tick = GetTickCount();
	if( (unsigned)(tick - l->move_tick) > tm->delay)
	{
		l->move_tick = tick;
		OffsetRect(&l->r, l->d->x, l->d->y);

		l->redraw = true;

		l->d = l->d->next;
		if(l->d == NULL)
		{
			if(l->move_type == LT_FOREVER)
				l->d = tm->fd;
			else if( (l->move_type == LT_ONCE) || (l->move_count == 0) )
				l->movement_done = true;
			else if( (l->move_type == LT_NUMBER) && (l->move_count > 0) )
			{
				l->move_count--;
				l->d = tm->fd;
			}
		}
	}
}

void ACTION::CheckCol(LAYER *l)
{
	tc1 = l->col;

	RECT r1, r2;
	bool hit_something = false;
	
	for(tl = l->prev; tl != NULL; tl = tl->prev)
	{	
		tc2 = tl->col;
		if(!tl->hit && tl->collidable && GETBIT(tc2->type, CT_ZONE) )
		{
			r1.left		= l->r.left + tc1->zone[0].x;
			r1.top		= l->r.top + tc1->zone[0].y;
			r1.right	= r1.left + tc1->zone[0].w;
			r1.bottom	= r1.top + tc1->zone[0].h;
			r2.left		= tl->r.left + tc2->zone[0].x;
			r2.top		= tl->r.top + tc2->zone[0].y;
			r2.right	= r2.left + tc2->zone[0].w;
			r2.bottom	= r2.top + tc2->zone[0].h;

			if( IN_RECT(r1, r2) )
			{
				l->hit = true;
				l->hitby = tl;

				tl->hit = true;
				tl->hitby = l;

				hit_something = true;
			}
		}
	}

	if(!hit_something)
		l->hit = false;

}

