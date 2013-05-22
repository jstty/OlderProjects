#pragma once


/*********************************************************
* You'll probably have to link in the following libraries:
* dsound.lib dxerr9.lib dxguid.lib
* And set your include path to include the path to
* the DXSDK include directory.
*********************************************************/

#include <dmusici.h>
#include "dsutil.h"

class cDxSound : public CObject
{
public:
	static cDxSound* getInstance();
	BOOL playSound(char *filename);
	BOOL playMusic(const char *filename);
	BOOL stopCurrentSong();

	~cDxSound(void);

private:
	cDxSound(void);
	long hash(char *filename);

private:
	CSoundManager *_pSoundManager;
	CMap<long, long, CSound*, CSound*> _sounds;
	IDirectMusicLoader8* _pLoader;
	IDirectMusicPerformance8* _pPerformance;
	IDirectMusicSegment8* _pSegment;
};


