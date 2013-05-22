// GraphicsOpenGL.h : interface of the cGraphicsOpenGL class
//
/////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_OPENGL
#define GRAPHICS_OPENGL
/*
	The OpenGL code in this module is inspired by code in Ron Fosner, "OpenGL Programming for 
Windows 95 and Windows NT", (Addison-Wesley 1997).  Similar code can also be found in
the online MSDN "Guide to OpenGL" that comes with Visual C++.
	Note that OpenGL is likely to run too slow for videogames on a system that is not using hardware
OpenGL acceleration. To get acceleration, you (a) have to have a graphics card with an OpenGL 
acceleator and (b) have to have your machine set to a graphics mode in which the card accelerates 
OpenGL: normally 16-bit color (65K colors) or "True Color" are accelerated, but other modes may not be. 
	You can tell if you are getting hardware acceleration by looking at the messsages in the Output window 
when running in the Debug mode.  If the message says you are using an OpenGL implementation by Microsoft,
then you aren't getting acceleration, if the message says  you are using an implmenetation by the
maker of your graphics card, then you are getting acceleration.  (These messages are output by
TRACE statements inside our cGraphicsOpenGL::initializeOpenGL method.)
	See http://www.opengl.org/developers/faqs/technical/mswindows.htm for more info about getting
hardware acceleration.
*/

#include "graphics.h"
#include "texture.h" //For cTexture, used in cMapEntry_ResourceIDToTexture
#include "sprite.h" //for cSprite::INVALIDID

// Include the OpenGL headers
#include "gl\gl.h"
#include "gl\glu.h"
/* For now, we're not using glaux as it seems buggy, and we don't use the SGI-written
glut as it's so Windows-hostile.  We do however, use some glut code which we've put into
the file glut_shapes.cpp. The methods of this file are prototyped in glshapes.h */
#include "glshapes.h"
	/* GLUT pre-built models sub-API */

//==========ResourceID
class cMapEntry_ResourceIDToTexture
{
	friend class cMap_ResourceIDToTexture;
	protected:
		static int FRESHLIFESPAN; /* How many updates you wait till killing an unused
			image off. Let's try 5. */
	//members
		cTexture *_pTexture;
		int _lifespan;
	public:
	//methods
		cMapEntry_ResourceIDToTexture():
			_pTexture(NULL),_lifespan(cMapEntry_ResourceIDToTexture::FRESHLIFESPAN){}
		cMapEntry_ResourceIDToTexture(cTexture *ptex):
			_pTexture(ptex),_lifespan(cMapEntry_ResourceIDToTexture::FRESHLIFESPAN){}
		~cMapEntry_ResourceIDToTexture(){} /* Don't delete the texture as possibly
			some other cMapEntry_ResourceIDToTexture is using it as well. */
};

class cMap_ResourceIDToTexture: 
	public CMap<int, int, cMapEntry_ResourceIDToTexture*, cMapEntry_ResourceIDToTexture*>
{
public:
	cTexture* lookupTexture(unsigned long resourceID)
	{
		cMapEntry_ResourceIDToTexture *pmapentry = NULL;
		if (!Lookup(resourceID, pmapentry)) //The base CMap Lookup.
			return NULL; //No texture found.
		else
		{
			pmapentry->_lifespan = cMapEntry_ResourceIDToTexture::FRESHLIFESPAN;
				//So garbageCollect knows this texture is worth keeping around.
			return pmapentry->_pTexture;
		}
	}
	void garbageCollect();
	void free();
	~cMap_ResourceIDToTexture(){free();}
};

//=========SkinFileID
class cMapEntry_SkinFileIDToTexture
{
	friend class cMap_SkinFileIDToTexture;
	protected:
		static int FRESHLIFESPAN; /* How many updates you wait till killing an unused
			skin texture off. Let's try 20. */
	//members
		cTexture *_pTexture;
		int _lifespan;
	public:
	//methods
		cMapEntry_SkinFileIDToTexture():
			_pTexture(NULL),_lifespan(cMapEntry_SkinFileIDToTexture::FRESHLIFESPAN){}
		cMapEntry_SkinFileIDToTexture(cTexture *ptex):
			_pTexture(ptex),_lifespan(cMapEntry_SkinFileIDToTexture::FRESHLIFESPAN){}
		~cMapEntry_SkinFileIDToTexture(){} /* Don't delete the texture as possibly
			some other cMapEntry_SkinFileIDToTexture is using it as well. */
};

