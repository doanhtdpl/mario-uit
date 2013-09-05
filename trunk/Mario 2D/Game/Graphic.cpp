#include "Graphic.h"

// Constructor
CGraphic::CGraphic(void)
{
	m_pd3d = NULL;
	m_pd3ddevice = NULL;
}

// Destructor
CGraphic::~CGraphic(void)
{
}

//Init device
bool CGraphic::InitDevice(HWND _wndHandle)
{
	if ((m_pd3d = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
	{
		return false;
	}

	ZeroMemory( &m_d3dpp, sizeof(m_d3dpp) );
	m_d3dpp.Windowed			= TRUE;
	m_d3dpp.SwapEffect			= D3DSWAPEFFECT_DISCARD;
	m_d3dpp.BackBufferFormat	= D3DFMT_UNKNOWN;
	m_d3dpp.BackBufferCount		= 1;
	m_d3dpp.BackBufferHeight	= SCREEN_HEIGHT;
	m_d3dpp.BackBufferWidth		= SCREEN_WIDTH;
	m_d3dpp.hDeviceWindow		= _wndHandle;
	
	if( FAILED( m_pd3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,				// D3DDEVTYPE_HAL
	_wndHandle, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &m_d3dpp, &m_pd3ddevice ) ) )
	{
		if( FAILED( m_pd3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_REF,			// D3DDEVTYPE_REF
		_wndHandle,	D3DCREATE_SOFTWARE_VERTEXPROCESSING, &m_d3dpp, &m_pd3ddevice ) ) )
		{
			if( FAILED( m_pd3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_SW,		// D3DDEVTYPE_SW
			_wndHandle, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &m_d3dpp, &m_pd3ddevice ) ) )
			{
				return false;
			}
		}
	}
	return true;
}

// Get direct 3D
LPDIRECT3D9 CGraphic::Get_pd3d()
{
	return m_pd3d;
}

// Get direct 3D device
LPDIRECT3DDEVICE9 CGraphic::Get_pd3ddevice()
{
	return m_pd3ddevice; 
}

// Get present parameter of direct 3D
D3DPRESENT_PARAMETERS CGraphic::Get_d3dpp()
{
	return m_d3dpp;
}

// Begin render
void CGraphic::BeginRender()
{
	if (m_pd3ddevice != NULL)
	{
		m_pd3ddevice->BeginScene();
		m_pd3ddevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,255,255), 1.0f, 0);
	}
}

// End render
void CGraphic::EndRender()
{
	m_pd3ddevice->EndScene();
	m_pd3ddevice->Present(NULL, NULL, NULL, NULL);
}

// Release device
void CGraphic::ReleaseDevice()
{
	if (m_pd3d != NULL)
	{
		m_pd3d->Release();
		m_pd3d = NULL;
	}
	if (m_pd3ddevice != NULL)
	{
		m_pd3ddevice->Release();
		m_pd3ddevice = NULL;
	}
}

// Get screen width
int CGraphic::GetScreenWidth()
{
	return SCREEN_WIDTH;
}

// Get screen height
int CGraphic::GetScreenHeight()
{
	return SCREEN_HEIGHT;
}


