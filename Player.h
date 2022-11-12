// Player Class - holds all the player data
// It is parent class to JSON_Player so its members are protected
// example of iheritance, this class being a base or parent

#pragma once
#include <iostream> // standard library

using namespace std;

class Player
{
protected:
    int Ranking;            // Player object properties
    string Name;
    int Score;
    int Level;
    int RowsCleared;
    int RowsToNextLevel;
    int HighScoretoBeat;


public:
    Player(); //allows declaration of array of Player
    Player(int rank, string name, int score, int level, int rows, int remain, int high);

    //setters & getters 
    void resetplayer(bool full);
    void giveName(string name);
    void setHighScore(int setScore);
    void setRanking(int setRanking);
    int getRanking();
    string getName();
    int getHighScore();
    int getScore();
    int getLevel();
    int getRows();
    int getRemaining();
    int updateScore();
    
};

