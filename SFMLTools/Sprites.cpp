//
// Created by Raina Wan on 4/4/23.
//

#include "Sprites.h"

Sprites::Sprites() : Sprites(Image::get(HOME)) {

}

Sprites::Sprites(const sf::Texture &texture) : Sprite(texture) {
    setTexture(texture);
}

void Sprites::setSprite(image_enum icon) {
    setTexture(Image::get(icon), true);
}

void Sprites::setPosition(const sf::Vector2f &position) {
    this->setPosition(position);
}

void Sprites::setScale(const sf::Vector2f &position) {
    setScale(position);
}

void Sprites::setSize(const sf::Vector2f &size) {
    setSize(size);
}

void Sprites::getPosition() {
    return this->getPosition();
}

void Sprites::draw() {

}
