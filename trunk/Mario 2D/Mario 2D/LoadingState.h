#ifndef LOADING_STATE__H
#define LOADING_STATE__H

#include "GameState.h"
#include "Sprite.h"
#include "ResourceManager.h"
#include "MenuState.h"
#include "Audio.h"

class CGameState;
class CLoadingState: public CGameState
{
protected:
	CAudio* m_sound;
public:
	CLoadingState(void);
	~CLoadingState();

	void Init(CGameStateManager*);
	void Render(LPD3DXSPRITE);
	void Update(CInput*, float);
	void Exit();

	GameStateID GetGameStateID();
};
#endif


