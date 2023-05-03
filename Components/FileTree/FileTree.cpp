//
// Created by Raina Wan on 4/19/23.
//

#include "FileTree.h"

std::vector<std::string> FileTree::split(std::string fileName) {
    std::stringstream sstr(fileName);
    std::vector<std::string> v;
    while(sstr.good()) {
        std::string substr;
        getline(sstr, substr, '/');
        v.push_back(substr);
    }
    return v;
}

void FileTree::push(std::string filepath) {
    std::vector<std::string> paths = split(filepath);
    FileTreeNode* p = root;

    if (root == nullptr) {
        root = new FileTreeNode(paths[0], SORT); // FOLDER
    }
    else if (p->getData() == paths[0]) {  // root is what we're looking for
        for (int i = 1; i < paths.size() - 1; i++) {
            if (p != nullptr)  { // children is what we're looking for
                p = search(paths[i], p); // search first path, starting from root, until you reach new restaurants
            }
        }
        p->push(paths[paths.size() - 1], set_image(paths[paths.size() - 1])); // FILE
    }
}

image_enum FileTree::set_image(std::string s) {
    switch (s[s.size() - 1]) {
        case 'e': // price
            return PRICE;
            break;
        case 'y': // popularity
            return POPULARITY;
            break;
        case 'h': // low to high
            return HIGH;
            break;
        case 'w': // high to low
            return LOW;
            break;
        case 'd': // most loved
            return LOVED;
            break;
        case 's': // new places
            return NEW;
            break;
        default:
            return SORT;
            break;
    }
}

FileTreeNode *FileTree::search(std::string s, FileTreeNode *node) {
    auto iter = node->begin();
    for (; iter != node->end(); ++iter) {
        if ((*iter)->getData() == s) { // if data is what we're looking for, return data. else nullptr
            return *iter;
        }
    }
    return nullptr;
}

FileTreeNode *FileTree::createNode(std::string s) {
    FileTreeNode* p = new FileTreeNode;
    p->getData() = s;
    return p;
}

void FileTree::setPosition(const sf::Vector2f &position) {
    root->setPosition(position);
}

std::string FileTree::getData() {
//    auto iter = root->begin();
//    for (; iter != root->end(); ++iter) {
//        if ((*iter)->getState(SHOW_CHILDREN))
//            last_clicked = (*iter)->getLastClicked();
////            std::cout << (*iter)->getData();
//    }
    std::cout << last_clicked << " ";
    return last_clicked;
}

void FileTree::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*root);
}

void FileTree::eventHandler(sf::RenderWindow &window, sf::Event event) {
    root->eventHandler(window, event);

    auto iter = root->begin();
    for (; iter != root->end(); ++iter) {

        auto i = (*iter)->begin();
        for (;i != (*iter)->end(); ++i) {

            if ((*i)->getState(LOW_TO_HIGH)) {
                last_clicked.clear();
                last_clicked = (*i)->getData();
                enableState(LOW_TO_HIGH);
            }
            if ((*i)->getState(HIGH_TO_LOW)) {
                last_clicked.clear();
                last_clicked = (*i)->getData();
            }

        }
    }
//    std::cout << last_clicked << ". ";
}

void FileTree::update() {

}

Snapshot *FileTree::getSnapshot() {
    return nullptr;
}

void FileTree::applySnapshot(Snapshot *snapshot) {

}
