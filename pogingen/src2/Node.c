#include "Node.h"

typedef struct NODE
{
    int x, y;
    bool active;
} NODE;

static NODE* list = (void*)0;
static int size = 0;

void CreateNode(bool activate, int x, int y)
{
    list = MemRealloc(list, (size + 1) * sizeof(NODE));

    list[size] = (NODE){
        .x = x,
        .y = y,
        .active = activate
    };

    size++;
}

void RenderNodes()
{
    for (int c = 0; c < size; c++)
    {
        DrawRectangleRounded(
            (Rectangle){
                .x = list[c].x,
                .y = list[c].y,
                .width = 192,
                .height = 128,
            }, 0.1, 2,
            (Color){
                .r = 120,
                .g = 120,
                .b = 120,
                .a = 255
        });
    }
}