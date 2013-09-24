#ifndef MENU_STATE__H
#define MENU_STATE__H

#include "GameState.h"
#include "Sprite.h"
#include "ResourceManager.h"
#include "Audio.h"

class GameState;
class CMenuState : public CGameState
{
private:
	CAudio* m_audio;
public:
	CMenuState(void);
	~CMenuState(void);

	void Init(CGameApps*);
	void Render(LPD3DXSPRITE _spriteHandler);
	void Update(CInput*, float);
	void Exit();

	GameStateID GetGameStateID();
};

#endif