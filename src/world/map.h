#pragma once
#include <raylib.h>


class Maps
{
private:
	Rectangle mapLimits;

public:
	void Draw() const;
	void ClampInside(Rectangle& rect) const;
	Vector2 CentralSpawn(const Vector2& size) const;
	Vector2 RandomSpawn(const Vector2& size) const;


	Maps(Rectangle mapLimits);
};