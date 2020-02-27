#include "gamesystem.h"

/// Main loop controls
bool gameExit = false;

bool redraw = false;

int mainPhase = MAIN_PHASE_GAME;

/// Input and interface controls
int controlContext = CONTROL_CONTEXT_OVERWORLD;

int controlContextChangeDelay = 0;

/// Display, window, and camera control
int cameraXPosition = 0;
int cameraYPosition = 0;

int drawingXCellCutoff = SCREEN_W/HEX_SIZE; //1600/64
int drawingYCellCutoff = SCREEN_H/HEX_SIZE; //900/64  -- Make these scalable later when zooming is implemented.

/// Overworld controls
int worldSize = 31;  // Should be an odd number to produce a hexagon.



