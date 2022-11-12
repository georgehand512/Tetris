// function to move the active blocks 
// left, right or rotate

#include "user_move_input.h"

void user_move_input(Event Keypressed)
{
    bool rotate = false;
    int dx = 0;

    if (Keypressed.key.code == Keyboard::Up) rotate = true;     // Up key sets rotate flag
    else if (Keypressed.key.code == Keyboard::Left) dx = -1;    // left key set direction x to -1
    else if (Keypressed.key.code == Keyboard::Right) dx = 1;    // left key set direction x to +1

    for (int i = 0; i < 4; i++)                                 // loop through each sub-block
    {
        stored_Block[i] = active_Block[i];                      // store position before updating
        Point p = active_Block[1];                              // sub-block position assign as center of rotation for full Block

        if (dx != 0)                                            //// <- Move -> ///
        {
            active_Block[i].x += dx;                            // change block x postion by +/- 1 depending on dx above
        }
        else if (rotate)                                        //// Rotate ///
        {
            int x = active_Block[i].y - p.y;                    // move block relative to centre of rotation block
            int y = active_Block[i].x - p.x;
            active_Block[i].x = p.x - x;
            active_Block[i].y = p.y + y;
        }
    }
    if (!check_move_ok()) for (int i = 0; i < 4; i++)           // check proposed moves are valid - call function
    {
        active_Block[i] = stored_Block[i];                      // if not restore original positions - don't allow move
    }
}