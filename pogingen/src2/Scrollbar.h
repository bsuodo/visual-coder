#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include "Engine.h"

void* CreateScrollbar(int x, int y, int width, int height, bool right, bool bottom);
void RenderScrollbars();
void UpdateScrollbars();

void SetStyleScrollbar(ELEMENT element, style type, int value);

#endif//SCROLLBAR_H