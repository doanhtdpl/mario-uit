#ifndef DEVICE__H
#define DEVICE__H

#if CONFIG_PLATFORM==PLATFORM_WIN32_VS
#	include <Windows.h>
#	include <time.h>
#endif

class CDevice
{
public:
	CDevice();
	~CDevice();
	// Singleton
	static CDevice * s_pInstance;
	static CDevice * GetInstance();
	void SleepEx(unsigned long milisec);
	unsigned long GetTimer();
};

#endif
