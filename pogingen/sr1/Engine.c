#include "Engine.h"

void initialize()
{
    // Configs
    SetConfigFlags(FLAG_MSAA_4X_HINT); SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Visual Editor");
    SetTargetFPS(60);
}

float EaseInAndOut(float time)
{
    return time < 0.5 ? 4 * time * time * time : 1 - powf(-2 * time + 2, 3) / 2;
}