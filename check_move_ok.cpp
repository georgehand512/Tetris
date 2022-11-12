// Function to check if game field location is valid move
// checks if position is still on the game field
// checks if posistion is already filled with a static sub-block

#include "check_move_ok.h"


// Function retruns bool true - Free space, false - move not valid
bool check_move_ok()
{
    // loop to check that each of the 4 sub-blocks points are free 
    for (int i = 0; i < 4; i++)
             
        // check if proposed location is within the game field boundaries (off field left, right or off the bottom)
        if (active_Block[i].x < 0 || active_Block[i].x >= field_cols || active_Block[i].y >= field_rows)
        {
            return false; // not valid move
        }
        // check field is zero. does not already hold a static sub-block colour number, thus is above zero 
        else if (field[active_Block[i].y][active_Block[i].x])
        {
            return false; // if holds a number is already occuppied so move not valid
        }

    return true; // move is valid return true
};
