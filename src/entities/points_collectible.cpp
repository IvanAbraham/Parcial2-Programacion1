#include "points_collectible.h"
#include "player.h"

static const int bonusScore = 100;

PointsCollectible::PointsCollectible(Rectangle hitbox, Texture2D sprite) : Collectible(hitbox, sprite)
{
}

void PointsCollectible::Draw() const
{
    DrawSprite();
}

void PointsCollectible::OnCollect(Player& player)
{
    player.AddScore(bonusScore);
}