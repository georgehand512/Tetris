// function to move the active blocks 
// left, right or rotate

#pragma once

#include "global.h"				// global variables
#include "check_move_ok.h"		// check valid move function
#include "update_game_field.h"	// update or move block down function

void user_move_input(Event Keypressed);  // User moves block left, right or rotate