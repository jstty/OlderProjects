////////////////////////////////////////////////////////////////////////
//	Program Name:	ErrorClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Error Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _ERRORCLASS
#define _ERRORCLASS

#include <stdio.h>
#include <stdarg.h>
#include <windows.h>

#define ETYPE_OK		0
#define ETYPE_YESNO	1
#define ETYPE_RETRY	2

class ERRORCLASS
{
	private:
		char							*MsgFormat;
		char							*PrevMsgFormat;
		unsigned int			Type:2;
		HWND							hWnd;
		//
		int GetType(int t)
		{
			if(Type == ETYPE_OK)
				return MB_OK;
			else if(Type == ETYPE_YESNO)
				return MB_YESNO;
			else if(Type == ETYPE_RETRY)
				return MB_RETRYCANCEL;
			else
				return MB_OK;
		};
//
	public:
		void InitError(void)
		{
			MsgFormat = NULL;
			PrevMsgFormat = NULL;
			SetError_Format();
			Type = ETYPE_OK;
			hWnd = GetDesktopWindow();
		}
		//
		unsigned __int32 Get_Type(void){ return Type; };
		void SetError_Type(unsigned int t = 0){ Type = t; };
	//
		HWND Get_hWnd(void){ return hWnd; };
		void Set_hWnd(HWND h){ hWnd = h; };
	//
		char *Get_MsgFormat(void){ return MsgFormat; };
		void	SetError_Format(unsigned __int8 n = 0)
		{
			if(MsgFormat != NULL)
			{
				PrevMsgFormat = new char[strlen(MsgFormat)];
				strcpy(PrevMsgFormat, MsgFormat);
			}

			char Temp[64];
						if(n == 0)	strcpy(Temp, "Class: %s\nFunction: %s\nError: %d");
			else	if(n == 1)	strcpy(Temp, "Class:%s || Function:%s || Error:%d");
			else	if(n == 2)	strcpy(Temp, "Class:\"%s\" || Function:%s || Error:%d");
			else	if(n == 3)	strcpy(Temp, "%s::%s || Error = %d");
			else							strcpy(Temp, "Error - %s %s(%d)");

			MsgFormat = new char[strlen(Temp)];
			strcpy(MsgFormat, Temp);
		};
		//
		void	SetError_Format(char *m)
		{
			if(MsgFormat != NULL)
			{
				PrevMsgFormat = new char[strlen(MsgFormat)];
				strcpy(PrevMsgFormat, MsgFormat);
			}

			if(m != NULL)
			{
				MsgFormat = new char[strlen(m)];
				strcpy(MsgFormat, m);
			}
			else
			{
				MsgFormat = new char[2];
				strcpy(MsgFormat, "");
			}
		};
		//
		bool ReSetError_Format(bool n = 0)
		{
			if(PrevMsgFormat != NULL)
			{
				MsgFormat = new char[strlen(PrevMsgFormat)];
				strcpy(MsgFormat, PrevMsgFormat);
			}
			return n;
		};
	//
		bool Error(char *m, ...)
		{
			char		mTemp[256];
			va_list	vl;

			if(m != NULL)
			{
				if(MsgFormat != NULL)
				{
					PrevMsgFormat = new char[strlen(MsgFormat)];
					strcpy(PrevMsgFormat, MsgFormat);
				}

				MsgFormat = new char[strlen(m)];
				strcpy(MsgFormat, m);
			}

			if(MsgFormat != NULL)
			{
				if(strlen(MsgFormat) > 0)
				{
					va_start(vl, m);
					vsprintf(mTemp, MsgFormat, vl);
					va_end(vl);
				}
				else
					strcpy(mTemp, "Problem with error message.");
			}
			else
				return 1;

			if(Type < 0)
				Type = 0;
			
			if(hWnd == NULL)
				hWnd = GetDesktopWindow();

			int Ok = MessageBox(hWnd, mTemp, "Error", GetType(Type) | MB_SYSTEMMODAL );

			if( (Ok == IDOK ) || ( Ok == IDNO ) || ( Ok == IDCANCEL ) )
				return 1;
			else
				return 0;
		};
	//
		bool ErrorMsg(char *Format, ...)
		{
			char		mTemp[256];
			va_list	vl;

			if(Format != NULL)
			{
				if(MsgFormat != NULL)
				{
					PrevMsgFormat = new char[strlen(MsgFormat)];
					strcpy(PrevMsgFormat, MsgFormat);
				}

				MsgFormat = new char[strlen(Format)];
				strcpy(MsgFormat, Format);
			}
							
			va_start(vl, Format);
			vsprintf(mTemp, MsgFormat, vl);
			va_end(vl);
			
			int Ok = MessageBox(GetDesktopWindow(), mTemp, "Error", GetType(Type));

			strcpy(MsgFormat, PrevMsgFormat);

			if( (Ok == IDOK ) || ( Ok == IDNO ) || ( Ok == IDCANCEL ) )
				return 1;
			else
				return 0;
		};
	//
		bool ErrorMsgEx(HWND h, int type, char *mFormat, ...)
		{
			char		mTemp[256];
			va_list	vl;

			if(h != NULL)
				hWnd = h;
			else if( (h == NULL) && (hWnd == NULL) )
				hWnd = GetDesktopWindow();

			if(mFormat != NULL)
			{
				if(MsgFormat != NULL)
				{
					PrevMsgFormat = new char[strlen(MsgFormat)];
					strcpy(PrevMsgFormat, MsgFormat);
				}

				MsgFormat = new char[strlen(mFormat)];
				strcpy(MsgFormat, mFormat);
			}

			va_start(vl, MsgFormat);
			vsprintf(mTemp, MsgFormat, vl);
			va_end(vl);

			if(type >= 0)
				Type = type;
			
			if(Type < 0)
				Type = 0;
			
			int Ok = MessageBox(GetDesktopWindow(), mTemp, "Error", GetType(Type));

			if( (Ok == IDOK ) || ( Ok == IDNO ) || ( Ok == IDCANCEL ) )
				return 1;
			else
				return 0;
		};
/*
		bool Post(int v1 = 0, int v2 = 0, char *s = NULL, char *m = NULL, char *t = NULL, int type = -1)
		{
			if(m != NULL)
				strcpy(MsgFormat, m);
			else if( (m == NULL) && (MsgFormat == NULL) )
				return 1;

			if(t != NULL)
				strcpy(TileFormat, t);
			else if( (t == NULL) && (TileFormat == NULL) )
				return 1;

			if(v1 != 0)
				e1 = v1;

			if(v2 != 0)
				e2 = v2;

			if(s != NULL)
				strcpy(Msg, s);
			else if( (s == NULL) && (Msg == NULL) )
				return 1;

			if(type >= 0)
				Type = type;

			if(hWnd == NULL)
				hWnd = GetDesktopWindow();

			sprintf(TempMsg, MsgFormat, Msg, e1, e2);
			sprintf(TempTitle, TileFormat, e1, e2, Msg);

			MessageBox(hWnd, 	TempMsg, TempTitle, GetType(Type) );

			return 0;
		}
*/
//
//
		/*
		char *ConvertFormat(char *s, char *t)
		{
			char *m;
			unsigned __int8 mNum = 0;
			int *List[1];
			unsigned __int8 ListNum = 0;
			int l = strlen(s);
			
			if(s != NULL)
			{
				for(int i = 0; i < l; i++)
				{
					if(s[i] == '%')
					{
						i++;
						if(s[i] == 's')
						{
							m = Msg;
							ListNum++;
							mNum = ListNum;
						}
						else if(s[i] == 'a')
						{
							s[i] = 'd';
							List[ListNum] = (int *)e1;
							ListNum++;
						}
						else if(s[i] == 'b')
						{
							s[i] = 'd';
							List[ListNum] = (int *)e2;
							ListNum++;
						}
						else
							return NULL;
					}
				}
				
				if(t != NULL)
				{
					if(				(mNum == 0) && (ListNum == 1) )	sprintf(t, s, *List[0]);
					else if(	(mNum == 0) && (ListNum == 2) )	sprintf(t, s, *List[0], *List[1]);
					else if(	(mNum == 0) && (ListNum == 3) )	sprintf(t, s, *List[0], *List[1], *List[2]);
					//
					else if(	(mNum == 1) && (ListNum == 1) )	sprintf(t, s, m, *List[0]);
					else if(	(mNum == 1) && (ListNum == 2) )	sprintf(t, s, m, *List[0], *List[1]);
					else if(	(mNum == 1) && (ListNum == 3) )	sprintf(t, s, m, *List[0], *List[1], *List[2]);
					//
					else if(	(mNum == 2) && (ListNum == 1) )	sprintf(t, s, *List[0], m);
					else if(	(mNum == 2) && (ListNum == 2) )	sprintf(t, s, *List[0], m, *List[1]);
					else if(	(mNum == 2) && (ListNum == 3) )	sprintf(t, s, *List[0], m, *List[1], *List[2]);
					//
					else if(	(mNum == 3) && (ListNum == 2) )	sprintf(t, s, *List[0], *List[1], m);
					else if(	(mNum == 3) && (ListNum == 3) )	sprintf(t, s, *List[0], *List[1], m, *List[2]);
					//
					else if(	(mNum == 4) && (ListNum == 3) )	sprintf(t, s, *List[0], *List[1], *List[2], m);
					else	return NULL;
				}
				return t;
			}

			return NULL;
		}
		*/

/*
		//
		bool Post(HWND h = NULL)
		{
			char TempMsg[128];
			char TempTitle[128];
			int MessageType = MB_OK;

			if(h != NULL)
				hWnd = h;
			else if( (h == NULL) && (hWnd == NULL) )
				return 1;

			vsprintf(TempMsg, MsgFormat, vaMsg);
			vsprintf(TempTitle, TileFormat, vaTile);

			if(Type == ETYPE_OK)
				MessageType = MB_OK;
			else if(Type == ETYPE_YESNO)
				MessageType = MB_YESNO;
			else if(Type == ETYPE_RETRY)
				MessageType = MB_RETRYCANCEL;

			MessageBox(hWnd, TempMsg, TempTitle, MessageType);

			va_end(vaTile);
			va_end(vaMsg);
			return 0;
		};
//
		bool PostMsg(char *m, ...)
		{
			char TempMsg[128];
			va_list   vl;
			int MessageType = 0;

			if(strlen(m) > 0)
				strcpy(MsgFormat, m);
			else
				return 1;

			if(hWnd == NULL)
				return 1;

			va_start(vl, MsgFormat);
			vsprintf(TempMsg, MsgFormat, vl);

			if(Type == ETYPE_OK)
				MessageType = MB_OK;
			else if(Type == ETYPE_YESNO)
				MessageType = MB_YESNO;
			else if(Type == ETYPE_RETRY)
				MessageType = MB_RETRYCANCEL;

			MessageBox(hWnd, TempMsg, "Error", MessageType);

			va_end(vl);
			return 0;
		};
*/
//
		//		void PostError(long msg = 0, char *Title = NULL, char *Des = NULL);
};

#endif
