#pragma once
#include "Enemy.h"

class EnemyBazoka : public Enemy
{
private:
	float delayTime;
	Sprite* explodeBullet;

public:
	EnemyBazoka();
	void UpdateDistance(float dt);
	void Update(float dt);
	void Render(float translateX = 0, float translateY = 0);
};