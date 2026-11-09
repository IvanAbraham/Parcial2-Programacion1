#include "points_collectible.h"
#include "player.h"

static const Color pointsColor = GOLD;

static const int bonusScore = 100;

PointsCollectible::PointsCollectible(Rectangle hitbox) : Collectible(hitbox), color(pointsColor)
{
}

void PointsCollectible::Draw() const
{
    Vector2 center = { hitBox.x + hitBox.width / 2, hitBox.y + hitBox.height / 2 };
    float radius = hitBox.width / 2;

    DrawCircleV(center, radius, color);
}

void PointsCollectible::OnCollect(Player& player)
{
    player.AddScore(bonusScore);
}