// Main game running function
// called once the game status is changed to game running
// continues to loop until blocks build up to the top of the screen
// and the player loses the game

#pragma once

#include <SFML/Graphics.hpp>	// SFML media library
#include <time.h>				// standard time library
#include <iostream>				// standard library
#include "global.h"				// global variables
#include "Format_SFML_Text.h"	// SFML text format class
#include "clear_full_row.h"		// clear full row function
#include "user_move_input.h"	// user move function

void running_game_loop(RenderWindow& window, Clock& clock);