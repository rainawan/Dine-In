//
// Created by Raina Wan on 3/20/23.
//

#ifndef TEXTINPUT_TEXTINPUT_H
#define TEXTINPUT_TEXTINPUT_H
#include <SFML/Graphics.hpp>
#include "Typing.h"
#include "TextBox.h"
#include "Cursor.h"
#include "../../SFMLTools/MouseEvents.h"
#include "../../SFMLTools/GUIComponent.h"
#include "../../SFMLTools/States.h"

class TextInput : public GUIComponent {
private:
    Typing typing;
    TextBox textbox;
    sf::Text label;
    Cursor cursor;
public:
    TextInput();
    void setLabel(std::string string);
    void setLabelSize(int num);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setOutlineColor(sf::Color color);
    void initialize();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //TEXTINPUT_TEXTINPUT_H
