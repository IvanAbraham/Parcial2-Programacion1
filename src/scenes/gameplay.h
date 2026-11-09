#pragma once
#include "entities/player.h"
#include "entities/enemy.h"
#include "entities/points_collectible.h"
#include "entities/life_collectible.h"
#include "entities/multiplier_collectible.h"
#include <vector>

class Gameplay
{
private:
	Maps map;
	Player player;
	std::vector<Entity*> entities;
	Rectangle FindFreeSpawn(Vector2 size) const;

public:
	Gameplay();
	~Gameplay();
	void Update();
	void Draw() const;
};