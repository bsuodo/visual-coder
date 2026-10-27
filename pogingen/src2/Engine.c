#include "Engine.h"

float x = 0; float GetX() {return x;}
float y = 0; float GetY() {return y;}
float zoom = 1;

float mouse_origin_x = 0;
float mouse_origin_y = 0;

bool WorkspaceAlreadyDragging = false;
bool WorkspaceBlockedPressed = false;

void EngineInit()
{
    CreateNode(false, 0, 0);
}

void EngineUpdate()
{
    WorkspaceBlockedPressed = false;

    UpdateScrollbars();
    UpdateButtons();

    // the draging system, scrolling
    if (!WorkspaceBlockedPressed && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        mouse_origin_x = GetMouseX();
        mouse_origin_y = GetMouseY();

        WorkspaceAlreadyDragging = true;
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) || WorkspaceBlockedPressed)
        WorkspaceAlreadyDragging = false;

    if (WorkspaceAlreadyDragging)
    {
        float change_x = (GetMouseX() - mouse_origin_x) / 3;
        float change_y = (GetMouseY() - mouse_origin_y) / 3;

        x -= change_x;
        y -= change_y;

        mouse_origin_x += change_x;
        mouse_origin_y += change_y;
    }
}

void EngineRender()
{
    BeginDrawing();
        ClearBackground((Color){15, 15, 15, 255});

        // x version
        for (float c_x = fmod(-x,64); c_x < GetScreenWidth(); c_x+=64)
            DrawLineEx((Vector2){c_x, 0}, (Vector2){c_x, GetScreenHeight()}, 2, (Color){45, 45, 45, 255});
        
        // y version
        for (float c_y = fmod(-y,64); c_y < GetScreenHeight(); c_y+=64)
            DrawLineEx((Vector2){0, c_y}, (Vector2){GetScreenWidth(), c_y}, 2, (Color){45, 45, 45, 255});

        RenderButtons();
        RenderScrollbars();
        RenderNodes();
    EndDrawing();
}