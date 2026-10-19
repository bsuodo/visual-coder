#include "Engine.h"

void initialize()
{
    // Configs
    SetConfigFlags(FLAG_MSAA_4X_HINT); SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Visual Editor");
    SetTargetFPS(60);
}