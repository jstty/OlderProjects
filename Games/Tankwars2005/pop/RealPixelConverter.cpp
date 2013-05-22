#include <stdafx.h>
#include "realpixelconverter.h" //Log and comments are in the header.
#include "realbox.h" //for cRealBox

BOOL RealCLAMP(Real &x, Real lo, Real hi)
{
	Real oldx = x;
	CLAMP(x,lo,hi);
	return x!=oldx;
}

cRealPixelConverter::cRealPixelConverter(Real radiusx, Real radiusy)
{
	_changed_size_flag = TRUE;
	_fixed_aspect_flag = TRUE;
	if (!radiusx)
		radiusx = SMALL_REAL;
	if (!radiusy)
		radiusy = SMALL_REAL; //Never allow zeroes.
	_realradiusx = radiusx;
	_realradiusy = radiusy;
	_realcenterx = _realcentery = 0.0; //Default center at origin.
/* Force some numbers in to be safe, though normally you'll
call setPixelWindow again in the initial WM_SIZE with
the actual size of your active window. */
	setPixelWindow(800, 600);
}

void cRealPixelConverter::_fixup_constants()
{ /* Precompute the four constants used in realToPixel and
turn on the _changed_size_flag so that anyone using this cRealPixelConverter
object will know that any realToPixel computation results they've
stored must now be redone. */
	Real realwindowaspect = height()/width(); 
	Real pixelwindowaspect = Real(_cy)/_cx;
	_realpixperx = Real(_midx-_left)/_realradiusx;
	_realpixpery = Real(_midy-_top)/_realradiusy;
	if (_fixed_aspect_flag)
	{
		if (_realpixperx < _realpixpery)
			_realpixpery = _realpixperx;
		else
			_realpixperx = _realpixpery;
	}
	_constx = _midx - _realcenterx * _realpixperx;
	_consty = _midy + _realcentery * _realpixpery;
	_changed_size_flag = TRUE;
}

void cRealPixelConverter::setPixelWindow(int cx, int cy)
{
	_left = 0; _top = 0; _right = cx; _bottom = cy;
	_cx = cx;
	_cy = cy;
	_midx = cx/2;
	_midy = cy/2;
	if (!_midx)
		_midx = 1;
	if (!_midy)
		_midy = 1; //Do this so _realpixperx can't be 0 in pixelToReal.
	_fixup_constants();
}

void cRealPixelConverter::setPixelWindow(int left, int top, int right, int bottom)
{
	_left = left; _top = top; _right = right; _bottom = bottom;
	_cx = _right - _left;
	_cy = _bottom - _top;
	_midx = _left + _cx/2;
	_midy = _top + _cy/2;
	if (!_midx)
		_midx = 1;
	if (!_midy)
		_midy = 1; //Do this so _realpixperx can't be 0 in pixelToReal.
	_fixup_constants();
}

void cRealPixelConverter::setFixedAspect(BOOL truefalse)
{
	_fixed_aspect_flag = truefalse;
	_fixup_constants();
}

void cRealPixelConverter::setRealWindow(Real lox, Real loy, Real hix, Real hiy)
{
	_realcenterx = (lox + hix) / 2.0; //Average the values
	_realcentery = (loy + hiy) / 2.0; //Average to get the center.
	_realradiusx = hix - _realcenterx;
	_realradiusy = hiy - _realcentery;
	if (!_realradiusx)
		_realradiusx = SMALL_REAL;
	if (!_realradiusy)
		_realradiusy = SMALL_REAL;
	_fixup_constants();
}

void cRealPixelConverter::setRealWindow(const cRealBox &box)
{
	setRealWindow(box.lox(), box.loy(), box.hix(), box.hiy());
}


void cRealPixelConverter::realToPixel(Real rx, Real ry, int *ix, int *iy) const
{ /*Designed to match the centers of the 2 windows even if
_fixed_aspect_flag.  Originally, we had the more obvious
	tempx = _midx + (rx - _realcenterx) * (_midx/_realradiusx);
	tempy = _midy - (ry - _realcentery) * (_midy/_rearadiusy);
To speed it up, we precompute _midx/_realradiusx
as _realpixperx and we precompute 
_midx -_realcenterx*_realpixperx as constx, so now
tempx = constx + rx*_realpixperx.  Note that you have
to recompute these constants whenever you change the window
sizes. Another thing we do here is to not allow integers
that might overflow a thirty-two bit register. */
	Real tempx, tempy;
	tempx = _constx + rx * _realpixperx;
	tempy = _consty - ry * _realpixpery;
/* I use VERIFY here and not ASSERT.  In the Debug mode, if either a VERIFY or
an ASSERT line fails, the program halts with a message.  In the Release mode,
an ASSERT line is ignored.  In the Release mode, a VERIFY line is executed,
which I want here for safety, but the program is NOT interrupted if the 
check fails, which is also what I want. */
#define WARNOVERFLOW
#ifdef WARNOVERFLOW
	VERIFY(!RealCLAMP(tempx, - INTEGER_OVERFLOW, INTEGER_OVERFLOW));
	VERIFY(!RealCLAMP(tempy, - INTEGER_OVERFLOW, INTEGER_OVERFLOW));
#else //Just do the check and don't worry about warning.
	RealCLAMP(tempx, - INTEGER_OVERFLOW, INTEGER_OVERFLOW);
	RealCLAMP(tempy, - INTEGER_OVERFLOW, INTEGER_OVERFLOW);
#endif
	*ix = (int)tempx;
	*iy = (int)tempy;
}

void cRealPixelConverter::realToInt(Real rx, int *ix) const
{ 
	Real tempx;
	tempx = rx * __min(_realpixperx, _realpixpery);
//See note on VEFIFY above.
	VERIFY(!RealCLAMP(tempx, - INTEGER_OVERFLOW, INTEGER_OVERFLOW));
	*ix = (int)tempx;
}

void cRealPixelConverter::realToIntAnisotropic(Real rx, int *ix, int *iy) const
{ 
	Real tempx, tempy;
	tempx = rx * _realpixperx;
	tempy = rx * _realpixpery;
//See note on VEFIFY above.
	VERIFY(!RealCLAMP(tempx, - INTEGER_OVERFLOW, INTEGER_OVERFLOW));
	*ix = (int)tempx;
	*iy = (int)tempy;
}

void cRealPixelConverter::pixelToReal( int ix, int iy, Real *rx, Real *ry) const
{

	*rx = ((Real)(ix - _midx)/_realpixperx) + _realcenterx;
	*ry = ((Real)(_midy - iy)/_realpixpery) + _realcentery;
}

void cRealPixelConverter::intToReal(int ix, Real *rx) const
{ 
	*rx = Real(ix) / __max(_realpixperx, _realpixpery);
}

void cRealPixelConverter::zoom(Real newcenterx, Real newcentery, Real zoomfactor)
{
	_realcenterx = newcenterx;
	_realcentery = newcentery;
	_realradiusx *= zoomfactor;
	_realradiusy *= zoomfactor;
	_fixup_constants();
}

void cRealPixelConverter::zoomAtPixel(int pixx, int pixy, Real zoomfactor)
{
	Real newcenterx, newcentery;
	pixelToReal(pixx, pixy, &newcenterx, &newcentery);
	zoom(newcenterx, newcentery, zoomfactor);
}
