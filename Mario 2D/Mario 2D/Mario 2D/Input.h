#ifndef INPUT__H
#define INPUT__H

#include <dinput.h>
#include "Register.h"

#define KEYBOARD_BUFFER_SIZE    1024 
#define DIRECTINPUT_VERSION		0x0800
#define BUTTON_DOWN	(obj, button) (obj.rgbButtons[button] & 0x80)

class CInput
{
public:
	LPDIRECTINPUT8			m_dinput;
	LPDIRECTINPUTDEVICE8	m_dinputkeyboard;
	DIDEVICEOBJECTDATA		m_keyEvents[ KEYBOARD_BUFFER_SIZE ]; 
	
	BYTE	m_keyState[256];
	BYTE	m_lastState[256];
	int		m_keyDown;
	int		m_keyUp;

public:
	CInput(void);
	~CInput(void);
	
	int InitInput(HINSTANCE);
	int InitKeyboard(HWND);
	
	void Poll_KeyBoard();
	void Kill_Keyboard();
	void Process_KeyBoard();

	int KeyDown(int);
	
	bool OnKeyDown(int);
	bool OnKeyUp(int);
	
	LPDIRECTINPUTDEVICE8 Get_KeyBoard();
};
#endif


