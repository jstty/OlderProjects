/////////////////////////////////////////////////////////////////////////////
//
// texture.cpp : implementation of the cTexture class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <math.h>

#include "texture.h"
#include "memorydc.h"
#include "resource.h"
#include "quakeMD2model.h"

//BEGIN IMPORTANT SWITCHES========================

const BOOL cTexture::USEMIPMAP = TRUE; /*
		The USEMIPMAP switch happens to be implemented as a cTexture static vairable
	instead of as a #define, like most of our switches.
		If I set USEMIPMAP = TRUE, then a texture will actually store a variety of
	textures of different resolution, and pick the best one according to the size of
	the target onscreen pixel swatch.
		One might expect USEMIPMAP = TRUE to make the textures run a bit faster or look a
	bit nicer, but I haven't seen any real difference in the limited number of tests I've
	done.
		You might want to have USEMIPMAP = FALSE, simply because if you don't
	use mipmaps, then the RAM size of your texture objects will be less.  But if you use
	a lot of textures, do test the TRUE option.
		Do note that USEMIPMAP = FALSE requires that the resource bitmaps fed into the
	texture-maker have both	dimensions be exact powers of two. We have some code to 
	handle the case where you disobey the powers-of-two-edged source bitmap injuction
	(see comment on GLUSCALERESOURCEEINFO below), but	you really SHOULD always use
	powers-of-two-edged source bitmaps. */
const BOOL cTexture::MAXEDGESIZE = 1024; /* MAXEDGESIZE should be a power of two. You need
	to increase MAXEDGESIZE here if you plan to use a bigger kind of soruce bitmap. */

#define GLUSCALETEXTUREINFO
	/*  GLUSCALERESOURCEEINFO activates the use of the 
OpenGL ::gluScaleImage method in the cTexture(cTextureInfo *pinfo) constructor.
	I thought we needed this becausein order to use a texture in OpenGL,
it should be based on a bitmap to have both edges be powers of two. Actually,
it's not that important because when you use gluBuild2DMipmaps, this 
method will in fact fix the size if it has to.
	But it works ok and doesn't to any harm in case we ever switch off 
mipmaps.
	For the resource-based bitmaps in the
cTexture::cTexture(int resourceID, BOOL transparent) constructor, we simply
use the the MFC CDC::StretchBlt method, which works
fine (provided I set the StretchBltMode).
*/

//END IMPORTANT SWITCHES========================

//TEST SWITCHES and an OBSOLETE SWITCH
#define ALLOWALPHATRANSPARENCY //TEST PURPOSES ONLY
	/* If we comment in ALLOWALPHATRANSPARENCY then a cSpriteIcon can be drawn with its
background transparent by using alpha blending.  If we comment out ALLOWALPHATRANSPARENCY,
the sprite icon are drawn with a solid background, that looks a bit clunky. The switch takes
place inside the cTexture constructor code. The purpose of the ALLOWALPHATRANSPARENCY is to
see if using this effect slows the program down much.  The fact seems to be using the
transparency has no substantial speed penalty.  The program will run slow whenever you
have a visually large cSpriteIcon in 3D, whether or not you are using the transparency
effect.  You need to not let the user get too close to a cSpriteIcon
critter, so that you aren't doing a texture map onto a very large number of screen 
pixels. Concievably you can partly alleviate the slowness of large texture areas by
by basing the texture on a large bitmap and making cTexture::USEMIPMAP be TRUE.  */

//#define GLUSCALERESOURCEEINFO  //OBSOLETE
	/*  In order to use a texture based on a resource bitmap, I have to 
stretch the bitmap to have both edges be powers of two.
	The RIGHT thing to do is simply to prepare the bitmaps yourself in Photoshop so that you
always only use resource bitmaps whose edges are powers of two!!!!!! 
	 If I use a non-powers-of-two-edged source bitmap, then either I can stretch 
it with a cMemoryDC::stretchTo call, which uses  or I can use the OpenGL ::gluScaleImage method
which is what GLUSCALERESOURCEEINFO activates.
	Although in principle it would seem I could ::gluScaleImage for resizing an image,
in the context of the Pop code below, the ::gluScaleImage call seemed to crash sometimes
in the cTexture constructor for certain sizes of input bitmaps.
	So I don't use GLUSCALERESOURCEEINFO. The code is here only out of archival interest.
*/


