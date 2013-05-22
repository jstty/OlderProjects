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
#include "Level001.h"

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
		Display = Val->Display;

		P1 = Val->Controls->Player[0];
		//
		Tile = Display->FindLayer("Tile");

		Win[0] = Display->FindLayer("Win1");

		Win[1] = Display->CopyLayer(Win[0]);
		Win[1]->SetPos(32, 76);

		Win[2] = Display->CopyLayer(Win[0]);
		Win[2]->SetPos(32, 146);

		if(gData->SubLevelNum)
			Title[0] = Display->FindLayer("save_Title1");
		else
			Title[0] = Display->FindLayer("load_Title1");

		Title[0]->Show();

		Title[1] = Display->CopyLayer(Title[0]);
		Title[1]->SetPos(56, 80);
		Title[2] = Display->CopyLayer(Title[0]);
		Title[2]->SetPos(56, 150);

		char S[8];
		Num[0] = Display->CreateCounter(155, 10, 1,		"1");
		Num[1] = Display->CreateCounter(155, 80, 1,		"2");
		Num[2] = Display->CreateCounter(155, 150, 1,	"3");

		if(gData->data != NULL)
		{
			GAME_VAR *tGV = (GAME_VAR *)gData->data;
			gv = *tGV;
		}

		Text[0] = Display->FindLayer("Text1");
		Text[1] = Display->CopyLayer(Text[0]);
		Text[1]->SetPos(45, 102);
		Text[2] = Display->CopyLayer(Text[0]);
		Text[2]->SetPos(45, 172);

		File[0] = Display->FindLayer("File1");
		File[1] = Display->CopyLayer(File[0]);
		File[1]->SetPos(37, 110);
		File[2] = Display->CopyLayer(File[0]);
		File[2]->SetPos(37, 180);

		for(i = 0; i < 3; i++)
		{
			if( Val->Game->CheckFile(i) )
			{
				TempGD[i] = Val->Game->Load(i);
				TempGV[i] = (GAME_VAR *)TempGD[i]->data;

				sprintf(S, "%d", TempGV[i]->char_info[0].level);
				snLvl[i] = Display->CreateCounter(125, 31 + i*70, 2,	S);
				sprintf(S, "%d", TempGV[i]->char_info[1].level);
				rnLvl[i] = Display->CreateCounter(125, 50 + i*70, 2,	S);
				sprintf(S, "%d", TempGV[i]->h);
				hour[i] = Display->CreateCounter(165, 50 + i*70, 3,		S);
				sprintf(S, "%d", TempGV[i]->m);
				min[i] = Display->CreateCounter(215, 50 + i*70, 2,		S);
				sprintf(S, "%d", TempGV[i]->s);
				sec[i] = Display->CreateCounter(255, 50 + i*70, 2,		S);

				Text[i]->visable = true;
			}
			else
				File[i]->visable = true;
		}

		Back = Display->FindLayer("Back");
		Hand = Display->FindLayer("Hand");
		Display->AppendLayer(Hand);

		i = 0;
		mItem[i++] = true;
		mItem[i++] = false;
		mItem[i++] = false;
		mItem[i++] = false;
		End = i - 1;

		i = 0;
		Pos[i].x = 40;	Pos[i++].y = 16;
		Pos[i].x = 40;	Pos[i++].y = 86;
		Pos[i].x = 40;	Pos[i++].y = 156;
		Pos[i].x = 40;	Pos[i++].y = 224;

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

///////////////////////////////////////////////////////
// 	LevelCode
///////////////////////////////////////////////////////
HRESULT LevelCode(void *v, DWORD s)
{
	for(i = 0; i < 3; i++)
	{
		Win[i]->redraw = true;
		Title[i]->redraw = true;
		Num[i]->redraw = true;

		if(File[i]->visable == false)
		{
			Text[i]->redraw = true;
			snLvl[i]->redraw = true;
			rnLvl[i]->redraw = true;
			hour[i]->redraw = true;
			min[i]->redraw = true;
			sec[i]->redraw = true;
		}
		else
			File[i]->redraw = true;
	}

	Hand->redraw = true;
	Back->redraw = true;

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
	else if( !dButton && !uButton && !bButton && P1[B1].v )
	{
		if(mNum < 3)
		{
			if( (!gData->SubLevelNum) && (File[mNum]->visable) )
				Val->Main->Error("No File");
			else if(gData->SubLevelNum)
			{
				Val->Game->Save(mNum);

				Val->Main->LoadLevel = false;
				gData->LevelNum = 3;
				bButton = true;
			}
			else
			{
				gData->LevelNum = TempGV[mNum]->ScreenNum;
				gData->SubLevelNum = TempGV[mNum]->SubScreenNum;

				gData->data = TempGV[mNum];

				Val->Main->LoadLevel = false;
				bButton = true;
			}
			
		}
		else
		{
			if(gData->SubLevelNum)
			{
				Val->Main->LoadLevel = false;
				gData->LevelNum = 3;
				bButton = true;
			}
			else
			{
				Val->Main->LoadLevel = false;
				gData->LevelNum = 0;
				bButton = true;
			}
		}
	}
	else if(!P1[B1].v)
		bButton = false;

	return 0;
}
///////////////////////////////////////////////////////
// 	CustomCode
///////////////////////////////////////////////////////
HRESULT CustomCode(void *v, DWORD s)
{
	
	return 0;
}
