////////////////////////////////////////////////////////////////////////
//	Program Name:	Level???.cpp
//	Programmer:		Joseph E Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Level File
//	Date: 
////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include "Level000.h"

#include "math.h"

int Rand(int start, int end)
{
	int a = rand();
	return start + (a%(end - start + 1));
}

int LoopCount;

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

		P1 = Val->Controls->Player[0];
		cInfo = &Val->Controls->Mouse;
		cSprite = Val->Display->Mouse;
		Display = Val->Display;
		//

		r.left = 40;
		r.top = 59;
		r.right = r.left + 156;
		r.bottom = r.top + 17;

/*
		unsigned __int8 i = 0;
		Logo = &Val->Display->Layer[i++];

		Star1 = &Val->Display->Layer[i++];
		Star2 = &Val->Display->Layer[i++];
		TempStar = NULL;

		Title = &Val->Display->Layer[i++];

		GrayBkg = &Val->Display->Layer[i++];

		Bossman		=	&Val->Display->Layer[i++];
		Hogan			=	&Val->Display->Layer[i++];
		Andre			=	&Val->Display->Layer[i++];
		Warrior		=	&Val->Display->Layer[i++];
		Honky			=	&Val->Display->Layer[i++];
		Savage		=	&Val->Display->Layer[i++];
		Ted				=	&Val->Display->Layer[i++];
		Jim				=	&Val->Display->Layer[i++];

		Select1	= &Val->Display->Layer[i++];
		Select2	= &Val->Display->Layer[i++];

		Ring	= &Val->Display->Layer[i++];
		rHonky	= &Val->Display->Layer[i++];

		Rope1	= &Val->Display->Layer[i++];
		Rope2	= &Val->Display->Layer[i++];
		Rope3	= &Val->Display->Layer[i++];

		TempChar = NULL;
		
		Level = 4;
		LoopCount = 0;

		TempChar = Star1;
		TempChar->anim_done = true;
*/

		return 0;
}



