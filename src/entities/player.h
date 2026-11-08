#pragma once
#include "entity.h"

class Player : public Entity
{
private:
	int currentLife;
	int maxLife;
	int score;
	float speed;
	Color color;

public:
	Player(Rectangle playerHitbox);
	void Draw() override;
};