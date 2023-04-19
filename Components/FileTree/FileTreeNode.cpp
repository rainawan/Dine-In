//
// Created by Raina Wan on 4/19/23.
//

#include "FileTreeNode.h"

FileTreeNode::FileTreeNode() : FileTreeNode("Template", PRICE) {

}

FileTreeNode::FileTreeNode(std::string text, image_enum i) {
    setupData(text);
    setupIcon(i);
    setPosition({0,0});
}

void FileTreeNode::setupData(std::string string) {
    item.reinitialize(string, {300,50});
    item.setTextColor(sf::Color::Black);
}

void FileTreeNode::setupIcon(image_enum i) {
    sprite.setSprite(i);
    sprite.sf::RectangleShape::setScale({.08,.08});
    sprite.sf::RectangleShape::setPosition({item.getPosition().x,item.getPosition().y});
}

void FileTreeNode::push(std::string text, image_enum i) {
    FileTreeNode* node = new FileTreeNode(text, i);
    push(node);
}

void FileTreeNode::push(FileTreeNode *node) {
    children.push_back(node);
}

void FileTreeNode::setPosition(sf::Vector2f pos) {
    item.setPosition(pos);
    sprite.sf::RectangleShape::setPosition({item.getPosition().x,item.getPosition().y});
    reposition();
}

void FileTreeNode::reposition() const {
    if (getState(SHOW_CHILDREN)) {
        sf::Vector2f pos = item.getPosition();
        pos.x += 25;
        pos.y = item.getGlobalBounds().top + item.getGlobalBounds().height;
        for (FileTreeNode* c : children) {
            c->setPosition(pos);
            pos.y += c->getGlobalBounds().height;
        }
    }
}

std::string FileTreeNode::getData() {
    return item.getString();
}

sf::FloatRect FileTreeNode::getGlobalBounds() const {
    sf::FloatRect b = item.getGlobalBounds();
    if (getState(SHOW_CHILDREN)) {
        for (FileTreeNode* c : children) {
            b.height += c->getGlobalBounds().height;
        }
    }
    return b;
}

typename FileTreeNode::iter FileTreeNode::begin() {
    return children.begin();
}

typename FileTreeNode::iter FileTreeNode::end() {
    return children.end();
}

void FileTreeNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    reposition();
    target.draw(item);
    target.draw(sprite);
    if (getState(SHOW_CHILDREN)) {
        for (FileTreeNode* c : children) {
            c->draw(target, states);
        }
    }
}

void FileTreeNode::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents::isClicked(item, window)) {
        std::cout << "c";
        toggleState(SHOW_CHILDREN);
    }
    if (getState(SHOW_CHILDREN)) {
        for (FileTreeNode* c : children) {
            c->eventHandler(window, event);
        }
    }
}

void FileTreeNode::update() {

}

Snapshot *FileTreeNode::getSnapshot() {
    return nullptr;
}

void FileTreeNode::applySnapshot(Snapshot *snapshot) {

}
