//
// Created by Raina Wan on 3/24/23.
//

#ifndef MENU_FONTS_H
#define MENU_FONTS_H
#include <SFML/Graphics.hpp>
#include <map>

enum fonts_enum {
    OPEN_SANS,
    LAST_FONT
};

class Fonts {
private:
    static std::map<fonts_enum, sf::Font> map;
    static void load(fonts_enum font);
    static std::string getPath(fonts_enum font);
public:
    static sf::Font& getFont(fonts_enum font);
};


#endif //MENU_FONTS_H
