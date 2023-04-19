//
// Created by Raina Wan on 3/24/23.
//

#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <SFML/Graphics.hpp>
#include "../../SFMLTools/GUIComponent.h"
#include "../History/History.h"
#include "../History/DropdownSnapshot.h"

class Item : public GUIComponent {
private:
    sf::RectangleShape box;
    sf::Text text;
    void setupText(std::string text);
    void setupBox(sf::Vector2f size);
    void setupColor(sf::Color background, sf::Color hover);
    sf::Color backgroundColor = sf::Color::White, hoverColor = sf::Color::Blue;
public:
    Item();
    Item(std::string text, sf::Vector2f size);
    void onClick(void (*f)(), sf::RenderWindow& window);
    void setBoxSize(sf::Vector2f size);
    void setTextSize(unsigned int size);
    void setBackgroundColor(sf::Color color);
    void setTextColor(sf::Color color);
    sf::FloatRect getGlobalBounds() const;
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
//    void setPosition(sf::Vector2f position) const;
    void setTextPosition(const sf::Vector2f& position);
    void setString(std::string text);
    sf::Vector2f getPosition();
    std::string getString() const;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //MENU_ITEM_H
