#include "LogoState.h"


CLogoState::CLogoState() : CGameState()
{
}

CLogoState::~CLogoState()
{
}

void CLogoState::Init(CGameApps* _game)
{
	CGameState::Init(_game);
	m_menuState = new CMenuState();
	m_background = CResourceManager::GetInstance()->GetResouce(MAP_ID);
	m_time = 0.0f;
	m_sound = CResourceManager::GetAudio();
	m_sound->PlaySound(CResourceManager::GetInstance()->GetSound(SOUND_LOADING_ID));
}

void CLogoState::Render(LPD3DXSPRITE _spriteHandler)
{
	if (m_game->m_isAlived == true)
	{
		m_background->Render(_spriteHandler);
	}
	CGameState::Render(_spriteHandler);
}

void CLogoState::Update(CInput* _input, float _gameTime)
{
	CGameState::Update(_input , _gameTime);

	m_background->SetCurrentFrame(0);
	m_background->SetTimeAnimation(0);
	m_background->Update(0,1);
	//
	m_time += _gameTime;
	if (m_time >= 10.0f)
	{
		CGameStateManager::GetInstance()->SwitchState(m_menuState);
		m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_LOADING_ID));
		m_game->m_isAlived = true;
	}
}

void CLogoState::Exit()
{
	delete m_sound;
	delete m_background;
	CGameState::Exit();
}

GameStateID CLogoState::GetGameStateID()
{
	return GAME_LOGO;
}