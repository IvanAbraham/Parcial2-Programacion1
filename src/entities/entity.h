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

public:
	Rectangle GetHitBox() const;

	bool Collide(const Entity& secondEntity) const;
	bool IsActive() const;

	virtual void Draw() const = 0;
	virtual void OnPlayerCollision(Player& player);
	virtual void Update(const Maps& map);
	virtual bool IsCollectible() const;
	

	Entity(Rectangle hitBox, Texture2D sprite);
	virtual ~Entity();
};	