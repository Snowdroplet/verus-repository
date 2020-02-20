#ifndef GAMESYSTEM_H_INCLUDED
#define GAMESYSTEM_H_INCLUDED

/// Main loop controls
extern bool gameExit; // Terimination condition of main loop.
extern bool redraw;

extern int mainPhase; // The main loop is organized into "phases."
enum enumMainPhases
{
    MAIN_PHASE_TITLE = 0,
    MAIN_PHASE_LOADING = 1,
    MAIN_PHASE_GAME = 2
};

/// Math constants
const float PI = 3.141592;

/// Display and window constants
const float FPS = 60;

const int SCREEN_W = 1600;
const int SCREEN_H = 900;

/*
// ALLEGRO_BITMAP*scaleBuffer;
int sx = windowWidth / screenWidth;
int sy = windowHeight / screenHeight;
int scale = std::min(sx, sy);

int scaleW = screenWidth * scale;
int scaleH = screenHeight * scale;
int scaleX = (windowWidth - scaleW) / 2;
int scaleY = (windowHeight - scaleH) / 2;
*/

/// Drawing coordinate constants
const int HEX_SIZE = 32;
const int MINI_HEX_SIZE = HEX_SIZE/4;

const int ISOMETRIC_OFFSET_Y = -3; // Modify drawing position to account for isometric effect

/// Direction constants
enum enumDirections
{
    NO_DIRECTION = 0,
    NORTHEAST    = 60,
    NORTHWEST    = 120,
    EAST         = 180,
    SOUTHWEST    = 240,
    SOUTHEAST    = 300,
    WEST         = 360
};

enum enumInputDirections
{
    INPUT_NO_DIRECTION = 0,
    INPUT_NORTHEAST    = 60,
    INPUT_NORTHWEST    = 120,
    INPUT_EAST         = 180,
    INPUT_SOUTHWEST    = 240,
    INPUT_SOUTHEAST    = 300,
    INPUT_WEST         = 360
};

/// Overworld controls
extern int worldSize; // The length of one edge of the hexagonal world.

#endif // GAMESYSTEM_H_INCLUDED
