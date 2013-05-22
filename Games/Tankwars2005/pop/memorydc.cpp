#include "stdafx.h"
#include "MemoryDC.h"
#include <math.h> //for ceiling and floor

IMPLEMENT_SERIAL(cMemoryDC, CDC, 0);
IMPLEMENT_SERIAL(cTransparentMemoryDC, cMemoryDC, 0);


 const int cMemoryDC::ST_NON_ISO =1;
 const int cMemoryDC::ST_ISO_COVER_TARGET =2;
 const int cMemoryDC::ST_ISO_USE_WHOLE_SOURCE =4;

/* This flag is used for a constructor call to get a screen-sized cMemoryDC */
 const int cMemoryDC::CMEMDC_ONEPIXEL =0;
 const int cMemoryDC::CMEMDC_FULLSCREEN =1;

//----------------------cMemoryDC------------
cMemoryDC::cMemoryDC(): 
_blankcolor(RGB(255,255,255)),
_resize_on_load(TRUE), //Willing to change size.
_cx(1),
_cy(1)
{
/* We use the default constructor mostly for cMemoryDC which we are planning
to load with a resource or file bitmap, which is why we set _resize_on_load
to TRUE.  Loading a resource or file bitmap calls setHBITMAP, which calls
the CDC::Select, which requires that the HDC m_hDC field inside our cMemoryDC
is valid (and not a default NULL value).  So we need to get a valid m_hDC even
in the default constructor.  So as not to duplicate code, the simplest thing
to do is to set _cx = _cy = 1 and call _allocate.  This also puts a valid
(1 x 1) HBITMAP into _cBitmap, which is just as well, so that we can always
assume that _cBitmap does currently have a valid bitmap. */
	_allocate();
}

cMemoryDC::cMemoryDC(int enumSize, COLORREF blankcol): //constructor
_blankcolor(blankcol),
_resize_on_load(FALSE) //Want to stay at fullscreen size
{ /* Usually we call this with the enumSize CMEMDC_FULLSCREEN).
	SM_C?FULLSCREEN gives the actual size of a fullscreen client window's
screen measured in pixels.  This assumes the window has a caption.
Let's also subtract off the region for the menu. Since we usually use this kind
of cMemoryDC for a "virtual window" copy of an active window, it makes sense to
do call clear in here. */
	if (enumSize == CMEMDC_ONEPIXEL)
	{
		_cx = 1;
		_cy = 1;
	}
	else
	{
/* I used to set the _cx and _cy to just be large enough to cover the
largest possible client window, using the following calls.  Note that the
SM_CXFULLSCREEN argument to GetSystemMetrics returns a pixel measurement of the
client area and not of the full screen. */
//		_cx = GetSystemMetrics(SM_CXFULLSCREEN); 
//		_cy = GetSystemMetrics(SM_CYFULLSCREEN)- GetSystemMetrics(SM_CYMENU);
/* And then I started using a trick to magnify the size of my window and
shift it so that only the client area shows --- Alvin Cho found this trick on
the web as a way of making a windowed app appear to be a clean fullscreen app.
For this to work, you need to be able to bitblt the full screen size, and this
is what you get if you use the SM_CXSCREEN argument.  I add in the SM_CXBORDER
which is only a few pixels to try and shave off the thin window border as well,
though I'm not sure if this actually has an effect.  The bulk of the fullscreen
code is in mainfrm.cpp of the Pop framework, starting with build 34.4. */
		_cx = ::GetSystemMetrics(SM_CXSCREEN) + ::GetSystemMetrics(SM_CXBORDER);
		_cy = ::GetSystemMetrics(SM_CYSCREEN) + ::GetSystemMetrics(SM_CYBORDER);
	}
	_allocate();
	clear();
}

cMemoryDC::~cMemoryDC() //destructor
{ /* All I really need to do here is DeleteDC(), as the GdiObject destructors
	would do the DeleteObject on _cBitmap and cBrush_blank, but it seems tidier
	to just call the _free method, which does the GdiObject cleanup explicitly.
	There's no harm, by the way, in calling CGdiObject::DeleteObject twice,
	as the first call sets the GDI object handle to NULL, and a DeleteObject
	does nothing to a NULL. */ 
	_free();
}

void cMemoryDC::setSize(int cx, int cy)
{
	_free();
	_cx = cx;
	_cy = cy;
	_allocate();
}

// ==========cMemoryDC Copy stuff

cMemoryDC::cMemoryDC(const cMemoryDC &memDC)
{
	_copy(memDC);
}

cMemoryDC::cMemoryDC(const cTransparentMemoryDC &trMemDC)
{
	_copy(trMemDC);
}

cMemoryDC& cMemoryDC::operator=(const cMemoryDC &memDC)
{
	_copy(memDC);
	return *this;
}

cMemoryDC& cMemoryDC::operator=(const cTransparentMemoryDC &trMemDC)
{
	_copy(trMemDC);
	return *this;
}

// cMemoryDC memory helper functions-----------------------

void cMemoryDC::_allocate()
{
	CDC cDC_display; 
		/* Get a CDC* from the physical screen window.  I used to use 
		cDC_display.AfxGetMainWnd()->GetDC() here, but if I initialize a
		cMemoryDC early in my program, like inside the CMainFrame::OnCreate
		function, then AfxGetMainWnd() returns NULL and the GetDC call will
		fail. Note that when we exit this function the CDC destructor will do
		the cDC_display.DeleteDC() call for us. */
	CBitmap *pBitmap_old; /* The CreateConmpaticleDC call below selects a 
		non-empty HBITMAP into our CDC, and we need to kill that after selecting 
		it out. */ 
	cDC_display.CreateDC("DISPLAY", NULL, NULL, NULL);
	CreateCompatibleDC(&cDC_display); /* Allocates a memory CDC and selects into
		it a CBitmap holding an	HBITMAP with an area of one pixel. */
	if (!_cBitmap.CreateCompatibleBitmap(&cDC_display, _cx, _cy)) 
		/* You must use a physical screen CDC* as an argument to
		CreateCompatible Bitmap; if you used "this" instead of "&cDC_display,
		it won't work.
			CreateCompatible Bitmap is really a memory allocation call as
		bitmap has size, so it might very well fail. The call
		returns a zero if it fails.  If it fails we bail, otherwise we continue.
			Note that before this call, the default CBitmap constructor has put a
		NULL m_hObject HBITMAP inside _cBitmap. */
	{
		errorBox((LPSTR)"Failure in Bitmap Allocation!",(LPSTR)"Memory Problems!");
		return;
	}
	pBitmap_old = SelectObject(&_cBitmap); //Now we have a _cx by _cy area.
	pBitmap_old->DeleteObject(); /* Otherwise the encapsulated one-pixel HBITMAP
		never gets deleted and our program has a resource leak. */
}

void cMemoryDC::_copy(const cMemoryDC &memDC)
{ 
	setSize(memDC._cx, memDC._cy);
	_blankcolor = memDC._blankcolor;
	_resize_on_load = memDC._resize_on_load;
	BitBlt(0, 0, _cx, _cx, (CDC*)&memDC, 0, 0, SRCCOPY);
}

