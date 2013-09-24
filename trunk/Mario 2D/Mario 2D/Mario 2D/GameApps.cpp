#include "GameApps.h"
#include <Windows.h>
#include <iostream>
using namespace std;

// Contructor
CGameApps::CGameApps()
{
}

// Destructor
CGameApps::~CGameApps()
{
}

// Init
int CGameApps::Init(HINSTANCE _hInstance)
{
	cout<<"\nInit game";

// Set defaul parameters
	m_isPaused = false;
	m_isAlived = true;

//  Windows
	m_register = new CRegister(_hInstance);
	if (!m_register->InitWindows())
	{
		MessageBox(m_register->Get_WndHandle(), "Can't Create Windows", "Error", MB_OK );
		return 0;
	}

//	Graphic
	m_graphic = new CGraphic();
	if (!m_graphic->InitDevice(m_register->Get_WndHandle()))
	{
		MessageBox(m_register->Get_WndHandle(), "Can't Create Graphic Device", "Error", MB_OK );
		return 0;
	}

//	Camera
	m_camera = new CCamera();

//	FPS
	m_fps = new CFps();
	m_fps->SetLimitFps(60);

//	Input
	m_input = new CInput();
	if (!m_input->InitInput(m_register->Get_hInstance()))
	{
		MessageBox(m_register->Get_WndHandle(), "Can't Create Input Device", "Error", MB_OK );
		return 0;
	}
	if (!m_input->InitKeyboard(m_register->Get_WndHandle()))
	{
		MessageBox(m_register->Get_WndHandle(), "Can't Create Keyboard", "Error", MB_OK );
		return 0;
	}

//	Sprite
	D3DXCreateSprite(m_graphic->Get_pd3ddevice(), &m_spriteHandler);
	if (m_spriteHandler == NULL)
	{
		return 0;
	}

// Game State Manager
	CGameStateManager::GetInstance()->Init(m_register->Get_hInstance(), m_register->Get_WndHandle(), m_graphic , m_input);

	return 1;
}

// Destroy
void CGameApps::Destroy()
{
	cout<<"\nDestroy game";
}
// Run
void CGameApps::Run()
{
	this->Init(m_register->Get_hInstance());
	 while (m_isAlived) {
		m_fps->BeginCounter();
        if (m_isPaused == false) {
			CGameStateManager::GetInstance()->Update(true);
        } else {
            CGameStateManager::GetInstance()->Update(false);
        }
		m_fps->EndCounter();
		//
        Sleep(TIME_DELAY);
    }
	Destroy();
}

// Pause
void CGameApps::Pause()
{
	m_isPaused = true;
}

// Resume
void CGameApps::Resume()
{
	m_isPaused = false;
}

// Exit
void CGameApps::Exit()
{
	m_isAlived = false;
}

// Flags: isAlived / isPaused
bool CGameApps::IsAlive(){
	return m_isAlived;
}
bool CGameApps::IsPause(){
	return m_isPaused;
}


