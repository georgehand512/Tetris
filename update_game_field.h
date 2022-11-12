// updates the positions of the active and static blocks function
// moves the active block down the screen if valid

#pragma once

#include <SFML/Graphics.hpp>	// SFML media library
#include <iostream>				// standard library
#include "global.h"				// global variables
#include "Random_Block.h"		// random block generator Class
#include "running_game_loop.h"	// running game function
#include "check_move_ok.h"		// check move function

void update_game_field();
