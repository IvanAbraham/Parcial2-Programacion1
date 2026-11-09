#pragma once
#include "collectible.h"

class PointsCollectible : public Collectible
{
private:
    Color color;

public:
    PointsCollectible(Rectangle hitbox);
    void Draw() const override;
    void OnCollect(Player& player) override;
};