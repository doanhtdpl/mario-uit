#ifndef	GAME_STATE_MANAGER__H
#define GAME_STATE_MANAGER__H

#include "GameApps.h"
#include "GameState.h"

class CGameState;
class CGameApps;

class CGameStateManager
{
public:
	CGameApps*	m_game;
	// Init next/current state
	CGameState* m_pCurrentState;
	CGameState* m_pNextState;

public:
	// Constructor
	CGameStateManager();

	// Transmission parameter
	HINSTANCE		m_hInstance;
	HWND			m_wndHandler;
	CGraphic*		m_graphic;
	CInput*			m_input;
	LPD3DXSPRITE	m_spriteHandler;

	float m_time;

	// Singleton
	static CGameStateManager* s_pInstance;
	static CGameStateManager* GetInstance();

	// Init
	void Init(CGameApps*, HINSTANCE, HWND, CGraphic*, CInput*, LPD3DXSPRITE);
	
	// Update/Switch state
	void Update(bool check);
	void SwitchState(CGameState*);

	// Get screen size
	int GetScreenWidth();
	int GetScreenHeight();
};

#endif