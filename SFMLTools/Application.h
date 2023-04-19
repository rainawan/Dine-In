//
// Created by Raina Wan on 4/18/23.
//

#ifndef DINEIN_APPLICATION_H
#define DINEIN_APPLICATION_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GUIComponent.h"
//#include "../Components/Menu/Drop"
#include "../Components/Menu/MenuBar.h"
//#include "Sprites.h"
//#include "FileItem.h"
//#include "Item.h"
//#include "FileNode.h"
//#include "FileTree.h"

class Application {
private:
    sf::RenderWindow window;
    void eventListener();
    std::vector<GUIComponent *> objects;

public:
    Application();
    Application(sf::VideoMode videoMode, std::string title);
    void runLoop();
    void addDrawable(GUIComponent& object);
};


#endif //DINEIN_APPLICATION_H
