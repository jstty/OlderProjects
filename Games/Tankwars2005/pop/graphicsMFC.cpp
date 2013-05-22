// implementation of the cGraphicsMFC class
//

#include "stdafx.h"
#include "ChildFrm.h" //For CChildFrame class to use _cSplitterWnd.  RR.
#include "game.h"
#include "listener.h"
#include "MainFrm.h" //For CMainFrame class to call SetMessageText.  RR.
#include "graphicsMFC.h"
#include "realbox.h"
#include "spritepolygon.h"
#include "spriteicon.h"
#include "critterviewer.h" //For pixeltovector kludge

#define USEPOPVIEW
/* USEPOPVIEW does some special things relating to showing a CPopDocument.  If you want to use
the cGraphicsMFC class for another kind of program, don't #define USEPOPVIEW.
The special things we do are to (a) write a font message and (b) redraw the game border
edge so its on top of the critters. */

//#define USEONSCREENFONT_MFC
	/* If USEONSCREENFONT_MFC is defined, I write PRESS ENTER when a game is over. */
#define CALLDRAWFOREGROUND
	/* If I use CALLDRAWFOREGROUND, then I have the draw method call the
	attached pgame()->drawForeground method.  I could to just let
	the game itself make that call in its drawworld() method. But if I
	call it from cGraphicsMFC::display, then it's crisply on top of	
	anything at the edge. */
#ifdef USEPOPVIEW
#include "PopView.h"
#endif //USEPOPVIEW


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// cGraphicsMFC
IMPLEMENT_SERIAL(cGraphicsMFC, cGraphics, 0)

int cGraphicsMFC::INSTANCECOUNT = 0; /* I need this so I know when to clear
	out the static cGraphicsMFC::_map_ResourceIDToScaledDC array. */

cGraphicsMFC::cGraphicsMFC():		//Call constructors for the members.
	_realpixelconverter(),
	_pmatrixstack(&_modelviewmatrixstack),
	_matrix(_modelviewmatrixstack.matrix())
{
	_pMemDC = new cMemoryDC(cMemoryDC::CMEMDC_FULLSCREEN);
	cGraphicsMFC::INSTANCECOUNT++;
	_realpixelconverter.setFixedAspect(TRUE);
}

cGraphicsMFC::~cGraphicsMFC()
{ 
	free(); //Release all the resource textures.
	delete _pMemDC;
	_pMemDC = NULL;
	 /* We may have to free the images as well. Since we chose to treat
		 cGraphicsMFC::_map_ResourceIDToScaledDC as a shared resource, we don't want to kill it off
		until the last cGraphicsMFC dies. */
	cGraphicsMFC::INSTANCECOUNT--;
	if (cGraphicsMFC::INSTANCECOUNT <= 0) //You're destroying the last instance
		cGraphicsMFC::_map_ResourceIDToScaledDC.free(); /* Delete all the
			cMemoryDC pointers stored in here. */
} 

//Matrix and projection methods================================

void cGraphicsMFC::matrixMode(MATRIXMODE mode)
{
	if (mode == MODELVIEW)
	{
		_matrix = _modelviewmatrixstack.matrix();
		_pmatrixstack = &_modelviewmatrixstack;
	}
	if (mode == PROJECTION)
	{
		_matrix = _projectionmatrixstack.matrix();
		_pmatrixstack = &_projectionmatrixstack;
	}
	if (mode == TEXTURE)
	{
		_matrix = _texturematrixstack.matrix();
		_pmatrixstack = &_texturematrixstack;
	}
}

void cGraphicsMFC::ortho(Real left, Real right, Real bottom, Real top, Real nearzclip, Real farzclip)
{
	_realpixelconverter.setRealWindow(left, bottom, right, top);
	/* Note that unlike the ortho call's order of variables, the cRealPixelConverter expects the order
		(lox, loy, hix, hiy). */
}
//Helpers======================================================

void cGraphicsMFC::setViewport(int width, int height)
{
	_realpixelconverter.setPixelWindow(width, height);
}

void cGraphicsMFC::setClearColor(COLORREF colorref)
{
	_pMemDC->setBlankColor(colorref);
}

void cGraphicsMFC::clear(const CRect &clearrect)
{
	_pMemDC->clear(clearrect);
}

void cGraphicsMFC::setRealBox(cRealBox border)
{
	_realpixelconverter.setRealWindow(border.lox(), border.loy(), border.hix(), border.hiy());
}

void cGraphicsMFC::vectorToPixel(cVector position, int &xpix, int &ypix, Real &zbuff)
{
/* I have to use a viewercorrection like in cGraphicsMFC::pixelToVector*/
	int tempx, tempy;
	cVector viewercorrection = _matrix.lastColumn();
	position += viewercorrection;
	_realpixelconverter.realToPixel(position.x(), position.y(), &tempx, &tempy);
	xpix = tempx;
	ypix = tempy;
	zbuff = 0.0;
}

