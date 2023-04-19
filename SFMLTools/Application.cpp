//
// Created by Raina Wan on 4/18/23.
//

#include "Application.h"

Application::Application() : window({2500,1500, 32}, "Dine-In") {

}

Application::Application(sf::VideoMode videoMode, std::string title) : window(videoMode, title) {

}

void Application::eventListener() {

}

void Application::runLoop() {
    DropdownMenu menu = {"ONE", "TWO", "THREE"};
    menu.setPosition({300,200});

    MenuBar menu_bar;
    menu_bar.addItem("menu 0",{"do", "re", "mi"});
    menu_bar.addItem("menu 1",{"fa","so","la"});
    menu_bar.addItem("menu 2",{"ti","do"});

    TextInput t;

    HomePage home;


    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)) {
            if(sf::Event::Closed == event.type)
                window.close();
            menu.eventHandler(window, event);

            home.eventHandler(window, event);
        }


        for(GUIComponent *o : objects)
        {
            o->update();
        }

        home.update();
        window.clear(sf::Color(255, 242, 204));
        window.draw(home);
        window.display();
    }
}

void Application::addDrawable(GUIComponent &object) {
    objects.push_back(&object);
}
