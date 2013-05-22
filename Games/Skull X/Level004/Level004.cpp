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
#include "Level004.h"

//////////////////////////////////////
// DLLMain
//////////////////////////////////////
BOOL APIENTRY DllEntryPoint(HINSTANCE hInstDLL, WORD wDataSeg, LPVOID lpReserved)
{	return TRUE; }

///////////////////////////////////////////////////////
// 	LoadDefaultVar
///////////////////////////////////////////////////////
HRESULT LoadDefaultVar(void *v, DWORD s)
{
		Val = (VALUES *)v;
		gData = &Val->Game->gData;

		if(gData->data != NULL)
		{
			GAME_VAR *temp_gv = (GAME_VAR *)gData->data;
			gv = *temp_gv;
		}

		P1 = Val->Controls->Player[0];
		Display = Val->Display;
		//
		LandA = Display->FindLayer("LandA");
		LandB = Display->FindLayer("LandB");
		Tab = Display->FindLayer("Tab");
		Hand = Display->FindLayer("Hand");

		i = 0;
		mItem[i++] = true;
		mItem[i++] = false;
		mItem[i++] = false;
		mItem[i++] = false;
		mItem[i++] = false;
		mItem[i++] = false;
		End = i - 1;

		//	30,174
		//	30,190
		//	30,206
		//	30,222
		//	99,174
		//	99,190

		i = 0;
		Pos[i].x = 30;	Pos[i++].y = 174;
		Pos[i].x = 30;	Pos[i++].y = 190;
		Pos[i].x = 30;	Pos[i++].y = 206;
		Pos[i].x = 30;	Pos[i++].y = 222;
		Pos[i].x = 99;	Pos[i++].y = 174;
		Pos[i].x = 99;	Pos[i++].y = 190;

		mNum = 0;
		Hand->SetPos(Pos[mNum].x, Pos[mNum].y );
		Hand->Show();

		//
		Super = Display->FindLayer("Super");
		Red = Display->FindLayer("Red");

		Name	= Display->CreateCounter(5, 144, 5, "RED", AT_CENTER);

		s_hp	= Display->CreateCounter(240, 161, 3);
		s_t_hp	= Display->CreateCounter(240, 177, 3);
		s_mp	= Display->CreateCounter(280, 161, 3);
		s_t_mp	= Display->CreateCounter(280, 177, 3);

		r_hp	= Display->CreateCounter(240, 203, 3);
		r_t_hp	= Display->CreateCounter(240, 219, 3);
		r_mp	= Display->CreateCounter(280, 203, 3);
		r_t_mp	= Display->CreateCounter(280, 219, 3);

//
		// Enemy
		Lupi = Display->FindLayer("Lupi");
//

// Controls
		if(P1[UP].v)
			uButton = true;
		else if(P1[DOWN].v)
			dButton = true;
		if(P1[LEFT].v)
			lButton = true;
		else if(P1[RIGHT].v)
			rButton = true;

		b1Button = true;
		b2Button = true;

		mDelay = 750;
//
		return 0;
}

// Menu
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

///////////////////////////////////////////////////////
// 	LevelCode
///////////////////////////////////////////////////////
HRESULT LevelCode(void *v, DWORD s)
{
	/*
	LandB->redraw = true;
	Tab->redraw = true;

	Name->redraw = true;
	
	s_hp->redraw = true;
	s_t_hp->redraw = true;
	s_mp->redraw = true;
	s_t_mp->redraw = true;

	r_hp->redraw = true;
	r_t_hp->redraw = true;
	r_mp->redraw = true;
	r_t_mp->redraw = true;
*/
	LandA->redraw = true;
	Lupi->redraw = true;

	Super->redraw = true;
	Red->redraw = true;

	if(!uButton && P1[UP].v)
	{
		MoveUp();
		mTick = GetTickCount();

		Tab->redraw = true;
		Name->redraw = true;

	}
	else if(uButton && P1[UP].v && (GetTickCount() - mTick > mDelay))
	{
		MoveUp();
		mTick = GetTickCount();

		Tab->redraw = true;
		Name->redraw = true;
	}
	else if(uButton && !P1[UP].v )
		uButton = false;
	else if(!dButton && P1[DOWN].v)
	{
		MoveDown();
		mTick = GetTickCount();

		Tab->redraw = true;
		Name->redraw = true;
	}
	else if(dButton && P1[DOWN].v && (GetTickCount() - mTick > mDelay))
	{
		MoveDown();
		mTick = GetTickCount();

		Tab->redraw = true;
		Name->redraw = true;
	}
	else if(dButton && !P1[DOWN].v )
		dButton = false;
	else if(!lButton && P1[LEFT].v)
	{
		mTick = GetTickCount();
		Tab->redraw = true;
		Name->redraw = true;
		
		mItem[mNum] = false;

		if(mNum == 0)
			mNum = 4;
		else if(mNum == 4)
			mNum = 0;
		else if( (mNum > 0) && (mNum < 4) )
			mNum =  5;
		else if( mNum == 5 )
			mNum =  1;

		mItem[mNum] = true;

		Hand->SetPos(Pos[mNum].x, Pos[mNum].y );
		lButton = true;
	}
	else if(lButton && P1[LEFT].v && (GetTickCount() - mTick > mDelay))
	{
		mTick = GetTickCount();
		Tab->redraw = true;
		Name->redraw = true;

		mItem[mNum] = false;

		if(mNum == 0)
			mNum = 4;
		else if(mNum == 4)
			mNum = 0;
		else if( (mNum > 0) && (mNum < 4) )
			mNum =  5;
		else if( mNum == 5 )
			mNum =  1;

		mItem[mNum] = true;

		Hand->SetPos(Pos[mNum].x, Pos[mNum].y );
		lButton = true;
	}
	else if(lButton && !P1[LEFT].v )
		lButton = false;
	else if(!rButton && P1[RIGHT].v)
	{
		mTick = GetTickCount();
		Tab->redraw = true;
		Name->redraw = true;

		mItem[mNum] = false;

		if(mNum == 0)
			mNum = 4;
		else if(mNum == 4)
			mNum = 0;
		else if( (mNum > 0) && (mNum < 4) )
			mNum =  5;
		else if( mNum == 5 )
			mNum =  1;

		mItem[mNum] = true;

		Hand->SetPos(Pos[mNum].x, Pos[mNum].y );
		rButton = true;
	}
	else if(rButton && P1[RIGHT].v && (GetTickCount() - mTick > mDelay))
	{
		mTick = GetTickCount();
		Tab->redraw = true;
		Name->redraw = true;

		mItem[mNum] = false;

		if(mNum == 0)
			mNum = 4;
		else if(mNum == 4)
			mNum = 0;
		else if( (mNum > 0) && (mNum < 4) )
			mNum =  5;
		else if( mNum == 5 )
			mNum =  1;

		mItem[mNum] = true;

		Hand->SetPos(Pos[mNum].x, Pos[mNum].y );
		rButton = true;
	}
	else if(rButton && !P1[RIGHT].v )
		rButton = false;

	if( !b1Button && P1[B1].v )
	{
		Val->Main->LoadLevel = false;
		gData->LevelNum = 3;
		b1Button = true;
	}
	else if(!P1[B1].v)
		b1Button = false;

	return 0;
}
///////////////////////////////////////////////////////
// 	CustomCode
///////////////////////////////////////////////////////
HRESULT CustomCode(void *v, DWORD s)
{
	
	return 0;
}
