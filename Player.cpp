// Player Class - holds all the player data
// It is parent class to JSON_Player so its members are protected
// example of iheritance, this class being a base or parent

#include "Player.h"

Player::Player()
{
}

Player::Player(int rank, string name, int score, int level, int rows, int remain, int high)
{
    Ranking = rank;
    Name = name;
    Score = score;
    Level = level;
    RowsCleared = rows;
    RowsToNextLevel = remain;
    HighScoretoBeat = high;
}

void Player::resetplayer(bool full) // reset player on restart of game
{
    if (full) Name = "unknown"; // name only reset if player selects NEW game versus restart

    Ranking = 99;           // reset of data is self explainatory
    Score = 0;
    Level = 1;
    RowsCleared = 0;
    RowsToNextLevel = 10;
}

void Player::giveName(string name)
{
    Name = name;
}

void Player::setHighScore(int setScore)
{
    HighScoretoBeat = setScore;
}

void Player::setRanking(int setRanking)
{
    Ranking = setRanking;
}

int Player::getRanking()
{
    return Ranking;
}

string Player::getName()
{
    return Name;
}

int Player::getHighScore()
{
    return HighScoretoBeat;
}

int Player::getScore()
{
    return Score;
}

int Player::getLevel()
{
    return Level;
}


int Player::getRows()
{
    return RowsCleared;
}

int Player::getRemaining()
{
    return RowsToNextLevel;
}

int Player::updateScore()
{
    RowsCleared++;                                          // score incremented on call to function
    RowsToNextLevel = 10 - (RowsCleared % 10);              // calculate rows to next level
    if ((RowsToNextLevel % 10) == 0) Level++;               // change level every 10 completed rows
    Score = Score + (5 + (5 * Level));                      // update score based on formula
    if (Score >= HighScoretoBeat) HighScoretoBeat = Score;  // update highscore if player beats highscore during game

    return Level;                                           // return current game level
}