cVector cGraphicsMFC::pixelToVector( int xpix, int ypix, Real zbuff)
{
/* I have to use a viewercorrection like in cGraphicsMFC::vectorToPixel*/
	Real tempx, tempy;
	_realpixelconverter.pixelToReal(xpix, ypix, &tempx, &tempy);
	cVector transformpos = cVector(tempx, tempy); /* We don't use the zbuff,
		as in the cGrapphicsMFC, every pixel pos is the same depth, and	
		we interpret them all as 0 z. */
	cVector viewercorrection = _matrix.lastColumn();
	transformpos -= viewercorrection;
	return transformpos;
}

cLine cGraphicsMFC::pixelToSightLine(int xpix, int ypix)
{ /* This is a line that runs from the viewer's eye to the direction matching the pixel point. */
	cVector planepoint = pixelToVector(xpix, ypix, 0.0);
	return cLine(planepoint, -cVector::ZAXIS); //Second arg should be a unit vector.
}

//====Drawing===========================================

void cGraphicsMFC::display(CView *pview, CDC *pDC)
{
#ifdef USEPOPVIEW 
/* This does some special things relating to showing a CPopDocument.  If you want to use
this graphics class for another kind of program, don't #define USEPOPVIEW at program top.
The special things we do are to (a) write a font message and (b) redraw the game border
edge so its on top of the critters. */
#ifdef USEONSCREENFONT_MFC
//(a) Do the font message
	CPopDoc *pDoc = ((CPopView*)pview)->GetDocument(); 
	if( pDoc->pgame()->gameover())
	{
		CFont font, *poldfont;
		/* The CreatePointFont takes a number which is ten times the "point size" as the
			first argument.  Some testing shows that 0.4 times the window height is a
			reasonable-looking argument to use. */
		BOOL fontcreated = font.CreatePointFont(0.7 * _realpixelconverter.cy(), "Arial", _pMemDC);
			/* It's inefficent to do this over and over, I shoudl really do it once and save
			as a member of the class.  This is	a bigger issue in cGraphicsOpenGL where makign
			a font is slooooow. */
		if (fontcreated)
			poldfont = _pMemDC->SelectObject(&font);
		COLORREF oldtextcolor = _pMemDC->SetTextColor(cColorStyle::CN_ORANGE);
		int oldbkmode = _pMemDC->SetBkMode(TRANSPARENT);
//#define USEDRAWTEXT
/* USEDRAWTEXT usesthe fancier DrawText with its autopositioning flags. */
#ifdef USEDRAWTEXT
		_pMemDC->DrawText("Press Enter", 
			CRect(0,0,_realpixelconverter.cx(), _realpixelconverter.cy()),
			DT_CENTER|DT_VCENTER|DT_SINGLELINE);
#else //Not USEDRAWTEXT means use the simpler TextOut call. */
		_pMemDC->TextOut(_realpixelconverter.cx()/4, 
			_realpixelconverter.cy()/2, "Press Enter");
#endif //USEDRAWTEXT
		_pMemDC->SetBkMode(oldbkmode);
		_pMemDC->SetTextColor(oldtextcolor);
		_pMemDC->SelectObject(poldfont);
	}
#endif //USEONSCREENFONT_MFC
//(b) Draw the border frame on top of everything else.
#ifdef CALLDRAWFOREGROUND
	if (pview->IsKindOf(RUNTIME_CLASS(CPopView)))
	{
		CPopDoc *pDoc = ((CPopView*)pview)->GetDocument(); 
		cRealBox border = pDoc->pgame()->border(); //Only reason I need the pview.
		pushMatrix();
		translate(cVector(0.0, 0.0, //Put foreground in front.
			border.hiz() + cGame::FOREGROUNDOFFSET)); 
		pDoc->pgame()->drawForeground(this, CPopView::DF_STANDARD);
		/* By default this draws an unfilled yellow-line rectangle the shape
			of pskybox().member(HIZ) on top of any possible overlapping sprites.
			Can draw some more foreground furniture if pgame likes. */
		popMatrix();
	}
#endif //CALLDRAWFOREGROUND
#endif //USEPOPVIEW
//The next three lines are all that you REALLY need to do in here.
	CRect targetrect;
	pDC->GetClipBox(&targetrect);
	_pMemDC->copyTo(pDC, targetrect);
}

//----------- Methods used by cGame ---------------------------

COLORREF cGraphicsMFC::sniff(cVector sniffpoint)
{
	int pix_x, pix_y;
	Real dummyz;
	vectorToPixel(sniffpoint, pix_x, pix_y, dummyz);
	COLORREF dummy = _pMemDC->GetPixel(pix_x, pix_y);
	return _pMemDC->GetPixel(pix_x, pix_y);
}

