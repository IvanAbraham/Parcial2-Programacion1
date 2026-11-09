#include "map.h"

Maps::Maps(Rectangle mapLimits) : mapLimits(mapLimits)
{
}

Vector2 Maps::RandomSpawn(const Vector2& size) const
{
    int minX = static_cast<int>(mapLimits.x);
    int maxX = static_cast<int>(mapLimits.x + mapLimits.width - size.x);
    int minY = static_cast<int>(mapLimits.y);
    int maxY = static_cast<int>(mapLimits.y + mapLimits.height - size.y);

    float x = static_cast<float>(GetRandomValue(minX, maxX));
    float y = static_cast<float>(GetRandomValue(minY, maxY));

    return { x, y};
}

Vector2 Maps::CentralSpawn(const Vector2& size) const
{
    float x = (mapLimits.x + mapLimits.width / 2) - (size.x / 2);
    float y = (mapLimits.y + mapLimits.height / 2) - (size.y / 2);

    return { x, y };
}

void Maps::Draw() const
{
	const float frameThickness = 2.0f;
	DrawRectangleLinesEx(mapLimits, frameThickness, WHITE);
}

void Maps::ClampInside(Rectangle& rect) const
{
    float minX = mapLimits.x;
    float maxX = mapLimits.x + mapLimits.width - rect.width;
    float minY = mapLimits.y;
    float maxY = mapLimits.y + mapLimits.height - rect.height;

    if (rect.x < minX)
        rect.x = minX;
    else if (rect.x > maxX)
        rect.x = maxX;

    if (rect.y < minY)
        rect.y = minY;
    else if (rect.y > maxY)
        rect.y = maxY;
}