///////////////////////////////////////////////////////
// 	LevelCode
///////////////////////////////////////////////////////
HRESULT LevelCode(void *v, DWORD s)
{
	if(Display->UseMouse)
	{
		cSprite->draw = !cInfo->show;
		cSprite->SetPos(cInfo->x, cInfo->y);
	}

	if(  )
	{
		Val->Main->LoadLevel = false;
		Val->Main->LevelNum = 1;
	}
/*
	if( (Level == 1) && (Logo->anim_done) )
	{
		//Logo->SetType(LT_IMAGE);
		Logo->visable = true;
		Logo->animate = false;

		Title->Show();

		LoopCount = 0;
		Level = 2;
		return 0;
	}
	else if( (Level == 1) && ( P1[B1].v ) )
	{
		Logo->JumptoLastCel();
		//Logo->SetType(LT_IMAGE);
		Logo->visable = true;
		Logo->animate = false;

		Title->Show();

		LoopCount = 0;
		Level = 2;
		return 0;
	}
	else if( (Level == 2) && (!P1[B1].v) )
	{
		if(LoopCount == 0)
		{
			// Start Star
			x = Rand(0, 1);

			if(x)
				TempStar = Star2;
			else
				TempStar = Star1;
			
			x = Rand(35, 295);
			y = Rand(10, 165);

			TempStar->SetPos(x, y);
			TempStar->Show();
			LoopCount++;
		}
		else
		{
			if(TempStar->anim_done)
			{
				TempStar->Hide();

				x = Rand(0, 1);

				if(x)
					TempStar = Star2;
				else
					TempStar = Star1;

				TempStar->anim_done = false;
				TempStar->Show();
			
				x = Rand(35, 295);
				y = Rand(20, 165);
			
				TempStar->SetPos(x, y);
			}
		}

	}
	else if( (Level == 2) && ( P1[B1].v ) )
	{
		Logo->animate = false;
		Logo->visable = false;
		
		Title->visable = false;

		Star1->animate = false;
		Star1->visable = false;
		Star2->animate = false;
		Star2->visable = false;

		GrayBkg->Show();
		Select1->Show();

		Selection = 1;
		SelChanged = true;
		ButtonType = B1;
		ButtonPressed = true;
		P1_Selected	 = false;
		NoSelect = 0;

		StartTime = GetTickCount();
		WaitTime = 5000;

		Level = 3;
		return 0;
	}
	else if(Level == 3)
	{
		if( (GetTickCount() - StartTime) > WaitTime)
		{
			StartTime = GetTickCount();
			
			// type Vert or Horz
			tAutoSel = Rand(1, 2);
			// Direction + or -
			dAutoSel = Rand(1, 2);

			WaitTime = Rand(1, 100);
			if(WaitTime < 75)
			{
				if(tAutoSel > 1)
				{
					if(Selection == 1)
						Selection = 5;
					else if(Selection == 2)
						Selection = 6;
					else if(Selection == 3)
						Selection = 7;
					else if(Selection == 4)
						Selection = 8;
					else if(Selection == 5)
						Selection = 1;
					else if(Selection == 6)
						Selection = 2;
					else if(Selection == 7)
						Selection = 3;
					else if(Selection == 8)
						Selection = 4;

					if(Selection == NoSelect)
					{
						if(Selection == 1)
							Selection = 5;
						else if(Selection == 2)
							Selection = 6;
						else if(Selection == 3)
							Selection = 7;
						else if(Selection == 4)
							Selection = 8;
						else if(Selection == 5)
							Selection = 1;
						else if(Selection == 6)
							Selection = 2;
						else if(Selection == 7)
							Selection = 3;
						else if(Selection == 8)
							Selection = 4;
					}

					SelChanged = true;
				}
				else
				{
					if(dAutoSel > 1)
					{
						if( (Selection != 4) && (Selection != 8) )
							Selection++;
						else if(Selection == 4)
							Selection = 1;
						else if(Selection == 8)
							Selection = 5;

						if(Selection == NoSelect)
						{
							if( (Selection != 4) && (Selection != 8) )
								Selection++;
							else if(Selection == 4)
								Selection = 1;
							else if(Selection == 8)
								Selection = 5;
						}

						SelChanged = true;
					}
					else
					{
						if( (Selection != 1) && (Selection != 5) )
							Selection--;
						else if(Selection == 1)
							Selection = 4;
						else if(Selection == 5)
							Selection = 8;

						if(Selection == NoSelect)
						{
							if( (Selection != 1) && (Selection != 5) )
								Selection--;
							else if(Selection == 1)
								Selection = 4;
							else if(Selection == 5)
								Selection = 8;
						}

						SelChanged = true;
					}
				}
			}
			
			else
			{
				SelChanged = false;
				ButtonPressed = false;
				P1[B1].v = true;
			}
			
			WaitTime = 400;
		}

		if(TempChar == NULL)
		{
			if( (P1[B1].v) && (!SelChanged) && (!ButtonPressed) )
			{
				if(Selection == 1)
					TempChar = Bossman;
				else if(Selection == 2)
					TempChar = Hogan;
				else if(Selection == 3)
					TempChar = Andre;
				else if(Selection == 4)
					TempChar = Warrior;
				else if(Selection == 5)
					TempChar = Honky;
				else if(Selection == 6)
					TempChar = Savage;
				else if(Selection == 7)
					TempChar = Ted;
				else if(Selection == 8)
					TempChar = Jim;

				TempChar->Show();

				if(P1_Selected)
				{
					Select2->Hide();
				
					Level = 4;
					return 0;
				}

				return 0;
			}

			if( (P1[RIGHT].v) && (!SelChanged) && (!ButtonPressed) )
			{
				StartTime = GetTickCount();

				if( (Selection != 4) && (Selection != 8) )
					Selection++;
				else if(Selection == 4)
					Selection = 1;
				else if(Selection == 8)
					Selection = 5;
				
				if(Selection == NoSelect)
				{
					if( (Selection != 4) && (Selection != 8) )
						Selection++;
					else if(Selection == 4)
						Selection = 1;
					else if(Selection == 8)
						Selection = 5;
				}

				SelChanged = true;

				ButtonType = RIGHT;
				ButtonPressed = true;
			}
			else	if( (P1[LEFT].v) && (!SelChanged) && (!ButtonPressed) )
			{
				StartTime = GetTickCount();

				if( (Selection != 1) && (Selection != 5) )
					Selection--;
				else if(Selection == 1)
					Selection = 4;
				else if(Selection == 5)
					Selection = 8;

				if(Selection == NoSelect)
				{
					if( (Selection != 1) && (Selection != 5) )
						Selection--;
					else if(Selection == 1)
						Selection = 4;
					else if(Selection == 5)
						Selection = 8;
				}

				SelChanged = true;

				ButtonType = LEFT;
				ButtonPressed = true;
			}
			else	if( ((P1[UP].v) || (P1[DOWN].v)) && (!SelChanged) && (!ButtonPressed) )
			{
				StartTime = GetTickCount();

				if(Selection == 1)
					Selection = 5;
				else if(Selection == 2)
					Selection = 6;
				else if(Selection == 3)
					Selection = 7;
				else if(Selection == 4)
					Selection = 8;
				else if(Selection == 5)
					Selection = 1;
				else if(Selection == 6)
					Selection = 2;
				else if(Selection == 7)
					Selection = 3;
				else if(Selection == 8)
					Selection = 4;

				if(Selection == NoSelect)
				{
					if(Selection == 1)
						Selection = 5;
					else if(Selection == 2)
						Selection = 6;
					else if(Selection == 3)
						Selection = 7;
					else if(Selection == 4)
						Selection = 8;
					else if(Selection == 5)
						Selection = 1;
					else if(Selection == 6)
						Selection = 2;
					else if(Selection == 7)
						Selection = 3;
					else if(Selection == 8)
						Selection = 4;
				}

				SelChanged = true;

				if(P1[UP].v)
					ButtonType = UP;
				else if(P1[DOWN].v)
					ButtonType = DOWN;
				ButtonPressed = true;
			}
			else if( (ButtonPressed) && (!P1[ButtonType].v) ) 
			{
				ButtonPressed = false;
			}
			else if(SelChanged)
			{
				if(!P1_Selected)
				{
					if(Selection == 1)
						Select1->SetPos(7, 17);
					else if(Selection == 2)
						Select1->SetPos(87, 1);
					else if(Selection == 3)
						Select1->SetPos(167, 1);
					else if(Selection == 4)
						Select1->SetPos(247, 17);
					else if(Selection == 5)
						Select1->SetPos(7, 121);
					else if(Selection == 6)
						Select1->SetPos(87, 138);
					else if(Selection == 7)
						Select1->SetPos(167, 138);
					else if(Selection == 8)
						Select1->SetPos(247, 121);
				}
				else
				{

				if(Selection == 1)
					Select2->SetPos(7, 17);
				else if(Selection == 2)
					Select2->SetPos(87, 1);
				else if(Selection == 3)
					Select2->SetPos(167, 1);
				else if(Selection == 4)
					Select2->SetPos(247, 17);
				else if(Selection == 5)
					Select2->SetPos(7, 121);
				else if(Selection == 6)
					Select2->SetPos(87, 138);
				else if(Selection == 7)
					Select2->SetPos(167, 138);
				else if(Selection == 8)
					Select2->SetPos(247, 121);

				}

				SelChanged = false;
			}
		}
		else
		{
			if(TempChar->anim_done)
			{
				P1_Selected = true;
				NoSelect = Selection;

				ButtonType = B1;
				ButtonPressed = true;
				
				Select1->Hide();

				TempChar->JumpToCel(2);
				Logo->visable = true;
				Logo->animate = false;
				
				TempChar = NULL;

				// move cursor
				SelChanged = true;
				Selection++;

				if(Selection == 5)
					Selection = 1;
				else if(Selection == 9)
					Selection = 5;

				if(Selection == 1)
					Select2->SetPos(7, 17);
				else if(Selection == 2)
					Select2->SetPos(87, 1);
				else if(Selection == 3)
					Select2->SetPos(167, 1);
				else if(Selection == 4)
					Select2->SetPos(247, 17);
				else if(Selection == 5)
					Select2->SetPos(7, 121);
				else if(Selection == 6)
					Select2->SetPos(87, 138);
				else if(Selection == 7)
					Select2->SetPos(167, 138);
				else if(Selection == 8)
					Select2->SetPos(247, 121);

				Select2->Show();
			}			
		}
	}
	else if( (Level == 4) && (TempChar->anim_done) )
	{
		GrayBkg->visable = false;
		Select2->visable = false;

		if(Bossman->visable)
			Bossman->visable = false;
		if(Hogan->visable)
			Hogan->visable = false;
		if(Andre->visable)
			Andre->visable = false;
		if(Warrior->visable)
			Warrior->visable = false;
		if(Honky->visable)
			Honky->visable = false;
		if(Savage->visable)
			Savage->visable = false;
		if(Ted->visable)
			Ted->visable = false;
		if(Jim->visable)
			Jim->visable = false;

		Logo->visable = false;

		Ring->Show();
		Ring->Move();
		Ring->SetPos(-200, -200);

		rHonky->Show();
//		rHonky->Move();
		rHonky->SetPos( -200, -150);

		Rope1->Show();
		Rope1->Move();
		Rope1->SetPos(-200, -200);

		Rope2->Show();
		Rope2->Move();
		Rope2->SetPos(-200, -200);

		Rope3->Show();
		Rope3->Move();
		Rope3->SetPos(-200, -200);

		Level++;
	}
*/

	return 0;
}
///////////////////////////////////////////////////////
// 	CustomCode
///////////////////////////////////////////////////////
HRESULT CustomCode(void *v, DWORD s)
{
	
	return 0;
}
