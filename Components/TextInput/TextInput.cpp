//
// Created by Raina Wan on 3/20/23.
//

#include "TextInput.h"

TextInput::TextInput() {
    textbox.setFillColor(sf::Color(247, 255, 184,150));
}

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
    textbox.setPosition(position);
}

void TextInput::setPosition(float x, float y) {
    setPosition({x,y});
}

void TextInput::setOutlineColor(sf::Color color) {
    textbox.setOutlineColor(color);
}

void TextInput::initialize() {
//    textbox.setOutlineColor(sf::Color(247, 255, 184));
    textbox.setOutlineColor(sf::Color(113, 118, 55));
    textbox.setFillColor(sf::Color(247, 255, 184,150));

    typing.setFillColor(sf::Color::Black);
    typing.setCharacterSize(textbox.getGlobalBounds().height - 30);
    typing.setPosition({textbox.getPosition().x, textbox.getPosition().y});

    cursor.setFillColor(sf::Color::Black);
    cursor.setPosition({typing.getPosition().x + typing.getGlobalBounds().width + 1, typing.getPosition().y});
    cursor.setCharacterSize(typing.getCharacterSize() - 15);
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(textbox);
    window.draw(typing);
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
