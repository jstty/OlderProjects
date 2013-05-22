/*
The MD2 mesh type was orginally created for Quake 2.  You can create your own
with Milkshape.
11/22/01	Giavinh	Pham Created. Added MD2 mesh model (animation) into the game.
4/14/2003  Rudy Rucker reworked so the textures are handled by cGraphics.
*/

#ifndef QUAKEMD2MODEL_H
#define QUAKEMD2MODEL_H


#include <stdio.h>
//#include <gl/gl.h>				// standard OpenGL include
//#include <gl/glu.h>				// OpenGL utilties
#include "realbox.h"	//for boundingbox method return type
#include "afxcoll.h" //For CMapStringToOb
class cGraphics; //So I can use this as an argument in cMD2Model::Animate, etc.

#define MAX_FRAMES 512

//Enums and helper structures

// types of texture file formats
enum texTypes_t
{
	PCX,
	BMP
};

// model animation states
enum modelState_t
{
	MODEL_IDLE,	    // idle animation
	MODEL_CROUCH,	// crouch animation
	MODEL_RUN,		// running animation
	MODEL_JUMP,		// jumping animation
	MODEL_DIE,		// dying animation
	MODEL_SHOT,		// animation of getting shot
};

// only partial pcx file header
typedef struct
{
	unsigned char manufacturer;
	unsigned char version;
	unsigned char encoding;
	unsigned char bits;
	unsigned int xMin; //This and the following four lines were unsigned char
	unsigned int yMin; //And this meant I couldn't store a correct size in them.
	unsigned int xMax; //If the size was greater than 256, so a PCX of
	unsigned int yMax; //size 320 by 200 wouldn't load.
	unsigned char *palette;
} PCXHEADER;

// a single vertex
typedef struct
{
	float point[3];
} vector_t;

vector_t operator-(vector_t a, vector_t b);
vector_t operator*(float f, vector_t b);
vector_t operator/(vector_t a, vector_t b);
vector_t operator+(vector_t a, vector_t b);

/* 
MD2 Model Helper Structures
*/

// texture coordinate
typedef struct
{
	float s;
	float t;
} texCoord_t;

// texture coordinate index
typedef struct
{
	short s;
	short t;
} stIndex_t;

// info for a single frame point
typedef struct
{
	unsigned char v[3];
	unsigned char normalIndex;	// not used
} framePoint_t;

// information for a single frame
typedef struct
{
	float scale[3];
	float translate[3];
	char name[16];
	framePoint_t fp[1];
} frame_t;

// data for a single triangle
typedef struct
{
	unsigned short meshIndex[3];    // vertex indices
	unsigned short stIndex[3];      // texture coordinate indices
} mesh_t;

typedef struct
{
	int ident;        // identifies as MD2 file "IDP2"
	int version;      // mine is 8
	int skinwidth;    // width of texture
	int skinheight;   // height of texture
	int framesize;    // number of bytes per frame
	int numSkins;     // number of textures
	int numXYZ;       // number of points
	int numST;        // number of texture
	int numTris;      // number of triangles
	int numGLcmds;
	int numFrames;    // total number of frames
	int offsetSkins;  // offset to skin names (64 bytes each)
	int offsetST;     // offset of texture s-t values
	int offsetTris;   // offset of triangle mesh
	int offsetFrames; // offset of frame data (points)
	int offsetGLcmds; // type of OpenGL commands to use
	int offsetEnd;    // end of file
} modelHeader_t;

//===================Class for turning strings into integer keys

class cStringPool : public CArray<CString, CString>
{
public:
	int lookupKey(CString string)
	{
		for (int i=0; i<GetSize(); i++)
			if (string == GetAt(i))
				return i;
		return Add(string);
	}
};

class cTextureInfo;

class cMapFilenameToTextureInfo : public CMap<int, int, cTextureInfo*, cTextureInfo*>
{
public:
	static cStringPool _skinFilenamePool;
	BOOL Lookup( CString skinfilename, cTextureInfo*& ptextureinfo );
	int lookupKey(CString skinfilename){return _skinFilenamePool.lookupKey(skinfilename);}
		/* I need cMapFilenameToTextureInfo::lookupKey for the cTextureInfo::skinfileKey
		method whichs is used by the cGraphicsOpenGL::selectSkinTexture. */
	void free();
};

