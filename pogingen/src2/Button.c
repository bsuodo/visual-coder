#include "Button.h"
#include "Internal.h"

typedef struct BUTTON
{
    char* text;
    int width, height;
    int x, y;
    float roundness;
    bool hover;
    Color color;
} BUTTON;

static BUTTON* list = (void*)0;
static int size = 0;

void* CreateButton(int x, int y, int width, int height, char* text)
{
    list = MemRealloc(list, (size+1)*sizeof(BUTTON));
    list[size] = (BUTTON){
        .x = x,
        .y = y,
        .width = width,
        .height = height,
        .text = text,
        .roundness = 0,
        .hover = false,
        .color = (Color){25,25,25,255}
    };

    size++;

    return (void*)&list[size - 1];
}

void* CreateRoundedButton(int x, int y, int width, int height, float roundness, char* text)
{
    list = MemRealloc(list, (size+1)*sizeof(BUTTON));
    list[size] = (BUTTON){
        .x = x,
        .y = y,
        .width = width,
        .height = height,
        .text = text,
        .roundness = roundness,
        .hover = false,
        .color = (Color){25,25,25,255}
    };

    size++;

    return (void*)&list[size - 1];
}

void UpdateButtons()
{
    // reset hover
    for (int c = size - 1; c >= 0; c--) list[c].hover = false;

    // apend hover to the highest (depth) one
    for (int c = size - 1; c >= 0; c--)
    {
        list[c].hover = CheckCollisionPointRec((Vector2){GetMouseX(),GetMouseY()}, (Rectangle){list[c].x,list[c].y,list[c].width,list[c].height});

        // register a button press
        if (list[c].hover) {
            WorkspaceBlockedPressed = true; return;
        }

    }
}

void RenderButtons()
{
    for (int c = 0; c < size; c++)
    {
        DrawRectangleRounded((Rectangle){list[c].x,list[c].y,list[c].width,list[c].height},list[c].roundness,6,(Color){list[c].color.r,list[c].color.g,list[c].color.b,(list[c].hover ? list[c].color.a - 180 : list[c].color.a)});
        
        int text_width = MeasureText(list[c].text, 32);
        int center_text_x = (list[c].x + list[c].width/2) - text_width/2;
        int center_text_y = (list[c].y + list[c].height/2) - 32/2;

        DrawText(list[c].text, center_text_x, center_text_y, 32, (Color){45,45,45,list[c].hover ? list[c].color.a - 180 : list[c].color.a});
    }
}