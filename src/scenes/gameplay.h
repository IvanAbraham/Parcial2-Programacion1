#pragma once
#include "entities/player.h"
#include "entities/enemy.h"
#include <vector>

class Gameplay
{
private:
	Maps map;
	Player player;
	std::vector<Entity*> entities;

public:
	Gameplay();
	~Gameplay();
	void Update();
	void Draw() const;
};