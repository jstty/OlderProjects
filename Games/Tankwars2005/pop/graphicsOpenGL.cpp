 
// graphicsOpenGL.cpp implemenation of the cGraphicsOpenGL class
//
#include "stdafx.h"
#include "ChildFrm.h" //For CChildFrame class to use _cSplitterWnd.  RR.
#include "game.h"
#include "listener.h"
#include "MainFrm.h" //For CMainFrame class to call SetMessageText.  RR.
#include "Pop.h"
#include "PopView.h"
#include "graphicsopengl.h"
#include "spritepolygon.h"
#include "spriteicon.h"
#include "spritequake.h"
#include "glext.h" /* This is for using OpenGL methods higher than
	those in the Version 1.1 that Windows supports.  I downloaded
	this file from SGI
	http://oss.sgi.com/projects/ogl-sample/ABI/glext.h
	and I found out about it at
	http://www.gamedev.net/reference/programming/features/oglext/
	after google searching for "Windows OpenGL 1.2" 
	The glext.h has a bunch of typedef that make it easy to 
	use OpenGL extensions.  We use the higher-than-1.1 functions
	as extensions. I initially got into this because I wanted to
	call the OpenGL 1.2 method glLightModeli(
		GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
*/

cGraphicsOpenGL *open_gfx = NULL;

// add support for OpenGL 1.1 if we're using an old header
// These are new PIXELFORMATDESCRIPTOR flags for OpenGL 1.1
#ifndef PFD_GENERIC_ACCELERATED
#define PFD_GENERIC_ACCELERATED		0x00001000
#endif
#ifndef PFD_DEPTH_DONTCARE
#define PFD_DEPTH_DONTCARE			0x20000000
#endif
#define INSTALLABLE_DRIVER_TYPE_MASK  (PFD_GENERIC_ACCELERATED|PFD_GENERIC_FORMAT)

IMPLEMENT_SERIAL(cGraphicsOpenGL, cGraphics, 0)

//Invent a type GL_REAL to stand for float or real.
#ifdef USEFLOAT //The USEFLOAT is defined or not in realnumber.h
	#define GL_REAL GL_FLOAT
#else //not USEFLOAT
	#define GL_REAL GL_DOUBLE
#endif //USEFLOAT
//#define TRACEPIXELTOVECTOR
	/* Comment in TRACEPIXELTOVECTOR to debug a conversion routine by 
	printing trace info to the output window. */
#define GLCIRCLESLICES 16
	/* Approximate a circle by a polygon with GLCIRCLESLICES vertices.  Reduce the nubmer
	to pick up speed at the cost of smoothness of form. */
#define TRACEGRAPHICSINFOTOOUTPUT
	/* If we comment in TRACEGRAPHICSINFOTOOUTPUT, then we see some info about the OpenGL graphics
	in the output window.  In the past this was a cause of a Debug build crash problem as the
	extensions strings overwhelmed TRACE with good video cards in which the extensions descriptions
	added up to more tha 512 char, the max allowed by TRACE.  But this problem has been fixed. */
#define DISABLEATTRIBUTESFORLINES
	/* We use DISABLEATTRIBUTESFORLINES because if we use colored lighting
		on lines, they tend not to have colors consistent with what we'd like.
		And if texture is on, the lines don't show up at all.  So we disable
		lighting and texture when drawing lines. But doing this seems to
		mess up the lighting, so I'm not doing it now. */
// modified by: Joseph E. Sutton
#define NUMBEROFLIGHTS 1//4
	/* This can presently be a number from 1 to 4. (Numbers less than 1 are treated as 1, numbers
		greater than 4 are treated as 4.) I have the NUMBEROFLIGHTS as a way to easily test if
		having more lights slows me down. Seemingly it does NOT slow you down to have more lights,
		although if your OpenGL game is slow, you may want to double check this. */
#define INITIALIZEWITHALPHABLEND
	/* Turn on alpha blending at start up the time to have transparent objects. 
	This is effectively overridden by the adjustAttribute method now, which
	calls cSprite::usesAlpha() for each sprite.  This  means that 
	if you want to use alpha on a sprite, you have to change or overload
	the cSprite::usesAlpha() method to return TRUE. */
#define GARBAGECOLLECTTEXTURES
	/* If GARBAGECOLLECTTEXTURES defined, then if a shared pTexture resource 
	has been around and unused for too many updates (as specified in the
	FRESHLIFESPAN statics defined below, that is, we use a
	cMapEntry_ResourceIDToTexture::FRESHLIFESPAN for resource-based textures
	and a cMapEntry_SkinFileIDToTexture::FRESHLIFESPAN for skinfile-based
	textures), we get rid of it calling the
	~cTexture, which calls	::glDeleteTextures.	 I commented
	GARBAGECOLLECTTEXTURES out in Build 32, as when I used a lot of 
	cSpritQuake critters, I was getting some untraceable crashes inside
	GL library code, which might possibly be caused
	by a texture being deleted in one spot and still being used in another
	spot. */
#define GARBAGECOLLECTDISPLAYLISTIDS
	/* If GARBAGECOLLECTDISPLAYLISTIDS defined, then if shared displaylist
	ID has been	around and unused for too many updates (as specified in a
	cMapEntry_SpriteIDToDisplayListID::FRESHLIFESPAN static defined below)
	we call ::glDeleteLists on it. For now to be safe I'm taking this out. */
// #define INITIALIZE_FONTS_AT_STARTUP
	/* If INITIALIZE_FONTS_AT_STARTUP is on, we generate default fonts at startup, otherwise
	we only build them if and when the program first calls drawtext. It's 
	time-consuming to build the fonts, which is why we prefer not to automatically
	load them at start-up every time, given that I don't normally use fonts.
	In a game that WILL use fonts, you might as well comment in INITIALIZE_FONTS_AT_STARTUP
	and get the lag out of the way during startup rather than having it occur
	unexecptedly with your first write text command. */
#define UNCONDITIONAL_ADJUSTATTRIBUTES
	/* I have a cGraphics::adjsutAttributes(cSprite *psprite) that adjusts 
	various attributes like enabling or disabling blending, lights, texture, 
	and so on.  If UNCONDITIONAL_ADJUSTATTRIBUTES is on, then I simply do
	this (possibly unnecessarily re-doing a setting) for each sprite.  IF
	UNCONDITIONAL_ADJUSTATTRIBUTES is off, then for each attribute, I first
	check if its already on before turning it on, and so on.  This is
	more cumbersome and I only did it because I had the feeling that 
	it might take time to enable or disable an attribute, or that doing this
	might change some existing settins, though this may	be wrong.  I now
	think is better to have UNCONDITIONAL_ADJUSTATTRIBUTES on because in this
	case in the cSprite::draw code I can put adjustAttributes INSIDE the 
	displaylist calls --- if UNCONDITIONAL_ADJUSTATTRIBUTES is off, then the
	calls it makes are conditional, and relaly shouldn't be insid the display
	list. Also it's simpler.
		I tested this for speed in 3D Stub and Racer, and I found that 
	having UNCONDITIONAL_ADJUSTATTRIBUTES runs 1 or 2 fps faster in the 
	Release build and about 1 fps slower in the Debug build, so I'll go with it
	being on.  Note that to carefully compare fps, I have to comment in
	REGRESSIONTEST in randomizer.cpp, otherwise the random elements are
	different in each Release run.*/ 
#define LET_OPENGL_NORMALIZE_LENGTH
	/* If I comment in LET_OPENGL_NORMALIZE_LENGTH, then I pass normals that
	aren't of unit length to OpenGL and let it normalize them.  This gives
	frame rates ten or fifteen percent higher than computing the length
	and dividing by it myself, espeically when I use cSpriteQuake, who
	require lots of normals. */
//#define ONLYAMBIENTLIGHT
#define DONT_REPORT_WGLMAKECURRENT_ERROR
	/* If I comment in DONT_REPORT_WGLMAKECURRENT_ERROR, then I don't report
an error in wglMakeCurrent when it's called in the activate method.  I have been getting an
error message here when I have two OpenGL views open, as in a split window, and then I close the app, 
or close one of the windows.  I only get this on certain machines. */
/////////////////////////////////////////////////////////////////////////////
//Define your statics
	/* These static FRESHLIFESPAN numbers count how many updates to keep
	a shared resource before garbage collecting it, if the game hasn't used it
	recently. */
int cMapEntry_SpriteIDToDisplayListID::FRESHLIFESPAN = 10000; //10K
	/* Allow about two minutes at 80 updates a second.
		That is, ten thousand, or 10,000 is about 9,600 = 2*60*80. */
int cMapEntry_ResourceIDToTexture::FRESHLIFESPAN = 10000; //10K
	//Allow about two minutes at 80 updates a second.
int cMapEntry_SkinFileIDToTexture::FRESHLIFESPAN = 10000; //10K
	//Allow about two minutes at 80 updates a second.

BOOL cGraphicsOpenGL::FIRSTTIME = TRUE;
unsigned int cGraphicsOpenGL::INSTANCECOUNT = 0;
unsigned int cGraphicsOpenGL::ACTIVEID = 0;
CString cGraphicsOpenGL::_graphicsmodestring(
"OpenGL graphics have not yet been initialized during this session.\n To get your system's OpenGL graphics information,\n  Close this dialog,\n  Select View | 3D OpenGL Graphics, and\n  Open this dialog again.\n");
CString cGraphicsOpenGL::_vendorstring;
CString cGraphicsOpenGL::_rendererstring;
CString cGraphicsOpenGL::_driverstring;
CStringArray cGraphicsOpenGL::_extensionstringArray; /* array of all available OpenGL extensions, 
		for this card, neatly parsed */

const char* const cGraphicsOpenGL::_errorStrings[]=
	{
		{"\nNo Error.\n"},					// NONE
		{"\nUnable to get a DC.\n"},		// GETDC
		{"\nChoosePixelFormat failed.\n"},	// CHOOSEPIXELFORMAT
		{"\nSelectPixelFormat failed.\n"},	// SELECTPIXELFORMAT
		{"\nwglCreateContext failed.\n"},	// CREATECONTEXT
		{"\nwglMakeCurrent failed.\n"},		// MAKECURRENT
		{"\nwglDeleteContext failed.\n"},	// DELETECONTEXT
		{"\nSwapBuffers failed.\n"},		// SWAPBUFFERS
		{"\nYour INSTANCECOUNT is bad. \n"} // BADID
	};

int cGraphicsOpenGL::DEFAULT_LINEPIXELS = 3.0f; //was 2.0

unsigned long cGraphicsOpenGL::INVALIDDISPLAYLISTID = 0;

void cGraphicsOpenGL::setVertexColor(COLORREF color, float alpha)
{
	float r = (float)GetRValue(color)/255.0;
	float g = (float)GetGValue(color)/255.0;
	float b = (float)GetBValue(color)/255.0;
	::glColor4f(r, g, b, alpha);
}	

void cGraphicsOpenGL::setVertexColorDim(COLORREF color, float dimfactor, float alpha)
{
	float r = dimfactor * (float)GetRValue(color)/255.0;
	float g = dimfactor * (float)GetGValue(color)/255.0;
	float b = dimfactor * (float)GetBValue(color)/255.0;
	CLAMP(r, 0.0, 1.0); //Use a macro from realnumber.h
	CLAMP(g, 0.0, 1.0);
	CLAMP(b, 0.0, 1.0);
	::glColor4f(r, g, b, alpha);
}	

void cGraphicsOpenGL::setMaterialColor(COLORREF color, Real alpha)
{
  	float r = (float)GetRValue(color)/255.0;
	float g = (float)GetGValue(color)/255.0;
	float b = (float)GetBValue(color)/255.0;
	GLfloat materialAmbDiff[4]={ r, g, b, alpha };
	::glMaterialfv( GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialAmbDiff );
	::glColor4f(r, g, b, alpha);
}

void cGraphicsOpenGL::setMaterialColorFrontAndBack(COLORREF color, Real alpha)
{
  	float r = (float)GetRValue(color)/255.0;
	float g = (float)GetGValue(color)/255.0;
	float b = (float)GetBValue(color)/255.0;
	GLfloat materialAmbDiff[4]={ r, g, b, alpha };
	::glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, materialAmbDiff );
	::glColor4f(r, g, b, alpha);			
}

void cGraphicsOpenGL::setMaterialColorDim(COLORREF color, float dimfactor)
{
  	float r = dimfactor * (float)GetRValue(color)/255.0;
	float g = dimfactor * (float)GetGValue(color)/255.0;
	float b = dimfactor * (float)GetBValue(color)/255.0;
	CLAMP(r, 0.0, 1.0); //Use a macro from realnumber.h
	CLAMP(g, 0.0, 1.0);
	CLAMP(b, 0.0, 1.0);
	GLfloat materialAmbDiff[4]={ r, g, b, 1.0f };
	::glMaterialfv( GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialAmbDiff );
	::glColor4f(r, g, b, 1.0);
}
// This is a helper function that's used to parse the strings
const char* cGraphicsOpenGL::getString(GLenum theEnum)
{
    char* string;
    
    string = (char*)::glGetString(theEnum);// returns a pointer to a STATIC string!
    if (GL_NO_ERROR != ::glGetError()) // failed!
    {
        static char* error = "no-information-available" "";
		string = error;
	}
    return string;
}

/*
//In case I decide to make these static, which would in fact make sense.  Alternately I could
//make the cGraphicsOpenGL a singleton class. 
int cGraphicsOpenGL::_pixelFormatIndex = 0;
HGLRC  cGraphicsOpenGL::_hRenderingContext = NULL;
*/

/////////////////////////////////////////////////////////////////////////////
// cGraphicsOpenGL construction

