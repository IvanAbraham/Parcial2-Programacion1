#include "game.h"
#include "raylib.h"
#include "world/map.h"

namespace game
{
    static const int screenWidth = 800;
    static const int screenHeight = 600;

    void Run()
    {
        InitWindow(screenWidth, screenHeight, "Game");

        const float hudHeight = 60.0f;
        const float margin = 20.0f;
        Maps map({ margin, hudHeight, screenWidth - margin * 2, screenHeight - hudHeight - margin });

        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(BLACK);
            map.DrawMap();
            EndDrawing();
        }

        CloseWindow();
    }
}
