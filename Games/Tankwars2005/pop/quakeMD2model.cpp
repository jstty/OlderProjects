/*
11/22/01	Giavinh	Pham created. Added MD2 mesh model (animation) into the game.
4/16/03  Rudy changed to integrate better with Pop framework, and to use textures
	more efficiently.
*/

#include "stdafx.h"
#include "quakemd2model.h"
#include "GraphicsOpenGL.h"
#include "spritequake.h" //For the FORCEWIDTH320 switch

#define BITMAP_ID 0x4D42		// the universal bitmap ID

//========Some C type code===========
// vector subtraction
vector_t operator-(vector_t a, vector_t b)
{
	vector_t c;
	c.point[0] = a.point[0] - b.point[0];
	c.point[1] = a.point[1] - b.point[1];
	c.point[2] = a.point[2] - b.point[2];
	return c;
}

// scalar-vector multiplication
vector_t operator*(float f, vector_t b)
{
	vector_t c;
	c.point[0] = f * b.point[0];
	c.point[1] = f * b.point[1];
	c.point[2] = f * b.point[2];
	return c;
}

// vector division
vector_t operator/(vector_t a, vector_t b)
{
	vector_t c;
	c.point[0] = a.point[0] / b.point[0];
	c.point[1] = a.point[1] / b.point[1];
	c.point[2] = a.point[2] / b.point[2];
	return c;
}

// vector addition
vector_t operator+(vector_t a, vector_t b)
{
	vector_t c;
	c.point[0] = a.point[0] + b.point[0];
	c.point[1] = a.point[1] + b.point[1];
	c.point[2] = a.point[2] + b.point[2];
	return c;
}

//========================cTextureInfo Hardcore File Reading Stuff============

// LoadBitmapFile
// desc: Returns a pointer to the bitmap image of the bitmap specified
//       by skinfilename. Also writes data into the bitmap header information.
//		 No support for 8-bit bitmaps.
unsigned char* cTextureInfo::LoadBitmapFile(const char *skinfilename, BITMAPINFOHEADER *bitmapInfoHeader)
{
	FILE *filePtr;							// the file pointer
	BITMAPFILEHEADER	bitmapFileHeader;		// bitmap file header
	unsigned char		*bitmapImage;			// bitmap image data
	unsigned int		imageIdx = 0;		// image index counter
	unsigned char		tempRGB;				// swap variable
	
// open skinfilename in "read binary" mode
	filePtr = fopen(skinfilename, "rb");
	if (filePtr == NULL)
		return NULL;
// read the bitmap file header
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);
// verify that this is a bitmap by checking for the universal bitmap id
	if (bitmapFileHeader.bfType != BITMAP_ID)
	{
		fclose(filePtr);
		return NULL;
	}
// read the bitmap information header
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);
// move file pointer to beginning of bitmap data
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);
// allocate enough memory for the bitmap image data
	bitmapImage = new unsigned char[bitmapInfoHeader->biSizeImage];
// verify memory allocation
	if (!bitmapImage)
	{
		delete [] bitmapImage;
		fclose(filePtr);
		return NULL;
	}
// read in the bitmap image data
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);
// make sure bitmap image data was read
	if (bitmapImage == NULL)
	{
		fclose(filePtr);
		return NULL;
	}
// swap the R and B values to get RGB since the bitmap color format is in BGR
	for (imageIdx = 0; imageIdx < bitmapInfoHeader->biSizeImage; imageIdx+=3)
	{
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}
// close the file and return the bitmap image data
	fclose(filePtr);
	return bitmapImage;
}

// LoadBMPTexture()
// desc: loads a texture of the BMP format
BOOL cTextureInfo::LoadBMPTexture(const char *skinfilename)
{
	BITMAPINFOHEADER headerinfo;		// BMP header

// store BMP data in texture
	_pdata = LoadBitmapFile(skinfilename, &headerinfo);
	/* Note that unlike PCX, we don't bother scaling the rectangle edges to powers of two. */
	if (_pdata == NULL)
		return FALSE;
// store texture information
	_width = headerinfo.biWidth;
	_height = headerinfo.biHeight;
	_ppalette = NULL;
	textureType = BMP;
	return TRUE;
}

