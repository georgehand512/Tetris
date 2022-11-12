// Random Block Class
// generates 1 of 7 available block shapes
// each shape has its own assigned colour

#pragma once
#include <iostream> // standard library

class RandomBlock
{
private:
    int T_Shape[4][2] = { {3,0}, {4,0},{4,1}, {5,0} };	// Block T - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
    int Z_Shape[4][2] = { {3,0}, {4,0},{4,1}, {5,1} };	// Block Z - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
    int S_Shape[4][2] = { {5,0}, {4,0},{4,1}, {3,1} };	// Block S - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
    int O_Shape[4][2] = { {3,0}, {4,0},{3,1}, {4,1} };	// Block O - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
    int I_Shape[4][2] = { {6,1}, {5,1},{4,1}, {3,1} };	// Block I - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
    int L_Shape[4][2] = { {3,1}, {4,1},{5,1}, {5,0} };	// Block L - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
    int J_Shape[4][2] = { {5,1}, {4,1},{3,1}, {3,0} };	// Block J - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates

    int Colour;		// selects the tile image/texture/colour to display

public:
    RandomBlock();
    int** getBlockshape();  // return pointer to pointer to block shape array
    int getBlockcolour();	// return integer value select block image/texture/colour
};


