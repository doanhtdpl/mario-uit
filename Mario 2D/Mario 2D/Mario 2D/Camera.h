#ifndef CAMERA__H
#define CAMERA__H

#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>
#include "Input.h"

class CCamera
{
private:
	D3DXMATRIX m_viewPort;	
	float m_step;
	RECT m_view;
	D3DXVECTOR2 m_pos;
public:
	CCamera(void);
	~CCamera(void);
	void Update(CInput*, D3DXVECTOR2);
	D3DXMATRIX Get_ViewPort();
	RECT Get_Rect();
	void UpdateRect();
};

#endif


