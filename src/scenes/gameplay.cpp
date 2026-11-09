#include "gameplay.h"

static const float hudHeight = 60.0f;
static const float mapMargin = 20.0f;
static const Vector2 playerSize = { 30.0f, 50.0f };

static const int enemiesAmount = 5;
static const Vector2 enemiesSize = { 30.0f, 50.0f };

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

static Rectangle CalculateEnemySpawn(const Maps& map)
{
    Vector2 spawn = map.RandomSpawn(enemiesSize);
    return { spawn.x, spawn.y, enemiesSize.x, enemiesSize.y };
}

Gameplay::Gameplay() : map(CalculateMapLimits()), player(CalculatePlayerSpawn(map))
{
    for (int i = 0; i < enemiesAmount; i++)
        entities.push_back(new Enemy(CalculateEnemySpawn(map)));
}

Gameplay::~Gameplay()
{
    for (int i = 0; i < entities.size(); i++)
        delete entities[i];
}

void Gameplay::Update()
{
    player.Update(map);
}

void Gameplay::Draw() const
{
    ClearBackground(BLACK);
    map.Draw();

    for (size_t i = 0; i < entities.size(); i++)
        entities[i]->Draw();

    player.Draw();
}
