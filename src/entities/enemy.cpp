#include "enemy.h"
#include "player.h"
#include "world/map.h"

static const float enemySpeed = 120.0f;
static const int enemyFrames = 3;

static Vector2 RandomDirection()
{
	float dir = (GetRandomValue(0, 1) == 0) ? -1.0f : 1.0f;

	if (GetRandomValue(0, 1) == 0)
		return { dir, 0.0f };

	return { 0.0f, dir };
}

Enemy::Enemy(Rectangle hitbox, Texture2D sprite) : Entity(hitbox, sprite, enemyFrames), speed(enemySpeed), dir(RandomDirection())
{
}

void Enemy::Update(const Maps& map)
{
    float step = speed * GetFrameTime();
    hitBox.x += dir.x * step;
    hitBox.y += dir.y * step;

    Rectangle beforeClamp = hitBox;
    map.ClampInside(hitBox);

    if (hitBox.x != beforeClamp.x)
        dir.x = -dir.x;
    if (hitBox.y != beforeClamp.y)
        dir.y = -dir.y;

    UpdateAnimation();
}

void Enemy::Draw() const
{
	DrawSprite();
}

void Enemy::OnPlayerCollision(Player& player) 
{
	player.TakeHit();
}