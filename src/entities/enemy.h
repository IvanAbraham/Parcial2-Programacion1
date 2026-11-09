#pragma once
#include <raylib.h>
#include "entity.h"

class Enemy : public Entity
{
private:
	float speed;
	Color color;
public:
	Enemy(Rectangle hitbox);
	void Draw() const override;
	void OnPlayerCollision(Player& player) override;
};