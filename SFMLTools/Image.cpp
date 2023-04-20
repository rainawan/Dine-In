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
        case LAST_IMAGE: "";
    }
    return std::string();
}

sf::Texture &Image::get(image_enum image) {
    load(image);
    return images.at(image);
}