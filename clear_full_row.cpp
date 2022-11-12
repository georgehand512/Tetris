// Function to check for full rows & update player score
// 
// how the code works:
// 
// both y_pos and row_offset are set to start checking rows from the bottom of the game field
// To start with y_pos and row_offset are looking at the same row
// y_pos copies the row contents into row_offset contents and updates the game field
// If they remain the same nothing changes as the row is unchanged.
// 
// If a full row is dectect then row_offset is not decremented (moved up to next row)
// y_pos will then be looking at a row higher, and move it's contents into row_offset
// this will over-write the values from the higher row into the lower row.

#include "clear_full_row.h"

void clear_full_row()
{
    int row_offset = field_rows - 1;                        // row_offset initialised to start at the bottom row of game field
    
    for (int y_pos = field_rows - 1; y_pos > 0; y_pos--)    // loop through game field starting at bottom row and working up towards the top
    {                                           
        int filled_count = 0;                               // counts filled positions in the row being checked
                                        
        for (int x_pos = 0; x_pos < field_cols; x_pos++)    // loops through each position in the row being checked
        {
            if (field[y_pos][x_pos]) filled_count++;        // if field is true (has a colour value) then increment filled_counter
            field[row_offset][x_pos] = field[y_pos][x_pos]; // copy position value into row_offset value 

        }
        if (filled_count < field_cols) row_offset--;            // if row is not full then decrement row_offset, if row is full row_offset remains the same
        if (filled_count == field_cols) player1.updateScore();  // if full row dectected update player score - call function
    }
}