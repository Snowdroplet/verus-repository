#include "overworld.h"



Overworld::Overworld(int ws)
{
    std::cout << "Overworld created." << std::endl;

    rhombusEdge = ws;

    // Force world to have an odd numbered edge-length.
    if(rhombusEdge%2 == 0)
        rhombusEdge+=1;

    // Hexagon's edge should be half of the rhombus, rounded up.
    hexagonEdge = rhombusEdge/2 +1; // Add one after interger type decimal truncation.
    triangleEdge = rhombusEdge - hexagonEdge;

    // Fill in the grid with hexes (n = world cell width * world cell height)
    for(int r = 0; r < rhombusEdge; r++)
    {
        for(int q = 0; q < rhombusEdge; q++)
        {
            if(q < triangleEdge-r || q >= rhombusEdge+triangleEdge-r) // If a cell is inside the upper-left or lower-right triangle
                hexGraph.push_back(nullptr);
            else
                hexGraph.push_back(new Hex(q,r,HEX_BASE_GRASS));
        }
    }
    // Connect the graph by listing each hex's adjacent nodes.
    for(std::vector<Hex*>::iterator it = hexGraph.begin(); it != hexGraph.end(); ++it)
    {

        if(*it != nullptr)
        {
            int q = (*it)->qCell;
            int r = (*it)->rCell;

            // Naturally, any cell on the edge of the hexagon does not have connections beyond that edge.

            // 1-Add Western neighbour if...
            if(q > 0                               // Not on left edge of rhombus
               && q > triangleEdge-r)              // Not on upper-left edge of hexagon
                (*it)->neighbours.push_back(r*rhombusEdge+(q-1));

            // 2-Add Eastern neighbour if...
            if(q < rhombusEdge-1                   // Not on right edge of rhombus
               && q < rhombusEdge+triangleEdge-r)  // Not on lower-right edge of hexagon
                (*it)->neighbours.push_back(r*rhombusEdge+(q+1));

            // 3-Add Northwest neighbour if...
            if(r > 0                               // Not on upper edge of rhombus
               && q > triangleEdge-r)              // Not on upper-left edge of hexagon
                (*it)->neighbours.push_back((r-1)*rhombusEdge+q);

            // 4-Add Southeast neighbour if...
            if(r < rhombusEdge-1                   // Not on lower edge of rhombus
               && q < rhombusEdge+triangleEdge-r)  // Not on lower-right edge of hexagon
                (*it)->neighbours.push_back((r+1)*rhombusEdge+q);

            // 5-Add Northeast neighbour if...
            if(q < rhombusEdge-1                   // Not on right edge of rhombus
               && r > 0)                           // Not on upper edge of rhombus
                (*it)->neighbours.push_back((r-1)*rhombusEdge+(q+1));

            // 6-Add Southwest neighbour if...
            if(q > 0                               // Not on left edge of rhombus
               && r < rhombusEdge-1)               // Not on lower edge of rhombus
                (*it)->neighbours.push_back((r+1)*rhombusEdge+(q-1));
        }
    }
}

Overworld::~Overworld()
{
    for(std::vector<Hex*>::iterator it = hexGraph.begin(); it != hexGraph.end();)
    {
        delete *it;
        hexGraph.erase(it);
    }
}
