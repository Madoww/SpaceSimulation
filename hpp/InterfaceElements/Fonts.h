#ifndef Fonts_h
#define Fonts_h
#include <SFML/Graphics.hpp>

class Fonts
{
public:
    Fonts()
    {
        //default_font.loadFromFile("/Users/Filip/Documents/code/dark_forest/dark_forest/Sources/Fonts/PixelSplitter.otf");
        default_font.loadFromFile("C:/font.otf");
    }
    Fonts(const Fonts&) = delete;
    Fonts operator=(const Fonts&) = delete;
    inline static Fonts& Instance()
    {
        static Fonts fonts;
        return fonts;
    }
    sf::Font default_font;
};


#endif /* Fonts_h */
