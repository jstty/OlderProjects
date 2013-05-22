////////////////////////////////////////////////////////////////////////
//	Program Name:	Level???.cpp
//	Programmer:		Joseph E Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Level File
//	Date: 
////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include "math.h"
#include "Level003.h"

//////////////////////////////////////
// DLLMain
//////////////////////////////////////
BOOL APIENTRY DllEntryPoint(HINSTANCE hInstDLL, WORD wDataSeg, LPVOID lpReserved)
{	return TRUE; }

void ShowStatus(bool stat)
{
	c_level->visable = stat;
	c_gold->visable = stat;
	c_next->visable = stat;
	c_exp->visable = stat;

	c_hps->visable = stat;
	c_t_hps->visable = stat;
	c_mps->visable = stat;
	c_t_mps->visable = stat;

	c_ba->visable = stat;
	c_bd->visable = stat;
	c_bm->visable = stat;
	c_bs->visable = stat;

	c_ia->visable = stat;
	c_id->visable = stat;
	c_im->visable = stat;
	c_is->visable = stat;

	c_ta->visable = stat;
	c_td->visable = stat;
	c_tm->visable = stat;
	c_ts->visable = stat;
}

void RedrawStat()
{
	bool stat = true;

	c_level->redraw = stat;
	c_gold->redraw = stat;
	c_next->redraw = stat;
	c_exp->redraw = stat;

	c_hps->redraw = stat;
	c_t_hps->redraw = stat;
	c_mps->redraw = stat;
	c_t_mps->redraw = stat;

	c_ba->redraw = stat;
	c_bd->redraw = stat;
	c_bm->redraw = stat;
	c_bs->redraw = stat;

	c_ia->redraw = stat;
	c_id->redraw = stat;
	c_im->redraw = stat;
	c_is->redraw = stat;

	c_ta->redraw = stat;
	c_td->redraw = stat;
	c_tm->redraw = stat;
	c_ts->redraw = stat;
}

void PrintStat(unsigned __int8 player)
{
	C_INFO *ci = &gv.char_info[player];

	Display->SetCounter(c_level, ci->level);
	Display->SetCounter(c_gold, ci->gold);
	Display->SetCounter(c_next, ci->next);
	Display->SetCounter(c_exp, ci->exp);

	Display->SetCounter(c_hps, ci->hp);
	Display->SetCounter(c_t_hps, ci->t_hp);
	Display->SetCounter(c_mps, ci->mp);
	Display->SetCounter(c_t_mps, ci->t_mp);

	Display->SetCounter(c_ba, ci->a);
	Display->SetCounter(c_bd, ci->d);
	Display->SetCounter(c_bm, ci->m);
	Display->SetCounter(c_bs, ci->s);

	Display->SetCounter(c_ia, ci->a_item);
	Display->SetCounter(c_id, ci->d_item);
	Display->SetCounter(c_im, ci->m_item);
	Display->SetCounter(c_is, ci->s_item);

	Display->SetCounter(c_ta, ci->a + ci->a_item);
	Display->SetCounter(c_td, ci->d + ci->d_item);
	Display->SetCounter(c_tm, ci->m + ci->m_item);
	Display->SetCounter(c_ts, ci->s + ci->s_item);
}

