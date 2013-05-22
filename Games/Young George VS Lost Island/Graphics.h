////////////////////////////////////////////////////////////////////////
//	Program Name:	Graphics.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Graphics header File
//	Date: 
////////////////////////////////////////////////////////////////////////

		//	CompileBitmap only compiles a new bitmap 
		//	from an array of bitmaps whitch it then returns.
DllExport HDC CompileBitmap(HWND hwnd, LPLEVEL level);
		//	CompileSprite only compiles a new bitmap
		//	from an array of bitmaps and a bitmap whitch it then return.
DllExport void CompileSprite(HWND hwnd, HDC origBkgHdc, LPLEVEL level);
		//	DisplayBG simply displays a bitmap.
DllExport HDC DisplayBG(HWND hwnd, HDC bitmap);
		//	CheckPath gets a point from the given bitmap, 
		//	checks to see if it is path or not and returns the result.
DllExport BOOL CheckPath(HWND hwnd, LPLEVEL level, UINT spriteNum, UINT msg, int dS);
		// zOrderSort
void zOrderSort(LPLEVEL level);
		// Checks for Collision
//void CheckCollision(HDC hdcBkg, HDC hdcM, LPSPRITEARRAY	spriteA[], UINT spriteNum);

