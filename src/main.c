#include "Engine.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Visual Editor");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        ControlWorkspace();
                    
        BeginDrawing();
            ClearBackground((Color){15, 15, 15, 255});
        
            RenderWorkspace();
    
        EndDrawing();
    }
    
    CloseWindow();
}