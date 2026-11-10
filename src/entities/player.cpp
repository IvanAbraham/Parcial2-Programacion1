#include "player.h"

static const int initialLives = 3;
static const int maxLives = 5;

static const float playerSpeed = 250.0f;
static const float speedIncreasePerSecond = 5.0f;
static const float maxPlayerSpeed = 1000.0f;

static const float gameDuration = 60.0f;

Player::Player(Rectangle playerHitbox, Texture2D sprite) : Entity(playerHitbox, sprite), currentLife(initialLives), maxLife(maxLives), score(0), speed(playerSpeed), spawnPoint({ playerHitbox.x, playerHitbox.y }), remainingTime(gameDuration)
{
}

void Player::Update(const Maps& map)
{
    Vector2 direction = { 0.0f, 0.0f };

    remainingTime -= GetFrameTime();
    if (remainingTime < 0.0f)
        remainingTime = 0.0f;

    speed += speedIncreasePerSecond * GetFrameTime();

    if (speed > maxPlayerSpeed)
        speed = maxPlayerSpeed;

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
    Entity::DrawSprite();
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

void Player::AddScore(int bonusScore)
{
    score += bonusScore;
}

void Player::MultiplyScore(float scoreMultiplier)
{
    score = static_cast<int>(score * scoreMultiplier);
}

float Player::GetRemainingTime() const
{
    return remainingTime;
}

bool Player::IsAlive() const
{
    return currentLife > 0;
}

bool Player::IsTimeOver() const
{
    return remainingTime <= 0.0f;
}