// FormatSFMLtext Class - is used to format all game display text, integers ready for drawing to the screen
// Returns "Text" in format with --> value to display, character size, start position x & y, color Black or White
// Saves on repeated coding and function overloading used here is an example of Compile-Time Polymorphism

#include "Format_SFML_Text.h"

FormatSFMLtext::FormatSFMLtext()
{
}

Text FormatSFMLtext::format_SFML_text(int numberToDisplay, int textSize, int posX, int posY, bool col) // Integer to Text
{
    if (!comicFont.loadFromFile("resources/Fonts/comic.ttf"));  // loads font from resource folder

    formatText.setString(to_string(numberToDisplay));           // Text value to display - integer to string conversion
    formatText.setCharacterSize(textSize);                      // Text size set
    formatText.setFont(comicFont);                              // Text font set
    formatText.setPosition(posX, posY);                         // Text x, y, position set
    formatText.setFillColor(col ? Color::White : Color::Black); // Text colour true - White, false - Black

    return  formatText;                                         // returns formatted SFML Text type
}

Text FormatSFMLtext::format_SFML_text(string display, int textSize, int posX, int posY, bool col)   // String to Text
{
    if (!comicFont.loadFromFile("resources/Fonts/comic.ttf"));  // loads font from resource folder

    formatText.setString(display);                              // Text value to display - string conversion
    formatText.setCharacterSize(textSize);                      // Text size set
    formatText.setFont(comicFont);                              // Text font set
    formatText.setPosition(posX, posY);                         // Text x, y, position set
    formatText.setFillColor(col ? Color::White : Color::Black); // Text colour true - White, false - Black

    return  formatText;                                         // returns formatted SFML Text type
}

Text FormatSFMLtext::format_SFML_text(Text text, int textSize, int posX, int posY, bool col)    // Text to formatted Text
{
    if (!comicFont.loadFromFile("resources/Fonts/comic.ttf"));  // loads font from resource folder

    formatText = text;                                          // Text value to display
    formatText.setCharacterSize(textSize);                      // Text size set
    formatText.setFont(comicFont);                              // Text font set
    formatText.setPosition(posX, posY);                         // Text x, y, position set
    formatText.setFillColor(col ? Color::White : Color::Black); // Text colour true - White, false - Black

    return  formatText;                                         // returns formatted SFML Text type
}
