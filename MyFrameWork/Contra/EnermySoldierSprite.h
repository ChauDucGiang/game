#pragma once
#include"Sprite.h"

class EnermySoldierSprite : public Sprite
{
public:
	Type type;
	EnermySoldierSprite() {};
	EnermySoldierSprite(Type type, int left, int top, int right, int bottom);
};