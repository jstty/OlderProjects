#include "stdafx.h"
#include "PopView.h"
#include "graphics.h"
#include "realbox.h"
#include "spritepolygon.h"
#include "popdoc.h"
#include "critter.h"

IMPLEMENT_SERIAL(cGraphics, CObject, 0 );
IMPLEMENT_SERIAL(cLightingModel, CObject, 0 );

cVector cGraphics::pixelAndPlaneToVector(int xpix, int ypix, const cPlane &plane)
{
	return plane.intersect(pixelToSightLine(xpix, ypix));
		//Find the line of sight and intersect it with the plane.
}

cLine cGraphics::pixelToSightLine(int xpix, int ypix) //This is virtual, cGraphicsMFC does different
{ /* This is a line that runs from the viewer's eye to the direction matching the pixel point. */
	cVector nearpoint = pixelToVector(xpix, ypix, 0.0);
	cVector farpoint =  pixelToVector(xpix, ypix, 1.0);
	cVector tangent = farpoint - nearpoint;
	if (tangent.isPracticallyZero())
		tangent = -cVector3::ZAXIS;
	else
		tangent.normalize();
	return cLine(nearpoint, tangent); //Second arg should be a unit vector.
}

void cGraphics::drawXYrectangle(const cVector &cornerlo, const cVector &cornerhi,
	 cColorStyle *pcolorstyle, int drawflags)
{
	drawrectangle(cornerlo, cVector(cornerhi.x(), cornerlo.y(), cornerlo.z()),
		cornerhi, cVector(cornerlo.x(), cornerhi.y(), cornerlo.z()), 
		pcolorstyle, drawflags);
}

CRect cGraphics::realBoxToCRect(const cRealBox &realbox)
{
	int intlox, intloy, inthix, inthiy;
	Real zbuff; //dummy to ignore
	vectorToPixel(cVector(realbox.lox(), realbox.loy()), intlox, intloy, zbuff);
	vectorToPixel(cVector(realbox.hix(), realbox.hiy()), inthix, inthiy, zbuff);
	return CRect(intlox, inthiy, inthix, intloy); /* The CRect constructor expects
		args in the left, top, right, bottom order. */
}

//=================cLightingModesl stuff==============

void cLightingModel::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
 	if (ar.IsStoring()) // Save 
		ar << _enablelighting;
	else
		ar >> _enablelighting;
}