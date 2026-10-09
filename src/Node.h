#ifndef NODE_H
#define NODE_H

#include "Engine.h"

void ControlNodes();
void RenderNodes();

typedef struct Node
{
    Vector2 origin;
    Rectangle rect;
    Color kleur;
} Node;

#endif//NODE_H