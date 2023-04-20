//
// Created by Raina Wan on 4/19/23.
//

#ifndef DINEIN_RESTAURANTITEM_H
#define DINEIN_RESTAURANTITEM_H

#include "../Components/Menu/Item.h"
#include "../SFMLTools/Image.h"
#include "../SFMLTools/Sprites.h"

class RestaurantItem : public GUIComponent {
private:
    Item item;
    Sprites rest_sprite;
    void setupText(std::string string, sf::Vector2f size);
    void setupSprite(image_enum icon);
    void reposition();
public:
    RestaurantItem();
    RestaurantItem(std::string string, sf::Vector2f size, image_enum icon);
    void setScale(sf::Vector2f scale);
    void setPosition(const sf::Vector2f& position);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //DINEIN_RESTAURANTITEM_H