//--------------Graphics methods-------------
void cGraphicsMFC::drawtext(CString string, int pixx, int pixy)
{
	_pMemDC->TextOut(pixx, pixy, string);
}


void cGraphicsMFC::drawline(cVector posa, cVector posb, cColorStyle *pcolorstyle)
{
//First transform
	cVector transformposa = _matrix*posa;
	cVector transformposb = _matrix*posb;

	int ixa, iya, ixb, iyb;
	int intlinewidth;
	CPen cpen, *ppen_old;

	_realpixelconverter.realToInt(pcolorstyle->lineWidth(), &intlinewidth);
	if (!intlinewidth) /* This is why setting _reallinewidth to 0.0 or to
		LW_IGNORELINEWIDTHWEIGHT has the effect of making it be _linewidth */
		intlinewidth = pcolorstyle->lineWidth();
	_realpixelconverter.realToPixel(transformposa.x(), transformposa.y(), &ixa, &iya);
	_realpixelconverter.realToPixel(transformposb.x(), transformposb.y(), &ixb, &iyb);
	cpen.CreatePen(PS_SOLID, intlinewidth, pcolorstyle->lineColor());
	ppen_old = _pMemDC->SelectObject(&cpen);
	_pMemDC->MoveTo(ixa, iya);
	_pMemDC->LineTo(ixb, iyb);
	_pMemDC->SelectObject(ppen_old);
	cpen.DeleteObject();
}

void cGraphicsMFC::drawrectangle(const cVector &corner0, const cVector &corner1,
		const cVector &corner2, const cVector &corner3,
		cColorStyle *pcolorstyle, int drawflags)
{
//First transform
	cVector transformcorner0 = _matrix*corner0;
	cVector transformcorner2 = _matrix*corner2;
//First convert to pixel coords.
	int intcorner0x, intcorner0y, intcorner2x, intcorner2y, intlinewidth;

	_realpixelconverter.realToPixel(transformcorner0.x(),
		transformcorner0.y(), &intcorner0x, &intcorner0y);
	_realpixelconverter.realToPixel(transformcorner2.x(),
		transformcorner2.y(), &intcorner2x, &intcorner2y);
	_realpixelconverter.realToInt(pcolorstyle->lineWidth(), &intlinewidth);
	if (!intlinewidth) /* This is why setting _reallinewidthweight to 0.0
		or to LW_IGNORELINEWIDTHWEIGHT has the effect of making it be _linewidth */
		intlinewidth = pcolorstyle->lineWidth();
//Now draw the rectangle
	CBrush cbrush, *pbrush_old; 
	CPen cpen, *ppen_old;
	CRect rect(intcorner0x, intcorner0y, intcorner2x, intcorner2y);
	rect.NormalizeRect();
	if (pcolorstyle->filled() && !(drawflags & CPopView::DF_WIREFRAME))
	{
		cbrush.CreateSolidBrush(pcolorstyle->fillColor());
		pbrush_old = _pMemDC->SelectObject(&cbrush);
		_pMemDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);	
			/* This is faster than Rectangle, but even so, we geting a noticeable lag from
			this when the width and height are about 1000 and the bits per pixel is 24. If you
			were to comment this line out, the glitch would seem to go away. See the popdoc.cpp note
			by the TRACETIMESTEPANOMALIES switch. */
		_pMemDC->SelectObject(pbrush_old); 
		cbrush.DeleteObject(); //Don't trust the destructor to do the DeleteObject.
	}
	if (pcolorstyle->edged() || (drawflags & CPopView::DF_WIREFRAME)) 
	{
		cpen.CreatePen(PS_SOLID, intlinewidth, pcolorstyle->lineColor());
		ppen_old = _pMemDC->SelectObject(&cpen);
		_pMemDC->MoveTo(rect.TopLeft());
		_pMemDC->LineTo(CPoint(rect.left, rect.bottom));
		_pMemDC->LineTo(rect.BottomRight());
		_pMemDC->LineTo(CPoint(rect.right, rect.top));
		_pMemDC->LineTo(rect.TopLeft());
		_pMemDC->SelectObject(ppen_old);
		cpen.DeleteObject();
	}
}

