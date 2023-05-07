#pragma once

#include "SceneManager.h"
#include "Graphics.h"

class Game
{

public:
	Game(HWND hWnd);
	~Game()
	{}
	void cleanUp();
	//void go();
	void update();
	void render();
};