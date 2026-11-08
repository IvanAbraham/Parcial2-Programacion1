#include "game.h"
#include "raylib.h"
#include "world/map.h"
#include "entities/player.h"

namespace game
{
    static const int screenWidth = 800;
    static const int screenHeight = 600;

    void Run()
    {
        InitWindow(screenWidth, screenHeight, "P1 Parcial 2 - Ivan Abraham");

        const float hudHeight = 60.0f;
        const float margin = 20.0f;
        Maps map({ margin, hudHeight, screenWidth - margin * 2, screenHeight - hudHeight - margin });
        const Vector2 playerSize = { 30.0f, 50.0f };
        Vector2 playerSpawn = map.CentralSpawn(playerSize);
        Player player({ playerSpawn.x, playerSpawn.y, playerSize.x, playerSize.y });

        while (!WindowShouldClose())
        {
            player.Update(map);

            BeginDrawing();
            ClearBackground(BLACK);
            map.DrawMap();
            player.Draw();
            
            EndDrawing();
        }
        CloseWindow();
    }
}
