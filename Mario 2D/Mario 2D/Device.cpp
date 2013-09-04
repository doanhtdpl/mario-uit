#include "Device.h"

// Contructor
CDevice::CDevice(){}

// Destructor
CDevice::~CDevice(){}

// Singleton
CDevice *CDevice::s_pInstance = 0;
CDevice *CDevice::GetInstance()
{
	if (!s_pInstance){
		s_pInstance = new CDevice();
	}
	return s_pInstance;
}

// Get timer system
unsigned long CDevice::GetTimer()
{
	#if CONFIG_PLATFORM==PLATFORM_WIN32_VS
		return clock();
	#else
		TODO("GetTimer for CONFIG_PLATFORM!=PLATFORM_WIN32_VS is not implement yet !");

		return 0;
	#endif
}

// Sleep frame
void CDevice::SleepEx(unsigned long milisec)
{
	Sleep(milisec);
}

