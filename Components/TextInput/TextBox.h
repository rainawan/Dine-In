//
// Created by Raina Wan on 4/18/23.
//

#ifndef DINEIN_TEXTBOX_H
#define DINEIN_TEXTBOX_H

#include <SFML/Graphics.hpp>
#include "../../SFMLTools/GUIComponent.h"
#include "../../SFMLTools/States.h"
#include "../../SFMLTools/MouseEvents.h"
#include "Typing.h"

class TextBox : public GUIComponent {
private:
    sf::RectangleShape textbox;
    Typing typing;
    const float thickness = 8.0;
public:
    TextBox();
    void setOutlineColor(sf::Color color);
    void setFillColor(sf::Color color);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds() const;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //DINEIN_TEXTBOX_H
