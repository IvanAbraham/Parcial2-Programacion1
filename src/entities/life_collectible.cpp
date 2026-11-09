#include "life_collectible.h"
#include "player.h"

static const Color lifeColor = GREEN;

LifeCollectible::LifeCollectible(Rectangle hitbox) : Collectible(hitbox), color(lifeColor)
{
}

void LifeCollectible::Draw() const
{
    float thickness = hitBox.width / 3;

    Rectangle vertical = { hitBox.x + thickness, hitBox.y, thickness, hitBox.height };
    Rectangle horizontal = { hitBox.x, hitBox.y + thickness, hitBox.width, thickness };

    DrawRectangleRec(vertical, color);
    DrawRectangleRec(horizontal, color);
}

void LifeCollectible::OnCollect(Player& player)
{
    player.AddLife();
}
