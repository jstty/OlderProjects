#include "stdafx.h"
#include "colorstyle.h"
#include "randomizer.h"  //For the cRandomizer in the mutate method
#include "spritepolygon.h" //for the MF_ flags.

IMPLEMENT_SERIAL(cColorStyle, CObject, 0)

Real cColorStyle::LINEWIDTHWEIGHT = 0.05; //Default linewidth proportion


const Real cColorStyle::LW_IGNORELINEWIDTHWEIGHT = 0.0;
 //Color constants.  Don't normally zero-out any field, as otherwise
//you lose any chance for color highlights.
const UINT cColorStyle::CN_BLACK = RGB(10,10,10);
const UINT cColorStyle::CN_WHITE = RGB(255,255,255);
const UINT cColorStyle::CN_BROWN = RGB(140, 100, 60);
const UINT cColorStyle::CN_DARKBROWN = RGB(60,60, 40);

const UINT cColorStyle::CN_GRAY = RGB(80,80,80);
const UINT cColorStyle::CN_RED = RGB(255, 10, 10);
const UINT cColorStyle::CN_ORANGE = RGB(255, 128, 128);
const UINT cColorStyle::CN_YELLOW = RGB(255, 255, 10);
const UINT cColorStyle::CN_GREEN = RGB(10, 255, 10);
const UINT cColorStyle::CN_BLUE = RGB(10, 10, 255);
const UINT cColorStyle::CN_PURPLE = RGB(255, 10, 255);

const UINT cColorStyle::CN_DARKGRAY = RGB(40,40,40);
const UINT cColorStyle::CN_DARKRED = RGB(128, 10, 10);
const UINT cColorStyle::CN_DARKORANGE = RGB(128, 64, 64);
const UINT cColorStyle::CN_DARKYELLOW = RGB(128, 128, 10);
const UINT cColorStyle::CN_DARKGREEN = RGB(10, 128, 10);
const UINT cColorStyle::CN_DARKBLUE = RGB(10, 10, 128);
const UINT cColorStyle::CN_DARKPURPLE = RGB(128, 10, 128);

const UINT cColorStyle::CN_LIGHTGRAY = RGB(160,160,160);
const UINT cColorStyle::CN_LIGHTRED = RGB(255, 200, 200);
const UINT cColorStyle::CN_LIGHTORANGE = RGB(255, 192, 192);
const UINT cColorStyle::CN_LIGHTYELLOW = RGB(255, 255, 128);
const UINT cColorStyle::CN_LIGHTGREEN = RGB(128, 255, 128);
const UINT cColorStyle::CN_LIGHTBLUE = RGB(128, 128, 255);
const UINT cColorStyle::CN_LIGHTPURPLE = RGB(255, 128, 255);

cColorStyle::cColorStyle(BOOL filled, BOOL edged, 
		COLORREF fillcolor,
		COLORREF linecolor, Real linewidth, 
		Real linewidthweight,
		Real alpha):
		_filled(filled),_edged(edged),_fillcolor(fillcolor),
		_linecolor(linecolor),_linewidth(linewidth), 
 		_linewidthweight(linewidthweight), _alpha(alpha)
{}


cColorStyle::cColorStyle(const cColorStyle &colorstyle)
{
	copy(colorstyle);
}

cColorStyle::cColorStyle(cColorStyle *pcolorstyle)
{
	copy(*pcolorstyle);
}

cColorStyle::~cColorStyle()
{
}

void cColorStyle::copy(const cColorStyle &colorstyle)
{
	_filled = colorstyle._filled;
	_edged = colorstyle._edged;
	_fillcolor = colorstyle._fillcolor;
	_linecolor = colorstyle._linecolor;
	_linewidth = colorstyle._linewidth;
	_linewidthweight = colorstyle._linewidthweight;
	_alpha = colorstyle._alpha;
}

cColorStyle* cColorStyle::clone()
{
/* The purpose of this method is that we may later have various child classes
cColorStyleChild of the cColorStyle class, and to truly copy a cColorStyleChild, you need
a cColorStyleChild* pointer and not a cColorStyle* pointer.  The following will
create a cColorStyleyChild* pointer.  Even though we cast pcolorstyle into a cColorStyle*
pointer for the return, it "really" remains a cColorStyleChild, and will use the
child classes overloads of any virtual methods. */  
	CRuntimeClass *pRuntimeClass = GetRuntimeClass();
	cColorStyle *pcolorstyle = (cColorStyle*)(pRuntimeClass->CreateObject());
	pcolorstyle->copy(this);
	return pcolorstyle;
}

cColorStyle cColorStyle::operator=(const cColorStyle & colorstyle)
{
	copy(colorstyle);
	return *this;
} 

void cColorStyle::mutate(int mutationflags, Real mutationstrength)
{
//The colors
	if (mutationflags & cPolygon::MF_COLOR)
		_fillcolor = cRandomizer::pinstance()->mutateColor(_fillcolor, mutationstrength);
//The filling
	if (mutationflags & cPolygon::MF_FILLING)
		_filled = _filled ^ cRandomizer::pinstance()->randomBOOL(mutationstrength/2.0); 
		// Need to divide by two to get a proper coinflip; consider the case where mutationstrength is 1.0.
//The linewidth
	if (mutationflags & cPolygon::MF_LINEWIDTH)
	{
		if (cRandomizer::pinstance()->randomBOOL(0.9))
		{
			_linewidthweight = LW_IGNORELINEWIDTHWEIGHT;
			_linewidth = 1.0;
		}
		else
		{
			_linewidthweight = 
				cRandomizer::pinstance()->
					mutate(_linewidthweight, 0.05, 0.2, mutationstrength);
			_linewidth = cRandomizer::pinstance()->
					mutate(_linewidth, 1.0, 7.0, mutationstrength);
		}
	}
}

void cColorStyle::Serialize(CArchive &ar)
{
	if (ar.IsStoring()) //Writing data.
		ar <<  _filled <<  _edged << _fillcolor << _linecolor << _linewidth;
	else //Reading data.
		ar >>  _filled >>  _edged >> _fillcolor >> _linecolor >> _linewidth;
}
