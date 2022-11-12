// updates the positions of the active and static blocks function
// moves the active block down the screen if valid

#include "update_game_field.h"

void update_game_field()
{

    for (int i = 0; i < 4; i++)
    {
        stored_Block[i] = active_Block[i];  // copy active block current posisiton into temp store
        active_Block[i].y += 1;             // moves active piece down grid 1 place, + y positions of each sub-block
    }
    
    if (!check_move_ok())                   // calls check move function and if returns - false move
    {
        for (int i = 0; i < 4; i++)
        {
            field[stored_Block[i].y][stored_Block[i].x] = active_Block_colour; // set stored block locations to static - fill with colour number
            if (stored_Block[i].y == 0)  gameState = GameStatus::GameOver;     // checks if this has reached row zero to end the game
        }

        for (int i = 0; i < 4; i++)
        {
            active_Block[i] = next_Block[i];            // make next block the active block
            active_Block_colour = next_Block_colour;    // set new active block colour
        }

        // a pointer to an Point, this is where the return address to point will be stored that comes back from the Class Method.
        int** BlockPointer;

        RandomBlock newBlock;                           //objects to get new block shape & colour

        BlockPointer = newBlock.getBlockshape();        //call function to get new block

        for (int i = 0; i < 4; i++)                     // loop through addresses pointed at to retrieve array values
        {
            next_Block[i].x = BlockPointer[i][0];       // load x values into active block
            next_Block[i].y = BlockPointer[i][1];       // load y values into active block
        }

        next_Block_colour = newBlock.getBlockcolour(); //set colour of next Block

    }
}