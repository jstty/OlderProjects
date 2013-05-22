#ifndef REALPIXELCONVERTER_HPP
#define REALPIXELCONVERTER_HPP
/*----Log
Created September 26, 1995
October 5, 1995. Changed max? names to c? names.  Added changed_size_flag
flag in case you have a program that uses realpixelconverter to compute and
store a lot of pixel/real info; the status of the changed_size_flag
tells the program when it needs to recompute its pixel/real info.
October 9, 1995.  Added PixelToReal and two Zoom methods.
Feb 7, 1996 Temporarily changed RealToPixel and PixelToReal to
use pass by reference.  This change was later removed as it 
did not work reliably.  Added _fixedaspect switch to toggle 
between isometric mode and fill-the-whole-window mode.
December 13, 1997.  Re-edited and cleaned up comments.  Added
the private _fixup_constants function to avoid code duplication.
June 21, 1999.  Changed the name of the class from the former 
"Frame" to the new "cRealPixelConverter".
July 26, 1999.  Added a feature that has the converter effectively rotate
the RealWindow to have its loger direction in the same direction as the longer
direction of the pixelview. _autorotate_flag
July 23, 1999.  Added the _forcerotate_flag so one view can slave its rotation to
another view, could be useful to match a subsidiary view to a main view.  I've
never actually used this flag so I can't be sure it really works.
August 9, 1999.  Enclosed the CLAMP checks inside an ASSERT, so that they are
turned off in the release build for better speed.  The CLAMP checks are to 
prevent a real from being converted into an integer so large that it wraps around
and appears negative.  This is not going to happen in simple 2D programs, but it
is a risk when you use a cRealPixelConverter in a 3D program where you are
projecting objects onto a plane; an object close to a projection point can
project out arbitrarily far onto a plane.  Even here, though it will be better
to risk not doing the check in the Release build.  Instead you should catch the
problem in a Debug buidl and prevent it form happening, e.g. by using a clip
plane to not process an object that's too close to the projection point. 
-----Usage
(1) Put "#include realpixelconverter.h" before using the class.
(2) Put cRealPixelConverter _realpixelconverter; as a global variable in your Windows32 program.  In MFC, have it as a member of your CView class.
(3) Use _realpixelconverter.setRealWindow(Real lox,Real loy,Real hix,Real hiy);
	to change Real window box if desired.  In Windows32, do this in 
	WM_CREATE; in MFC do it in CView::OnCreate.  You can change it
	again as a result of user input later on, i.e. for panning or zooming.
(4) Put realpixelconverter.setPixelWindow(LOWORD(lParam), HIWORD(lParam)); in	WM_SIZE in Windows 32.  In MFC, put the following line in CView::OnSize.
	_realpixelconverter.setPixelWindow(cx, cy); This adjusts _cx and _cy to 
	match current pixel window size.
(5) Use _realpixelconverter.realToPixel(rx, ry, &ix, &iy)
	to convert Real (rx, ry) to int (ix, iy).
(6) Use _realpixelconverter.pixelToReal(int ix, int iy, Real &rx, Real &ry)
	to convert int (ix, iy) [e.g. from a mouse click] to  Real (rx, ry).
(7) Use _realpixelconverter.zoomAtPixel(int pixx, int pixy, Real zoomfactor); to
	zoom in or out at a given mouseclick point.  zoomfactor > 1.
	0 makes image smaller, zoomfactor < 1.0 makes image bigger.
(8) Use _realpixelconverter.setFixedAspect(TRUE) to keep circles from changing
	to ellipses as you resize Pixel window.  In this case the 
	Pixel window stays centered on the center, and there may be some
	unused areas of the onscreen window at the edges.  Use FALSE to keep
	things 	fixed in same relative Pixel window positions, but
	at the cost of deforming things (circles to ellipses).  TRUE is default.
(9) Use _realpixelconverter.setAutoRotate(TRUE) to make the display automatically
	rotate 90 degrees counterclockwise for best use of screen space.  Use this
	if there's nothing that has to be horizontal vs. vertical.  This doesn't 
	work smoothly with FixedAspect(FALSE), so use with the default FixedAspect TRUE.
May 21, 2002. Took out _forcerotate_flag and _autorotate_flag.*/


