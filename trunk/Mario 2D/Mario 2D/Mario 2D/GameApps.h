#ifndef GAME_APPS__H
#define GAME_APPS__H

#include <d3d9.h>
#include <d3dx9.h>
#include "FPS.h"
#include "Input.h"
#include "Camera.h"
#include "Graphic.h"
#include "Register.h"
#include "GameStateManager.h"

#define TIME_DELAY	80

class CGameStateManager;
class CGameApps
{
protected:
	CFps*				m_fps;
	CInput*				m_input;
	CCamera*			m_camera;
	CGraphic*			m_graphic;
	CRegister*			m_register;
	CGameStateManager*	m_gamestatemanager;
public:
	bool m_isAlived;
	bool m_isPaused;
	LPD3DXSPRITE m_spriteHandler;
	CGameApps();
	~CGameApps();

#pragma region Main methods
	int Game_Init(HINSTANCE);
	int Game_Destroy();
	// ========================
	void Game_Run();
	void Game_Pause();
	void Game_Resume();
	void Game_Exit();
#pragma endregion Main methods
	
	bool IsAlive();
	bool IsPause();

};

#endif

