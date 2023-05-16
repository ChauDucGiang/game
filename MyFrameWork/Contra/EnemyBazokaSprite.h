#pragma once
#include"Sprite.h"

class EnemyBazokaSprite : public Sprite
{
public:
	Type type;
	EnemyBazokaSprite() {};
	EnemyBazokaSprite(Type type, int left, int top, int right, int bottom);
};