#ifndef BUTTON_H
#define BUTTON_H

#include "Engine.h"

void* CreateButton(int x, int y, int width, int height, char* text);
void* CreateRoundedButton(int x, int y, int width, int height, float roundness, char* text);

void UpdateButtons();
void RenderButtons();
#include "Internal.h"

#endif//BUTTON_H