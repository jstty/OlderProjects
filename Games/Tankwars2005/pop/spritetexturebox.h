#ifndef TEXTUREBOX_HPP
#define TEXTUREBOX_HPP

#include "sprite.h"
#include "realbox.h"

class cSpriteTextureBox : public cSpriteComposite
{
DECLARE_SERIAL(cSpriteTextureBox)
protected:
	cRealBox *_pskeleton;
	void _initialize();
	void _fixspriteattitude(int boxside);
	void _fixspriteattitudes();
public:
	cSpriteTextureBox(
		const cVector3 &locorner = cVector(-1, -1, -1),
		const cVector3 &hicorner = cVector(1, 1, 1),
		int resourceID = -1, int xtilecount = 1);
	cSpriteTextureBox(cRealBox *pskeleton, int resourceID = -1, int
		xtilecount = 1);
	cSpriteTextureBox(cSpriteTextureBox *ptexturebox):cSpriteComposite()
		{copy(ptexturebox);}
	cSpriteTextureBox(cSpriteTextureBox &texturebox):cSpriteComposite()
		{copy(&texturebox);}
	virtual ~cSpriteTextureBox();
//Accessors
	cSprite* pside(int boxside); 
	cRealBox *pskeleton(){return _pskeleton;}
	Real lox(){return _pskeleton->lox();}
	Real loy(){return _pskeleton->loy();}
	Real loz(){return _pskeleton->loz();}
	Real hix(){return _pskeleton->hix();}
	Real hiy(){return _pskeleton->hiy();}
	Real hiz(){return _pskeleton->hiz();}
	Real midx(){return _pskeleton->midx();}
	Real midy(){return _pskeleton->midy();}
	Real midz(){return _pskeleton->midz();}
	virtual BOOL enabledisplaylist()const{return FALSE;}
	/* enabledisplaylist specifies whetehr or not you want to
		try and use a display list to show this kind of sprite. By default this is TRUE.  We 
		make it FALSE because the cSpriteTextureBox actually runs slower with displaylists, so we
		want to be able turn of display lists for them.  */ 
//Mutator
	void setSideTexture(int boxside, int resourceid, int xtilecount = 1);
	void setAllSidesTexture(int resourceid, int xtilecount = 1);
	void setPlainRectangle(int boxside); //Makes this side a plain rectangle.
	void setSideInvisible(int boxside);
	void setSideSolidColor(int boxside, COLORREF color); //Makes the side a rect
	void setSideColors(COLORREF color); //Just sets the fill colors
	void setSkeleton(const cRealBox3 &skeleton);
	//cSprite overloads
	virtual void copy(cSprite *psprite);
	virtual void Serialize(CArchive &ar);
//Overload the cSpriteComposite draw function
	virtual void draw(cGraphics *pgraphics, int drawflags); /* We cascade
		to the children like cSpriteComposite, but if drawflags is WIREFRAME,
		we draw the skeleton. */
};
#endif //TEXTUREBOX_HPP