// Gameover Screen
// called once the blocks hit the top of the screen and the game is lost
// Displays leaderboard scores
// Gives player option to restart, start as new player or quit the game

#pragma once

#include <SFML/Graphics.hpp>	// SFML media library
#include <iostream>				// standard library
#include "global.h"				// global variables
#include "Format_SFML_Text.h"	// SFML text format class
#include "file_handling.h"		// creating/read/writting to JSON formatted file

void game_over_screen(RenderWindow& window);