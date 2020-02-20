#ifndef HEX_H_INCLUDED
#define HEX_H_INCLUDED

#include <iostream>
#include <vector>

#include "gamesystem.h"

enum enumHexBase
{
    HEX_BASE_STONE = 0,
    HEX_BASE_SNOW  = 1,
    HEX_BASE_BOG   = 2,
    HEX_BASE_GRASS = 3,
    HEX_BASE_PLAIN = 4,
    HEX_BASE_SAND  = 5,
    HEX_BASE_POND  = 6,
    HEX_BASE_LAKE  = 7,
    HEX_BASE_OCEAN = 8
};

enum enumHexFeature
{
    HEX_FEATURE_NONE = 0,
    HEX_FEATURE_FOREST = 1
};

class Hex
{
public:
    int qCell, rCell;          // q and r will be used to describe cell-level axial coordinates.
    int xPosition, yPosition;  // x and y will be used to describe pixel-level Cartesian coordinates.
    std::vector<int>neighbours;

    int base;
    int feature;
    bool roads[6];

    Hex(int q, int r, int b);
    ~Hex();
    void SetBase(int setTo);
    void SetFeature(int setTo);
    void ToggleRoad(int direction);
    void SetRoads(bool setTo[6]);
};

#endif // HEX_H_INCLUDED
