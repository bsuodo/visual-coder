#include "Node.h"

Node* nodes;
char nodes_lengte;

void ControlNodes()
{
    if (IsKeyDown(KEY_RIGHT_CONTROL) || IsKeyDown(KEY_LEFT_CONTROL))
    {
        if (IsKeyPressed(KEY_N))
        {
            nodes = MemRealloc(nodes, (nodes_lengte + 1)*sizeof(Node));
            nodes[nodes_lengte] = (Node){
                .kleur = (Color){GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255},
                .rect.width = 192,
                .rect.height = 128
            };
            
            nodes[nodes_lengte].origin.x = x + GetMouseX()/zoom  - 192/2;
            nodes[nodes_lengte].origin.y = y + GetMouseY()/zoom - 128/2;
            
            nodes_lengte++;
        }
    }

    for (int count = 0; count < nodes_lengte; count++)
    {
        nodes[count].rect.x = -x*zoom + nodes[count].origin.x*zoom;
        nodes[count].rect.y = -y*zoom + nodes[count].origin.y*zoom;
        nodes[count].rect.width = zoom * 192;
        nodes[count].rect.height = zoom * 128;
    }
}

void RenderNodes()
{
    for (int count = 0; count < nodes_lengte; count++)
    {
        Node *current_node = &nodes[count]; 
        DrawRectangleRounded(current_node->rect, 0.3, 1, current_node->kleur);
    }
}