class cMap_SkinFileIDToTexture: 
	public CMap<int, int, cMapEntry_SkinFileIDToTexture*, cMapEntry_SkinFileIDToTexture*>
{
public:
	cTexture* lookupTexture(unsigned long skinFileID)
	{
		cMapEntry_SkinFileIDToTexture *pmapentry = NULL;
		if (!Lookup(skinFileID, pmapentry)) //The base CMap Lookup.
			return NULL; //No texture found.
		else
		{
			pmapentry->_lifespan = cMapEntry_SkinFileIDToTexture::FRESHLIFESPAN;
				//So garbageCollect knows this texture is worth keeping around.
			return pmapentry->_pTexture;
		}
	}
	void garbageCollect();
	void free();
	~cMap_SkinFileIDToTexture(){free();}
};

//==========SpriteID
class cMapEntry_SpriteIDToDisplayListID
{
	friend class cMap_SpriteIDToDisplayListID;
	protected:
		static int FRESHLIFESPAN; /* How many updates you wait till killing an unused
			displayListID off. Let's try 50. */
	//members
		GLuint _displayListID;
		int _lifespan;
	public:
		cMapEntry_SpriteIDToDisplayListID():
			_displayListID(0), //0 is cGraphicsOpenGL::INVALIDDISPLAYLISTID)
			_lifespan(cMapEntry_SpriteIDToDisplayListID::FRESHLIFESPAN){} 
		cMapEntry_SpriteIDToDisplayListID(int displayListID):
			_displayListID(displayListID),
			_lifespan(cMapEntry_SpriteIDToDisplayListID::FRESHLIFESPAN){}
		~cMapEntry_SpriteIDToDisplayListID(){}
};

class cMap_SpriteIDToDisplayListID : 
	public CMap<unsigned long, unsigned long, cMapEntry_SpriteIDToDisplayListID*,
		cMapEntry_SpriteIDToDisplayListID*>
{
public:
	GLuint lookupDisplayListID(unsigned long spriteID)
	{
		cMapEntry_SpriteIDToDisplayListID *pmapentry;
		if (!Lookup(spriteID, pmapentry)) //The base CMap Lookup.
			return 0; //0 is cGraphicsOpenGL::INVALIDDISPLAYLIST;
		else
		{
			pmapentry->_lifespan = cMapEntry_SpriteIDToDisplayListID::FRESHLIFESPAN;
				//So garbageCollect knows this texture is worth keeping around.
			return pmapentry->_displayListID;
		}
	}
	void free();
	void garbageCollect();
	~cMap_SpriteIDToDisplayListID(){free();}
};

