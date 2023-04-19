//
// Created by Raina Wan on 3/27/23.
//

#include "Cursor.h"
Cursor::Cursor() {
    cursor.setFont(Fonts::getFont(OPEN_SANS));
    cursor.setString("|");
    cursor.setCharacterSize(24);
}

void Cursor::setPosition(const sf::Vector2f &position) {
    cursor.setPosition(position);
}

void Cursor::setCharacterSize(int num) {
    cursor.setCharacterSize(num);
}

void Cursor::setFillColor(sf::Color color) {
    cursor.setFillColor(color);
}

void Cursor::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Cursor::update() {
    if (getState(ENABLED)) {
        disableState(HIDDEN);
        if (clock.getElapsedTime().asMilliseconds() > 500) {
            toggleState(BLINK);
            clock.restart();
        }
    }
}

void Cursor::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!getState(HIDDEN) && getState(BLINK) && getState(ENABLED)) {
        target.draw(cursor);
    }
}

Snapshot *Cursor::getSnapshot() {

}

void Cursor::applySnapshot(Snapshot *snapshot) {

}