void cMemoryDC::_copy(const cTransparentMemoryDC &trMemDC)
{
	int i,j;

	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT)); /* Because this
		takes so long we turn on the hourglass while we do it */
	_copy((cMemoryDC)trMemDC); /* You can always trivially downcast to your
		parent class as it's data members are a subset of your data 
		members. */
	/* Now we undo what makeTransparent does.  We color the transparent pixels
		_blankcolor.  Which are those?  The ones that are WHITE in
		_pMemDC_mask and BLACK in _hdc. */
	for (j=0; j<_cy; j++)
		for (i=0; i<_cx; i++)
		{
			if ( (trMemDC.GetPixel(i, j) == RGB(0,0,0)) &&
				(trMemDC._pMemDC_mask->GetPixel(i, j) == 
					RGB(255,255,255)) )
				SetPixel(i, j, _blankcolor);
		}
	// Finally, code in the _blankcolor color as the pixel at (0, 0).
	if (trMemDC._transparent_color_equals_corner_color)
		SetPixel(0, 0, _blankcolor);
}

void cMemoryDC::_free()
{
/* I am going to be resizing my bitmaps in some of my methods, so I'm going
to need to be able to release the GDI objects and start over.  There is a
rule that you can't delete a GDI tool while it is selected into a valid 
HDC, so first we get rid of the DC and then we can get rid of the GDI 
objects.
	There is no harm in calling DeleteDC twice or _cBitmap.DeleteObject
twice because after the first Delete??? call the respective m_hDC or m_hObject is
NULL and the second Delete??? call does nothing if the m_?? is NULL.
	By the same token, it doesn't hurt if you call _free before _allocate, as
in the copy constructor, because the default m_??? are NULL, and thus their
wrapper objects do nothing with the Delete??? calls. */
	DeleteDC();
	//Delete the cBitmap.
	_cBitmap.DeleteObject();
	//now the parent CDC parent destructor is called.
}

// cMemoryDC methods-----------------------

void cMemoryDC::clear()
{ //This clears the cBitmap.
	clear(CRect(0,0,_cx,_cy));
}

void cMemoryDC::clear(const CRect &rect)
{ //This clears the cBitmap.
	CBrush *pBrush_old;
	CBrush cBrush_blank(_blankcolor);

	pBrush_old = SelectObject(&cBrush_blank);
	//This covers the screen with the selected brush pattern.
	PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
	SelectObject(pBrush_old);
	cBrush_blank.DeleteObject();
}


void cMemoryDC::copyTo(CDC *pDC)
{
	CRect rect;
	rect = CRect(0, 0, _cx, _cy);
	copyTo(pDC, rect);
}

void cMemoryDC::copyTo(CDC *pDC, const CRect &copyrect)
{
	pDC->BitBlt(copyrect.left, copyrect.top, //Next two arguments are width and height
		copyrect.Width(), copyrect.Height(),
		this, copyrect.left, copyrect.top, SRCCOPY);
	if (pDC->GetRuntimeClass() == RUNTIME_CLASS(cTransparentMemoryDC))
		((cTransparentMemoryDC*)pDC)->makeTransparent();
}


void cMemoryDC::stretchTo(CDC *pDC, const CRect &targetrect, const CRect &sourcerect)
{
	pDC->StretchBlt(targetrect.left, targetrect.top,
		targetrect.Width(), targetrect.Height(),
		this, sourcerect.left, sourcerect.top,
		sourcerect.Width(), sourcerect.Height(), SRCCOPY);
	if (pDC->GetRuntimeClass() == RUNTIME_CLASS(cTransparentMemoryDC))
		((cTransparentMemoryDC*)pDC)->makeTransparent();
}

void cMemoryDC::stretchTo(CDC *pDC, const CRect &targetrect, int nFlags)
{
	/* When the pDC is for print or print preview, it has a clip box rect of
	something like (-10, -10, 2000, 3000), and what happens if you do CopyTo
	is that you don't see anything at all.  Maybe your image gets squeezed up
	near (-10, -10), which isn't even visible in the print preview (off the
	upper left corner of the page). So we use a StretchBlt instead of the 
	BitBlt used by cMemoryDC::CopyTo. Note that stretchTo is virtual and has in internal
	switch on pDC->GetRuntimeClass as well, so it actually has four possible behaviors
	depending on whether the source and target are cMemoryDC or cTransparentMemoryDC.
	*/
	if (nFlags & ST_NON_ISO)
		stretchTo(pDC, targetrect, 
		CRect(0, 0, _cx, _cy)); //sourcerect
	else
	{
		int source_cx = _cx;
		int source_cy = _cy;
		int target_cx = targetrect.Width();
		int target_cy = targetrect.Height();
		int target_left = targetrect.left;
		int target_top = targetrect.top;
		adjustStretch(source_cx, source_cy, target_left, target_top, target_cx, target_cy, nFlags);
		stretchTo(pDC, CRect(target_left, target_top, target_cx, target_cy),
			CRect(0, 0, source_cx, source_cy)); //Note this method is virtual
	}
}

void cMemoryDC::stretchTo(cMemoryDC *pDC)
{
	stretchTo(pDC,
		CRect(0, 0, pDC->cx(), pDC->cy()), //targetrect
		CRect(0, 0, _cx, _cy)); //sourcerect
}

void cMemoryDC::setBlankColor(COLORREF blankcol)
{
	_blankcolor = blankcol;
}

void cMemoryDC::copyFrom(CDC *pDC, const CRect &rect)
{
	setSize(rect.right - rect.left, rect.bottom - rect.top);
	//Now copy the rect region of hdc to the (0,0) position of _hdc
	BitBlt(0, 0, _cx, _cy, pDC, rect.left, rect.top, SRCCOPY);
}

void cMemoryDC::pasteTo(CDC *pDC, const CPoint &corner)
{ //Copy all of _hdc to the hdc rect with corner at corner.
	pDC->BitBlt(corner.x, corner.y, _cx, _cy, (CDC*)this, 0, 0, SRCCOPY);
}

void cMemoryDC::centeredPasteTo(CDC *pDC, const CPoint &center)
{
	CPoint corner = center - CSize( _cx/2, _cy/2 );
	pasteTo(pDC, corner);
}

//cMemoryDC Loading and Saving

void cMemoryDC::setHBITMAP(HBITMAP hBitmap_new)
{		/* This puts the HBITMAP field in_cBitmap.  We assume nobody else has 
		wrapped up hBitmap_new, so we don't need to worry about it getting 
		destroyed. */
	BITMAP bm;	//Bitmap structure for getting size.
	CBitmap cBitmap_dummy;
	SelectObject(&cBitmap_dummy); /* This unselects current _cBitmap so
		that I am free to delete its HBITMAP without upsetting my CDC. This 
		is a spot where it is necessary for the m_hDC field be non-NULL, 
		otherwise you'll get an error.  If for some reason you wanted a 
		constructor which would leave m_hDC NULL and then perhaps call this 
		method, you'd need to put in a special case here to handle the m_hDC 
		== NULL option. */
	_cBitmap.DeleteObject();
	_cBitmap.Attach(hBitmap_new);
	SelectObject(_cBitmap); //Put the _cBitmap back in place.
	_cBitmap.GetObject(sizeof(BITMAP), (LPVOID)&bm);
	_cx = bm.bmWidth;
	_cy = bm.bmHeight;
}

