#pragma once
#include"Enemy.h"

class EnermySoldier : public Enemy
{
private:
	Rect curGroundBound;

public:
	bool isOnGround;
	float activeDistance;
	EnermySoldier();
	void DetectCurGround(std::unordered_set<Rect*> grounds);
	void UpdateDistance(float dt);
	void ChangeState(State StateName);
};