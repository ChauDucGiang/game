#include "GameGlobal.h"

// Texture custom - có thêm hàm load từ file dẫn cho trước
class Texture
{
private:
	LPDIRECT3DTEXTURE9 texture;

public:
	Texture(const char* filePath)
	{
		D3DXIMAGE_INFO imageInfo;
		D3DXGetImageInfoFromFile(filePath, &imageInfo);
		D3DXCreateTextureFromFileEx(d3ddev, filePath, imageInfo.Width, imageInfo.Height, 1, D3DUSAGE_DYNAMIC,
			D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, NULL, &imageInfo, NULL, &texture);
	}
	~Texture() { texture->Release(); }
	LPDIRECT3DTEXTURE9 GetTexture() { return texture; }
};