void cMemoryDC::loadResourceBitmap(LPSTR resource_name)
{ /* We sometimes use this to initialize a cMemoryDC, i.e. we do this right after
construction.  Since we will be calling CDC::Select on a CBitmap, it is necessary
that the m_hDC field be initialized and non-NULL before you do this or you get
an error.  This is why we have our default constructor initialize the m_hDC. */
	CBitmap cBitmap_new;
	HBITMAP hbitmap_new;
	cMemoryDC *pMemDC_copy; //Use this in the NOT _resize_on_load case.
	if (!cBitmap_new.LoadBitmap(resource_name))
		//If there's not enough memory, tell & bail.
	{
		errorBox((LPSTR)"Failure in Bitmap Loading!", (LPSTR)resource_name);
		return;
	}
/* We want to take the HBITMAP field away from cBitmap_new and give it to a
_cBitmap.  We don't want to let cBitmap_new keep the HBITMAP because otherwise
when it goes out of scope and hits its destructor, it will do a DeleteObject on
the HBITMAP.  The HBITMAP() in the next line here is an overloaded CBitmap
casting operator that gets the HBITMAP field out of a CBitmap. The reason that
we "hand over" the HBITMAP instead of putting it into a cMemDC_temp and calling
cMemDC_temp.copyTo(this) is that the latter option would waste time. */
	hbitmap_new = HBITMAP(cBitmap_new); // Get the HBITMAP
	cBitmap_new.Detach(); // Take it away from cBitmap_new
	if (_resize_on_load)
		setHBITMAP(hbitmap_new);
	else   //don't resize the calling cMemoryDC.
	{
		pMemDC_copy = new cMemoryDC();  // Default 1 x 1 cMemoryDC
		pMemDC_copy->setHBITMAP(hbitmap_new);
		pMemDC_copy->stretchTo(this, CRect(0,0,_cx,_cy), ST_NON_ISO); 
			//anisotropic
		delete pMemDC_copy;
		pMemDC_copy = NULL;
	}
}

void cMemoryDC::loadResourceBitmap(int resource_ID)
{
	loadResourceBitmap((LPSTR)MAKEINTRESOURCE(resource_ID));
}

void cMemoryDC::loadFileBitmap(CFile *pFile)
{
	cMemoryDC	*pMemDC_copy; //Use this in the NOT _resize_on_load case.
	HBITMAP hbitmap_new = NULL;    // handle to the bitmap

	hbitmap_new = ::readBitmapFile(pFile); //The helper function at the end
		/* You can't allocate this guy as a cMemoryDC, as you have
		no idea what his size is! */
	if (!hbitmap_new) //If there's not enough memory, tell & bail.
	{
		errorBox((LPSTR)"Failure in Bitmap Loading!", "CFile");
		return;
	}
	if (_resize_on_load)
		/* The reason that we "hand over" the HBITMAP instead of putting it 
		into a	 cMemDC_temp and calling cMemDC_temp.copyTo(this) is that the 
		latter option would waste time, and would also require some resizing. 
		*/
		setHBITMAP(hbitmap_new);
	else   //don't resize the calling cMemoryDC.
	{
		pMemDC_copy = new cMemoryDC(); // Default 1 x 1 cMemoryDC
		pMemDC_copy->setHBITMAP(hbitmap_new);
		pMemDC_copy->stretchTo(this, CRect(0,0,_cx,_cy), ST_NON_ISO); 
			//anisotropic
		delete pMemDC_copy; //Don't need hbitmap_new anymore
		pMemDC_copy = NULL;
	}
}

void cMemoryDC::saveFileBitmap(CFile *pFile)
{
	::writeBitmapFile(pFile, _cBitmap);  //The helper function at the end
}

void cMemoryDC::loadFileBitmap(LPSTR file_bitmap_name)
{ /* For wider usefulness, we allow load and save from file names rather
than already open CFile*.  When you open a cFile you need to specify both
a read/write mode and a sharing mode. */

	CFile cFile;
if (!cFile.Open(file_bitmap_name, CFile::modeRead | CFile::shareDenyWrite))
	{
		errorBox("LARRYDIB.C module",
			"ReadBitmapFile(): Unable to open bitmap file");
		return;
	}
	loadFileBitmap(&cFile);
	//CFile::~CFile destructor will call cFile.Close().
}

void cMemoryDC::saveFileBitmap(LPSTR file_bitmap_name)
{
	CFile cFile;
	if (!cFile.Open(file_bitmap_name, CFile::modeCreate |
		CFile::modeWrite | CFile::shareExclusive))
	{ //modeCreate will empty out a pre-existing file of the same name.
		errorBox("LARRYDIB.C module",
			"ReadBitmapFile(): Unable to open bitmap file for writing");
		return;
	}
	saveFileBitmap(&cFile);
	//CFile::~CFile destructor will call cFile.Close().
}

void cMemoryDC::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
		saveFileBitmap(ar.GetFile()); //CArchive::GetFile() returns a CFile*
	else
		loadFileBitmap(ar.GetFile());
}

// cMemoryDC Clipboard Methods

void cMemoryDC::copyToClipboard(const CRect &rect_select)
{ /* This makes a temporary cMemDC_clipboard cMemoryDC, puts the desired image in 
its _cBitmap, gives the  HBITMAP member to the clipboard, makes sure the 
cMemDC_clipboard no longer owns the HBITMAP, and then lets the cMemDC_clipboard 
go out of scope and be destroyed by the automatic going-out-of-scope destructor 
call. */
	cMemoryDC cMemDC_clipboard;
	cMemDC_clipboard.copyFrom(this, rect_select); //Resize and BitBlt.
	AfxGetMainWnd()->OpenClipboard();
	EmptyClipboard();
	SetClipboardData(CF_BITMAP, HBITMAP(cMemDC_clipboard._cBitmap));
		// The HBITMAP on the right is an overloaded CBitmap cast operator.
	CloseClipboard();
	cMemDC_clipboard._cBitmap.Detach();
		/* Let go of HBITMAP you gave the clipboard before your destructor 
		happens. */
}

