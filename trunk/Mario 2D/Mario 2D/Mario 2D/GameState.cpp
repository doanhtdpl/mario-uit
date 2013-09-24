#include "GameState.h"


CGameState::CGameState()
{

}

void CGameState::Init(CGameApps* _game)
{
	m_game = _game;
	m_game->m_isAlived = true;
	m_time = 0.0f;
	m_background = NULL;
}

void CGameState::Render(LPD3DXSPRITE _spriteHandler)
{

}

void CGameState::Update(CInput* _input, float _time)
{

}

void CGameState::Exit()
{

}

GameStateID CGameState::GetGameStateID()
{
	return this->m_id;
}

CGameState::~CGameState()
{
}

