/////////////////////////////////////////////////////////////////////////////
//
// texture.h : interface of the cTexture class
//
/////////////////////////////////////////////////////////////////////////////

#ifndef TEXTURE_H
#define TEXTURE_H

#include "gl\gl.h"
#include "gl\glu.h"
#include "memorydc.h"

class cTextureInfo; //Defined in quakeMD2model.h

class cTexture : public CObject
{
public:
	static const double cTexture::LOG2;
	static void makePowersOfTwo(int &cx, int &cy);
protected:
	static const BOOL USEMIPMAP;
	static const int MAXEDGESIZE;
		/* The actual aspect of the resource image we loaded will live in double _imageaspect,
		but we will size the texture to powers of two and keep that in _cx and _cy. */ 
	double _imageaspect;
	int _cx; //These are powers of two that try to match the size of the resource image.
	int _cy;
	BOOL _transparent;
	GLint _pixeldataformat; //Will be GL_RGBA or GL_RGB according to _transparent TRUE or FALSE 
	BOOL _usemipmap;
	GLuint _textureID; //An OpenGL-generated integer type name for a texture object.
	GLubyte* _readDC(cMemoryDC *pMemDC); /* A helper function that gets a GLubyte *pdata
		array out of the pMemDC so you can scale it and pass it to _maketexture.
		 Used in the constructors.*/
	void _maketexture(GLubyte *pdata); /* A helper function that actually makes the
		texture.  It's called by _readDC. */
public:
	cTexture(int resourceID, BOOL transparent); //For use with resrource bitmaps
	cTexture::cTexture(cTextureInfo *ptextureinfo); //For use with quake MD2 models
	int textureID(){return _textureID;}
	int cx(){return _cx;}
	int cy(){return _cy;}
	double imageaspect(){return _imageaspect;}
	BOOL usesTransparentMask(){return _transparent;}
   	void select(){::glBindTexture(GL_TEXTURE_2D, _textureID);} 
		/* Makes this texture active. */
	void unselect(){::glBindTexture(GL_TEXTURE_2D, 0);} /* Makes OpenGL
		revert to the default empty texture. Also prevents texture calls from
		affecting this texture. */
	virtual ~cTexture(); //Frees up all associated resources.
};
#endif //TEXTURE_H

