#include "player.h"

static const int initialLives = 3;
static const int maxLives = 5;

static const int bonusScore = 100;
static const float scoreMultiplier = 1.2f;

static const float playerSpeed = 250.0f;
static const Color playerColor = SKYBLUE;

Player::Player(Rectangle playerHitbox) : Entity(playerHitbox), currentLife(initialLives), maxLife(maxLives), score(0), speed(playerSpeed), spawnPoint({playerHitbox.x, playerHitbox.y}), color(playerColor)
{
}

void Player::Update(const Maps& map)
{
    Vector2 direction = { 0.0f, 0.0f };

    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        direction.y -= 1.0f;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
        direction.y += 1.0f;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        direction.x -= 1.0f;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        direction.x += 1.0f;

    float step = speed * GetFrameTime();
    hitBox.x += direction.x * step;
    hitBox.y += direction.y * step;

    map.ClampInside(hitBox);
}

void Player::Draw() const
{
    Entity::DrawHumanoid(color);
}

void Player::TakeHit()
{
    currentLife--;
    hitBox.x = spawnPoint.x;
    hitBox.y = spawnPoint.y;
}

int Player::GetLife() const
{
    return currentLife;
}

int Player::GetScore() const
{
    return score;
}

void Player::AddLife()
{
    if (currentLife < maxLife)
        currentLife++;
}

void Player::AddScore()
{
    score += bonusScore;
}

void Player::MultiplyScore()
{
    score = static_cast<int>(score * scoreMultiplier);
}