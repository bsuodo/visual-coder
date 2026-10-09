#include "Workspace.h"

float x = 0;
float y = 0;
float zoom = 1;
int zoomdir = 0;

int mouse_origin_x = 0;
int mouse_origin_y = 0;

void ControlWorkspace()
{
    if (IsKeyDown(KEY_RIGHT_CONTROL) || IsKeyDown(KEY_LEFT_CONTROL))
    {
        // zoom dir
        if      (IsKeyPressed(KEY_MINUS))                                         {zoomdir = -1;}
        else if (IsKeyPressed(KEY_EQUAL))                                         {zoomdir =  1;}
        if      ((zoom >= 2.5 && zoomdir == 1) || (zoom <= 0.8 && zoomdir == -1)) {zoomdir =  0;}

        if (zoom <= 2.7 && zoom >= 0.6)
        {
            float worldX = GetMouseX() / zoom + x;
            float worldY = GetMouseY() / zoom + y;

            zoom += 0.2 * zoomdir;
            zoomdir = 0;

            x = worldX - GetMouseX() / zoom;
            y = worldY - GetMouseY() / zoom;
        }
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        x += (mouse_origin_x - GetMouseX())/zoom;
        y += (mouse_origin_y - GetMouseY())/zoom;
    }
    mouse_origin_x = GetMouseX();
    mouse_origin_y = GetMouseY();
}

void RenderWorkspace()
{
    // lines on the x axis
    for (float count = fmodf(-x*zoom, 64*zoom); count <= GetScreenWidth(); count+=zoom*64)
    {
        DrawLineEx((Vector2){count, 0}, (Vector2){count, GetScreenHeight()}, 2, (Color){45, 45, 45, 255});
    }

    // lines on the y axis
    for (float count = fmodf(-y*zoom, 64*zoom); count <= GetScreenHeight(); count+=zoom*64)
    {
        DrawLineEx((Vector2){0, count}, (Vector2){GetScreenWidth(), count}, 2, (Color){45, 45, 45, 255});
    }
}