#include "life_collectible.h"
#include "player.h"

LifeCollectible::LifeCollectible(Rectangle hitbox, Texture2D sprite) : Collectible(hitbox, sprite)
{
}

void LifeCollectible::Draw() const
{
    DrawSprite();
}

void LifeCollectible::OnCollect(Player& player)
{
    player.AddLife();
}
