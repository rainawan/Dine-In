//
// Created by Raina Wan on 3/24/23.
//

#include "Fonts.h"
std::map<fonts_enum, sf::Font> Fonts::map;

void Fonts::load(fonts_enum font) {
    map[font].loadFromFile(getPath(font));
}

std::string Fonts::getPath(fonts_enum font) {
    switch(font) {
        case OPEN_SANS: return "SFMLTools/OpenSans-Bold.ttf";
        case LAST_FONT: return "";
    }
}

sf::Font &Fonts::getFont(fonts_enum font) {
    load(font);
    return map[font];
}