#ifndef NODE_H
#define NODE_H

#include "Engine.h"

typedef enum TypeNode
{
    DEFAULT
} TypeNode;

typedef struct Node
{
    Vector2 origin;
    Rectangle rect;
    TypeNode type;
} Node;

void ControlNodes();
void RenderNodes();

Node* CheckMouseNodeCollision(int *offset_x, int *offset_y);

#endif//NODE_H