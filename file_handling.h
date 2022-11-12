// Function for creating/read/writting to JSON formatted file
// Reads in existing leaderboard of 10 player object data
// Initialises the current high score data
// Writes newly ranked and sorted leaderboard of 10 player object data

#pragma once
#include "global.h"			// global variables
#include "JSON_Player.h"	// single player object formatted for Rapid JSON writter
#include "JSON_Players.h"	// array of player objects for Rapid JSON saving


void file_handling();