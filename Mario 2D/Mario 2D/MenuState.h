#ifndef MENU_STATE__H
#define MENU_STATE__H

#include "GameState.h"
#include "ResourceManager.h"
#include "Sprite.h"
#include "PlayingState.h"
#include "Audio.h"
#include <vector>

//Tỉ lệ vẽ menu items
#define MENU_TITLE_RATIO 3
#define MENU_NEWGAME_RATIO 12
#define MENU_CONTINUE_RATIO 15
#define MENU_OPTIONS_RATIO 18
#define MENU_ABOUT_RATIO 21
#define MENU_EXIT_RATIO 24

//Định số cho mỗi menu items để xử lý keyboard
#define MENU_NEWGAME_NUMBER 1
#define MENU_CONTINUE_NUMBER 2
#define MENU_OPTIONS_NUMBER 3
#define MENU_ABOUT_NUMBER 4
#define MENU_EXIT_NUMBER 5

class CMenuState :
	public CGameState
{
protected:
	CSprite* m_menu_select;
	CSprite* m_menu_title;
	CSprite *m_menu_newgame;
	CSprite *m_menu_continue;
	CSprite *m_menu_options;
	CSprite *m_menu_exit;
	CSprite *m_menu_about;
	
	//Tạo vùng vẽ các menuItems lên màn hình
	RECT m_menu_background_rect;
	RECT m_menu_title_rect;
	RECT m_menu_newgame_rect;
	RECT m_menu_continue_rect;
	RECT m_menu_options_rect;
	RECT m_menu_about_rect;
	RECT m_menu_exit_rect;

	//Biến lưu thứ tự menu items
	int m_menuItemsNumber;
	vector<CSprite *> m_menuItems;

	//Sounds

	CAudio *m_sound;
public:
	CMenuState(void);

	virtual ~CMenuState(void);
	void Init(CGameStateManager*);
	void Update(CInput*, float);
	
	void Render(LPD3DXSPRITE);
	void RenderSelect(LPD3DXSPRITE);
	void RenderMenuItems(LPD3DXSPRITE);
	void RenderLogo(LPD3DXSPRITE);

	void Exit();

	void InitMenuItemsRect();
	void InitMenuItemRect(D3DXVECTOR2,D3DXVECTOR2,CSprite*,RECT&);
	void SetMenuItemsCurrentFrame(int frameNumber,vector<CSprite*> &menuItems);
	
	GameStateID GetGameStateID();
};
#endif

