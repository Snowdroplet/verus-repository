#ifndef OVERWORLD_H_INCLUDED
#define OVERWORLD_H_INCLUDED

#include "gamesystem.h"
#include "hex.h"

/** Axes of a hexagonal grid, using axial coordinates as detailed by a tutorial at https://www.redblobgames.com/grids/hexagons/
// Pointy-corner-up


                q +0                   q +1
                r -1                   r -1


                            -r
                             |
                             |       +q
                             |    __/
     q -1                    |   /                q +1
     r +0                    0                    r +0
                       __/   |
                      /      |
                    -q       |
                             |
                            +r


                q -1                   q +0
                r +1                   r +1

Vector indices corresponding to hexagonal coordinates, for a world of size 7:
-RhombusEdge = worldSize
-If rhombus edge is even, add 1.
-HexagonEdge = rhombusEdge/2, rounded up.
-TriangleEdge = rhombusEdge - hexagonEdge.

==============rhombus================
                  =====hexagon=======
=====Triangle=====                                     (q,r)
                  ___________________                                       _____________________
0     1     2    /3     4     5     6\          =         0,0   1,0   2,0  /3,0   4,0   5,0   6,0\

   7     8    /9    10    11    12    13\          =         0,1   1,1  /2,1   3,1   4,1   5,1   6,1\

      14   /15    16    17    18    19    20\         =          0,2  /1,2   2,2   3,2   4,2   5,2   6,2\

        /21    12    23    24    25    26    27\         =         /0,3   1,3   2,3   3,3   4,3   5,3   6,3\

          \ 28    29    30    31    32    33/   34          =        \ 0,4   1,4   2,4   3,4   4,4   5,4/  6,4

             \ 35    36    37    38    39/   40    41          =        \ 0,5   1,5   2,5   3,5   4,5/  5,5   6,5

                \ 42    43    44    45/   46    47   48           =        \ 0,6    1,6   2,6   3,6/  4,6   5,6   6,6
                  -------------------                                        ---------------------

Visualization of rectangular array indices:

-An index is in top left triangle if q < triangleEdge-r
-An index is in bottom right triangle if q > rhombusEdge+triangleEdge-r

 0  1  2            /3  4  5  6|               =      0,0 1,0 2,0             3,0 4,0 5,0 6,0
 7  8            /9 10 11 12 13|               =      0,1 1,1             2,1 3,1 4,1 5,1 6,1
14           /15 16 17 18 19 20|               =      0,2             1,2 2,2 3,2 4,2 5,2 6,2
          /21 22 23 24 25 26 27/               =                  0,3 1,3 2,3 3,3 4,3 5,3 6,3
          |28 29 30 31 32 33/          34      =                  0,4 1,4 2,4 3,4 4,4 5,4             6,4
          |35 36 37 38 39/          40 41      =                  0,5 1,5 2,5 3,5 4,5             5,5 6,4
          |42 43 44 45/          46 47 48      =                  0,6 1,6 2,6 3,6             4,6 5,6 6,6

*/

struct Overworld
{
    std::vector<Hex*>hexGraph;

    int rhombusEdge;
    int hexagonEdge;
    int triangleEdge;

    Overworld(int ws);
    ~Overworld();

};



#endif // OVERWORLD_H_INCLUDED
