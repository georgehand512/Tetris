// Start screen function
// called once the game status is changed to startscreen
// continues to loop until player enters their name and presses "S" to start

#include "start_screen.h"

using namespace sf;     // using SFML namespace
using namespace std;    // using standard namespace

void start_screen(RenderWindow& window, Clock& clock)   // SFML requires us to pass reference to window to allow draw functions
{
    FormatSFMLtext displayText;                 // declare variables
    string playerName;                          
    Text name;
    bool playerEntered = false;
    bool error_message = false;

    file_handling();                            // call file handling function to process scores and update leaderboard list

    RectangleShape rectangle;                   // draw a SFML rectangle to represent the start screen
    rectangle.setSize(sf::Vector2f(700, 650));  // start rectangle/screen size width & height
    rectangle.setFillColor(Color::Black);       // background fill colour
    rectangle.setOutlineColor(sf::Color::Red);  // window outline colour
    rectangle.setOutlineThickness(5);           // window outline thickness
    rectangle.setPosition(10, 140);             // window position

    while ((window.isOpen()) && (gameState == GameStatus::StartScreen))     // start loop conditions
    {
        Event event;                                                        // declare SFML game event variable
        while (window.pollEvent(event))                                     // while loop, polling for event to occur
        {
            if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape)))    // if escape key is pressed or window closed selected
                window.close();                                                                 // close window and quit game


            // player name entry with try/catch exception handling
            if (!playerEntered)                                                     // if name not entered
            {
                if ((event.type == Event::TextEntered) && (playerName.size() < 10)) // if text entered and less than 10 characters long
                {
                    if ((isprint(event.text.unicode)) && ((event.key.code > 47)||(event.key.code > 97)) && ((event.key.code < 91)||(event.key.code < 123)))
                    {
                        playerName += event.text.unicode;   // add char entered onto name if its a valid character
                        error_message = false;              // reset no char entered error message
                    }                    
                }
                else if (event.type == Event::KeyPressed)   
                {
                    if (event.key.code == Keyboard::BackSpace)
                    {
                        if (!playerName.empty())            // if name string is not already empty
                            playerName.pop_back();          // delete char entered from name if backspace key pressed
                    }
                    
                    if (event.key.code == Keyboard::Return) // if player presses return to enter name
                    {
                        try                                 // exception handling try/catch to ensure there are characters entered
                        {
                            
                            if (!playerName.empty())        // if string is valid
                            {
                                player1.giveName(playerName);                                           // set player name
                                name = displayText.format_SFML_text(playerName, 40, 280, 400, true);    // format text for display
                                playerEntered = true;                                                   // set name enter flag
                            }
                            else 
                            {
                                throw (playerEntered);      // throw exception return ket pressed without name
                            }
                        }
                        catch (bool valid)                  // catch exception
                        {
                            if (!valid) error_message = true; // if not valid set error message flag to display message
                        }
                    }
                }
            }

            if ((Keyboard::isKeyPressed(Keyboard::S)) && (playerEntered))   
            {
                gameState = GameStatus::GameRunning;    // start game by setting status to game running if "S" is pressed
            }

        }

        static Time text_effect_time;           // next lines setup the cursor to flash for player entry prompt
        static bool flash_text;

        text_effect_time += clock.restart();

        if (text_effect_time >= seconds(0.7f))
        {
            flash_text = !flash_text;
            text_effect_time = Time::Zero;
        }

        // formatting the various text to display using my SFML format class

        Text input = displayText.format_SFML_text((playerName + (flash_text ? '_' : ' ')), 20, 300, 610, true); // cursor flashes

        Text welcome = displayText.format_SFML_text("WELCOME TO TETRIS", 35, 170, 160, true);

        Text instructions1 = displayText.format_SFML_text("Controls:", 30, 80, 240, true);
        Text instructions2 = displayText.format_SFML_text("\"Left\" or \"Right\" arrow keys: Move blocks left or right", 20, 100, 300, true);
        Text instructions3 = displayText.format_SFML_text("\"Up\" arrow key: Rotate blocks", 20, 100, 340, true);
        Text instructions4 = displayText.format_SFML_text("\"Down\" arrow key: Fast drop", 20, 100, 380, true);
        Text instructions5 = displayText.format_SFML_text("Clear as many full rows as possible", 30, 100, 450, true);

        Text prompt = displayText.format_SFML_text("Please enter your name and press enter to continue", 25, 60, 550, true);
        Text prompt1 = displayText.format_SFML_text("\(max 10 characters\)", 15, 450, 615, true);
        Text message = displayText.format_SFML_text((flash_text ? "Please enter a name" : "                       "), 25, 250, 650, true);
        Text startText = displayText.format_SFML_text((flash_text ? "Press \"S\" to start the game": "                       "), 30, 170, 500, true);    

        Text info = displayText.format_SFML_text("Press \"Escape\" to QUIT", 30, 200, 740, true);


        // Draw Start Screen //

        // SFML sprite type used to display background
        Texture game_background;                                // declares SFML texture type variable 
        game_background.loadFromFile("images/background.png");  // loads background image from file and assigns to texture variable
        Sprite background(game_background);                     // declares Sprite type variable with texture assigned

        window.clear(Color::Black);     // clears main game window
        window.draw(background);        // draws main game background
        window.draw(rectangle);         // draws gameover rectangle to represent smaller gameover window
        window.draw(welcome);           // draws text

        if (!playerEntered)                             // if player name is not entered
        {
            RectangleShape textbox;                     // create a red rectangle/window to highlight required input
            textbox.setSize(sf::Vector2f(680, 170));
            textbox.setFillColor(Color::Red);
            textbox.setOutlineColor(sf::Color::Red);
            textbox.setOutlineThickness(2);
            textbox.setPosition(20, 540);

            RectangleShape namebox;                     // create a small rectangle/window for name entery textbox
            namebox.setSize(sf::Vector2f(150, 40));
            namebox.setFillColor(Color::Black);
            namebox.setOutlineColor(sf::Color::Red);
            namebox.setOutlineThickness(2);
            namebox.setPosition(290, 600);

            // draw items onto screen
            window.draw(textbox);
            window.draw(prompt);
            window.draw(prompt1);
            window.draw(namebox);
            window.draw(input);
            if (error_message) window.draw(message);

            window.draw(instructions1);
            window.draw(instructions2);
            window.draw(instructions3);
            window.draw(instructions4);
            window.draw(instructions5);
        }
        else                                            // else if name is entered
        {
            RectangleShape textbox;                     // create a red rectangle/window to highlight required input
            textbox.setSize(sf::Vector2f(680, 270));
            textbox.setFillColor(Color::Red);
            textbox.setOutlineColor(sf::Color::Red);
            textbox.setOutlineThickness(2);
            textbox.setPosition(20, 340);
            
            // draw items onto screen
            window.draw(textbox);
            window.draw(name);
            window.draw(startText);
        }
        window.draw(info);
        window.display();
    }

}
