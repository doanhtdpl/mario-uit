#ifndef FPS__H
#define FPS__H

#include <Windows.h>
#include "Device.h"

#define DEFAULT_LIMIT_FPS 25

class CFps
{
protected:
	int m_iLimitFps;
	int m_iLimitFrameDt;	
	int m_iFrameDt;
private:
	long m_iStartTime;
public:
	// Singleton
	static CFps * s_pInstance;
	static CFps * GetInstance();

	// Contructor
	CFps();
	~CFps();
		
	void SetLimitFps(unsigned int limitFps);
	void BeginCounter();
	void EndCounter();

	int GetFrameDt();
	int GetRuntimeFps();
};

#endif
