#ifndef AUDIO__H
#define AUDIO__H

#include "dsutil.h"

//primary DirectSound object
extern CSoundManager *dsound;

//function prototypes
class CAudio
{
public:
	CAudio(HWND);
	CSound *LoadSound(char*);	
	void PlaySound(CSound *);
	void LoopSound(CSound *);
	void StopSound(CSound *);	
	static bool m_isSoundOff;
};

#endif
