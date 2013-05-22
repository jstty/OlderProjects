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
#include "Level000.h"

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

		P1 = Val->Controls->Player[0];
		cInfo = &Val->Controls->Mouse;
		cSprite = Val->Display->Mouse;
		Display = Val->Display;
		//
		Hand = Display->FindLayer("Hand");
		Bkg = Display->FindLayer("Bkg");
		Text = Display->FindLayer("Text");


/*
		Guardian = Display->FindLayer("Guardian");
		gCopy = Display->CopyLayer(Guardian, "Test");
		gCopy->SetPos(200, 180);
*/

		mItem[0] = true;
		mItem[1] = false;
		mItem[2] = false;
		End = 2;

		i = 0;
		Pos[i].x		= 48;		Pos[i++].y	= 66;
		Pos[i].x		= 48;		Pos[i++].y	= 86;
		Pos[i].x		= 48;		Pos[i++].y	= 106;

		mNum = 0;
		Hand->SetPos(Pos[mNum].x, Pos[mNum].y );
		Hand->Show();

		mDelay = 500;

		uButton = false;
		dButton = false;

		if(P1[UP].v)
			uButton = true;
		else if(P1[DOWN].v)
			dButton = true;
		
		bButton = true;

		/*
		P1[UP].v = false;
		P1[DOWN].v = false;
		P1[B1].v = false;
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
	Bkg->redraw = true;
	Text->redraw = true;

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
	Bkg->redraw = true;
	Text->redraw = true;

	dButton = true;
}

///////////////////////////////////////////////////////
// 	LevelCode
///////////////////////////////////////////////////////
HRESULT LevelCode(void *v, DWORD s)
{
	gData->SubLevelNum = 0;

//	Val->Main->LoadLevel = false;
//	gData->LevelNum = 3;

	if(Display->UseMouse)
	{
		cSprite->draw = !cInfo->show;
		cSprite->SetPos(cInfo->x, cInfo->y);
		cInfo->show = true;
	}

/*
	Hand->redraw = true;
	Bkg->redraw = true;
	Text->redraw = true;
	Guardian->redraw = true;
	gCopy->redraw = true;

	if( (Guardian->anim->done) && ( strcmp(Guardian->anim->name, "grow") == 0 ) )
	{
		Guardian->Reset();
		Guardian->SetAnim("walk");
		gCopy->Show();
		gCopy->Play();
	}
*/


	if(!uButton && P1[UP].v)
	{
		MoveUp();
		Tick = GetTickCount();
	}
	else if(uButton && P1[UP].v && (GetTickCount() - Tick > mDelay))
	{
		MoveUp();
		Tick = GetTickCount();
	}
	else if(uButton && !P1[UP].v )
		uButton = false;
	else if(!dButton && P1[DOWN].v)
	{
		MoveDown();
		Tick = GetTickCount();
	}
	else if(dButton && P1[DOWN].v && (GetTickCount() - Tick > mDelay))
	{
		MoveDown();
		Tick = GetTickCount();
	}
	else if(dButton && !P1[DOWN].v )
		dButton = false;
	else if( !uButton && !dButton && !bButton && P1[B1].v )
	{
		if(mNum == 0)
		{
			//Guardian->visable = true;

			Val->Main->LoadLevel = false;
			gData->LevelNum = 3;
		}
		else if(mNum == 1)
		{
			Val->Main->LoadLevel = false;
			gData->SubLevelNum = 0;
			gData->LevelNum = 1;
		}
		else if(mNum == 2)
		{
			PostMessage(Val->Main->Get_MainHwnd(), WM_DESTROY, 0, 0);
		}
	}
	else if(!P1[B1].v)
	{
		bButton = false;
	}

//
	return 0;
}
///////////////////////////////////////////////////////
// 	CustomCode
///////////////////////////////////////////////////////
HRESULT CustomCode(void *v, DWORD s)
{
	
	return 0;
}
