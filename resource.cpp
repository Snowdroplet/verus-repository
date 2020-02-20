#include "resource.h"

ALLEGRO_BITMAP *gfxOverworldSheet = nullptr;

void LoadResources()
{
    gfxOverworldSheet = al_load_bitmap("overworldSheet32x42.png");
}

void UnloadResources()
{
    al_destroy_bitmap(gfxOverworldSheet);
}
