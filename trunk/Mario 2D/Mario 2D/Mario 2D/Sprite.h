#ifndef SPRITE__H
#define SPRITE__H

#include <d3d9.h>
#include <d3dx9.h>

class CSprite
{
protected:
	LPDIRECT3DTEXTURE9 m_texture;
	RECT rect;
	
	int		m_curFrame;
	int		m_totalFrame;
	int		m_columnFrame;
	
	int		m_frameWidth;
	int		m_frameHeight;

	float	m_timeAnimation;
	float	m_timeCurrent;
public:

	D3DXVECTOR2 m_pos;

	CSprite(void);
	CSprite(float _x, float _y, int _totalFrame, int _sourceWidth, int _sourceHeight, int _columnFrame);
	~CSprite(void);
	
	void Init(LPDIRECT3DTEXTURE9);
	
	void Render(LPD3DXSPRITE);
	void Render(LPD3DXSPRITE, D3DXVECTOR2);
	
	void Position();
	
	void Update(float, int);
	void Update(float, int, int, int);
	
	void SetTimeAnimation(float);
	void SetCurrentFrame(int);
	
	float GetFrameWidth();
	float GetFrameHeight();

};

#endif


