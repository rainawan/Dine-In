//
// Created by Raina Wan on 3/30/23.
//

#ifndef MENU_MENUBAR_H
#define MENU_MENUBAR_H
#include "../../SFMLTools/GUIComponent.h"
#include "DropdownMenu.h"
#include <vector>

class MenuBar : public GUIComponent {
private:
    std::vector<DropdownMenu> menus;
public:
    MenuBar();
    MenuBar(int num_menus);
    void addItem(std::string header, std::initializer_list<std::string> items);
    void setup();
    void setPosition(const sf::Vector2f& position);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //MENU_MENUBAR_H
