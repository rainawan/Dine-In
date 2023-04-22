//
// Created by Raina Wan on 4/18/23.
//

#ifndef DINEIN_APPLICATION_H
#define DINEIN_APPLICATION_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GUIComponent.h"
#include "../Applications/HomePage.h"
#include "../Applications/RestaurantItem.h"
#include "../Applications/RestaurantsPage.h"
#include "../Components/Menu/MenuBar.h"
#include "../Components/TextInput/TextInput.h"
#include "../Components/FileTree/FileTreeNode.h"
#include "../Components/FileTree/FileTree.h"

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