//Other static
const double cTexture::LOG2 = log(2.0); 

void cTexture::makePowersOfTwo(int &cx, int &cy)
{
	/* We want to disallow the possiblity of a texture with an edge greater than cTexture::MAXEDGESIZE.
		So to start with we shrink the cx and cy down to be less than this size. */
	double clampcx = cx;
	double clampcy = cy;
	while( clampcx > cTexture::MAXEDGESIZE || clampcy > cTexture::MAXEDGESIZE)
	{
		clampcx /= 2.0;
		clampcy /= 2.0;
	} 
	ASSERT(clampcx >= 1.0 && clampcy >= 1.0); //Otherwise you've clamped a long line too far.
	double logcx = log(clampcx) / cTexture::LOG2; //This gives the log base 2.
	double logcy = log(clampcy) / cTexture::LOG2;
	double targetaspect = (double)cx/(double)cy;
		/* We consider rounding the log base 2 both down or up to the nearest integer. */
	double newcxlo = __min(cTexture::MAXEDGESIZE, pow(2.0, floor(logcx)));
	double newcxhi = __min(cTexture::MAXEDGESIZE, pow(2.0, ceil(logcx)));
	double newcylo = __min(cTexture::MAXEDGESIZE, pow(2.0, floor(logcy)));
	double newcyhi = __min(cTexture::MAXEDGESIZE, pow(2.0, ceil(logcy)));
	double testaspect[4]; /* I want to get the best match for the targetaspect, so I will
		try all four possibile combinations of lo and hi for x and y. */
	testaspect[0] = newcxlo/newcylo;
	testaspect[1] = newcxlo/newcyhi;
	testaspect[2] = newcxhi/newcylo;
	testaspect[3] = newcxhi/newcyhi;
	int bestaspectindex = 3; //All in all, I would prefer to stretch.
	double bestaspecterror = fabs(testaspect[3]-targetaspect);
	for (int i=2; i>=0; i--)
		if (fabs(testaspect[i]-targetaspect) < bestaspecterror)
		{
			bestaspectindex = i;
			bestaspecterror = fabs(testaspect[i]-targetaspect);
		}
	switch(bestaspectindex)
	{
		case 0:
			cx = (int)newcxlo;
			cy = (int)newcylo;
			break;
		case 1:
			cx = (int)newcxlo;
			cy = (int)newcyhi;
			break;
		case 2:
			cx = (int)newcxhi;
			cy = (int)newcylo;
			break;
		case 3:
			cx = (int)newcxhi;
			cy = (int)newcyhi;
			break;
	}
	ASSERT(cx);
	ASSERT(cy);
}		

// cTexture construction/destruction////////////////////////////////////////////////////

