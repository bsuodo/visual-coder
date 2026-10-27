#ifndef ENGINE_H
#define ENGINE_H

#include <RayLib/raylib.h>
#include <math.h>

#define ELEMENT void*

typedef enum style {
    SET_HEIGHT,
} style;

#include "Button.h"
#include "Node.h"
#include "Scrollbar.h"

void EngineInit();

void EngineUpdate();
void EngineRender();

float GetX();
float GetY();

#endif//ENGINE_H