#pragma once
#include <raylib.h>
#include "entity.h"

class Enemy : public Entity
{
private:
	float speed;

public:
	Enemy(Rectangle hitbox, Texture2D sprite);
	void Draw() const override;
	void OnPlayerCollision(Player& player) override;
};