class cTextureInfo
{
public: 
//static
	static cMapFilenameToTextureInfo _mapFilenameToTextureInfo;
//members									
	texTypes_t textureType;
	int _width;					// width of texture
	int _height;					// height of texture
	CString _skinfilename;
	unsigned char *_pdata;		// the texture data
	unsigned char *_ppalette;
	int _lifetime;
//TextureInfo loading methods
	BOOL LoadTexture(const char *filename); //Calls one of the next two pairs
	unsigned char *LoadBitmapFile(const char *filename, BITMAPINFOHEADER *bitmapInfoHeader);
	BOOL LoadBMPTexture(const char *filename);
	unsigned char *LoadPCXFile(const char *filename, PCXHEADER *pcxHeader);
	BOOL LoadPCXTexture(const char *filename);
public:
	cTextureInfo():_pdata(NULL), _ppalette(NULL){}
	CString skinfilename(){return _skinfilename;}
	~cTextureInfo();
	unsigned char * pdata(){return _pdata;}
	void resetData(int width, int height, unsigned char *pdatanew)
		{delete [] _pdata; _pdata = pdatanew; _width = width; height = _height;}
};

//MD2Model Stuff==========================================
class cMD2Info;

class cMapFilenameToMD2Info : public CMap<int, int, cMD2Info*, cMD2Info*>
{
public:
	static cStringPool _modelFilenamePool;
	BOOL Lookup( CString modelfilename, CString skinfilename, cMD2Info*& pmd2info );
	void free();
};

class cMD2Info
{
protected:
	int numFrames;				// number of model frames
	int numVertices;			// number of vertices per frame
	int _numTriangles;			// number of triangles per frame
	int numST;					// number of skins.  Not used now, we have only one skin.
	int frameSize;				// size of each frame in bytes
	mesh_t *_triIndex;			// triangle list
	texCoord_t *st;			    // texture coordinate list
	vector_t *vertexList;		// vertex list
public:
	cMD2Info();
	~cMD2Info();
	BOOL Load(const char * modelfilename, const char * skinfilename);
	cRealBox boundingbox(int framenumber = 0);
friend class cMD2Model;
};

class cMD2Model
{
public:
	static cMapFilenameToMD2Info _mapFilenameToMD2Info;
protected:
	CString _skinfilename;      //Use this to get cTextureInfo
//Store the bulky cMD2Info _pdata arrays in a shared static cMD2Info object
	CString _modelfilename;     //Use with _mapFilenameToMD2Info to find a cMD2Info object.
//Individual instance data
	int _currentFrame;			// current frame # in animation
	int _nextFrame;				// next frame # in animation
	float _interpol;			// percent through current frame
	modelState_t _modelState;	// current model animation state
public:
	cMD2Model();    // constructor
	~cMD2Model(){}   // default destructor, as it doesn't own any arrays.
	int Unload();	// free memory of model
//Shared Static cMD2Info data Methods	
	BOOL Load(const char *modelfilename, const char *skinfilename);
		// If necessary, make a new cMD2Info object and load model, also load skin.
	//Accessors
		/* triIndex, numTriangles, textureCoords are
			used by cGraphicsOpenGL::interpolateAndRender */
	cMD2Info* pmd2info();
	mesh_t* triIndex(){return pmd2info()->_triIndex;} 
	int numTriangles(){return pmd2info()->_numTriangles;} 
	int numFrames(){return  pmd2info()->numFrames;}
	vector_t *vertexList(){return pmd2info()->vertexList;}
	texCoord_t* textureCoords() {return pmd2info()->st;}		    // texture coordinate list
	cRealBox boundingbox(int framenumber = 0){return pmd2info()->boundingbox(framenumber);} //Used by cSpriteQuake constructor and setRadius.
	cTextureInfo *ptextureinfo(); /* Used by cGraphicsOpenGL::selectSkinTexture in
		the cGraphicsOpenGL::interpolateAndRender method. */
	int skinfileKey(){return cTextureInfo::_mapFilenameToTextureInfo.lookupKey(_skinfilename);}
		/* Used by cGraphicsOpenGL::selectSkinTexture. */
//Individual Instance Methods
	int Animate(cGraphics *pgraphics, int startFrame, int endFrame, float percent);
		// render model with interpolation to get animation
	int RenderFrame(cGraphics *pgraphics, int keyFrame);// render a single frame
	//Mutators
	int SetState(modelState_t state);	// set animation state of model
	void setAnimatePercent(float percent);// set the current interpolatio percent
	//Accessors
	modelState_t GetState(); // retrieve animation state of model
	float animatePercent() const;// get the current interpolation percent
};

#endif //QUAKEMD2MODEL_H