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

void Entity::DrawHumanoid(Color color) const
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

void Entity::OnPlayerCollision(Player& /*player*/) {}