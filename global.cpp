// Global variables

#include "global.h"

using namespace sf;
using namespace std;

GameStatus gameState = GameStatus::StartScreen;			// Initialise gameState to start game on start screen

int field[rows][col] = { 0 };							// Initilalise game field with blanks
int field_rows = rows;									// Initialise rows
int field_cols = col;									// Initialise columns

Point active_Block[4], stored_Block[4], next_Block[4];	// declare 3 Point array variables

int active_Block_colour = 1, next_Block_colour = 1;		// initialise sub-block colour variables

Player player1(99, "unknown", 0, 1, 0, 10, 0);			// initialise player 1 of type Player 

JSON_Player json_rank_list[10];							// declare reanking list
JSON_Players json_players;								// declare players objects for JSON file serialisation/deserialisation