void cMemoryDC::copyFromClipboard()
{ /*  This method bails if there's no HBITMAP on clipboard, otherwise it resizes
the caller to match the clipboard and copies what's on the clipboard.
	This function makes a temporary cMemoryDC cMemDC_clipboard which we use as
a superwrapper around the clipboard HBITMAP so we can copy it to our caller
cMemoryDC.
	A key thing to remember here is that we must be careful not to DeleteObject
the clipboard bitmap. So we want to let go of hbitmap_clipboard by the time we
exit. */
	HBITMAP hbitmap_clipboard; /* Note that since this is not a CBitmap,
		we don't need to worry about a destructor and DeleteObject call
		happening to this automatically when we exit this method.  In
		other words we can copy the clipboard HBITMAP into this temporary
		handle variable and then painlessly let this variable die. */
	BITMAP bm; //Use this to figure out the size of hbitmap_clipboard, if any.
	cMemoryDC cMemDC_clipboard; /* Use this to superwrap the hbitmap_clipboard
		so you can copy it to your caller. */

	AfxGetMainWnd()->OpenClipboard();
	hbitmap_clipboard = (HBITMAP)GetClipboardData(CF_BITMAP);
	CloseClipboard();
	if (!hbitmap_clipboard)
		return;
	::GetObject(hbitmap_clipboard, sizeof(BITMAP), (PSTR) &bm); /* Use the
		global version of the GetObject function to get size. */
	setSize(bm.bmWidth, bm.bmHeight); /* Get ready to hold a copy of the 
		hbitmap_clipboard image. */
	cMemDC_clipboard.setHBITMAP(hbitmap_clipboard); /* Take a default cMemoryDC
		cMemoryDC_clipboard and put the cBitmap_clipboard in it. Remember 
		that when you delete cMemoryDC_clipboard you have to make sure to 
		Detach hbitmap_clipboard from cMemoryDC_clipboard._cBitmap because 
		the clipboard's bitmap must not be invalidated. */
	cMemDC_clipboard.pasteTo(this, CPoint(0,0)); //BitBlt whole _cBitmap.
	cMemDC_clipboard._cBitmap.Detach();/* Absolutely necessary, see comment 
		just above! */
}

//--------------cTransparentMemoryDC---------
/* In writing these child contructors and the child destructor, remember that
when an child class is constructed, the parent class constructor of the same
signature is automatically called before the child constructor code, unless you
yourself request a different parent class constructor.
	And when a child class is destroyed, the parent destructor is called after
the child destructor code.  */

cTransparentMemoryDC::cTransparentMemoryDC():
_transparent_color_equals_corner_color(TRUE),
_pMemDC_mask(NULL) // Just to be safe, don't let a bad pointer be in here.
{
	_allocate_mask_device();
	makeTransparent();
}

cTransparentMemoryDC::cTransparentMemoryDC(int enumSize, COLORREF blankcol ):
_transparent_color_equals_corner_color(TRUE),
_pMemDC_mask(NULL) // Just to be safe, don't let a bad pointer be in here.
{
	_allocate_mask_device();
	makeTransparent();
}

cTransparentMemoryDC::cTransparentMemoryDC(const cMemoryDC &memDC):
_transparent_color_equals_corner_color(TRUE),
_pMemDC_mask(NULL) // Just to be safe, don't let a bad pointer be in here.
{
	_allocate_mask_device();
	makeTransparent();
}

cTransparentMemoryDC::cTransparentMemoryDC(const cTransparentMemoryDC &trMemDC):
cMemoryDC(),
	 /* We explicitly call the () base class destructor because otherwise the
	compiler will choose the base class constructor of the signature, i.e. the
	copy constructor, and the transparent trMemDC will be wastefully transformed
	into a standard cMemoryDC that you will immediately throw out. */
_pMemDC_mask(NULL) // So the _free_mask_device called inside _copy does nothing. 
{
	_copy(trMemDC);
}

cTransparentMemoryDC::~cTransparentMemoryDC()
{
	_free();
}

cTransparentMemoryDC& cTransparentMemoryDC::operator=(const cMemoryDC &memDC)
{
	_copy(memDC);
	return *this;
}

cTransparentMemoryDC& cTransparentMemoryDC::operator=(const cTransparentMemoryDC &trMemDC)
{
	_copy(trMemDC);
	return *this;
}

void cTransparentMemoryDC::setSize(int cx, int cy)
{
	_free();
	_cx = cx;
	_cy = cy;
	_allocate();
}

//------cTransparentMemoryDC Helper functions -----

void cTransparentMemoryDC::_allocate()
{
	cMemoryDC::_allocate();
	_allocate_mask_device();
}

void cTransparentMemoryDC::_allocate_mask_device()
{
	_pMemDC_mask = new cMemoryDC();
	if (!_pMemDC_mask)
		errorBox((LPSTR)"Failure in Transparent Bitmap Allocation!",
			(LPSTR)"Memory Problems!");
	_pMemDC_mask->setSize(_cx, _cy);
}

void cTransparentMemoryDC::_copy(const cMemoryDC &memDC)
{  /* Assume that you've already done a _free() before you call _copy, or
that you're memory hasn't been _alllocated yet.
The cMemoryDC::_copy call has an _allocate call inside it.  Although wasn't
not obvious to me initially, it turns out that since I am calling that _allocate
with my cTransparentMemoryDC object *this, that _allocate will actually execute
as cTransparentMemoryDC::_allocate, even though it's inside a cMemoryDC method.
So I don't need to have _allocate_mask_device after the cMemoryDC::_copy(memDC)
call, as I used to think I needed. 
	The same thing is true for _free.  The _free call in cMemoryDC::_copy
actually calls the cTransparentMemoryDC::_free, so I don't need to do a 
_free_mask_device before the _copy call. */
	cMemoryDC::_copy(memDC); 
	makeTransparent();
}

void cTransparentMemoryDC::_copy(const cTransparentMemoryDC &trMemDC)
{
	_blankcolor = trMemDC._blankcolor;
	_transparent_color_equals_corner_color =
		trMemDC._transparent_color_equals_corner_color;
	setSize(trMemDC._cx, trMemDC._cy);
	BitBlt(0, 0, _cx, _cx, (CDC *)&trMemDC, 0, 0, SRCCOPY);
	_pMemDC_mask->BitBlt(0, 0, _cx, _cx, trMemDC._pMemDC_mask, 0, 0, SRCCOPY);
}

void cTransparentMemoryDC::_free()
{
	cMemoryDC::_free();
	_free_mask_device();
}

void cTransparentMemoryDC::_free_mask_device()
{
	if (_pMemDC_mask)
		delete _pMemDC_mask;
	_pMemDC_mask = NULL;   //Set to NULL in case you do two frees.
}

//------cTransparentMemoryDC Methods-----------------

