#include "Finder.h"

Node display_nodes_events[1] = {
    {
        .type = DEFAULT,
        .rect = (Rectangle){0, 0, 192, 128},
        // .grab = false
    },
}; 

typedef struct
{
    Vector2 pos;
    int scroll_y;
    void (*drawfunc)(int);
    void (*controlfunc)(int);
} Finder;

void EventsDrawFinder(int ID);
void EventsControlFinder(int ID);

#define FINDER_SIZE 1
int finder_current_opened_ID = -1;
Finder finder_list[FINDER_SIZE] = {
    {
        .pos.x = 0,
        .pos.y = 16,
        .scroll_y = 0,
        .drawfunc = EventsDrawFinder,
        .controlfunc = EventsControlFinder,
    },
};

void EventsDrawFinder(int ID)
{
    DrawRectangle(finder_list[ID].pos.x, finder_list[ID].pos.y, 64, 64, (Color){230, 120, 30, 255});
    DrawCircle(finder_list[ID].pos.x, finder_list[ID].pos.y + 32, 32, (Color){230, 120, 30, 255});

    if (finder_current_opened_ID == ID)
    {
        DrawRectangle(finder_list[ID].pos.x + 64, 0, 192 + 32, GetScreenHeight(), (Color){230, 120, 30, 120});

        RenderNodes(display_nodes_events, 1);
    }
}

void EventsControlFinder(int ID)
{
    finder_list[ID].pos.x = GetScreenWidth() - (64) - (finder_current_opened_ID == ID ? 192 + 32 : 0);

    for (int c = 0; c < 1; c++)
    {
        display_nodes_events[c].rect.x = finder_list[ID].pos.x + 64 + 16;
        display_nodes_events[c].rect.y = finder_list[ID].scroll_y + 16;
    }

    if ((CheckCollisionPointCircle( (Vector2){GetMouseX(), GetMouseY()}, (Vector2)   {finder_list[ID].pos.x, finder_list[ID].pos.y + 32}, 32)                               OR
         CheckCollisionPointRec(    (Vector2){GetMouseX(), GetMouseY()}, (Rectangle) {.x = finder_list[ID].pos.x, .y = finder_list[ID].pos.y, .width = 64 , .height = 64})) AND
         IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { finder_current_opened_ID = (finder_current_opened_ID == ID) ? -1 : ID; } // pressed one of the finder button

    Rectangle display_node_collision_rect = {
        .x = finder_list[ID].pos.x,
        .y = finder_list[ID].pos.y,
        .width = 192,
        .height = 128
    };
    Vector2 mouse_pos = {GetMouseX(), GetMouseY()};
    if (CheckCollisionPointRec(mouse_pos, display_node_collision_rect) AND
        finder_current_opened_ID == ID AND IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) SelectNode(AddNode());
}

bool FinderUIBlock()
{
    for (int ID = 0; ID <= 1; ID++)
    {
        if (finder_current_opened_ID == ID AND
            CheckCollisionPointRec((Vector2){GetMouseX(), GetMouseY()}, (Rectangle){.x=finder_list[ID].pos.x + 64, .y=0, .width=192 + 32, .height=GetScreenHeight()}))
            return true;
    }

}

void ControlFinder()
{
    for (int c=0; c < FINDER_SIZE; c++) finder_list[c].controlfunc(c);
}

void RenderFinder()
{
    for (int c=0; c < FINDER_SIZE; c++) finder_list[c].drawfunc(c);
}