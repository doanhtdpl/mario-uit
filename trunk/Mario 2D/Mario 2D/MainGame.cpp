#include "GameApps.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CGameApps* m_game;
	m_game = new CGameApps();
	if (! m_game->Init(hInstance))
	{
		return 0;
	}
	
	m_game->Run();
	m_game->Exit();
	
	return 1;
	
}

