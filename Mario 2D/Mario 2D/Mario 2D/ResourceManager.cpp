#include "ResourceManager.h"


CResourceManager* CResourceManager::m_pInstance = 0;
LPDIRECT3DDEVICE9 CResourceManager::m_pd3ddevice = 0;
HWND CResourceManager::m_wndHandle = 0;
CAudio* CResourceManager::m_Audio = 0;

// Constructor
CResourceManager::CResourceManager()
{
//==============================|| Init sprite ||=================================//
	// Mario
	m_marioBig = new CSprite(0, 50, 10, 235, 180, 5);
	m_marioSmall = new CSprite(0 , 50 , 12 , 282 , 120 , 6);
	m_marioGun = new CSprite(0, 50, 10, 235, 180, 5);
	
	// Mushroom
	m_mushroom = new CSprite(0 , 0, 4, 124, 31, 4);
	m_mushroomBig = new CSprite(0, 0 , 8 , 200, 100, 4);
	m_lifeup = new CSprite(0, 0 , 8 , 200, 100, 4);

	// Question Box
	m_questionBox = new CSprite(0, 0 , 3, 150, 50, 3 );
	
	// Brick
	m_brick = new CSprite(0, 0, 1 , 50, 50, 1);
	m_brickBreak = new CSprite( 0 ,0 ,1, 25 ,25 , 1);
	
	// Pipe
	m_smallPipe = new CSprite(0, 0, 1, 75, 100, 1);
	m_mediumPipe = new CSprite(0, 0, 1, 75, 150, 1);
	m_bigPipe = new CSprite( 0, 0, 1, 74, 198, 1 );
	
	// Turtle
	m_turtle = new CSprite(0, 0, 4, 63 , 94 , 2);
	m_turtleShield = new CSprite(0, 0, 3, 99, 29, 3);
	
	// Coin
	m_coin = new CSprite (0, 0, 7, 315, 50, 7);
	
	// Star
	m_star = new CSprite (0, 0, 12, 99, 128, 3);
	
	// Flower
	m_flower = new CSprite (0, 0, 4, 200, 50, 4);
	
	
//=============================|| Background ||=================================//
	// Map
	m_mapBackground = new CSprite(0, 0, 1, 3840, 1080, 1);
	
	// Land
	m_land = new CSprite( 0,0 , 2, 100, 50, 2);
	
	// Cloud
	m_cloud = new CSprite(0,0,2,128,50,2);
	
	// Fence
	m_fence = new CSprite(0,0,1,141,32,1);
	
	// Grass
	m_grass = new CSprite(0,0,2,128,29,2);
	
	// Mountain
	m_mountain = new CSprite(0,0,1,311,127,1);
	
	// Tree
	m_bigTree = new CSprite(0,0,1,31,90,1);
	m_smallTree = new CSprite(0,0,1,27,60,1);
	
	// Finish
	m_endColumn = new CSprite(0,0,1,102,288,1);
	m_endMark = new CSprite(0,0,1,31,32,1);
	m_ladder = new CSprite(0,0,1,46,17,1);

//===============================|| Menu ||=================================//
	// Select
	m_menu_select = new CSprite(0,0,1,51,50,1);
	
	// Tile
	m_menu_title = new CSprite( 0, 0, 1, 300, 100 , 1);
	
	// New Game
	m_menu_newgame = new CSprite( 0, 0, 2, 428, 50 , 2);
	
	// Continue
	m_menu_continue = new CSprite( 0, 0, 2, 420, 50 , 2);
	
	// Option
	m_menu_options = new CSprite( 0, 0, 2, 374, 50 , 2);
	
	// About
	m_menu_about = new CSprite( 0, 0, 2, 302, 50, 2);
	
	// Exit
	m_menu_exit = new CSprite( 0, 0, 2, 218, 50, 2);
}