void cGraphicsMFC::drawcircle(const cVector &center, Real radius, cColorStyle *pcolorstyle,
		int drawflags)
{
//First transform
	cVector transformcenter = _matrix*center;

//Convert to pixel coords.
	int intcenterx, intcentery, intlinewidth, intradius;

	_realpixelconverter.realToPixel(transformcenter.x(), transformcenter.y(), &intcenterx, &intcentery);
	_realpixelconverter.realToInt(radius, &intradius);
	_realpixelconverter.realToInt(pcolorstyle->lineWidth(), &intlinewidth);
	if (!intlinewidth) /* This is why setting _reallinewidthweight to 0.0 or to
		LW_IGNORELINEWIDTHWEIGHT has the effect of making it be _linewidth */
		intlinewidth = pcolorstyle->lineWidth();
//Now draw the circle
	CBrush cbrush, *pbrush_old; 
	CPen cpen, *ppen_old;
	if (pcolorstyle->filled() && !(drawflags & CPopView::DF_WIREFRAME))
		cbrush.CreateSolidBrush(pcolorstyle->fillColor());
	else
		cbrush.CreateStockObject(NULL_BRUSH);
	pbrush_old = _pMemDC->SelectObject(&cbrush);
	if (pcolorstyle->edged() || (drawflags & CPopView::DF_WIREFRAME))
		cpen.CreatePen(PS_SOLID, intlinewidth, pcolorstyle->lineColor());
	else
		cpen.CreateStockObject(NULL_PEN);
	ppen_old = _pMemDC->SelectObject(&cpen);
	CRect rect(intcenterx - intradius, intcentery + intradius,
		intcenterx + intradius, intcentery - intradius);
	rect.NormalizeRect();
	_pMemDC->Ellipse(rect);
	_pMemDC->SelectObject(pbrush_old); 
	_pMemDC->SelectObject(ppen_old);
	cbrush.DeleteObject(); //Don't trust the destructor to do the DeleteObject.
	cpen.DeleteObject();
}

void cGraphicsMFC::drawpolygon(cPolygon *ppolygon, int drawflags )
{
//Leave the polygon itself alone, but make a copy of its verts and transform them.
	CArray<cVector, cVector &>* ptransformedvert = ppolygon->transformedVert(_matrix);
	cVector transformcenter = _matrix*ppolygon->center();
	//We assume that the transformed poly has the same radius as the ppolygon, that is, we assume
	//that _matrix is a rigid body transformation, that is, it has no scale or sheer.
//Then convert to pixel coords.
	int intdotradius, intlinewidth;
//	int intcenterx, intcentery, intradiusx, intradiusy;
//	_realpixelconverter.realToPixel(transformcenter.x(), transformcenter.y(), &intcenterx, &intcentery);
//	_realpixelconverter.realToIntAnisotropic(ppolygon->radius(), &intradiusx, &intradiusy);
	CArray<CPoint, CPoint &> pointvert; //Helper
	pointvert.SetSize(ppolygon->vertCount());
	/* I fill pointvert in a slightly awkward way because the compiler gets confused and
		throws an error if I try and use &(pointvert[i].x) as the third argument to
		realToPixel, which expects an int* there, and is happy with the &x for the local x,
		but if I try and generate a pointer to the x-field of the CPoint in the pointvert
		array, the compiler doesn't like it.  So I work around it. */
	int pix_x, pix_y;

	for (int i = 0; i<ppolygon->vertCount(); i++)
	{
			_realpixelconverter.realToPixel(ptransformedvert->GetAt(i).x(), ptransformedvert->GetAt(i).y(), &pix_x, &pix_y);
			pointvert[i].x = pix_x;
			pointvert[i].y = pix_y;
	}
	_realpixelconverter.realToInt(ppolygon->dotRadius(), &intdotradius);
	_realpixelconverter.realToInt(ppolygon->radius()*ppolygon->lineWidthWeight(),
		&intlinewidth);
	if (!intlinewidth) /* This is why setting _reallinewidthweight to 0.0 or to
		LW_IGNORELINEWIDTHWEIGHT has the effect of making it be _linewidth */
		intlinewidth = ppolygon->lineWidth();
//Now draw the polygon
	CBrush cbrush, *pbrush_old; 
	CPen cpen, *ppen_old;
	if (!ppolygon->vertCount())
		return;
	if (ppolygon->filled() && !(drawflags & CPopView::DF_WIREFRAME))
		cbrush.CreateSolidBrush(ppolygon->fillColor());
	else
		cbrush.CreateStockObject(NULL_BRUSH);
	pbrush_old = _pMemDC->SelectObject(&cbrush);
	if (ppolygon->edged() || (drawflags & CPopView::DF_WIREFRAME))
		cpen.CreatePen(PS_SOLID, intlinewidth, ppolygon->lineColor());
	else
		cpen.CreateStockObject(NULL_PEN);
	ppen_old = _pMemDC->SelectObject(&cpen);
//draw a polygon.
	/* We draw the polygons using standard CDC::Polygon(POINT *, int) function.
	The CArray::GetData function turns a CArray into a simple CPoint * array,
	and we can use this without a further cast into (POINT *). */ 
	_pMemDC->Polygon(pointvert.GetData(), ppolygon->vertCount());

	if (ppolygon->dotted())
	{
		/* The only safe way to "change a brush color" is to actually get rid of
		the old brush and make a new one. Note that it is permissible to
		call DeleteObject even if cbrush hold the NULL_BRUSH, as a call to
		delte a stock object actually does nothing.  */
		_pMemDC->SelectObject(pbrush_old); //Need to unselect the brush before deleting
		cbrush.DeleteObject(); //Delete the brush.
		if (ppolygon->pdotcolorstyle()->filled() && !(drawflags & CPopView::DF_WIREFRAME))
			cbrush.CreateSolidBrush(ppolygon->pdotcolorstyle()->fillColor());
		else
			cbrush.CreateStockObject(NULL_BRUSH);
		pbrush_old = _pMemDC->SelectObject(&cbrush);
		for (i=0; i<ppolygon->vertCount(); i++)
#ifndef TRUESTAR //Only draw half the dots if you're not using TRUESTAR,
					//which is a switch in spritepolygon.h
			if (i%2 == 0 || ppolygon->convex())
#endif //TRUESTAR
				_pMemDC->Ellipse(CRect(pointvert[i].x - intdotradius,
					pointvert[i].y - intdotradius,
					pointvert[i].x + intdotradius,
					pointvert[i].y + intdotradius));
	}
	_pMemDC->SelectObject(pbrush_old); 
	_pMemDC->SelectObject(ppen_old);
	cbrush.DeleteObject(); //Don't trust the destructor to do the DeleteObject.
	cpen.DeleteObject();
}


