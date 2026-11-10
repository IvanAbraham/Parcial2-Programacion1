#pragma once
#include "collectible.h"

class LifeCollectible : public Collectible
{
public:
    LifeCollectible(Rectangle hitbox, Texture2D sprite);
    void Draw() const override;
    void OnCollect(Player& player) override;
};