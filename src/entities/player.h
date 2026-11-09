#pragma once
#include "entity.h"
#include "world/map.h"

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
	void Update(const Maps& map);
	void Draw() const override;
};