void cGraphicsMFC::setClipRegion(cRealBox *pclipbox)
{
	if (!pclipbox)
		_pMemDC->SelectClipRgn(NULL); //Makes the clipping region the client window.
	else
	{
		CRgn cliprgn; //Temporary region used as a kind of scratchpad.
		CRect crectclipbox = realBoxToCRect(*pclipbox);
		cliprgn.CreateRectRgn(crectclipbox.left, crectclipbox.top, crectclipbox.right,
			crectclipbox.bottom);
		_pMemDC->SelectClipRgn(&cliprgn); //Makes a copy of cliprgn.
		cliprgn.DeleteObject(); //Need to do this, or resource leak!  CRgn destructor won't do it.
	}
} 

//====================================== cSpriteIcon stuff================
/* Give the static array member with the default constructor a place to live, 
that is, right here.  The default constructor sets its size to 0. */

cMap_ResourceIDToScaledDC cGraphicsMFC::_map_ResourceIDToScaledDC;

int cMapEntry_ResourceIDToScaledDC::FRESHLIFESPAN = 160000;
	//Allow about two minutes at 80 updates a second.
int cMapEntry_ResourceIDToScaledDC::SIZEJITTERLEVEL = 2;
Real cMapEntry_ResourceIDToScaledDC::ASPECTJITTERLEVEL = 0.01;

void cGraphicsMFC::garbageCollect()
{
	cGraphicsMFC::_map_ResourceIDToScaledDC.garbageCollect();
}

void cGraphicsMFC::free()
{
	cGraphicsMFC::_map_ResourceIDToScaledDC.free();
}

void cMap_ResourceIDToScaledDC::garbageCollect()
{
/* The idea here is that for every mapentry with a 0 or negative lifespan we delete its _pScaledImage
and throw away the mapentry.  In addition, if a mapentry happens to be the only one that is using
a given _pResourceImage, we delete that too. */
	for (int i=0; i< GetSize(); i++)
		if (--(ElementAt(i)._lifespan) <= 0) 
		{/* The -- in the line above ensures that a call to garbageCollect "ages" the images.
				Recall that the ElementAt array accessor returns a reference to the entry,
				so you can actually change it.  This is as opposed to the GetAt array accessor
				which returns a copy, and if you change the copy it doesn't affect the actual
				array. ElementAt is also faster, so we prefer that in here even in the
				places where we don't need it. */
			BOOL killResourceImageToo = TRUE;
			for (int j=0; j < GetSize(); j++)
				if (j!=i && ElementAt(i)._pResourceImage ==  ElementAt(j)._pResourceImage)
						killResourceImageToo = FALSE;
			delete ElementAt(i)._pScaledImage;
			ElementAt(i)._pScaledImage = NULL;
			if (killResourceImageToo) //This entry is the only one using the _pResourceImage.
			{
				delete ElementAt(i)._pResourceImage;
				ElementAt(i)._pResourceImage = NULL;
			}
			RemoveAt(i); /* This removes the ith element and shifts
				down the ones above it.  This means that the ith element is now one we haven't seen,
				so we decrement i to make sure we get it. The closing bracket of the loop increments the
				i back up, so there's no danger of trying to access a -1 index. Note the i-- move
				also prevents us from running off the end of the array after removing the last element. 
				It's awkward to this, though, and it's a sign I should have used a CList instead of
				CArray for the base class. */
			i--;
		}
}

