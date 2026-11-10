#include "entity.h"

static const float frameDuration = 0.12f;

Entity::Entity(Rectangle hitBox, Texture2D sprite, int frameCount, int firstLoopFrame) : hitBox(hitBox), active(true), sprite(sprite), frameCount(frameCount), firstLoopFrame(firstLoopFrame), currentFrame(0), frameTimer(0.0f), facingLeft(false)
{
}

bool Entity::Collide(const Entity& secondEntity) const
{
	return CheckCollisionRecs(hitBox, secondEntity.hitBox);
}

void Entity::UpdateAnimation()
{
    if (currentFrame < firstLoopFrame)
        currentFrame = firstLoopFrame;

    frameTimer += GetFrameTime();

    if (frameTimer >= frameDuration)
    {
        frameTimer -= frameDuration;
        currentFrame++;

        if (currentFrame >= frameCount)
            currentFrame = firstLoopFrame;
    }
}

void Entity::ResetAnimation()
{
    currentFrame = 0;
    frameTimer = 0.0f;
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
    float frameWidth = static_cast<float>(sprite.width) / static_cast<float>(frameCount);
    float sourceWidth = facingLeft ? -frameWidth : frameWidth;

    Rectangle source = { frameWidth * static_cast<float>(currentFrame), 0.0f, sourceWidth,
    static_cast<float>(sprite.height) };
    
    Vector2 origin = { 0.0f, 0.0f };
    const float rotation = 0.0f;

    DrawTexturePro(sprite, source, hitBox, origin, rotation, WHITE);
}

void Entity::OnPlayerCollision(Player& /*player*/) {}

void Entity::Update(const Maps& /*map*/) {}

bool Entity::IsActive() const
{
    return active;
}

Rectangle Entity::GetHitBox() const
{
    return hitBox;
}