///////////////////////////////////////////////////////
// 	LoadDefaultVar
///////////////////////////////////////////////////////
HRESULT LoadDefaultVar(void *v, DWORD s)
{
		Val = (VALUES *)v;
		g = Val->Game;
		gData = &g->gData;

		if(gData->data != NULL)
		{
			GAME_VAR *temp_gv = (GAME_VAR *)gData->data;
			gv = *temp_gv;
		}

		P1 = Val->Controls->Player[0];
		cInfo = &Val->Controls->Mouse;
		cSprite = Val->Display->Mouse;
		Display = Val->Display;
		//
		Tile1 = Display->FindLayer("Tile1");
		Tile2 = Display->FindLayer("Tile2");
		Map = Display->FindLayer("Map");
		Camp = Display->FindLayer("Camp");
		Menu = Display->FindLayer("Menu");
		Pic[0] = Display->FindLayer("sPic");
		Pic[1] = Display->FindLayer("rPic");
		Stat[0] = Display->FindLayer("sStat");
		Stat[1] = Display->FindLayer("rStat");

		nGoo = 5;
		Goo = new LAYER*[nGoo];
		ZeroMemory(Goo, nGoo*sizeof(LAYER*));
		Goo[0] = Display->FindLayer("BlueGoo");
		Goo[1] = Display->FindLayer("RedGoo");

		// Red
		Goo[2] = Display->CopyLayer(Goo[0]);
		Goo[2]->SetPos(80, 120);

		// Blue
		Goo[3] = Display->CopyLayer(Goo[1]);
		Goo[3]->SetPos(140, 100);
		Goo[4] = Display->CopyLayer(Goo[1]);
		Goo[4]->SetPos(40, 160);

		Super = Display->FindLayer("Super");
		Gray = Display->FindLayer("Gray");
		Hand = Display->FindLayer("Hand");

		xCounter = Display->CreateCounter(5, 5, 3);
		yCounter = Display->CreateCounter(40, 5, 3);

		c_level	= Display->CreateCounter(176, 21, 2);
		c_gold	= Display->CreateCounter(242, 21, 7);
		c_next	= Display->CreateCounter(242, 41, 7);
		c_exp		= Display->CreateCounter(122, 41, 7);

		c_hps			= Display->CreateCounter(120, 61, 3);
		c_t_hps		= Display->CreateCounter(161, 61, 3);
		c_mps			= Display->CreateCounter(240, 61, 3);
		c_t_mps		= Display->CreateCounter(282, 61, 3);

		c_ba		= Display->CreateCounter(112, 120, 3);
		c_bd		= Display->CreateCounter(112, 142, 3);
		c_bm		= Display->CreateCounter(112, 164, 3);
		c_bs		= Display->CreateCounter(112, 186, 3);

		c_ia		= Display->CreateCounter(154, 120, 3);
		c_id		= Display->CreateCounter(154, 142, 3);
		c_im		= Display->CreateCounter(154, 164, 3);
		c_is		= Display->CreateCounter(154, 186, 3);

		c_ta		= Display->CreateCounter(37, 120, 3);
		c_td		= Display->CreateCounter(37, 142, 3);
		c_tm		= Display->CreateCounter(37, 164, 3);
		c_ts		= Display->CreateCounter(37, 186, 3);

		ShowStatus(false);

//
		i = 0;
		mItem[i++] = true;
		mItem[i++] = false;
		mItem[i++] = false;
		mItem[i++] = false;
		End = i - 1;

		//8,59
		//8,91
		//8,111
		//8,151
		//8,171
		short xBase = (short)Menu->r.left;
		short yBase = (short)Menu->r.top;
		i = 0;
		Pos[i].x = 8 + xBase;	Pos[i++].y = 7 + yBase;
		Pos[i].x = 8 + xBase;	Pos[i++].y = 27 + yBase;
		Pos[i].x = 8 + xBase;	Pos[i++].y = 53 + yBase;
		Pos[i].x = 8 + xBase;	Pos[i++].y = 73 + yBase;

		mNum = 0;
		Hand->SetPos(Pos[mNum].x, Pos[mNum].y );
		Hand->Show();

		sPlayer = 0;
		Pic[sPlayer]->Show();

		mDelay = 500;

		uButton = false;
		dButton = false;
		lButton = false;
		rButton = false;

		if(P1[UP].v)
			uButton = true;
		else if(P1[DOWN].v)
			dButton = true;
		if(P1[LEFT].v)
			lButton = true;
		else if(P1[RIGHT].v)
			rButton = true;

		b2Button = true;
		bButton = true;
		Level = 0;

		mTick = Tick = GetTickCount();

		for(i = 0; i < nGoo; i++)
			Goo[i]->movement_done = true;
		
		WalkOnMap = false;

		/*
		gv.char_info[0].level = 12;
		gv.char_info[0].gold	= 1234567;
		gv.char_info[0].exp		= 1234567;
		gv.char_info[0].next	= 1234567;

		gv.char_info[0].hp	= 123;
		gv.char_info[0].t_hp	= 456;
		gv.char_info[0].mp	= 123;
		gv.char_info[0].t_mp	= 456;

		gv.char_info[0].a = 12;
		gv.char_info[0].d = 34;
		gv.char_info[0].m = 56;
		gv.char_info[0].s = 78;

		gv.char_info[0].a_item = 12;
		gv.char_info[0].d_item = 34;
		gv.char_info[0].m_item = 56;
		gv.char_info[0].s_item = 78;
	*/
		
		return 0;
}

