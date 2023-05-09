#pragma once
#include "Sound.h"

// Chứa tất cả các Sound cần dùng cho Game
// Dùng Singleton Pattern

class SoundManager
{
private:
	static class SoundManager* _instance;

public:
	void LoadResources();
	Sound* GetSound(char name);
};