void cTransparentMemoryDC::makeTransparent()
{
	int i,j;
	COLORREF imagecolor;
/*   To understand what we are doing here, and why, first look at
cTransparentMemoryDC::pasteTo. Briefly, we want to be able to AND 
_pMemDC_mask with the target and then OR _hdc with the target, and have
the image come through, with the "transparent" pixels left unchanged. 
makeTransparent uses the current _hdc to make a makeTransparent version
of _hdc and a makeTransparent _pMemDC_mask.  Wherever there is a "transparent" 
pixel in _hdc you want BLACK in the fixed _hdc, and you want WHITE in the 
_pMemDC_mask.  Wherever there is an image pixel (that is a non-transparent pixel)
in _hdc, you want it the same in the makeTransparent _hdc and you want
it BLACK in _pMemDC_mask. */
	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT)); /* Because this
		takes so long we turn on the hourglass while we do it */
	for (j=0; j<_cy; j++)
		for (i=0; i<_cx; i++)
		{
			imagecolor = GetPixel(i, j);
			if (imagecolor == _blankcolor)
				//Pixel is part of the background.
			{
				_pMemDC_mask->SetPixel(i, j, RGB(255,255,255));
				SetPixel(i, j, RGB(0,0,0));
			}
			else //The pixel is part of the image.
			{
				_pMemDC_mask->SetPixel(i, j, RGB(0,0,0));
				/* SetPixel(i, j, imagecolor);  Don't need to do
				this because the color is already in place! */
			}
		}
}

void cTransparentMemoryDC::copyFrom(CDC *pDC, const CRect &rect)
{ /* When you do a copyFrom here you should first do a
	setBlankColor(backgroundcolor) for whatever the current screen background
	color is --- because it's possible you have the WRONG blankcolor in here
	as the result of a loadFileBitmap call.  Of course if you have just
	constructed your TransparentWindowBimtmap with backgroundcolor as an
	argument then this isn't a problem. */
	cMemoryDC::copyFrom(pDC, rect);
	makeTransparent();
}

void cTransparentMemoryDC::pasteTo(CDC *pDC, const CPoint &point)
{  /* You (or a method) call cTransparentMemoryDC::makeTransparent before this 
call. makeTransparent has prepared _pMemDC_mask to be BLACK where the image goes,
and WHITE where the transparent background goes.  The SRCAND BitBlt (which
does a bitwise AND between source and target) sets the pixels in the target image 
location to BLACK and leaves the others alone.  That is, it nukes exactly those 
pixels where the image is to go.  makeTransparent has prepared _hdc to have the 
correct colors in the image region, and to have BLACK in the transparent 
background.  The SRCPAINT (BitBlt (which does a bitwise OR between source and 
target) puts the image pixels in the target location and leaves the others
alone. */
	pDC->BitBlt(point.x, point.y, _cx, _cy, _pMemDC_mask, 0, 0, SRCAND);
	pDC->BitBlt(point.x, point.y, _cx, _cy, this, 0, 0, SRCPAINT);
}

void cTransparentMemoryDC::setHBITMAP(HBITMAP hBitmap_new)
{
	_free_mask_device();
	cMemoryDC::setHBITMAP(hBitmap_new);
	_allocate_mask_device();
}

void cTransparentMemoryDC::loadResourceBitmap(LPSTR resource_bitmap_name)
{
	cMemoryDC::loadResourceBitmap(resource_bitmap_name); /* Because we have
		make setHBITMAP a virtual, note that in the _resize_on_load case,
		this will call setHBITMAP, which will be the cTransparentMemoryDC
		version which will resize the *_pMemDC_mask. */
	if (_transparent_color_equals_corner_color)
			setBlankColor(GetPixel(0, 0)); /* Assume blankcolor
				is equal to the corner color of the pixel image */
	makeTransparent();
}

void cTransparentMemoryDC::loadResourceBitmap(int resource_ID)
{
	loadResourceBitmap(MAKEINTRESOURCE(resource_ID));
}

void cTransparentMemoryDC::loadFileBitmap(LPSTR file_bitmap_name)
{
	cMemoryDC::loadFileBitmap(file_bitmap_name); /* This calls setHBITMAP, 
		which will also resize the *_pMemDC_mask */
	if (_transparent_color_equals_corner_color)
			setBlankColor(GetPixel(0, 0)); /* Assume blankcolor
		is equal to the corner color of the pixel image */
	makeTransparent();
}

void cTransparentMemoryDC::loadFileBitmap(CFile *pFile)
{
	cMemoryDC::loadFileBitmap(pFile);
	if (_transparent_color_equals_corner_color)
			setBlankColor(GetPixel(0, 0)); /* Assume blankcolor
		is equal to the corner color of the pixel image */
	makeTransparent();
}

void cTransparentMemoryDC::saveFileBitmap(LPSTR file_bitmap_name)
{
/* Use a copy constructor to make a copy of this which has _blankcolor in the 
transparent regions.  We store _blankcolor in position (0,0), provided 
_transparent_color_equals_corner_color is TRUE. */
	cMemoryDC cMemDC_save(*this); /* Calls the
		 cMemoryDC(cTransparentMemoryDC&)copy constructor. */
	cMemDC_save.saveFileBitmap((char *)file_bitmap_name); /* Calls the
		cMemoryDC::saveFileBitmap function */
	/* When you exit this call, cMemDC_save goes out of scope and
		calls its own destructor. */
}

void cTransparentMemoryDC::saveFileBitmap(CFile *pFile)
{
/* Use a copy constructor to make a copy of this which has _blankcolor in the 
transparent regions.  We store _blankcolor in position (0,0), provided 
_transparent_color_equals_corner_color is TRUE. */
	cMemoryDC cMemDC_save(*this); /* Calls the
		 cMemoryDC(cTransparentMemoryDC&)copy constructor. */
	cMemDC_save.saveFileBitmap(pFile); /* Calls the
		cMemoryDC::saveFileBitmap function */
	/* When you exit this call, cMemDC_save goes out of scope and
		calls its own destructor. */
}

void cTransparentMemoryDC::clear(const CRect &rect)
{ // Makes it transparent, with black in the main cdc, white in the mask.
	PatBlt(rect.left, rect.top, rect.Width(), rect.Height(),
		BLACKNESS);
	_pMemDC_mask->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(),
		WHITENESS);
}

void cTransparentMemoryDC::copyTo(CDC *pDC, const CRect &copyrect)
{ // This uses the same idea as cTransparentMemoryDC::pasteTo.
	if (!(pDC->IsKindOf(RUNTIME_CLASS(cTransparentMemoryDC))))
	{
		pDC->BitBlt(copyrect.left, copyrect.top,
			copyrect.right - copyrect.left, copyrect.bottom - copyrect.top,
			_pMemDC_mask, copyrect.left, copyrect.top, SRCAND);
		pDC->BitBlt(copyrect.left, copyrect.top,
			copyrect.right - copyrect.left, copyrect.bottom - copyrect.top,
			this, copyrect.left, copyrect.top, SRCPAINT);
	}
	else
	{
		cTransparentMemoryDC * pTransDC = (cTransparentMemoryDC *)pDC;
		pTransDC->BitBlt(copyrect.left, copyrect.top,
			copyrect.Width(), copyrect.Height(),
			this, copyrect.left, copyrect.top, SRCCOPY);
		pTransDC->_pMemDC_mask->BitBlt(copyrect.left, copyrect.top,
			copyrect.Width(), copyrect.Height(),
			_pMemDC_mask, copyrect.left, copyrect.top, SRCCOPY);
	}
}

