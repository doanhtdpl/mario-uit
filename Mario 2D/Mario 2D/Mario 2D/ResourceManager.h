#ifndef RESOURCE_MANAGER__H
#define RESOURCE_MANAGER__H

#include "Texture.h"
#include "Sprite.h"
#include "ResourcePath.h"
#include "Audio.h"

// Define ID for each resource
enum ResourceID
{
	//Game Objects
	MARIOBIG_ID,
	MARIOSMALL_ID,
	MARIOGUN_ID,
	MUSHROOM_ID,
	BRICK_ID,
	BRICKBREAK_ID,
	
	QUESTIONBOX_ID,
	MAP_ID,
	//BG_ID,
	MUSHROOMBIG_ID,
	TURTLE_ID,
	COIN_ID,
	STAR_ID,
	FLOWER_ID,
	LIFEUP_ID,
	LAND_ID,
	TURTLESHIELD_ID,
	SMALLPIPE_ID,
	MEDIUMPIPE_ID,
	BIGPIPE_ID,
	CLOUD_ID,
	FENCE_ID,
	GRASS_ID,
	MOUNTAIN_ID,
	BIG_TREE_ID,
	SMALL_TREE_ID,
	END_COLUMN_ID,
	END_MARK_ID,
	LADDER_ID,

	//Menu
	MENU_SELECT_ID,
	MENU_TITLE_ID,
	MENU_NEWGAME_ID,
	MENU_CONTINUE_ID,
	MENU_OPTIONS_ID,
	MENU_ABOUT_ID,
	MENU_EXIT_ID,

	//Sounds
	SOUND_ABOUT_ID,
	SOUND_BRICKBREAK_ID,
	SOUND_BRICKSLIDE_ID,
	SOUND_COIN_ID,
	SOUND_DEATH_ID,
	SOUND_ITEMUP_ID,
	SOUND_JUMP_ID,
	SOUND_LIFEUP_ID,
	SOUND_LOADING_ID,
	SOUND_LOSE_ID,
	SOUND_MAP1_ID,
	SOUND_MAP2_ID,
	SOUND_MARIOGROW_ID,
	SOUND_MARIOKICK_ID,
	SOUND_MENU_ID,
	SOUND_MUSHROOMDIE_ID,
	SOUND_OPTIONS_ID,
	SOUND_POWERUP_ID,
	SOUND_SHOTTED_ID,
	SOUND_SLIDEPIPE_ID,
	SOUND_STARTGAME_ID,
	SOUND_TURTLEHEAD_ID,
	SOUND_WIN_ID
};

class CResourceManager
{
public:
#pragma region Parameters declaration
//=================|| Singleton ||===================//
	static CResourceManager* m_pInstance;
	static CAudio* m_Audio;

	static LPDIRECT3DDEVICE9 m_pd3ddevice;
	static HWND  m_wndHandle;

//===================||Texture ||====================//
	CTexture *m_texture;

//=====================|| Map ||=====================//
	CSprite *m_mapBackground;
	//CSprite *m_bg;
	CSprite *m_cloud;
	CSprite *m_fence;
	CSprite *m_grass;
	CSprite *m_mountain;
	CSprite *m_bigTree;
	CSprite *m_smallTree;
	CSprite *m_endColumn;
	CSprite *m_endMark;
	CSprite *m_ladder;
	
	
//===================|| Objects ||===================//
	// Mario
	CSprite *m_marioBig;
	CSprite *m_marioSmall;
	CSprite *m_marioGun;
	
	// Mushroom
	CSprite *m_mushroom;
	CSprite *m_mushroomBig;
	CSprite *m_lifeup;
	
	// Brick
	CSprite *m_brick;
	CSprite *m_brickBreak;
	
	// Pipe
	CSprite *m_smallPipe;
	CSprite *m_mediumPipe;
	CSprite *m_bigPipe;
	
	// Question Box
	CSprite *m_questionBox;
	
	// Turtle
	CSprite *m_turtle;
	CSprite *m_turtleShield;
	
	// Coin
	CSprite *m_coin;
	
	// Star
	CSprite *m_star;
	
	// Flower
	CSprite *m_flower;
	
	// Land
	CSprite *m_land;
	
//====================|| Menu ||======================//
	// Select
	CSprite *m_menu_select;
	
	// Title
	CSprite *m_menu_title;
	
	// New game
	CSprite *m_menu_newgame;
	
	// Continue
	CSprite *m_menu_continue;
	
	// Option
	CSprite *m_menu_options;
	
	// Exit
	CSprite *m_menu_exit;
	
	// About
	CSprite *m_menu_about;
	
//====================|| Audio ||=====================//
	// Start game
	CSound * m_soundStartGame;
	
	// Loading
	CSound * m_soundLoading;
	
	// Menu
	CSound * m_soundMenu;
	
	// Option
	CSound * m_soundOptions;

	// Lose
	CSound * m_soundLose;

	// Win
	CSound * m_soundWin;

	// About
	CSound * m_soundAbout;
	
	// Brick
	CSound * m_soundBrickBreak;
	CSound * m_soundBrickSlide;
	
	// Coin
	CSound * m_soundCoin;
	
	// Mario
	CSound * m_soundDeath;
	CSound * m_soundItemUp;
	CSound * m_soundJump;
	CSound * m_soundMarioGrow;
	CSound * m_soundMarioKick;
	CSound * m_soundPowerUp;
	CSound * m_soundShotted;

	// Mushroom
	CSound * m_soundLifeUp;
	CSound * m_soundMushroomDie;

	// Turtle head kick
	CSound * m_soundTurtleHead;
	
	// Map
	CSound * m_soundMap1;
	CSound * m_soundMap2;
	
	// Slide pipe
	CSound * m_soundSlidePipe;
#pragma endregion
	
public:
	// Constructor
	CResourceManager(void);
	
	// Destructor
	~CResourceManager(void);

	// Singleton
	static CResourceManager* GetInstance();
	static CAudio* GetAudio();

	// Init device, windows handler
	bool Init(LPDIRECT3DDEVICE9, HWND);

	// Get resource, sound
	CSprite* GetResouce(ResourceID);
	CSound* GetSound(ResourceID);
};

#endif