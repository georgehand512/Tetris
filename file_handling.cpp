// Function for creating/read/writting to JSON formatted file
// Reads in existing leaderboard of 10 player object data
// Initialises the current high score data
// Writes newly ranked and sorted leaderboard of 10 player object data

#include "file_handling.h"

void file_handling()
{
    // Start of game - check if file exists using try/catch code
    if (gameState == GameStatus::StartScreen)
    {

        try {
            bool exists = true;                                                 // exists flag
            exists = json_players.DeserializeFromFile("High_Scores.json");      // use RapidJSON method to check if file exists true/false

            if (exists)     // file exists
            {
                JSON_Players json_players_from_file;                            // declare list of type JSON_Players
                json_players_from_file.DeserializeFromFile("High_Scores.json"); // deserialise data from file and store in list

                int i = 0; // variable to increment array element

                // loop through the list items of player objects until the end of file 
                for (std::list<JSON_Player>::const_iterator it = json_players_from_file.PlayersList().begin(); it != json_players_from_file.PlayersList().end(); it++)
                {
                    json_rank_list[i] = *it; // copy from list into array using pointer
                    i++;                     // increment array to next element
                }

            }
            else {
                throw (exists);             // throw exception file not found or does not exist
            }
        }
        catch (bool nofile)
        {
            for (int i = 0; i < 10; i++)    // Create a file formatted correctly with 10 blank players
            {
                JSON_Player json_players_blank((i + 1), "unknown", 0, 1, 0, 10, 0); // create blank player in JSON format
                json_rank_list[i] = json_players_blank;                             // copy into players array
                json_players.PlayersList().push_back(json_rank_list[i]);            // copy into player list
            }

            json_players.SerializeToFile("High_Scores.json");                       // JSON serialisation & create file/save
        }
        
        int highscore = json_rank_list[0].get_Score();                              // gets current high score from file data
        player1.setHighScore(highscore);                                            // load high score for game
    }


    //Gameover - update leaderboard score & rankings for display & save to JSON file
    if (gameState == GameStatus::GameOver)
    {
        int rank_10_score = json_rank_list[9].get_Score();                          // store leaderboard lowest ranked player score

        if (player1.getScore() > rank_10_score)                                     // if current player beats 10 score
        {
            json_rank_list[9].Player_to_JSON_Player(player1);                       // replace 10th place player with current players data
        }

        // Bubble sort Top Ten Ranking
        bool sorted = false;	                                                    // sorted flag
        JSON_Player temp;		                                                    // temp Player to store value to be swapped in position

        while (!sorted)
        {
            sorted = true;                                                          // standard bubble sort code
            for (int i = 0; i < (10 - 1); i++)                                      // sorted by score
            {
                if (json_rank_list[i].get_Score() < json_rank_list[i + 1].get_Score())
                {
                    temp = json_rank_list[i];
                    json_rank_list[i] = json_rank_list[i + 1];
                    json_rank_list[i + 1] = temp;
                    sorted = false;
                }
            }

        }

        // Update ranking numbers of to the sorted list
        for (int i = 0; i < 10; i++)
        {
            json_rank_list[i].update_Ranking(i + 1);
        }


        // Serialise and store data to JSON file
        JSON_Players json_players_save_to_file;

        for (int i = 0; i < 10; i++)
        {
            json_players_save_to_file.PlayersList().push_back(json_rank_list[i]);   // move data from array to list for writing to file
        }

        // save to new array file.
        json_players_save_to_file.SerializeToFile("High_Scores.json");              // write list to file JSON format

    }

}