void cMap_ResourceIDToScaledDC::free()
{

	for (int i=0; i< GetSize(); i++)
		ElementAt(i)._lifespan = 0;
	garbageCollect(); //Garbage collection will get rid of everything now.
	ASSERT(!GetSize()); //Just to check that it works.
}


BOOL cMapEntry_ResourceIDToScaledDC::matchesTargetRect(const CRect &targetRect)const
{ 
	return abs(_targetRect.Width() - targetRect.Width()) < cMapEntry_ResourceIDToScaledDC::SIZEJITTERLEVEL &&
		abs(_targetRect.Height() - targetRect.Height()) < cMapEntry_ResourceIDToScaledDC::SIZEJITTERLEVEL;
}

BOOL cMapEntry_ResourceIDToScaledDC::matchesResourceAndAspect(cSpriteIcon *picon)const
{ 
	if (!picon->presetaspect())
		return _resourceID == picon->resourceID();
	else //You have to match the aspect as well.
		return _resourceID == picon->resourceID() && fabs(_aspect - picon->aspect()) <
			cMapEntry_ResourceIDToScaledDC::ASPECTJITTERLEVEL;
}

void* cGraphicsMFC::_getScaledImage(cSpriteIcon *picon, CRect &targetRect)
{
	int i;
	BOOL resourceidwasfound = FALSE;
	cMapEntry_ResourceIDToScaledDC mapentry; /* There are four possible cases here: (1), (2.1), (2.2) and (2.3).
		(1) If this is the first time this view is drawing an icon with this resourceID, then
		we need to intialize all the field of mapentry and add it to cGraphicsMFC::_map_ResourceIDToScaledDC. 
		(2) We have already done step (a) once in some instance of cGraphicsMFC during this program
		run, and mapentry is a copy of this entry with a valid _pResourceImage.  Now three subcases
		arise.  (2.1) This is the first time picon has called _getScaledImage, and !picon->imageloaded()
		holds.  In this case, the targetRect passed in was not in fact of the correct aspect, that is
		it doesn't match the aspect of the _pResourceImage.  In this case, we recalculate targerRect,
		and once again search for a mapentry with matching resourceID and targetRect.  We will
		at least find one with matching resourceID.  At this point whether or not we had to do
		case (2.1) we now move on to (2.2) or (2.3).  (2.2) None of	the mapentry with the correct
		_resourceID has the correct _targetRect. In this case we make a new _pScaledImage, put it
		in the mapentry, and add the new mapentry to  cGraphicsMFC::_map_ResourceIDToScaledDC. (2.3) We find
		a mapentry with a _targetRect so that it matchesTargetRect(targetRect). In	this case we can return
		mapentry._pScaledImage. 
		As a further complication, we will make separate mapentries with separate _pResourceImage
		for the same _resoruceID in the case where we have two presetaspect icons with different
		aspect.*/
	for (i=0; i< cGraphicsMFC::_map_ResourceIDToScaledDC.GetSize(); i++)
		if (cGraphicsMFC::_map_ResourceIDToScaledDC[i].matchesResourceAndAspect(picon))
		{
			resourceidwasfound = TRUE;
			mapentry = cGraphicsMFC::_map_ResourceIDToScaledDC.GetAt(i); //Make a copy.
			if (mapentry.matchesTargetRect(targetRect))
			{//This is Case 2.3, the easy case where you find just what you need.
				cGraphicsMFC::_map_ResourceIDToScaledDC.ElementAt(i)._lifespan = 
					cMapEntry_ResourceIDToScaledDC::FRESHLIFESPAN;
				return mapentry._pScaledImage; //You're done!
			}
		}
	/* If we're here, we're in case (1) or case (2.2) or we may be in case (2.1) where the
		picon fed in an incorrect targetrect.  We assume the worst for now and start to
		we are going to fill in some or all of the fields of mapentry to later add to
		 cGraphicsMFC::_map_ResourceIDToScaledDC. */
	if (!resourceidwasfound) /* In this case (1), mapentry is the default constructor entry; no
		corresponding resourceID was found. Initialize the mapentry _resourceID and _pResourceImage
		to start with. */
	{		// First set the dummy mapentry's _resourceID
		mapentry._resourceID = picon->resourceID();
			//Second construct the dummy mapentry's _pResourceImage
		if (picon->usesTransparentMask())
			mapentry._pResourceImage = new cTransparentMemoryDC();
		else
			mapentry._pResourceImage = new cMemoryDC();
			/* The default constructors make the cMemoryDC 1 x 1 and set 
			the _resize_on_load flag to TRUE so we will make the bitmap match
			the image being loaded in loadResourceBitmap. */
		ASSERT(mapentry._pResourceImage);
			//Third, load the resource bitmap into the mapentry._pResourceImage
		mapentry._pResourceImage->loadResourceBitmap(picon->resourceID());
			//If necessary, adjust the size of the mapentry._pResourceImage if picon->presetaspect()
		if (picon->presetaspect())
		{
			int sourcex = mapentry._pResourceImage->cx();
			int sourcey = mapentry._pResourceImage->cy();
			ASSERT(sourcey);
			ASSERT(picon->aspect());
			Real tempaspect = Real(sourcex)/sourcey;
			// We want to make the source bitmap match the _aspect of the picon.
			if (tempaspect > picon->aspect()) //sourcex too big, make it smaller than tempaspect*sourcey.
				sourcex = picon->aspect() * sourcey;
			if (tempaspect < picon->aspect()) //sourcey too big, make it smaller than sourcex/tempaspect.
				sourcey = sourcex / picon->aspect();
			cMemoryDC *pMemDC_bitmap = new cMemoryDC();
			ASSERT(pMemDC_bitmap);
			pMemDC_bitmap->setSize(sourcex, sourcey);
			mapentry._pResourceImage->copyTo(pMemDC_bitmap, CRect(0,0,sourcex, sourcey));
			delete mapentry._pResourceImage;
			mapentry._pResourceImage = NULL;
			mapentry._pResourceImage = pMemDC_bitmap;
		}
		//Initialize mapentry._aspect to match the dimensions of _pResourceImage.
		mapentry._aspect = (Real)(mapentry._pResourceImage->cx())/ mapentry._pResourceImage->cy();
		/* What about putting the newly initialized pmapentry into cGraphicsMFC::_map_ResourceIDToScaledDC?
			We'll do that in the next block of code, after we have initialized ALL of 
			its fields. */
		picon->setAspect(mapentry._aspect); //Do this here to be sure in case roundoff error made not match
	}

		/* At this point, we know that mapentry has a valid _resourceID and _pResourceImage, 
		and that in case of picon->presetaspect, the _apsect of the _pResourceImage as been 
		adjusted to match the picon->aspect. But since
		we didn't manage to do a case 2.3 bail in the initial loop, we know the _targetRect 
		doesn't match the size of the _pScaledImage.  There are two possibilities.  Either (2.2)
		targetRect is a legitimate size and we actually need a new _pScaledImage.
			Or maybe (2.1) targetRect is wrong because picon didn't know what it's shaped like yet.
		Tell the picon the correct aspect of the basic bitmap in case this is the very first time
		the picon is calling draw.  Also correct the targetRect to match the correct aspect. Note
		that the default starting aspect of picon was 1.0. 
			Of course in the case of picon->presetaspect, we shouldn't need to adjust pcion->aspect,
		but there could be some discrepancy due to round off, so back-correcting it here can't
		hurt. */
	if (!picon->imageloaded()) /* This means the picon has an _aspect
		that may not match the aspect of the image you loaded, and this  means that the aspect
		of the	targetRect doens't necessarily match the image.  Fix targetRect in here. */
	{
		int intcenterx, intcentery, intsizex, intsizey, intradiusx, intradiusy;
		intcenterx = targetRect.CenterPoint().x;
		intcentery = targetRect.CenterPoint().y;
		picon->setAspect(mapentry._aspect);
			/* The call to cSpriteIcon::setAspect will make the Real sizex and sizey of the 
			picon match the aspect. Now we have to convert those into correct pixel sizes. */
		_realpixelconverter.realToInt(picon->sizex(), &intsizex);
		_realpixelconverter.realToInt(picon->sizey(), &intsizey);
		intradiusx = intsizex/2;
		intradiusy = intsizey/2;
		targetRect = CRect(intcenterx - intradiusx, intcentery - intradiusy,
			intcenterx + intradiusx, intcentery + intradiusy);
		/* Now that we have a correct targetrect, we need to check again if maybe there was,
		after all, a mapentry with the matching resoruceID and targetrect.  We actually have
		to do the whole damn loop again! */
		for (i=0; i< cGraphicsMFC::_map_ResourceIDToScaledDC.GetSize(); i++)
			if (cGraphicsMFC::_map_ResourceIDToScaledDC[i].matchesResourceAndAspect(picon))
			{
				mapentry = cGraphicsMFC::_map_ResourceIDToScaledDC.GetAt(i); //Make a copy.
				if (mapentry.matchesTargetRect(targetRect))
				{//This is like Case 2.3 again, the easy case where you find just what you need.
					cGraphicsMFC::_map_ResourceIDToScaledDC.ElementAt(i)._lifespan =
						cMapEntry_ResourceIDToScaledDC::FRESHLIFESPAN;
					return mapentry._pScaledImage; //You're done!
				}
			}
	}
		/* If we get to this point, we are in case (1) or (2.2), and we need to fill in in the mapentry
		and add it.  Tell pmapentry about the targetRect. We don't preserve the corner of the target
		rect, only its size. */
	mapentry._targetRect = CRect(0, 0, targetRect.Width(), targetRect.Height());
		//Create a new _pScaledImage.
	if (picon->usesTransparentMask())
		mapentry._pScaledImage = new cTransparentMemoryDC();
	else
		mapentry._pScaledImage = new cMemoryDC();
	ASSERT(mapentry._pScaledImage);
		//Resize _pScaledImage to the targetRect dimension.
	mapentry._pScaledImage->setSize(mapentry._targetRect.Width(), mapentry._targetRect.Height());
		//Stretch _pResourceImage to _pScaledImage.
	mapentry._pResourceImage->stretchTo(mapentry._pScaledImage, mapentry._targetRect);
		/* This uses the whole sourceRect of the _pResourceImage and does a non-isometric strecth,
		But of course we've scaled the source and the target to have matching aspects, so it's ok
		to be non-isometric. */
	mapentry._lifespan = cMapEntry_ResourceIDToScaledDC::FRESHLIFESPAN;
		// Add mapentry to cGraphicsMFC::_map_ResourceIDToScaledDC
	cGraphicsMFC::_map_ResourceIDToScaledDC.Add(mapentry); //So you don't have to load it again.
		//You're done!
	return mapentry._pScaledImage;								
}