cGraphicsOpenGL::cGraphicsOpenGL():		//Put defaults in for your data fields
	_defaultTextID(0),
	_default3DTextID(0),
	_defaultFlatTextID(0),
	_initializedDefaultFonts(FALSE),
	_pixelFormatIndex(),
	_pDCview(NULL),
	_hRenderingContext(NULL),
	_errorString(_errorStrings[NONE]),
	_activeDisplayListID(cGraphicsOpenGL::INVALIDDISPLAYLISTID),
	_activeDisplayListIDIsReady(FALSE)
{
   open_gfx = this;
	/* Need to call initializeOpenGL(pview), but you have to wait till you have a pview
		passed by cGraphicsOpenGL::setOwnerView(CView *pview). */
	cGraphicsOpenGL::INSTANCECOUNT++;
	_instanceID = cGraphicsOpenGL::INSTANCECOUNT;
	if (!_instanceID) //You've allocated 3 billion graphics and wrapped around!
		setError(errorType::BADID); 
}

/////////////////////////////////////////////////////////////////////////////
// cGraphicsOpenGL destruction
cGraphicsOpenGL::~cGraphicsOpenGL()
{
	/* I am getting an error in the activate call in certain OpenGL
		 implementations at school, so am worried.  It works fine at home and in my office. */
	activate(); 
		/* Just to make sure you're deleting the right guy, I make this
		the current rendering context. Note that soemthing like 
		this call to activate() seems to be indispensible, because if you don't 
		do it, you white-out the texture in the surviving view. */
	free(); //Release all the resource textures, skin textures, and displaylist IDs.
	if ( FALSE == ::wglMakeCurrent(NULL, NULL) )//Args stand for (target_HDC, target_HGLRC)
		setError(errorType::MAKECURRENT); 
			/* Make the RC non-current before deleting it.  (The NULL in the second
			argument makes _hRenderingContext no longer current, in case it still was. When you
			use NULL in the second argument of wglMakeCurrent, the first argument is ignored,
			so we just use NULL there as well.) Really the ::wglDeleteContext(_hRenderingContext)
			below is supposed to make the _hRenderingContext non-current anyway, so you usually 
			don't need this ::wglMakeCurrent call.  You would, however need it if the
			_hRenderingContext you want to delete weren't in fact the active rendering context
			within the openGL thread where you're calling this destructor.  When this call
			fails I get the same errorcode 6 as	below. */
	if (cGraphicsOpenGL::ACTIVEID == _instanceID)
		cGraphicsOpenGL::ACTIVEID = 0;
	if (FALSE == ::wglDeleteContext(_hRenderingContext)) 
		setError(errorType::DELETECONTEXT);
		/* I often, but not always, get an "Invalid Address specified to RtlFreeHeap" user breakpoint 
			message in the the Visual Studio Output window while I'm inside the 
			wglDeleteContext.  Happens when I use the Pop Framework View menu to make a call to 
			CPopView::setGraphicsClass which calls this destructor.  I also usually get it when I exit
			the program	while in 3D mode, so the exit calls the destructor.  But the wglDeleteContext
			call doesn't actually crash	the program, nor does it return a FALSE. But it would be
			good to figure out how to make this go away. */
	int systemerrorcode = ::GetLastError(); /* For debugging. When I get that "Invalid
			Address specified to RtlFreeHeap" error, the systemerrorcode is 6, which
			is the Win32 Error code "The handle is invalid.  ERROR_INVALID_HANDLE" */
	_hRenderingContext = NULL; //Just to be sure you don't try and use it again.
		/* In Win32 programming, we have to worry about deleting the HDC that was active in the
		_hRenderingContext, that is we would have needed to somehow keep track of the HDC
		::wglGetCurrentDC() and its associated window so we could call a DeleteDC on it here.
		But our current situation is that this HDC is either NULL or is an HDC belonging to 
		some window in our app, and we leave it up to that window to delete its own HDC.  Indeed,
		trying to delete the HDC here is risky as it may be that the window we got it from is 
		already dead by the time the cGraphicsOpenGL destructor is called. */
	delete _pDCview; /* This will  release the HDC wrapped inside _pDCview. */
	_pDCview = NULL;
			/* Note that the member destructors will call _map_ResourceIDToTexture.free() and
		_map_SpriteIDToDisplayListID.free(); */
}

void cGraphicsOpenGL::setClearColor(COLORREF color)
{
	float r = (float)GetRValue(color)/255.0;
	float g = (float)GetGValue(color)/255.0;
	float b = (float)GetBValue(color)/255.0;
	::glClearColor(r, g, b, 1.0);
}

void cGraphicsOpenGL::activate()
{
/* You may be using multiple views, in which case you have a different HGLRC for each view, as
you don't want to accumulate one views drawing commands into another view.  So in the multiple
view case, we do need to make the correct _hRenderingContext current before drawing. */
//	HDC windowDC = pDC->GetSafeHdc();
//	HDC renderingContextDC = ::wglGetCurrentDC();
	if (cGraphicsOpenGL::ACTIVEID == _instanceID) //Can I bail without doing anything here?
		return;
    if ( FALSE == ::wglMakeCurrent( _pDCview->GetSafeHdc(), _hRenderingContext ) )
		setError(errorType::MAKECURRENT); 
	cGraphicsOpenGL::ACTIVEID = _instanceID;
}

