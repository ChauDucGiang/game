#pragma once
#include"Enemy.h"

class EnemySoldier : public Enemy
{
private:
	Rect curGroundBound;

public:
	bool isOnGround;
	float activeDistance;
	EnemySoldier();
	void DetectCurGround(std::unordered_set<Rect*> grounds);
	void UpdateDistance(float dt);
	void ChangeState(State StateName);
};