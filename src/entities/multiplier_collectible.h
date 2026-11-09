#pragma once
#include "collectible.h"

class MultiplierCollectible : public Collectible
{
private:
    Color color;

public:
    MultiplierCollectible(Rectangle hitbox);
    void Draw() const override;
    void OnCollect(Player& player) override;
};
