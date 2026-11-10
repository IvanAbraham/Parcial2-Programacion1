#pragma once
#include <raylib.h>
#include "entity.h"

class Enemy : public Entity
{
private:
	float speed;
	Vector2 dir;

public:
	Enemy(Rectangle hitbox, Texture2D sprite);
	void Update(const Maps& map) override;
	void Draw() const override;
	void OnPlayerCollision(Player& player) override;
};