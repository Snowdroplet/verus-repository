#include "resource.h"

ALLEGRO_BITMAP *gfxOverworldSheet = nullptr;

void LoadResources()
{
    gfxOverworldSheet = al_load_bitmap("hexStripe.png");
}

void UnloadResources()
{
    al_destroy_bitmap(gfxOverworldSheet);
}
