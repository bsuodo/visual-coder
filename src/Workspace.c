#include "Workspace.h"

float x = 0;
float y = 0;
float zoom = 1;
int zoomdir = 0;

int mouse_origin_x = 0;
int mouse_origin_y = 0;

int mouse_smooth_x = 0;
int mouse_smooth_y = 0;

int offset_x = 0;
int offset_y = 0;

Node* selected_node;

void ControlWorkspace()
{
    if (IsKeyDown(KEY_RIGHT_CONTROL) OR IsKeyDown(KEY_LEFT_CONTROL))
    {
        // zoom dir
        if      (IsKeyPressed(KEY_MINUS))                                           {zoomdir = -1;}
        else if (IsKeyPressed(KEY_EQUAL))                                           {zoomdir =  1;}
        if      ((zoom >= 2.5 AND zoomdir == 1) OR (zoom <= 0.8 AND zoomdir == -1)) {zoomdir =  0;}

        if (zoom <= 2.7 AND zoom >= 0.6)
        {
            float worldX = GetMouseX() / zoom + x;
            float worldY = GetMouseY() / zoom + y;

            zoom += 0.2 * zoomdir;
            zoomdir = 0;

            x = worldX - GetMouseX() / zoom;
            y = worldY - GetMouseY() / zoom;
        }
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {selected_node = CheckMouseNodeCollision(&offset_x, &offset_y);}
    if (IsMouseButtonUp(MOUSE_BUTTON_LEFT))      {selected_node = NONE; mouse_smooth_x=0; mouse_smooth_y=0;}
    
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        if     (selected_node == NONE)
        {
            mouse_smooth_x += (mouse_origin_x - GetMouseX())/zoom;
            mouse_smooth_y += (mouse_origin_y - GetMouseY())/zoom;
            x += mouse_smooth_x / 12;
            y += mouse_smooth_y / 12;
            mouse_smooth_x -= mouse_smooth_x / 6;
            mouse_smooth_y -= mouse_smooth_y / 6;
        }
        else // if selected
        {
            selected_node->origin.x += ((x + GetMouseX()/zoom - offset_x) - selected_node->origin.x) / 2;
            selected_node->origin.y += ((y + GetMouseY()/zoom - offset_y) - selected_node->origin.y) / 2;
        }
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