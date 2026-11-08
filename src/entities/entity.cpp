#include "entity.h"

Entity::Entity(Rectangle hitBox) : hitBox(hitBox)
{
}

bool Entity::Collide(const Entity& secondEntity) const
{
	return CheckCollisionRecs(hitBox, secondEntity.hitBox);
}

Entity::~Entity()
{
	
}
