// Global variables 

#pragma once
#include <SFML/Graphics.hpp>    // SFML media library
#include "JSON_Player.h"        // single player object formatted for Rapid JSON writter
#include "JSON_Players.h"       // array of player objects for Rapid JSON saving
#include "Player.h"             // Player class


enum class GameStatus           // Standard c++ enum class type GameStatus
{
    StartScreen,                // used for setting game state
    GameRunning,                // 1 of the 3 states specified
    GameOver,
    Paused
};

extern GameStatus gameState;    // declare GameStatus variable gameState

const int rows = 22;            // constant for game field number of rows
const int col = 10;             // constant for game filed number of columns

extern int field[rows][col];    // 2d array for game field
extern int field_rows;          // game field rows
extern int field_cols;          // game field columns


struct Point { int x, y; };                                     // Struct of type Point, x, y for positions
extern Point active_Block[4], stored_Block[4], next_Block[4];   //full Blocks contain 4 sub-blocks each with its own x, y position
extern int active_Block_colour, next_Block_colour;              //sub-block colour helds as integer value

extern Player player1;                  // Player type declaration of player1

extern JSON_Player json_rank_list[10];  // JSON ranking list of player objects
extern JSON_Players json_players;       // JSON players variable

