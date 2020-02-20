#ifndef RESOURCE_H_INCLUDED
#define RESOURCE_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

/// Game asset constants

const int OVERWORLD_TILESHEET_COLS = 9; // index 0 to 8

extern ALLEGRO_BITMAP *gfxOverworldSheet;

void LoadResources();
void UnloadResources();

#endif // RESOURCE_H_INCLUDED
