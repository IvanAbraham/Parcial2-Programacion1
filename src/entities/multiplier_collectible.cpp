#include "multiplier_collectible.h"
#include "player.h"

static const Color multiplierColor = PURPLE;

static const float scoreMultiplier = 1.2f;

MultiplierCollectible::MultiplierCollectible(Rectangle hitbox) : Collectible(hitbox), color(multiplierColor)
{
}

void MultiplierCollectible::Draw() const
{
    Vector2 center = { hitBox.x + hitBox.width / 2, hitBox.y + hitBox.height / 2 };
    float radius = hitBox.width / 2;
    const int sides = 4;
    const float rotation = 0.0f;

    DrawPoly(center, sides, radius, rotation, color);
}

void MultiplierCollectible::OnCollect(Player& player)
{
    player.MultiplyScore(scoreMultiplier);
}
