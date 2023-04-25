//
// Created by Raina Wan on 4/19/23.
//

#ifndef DINEIN_RESTAURANTITEM_H
#define DINEIN_RESTAURANTITEM_H

#include "../Components/Menu/Item.h"
#include "../SFMLTools/Image.h"
#include "../SFMLTools/Sprites.h"
#include <vector>

class RestaurantItem : public GUIComponent {
private:
    sf::RectangleShape item, outline;
    sf::Text header;
    Sprites rest_sprite, star_sprite;
    std::vector<Sprites> dollar_sprites;
    void setupText(std::string string);
    void setupFoodSprite(image_enum food);
    void setupStarSprite(image_enum stars);
    void setupDollars(int dollars);
    void setupBox(sf::Vector2f size);
    void reposition();
public:
    RestaurantItem();
    RestaurantItem(std::string string, sf::Vector2f size, image_enum food, image_enum stars, int dollars);
    void setScale(sf::Vector2f scale);
    void setPosition(const sf::Vector2f& position);
    std::string getString();
    std::vector<Sprites> getDollars();
    Sprites getStars();
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //DINEIN_RESTAURANTITEM_H
