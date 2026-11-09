#include "gameplay.h"

static const float hudHeight = 60.0f;
static const float mapMargin = 20.0f;
static const Vector2 playerSize = { 30.0f, 50.0f };

static Rectangle CalculateMapLimits()
{
    float screenWidth = static_cast<float>(GetScreenWidth());
    float screenHeight = static_cast<float>(GetScreenHeight());

    return { mapMargin, hudHeight, screenWidth - mapMargin * 2, screenHeight - hudHeight - mapMargin };
}

static Rectangle CalculatePlayerSpawn(const Maps& map)
{
    Vector2 spawn = map.CentralSpawn(playerSize);
    return { spawn.x, spawn.y, playerSize.x, playerSize.y };
}

Gameplay::Gameplay() : map(CalculateMapLimits()), player(CalculatePlayerSpawn(map))
{
}

void Gameplay::Update()
{
    player.Update(map);
}

void Gameplay::Draw() const
{
    ClearBackground(BLACK);
    map.Draw();
    player.Draw();
}