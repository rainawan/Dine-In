//
// Created by Raina Wan on 4/3/23.
//

#ifndef MENU_IMAGE_H
#define MENU_IMAGE_H

#include <map>
#include <SFML/Graphics.hpp>

enum image_enum {
    HOME, FOOD, SEARCH,
    SORT, PRICE, POPULARITY,
    FIVESTAR, FOURSTAR, DOLLAR,
    BONE_KETTLE, MILLIES, GRANVILLE, URTH,
    SPICE1, SPICE2,
    RESERVE, BACK, BK_INSIDE,
    LAST_IMAGE
};

class Image {
private:
    static std::map<image_enum, sf::Texture> images;
    static void load(image_enum image);
    static std::string getPath(image_enum image);
public:
    static sf::Texture& get(image_enum image);
};


#endif //MENU_IMAGE_H
