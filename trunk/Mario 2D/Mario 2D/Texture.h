#ifndef TEXTURE__H
#define TEXTURE__H

#include <d3d9.h>
#include <d3dx9.h>
#include <string>
using namespace std;

class CTexture
{
protected:
	D3DXIMAGE_INFO			m_info;			// info image
	LPDIRECT3DTEXTURE9		m_texture;		// texture
	LPDIRECT3DDEVICE9		m_pd3ddevice;	// device
public:
	CTexture(void);
	~CTexture(void);
	
	CTexture(LPDIRECT3DDEVICE9);
	LPDIRECT3DTEXTURE9 GetTexture(string);	// Get texture
	D3DXIMAGE_INFO GetTextureInfo();		// Get info image
};
#endif
