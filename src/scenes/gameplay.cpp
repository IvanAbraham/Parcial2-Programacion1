#include "gameplay.h"

static const float hudHeight = 60.0f;
static const float mapMargin = 20.0f;
static const Vector2 playerSize = { 32.0f, 50.0f };

static const int enemiesStartAmount = 5;
static const Vector2 enemiesSize = { 32.0f, 50.0f };

static const int pointsCollectiblesAmount = 3;
static const int lifeCollectiblesAmount = 1;
static const int multiplierCollectiblesAmount = 1;
static const Vector2 collectibleSize = { 20.0f, 20.0f };

static const int maxSpawnAttempts = 100;
static const float playerSafeMargin = 50.0f;

static const Color overlayColor = { 0, 0, 0, 180 };
static const int titleFontSize = 50;
static const int subtitleFontSize = 25;

static void DrawCenteredText(const char* text, int y, int fontSize, Color color)
{
    DrawText(text, GetScreenWidth() / 2 - MeasureText(text, fontSize) / 2, y, fontSize, color);
}

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

void Gameplay::SpawnCollectibles()
{
    for (int i = 0; i < pointsCollectiblesAmount; i++)
        entities.push_back(new PointsCollectible(FindFreeSpawn(collectibleSize), pointsTexture));

    for (int i = 0; i < lifeCollectiblesAmount; i++)
        entities.push_back(new LifeCollectible(FindFreeSpawn(collectibleSize), lifeTexture));

    for (int i = 0; i < multiplierCollectiblesAmount; i++)
        entities.push_back(new MultiplierCollectible(FindFreeSpawn(collectibleSize), multiplierTexture));
}

void Gameplay::SpawnEnemies()
{
    for (int i = 0; i < currentEnemies; i++)
        entities.push_back(new Enemy(FindFreeSpawn(enemiesSize), enemyTexture));
}

void Gameplay::RefreshLevel()
{
    for (size_t i = 0; i < entities.size(); i++)
        delete entities[i];
    entities.clear();

    currentEnemies++;
    SpawnEnemies();
    SpawnCollectibles();
}

bool Gameplay::HasCollectiblesLeft() const
{
    for (size_t i = 0; i < entities.size(); i++)
        if (entities[i]->IsCollectible())
            return true;

    return false;
}

Gameplay::Gameplay() : map(CalculateMapLimits()), playerTexture(LoadTexture("res/player-sheet.png")), enemyTexture(LoadTexture("res/enemy-sheet.png")), pointsTexture(LoadTexture("res/add_points.png")), lifeTexture(LoadTexture("res/heal.png")), multiplierTexture(LoadTexture("res/multiplier.png")), player(CalculatePlayerSpawn(map), playerTexture), hud(player), state(GameState::Playing), currentEnemies(enemiesStartAmount)
{
    SpawnEnemies();
    SpawnCollectibles();
}

Gameplay::~Gameplay()
{
    for (size_t i = 0; i < entities.size(); i++)
        delete entities[i];

    UnloadTexture(playerTexture);
    UnloadTexture(enemyTexture);
    UnloadTexture(pointsTexture);
    UnloadTexture(lifeTexture);
    UnloadTexture(multiplierTexture);
}

void Gameplay::Update()
{
    if (state != GameState::Playing)
        return;

    player.Update(map);
    
    for (size_t i = 0; i < entities.size(); i++)
        entities[i]->Update(map);

    for (size_t i = 0; i < entities.size(); i++)
        if (player.Collide(*entities[i]))
            entities[i]->OnPlayerCollision(player);

    for (size_t i = entities.size(); i > 0; i--)
    {
        size_t index = i - 1;

        if (!entities[index]->IsActive())
        {
            delete entities[index];
            entities.erase(entities.begin() + index);
        }
    }

    if (!HasCollectiblesLeft())
        RefreshLevel();

    if (!player.IsAlive())
        state = GameState::Lost;
    else if (player.IsTimeOver())
        state = GameState::Won;
}

void Gameplay::Draw() const
{
    ClearBackground(BLACK);
    map.Draw();

    for (size_t i = 0; i < entities.size(); i++)
        entities[i]->Draw();

    player.Draw();
    hud.Draw();

    if (state != GameState::Playing)
    {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), overlayColor);

        int centerY = GetScreenHeight() / 2;
        bool won = state == GameState::Won;

        DrawCenteredText(won ? "GANASTE" : "PERDISTE", centerY - 80, titleFontSize, won ? GREEN : RED);
        DrawCenteredText(TextFormat("Puntaje final: %d", player.GetScore()), centerY, subtitleFontSize, WHITE);
        DrawCenteredText("ESC para salir", centerY + 50, subtitleFontSize, GRAY);
    }
}