cTexture::cTexture(int resourceID, BOOL transparent):
	_transparent(transparent)
{
	GLubyte *pdata = NULL;
	GLubyte *pdatascaled = NULL;
#ifndef ALLOWALPHATRANSPARENCY
	_transparent = FALSE;
#endif //ALLOWALPHATRANSPARENCY
	int bytesperpixel;
	if (_transparent)
	{
		bytesperpixel = 4;
		_pixeldataformat = GL_RGBA;
	}
	else
	{
		bytesperpixel = 3;
		_pixeldataformat = GL_RGB;
	}
	_usemipmap = cTexture::USEMIPMAP;
	cMemoryDC *pDC = new cMemoryDC();

   // Added Load from file by: Joseph E. Sutton
   CFile cFile;
   if(!cFile.Open((char *)resourceID, CFile::modeRead | CFile::shareDenyWrite))
	{
		pDC->loadResourceBitmap(resourceID);
	}
   else
   {
      pDC->loadFileBitmap(&cFile);
      cFile.Close();
   }

	int imagecx = pDC->cx();
	int imagecy = pDC->cy();
	_cx = imagecx;
	_cy = imagecy;
	_imageaspect = (double)_cx / (double)_cy; /* By default we set the aspect to match the aspect
		of the  image we loaded, before doing the makePowersOfTwo call. Even though we are going
		to clamp the texture to powers of two, if we apply it to a rectangle with proportions
		matching _imageaspect, the image will appear unstretched; the two stretches cancel out. */
	makePowersOfTwo(_cx, _cy);
	if (_cx == imagecx && _cy == imagecy) //Don't need to rescale
	{
		pdata = _readDC(pDC); //Uses the _transparent flag to decide how to read.
		delete pDC;
		_maketexture(pdata);
		delete pdata; 
		return;
	}
	//Else you have to scale the bitmap data to match (_cx, _cy).	
#ifndef GLUSCALERESOURCEEINFO //Don't use flaky gluScale, use reliable StretchBlt
	cMemoryDC *pDCpoweroftwo = new cMemoryDC();
	pDCpoweroftwo->setSize(_cx, _cy);
	pDCpoweroftwo->SetStretchBltMode(COLORONCOLOR); /* We can control a StretchBlt by setting
		the mode of the TARGET CDC.  COLORONCOLOR gives a nicer effect than the default. */
//	pDCpoweroftwo->SetStretchBltMode(HALFTONE);
		 //HALFTONE is an alternate stretchblt mode, but it makes ugly dither marks.
//	::SetBrushOrgEx(pDCpoweroftwo->GetSafeHdc(), 0, 0, NULL);
		 //You're supposed to call SetBrushOrgEx after setting stretch blt mode to HALFTONE.
	pDC->stretchTo(pDCpoweroftwo);
	delete pDC;
	pdatascaled = _readDC(pDCpoweroftwo);
	delete pDCpoweroftwo;
	_maketexture(pdatascaled);
	delete pdatascaled;
	return;
#else //GLUSCALERESOURCEEINFO //Use flaky gluScale which crashes or does nothing.
	pdata = _readDC(pDC); //Uses the _transparent flag to decide how to read.
	delete pDC;
	unsigned long arraysize = 3 * (unsigned long)_cx * (unsigned long)_cy;
	pdatascaled = new GLubyte[arraysize];
	ASSERT(pdatascaled);
	::glPixelStorei(GL_UNPACK_ALIGNMENT, 1); //We're not padding at ends of lines when we write textures.
	::glPixelStorei(GL_PACK_ALIGNMENT, 1); //We're not padding at ends of lines when we read textures.
	::gluScaleImage(_pixeldataformat, //data format
		imagecx, imagecy, GL_UNSIGNED_BYTE, pdata, //settings of source image
		_cx, _cy, GL_UNSIGNED_BYTE, pdatascaled); //settings of target image
	delete pdata; //I tend to get a crash here when the bitmap sizes don't match.
	_maketexture(pdatascaled); //This seems to crash sometimes.
	delete pdatascaled;
	return;
#endif //GLUSCALERESOURCEEINFO
}

cTexture::cTexture(cTextureInfo *ptextureinfo):
_transparent(FALSE),
_usemipmap(TRUE)
{
	unsigned long bytesperpixel = 3;

	if (ptextureinfo->textureType == BMP)
		_pixeldataformat = GL_RGB;
	else if(ptextureinfo->textureType == PCX)
	{
		_pixeldataformat = GL_RGBA;
		bytesperpixel = 4;
	}
	else //Unknown file type
		return;
	int imagecx = _cx = ptextureinfo->_width;
	int imagecy = _cy = ptextureinfo->_height;
	_imageaspect = (double) _cx / (double) _cy;/* By default we set the aspect to match the aspect
		of the  image we loaded, before doing the makePowersOfTwo call. Even though we are going
		to clamp the texture to powers of two, if we apply it to a rectangle with proportions
		matching _imageaspect, the image will appear unstretched; the two stretches cancel out. */

#ifdef GLUSCALETEXTUREINFO
	makePowersOfTwo(_cx, _cy); 
	if (_cx != imagecx || _cy != imagecy) //Need to rescale
	{
		unsigned long arraysize =
			 bytesperpixel * (unsigned long)_cx * (unsigned long)_cy;
		unsigned char * pdatascaled = new unsigned char[arraysize];
		ASSERT(pdatascaled);
		::glPixelStorei(GL_UNPACK_ALIGNMENT, 1); //We're not padding at ends of lines when we write textures.
		::glPixelStorei(GL_PACK_ALIGNMENT, 1); //We're not padding at ends of lines when we read textures.
		::gluScaleImage(_pixeldataformat, //data format
			imagecx, imagecy, GL_UNSIGNED_BYTE, ptextureinfo->pdata(),
				//settings of source image
			_cx, _cy, GL_UNSIGNED_BYTE, pdatascaled);
				//settings of target image
		const GLubyte* errorstring = gluErrorString(glGetError());
		ptextureinfo->resetData(_cx, _cy, pdatascaled);
	}		
#endif //GLUSCALETEXTUREINFO

	_maketexture(ptextureinfo->pdata());
}

