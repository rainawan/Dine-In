//
// Created by Raina Wan on 3/20/23.
//

#include "TextInput.h"

void TextInput::setLabel(std::string string) {
    label.setString(string);
    label.setFont(Fonts::getFont(OPEN_SANS));
    label.setCharacterSize(30);
    label.setPosition({50,50});
    textbox.setPosition({label.getPosition().x + 200, label.getPosition().y});
}

void TextInput::setLabelSize(int num) {
    label.setCharacterSize(num);
}

void TextInput::setPosition(const sf::Vector2f &position) {
    label.setPosition(position);
}

void TextInput::setPosition(float x, float y) {
    setPosition({x,y});
}

void TextInput::initialize() {
    textbox.setOutlineColor(sf::Color::White);
    typing.setFillColor(sf::Color::Black);
    typing.setCharacterSize(textbox.getGlobalBounds().height - 25);
    typing.setPosition({textbox.getPosition().x, textbox.getPosition().y});

    cursor.setFillColor(sf::Color::Black);
    cursor.setPosition({typing.getPosition().x + typing.getGlobalBounds().width + 2, typing.getPosition().y});
    cursor.setCharacterSize(typing.getCharacterSize() - 5);
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(typing);
    window.draw(textbox);
    window.draw(label);
    window.draw(cursor);
}

void TextInput::eventHandler(sf::RenderWindow &window, sf::Event event) {


    textbox.eventHandler(window, event);

    if (textbox.getState(CLICKED)) {
        cursor.enableState(ENABLED);
        typing.eventHandler(window, event);
        initialize();
    }
    if (textbox.getState(NOT_CLICKED)) {
        textbox.setOutlineColor(sf::Color::Black);
        cursor.disableState(ENABLED);
    }

}

void TextInput::update() {
    cursor.update();
}

Snapshot *TextInput::getSnapshot() {

}

void TextInput::applySnapshot(Snapshot *snapshot) {

}
