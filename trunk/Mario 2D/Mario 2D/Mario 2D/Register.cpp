#include "Register.h"

CRegister::CRegister(void)
{
}

CRegister::CRegister(HINSTANCE _hinstance)
{
	this->m_hInstance = _hinstance;
}

bool CRegister::InitWindows()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= m_hInstance;
	wcex.hIcon			= 0;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= NameClass;
	wcex.hIconSm		= 0;
	RegisterClassEx(&wcex);
	m_wndHandle = CreateWindow(
		NameClass, 
		NameClass, 
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		SCREEN_WIDTH,   
 		SCREEN_HEIGHT, 
		NULL, 
		NULL, 
		m_hInstance, 
		NULL);
	if (!m_wndHandle)
	{
		return false;
	}
	if (!SetWindowPos(m_wndHandle , HWND_NOTOPMOST , 200, 100 , SCREEN_WIDTH , SCREEN_HEIGHT , SWP_SHOWWINDOW))
	{
		return false;
	}
	bool _show = false;
	while (!_show)
	{
		_show = ShowWindow(m_wndHandle, SW_SHOW);
	}
	UpdateWindow(m_wndHandle);
	return true;

}

HINSTANCE CRegister::Get_hInstance()
{
	return this->m_hInstance;
}

HWND CRegister::Get_WndHandle()
{
	return this->m_wndHandle;
}

LRESULT CALLBACK CRegister::WndProc(HWND wnd,UINT mess,WPARAM wParam,LPARAM lParam)
{
	switch (mess)
	{
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
	}
	return DefWindowProc(wnd,mess,wParam,lParam);
}

CRegister::~CRegister(void)
{
}
