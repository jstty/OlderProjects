// GraphicsMFC.h : interface of the cGrpahicsMFC class
//
/////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICSMFC_H
#define GRAPHICSMFC_H

#include "graphics.h"
#include "realpixelconverter.h" //For _realpixelconverter.  RR.
#include "memorydc.h" //For _cMemDC

class cMatrixStack : private  CList<cMatrix, cMatrix> 
{
private:
	cMatrix _workingcopy;
public:
	cMatrixStack(){}//Defaults put identity in _workingcopy, have CList empty.
	~cMatrixStack(){RemoveAll();}
    // Add element to top of stack
    void push(){AddHead(_workingcopy);}
    // Pop top element off stack
    void pop(){if(!IsEmpty())_workingcopy = RemoveHead();}
	cMatrix& matrix(){return _workingcopy;}
};

class cMapEntry_ResourceIDToScaledDC
{
	friend class cGraphicsMFC;
	friend class cMap_ResourceIDToScaledDC;
	protected:
		static int FRESHLIFESPAN; /* How many updates you wait till killing an unused
			image off. Let's try 5. */
		static int SIZEJITTERLEVEL; /* Number of pixels a bitmap size  has to change before we
			do something about it.  We try 2. The sizes will vary below this level due to roundoff. */
		static Real ASPECTJITTERLEVEL; /* Amount of aspect by which a presetaspect cSpriteIcon has
			to change before we	do something about it.  We try 0.1. The sizes may vary below this
			level due to roundoff. */
	//members
		int _resourceID;
		Real _aspect;
		CRect _targetRect;
		cMemoryDC * _pResourceImage;
		cMemoryDC * _pScaledImage;
		int _lifespan;
	public:
	//methods
		cMapEntry_ResourceIDToScaledDC():_resourceID(-1), _aspect(1.0), _targetRect(0,0,0,0), 
			_pResourceImage(NULL), _pScaledImage(NULL), _lifespan(cMapEntry_ResourceIDToScaledDC::FRESHLIFESPAN){}
		BOOL matchesResourceAndAspect(cSpriteIcon *picon)const;
		BOOL matchesTargetRect(const CRect &targetRect)const;
		~cMapEntry_ResourceIDToScaledDC(){} /* Don't delete the pointers, as other
			cMapEntry_ResourceIDToScaledDC objects may be sharing use of them.  Leave
			the memory management to cMap_ResourceIDToScaledDC; */
};

class cMap_ResourceIDToScaledDC :
	public CArray<cMapEntry_ResourceIDToScaledDC, cMapEntry_ResourceIDToScaledDC&>
{
public:
	~cMap_ResourceIDToScaledDC(){free();}
	void garbageCollect();
	void free();
};
	/* Instead of a CArray as the map's base class, in the cGraphicsOpenGL we use a CMap.
		Here in cGraphicsMFC, the CArray seems better suited because we end up having to do
		a kind of triple-keyed search of the _map_ResourceIDToScaledDC in the _getScaledImage
		method, and implementing this for CMap would be a pain and possibly slower.  In any case
		the array is not very large (and doesn't GET large thanks to garbageCollect), 
		so this isn't a very important issue. */


