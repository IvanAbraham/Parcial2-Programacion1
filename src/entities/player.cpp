#include "player.h"

static const int initialLives = 3;
static const int maxLives = 5;
static const float playerSpeed = 250.0f;
static const Color playerColor = SKYBLUE;

Player::Player(Rectangle playerHitbox) : Entity(playerHitbox), currentLife(initialLives), maxLife(maxLives), score(0), speed(playerSpeed), color(playerColor)
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