void cGraphicsOpenGL::clear(const CRect &clearrect)
{
	//OpenGL has no use for the clearrect argument.
	::glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void cGraphicsOpenGL::display(CView *pview, CDC *pDC)
{
	// Tell OpenGL to flush its pipeline
	::glFinish();
	// Now Swap the buffers
	if ( FALSE == ::SwapBuffers( ::wglGetCurrentDC() ) )
	{
		int errorid = ::GetLastError();  /* When I open two OpenGL windows and close one,
			I get errorid 6 for "The handle is invalid.  ERROR_INVALID_HANDLE" This
			derives from the problem in ~cGraphicsOpenGL. */
		setError(errorType::SWAPBUFFERS);
	}
}

void cGraphicsOpenGL::setViewport(int width, int height)
{
	::glViewport(0, 0, width, height);
}

//Specical cGraphicsOpenGL methods
//////////////////////////////////////////////////////////////////////////////
// setError-error string manipulation

/////////////////////////////////////////////////////////////////////////////
void cGraphicsOpenGL::setError( int e )
{
/* If there was no previous error, then announce this one.  Don't repeatedly announce errors
as otherwise yousave this one so you can examine it in the debugger at exit. */
	int systemerrorcode = ::GetLastError(); // For debugging. 
	if ( _errorStrings[0] == _errorString ) 
	{
#ifdef DONT_REPORT_WGLMAKECURRENT_ERROR
	if (e == MAKECURRENT)
			return;
#endif //DONT_REPORT_WGLMAKECURRENT_ERROR
		_errorString = _errorStrings[e];
		::MessageBeep(MB_ICONEXCLAMATION);
		::AfxMessageBox(_errorString + "  Close program now.", MB_ICONEXCLAMATION);
	}
}

void cGraphicsOpenGL::setOwnerView(CView *pview)
{
	_pownerview = pview;
	initializeOpenGL(pview);
}

//////////////////////////////////////////////////////////////////////////////
// initializeOpenGL
BOOL cGraphicsOpenGL::initializeOpenGL(CView *pview)
{
	_pDCview = new CClientDC(pview); 
		/* Don't call this until pview owner view has been properly
		set, that is, you want to make this call till inside the pview's call to
		OnCreate, rather than in the pview's constructor. */
	HDC viewHDC = _pDCview->GetSafeHdc();

    if ( NULL == viewHDC ) // failure to get DC
	{
		setError(errorType::GETDC);
		return FALSE;
	}
	if (!setupPixelFormat(viewHDC))
        return FALSE;
    if ( 0 == (_hRenderingContext = ::wglCreateContext( viewHDC ) ) )
	{
		setError(4);
		return FALSE;
	}
	activate(); /* activate()  calls ::wglMakeCurrent(_pDCview->GetSafeHdc(),_hRenderingContext))
		and sets cGraphicsOpenGL::ACTIVEID == _instanceID; */
	if (_instanceID == 1) //This is the first cGraphicsOpenGL instance you're opening up
		fetchExtendedInformation(); /* We don't bother to fetch this again as
			our graphics card isn't going to change in the middle of a run. */
// select our default display fonts
// (this takes a long time, so we normally comment out the switch, so that
// programs without fonts don't have to work so hard. Without INITIALIZE_FONTS_AT_STARTUP,
// the setDefaultFonts gets called only when you first try to use a font.
#ifdef INITIALIZE_FONTS_AT_STARTUP
	setDefaultFonts();
#endif //INITIALIZE_FONTS_AT_STARTUP
// specify your clear color, that is, your background color.
//	::glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //black
    ::glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //white
// specify the back of the buffer as clear depth
    ::glClearDepth(1.0f);
// enable depth testing
#ifdef LET_OPENGL_NORMALIZE_LENGTH
	glEnable(GL_NORMALIZE);
#endif //LET_OPENGL_NORMALIZE_LENGTH
#ifdef INITIALIZEWITHALPHABLEND //This is kind of overriden by adjustAttributes now
	::glEnable(GL_ALPHA_TEST);
	::glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#endif
    ::glEnable(GL_DEPTH_TEST);
		/* By default GL_DEPTH_TEST is off.  We normally need it so that nearer things cover 
		further things.  Don't need it, though, in the two dimensional case. */
	::glDepthFunc(GL_LESS); 
		/* This is the default depth test, but we make it explicity.  Skips drawing any pixel with
		a smaller depth than the zbuffer depth value at that spot. */
//	::glShadeModel(GL_SMOOTH); //The default shading model, instead we prefer GL_FLAT
	::glShadeModel(GL_FLAT ); 
		/* GL_SMOOTH interpolates from the vertices across a polygon, while
			GL_FLAT picks one vertex (the first of the poly) and uses that color across
			the polygon. Default is GL_SMOOTH.  Runs about 75% as fast as GL_FLAT, and there's
			no point to it for polyhedra, as all verts of a polyhedron face have the same
			normal anyway (Unless you tilt the vert normals to make the polyhedron resemble
			a curved surface, in which case you do want SMOOTH and should temporarily 
			turn it on for that object with a glShadeModel call). */
//	::glEnable(GL_LINE_SMOOTH); 
		//Anti-alias lines.  Makes lines a bit more solid looking, but costs a lot of speed.
//	::glEnable(GL_POLYGON_SMOOTH); 
		/* To make the polygon edges smoother. Don't even THINK of using this one, it cuts your speed
		to almost nothing. */
	//::glEnable(GL_CULL_FACE);
		 /* Don't draw back-facing polygons to save speed?  Better not.  First of all, we need to
		draw them in demo mode, as the teapot seems to have	clockwise polygons. Second of all,
		the cSpriteIcon doesn't work if we cull faces. */
	//::glEnable(GL_LIGHTING); 
		/* Default is lighting ON.  We do in fact 
		always want to use lighting with OpenGL, as, surprisingly, OpenGL is FASTER with lighting 
		turned on!  Do be aware that if have lighting on, you MUST install some lights 
		or everything is black.  So we MUST have a call to installLightingModel here as well.  
		To be safe, we turn the light on with a call to our installLightingModel with
		a NULL argument to give a default  behavior that turns lighting on and adds some
		lights. */
	installLightingModel(NULL);
		/* Actually we can leave this line out, as the CPopView::setGraphicsClass
			calls installLightingModel anyway. */
	::glPixelStorei(GL_UNPACK_ALIGNMENT, 1); //We're not padding at ends of lines when we write textures.
	::glPixelStorei(GL_PACK_ALIGNMENT, 1); //We're not padding at ends of lines when we read textures.
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
BOOL cGraphicsOpenGL::setupPixelFormat(HDC viewHDC)
{
  static PIXELFORMATDESCRIPTOR pfd = 
	{
        sizeof(PIXELFORMATDESCRIPTOR),  // size of this pfd
        1,                              // version number
        PFD_DRAW_TO_WINDOW |            // support window
        PFD_SUPPORT_OPENGL |          // support OpenGL
        PFD_DOUBLEBUFFER,             // double buffered
        PFD_TYPE_RGBA,                  // RGBA type
        24,                             // 24-bit color depth
        0, 0, 0, 0, 0, 0,               // color bits ignored
        8,                              // Number of alpha bits.  Was 0, use 8
        0,                              // shift bit ignored
        0,                              // no accumulation buffer
        0, 0, 0, 0,                     // accum bits ignored
        16,                             // 16-bit z-buffer
        0,                              // no stencil buffer
        0,                              // no auxiliary buffer
        PFD_MAIN_PLANE,                 // main layer
        0,                              // reserved
        0, 0, 0                         // layer masks ignored
    };
	if ( 0 == (_pixelFormatIndex = ::ChoosePixelFormat(viewHDC, &pfd)) )
	{
		setError(errorType::CHOOSEPIXELFORMAT);
		return FALSE;
	}
    if ( FALSE == ::SetPixelFormat(viewHDC, _pixelFormatIndex, &pfd) )
	{
		setError(3);
		return FALSE;
	}
    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
void cGraphicsOpenGL::fetchExtendedInformation()
{
/* Get information about the particular pixel format that's running. From this we
can tell if the OpenGL implementation is strictly software, partially in hardware with
some of the routines being processed by the generic software driver (the Mini-Client driver)
or if the entire implementation is in hardware (the Installable Client driver).
We save the OpenGL info both inside the cGraphicsOpenGL object and up in the CPopApp
so the dialog can see it.  */

	PIXELFORMATDESCRIPTOR pfd;
	const char *_pVender, *_pRenderer, *_pVersion;

	// Get information about the DC's current pixel format 
	::DescribePixelFormat( ::wglGetCurrentDC(), _pixelFormatIndex,
		sizeof(PIXELFORMATDESCRIPTOR), &pfd ); 
	cGraphicsOpenGL::_graphicsmodestring.Format(
		"Graphics Mode: Using %d bits per pixel with %d alpha bits. Double buffering is %s.\n", 
		pfd.cColorBits, pfd.cAlphaBits, (pfd.dwFlags & PFD_DOUBLEBUFFER)?"on":"off");

/* Now that we've set up a pixel format, get information about the current
		 driver for this format. You can use this info to determine which pixel format
		is the fastest. Note that the Mini-Client driver is only available in OpenGL 1.1
		or later.  We don't actually use the _eCurrentDriver anywhere in the code. */

	if ( 0 == ( INSTALLABLE_DRIVER_TYPE_MASK & pfd.dwFlags ) )
		_driverstring = "Using full hardware graphics driver with acceleration.\n"; // fully in hardware (fastest)
	else if ( INSTALLABLE_DRIVER_TYPE_MASK == ( INSTALLABLE_DRIVER_TYPE_MASK & pfd.dwFlags ) )
		_driverstring = "Using partial \"mini\" hardware graphics driver.\n";	// partially in hardware (pretty fast, maybe..)
	else  // plain old generic
		_driverstring = "Generic software graphics driver, no hardware acceleration.\n";	// software
	// end of the current driver specific area

// Get general information about the OpenGL driver

//  GL_VENDOR
//  Returns the company responsible for this GL implementation.
//  This name does not change from release to release. 
    _pVender = getString( GL_VENDOR );
	cGraphicsOpenGL::_vendorstring.Format("Vendor: Using OpenGL implementation by %s.\n", _pVender);

//  GL_RENDERER
//  Returns the name of the renderer. This name is typically specific
//  to a particular configuration of a hardware platform.
//  It does not change from release to release. 
    _pRenderer = getString( GL_RENDERER );

//  GL_VENDOR and GL_RENDERER together uniquely specify a platform,
//  and will not change from release to release. They should be used
//  to identify the platform.

//  GL_VERSION
//  Returns a version or release number. 
    _pVersion = getString( GL_VERSION );
	cGraphicsOpenGL::_rendererstring.Format("Renderer: %s.  Version: %s.\n", _pVender, _pVersion);


//  GL_EXTENSIONS
//  Returns a space-separated list of supported extensions to GL.
//  Because GL does not include queries for the performance
//  characteristics of an implementation, it is expected that some
//  applications will be written to recognize known platforms and will
//  modify their GL usage based on known performance characteristics
//  of these platforms.

//  The format and contents of the string that glGetString() returns depend
//  on the implementation, except that extension names will not include
//  space characters and will be separated by space characters
//  in the GL_EXTENSIONS string, and that all strings are null-terminated.
    char *extensionline;
	BOOL bDone = FALSE;
	CString extensioninfostring = getString(GL_EXTENSIONS);
	char *extensioninfo = extensioninfostring.GetBuffer(extensioninfostring.GetLength());

	while ( !bDone )
	{
		extensionline = extensioninfo;
		while ( (0 != *extensioninfo) && (' ' != *extensioninfo)  )
			extensioninfo++;
		if ( 0 == *extensioninfo )
			bDone = TRUE;
		*extensioninfo = 0; // terminate the string by replacing ' ' with 0.
        cGraphicsOpenGL::_extensionstringArray.Add(extensionline);// Create a new CString object and add to the array
 		extensionline = ++extensioninfo;  // skip to next string
	}
//Trace info to the screen if this is the first time you're going into OpenGL mode.
#ifdef TRACEGRAPHICSINFOTOOUTPUT
	TRACE("\n\n********************************************************************\n");
	TRACE(cGraphicsOpenGL::_graphicsmodestring);
	TRACE(cGraphicsOpenGL::_driverstring);
	TRACE(cGraphicsOpenGL::_vendorstring);
	TRACE(cGraphicsOpenGL::_rendererstring);
	TRACE("\nSupported OpenGL Extensions:\n");
	for (int i=0; i<cGraphicsOpenGL::_extensionstringArray.GetSize(); i++)
		TRACE("        %s\n", cGraphicsOpenGL::_extensionstringArray[i]);
/* We used to assemble all of the _extensionArray[i] into a single 
_exentsionsstring and then try and  TRACE(cGraphicsOpenGL::_extensionsstring);
But this would crash the Debug version when using graphics cards with lots of
extensions, the reason being that TRACE is limited to sending a total of 512 
characters at a time. Exceeding this limit triggers an ASSERT which crashes the
program. */
	TRACE("********************************************************************\n\n");
#endif TRACEGRAPHICSINFOTOOUTPUT
}	



/////////////////////////////////////////////////////////////////////////////
// Draw3DAxes
// Draws lines along the current 3 axes from "start" units to "finish", with 
// "ticks" tickmarks spaced out along it.
void cGraphicsOpenGL::draw3DAxes( float start, float finish, int ticks )
{
	// make sure that start < finish
	if ( start > finish )
		{
		float temp = start;
		start = finish;
		finish = start;
		}

	// if ticks < 0 and delta is larger than 1, place the ticks
	// on each scales unit length
	if ( 0 > ticks )
		{
		float delta = finish-start;
		ticks = delta > 1.0 ? (int)delta : 0;
		}

	// draw the tickmarked axes
	draw3DAxesLine( start, finish, 0, ticks );
	draw3DAxesLine( start, finish, 1, ticks );
	draw3DAxesLine( start, finish, 2, ticks );
}

/////////////////////////////////////////////////////////////////////////////
// draw3DAxesLine
// This routine draws a colored line along a specified axis.
// axis_id = 0 for the x, 1 for the y, and anything else for the z
// start and finish are the starting and ending location, start < finish.
// ticks is the number of ticks to place along the axis.
// If you are using lighting/materials, you might want to wrapper this routine
// so that it's called with lighting disabled, or else the axis lines will be effected
// by lighting claculations - which generally means hard to see.
void cGraphicsOpenGL::draw3DAxesLine( float start, float finish, int axis_id, int ticks )
{
	float *px, *py, *pz, zero = 0.0f;
	float tickx, ticky, tickz;
	float *pdx, *pdy, *pdz, tinytick, delta = (finish-start)/(ticks<1?1:ticks);
	GLfloat negativeColor[3] = { 1.0f, 0.0f, 0.0f };
	GLfloat positiveColor[3] = { 0.0f, 1.0f, 0.0f };

	pdx = pdy = pdz = px = py = pz = &zero;
	tickx = ticky = tickz = 0.0f;
	tinytick = 0.05f;

	// select which of the 3 axes is going to vary
	if ( 0 == axis_id ) // X axis
		{
		pdx = &delta;	  
		ticky = tinytick;	  
		px = &start;	  
		}
	else if ( 1 == axis_id ) // Y axis
		{
		pdy = &delta;	  
		tickx = tinytick;	  
		py = &start;	  
		}
	else 	// default Z axis
		{
		pdz = &delta;	  
		ticky = tinytick;	  
		pz = &start;	  
		}

	glPushAttrib(GL_ENABLE_BIT); 
		/* Save the enabled or disabled state of 
		GL_LIGHTING, GL_ALPHA_TEST, and GL_TEXTURE_2D, as we may change all of these here. */
	glDisable(GL_LIGHTING); 
		/* Lines look bad with lighting.  We'll restore the lighting
		with the glPopAttrib below. */

	::glBegin(GL_LINES);

	// now draw the two lines that make up the axis
	::glColor3fv( negativeColor ); // negative color
	::glVertex3f( *px, *py, *pz );
	::glVertex3f( 0.0f, 0.0f, 0.0f );

	::glColor3fv( positiveColor ); // positive color
	::glVertex3f( 0.0f, 0.0f, 0.0f );
	::glVertex3f( *px+*pdx*ticks, *py+*pdy*ticks, *pz+*pdz*ticks );

	// now draw the tick marks
	int i;
	for ( i = 0; i < ticks  ; i++ )
		{
		if ( i < ticks/2 )
			{
			::glColor3fv( negativeColor );
			}
		else
			{
			::glColor3fv( positiveColor );
			}

		::glVertex3f( *px-tickx, *py-ticky, *pz-tickz );
		::glVertex3f( *px+tickx, *py+ticky, *pz+tickz );

		*px += *pdx;
		*py += *pdy;
		*pz += *pdz;
		}

	::glEnd();

	::glPopAttrib();
}


/////////////////////////////////////////////////////////////////////////////
// cGraphicsOpenGL Text-Specific routines follow
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// generateDefaultFonts
// generate the default 3D and flat text disp;ay lists
void cGraphicsOpenGL::generateDefaultFonts( char* font3D, char* fontFlat )
{
   _default3DTextID	= generateDisplayListForFont(font3D);
   _defaultTextID = _defaultFlatTextID	= generateBitmapListForFont(fontFlat);
}

/////////////////////////////////////////////////////////////////////////////
// textOut
// Output text (either Bitmap or Outline)
void cGraphicsOpenGL::textOut( const char * const textstring, GLuint fontID)
{
	if (!_initializedDefaultFonts)
	{
		setDefaultFonts(); // Make a call to generateDefaultFonts.
		_initializedDefaultFonts = TRUE;
	}

	if (textstring == NULL)
		return;

	if (fontID == -1) /* our default textout second arg -1 is a flag to use
		the default font.  We assume that if we have an arg here, we have
		takent he trouble to generate the font.  */
		fontID = _defaultTextID;
	
	GLsizei size = strlen( textstring );

	::glListBase( fontID );
	::glCallLists( size, GL_UNSIGNED_BYTE, (const GLvoid*)textstring ); 
} 

/////////////////////////////////////////////////////////////////////////////
// generateDisplayListForFont
// The routines used for generating 3D text.
GLuint cGraphicsOpenGL::generateDisplayListForFont( char* fontname, double xt )
{
	GLuint id = ::glGenLists(256);
	if ( !_pDCview || !id)
		return 0;

	LOGFONT logfont;
	GLYPHMETRICSFLOAT gmf[256];
	CFont *pnewfont = new CFont();
	CFont *poldfont, *pusednewfont;
	BOOL successmakefont = TRUE;
	BOOL successloadfont = TRUE;
	BOOL successwglfont = TRUE;
	HDC viewHDC = _pDCview->GetSafeHdc();

	if ( !_pDCview || ! id || !fontname ) 
        return 0;

	if (fontname != NULL) //Otherwise we use whatever system font is in place.
	{
		// lfHeight can't be used to change the font size
		logfont.lfHeight		= -12; // use glScale to change size
		logfont.lfWidth			= 0;
		logfont.lfEscapement	= 0;
		logfont.lfOrientation	= logfont.lfEscapement;
		logfont.lfWeight		= FW_NORMAL;
		logfont.lfItalic		= FALSE;
		logfont.lfUnderline		= FALSE;
		logfont.lfStrikeOut		= FALSE;
		logfont.lfCharSet		= ANSI_CHARSET;
		logfont.lfOutPrecision	= OUT_TT_ONLY_PRECIS;
		logfont.lfClipPrecision	= CLIP_DEFAULT_PRECIS;
		logfont.lfQuality		= DEFAULT_QUALITY;
		logfont.lfPitchAndFamily = FF_DONTCARE|DEFAULT_PITCH;
		lstrcpy ( logfont.lfFaceName, fontname );

		successmakefont = pnewfont->CreateFontIndirect( &logfont );
		poldfont = (CFont*)(_pDCview->SelectObject(pnewfont));
	} //end fontname != NULL case.
	else //NULL fontname means use system font.
		poldfont = (CFont*)(_pDCview->SelectObject(
			(HFONT)(::GetStockObject(SYSTEM_FONT ))));
	if (!poldfont) //SelectObject returns 0 for failure.
		successloadfont = FALSE;
    // Create a set of display lists based on the glyphs of the TrueType font 
	// notice that we really waste the first 32 spaces....
	// if there's a problem delete the display lists
	// Note that this single call takes MOST of the initialization time
	// for the cGraphicsOpenGL class (probably a couple of seconds!) so if you don't
	// want/need 3D text, you might comment this functionality out.
	successwglfont = ::wglUseFontOutlines(viewHDC,
			 0, 256, id, 0.0f,
			(float)xt, WGL_FONT_POLYGONS,
			gmf);
	if (!successwglfont)
	{
		::glDeleteLists( id, 256 );
		id  = 0; //Put a "bad" zero in id to signal that this didn't work.
	}
	pusednewfont = (CFont*)(_pDCview->SelectObject(poldfont)); 
		/* The pusednewfont is just for debugging, if its NULL, there's a
		problem. It should match pnewfont if the fontname wasn't NULL. */
	delete pnewfont;
	return id;
}

/////////////////////////////////////////////////////////////////////////////
// generateBitmapListForFont
// The routines used for generating flat text
GLuint cGraphicsOpenGL::generateBitmapListForFont( char* fontname )
{
	GLuint id = ::glGenLists(256);
	if ( !_pDCview || !id)
		return 0;

	LOGFONT logfont;
	CFont *pnewfont = new CFont();
	CFont *poldfont, *pusednewfont;
	BOOL successmakefont = TRUE;
	BOOL successloadfont = TRUE;
	BOOL successwglfont = TRUE;
	HDC viewHDC = _pDCview->GetSafeHdc();

	if ( fontname != NULL)
	{
		logfont.lfHeight		= -30;
		logfont.lfWidth			= 0;
		logfont.lfEscapement	= 0;
		logfont.lfOrientation	= logfont.lfEscapement;
		logfont.lfWeight		= FW_NORMAL;
		logfont.lfItalic		= FALSE;
		logfont.lfUnderline		= FALSE;
		logfont.lfStrikeOut		= FALSE;
		logfont.lfCharSet		= ANSI_CHARSET;
		logfont.lfOutPrecision	= OUT_DEFAULT_PRECIS;
		logfont.lfClipPrecision	= CLIP_DEFAULT_PRECIS;
		logfont.lfQuality		= DEFAULT_QUALITY;
		logfont.lfPitchAndFamily = FF_DONTCARE|DEFAULT_PITCH;
		lstrcpy ( logfont.lfFaceName, fontname );

		// returns 0 if it fails
		successmakefont = pnewfont->CreateFontIndirect( &logfont );
		poldfont = (CFont*)(_pDCview->SelectObject(pnewfont));
	} //End if ( fontname != NULL) case
	else //NULL fontname means use system font.
		poldfont = (CFont*)(_pDCview->SelectObject(
			(HFONT)(::GetStockObject(SYSTEM_FONT ))));
	if (!poldfont) //SelectObject returns 0 for failure.
		successloadfont = FALSE;
	
    // Create a set of display lists based on the glyphs of the font 
	// notice that we really waste the first 32 spaces....
	// if there's a problem delete the display lists
	successwglfont = ::wglUseFontBitmaps(viewHDC, 0, 256, id);
	if (!successwglfont)
	{
		::glDeleteLists( id, 256 );
		id  = 0;
	}
	pusednewfont = (CFont*)(_pDCview->SelectObject(poldfont)); 
		/* The pusednewfont is just for debugging, if its NULL, there's a
		problem. It should match pnewfont if the fontname wasn't NULL. */
	delete pnewfont;
	return id;
}
//============================Standard Graphics Overloads====================================

void cGraphicsOpenGL::vectorToPixel(cVector position, int &xpix, int &ypix, Real &zbuff)
{
#ifdef TRACEPIXELTOVECTOR
	TRACE("cGraphicsOpenGL::vectorToPixel transformed %f %f %f\n", position.x(), position.y(), position.z());
#endif //TRACEPIXELTOVECTOR
	double modelviewmatrix[16];
	double projectionmatrix[16];
	int viewport[4];
	::glGetDoublev(GL_MODELVIEW_MATRIX, modelviewmatrix);
	::glGetDoublev(GL_PROJECTION_MATRIX, projectionmatrix);
	::glGetIntegerv(GL_VIEWPORT, viewport);
	double doublex, doubley, doublez; /* Need these as gluProject demands these args be double,
		not int or float. */
	::gluProject(position.x(), position.y(), position.z(),
		modelviewmatrix, projectionmatrix, viewport,
		&doublex, &doubley, &doublez);
	xpix = (int)doublex;
	ypix = (int)(viewport[3] - doubley); /* OpenGL counts y pixels from bottom to top, but we will use
		the Windows	programming convention of couting them from top to bottom.  And viewport[3] 
		is the height of the viewport. */
	zbuff = (Real)doublez;
#ifdef TRACEPIXELTOVECTOR
	TRACE("to %d %d %f.\n", xpix, ypix, zbuff);
#endif //TRACEPIXELTOVECTOR
}

cVector cGraphicsOpenGL::pixelToVector(int xpix, int ypix, Real zbuff)
{
#ifdef TRACEPIXELTOVECTOR
	TRACE("cGraphicsOpenGL::pixelToVector transformed %d %d %f\n", xpix, ypix, zbuff);
#endif //TRACEPIXELTOVECTOR
	double doublex;
	double doubley;
	double doublez;
	double modelviewmatrix[16];
	double projectionmatrix[16];
	int viewport[4];
	::glGetDoublev(GL_MODELVIEW_MATRIX, modelviewmatrix);
	::glGetDoublev(GL_PROJECTION_MATRIX, projectionmatrix);
	::glGetIntegerv(GL_VIEWPORT, viewport);
	ypix = viewport[3] - ypix; /* OpenGL counts y pixels from bottom to top, but we will use
		the Windows	programming convention of couting them from top to bottom.  viewport[3]
		is the height of the viewport. */
	::gluUnProject((double)xpix, (double)ypix, (double)zbuff, 
		modelviewmatrix, projectionmatrix, viewport,
		&doublex, &doubley, &doublez);
#ifdef TRACEPIXELTOVECTOR
	TRACE("to %f %f %f.\n", position.x(), position.y(), position.z());
#endif //TRACEPIXELTOVECTOR
	return cVector(doublex, doubley, doublez);
}

//===========DRAWING METHODS=========================

void cGraphicsOpenGL::drawtext(CString string, int pixx, int pixy)
{
	LPTSTR pchar = string.GetBuffer(100);
	textOut(pchar);
	string.ReleaseBuffer();
}

void cGraphicsOpenGL::drawline( cVector posa, cVector posb, cColorStyle *pcolorstyle)
{
#ifdef DISABLEATTRIBUTESFORLINES
	glPushAttrib(GL_ENABLE_BIT); /* Save the enabled or disabled state of 
		GL_LIGHTING and GL_TEXTURE_2D, as we disable these here. */
	::glDisable(GL_LIGHTING);
		 /* Lines look bad with lighting.  We'll restore the lighting
		with the glPopAttrib below. */
 	::glDisable(GL_TEXTURE_2D);// Lines don't work with texture on.
#endif //DISABLEATTRIBUTESFORLINES
	
	::glLineWidth(DEFAULT_LINEPIXELS);
	::glBegin(GL_LINES);
	setMaterialColorFrontAndBack(pcolorstyle->lineColor()); //For use with lighting
	setVertexColor(pcolorstyle->lineColor()); //For use with no lighting
	setGLVertex(posa);
	setGLVertex(posb);
	::glEnd();

#ifdef DISABLEATTRIBUTESFORLINES
	::glPopAttrib();  //Leave lighting and texture as it was before.
#endif //DISABLEATTRIBUTESFORLINES
}

void cGraphicsOpenGL::drawrectangle(const cVector &corner0,
		const cVector &corner1,	const cVector &corner2,
		const cVector &corner3,	cColorStyle *pcolorstyle, int drawflags)
{
	cVector normal = (corner1 - corner0) * (corner2 - corner0);
#ifndef LET_OPENGL_NORMALIZE_LENGTH
	normal.normalize();
#endif //LET_OPENGL_NORMALIZE_LENGTH
	if (pcolorstyle->filled() && !(drawflags & CPopView::DF_WIREFRAME))
	{
		setMaterialColorFrontAndBack(pcolorstyle->fillColor()); //For use with lighting
		setVertexColor(pcolorstyle->fillColor()); //For use with no lighting
		::glBegin(GL_POLYGON);
		::glNormal3f(normal.x(), normal.y(), normal.z()); 
		::glVertex3f(corner0.x(), corner0.y(), corner0.z());
		::glVertex3f(corner1.x(), corner1.y(), corner1.z());
		::glVertex3f(corner2.x(), corner2.y(), corner2.z());
		::glVertex3f(corner3.x(), corner3.y(), corner3.z());
		::glEnd();
	}
#ifdef DISABLEATTRIBUTESFORLINES
	glPushAttrib(GL_ENABLE_BIT); /* Save the enabled or disabled state of 
		GL_LIGHTING and GL_TEXTURE_2D, as we disable these here. */
	::glDisable(GL_LIGHTING);
		/* Lines look bad with lighting.  We'll restore the lighting
		with the glPopAttrib below. */
 	::glDisable(GL_TEXTURE_2D);// Lines done't work with texture on.
#endif //DISABLEATTRIBUTESFORLINES
	if (pcolorstyle->edged() || (drawflags & CPopView::DF_WIREFRAME))
	{
		setVertexColor(pcolorstyle->lineColor()); //For no lighting
		setMaterialColorFrontAndBack(pcolorstyle->lineColor()); //For lighting
		::glLineWidth(cGraphicsOpenGL::DEFAULT_LINEPIXELS); //Must set this outside a glBegin/glEnd block.
		::glBegin(GL_LINE_LOOP);
		::glNormal3f(normal.x(), normal.y(), normal.z()); 
		::glVertex3f(corner0.x(), corner0.y(), corner0.z());
		::glVertex3f(corner1.x(), corner1.y(), corner1.z());
		::glVertex3f(corner2.x(), corner2.y(), corner2.z());
		::glVertex3f(corner3.x(), corner3.y(), corner3.z());
		::glEnd();
	}
#ifdef DISABLEATTRIBUTESFORLINES
	::glPopAttrib();  //Leave lighting and texture as it was before.
#endif //DISABLEATTRIBUTESFORLINES
}

void cGraphicsOpenGL::drawcircle(const cVector &center, Real radius,
	cColorStyle *pcolorstyle, int drawflags)
{
	Real angle = 0.0;
	Real angleinc = 2.0*PI/GLCIRCLESLICES;
	cVector circlevert[GLCIRCLESLICES];
	for (int i=0;  i < GLCIRCLESLICES; i++)
	{
		circlevert[i] = center + cVector(radius*cos(angle), radius*sin(angle), 0.0);
		angle += angleinc;
	}
	if (pcolorstyle->filled() && !(drawflags & CPopView::DF_WIREFRAME))
	{
		::glBegin(GL_TRIANGLE_FAN);
		setMaterialColorFrontAndBack(pcolorstyle->fillColor()); //For use with lighting
		setVertexColor(pcolorstyle->fillColor()); //For use with no lighting
		setGLVertex(center);
		for (i=0;  i < GLCIRCLESLICES; i++)
			setGLVertex(circlevert[i]);
		setGLVertex(circlevert[0]);
		::glEnd();
	}
	if (pcolorstyle->edged() || (drawflags & CPopView::DF_WIREFRAME))
	{
		::glLineWidth(cGraphicsOpenGL::DEFAULT_LINEPIXELS); //Must set this outside a glBegin/glEnd block.
		::glBegin(GL_LINE_LOOP);
		setMaterialColorFrontAndBack(pcolorstyle->lineColor()); //For use with lighting
		setVertexColor(pcolorstyle->lineColor()); //For use with no lighting
		for (i=0;  i < GLCIRCLESLICES; i++)
		setGLVertex(circlevert[i]);
		::glEnd();
	}
}

BOOL cGraphicsOpenGL::activateDisplayList(cSprite *psprite) /* This call gets an
	_activeDisplayListID based on the psprite's spriteID and newgeometryflag.  If the
	list has already been recorded,	we set _activeDisplayListIDIsReady to TRUE,
	otherwise we set _activeDisplayListIDIsReady to FALSE.  And then we return
	_activeDisplayListIDIsReady. */
{
	int spriteid = psprite->spriteID();
	BOOL newgeometryflag = psprite->newgeometryflag();
	_activeDisplayListID = /* Set the cGraphicsOpenGL field _activeDisplayListID so we can
			reference it in the cGraphicsOpenGL::callDisplayList(). */
		_map_SpriteIDToDisplayListID.lookupDisplayListID(psprite->spriteID());
	if (_activeDisplayListID != cGraphicsOpenGL::INVALIDDISPLAYLISTID && //nonzero means its a valid ID.
		!(psprite->newgeometryflag()))//sprite geometry hasn't been changed
			return _activeDisplayListIDIsReady = TRUE; //Means you have a valid, playable _activeDisplayListID
/* If you get here either its a new sprite, or the sprite has a newgeometryflag. If
you have an entry, but it's no good anymore, you have to get rid of it three 
different ways: Remove it from the CList, invalidate its OpenGL list, and delete
it from memory. */
	if (_activeDisplayListID != cGraphicsOpenGL::INVALIDDISPLAYLISTID && //nonzero means its a valid ID.
		(psprite->newgeometryflag())) //You have an entry, but it's no good anymore.
	{
		cMapEntry_SpriteIDToDisplayListID *pmapentry;
		_map_SpriteIDToDisplayListID.Lookup(psprite->spriteID(), pmapentry); //The base CMap Lookup.
		::glDeleteLists(_activeDisplayListID, 1);
		_map_SpriteIDToDisplayListID.RemoveKey(psprite->spriteID());
		delete pmapentry;
		pmapentry = NULL;
	}
	_activeDisplayListID = ::glGenLists(1); //Get the next display list ID from OpenGL
	/* Turn on the display list recorder.  It's OK to have it on while you do the 
	array setup stuff, as the only commands the recorder will catch are the gl and glu calls. */
	glNewList(_activeDisplayListID, GL_COMPILE);
		 /* Start recording the display list after this call. */
	return _activeDisplayListIDIsReady = FALSE; //Means you must still record onto the _activeDisplayListID
}

void cGraphicsOpenGL::callActiveDisplayList(cSprite *psprite)
{
	if (!_activeDisplayListIDIsReady)	
	{
		::glEndList();
		_map_SpriteIDToDisplayListID.SetAt(psprite->spriteID(),
			new cMapEntry_SpriteIDToDisplayListID(_activeDisplayListID));
		/* I once had a memory leak from this line, apparantly my
			cMap_SpriteIDToDisplayListID::free() wasn't
			killing all of the cMapEntry_SpriteIDToDisplayListID* in
			the destructor call for _map_SpriteIDToDisplayListID, which cascades
			out of the cGraphicsOpenGL destructor. To see the leak, start in 
			cGameSpacewar with windows graphics and polypolygons for the asteroid sprites,
			switch to Use View|OpenGL Grpahics, and close. */
	}
	::glCallList(_activeDisplayListID);
/* Note that when we were doing the GL_COMPILE Of the display list ID, none
of the ::gl commands were actually executed as in immediate mode.  So to actually
see anything this first time we need to "play the tape" of the display list
commands. Normally this dosn't matter, as most sprites get drawn over and 
over, but in the case where you're doing a one-shot draw of a temporary
sprite variable, this is an issue, for if we dont do the glCallList, then
you won't see anything. */
}

void cGraphicsOpenGL::drawpolygon(cPolygon *ppolygon, int drawflags )
{
	/* In my first version of the code I didn't know about glBegin(GL_POLYGON)
	and thought I had to break the polygon into triangles myself.  Feb, 18, 
	2004, I switched to using GL_POLYGON in the drawPolygon call, and cleaned
	up the code as well. It runs at about the same speed, though. But it's
	cleaner and now I can now use this method for rectangles, which looked
	like four triangles in the old way I was doing it. But doing this breaks
	my non-convex polygons, that is, my stars.  So I use the old way of
	drawing polygons as a drawstarpolygon method below. */ 
 
	int i; //We'll have a lot of loops.
//Find lighting, and decide whether to draw fill, draw edges, or both. 
	GLboolean currentlighting;
	::glGetBooleanv(GL_LIGHTING, &currentlighting);
	BOOL drawfill = ppolygon->filled() && !(drawflags & CPopView::DF_WIREFRAME);
			/* We fill if the polygon asks for fill and if we're not in
			 wireframe mode. */
	BOOL drawedges = (!drawfill) && //Edges suck if you have fill on.
		(ppolygon->edged() ||  (drawflags & CPopView::DF_WIREFRAME));
			/* We draw edges if polygon asks for edges, or if wireframe is 
			on. */
//Now allocate and register your vertices array.
	int size = ppolygon->vertCount(); 
	//So I don't have to repeatedly write out the long expression.
/* First create a vertex array holding the polygon vertices.  It doesn't matter that we may
be inside the display list GL_COMPILE recorder, because all the GL_COMPILE actually
"sees" is the actual values used in the vertex arrays. */
	glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT); 
		//Just so we can exit with state as we entered.
	glEnableClientState(GL_VERTEX_ARRAY);
	Real prismdz = ppolygon->prismDz();
	Real *vertices = NULL;
		//We'll use vertices to store the (bottom) face of the polygon,
		//and in the prismdz case we put the extra top face in there too.
	GLushort *quadindices = NULL;
	Real *edgenormals = NULL;

	// added by Joseph E. Sutton
	COLORREF color = ppolygon->fillColor();
	::glDisable(GL_LIGHTING); 

	if (prismdz)
	{
		vertices = new Real[2*3*(size)]; 
			/* The idea is to make two copies of an array that holds
			holds, flattened out, the x, y, and z coordinates of the
			size-many vertices.  And then, if prismDz()>0.0, you put
			another copy of this flat array, but with prismDz() added
			to the z-positioned numbers. */
		quadindices = new GLushort[4*size];
		edgenormals = new Real[3*size];
	}
	else //No prismdz means only draw one face, and you don't need edges.
		vertices = new Real[3*(size)]; 

//Now register the vertices pointer.
	glVertexPointer(3, GL_REAL, 0, (GLvoid*)vertices);

	/*
	 IMAGE decalImage;
		decalImage.Load("decal.bmp");
		decalImage.ExpandPalette();

		//Convert normal map to texture
		glGenTextures(1, &decalTexture);
		glBindTexture(GL_TEXTURE_2D, decalTexture);
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA8, decalImage.width, decalImage.height,
		0, decalImage.format, GL_UNSIGNED_BYTE, decalImage.data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	*/


		/* Arguments are (size of tuple, type of number, stride, array).
		The stride = 0 means don't skip over any vertices. */
//Set the size-count vertices of the polygon in slots 0 to size-1.
	for (i=0; i<size; i++)
	{
		vertices[3*i] = ppolygon->getVertex(i).x();
		vertices[3*i+1] = ppolygon->getVertex(i).y();
		vertices[3*i+2] = ppolygon->getVertex(i).z();
	}	

//Now get the main face normals ready.
	/* Assuming the polygon vertices are labeled CCW.   For our standard polys,
		upnormal and downnormal will	just be the pos and neg ZAXIS.
		For the edge faces, we take the cross product between the edge
		line and the upnormal, which works for asteroids and stars as
		well as for regular convex polys.*/
	cVector upnormal, downnormal;
	if(ppolygon->vertCount() >= 3)
		upnormal = (ppolygon->getVertex(1) - ppolygon->getVertex(0)) *
		(ppolygon->getVertex(2) - ppolygon->getVertex(0));
	if (upnormal.isZero())
		upnormal = cVector::ZAXIS;
#ifndef LET_OPENGL_NORMALIZE_LENGTH
	upnormal.normalize();
#endif //LET_OPENGL_NORMALIZE_LENGTH
	downnormal = -upnormal;

/* Note that  we draw the polygon with bottom face in the xy plane with the top face
in the plane z = prismdz */
	if (prismdz)
	{
//Make the top face
		for (i=0; i<size; i++)
		{
			vertices[3*(size) + 3*i] = vertices[3*i];
			vertices[3*(size) + 3*i + 1] = vertices[3*i + 1];
			vertices[3*(size) + 3*i + 2] = vertices[3*i + 2] + prismdz;
		}
/* Prepare the arrays you'll need to draw the edges of the prism. The vertices for these can be
found inside our vertices array, but in a special order.  Think of a polygon that is, say,
a triangle with verts at positions 1, 2, 3 and a copy
of the triangle with verts translated by prismDz(), at positions 1', 2', 3'.  To go around
the edge rects in counter clockwise order we want to hit 1, 2, 2', 1' and 2, 3, 3', 2' and so on.
OpenGL lets us store such a "rat's nest" index order in an array. */
		for (i=0; i<size-1; i++)
		{
			quadindices[4*i]     = i;
			quadindices[4*i + 1] = i + 1;
				/* Now skip to the second copy of	the verts, which is
				the copy with the prismDz() added into the z coords. */
			quadindices[4*i + 2] = size + i + 1;
			quadindices[4*i + 3] = size + i; 
		}
		//Now make the closing polygon edge face by hand.
		i = size-1;
		quadindices[4*i]     = size-1;
		quadindices[4*i + 1] = 0;
		quadindices[4*i + 2] = size;
		quadindices[4*i + 3] = size + size-1;

		cVector edgenormal;
			/* Do a cross product between an edge-line and the
			 upnormal to get a correct outward normal.  */
		for (i=0; i<size-1; i++)
		{
			edgenormal = (ppolygon->getVertex(i+1) - ppolygon->getVertex(i)) * 
				upnormal;
#ifndef LET_OPENGL_NORMALIZE_LENGTH
			edgenormal.normalize();
#endif //LET_OPENGL_NORMALIZE_LENGTH
			edgenormal = edgenormal * upnormal;  
				//We expect upnormal to be cVector::ZAXIS
			edgenormals[3*i] = edgenormal.x();
			edgenormals[3*i+1] = edgenormal.y();
			edgenormals[3*i+2] = edgenormal.z();
		}
	//Have to do the last edge normal as a special case as you wrap around to 0
		i=size-1;
		edgenormal = 0.5*(ppolygon->getVertex(0) - ppolygon->getVertex(i));
#ifndef LET_OPENGL_NORMALIZE_LENGTH
			edgenormal.normalize();
#endif //LET_OPENGL_NORMALIZE_LENGTH
		edgenormal = edgenormal * upnormal;
		edgenormals[3*i] = edgenormal.x();
		edgenormals[3*i+1] = edgenormal.y();
		edgenormals[3*i+2] = edgenormal.z();
	} //End the (prismdz) array loading code.
//HERE we finally start making some gl calls.
	if (drawfill)
	{
		setMaterialColorFrontAndBack(color); //For use with lighting
		setVertexColor(color); //For use with no lighting
		if (!prismdz)
		{
//Draw the top-facing polygon in non-prismdz
			::glNormal3f(upnormal.x(), upnormal.y(), upnormal.z()); 
			::glDrawArrays(GL_POLYGON, 0, size); 
				/* The top polygon. The glDrawArrays call takes the arguments
				(mode, starting vertex number, total number of vertices).
				It knows to pull off three Reals per counted vertex, that is,
				the array is regarded as an array of 3-tuples. */
		} //End drawfill non-prismdz case.
		else //(prismdz) fill case
		{
//Draw the top-facing polygon in prismdz
			::glNormal3f(upnormal.x(), upnormal.y(), upnormal.z()); 
			::glDrawArrays(GL_POLYGON, size, size); 
				/* The top polygon. The glDrawArrays call takes the arguments
				(mode, starting vertex number, total number of vertices).
				It knows to pull off three Reals per counted vertex, that is,
				the array is regarded as an array of 3-tuples. Note that in
				the prismdz case, the top polygon starts at vertex number size
				instead of at vertex number 0.*/
//Draw the bottom-facing polygon.
				/* The bottom face should have its vertices listed in the
				reverse order from the natural one so that, seen from outside
				the prism (which will be "from below"), they appear in the
				proper counterclockwise order. As far as the compiled code 
				is concerned what we do here is in fact about the same as a
				glDrawArrays call, except that this lets us reverse the
				order. */
			::glBegin(GL_POLYGON);
				::glNormal3f(downnormal.x(), downnormal.y(), downnormal.z()); 
				for (i = size-1; i>=0; i--) //Verts in reverse order.
					::glArrayElement(i);
			::glEnd();

//Draw the vertical band edge around the polygon
			setMaterialColorDim(color, 1.5);
				 //Make the edge brighter for lighting
			setVertexColorDim(color, 1.5);
				//Make the edge brighter for no lighting
			int normalsindex = 0;
			int quadindex = 0;
			
			for (i=0; i<size; i++)
			{
				::glBegin(GL_QUADS);
				::glNormal3f(edgenormals[normalsindex++],
					edgenormals[normalsindex++],
					edgenormals[normalsindex++]);
				::glArrayElement(quadindices[quadindex++]); 
				::glArrayElement(quadindices[quadindex++]); 
				::glArrayElement(quadindices[quadindex++]); 
				::glArrayElement(quadindices[quadindex++]); 
				::glEnd();
			}
		} //End drawfill prismdz  case.
	} //End drawfill case
	if (drawedges) 
		// We have no lighting and are filling and edging , or we have no fill
	{
//First pick a color for the lines.
		if (drawfill) /* If drawfill and drawedges are both on, this means you
			want contrasting edges. */
		{ 
			setVertexColor(ppolygon->lineColor());
				 //For use with no lighting
			setMaterialColorFrontAndBack(ppolygon->lineColor());
				//For use with lighting
		}
		else  /* Drawfill is off and drawedges is on, drawing a skeleton.
			In this case we use the polygon's fillcolor for the line. */
		{
			setVertexColor(color);
			setMaterialColorFrontAndBack(color);
		}
#ifdef DISABLEATTRIBUTESFORLINES
		glPushAttrib(GL_ENABLE_BIT); /* Save the enabled or disabled state of 
		GL_LIGHTING and GL_TEXTURE_2D, as we disable these here. */
		::glDisable(GL_LIGHTING); 
		/* Lines look bad with lighting.  We'll restore the lighting
		with the glPopAttrib below. */
		::glDisable(GL_TEXTURE_2D);// Lines done't work with texture on.
#endif //DISABLEATTRIBUTESFORLINES
//Draw the edge line of the bottom polygon
		::glLineWidth(cGraphicsOpenGL::DEFAULT_LINEPIXELS);
			//Must set this outside a glBegin/glEnd block.
		::glDrawArrays(GL_LINE_LOOP, 0, size);
			/* The glDrawArrays call takes the arguments
			(mode, starting vertex number, total number of vertices. */
		if (prismdz)
		{
//Draw the edge line of the top polygon
			::glDrawArrays(GL_LINE_LOOP, size, size);
//Draw vertical lines for the edges of the quads around the polygon edge.
			int quadindex = 0;
			for (i=0; i<size; i++)
			{
				::glBegin(GL_LINES);
					/* A quad's points are indexed so 0, 1
					are on bottom, and 2, 3 are on top, going
					the other way.  This means the vertical
					lines are from 0 to 3 and from 1 to 2. */
				::glArrayElement(quadindices[quadindex]); 
				::glArrayElement(quadindices[quadindex+3]); 
				::glArrayElement(quadindices[quadindex+1]); 
				::glArrayElement(quadindices[quadindex+2]); 
				quadindex+=4;
				::glEnd();
			}
		} //End drawedges prismdz case
#ifdef DISABLEATTRIBUTESFORLINES
	::glPopAttrib();  //Leave lighting and texture as it was before.
#endif //DISABLEATTRIBUTESFORLINES
	}  //End drawedges case

//Release the memory for the vertex arrays.
	delete vertices;
	vertices = NULL;
	if (prismdz)
	{
		delete quadindices;
		quadindices = NULL;
		delete edgenormals;
		edgenormals = NULL;
	}
	::glPopClientAttrib(); //To undo the glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
}

void cGraphicsOpenGL::drawstarpolygon(cPolygon *ppolygon, int drawflags )
{
	int i;
	int size = ppolygon->vertCount(); //So I don't have to repeatedly write out the long expression.
/* First create a vertex array holding the polygon vertices.  It doesn't matter that we may
be inside the display list GL_COMPILE recorder, because all the GL_COMPILE actually "sees"
is the actual values used in the vertex arrays. */
	glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT); //Just so we can exit with state as we entered.
	glEnableClientState(GL_VERTEX_ARRAY);
	Real *vertices = new Real[2*3*(size+2)]; /* The idea is to make two copies of an array that holds
		holds, flattened out, the x, y, and z coordinates of these size+2 points: the center,
		the size-many vertices, and the 0th vertex one more time.  And then, if prismDz()>0.0, you put
		another copy of this flat array, but with prismDz() added to the z-positioned numbers. */
	::glEnable(GL_LIGHTING);
//Set the origin in slot 0 (Not the polygon center, as we already took that into account
//by multiplying _spriteattitude at the right end of the modelveiw matrix.
	vertices[0] = 0.0; //ppolygon->center().x(); NO
	vertices[1] = 0.0; //ppolygon->center().y();
	vertices[2] = 0.0; //ppolygon->center().z();
//Set the size-count vertices of the polygon in slots 1 to size.
	for (i=0; i<size; i++)
	{
		vertices[3+3*i] = ppolygon->getVertex(i).x();
		vertices[3+3*i+1] = ppolygon->getVertex(i).y();
		vertices[3+3*i+2] = ppolygon->getVertex(i).z();
	}	
//Repeat the first vertex of the polygon in slot size+1 to close up (need this for the GL_TRIANGLE_FAN).
	vertices[3+3*size] = vertices[3];
	vertices[3+3*size+1] = vertices[3+1];
	vertices[3+3*size+2] = vertices[3+2];
	glVertexPointer(3, GL_REAL, 0, (GLvoid*)vertices); //(size of tuple, type of number, stride, array)

//We'll use these for the bottom face of the polygon, and we'll need them for drawing the edges as well.
	Real prismdz = ppolygon->prismDz();
/* Note that  we draw the polygon with bottom face in the xy plane with the top face
in the plane z = prismdz */

//	Real scalefactor = ppolygon->spriteattitude().scalefactor(); //For debugging.
//	if (scalefactor != 1.0)//For debugging.
//		TRACE("scalefactor %f", scalefactor);//For debugging.
	for (i=0; i<size+2; i++)
	{
		vertices[3*(size+2) + 3*i] = vertices[3*i];
		vertices[3*(size+2) + 3*i + 1] = vertices[3*i + 1];
		vertices[3*(size+2) + 3*i + 2] = vertices[3*i + 2] + ppolygon->prismDz();
	}	
/* Prepare the arrays you'll need to draw the edges of the prism. The vertices for these can be
found inside our vertices array, but in a special order.  Think of a polygon that is, say,
a triangle with verts at positions 1, 2, 3 and a copy
of the triangle with verts translated by prismDz(), at positions 1', 2', 3'.  To go around
the edge rects in counter clokwise order we want to hit 1, 2, 2', 1' and 2, 3, 3', 2' and so on.
OpenGL lets us store such a "rat's nest" index order in an array. */
	GLushort *quadindices = new GLushort[4*size];
	for (i=0; i<size; i++)
	{
		quadindices[4*i] = 1 + i; //The 1+ is to skip the center vertex in 0th place.
		quadindices[4*i + 1] =1 + i + 1;
		quadindices[4*i + 2] = (size + 2) + 1 + i + 1;/* The (size+2) + skips to the second
			copy of	the verts, which is the copy with the prismDz() added into the z coords. */
		quadindices[4*i + 3] = (size + 2) + 1 + i; 
	}

//Now get the normals ready.
	/* Assuming the polygon vertices are labelled CCW.   For our standard polys, upnormal 
		and downnormal will	just be the pos and neg ZAXIS. For the edge faces, 
		we take the cross product between the edge line and the upnormal, which works
		for asteroids and stars as well as for regular convex polys.   */
	cVector upnormal, downnormal;
	if(ppolygon->vertCount() >= 3)
		upnormal = (ppolygon->getVertex(1) - ppolygon->getVertex(0)) *
		(ppolygon->getVertex(2) - ppolygon->getVertex(0));
	if (upnormal.isZero())
		upnormal = cVector::ZAXIS;
	upnormal.normalize();
	downnormal = -upnormal;
	Real *edgenormals = new Real[3*size]; 
	cVector edgenormal;
/* Do a cross product between an edge-line and the upnormal to get a correct outward normal.  */
	for (i=0; i<size-1; i++)
	{
		edgenormal = (ppolygon->getVertex(i+1) - ppolygon->getVertex(i)) * 
			upnormal;
		//Midpoint of line between vert i and vert i+1
		edgenormal.normalize();
		edgenormal = edgenormal * upnormal;  //We expect upnormal to be cVector::ZAXIS
		edgenormals[3*i] = edgenormal.x();
		edgenormals[3*i+1] = edgenormal.y();
		edgenormals[3*i+2] = edgenormal.z();
	}
	//Have to do the last edge normal as a special case as you wrap around to 0
	i=size-1;
	edgenormal = 0.5*(ppolygon->getVertex(0) - ppolygon->getVertex(i));
	edgenormal.normalize();
	edgenormal = edgenormal * upnormal;
	edgenormals[3*i] = edgenormal.x();
	edgenormals[3*i+1] = edgenormal.y();
	edgenormals[3*i+2] = edgenormal.z();
//Find lighting, and decide whether to draw fill, draw edges, or both. 
	GLboolean currentlighting;
	::glGetBooleanv(GL_LIGHTING, &currentlighting);
	BOOL drawfill = ppolygon->filled() && !(drawflags & CPopView::DF_WIREFRAME);
			/* We fill if the polygon asks for fill and if we're not in
			 wireframe mode. */
	BOOL drawedges = (!drawfill) && //Edges suck if you have fill on.
		(ppolygon->edged() ||  (drawflags & CPopView::DF_WIREFRAME));
			/* We draw edges if polygon asks for edges, or if wireframe is 
			on. */
//HERE we finally start making some gl calls.
	if (drawfill)
	{
		setMaterialColorFrontAndBack(ppolygon->fillColor()); //For use with lighting
		setVertexColor(ppolygon->fillColor()); //For use with no lighting
//Draw the bottom-facing polygon.
		/* What we want to do here is to draw the center of the polygon, draw the size vertices, and
			then draw the frist vertex again to close up the fan. You might think you could do a
			simple call to ::glDrawArrays(GL_TRIANGLE_FAN, 0, size + 2);
			But, if we assume that in general we are drawing a prism, then the bottom face should have
			its vertices listed in the reverse order from the natural one so that, seen from outside the
			prism (which will be "from below"), they appear in the proper counterclockwise order. 
			This will prevent the bottom face from incorrectly disappearing if we call
			::glEnable(GL_CULLFACE). As far as the compiled code is concerned what we do here is in
			fact about the same as a glDrawArrays call, except that this lets us reverse the order. */ 
		::glBegin(GL_TRIANGLE_FAN);
		::glNormal3f(downnormal.x(), downnormal.y(), downnormal.z()); 
		::glArrayElement(0); //The center from slot 0.
		::glArrayElement(1); //The first vertex of the polygon from slot 1.
		for (i = size; i>0; i--) //The other polygon vertices in reverse order from slots size to 1.
			::glArrayElement(i);
		::glArrayElement(1); /* The first polygon vertex to close up the fan.  Or could use (size+1),
			as that's a copy of the first vertex as well. */ 
		::glEnd();
//Draw the top-facing polygon
		::glNormal3f(upnormal.x(), upnormal.y(), upnormal.z()); 
		::glDrawArrays(GL_TRIANGLE_FAN, size+2, size+2); 
			/* The top polygon. We have the center,
			the size-count vertices, and the repeated initial vertex in place.  The glDrawArrays call
			takes the arguments	(mode, starting vertex number, total number of vertices. It knows to
			pull off three Reals per counted vertex, that is, the array is regarded as an array of
			3-tuples. */
//Draw the vertical band edge around the polygon
		setMaterialColorDim(ppolygon->fillColor(), 1.5); //Make the edge brighter 
		setVertexColorDim(ppolygon->fillColor(), 1.5); //Make the edge brighter 
		int normalsindex = 0;
		int quadindex = 0;
		for (i=0; i<size; i++)
		{
			::glBegin(GL_QUADS);
			::glNormal3f(edgenormals[normalsindex++],edgenormals[normalsindex++],
				edgenormals[normalsindex++]); /* I wonder if something is wrong
					here, as the lighting I see on the edges doesn't seem logical */
			::glArrayElement(quadindices[quadindex++]); 
			::glArrayElement(quadindices[quadindex++]); 
			::glArrayElement(quadindices[quadindex++]); 
			::glArrayElement(quadindices[quadindex++]); 
			::glEnd();
		}
	}
	if (drawedges) //Either we have no lighting and are filling and edging , or we have no fill
	{
		if (drawfill) /* If drawfill and drawedges are both on, this means you
			want contrasting edges. */
		{ 
			setVertexColor(ppolygon->lineColor()); //For use with no lighting
			setMaterialColorFrontAndBack(ppolygon->lineColor()); //For use with no lighting
		}
		else  /* If drawfill is off and drawedges is on, we are drawing a skeleton of the polygon.
			In this case we use the polygon's fillcolor for the line. */
		{
			setVertexColor(ppolygon->fillColor());
			setMaterialColorFrontAndBack(ppolygon->fillColor());
		}
#ifdef DISABLEATTRIBUTESFORLINES
		glPushAttrib(GL_ENABLE_BIT); /* Save the enabled or disabled state of 
		GL_LIGHTING and GL_TEXTURE_2D, as we disable these here. */
		::glDisable(GL_LIGHTING); 
		/* Lines look bad with lighting.  We'll restore the lighting
		with the glPopAttrib below. */
		::glDisable(GL_TEXTURE_2D);// Lines done't work with texture on.
#endif //DISABLEATTRIBUTESFORLINES
//Draw the edge line of the bottom polygon
		::glLineWidth(cGraphicsOpenGL::DEFAULT_LINEPIXELS); //Must set this outside a glBegin/glEnd block.
		::glDrawArrays(GL_LINE_LOOP, 1, size); /* The glDrawArrays call takes the arguments
			(mode, starting vertex number, total number of vertices. */
//Draw the edge line of the top polygon
		::glLineWidth(cGraphicsOpenGL::DEFAULT_LINEPIXELS); //Must set this outside a glBegin/glEnd block.
		::glDrawArrays(GL_LINE_LOOP, size+2+1, size);
//Draw vertical lines for the edges of the quads around the polygon edge.
		::glLineWidth(cGraphicsOpenGL::DEFAULT_LINEPIXELS); //Must set this outside a glBegin/glEnd block.
		int quadindex = 0;
		for (i=0; i<size; i++)
		{
			::glBegin(GL_LINES);
				/* As it happens a quad's points are indexed so 0, 1 are on bottom, and 2, 3 are on
				top, going the other way.  This means the vertical lines are from 0 to 3 and
				from 1 to 2. */
			::glArrayElement(quadindices[quadindex]); 
			::glArrayElement(quadindices[quadindex+3]); 
			::glArrayElement(quadindices[quadindex+1]); 
			::glArrayElement(quadindices[quadindex+2]); 
			quadindex+=4;
			::glEnd();
		}
#ifdef DISABLEATTRIBUTESFORLINES
	::glPopAttrib();  //Leave lighting and texture as it was before.
#endif //DISABLEATTRIBUTESFORLINES
	}
//Release the memory for the vertex arrays.
	delete quadindices;
	quadindices = NULL;
	delete vertices;
	vertices = NULL;
	delete edgenormals;
	edgenormals = NULL;
	::glPopClientAttrib(); //To undo the glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
}


//====================================== cSpriteIcon and DisplayList stuff================
/* Give the static array member with the default constructor a place to live, 
that is, right here.  The default constructor sets its size to 0. */

//=========SpriteID
void cMap_SpriteIDToDisplayListID::garbageCollect()
{
#ifdef GARBAGECOLLECTDISPLAYLISTIDS
	POSITION pos = GetStartPosition();
	while( pos != NULL )
	{
	    cMapEntry_SpriteIDToDisplayListID *pmapentry;
		unsigned long key;
	    // Get key ( spriteID) and value ( cMapEntry_SpriteIDToDisplayListID )
		GetNextAssoc(pos, key, pmapentry);
	    // Use key and/or value
		if (--(pmapentry->_lifespan) <= 0)
		{
			::glDeleteLists(pmapentry->_displayListID, 1);
			RemoveKey(key); 
			delete pmapentry;
			pmapentry = NULL;
		}
	}
#endif //GARBAGECOLLECTDISPLAYLISTIDS
}

void cMap_SpriteIDToDisplayListID::free()
// We have to use a special kind of trick for iterating over a CMap.
{
	POSITION pos = GetStartPosition();
	while( pos != NULL )
	{
	    cMapEntry_SpriteIDToDisplayListID *pmapentry;
		unsigned long key;
	    // Get key ( spriteID) and value ( cMapEntry_SpriteIDToDisplayListID )
		GetNextAssoc( pos, key, pmapentry);
	    // Use key and/or value
		::glDeleteLists(pmapentry->_displayListID, 1);
		RemoveKey(key); 
		delete pmapentry;
		pmapentry = NULL;
	}
}
//==========ResourceID
void cMap_ResourceIDToTexture::garbageCollect()
{
/*	The idea here is that for every mapentry with a 0 or negative lifespan we delete its _pTexture.
In our current set-up, we will load only one texture for each _ResourceID, so this code is simpler
than the cGrahicsMFC::garbageCollect(). 
We have to use a special kind of trick for iterating over a CMap. */
#ifdef GARBAGECOLLECTTEXTURES
	POSITION pos = GetStartPosition();
	while( pos != NULL )
	{
	    cMapEntry_ResourceIDToTexture *pmapentry;
		int key;
	    // Get key ( resoruceID_key) and value ( cMapEntry_ResourceIDToTexture )
		GetNextAssoc( pos, key, pmapentry);
	    // Use key and/or value
		if (--(pmapentry->_lifespan) <= 0) 
		{//The -- in the line above ensures that a call to garbageCollect "ages" the images.
			delete pmapentry->_pTexture;
			pmapentry->_pTexture = NULL;
				// It's a good habit to always NULL a deleted pointer.
			RemoveKey(key);
			delete pmapentry;
			pmapentry = NULL;
		}
	}
#endif // GARBAGECOLLECTTEXTURES
}

void cMap_ResourceIDToTexture::free()
{
//We have to use a special kind of trick for iterating over a CMap.
	POSITION pos = GetStartPosition();
	while( pos != NULL )
	{
	    cMapEntry_ResourceIDToTexture *pmapentry;
		int key;
	    // Get key ( resourceID_key) and value ( cMapEntry_ResourceIDToTexture )
		GetNextAssoc( pos, key, pmapentry);
	    // Use key and/or value
		delete pmapentry->_pTexture;
		pmapentry->_pTexture = NULL;
		// It's a good habit to always NULL a deleted pointer.
		RemoveKey(key); 
		delete pmapentry;
		pmapentry = NULL;
	}
}
//=====================SkinFileID
void cMap_SkinFileIDToTexture::garbageCollect()
{
#ifdef GARBAGECOLLECTTEXTURES
/*	The idea here is that for every mapentry with a 0 or negative lifespan we delete its _pTexture.
In our current set-up, we will load only one texture for each _SkinFileID, so this code is simpler
than the cGrahicsMFC::garbageCollect(). 
We have to use a special kind of trick for iterating over a CMap. */
	POSITION pos = GetStartPosition();
	while( pos != NULL )
	{
	    cMapEntry_SkinFileIDToTexture *pmapentry;
		int key;
	    // Get key ( skinFileID_key) and value ( cMapEntry_SkinFileIDToTexture )
		GetNextAssoc( pos, key, pmapentry);
	    // Use key and/or value
		if (--(pmapentry->_lifespan) <= 0) 
		{//The -- in the line above ensures that a call to garbageCollect "ages" the images.
			delete pmapentry->_pTexture;
			pmapentry->_pTexture = NULL;
				// It's a good habit to always NULL a deleted pointer.
			RemoveKey(key);
			delete pmapentry;
			pmapentry = NULL;
		}
	}
#endif //GARBAGECOLLECTTEXTURES
}

void cMap_SkinFileIDToTexture::free()
{
//We have to use a special kind of trick for iterating over a CMap.
	POSITION pos = GetStartPosition();
	while( pos != NULL )
	{
	    cMapEntry_SkinFileIDToTexture *pmapentry;
		int key;
	    // Get key ( resoruceID_key) and value ( cMapEntry_SkinFileIDToTexture )
		GetNextAssoc( pos, key, pmapentry);
	    // Use key and/or value
		delete pmapentry->_pTexture;
		pmapentry->_pTexture = NULL;
		// It's a good habit to always NULL a deleted pointer.
		RemoveKey(key); 
		delete pmapentry;
		pmapentry = NULL;
	}
}

void cGraphicsOpenGL::garbageCollect()
{
	_map_ResourceIDToTexture.garbageCollect();
	_map_SkinFileIDToTexture.garbageCollect();
	_map_SpriteIDToDisplayListID.garbageCollect();
}

void cGraphicsOpenGL::free()
{
	_map_ResourceIDToTexture.free();
	_map_SkinFileIDToTexture.free();
	_map_SpriteIDToDisplayListID.free();
}

cTexture* cGraphicsOpenGL::_getTexture(cSpriteIcon *picon)
{
	cTexture *ptexture = _map_ResourceIDToTexture.lookupTexture(picon->resourceID());

		/* If successful, the lookupTexture call will set the _lifetime to 
		cMapEntry_ResourceIDToTexture::FRESHLIFESPAN to protect the thing from
		getting culled by garbageCollect. */ 
	if (!ptexture)	//We didn't find one, so we make one.
	{
		ptexture = new cTexture(picon->resourceID(), picon->usesTransparentMask());
		ASSERT(ptexture);
			/* We record a new cMapEntry_ResourceIDToTexture matching the
			resourceID and ptexture.  The constructor gives it a FRESHLIFESPAN
			as well. */
		_map_ResourceIDToTexture.SetAt(picon->resourceID(),
			new cMapEntry_ResourceIDToTexture(ptexture)); 
	}
		/* The picon has an _aspect that perhaps has not yet been checked against the aspect of
		the texture it will get.  If we don't require that the
		icon keep some fixed preset aspect (as when we use the icon to fill a fixed aspect
		backgroudn rectangle for instance), we go ahead and tell it to match the aspect 
		of the image the texture is based on. Note that the cSpriteIcon::setAspect will 
		not chagne the 	cSpriteIcon->radius(), but it will change its sizex and sizey to
		have a ratio matching the aspect.*/
	if (!picon->imageloaded() && !picon->presetaspect())
			picon->setAspect(ptexture->imageaspect());
	return ptexture;	//All done!							
}

void cGraphicsOpenGL::drawbitmap(cSpriteIcon *picon, int drawflags )
{ 

#ifndef DONTWIREFRAMEBITAPS /* If the DONTWIREFRAMEBITAPS define switch is on always just do next code block.
		The DONTWIREFRAMEBITAPS is defined (or not) in graphics.h so as to apply to all cGraphics children.*/
	if (!(drawflags & CPopView::DF_WIREFRAME)) //Normal drawing mode.
#endif //DONTWIREFRAMEBITMAPS
	{
		//Get the ptexture so you can find the index of the Texture object inside it.
		cTexture *ptexture = cGraphicsOpenGL::_getTexture(picon); 

		if (!picon->imageloaded()) //One way or another, you've managed to load the image now.
			picon->setImageloaded(TRUE);

		selectTexture(ptexture); 

		if (!(picon->tiled()))
		{	
			::glBegin(GL_QUADS); //Walk from lower left counterclockwise around the rectangle.
				::glTexCoord2f(0.0f, 0.0f); ::glVertex3f(-0.5*picon->sizex(), -0.5*picon->sizey(), 0.0f);
				::glTexCoord2f(1.0f, 0.0f); ::glVertex3f( 0.5*picon->sizex(), -0.5*picon->sizey(), 0.0f);
				::glTexCoord2f(1.0f, 1.0f); ::glVertex3f( 0.5*picon->sizex(),  0.5*picon->sizey(), 0.0f);
				::glTexCoord2f(0.0f, 1.0f); ::glVertex3f(-0.5*picon->sizex(),  0.5*picon->sizey(), 0.0f);
			::glEnd();
		}
		else //begin tiled() case
		{
			int xtiles = picon->xtilecount(); // number of y tiles
			int ytiles = ceil(xtiles/picon->aspect()); //aspect is sizex/sizey.
			GLfloat startX = picon->lox();
			GLfloat startY = picon->loy();
			GLfloat stepX = picon->sizex() / xtiles;
			GLfloat stepY = picon->sizey() / ytiles;  
			::glBegin(GL_QUADS);
			for (int j=0;j<ytiles;j++)
			{
				for (int i=0;i<xtiles;i++)
				{
					::glTexCoord2f(0,0);	
					::glVertex3f(startX, startY, 0);

					::glTexCoord2f(1,0);	
					::glVertex3f(startX + stepX, startY, 0);

					::glTexCoord2f(1,1);	
					::glVertex3f(startX + stepX, startY + stepY, 0);

					::glTexCoord2f(0,1);	
					::glVertex3f(startX, startY + stepY, 0);

				startX += stepX;
				}
				startX=picon->lox();
				startY += stepY;
			}
			::glEnd();
		} //End tiled() case
//		ptexture->unselect();
	} //End non-wireframe case.
#ifndef DONTWIREFRAMEBITAPS
	else //Draw a hollow circle and rectangle
	{
		cColorStyle colorstyle;
		colorstyle.setFilled(FALSE);
		drawcircle(picon->center(), picon->radius(), &colorstyle);
		drawrectangle(picon->locorner(), picon->hicorner(), &colorstyle);
	}
#endif //DONTWIREFRAMEBITAPS
}

void cGraphicsOpenGL::adjustAttributes(cSprite *psprite)
{ 
	GLfloat black[4] =  { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat white[4] =  { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat gray[4] =  { 0.6f, 0.6f, 0.6f, 1.0f };

#ifdef UNCONDITIONAL_ADJUSTATTRIBUTES
	//UNCONDITIONAL_ADJUSTATTRIBUTES does enable or disable even
	// if already in place
		/* I'll enable or disable GL_TEXTURE_2D.  It must be ON to draw
		a cSpriteIcon or cSpriteQuake, but if I draw a solid face, then
		texture must be OFF, or the face comes out black. */ 
	if (!psprite->usesTexture()) 
	{
		::glDisable(GL_TEXTURE_2D);
		::glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, gray );
	}
if (psprite->usesTexture())
	{
		::glEnable(GL_TEXTURE_2D);
/* The following calls don't do anything unles we've enabled texture. 
If we comment out ALLOWALPHATRANSPARENCY in texture.cpp, then you will
in fact never have transparent icon. The speed of transparency, however,
seems not to be a noticeable factor.  What IS noticeable is that, transparent 
or not, cSpritIcon will  slowly if they are very large (near to the viewer
and taking up a lot of the window with a very coarse magnified pixel size.) */
		if (psprite->usesTransparentMask())
		{
			::glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
				/*	We are going to set the transparent parts of our textures to have
				alpha value of zero.  There are two possible ways to let things "show through"
				the transparent alpha.  We presently do a clipping-style alpha test.  Even if
				we were to turn on blending, some tests indicate that without the alpha test,
				the textures would only be transparent in one direction. 
					This technique for getting a transparent background of a texture is
				mentioned in the Red Book, and indexed under "billboarding". We have set
				the alpha to 0 for our transparent texture backgrounds, but we need
				the GL_ALPHA_TEST as well, otherwise the "transparent" pixels can still cover
				up underlying pixels (unless we enable GL_BLEND, but I find the GL_ALPHA_TEST
				easier to get working, as described in the next comment. */
			//::glEnable(GL_ALPHA_TEST);
			 /* I'm turning alpha test on in my 
				cGraphics::adjustAttributes(psprite) call*/
			::glAlphaFunc(GL_GREATER, 0.1f);
			::glColor4f(0.0, 0.0, 0.0, 1.0); //Fix BaseColor and BaseAlpha
				/* As well as making the background transparent, we still have the issue
				of making the colors show up as you want them too when GL_BLEND is on.
					Set the BaseColor (first three numbers) and BaseAlpha (fourth
				number), for the polygon you plan to put the texture onto.  The
				texture has its own TextureColor and TextureAlpha.
					How the Texture and Base blend depends on which _textureFunction
				my texture has.  (Our transparent cTexture objects use GL_BLEND and
				the non-transparent ones use GL_DECAL.) Where necessary, we think of
				the * as operating term-by-term on	the color components.  The
				formula for GL_BLEND is this:
					FinalColor = BaseColor*(1-TextureColor) + TextureEnviromentColor*TextureColor;
					FinalAlpha = BaseAlpha * TextureAlpha
					In other words, with GL_BLEND, if TextureAlpha	is 1 we see the TextureColor,
				and if TextureAlpha is 0.0	we see transparency.  This last comment
				depends on making the BaseColor have RGB 0.0 and on making
				the TextureEnvironmentColor have RGB 1.0.  You change
				TextureEnvironmentColor with this glTexEnvfv call. */
			GLfloat environmentcolors[4] = {1.0, 1.0, 1.0, 1.0};
			::glTexEnvfv(GL_TEXTURE_ENV, 
				GL_TEXTURE_ENV_COLOR, environmentcolors ); 
		::glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, black );
	}
		else //Not usesTransparentMask.
	{
		if (!psprite->IsKindOf(RUNTIME_CLASS(cSpriteQuake)))
		{
			::glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, 
				GL_REPLACE);
			::glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, black );
		}
		else //quake sprite
		{
			::glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, 
				GL_MODULATE);
			::glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, white );
			::glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white );
		}
	}
}
	if (!psprite->usesAlpha())
		::glDisable(GL_ALPHA_TEST);
	if (psprite->usesAlpha())
	{
		::glEnable(GL_ALPHA_TEST);
//		::glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	if (!psprite->usesLighting())
		::glDisable(GL_LIGHTING);
	if (psprite->usesLighting())
		::glEnable(GL_LIGHTING);
#else //not UNCONDITIONAL_ADJUSTATTRIBUTES, only enable or disable if needed
	/* I'll enable or disable GL_TEXTURE_2D.  It must be ON to draw
	a cSpriteIcon or cSpriteQuake, but if I draw a solid face, then texture must
	be OFF, or the face comes out black. */ 
	GLboolean istextureon;
	::glGetBooleanv(GL_TEXTURE_2D, &istextureon);
	if (istextureon && !psprite->usesTexture()) 
		::glDisable(GL_TEXTURE_2D);
	if (!istextureon && psprite->usesTexture())
		::glEnable(GL_TEXTURE_2D);
	GLboolean isalphaon;
	::glGetBooleanv(GL_ALPHA_TEST, &isalphaon);
	if (isalphaon && !psprite->usesAlpha())
		::glDisable(GL_ALPHA_TEST);
	if (!isalphaon && psprite->usesAlpha())
		::glEnable(GL_ALPHA_TEST);
	GLboolean islightingon;
	::glGetBooleanv(GL_LIGHTING, &islightingon);
	if (islightingon && !psprite->usesLighting())
		::glDisable(GL_LIGHTING);
	if (!islightingon && psprite->usesLighting())
		::glEnable(GL_LIGHTING);
#endif //UNCONDITIONAL_ADJUSTATTRIBUTES
}

