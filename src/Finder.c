#include "Finder.h"

int toolbar_x;
int toolbar_y;
int radius = 48;

bool hover = false;

void ControlFinder()
{
    toolbar_x = GetScreenWidth() - 48 - 16 - (hover * 4);
    toolbar_y = GetScreenHeight() - 48 - 16 - (hover * 4);

    if (CheckCollisionPointCircle((Vector2){GetMouseX(), GetMouseY()},(Vector2){toolbar_x + (hover * 4), toolbar_y + (hover * 4)},48))
        hover = true;
    else
        hover = false;
}

void RenderFinder()
{
    if (!hover)
        DrawCircle(toolbar_x - 4, toolbar_y - 4, 48, (Color){200, 100, 0, 255});
    DrawCircleGradient((Vector2){toolbar_x, toolbar_y}, 48, (Color){255, 160, 30, 255}, (Color){255, 128, 0, 255});

    // arrow (up)
    DrawLineEx((Vector2){toolbar_x - 28, toolbar_y + 24}, (Vector2){toolbar_x, toolbar_y - 22}, 12, WHITE);
    DrawLineEx((Vector2){toolbar_x + 28, toolbar_y + 24}, (Vector2){toolbar_x, toolbar_y - 22}, 12, WHITE);
    DrawCircle(toolbar_x, toolbar_y - 22, 6, WHITE);
}