class cGraphicsMFC : public cGraphics
{
	DECLARE_SERIAL(cGraphicsMFC)
protected:
	cMemoryDC *_pMemDC;
	cRealPixelConverter _realpixelconverter;
	//Matrix support.
	cMatrixStack _modelviewmatrixstack;
	cMatrixStack _projectionmatrixstack;
	cMatrixStack _texturematrixstack;
	cMatrix& _matrix;
	cMatrixStack *_pmatrixstack;
//cSpriteIcon and cSpriteIconBackground management stuff.
	static int INSTANCECOUNT; //See comment on _map_ResourceIDToScaledDC.
	static cMap_ResourceIDToScaledDC _map_ResourceIDToScaledDC; 
			/*  The _map_ResourceIDToScaledDC is static in cGraphicsMFC because the different
		cGraphicsMFC veiws	can share the cMemoryDC resources. 
		 (In cGraphicsOpenGL _map_ResourceIDToScaledDC is NOT static, because
		the pTexture objects are OpenGL texture objects similar to display lists, and these
		are specific to the OpenGL instance that they are created in.  So we can't share
		them across views.) Here in cGraphicsMFC, we will clear out the static _map_ResourceIDToScaledDC
		array when the last cGraphicsMFC object is destroyed.  In order to notice when the
		last one goes, we need to track a static INSTANCECOUNT that tells how many
		cGraphicsMFC have been opened.*/
public:
	cGraphicsMFC();
	virtual ~cGraphicsMFC();
	virtual BOOL is3D(){return FALSE;} 
//Special overloads
	virtual void garbageCollect(); /*Release all the not-recently-used 
		stored textures and displaylist IDs. */
	virtual void free(); /* Release all the stored textures and 
		displaylist IDs */
	virtual void display(CView *pview, CDC *pDC); /* The GraphicsMFC checks if pview is a CPopView,
		and if so, it draws the hollow border box on top. */
	virtual void setRealBox(cRealBox border);
	virtual void setClearColor(COLORREF colorref);
	virtual void clear(const CRect &clearrect);
	virtual void vectorToPixel(cVector position, int &xpix, int &ypix, Real &zbuff);
	virtual cVector pixelToVector( int xpix, int ypix, Real zbuff = 0.0);
	virtual cLine pixelToSightLine(int xpix, int ypix);
//Matrix Method overloads
	virtual void matrixMode(MATRIXMODE mode);
	virtual void loadMatrix(cMatrix &matrix){_matrix.copy(matrix);}
	virtual void loadIdentity(){_matrix.identity();}
	virtual void pushMatrix(){_pmatrixstack->push();}
	virtual void popMatrix(){_pmatrixstack->pop();}
	virtual void multMatrix(cMatrix &rightmatrix){_matrix*=rightmatrix;}
	virtual void translate(cVector translation){_matrix.translate(translation);}
//Projection matrix overloads.
	virtual void ortho(Real left, Real right, Real bottom, Real top, Real nearzclip, Real farzclip);
	/* We haven't implement perspective(Real fieldofviewangleinradians, Real xtoyaspectratio,
		Real nearzclip,	Real farzclip) for cGraphicsMFC, yet, thethe do-nothing base method 
		remains in place. At the very least we should generate a call to setRealWindow like ortho.
		Effectively our ortho and pesprecive projections just ignores the z coordinate.  Maybe later
		we'll fix perspective projection for cGraphicsMFC later too. */
//Graphics drawing overloads
	//cMemoryDC* _getScaledImage(cSpriteIcon *picon, CRect &targetRect);
	virtual void* _getScaledImage(cSpriteIcon *picon, CRect &targetRect);
	virtual void setViewport(int width, int height);
	virtual void drawline(cVector posa, cVector posb, cColorStyle *pcolorstyle); //reallinewidth 0 means 1 pixel wide.
	virtual void drawrectangle(const cVector &corner0, const cVector &corner1,
		const cVector &corner2, const cVector &corner3,
		cColorStyle *pcolorstyle, int drawflags);
	virtual void drawcircle(const cVector &center, Real radius, cColorStyle *pcolorstyle,
		int drawflags);
	virtual void drawpolygon(cPolygon *ppolygon, int drawflags );
	virtual void drawstarpolygon(cPolygon *ppolygon, int drawflags )
		{drawpolygon(ppolygon, drawflags);} //MFC is ok with non-convex polygons.
	virtual void drawbitmap(cSpriteIcon *picon, int drawflags);
	virtual void drawtext(CString string, int pixx, int pixy);
//Other graphics overloads
	virtual void setClipRegion(cRealBox *pclipbox);
//Special cGraphicsMFC helper
	//virtual void realToPixel(cSprite *psprite);

public:
	virtual COLORREF sniff(cVector sniffpoint); /* Find the pixel color corresponding to a given location
			in the world of the game. Can be used by critters to see what they're standing on. */
};

#endif GRAPHICSMFC_H