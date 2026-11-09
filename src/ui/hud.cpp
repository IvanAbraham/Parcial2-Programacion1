#include "hud.h"
#include <cmath>

static const int fontSize = 20;
static const int textY = 20;
static const int sideMargin = 20;
static const Color textColor = WHITE;

Hud::Hud(const Player& player) : player(player)
{
}

void Hud::Draw() const
{
    DrawText(TextFormat("Vidas: %d", player.GetLife()), sideMargin, textY, fontSize, textColor);

    const char* scoreText = TextFormat("Puntaje: %d", player.GetScore());
    DrawText(scoreText, GetScreenWidth() / 2 - MeasureText(scoreText, fontSize) / 2, textY, fontSize, textColor);

    const char* timeText = TextFormat("Tiempo: %d", static_cast<int>(ceilf(player.GetRemainingTime())));
    DrawText(timeText, GetScreenWidth() - MeasureText(timeText, fontSize) - sideMargin, textY, fontSize, textColor);
}