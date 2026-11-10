#include "enemy.h"
#include "player.h"

static const float enemySpeed = 250.0f;

Enemy::Enemy(Rectangle hitbox, Texture2D sprite) : Entity(hitbox, sprite), speed(enemySpeed)
{
}

void Enemy::Draw() const
{
	DrawSprite();
}

void Enemy::OnPlayerCollision(Player& player) 
{
	player.TakeHit();
}