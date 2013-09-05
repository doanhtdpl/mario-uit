#ifndef GRAPHIC__H
#define GRAPHIC__H

#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>

#define SCREEN_WIDTH	800 // width of screen
#define SCREEN_HEIGHT	600 // height of screen

class CGraphic
{
protected:
	LPDIRECT3D9				m_pd3d;			// direct 3D
	LPDIRECT3DDEVICE9		m_pd3ddevice;	// direct 3D device
	D3DPRESENT_PARAMETERS	m_d3dpp;		// present parameter of direct 3D
public:
	CGraphic(void);
	~CGraphic(void);

	bool InitDevice(HWND); // Init device (windows handler)
	
	LPDIRECT3D9 Get_pd3d();				// Get direct 3D
	LPDIRECT3DDEVICE9 Get_pd3ddevice(); // Get direct 3D device
	D3DPRESENT_PARAMETERS Get_d3dpp();	// Get present parameter of direct 3D
	
	void ReleaseDevice();	// Release device
	void BeginRender();		// Begin render
	void EndRender();		// End render
	
	int GetScreenWidth();	// Get screen width
	int GetScreenHeight();	// Get screen height
};
#endif


