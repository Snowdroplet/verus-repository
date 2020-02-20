#define __USE_MINGW_ANSI_STDIO 0

#include <cstdio>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>

//#include <boost/filesystem.hpp>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_physfs.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <physfs.h>

#include "allegrocustom.h"

#include "gamesystem.h"
#include "resource.h"
#include "control.h"

#include "hex.h"
#include "overworld.h"


void TitleLogic();
void TitleDrawing();

void LoadingLogic();
void LoadingDrawing();

void GameLogic();
void GameDrawing();

void DrawTiles();
void DrawGUI();

Overworld *overworld;

int main(int argc, char*argv[])
{
    srand(time(nullptr));

    //Replace fprintf with native dialogue later
    if(!al_init())
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        return false;
    }
    if(!al_install_keyboard())
    {
        fprintf(stderr, "failed to install keyboard!\n");
        return false;
    }
    if(!al_install_mouse())
    {
        fprintf(stderr, "failed to install mouse!\n");
        return false;
    }
    if(!al_init_image_addon())
        return false;
    if(!al_init_primitives_addon())
        return false;

    al_init_font_addon();

    if(!al_init_ttf_addon())
        return false;

    if(!PHYSFS_init(argv[0]))
        return false;

    if(!PHYSFS_mount("./gamedata.zip", "/", 1))
    {
        fprintf(stderr, "gamedata not found!\n");
        return false;
    }

    al_set_physfs_file_interface();

    AllegroCustomColours();

    FPStimer = al_create_timer(1.0/FPS);
    if(!FPStimer)
    {
        fprintf(stderr, "failed to create fpstimer!\n");
        return false;
    }

    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display)
    {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(FPStimer);
        return false;
    }

    eventQueue = al_create_event_queue();
    if(!eventQueue)
    {
        fprintf(stderr, "failed to create event queue!\n");
        al_destroy_display(display);
        al_destroy_timer(FPStimer);
        return false;
    }

    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_timer_event_source(FPStimer));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_mouse_event_source());

    LoadResources();

    //GuiInit();

    overworld = new Overworld(worldSize);

    al_start_timer(FPStimer);

    while(!gameExit)
    {
        al_wait_for_event(eventQueue, &ev);
        Control();

        if(ev.type == ALLEGRO_EVENT_TIMER || gameExit == true)
        {
            if(mainPhase == MAIN_PHASE_GAME)
            {
                GameLogic();
                GameDrawing();
            }
            else if(mainPhase == MAIN_PHASE_LOADING)
            {
                LoadingLogic();
                LoadingDrawing();
            }
            else if(mainPhase == MAIN_PHASE_TITLE)
            {
                TitleLogic();
                TitleDrawing();
            }

            redraw = true;
        }
    }

    std::cout << "Game exit - Cleanup:" << std::endl;

    delete overworld;

    UnloadResources();

    al_destroy_timer(FPStimer);
    al_destroy_display(display);
    al_destroy_event_queue(eventQueue);
    PHYSFS_deinit();

    return 0;
}

void GameLogic()
{

}

void GameDrawing()
{
    if(redraw && al_is_event_queue_empty(eventQueue))
    {
        redraw = false;
        al_clear_to_color(al_map_rgb(0,0,0));

        DrawTiles();
        DrawGUI();

        al_flip_display();
    }
}

void LoadingLogic()
{

}

void LoadingDrawing()
{

}

void TitleLogic()
{

}

void TitleDrawing()
{

}

void DrawTiles()
{
    for(int drawR = 0; drawR < overworld->rhombusEdge; drawR++)
    {
        for(int drawQ = 0; drawQ < overworld->rhombusEdge; drawQ++)
        {
            Hex *hex = overworld->hexGraph[drawR*worldSize+drawQ];

            if(hex != nullptr)
                al_draw_bitmap_region(gfxOverworldSheet,
                                  HEX_SIZE * hex->base, 0,
                                  HEX_SIZE, 42,
                                  hex->xPosition,
                                  hex->yPosition + ISOMETRIC_OFFSET_Y*hex->rCell, // At the moment, 42 is the height of the tile sprite.
                                  0);
        }
    }
}

void DrawGUI()
{

}