void MoveUp(void)
{
	mItem[mNum] = false;

	if(mNum == 0)
		mNum = End;
	else
		mNum--;

	mItem[mNum] = true;

	Hand->SetPos(Pos[mNum].x, Pos[mNum].y );

	uButton = true;
}

void MoveDown(void)
{
	mItem[mNum] = false;
	
	if(mNum == End)
		mNum = 0;
	else
		mNum++;

	mItem[mNum] = true;

	Hand->SetPos(Pos[mNum].x, Pos[mNum].y );

	dButton = true;
}

void MapMenu()
{
	if(Level == 0)
	{
		Pic[sPlayer]->redraw = true;
		Menu->redraw = true;
		Hand->redraw = true;
		Tile2->redraw = true;
		Map->redraw = true;

		if(!uButton && P1[UP].v)
		{
			MoveUp();
			mTick = GetTickCount();
		}
		else if(uButton && P1[UP].v && (GetTickCount() - mTick > mDelay))
		{
			MoveUp();
			mTick = GetTickCount();
		}
		else if(uButton && !P1[UP].v )
			uButton = false;
		else if(!dButton && P1[DOWN].v)
		{
			MoveDown();
			mTick = GetTickCount();
		}
		else if(dButton && P1[DOWN].v && (GetTickCount() - mTick > mDelay))
		{
			MoveDown();
			mTick = GetTickCount();
		}
		else if(dButton && !P1[DOWN].v )
			dButton = false;
		else if( !dButton && !uButton && !bButton && P1[B1].v )
		{
			if(mNum == 0)
			{
				Level = 1;
				bButton = true;
			}
			else if(mNum == 1)
			{
				/*
				Map->moveable = true;
				Tile1->moveable = false;
				Hand->Hide();
				Camp->Hide();

				Tile1->redraw = true;
				Menu->redraw = true;
				Level = 3;
				*/

				WalkOnMap = true;

				Gray->visable = true;

				for(i = 0; i < nGoo; i++)
				{
					Goo[i]->visable = true;
					Goo[i]->moveable = true;
					Goo[i]->animate = true;
					Goo[i]->movement_done = true;
				}

				Super->visable = true;
				Super->moveable = true;
				Super->animate = true;
				Super->movement_done = true;

				Hand->visable = false;

				bButton = true;
			}
			else if(mNum == 2)
			{
				gv.ScreenNum = gData->LevelNum;
				gv.SubScreenNum = gData->SubLevelNum;
				gv.h = 456;
				gv.m = 12;
				gv.s = 56;

				gData->size = sizeof(gv);
				gData->data = &gv;

				Val->Main->LoadLevel = false;
				gData->SubLevelNum = 1;
				gData->LevelNum = 1;
				bButton = true;
			}
			else if(mNum == 3)
			{
				PostMessage(Val->Main->Get_MainHwnd(), WM_DESTROY, 0, 0);
				bButton = true;
			}
		}
		else if(!P1[B1].v)
			bButton = false;
	}
	else if(Level == 1)
	{
		Tile1->moveable = false;
		Menu->Hide();
		Tile1->redraw = true;
		Camp->animate = false;

		Tile2->redraw = true;
		Map->redraw = true;

		Stat[sPlayer]->Show();
		Stat[sPlayer]->redraw = true;

		ShowStatus(true);
		RedrawStat();
		PrintStat(sPlayer);

		Hand->SetPos(25, 227);
		Level = 2;
	}
	else if(Level == 2)
	{
		if( !bButton && P1[B1].v )
		{
			Level = 0;
			Menu->Show();

			Pic[sPlayer]->Show();
			Pic[sPlayer]->redraw = true;
			Pic[!sPlayer]->Hide();

			Tile1->moveable = true;
			Hand->SetPos(Pos[mNum].x, Pos[mNum].y );
			Hand->redraw = true;

			Map->redraw = true;
			Tile2->redraw = true;
			Camp->animate = true;

			ShowStatus(false);

			Stat[0]->Hide();
			Stat[1]->Hide();

			bButton = true;
		}
		else if(!P1[B1].v)
			bButton = false;
	}
	/*
	else if( (Level == 3) && (Map->movement_done))
	{
		Tile1->moveable = true;
		Hand->Show();
		Hand->SetPos(Pos[mNum].x, Pos[mNum].y );
		Menu->redraw = true;
		Level = 0;
	}
	*/

	if(!lButton && P1[LEFT].v)
	{
		if(Level == 0)
		{
			Pic[sPlayer]->Hide();
			sPlayer = sPlayer ? 0 : 1;
			Pic[sPlayer]->Show();
			Pic[sPlayer]->redraw = true;

			PrintStat(sPlayer);
			RedrawStat();
		}
		else if(Level == 2)
		{
			Hand->redraw = true;

			Stat[sPlayer]->Hide();
			sPlayer = sPlayer ? 0 : 1;
			Stat[sPlayer]->Show();
			Stat[sPlayer]->redraw = true;

			PrintStat(sPlayer);
			RedrawStat();
		}
		lButton = true;
	}
	else if(lButton && !P1[LEFT].v )
		lButton = false;
	else if(!rButton && P1[RIGHT].v)
	{
		if(Level == 0)
		{
			Pic[sPlayer]->Hide();
			sPlayer = sPlayer ? 0 : 1;
			Pic[sPlayer]->Show();
			Pic[sPlayer]->redraw = true;

			PrintStat(sPlayer);
			RedrawStat();
		}
		else if(Level == 2)
		{
			Hand->redraw = true;

			Stat[sPlayer]->Hide();
			sPlayer = sPlayer ? 0 : 1;
			Stat[sPlayer]->Show();
			Stat[sPlayer]->redraw = true;

			PrintStat(sPlayer);
			RedrawStat();
		}
		rButton = true;
	}
	else if(rButton && !P1[RIGHT].v )
		rButton = false;
}

