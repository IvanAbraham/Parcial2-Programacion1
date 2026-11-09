#include "game.h"
#include "raylib.h"
#include "scenes/gameplay.h"

namespace game
{
    static const int screenWidth = 800;
    static const int screenHeight = 600;

    void Run()
    {
        InitWindow(screenWidth, screenHeight, "P1 Parcial 2 - Ivan Abraham");

        Gameplay gameplay;

        while (!WindowShouldClose())
        {
            gameplay.Update();

            BeginDrawing();
            
            gameplay.Draw();

            EndDrawing();
        }
        CloseWindow();
    }
}