// LoadPCXFile()
// desc: returns an array of pixel data.  Also loads info into the PCXHEADER.
unsigned char*  cTextureInfo::LoadPCXFile(const char *skinfilename,
	PCXHEADER *pcxHeader)
{
	int idx = 0;                  // counter index
	int c;                        // used to retrieve a char from the file
	int i;                        // counter index
	int numRepeat;      
	FILE *filePtr;                // file handle
	int width;                    // pcx width
	int height;                   // pcx height
	unsigned char *pixelData;     // pcx image data
	unsigned char *paletteData;   // pcx palette data
	
// open PCX file
	filePtr = fopen(skinfilename, "rb");
	if (filePtr == NULL)
		return NULL;
// retrieve first character; should be equal to 10
	c = getc(filePtr);
	if (c != 10)
	{
		fclose(filePtr);
		return NULL;
	}
// retrieve next character; should be equal to 5
	c = getc(filePtr);
	if (c != 5)
	{
		fclose(filePtr);
		return NULL;
	}
// reposition file pointer to beginning of file
	rewind(filePtr);
// read 4 characters of data to skip
	fgetc(filePtr);
	fgetc(filePtr);
	fgetc(filePtr);
	fgetc(filePtr);
// retrieve leftmost x value of PCX
//	pcxHeader->xMin = fgetc(filePtr);       // loword
//	pcxHeader->xMin |= fgetc(filePtr) << 8; // hiword
	int xminlo = fgetc(filePtr);       // loword
	int xminhi = fgetc(filePtr); // hiword
	xminhi <<= 8;
	int xmin =  xminlo | xminhi;
	pcxHeader->xMin = xmin;

// retrieve bottom-most y value of PCX
	pcxHeader->yMin = fgetc(filePtr);       // loword
	pcxHeader->yMin |= fgetc(filePtr) << 8; // hiword
// retrieve rightmost x value of PCX
	pcxHeader->xMax = fgetc(filePtr);       // loword
	pcxHeader->xMax |= fgetc(filePtr) << 8; // hiword
// retrieve topmost y value of PCX
	pcxHeader->yMax = fgetc(filePtr);       // loword
	pcxHeader->yMax |= fgetc(filePtr) << 8; // hiword
// calculate the width and height of the PCX
	width = pcxHeader->xMax - pcxHeader->xMin + 1;
	height = pcxHeader->yMax - pcxHeader->yMin + 1;

// allocate memory for PCX image data
	pixelData = new unsigned char[width*height];
// set file pointer to 128th byte of file, where the PCX image data starts
	fseek(filePtr, 128, SEEK_SET);
// decode the pixel data and store
	while (idx < (width*height))
	{
		c = getc(filePtr);
		if (c > 0xbf)
		{
			numRepeat = 0x3f & c;
			c = getc(filePtr);
			for (i = 0; i < numRepeat; i++)
			{
				pixelData[idx++] = c;
			}
		}
		else
			pixelData[idx++] = c;
		fflush(stdout);
	}
// allocate memory for the PCX image palette
	paletteData = new unsigned char[768];
// palette is the last 769 bytes of the PCX file
	fseek(filePtr, -769, SEEK_END);
// verify palette; first character should be 12
	c = getc(filePtr);
	if (c != 12)
	{
		fclose(filePtr);
		return NULL;
	}
// read and store all of palette
	for (i = 0; i < 768; i++)
	{
		c = getc(filePtr);
		paletteData[i] = c;
	}
// close file and store palette in header
	fclose(filePtr);
	pcxHeader->palette = paletteData;
// return the pixel image data
	return pixelData;
}

