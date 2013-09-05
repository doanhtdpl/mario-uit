#include "Input.h"


CInput::CInput(void)
{	
}
CInput::~CInput(void)
{
}
int CInput::InitInput(HINSTANCE _hInstance)
{
	HRESULT result;
	result = DirectInput8Create(_hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**) &m_dinput, NULL);
	if (result != DI_OK)
	{
		return 0;
	}
	result = m_dinput->CreateDevice(GUID_SysKeyboard, &m_dinputkeyboard, NULL);
	if (result != DI_OK)
	{
		return 0;
	}
	return 1;
}
int CInput::InitKeyboard(HWND _wndhandle)
{
	HRESULT result;
	result= m_dinputkeyboard->SetDataFormat(&c_dfDIKeyboard);
	if (result != DI_OK)
	{
		return 0;
	}
	result = m_dinputkeyboard->SetCooperativeLevel(_wndhandle, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	if (result != DI_OK)
	{
		return 0;
	}
	DIPROPDWORD dipdw; 
	dipdw.diph.dwSize       = sizeof(DIPROPDWORD); 
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER); 
	dipdw.diph.dwObj        = 0; 
	dipdw.diph.dwHow        = DIPH_DEVICE; 
	dipdw.dwData            = KEYBOARD_BUFFER_SIZE;
	m_dinputkeyboard->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	result = m_dinputkeyboard->Acquire();
	return 1;
}

void CInput::Process_KeyBoard()
{
	m_dinputkeyboard->Poll();
	
	for (int i=0; i < 256; i++)
	{
		m_lastState[i] = m_keyState[i];
	}
	
	if (!SUCCEEDED (m_dinputkeyboard->GetDeviceState(256, (LPVOID) &m_keyState)) )
	{
		m_dinputkeyboard->Acquire();
	}
	Poll_KeyBoard();

}
bool CInput::OnKeyDown(int key)
{
	if((this->m_keyState[key] & 0x80) && !(this->m_lastState[key] && 0x80))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CInput::OnKeyUp(int key)
{
	if(!(this->m_keyState[key] & 0x80) && (this->m_lastState[key] && 0x80))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int CInput::KeyDown(int key)
{
	return (m_keyState[key] && 0x80) > 0;
}

void CInput::Poll_KeyBoard()
{
	m_dinputkeyboard->GetDeviceState(sizeof(m_keyState), (LPVOID) &m_keyState);
}
void CInput::Kill_Keyboard()
{
	if (m_dinputkeyboard != NULL)
	{
		m_dinputkeyboard->Unacquire();
		m_dinputkeyboard->Release();
		m_dinputkeyboard = NULL;
	}
}
LPDIRECTINPUTDEVICE8 CInput::Get_KeyBoard()
{
	return m_dinputkeyboard;
}