void cTransparentMemoryDC::stretchTo(CDC *pDC, const CRect &targetrect, const CRect &sourcerect)
{
	if (!(pDC->IsKindOf(RUNTIME_CLASS(cTransparentMemoryDC))))
	{
		pDC->StretchBlt(targetrect.left, targetrect.top,
			targetrect.Width(), targetrect.Height(),
			_pMemDC_mask, sourcerect.left, sourcerect.top,
			sourcerect.Width(), sourcerect.Height(), SRCAND);
		pDC->StretchBlt(targetrect.left, targetrect.top,
			targetrect.Width(), targetrect.Height(),
			this, sourcerect.left, sourcerect.top,
			sourcerect.Width(), sourcerect.Height(), SRCPAINT);
	}
	else
	{
		cTransparentMemoryDC * pTransDC = (cTransparentMemoryDC *)pDC;
		pTransDC->StretchBlt(targetrect.left, targetrect.top,
			targetrect.Width(), targetrect.Height(),
			this, sourcerect.left, sourcerect.top,
			sourcerect.Width(), sourcerect.Height(), SRCCOPY);
		pTransDC->_pMemDC_mask->StretchBlt(targetrect.left, targetrect.top,
			targetrect.Width(), targetrect.Height(),
			_pMemDC_mask, sourcerect.left, sourcerect.top,
			sourcerect.Width(), sourcerect.Height(), SRCCOPY);
	}
}

// cMemoryDC Clipboard Methods

void cTransparentMemoryDC::copyToClipboard(const CRect &rect_select)
{ /* There's some waste motion here in that we are converting all of the bitmap,
and really only need to convert the rect_select.  If this ever becomes important
you can speed it up. */
	cMemoryDC cMemDC(*this); //Make a bitmap with a normal background.
	cMemoryDC::copyToClipboard(rect_select); //Copy a rect from it.
}

void cTransparentMemoryDC::copyFromClipboard()
{ 
/*			The first time I wrote this function, I did it like this:
	cMemoryDC cMemDC_clipboard;
	cMemDC_clipboard.copyFromClipboard();
	_copy(cMemDC_clipboard);
			But this method is slightly wasteful in that has an extra 
		BitBlt, from the clipboard bitmap to the bitmap in cMemDC_clipboard, 
		which have to BitBlt to the caller cTransparentMemoryDC again.  In 
		the improved code below we effectively BitBlt direct from the 
		clipboard bitmap to our caller.
			Another reason the code below is better is that I'm not using 
		the _copy function, so that's one less method to worry about 
		maintaining.
*/
	cMemoryDC *pMemDC = (cMemoryDC *)this; /* Downcast your this pointer to a
		cMemoryDC pointer so you can call the cMemoryDC::copyFromClipboard 
		method without the internal functions like _free and _allocate 
		doing extra cTransparentMemoryDC things.  We do this because to begin 
		with we just want to make sure and do the exact 
		cMemoryDC::copyFromClipboard code so that we can get a copy of the 
		hbitmap_clipboard inside our caller _cBitmap.
			If we try to put pMemDC->copyFromClipboard() in the next line
		the cTransparentMemoryDC::copyFromClipboard method will be called,
		even though the pMemDC is a cMemoryDC*; this is because we are making
		this call inside of a cTransparentMemoryDC method.
			So we override the copyFromClipboard call to get to the 
		cMemoryDC call, and we did a downcast on the pointer so that when we 
		are in the cMemoryDC::copyFromClipboard code we stay with cMemoryDC 
		methods. */
	pMemDC->cMemoryDC::copyFromClipboard();
	_allocate_mask_device(); /* Since you only did cMemoryDC code so far, you
		need to set your *_pMemDC_mask to the right size. */
	makeTransparent(); /* Now adjust the bitmaps. */
}

//------------------The Static Helper Function------------------------
void adjustStretch(int &source_cx, int &source_cy, int &target_left, int &target_top, int &target_cx,
		int &target_cy, int nFlags)
{
	double ratio_x, ratio_y;

	if (!source_cx)
		source_cx = 1;
	if (!source_cy)
		source_cy = 1;
	if (!target_cx)
		target_cx = 1;
	if (!target_cy)
		target_cy = 1;
	ratio_x = ((double)target_cx) / source_cx;
		 //cast to double or int division gives 0!
	ratio_y = ((double)target_cy) / source_cy;
	/* If no ST_*_ISO flags or on, or ST_NON_ISO is on, we leave
		the x and y the same.  */ 
	if ( !(nFlags & cMemoryDC::ST_NON_ISO) && (nFlags & cMemoryDC::ST_ISO_COVER_TARGET ||
		nFlags & cMemoryDC::ST_ISO_USE_WHOLE_SOURCE) )
	{ //If both BIG and SMALL are on, choose BIG.
		if (nFlags & cMemoryDC::ST_ISO_COVER_TARGET)
			ratio_x = ratio_y = max(ratio_x, ratio_y);
		else 
			ratio_x = ratio_y = min(ratio_x, ratio_y);
	}
	if (nFlags & cMemoryDC::ST_ISO_USE_WHOLE_SOURCE)
	{
		int actual_target_cx = target_cx;
		int actual_target_cy = target_cy;
		target_cx = (int)(ratio_x * source_cx);
		target_cy = (int)(ratio_y * source_cy);
		target_left = (int)((actual_target_cx - target_cx)/2.0);
		target_top = (int)((actual_target_cy - target_cy)/2.0);
	}
	if (nFlags & cMemoryDC::ST_ISO_COVER_TARGET)
	{
		source_cx = (int)(target_cx/ratio_x);
		source_cy = (int)(target_cy/ratio_y);
	}
}


void errorBox(char* box_caption, char* error_message)
{ /* To put up a message box.  If you happen to call this really early in your
program with AfxGetMainWnd() still NULL, the GetSafeHwnd will return a NULL,
and, as it turns out, the global MessageBox call actually works fine with a
NULL argument as its HWND, in this case it just has no owner window, which
actually doesn't matter. */
	::MessageBox(NULL, //AfxGetMainWnd()->GetSafeHwnd(),
		(LPSTR)error_message, //Text in window
		(LPSTR)box_caption, //Caption
		MB_OK | MB_ICONEXCLAMATION ); //Button flags
}


//---------DIB and Bitmap conversion code------------------
/*
This is shareware code which was taken from Larry Widing's bitmap.zip
file and given out to CS 146B at SJSU, October, 1996, by Rudy Rucker.
The bitmap.zip file was obtained from the "Shareware Code" page at
http://www.pfdpf.state.oh.us/msawczyn/files.  You could at that time also
also get to it from the Borland C++ home page.
Rucker took the pieces needed for loading and saving bitmaps and
put them into this file.
In December, 1997, Rucker ported the code to work with MFC
programs.  
---rucker@mathcs.sjsu.edu

Widing's Readme.doc includes these paragraphs:

If you have any questions on this code, suggestions for improvement, or
just to tell me you found it useful, you can contact me through my
CompuServe account number 70253,3461.

For further image processing information, I would suggest checking out
Martin Heller's Advanced Windows Programming book, which provided the
basis for my PCX and GIF file loading code.

As a final note, I have tried to make this code as problem free as
possible, but I make no guarantees.  Use at your own risk.

**	Modification History
**	--------------------
** 10/15/91     Larry Widing   Initial version for Win Tech Journal Article.
** 11/12/91     Larry Widing   Added defines for print menu options and
**                             conversion menu.
** 02/10/92     Larry Widing   Added hooks to alter the colormap.  Added HDIB
**                             typdef.  Added hooks for reading compressed RIX
**                             images.
 ----Larry Widing 
*/
#include	<malloc.h>
#include	<dos.h>
#include	<stdlib.h>
#include <stdio.h> //For unlink

