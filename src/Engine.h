#ifndef ENGINE_H
#define ENGINE_H

#include <RayLib/raylib.h>
#include <math.h>
#include <stdlib.h>

#define NONE (void*)0
#define AND &&
#define OR ||

#include "Workspace.h"
#include "Node.h"
#include "Finder.h"

void initialize();

#endif//ENGINE_H