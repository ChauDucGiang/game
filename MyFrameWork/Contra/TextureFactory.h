#pragma once
#include <unordered_map>
#include "Texture.h"

class TextureFactory
{
private:
	static TextureFactory* instance;
	std::unordered_map<Tag, LPDIRECT3DTEXTURE9> textures;

public:
	void LoadResources();
	void AddTexture(Tag tag, const char* filePath);
	static TextureFactory* GetInstance();
	LPDIRECT3DTEXTURE9 GetTexture(Tag tag);
};