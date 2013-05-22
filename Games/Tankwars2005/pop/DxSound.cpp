// DxSound.cpp : implementation file
//

#include "stdafx.h"
#include "Pop.h"

// added by: Joseph E. Sutton
#ifdef USE_DIRECTSOUND

#include "DxSound.h"

#define REL(ptr) {if(ptr) { ptr->Release(); ptr = NULL; }}
#define DEL(ptr) {if(ptr) { delete ptr; ptr = NULL; }}

cDxSound::cDxSound(void) :
_pLoader(NULL),
_pPerformance(NULL),
_pSegment(NULL),
_pSoundManager(NULL)
{
}

cDxSound::~cDxSound(void)
{
	REL(_pSegment);
	REL(_pPerformance);
	REL(_pLoader);
	POSITION pos = _sounds.GetStartPosition();
	long key;
	CSound* value;
	while(pos)
	{
		_sounds.GetNextAssoc(pos, key, value);
		delete value;
	}
	_sounds.RemoveAll();
	DEL(_pSoundManager);
}

cDxSound* cDxSound::getInstance()
{
	cDxSound* pInstance = new cDxSound();
	// Try to initialize DirectMusic
	CoInitialize(NULL);
	if(FAILED(CoCreateInstance(CLSID_DirectMusicLoader, NULL, CLSCTX_INPROC, 
							   IID_IDirectMusicLoader8, (void**)&pInstance->_pLoader)))
	{
		delete pInstance;
		return NULL;
	}
	if(FAILED(CoCreateInstance(CLSID_DirectMusicPerformance, NULL, CLSCTX_INPROC,
						  	   IID_IDirectMusicPerformance8, (void**)&pInstance->_pPerformance)))
	{
		delete pInstance;
		return NULL;
	}
	
	if(FAILED(pInstance->_pPerformance->InitAudio(NULL, NULL, NULL,
				DMUS_APATH_SHARED_STEREOPLUSREVERB, 16, DMUS_AUDIOF_ALL, NULL)))
	{
		delete pInstance;
		return NULL;
	}
	
	// Try to initialize DirectSound
	pInstance->_pSoundManager = new CSoundManager();
	CWnd* pWnd = ::AfxGetMainWnd();
	if(FAILED(pInstance->_pSoundManager->Initialize(pWnd->GetSafeHwnd(), DSSCL_PRIORITY)))
	{
		delete pInstance;
		return NULL;
	}
	if(FAILED(pInstance->_pSoundManager->SetPrimaryBufferFormat(2, 22050, 16)))
	{
		delete pInstance;
		return NULL;
	}
	return pInstance;
}

BOOL cDxSound::playMusic(const char *filename)
{
	// Error check
	if(!_pLoader || !_pPerformance) return FALSE;
	if(_pSegment) stopCurrentSong();

	// Convert char* to WCHAR*
	CString str = filename;
	LPWSTR lpszW = new WCHAR[255];
	LPTSTR lpStr = str.GetBuffer(str.GetLength());
	int nLen = MultiByteToWideChar(CP_ACP, 0, lpStr, -1, NULL, NULL);
	MultiByteToWideChar(CP_ACP, 0, lpStr, -1, lpszW, nLen);

	// Download and play the music
	if(FAILED(_pLoader->LoadObjectFromFile(CLSID_DirectMusicSegment, IID_IDirectMusicSegment8,
		lpszW, (void**)&_pSegment)))
	{
		return FALSE;
	}
	_pSegment->Download(_pPerformance);

   // added loop music: Joseph E. Sutton
   _pSegment->SetRepeats(-1);
   //

	_pPerformance->PlaySegmentEx(_pSegment, NULL, NULL, 0, 0, NULL, NULL, NULL);

	delete[] lpszW;
	return TRUE;
}

BOOL cDxSound::stopCurrentSong()
{
	if(!_pPerformance) return FALSE;
	_pPerformance->Stop(_pSegment, NULL, 0, 0);
	REL(_pSegment);
	return TRUE;
}

BOOL cDxSound::playSound(char *filename)
{
	if(!_pSoundManager) return FALSE;

	CSound *pSound = NULL;
	long hashValue = hash(filename);
	if(!_sounds.Lookup(hashValue, pSound))
	{	// A new sound, so we have to load it in first
		if(FAILED(_pSoundManager->Create(&pSound, filename, 0, GUID_NULL, 5)))
		{
			return FALSE;
		}
		_sounds.SetAt(hashValue, pSound);
	}
	pSound->Play();
	return TRUE;
}

long cDxSound::hash(char *filename)
{
	long ret = 0;
	int i = 0;
	while(*(filename+i) != 0)
	{
		ret += i * (*(filename + i));
		i++;
	}
	return ret;
}

#endif
