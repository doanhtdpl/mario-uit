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
	bool m_isAlived;
	bool m_isPaused;

	CFps*				m_fps;
	CInput*				m_input;
	CCamera*			m_camera;
	CGraphic*			m_graphic;
	CRegister*			m_register;
	CGameStateManager*	m_gamestatemanager;
public:
	LPD3DXSPRITE m_spriteHandler;

	CGameApps();
	~CGameApps();

// Main methods
	int Init(HINSTANCE);
	void Destroy();
	void Run();
	void Pause();
	void Resume();
	void Exit();
// End main methods
	
	bool IsAlive();
	bool IsPause();

};

#endif

