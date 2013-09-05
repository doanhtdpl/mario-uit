#include "MenuState.h"


CMenuState::CMenuState(void)
{
}

void CMenuState::Init(CGameStateManager* _game)
{
	CGameState::Init(_game);

	m_sound = CResourceManager::GetAudio();
	m_sound->LoopSound(CResourceManager::GetInstance()->GetSound(SOUND_MENU_ID));
	
	m_menuItemsNumber = 1;
	
	m_background = CResourceManager::GetInstance()->GetResouce(MAP_ID);
	m_menu_select = CResourceManager::GetInstance()->GetResouce(MENU_SELECT_ID);
	m_menu_title = CResourceManager::GetInstance()->GetResouce(MENU_TITLE_ID);
	m_menu_newgame = CResourceManager::GetInstance()->GetResouce(MENU_NEWGAME_ID);
	m_menu_continue = CResourceManager::GetInstance()->GetResouce(MENU_CONTINUE_ID);
	m_menu_options = CResourceManager::GetInstance()->GetResouce(MENU_OPTIONS_ID);
	m_menu_about = CResourceManager::GetInstance()->GetResouce(MENU_ABOUT_ID);
	m_menu_exit = CResourceManager::GetInstance()->GetResouce(MENU_EXIT_ID);

	InitMenuItemsRect(); 
	m_menuItems.push_back(m_menu_newgame);
	m_menuItems.push_back(m_menu_continue);
	m_menuItems.push_back(m_menu_options);
	m_menuItems.push_back(m_menu_about);
	m_menuItems.push_back(m_menu_exit);
	
	m_time = 0.0f;
	
}

void CMenuState::Exit()
{
	delete m_menu_select;
	delete m_menu_title;
	delete m_menu_newgame;
	delete m_menu_continue;
	delete m_menu_options;
	delete m_menu_exit;
	delete m_menu_about;
	CGameState::Exit();
}


void CMenuState::Render(LPD3DXSPRITE _spriteHandler)
{
	if (!m_isQuit)
	{
		m_background->Render(_spriteHandler);
		RenderSelect(_spriteHandler);
		RenderLogo(_spriteHandler);
		RenderMenuItems(_spriteHandler);
	}
	CGameState::Render(_spriteHandler);
}
void CMenuState::RenderSelect(LPD3DXSPRITE _spriteHandler)
{
	switch(m_menuItemsNumber)
	{
		case MENU_NEWGAME_NUMBER:
			m_menu_select->Render(_spriteHandler,D3DXVECTOR2(m_menu_newgame_rect.left-m_menu_select->GetFrameWidth(),m_menu_newgame_rect.top));
			break;
		case MENU_CONTINUE_NUMBER:
			m_menu_select->Render(_spriteHandler,D3DXVECTOR2(m_menu_continue_rect.left-m_menu_select->GetFrameWidth(),m_menu_continue_rect.top));
			break;
		case MENU_OPTIONS_NUMBER:
			m_menu_select->Render(_spriteHandler,D3DXVECTOR2(m_menu_options_rect.left-m_menu_select->GetFrameWidth(),m_menu_options_rect.top));
			break;
		case MENU_ABOUT_NUMBER:
			m_menu_select->Render(_spriteHandler,D3DXVECTOR2(m_menu_about_rect.left-m_menu_select->GetFrameWidth(),m_menu_about_rect.top));
			break;
		case MENU_EXIT_NUMBER:
			m_menu_select->Render(_spriteHandler,D3DXVECTOR2(m_menu_exit_rect.left-m_menu_select->GetFrameWidth(),m_menu_exit_rect.top));
			break;
		default:
			break;
	}
}
void CMenuState::RenderLogo(LPD3DXSPRITE _spriteHandler)
{
	m_menu_title->Render(_spriteHandler,D3DXVECTOR2(m_menu_title_rect.left,m_menu_title_rect.top));
}

void CMenuState::RenderMenuItems(LPD3DXSPRITE _spriteHandler)
{
	m_menu_newgame->Render(_spriteHandler,D3DXVECTOR2(m_menu_newgame_rect.left,m_menu_newgame_rect.top));
	m_menu_continue->Render(_spriteHandler,D3DXVECTOR2(m_menu_continue_rect.left,m_menu_continue_rect.top));
	m_menu_options->Render(_spriteHandler,D3DXVECTOR2(m_menu_options_rect.left,m_menu_options_rect.top));
	m_menu_about->Render(_spriteHandler,D3DXVECTOR2(m_menu_about_rect.left,m_menu_about_rect.top));
	m_menu_exit->Render(_spriteHandler,D3DXVECTOR2(m_menu_exit_rect.left,m_menu_exit_rect.top));
}

