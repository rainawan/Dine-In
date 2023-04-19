//
// Created by Raina Wan on 4/18/23.
//

#include "TextBox.h"

TextBox::TextBox() {
    textbox.setSize({500,50});
    textbox.setFillColor(sf::Color::Transparent);
    textbox.setOutlineColor(sf::Color::Black);
    textbox.setOutlineThickness(thickness);
}

void TextBox::setOutlineColor(sf::Color color) {
    textbox.setOutlineColor(color);
}

void TextBox::setPosition(const sf::Vector2f &position) {
    textbox.setPosition(position);
}

void TextBox::setPosition(float x, float y) {
    setPosition({x, y});
}

sf::Vector2f TextBox::getPosition() {
    return {textbox.getPosition().x, textbox.getPosition().y};
}

sf::FloatRect TextBox::getGlobalBounds() const {
    return textbox.getGlobalBounds();
}

void TextBox::eventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    if (MouseEvents::isClicked(textbox, window)) {
        enableState(CLICKED);
        disableState(NOT_CLICKED);
    }
    else if (MouseEvents::isNotClicked(textbox, window)) {
        enableState(NOT_CLICKED);
        disableState(CLICKED);
    }
}

void TextBox::update() {

}

void TextBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(textbox);
    window.draw(typing);
}

Snapshot *TextBox::getSnapshot() {

}

void TextBox::applySnapshot(Snapshot *snapshot) {

}
