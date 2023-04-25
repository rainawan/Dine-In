//
// Created by Raina Wan on 4/19/23.
//

#include "RestaurantItem.h"

RestaurantItem::RestaurantItem() : RestaurantItem("RestItem", {500,600}, FOOD, FIVESTAR, 3){

}

RestaurantItem::RestaurantItem(std::string string, sf::Vector2f size, image_enum food, image_enum stars, int dollars) {
    setupBox(size);
    setupText(string);
    setupFoodSprite(food);
    setupStarSprite(stars);
    setupDollars(dollars);
    reposition();
}

void RestaurantItem::setupText(std::string string) {
    header.setString(string);
    header.setFont(Fonts::getFont(LOUISE));
    header.setCharacterSize(100);
    header.setFillColor(sf::Color(128, 0, 0));
}

void RestaurantItem::setupFoodSprite(image_enum food) {
    rest_sprite.setSprite(food);
    rest_sprite.sf::RectangleShape::setScale({.3,.3});
}

void RestaurantItem::setupStarSprite(image_enum stars) {
    star_sprite.setSprite(stars);
    star_sprite.sf::RectangleShape::setScale({.5,.5});
}

void RestaurantItem::setupDollars(int dollars) {
    for (int i = 0; i < dollars; ++i) {
        Sprites one_dollar;
        one_dollar.setSprite(DOLLAR);
        one_dollar.sf::RectangleShape::setScale({.09,.09});
        dollar_sprites.push_back(one_dollar);
    }
}

void RestaurantItem::setupBox(sf::Vector2f size) {
    item.setSize(size);
    item.setFillColor(sf::Color(211, 211, 211, 220));

    outline.setSize({size.x + 30, size.y + 30});
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineThickness(8.0);
    outline.setOutlineColor(sf::Color::White);
}

void RestaurantItem::reposition() {
    Position::center(item, outline);
    header.setPosition({item.getPosition().x + 20, item.getPosition().y + 10});

    rest_sprite.sf::RectangleShape::setPosition({item.getPosition().x + item.getGlobalBounds().width - rest_sprite.getGlobalBounds().width - 30,
                                                 item.getPosition().y + (item.getGlobalBounds().height / 2) - (rest_sprite.getGlobalBounds().height / 2)});

    star_sprite.sf::RectangleShape::setPosition({header.getPosition().x, header.getPosition().y + 40});

    if (!dollar_sprites.empty()) {
        dollar_sprites[0].sf::RectangleShape::setPosition({star_sprite.sf::RectangleShape::getPosition().x + star_sprite.getGlobalBounds().width + 90, star_sprite.sf::RectangleShape::getPosition().y + 110});
        for (int i = 1; i < dollar_sprites.size(); ++i) {
            dollar_sprites[i].sf::RectangleShape::setPosition({dollar_sprites[i-1].sf::RectangleShape::getPosition().x + dollar_sprites[i-1].getGlobalBounds().width - 20, dollar_sprites[i-1].sf::RectangleShape::getPosition().y});
        }
    }
}

void RestaurantItem::setScale(sf::Vector2f scale) {
    rest_sprite.sf::RectangleShape::setScale(scale);
}

void RestaurantItem::setPosition(const sf::Vector2f &position) {
    item.setPosition(position);
    reposition();
}

std::string RestaurantItem::getString() {
    return header.getString();
}

std::vector<Sprites> RestaurantItem::getDollars() {
    return dollar_sprites;
}

Sprites RestaurantItem::getStars() {
    return star_sprite;
}

sf::Vector2f RestaurantItem::getPosition() const {
    return item.getPosition();
}

sf::FloatRect RestaurantItem::getGlobalBounds() const {
    return outline.getGlobalBounds();
}

void RestaurantItem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(item);
    target.draw(outline);

    target.draw(rest_sprite);
    target.draw(star_sprite);
    for (int i = 0; i < dollar_sprites.size(); ++i) {
        target.draw(dollar_sprites[i]);
    }

    target.draw(header);
}

void RestaurantItem::eventHandler(sf::RenderWindow &window, sf::Event event) {
    // on hover, highlight border
    if (MouseEvents::isHovered(item, window) || MouseEvents::isHovered(outline, window)) {
        outline.setOutlineColor(sf::Color(100,0,0));
        item.setFillColor(sf::Color(230, 230, 230, 250));
    }
    if (!(MouseEvents::isHovered(item, window) || MouseEvents::isHovered(outline, window))) {
        outline.setOutlineColor(sf::Color::White);
        item.setFillColor(sf::Color(211, 211, 211, 220));
    }
}

void RestaurantItem::update() {

}

Snapshot *RestaurantItem::getSnapshot() {
    return nullptr;
}

void RestaurantItem::applySnapshot(Snapshot *snapshot) {

}
