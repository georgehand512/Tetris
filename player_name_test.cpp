#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>




using namespace std;

int main()
{
    sf::SoundBuffer buffer;
    sf::Color my_colour_red (255, 0,0, 255);
    sf::Color my_colour_blue(0, 0, 255, 255);
    float x = 0, y = 0, r = 0;

     

    if (!buffer.loadFromFile ("resources/Audio/test.wav"))
    {
    cout << "Error loading sound" << endl;
    }

    sf::Sound sound;
    sound.setBuffer(buffer);
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tetris using SFML");
   
    sf::RectangleShape box_1;
    box_1.setSize(sf::Vector2f(100, 50));
    box_1.setOutlineColor(my_colour_red);
    box_1.setFillColor(my_colour_blue);
    box_1.setOutlineThickness(2);
    box_1.setPosition(300, 200);

    sf::RectangleShape box_2;
    box_2.setSize(sf::Vector2f(100, 50));
    box_2.setOutlineColor(my_colour_blue);
    box_2.setFillColor(my_colour_red);
    box_2.setOutlineThickness(2);
    box_2.setPosition(x, y);
    box_2.setOrigin(sf::Vector2f(50, 25));
    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left)
                {
                    box_2.setPosition(x = x - 10, y);
                }
                if ((event.key.code == sf::Keyboard::Right) && !(box_2.getGlobalBounds().intersects(box_1.getGlobalBounds())))
                {
                    box_2.setPosition(x = x + 10, y);
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    box_2.setPosition(x , y = y + 10);
                }
                if (event.key.code == sf::Keyboard::Up)
                {
                    box_2.setRotation(r = r + 90);
                }
                if (box_2.getGlobalBounds().intersects(box_1.getGlobalBounds()))
                {
                    sound.play();
               //     box_2.setPosition(x= x+10, y= y+10);
                }

                
               
            }
            
        }

        window.clear();
        window.draw(box_1);
        window.draw(box_2);
        window.display();


    }
    
    return 0;
}