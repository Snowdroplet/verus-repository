#include "hex.h"

Hex::Hex(int q, int r, int b)
{
    qCell = q;
    rCell = r;
    xPosition = qCell*HEX_SIZE + 0.50*rCell*HEX_SIZE;
    yPosition = rCell*0.75*HEX_SIZE;

    base = b;

}

Hex::~Hex()
{
    //std::cout << "Hex (" << qCell << ", " << rCell << ") was destroyed." << std::endl;
    neighbours.clear();
    neighbours.shrink_to_fit();
}

void Hex::SetBase(int setTo)
{
    base = setTo;
}

void Hex::SetFeature(int setTo)
{
    feature = setTo;
}

void Hex::ToggleRoad(int direction)
{
    roads[direction] = !roads[direction];
}

void Hex::SetRoads(bool setTo[6])
{
    for(int i = 0; i < 6; i++)
        roads[i] = setTo[i];
}
