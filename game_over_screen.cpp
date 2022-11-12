// Gameover Screen
// called once the blocks hit the top of the screen and the game is lost
// Displays leaderboard scores
// Gives player option to restart, start as new player or quit the game

#include "game_over_screen.h"

using namespace sf;     // using SFML namespace
using namespace std;    // using standard namespace

void game_over_screen(RenderWindow& window)     // SFML requires us to pass reference to window to allow draw functions
{
    FormatSFMLtext displayText;                 // declare variable of type FormatSFMLtext

    file_handling();                            // call file handling function to process scores and update leaderboard list

    RectangleShape rectangle;                   // draw a SFML rectangle to represent the gameover screen
    rectangle.setSize(sf::Vector2f(700, 650));  // gameover rectangle/screen size width & height
    rectangle.setFillColor(Color::Black);       // background fill colour
    rectangle.setOutlineColor(sf::Color::Red);  // window outline colour
    rectangle.setOutlineThickness(5);           // window outline thickness
    rectangle.setPosition(10, 140);             // window position

    while ((window.isOpen()) && (gameState == GameStatus::GameOver))    // gameover loop conditions
    {
        Event event;                                                    // declare SFML game event variable
        while (window.pollEvent(event))                                 // while loop, polling for event to occur
        {
            if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape))) // if escape key is pressed or window closed selected
                window.close();                                                              // close window and quit game

            if (Keyboard::isKeyPressed(Keyboard::R))                    // if user presses "R" key - restart as same player
            {
                player1.resetplayer(false);                             // reset player scores but keep retain same name
                gameState = GameStatus::GameRunning;                    // Restart game - set gamestate back to running
            }
            else if (Keyboard::isKeyPressed(Keyboard::N))               // if user presses "N" key - restart as NEW player
            {
                player1.resetplayer(true);                              // reset player name & scores
                gameState = GameStatus::StartScreen;                    // call start screen for new player entry
            }
        }

        for (int i = 0; i < field_rows; i++)                            // clear game field
            for (int j = 0; j < field_cols; j++)                        // loop through each position
            {
                field[i][j] = 0;                                        // set value to 0 - clear data
            }

        RectangleShape textbox;                                         // SFML Rectangle to give background to player option text
        textbox.setSize(sf::Vector2f(540, 80));                         // small red window
        textbox.setFillColor(Color::Red);
        textbox.setOutlineColor(sf::Color::Red);
        textbox.setOutlineThickness(2);
        textbox.setPosition(100, 640);

        // formatting the various text to display using my SFML format class
        Text Game_Over_text = displayText.format_SFML_text("GAME OVER", 40, 240, 150, true); 
        
        Text leaderBoard = displayText.format_SFML_text("Leaderboard", 30, 260, 230, true);
        Text leaderBoardTitles = displayText.format_SFML_text("Position        Name          Score       Level        Rows", 25, 65, 280, true);

        Text restartText = displayText.format_SFML_text("press \"R\" - To restart game as same Player\n\t  press \"N\" - To start as a new Player", 20, 160, 650, true);
        Text info = displayText.format_SFML_text("Press \"Escape\" to QUIT", 30, 200, 740, true);
        

        // Drawing all information onto the screen
        
        // SFML sprite type used to display background
        Texture game_background;                                // declares SFML texture type variable               
        game_background.loadFromFile("images/background.png");  // loads background image from file and assigns to texture variable
        Sprite background(game_background);                     // declares Sprite type variable with texture assigned
       
        window.clear(Color::Black);         // clears main game window
        window.draw(background);            // draws main game background
        window.draw(rectangle);             // draws gameover rectangle to represent smaller gameover window
        window.draw(textbox);               // draws small red window to highlight options text

        window.draw(Game_Over_text);        // draws each of the previously formatted SFML text objects
        window.draw(leaderBoard);
        window.draw(leaderBoardTitles);
        window.draw(restartText);
        window.draw(info);

        for (int i = 0; i < 10; i++)        // loops through and displays leaderboard of top ten player
        {
            Text displayRank = displayText.format_SFML_text(json_rank_list[i].get_Ranking(), 20, 105, (320 + (i * 30)), true);
            window.draw(displayRank);
            Text displayName = displayText.format_SFML_text(json_rank_list[i].get_Name(), 20, 205, (320 + (i * 30)), true);
            window.draw(displayName);
            Text displayScore = displayText.format_SFML_text(json_rank_list[i].get_Score(), 20, 365, (320 + (i * 30)), true);
            window.draw(displayScore);
            Text displayLevel = displayText.format_SFML_text(json_rank_list[i].get_Level(), 20, 495, (320 + (i * 30)), true);
            window.draw(displayLevel);
            Text displayRows = displayText.format_SFML_text(json_rank_list[i].get_RowsCleared(), 20, 605, (320 + (i * 30)), true);
            window.draw(displayRows);
        }


        // displays the built window on the screen
        window.display();                   
    }

}