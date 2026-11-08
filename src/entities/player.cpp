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

void Player::Draw()
{
    float x = hitBox.x;
    float y = hitBox.y;
    float w = hitBox.width;
    float h = hitBox.height;

    const float lineThickness = 3.0f;

    // Cabeza
    float headRadius = h * 0.15f;
    Vector2 headCenter = { x + w / 2, y + headRadius };
    DrawCircleV(headCenter, headRadius, color);

    // Cuerpo
    float bodyTop = y + headRadius * 2;
    float bodyBottom = y + h * 0.65f;
    float bodyWidth = w * 0.4f;
    Rectangle body = { x + (w - bodyWidth) / 2, bodyTop, bodyWidth, bodyBottom - bodyTop };
    DrawRectangleRec(body, color);

    // Brazos
    float shoulderY = bodyTop + h * 0.05f;
    float handY = bodyTop + h * 0.25f;
    DrawLineEx({ body.x, shoulderY }, { x, handY }, lineThickness, color);
    DrawLineEx({ body.x + bodyWidth, shoulderY }, { x + w, handY }, lineThickness, color);

    // Piernas
    DrawLineEx({ body.x, bodyBottom }, { x + w * 0.15f, y + h }, lineThickness, color);
    DrawLineEx({ body.x + bodyWidth, bodyBottom }, { x + w * 0.85f, y + h }, lineThickness, color);
}