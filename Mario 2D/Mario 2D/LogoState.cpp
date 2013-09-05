#include "LogoState.h"
#include <iostream>
using namespace std;


CLogoState::CLogoState() : CGameState()
{
}

CLogoState::~CLogoState()
{
}

void CLogoState::Init(CGameStateManager* _game)
{
	cout<<"\nLogo State: Init";
	CGameState::Init(_game);
	//m_bg = CResourceManager::GetInstance()->GetResouce(BG_ID);
//	m_time = 0.0f;
//	m_sound = CResourceManager::GetAudio();
//	m_sound->PlaySound(CResourceManager::GetInstance()->GetSound(SOUND_LOADING_ID));
}

void CLogoState::Render(LPD3DXSPRITE _spriteHandler)
{
	cout<<"\nLogo State: Render";
	//if (!m_isQuit)
	//{
	//	//m_bg->Render(_spriteHandler);
	//}
	CGameState::Render(_spriteHandler);
}

void CLogoState::Update(CInput* _input, float _gameTime)
{
	cout<<"\nLogo State: Update";
	CGameState::Update(_input , _gameTime);

	//m_bg->SetCurrentFrame(0);
	//m_bg->SetTimeAnimation(0);
	//m_bg->Update(0,1);
	//
	//m_time += _gameTime;
	//if (m_time >= 10.0f)
	//{
	//	CGameStateManager::GetInstance()->SwitchState(new CLoadingState());
	//	m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_LOADING_ID));
	//	m_isQuit = true;
	//}
}

void CLogoState::Exit()
{
	//delete m_sound;
	//delete m_bg;
	//delete m_background;
	CGameState::Exit();
}

GameStateID CLogoState::GetGameStateID()
{
	return GAME_LOGO;
}