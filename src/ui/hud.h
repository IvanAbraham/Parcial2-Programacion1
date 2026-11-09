#pragma once
#include "entities/player.h"

class Hud
{
private:
    const Player& player;

public:
    Hud(const Player& player);
    void Draw() const;
};