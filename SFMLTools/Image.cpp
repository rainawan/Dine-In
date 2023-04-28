//
// Created by Raina Wan on 4/3/23.
//

#include "Image.h"

std::map<image_enum, sf::Texture> Image::images;

void Image::load(image_enum image) {
    if(!images[image].loadFromFile(getPath(image)))
        exit(65);
}

std::string Image::getPath(image_enum image) {
    switch(image) {
        case HOME: return "SFMLTools/images/home.jpeg";
        case FOOD: return "SFMLTools/images/food.jpeg";
        case SEARCH: return "SFMLTools/images/search.png";
        case SORT: return "SFMLTools/images/sort-down.png";
        case PRICE: return "SFMLTools/images/price-tag.png";
        case POPULARITY: return "SFMLTools/images/fire.png";
        case FIVESTAR: return "SFMLTools/images/fivestar.png";
        case FOURSTAR: return "SFMLTools/images/fourstar.png";
        case DOLLAR: return "SFMLTools/images/dollar.png";
        case BONE_KETTLE: return "SFMLTools/images/bone_kettle.jpeg";
        case MILLIES: return "SFMLTools/images/millies.jpeg";
        case GRANVILLE: return "SFMLTools/images/granv1.jpeg";
        case URTH: return "SFMLTools/images/urth.jpeg";
        case SPICE1: return "SFMLTools/images/spices.jpeg";
        case SPICE2: return "SFMLTools/images/spice6.jpg";
        case RESERVE: return "SFMLTools/images/reserve5.jpg";
        case BACK: return "SFMLTools/images/back.png";
        case BK_INSIDE: return "SFMLTools/images/bk_inside.jpeg";
        case M_INSIDE: return "SFMLTools/images/m.jpeg";
        case G_INSIDE: return "SFMLTools/images/g.jpeg";
        case U_INSIDE: return "SFMLTools/images/u.jpeg";
        case LAST_IMAGE: "";
    }
    return std::string();
}

sf::Texture &Image::get(image_enum image) {
    load(image);
    return images.at(image);
}