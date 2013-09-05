#include "Camera.h"


CCamera::CCamera(void)
{
	m_pos = D3DXVECTOR2(0, 800);
}

void CCamera::Update(CInput* _keyBoard, D3DXVECTOR2 _pos)
{
	m_pos.x = (float)_pos.x - 400;
	if (m_pos.x < 0)
	{
		m_pos.x =  0;
	}
	UpdateRect();
}

D3DXMATRIX CCamera::Get_ViewPort()
{
	D3DXMatrixIdentity(&m_viewPort);
	D3DXMatrixAffineTransformation(&m_viewPort , 1, &D3DXVECTOR3(0,0,0), &D3DXQUATERNION(0,0,0,0), &D3DXVECTOR3((float)-m_pos.x, (float) m_pos.y, 0)); 
	m_viewPort._22 = -1;
	return m_viewPort;
}
void CCamera::UpdateRect()
{
	m_view.left = (LONG)m_pos.x - 400;
	m_view.top = (LONG)m_pos.y - 1000;
	m_view.right = (LONG)m_view.left + 1400;
	m_view.bottom = (LONG)m_view.top + 1600;
}

RECT CCamera::Get_Rect()
{
	return m_view;
}
CCamera::~CCamera(void)
{
}

