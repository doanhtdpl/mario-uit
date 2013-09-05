#include "Texture.h"

// Contructor without parameter
CTexture::CTexture(void)
{
}

// Destructor
CTexture::~CTexture(void)
{
}

// Contructor with 1 parameter
CTexture::CTexture(LPDIRECT3DDEVICE9 _pd3device)
{
	m_pd3ddevice = _pd3device;
}

// Get texture
LPDIRECT3DTEXTURE9 CTexture::GetTexture(string _filename)
{
	HRESULT result;
	
	// Get image from file
	result = D3DXGetImageInfoFromFile(_filename.c_str(), &m_info);
	if (FAILED(result))
	{
		return NULL;
	}
	
	// Create texture from file >>Ex
	result = D3DXCreateTextureFromFileEx(
		m_pd3ddevice, //device
		_filename.c_str(), //file name
		m_info.Width,  //width of image
		m_info.Height, //height of image
		1, // 
		D3DPOOL_DEFAULT, //
		D3DFMT_UNKNOWN,	 //format
		D3DPOOL_DEFAULT, //
		D3DX_DEFAULT, 
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(250,100,100), // color key
		&m_info, //info image
		NULL,
		&m_texture); //texture

	if (FAILED(result))
	{
		return NULL; // FAILED is declared in WinError.h
	}
	//
	return m_texture;
}

// Get texture information
D3DXIMAGE_INFO CTexture::GetTextureInfo()
{
	return m_info;
}
