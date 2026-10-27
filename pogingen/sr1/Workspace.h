#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "Engine.h"

void ControlWorkspace();
void RenderWorkspace();

void SelectNode(void* p_node);

extern float x;
extern float y;
extern float zoom;

#endif//WORKSPACE_H