// Init resource
bool CResourceManager::Init(LPDIRECT3DDEVICE9 _pd3ddevice, HWND _wndHandle)
{
	m_pd3ddevice = _pd3ddevice;
	m_wndHandle = _wndHandle;
//==============================|| Texture ||==============================//
	m_texture = new CTexture(m_pd3ddevice);
	if (m_texture == NULL)
	{
		return false;
	}
//===============================|| Audio ||===============================//
	m_Audio = new CAudio(m_wndHandle);
	if (m_Audio == NULL)
	{
		return false;
	}

//==============================|| Objects ||==============================//
	// Mario
	m_marioBig->Init(m_texture->GetTexture(MARIO_BIG));
	m_marioSmall->Init(m_texture->GetTexture(MARIO_SMALL));
	m_marioGun->Init(m_texture->GetTexture(MARIO_GUN));
	
	// Mushroom
	m_mushroom->Init(m_texture->GetTexture(MUSHROOM));
	m_mushroomBig->Init(m_texture->GetTexture(MUSHROOMBIG));
	m_lifeup->Init(m_texture->GetTexture(MUSHROOMBIG));

	// Question Box
	m_questionBox->Init(m_texture->GetTexture(QUESTIONBOX));
	
	// Brick
	m_brick->Init(m_texture->GetTexture(BRICK));
	m_brickBreak->Init(m_texture->GetTexture(BRICKBREAK));

	// Pipe
	m_smallPipe->Init(m_texture->GetTexture(SMALLPIPE));
	m_mediumPipe->Init(m_texture->GetTexture(MEDIUMPIPE));
	m_bigPipe->Init(m_texture->GetTexture(BIGPIPE));
	
	// Turtle
	m_turtle->Init(m_texture->GetTexture(TURTLE));
	m_turtleShield->Init(m_texture->GetTexture(TURTLESHIELD));
	
	// Coin
	m_coin->Init(m_texture->GetTexture(COIN));
	
	// Star
	m_star->Init(m_texture->GetTexture(ITEM));
	
	// Flower
	m_flower->Init(m_texture->GetTexture(FLOWER));
	
	
//=============================|| Background ||==============================//
	// Map
	m_mapBackground->Init(m_texture->GetTexture(MAP));

	//// Bg
	//m_bg->Init(m_texture->GetTexture(BG));

	// Land
	m_land->Init(m_texture->GetTexture(LAND));

	// Cloud
	m_cloud->Init(m_texture->GetTexture(CLOUD));
	
	// Fence
	m_fence->Init(m_texture->GetTexture(FENCE));
	
	// Grass
	m_grass->Init(m_texture->GetTexture(GRASS));
	
	// Mountain
	m_mountain->Init(m_texture->GetTexture(MOUNTAIN));
	
	// Tree
	m_bigTree->Init(m_texture->GetTexture(BIG_TREE));
	m_smallTree->Init(m_texture->GetTexture(SMALL_TREE));
	
	// Finish
	m_endColumn->Init(m_texture->GetTexture(END_COLUMN));
	m_endMark->Init(m_texture->GetTexture(END_MARK));
	m_ladder->Init(m_texture->GetTexture(LADDER));

//===============================||Menu ||================================//
	// Select
	m_menu_select->Init(m_texture->GetTexture(MENU_SELECT));
	
	// Title
	m_menu_title->Init(m_texture->GetTexture(MENU_TITLE));
	
	// New game
	m_menu_newgame->Init(m_texture->GetTexture(MENU_NEWGAME));
	
	// Continue
	m_menu_continue->Init(m_texture->GetTexture(MENU_CONTINUE));
	
	// Option
	m_menu_options->Init(m_texture->GetTexture(MENU_OPTIONS));
	
	// About
	m_menu_about->Init(m_texture->GetTexture(MENU_ABOUT));
	
	// Exit
	m_menu_exit->Init(m_texture->GetTexture(MENU_EXIT));

//===============================|| Sounds ||================================//
	// About
	m_soundAbout = m_Audio->LoadSound(SOUND_ABOUT);
	
	// Brick
	m_soundBrickBreak = m_Audio->LoadSound(SOUND_BRICKBREAK);
	m_soundBrickSlide = m_Audio->LoadSound(SOUND_BRICKSLIDE);
	
	// Get coin
	m_soundCoin = m_Audio->LoadSound(SOUND_COIN);
	
	// Item up
	m_soundItemUp = m_Audio->LoadSound(SOUND_ITEMUP);
	
	// Jump
	m_soundJump = m_Audio->LoadSound(SOUND_JUMP);
	
	// Life up
	m_soundLifeUp = m_Audio->LoadSound(SOUND_LIFEUP);
	
	// Loading
	m_soundLoading = m_Audio->LoadSound(SOUND_LOADING);
	
	// Lose
	m_soundLose = m_Audio->LoadSound(SOUND_LOSE);
	
	// Map
	m_soundMap1 = m_Audio->LoadSound(SOUND_MAP1);
	m_soundMap2 = m_Audio->LoadSound(SOUND_MAP2);
	
	// Mario
	m_soundMarioGrow = m_Audio->LoadSound(SOUND_MARIOGROW);
	m_soundMarioKick = m_Audio->LoadSound(SOUND_MARIOKICK);
	m_soundShotted  = m_Audio->LoadSound(SOUND_SHOTTED);
	m_soundPowerUp  = m_Audio->LoadSound(SOUND_POWERUP);
	m_soundDeath = m_Audio->LoadSound(SOUND_DEATH);

	// Menu
	m_soundMenu = m_Audio->LoadSound(SOUND_MENU);
	
	// Option
	m_soundOptions = m_Audio->LoadSound(SOUND_OPTIONS);

	// Mushroom
	m_soundMushroomDie = m_Audio->LoadSound(SOUND_MUSHROOMDIE);
	
	// Slide pipe
	m_soundSlidePipe = m_Audio->LoadSound(SOUND_SLIDEPIPE);
	
	// Start game
	m_soundStartGame = m_Audio->LoadSound(SOUND_STARTGAME);
	
	// Turtle head kick
	m_soundTurtleHead = m_Audio->LoadSound(SOUND_TURTLEHEAD);
	
	// Win
	m_soundWin = m_Audio->LoadSound(SOUND_WIN);

	return true;
}

