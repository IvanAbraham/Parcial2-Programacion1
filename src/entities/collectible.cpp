#include "collectible.h"
#include "player.h"

Collectible::Collectible(Rectangle hitbox) : Entity(hitbox)
{
}

void Collectible::OnPlayerCollision(Player& player)
{
	OnCollect(player);
	active = false;
}