BOOL cGraphicsOpenGL::selectTexture(cTexture *ptexture) /* Returns
		TRUE if the texture is selected, returns FALSE if either the ptexture is
		NULL or if an equivalent texture was already active so ptexture
		didn't need to be selected. */
{
	if (_ptextureactive)
	{
		if (ptexture->textureID() == _ptextureactive->textureID())
			return FALSE;
	}
	::glBindTexture(GL_TEXTURE_2D, ptexture->textureID());
		/* Or I could call ptexture->select(), which wraps this same call. */
	_ptextureactive = ptexture;	
	return TRUE;	
}


void cGraphicsOpenGL::selectSkinTexture(cMD2Model *pmodel)
{
	int skinfileID = pmodel->skinfileKey();

	cTexture *ptexture = _map_SkinFileIDToTexture.lookupTexture(skinfileID);
		/* If successful, the lookupTexture call will set the _lifetime to 
		cMapEntry_SkinFileIDToTexture::FRESHLIFESPAN to protect the thing from
		getting culled by garbageCollect. */ 
	if (!ptexture)	//We didn't find one, so we make one.
	{
		ptexture = new cTexture(pmodel->ptextureinfo());
		ASSERT(ptexture);
			/* We record a new cMapEntry_ResourceIDToTexture matching the
			resourceID and ptexture.  The constructor gives it a FRESHLIFESPAN
			as well. */
		_map_SkinFileIDToTexture.SetAt(skinfileID,
			new cMapEntry_SkinFileIDToTexture(ptexture)); 
	}
	selectTexture(ptexture); /* If _ptextureactive == ptexture does nothing,
		otherwise uses ::glBindTexture(GL_TEXTURE_2D, ptexture->_textureID) */
}

