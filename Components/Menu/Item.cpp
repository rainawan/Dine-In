//
// Created by Raina Wan on 3/24/23.
//

#include "Item.h"

Item::Item() : Item("",{0.f,0.f}){

}

Item::Item(std::string text, sf::Vector2f size) {
    setupText(text);
    setupBox(size);
}

void Item::reinitialize(std::string text, sf::Vector2f size) {
    setupText(text);
    setupBox(size);
}

void Item::onClick(void (*f)(), sf::RenderWindow& window) {
    if(MouseEvents::isClicked(box, window)) {
        f();
    }
}

void Item::setupText(std::string string) {
    text.setFont(Fonts::getFont(LOUISE));
    text.setString(string);
    text.setFillColor(sf::Color::Red);
}

void Item::setupBox(sf::Vector2f size) {
    box.setSize(size);
    box.setFillColor(sf::Color::Green);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(2);
    Position::centerText(box, text);
}

void Item::setupColor(sf::Color background, sf::Color hover) {
    box.setOutlineColor(sf::Color::Black);
    backgroundColor = background;
    hoverColor = hover;
}

void Item::setBoxSize(sf::Vector2f size) {
    box.setSize(size);
    Position::centerText(box, text);
}

void Item::setTextSize(unsigned int size) {
    text.setCharacterSize(size);
    Position::centerText(box, text);
}

void Item::setBackgroundColor(sf::Color color) {
    backgroundColor = color;
    box.setFillColor(color);
}

void Item::setTextColor(sf::Color color) {
    text.setFillColor(color);
}

void Item::setOutlineColor(sf::Color color) {
    box.setOutlineColor(color);
}

sf::FloatRect Item::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void Item::setPosition(const sf::Vector2f &position) {
    box.setPosition(position);
    Position::centerText(box, text);
}

void Item::setPosition(float x, float y) {
    setPosition({x, y});
}

void Item::setTextPosition(const sf::Vector2f &position) {
    text.setPosition(position);
}

void Item::setString(std::string text) {
    this->text.setString(text);
    Position::centerText(box, this->text);
}

void Item::setFont(fonts_enum font) {
    text.setFont(Fonts::getFont(font));
}

void Item::setCharacterSize(int size) {
    text.setCharacterSize(size);
}

sf::Vector2f Item::getPosition() const {
    return box.getPosition();
}

std::string Item::getString() const {
    return text.getString();
}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!getState(HIDDEN)) { //only draw if not hidden
        target.draw(box);
        target.draw(text);
    }
}

void Item::eventHandler(sf::RenderWindow &window, sf::Event event) {

    if (MouseEvents::isClicked(box, window)) {
        enableState(SHOWN);
    }

    if(MouseEvents::isHovered(box, window)) {
        box.setFillColor(hoverColor);
        text.setFillColor(backgroundColor);
    }
    else {
        box.setFillColor(backgroundColor);
        text.setFillColor(hoverColor);
    }

}

void Item::update() {

}

Snapshot *Item::getSnapshot() {
    DropdownSnapshot* p = new DropdownSnapshot;
    p->setData(text.getString());
    return p;
}

void Item::applySnapshot(Snapshot *snapshot) {
    text.setString(dynamic_cast<DropdownSnapshot*>(snapshot)->getData()); // cast header input to snapshot
}
