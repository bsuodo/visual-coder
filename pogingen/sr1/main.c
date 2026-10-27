#include "Engine.h"

int main()
{
    initialize();
    
    while (!WindowShouldClose())
    {
        ControlWorkspace();
        ControlNodes();
        ControlFinder();
                    
        BeginDrawing();
            ClearBackground((Color){15, 15, 15, 255});
        
            RenderWorkspace();
            RenderNodes(nodes, nodes_lengte);
            RenderFinder();

            DrawText(TextFormat("X: %f - Y: %f - Z: %f", x, y, zoom), 16, 16, 32, RAYWHITE);
        EndDrawing();
    }
    
    CloseWindow();
}