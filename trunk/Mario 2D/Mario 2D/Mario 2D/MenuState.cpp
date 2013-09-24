#include "MenuState.h"

CMenuState::CMenuState() : CGameState()
{
}

CMenuState::~CMenuState()
{
}

void CMenuState::Init(CGameApps* _game)
{
	CGameState::Init(_game);
}

void CMenuState::Render(LPD3DXSPRITE _spriteHandler)
{
	CGameState::Render(_spriteHandler);
}

void CMenuState::Update(CInput* _input, float _gameTime)
{
	CGameState::Update(_input, _gameTime);
}

void CMenuState::Exit()
{
	CGameState::Exit();
}

GameStateID CMenuState::GetGameStateID()
{
	return GAME_MENU;
}