#define HDIB HANDLE

//Larry Widing Helper functions
/*
** int							number of color entries in header
** DIBitmapColors(BITMAPINFO FAR *bmi);	pointer to bitmap header
**    This function returns the number of colors in the color table of
** the specified Device-Independent Bitmap.
** Modification History:
** 09/12/91  LCW  Created
*/
int
DIBitmapColors(BITMAPINFO FAR *bmi)
{
	/*
	**	Windows bitmap
	*/
	if (bmi->bmiHeader.biClrUsed == 0)
	{
		/* Maximum number of entries */
		switch (bmi->bmiHeader.biBitCount)
		{
			case 1:
				return 2;	/* Monochrome bitmap -> 2 colors */
			case 4:
				return 16;	/* 4-bit image -> 16 colors */
			case 8:
				return 256;	/* 8-bit image -> 256 colors */
			case 24:
				return 0;	/* 24-bt image -> 0 colors in color table */
		}
	}
	else
	{
		return (int)bmi->bmiHeader.biClrUsed;
	}
	return 0;
}

/*
** LPSTR						pointer to bitmap bits
** DIBitmapBits(BITMAPINFO FAR *bmi);	pointer to bitmap header
**    This function returns a pointer to the bits in a packed Device-
** Independent Bitmap.
** Modification History:
** 09/12/91  LCW  Created
*/
LPSTR
DIBitmapBits(BITMAPINFO FAR *bmi)
{
	LPSTR	bits;
	int	colors = DIBitmapColors(bmi);

	bits = ((LPSTR)bmi) + (unsigned int)bmi->bmiHeader.biSize;
	if (bmi->bmiHeader.biSize == sizeof(BITMAPCOREHEADER))
	{
		bits += colors * sizeof(RGBTRIPLE);
	}
	else
	{
		bits += colors * sizeof(RGBQUAD);
	}
	return bits;
}

HBITMAP
DibToBitmap(HDIB hbm)
{
	HBITMAP		bm = (HBITMAP)NULL;
	HDC			hdc;
	BITMAPINFO FAR	*bmi;
	LPSTR			bits;
	HWND			main_hwnd = AfxGetMainWnd()->m_hWnd;

	bmi = (BITMAPINFO FAR *)GlobalLock(hbm);
	if (bmi != NULL)
	{
		hdc = GetDC(main_hwnd);
		if (hdc != (HDC)NULL)
		{
			bits = DIBitmapBits(bmi);
			bm = CreateDIBitmap(hdc, (LPBITMAPINFOHEADER)bmi, CBM_INIT,
				bits, bmi, DIB_RGB_COLORS);
			ReleaseDC(main_hwnd, hdc);
		}
		GlobalUnlock(hbm);
	}
	return bm;
}

/*
** HDIB		handle of new packed DIB (NULL if an error occurred)
** BitmapToDIB(
**   HBITMAP hbm,	handle of logical bitmap to convert
**   int mode);	mode to use when converting
**    This function will convert a logical bitmap into a packed Device
** Independent Bitmap, using the mode parameter to determine if the resulting
** DIB should be run length encoded (mode == 1),or a unencoded DIB (mode == 0).
** Modification History:
** 09/07/91  LCW  Created
** 12/13/97  Rucker took out OS/2 mode
*/
HDIB
BitmapToDIB(HBITMAP hbm, int mode)
{
	int			i;
	HDC			hdc;
	HDIB			result = (HDIB)NULL;
	BITMAPINFO		*bmi;
	BITMAPCOREINFO	*bmci;
	LPSTR			ptr, sptr, dptr;
	int			hdrSize;
	int			bitsPerPixel;
	BITMAP			bm;
	HWND			main_hwnd = AfxGetMainWnd()->m_hWnd;

/*
**	Get bitmap information
*/
	GetObject(hbm, sizeof(bm), (LPSTR)&bm);
	if (bm.bmPlanes == 1)
		bitsPerPixel = bm.bmBitsPixel;
	else
		bitsPerPixel = bm.bmPlanes;
/*
**	Building a Windows compatible Bitmap
*/
		hdrSize = sizeof(BITMAPINFOHEADER);
		switch (bitsPerPixel)
		{
			case 1:
				hdrSize += 2 * sizeof(RGBQUAD);
				break;
			case 3:
				++bitsPerPixel;
			case 4:
				hdrSize += 16 * sizeof(RGBQUAD);
				break;
			case 8:
				hdrSize += 256 * sizeof(RGBQUAD);
				break;
		}
		bmi = (BITMAPINFO *)malloc(hdrSize);
		bmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmi->bmiHeader.biWidth = bm.bmWidth;
		bmi->bmiHeader.biHeight = bm.bmHeight;
		bmi->bmiHeader.biPlanes = 1;
		bmi->bmiHeader.biBitCount = bitsPerPixel;
		if (mode == 0 || (bitsPerPixel != 8 && bitsPerPixel != 4))
			bmi->bmiHeader.biCompression = BI_RGB;
		else if (bitsPerPixel == 8)
			bmi->bmiHeader.biCompression = BI_RLE8;
		else
			bmi->bmiHeader.biCompression = BI_RLE4;
		bmi->bmiHeader.biSizeImage = 0;
		bmi->bmiHeader.biXPelsPerMeter = 0;
		bmi->bmiHeader.biYPelsPerMeter = 0;
		bmi->bmiHeader.biClrUsed = 0;
		bmi->bmiHeader.biClrImportant = 0;
		bmci = NULL;
/*
**	Get a DC to use
*/
	hdc = GetDC(main_hwnd);
	if (hdc != (HDC)NULL)
	{
/*
**	Allocate storage needed
*/
		if (bmi == NULL)
		{
			DWORD	bitSize = (DWORD)bm.bmWidth * (DWORD)bitsPerPixel / 8;
			if ((bitSize & 3) != 0)
				bitSize += 4 - (bitSize & 3);
			result = GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT,
				(long)hdrSize + (DWORD)bm.bmHeight * bitSize);
			if (result != (HDIB)NULL)
			{
				ptr = (LPSTR)GlobalLock(result);
				if (ptr == NULL)
				{
					GlobalFree(result);
					result = (HDIB)NULL;
					errorBox("LARRYDIB.C module",
				"BitmapToDIB(): Unable to lock DIB memory");
				}
				else
				{
					sptr = (LPSTR)bmci;
				}
			}
		}
		else
		{
			if (GetDIBits(hdc, hbm, 0, bm.bmHeight, NULL,
				(LPBITMAPINFO)bmi, DIB_RGB_COLORS))
			{
				result = GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT,
					(long)hdrSize + bmi->bmiHeader.biSizeImage);
				if (result != (HDIB)NULL)
				{
					ptr = (LPSTR)GlobalLock(result);
					if (ptr == NULL)
					{
						GlobalFree(result);
						result = (HDIB)NULL;
						errorBox("LARRYDIB.C module",
					"BitmapToDIB(): Unable to lock DIB memory");
					}
					else
					{
						sptr = (LPSTR)bmi;
					}
				}
			}
		}
		if (result)
		{
/*
**	Copy header
*/
			dptr = ptr;
			for (i = 0 ; i < hdrSize ; ++i)
			{
				*dptr++ = *sptr++;
			}
/*
**	Get the bits
*/
			if (!GetDIBits(hdc, hbm, 0, bm.bmHeight, dptr,
				(LPBITMAPINFO)ptr, DIB_RGB_COLORS))
			{
				GlobalUnlock(result);
				GlobalFree(result);
				result = (HDIB)NULL;
			}
			else
			{
				GlobalUnlock(result);
			}
		}
		ReleaseDC(main_hwnd, hdc);
	}
	else
	{
		errorBox("LARRYDIB.C module",
			"BitmapToDIB(): Unable to get DC from main window");
	}
	if (bmi != NULL)
		free(bmi);
	if (bmci != NULL)
		free(bmci);
	return result;
}



