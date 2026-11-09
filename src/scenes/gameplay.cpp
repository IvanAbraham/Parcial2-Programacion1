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

static const int maxSpawnAttempts = 100;
static const float playerSafeMargin = 50.0f;

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

Rectangle Gameplay::FindFreeSpawn(Vector2 size) const
{
    Rectangle playerHitBox = player.GetHitBox();
    Rectangle safeZone = { playerHitBox.x - playerSafeMargin, playerHitBox.y - playerSafeMargin, playerHitBox.width + playerSafeMargin * 2, playerHitBox.height + playerSafeMargin * 2 };
    Rectangle candidate = { 0.0f, 0.0f, size.x, size.y };

    for (int attempt = 0; attempt < maxSpawnAttempts; attempt++)
    {
        Vector2 spawn = map.RandomSpawn(size);
        candidate.x = spawn.x;
        candidate.y = spawn.y;

        bool overlaps = CheckCollisionRecs(candidate, safeZone);

        for (size_t i = 0; i < entities.size() && !overlaps; i++)
            if (CheckCollisionRecs(candidate, entities[i]->GetHitBox()))
                overlaps = true;

        if (!overlaps)
            return candidate;
    }

    return candidate;
}

Gameplay::Gameplay() : map(CalculateMapLimits()), player(CalculatePlayerSpawn(map))
{
    for (int i = 0; i < enemiesAmount; i++)
        entities.push_back(new Enemy(FindFreeSpawn(enemiesSize)));

    for (int i = 0; i < pointsCollectiblesAmount; i++)
        entities.push_back(new PointsCollectible(FindFreeSpawn(collectibleSize)));

    for (int i = 0; i < lifeCollectiblesAmount; i++)
        entities.push_back(new LifeCollectible(FindFreeSpawn(collectibleSize)));

    for (int i = 0; i < multiplierCollectiblesAmount; i++)
        entities.push_back(new MultiplierCollectible(FindFreeSpawn(collectibleSize)));
}


Gameplay::~Gameplay()
{
    for (size_t i = 0; i < entities.size(); i++)
        delete entities[i];
}

void Gameplay::Update()
{
    player.Update(map);
    for (size_t i = 0; i < entities.size(); i++)
        if(player.Collide(*entities[i]))
        {
            entities[i]->OnPlayerCollision(player);
        }

    for (size_t i = entities.size(); i > 0; i--)
    {
        size_t index = i - 1;

        if (!entities[index]->IsActive())
        {
            delete entities[index];
            entities.erase(entities.begin() + index);
        }
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