// LoadPCXTexture()
// desc: loads a PCX image file as a texture
 BOOL cTextureInfo::LoadPCXTexture(const char *skinfilename)
{
	PCXHEADER headerinfo;            // header of texture
	unsigned char *unscaledData;// used to calculate pcx
	int i;                             // index counter
	int j;                             // index counter
	
// load the PCX file into the texture struct
	_pdata = LoadPCXFile(skinfilename, &headerinfo);
	if (_pdata == NULL)
		return FALSE;
// store the texture information
	_ppalette = headerinfo.palette;
#ifdef FORCEWIDTH320
	_width = 320; 
#else //normal not FORCEWIDTH320
	_width = headerinfo.xMax - headerinfo.xMin + 1;
#endif //FORCEWIDTH320

	_height = headerinfo.yMax - headerinfo.yMin + 1;
	textureType = PCX;
// allocate memory for the unscaled data
	unscaledData = new unsigned char[_width*_height*4];
// store the unscaled rearranged data via the _ppalette
	for (j = 0; j < _height; j++) 
	{
		for (i = 0; i < _width; i++) 
		{
			unscaledData[4*(j*_width+i)+0] = (unsigned char)_ppalette[
				3*_pdata[j*_width+i]+0];
			unscaledData[4*(j*_width+i)+1] = (unsigned char)_ppalette[
				3*_pdata[j*_width+i]+1];
			unscaledData[4*(j*_width+i)+2] = (unsigned char)_ppalette[
				3*_pdata[j*_width+i]+2];
			unscaledData[4*(j*_width+i)+3] = (unsigned char)255;
		}
	}

// clear the texture data
	delete [] _pdata;
	_pdata = NULL;
// reallocate memory for the texture _pdata
	_pdata = new unsigned char[_width*_height*4];
// copy the rearranged unscaled data
	for (i =0; i < _width*_height*4; i++)
		_pdata[i] = unscaledData[i];
//Important, or you get memory leak.
	delete [] unscaledData;
//Done
	return TRUE;
}

// LoadTexture()
// desc: loads a texture's information given the skinfilename
// 
BOOL cTextureInfo::LoadTexture(const char *skinfilename)
{
	BOOL success;
	// get extension from skinfilename
	char * extStr = strchr(skinfilename, '.');
	extStr++;
	// set the texture type based on extension of skinfilename
	if ((strcmp(extStr, "BMP") == 0) || (strcmp(extStr, "bmp") == 0))
		success = LoadBMPTexture(skinfilename);
	else if ((strcmp(extStr, "PCX") == 0) || (strcmp(extStr, "pcx") == 0) )
		success = LoadPCXTexture(skinfilename);
	return success;
}

cTextureInfo::~cTextureInfo()
{
	if (_pdata)
	{
		delete [] _pdata;
		_pdata = NULL;
	}
	if (_ppalette)
	{
		delete [] _ppalette;
		_ppalette = NULL;
	}
}


//=========================Texture Map Statics and Methods =========
//The static map members of cTextureInfo
cMapFilenameToTextureInfo cTextureInfo::_mapFilenameToTextureInfo;
cStringPool cMapFilenameToTextureInfo::_skinFilenamePool; //Static map from filename strings to integer IDs.

BOOL cMapFilenameToTextureInfo::Lookup(CString skinfilename, cTextureInfo*& ptextureinfo)
{
	BOOL success;
	int skinfileKey = _skinFilenamePool.lookupKey(skinfilename);

	success = CMap<int, int, cTextureInfo*, cTextureInfo*>::Lookup(skinfileKey, ptextureinfo);
	if (success) //We've already read in and saved the _pdata before.
		return TRUE;
	//Otherwise create and register a new cTextureInfo* object that's loaded with the skinfile.
	ptextureinfo = new cTextureInfo();
	success = ptextureinfo->LoadTexture(skinfilename);
	if(success) //Save the ptextureinfo
		SetAt(skinfileKey, ptextureinfo);
	return success;
}

cTextureInfo* cMD2Model::ptextureinfo()
{
	cTextureInfo *pinfo = NULL;
	BOOL success;

	success = cTextureInfo::_mapFilenameToTextureInfo.Lookup(_skinfilename, pinfo);
	ASSERT(pinfo);
	return pinfo; //If failure.
}

