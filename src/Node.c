#include "Node.h"

Node* nodes;
int nodes_lengte;

Node* CheckMouseNodeCollision(int *offset_x, int *offset_y)
{
    for (int count = 0; count < nodes_lengte; count++)
    {
        if (x + GetMouseX()/zoom >= nodes[count].origin.x       AND
            x + GetMouseX()/zoom <= nodes[count].origin.x + 192 AND
            y + GetMouseY()/zoom >= nodes[count].origin.y       AND
            y + GetMouseY()/zoom <= nodes[count].origin.y + 128
        )
        {
            *offset_x = (int)(x + GetMouseX()/zoom - nodes[count].origin.x);
            *offset_y = (int)(y + GetMouseY()/zoom - nodes[count].origin.y);
            return &nodes[count];
        }
    }

    return NONE;
}

void ControlNodes()
{
    if (IsKeyDown(KEY_RIGHT_CONTROL) OR IsKeyDown(KEY_LEFT_CONTROL))
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            nodes = MemRealloc(nodes, (nodes_lengte + 1)*sizeof(Node));
            nodes[nodes_lengte] = (Node){
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
        DrawRectangleRounded(current_node->rect, 0.3, 6, GREEN);
    }
}