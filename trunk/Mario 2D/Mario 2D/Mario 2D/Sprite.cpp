#include "Sprite.h"

// Contructor without parameter
CSprite::CSprite(void)
{
}

// Destructor
CSprite::~CSprite(void)
{
}

// Contructor with 6 parameters 
CSprite::CSprite(float _x, float _y, int _totalFrame, int _sourceWidth, int _sourceHeight, int _columnFrame)
{
	m_texture = NULL;
	m_curFrame = 0;
	m_pos = D3DXVECTOR2(_x, _y);
	
	m_totalFrame = _totalFrame;
	m_columnFrame =	_columnFrame;
	m_frameWidth = _sourceWidth / _columnFrame;
	m_frameHeight = (_sourceHeight) / (m_totalFrame / _columnFrame);

}

// Init sprite
void CSprite::Init(LPDIRECT3DTEXTURE9 _texture )
{
	m_texture = _texture;
	m_timeCurrent = 0;
	m_timeAnimation = 0;
	m_curFrame = 0;
}

// Draw sprite with 1 parameter
void CSprite::Render(LPD3DXSPRITE m_spriteHandle)
{
	D3DXVECTOR3 position = D3DXVECTOR3((float)m_pos.x, (float)m_pos.y, 0);
	m_spriteHandle->Draw(m_texture, &rect, NULL, &position, D3DCOLOR_XRGB(255,255,255)); // WinNT.h
}

// Draw sprite with 2 parameters
void CSprite::Render(LPD3DXSPRITE m_spriteHandle, D3DXVECTOR2 t_pos)
{
	D3DXVECTOR3 position = D3DXVECTOR3(t_pos.x , t_pos.y , 0);
	m_spriteHandle->Draw(m_texture, &rect, NULL, &position, D3DCOLOR_XRGB(255,255,255)); // WinNT.h
}

// Position sprite
void CSprite::Position()
{
	rect.left = (m_curFrame % m_columnFrame) * m_frameWidth;
	rect.top = (m_curFrame / m_columnFrame) * m_frameHeight;
	rect.right = rect.left + m_frameWidth;
	rect.bottom = rect.top + m_frameHeight;
}

// Update sprite with 2 parameters
void CSprite::Update(float _time, int _flag)
{
	if (m_timeAnimation != 0)
	{
		Update(_time, 0 , m_totalFrame-1, _flag);
	}
	Position();
}

// Update sprite with 4 parameters
void CSprite::Update(float _time, int _beginFrame, int _endFrame, int _flag)
{
	if (m_timeAnimation != 0)
	{
		if (m_timeCurrent > m_timeAnimation)
		{
			// update frame right -> left
			if (_flag == 1)
			{
				m_curFrame++;
				if (m_curFrame < _beginFrame)
				{
					m_curFrame = _beginFrame;
				}
				if (m_curFrame > _endFrame )
				{
					m_curFrame = _beginFrame;
				}
			}
			// update frame left -> right
			if (_flag == -1)
			{
				m_curFrame--;
				if (m_curFrame < _beginFrame)
				{
					m_curFrame = _endFrame ;
				}
				if (m_curFrame > _endFrame )
				{
					m_curFrame = _beginFrame;
				}
			}
			//
			Position();
			m_timeCurrent = 0;
		}
		else
		{
			m_timeCurrent += _time;
		}
	}
}

// Set time animation
void CSprite::SetTimeAnimation(float _time)
{
	m_timeAnimation = _time;
}

// Set current frame
void CSprite::SetCurrentFrame(int _frame)
{
	m_curFrame = _frame;
}

// Get frame height
float CSprite::GetFrameHeight()
{
	return (float)m_frameHeight;
}

// Get frame width
float CSprite::GetFrameWidth()
{
	return (float)m_frameWidth;
}
