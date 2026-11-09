#pragma once
#include "collectible.h"

class LifeCollectible : public Collectible
{
private:
    Color color;

public:
    LifeCollectible(Rectangle hitbox);
    void Draw() const override;
    void OnCollect(Player& player) override;
};