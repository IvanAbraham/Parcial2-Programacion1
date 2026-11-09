#pragma once

#include <raylib.h>

class Entity
{
protected:
	Rectangle hitBox;
	void DrawHumanoid(Color color) const;

public:
	bool Collide(const Entity& secondEntity) const;

	virtual void Draw() const = 0;

	Entity(Rectangle hitBox);
	virtual ~Entity();
	
};	