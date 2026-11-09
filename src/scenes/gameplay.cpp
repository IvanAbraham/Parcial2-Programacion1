#include "gameplay.h"

static const float hudHeight = 60.0f;
static const float mapMargin = 20.0f;
static const Vector2 playerSize = { 30.0f, 50.0f };

static const int enemiesAmount = 5;
static const Vector2 enemiesSize = { 30.0f, 50.0f };

static const int pointsCollectiblesAmount = 3;
static const int lifeCollectiblesAmount = 1;
static const int multiplierCollectiblesAmount = 1;
static const Vector2 collectibleSize = { 20.0f, 20.0f };

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

static Rectangle CalculateCollectibleSpawn(const Maps& map)
{
    Vector2 spawn = map.RandomSpawn(collectibleSize);
    return { spawn.x, spawn.y, collectibleSize.x, collectibleSize.y };
}

Gameplay::Gameplay() : map(CalculateMapLimits()), player(CalculatePlayerSpawn(map))
{
    for (int i = 0; i < enemiesAmount; i++)
        entities.push_back(new Enemy(CalculateEnemySpawn(map)));

    for (int i = 0; i < pointsCollectiblesAmount; i++)
        entities.push_back(new PointsCollectible(CalculateCollectibleSpawn(map)));

    for (int i = 0; i < lifeCollectiblesAmount; i++)
        entities.push_back(new LifeCollectible(CalculateCollectibleSpawn(map)));

    for (int i = 0; i < multiplierCollectiblesAmount; i++)
        entities.push_back(new MultiplierCollectible(CalculateCollectibleSpawn(map)));
}

Gameplay::~Gameplay()
{
    for (int i = 0; i < entities.size(); i++)
        delete entities[i];
}

void Gameplay::Update()
{
    player.Update(map);
    for (int i = 0; i < entities.size(); i++)
        if(player.Collide(*entities[i]))
        {
            entities[i]->OnPlayerCollision(player);
        }
}

void Gameplay::Draw() const
{
    ClearBackground(BLACK);
    map.Draw();

    for (size_t i = 0; i < entities.size(); i++)
        entities[i]->Draw();

    player.Draw();
}
