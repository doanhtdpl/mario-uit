#include "LoadingState.h"
#include <iostream>
using namespace std;


CLoadingState::CLoadingState(void) : CGameState()
{
}

CLoadingState::~CLoadingState()
{
}

void CLoadingState::Init(CGameStateManager* _game)
{
	CGameState::Init(_game);
	m_background = CResourceManager::GetInstance()->GetResouce(MAP_ID);
	m_time = 0.0f;
	m_sound = CResourceManager::GetAudio();
	m_sound->PlaySound(CResourceManager::GetInstance()->GetSound(SOUND_LOADING_ID));
	
}


void CLoadingState::Render(LPD3DXSPRITE _spriteHandler)
{
	cout<<"\nLoading State";
	if (!m_isQuit)
	{
		m_background->Render(_spriteHandler);
	}
	CGameState::Render(_spriteHandler);
}

void CLoadingState::Update(CInput* _input, float _gameTime)
{
	cout<<"\nUpdate Loading State";
	CGameState::Update(_input , _gameTime);

	m_background->SetCurrentFrame(0);
	m_background->SetTimeAnimation(0);
	m_background->Update(0,1);
	
	m_time += _gameTime;
	if (m_time >= 10.0f)
	{
		CGameStateManager::GetInstance()->SwitchState(new CMenuState());
		m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_LOADING_ID));
		m_isQuit = true;
	}
}

void CLoadingState::Exit()
{
	delete m_sound;
	delete m_background;
	CGameState::Exit();
}

GameStateID CLoadingState::GetGameStateID()
{
	return GAME_START;
}