//
// Created by Raina Wan on 3/27/23.
//

#include "Typing.h"

Typing::Typing() {
    text.setFont(Fonts::getFont(OPEN_SANS));
}

void Typing::setPosition(const sf::Vector2f &position) {
    text.setPosition(position);
}

void Typing::setCharacterSize(int num) {
    text.setCharacterSize(num);
}

void Typing::setFillColor(sf::Color color) {
    text.setFillColor(color);
}

sf::FloatRect Typing::getGlobalBounds() {
    return text.getGlobalBounds();
}

sf::Vector2f Typing::getPosition() {
    return text.getPosition();
}

float Typing::getCharacterSize() {
    return text.getCharacterSize();
}

std::string Typing::getText() {
    return text.getString();
//    return s;
}

void Typing::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (sf::Event::TextEntered == event.type) {
        History::push({this, getSnapshot()}); // pointer pointing to obj, get snapshot
        s = text.getString();
        if (event.text.unicode == 8) { //sf::Keyboard::Backspace
            s.pop_back();
        }
        else {
            s.push_back(static_cast<char>(event.text.unicode));
        }
    }
    text.setString(s);
}

void Typing::update() {

}

void Typing::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(text);
}

Snapshot *Typing::getSnapshot() {
    TextInputSnapshot* p = new TextInputSnapshot;
    p->setData(text.getString());
    return p;
}

void Typing::applySnapshot(Snapshot* snapshot) {
//    std::cout << dynamic_cast<TextInputSnapshot*>(snapshot)->getData();
    text.setString(dynamic_cast<TextInputSnapshot*>(snapshot)->getData()); // cast text input to snapshot
    s = dynamic_cast<TextInputSnapshot*>(snapshot)->getData();
}
