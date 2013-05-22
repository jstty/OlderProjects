#ifndef CMEMORYDC_H
#define CMEMORYDC_H

/* The cMemoryDC class is used to maintain a bitmap in memory.

===== cMemoryDC Usage ====
Some uses for cMemoryDC objects are:

* To keep a copy of a CView window to use in restoring the window.
* To use as hidden scratch paper for assembling an image to then BitBlt to
the screen. This is done either when drawing temporary objects or during 
animation.
* To use for small bitmaps to represent movable objects such as game characters.

Here are the steps to use a cMemoryDC to maintain a CView window's image.  
Suppose that your application is called My, and you have CMyView class that is a 
child of CView.

(1)	Declaration.
	(SDI case) Add a protected member to your CMyView like this:
		cMemoryDC *_pMemDC;
	Another option is to have a class member rather than a pointer member.  
		cMemoryDC _memDC(CMEMDC_FULLSCREEN, backgroundcolor);
	or
		cMemoryDC _memDC(CMEMDC_FULLSCREEN);
	Note that the constructor with no arguments makes a cMemoryDC that is only one
pixel in size.  This is used for small bitmaps, being resized as the bitmaps 
are loaded.
		cMemoryDC _memDC;
	As a rule it seems better to use the pointer becuase it's a lighter object to
pass around, because it allows the possiblity of standing for an enahanced child
class object.  When using a pointer object you need to remember to do a delete 
on it in the destructor.
	(MDI single bitmap case ) If you are doing an MDI program, AND you want all 
your views to be of the same bitmap, then put a public
		cMemoryDC *_pMemDC;
into CMyDoc class instead.  You can access it in the CMyView code as
		GetDocument()->_pMemDC. 
	(Multiple bitmap cases)  If you are doing an animation or a paint
program you will often want two cMemoryDC bitmaps, one for the more
permanent images and one for use as a scratch pad to assemble temporary
images.  A good name for the pointer to the second one is _pMemDC_temp.

(2)	Construction and initialization.		
	(SDI case) Add a message handler for WM_CREATE and in the 
CMyView::OnCreate, put:
		_pMemDC = new cMemoryDC(CMEMDC_FULLSCREEN, backgroundcolor);
	backgroundcolor can be omitted if you want it to be WHITE, otherwise you 
need to feed it in.
	The cMemoryDC constructor with the CMEMDC_FULLSCREEN argument makes the 
cMemoryDC hold a blank bitmap as large as a fullscreen window and sets 
its _resize_on_load flag to FALSE, i.e. loading a bitmap into the cMemoryDC 
stretches the bitmap rather than resizing the cMemoryDC.
	Since the constructor only uses information abou the hardware, you can
also simply invoke it by having a cMemoryDC member of the CView like this.
	cMemoryDC _memDC(CMEMDC_FULLSCREEN, backgroundcolor);
	(MDI case) If you expect the image to look the same in each view and are
concerned about using up memory, you can put this into the CMyDoc constructor:
		_pMemDC = new cMemoryDC(CMEMDC_FULLSCREEN);
	But it is more typical that the view images will look different, in which
case you have a cMemoryDC for each CView.

(3)	Use in OnDraw.
	In your CMyView::OnDraw(CDC *pDC), do something
like this:
		if (!pDC->IsPrinting())
		{
			//Put code here to draw your image into the _pMemDC
			_pMemDC->copyTo(pDC);
		}
		else //The Print or Print Preview case
			//Put code here to draw your image directly to the pDC
		
	Another approach to dealing wiht the Print cases is to stretch your _pMemDC
to the large print CDC.  This produces poor print images, but is an easy 
approach for situations in which you do not maintain scalable "display list" 
information about your image.
		CRect rect;
		pDC->GetClipBox(&rect);
		if (!pDC->IsPrinting())
			_pMemDC->copyTo(pDC, &rect);
		else 
			_pMemDC->stretchTo(pDC, &rect, ST_ISO_USE_WHOLE_SOURCE);
	You also have the option of doing the following in the non-printing case,
should you want to squeeze the whole image into the window:
		_pMemDC->stretchTo(pDC, &rect, ST_NON_ISO)
	In the case, when _pMemDC is not a member of CMyView, you
start the OnDraw code with a line like:
		cMemoryDC *_pMemDC = GetDocument()->_pMemDC
	(animation case) If you are doing an animation, you will want
to assemble your image by GDI calls to before the copyTo or stretchTo in
CMyView::OnDraw.  You might have calls like, for instance,
pMemDC->Ellipse(...) or pMemDC->BitBlt(...) to put things into pMemDC.
	It is also possible, if you are doing an MDI animation and using
a view/document architecture anyway, that the preparation of the pMemDC
is handled by, say, a CMyDoc::update method.
	(paint case) If you are doing a paint program, you will have put things
into the pMemDC in the mouse handling messages, so you probably don't need to do
any preparation of pMemDC here.  It may be that depending on whether
you are showing a temporary or a permanent change to the image you want to use _pMemDC or _pMemDC_temp.  A convenient way to deal with this is to put an int _nVisibleMemDC flag into CMyDoc and give CMyDoc a cMemoryDC * getVisibleMemDC() method which will return _pMemDC or _pMemDC_temp according to the state in which your other code has put the _nVisibleMemDC flag.  And then you start the OnDraw
code with 
		cMemoryDC *_pMemDC = GetDocument()->getVisibleMemDC();

(4)	Destruction.
	(_pmemDC a member of CMyView) In your CMyView destructor, put
		delete pMemDC; 
	(_pmemDC a member of CMyDoc)  In your CMyDoc destructor, put
		delete pMemDC;

(5)	To clear the window from within any CMyView method, (i.e. to fill it with 
the cMemoryDC backgroundcolor), put:
		pMemDC->clear();
		Invalidate(FALSE); //FALSE means don't have to erase the background.

(6)	Use the standard Windows API GUI calls to write graphics to your cMemoryDC.
	Whenever you want to make a persistent mark in your CView window, make
the mark in *_pMemDC, and then call Invalidate.  For instance:
		_pMemDC->Rectangle(l, t, r, b);
		Invalidate(FALSE);
	In the case where you are using the same _pMemDC across all your views of your
document, you might do something like this.
		GetDocument()->_pMemDC->Rectangle(l, t, r, b);
		GetDocument()->UpdateAllViews;
	The UpdateAllViews function calls each of the CMyView::OnUpdate function.  You 
should override this function to have exactly these two lines:
		Invalidate(FALSE); //Don't bother erasing
		UpdateWindow(); //Call OnDraw to show the change right away.
	A third kind of approach is to store your graphic information as a display
list, and have a sequence like this
		//add geometry to display list
		GetDocument()->UpdateAllViews;
	And then in the CMyView::OnUpdate function do
		//draw the display list geometry into the pMemDC
		Invalidate(FALSE); //Don't bother erasing
		UpdateWindow(); //Call OnDraw to show the change right away.
	A variation on this approach is to put the code for drawing the display list
geometry to _pMemDC inside the OnDraw function.

(7)	The cMemoryDC class can also be used for Copy, Cut and Paste.
Use the copyFrom(CDC *pDC, CRect &rect) method to get an image into the
cMemoryDC and use pasteTo(CDC *pDC, CPoint &point) to put it back out.
	Note that pasteTo takes a CPoint and not a CRect as its second
argument; this is because pasteTo pastes ALL of the cMemoryDC image with
its upper left hand corner at the target point.

(8)	You can load a resource bitmap from an resource string name or from
 a resource_ID number.  Here is an example of how you might do this.  Note
that the default no-argument cMemoryDC constructor gives the cMemoryDC
a nominal bitmap of size 1x1 and sets its _resize_on_load flag to TRUE,
meaning that when I load a bitmap into this cMemoryDC, the cMemoryDC
will resize itself to match the bitmap.
		cMemoryDC *_pMemDC_stamp;
		_pMemDC_stamp = new cMemoryDC();
		_pMemDC_stamp->loadResourceBitmap(IDB_STAMP);

(9)	You can load and save in the *.BMP format with a LPSTR file name or 
with a CFile* file object.  This method is not fully perfected, and will
occasionally fail to work when the number of colors in the *.BMP is not
compatible with the number of colors being used by the display device.
	When loading a bitmap from a resource or from a *.BMP file, the
_resize_on_load field is important.  If _resize_on_load is TRUE, your
cMemoryDC _bitmap is resized to match the size of the bitmap being loaded.
If _resize_on_load is FALSE then the source bitmap is stretched to cover
your caller cMemoryDC _bitmap.  Remember that the default value for
_resize_on_load is FALSE for the CMEMDC_FULLSCREEN-constructed objects
and is TRUE for the default-constructed objects.

(10)	Further loading and saving options are the 
 Serialize method that could be used in a MDI paint program like this:
		void CMyDoc::Serialize(CArchive& ar)
		{
			_pMemDC->Serialize(ar);
		}

(11) We have two clipboard methods: copyToClipboard, and copyFromClipboard.
	void copyToClipboard(const CRect &rect_select) makes an HBITMAP copy of the
rectangle in question and puts it on the clipboard.
	void copyFromClipboard() does nothing if there's no HBITMAP on the 
clipboard. Otherwise it frees up the calling cMemoryDC's memory and resizes it to
match the size of the clipboard, then making a copy of the clipboard's HBITMAP 
image.

(12) The cTransparentMemoryDC class is for showing images with a
"transparent" background.
	(A) images for moving game or simulation characters,
	(B) for cutting and pasting non rectangular images,
	(C) a foreground "scrim" behind which your characters move.  Thus 
you might have a cMemoryDC background, cTransparentMemoryDC icons moving on top 
of that, and cTransparentMemoryDC scrim on top of everything.

(12A) A typical use of (A) might be to have this in a constructor
		cTransparentMemoryDC _pDC_charicon;
	And this kind of call in the code.
		_pDC_charicon->loadResourceBitmap(IDB_CHARACTER);
	And then put it on the screen with a call like
		_pDC_charicon->centeredPasteTo(...);
(12B) An example of (B) might be this in the document constructor
		cTransparentMemoryDC _pDC_clipboard;
	Something like this in the View OnEditPaste,
		_pDC_clipboard->copyFromClipboard();
	followed by, in OnLButtonDown, for instance, a call to:
		_pDC_clipboard->centeredPasteTo(...);
(12C) An example of (C) might be this in a constructor
		cMemoryDC _pDC_scrim(CMEMDC_FULLSCREEN);
		_pDC_scrim->loadFileBitmap("Scrim.BMP");
	And something like this in the View OnDraw Method
		_pMemDC_background->copyTo(cMemDC_temp);
		_pMemDC_charicon->pasteTo(cMemDC_temp);
		_pMemDC_scrim->copyTo(cMemDC_temp);
		cMemDC_temp->copyTo(pMemDC); //to the screen.
	
(13) To be good citizens we added copy constructors and overloaded = operators,
supported by private _copy functions.  The only use of these in any of our 
other methods is in the cTransparentMemoryDC::saveFileBitmap functions, where we
use a cTransparentMemoryDC(cMemoryDC) constructor to make a downcast so as to
call the cMemoryDC::saveFileBitmap. 
*/

