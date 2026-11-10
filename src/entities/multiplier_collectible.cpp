#include "multiplier_collectible.h"
#include "player.h"

static const float scoreMultiplier = 1.2f;

MultiplierCollectible::MultiplierCollectible(Rectangle hitbox, Texture2D sprite) : Collectible(hitbox, sprite)
{
}

void MultiplierCollectible::Draw() const
{
    DrawSprite();
}

void MultiplierCollectible::OnCollect(Player& player)
{
    player.MultiplyScore(scoreMultiplier);
}
