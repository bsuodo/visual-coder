#include "Engine.h"

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    InitWindow(800, 600, "Visual Editor");

    EngineInit();

    // CreateButton(100, 100, 192, 128, "click");
    // CreateRoundedButton(200, 170, 162, 162, 0.1, "shop");

    ELEMENT scrollbar = CreateScrollbar(-256, 0, 256, GetScreenHeight(), true, false);
    
    while (!WindowShouldClose())
    {
        SetStyleScrollbar(scrollbar, SET_HEIGHT, GetScreenHeight());

        EngineUpdate();
        EngineRender();
    }

    CloseWindow();

    return 0;
}