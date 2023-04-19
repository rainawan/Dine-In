//
// Created by Raina Wan on 4/19/23.
//

#ifndef DINEIN_FILETREE_H
#define DINEIN_FILETREE_H

#include "../../SFMLTools/GUIComponent.h"
#include "FileTreeNode.h"
#include "sstream"

class FileTree : public GUIComponent {
private:
    FileTreeNode* root = nullptr;
    std::vector<std::string> split(std::string fileName);
    FileTreeNode* search(std::string s, FileTreeNode* node);
    FileTreeNode* createNode(std::string s);
public:
    void push(std::string filepath);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot* getSnapshot() override;
    void applySnapshot(Snapshot* snapshot) override;
};


#endif //DINEIN_FILETREE_H
