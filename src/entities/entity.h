#pragma once
#include <raylib.h>

class Player;

class Entity
{
protected:
	Rectangle hitBox;
	bool active;
	void DrawHumanoid(Color color) const;

public:
	Rectangle GetHitBox() const;

	bool Collide(const Entity& secondEntity) const;
	bool IsActive() const;

	virtual void Draw() const = 0;
	virtual void OnPlayerCollision(Player& player);
	virtual bool IsCollectible() const;

	Entity(Rectangle hitBox);
	virtual ~Entity();
};	