void CMenuState::InitMenuItemsRect()
{
	D3DXVECTOR2 ratioScreen = D3DXVECTOR2(m_game->GetScreenWidth()/2, m_game->GetScreenHeight()/30);
	InitMenuItemRect(ratioScreen,D3DXVECTOR2(2,MENU_TITLE_RATIO),m_menu_title,m_menu_title_rect);
	InitMenuItemRect(ratioScreen,D3DXVECTOR2(2,MENU_NEWGAME_RATIO),m_menu_newgame,m_menu_newgame_rect);
	InitMenuItemRect(ratioScreen,D3DXVECTOR2(2,MENU_CONTINUE_RATIO),m_menu_continue,m_menu_continue_rect);
	InitMenuItemRect(ratioScreen,D3DXVECTOR2(2,MENU_OPTIONS_RATIO),m_menu_options,m_menu_options_rect);
	InitMenuItemRect(ratioScreen,D3DXVECTOR2(2,MENU_ABOUT_RATIO),m_menu_about,m_menu_about_rect);
	InitMenuItemRect(ratioScreen,D3DXVECTOR2(2,MENU_EXIT_RATIO),m_menu_exit,m_menu_exit_rect);
}

void CMenuState::InitMenuItemRect( D3DXVECTOR2 _ratioScreen,D3DXVECTOR2 _rationMenuItem,CSprite* _menuItem,RECT &_rect)
{
	_rect.top = _ratioScreen.y*_rationMenuItem.y;
	_rect.left = _ratioScreen.x - _menuItem->GetFrameWidth()/_rationMenuItem.x;
	_rect.bottom =  _rect.top + _menuItem->GetFrameHeight();
	_rect.right =  _rect.left + _menuItem->GetFrameWidth();
}
void CMenuState::Update(CInput* _input,float _gameTime)
{
	m_background->Update(_gameTime,1);
	m_menu_select->Update(_gameTime,1);
	m_menu_title->Update(_gameTime,1);
	for(int i=0;i<m_menuItems.size();i++)
	{
		m_menuItems[i]->Update(_gameTime,-1);
	}
	switch (m_menuItemsNumber)
	{
		case MENU_NEWGAME_NUMBER:
			SetMenuItemsCurrentFrame(MENU_NEWGAME_NUMBER,m_menuItems);
			break;
		case MENU_CONTINUE_NUMBER:
			SetMenuItemsCurrentFrame(MENU_CONTINUE_NUMBER,m_menuItems);
			break;
		case MENU_OPTIONS_NUMBER:
			SetMenuItemsCurrentFrame(MENU_OPTIONS_NUMBER,m_menuItems);
			break;
		case MENU_ABOUT_NUMBER:
			SetMenuItemsCurrentFrame(MENU_ABOUT_NUMBER,m_menuItems);
			break;
		case MENU_EXIT_NUMBER:
			SetMenuItemsCurrentFrame(MENU_EXIT_NUMBER,m_menuItems);
			break;
		default:
			break;
	}
	
	m_time+=_gameTime;
	if(m_time>=1.05f)
	{
		m_time=0;
		if(_input->KeyDown(DIK_DOWN))
		{
			if(m_menuItemsNumber <5)
			{
				m_menuItemsNumber ++;
			}
			else if(m_menuItemsNumber ==5)
			{
				m_menuItemsNumber = 1;
			}
		}
		if(_input->KeyDown(DIK_UP))
		{
			if(m_menuItemsNumber > 1)
			{
				m_menuItemsNumber --;
			}
			else if(m_menuItemsNumber == 1)
			{
				m_menuItemsNumber = 5;
			}
		}
	}
	//Kiểm tra Enter vào State được chọn
	if(_input->KeyDown(DIK_RETURN))
	{
		switch (m_menuItemsNumber)
		{
			case MENU_NEWGAME_NUMBER:
				m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_MENU_ID));
				CGameStateManager::GetInstance()->SwitchState(new CMenuState());
				m_isQuit = true;
				break;
			/*case MENU_CONTINUE_NUMBER:
				SetGameStateId(CONTINUE_STATE);
				break;
				case MENU_OPTIONS_NUMBER:
				SetGameStateId(OPTIONS_STATE);
				break;
			case MENU_HIGHSCORE_NUMBER:
				setGameStateId(HIGHSCORE_STATE);
				break;
			case MENU_ABOUT_NUMBER:
				setGameStateId(ABOUT_STATE);
				break;*/
			case MENU_EXIT_NUMBER:
				PostQuitMessage(0);
				break;
			default:
				break;
		}
	}
	CGameState::Update(_input,_gameTime);
}
void CMenuState::SetMenuItemsCurrentFrame(int frameNumber,vector<CSprite *> &menuItems)
{
	for(int i=0;i<menuItems.size();i++)
	{
		if(i==frameNumber -1)
			menuItems[i]->SetCurrentFrame(1);
		else 
			menuItems[i]->SetCurrentFrame(0);
	}
}
GameStateID CMenuState::GetGameStateID()
{
	return GAME_MENU;
}
CMenuState::~CMenuState(void)
{
}
