#pragma once
#include <raylib.h>

class Player;
class Maps;

class Entity
{
protected:
	Rectangle hitBox;
	bool active;
	Texture2D sprite;
	void DrawSprite() const;
	int frameCount;
	int firstLoopFrame;
	int currentFrame;
	float frameTimer;
	bool facingLeft;
	void UpdateAnimation();
	void ResetAnimation();

public:
	Rectangle GetHitBox() const;

	bool Collide(const Entity& secondEntity) const;
	bool IsActive() const;

	virtual void Draw() const = 0;
	virtual void OnPlayerCollision(Player& player);
	virtual void Update(const Maps& map);
	virtual bool IsCollectible() const;
	

	Entity(Rectangle hitBox, Texture2D sprite, int frameCount = 1, int firstLoopFrame = 0);
	virtual ~Entity();
};	