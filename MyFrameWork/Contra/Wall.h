#pragma once
#include "Rect.h"
// Tường
struct Wall
{
	Rect rect;
	int type;

	Wall() {}
	Wall(float x, float y, float width, float height, int type)
	{
		this->rect.x = x;
		this->rect.y = y;
		this->rect.width = width;
		this->rect.height = height;
		this->type = type;
	}
};