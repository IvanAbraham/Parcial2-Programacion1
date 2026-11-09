#pragma once
#include <raylib.h>

class Player;

class Entity
{
protected:
	Rectangle hitBox;
	void DrawHumanoid(Color color) const;

public:
	bool Collide(const Entity& secondEntity) const;

	virtual void Draw() const = 0;
	virtual void OnPlayerCollision(Player& player);

	Entity(Rectangle hitBox);
	virtual ~Entity();
};	