void cMapFilenameToTextureInfo::free()
// We have to use a special kind of trick for iterating over a CMap.
{
	POSITION pos = GetStartPosition();
	while( pos != NULL )
	{
	    cTextureInfo* pmapentry;
		int key;
	    // Get key ( skinID ) and value ( cTextureInfo* )
		GetNextAssoc( pos, key, pmapentry);
	    // Use key and/or value
		RemoveKey(key); 
		delete pmapentry;
		pmapentry = NULL;
	}
}
//===============Model Map Methods =======================================
//The static map members of cMD2Model
cMapFilenameToMD2Info cMD2Model::_mapFilenameToMD2Info;
cStringPool cMapFilenameToMD2Info::_modelFilenamePool; //Static map from filename strings to integer IDs.

BOOL cMapFilenameToMD2Info::Lookup(
	CString modelfilename, CString skinfilename, cMD2Info*& pmd2info)
{
	BOOL success;
	int modelfileKey = _modelFilenamePool.lookupKey(modelfilename);

	success = CMap<int, int, cMD2Info*, cMD2Info*>::Lookup(modelfileKey, pmd2info);
	if (success) //We've already read in and saved the _pdata before.
		return TRUE;
	//Otherwise create and register a new cMD2Info* object that's loaded with the modelfile.
	pmd2info = new cMD2Info();
	success = pmd2info->Load(modelfilename, skinfilename);
	if(success) //Save the ptextureinfo
		SetAt(modelfileKey, pmd2info);
	return success;
}

cMD2Info* cMD2Model::pmd2info()
{
	cMD2Info *pinfo = NULL;
	BOOL success;

	success = _mapFilenameToMD2Info.Lookup(_modelfilename, _skinfilename, pinfo);
	ASSERT (pinfo);
	return pinfo; //If failure.
}

void cMapFilenameToMD2Info::free()
// We have to use a special kind of trick for iterating over a CMap.
{
	POSITION pos = GetStartPosition();
	while( pos != NULL )
	{
	    cMD2Info* pmapentry;
		int key;
	    // Get key ( modelID and value ( cMD2Info* )
		GetNextAssoc( pos, key, pmapentry);
	    // Use key and/or value
		RemoveKey(key); 
		delete pmapentry;
		pmapentry = NULL;
	}
}
/////////////////////////////////////////////////////////////////////////////
// cMD2Model Class
/////////////////////////////////////////////////////////////////////////////

// cMD2Model constructor
cMD2Info::cMD2Info()
{
	numVertices = 0;    // vertices
	_numTriangles = 0;   // triangles
	numFrames = 0;      // frames
	numST = 0;          // texture coordinates
	frameSize = 0;      // needed?
	_triIndex = NULL;    // triangle indices
	st = NULL;          // texture coordinate indices
	vertexList = NULL;  // vertices
}    

cMD2Model::cMD2Model()
{
	_currentFrame = 0;   // current keyframe 
	_nextFrame = 1;      // next keyframe
	_interpol = 0.0;     // interpolation percent
	_skinfilename = "";    // skinfilename
	_modelfilename = "";    // modelfilename
	_modelState = MODEL_IDLE;
}    

// cMD2Model::Load()
// access: public
// desc: loads model and skin
BOOL cMD2Model::Load(const char *modelfilename, const char *skinfilename)
{
	_modelfilename = modelfilename;
	_skinfilename = skinfilename;
	cMD2Info *pdummy;
	return _mapFilenameToMD2Info.Lookup(_modelfilename, _skinfilename, pdummy);
}