//helper

void CalculateNormal(float *p1, float *p2, float *p3)
{
	float a[3], b[3], result[3];
	
	a[0] = p1[0] - p2[0];
	a[1] = p1[1] - p2[1];
	a[2] = p1[2] - p2[2];
	
	b[0] = p1[0] - p3[0];
	b[1] = p1[1] - p3[1];
	b[2] = p1[2] - p3[2];
	
	result[0] = a[1] * b[2] - b[1] * a[2];
	result[1] = b[0] * a[2] - a[0] * b[2];
	result[2] = a[0] * b[1] - b[0] * a[1];
#ifdef LET_OPENGL_NORMALIZE_LENGTH
	::glNormal3f(result[0], result[1], result[2]);
#else //not LET_OPENGL_NORMALIZE_LENGTH
	// calculate the length of the normal
	float length = (float)sqrt(
		result[0]*result[0] + result[1]*result[1] + result[2]*result[2]);
	::glNormal3f(result[0]/length, result[1]/length, result[2]/length);
#endif //LET_OPENGL_NORMALIZE_LENGTH
}

void cGraphicsOpenGL::interpolateAndRender(cMD2Model *pmodel,
	vector_t *startframe, vector_t *endframe, float interpolationpercent)
{
//#define MYVECTORWAY
#ifdef MYVECTORWAY  
	/*I want to clean up this code and get rid of the CalculateNormal call by
		using my cVector class and its glVertex() method. But not today. */
#else
	int i;                        // index counter
	float x1, y1, z1;             // current frame point values
	float x2, y2, z2;             // next frame point values
	vector_t vertex[3]; 
	mesh_t* triangles = pmodel->triIndex(); 
	int numberoftriangles = pmodel->numTriangles();
	texCoord_t *texturecoords = pmodel->textureCoords();		// texture coordinate list
		
		/* At one point, I tested if it would be faster here to
		call :glNewList(1, GL_COMPILE), draw into a display list object,
		and then at the end call glEndList(); glCallList(1);
		The answer is, NO, don't do this, as it cuts your speed to 30% of
		what it is otherwise.  The reason is perhaps that the move messes
		up your use of texture IDs.	Just do the triangles. */

	selectSkinTexture(pmodel);
	setMaterialColor(cColorStyle::CN_WHITE); 
		/* For the lighting calculations
		on the meshes, I'll treat the creatutures as as white.  I'll use
		the specular component of the lighting later, thanks to the fact
		that I've called 	::glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,
		GL_SEPARATE_SPECULAR_COLOR); */
	::glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		/* I can try using GL_MODULATE insetad of teh default GL_DECAL. */

	glBegin(GL_TRIANGLES);
	for (i = 0; i < numberoftriangles; i++)
	{
		// get first points of each frame
		x1 = startframe[triangles[i].meshIndex[0]].point[0];
		y1 = startframe[triangles[i].meshIndex[0]].point[1];
		z1 = startframe[triangles[i].meshIndex[0]].point[2];
		x2 = endframe[triangles[i].meshIndex[0]].point[0];
		y2 = endframe[triangles[i].meshIndex[0]].point[1];
		z2 = endframe[triangles[i].meshIndex[0]].point[2];
		
		// store first interpolated vertex of triangle
		//Note that interpol is between 0.0 and 1.0
		vertex[0].point[0] = x1 + interpolationpercent * (x2 - x1);
		vertex[0].point[1] = y1 + interpolationpercent * (y2 - y1);
		vertex[0].point[2] = z1 + interpolationpercent * (z2 - z1);
		
		// get second points of each frame
		x1 = startframe[triangles[i].meshIndex[2]].point[0];
		y1 = startframe[triangles[i].meshIndex[2]].point[1];
		z1 = startframe[triangles[i].meshIndex[2]].point[2];
		x2 = endframe[triangles[i].meshIndex[2]].point[0];
		y2 = endframe[triangles[i].meshIndex[2]].point[1];
		z2 = endframe[triangles[i].meshIndex[2]].point[2];
		
		// store second interpolated vertex of triangle
		vertex[2].point[0] = x1 + interpolationpercent * (x2 - x1);
		vertex[2].point[1] = y1 + interpolationpercent * (y2 - y1);
		vertex[2].point[2] = z1 + interpolationpercent * (z2 - z1);   
		
		// get third points of each frame
		x1 = startframe[triangles[i].meshIndex[1]].point[0];
		y1 = startframe[triangles[i].meshIndex[1]].point[1];
		z1 = startframe[triangles[i].meshIndex[1]].point[2];
		x2 = endframe[triangles[i].meshIndex[1]].point[0];
		y2 = endframe[triangles[i].meshIndex[1]].point[1];
		z2 = endframe[triangles[i].meshIndex[1]].point[2];
		
		// store third interpolated vertex of triangle
		vertex[1].point[0] = x1 + interpolationpercent * (x2 - x1);
		vertex[1].point[1] = y1 + interpolationpercent * (y2 - y1);
		vertex[1].point[2] = z1 + interpolationpercent * (z2 - z1);
		
		// calculate the normal of the triangle
		CalculateNormal(vertex[0].point, vertex[2].point, vertex[1].point);
		
		// render properly textured triangle
		glTexCoord2f(texturecoords[triangles[i].stIndex[0]].s, texturecoords[triangles[i].stIndex[0]].t);
		glVertex3fv(vertex[0].point);
		
		glTexCoord2f(texturecoords[triangles[i].stIndex[2]].s, texturecoords[triangles[i].stIndex[2]].t);
		glVertex3fv(vertex[2].point);
		
		glTexCoord2f(texturecoords[triangles[i].stIndex[1]].s, texturecoords[triangles[i].stIndex[1]].t);
		glVertex3fv(vertex[1].point);
	}
	glEnd();
#endif //MYVECTORWAY
}


