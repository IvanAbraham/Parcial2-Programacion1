#include "map.h"

Maps::Maps(Rectangle mapLimits) : mapLimits(mapLimits)
{
}

Vector2 Maps::GetMapLimits() const
{
	return { mapLimits.x, mapLimits.y };
}

void Maps::DrawMap() const
{
	const float frameThickness = 2.0f;
	DrawRectangleLinesEx(mapLimits, frameThickness, WHITE);
}

