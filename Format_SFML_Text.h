// FormatSFMLtext Class - is used to format all game display text, integers ready for drawing to the screen
// Returns "Text" in format with --> value to display, character size, start position x & y, color Black or White
// Saves on repeated coding and function overloading used here is an example of Compile-Time Polymorphism

#pragma once
#include <SFML/Graphics.hpp> // SFML media library

using namespace sf;
using namespace std;

class FormatSFMLtext
{
private:
	Font comicFont;		// specifies font to be used
	Text formatText;	// SFML Text type


public:
	FormatSFMLtext();	// default constructor

	// overloaded functions 
	Text format_SFML_text(int numberToDisplay, int textSize, int posX, int posY, bool col); // Integer to Text
	Text format_SFML_text(string display, int textSize, int posX, int posY, bool col);		// String to Text
	Text format_SFML_text(Text text, int textSize, int posX, int posY, bool col);			// Text to Text formatted
};