class cGraphicsOpenGL : public cGraphics
{
	DECLARE_SERIAL(cGraphicsOpenGL);
//==============Some useful Statics============================
public:
//Static tracker of which graphics is receiving has control of the OpenGL calls.
	static unsigned int INSTANCECOUNT;
	static unsigned int ACTIVEID;
	/* What we do here is to give each cGraphicsOpenGL an _instanceID, starting with
	1 and increasing up from there as long as a given app runs.  We use the 
	static INSTANCECOUNT to track the values so we don't reuse an ID.  It turns out
	not to be a good idea to use the "this" pointer as an identifier for an
	object because if an object is deleted the same pointer may well be recycled
	and attached to a fresh instance.  By using INSTANCECOUNT we ensure that 
	_instanceID is unique.  (And if INSTANCECOUNT ever wraps around to zero we
	trigger an errormessage.) We use the ACTIVEID to track which 
	OpenGL rendering context is currently active and receiving the OpenGL calls. 
	This is important when you have more than one view of your game, as then you
	have to keep swapping back and forth with the activate() call. */
//Static information about the graphics mode you're in.
	static CString _graphicsmodestring;
	static CString _vendorstring;
	static CString _rendererstring;
	static CString _driverstring;
    static CStringArray _extensionstringArray; /* array of all available OpenGL extensions, 
		for this card, neatly parsed */
	static BOOL FIRSTTIME; /*Can use this to pop up an info dialog first time you show OpenGL
		graphics, also to dump first time info to the Output window in the debug build. */
//Helper
	enum errorType{ NONE, GETDC, CHOOSEPIXELFORMAT, SELECTPIXELFORMAT,
				 CREATECONTEXT, MAKECURRENT, DELETECONTEXT, SWAPBUFFERS, BADID }; //Similar to static.
	static int DEFAULT_LINEPIXELS; /* Thickness for lines, until I think of a way to use a
		reallinewidth parameter. */
	static unsigned long INVALIDDISPLAYLISTID; //This shadows cGraphics::INVALIDDISPLAYLISTID
 	static const char* const _errorStrings[]; /* A list of standard error messages.  Use this
		funky type instead of CStringArray so we can manually initailize it. */
protected:
//Essential members
	CDC *_pDCview;
	int	_pixelFormatIndex;
	HGLRC _hRenderingContext;
	unsigned int _instanceID; /* See comment on INSTANCECOUNT and ACTIVEGRAPHICSID above. */
//Maps
	cMap_SpriteIDToDisplayListID _map_SpriteIDToDisplayListID;
	cMap_ResourceIDToTexture _map_ResourceIDToTexture;
	cMap_SkinFileIDToTexture _map_SkinFileIDToTexture;
		/* The analagous _map is static in cGraphicsMFC because the different cGraphicsMFC veiws
		can share the cMemoryDC resources.  In cGraphicsOpenGL _map_ResourceIDToTexture
		is NOT static, because the pTexture objects are OpenGL texture objects similar to 
		display lists, and these are specific to the OpenGL instance that they are created in.
		 So we can't share them across views. */
//Fields for recording displaylists
	GLuint _activeDisplayListID;
	BOOL _activeDisplayListIDIsReady;
// Information about the last error.
	CString	_errorString;  // holds the last wgl/OGL error found
//Font Fields
	BOOL _initializedDefaultFonts;
	GLuint _defaultTextID, _default3DTextID, _defaultFlatTextID;
//Special helper methods
	virtual BOOL setupPixelFormat(HDC hdc);
	BOOL initializeOpenGL(CView *pview);
	void setError( int e );
    void fetchExtendedInformation();
public:
// Routines that draw the three axis lines
	void draw3DAxes(float start = -10.0, float finish = 10.0, int ticks = -1);
	void draw3DAxesLine(float start, float finish,	int axis_id, int ticks);
	// The increments are in 5ths of the maximum allowable values
// The Font Member Functions
	virtual void setDefaultFonts( char* font3D = "Arial", 
		char* fontFlat = "Arial")
		{generateDefaultFonts(font3D, fontFlat);}
	void textOut(const char * const textstring, GLuint id = -1);
		/* our default textOut second arg -1 is a flag to use
			the default bitmapped font startng at _defaultFlatTextID*/
	GLuint generateBitmapListForFont(char* fontname);
	GLuint generateDisplayListForFont(char*, double xt = 0.1f);
	void generateDefaultFonts(char*, char*);

//========================================cGraphics Overloads==========================
public:
	cGraphicsOpenGL();
	virtual ~cGraphicsOpenGL();
	virtual BOOL is3D(){return TRUE;} 
//cGraphics overloads
	virtual void garbageCollect(); /*Release all the not-recently-used 
		stored textures and displaylist IDs. */
	virtual void free(); /* Release all the stored textures and 
		displaylist IDs */
	virtual void setOwnerView(CView *pview); /* Calls initializeOpenGL and
		if the first time, displays the OpenGL driver info. We don't call
			initializeOpenGL in the constructor because it needs a
			pview argument that contains contain a valid view.  We wait and call
			setOwnerView after the CPopView is initialized, for instance
			in CPopView::OnCreate, or perhaps in response to a menu request
			to change graphics styles. */
	virtual void vectorToPixel(cVector position, int &xpix, int &ypix, Real &zbuff);
	virtual cVector pixelToVector( int xpix, int ypix, Real zbuff = 0.0);
		 /* Note that the cGraphicsOpenGL::pixelToVector method is not all that accurate, and tends
		to be off by about 1%.  You shouldn't depend on it being an exact inverse of vectorToPixel. */
//cGraphics message handling overloads
	virtual void activate();
	virtual void display(CView *pview, CDC* pDC); 
//Matrix Method overloads
	virtual void matrixMode(MATRIXMODE mode)
		{(mode==MODELVIEW)?(::glMatrixMode(GL_MODELVIEW)):
		(mode==PROJECTION)?(::glMatrixMode(GL_PROJECTION)):
		(::glMatrixMode(GL_TEXTURE));}
	virtual void loadMatrix(cMatrix &matrix)
		{::glLoadMatrixf(cMatrix3(matrix).transpose().elements());}
	virtual void loadIdentity(){::glLoadIdentity();}
	virtual void pushMatrix(){::glPushMatrix();}
	virtual void popMatrix(){::glPopMatrix();}
	virtual void multMatrix(cMatrix &rightmatrix)
		{::glMultMatrixf(cMatrix3(rightmatrix).transpose().elements());}
	virtual void translate(cVector translation)
		{::glTranslatef(translation.x(),translation.y(),translation.z());} 
//Projection matrix methods.
	virtual void ortho(Real left, Real right, Real bottom, Real top, Real nearzclip, Real farzclip)
		{::glOrtho(GLdouble(left), GLdouble(right), GLdouble(bottom),
			 GLdouble(top), GLdouble(nearzclip), GLdouble(farzclip));}
	virtual void perspective(Real fieldofviewangleindegrees, Real xtoyaspectratio,
		Real nearzclip, Real farzclip)
		{::gluPerspective(GLdouble(fieldofviewangleindegrees),
		GLdouble(xtoyaspectratio), GLdouble(nearzclip), GLdouble(farzclip));}
	virtual void frustum(Real l, Real r, Real b, Real t, Real n, Real f)
		{::glFrustum(l, r, b, t, n, f);}
//cGraphics drawing overloadso
	cTexture* _getTexture(cSpriteIcon *picon);
	virtual void setViewport(int width, int height);
	virtual void drawline(cVector posa, cVector posb, cColorStyle *pcolorstyle); //reallinewidth 0 means 1 pixel wide.
	virtual void drawrectangle(const cVector &corner0, const cVector &corner1,
		const cVector &corner2, const cVector &corner3,
		cColorStyle *pcolorstyle, int drawflags);
	virtual void drawcircle(const cVector &center, Real radius, cColorStyle *colorstyle,
		int drawflags);
	virtual void drawpolygon(cPolygon *ppolygon, int drawflags );
	virtual void drawstarpolygon(cPolygon *ppolygon, int drawflags);
	virtual void drawbitmap(cSpriteIcon *picon, int drawflags);
	virtual void drawtext(CString string, int pixx, int pixy);

//Tetxture Overloads
	virtual void adjustAttributes(cSprite *psprite); /* You may want to adjust things like
		activation of texture or lighting depending on the sprite. */
	virtual BOOL selectTexture(cTexture *ptexture); /* Returns
		TRUE if the texture is selected, returns FALSE if either the ptexture is
		NULL or if an equivalent texture was already active so ptexture
		didn't need to be selected. */

//Special MD2 Methods
	virtual void selectSkinTexture(cMD2Model *pmodel);
	virtual void interpolateAndRender(cMD2Model *pmodel,
		vector_t *startframe, vector_t *endframe, float interpolationpercent);



//cGraphics Lighting overloads
	virtual void installLightingModel(cLightingModel *plightingmodel = NULL);
		/* This gets called by CPopView::setGraphicsClass in the form
		pgraphics()->installLightingModel(pgame()->plightingmodel()).  For now, 
		installLightingModel does nothing in MFC and sets up some default standard
		lights in OpenGL.  Eventually the cLightingModel will have useful fields,
		but at present all it has is a BOOL _enablelighting. I only have the
		default NULL argument so I can call this in the cGraphicsOpenGL constructor. */
	virtual void enableLighting(BOOL onoff); /* Use enableLighting to turn on and off the OpenGL 
		lighting model. */
//Display list overloads
	virtual BOOL supportsDisplayList(){return TRUE;}
	virtual BOOL activateDisplayList(cSprite *psprite); /* This call gets an
		_activeDisplayListID based on the psprite's spriteID and newgeometryflag.  If the
		list has already been recorded,	we set _activeDisplayListIDIsReady to TRUE,
		otherwise we set _activeDisplayListIDIsReady to FALSE.  And then we return
		_activeDisplayListIDIsReady. If the return is FALSE, you need to call a drawsomething
		method before calling callActiveDisplayList. */
	virtual void callActiveDisplayList(cSprite *psprite); /* If _activeDisplayListIDIsReady is
		FALSE,	we close the list and add it to the _map_SpriteIDToDisplayListID.  And then in
		any case we call ::glCallList(_activeDisplayListID). */
//Other graphics overloads
	virtual void setClearColor(COLORREF colorref);
	virtual void clear(const CRect &clearrect);
	virtual void setClipRegion(cRealBox *pclipbox){}
	virtual void setMaterialColor(COLORREF color, Real alpha = 1.0); 
	virtual void setMaterialColorFrontAndBack(COLORREF color, Real alpha = 1.0); 
	virtual void use3DText(BOOL yesno)
		{yesno?_defaultTextID=_default3DTextID:_defaultTextID=_defaultFlatTextID;}
//cGraphicsOpenGL methods that haven't been migrated into cGraphics yet...
//Color methods
	void setVertexColor(COLORREF color, float alpha = 1.0);
	void setVertexColorDim(COLORREF color, float dimfactor = 0.5, float alpha = 1.0);
		 //Set a color but reduce all intensity by dimfactor.
	void setMaterialColorDim(COLORREF color, float dimfactor = 0.5);
//String method
	const char* getString(GLenum theEnum); //For getting strings from OpenGL
//Vertex methods
#ifdef USEFLOAT
	void setGLVertex(cVector2 vert){::glVertex2f(vert.x(), vert.y());} //Assumes float.
	void setGLVertex(cVector3 vert)
		{::glVertex3f(vert.x(), vert.y(), vert.z());} //Assumes float.
#else //not USEFLOAT means using double
	void setGLVertex(cVector2 vert){::glVertex2d(vert.x(), vert.y());} //Assumes float.
	void setGLVertex(cVector3 vert)
		{::glVertex3d(vert.x(), vert.y(), vert.z());} //Assumes float.
#endif //USEFLOAT switch
};

#endif //GRAPHICS_OPENGL