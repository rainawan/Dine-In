//
// Created by Raina Wan on 3/24/23.
//

#ifndef MENU_ITEMLIST_H
#define MENU_ITEMLIST_H

#include "../../SFMLTools/GUIComponent.h"
#include "Item.h"

class ItemList : public GUIComponent {
private:
    std::vector<Item> items;
    void position();
public:
    void addItem(const std::string& text, void (*f)() = nullptr);
    void addItem(const Item& item, void (*f)() = nullptr);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    sf::FloatRect getHeaderBounds();
    sf::FloatRect getGlobalBounds();
    std::vector<Item>& getItems();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;

    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //MENU_ITEMLIST_H