BOOL cMD2Info::Load(const char *modelfilename, const char *skinfilename)
{
	//First load the modelfilename==================
	FILE *filePtr;                          // file pointer
	int fileLen;                            // length of model file
	char *buffer;                           // file buffer
	
	modelHeader_t *modelHeader;             // model header
	
	stIndex_t *stPtr;                       // texture data
	frame_t *frame;                         // frame data
	vector_t *vertexListPtr;                // index variable
	mesh_t *bufIndexPtr;          // index variables
	int i, j;                               // index variables

	// open the model file
	filePtr = fopen(modelfilename, "rb");
	if (filePtr == NULL)
		return FALSE;
	
	// find length of file
	fseek(filePtr, 0, SEEK_END);
	fileLen = ftell(filePtr);
	fseek(filePtr, 0, SEEK_SET);
	
	// read entire file into buffer
	buffer = new char [fileLen+1];
	fread(buffer, sizeof(char), fileLen, filePtr);
	
	// extract model file header from buffer
	modelHeader = (modelHeader_t*)buffer;
	
	vertexList = new vector_t [modelHeader->numXYZ * modelHeader->numFrames];
	
	numVertices = modelHeader->numXYZ; //Vertices per frame
	numFrames = modelHeader->numFrames; 
	frameSize = modelHeader->framesize; //Size of a frame in bytes
	
	for (j = 0; j < numFrames; j++)
	{
		frame = (frame_t*)&buffer[modelHeader->offsetFrames + frameSize * j];
		
		vertexListPtr = (vector_t*)&vertexList[numVertices * j];
		for (i = 0; i < numVertices; i++)
		{
			vertexListPtr[i].point[0] = frame->scale[0] * frame->fp[i].v[0] + frame->translate[0];
			vertexListPtr[i].point[1] = frame->scale[1] * frame->fp[i].v[1] + frame->translate[1];
			vertexListPtr[i].point[2] = frame->scale[2] * frame->fp[i].v[2] + frame->translate[2];
		}
	}

	_numTriangles = modelHeader->numTris;
	_triIndex = new mesh_t [_numTriangles];
	
	// point to triangle indexes in buffer
	bufIndexPtr = (mesh_t*)&buffer[modelHeader->offsetTris];
	
	// create a mesh (triangle) list
	for (j = 0; j < numFrames; j++)         
	{
		// for all triangles in each frame
		for(i = 0; i < _numTriangles; i++)
		{
			_triIndex[i].meshIndex[0] = bufIndexPtr[i].meshIndex[0];
			_triIndex[i].meshIndex[1] = bufIndexPtr[i].meshIndex[1];
			_triIndex[i].meshIndex[2] = bufIndexPtr[i].meshIndex[2];
			_triIndex[i].stIndex[0] = bufIndexPtr[i].stIndex[0];
			_triIndex[i].stIndex[1] = bufIndexPtr[i].stIndex[1];
			_triIndex[i].stIndex[2] = bufIndexPtr[i].stIndex[2];
		}
	}

	/* Now get the cTextureInfo* object, which will have the effect of registering
	the filename and creating and retgistering a cTextureInfo*, if this is the first time
	the skin file name is used. */
	cTextureInfo *ptextureinfo = NULL;
	BOOL success = cTextureInfo::_mapFilenameToTextureInfo.Lookup(skinfilename, ptextureinfo);
	if (!success || !ptextureinfo)
		return FALSE;

	//Use the model info and skin info together to initialize texture coords st
	int imagewidth = ptextureinfo->_width;
	int imageheight = ptextureinfo->_height;

	numST = modelHeader->numST;
	st = new texCoord_t [numST];
	stPtr = (stIndex_t*)&buffer[modelHeader->offsetST];
		/* The stPtr[i].s and stPtr[i].s are actually pixel count
		numbers, as in "m-th pixel over and n-th pixel down in my skin file".
		We convert them into proportions between 0.0 and 1.0 relative to the
		size of the original skin image that was saved with the MD2 model
		and save these values in the st[i].s and st[i].t so the OpenGL
		texture can use them.
			Even if we plan to rescale the image that won't in fact affect the
		proportional locations of the texture points since we will still think
		of the map as a swatch in the plane from corner (0.0,0.0) to corner
		(1.0, 1.0).  So there seems to be no need to compute here the rescaled
		image size with cTexture::makePowersOfTwo(imagewidth, imageheight);
		and then use it in any fashion. */
	for (i = 0; i < numST; i++)
	{
		float s = stPtr[i].s; float t = stPtr[i].t;
		st[i].s = (float)stPtr[i].s / (float)imagewidth;
		st[i].t = (float)stPtr[i].t / (float)imageheight;
		s = st[i].s; t = st[i].t;
	}

	// close file and free memory
	fclose(filePtr);
	delete [] buffer;
	
	return TRUE;
}