//LIGHTING METHODS
/* installLightingModel gets called by the cGraphicsOpenGL constructor for now, to
set up some standard lights in OpenGL.
  Eventually we should give installLightingModel an argument of type say, cLightingModel*.
And then we could let each cGame have a cLightingModel *_plighting object.  And instead
of (or, maybe to make the code more reusable, in addition to) calling installLightingModel
in the thhe cGraphicsOpenGL constructor, we could have
(a) cGame::initializeView(cPopView *pview) call
		pview()->pgraphics()->installLightingModel(_plighting);
(b)	Graphics mode change handlers like CPopView::OnViewOpenglgraphics() call
		pgraphics()->installLightingModel(pgame()->plighting());
(c) cGraphicsOpenGL::cGraphicsOpenGL calls
		installLightingModel(cGraphics::STANDARDLIGHTINGMODEL),
		where cLightingModel cGraphics::STANDARDLIGHTINGMODEL is a static.
 */

void cGraphicsOpenGL::installLightingModel(cLightingModel *plightingmodel)
{
	if (!plightingmodel)
		enableLighting(TRUE);
	else
		enableLighting(plightingmodel->enableLighting());

/* At present we always add these lights, later we'll tailor this code to
get the light info out of the plightingmodel object. */

//1 set the material properties for objects.
	GLfloat materialSpecular[4] =
		// { 0.1f, 0.1f, 0.1f, 1.0f };
			//Look ok, but a bit dull with materialShininess 2
			//Pops too hard with materialShininess 5
		// { 0.3f, 0.3f, 0.3f, 1.0f }; 
			//Pretty nice flow with materialShininess 2
			//Pops too hard with materialShininess 3
		 //{ 0.45f, 0.45f, 0.45f, 1.0f };
			//Smooth lively flow with materialShininess 2.
		  { 0.6f, 0.6f, 0.6f, 1.0f };
			//Pops  a bit with materialShininess 2.
			//Pops hard glaring white highlights with materialShininess 15.
	GLfloat materialShininess[1] = { 2.0f }; 
		//{ 15.0f } gave too abrupt a glare 
		//was 35.0.  Bigger means smaller sized highlight.  Range is 0.0 to 128.0
	::glMaterialfv( GL_FRONT, GL_SPECULAR, materialSpecular );
	::glMaterialfv( GL_FRONT, GL_SHININESS, materialShininess );
//	::glMaterialfv( GL_FRONT, GL_SPECULAR, materialSpecular );
//	::glMaterialfv( GL_FRONT, GL_SHININESS, materialShininess );
 	setMaterialColor(cColorStyle::CN_WHITE); //Restore to a default state.
	/*cGraphicsOpenGL::setMaterialColor is my method, and this call
	with a CN_WHITE
	argument is equivalent to
	GLfloat materialAmbDiff[4]={ 1.0f, 1.0f, 1.0f, 1.0f };
	::glMaterialfv( GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialAmbDiff );
	We alter the GL_AMBIENT_AND_DIFFUSE setting with a call to setMaterialColor
	inside each of our cGraphicsOpenGL::draw??? methods. We make these 
	setMaterialColor calls so that our objects will have intrinsic colors. */

//2 set the LightModel settings, including global ambient lighting.
	GLfloat global_ambient[4] = { 0.45f, 0.45f, 0.45f, 1.0f }; //not too bright
	::glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
	//::glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE );
		/* If I enable GL_LIGHT_MODEL_LOCAL_VIEWER it runs slower but the highlights are more accurate */
//	::glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE );
		/* If I use the GL_LIGHT_MODEL_TWO_SIDE, I have nice light when I'm
		 like inside a teapot. */
		/* This next call is an OpenGL 1.2 method, and I need to include
		glext.h for it to work, as wretched Windows still ships with only
		OpenGl 1.1, trying to make us use DirectX.  Thanks, Bill... */
	::glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);

