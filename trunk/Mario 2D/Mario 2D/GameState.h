#ifndef GAME_STATE__H
#define GAME_STATE__H

#include <d3d9.h>
#include <d3dx9.h>
#include "GameStateManager.h"
#include "Input.h"
#include "Camera.h"
#include "Sprite.h"

class CGameStateManager;

// State game ID
enum GameStateID
{
	GAME_LOGO,
	GAME_START,
	GAME_MENU,
	GAME_PLAY,
	GAME_CONTINUE,
	GAME_OPTIONS,
	GAME_EXIT
};

class CGameState
{	
protected:
	CGameStateManager* m_game;
	GameStateID m_id;
	CSprite* m_background;
	//CSprite* m_bg;
	LPD3DXSPRITE m_spriteHandler;
	CInput* m_input;
	
	float m_time;
	bool m_isQuit;
public:
	CGameState();
	~CGameState();
	
	virtual void Init(CGameStateManager*);
	virtual void Render(LPD3DXSPRITE);
	virtual void Update(CInput*, float);
	virtual void Exit();

	virtual GameStateID GetGameStateID();
};

#endif