//=======================CFile Versions

/*
** HDIB						handle of created DI bitmap
** ReadBitmapFile(const char *filename);	name of file to load
**    This function will read the passed file in, and create a device
** dependent bitmap, returning the handle to the created bitmap to the
** caller.
** Modification History:
** 09/06/91  LCW  Created
** 1/1/98 Rucker Changed
*/
HDIB
ReadDIBFile(CFile *pFile)
{
	int			rc;
	unsigned int		block;
	unsigned long	size;
	HDIB			hdata = (HDIB)NULL;
	char 			*pdata;
	char 			*ptr;
	BITMAPFILEHEADER	bfHdr;

/*
**	2. Read in BITMAPFILEHEADER and verify that this is a bitmap file
*/
		rc = pFile->Read((LPSTR)&bfHdr, sizeof(BITMAPFILEHEADER));
		if (rc == sizeof(BITMAPFILEHEADER)
			|| bfHdr.bfType == ('B' + ('M' << 8)))
		{
/*
**	2.1. Verify that the bfSize field is correct
*/
		{
			DWORD	_offset = DWORD(pFile->Seek(0L, 1));
			DWORD	_size = DWORD(pFile->Seek(0L, 2));
			pFile->Seek(_offset, 0);
			if (bfHdr.bfSize != _size)
				bfHdr.bfSize = _size;
		}
/*
**	3. Allocate storage for packed DIB
*/
			size = bfHdr.bfSize - sizeof(BITMAPFILEHEADER);
			hdata = GlobalAlloc(GMEM_MOVEABLE | GMEM_NODISCARD, size);
			if (hdata != (HDIB)NULL)
			{
				rc = -1;
				pdata = (char  *)GlobalLock(hdata);
				if (pdata != NULL)
				{
/*
**	4. Read in DIB header and bits into packed-DIB buffer
*/
					block = 16 * 1024;	/* size of chunks to read in */
					ptr = pdata;
					while (size > 0)
					{
						if (size < (unsigned long)block)
						{
							block = (unsigned int)size;
						}
						if (pFile->Read((LPSTR)ptr, block) != block)
						{
							errorBox("LARRYDIB.C module",
						"ReadBitmapFile(): Error reading BMP file");
							break;
						}
						size -= (long)block;
						ptr += block;
					}
					if (size == 0)
					{
						rc = 0;
					}
					GlobalUnlock(hdata);
				}
				else
				{
					errorBox("LARRYDIB.C module",
				"ReadBitmapFile(): Error locking packed DIB memory");
				}
				if (rc < 0)
				{
					GlobalFree(hdata);
					hdata = (HDIB)NULL;
				}
			}
			else
			{
				errorBox("LARRYDIB.C module",
			"ReadBitmapFile(): Unable to allocate memory for packed DIB");
			}
		}
		else
		{
			errorBox("LARRYDIB.C module",
			"ReadBitmapFile(): Error reading BITMAPFILEHEADER");
		}
	return hdata;
}

/*
** int
** WriteBitmapFile(
**	const char *filename,	name of file to load
**	const HDIB hbm);		handle to packed DIB
**    This function will write the passed packed Device Independent Bitmap
** to the specified file.
** Modification History:
** 09/06/91  LCW  Created
** 1/3/98 Rucker Changed
*/
int
WriteDIBitmapFile(CFile *pFile, HDIB hbm)
{
	int			rc = -1;
	unsigned int		block;
	unsigned long	size;
	char 			*ptr;
	BITMAPFILEHEADER	bfHdr;
	LPBITMAPINFO		bmi;

/*
**	1. Open output file already done
*/
/*
**	2. Lock memory resource
*/
		bmi = (LPBITMAPINFO)GlobalLock(hbm);
		if (bmi != NULL)
		{
/*
**	3. Create BITMAPFILEHEADER and write to file
*/
			bfHdr.bfType = ('B' + ('M' << 8));
			bfHdr.bfSize = sizeof(BITMAPFILEHEADER) + GlobalSize(hbm);
			bfHdr.bfReserved1 = 0;
			bfHdr.bfReserved2 = 0;
			bfHdr.bfOffBits = sizeof(BITMAPFILEHEADER)
				+ (DWORD)(DIBitmapBits(bmi) - (LPSTR)bmi);
			pFile->Write((LPSTR)&bfHdr, sizeof(bfHdr));
/*
**	4. Write out DIB header and packed bits to file
*/
				size = GlobalSize(hbm);
				ptr = (char  *)bmi;
				block = 16 * 1024;	/* size of chunks to write out */
				while (size > 0)
				{
					if (size < (unsigned long)block)
					{
						block = (unsigned int)size;
					}
				pFile->Write((LPSTR)ptr, block) ;

					size -= (long)block;
					ptr += block;
				}
				if (size == 0)
				{
					rc = 0;
				}
			GlobalUnlock(hbm);
		}
		else
		{
			errorBox("LARRYDIB.C module",
			"WriteBitmapFile(): Error locking bitmap into memory");
		}
	return rc;
}

//--------The interface functions----------


HBITMAP readBitmapFile(CFile *pFile)
{
	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT)); /* Because this
takes so long we turn on the hourglass while we do it */
	return DibToBitmap(ReadDIBFile(pFile));
}

int writeBitmapFile(CFile *pFile, HBITMAP hbm)
{
	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_WAIT)); /* Because this
takes so long we turn on the hourglass while we do it */
	return WriteDIBitmapFile(pFile, BitmapToDIB(hbm, 1));
}

