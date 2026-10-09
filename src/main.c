#include "Engine.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Visual Editor");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        ControlNodes();
        ControlWorkspace();
                    
        BeginDrawing();
            ClearBackground((Color){15, 15, 15, 255});
        
            RenderWorkspace();
            RenderNodes();

            DrawText(TextFormat("X: %f - Y: %f - Z: %f", x, y, zoom), 0, 0, 32, RAYWHITE);
        EndDrawing();
    }
    
    CloseWindow();
}