void Walk()
{
		Pic[sPlayer]->redraw = true;
		Menu->redraw = true;
		Tile2->redraw = true;
		Map->redraw = true;
		for(i = 0; i < nGoo; i++)
			Goo[i]->redraw = true;

		xCounter->redraw = true;
		yCounter->redraw = true;

		Super->redraw = true;
		Gray->redraw = true;

		Goo_Movement_done = 0;
		for(i = 0; i < nGoo; i++)
		{
			if(Goo[i]->movement_done)
				Goo_Movement_done++;
		}
		
		if(Goo_Movement_done == nGoo)
		{
			for(i = 0; i < nGoo; i++)
			{
				Tick = GetTickCount();
				Goo[i]->ResetMove();
				Goo[i]->moveable = false;
			}
		}

		Goo_Movement_done = 0;
		for(i = 0; i < nGoo; i++)
		{
			if(!Goo[i]->moveable)
				Goo_Movement_done++;
		}

		if( (GetTickCount() - Tick > 100) && (Goo_Movement_done == nGoo) )
		{
			for(j = 0; j < nGoo; j++)
			{
				Start = g->Rand(1, 5);
				for(i = Start + 1; i != Start; i++)
				{
					if(i > 5)
						i = 1;

					x = 0;	y = 0;

					if(i == 1)
						x = -20;	// Left
					else if(i == 2)
						x = 20;		// Right
					else if(i == 3)
						y = -20;	// Up
					else if(i == 4)
						y = 20;		// Down

					if( (((Goo[j]->r.left + x)/20 - 5) >= 0) && (((Goo[j]->r.top + y)/20 - 1) >= 0))
					{
						if( Goo[j]->col->map->data[(Goo[j]->r.top + y)/20 - 1][(Goo[j]->r.left + x)/20 - 5] )
						{
							if(i == 1)
								Goo[j]->SetMove("Left");
							else if(i == 2)
								Goo[j]->SetMove("Right");
							else if(i == 3)
								Goo[j]->SetMove("Up");
							else if(i == 4)
								Goo[j]->SetMove("Down");
							else
								Goo[j]->movement_done = true;

							Goo[j]->moveable = true;

							i = Start - 1;
						}
					}
				}
			}

		}

		if( Super->movement_done )
		{
			Tick = GetTickCount();
			Super->ResetMove();
			Super->moveable = false;
		}

		if( !bButton && P1[B2].v )
		{
			WalkOnMap = false;
			Gray->visable = false;
			
			for(i = 0; i < nGoo; i++)
			{
				Goo[i]->visable = false;
				Goo[i]->moveable = false;
				Goo[i]->animate = false;
			}

			Super->visable = false;
			Super->moveable = false;
			Super->animate = false;

			Hand->visable = true;

			b2Button = true;

			return;
		}
		else if(!P1[B2].v)
			b2Button = false;

		if(Super->hit)
		{
			//Display->SetCounter(xCounter, "HIT");

			Val->Main->LoadLevel = false;
			gData->LevelNum = 4;
		}
		else
		{
			Display->SetCounter(xCounter, "   ");
		}

		// Up
		if( !Super->moveable && !uButton && P1[UP].v)
		{
			s_x = (Super->r.left)/20 - 5;
			s_y = (Super->r.top)/20 - 2;
			
			if( (s_y >= 0) && (s_x >= 0) )
			{
				if(Super->col->map->data[s_y][s_x])
				{
					Super->SetMove("Up");
					Super->moveable = true;

					uButton = true;
					mTick = GetTickCount();
				}
			}
		}
		else if(uButton && P1[UP].v && (GetTickCount() - mTick > mDelay))
		{
			s_x = (Super->r.left)/20 - 5;
			s_y = (Super->r.top)/20 - 2;

			if( (s_y >= 0) && (s_x >= 0) )
			{
				if(Super->col->map->data[s_y][s_x])
				{
					Super->SetMove("Up");
					Super->moveable = true;

					mTick = GetTickCount();
				}
			}
		}
		else if(!P1[UP].v)
			uButton = false;

		// Down
		if( !Super->moveable && !dButton && P1[DOWN].v)
		{
			s_x = (Super->r.left)/20 - 5;
			s_y = (Super->r.top)/20;

			if( (s_y >= 0) && (s_x >= 0) )
			{
				if(Super->col->map->data[s_y][s_x])
				{
					Super->SetMove("Down");
					Super->moveable = true;

					uButton = true;
					mTick = GetTickCount();
				}
			}
		}
		else if(dButton && P1[DOWN].v && (GetTickCount() - mTick > mDelay))
		{
			s_x = (Super->r.left)/20 - 5;
			s_y = (Super->r.top)/20;

			if( (s_y >= 0) && (s_x >= 0) )
			{
				if(Super->col->map->data[s_y][s_x])
				{
					Super->SetMove("Down");
					Super->moveable = true;

					mTick = GetTickCount();
				}
			}

		}
		else if(!P1[DOWN].v)
			dButton = false;

		// Left
		if( !Super->moveable && !lButton && P1[LEFT].v)
		{
			s_x = (Super->r.left)/20 - 6;
			s_y = (Super->r.top)/20 - 1;

			if( (s_y >= 0) && (s_x >= 0) )
			{
				if(Super->col->map->data[s_y][s_x])
				{
					Super->SetMove("Left");
					Super->moveable = true;

					lButton = true;
					mTick = GetTickCount();
				}
			}
		}
		else if(lButton && P1[LEFT].v && (GetTickCount() - mTick > mDelay))
		{
			s_x = (Super->r.left)/20 - 6;
			s_y = (Super->r.top)/20 - 1;

			if( (s_y >= 0) && (s_x >= 0) )
			{
				if(Super->col->map->data[s_y][s_x])
				{
					Super->SetMove("Left");
					Super->moveable = true;

					mTick = GetTickCount();
				}
			}
		}
		else if(!P1[LEFT].v)
			lButton = false;

		// Right
		if( !Super->moveable && !rButton && P1[RIGHT].v)
		{
			s_x = (Super->r.left)/20 - 4;
			s_y = (Super->r.top)/20 - 1;

			if( (s_y >= 0) && (s_x >= 0) )
			{
				if(Super->col->map->data[s_y][s_x])
				{
					Super->SetMove("Right");
					Super->moveable = true;

					rButton = true;
					mTick = GetTickCount();
				}
			}
		}
		else if(dButton && P1[RIGHT].v && (GetTickCount() - mTick > mDelay))
		{
			s_x = (Super->r.left)/20 - 4;
			s_y = (Super->r.top)/20 - 1;

			if( (s_y >= 0) && (s_x >= 0) )
			{
				if(Super->col->map->data[s_y][s_x])
				{
					Super->SetMove("Right");
					Super->moveable = true;

					mTick = GetTickCount();
				}
			}
		}
		else if(!P1[RIGHT].v)
			rButton = false;

		if( !bButton && P1[B1].v )
			bButton = true;
		else if(!P1[B1].v)
			bButton = false;

}

///////////////////////////////////////////////////////
// 	LevelCode
///////////////////////////////////////////////////////
HRESULT LevelCode(void *v, DWORD s)
{

	if(WalkOnMap)
		Walk();
	else
		MapMenu();

	return 0;
}
///////////////////////////////////////////////////////
// 	CustomCode
///////////////////////////////////////////////////////
HRESULT CustomCode(void *v, DWORD s)
{
	
	return 0;
}