// Get resource
CSprite* CResourceManager::GetResouce(ResourceID _id)
{
	switch (_id)
	{
	case MARIOBIG_ID:
		{
			return new CSprite(*m_marioBig);
			break;
		}
	case MARIOGUN_ID:
		{
			return new CSprite(*m_marioGun);
			break;
		}
	case MARIOSMALL_ID:
		{
			return new CSprite(*m_marioSmall);
			break;
		}
	case MUSHROOM_ID:
		{
			return new CSprite(*m_mushroom);
			break;
		}
	case QUESTIONBOX_ID:
		{
			return new CSprite(*m_questionBox);
			break;
		}
	case MUSHROOMBIG_ID:
		{
			return new CSprite(*m_mushroomBig);
			break;
		}
	case BRICK_ID:
		{
			return new CSprite(*m_brick);
			break;
		}
	case BRICKBREAK_ID:
		{
			return new CSprite(*m_brickBreak);
			break;
		}
	case SMALLPIPE_ID:
		{
			return new CSprite(*m_smallPipe);
			break;
		}
	case MEDIUMPIPE_ID:
		{
			return new	CSprite(*m_mediumPipe);
			break;
		}
	case BIGPIPE_ID:
		{
			return new CSprite (*m_bigPipe);
			break;
		}
	case CLOUD_ID:
		{
			return new CSprite(*m_cloud);
			break;
		}
	case FENCE_ID:
		{
			return new CSprite(*m_fence);
			break;
		}
	case GRASS_ID:
		{
			return new CSprite(*m_grass);
			break;
		}
	case MOUNTAIN_ID:
		{
			return new CSprite(*m_mountain);
			break;
		}
	case BIG_TREE_ID:
		{
			return new CSprite(*m_bigTree);
			break;
		}
	case SMALL_TREE_ID:
		{
			return new CSprite(*m_smallTree);
			break;
		}
	case END_COLUMN_ID:
		{
			return new CSprite(*m_endColumn);
			break;
		}
	case END_MARK_ID:
		{
			return new CSprite(*m_endMark);
			break;
		}
	case LADDER_ID:
		{
			return new CSprite(*m_ladder);
			break;
		}
	case MAP_ID:
		{
			return new CSprite(*m_mapBackground);
			break;
		}
	//case BG_ID:
	//	{
	//		return new CSprite(*m_bg);
	//		break;
	//	}
	case TURTLE_ID:
		{
			return new CSprite(*m_turtle);
			break;
		}
	case COIN_ID:
		{
			return new CSprite( *m_coin);
			break;
		}
	case STAR_ID:
		{
			return new CSprite(*m_star);
			break;
		}
	case FLOWER_ID:
		{
			return new CSprite(*m_flower);
			break;
		}
	case LIFEUP_ID:
		{
			return new CSprite(*m_lifeup);
			break;
		}
	case LAND_ID:
		{
			return new CSprite(*m_land);
			break;
		}
	case TURTLESHIELD_ID:
		{
			return new CSprite(*m_turtleShield);
			break;
		}
	case MENU_SELECT_ID:
		{
			return new CSprite(*m_menu_select);
			break;
		}
	case MENU_TITLE_ID:
		{
			return new CSprite(*m_menu_title);
			break;
		}
	case MENU_NEWGAME_ID:
		{
			return new CSprite(*m_menu_newgame);
			break;
		}
	case MENU_CONTINUE_ID:
		{
			return new CSprite(*m_menu_continue);
			break;
		}
	case MENU_OPTIONS_ID:
		{
			return new CSprite(*m_menu_options);
			break;
		}
	case MENU_ABOUT_ID:
		{
			return new CSprite(*m_menu_about);
			break;
		}
	case MENU_EXIT_ID:
		{
			return new CSprite(*m_menu_exit);
			break;
		}
	default:
		{
			return NULL;
			break;
		}
	}
}

