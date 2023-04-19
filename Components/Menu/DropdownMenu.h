//
// Created by Raina Wan on 3/24/23.
//

#ifndef MENU_DROPDOWNMENU_H
#define MENU_DROPDOWNMENU_H

#include "../../SFMLTools/GUIComponent.h"
#include "ItemList.h"
#include "../History/DropdownSnapshot.h"
#include <initializer_list>

class DropdownMenu : public GUIComponent {
private:
    Item header;
    ItemList list;
    void init();
    DropdownSnapshot snapshot;
public:
    DropdownMenu();
    DropdownMenu(std::initializer_list<std::string> items);
    void addItem(std::string item);
    void setPosition(const sf::Vector2f& position);
    void setHeader(std::string string);
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //MENU_DROPDOWNMENU_H
