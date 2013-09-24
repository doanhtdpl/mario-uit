#include "GameApps.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CGameApps* m_game;
	m_game = new CGameApps();
	
	if (!m_game->Game_Init(hInstance))
	{
		return 0;
	}
	m_game->Game_Run();
	m_game->Game_Destroy();
	
	return 1;
	
}

