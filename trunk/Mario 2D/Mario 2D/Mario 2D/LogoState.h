#ifndef LOGO_STATE__H
#define LOGO_STATE__H

#include "GameState.h"
#include "Sprite.h"
#include "ResourceManager.h"
#include "Audio.h"
#include "MenuState.h"

class CGameState;
class CLogoState : public CGameState
{
protected:
	CAudio*		m_sound;
	CMenuState* m_menuState;
public:
	CLogoState(void);
	~CLogoState(void);
	
	void Init(CGameApps*);
	void Render(LPD3DXSPRITE _spriteHandler);
	void Update(CInput*, float);
	void Exit();

	GameStateID GetGameStateID();
};
#endif


