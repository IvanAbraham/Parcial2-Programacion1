#pragma once
#include "collectible.h"

class PointsCollectible : public Collectible
{
public:
    PointsCollectible(Rectangle hitbox, Texture2D sprite);
    void Draw() const override;
    void OnCollect(Player& player) override;
};