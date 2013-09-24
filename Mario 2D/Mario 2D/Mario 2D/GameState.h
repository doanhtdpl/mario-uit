#ifndef GAME_STATE__H
#define GAME_STATE__H

#include <d3d9.h>
#include <d3dx9.h>
#include "GameApps.h"
#include "Input.h"
#include "Camera.h"
#include "Sprite.h"

class CGameApps;

// State game ID
enum GameStateID
{
	GAME_LOGO,
	GAME_START,
	GAME_MENU,
	GAME_PLAY,
	GAME_PAUSE,
	GAME_CONTINUE,
	GAME_OPTIONS,
	GAME_INSTRUCTION,
	GAME_EXIT
};

class CGameState
{	
protected:
	CGameApps*		m_game;
	GameStateID		m_id;
	CSprite*		m_background;
	LPD3DXSPRITE	m_spriteHandler;
	CInput*			m_input;
	// Timer
	float m_time;

public:
	CGameState();
	~CGameState();
	
	virtual void Init(CGameApps*);
	virtual void Render(LPD3DXSPRITE);
	virtual void Update(CInput*, float);
	virtual void Exit();

	virtual GameStateID GetGameStateID();
};

#endif