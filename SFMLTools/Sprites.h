//
// Created by Raina Wan on 4/4/23.
//

#ifndef MENU_SPRITES_H
#define MENU_SPRITES_H

#include "SFML/Graphics.hpp"
#include "Image.h"

class Sprites : public sf::Sprite {
public:
    Sprites();
    Sprites(const sf::Texture& texture);
    void setSprite(image_enum icon);
    void setPosition(const sf::Vector2f& position);
    void setScale(const sf::Vector2f& position);
    void setSize(const sf::Vector2f& size);
    void setFillColor(sf::Color color);
    sf::Vector2f& getPosition();
    void draw();
};


#endif //MENU_SPRITES_H
