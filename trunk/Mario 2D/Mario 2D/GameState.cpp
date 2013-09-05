#include "GameState.h"


CGameState::CGameState()
{

}

void CGameState::Init(CGameStateManager* _game)
{
	m_game = _game;
	m_isQuit = false;
	m_time = 0.0f;
	m_background = NULL;
	//m_bg = NULL;
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

