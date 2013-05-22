
// Graphics.h : interface of the cGraphics class
//
/////////////////////////////////////////////////////////////////////////////
/*  This is a base class used to derive cGraphicsMFC and cGraphicsOpenGL from.
Theoretically I could try and support four modes: 2D OpenGL, 2D MFC, 3D OpenGL, and 3D MFC.  For sanity's
sake, I'm going to only guarantee support for two modes: 2D MFC and 3D OpenGL.
	This said, OpenGL does in fact work in 2D, but on many machines it will run slower than MFC graphics.
So it's good to have the MFC fallback.  
	Certainly OpenGL is slower on a system that is not using hardware OpenGL acceleration. 
(Note that to get acceleration, you (a) have to have a graphics card with an OpenGL acceleator and 
(b) have to have your machine set to a graphics mode in which the card accelerates OpenGL: normally 
16-bit color (65K colors) or "True Color" are accelerated, but other modes may not be. You can tell
if you are getting hardware acceleration by looking at the messsages in the Output window when running
in the Debug mode.  If the message says you are using an OpenGL implementation by Microsoft, then
you aren't getting acceleration, if the message says  you are using an implmenetation by the
maker of your graphics card, then you are getting accelerationg.  See
http://www.opengl.org/developers/faqs/technical/mswindows.htm for more about getting hardware acceleration.
	MFC graphics could be made to work in 3D, I haven't added the necessary machinery to it; given that
OpenGL is a fullfeatured 3D library, why reinvent the wheel. 
	Eventually it would be nice to allow the use of DirectX graphics as another option. */

#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "vectortransformation.h"
#include "realbox.h"
#include "quakeMD2model.h" 
	//For the vector_t type, which I should replace with cVector
#include "texture.h" //For the cTexture *_ptextureactive field.

#define DONTWIREFRAMEBITAPS 
	/* If the DONTWIREFRAMEBITAPS define switch is on we never make an effort
	to "wireframe" a bitmap sprite by, say drawing a hollow rectangle.  In fact this always looks bad,
	so it's much better to leave this switch on.  The DONTWIREFRAMEBITAPS is used both in 
	graphicsopengl.cpp and graphicsmfc.cpp. It's useful to turn on only for debugging. */

class cRealBox2;
class cRealBox3;
class cPolygon;
class cSprite;
class cSpriteIcon;
class cSpriteIconBackground;
class cColorStyle;
class cCritter;
class CPopView;
class cLightingModel;
class cMD2Model;

