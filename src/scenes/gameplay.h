#pragma once
#include "entities/player.h"
#include "world/map.h"

class Gameplay
{
private:
	Maps map;
	Player player;

public:
	Gameplay();
	void Update();
	void Draw() const;
};