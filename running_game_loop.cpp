// Main game running function
// called once the game status is changed to game running
// continues to loop until blocks build up to the top of the screen
// and the player loses the game

#include "running_game_loop.h"

using namespace sf;     // using SFML namespace
using namespace std;    // using standard namespace

void running_game_loop(RenderWindow& window, Clock& clock)  // SFML requires us to pass reference to window to allow draw functions
{
    FormatSFMLtext displayText;                 // declare variable of type FormatSFMLtext
    double timer = 0, delay = 0.5;              // declare variables for game timing
    srand(time(0));                             // seed random number generator based on time

    int** BlockPointer;                         // a pointer to a pointer , this is how we get 2d array values back from Random Block Class
    
    RandomBlock Block;                          //objects to get active and waiting block shape & colour


    // get initial active block shape and colour
    BlockPointer = Block.getBlockshape();       //call function to access block shape, but initialise shape and clolour
    
    for (int i = 0; i < 4; i++)                 // loop through addresses pointed at to retrieve array values
    {
        active_Block[i].x = BlockPointer[i][0]; // load x values into active block
        active_Block[i].y = BlockPointer[i][1]; // load y values into active block
    }
    active_Block_colour = Block.getBlockcolour(); //set colour of first active Block


    // repeat to get initial next block shape and colour
    BlockPointer = Block.getBlockshape();       //call function to access block shape, but initialise shape and clolour

    for (int i = 0; i < 4; i++)                 // loop through addresses pointed at to retrieve array values
    {
        next_Block[i].x = BlockPointer[i][0];   // load x values into active block
        next_Block[i].y = BlockPointer[i][1];   // load y values into active block
    }
    next_Block_colour = Block.getBlockcolour(); //set colour of first waiting Block



    while ((window.isOpen()) && (gameState == GameStatus::GameRunning)) // running loop conditions
    {

        float time = clock.getElapsedTime().asSeconds();                // setup game speed time
        clock.restart();
        timer += time;

        Event event;                                                    // declare SFML game event variable
        while (window.pollEvent(event))                                 // while loop, polling for event to occur
        {
            if (event.type == Event::Closed)                            // if window closed selected
                window.close();                                         // close window and quit game

            if (event.type == Event::KeyPressed) user_move_input(event);// if keypressed call user move function
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;       // if down arrow is pressed reduce delay from 0.5 to 0.05 fast drop

        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            if (gameState == GameStatus::GameRunning) gameState = GameStatus::Paused;
            else gameState = GameStatus::GameRunning;
        }

        while (gameState != GameStatus::Paused)
        {
            if ((timer > delay) && (gameState == GameStatus::GameRunning))  // once time delay has passed
            {
                update_game_field();                                        // call update game field function
                timer = 0;                                                  // reset timer
            }

            clear_full_row();                                               // check for full rows, call clear row function

            delay = (0.3 - (0.03 * player1.getLevel()));                    // adjust game difficaulty level - increase speed as level increases
        }
       



        // formatting the various text to display using my SFML format class

        Text displayName = displayText.format_SFML_text(player1.getName(), 20, 550, 475, true);

        Text nextPiece = displayText.format_SFML_text("NEXT BLOCK", 20, 530, 150, false);

        Text hiScoreText = displayText.format_SFML_text("Highest Score", 20, 510, 330, false);
        Text displayhiScore = displayText.format_SFML_text(player1.getHighScore(), 20, 550, 365, true);

        Text scoreText = displayText.format_SFML_text("Score", 20, 540, 546, false);
        Text displayScore = displayText.format_SFML_text(player1.getScore(), 20, 630, 546, true);

        Text levelText = displayText.format_SFML_text("Level", 20, 545, 620, false);
        Text displayLevel = displayText.format_SFML_text(player1.getLevel(), 20, 630, 620, true);

        Text rowClearedText = displayText.format_SFML_text("Rows cleared", 20,475, 690, false);
        Text rowsCleared = displayText.format_SFML_text(player1.getRows(), 20, 630, 690, true);

        Text remainingText = displayText.format_SFML_text("Row this level", 20, 475, 763, false);
        Text displayRemaining = displayText.format_SFML_text(player1.getRemaining(), 20, 630, 763, true);


        // Drawing all information onto the screen
        // Draw game runnning screen and update blocks and scores etc.

        // SFML sprite type used to display background
        Texture game_background, sub_block_image;                       // declare textures for background and blocks
        sub_block_image.loadFromFile("images/block.png");               // load block image file and assigns to texture variable
        game_background.loadFromFile("images/background.png");          // loads background image from file and assigns to texture variable
        Sprite background(game_background), sub_block(sub_block_image); // declares Sprite type variable with texture assigned


        window.clear(Color::Black);     // clears main game window
        window.draw(background);        // draws main game background

        window.draw(nextPiece);         // draw all formatted text no comments necessary on next few lines
        window.draw(hiScoreText);
        window.draw(displayhiScore);

        window.draw(displayName);

        window.draw(scoreText);
        window.draw(displayScore);

        window.draw(levelText);
        window.draw(displayLevel);

        window.draw(rowClearedText);
        window.draw(rowsCleared);

        window.draw(remainingText);
        window.draw(displayRemaining);

        
        // Draw game field
        //displays static blocks from row 2 onwards (rows 0 & 1 are not shown but used to load block into off screen)
        for (int i = 2; i < field_rows; i++)        //loops through each row
            for (int j = 0; j < field_cols; j++)    //loops through each column in row
            {
                // if field is occuppied draw a static block
                if (field[i][j] != 0)               
                {
                    sub_block.setTextureRect(IntRect(field[i][j] * 36, 0, 36, 36)); //select to texture from file
                    sub_block.setPosition(j * 36, i * 36);                          //set position
                    sub_block.move(36, 72); //offset                                //set offset value
                    window.draw(sub_block);                                         //draw the block
                }

            }

        // draw active and next blocks
        for (int i = 0; i < 4; i++)
        {
            // active block
            sub_block.setTextureRect(IntRect(active_Block_colour * 36, 0, 36, 36)); //select to texture from file
            sub_block.setPosition(active_Block[i].x * 36, active_Block[i].y * 36);  //set position
            sub_block.move(36, 72); //offset                                        //set offset value
            if (active_Block[i].y >= 2) window.draw(sub_block);                     //draw the block

            // next block
            sub_block.setTextureRect(IntRect(next_Block_colour * 36, 0, 36, 36));   //select to texture from file
            sub_block.setPosition(next_Block[i].x * 36, next_Block[i].y * 36);      //set position
            sub_block.move(400, 198); //offset                                      //set offset value
            window.draw(sub_block);                                                 //draw the block
        }


        // displays the built window on the screen
        window.display();
    }
}