cTexture::~cTexture()
{
	::glDeleteTextures(1, &_textureID);
}

//cTexture helper methods----------------------------------------------

GLubyte* cTexture::_readDC(cMemoryDC *pMemDC)
{
	GLubyte *pdata = NULL;
	ASSERT(pMemDC);
	int cx = pMemDC->cx();
	int cy = pMemDC->cy();
	ASSERT(cx>1 && cy>1); //If not, this means something's wrong.
	unsigned long index = 0;
	COLORREF colorref;
	if (!_transparent)
	{
		unsigned long arraysize = 3 * (unsigned long)cx * (unsigned long)cy;
		pdata = new GLubyte[arraysize];
		ASSERT(pdata);
		/* We step the y values in the reverse order because OpenGL counts y pixels from bottom to
			top unlike Windows CDCs, which count from top to bottom. */
		for (int j=cy-1; j>=0; j--)
			for (int i=0; i<cx; i++)
			{
				colorref = pMemDC->GetPixel(i, j);
				pdata[index++] = GetRValue(colorref);
				pdata[index++] = GetGValue(colorref);
				pdata[index++] = GetBValue(colorref);
			}
	}
	else //transparent.  This means show with a transparent background.
	{
		pdata = new GLubyte[4*cx*cy];
		COLORREF transparentcolorref;
		transparentcolorref = pMemDC->GetPixel(0,0);
			/* We will treat the color found in the upper left corner as transparent. */
		for (int j=cy-1; j >= 0; j--)
			for (int i=0; i<cx; i++)
			{
				colorref = pMemDC->GetPixel(i, j);
				pdata[index++] = GetRValue(colorref);
				pdata[index++] = GetGValue(colorref);
				pdata[index++] = GetBValue(colorref);
				pdata[index++] = colorref == transparentcolorref?0:255;
				/* Set the alpha to minimum on "background" pixels, and to maximum
					otherwise.  These values get normalized to 0.0 and 1.0 in
					the fragment operations. */
			}
	}
	return pdata; //Return it to the cTexture constructor method, where it gets used and deleted.
}

void cTexture::_maketexture(GLubyte *pdata)
{	/* usemipmap uses more memory, makes a nicer looking
		images across a range of size scales.  It may be slower. */
	::glGenTextures(1, &_textureID); /* Get an unused name for a texture
		object, which is something a bit like a display list.  That is,
		it's a kind of handle which will enable us to rapidly reaccess a
		texture once we've first loaded it. */
	::glBindTexture(GL_TEXTURE_2D, _textureID); /* Makes this texture current
		so that all the following calls in _maketexture() affect it. */
	::glPixelStorei(GL_UNPACK_ALIGNMENT, 1); //We're not padding at ends of lines to have even byte cound.
	::glPixelStorei(GL_PACK_ALIGNMENT, 1); //We're not padding at ends of lines to have even byte cound.

	::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); //GL_CLAMP less likely to make artifacts.
	::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	if (_usemipmap)
	{
		::glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		::glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	    ::gluBuild2DMipmaps(GL_TEXTURE_2D, 
			_pixeldataformat,/* Internal GL format to use for pixel component intensities
				can also be viewed as number of color components in texture:
				1,2,3,4 or GL_LUMINANCE, GL_LUMINANCE_ALPHA, GL_RGB, GL_RGBA. */
			_cx, _cy, //Width and height of the source bitmap
			_pixeldataformat,
			GL_UNSIGNED_BYTE, //Type of the intensity values
			pdata); //Source array of intensities of pixel components
	}
	else //No usemipmap means use only use one texture
	{
	//  LINEAR means average a 2x2 neighborhood.
		::glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		::glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		::glTexImage2D( GL_TEXTURE_2D, 
			0, //Level of detail currently being defined, starting with 0.
			_pixeldataformat, //Internal GL format to use for pixel component intensities
			_cx, _cy, //Width and height of the source bitmap
			0, //Width of border, if any, in pixels.
			_pixeldataformat,
			GL_UNSIGNED_BYTE, //Type of the intensity values
			pdata); //Source array of intensities of pixel components
	}
	::glBindTexture(GL_TEXTURE_2D, 0); //Close off the call to glBindTexture started above.
}

