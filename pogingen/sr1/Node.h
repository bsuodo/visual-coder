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
    // bool grab;
} Node;

void ControlNodes();
void RenderNodes();

Node* AddNode();

Node* CheckMouseNodeCollision(int *offset_x, int *offset_y);

extern Node* nodes;
extern int nodes_lengte;

#endif//NODE_H