class cGraphics : public CObject
{
	DECLARE_SERIAL(cGraphics)
public:
	static const enum MATRIXMODE {MODELVIEW, PROJECTION, TEXTURE};
protected:
	CView *_pownerview; /* This is a reference that cGraphicsOpenGL might use. */
	cTexture *_ptextureactive;
public:
	cGraphics():_pownerview(NULL),_ptextureactive(NULL){}
	virtual ~cGraphics(){_ptextureactive = NULL;} /* Don't need to delete
		the texture as the garbage collection will have done that. */
	virtual void setOwnerView(CView *pview){_pownerview = pview;}
	virtual BOOL is3D(){return FALSE;} /* This will return TRUE for cGraphics classes which
		render in 3D and for which the viewpoint does more than stare straight down ortho style. */
//Hooks for Windows MFC
//Matrix Methods
	virtual void matrixMode(MATRIXMODE mode){}
	virtual void loadMatrix(cMatrix &matrix){}
	virtual void loadIdentity(){}
	virtual void pushMatrix(){}
	virtual void popMatrix(){}
	virtual void multMatrix(cMatrix &rightmatrix){}
	virtual void translate(cVector translation){}
//Perspective Matrix methods
	virtual void ortho(Real left, Real right, Real bottom, Real top, Real nearzclip, Real farzclip){}
	virtual void perspective(Real fieldofviewangleindegrees, Real xtoyaspectratio, Real nearzclip, Real farzclip){}
	virtual void frustum(Real l, Real r, Real b, Real t, Real n, Real f) {}
//Special Methods
	virtual void garbageCollect(){} /*Release all the not-recently-used 
		stored textures and displaylist IDs. */
	virtual void free(){} /* Release all the stored textures and 
		displaylist IDs */
	virtual void activate(){}
	virtual void display(CView *pview, CDC *pDC){} /* Pass the CView in case you need some
		info from the document for the display. */
	virtual void setRealBox(cRealBox border){}
	virtual void setClearColor(COLORREF colorref){}
	virtual void clear(const CRect &clearrect){}
	virtual void vectorToPixel(cVector position, int &xpix, int &ypix, Real &zbuff){}
	virtual cVector pixelToVector( int xpix, int ypix, Real zbuff = 0.0){return cVector();}
	virtual cLine pixelToSightLine(int xpix, int ypix); /* This is a line that runs
		from the viewer's eye to the direction matching the pixel point. This whole line is
		projected as a point at the pixel point.  When pickign a critter, we look for the ones
		close to the pixelToSightLine for the screen pick pixel. I put in a default implementation
		to do it the "right" way in 3D, and I overload this for cGrahicsMFC to make 
		the  direction of the line just be the negative Z axis. */
	cVector pixelAndPlaneToVector( int xpix, int ypix, const cPlane &plane); /* This 
		method unprojects to the near and far possiblities for the pixel position, draws the "sight
		line" between the two (I call it a "sight line" because these are all positions that 
		get projected into the same pixel), and finds the point where the line crosses the plane.
		This method is useful if you know what plane you are trying to pick in; often, for instance,
		you want to pick a point in the plane of the player. It uses the virtual pixelToSightLine
		method. */	
	CRect realBoxToCRect(const cRealBox &realbox);
	virtual COLORREF sniff(cVector sniffpoint){return RGB(0,0,0);}
//Texture methods
	cTexture* activeTexture(){return _ptextureactive;}
	virtual BOOL selectTexture(cTexture *ptexture){return FALSE;} /* Returns
		TRUE if the texture is selected, returns FALSE if either the ptexture is
		NULL or if an equivalent texture was already active so ptexture
		didn't need to be selected. */
//Graphics overloadables
	virtual void setViewport(int width, int height){} /* CPopView calls this in OnSize to set the
		pixel size of the view window. */
	virtual void adjustAttributes(cSprite *psprite){}; /* You may want to adjust things like
		activation of texture or lighting depending on the sprite. */
	virtual void setMaterialColor(COLORREF color, Real alpha = 1.0){}
	virtual void setMaterialColorFrontAndBack(COLORREF color, Real alpha = 1.0){}
	virtual void drawline(cVector posa, cVector posb, cColorStyle *pcolorstyle){} //reallinewidth 0 means 1 pixel wide.
	void drawXYrectangle(const cVector &cornerlo, const cVector &cornerhi, cColorStyle *pcolorstyle,
		int drawflags); /* Turns the 2 points into 4 and calls the virtual
		drawrectangle method that uses four corners.  The 2 corner call assumes
		the rectangle has its z values averaged between
		cornerlo and cornerhi and traverses the 4 corners starting out heading from 
		cornerlo.x() to cornerhi.x(). */
	virtual void drawrectangle(const cVector &corner0, const cVector &corner1,
		const cVector &corner2, const cVector &corner3,
		cColorStyle *pcolorstyle, int drawflags){} //Defined in indivdiual graphics files.
	virtual void drawcircle(const cVector &center, Real radius, cColorStyle *pcolorstyle,
		int drawflags){}
	virtual void drawpolygon(cPolygon *ppolygon, int drawflags ){}
	virtual void drawstarpolygon(cPolygon *ppolygon, int drawflags){};
		//Need to handle non-_convex polygons differently in OpenGL
	virtual void drawbitmap(cSpriteIcon *picon, int drawflags){}
	virtual void selectSkinTexture(cMD2Model *pmodel){}
	virtual void interpolateAndRender(cMD2Model *pmodel,
		vector_t *startframe, vector_t *endframe, float interpolationpercent){}
	virtual void drawtext(CString string, int pixx = 100, int pixy = 100){}
//cGraphics text overloads
	virtual void use3DText(BOOL yesno){}
//cGraphics Lighting overloads
	virtual void installLightingModel(cLightingModel *plightingmodel = NULL){}
		/* This gets called by CPopView::setGraphicsClass in the form
		pgraphics()->installLightingModel(pgame()->plightingmodel()).  For now, 
		installLightingModel does nothing in MFC and sets up some default standard
		lights in OpenGL.  Eventually the cLightingModel will have useful fields,
		but at present all it has is a BOOL _enablelighting. I only have the
		default NULL argument so I can call this in the cGraphicsOpenGL constructor. */
	virtual void enableLighting(BOOL onoff){} /* Use enableLighting to turn on and off the OpenGL 
		lighting model. */
//Display list overloads
	virtual BOOL supportsDisplayList(){return FALSE;}
	virtual BOOL activateDisplayList(cSprite *psprite){return FALSE;} /* In sophisticated graphics
		implementations, this call gets an unsigned int _activeDisplayListID based on the
		psprite's spriteID and newgeometryflag.  If the list has already been recorded,	we set 
		a BOOL _activeDisplayListIDIsReady to TRUE, otherwise we set _activeDisplayListIDIsReady 
		to FALSE.  And then we return _activeDisplayListIDIsReady. If the return is FALSE,
		you need to call a drawsomething method before calling callActiveDisplayList. */
	virtual void callActiveDisplayList(cSprite *psprite){} /* In sophisticated graphics
		implementations, if _activeDisplayListIDIsReady is FALSE, we close the list and 
		add it to the _map_SpriteIDToDisplayListID.  And then in any case we call
		a graphics method to call the list. */
//Other graphics overloads
	virtual void setClipRegion(cRealBox *pclipbox){}
};

/* The cLightingModel prototype below is just a start on the class.
Eventually it should have information about the locations of lights,
the ambient, diffuse, and specular paraemters for their three colors.
I think the materials parameters need to be part of cColorStyle.
cLightingModel should have params for all the calls now made in the 
cGraphicsOpenGL::installLightingModel(cLightingModel *plightingmodel).
*/
class cLightingModel : public CObject
{
	DECLARE_SERIAL(cLightingModel)
protected:
	BOOL _enablelighting;
public:
	cLightingModel(BOOL enablelighting = TRUE):_enablelighting(enablelighting){}
	BOOL enableLighting()const{return _enablelighting;}
	void setEnableLighting(BOOL enablelighting){_enablelighting = enablelighting;}
	void Serialize(CArchive& ar);
};

#endif //GRAPHICS_H