/* The meaning of these flags is explained below.  The are used in the last 
argument to cMemoryDC::stretchTo and in the adjustStretch helper function. */

class cTransparentMemoryDC; /* This "forward" declaration is needed so
	cMemoryDC knows there will be such a class, so that it's _copy
	function and copy constructor know it's OK to have a
	cTransparentMemoryDC type as an argument. */

class cMemoryDC : public CDC
{
public:
	static const int ST_NON_ISO;
	static const int ST_ISO_COVER_TARGET;
	static const int ST_ISO_USE_WHOLE_SOURCE;

/* This flag is used for a constructor call to get a screen-sized cMemoryDC */
	static const int CMEMDC_ONEPIXEL;
	static const int CMEMDC_FULLSCREEN;

DECLARE_SERIAL(cMemoryDC);
protected:
	CBitmap _cBitmap;
	COLORREF _blankcolor;
	int _cx, _cy;
	BOOL _resize_on_load;
		/* _resize_on_load says whether or not change _cx and _cy to match 
the dimensions of the file bitmap you are loading.  If FALSE we StretchBlt the
loaded bitmap to fit our current size, if TRUE, we change our current size.  This 
applies both to loadFileBitmap and to loadResourceBitmap. */
	virtual void _allocate();
	virtual void _free();
	virtual void _copy(const cMemoryDC &memDC); // Used by copy constructor and by =
	virtual void _copy(const cTransparentMemoryDC &memDC); // Used by copy constructor and by =
public:
//Constructors and destructor
	cMemoryDC();
	cMemoryDC(int enumSize, COLORREF blankcol = RGB(255, 255, 255)); 
		/* enumSize is either CMEMDC_ONEPIXEL or CMEMDC_FULLSCREEN */
	cMemoryDC(const cMemoryDC &memDC);
		/* I'm not using this constructor, but it seems like the
		Right Thing To Do to have it.  Any class which does memory
		allocation in its constructors should have a copy constructor,
		as a term by term copy would not be appropriate; an HBITMAP
		might still be used in one copy when already Deleted by another
		copy's destructor, for instance. */
	cMemoryDC(const cTransparentMemoryDC &memDC);
	virtual ~cMemoryDC(); /* The destructor is declared to be virtual
		because cMemoryDC has a child class cTransparentMemoryDC,
		and the child's destructor is different. The methods that differ
		between parent and child are also declared virtual.  */
//Accessors
	int cx(){return _cx;}
	int cy(){return _cy;}
	CSize getSize(){return CSize(_cx, _cy);}
	BOOL resize_on_load(){return _resize_on_load;}
//Mutators
	void clear();
	virtual void clear(const CRect &rect);
	void setBlankColor(COLORREF blankcol);
	void set_resize_on_load(BOOL newval) {_resize_on_load = newval;}
	virtual void setHBITMAP(HBITMAP hbitmap_new); /* This sets the HBITMAP field of
		_cBitmap to hbitmap_new */
	virtual void setSize(int cx, int cy); /* Since this calls the virtual _free
		and _allocate to resize the bitmap or bitmaps, I initially thought it
		doesn't have to be virtual.  But if it isn't virtual, when a
		cTransparentMemoryDC calls setSize, the caller is downcast and uses
		the cMemoryDC _free and _allocate.*/
//Blt Methods
	void copyTo(CDC *pDC); /* This doesn't need to be
		virtual because it just calls the virtual copyTo, for either class */
	virtual void copyTo(CDC *pDC, const CRect &rect);
	virtual void stretchTo(CDC *pDC, const CRect &targetrect, const CRect &sourcerect);
		/* Uses ST_NON_ISO flag behavior, it's up to you to give the rects the same aspect.
		This method is virtual and has an internal switch on pDC->GetRuntimeClass as well, 
		so it actually has four possible behaviors depending on whether the source and target
		are cMemoryDC or cTransparentMemoryDC.*/
	void stretchTo(CDC *pDC, const CRect &targetrect, int nFlags = ST_NON_ISO);
		 //See comment below on ST_? flags. Calls the vitual stretchTo above.
	void stretchTo(cMemoryDC *pDC); /* Calls the virtual 
		stretchTo(CDC *pDC, const CRect &targetrect, const CRect &sourcerect) */
	virtual void copyFrom(CDC *pDC, const CRect &rect);
	virtual void pasteTo(CDC *pDC, const CPoint &corner);
	void centeredPasteTo(CDC *pDC, const CPoint &center); /* This calls pasteTo,
		so it doesn't have to be virtual itself. */
//Clipboard Methods
	virtual void copyToClipboard(const CRect &rect_select);
	virtual void copyFromClipboard();
//File Methods
	virtual void loadResourceBitmap(char * resource_name);
	virtual void loadResourceBitmap(int resource_ID);
	virtual void loadFileBitmap(LPSTR file_bitmap_name); //Affected by _resize_on_load
	virtual void loadFileBitmap(CFile *pFile);
	virtual void saveFileBitmap(LPSTR file_bitmap_name);
	virtual void saveFileBitmap(CFile *pFile);
	void Serialize(CArchive& ar); //Calls the virtual saveFileBitmap or loadFileBitmap.
//Operators
	cMemoryDC& operator=(const cMemoryDC &memDC);
		/* I'm not using this yet, but like the copy constructor its
		a good thing to have around. */
	cMemoryDC& operator=(const cTransparentMemoryDC &memDC);
};

