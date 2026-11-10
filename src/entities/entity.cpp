#include "entity.h"

Entity::Entity(Rectangle hitBox, Texture2D sprite) : hitBox(hitBox), active(true), sprite(sprite)
{
}

bool Entity::Collide(const Entity& secondEntity) const
{
	return CheckCollisionRecs(hitBox, secondEntity.hitBox);
}

Entity::~Entity()
{
	
}

bool Entity::IsCollectible() const
{
    return false;
}

void Entity::DrawSprite() const
{
    Rectangle source = { 0.0f, 0.0f, static_cast<float>(sprite.width), static_cast<float>(sprite.height) };
    Vector2 origin = { 0.0f, 0.0f };
    const float rotation = 0.0f;

    DrawTexturePro(sprite, source, hitBox, origin, rotation, WHITE);
}

void Entity::OnPlayerCollision(Player& /*player*/) {}

bool Entity::IsActive() const
{
    return active;
}

Rectangle Entity::GetHitBox() const
{
    return hitBox;
}
