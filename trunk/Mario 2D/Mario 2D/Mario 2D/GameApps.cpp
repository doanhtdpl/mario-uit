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
int CGameApps::Game_Init(HINSTANCE _hInstance)
{
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
	CGameStateManager::GetInstance()->Init(this, m_register->Get_hInstance(), m_register->Get_WndHandle(), m_graphic , m_input, m_spriteHandler);

	return 1;
}

// Destroy
int CGameApps::Game_Destroy()
{
	if (m_register != NULL)
	{
		delete m_register;
	}
	if (m_graphic != NULL)
	{
		delete m_graphic;
	}
	if (m_gamestatemanager != NULL)
	{
		delete m_gamestatemanager;
	}
	if (m_input!=NULL)
	{
		m_input->Kill_Keyboard();
		delete m_input;
	}
	return 1;
}
// Run
void CGameApps::Game_Run()
{
	while (m_isAlived) 
	 {
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
	Game_Destroy();
}

// Pause
void CGameApps::Game_Pause()
{
	m_isPaused = true;
}

// Resume
void CGameApps::Game_Resume()
{
	m_isPaused = false;
}

// Exit
void CGameApps::Game_Exit()
{
	m_isAlived = false;
}

// Flags: isAlived / isPaused
bool CGameApps::IsAlive()
{
	return m_isAlived;
}
bool CGameApps::IsPause()
{
	return m_isPaused;
}


