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
	void SpawnCollectibles();
	void SpawnEnemies();
	bool HasCollectiblesLeft() const;
	void RefreshLevel();

	Maps map;
	
	Texture2D playerTexture;
	Texture2D enemyTexture;
	Texture2D pointsTexture;
	Texture2D lifeTexture;
	Texture2D multiplierTexture;
	
	Player player;
	Hud hud;
	GameState state;
	int currentEnemies;
	std::vector<Entity*> entities;
	Rectangle FindFreeSpawn(Vector2 size) const;

public:
	Gameplay();
	~Gameplay();
	void Update();
	void Draw() const;
};