// cMD2Model::Animate()
// access: public
// desc: animates the model between the keyframes startFrame and endFrame
int cMD2Model::Animate(cGraphics *pgraphics, int startFrame, int endFrame, float percent)
{
	if ((startFrame > _currentFrame))
		_currentFrame = startFrame;
	if ((startFrame < 0) || (endFrame < 0))
		return -1;
	if ((startFrame >= numFrames()) || (endFrame >= numFrames()))
		return -1;
	if (_interpol >= 1.0)
	{
		_interpol = 0.0f;
		_currentFrame++;
		if (_currentFrame >= endFrame)
			_currentFrame = startFrame;
		_nextFrame = _currentFrame + 1;
		if (_nextFrame >= endFrame)
			_nextFrame = startFrame;
	}

	cMD2Info *pinfo = pmd2info();
	int numvertsperframe = pinfo->numVertices;
	vector_t *startframe = &((pinfo->vertexList)[numvertsperframe * _currentFrame]);
	vector_t *endframe = &((pinfo->vertexList)[numvertsperframe * _nextFrame]);
	pgraphics->interpolateAndRender(this, startframe, endframe, _interpol);

	_interpol += percent;  // increase percentage of interpolation between frames
	return 0;
}

// RenderFrame()
// desc: renders a single key frame
int cMD2Model::RenderFrame(cGraphics *pgraphics, int keyFrame)
{
	return Animate(pgraphics, keyFrame, keyFrame, 0.0);
}

// Unload()
// desc: unloads model data from memory
cMD2Info::~cMD2Info()
{
	if (_triIndex)       // triangle list
		delete [] _triIndex;
	if (vertexList)     // vertex list
		delete [] vertexList;
	if (st)             // texture coordinate list
		delete [] st;
	_triIndex = NULL;    // triangle indices
	st = NULL;          // texture coordinate indices
	vertexList = NULL;  // vertices
}

// SetState()
// desc: set the model state
int cMD2Model::SetState(modelState_t state)
{
	_modelState = state;
	return 0;
}

// GetState()
// desc: retrieve the model state
modelState_t cMD2Model::GetState()
{
	return _modelState;
}

// animatePercent()
// access: public
// desc: get the current interpolation percent
float cMD2Model::animatePercent() const
{
	return _interpol;
}

// setAnimatePercent()
// access: public
// desc: set the current interpolatio percent
void cMD2Model::setAnimatePercent(float percent)
{
	_interpol = percent;
}

cRealBox cMD2Info::boundingbox(int framenumber)
{
	/*We return the bounding box for the critter as it appears in the first frame.
		We have numVertices vertices per frame, so the first numVertices all belong to
		the first frame. */
	Real lox, hix, loy, hiy, loz, hiz, val;

	int baseindex = numVertices * framenumber;
	
	lox = hix = vertexList[0].point[0];
	loy = hiy = vertexList[0].point[1];
	loz = hiz = vertexList[0].point[2];

	for (int i=1; i<numVertices; i++)
	{
		val = vertexList[baseindex + i].point[0];
		if (val < lox){lox = val;}
		if (val > hix){hix = val;}
		val = vertexList[baseindex + i].point[1];
		if (val < loy){loy = val;}
		if (val > hiy){hiy = val;}
		val = vertexList[baseindex + i].point[2];
		if (val < loz){loz = val;}
		if (val > hiz){hiz = val;}
	}
	return cRealBox(cVector(lox, loy, loz), cVector(hix, hiy, hiz));
}	