// Start screen function
// called once the game status is changed to startscreen
// continues to loop until player enters their name and presses "S" to start


#pragma once

#include <SFML/Graphics.hpp>	// SFML media library
#include <iostream>				// standard library
#include "global.h"				// global variables
#include "Format_SFML_Text.h"	// SFML text format class
#include "file_handling.h"		// creating/read/writting to JSON formatted file 

void start_screen(RenderWindow& window, Clock& clock);
