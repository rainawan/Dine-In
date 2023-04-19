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
        case TABLE: return "SFMLTools/images/restaurant.jpeg";
        case FOOD: return "SFMLTools/images/food.jpeg";
        case BACKGROUND: return "SFMLTools/images/background.jpeg";
        case LAST_IMAGE: "";
    }
    return std::string();
}

sf::Texture &Image::get(image_enum image) {
    load(image);
    return images.at(image);
}