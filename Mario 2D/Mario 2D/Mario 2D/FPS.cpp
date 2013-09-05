#include "FPS.h"
#include "Device.h"

// Singleton
CFps* CFps::s_pInstance = 0;
CFps* CFps::GetInstance()
{
	if (!s_pInstance){
		s_pInstance = new CFps();
	}
	return s_pInstance;
}

// Contructor
CFps::CFps()
{
	m_iLimitFps = 0;
	m_iLimitFrameDt = 0;
	m_iStartTime = 0;
	m_iFrameDt = 0;
	SetLimitFps(DEFAULT_LIMIT_FPS);
}

// Destructor
CFps::~CFps()
{
	// code here
}

// Set limit frame per second
void CFps::SetLimitFps(unsigned int limitFps) 
{
	m_iLimitFps = limitFps;
	m_iLimitFrameDt = 1000 / limitFps;
}

// Start counting time
void CFps::BeginCounter()
{
	m_iStartTime = CDevice::GetInstance()->GetTimer();
}

// End counting time
void CFps::EndCounter()
{
	long Endtime = CDevice::GetInstance()->GetTimer();
	int Dt = int(Endtime - m_iStartTime);
	if (Dt < m_iLimitFrameDt)
	{
		m_iFrameDt = m_iLimitFrameDt;
		CDevice::GetInstance()->SleepEx(m_iLimitFrameDt - Dt);
	}
	else
	{
		m_iFrameDt = Dt;
		CDevice::GetInstance()->SleepEx(1);
	}

}

// Get frame delta time
int CFps::GetFrameDt() 
{
	return m_iFrameDt;
}

// Get run time frame per second
int CFps::GetRuntimeFps() 
{
	return (m_iFrameDt) ? int(1000 / m_iFrameDt): 0;
}