class cTransparentMemoryDC : public cMemoryDC
{
DECLARE_SERIAL(cTransparentMemoryDC);
protected:
	cMemoryDC *_pMemDC_mask;
	BOOL _transparent_color_equals_corner_color;
	virtual void _allocate();
	virtual void _allocate_mask_device();
	virtual void _free();
	virtual void _free_mask_device();
	virtual void _copy(const cMemoryDC &memDC); // Used by copy constructor and by =
	virtual void _copy(const cTransparentMemoryDC &memDC); // Used by copy constructor and by =
	friend cMemoryDC; //for cMemoryDC::_copy(cTransparentMemoryDC&)
public:
//Constructors and destructor
	cTransparentMemoryDC();
	cTransparentMemoryDC(int enumSize, COLORREF blankcol = RGB(255, 255, 255)); 
		/* enumSize is either CMEMDC_ONEPIXEL or CMEMDC_FULLSCREEN.  But in fact the
		enumSize is ignored and a one-pixel bitmap is created.  We make two bitmaps, 
		and use transparent as the blankcol called by Clear() */
	cTransparentMemoryDC(const cMemoryDC &memDC);
	cTransparentMemoryDC(const cTransparentMemoryDC &memDC);
	virtual ~cTransparentMemoryDC(); /* Call this virtual to match
		the "virtual" on the parent classes destructor.  We put virtual
		in front of the methods which are virtual in the parent as well.
		Strictly speaking you don't need to use the "virtual" declaration
		in the child class, it only has an effect in when used in the
		parent class, but it's good practice to match the declarations. */
	virtual void setSize(int cx, int cy);
//Accessors are the same, plus this one new Accessor.
	COLORREF transparentcolor(){return _blankcolor;}
	/* All the Methods need to be changed, and setTransparentColorEqualsCornerColor
		is new.  Note that Clear will fill *only* the _hdc with the
		_blankcolor color; to then make the bitmap truly transparent you
		would need to call makeTransparent(). */
//Mutators
	virtual void setHBITMAP(HBITMAP hbitmap_new); /* This sets the HBITMAP field of
		_cBitmap to hbitmap_new and resizes *_pMemDC_mask to match. */
	void setTransparentColorEqualsCornerColor(BOOL onoff)
		{_transparent_color_equals_corner_color = onoff;}
	//Blt Methods
	virtual void clear(const CRect &rect);
	virtual void copyTo(CDC *pDC, const CRect &rect);
	virtual void stretchTo(CDC *pDC, const CRect &targetrect, const CRect &sourcerect);
		/* Uses ST_NON_ISO flag behavior, it's up to you to give the rects the same aspect.
		This method is virtual and has an internal switch on pDC->GetRuntimeClass as well, 
		so it actually has four possible behaviors depending on whether the source and target
		are cMemoryDC or cTransparentMemoryDC.*/
	virtual void copyFrom(CDC *pDC, const CRect &rect);
	virtual void pasteTo(CDC *pDC, const CPoint &point);
	void makeTransparent(); /* Function used to convert a cMemoryDC style
		_hdc into a cTransparentMemoryDC pair of _hdc and _hdc_mask.
		Mostly this is used privately in the implementation of the methods,
		but you might want to call it if you'd drawn something in _hdc
		by calling clear and then doing GDI calls. */
//Clipboard Methods
	virtual void copyToClipboard(const CRect &rect_select);
	virtual void copyFromClipboard();
//File Methods
	virtual void loadResourceBitmap(char * resource_name);
	virtual void loadResourceBitmap(int resource_ID);
	virtual void loadFileBitmap(LPSTR file_bitmap_name); //Affected by _resize_on_load
	virtual void loadFileBitmap(CFile *pFile);
	virtual void saveFileBitmap(LPSTR file_bitmap_name);
	virtual void saveFileBitmap(CFile *pFile);
//Operators
	cTransparentMemoryDC& operator=(const cMemoryDC &memDC);
	cTransparentMemoryDC& operator=(const cTransparentMemoryDC &memDC);
};

