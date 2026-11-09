#pragma once
#include "entities/player.h"
#include "entities/enemy.h"
#include "entities/points_collectible.h"
#include "entities/life_collectible.h"
#include "entities/multiplier_collectible.h"
#include "ui/hud.h"
#include <vector>

enum class GameState
{
	Playing,
	Won,
	Lost
};

class Gameplay
{
private:
	Maps map;
	Player player;
	Hud hud;
	GameState state;
	std::vector<Entity*> entities;
	Rectangle FindFreeSpawn(Vector2 size) const;

public:
	Gameplay();
	~Gameplay();
	void Update();
	void Draw() const;
};