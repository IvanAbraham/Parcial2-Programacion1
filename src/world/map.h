#pragma once
#include <raylib.h>


class Maps
{
private:
	Rectangle mapLimits;

public:
	Vector2 GetMapLimits() const;
	void DrawMap() const;

	Maps(Rectangle mapLimits);
};