// Get sound
CSound* CResourceManager::GetSound(ResourceID _resourceID)
{
	switch (_resourceID)
	{
	case SOUND_ABOUT_ID:
		{
			return new CSound( *m_soundAbout);
			break;
		}
	case SOUND_BRICKBREAK_ID:
		{
			return new CSound( *m_soundBrickBreak);
			break;
		}
	case SOUND_BRICKSLIDE_ID:
		{
			return new CSound( *m_soundBrickSlide);
			break;
		}
	case SOUND_COIN_ID:
		{
			return new CSound( *m_soundCoin);
			break;
		}
	case SOUND_DEATH_ID:
		{
			return new CSound( *m_soundDeath);
			break;
		}
	case SOUND_ITEMUP_ID:
		{
			return new CSound( *m_soundItemUp);
			break;
		}
	case SOUND_JUMP_ID:
		{
			return new CSound( *m_soundJump);
			break;
		}
	case SOUND_LIFEUP_ID:
		{
			return new CSound( *m_soundLifeUp);
			break;
		}
	case SOUND_LOADING_ID:
		{
			return new CSound( *m_soundLoading);
			break;
		}
	case SOUND_LOSE_ID:
		{
			return new CSound( *m_soundLose);
			break;
		}
	case SOUND_MAP1_ID:
		{
			return new CSound( *m_soundMap1);
			break;
		}
	case SOUND_MAP2_ID:
		{
			return new CSound( *m_soundMap2);
			break;
		}
	case SOUND_MARIOGROW_ID:
		{
			return new CSound( *m_soundMarioGrow);
			break;
		}
	case SOUND_MARIOKICK_ID:
		{
			return new CSound(* m_soundMarioKick);
			break;
		}
	case SOUND_MENU_ID:
		{
			return new CSound( *m_soundMenu);
			break;
		}
	case SOUND_MUSHROOMDIE_ID:
		{
			return new CSound( *m_soundMushroomDie);
			break;
		}
	case SOUND_OPTIONS_ID:
		{
			return new CSound( *m_soundOptions);
			break;
		}
	case SOUND_POWERUP_ID:
		{
			return new CSound( *m_soundPowerUp);
			break;
		}
	case SOUND_SHOTTED_ID:
		{
			return new CSound( *m_soundShotted);
			break;
		}
	case SOUND_SLIDEPIPE_ID:
		{
			return new CSound( *m_soundSlidePipe);
			break;
		}
	case SOUND_STARTGAME_ID:
		{
			return new CSound( *m_soundStartGame);
			break;
		}
	case SOUND_TURTLEHEAD_ID:
		{
			return new CSound( *m_soundTurtleHead);
			break;
		}
	case SOUND_WIN_ID:
		{
			return new CSound( *m_soundWin);
			break;
		}
	default:
		{
			return NULL;
			break;
		}
	}
}

// Singleton
CAudio * CResourceManager::GetAudio()
{
	if(m_Audio == NULL)
	{
		m_Audio = new CAudio(m_wndHandle);
	}
	return m_Audio;
}

// Singleton
CResourceManager* CResourceManager::GetInstance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CResourceManager();
	}
	return m_pInstance;
}

// Destructor
CResourceManager::~CResourceManager(void)
{
}