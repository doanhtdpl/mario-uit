#ifndef LOGO_STATE__H
#define LOGO_STATE__H

#include "GameState.h"
#include "Sprite.h"
#include "ResourceManager.h"
#include "Audio.h"
#include "LoadingState.h"

class CGameState;
class CLogoState : public CGameState
{
protected:
	CAudio* m_sound;
public:
	CLogoState(void);
	~CLogoState(void);
	
	void Init(CGameStateManager*);
	void Render(LPD3DXSPRITE _spriteHandler);
	void Update(CInput*, float);
	void Exit();

	GameStateID GetGameStateID();
};
#endif


