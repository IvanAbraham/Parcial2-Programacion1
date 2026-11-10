#include "collectible.h"
#include "player.h"

Collectible::Collectible(Rectangle hitbox, Texture2D sprite) : Entity(hitbox, sprite)
{
}

void Collectible::OnPlayerCollision(Player& player)
{
	OnCollect(player);
	active = false;
}

bool Collectible::IsCollectible() const
{
	return true;
}