#include "realnumber.h" //For Real type
#define INTEGER_OVERFLOW 2000000000.0 /* This is designed to match the range
	of a 32-bit integer, which goes from -2 Gig to 2 Gig.  You need to change
	this value if you use a different size of integer. */
#include "realbox.h" //For the setRealWindow argument.

class cRealPixelConverter
{
private:
	int _left, _top, _right, _bottom; //Current pixel window
	int _cx, _cy; //current pixel window size in pixels.
	int _midx, _midy; /*Used by RealToPixel().  Pixel center of window.
	int _left, _top, _right, _bottom; //Pixel coords for the occasional times
		cases when the pixel window happens not just be (0,0) to (_cx,_cy)*/
	Real _realcenterx, _realcentery; //Real coords of center of window.
	Real _realradiusx, _realradiusy;
		//The real value of half the window, origin in center.
	Real _realpixperx, _realpixpery;
		//Length per pixel, same as _mid?/_realradius?
	Real _constx, _consty; //precalculated terms to speed up RealToPixel
	BOOL _changed_size_flag; 
	BOOL _fixed_aspect_flag; //See (8) above.
	void _fixup_constants(); /* Helper function to update
		_realpixper?, _const? and _changed_size_flag. */
public:
	cRealPixelConverter(Real radiusx = 2.0, Real radiusy = 1.5);
	/* The default realpixelconverter will have a RealWindow 4 wide and 3 high, in 
		the same proportion as a standard window (such as 800 by 600 pixels).
		We'll put the center at (0.0, 0.0) and let the bottom left corner be
		(-2.0, -1.5), and the top right corner be (2.0, 1.5). The default
		PixelWindow will be 800 by 600. */
	int cx()const{return _cx;}
	int cy()const{return _cy;}
	Real lorealx()const {return _realcenterx - _realradiusx;}
	Real hirealx()const {return _realcenterx + _realradiusx;}
	Real lorealy()const {return _realcentery - _realradiusy;}
	Real hirealy()const {return _realcentery + _realradiusy;}
	Real width()const {return 2*_realradiusx;}
	Real height()const {return 2*_realradiusy;}
	BOOL changedSizeFlag()const{return _changed_size_flag;}
	void setChangedSizeFlag(BOOL newval){_changed_size_flag = newval;}
	void setFixedAspect(BOOL truefalse);
	BOOL getFixedAspect()const{return _fixed_aspect_flag;}
	void setPixelWindow(int cx, int cy); //Assumes pixel window is from (0,0) to (cx,cy)
	void setPixelWindow(int left, int top, int right, int bottom);
	void setRealWindow(Real lox, Real loy, Real hix, Real hiy);
	void setRealWindow(const cRealBox &box);
	/* Usually we like to pass variables by reference if we change them,
		but in the special case of the next two functions we don't
		do this. The reason is that these functions are used inside
		lots of classes, and C++ doesn't always do the right thing if
		you ask it to generate a reference to a class member.  Instead
		we'll always explicitly generate the pointer at the coding
		time with the "&" operator. */
	void realToPixel(Real rx, Real ry, int *ix, int *iy)const;
	/*Converts real coords to integer pixel coords.  Bails with a FALSE
		if an integer coord would be >INTEGER_OVERFLOW or <-INTEGER_OVERFLOW. */
	void realToInt(Real rx, int *ix) const;
	/*Converts scalar real quantities, like circle radii, to an appropriate pixel
		 size. Chooses min value between x and y directions if not fixed aspect. */
	void realToIntAnisotropic(Real rx, int *ix, int *iy) const; /* Use this in
		case FixedAspect is FALSE and you want it to show.  If, for
		instance you want to draw your real space cicles as pixel space ellipses. */
	void pixelToReal(int ix, int iy, Real *rx, Real *ry)const;
		//Convert pixel coords to real coords.
	void intToReal(int ix, Real *rx) const; /* convert a pixel distance to a real.
		Chooses max value between x and y directions if not fixed aspect. */
	void zoom(Real newcenterx, Real newcentery, Real zoomfactor);
	//Sets RealWindow center to args, multiplies radius by zoomfactor.
	void zoomAtPixel(int pixx, int pixy, Real zoomfactor); //Same
	//as the other Zoom, but calls PixelToReal first.
};

#endif REALPIXELCONVERTER_HPP
