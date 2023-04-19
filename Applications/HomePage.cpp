//
// Created by Raina Wan on 4/18/23.
//

#include "HomePage.h"

HomePage::HomePage() {
    init();
}

void HomePage::init() {
    header.setString("Dine-In");
    header.setFont(Fonts::getFont(EVIDANCE));
    header.setCharacterSize(200);
    header.setFillColor(sf::Color::Black);
    header.setPosition({820,200});

    text_input.setPosition({750,500});


    sprite.setSprite(HOME);
    sprite.sf::RectangleShape::setScale({4.5,4}); // home
//    sprite.sf::RectangleShape::setScale({3,2.7}); // food

}

void HomePage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
    target.draw(text_input);
    target.draw(header);
}

void HomePage::eventHandler(sf::RenderWindow &window, sf::Event event) {
    text_input.eventHandler(window, event);
}

void HomePage::update() {
    text_input.update();
}

Snapshot *HomePage::getSnapshot() {

}

void HomePage::applySnapshot(Snapshot *snapshot) {

}
