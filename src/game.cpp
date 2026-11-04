#include "game.h"

#include "raylib.h"

namespace game
{
	static const int screenWidth = 800;
	static const int screenHeight = 600;

	void Run()
	{
		InitWindow(screenWidth, screenHeight, "Game");

		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(BLACK);
			DrawText("raylib template", 10, 10, 20, RAYWHITE);
			EndDrawing();
		}

		CloseWindow();
	}
}
