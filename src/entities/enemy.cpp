#include "enemy.h"

static const float enemySpeed = 250.0f;
static const Color enemyColor = RED;

Enemy::Enemy(Rectangle hitbox) : Entity(hitbox), speed(enemySpeed), color(enemyColor)
{
}

void Enemy::Draw() const
{
	Entity::DrawHumanoid(color);
}