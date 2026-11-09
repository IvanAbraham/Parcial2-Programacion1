#pragma once
#include "entity.h"

class Collectible : public Entity
{
private:

public:
	Collectible(Rectangle hitbox);
	virtual void OnCollect(Player& player) = 0;
	void OnPlayerCollision(Player& player) override;
};