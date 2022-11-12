#include <SFML/Graphics.hpp>    // include SFML media library
#include "global.h"             // my global variables file
#include "start_screen.h"       // start file
#include "running_game_loop.h"  // running file
#include "game_over_screen.h"   // game over file



// ** main() function renamed to "WinMain()" to prevent console window appearing (project properties change also required)
int WinMain()   
{
    // SFML set game window & Title
    RenderWindow window(VideoMode(720, 900), "Tetris - George Hand");   

    // define game clock
    Clock clock; 

    // Game main while loop - whilst window is open
    while (window.isOpen())
    {
        // Call Start Screen and pass by reference window and clock - Note** gameState initialide to StartScreen in global file.
        if (gameState == GameStatus::StartScreen) start_screen(window, clock);
                
        // Call Game Running and pass by reference window and clock 
        if (gameState == GameStatus::GameRunning) running_game_loop(window, clock);
        
        // Call Game Running and pass by reference window. Clock not required for game over
        if (gameState == GameStatus::GameOver) game_over_screen(window);
        
        // SFML display window & Title
        window.display();
    }

    return 0;
}

