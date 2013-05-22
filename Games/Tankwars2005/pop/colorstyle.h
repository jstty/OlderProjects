#ifndef COLORSTYLE_H
#define COLORSTYLE_H

#include "realnumber.h"

class cColorStyle: public CObject
{
DECLARE_SERIAL(cColorStyle)
public:
	static Real LINEWIDTHWEIGHT; //Default linewidth
	static const Real LW_IGNORELINEWIDTHWEIGHT; /* Used as a linewidth value
		to mean ignore _linewidthweight and use _linewidth in graphicsMFC. */
//Color constants.
	static const UINT  CN_BLACK;
	static const UINT  CN_WHITE;
	static const UINT  CN_BROWN;
	static const UINT  CN_DARKBROWN;

	static const UINT  CN_GRAY;
	static const UINT  CN_RED;
	static const UINT  CN_ORANGE;
	static const UINT  CN_YELLOW;
	static const UINT  CN_GREEN;
	static const UINT  CN_BLUE;
	static const UINT  CN_PURPLE;

	static const UINT  CN_LIGHTGRAY;
	static const UINT  CN_LIGHTRED;
	static const UINT  CN_LIGHTYELLOW;
	static const UINT  CN_LIGHTORANGE;
	static const UINT  CN_LIGHTGREEN;
	static const UINT  CN_LIGHTBLUE;
	static const UINT  CN_LIGHTPURPLE;

	static const UINT  CN_DARKGRAY;
	static const UINT  CN_DARKRED;
	static const UINT  CN_DARKORANGE;
	static const UINT  CN_DARKYELLOW;
	static const UINT  CN_DARKGREEN;
	static const UINT  CN_DARKBLUE;
	static const UINT  CN_DARKPURPLE;
protected:
	BOOL _filled;
	BOOL _edged;
	COLORREF _fillcolor;
	COLORREF _linecolor;
	Real _linewidth; // Line width is the size at which I actually draw a line.
	Real _linewidthweight;
		/* In graphicsMFC, _linewidthweight is used to set _linewidth for	
		polygon to be a _linewidthweight * radius(). graphicsOpenGL just uses
		linewidth directly. */
	Real _alpha;
public:
//Construct and copy
	cColorStyle(BOOL filled = TRUE, BOOL edged = TRUE, 
		COLORREF fillcolor = CN_LIGHTGRAY,
		COLORREF linecolor = CN_BLACK, Real linewidth = 1, 
		Real linewidthweight = cColorStyle::LW_IGNORELINEWIDTHWEIGHT,
		Real alpha = 1.0);
	cColorStyle(const cColorStyle &colorstyle);
	cColorStyle(cColorStyle *pcolorstyle);
	virtual ~cColorStyle();
	void copy(const cColorStyle &colorstyle);
	cColorStyle* clone();
	cColorStyle operator=(const cColorStyle &colorstyle);
//Mutate
	void setFilled(BOOL yesno){_filled = yesno;}
	void setEdged(BOOL yesno){_edged = yesno;}
	virtual void setFillColor(COLORREF col){_fillcolor = col;}
	virtual void setLineColor(COLORREF col){_linecolor = col;}
	void setLineWidthWeight(Real linewidthweight){_linewidthweight = linewidthweight;}
	void setLineWidth(Real linewidth){_linewidth = linewidth;}
	void mutate(int mutationflags, Real mutationstrength);
//Accessor
	BOOL filled() const {return _filled;}
	BOOL edged() const {return _edged;}
	COLORREF fillColor() const {return _fillcolor;}
	COLORREF lineColor() const {return _linecolor;}
	Real lineWidthWeight() const {return _linewidthweight;}
	Real lineWidth() const {return _linewidth;}
//Serialize
	virtual void Serialize(CArchive &ar);
};

#endif //COLORSTYLE_H