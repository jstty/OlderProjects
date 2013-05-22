#include "windows.h"
#include <ddraw.h>

#include "..\Header Files\gfx.h"
#include "..\Header Files\Gfx_to_DD.h"

DD_SURFACE GfxToDD(DD_OBJECT pdd, char *FileName)
{
    HBITMAP                 hbm;
    DD_SDESC			          ddsd;
    DD_SURFACE						  pdds;
		GFX_INFO								GfxInfo;
		RGB_PAL								 *RawData;

		//
    // Load Graphics file then data
    //
		LoadGfxFile(FileName, &GfxInfo);
		//
    // Decompress Graphics Data to raw rgb values
    //
		DeCompress(&RawData, &GfxInfo);

		// FlipData
		DWORD i, j, k, count = GfxInfo.header.oSize;
		RGB_PAL		*TempData = new RGB_PAL[count];

		for(i = 0, j = GfxInfo.header.w*(GfxInfo.header.h - 1); i < count; i++, j++)
		{
			if( ( i%GfxInfo.header.w == 0 ) && (i != 0) )
			{
				k = GfxInfo.header.w*2;
				if( j > k )
					j -= k;
				else
					j = 0;
			}

			TempData[i] = RawData[j];
		}
		RawData = TempData;

		hbm = CreateBitmap(GfxInfo.header.w, GfxInfo.header.h, 1, 24, RawData);

    //
    // Create a DirectDrawSurface for this bitmap
    //
    ZeroMemory(&ddsd, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
    ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
    ddsd.dwWidth = GfxInfo.header.w;
    ddsd.dwHeight = GfxInfo.header.h;
    if (pdd->CreateSurface(&ddsd, &pdds, NULL) != DD_OK)
        return NULL;

    SetBitmap(pdds, hbm, GfxInfo.header.w, GfxInfo.header.h);

    DeleteObject(hbm);
    return pdds;
}

int DeCompress(RGB_PAL **data, GFX_INFO *gi)
{
	DWORD i, l, c = gi->header.oSize, t, j, lc;
	RGB_PAL *d;

	if(c)
		d = new RGB_PAL[c];
	else
	{
		// Count Error
		return 2;
	}

	c = 0;
	for(i = 0; i < gi->header.gSize;)
	{
		// one value
		if(gi->data.gfx[i] == 1)
		{
			t = gi->data.gfx[++i];

				d[j].r = gi->data.pal[t].b;
				d[j].g = gi->data.pal[t].g;
				d[j].b = gi->data.pal[t].r;

			i++;	c++;
		}
		// value with 8-bit length
		else if(gi->data.gfx[i] == 2)
		{
			l = gi->data.gfx[++i];
			lc = l + c;
			t = gi->data.gfx[++i];

			for(j = c; j < lc; j++)
			{
				d[j].r = gi->data.pal[t].b;
				d[j].g = gi->data.pal[t].g;
				d[j].b = gi->data.pal[t].r;
			}

			c = lc;	i++;
		}
		// value with 16-bit length
		else if(gi->data.gfx[i] == 3)
		{
			l = (gi->data.gfx[++i] << 8);
			l |= gi->data.gfx[++i];
			lc = l + c;
			t = gi->data.gfx[++i];

			for(j = c; j < lc; j++)
			{
				d[j].r = gi->data.pal[t].b;
				d[j].g = gi->data.pal[t].g;
				d[j].b = gi->data.pal[t].r;
			}

			c = lc;		i++;
		}
		// value with 32-bit length
		else if(gi->data.gfx[i] == 4)
		{
			l = (gi->data.gfx[++i] << 16);
			l |= (gi->data.gfx[++i] << 8);
			l |= gi->data.gfx[++i];
			lc = l + c;
			t = gi->data.gfx[++i];

			for(j = c; j < lc; j++)
			{
				d[j].r = gi->data.pal[t].b;
				d[j].g = gi->data.pal[t].g;
				d[j].b = gi->data.pal[t].r;
			}

			c = lc;		i++;
		}
		// data with 8-bit length
		else if(gi->data.gfx[i] == 5)
		{
			l = gi->data.gfx[++i];
			lc = l + c;
			t = gi->data.gfx[++i];

			for(j = c; j < lc; j++)
			{
				d[j].r = gi->data.pal[t].b;
				d[j].g = gi->data.pal[t].g;
				d[j].b = gi->data.pal[t].r;
			}

			c = lc;		i += l;
		}

		// data with 16-bit lenght
		else if(gi->data.gfx[i] == 6)
		{
			l = (gi->data.gfx[++i] << 8);
			l |= gi->data.gfx[++i];
			lc = l + c;
			t = gi->data.gfx[++i];

			for(j = c; j < lc; j++)
			{
				d[j].r = gi->data.pal[t].b;
				d[j].g = gi->data.pal[t].g;
				d[j].b = gi->data.pal[t].r;
			}

			c = lc;		i += l;
		}
		
		// data with 32-bit length
		else if(gi->data.gfx[i] == 7)
		{
			l = (gi->data.gfx[++i] << 16);
			l |= (gi->data.gfx[++i] << 8);
			l |= gi->data.gfx[++i];
			lc = l + c;
			t = gi->data.gfx[++i];

			for(j = c; j < lc; j++)
			{
				d[j].r = gi->data.pal[t].b;
				d[j].g = gi->data.pal[t].g;
				d[j].b = gi->data.pal[t].r;
			}

			c = lc;		i += l;
		}
		
		else
		{
			// Compression Error
			return 1;
		}
	}

	*data = d;

	return 0;
}

int LoadGfxFile(char *name, GFX_INFO *gi)
{
	DWORD NumBytes = 0;

	HANDLE hFile = CreateFile(name, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
		{	CloseHandle(hFile);		return 1;	}

	ReadFile(hFile, &(gi->header), sizeof(GFX_INFO_HEADER), &NumBytes, NULL);
	if(NumBytes != sizeof(GFX_INFO_HEADER))
		{	CloseHandle(hFile);		return 2;	}

	gi->data.pal = new RGB_PAL[gi->header.pSize];
	ReadFile(hFile, gi->data.pal, gi->header.pSize*sizeof(RGB_PAL), &NumBytes, NULL);
	if(NumBytes != gi->header.pSize*sizeof(RGB_PAL))
		{	CloseHandle(hFile);		return 3;	}

	gi->data.gfx = new BYTE[gi->header.gSize];
	ReadFile(hFile, gi->data.gfx, gi->header.gSize*sizeof(BYTE), &NumBytes, NULL);
	if(NumBytes != gi->header.gSize*sizeof(BYTE))
		{	CloseHandle(hFile);		return 4;	}

	CloseHandle(hFile);
	return 0;
}


HRESULT SetBitmap(DD_SURFACE pdds, HBITMAP hbm, int dx, int dy)
{
    HDC                     hdcImage;
    HDC                     hdc;
    HRESULT                 hr;

    if (hbm == NULL || pdds == NULL)
        return E_FAIL;
    //
    // Make sure this surface is restored.
    //
    pdds->Restore();
    //
    // Select bitmap into a memoryDC so we can use it.
    //
    hdcImage = CreateCompatibleDC(NULL);
    if (!hdcImage)
        OutputDebugString("createcompatible dc failed\n");
    SelectObject(hdcImage, hbm);

    if ((hr = pdds->GetDC(&hdc)) == DD_OK)
    {
        BitBlt(hdc, 0, 0, dx, dx, hdcImage, 0, 0, SRCCOPY);
        pdds->ReleaseDC(hdc);
    }
    DeleteDC(hdcImage);
    return hr;
}