//--------------GLOBAL Helper Functions defined here-------------

/*	The ST flags are used in the last argument of stretchTo and are passed
to the adjustStretch helper functions.
	ST_NON_ISO means exactly cover the target rect, even if this means anisotropic stretching.
	ST_ISO_COVER_TARGET and ST_ISO_USE_WHOLE_SOURCE are isotropic stretches.
In ST_ISO_COVER_TARGET we  make sure the stretch covers the entire target area, but
we may not use all of the source.
In ST_ISO_USE_WHOLE_SOURCE we make sure the stretch fits the entire source area 
into the target area, but we may not cover all of the target area.
	Logically, ST_NON_ISO, ST_ISO_COVER_TARGET, and ST_ISO_USE_WHOLE_SOURCE 
are mutually exclusive, but if you happen to turn on more than one of them, the
priority is in the order they are listed.  And if you turn on none of them,
the default assumption is ST_NON_ISO.
	Note that by itself, the default stretchTo
ST_NON_ISO flag does the most obvious thing: it stretches the source exactly
to the target.  If you use  ST_ISO_USE_WHOLE_SOURCE 
 you need to resize your target window to make sure it is all covered.
	The adjustStretch helper function is used in cMemoryDC::stretchTo.
There's no particular reason to make this function a member of cMemoryDC,
so we make it a global function in case we might want to use it somewhere
else sometime. */

void adjustStretch(int &source_cx, int &source_cy, int &target_left,
		int &target_top, int &target_cx, int &target_cy, int _nFlags);

// The errorBox function makes it easier to call the MessageBox function.
void errorBox(char* box_caption, char* error_message);

//These are functions used to load and save bitmap files; they translate between
//the DIB format and the HBITMAP format.
HBITMAP readBitmapFile(CFile *pFile);
int writeBitmapFile(CFile *pFile, HBITMAP hbm);

#endif //CMEMORYDC_H
