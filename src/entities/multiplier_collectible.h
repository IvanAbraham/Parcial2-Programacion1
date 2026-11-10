#pragma once
#include "collectible.h"

class MultiplierCollectible : public Collectible
{
public:
    MultiplierCollectible(Rectangle hitbox, Texture2D sprite);
    void Draw() const override;
    void OnCollect(Player& player) override;
};