void cGraphicsMFC::drawbitmap(cSpriteIcon *picon, int drawflags )
{
	int intcenterx, intcentery, intsizex, intsizey, intradiusx, intradiusy;
	cVector transformcenter = _matrix*picon->center();
	_realpixelconverter.realToPixel(transformcenter.x(), transformcenter.y(), &intcenterx, &intcentery);
	_realpixelconverter.realToInt(picon->sizex(), &intsizex);
	_realpixelconverter.realToInt(picon->sizey(), &intsizey);
	intradiusx = intsizex/2;
	intradiusy = intsizey/2;
	CRect targetRect(intcenterx - intradiusx, intcentery - intradiusy,	intcenterx + intradiusx,
		intcentery + intradiusy);
	cMemoryDC *pScaledImage = (cMemoryDC *)(cGraphicsMFC::_getScaledImage(picon, targetRect)); 
//	cMemoryDC *pScaledImage = cGraphicsMFC::_getScaledImage(picon, targetRect); 
		/* Note
		that targetRect is passed as a reference to this call and its size and aspect
		will be changed to match the correct size and aspect of the sprite image after
		the bitmap is loaded. */ 
	if (!picon->imageloaded()) //One way or another, you've managed to load the image now.
		picon->setImageloaded(TRUE);
#ifdef DONTWIREFRAMEBITAPS //Defined (or not) in Graphics.h so that it applies to all cGraphics child classes.
		//If DONTWIREFRAMEBITAPS is on, we always jut do the next line. 
	pScaledImage->centeredPasteTo(_pMemDC, CPoint(intcenterx, intcentery));
#else //not DONTWIREFRAMEBITAPS means do a switch in here.
	if (!(drawflags & CPopView::DF_WIREFRAME))
		pScaledImage->centeredPasteTo(_pMemDC, CPoint(intcenterx, intcentery));
	else //Draw a hollow ellipse with XOR edge for transparent case
	{
		CBrush cbrush_hollow, *pbrush_old;
		CPen cpen_white, *ppen_old;
		int ROP2_old = _pMemDC->SetROP2(R2_XORPEN);
		cbrush_hollow.CreateStockObject(NULL_BRUSH);
		cpen_white.CreatePen(PS_SOLID, 1, RGB(255,255,255)); /* A pen to use
			for drawing a halo around a focus object. For XOR write to have
			the biggest effect, use a white pen color, as this gets XORed with
			the target pixels. */
		pbrush_old = _pMemDC->SelectObject(&cbrush_hollow);
		ppen_old = _pMemDC->SelectObject(&cpen_white);
		_pMemDC->Rectangle(&targetRect);
		int radius;
		_realpixelconverter.realToInt(picon->radius(), &radius);
		CRect touchcircle(intcenterx - radius, intcentery - radius,	intcenterx + radius,
			intcentery + radius);
		_pMemDC->Ellipse(&touchcircle);
		_pMemDC->SetROP2(ROP2_old);
		_pMemDC->SelectObject(pbrush_old);
		_pMemDC->SelectObject(ppen_old);
		cbrush_hollow.DeleteObject();
		cpen_white.DeleteObject();
	}
#endif //DONTWIREFRAMEBITAPS
}


