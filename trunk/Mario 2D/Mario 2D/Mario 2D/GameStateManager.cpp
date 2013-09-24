#include "GameStateManager.h"
#include "LoadingState.h"
#include "LogoState.h"


CGameStateManager::CGameStateManager()
{
	m_pCurrentState = new CLogoState();
	m_pNextState = new CLogoState();
}

// Singleton
CGameStateManager* CGameStateManager::s_pInstance = 0;
CGameStateManager* CGameStateManager::GetInstance()
{
	if (!s_pInstance){
		s_pInstance = new CGameStateManager();
	}
	return s_pInstance;
}

// Init game state manager
void CGameStateManager::Init(HINSTANCE _hInstance, HWND _wndHandler, CGraphic* _graphic, CInput* _input)
{
	m_hInstance = _hInstance;
	m_wndHandler = _wndHandler;
	m_graphic = _graphic;
	m_input = _input;
	
	//D3DXCreateSprite(m_graphic->Get_pd3ddevice(), &m_spriteHandler);

}

// Update state
void CGameStateManager::Update(bool check)
{
	// check if need switch state
	if (m_pCurrentState != m_pNextState)
	{
		if (m_pCurrentState) 
		{
			m_pCurrentState->Exit();
			delete m_pCurrentState;
		}
		if (m_pNextState) 
		{
			m_pNextState->Init(this);
		}
		m_pCurrentState = m_pNextState;
	}

	//update state
	if (m_pCurrentState)
	{
		if (!check)
		{
			m_pCurrentState->Update(m_input, m_time);
		}
		m_pCurrentState->Render(m_spriteHandler);
	}
}

// Switch state
void CGameStateManager::SwitchState(CGameState* nextState)
{
	m_pNextState = nextState;
}

// Get screen width / height
int CGameStateManager::GetScreenWidth()
{
	return SCREEN_WIDTH;
}
int CGameStateManager::GetScreenHeight()
{
	return SCREEN_HEIGHT;
}