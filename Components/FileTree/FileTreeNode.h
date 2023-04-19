//
// Created by Raina Wan on 4/19/23.
//

#ifndef DINEIN_FILETREENODE_H
#define DINEIN_FILETREENODE_H

#include "../../SFMLTools/GUIComponent.h"
#include "../../SFMLTools/Image.h"
#include "../../SFMLTools/Sprites.h"
#include "../Menu/Item.h"
#include <vector>

class FileTreeNode : public GUIComponent {
private:
    sf::Text data;
    Item item;
    Sprites sprite;
    std::vector<FileTreeNode*> children;
    void setupData(std::string string);
    void setupIcon(image_enum i);
public:
    FileTreeNode();
    FileTreeNode(std::string text, image_enum i);
    void push(std::string text, image_enum i);
    void push(FileTreeNode* node);
    void setPosition(sf::Vector2f pos);
    void reposition() const;
    std::string getData();
    sf::FloatRect getGlobalBounds() const;
    typedef std::vector<FileTreeNode*>::iterator iter;
    iter begin();
    iter end();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //DINEIN_FILETREENODE_H
