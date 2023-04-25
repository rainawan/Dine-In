//
// Created by Raina Wan on 4/19/23.
//

#include "RestaurantsPage.h"

RestaurantsPage::RestaurantsPage() {
    init();
}

void RestaurantsPage::init() {
    // Restaurants
    RestaurantItem bone_kettle ("Bone Kettle", {1400, 250}, BONE_KETTLE, FIVESTAR, 4);
    RestaurantItem millies ("Millie's Cafe", {1400, 250}, MILLIES, FIVESTAR, 2);
    RestaurantItem granville ("Granville", {1400, 250}, GRANVILLE, FOURSTAR, 3);
    RestaurantItem urth ("Urth Caffe", {1400, 250}, URTH, FOURSTAR, 2);

    millies.setScale({.27,.3});
    granville.setScale({.5,.5});
    urth.setScale({.27,.27});

    // Push to Items
    items.push_back(bone_kettle);
    items.push_back(millies);
    items.push_back(granville);
    items.push_back(urth);

    reposition();
    setupFileTree();
    setupBackground();
}

void RestaurantsPage::setupFileTree() {
    sort.push("Sort By");
    sort.push("Sort By/Price");
    sort.push("Sort By/Price/Low to High");
    sort.push("Sort By/Price/High to Low");
    sort.push("Sort By/Popularity");
    sort.push("Sort By/Popularity/Most Loved");
    sort.push("Sort By/Popularity/New Places");
    sort.setPosition({1700,50});
}

void RestaurantsPage::setupBackground() {
    background.setSprite(SPICE2);
//    background.sf::RectangleShape::setScale({4.5,3.9}); // spice1
    background.sf::RectangleShape::setScale({4,3.6}); // spice2
}

void RestaurantsPage::reposition() {
    for (int i = 1; i < items.size(); ++i) {
        items[i].setPosition({items[i-1].getPosition().x, items[i-1].getPosition().y + items[i-1].getGlobalBounds().height + 30});
    }
}

void RestaurantsPage::setPosition(const sf::Vector2f &pos) {
    items[0].setPosition(pos);
    reposition();
}

void RestaurantsPage::push(std::string string, sf::Vector2f size, image_enum food, image_enum stars, int dollars) {
    
}

void RestaurantsPage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
    for (int i = 0; i < items.size(); ++i) {
        target.draw(items[i]);
    }
    target.draw(sort);
}

void RestaurantsPage::eventHandler(sf::RenderWindow &window, sf::Event event) {
    for (int i = 0; i < items.size(); ++i) {
        items[i].eventHandler(window, event);
    }
    sort.eventHandler(window, event);
}

void RestaurantsPage::update() {

}

Snapshot *RestaurantsPage::getSnapshot() {
    
}

void RestaurantsPage::applySnapshot(Snapshot *snapshot) {

}