#ifndef ONLYAMBIENTLIGHT
//3 set the lights.

	//3.1 Define the lights' properties.
/* The ambient is a directionless light that's simply added in; really since we have
a global_ambient above it's less confusing to have the indivdiual light ambients be zero.
	The diffuse is closest to the "color" of the light.
	The specular is used for color highlights, logically it can match diffuse, but
it looks peppier if its different.
	The position, if it has 0 in the fourth coord, is specifying the (x,y,z) direction
of the light, treated as parallel lines form infinity.  If you want to put the light in the 
position (x,y,z) then you put 1 in the fourth coord, and then the light is viewed as
radiating in all directions form this point. */
/* Let's try and pick four directions of light with roughly one dirction comign in towards
the origin from each vertex of a tetrahedron positioned with a point on the negative z
axis and another point on the yz plane. 
	We'll give different colors for the different directions, for the sake of visual
variety.  But try and make the net sum of light coming down from the positive Z be
white. 
	We'll give all the lights zero ambient, and just use the global ambient. */
	GLfloat ambient0[] =  { 0.0f, 0.0f, 0.0f, 1.0f }; 
    GLfloat diffuse0[] =  { 0.1f, 0.1f, 0.4f, 1.0f };//Blue
    GLfloat specular0[] = { 0.1f, 0.1f, 0.4f, 1.0f };
    GLfloat position0[] = { -1.0f, -0.5f, -1.0f, 0.0f }; //Dir to origin from hix, hiy, hiz.

	GLfloat ambient1[] =  { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat diffuse1[] =  { 0.4f, 0.1f, 0.1f, 1.0f }; //Red
    GLfloat specular1[] = { 0.4f, 0.1f, 0.1f, 1.0f };
    GLfloat position1[] = { 1.0f, -0.5f, -1.0f, 0.0f }; //Dir to origin from lox, hiy, hiz.
  
	GLfloat ambient2[] =  { 0.0f, 0.0f, 0.0f, 0.0f };
    GLfloat diffuse2[] =  { 0.1f, 0.4f, 0.1f, 1.0f }; //Green
    GLfloat specular2[] = { 0.1f, 0.4f, 0.1f, 1.0f };
    GLfloat position2[] = { 0.0f, 1.0f, -1.0f, 0.0f }; //Dir to origin from zero, loy, hiz
 
	GLfloat ambient3[] =  { 0.0f, 0.0f, 0.0f, 0.0f };
    GLfloat diffuse3[] =  { 0.25f, 0.250f, 0.25f, 1.0f }; //White
    GLfloat specular3[] = { 0.25f, 0.25f, 0.25f, 1.0f };
    GLfloat position3[] = { 0.0f, 0.0f, 1.0f, 0.0f }; //Dir to origin from zero, zero, loz

	/* 3.2 turn off all lights.  There are least eight by default, and possibly more in
	some implemetnations. */
    ::glDisable(GL_LIGHT0);  
    ::glDisable(GL_LIGHT1);  
    ::glDisable(GL_LIGHT2);  
    ::glDisable(GL_LIGHT3);  
    ::glDisable(GL_LIGHT4);  

	//3.3 Enable your lights
	//Enable Light0
	//Always have at least one light.
    ::glEnable(GL_LIGHT0);  
    ::glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
    ::glLightfv(GL_LIGHT0, GL_POSITION, position0);
    ::glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
    ::glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
	//Enable Light1
	if (NUMBEROFLIGHTS > 1) //NUMBEROFLIGHTS is a #define between 1 and 4.
	{
		::glEnable(GL_LIGHT1);
	    ::glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
		::glLightfv(GL_LIGHT1, GL_POSITION, position1);
	    ::glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
		::glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);
	}
	//Enable Light2
	if (NUMBEROFLIGHTS > 2) //NUMBEROFLIGHTS is a #define between 1 and 4.
	{
	    ::glEnable(GL_LIGHT2);  
		::glLightfv(GL_LIGHT2, GL_AMBIENT, ambient2);
		::glLightfv(GL_LIGHT2, GL_POSITION, position2);
		::glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse2);
		::glLightfv(GL_LIGHT2, GL_SPECULAR, specular2);
	}
	//Enable Light3 
	if (NUMBEROFLIGHTS > 3) //NUMBEROFLIGHTS is a #define between 1 and 4.
	{
		::glEnable(GL_LIGHT3);  
	    ::glLightfv(GL_LIGHT3, GL_AMBIENT, ambient3);
		::glLightfv(GL_LIGHT3, GL_POSITION, position3);
		::glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse3);
		::glLightfv(GL_LIGHT3, GL_SPECULAR, specular3);
	}
#endif //ONLYAMBIENTLIGHT
}

void cGraphicsOpenGL::enableLighting(BOOL onoff)
{
	if (onoff)
		::glEnable(GL_LIGHTING);
	else
		::glDisable(GL_LIGHTING);
} 

