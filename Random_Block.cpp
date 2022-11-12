// Random Block Class
// generates 1 of 7 available block shapes
// each shape has its own assigned colour

#include "Random_Block.h"

RandomBlock::RandomBlock()
{
}

int** RandomBlock::getBlockshape() // return pointer to pointer block shape array
{
    int **array;
    int row = 4, col = 2, i, j;

    //Dynamically allocating row space in heap
    array = new int *[row];

    //Dynamically allocating column space in heap
    for (i = 0; i < row; i++)
    {
        array[i] = new int[col];
    }

    //Generate random number 0-7 to select shape and colour of block
    int n = rand() % 7;
    Colour = n + 1;

    //Assigning random Block Shape to return via the array pointer to pointer
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (n == 0)  array[i][j] = T_Shape[i][j];       // Block T - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
            else if (n == 1)  array[i][j] = Z_Shape[i][j];  // Block Z - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
            else if (n == 2)  array[i][j] = S_Shape[i][j];  // Block S - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
            else if (n == 3)  array[i][j] = O_Shape[i][j];  // Block O - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
            else if (n == 4)  array[i][j] = I_Shape[i][j];  // Block I - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
            else if (n == 5)  array[i][j] = L_Shape[i][j];  // Block L - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
            else if (n == 6)  array[i][j] = J_Shape[i][j];  // Block J - shape made up of 4 sub-blocks with x, y top left corner posistion co-ordinates
        }
    }
    return array;   // returns array by reference pointer to pointer
}

int RandomBlock::getBlockcolour()	// return integer value select block tile image/texture/colour
{
    return Colour;
}