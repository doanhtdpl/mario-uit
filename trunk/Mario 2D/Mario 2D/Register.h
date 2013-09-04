#ifndef REGISTER__H
#define REGISTER__H

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#define NameClass "@========{==== Mario 2D >> Copyright by Philosopher ft Simba << UIT ======>"
#define SCREEN_WIDTH	800 // screen width
#define SCREEN_HEIGHT	600 // screen height

class CRegister
{
private:
	HINSTANCE m_hInstance;	// instance handler
	HWND m_wndHandle;		// windows handler
public:
	CRegister(void);
	~CRegister(void);
	CRegister(HINSTANCE);

	bool InitWindows();	// Init windows

	HINSTANCE Get_hInstance(); // Get instance handler
	HWND Get_WndHandle();	// Get windows handler

	static LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM); // Windows Processing
};

#endif