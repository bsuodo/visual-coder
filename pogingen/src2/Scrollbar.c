#include "Scrollbar.h"

#include "Internal.h"

typedef struct SCROLLBAR
{
    float x, y;
    float width, height;
    bool right, bottom;
} SCROLLBAR;

static SCROLLBAR* list;
static int size = 0;

void* CreateScrollbar(int x, int y, int width, int height, bool right, bool bottom)
{
    list = MemRealloc(list, (size+1)*sizeof(SCROLLBAR));
    list[size] = (SCROLLBAR){
        .x = x,
        .y = y,
        .width = width,
        .height = height,
        .right = right,
        .bottom = bottom
    };

    size++;

    return (void*)&list[size - 1];
}

void SetStyleScrollbar(ELEMENT element, style type, int value)
{
    if (type == SET_HEIGHT) ((SCROLLBAR*)element)->height = value;
}

void UpdateScrollbars()
{
    for (int c=0; c < size; c++)
    {
        if (CheckCollisionPointRec(
            (Vector2)
                {GetMouseX(),GetMouseY()},
            (Rectangle){
                list[c].right ? GetScreenWidth() + list[c].x : list[c].x,
                list[c].bottom ? GetScreenHeight() + list[c].y : list[c].y,
                list[c].width,
                list[c].height}))
            WorkspaceBlockedPressed = true;
    }
}

void RenderScrollbars()
{
    for (int c=0; c < size; c++)
    {
        DrawRectangle(
            list[c].right ? GetScreenWidth() + list[c].x : list[c].x,
            list[c].bottom ? GetScreenHeight() + list[c].y : list[c].y,
            list[c].width,
            list[c].height,
            (Color){255,120,30,120}
        );
    }
}