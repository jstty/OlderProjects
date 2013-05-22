//////////////////////////////////////////////////////////////////////////////
// Program Name:  gfx_util.h
// Programmer:    Joseph E. Sutton
// Description:	Graphics Utilities
// Start Date:    06/18/1999
// Last Updated:  10/18/2004
// Version:       2.50
//////////////////////////////////////////////////////////////////////////////
#ifndef _GFX_UTIL_
#define _GFX_UTIL_

class Rect
{
public:
	sInt32 left;
	sInt32 right;
	sInt32 top;
	sInt32 bottom;
	
	sInt32 GetWidth() { return right - left; }
	sInt32 GetHeight() { return bottom - top; }
	sInt32 GetX() { return left; }
	sInt32 GetY() { return top; }
};

inline bool CheckOnScreen(Rect r, sInt32 xMax, sInt32 yMax)
{
	if( (r.right > 0) &&
		 (r.bottom > 0) &&
		 (r.left < xMax) &&
		 (r.top < yMax) )
		return 1;

return 0;
}

inline bool RectOverRect(Rect r1, Rect r2)
{
	if( (r1.right  > r2.left)  &&
		 (r1.bottom > r2.top)   &&
		 (r1.left   < r2.right) &&
		 (r1.top    < r2.bottom) )
		return 1;

return 0;
}

inline bool PointInRect(Rect r, sInt32 x, sInt32 y)
{
	if( (r.right  > x) &&
		 (r.bottom > y) &&
		 (r.left   < x) &&
		 (r.top    < y) )
		return 1;

return 0;
}

inline bool CheckOnScreen(sInt32 r[4], sInt32 xMax, sInt32 yMax)
{
	if( (r[2] > 0) && (r[3] > 0) && (r[0] < xMax) && (r[1] < yMax) )
		return 1;

return 0;
}

inline bool RectOverRect(sInt32 r1[4], sInt32 r2[4])
{
	if( (r1[2] > r2[0]) &&
		 (r1[3] > r2[1]) &&
		 (r1[0] < r2[2]) &&
		 (r1[1] < r2[3]) )
		return 1;

return 0;
}

inline bool PointInRect(sInt32 r[4], sInt32 x, sInt32 y)
{
	if( (r[2] > x) &&
		 (r[3] > y) &&
		 (r[0] < x) &&
		 (r[1] < y) )
		return 1;

return 0;
}

// or macro
#define ONSCREEN(A, B, C, D, SCREEN_W, SCREEN_H) ((A > 0) && (B > 0) && (C < SCREEN_W) && (D < SCREEN_H))

#define ONSCREEN_RECT(R, SCREEN_W, SCREEN_H) ((R.right > 0) && (R.bottom > 0) && (R.left < SCREEN_W) && (R.top < SCREEN_H))

#define IN_RECT(R1, R2) ((R1.right > R2.left) && (R1.bottom > R2.top) && (R1.left < R2.right) && (R1.top < R2.bottom))

#define POINT_IN_RECT(R, x, y) ((R.right > x) && (R.bottom > y) && (R.left < x) && (R.top < y))

#endif